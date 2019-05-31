#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include "SocketDatagrama.h"
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <vector>

using namespace std;

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

#define puerto 5000
#define peticion "1"
#define broadcast "192.168.0.5"

static void handle_size(struct mg_connection *nc, struct http_message *hm) {
	char query[256];
	mg_get_http_var(&hm->body, "query", query,sizeof(query));

	int sock, n;

	SocketDatagrama socket = SocketDatagrama(puerto);
	//socket.setBroadcast();

	char respuesta[100] = "";
	//respuesta = (char*)malloc(1024);
	//strcat(respuesta, "");

	while(true){
		cout << "<=>" <<respuesta << endl;

		PaqueteDatagrama datagramaEnvia = PaqueteDatagrama((char*)peticion, sizeof(peticion),broadcast, puerto);
		n = socket.envia(datagramaEnvia);
    	printf("Se ha enviado\n");

		PaqueteDatagrama datagramaRecibe = PaqueteDatagrama(256);
		n = socket.recibe(datagramaRecibe);
		printf("Se ha recibido");
		
		char *respuestaDatagram;
		respuestaDatagram = (char*)datagramaRecibe.obtieneDatos();

		if(*respuestaDatagram == '\0'){
			break;
		}
	
		printf("\n->%s\n",respuestaDatagram);
		
		strcat(respuesta, respuestaDatagram);
		strcat(respuesta, "&nbsp;");

		//cout << respuesta << endl;

		//free(respuestaDatagram);
	}

	cout << "\n==>" << respuesta << endl;
	
	sprintf(query, "->%s", respuesta);
	printf("IP enviada: %s\n", respuesta);

	mg_send_head(nc,200,strlen(respuesta), "Content-Type: text/plain");
	mg_printf(nc, "%s", respuesta);
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
	char query[256];
 	struct http_message *hm = (struct http_message *) p;

	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/search") == 0) { 
			
			mg_get_http_var(&hm->body, "query", query,sizeof(query));
			printf("Cadena introducida: %s\n",query);

		    handle_size(nc, hm);
		}else{
			mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
		}
	}

}

int main(void) {
	struct mg_mgr mgr;
	struct mg_connection *nc;
	mg_mgr_init(&mgr, NULL);

	printf("Starting web server on port %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		return 1;
	}
	// Set up HTTP server parameters
	mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "www"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for (;;) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
	return 0;
}
