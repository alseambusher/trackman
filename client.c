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
    server=gethostbyname(argv[1]);
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero((char*)&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    bcopy((char*) server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port=htons(portno);
    connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    char a[100];
    strcpy(a,"alse");
    int n=write(sockfd,a,strlen(a));
    strcpy(a,"");
    n=read(sockfd,a,100);
    if(n>0)
    printf("%s",a);
    close(sockfd);
}
