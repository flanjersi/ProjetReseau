Attention, il se peut que certains fichiers soit en CRLF au lieu de LF, si tun_alloc renvoie une erreur alors que le programme est lancé en sudo, il faut convertir les fichiers configTunnelVM*.txt en LF.

lancer toutes les VM via launch.bat
exécuter :

Pour créer l'interface tun0 et connecter les serveurs ipv4 entre eux :
    - sur VM1 : cd /mnt/partage
                ./tunnel64d configTunnelVM1.txt
    - sur VM3 : cd /mnt/partage
                ./tunnel64d configTunnelVM3.txt

Pour lancer le script qui reconfigure la route automatique lorsque VM2-6 n'est pas joignable
    - sur VM1-6 : cd /mnt/partage
                ./vm1-6_auto_route.sh
    - sur VM3-6 : cd /mnt/partage
                ./vm3-6_auto_route.sh

Faire les observations conséquentes avec wireshark ..