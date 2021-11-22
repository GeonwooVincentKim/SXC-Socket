# SXC-Socket
Simple Cross Compile Socket

## Dependencies
 - C++17

## Platforms
 - [X] Windows
 - [X] Linux
 - [ ] MacOS (I want it...)
 - [ ] Android (?)
 - [ ] Nintendo Switch (??!?)

## Test
 - [X] Windows10
 - [X] Ubuntu20.04
 - [ ] RaspberryPI4

## Lib Build(Linux)
```
git clone https://github.com/errorcode4319/SXC-Socket.git
cd SXC-Socket/src
make
```

## Sample Build
```
cd SXC-Socket/sample

#ServerSample
#g++ -std=c++17 -o server server.cpp -I<include path> -L<lib path> -lsxcsock
g++ -std=c++17 -o server server.cpp -I../src -L../src -lsxcsock
./server

#ServerSample
g++ -std=c++17 -o server server.cpp -I../src -L../src -lsxcsock
./client
```
