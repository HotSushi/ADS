/*
    Simple udp client
*/
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdexcept>
#include <unistd.h>
 
#define SERVER "127.0.0.1"
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to send data
using namespace std;
void die(char *s)
{
    perror(s);
    exit(1);
}
 
int main(void)
{
    struct sockaddr_in si_other;
    int s, i;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];
    char* message = "m";
 
    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        die("socket");
    }
 
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
     
    if (inet_aton(SERVER , &si_other.sin_addr) == 0) 
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }
 
    while(1)
    {
        long no, divider = 10000;
        cout << "Input no of packets to send" <<endl;
        cin >> no;
        //send the message
        for (long i = 0; i<no ;i++){
            if(i%divider == 0){
                cout << "Sent:" << i << endl;
                divider *= 10;
            }
            sendto(s, message, 1 , 0 , (struct sockaddr *) &si_other, slen);
        }
        sleep(3);
        sendto(s, "X", 1 , 0 , (struct sockaddr *) &si_other, slen);
        //receive a reply and print it
        //clear the buffer by filling null, it might have previously received data
        memset(buf,'\0', BUFLEN);
    }
 
    close(s);
    return 0;
}