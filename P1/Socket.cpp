#include "Socket.h"

int getSocket(int net, int flow, int proto)
{
    int sockt = socket(net, flow, proto);
    if ( sockt < 0 ) throw std::runtime_error("Error: Initializing Socket");
    return sockt;
}
