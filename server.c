#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>

int main() {

    char message[500];

    //create socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);


    //define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to specified ip and port
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    while(1) {
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);


    //receive message from client and display it
    recv(client_socket, &message, sizeof(message), 0);
    printf("\nClient: %s", message);
    }

    //close the connection
    close(server_socket);
}
