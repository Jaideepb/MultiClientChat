#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>
#include<errno.h>
#include "data.h"

using namespace std;
int sockfd;

int main(int argc,char *argv[]) {
	/*
	if(argc<3) {
		cout<<"Usage ./client <Username> <Password>\n";
		exit(1);
	}

	string uName(argv[1]);	// Username
	string uPass(argv[2]);	// Password
	
	 */

	int logopt;
	struct addrinfo hints;
	
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if(getaddrinfo("127.0.0.1",MYPORT,&hints,&res)!=0) {
		perror("getaddrinfo");
	}
	
	sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);

	if(sockfd<0) {
		perror("socket");
	}
	
	if((result =connect(sockfd,res->ai_addr,res->ai_addrlen))<0) {
		perror("connect");
	}

	cout<<"Enter Option: 1: NewUser-Register 2:Login => ";
	cin>>logopt;
	
	if(logopt==REGISTER) {
		logStatus=REGISTER;

		while(logStatus==REGISTER) {
			struct 
			cout<<"Username : ";
			cin>>uName;
			cout<<"Password : ";
			cin>>uPass;	
			
			send(
		


	}




	while(1) {
		


	}

	
	return 0;
}

