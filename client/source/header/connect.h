#ifndef CONNECT_H
#define CONNECT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <string>



class call{
private:
    int sock;
    struct sockaddr_in stSockAddr;
    

public:
    
    call();
    void send();
    void revieve();
};

#endif