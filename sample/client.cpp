#include "Socket.h"
#include "SocketAddr.h"

int main() {
	sxc::SAstartup();

	sxc::Socket ClntSock;
	sxc::SocketAddr ServAddr("127.0.0.1", 8080);

	if (ClntSock._new(sxc::ip::PROTO::TCP) == INVALID_SOCKET) {
		std::cerr << "Create TCP Socket Failed" << std::endl;
	}

	if (ClntSock._connect(ServAddr.getCRef()) != 0) {
		std::cerr << "Connect Address Failed" << std::endl;
	}
	std::string msg = "Simple Cross Compile Socket Test";
	if (ClntSock._send(&msg[0], msg.size()) < 0) {
		std::cerr << "Send Message Failed" << std::endl;
	}

	ClntSock._close();
	
	sxc::SAcleanup();
}