#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdexcept>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;

void error(string);

int main(){
    int portNum = 7778;
    string hostname = "127.0.0.1";
    struct sockaddr_in server_address;

    int client = socket(AF_INET, SOCK_STREAM, 0);
    if(client < 0) error ("couldnt open socket");

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(portNum);
    server_address.sin_addr.s_addr = inet_addr(hostname.c_str());

    if (connect(client,(struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        error("couldnt connect to server");

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

