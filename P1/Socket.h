#ifndef SOCKET_H
#define SOCKET_H
#include <sys/socket.h>
#include <stdexcept>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <arpa/inet.h>

int getSocket(int, int, int);
int startTCPServerSocket(int, int&);
void startTCPClientSocket(int, std::string, int&);
void startUDPServerSocket(int portNumber, int &sockt);
void startUDPClientSocket(int portNum, std::string ip, int &sockt, sockaddr_in &server_address);


#endif
