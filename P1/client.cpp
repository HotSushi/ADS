#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdexcept>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "Socket.h"
using namespace std;

void error(string);

int main(){
    int client;
    startTCPClientSocket(7778, "127.0.0.1", client);
    int bufsize = 1024;
    char buffer[bufsize];
    string input = "";
    while(*buffer != 42)
    {
        cin >> buffer;
        send(client, buffer, bufsize, 0);
    }
    close(client);
        
}

void error(string error)
{
    throw runtime_error(error);
}

