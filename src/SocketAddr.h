#pragma once

#include "SXCBasic.h"
#include "SocketTypes.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>

namespace sxc {

	class SocketAddr
	{
	public:
		SocketAddr() = default;
		~SocketAddr() = default;
		SocketAddr(const sockaddr_t& addr) : mAddr(addr) {}
		SocketAddr(std::string_view ip, uint16_t port, int af = AF_INET) { setup(ip, port, af); }

		void		setup(std::string_view ip, uint16_t port, int af = AF_INET);
		void		clear() { memset(&mAddr, 0, sizeof(mAddr)); }

		void		setIP(std::string_view ip);
		std::string getIP();
		void		setPort(uint16_t port);
		uint16_t	getPort();
		void		setAF(int af);
		int			getAF();
		void		setRawData(sockaddr_t addr) { mAddr = addr; }
		sockaddr_t	getRawData() { return mAddr; }
		sockaddr_t& getRef() { return std::ref(mAddr); }
		const sockaddr_t& getCRef() { return std::cref(mAddr); }
	private:
		sockaddr_t mAddr{};
	};


}
