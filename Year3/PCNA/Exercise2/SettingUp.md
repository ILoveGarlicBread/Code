# Enable IPV6
```
sudo sysctl -w net.ipv6.conf.all.disable_ipv6=0
sudo sysctl -w net.ipv6.conf.default.disable_ipv6=0
```

To enable on a specific interface:
```
sudo sysctl -w net.ipv6.conf.eth0.disable_ipv6=0
```

Add to /etc/sysctl.conf for persistent setting:
```
sudo nvim /etc/sysctl.conf

net.ipv6.conf.all.disable_ipv6=0
net.ipv6.conf.default.disable_ipv6=0

```

Apply
```
sudo sysctl -p
```

# Checking
Check link-local address (automatically generarted with SLAAC):
```
ip -6 addr show
```
Check all multicast group
```
ip -6 maddr show
```

in wireshark use filter: icmpv6
check for:
Router Solicitation (RS) messages from the host
Router Advertisement (RA) responses from the router (if configured)
Duplicate Address Detection (DAD) messages (Neighbor Solicitation/Advertisement)

# Add Link-local address to an interface
Prefix: Always starts with fe80::/10
```
sudo ip -6 addr add fe80::1234:abcd:5678:90ab/64 dev eth0
```
The system sends Neighbor Solicitation (NS) to check for duplicate addresses (DAD).
If no duplicate is found, the address becomes valid.
Confirm with:
```
ip -6 addr show dev eth0
```
There should be 2 addresses

Used for essential local communication, especially:
   - Router discovery (Router Solicitation/Advertisement)
   - Neighbor Discovery Protocol (NDP)
   - Automatic address configuration
Required even if no global IPv6 address is configured

# Testing
Find all link-local addresses on the link using multicast
Run on router or any host
```
ping6 -I eth0 ff02::1

```
Get link-local addresses of responding hosts
```
ip -6 neigh

```
Ping between hosts using link-local addresses
must specify the interface when using link-local addresses,
since they are only unique per link.
```
ping6 fe80::1234:abcd:5678:9abc%eth0
```

# Ping Router 2 from Router 1 via link-local
```
ip -6 neigh
ping6 fe80::1a2b:3c4d:5e6f:7a8b%eth1
```
clear cache before test:
```
ip -6 neigh flush all
```
# Solicited-Node Multicast Address
Format: ff02::1:ffXX:XXXX
Derived by appending the last 24 bits of the IPv6 address to ff02::1:ff00:0/104.
Used by Neighbor Solicitation (NS) messages during:
  - Duplicate Address Detection (DAD)
  - Address Resolution (similar to ARP in IPv4)
Efficient: Limits multicast traffic only to relevant nodes instead of all nodes.

# Link-Local Scope
Automatically assigned.
Only used within the local link.
Required for basic IPv6 operations (routing, neighbor discovery).

Cannot be routed across multiple links.
Routers must not forward packets with link-local source or destination.
Typically used only for local control/management traffic.


# Duplicate Address Detection
Host generates a tentative IPv6 address (e.g., during SLAAC).
Sends a Neighbor Solicitation (NS) to its solicited-node multicast address.
Waits for a Neighbor Advertisement (NA):
  - If no reply, the address is unique and assigned.
  - If a reply is received, the address is already in use → not assigned.

Filter in wireshark
```
icmpv6.type == 135  # Neighbor Solicitation
icmpv6.type == 136  # Neighbor Advertisement

```
Test:
```
sudo ip -6 addr add fe80::dead:beef/64 dev eth0
```

