libsxcsock.a: Socket.o SocketAddr.o
	ar rcv libsxcsock.a Socket.o SocketAddr.o 

Socket.o: Socket.cpp Socket.h SocketAddr.h SocketTypes.h SXCBasic.h
	g++ -std=c++17 -c Socket.cpp 

SocketAddr.o: SocketAddr.cpp Socket.h SocketAddr.h SocketTypes.h SXCBasic.h
	g++ -std=c++17 -c SocketAddr.cpp 

clean:
	rm *.o *.a 