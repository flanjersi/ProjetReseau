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

##Configuration de VM3
#LAN4-6
eth1:
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

#LAN2-6    
eth2:            
  network.managed:                                                              
    - enabled: True           
    - type: eth                                                        
    - proto: none                                                   
    - enable_ipv6: True                          
    - ipv6proto: auto 

## But enable ipv6 forwarding
net.ipv6.conf.all.forwarding:
  sysctl:
    - present
    - value: 1

