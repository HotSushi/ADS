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
    int portNum = 7778;
 
    int client = getSocket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    server_address.sin_port = htons(portNum);

    if ((bind(client, (struct sockaddr*)&server_address, sizeof(server_address))) < 0) 
        error("couldnot bind socket");    
    socklen_t size = sizeof(server_address);               
    listen(client, 1);
    int server = accept(client, (struct sockaddr *)&server_address, &size);

    print("connected");
    int bufsize = 1024;
    char buffer[bufsize];
    while (server >= 0 )
    {
        print("waiting");
        recv(server, buffer, bufsize, 0);
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
