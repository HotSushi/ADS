#include "Socket.h"

int getSocket(int net, int flow, int proto)
{
    int sockt = socket(net, flow, proto);
    if ( sockt < 0 ) throw std::runtime_error("Error: Initializing Socket");
    return sockt;
}

int startTCPServerSocket(int portNumber, int &sockt)
{
    sockt = getSocket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    server_address.sin_port = htons(portNumber);

    if ((bind(sockt, (struct sockaddr*)&server_address, sizeof(server_address))) < 0) 
        throw std::runtime_error("Error: Initializing Socket");
  
    socklen_t size = sizeof(server_address);               
    listen(sockt, 1);
    int server = accept(sockt, (struct sockaddr *)&server_address, &size);
    return server;
}

void startTCPClientSocket(int portNum, std::string ip, int &sockt)
{
    struct sockaddr_in server_address;

    sockt = socket(AF_INET, SOCK_STREAM, 0);
    if(sockt < 0) throw std::runtime_error("couldnt open socket");

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(portNum);
    server_address.sin_addr.s_addr = inet_addr(ip.c_str());

    if (connect(sockt,(struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        throw std::runtime_error("couldnt connect to server");
}

void startUDPServerSocket(int portNumber, int &sockt)
{
    sockt = getSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    server_address.sin_port = htons(portNumber);

    if ((bind(sockt, (struct sockaddr *)&server_address, sizeof(server_address))) < 0) 
        throw std::runtime_error("Error: Initializing Socket");
}

void startUDPClientSocket(int portNum, std::string ip, int &sockt, sockaddr_in &server_address)
{
    sockt = getSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(portNum);
    server_address.sin_addr.s_addr = inet_addr(ip.c_str());
}
