through_tun=false
while true
do
    if ping6 -c 1 fc00:1234:2::26 &> /dev/null
    then
        echo 1
        if $through_tun ; then
            through_tun=false
            ip route del fc00:1234:3::/64 via fc00:1234:4::3 dev eth2
            ip route add fc00:1234:3::/64 via fc00:1234:2::26 dev eth1
        fi
    else
        echo 0
        if ! $through_tun ; then
            through_tun=true
            ip route del fc00:1234:3::/64 via fc00:1234:2::26 dev eth1
            ip route add fc00:1234:3::/64 via fc00:1234:4::3 dev eth2
        fi
    fi
    sleep 1
done