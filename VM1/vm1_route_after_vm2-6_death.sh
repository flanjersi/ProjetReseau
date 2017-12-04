ip route del fc00:1234:4::/64 via fc00:1234:3::16 dev eth2 metric 1024
ip route add fc00:1234:4::/64 via fc00:1234:ffff::10 dev tun0