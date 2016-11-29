/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
   //Set up most of the variable needed
   int sockfd, newsockfd, portno;
   socklen_t clilen;
   char buffer[256];
   struct sockaddr_in serv_addr, cli_addr;
   int n;

   //Check if correct amount of arguments were given
   if (argc < 2) {
       fprintf(stderr,"ERROR, no port provided\n");
       exit(1);
   }

   //Set up a socket
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   //Error check the socket
   if (sockfd < 0) 
       error("ERROR opening socket");

   //initialize serv_addr to all NULLs
   bzero((char *) &serv_addr, sizeof(serv_addr));

   //configure the server sockaddr_in
   portno = atoi(argv[1]);
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);

   //bind the given socket to the server struct sockaddr_in
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
       error("ERROR on binding");

   //checks the given socket for connections, allowing up to five
   //connections to queue
   listen(sockfd,5);
   clilen = sizeof(cli_addr);

   //block process until you get a connection from sockfd.
   //from now on, all communications with that connection
   //should be performed through the newsockfd that's returned
   newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

   //error-check the new socket
   if (newsockfd < 0) 
       error("ERROR on accept");

   //set the entire buffer to NULL
   bzero(buffer,256);
   
   //read from the new file-descriptor as you would any other.
   n = read(newsockfd,buffer,255);

   //error-check the read
   if (n < 0)
       error("ERROR reading from socket");

   //Print whatever message you got and return a confirmation
   //of receipt to the client
   printf("Server| Here is the message: %s",buffer);
   n = write(newsockfd,"Server to Client| I got your message",36);

   //error-check the write
   if (n < 0)
       error("ERROR writing to socket");

   //close all file-descriptors and exit
   close(newsockfd);
   close(sockfd);
   return 0; 
}
