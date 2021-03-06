#pragma once
#include "SXCBasic.h"
#include "SocketTypes.h"
#include <iostream>
#include <exception>

namespace sxc {

	int SAstartup();
	int SAcleanup();

	class Socket
	{
	public:
		Socket() = default;
		Socket(sock_t sock) : mSock(sock) {}
		~Socket() = default;

		sock_t	_new(ip::PROTO protocol = ip::PROTO::TCP, ip::VER ip_version = ip::VER::_4);
		sock_t	_newTCP();	
		sock_t	_newUDP(); 

		/*
		https://docs.microsoft.com/ko-kr/windows/win32/api/winsock/nf-winsock-getsockopt?redirectedfrom=MSDN
		*/
		int		_setOpt(int level, int optname, const void* optval, socklen_t optlen);
		int		_getOpt(int level, int optname, void* optval, socklen_t optlen);

		int		_bind(const sockaddr_t& addr);
		int		_listen(int backlog);
		int		_select();
		_pkg<sock_t, sockaddr_t> _accept();

		int		_connect(const sockaddr_t& addr);
		
		int		_send(const char* buf, int len, int flags = 0);
		int		_recv(char* buf, int len, int flags);

		int		_close();
		int		_shutdown(int how);

		bool	isValid() const { return (mSock != INVALID_SOCKET) && (mSock > sock_t(0)); }
		sock_t	getSocket()	const { return mSock; }

	private:
		sock_t	mSock = INVALID_SOCKET;
	};

}

