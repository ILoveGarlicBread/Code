## Monitoring NDP (Neighbor Discovery Protocol) with Wireshark

This section outlines the procedure to monitor and analyze Neighbor Discovery Protocol (NDP) packets using Wireshark, based on ICMPv6.

### Tools

* **Wireshark** (with filter `icmpv6`)
* **ping** (to trigger NDP messages)
* **ndisc6** (to force neighbor solicitation)
* **rdisc6** (to force router discovery)

### Setup Points

* **Junction Point 1**: Interface eth0 of Host 1
* **Junction Point 2**: Interface eth0 of Router 1

### a) Neighbor Solicitation Packets

* Use `ndisc6 <IPv6-Address> eth0` to manually trigger a neighbor discovery.
* Filter in Wireshark: `icmpv6.type == 135`
* **Observations:**

  * **Source IP**: Link-local address of Host 1
  * **Destination IP**: Solicited-node multicast address (ff02::1\:ffXX\:XXXX)
  * **Ethernet Source MAC**: Host 1's MAC address
  * **Ethernet Destination MAC**: Multicast MAC (33:33\:ff\:XX\:XX\:XX)

### b) Neighbor Advertisement Packets

* Triggered in response to the solicitation.
* Filter in Wireshark: `icmpv6.type == 136`
* **Observations:**

  * **Source IP**: Link-local address of the responding host/router
  * **Destination IP**: Link-local address of the soliciting host
  * **Ethernet Source MAC**: MAC of the responding device
  * **Ethernet Destination MAC**: MAC of the soliciting device

### c) Router Solicitation Packets

* Use `rdisc6 eth0` from Host 1
* Filter in Wireshark: `icmpv6.type == 133`
* **Observations:**

  * **Source IP**: Link-local address of Host 1
  * **Destination IP**: ff02::2 (all routers multicast)

### d) Router Advertisement Packets

* Sent in response to router solicitation or periodically.
* Filter in Wireshark: `icmpv6.type == 134`
* **Observations:**

  * **Source IP**: Link-local address of Router 1
  * **Destination IP**: ff02::1 (all nodes multicast) or link-local address of Host 1
  * Contains prefix info (e.g. 2001:67C:2414:1i::/64) and optional RDNSS (RFC 8106)

### e) Diagram of NDP Message Exchange

```
Host 1                Router 1               Host 2
  |                      |                     |
  |--- NS -------------->|                     |
  |<-- NA ---------------|                     |
  |--- RS -------------->|                     |
  |<-- RA ---------------|                     |
  |                                          |
  |--- NS ---------------------------------->|
  |<-- NA -----------------------------------|
```

**Message Types:**

* **NS (Neighbor Solicitation)**: Type 135
* **NA (Neighbor Advertisement)**: Type 136
* **RS (Router Solicitation)**: Type 133
* **RA (Router Advertisement)**: Type 134

**Explanation of NDP Functions and Comparisons to ARP:**

### Function of NDP

The Neighbor Discovery Protocol (NDP) facilitates:

* **MAC address resolution** (replacing ARP in IPv4)
* **Router discovery** (how hosts find routers)
* **Prefix discovery** (for SLAAC)
* **Neighbor unreachability detection**
* **Duplicate address detection (DAD)**

### Messages and Their Purpose

* **Neighbor Solicitation (NS):** Queries for a neighbor's MAC address.
* **Neighbor Advertisement (NA):** Responds to NS with the MAC address.
* **Router Solicitation (RS):** Sent by hosts to find routers.
* **Router Advertisement (RA):** Sent by routers to announce presence and network configuration.

### Comparison to ARP (IPv4)

| Feature                 | ARP (IPv4)       | NDP (IPv6)                |
| ----------------------- | ---------------- | ------------------------- |
| Protocol Used           | ARP (standalone) | ICMPv6                    |
| Address Resolution      | Broadcast-based  | Multicast-based           |
| Router Discovery        | Not provided     | Built-in with RS/RA       |
| Duplicate Address Check | Not native       | Native (DAD)              |
| Security                | None             | Supports SEND (Secure ND) |

**Role of ARP in IPv6:**
ARP does **not exist** in IPv6. Its functions are entirely replaced by NDP, making use of ICMPv6 message types.

This concludes the monitoring, explanation, and comparison of the Neighbor Discovery Protocol (NDP) in IPv6.

