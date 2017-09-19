#include<ctime>
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
void Q1TCP();

int main()
{
    Q1TCP();
}
/*
int main(){
    int client;
    //startTCPClientSocket(7778, "127.0.0.1", client);
    struct sockaddr_in si_other;
    startUDPClientSocket(7778, "127.0.0.1", client, si_other);
    int bufsize = 1024;
    char buffer[bufsize];
    string input = "";
    while(*buffer != 42)
    {
        cin >> buffer;
        //send(client, buffer, bufsize, 0);
       sendto(client, buffer, bufsize, 0, (struct sockaddr *)&si_other, sizeof(si_other)); 
    }
    close(client);
        
}
*/
void Q1TCP()
{
    int client;
    startTCPClientSocket(7778, "127.0.0.1", client);
    char buffer[1] = {'x'};
    clock_t begin = clock();
    send(client, buffer, 1, 0);
    recv(client, buffer, 1, 0);
    clock_t end = clock();
    double elapsed_sec = double(end - begin)/ CLOCKS_PER_SEC;
    cout << "Elaspsed Time:" << elapsed_sec << endl;
    close(client);
}

void error(string error)
{
    throw runtime_error(error);
}

