#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 54321
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    /* Fill server information */
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    socklen_t len = sizeof(servaddr);

    while (1) {
        /* Get number from user */
        printf("Enter a number (or 'q' to quit): ");
        fgets(buffer, MAXLINE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        /* Check if the user wants to quit */
        if (strcmp(buffer, "q") == 0) {
            printf("Client stopped.\n");
            break;
        }

        /* Send number to server */
        sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&servaddr, len);

        /* Receive result from server */
        int n = recvfrom(sockfd, buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
        buffer[n] = '\0';

        /* Print result */
        if (atoi(buffer) == 1) {
            printf("The number is prime.\n");
        } else {
            printf("The number is not prime.\n");
        }
    }

    close(sockfd);
    return 0;
}

