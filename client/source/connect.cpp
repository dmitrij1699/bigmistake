#ifndef CONNECT_CPP
#define CONNECT_CPP

#define port 7650

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include "header/connect.h"
#include <vector>
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

//	62.109.3.48

call::call(){
	


    sock= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  
	if (sock==-1){
		cout<<"socket failed"<< endl;
        exit(1);
	}

	memset(&stSockAddr, 0, sizeof (stSockAddr));

    stSockAddr.sin_family = PF_INET;
    stSockAddr.sin_port = htons(port);
    //stSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int err=inet_pton(PF_INET, "62.109.3.48", &stSockAddr.sin_addr); 
	if (err<0) {
		cout<<"inet_pton failed"<< endl;
        exit(1);
	}



	//if (bind(sock, (struct sockaddr*) &stSockAddr, sizeof (stSockAddr)) == -1) {
	//	cout<<"bind failed"<< endl;
     //   exit(1);
    //}

	//if ( listen(sock, 10)==-1) 
	//	cout<<"listen failed"<< endl;
      //  exit(1);



	if (connect(sock, (struct sockaddr*) &stSockAddr, sizeof (stSockAddr)) == -1) {
			perror("Ошибка: соединения");
			close(sock);
			exit(1);
		}
		/* выполнение операций чтения и записи ... */

		const char* buffer = "0011100";

		err =
		sendto(
		  sock,
		  buffer,
		  strlen( buffer ) + 1,
		  0,
		  ( struct sockaddr* )&stSockAddr,
		  sizeof( struct sockaddr_in )
		);
	
}

#endif