#include <stdio.h>
#include <stdlib.h>
#include "iftun.h"

int main (int argc, char** argv){
  if(argc < 2){
    printf("Usage\n");
    return 1;
  }
  
  int fd_tun = tun_alloc(argv[1]);
  if(fd_tun < 0){
    printf("erreur tun_alloc \n");
    return 1;
    
  }
      
  printf("appuyez sur une touche pour quitter : ");
  int t;
  scanf("%d", &t);
  
   
  write_in_fd(fd_tun, 1);
  printf("appuyez sur une touche pour quitter : ");
  scanf("%d", &t);
  
  return 0;
}
