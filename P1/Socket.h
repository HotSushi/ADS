#ifndef SOCKET_H
#define SOCKET_H
#include <sys/socket.h>
#include <stdexcept>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

int getSocket(int, int, int);
int startTCPServerSocket(int);

#endif
