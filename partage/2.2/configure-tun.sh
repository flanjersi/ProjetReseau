ip link set $1 up
ip addr add fc00:1234:ffff::1/64 dev $1
