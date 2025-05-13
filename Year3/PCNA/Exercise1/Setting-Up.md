# 2:
## b: Configuration
### Configuring hosts:
group 5
Host1:
```
sudo ip link set eth0 down
sudo ip addr add 192.168.i.10/24 broadcast 192.168.i.255 dev eth0
sudo ip link set eth0 up
sudo ip route add default via 192.168.i.1
```

Host2:
```
sudo ip addr add 192.168.i.20/24 broadcast 192.168.i.255 dev eth0
sudo ip link set eth0 up
sudo ip route add default via 192.168.i.1
```

Host3:
```
sudo ip addr add 192.168.i.30/24 broadcast 192.168.i.255 dev eth0
sudo ip link set eth0 up
sudo ip route add default via 192.168.i.1
```


### Configuring router:
Lan interface:
```
sudo ifconfig enp1s0f0 netmask 255.255.255.0
sudo ip addr add 192.168.i.1/24 dev eth0
sudo ip link set eth0 up
```
WLAN interface: 
```
sudo ip addr add 10.16.0.i/16 dev eth1
sudo ip link set eth1 up

```
Enable ip forwarding:
```
echo 1 | sudo tee /proc/sys/net/ipv4/ip_forward
# print 1 to the terminal then pipe it into the next command,
# tee take 1 and write it to the ip_forward kernel setting
# sudo is needed for writing to system file
```

ip: command for ip configuration
addr add: add ip address to an interface
link set x up: bring up interface
route add: add new routing rule to route table

## c: Testing
### Test connections:
From router:
```
ping -c 4 192.168.i.10    
ping -c 4 192.168.i.20    
ping -c 4 192.168.i.30    
```
Ping each ip addrese 4 times

From hosts to router1:
```
ping -c 4 192.168.i.1

```

From hosts to router2:

```
ping -c 4 10.16.0.200

```

### Configuring DNS:
Do this for each host
Print out /etc/resolv.conf:

```
cat /etc/resolv.conf
```

Set google DNS as the resolver for domain name lookup.

```
sudo echo "nameserver 8.8.8.8" > /etc/resolv.conf
```

Test DNS resolution:
```
ping -c 4 google.de
```

### Track router hops:
on any host or router
Ensure traceroute is install:
```
# sudo apt update
sudo apt install traceroute dnsutils
```
Use traceroute:
```
traceroute -I ict-ffm.de
# the flag -I stand for ICMP, by default it uses udp packets
```
result 13 hops for hosts, 12 for router
### Identify the IP addresses of medusa.fh-frankfurt.de
```
nslookup medusa.fh-frankfurt.de

```















