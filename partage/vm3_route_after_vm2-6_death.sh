ip route del fc00:1234:3::/64 via fc00:1234:4::36 dev eth2 metric 1024
ip route add fc00:1234:3::/64 via fc00:1234:ffff::10 dev tun0
sysctl -w net.ipv6.conf.all.forwarding=1
