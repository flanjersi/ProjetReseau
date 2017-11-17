# Configuration eth1
# RAPPEL: eth0 est à vagrant, ne pas y toucher

## Désactivation de network-manager
NetworkManager:
  service:
    - dead
    - enable: False

## Suppression de la passerelle par défaut
ip route del default:
  cmd:
    - run

##Configuration de VM1
eth1:
  network.managed:
    - enabled: True
    - type: eth
    - proto: none
    - enable_ipv4: false
    - ipv6proto: static
    - enable_ipv6: true
    - ipv6_autoconf: no
    - ipv6ipaddr: fc00:1234:3::16
    - ipv6netmask: 64
eth2:
  network.managed:
    - enabled: True
    - type: eth
    - proto: none
    - enable_ipv4: false
    - enable_ipv6: true
    - ipv6proto: auto

net.ipv6.conf.all.forwarding:
  sysctl:
    - present
    - value: 1

## Configuration des routes :
## - LAN1-6 via VM2-6
## - LAN3-6 via VM1
# routes:
#   network.routes:
#     - name: eth1
#     - routes:
#       - name: LAN1-6
#         ipaddr: fc00:1234:1::/64
#         gateway: fc00:1234:1::26
#       - name: LAN3-6
#         ipaddr: fc00:1234:3::/64
#         gateway: 172.16.2.131
