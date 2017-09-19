#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdexcept>
#include <unistd.h>
#include "Socket.h"
using namespace std;

void error(string);
void print(string);
int main()
{
    int server;
    //server = startTCPServerSocket(7778, server);

    struct sockaddr_in si_other;
    startUDPServerSocket(7778, server);
    socklen_t slen = sizeof(si_other);

    print("connected");
    int bufsize = 1024;
    char buffer[bufsize];
    while (server >= 0 )
    {
        print("waiting");
        recvfrom(server, buffer, bufsize, 0, (struct sockaddr *) &si_other, &slen);
        //recv(server, buffer, bufsize, 0);
        cout << buffer << endl;
        if(*buffer == '*')
            break;
    }
    close(server);
}

void error(string error)
{
    throw runtime_error(error);
}

void print(string string)
{
    cout << string << endl;
}
