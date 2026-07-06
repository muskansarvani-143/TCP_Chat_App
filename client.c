#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define DATA_SIZE 1024
int main(){
    int sock;
    struct sockaddr_in server_addr;
    char recv_data[DATA_SIZE];
    char reply_data[DATA_SIZE];
    
    sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0){
        perror("sock");
        exit(EXIT_FAILURE);
    }
    printf("Socket created succesfully..\n");
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    inet_pton(AF_INET,"127.0.0.1",&server_addr.sin_addr);
    
    //Connect
    if(connect(sock, (struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
          perror("Connect");
          exit(EXIT_FAILURE);
    }
    printf("Connected to server successfully\n");
    
    while(1){
          printf("Client : \n");
          fgets(recv_data,DATA_SIZE,stdin);
          recv_data[strcspn(recv_data,"\n")] = '\0';
          send(sock,recv_data,strlen(recv_data) + 1,0);
          if(strcmp(recv_data,"exit") == 0)
               break;
               
          memset(reply_data,0,sizeof(reply_data));
          recv(sock,reply_data,DATA_SIZE,0);
          printf("Server : %s\n",reply_data);
          if(strcmp(reply_data,"exit") == 0)
              break;     
    }
    close(sock);
    
    return 0;
}
