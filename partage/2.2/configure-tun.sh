#!/bin/bash
# $1 correspond au nom du tunnel
# $2 correspond a l'ip du tunnel
# $3 correspond au lan distant
ip link set $1 up
zero="0"
ip addr add $2/64 dev $1

#Suppression ancienne route
ip route del $3 via $4 dev eth2 metric 1024
#Ajout de la nouvelle route
ip route add $3 via $2$zero dev $1
#Ajout de l'ip forwarding pour faire suivre dans le tunnel
sysctl -w net.ipv6.conf.all.forwarding=1
