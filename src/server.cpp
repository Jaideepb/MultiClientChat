// Chat-Server
#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/time.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

using namespace std;
int sockfd,highfd;
fd_set readfds;

void SetSelectFDs() {
	if(FD_ISSET(sockfd,&readfds)){
		accept(sockfd,NULL,NULL);	
	}
}

int main() {
	struct addrinfo serv,*res;
	struct timeval tv;
	int on=1;

	FD_ZERO(&readfds);
	
	serv.ai_family = AF_UNSPEC;
	serv.ai_socktype = SOCK_STREAM;
	serv.ai_flags = AI_PASSIVE;

	if(getaddrinfo(NULL,MYPORT,&hints,&res) !=0) {
		perror("getaddrinfo");
	}
	
	if((sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol)) <0) {
		perror("socket");
	}
	
	setsockopt(sockfd,SOL_SOCKET,SO_REUSERADDR,&on,sizeof(int));
	FD_SET(sockfd,&readfds);

	if(bind(sockfd,res->ai_addr,res->ai_addrlen)<0) {
		perror("bind");
	}

	if(listen(sockfd,MCONN)<0) {
		perror("listen");
	}
	highfd = sockfd;

	while(1) {
		SetSelectFDs();
		tv.tv_sec = 2;
		tv.tv_usec = 0;
		
		result = select(highfd+1,&readfds,NULL,NULL,&tv);
		if(result<1) {
			perror("select");
		}
		else if(result==0) {
			cout<<".";
		}
		else {
			ListenConn();
		}
	}

	return 0;
}
