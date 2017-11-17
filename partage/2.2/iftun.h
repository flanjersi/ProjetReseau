#ifndef IFTUN_H
#define IFTUN_H

/*
 * créé une interface virtuelle tun de nom dev
 */
int tun_alloc(char *dev);

/*
 * copie les données reçu depuis src vers dst
 */
void write_in_fd(int src, int dst);


#endif
