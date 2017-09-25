// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#define PORT 8080
#define REPEAT 1000
using namespace std;
double getTimeDifference(struct timeval before, struct timeval after);
int main(int argc, char const *argv[])
{
    cout << "TCP Round trip in ms" << endl;
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "H";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "192.168.0.30", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    for(int i=0; i < REPEAT; i++){
        struct timeval tvalBefore, tvalAfter;
        gettimeofday (&tvalBefore, NULL);
        send(sock , hello , 1 , 0 );
        valread = read( sock , buffer, 1024);
        gettimeofday (&tvalAfter, NULL);
        double partA = getTimeDifference(tvalBefore, tvalAfter);
        cout << partA << endl;
    }
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