#include "SXC_Socket.h"

namespace sxc {

	int Socket::startup()
	{
#ifdef VS
		return WSAStartup(MAKEWORD(2, 2), &mWsaData);
#endif 
	}

	int Socket::cleanup()
	{
#ifdef VS
		return WSACleanup();
#endif 
	}


	int Socket::newSocket(IPPROTO ip_protocol) {
		if (ip_protocol == IPPROTO::TCP) {
			return newTCPSocket();
		}
		if (ip_protocol == IPPROTO::UDP) {
			return newUDPSocket();
		}
	}

	int	Socket::newTCPSocket() {
#ifdef VS
		mSd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
#endif 

		if (mSd != kInvalidSocket) {
			mIPProtocol = IPPROTO::TCP;
		}
		return mSd;
	}

	int	Socket::newUDPSocket() {
#ifdef VS
		mSd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
#endif 

		if (mSd != kInvalidSocket) {
			mIPProtocol = IPPROTO::UDP;
		}
		return mSd;
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
		mIPProtocol = IPPROTO::NONE;
		if (mSd == kInvalidSocket) return 0;
#ifdef VS
		return closesocket(mSd);
#endif 
	}

	int Socket::_shutdown(int how)
	{
		mIPProtocol = IPPROTO::NONE;
		if (mSd == kInvalidSocket) return 0;
#ifdef VS
		return shutdown(mSd, how);
#endif 
	}

}