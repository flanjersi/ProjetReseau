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

unsigned short tailleauto(char *paquetIpV4);

#endif
