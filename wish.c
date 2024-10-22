#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080 // You can adjust this port if needed

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    printf("\033[32m\"Introspection is the key to unlocking your fullest potential; knowing yourself is the first step.\"\033[0m\n\n");
    printf("                                                                                         - Zwique \n");
    printf("Have you thought about what you really wanted in life?\n");

    char flag[50];
    FILE *file = fopen("flag.txt", "r");
    if (file == NULL) {
        printf("Congrats!!! Now, run the nc instance to get the flag.");
        exit(1);
    }
    fread(flag, 1, 50, file);
    char buf[1008];

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    read(new_socket, buf, 1008);
    printf("I wish for you that you get %s", buf);
    close(new_socket);

    return 0;
}
