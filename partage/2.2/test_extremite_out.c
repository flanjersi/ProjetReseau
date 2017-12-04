#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iftun.h"
#include "extremite.h"

int main (int argc, char **argv){

	if(argc != 2){
		printf("Usage: %s idTun\n", argv[0]);
		exit(1);
	}

	char *idTun = argv[1];

	char cmd[100];
	int fdTun;

	fdTun = tun_alloc(idTun);

	strcpy(cmd, "./configure-tun.sh");
  strcat(cmd, " ");
  strcat(cmd, argv[1]);


  printf("Configuration en cours\n");
  system("chmod +x configure-tun.sh");
  system(cmd);

  printf("Configuration finit, scrutation de l'entrée standard\n");

	ext_out("123", fdTun);

	return 0;
}
