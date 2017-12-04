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
#include "traitement.h"

char* taillentete_in(unsigned char* aFragmenter){
  unsigned short taille = sizeof(aFragmenter);
  unsigned char *tableau = malloc((taille+2) /* sizeof(char)*/);
  tableau[0] = taille & 0xff;
  tableau[1] = (taille >> 8) & 0xff;
  for (int i = 2 ; i < taille +2 ; i++){
    tableau[i] = aFragmenter[i-2];
  }
  return tableau;
}

short taillentete_out(unsigned char* aReassembler){
  unsigned short taille = 0;

  taille = ((short*)aReasembler)[0];
  return taille;28 OCTETS
}

int main (void){
  //printf("%d", sizeof(char));
  // unsigned short shorty = 257;
  // unsigned short sacrifice;
  // unsigned char chary[2];
  // chary[0] = shorty & 0xff;
  // printf("%d\n", chary[0]);
  // chary[1] = (shorty >> 8) & 0xff;
  // printf("%d\n", chary[1]);
  // sacrifice = ((short*)chary)[0];
  // printf("shorty : %d\n", shorty);
  // printf("sacrifice : %d\n", sacrifice);
  return 0;
}
