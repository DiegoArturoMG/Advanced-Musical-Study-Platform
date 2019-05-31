#define SOCKET_DATAGRAMA_H_

#include "PaqueteDatagrama.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <iostream>

class SocketDatagrama
{
public:
	SocketDatagrama(int);
	~SocketDatagrama();
	//Recibe un paquete tipo datagrama proveniente de este socket
	int recibe(PaqueteDatagrama & paquete);
	//Envia un paquete tipo datagrama desde este socket 
	int envia(PaqueteDatagrama & paquete);
	void setBroadcast();
	void unsetBroadcast();
	int getSocketInt();
private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s; //ID socket
};