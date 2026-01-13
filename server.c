//**************************** UDP Sever Client chat Application ****************************** 
//  Copyright (c) 2021 Trenser 
//  All Rights Reserved 
//***************************************************************************** 
// 
// File       :server.c 
// Summary    :UDP server client chat application
// Note       :Client code on client.c
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
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // 1. Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // accept from any IP
    server_addr.sin_port = htons(PORT);

    // 3. Bind socket to port
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("UDP Receiver listening on port %d...\n", PORT);
    while(1)
    {
       // 4. Receive data
       int n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);

       buffer[n] = '\0';
       printf("Client [%s:%d]: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

       printf("Server: ");
       fgets(buffer, BUF_SIZE, stdin);
       sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, addr_len);
    }
    close(sockfd);
    return 0;
}
