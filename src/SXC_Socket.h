#pragma once

#include<iostream>

#include "platform_info.h"

#ifdef VS
#include<Windows.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")



#endif 

namespace sxc {

	enum class IPPROTO {
		IP = 0,
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

		// Socket Address
	using saddr_t =
#ifdef VS
	SOCKADDR_IN; 
#else 

#endif 
	class Socket
	{
	public:
		static void Startup();
		static void Cleanup();

		Socket() = delete;
		Socket(sd_t sd = 0) : mSd(sd) {};
		Socket(IPPROTO ip_protocol);
		~Socket();

		int _bind(const saddr_t& addr);
		int _listen(int backlog);
		int _connect(const saddr_t& addr);
		Socket _accept(saddr_t& addr);
		
		int _send(const Socket& sock, std::string_view buf, int flags = 0);
		int _send(const Socket& sock, const char* buf, int len, int flags = 0);

		int _recv(const Socket& sock, std::string& buf, int len, int flags = 0);
		int _recv(const Socket& sock, char* buf, int len, int flags);

		int _shutdown(int how);

		sd_t getSockDesc() const { return mSd; }
		bool hasBound() const { return mHasBound; }

	private:
		sd_t mSd;
		bool mHasBound;

#ifdef VS
		WSADATA mWsaData;
#endif 
	};

}

