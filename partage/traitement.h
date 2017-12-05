#ifndef TRAITEMENT_H
#define TRAITEMENT_H

/**
 * Rajoute au début de la donnée la taille de la donnée entière.
 *
 * @param aFragmenter donnée a formaté
 * @return le nouveau tableau ayant été formaté
 */
char* taillentete_in(char* aFragmenter);


/**
 * Recupère la taille de la donnée
 *
 * @param aReassembler donnée formaté
 */
unsigned short taillentete_out(char* aReassembler);


/**
 * Recupère la taille de la donnée
 *
 * @param paquetIpV4 paquet ipV4 à analyser
 * @return taille du paquet ipV6 encapsuler dans l'ipV4
 */
unsigned short tailleauto(char *paquetIpV4);

#endif
