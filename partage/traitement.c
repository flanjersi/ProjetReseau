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
  // remplacer short par unint16_t ?
  unsigned short taille = strlen(aFragmenter);
  char *tableau = (char*) malloc((taille+2));

  ((unsigned short*) tableau)[0] = taille;
  int i;
  for (i = 2 ; i < taille +2 ; i++){
    tableau[i] = aFragmenter[i-2];
  }

  return tableau;
}

unsigned short taillentete_out(char* aReassembler){
  unsigned short taille = 0;

  taille = ((unsigned short*)aReassembler)[0];
  return taille;//28 OCTETS
}

unsigned short tailleauto(char *paquetIpV4) {
  //TODO

  return 0x00;
}
