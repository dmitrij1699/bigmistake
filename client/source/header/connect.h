#ifndef CONNECT_H
#define CONNECT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

#define port 7650

class connect {
private:
    int sock;
    
public:
    connect();
};

#endif