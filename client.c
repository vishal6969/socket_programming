#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/socket.h>


#include<netinet/in.h>

int main() {

    //create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);


    //specify address for socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;


    //make connection
    int connect_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if(connect_status == -1) {
	
	printf("There was problem making connection");
    }


    //take user standard input
    char message[500];
    int i = 0;
    printf("\nYou: ");

    while(i < 500) {
        
	 scanf("%c", &message[i]);

	 //end message
	 if(i > 0 && message[i] == '\n' && message[i-1] == '\n') {
        
	    break;
	    message[++i] = '\0'; 
	 }

	 i++;
    }

    //send message
    send(network_socket, message, sizeof(message), 0);


    //close the connection
    close(network_socket);

    return 0;
}
