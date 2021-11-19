#pragma once

#include "env_info.h"

#ifdef VS
#include<Windows.h>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#else

#endif 

namespace sxc {

	namespace ip {
		enum class VER { _4, _6 };

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
	using sockaddr_t = SOCKADDR_IN; // Socket Address

#endif 
		// Invalid Socket
		constexpr sock_t INV_SOCKET =
#ifdef VS
		INVALID_SOCKET; // = ~0 uint64 (-1, int)
#else

#endif
		
		using saddr_t =
#ifdef VS
		SOCKADDR_IN;
#else 

#endif 