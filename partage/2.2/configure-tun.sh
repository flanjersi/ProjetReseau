#!/bin/bash
# $1 correspond au nom du tunnel
# $2 correspond a l'ip du tunnel
# $3 correspond au lan distant
ip link set $1 up
zero="0"
ip addr add $2/64 dev $1
ip route add $3 via $2$zero dev $1