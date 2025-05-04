Show the IP address of the hosts’ interface eth0
```
ip addr show eth0
```

Show the list of routes on Host 1:
```
ip route
```

Show the ARP table of Router 1:
```
ip neigh
```

Send the string "Hello!" to the server listening on port 80 hosted on Router 2:
```
nc 10.16.0.200 80
```
type in:
```
POST / HTTP/1.1
Host: 10.16.0.200
Content-Type: text/plain
Content-Length: 6

Hello!

```
note: press enter twice after typing Content-Length: 6

List all open TCP ports and processes on Host 1
```
sudo ss -tulnp
```

List all listening UDP ports on Host 1:
```
sudo ss -uln
```

Scan and list all open ports in the range of 1-1023 on the router Router 1 that are
reachable by Host 1:
```
nmap -p 1-1023 192.168.i.1
```

Scan and list all open ports and services of all clients on the private network
192.168.i.0/24:
```
sudo nmap -sV 192.168.i.0/24
# -sV enable version detection
```

Scan and list all open ports and services of all clients on the private network
10.16.0.0/16:
```
sudo nmap -sV 10.16.0.0/16
```

