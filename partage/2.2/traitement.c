#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <fcntl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <string.h>

#include "traitement.h"

char* taillentete_in(char* aFragmenter){
  unsigned short taille = strlen(aFragmenter);
  char *tableau = (char*) malloc((taille+2));

  tableau[0] = taille & 0xff;
  tableau[1] = (taille >> 8) & 0xff;

  for (int i = 2 ; i < taille +2 ; i++){
    tableau[i] = aFragmenter[i-2];
  }

  return tableau;
}

short taillentete_out(char* aReassembler){
  unsigned short taille = 0;

  taille = ((short*)aReassembler)[0];
  return taille;//28 OCTETS
}

short tailleauto(char *paquetIpV4) {
  //TODO

  return 0;
}
