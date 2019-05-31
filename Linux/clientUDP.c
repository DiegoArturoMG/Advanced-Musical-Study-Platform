/* UDP client in the internet domain */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

#define peticion "1"

void error(char *);

int main(int argc, char *argv[]){
  int sock, length, n;
  struct sockaddr_in server, from; // IP Addressing(ip, port, type) Stuff
  struct hostent *hp; // DNS stuff
  char buffer[256];

  fd_set readfds, masterfds;
  struct timeval timeout;

  if (argc != 3) { printf("Usage: %s <server_name> <port>\n",argv[0]);
    exit(1);
  }

  sock = socket(AF_INET, SOCK_DGRAM, 0);

  int yes = 1;

  if(setsockopt(sock,SOL_SOCKET,SO_BROADCAST,&yes,sizeof(int)) < 0){
    error("Error in setting Broadcast option");
    exit(0);
  }

  //if (sock < 0) error("socket");

  server.sin_family = AF_INET;
  hp = gethostbyname(argv[1]);

  if (hp==0) error("Unknown host");

  bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
  server.sin_port = htons(atoi(argv[2]));
  length=sizeof(struct sockaddr_in);

  //printf("Please enter the message: ");

  //bzero(buffer,256);

  //fgets(buffer,255,stdin);

  n=sendto(sock,peticion,sizeof(peticion),0,&server,length);

  if (n < 0) error("Sendto");


  timeout.tv_sec = 5;                    /*set the timeout to 10 seconds*/
  timeout.tv_usec = 0;

  FD_ZERO(&masterfds);
  FD_SET(sock, &masterfds);

  memcpy(&readfds, &masterfds, sizeof(fd_set));

  if (select(sock+1, &readfds, NULL, NULL, &timeout) < 0){
    perror("on select");
    exit(1);
  }

  if (FD_ISSET(sock, &readfds)){
    n = recvfrom(sock,buffer,256,0,&from, &length);
    if (n < 0) error("recvfrom");
    //write(1,"Got an ack: ",12);
    //write(1,buffer,n);
    printf("%s\n",buffer);

  }else{
    //Se envia otra ves
    printf("No se recibio del servidor\n");
  }

}

void error(char *msg){
  perror(msg);
  exit(0);
}