# 1. Network Setup

## Configure the ips of router interfaces:

eth0: Corporate

eth1: DMZ

eth2: Observer

```bash
# LAN Interfac
sudo ip addr add 192.168.150.1/24 dev eth0
# DMZ Interface
sudo ip addr add 192.168.50.1/24 dev eth1
# Observer Interface
sudo ip addr add 10.16.0.5/16 dev eth2
# Enable IP forwarding
sudo sysctl -w net.ipv4.ip_forward=1
```

## Setting up Hosts:
#### Host1: Corporate
```bash
sudo ip addr add 192.168.150.20/24 dev eth0
sudo ip route add default via 192.168.150.1

```

#### Host2: DMZ
```bash
sudo ip addr add 192.168.50.50/24 dev eth0
sudo ip route add default via 192.168.50.1
```

#### Host3: Observer
```bash
sudo ip addr add 10.16.5.100/16 dev eth0
sudo ip route add default via 10.16.0.5
```

# Configuring the firewall
## iptables: administration tool for IPv4 packet filtering and NAT
### Description (copying from man page)
 Iptables  and  ip6tables  are  used  to  set up, maintain, and inspect the tables of IPv4 and IPv6 packet
filter rules in the Linux kernel.  Several different **tables** may be defined.  Each table contains a number
of built-in chains and may also contain user-defined chains.

Each  **chain**  is  a list of rules which can match a set of packets.  Each **rule** specifies what to do with a
packet that matches.  This is called a `**target**', which may be a jump to a user-defined chain in the  same table.

**Summary**: 

- **Tables**: Different categories or "rulebooks" for filtering network traffic.

- **Chains**: Ordered lists of "rules" within each "table."
- **Rules**: Individual conditions that check network "packets." If a packet matches a rule, the rule tells your computer what action to take.
- **Target**: The specific action a "rule" tells your computer to perform on a matching "packet" (e.g., allow it, block it, or send it to another "chain" for more checks).

###  Targets
   A  firewall  rule  specifies  criteria for a packet and a target.  If the packet **does not match**, the **next** rule in the chain is examined; if it **does match**, then the next rule is **specified  by  the  value  of  the target**,   which   can   be   the  name  of  a  user-defined  chain,  one  of  the  targets  described  in iptables-extensions(8), or one of the special values ACCEPT, DROP or RETURN.

**ACCEPT** means to let the packet through.  
**DROP** means to drop the packet on the floor.  
**RETURN**  means  stop traversing  this  chain  and  resume  at  the next rule in the previous (calling) chain.  If the end of a built-in chain is reached or a rule in a built-in  chain  with  target **RETURN**  is  matched,  the  target
specified by the chain policy determines the fate of the packet.

**Summary**:
- Package arrives
- Goes to a table (depends on what kind of check)
- Enter a chain (a rule list)
- Check with a rule:
  + If not match: move to next rule
  + If match: The rule's target decides what happens next (ACCEPT, DROP, ...)
    
## Config
Flush all chains:
```bash
sudo iptables -F
```

Default Policy (what happen if no rules match in the chain):
```bash
sudo iptables -P FORWARD DROP
```

Allow Corporate Lan to access anywhere:
```bash
sudo iptables -A FORWARD -s 192.168.150.0/24 -j ACCEPT
```
Allow response:
```bash
sudo iptables -A FORWARD -m state --state ESTABLISHED,RELATED -j ACCEPT
```
Block DMZ from accessing Corporate:
```bash
sudo iptables -A FORWARD -s 192.168.50.0/24 -d 192.168.150.0/24 -j DROP
```
Allow HTTP from Internet to DMZ web server:
```bash
sudo iptables -A FORWARD -d 192.168.50.50 -p tcp --dport 80 -j ACCEPT
```
Block traffic **from DMZ**:
```bash
# Block from DMZ to Corporate
sudo iptables -A FORWARD -s 192.168.50.0/24 -d 192.168.150.0/24 -j DROP
# Block from DMZ to Internet
sudo iptables -A FORWARD -s 192.168.50.0/24 -j DROP
```
Allow traffic **from Corporate**:
```bash
sudo iptables -A FORWARD -s 192.168.150.0/24 -j ACCEPT
```
Allow Corporate to send DNS queries (using udp port 53):
```bash
sudo iptables -A FORWARD -s 192.168.150.0/24 -p udp --dport 53 -j ACCEPT
```
Allow Corporate to ssh into DMZ (tcp port 22):
```bash
sudo iptables -A FORWARD -s 192.168.150.0/24 -d 192.168.50.0/24 -p tcp --dport 22 -j ACCEPT
```
Allow SSH from LAN to firewall’s DMZ interface:
```bash
sudo iptables -A INPUT -s 192.168.150.0/24 -d 192.168.50.1 -p tcp --dport 22 -j ACCEPT
# Block everything else to the firewall (INPUT chain)
sudo iptables -P INPUT DROP
sudo iptables -A INPUT -i lo -j ACCEPT  # Allow loopback
sudo iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
```
Source NAT for LAN hosts:
```bash
sudo iptables -t nat -A POSTROUTING -s 192.168.150.0/24 -o eth3 -j MASQUERADE
```
Block inappropriate ICMP types:
```bash
# Allow essential ICMP from LAN to Internet
iptables -A FORWARD -s 192.168.150.0/24 -p icmp -j ACCEPT

# Allow related ICMP back in
sudo iptables -A FORWARD -m state --state ESTABLISHED,RELATED -p icmp -j ACCEPT
# Drop ping (echo-request) from Internet to LAN
sudo iptables -A FORWARD -p icmp --icmp-type echo-request -d 192.168.150.0/24 -j DROP
# Allow other necessary ICMP types from Internet to LAN (destination-unreachable, fragmentation-needed, etc.)
sudo iptables -A FORWARD -p icmp --icmp-type destination-unreachable -d 192.168.150.0/24 -j ACCEPT
sudo iptables -A FORWARD -p icmp --icmp-type fragmentation-needed -d 192.168.150.0/24 -j ACCEPT
sudo iptables -A FORWARD -p icmp --icmp-type time-exceeded -d 192.168.150.0/24 -j ACCEPT
```

DOS Protection:
```bash
# SYN flood:
sudo iptables -A FORWARD -p tcp --syn -m limit --limit 5/s --limit-burst 10 -j ACCEPT
# Ping of Death:
sudo iptables -A FORWARD -p icmp -m limit --limit 1/s --limit-burst 5 -j ACCEPT
```

Sources:

https://manpages.ubuntu.com/manpages/xenial/en/man8/iptables.8.html

https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/4/html/security_guide/s1-fireall-ipt-act