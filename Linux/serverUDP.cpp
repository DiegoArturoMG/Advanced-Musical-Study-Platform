#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include "SocketDatagrama.h"

#define puerto 5000
#define peticion "Do"

void error(char *msg){
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]){

  int sock, n;

  SocketDatagrama socket = SocketDatagrama(puerto);
  //socket.setBroadcast();

  char* Do = "Do";
  char* Re = "Re";
  char* Mi = "Mi";
  char* Fa = "Fa";
  char* Sol = "Sol";
  char* La = "La";
  char* Si = "Si";
  char* final = "\0";

  printf("Recibiendo...\n");
  while (1) {
    
    //Do
    PaqueteDatagrama datagramaRecibe1 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe1);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso1 =  PaqueteDatagrama((char*) Do, sizeof(Do), datagramaRecibe1.obtieneDireccion(), datagramaRecibe1.obtienePuerto());
    n = socket.envia(datagramaRegreso1);
    printf("Envia\n");

    //Re
    PaqueteDatagrama datagramaRecibe2 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe2);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso2 =  PaqueteDatagrama((char*) Re, sizeof(Re), datagramaRecibe2.obtieneDireccion(), datagramaRecibe2.obtienePuerto());
    n = socket.envia(datagramaRegreso2);
    printf("Envia\n");

    //Mi
    PaqueteDatagrama datagramaRecibe3 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe3);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso3 =  PaqueteDatagrama((char*) Mi, sizeof(Mi), datagramaRecibe3.obtieneDireccion(), datagramaRecibe3.obtienePuerto());
    n = socket.envia(datagramaRegreso3);
    printf("Envia\n");

    //Fa
    PaqueteDatagrama datagramaRecibe4 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe4);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso4 =  PaqueteDatagrama((char*) Fa, sizeof(Fa), datagramaRecibe4.obtieneDireccion(), datagramaRecibe4.obtienePuerto());
    n = socket.envia(datagramaRegreso4);
    printf("Envia\n");

    //Sol
    PaqueteDatagrama datagramaRecibe5 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe5);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso5 =  PaqueteDatagrama((char*) Sol, sizeof(Sol), datagramaRecibe5.obtieneDireccion(), datagramaRecibe5.obtienePuerto());
    n = socket.envia(datagramaRegreso5);
    printf("Envia\n");

    //La
    PaqueteDatagrama datagramaRecibe6 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe6);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso6 =  PaqueteDatagrama((char*) La, sizeof(La), datagramaRecibe6.obtieneDireccion(), datagramaRecibe6.obtienePuerto());
    n = socket.envia(datagramaRegreso6);
    printf("Envia\n");

    //Si
    PaqueteDatagrama datagramaRecibe7 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe7);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso7 =  PaqueteDatagrama((char*) Si, sizeof(Si), datagramaRecibe7.obtieneDireccion(), datagramaRecibe7.obtienePuerto());
    n = socket.envia(datagramaRegreso7);
    printf("Envia\n");

    //Final
    PaqueteDatagrama datagramaRecibe8 = PaqueteDatagrama(sizeof(char));
    n = socket.recibe(datagramaRecibe8);
    printf("Recibe\n");

    PaqueteDatagrama datagramaRegreso8 =  PaqueteDatagrama((char*) final, sizeof(final), datagramaRecibe8.obtieneDireccion(), datagramaRecibe8.obtienePuerto());
    n = socket.envia(datagramaRegreso8);
    printf("Envia\n");

  }
}