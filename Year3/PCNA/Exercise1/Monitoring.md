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

# Monitoring network protocol
Clear ARP cache on host 1 and router 1
```
sudo ip neigh flush all

```
On host 1:
```
curl http://ict-ffm.de
```

## Protocol stack of HTTP respone
from the bottom:
layer 2: 
ethernet 
- header size: 14 bytes
- trailer size: 4 
layer 3:
ip protocol header size: 20 to 60
layer 4:
tcp protocol header size: 20 to 60
layer 7:
http 


