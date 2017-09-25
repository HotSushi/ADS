// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <stdexcept>
#include <unistd.h>
#define PORT 8080
#define GB 1000000
#define KB 1000
#define LEN 1000000
#define REP 1000
using namespace std;
double getTimeDifference(struct timeval before, struct timeval after);
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[LEN] = {0};
    double tenGB_in_bytes = ((double)GB * KB)*10;
    double backup = tenGB_in_bytes;
    cout << "Q2 local 10 GB file" << endl;
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
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
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                           (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
    for(int i=0; i< REP ; i++){
        struct timeval tvalBefore, tvalAfter;
        gettimeofday (&tvalBefore, NULL);
        double hundMB_in_bytes = tenGB_in_bytes;
        while(true){
            valread = read( new_socket , buffer, LEN);
            hundMB_in_bytes -= valread;
            if(hundMB_in_bytes< 0) break;
        }
        gettimeofday (&tvalAfter, NULL);
        double partA = getTimeDifference(tvalBefore, tvalAfter);
        cout << partA<< endl;
        break;
    }
    close(server_fd);
    return 0;
}

// gets time in millisec
double getTimeDifference(struct timeval before, struct timeval after)
{
    double elapsedTime;
    elapsedTime = (after.tv_sec - before.tv_sec) * 1000.0;
    elapsedTime += (after.tv_usec - before.tv_usec) / 1000.0;
    return elapsedTime;
}