## Setup
1. Clone this repository on your local machine.
``git clone https://github.com/vishal6969/socket_programming.git``
2. Install MakeFile package on your system(skip this step if you already have it).
``sudo apt-get install make``
3. Navigate inside the repository folder and type below command
``make``
4. Open a second terminal(If you are on a virtual machine, you will have to create a new session using ssh).
5. In first terminal run the client program.
``./client``
6. In second terminal run the server program.
``./server``
7. Now you will be able to send message from client side to the server side using the standard input.

## Socket Programming

What we actually mean by sockets is the endpoints through which two programs or processes can talk to each other remotely with the help of some know protocols and network addresses.   
There are system defined functions available for creating a socket, making connection and sending/receving data through the connection.

![Socket-Diagram](https://i1.wp.com/aticleworld.com/wp-content/uploads/2017/05/SocketProgramTcp-min.jpg?resize=565%2C732&ssl=1)

### Steps to create a client using TCP/IP  API
* Create a socket using the socket() function in c.
* Initialize the socket address structure  as per the server and connect the socket to the address of the server using the connect();
* Receive and send the data using the recv() and send() functions.
* Close the connection by calling the close() function.

### Steps to create a server using TCP/IP API
* Create a socket using the socket() function in c.
* Initialize the socket address structure and bind the socket to an address using the bind() function.
* Listen for connections with the listen() function.
* Accept a connection with the accept() function system call. This call typically blocks until a client connects to the server.
* Receive and send data by using the recv() and send() function in c.
* Close the connection by using the close() function.
