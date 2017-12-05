#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>

#include <linux/ioctl.h>
#include <linux/if.h>
#include <linux/if_tun.h>

#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "iftun.h"

#include "extremite.h"



int socket_to_tun(int socket, int tun) {
  char buffer[1500];

  int nbrChar = recv(socket, buffer, 1500, 0);

  if(nbrChar < 0) {
    perror("read");
    return -1;
  }
  if(write (tun, buffer, nbrChar) < 0){
    perror("write");
    return -1;
  }

  return 1;
}



int ext_out (char* port, int fd) {
	int len, on = 1;

	struct addrinfo * resol;
	struct addrinfo indic = {
    AI_PASSIVE,
    AF_INET,
    SOCK_STREAM,
    0, 0,
    NULL, NULL, NULL
  };

  struct sockaddr_in client;

  int socketServer, socketClient;

	printf("Ecoute sur le port %s\n", port);

  int err = getaddrinfo(NULL, port, &indic, &resol);
  if (err < 0){
		fprintf(stderr,"Résolution: %s\n", gai_strerror(err));
		exit(2);
	}

	if ((socketServer = socket(resol->ai_family, resol->ai_socktype, resol->ai_protocol)) < 0) {
		perror("allocation de socket");
		exit(3);
	}
	printf("le numéro de la socket serveur est %i.\n", socketServer);

	if (setsockopt(socketServer, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
		perror("option socket");
		exit(4);
	}

	printf("Option initialisée\n");

	if (bind(socketServer , resol->ai_addr, sizeof(struct sockaddr_in)) < 0) {
		perror("bind");
		exit(5);
	}
	freeaddrinfo(resol);

	printf("Bind reussi\n");

	if (listen(socketServer, SOMAXCONN) < 0) {
		perror("listen");
		exit(6);
	}

	printf("Le serveur écoute ... \n");

	while(1) {
		len = sizeof(struct sockaddr_in);
		socketClient = accept(socketServer, (struct sockaddr *) &client, (socklen_t*) &len);

        if(socketClient < 0 ) {
            perror("accept");
            exit(7);
        }

        char hotec[NI_MAXHOST];
            char portc[NI_MAXSERV];

        err = getnameinfo((struct sockaddr*)&client, len, hotec, NI_MAXHOST, portc, NI_MAXSERV, 0);

        if (err < 0) fprintf(stderr,"résolution client (%i): %s\n", socketClient, gai_strerror(err));
        else printf("Connexion client reussi: fd = %i /// ip = %s /// port = %s\n", socketClient, hotec, portc);

        while(1) {
            int err = socket_to_tun(socketClient, fd);
            if(err == -1) {
                fprintf(stderr, "Erreur redirection client à tunnel\n");
                break;
            }
        }
    }
	close(socketServer);

    return 0;
}


int ext_in(char* ipServ, char* port, int fdTun) {
	char ip[INET_ADDRSTRLEN];

  struct addrinfo *resol;
  int soc;

	if (getaddrinfo(ipServ, port, NULL, &resol) < 0 ){
		perror("résolution adresse");
		exit(2);
	}

	inet_ntop(resol->ai_family, resol, ip, INET_ADDRSTRLEN);

	soc = socket(resol->ai_family, resol->ai_socktype, resol->ai_protocol);

  if (socket < 0) {
		perror("allocation de socket");
		exit(3);
	}

	printf("le numéro de la socket est : %i\n", soc);

	printf("Tentative de connexion à %s /// ip = %s sur le port %s \n", ipServ, ip, port);

  int c = connect(soc, resol->ai_addr, sizeof(struct sockaddr_in));
	if (c < 0) {
		perror("connection");
		exit(4);
	}

	printf("Connexion réussi\n");

	freeaddrinfo(resol);

	while (1) {
		if(write_in_fd(fdTun, soc) < 0){
      break;
    }
	}

	close(soc);

	return 0;
}

int makeExtInOut(char *ipOut, char* portOut, char *portIn, int fdTun) {
    int f = fork();

    if(f < 0){
	  perror("Fork\n");
	  return -1;
	}
	else if(f == 0){
	  sleep(5);
      ext_in(ipOut, portOut, fdTun);
    }
	else {
      ext_out(portIn, fdTun);
    }
}
