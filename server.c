#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080 
#define DATA_SIZE 1024

int main(){
    int server_fd,client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char recv_data[DATA_SIZE] = {0};
    char reply_data[DATA_SIZE];
    
    //creating socket
    server_fd = socket(AF_INET,SOCK_STREAM,0);
    
    if(server_fd < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("socket created successfully\n");
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    //Binding
    if(bind(server_fd,(struct sockaddr *)&address,sizeof(address)) < 0){
         perror("Bind");
         exit(EXIT_FAILURE);
    }
    printf("Bind successfully\n");
    
    //Listen
    if(listen(server_fd,5) < 0){
         perror("Listen");
         exit(EXIT_FAILURE);
    }
    printf("Server waiting for connection...\n");
    
    //Accept
    client_fd = accept(server_fd,(struct sockaddr *)&address,(socklen_t *)&addrlen);
    if(client_fd < 0){
        perror("Accept");
        exit(EXIT_FAILURE);
    }
    printf("Connection created successfully...\n");
    
    while(1){
        memset(recv_data,0,sizeof(recv_data));
        
        recv(client_fd,recv_data,DATA_SIZE,0);
        printf("Client : %s\n",recv_data);
        
        if(strcmp(recv_data,"exit") == 0){
             break;
        }     
        
        printf("Server : \n");
        fgets(reply_data,DATA_SIZE,stdin);
        reply_data[strcspn(reply_data,"\n")] = '\0';
        
        send(client_fd,reply_data,strlen(reply_data) + 1,0);
        if(strcmp(reply_data,"exit") == 0 ){
             break;
        }     
    }
    close(client_fd);
    close(server_fd);

    return 0;
}

