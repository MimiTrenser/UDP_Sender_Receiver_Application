#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in receiver_addr;
    char message[] = "Hello UDP Receiver";

    // 1. Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. Prepare receiver address
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(PORT);
    receiver_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 3. Send data
    sendto(sockfd, message, strlen(message), 0,
           (struct sockaddr *)&receiver_addr, sizeof(receiver_addr));

    printf("Message sent\n");

    close(sockfd);
    return 0;
}
