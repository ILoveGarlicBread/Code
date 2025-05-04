# Monitoring network trafic:
```
ping 10.16.0.200
```

On host 1:
```
ping -s 65507 10.16.0.i
```

The message of the ping command when using ping -M do -s 1473 to Router
1:
```
ping -M do -s 1473 10.16.0.i
```
ip header size is 20, icmp header size is 8
total size would be 1501

use
```
ifconfig | grep -i mtu
```
to check mtu size

use traceroute -I to determine routers:
```
traceroute -I ict-ffm.de
```
