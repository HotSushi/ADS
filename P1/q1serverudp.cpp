// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
using namespace std;
#define PORT 8080
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address, si_other;
    socklen_t slen = sizeof(si_other);
    int opt = 1;
    int addrlen = sizeof(address);
    int recv_len;
    char buffer[1024] = {0};
    char *hello = "x";
      
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
   
    while(true){
    	recvfrom(server_fd, buffer, 1, 0, (struct sockaddr *) &si_other, &slen);
    	sendto(server_fd, hello, 1, 0, (struct sockaddr *)&si_other, slen); 
    }
    return 0;
}