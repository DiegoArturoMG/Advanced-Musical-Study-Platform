#define PAQUETE_DATAGRAMA_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

class PaqueteDatagrama
{
public:
	PaqueteDatagrama(char *, unsigned int, char *, int);
	PaqueteDatagrama(unsigned int);
	PaqueteDatagrama();
	~PaqueteDatagrama();
	void deleteDatos();
	char *obtieneDireccion();
	unsigned int obtieneLongitud();
	int obtienePuerto();
	char *obtieneDatos();
	void inicializaPuerto(int);
	void inicializaIp(char *);
	void inicializaDatos(char *);
private:
	char *datos; 			//Almacena datos
	char ip[16];			//Almacena la IP
	unsigned int longitud; 	//Almacena la longitud de la cadena de datos
	int puerto; 			//Almacena el puerto	
};