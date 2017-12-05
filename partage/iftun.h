#ifndef IFTUN_H
#define IFTUN_H

/**
 * Créé une interface virtuelle tun
 * @param dev nom de l'interface
 * @return -1 si erreur
 */
int tun_alloc(char *dev);

/**
 * copie les données reçu depuis src vers dst
 * @param src file descripteur source
 * @param dst file descripteur destination
 * @return
 */
int write_in_fd(int src, int dst);


#endif
