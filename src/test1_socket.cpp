#include "SXC_Socket.h"
#include "SXC_SocketAddr.h"

int main() {
	sxc::SAstartup();

	sxc::Socket ServSock;
	sxc::SocketAddr ServAddr("127.0.0.1", 8080);
	
	if (ServSock._new(sxc::ip::PROTO::TCP) == INVALID_SOCKET) {
		std::cerr << "Create TCP Socket Failed" << std::endl;
	}

	if (ServSock._bind(ServAddr.getCRef()) != 0) {
		std::cerr << "Bind Address Failed" << std::endl;
	}
	if (ServSock._listen(10) != 0) {
		std::cerr << "Listen Failed" << std::endl;
	}
	
	auto [sock, addr] = ServSock._accept();
	sxc::Socket clntSock(sock);
	sxc::SocketAddr clntAddr(addr);

	std::string buf(4096, 0);
	clntSock._recv(&buf[0], 4096, 0);
	std::cout << buf << std::endl;

	clntSock._close();
	ServSock._close();

	sxc::SAcleanup();
}