#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "extremite.h"
#include "iftun.h"

typedef struct CfgTun {
  char *nameTun;
  char *inIp;
  char *inPort;
  char *options;
  char *outIp;
  char *outPort;
} CfgTun;

typedef struct Entry {
  char *key;
  char *value;
} Entry;


Entry readEntry(char* string){
  Entry entry;

  char tmp[512];
  int cpt = 0;

  for(int i = 0 ; string[i] != '\0' && string[i] != '\n' && string[i] != '\t'; i++){
    if(string[i] == ' ') continue;

    if(string[i] == '='){
      entry.key = (char*) malloc(sizeof(char) * cpt);
      tmp[cpt] = '\0';
      strcpy(entry.key, tmp);
      cpt = 0;
    }
    else {
      tmp[cpt] = string[i];
      cpt++;
    }
  }

  tmp[cpt] = '\0';
  entry.value = (char*) malloc(sizeof(char) * cpt);
  strcpy(entry.value, tmp);

  return entry;
}

CfgTun* readCfgFile(char *fileName){
  CfgTun *cfgTun = (CfgTun*) malloc(sizeof(CfgTun));

  FILE *cfgFile = fopen(fileName, "r");
  if(cfgFile == NULL){
    printf("Erreur ouverture fichier");
    return NULL;
  }

  size_t len = 0;
  ssize_t read;
  char *line = NULL;


  Entry entry;
  int cptLine = 1;
  while((read = getline(&line, &len, cfgFile)) != -1){
    if(line[0] == '#') continue;

    entry = readEntry(line);

    if(strcmp(entry.key, "tun") == 0){
      cfgTun->nameTun = (char*) malloc(sizeof(char) * strlen(entry.key));
      strcpy(cfgTun->nameTun, entry.value);
    }
    else if(strcmp(entry.key, "inip") == 0) {
      cfgTun->inIp = (char*) malloc(sizeof(char) * strlen(entry.key));
      strcpy(cfgTun->inIp, entry.value);
    }
    else if(strcmp(entry.key, "inport") == 0) {
      cfgTun->inPort = (char*) malloc(sizeof(char) * strlen(entry.key));
      strcpy(cfgTun->inPort, entry.value);
    }
    else if(strcmp(entry.key, "options") == 0) {
      cfgTun->options = (char*) malloc(sizeof(char) * strlen(entry.key));
      strcpy(cfgTun->options, entry.value);
    }
    else if(strcmp(entry.key, "outip") == 0) {
      cfgTun->outIp = (char*) malloc(sizeof(char) * strlen(entry.key));
      strcpy(cfgTun->outIp, entry.value);
    }
    else if(strcmp(entry.key, "outport") == 0){
      cfgTun->outPort = (char*) malloc(sizeof(char) * strlen(entry.key));
      strcpy(cfgTun->outPort, entry.value);
    }
    else{
      fprintf(stderr, "Erreur à la ligne %d : clé %s incorrecte\n", cptLine, entry.key);
      return NULL;
    }

    cptLine++;
  }

  fclose(cfgFile);

  return cfgTun;
}


int main (int argc, char **argv){

  if(argc != 2){
    printf("Usage : %s configTunnel.txt\n", argv[0]);
    return 0;
  }

  CfgTun *cfg = readCfgFile(argv[1]);

  if(cfg == NULL){
    return 0;
  }

  int fdTun = tun_alloc(cfg->nameTun);

  //TODO Config tun

	int f = fork();
	if(f < 0){
		perror("Fork\n");
		exit(1);
	}
	else if(f == 0){
		sleep(2);
    ext_out(cfg->outPort, fdTun);
	}
	else {
    ext_in(cfg->inIp, cfg->inPort, fdTun);
  }

  return 1;
}
