#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

#define port 7650


int main(){
    struct sockaddr_in stSockAddr;
    int i= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  
    stSockAddr.sin_family = PF_INET;
    stSockAddr.sin_port = htons(port);
    stSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);


	if (bind(i, (struct sockaddr*) &stSockAddr, sizeof (stSockAddr)) == -1) {
        exit(1);
    }

    if ( listen(i, 10)==-1) 
        exit(1);


	for (;;) {
		int iConnect = accept(i, 0, 0);

		if (iConnect < 0) {
			close(i);
			exit(EXIT_FAILURE);
		}

		/* выполнение операций чтения и записи ... */

		shutdown(iConnect, SHUT_RDWR);

		close(i);
	}

    return 0;
}