#include "Socket.h"

namespace sxc {

	int SAstartup() {
#if VS && WINDOWS
		static WSADATA wsaData;
		return WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif 
	}

	int SAcleanup() {
#if VS && WINDOWS
		return WSACleanup();
#endif 
	}

	sock_t Socket::_new(ip::PROTO protocol, ip::VER _v4)
	{
		if (protocol == ip::PROTO::TCP)
			return _newTCP();
		if (protocol == ip::PROTO::UDP)
			return _newUDP();

		return INVALID_SOCKET;
	}

	sock_t Socket::_newTCP()
	{
		return mSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	}

	sock_t Socket::_newUDP()
	{
		return mSock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	}

	int Socket::_bind(const sockaddr_t& addr)
	{
		return bind(mSock, (SOCKADDR*)&addr, sizeof(addr));
	}

	int Socket::_listen(int backlog)
	{
		return listen(mSock, backlog);
	}

	int Socket::_select() 
	{
		return 0;
	}

	int Socket::_connect(const sockaddr_t& addr)
	{
		return connect(mSock, (SOCKADDR*)&addr, sizeof(addr));
	}

	_pkg<sock_t, sockaddr_t> Socket::_accept()
	{
		sockaddr_t addr;
		int addrLen = sizeof(addr);
		sock_t sock = accept(mSock, (SOCKADDR*)&addr, &addrLen);
		return _pack(sock, addr);
	}

	int Socket::_send(const char* buf, int len, int flags)
	{
#if VS && WINDOWS
		return send(mSock, buf, len, flags);
#elif LINUX
		return write(mSock, buf, len, flags);
#else 
		
#endif 
	}

	int Socket::_recv(char* buf, int len, int flags)
	{
#if VS && WINDOWS
		return recv(mSock, buf, len, flags);
#elif LINUX
		return read(mSock, buf, len, flags);
#else 

#endif 
	}

	int Socket::_close()
	{
#if VS && WINDOWS
		return closesocket(mSock);
#elif LINUX
		return close(mSock);
#else 

#endif 
		return 0;
	}

	int Socket::_shutdown(int how)
	{
		return shutdown(mSock, how);
	}

}