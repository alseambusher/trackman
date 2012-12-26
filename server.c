#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
void main(int argc,char** argv){
    int sockfd,portno,newsockfd;
    struct sockaddr_in serv_addr,cli_addr;
    portno=atoi(argv[1]);
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero((char*) &serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(portno);
    bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    listen(sockfd,5);
    socklen_t clilen;
    clilen=sizeof(cli_addr);
    newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
    char buffer[100];
    strcpy(buffer,"");
    int n=read(newsockfd,buffer,100);
    int i,j;
    for(i=0;i<strlen(buffer);i++)
        if(buffer[i]==',')
            break;
    for(j=i+1;j<strlen(buffer);j++)
        printf("%c",buffer[j]);
    close(sockfd);
    close(newsockfd);
}
