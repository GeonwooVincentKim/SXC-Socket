#pragma once

#include<iostream>
#include<exception>

#include "platform_info.h"

#ifdef VS
#include<Windows.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")



#endif 

namespace sxc {

	enum class IPPROTO {
		NONE = 0,
		IP,
		TCP,
		UDP, 
		/* 
		ICMP,
		IGMP,
		GGP,
		PUP,
		IDP,
		ND
		*/
	};

	// Socket Descriptor Type 
	using sd_t =
#ifdef VS
	SOCKET; // = uint64_t 
#else

#endif 
	constexpr sd_t kInvalidSocket =
#ifdef VS
	INVALID_SOCKET; // = ~0 uint64 (-1, int)
#else

#endif

		// Socket Address
	using saddr_t =
#ifdef VS
	SOCKADDR_IN; 
#else 

#endif 
	class Socket
	{
	public:
		static int startup();
		static int cleanup();

		Socket() = default;
		Socket(const Socket& ref) = default;
		Socket(IPPROTO ip_protocol) { newSocket(ip_protocol); };
		~Socket() { _close(); };

		int		newSocket(IPPROTO ip_protocol);
		int		newTCPSocket();	
		int		newUDPSocket(); 

		int		_bind(const saddr_t& addr);
		int		_listen(int backlog);
		int		_connect(const saddr_t& addr);
		Socket	_accept(saddr_t& addr);
		
		int		_send(const Socket& sock, const char* buf, int len, int flags = 0);
		int		_recv(const Socket& sock, char* buf, int len, int flags);

		int		_close();
		int		_shutdown(int how);

		sd_t	getSockDesc()	const { return mSd; }
		bool	isValidSocket() const { return mSd != kInvalidSocket; }
		IPPROTO getIPProtocol() const { return mIPProtocol; }
		bool	hasBound()		const { return mHasBound; }

	private:
		sd_t	mSd			= 0;
		IPPROTO mIPProtocol = IPPROTO::NONE;
		bool	mHasBound	= false;

#ifdef VS
		static WSADATA mWsaData;
#endif 
	};

}

