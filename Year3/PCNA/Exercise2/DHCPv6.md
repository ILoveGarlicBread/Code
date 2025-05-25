# Stateful Autoconfiguration via DHCPv6

This section describes how to configure and test stateful address autoconfiguration using DHCPv6, where IPv6 prefixes are obtained via DHCP instead of manual configuration.

## a) Configure the Requesting Router

1. **Reboot** all machines (Router 1 and Hosts 1-3).
2. **Configure Router 1**:

   * Ensure Router 1 requests a **non-temporary IPv6 address** (per RFC 8415, Section 6.2).
   * Ensure Router 1 requests a **delegated prefix** (per RFC 8415, Section 6.3).
   * Use the **WIDE DHCPv6 client** (`dhcp6c`) and configure it via `/etc/wide-dhcpv6/dhcp6c.conf`.
   * Use `eth1` to send DHCPv6 requests.
   * Assign the delegated prefix to `eth0`.
   * Configure Router 1 to **advertise** the delegated prefix to the local network (via **Router Advertisements** or **DHCPv6**).

### Sample `dhcp6c.conf` (example):

```conf
interface eth1 {
    send ia-na 0;
    send ia-pd 0;
    request domain-name-servers;
    script "/etc/wide-dhcpv6/dhcp6c-script";
};

id-assoc na 0 {};
id-assoc pd 0 {
    prefix-interface eth0 {
        sla-id 0;
        sla-len 8;
    };
};
```

## b) Configure and Test the Network

1. Hosts \[1-3] should automatically obtain IP addresses from the **delegated prefix**.
2. Ensure **connectivity**:

   * Host\[1-3] ↔ Router 1
   * Router 1 ↔ Router 2
   * All nodes ↔ Internet (arbitrary public IPv6)
3. To ensure proper **default gateway configuration**, enable the acceptance of router advertisements:

```sh
sysctl net.ipv6.conf.all.accept_ra=2
```

## Demonstration Requirements

You must be ready to present and explain the following:

### 1. Function of DHCPv6

* **DHCPv6** is the IPv6 equivalent of DHCP in IPv4, responsible for assigning IPv6 addresses and options to hosts and routers.
* It supports both **stateful** (IP and option assignment) and **stateless** (option-only) modes.

### 2. DHCPv6 Message Flow

* **Client → Server**: Solicit
* **Server → Client**: Advertise
* **Client → Server**: Request
* **Server → Client**: Reply

Additional messages:

* **Renew**, **Rebind**, **Release**, etc., follow up for lease management.

### 3. Contents and Purpose of Messages

* **SOLICIT**: Client initiates request for configuration.
* **ADVERTISE**: Server replies with available configuration options.
* **REQUEST**: Client selects and requests specific configuration.
* **REPLY**: Server provides the confirmed configuration.
* **IA\_NA (Identity Association for Non-temporary Addresses)**: Used to request/assign stable IPv6 addresses.
* **IA\_PD (Identity Association for Prefix Delegation)**: Used to request/assign a whole prefix (e.g., for downstream networks).

### 4. IA\_NA and IA\_PD Options

* **IA\_NA**:

  * Purpose: Assign a stable, non-temporary IPv6 address to a client.
  * Used by individual hosts or routers for their own interface IP.

* **IA\_PD**:

  * Purpose: Delegate an entire prefix (subnet) to the client (typically a router).
  * Enables the router to assign IPs to downstream interfaces/hosts.

This concludes the configuration and analysis of stateful DHCPv6 setup.

