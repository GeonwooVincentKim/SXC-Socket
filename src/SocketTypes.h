#pragma once

#include "SXCBasic.h"

#if VS
#define _WINSOCKAPI_
#include<Windows.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else

#endif 

namespace sxc {

	namespace ip {
		enum class VER { // Currently, support only ipv4 
			_4,
			_6
		};

		enum class PROTO {
			NONE = 0,
			TCP,
			UDP
		};
	}

#ifdef VS
	using sock_t = SOCKET; // Socket Descriptor 
	using sockaddr_t = SOCKADDR_IN; // Socket Address
#else
	using sock_t = int; // Socket Descriptor 
	using sockaddr_t = struct sockaddr_in; // Socket Address
	using SOCKADDR = struct sockaddr;
	constexpr sock_t INVALID_SOCKET = -1;
#endif 

}