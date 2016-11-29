#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
   perror(msg);
   exit(0);
}

int main(int argc, char *argv[])
{
   //Set up most of the variables you'll need
   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;
   char buffer[256];

   //Check if the arguments are superficially
   //adequate
   if (argc < 3) {
       fprintf(stderr,"Client| usage %s hostname port\n", argv[0]);
       exit(0);
   }
  
   //get the port number from the cmd-arguments
   portno = atoi(argv[2]);
  
   //establish a socket
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   //error check the connection
   if (sockfd < 0) 
       error("ERROR opening socket");

   //Find to a named server, and error-check
   server = gethostbyname(argv[1]);
   if (server == NULL) {
       fprintf(stderr,"ERROR, no such host\n");
       exit(0);
   }

   //set the serv_addr to NULL
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;

   //copy the name of the server to serv_addr
   bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

   //convert the host port byte-order to the network port byte-order 
   serv_addr.sin_port = htons(portno);
   
   //connect the sockfd to the specified server
   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
       error("ERROR connecting");
   printf("Client| Please enter the message: ");

   //set the buffer to all NULL, get a message, and write to the socket
   bzero(buffer,256);
   fgets(buffer,255,stdin);
   n = write(sockfd,buffer,strlen(buffer));
   if (n < 0) 
       error("ERROR writing to socket");

   //set the buffer to all NULL, get a message, and write to the socket
   bzero(buffer,256);
   n = read(sockfd,buffer,255);
   if (n < 0) 
       error("ERROR reading from socket");
   printf("%s\n",buffer);

   //close the socket file-descriptor and exit
   close(sockfd);
   return 0;
}
