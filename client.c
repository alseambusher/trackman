#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
void main(int argc,char** argv){
    int sockfd,portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno=atoi(argv[2]);

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("ERROR opening socket");
        exit(1);
    }

    server=gethostbyname(argv[1]);
    if (server==NULL){
        printf("ERROR, no such port");
        exit(1);
    }
    bzero((char*)&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    bcopy((char*) server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port=htons(portno);
    connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    char data[1000];
    sprintf(data,"%d,%s",(int)strlen(argv[3]),argv[3]);
    int n=write(sockfd,data,strlen(data));
    if(n<0){
        printf("ERROR, unable to write to server");
        exit(1);
    }
    close(sockfd);
}
