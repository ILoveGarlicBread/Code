# IPv6 Stateless Address Autoconfiguration (SLAAC) Lab Setup

## Overview


* Hosts: Host 1, Host 2, Host 3
* Router: Router 1 (connected to two networks)

## IPv6 Network Configuration

### Addressing Scheme

* **Network 1 Prefix**: `2001:67C:2414:1i::/64`
* **Router 1 eth0**: `2001:67C:2414:1i::1`
* **Router 1 eth1**: `2001:67C:2414:10::i`
* **Router 2**: `2001:67C:2414:10::ffff`

---

## a) SLAAC Setup (RFC 4862)

### Step 1: Enable IPv6

On all machines:

```bash
sudo sysctl -w net.ipv6.conf.all.disable_ipv6=0
sudo sysctl -w net.ipv6.conf.default.disable_ipv6=0
```

### Step 2: Install and Configure `radvd` on Router 1

Install radvd:

```bash
sudo apt install radvd
```

Create config file `/etc/radvd.conf`:

```conf
interface eth0
{
    AdvSendAdvert on;
    prefix 2001:67C:2414:1i::/64
    {
        AdvOnLink on;
        AdvAutonomous on;
    };
};
```

Start radvd:

```bash
sudo systemctl restart radvd
```

### Step 3: Configure Router 1 eth0 & eth1

```bash
sudo ip -6 addr add 2001:67C:2414:1i::1/64 dev eth0
sudo ip -6 addr add 2001:67C:2414:10::i/64 dev eth1
```

### Step 4: Configure Hosts \[1-3] to Accept Router Advertisements

Make sure the interfaces are up:

```bash
sudo ip link set eth0 up
```

Then confirm auto-configuration:

```bash
ip -6 addr show dev eth0
```

### Default Route on Hosts

Use:

```bash
ip -6 route
```

Expected default route:

```
default via fe80::... dev eth0
```

**Scope**: Link-local (fe80::/10)

---

## b) DNS Configuration via Router Advertisements (RFC 8106)

Update `/etc/radvd.conf` on Router 1:

```conf
interface eth0
{
    AdvSendAdvert on;
    prefix 2001:67C:2414:1i::/64
    {
        AdvOnLink on;
        AdvAutonomous on;
    };
    RDNSS 2001:1608:10:25::1c04:b12f 2001:1608:10:25::9249:d69b
    {
        AdvRDNSSLifetime 600;
    };
};
```

Restart `radvd`:

```bash
sudo systemctl restart radvd
```

Hosts should now receive DNS via RA. Confirm with:

```bash
systemd-resolve --status
```

---

## c) Testing the Network

### ICMP Tests

From Router 1 to Hosts:

```bash
ping6 2001:67C:2414:1i::<host>
```

From Hosts to Router:

```bash
ping6 2001:67C:2414:1i::1
```

From Hosts to Router 2:

```bash
ping6 2001:67C:2414:10::ffff
```

### Additional Useful Commands

To check current IPv6 routes:

```bash
ip -6 route show
```

To see all IPv6 neighbors:

```bash
ip -6 neigh
```

To clear IPv6 neighbor cache:

```bash
ip -6 neigh flush all
```

---

## Summary

* All hosts receive addresses via SLAAC.
* Router 1 advertises prefix and DNS servers.
* Hosts can communicate with Router 1 and Router 2.
* The default route on hosts uses the link-local address of Router 1.
* DNS name resolution via IPv6 is functional.

