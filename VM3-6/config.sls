# Configuration eth1
# RAPPEL: eth0 est à vagrant, ne pas y toucher

## Désactivation de network-manager
NetworkManager:
  service:
    - dead
    - enable: False

##Configuration de VM3

#LAN2-6
eth1:
  network.managed:
    - enabled: True
    - type: eth
    - proto: none
    - enable_ipv4: false
    - ipv6proto: static
    - enable_ipv6: true
    - ipv6_autoconf: no
    - ipv6ipaddr: fc00:1234:2::36
    - ipv6netmask: 64

#LAN4-6
eth2:
  network.managed:
    - enabled: True
    - type: eth
    - proto: none
    - enable_ipv4: false
    - ipv6proto: static
    - enable_ipv6: true
    - ipv6_autoconf: no
    - ipv6ipaddr: fc00:1234:4::36
    - ipv6netmask: 64

## Configuration des routes :
routes:
  network.routes:
    - name: eth1
    - routes:
      - name: LAN1-6
        ipaddr: fc00:1234:1::/64
        gateway: fc00:1234:2::26
      - name: LAN3-6
        ipaddr: fc00:1234:3::/64
        gateway: fc00:1234:2::26
## Installation de iperf3
iperf3:
  pkg:
    - installed

## Installation de inetutils-inetd
inetutils-inetd:
  pkg:
    - installed
  service:
    - running
    - enable: True

## But enable ipv6 forwarding
net.ipv6.conf.all.forwarding:
  sysctl:
    - present
    - value: 1

## Suppression de la passerelle par défaut
ip route del default:
  cmd:
    - run

## Ajout dans la BDD de inetd
update-inetd --add "echo stream tcp6 nowait nobody internal":
  cmd:
    - run

service inetutils-inetd restart:
  cmd:
    - run



