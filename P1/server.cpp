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
void Q1TCP();

int main(){
    Q1TCP();
}
/*
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
*/

/* Server responds with an ack */
void Q1TCP()
{
    int server;
    server = startTCPServerSocket(7778, server);
    char buffer[1];
    recv(server, buffer, 1, 0);
    send(server, buffer, 1, 0);
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
