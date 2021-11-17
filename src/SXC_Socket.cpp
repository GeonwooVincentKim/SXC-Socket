#include "SXC_Socket.h"

namespace sxc {

	void Socket::Startup()
	{
#ifdef VS
		auto ret = WSAStartup(MAKEWORD(2, 2), &mWsaData);
		if (ret != 0) throw std::runtime_error("WSA 2.2 Startup Failed");
#endif 
	}

	void Socket::Cleanup()
	{
	}

	Socket::Socket(IPPROTO ip_protocol)
	{
	}

	Socket::~Socket()
	{
	}

	int Socket::_bind(const saddr_t& addr)
	{
		return 0;
	}

	int Socket::_listen(int backlog)
	{
		return 0;
	}

	int Socket::_connect(const saddr_t& addr)
	{
		return 0;
	}

	Socket Socket::_accept(saddr_t& addr)
	{
		return Socket();
	}

	int Socket::_send(const Socket& sock, const char* buf, int len, int flags)
	{
		return 0;
	}

	int Socket::_recv(const Socket& sock, char* buf, int len, int flags)
	{
		return 0;
	}

	int Socket::_close()
	{
		return 0;
	}

	int Socket::_shutdown(int how)
	{
		return 0;
	}

}