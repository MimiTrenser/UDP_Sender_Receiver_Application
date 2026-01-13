//**************************** UDP Sever Client chat Application ******************************
//  Copyright (c) 2021 Trenser
//  All Rights Reserved
//*****************************************************************************
//
// File       :client.c
// Summary    :UDP server client chat application
// Note       :server code on server.c
// Author     :Mimi C.S
// Date       :13/01/2026
//
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024
//******************************.main.******************************
//Purpose : UDP char server client application
//Inputs  : data from client
//Outputs : data to server
//Return  :
//Notes   :
//**********************************************************************************
int main() 
{
    int sockfd;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    while (1) 
    {
        printf("Client: ");
        fgets(buffer, BUF_SIZE, stdin);
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, addr_len);
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);
        buffer[n] = '\0';
        printf("Server: %s", buffer);
    }

    close(sockfd);
    return 0;
}
