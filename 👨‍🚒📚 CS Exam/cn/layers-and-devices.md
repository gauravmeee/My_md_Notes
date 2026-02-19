---
description: Made By Me 💚
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# Layers and Devices

> Added at LAB

**Things Difficult to Remember**

**Layers - Devices**

* **Layer 7 (Application)** - ==Proxy==, ==Gateway== (Layer 7), Load Balancer
* **Layer 4 (Transport)** - ==Firewall==, Load Balancer
* **Layer 3 (Network)** - ==Router==, Brouter, Switch (Layer 3), Firewall (Partially)
* **Layer 2 (Data Link)** - ==Switch==, ==Bridge==, Access Point, NIC
* **Layer 1 (Physical)** - ==Hub==, ==Repeater==, Modem (Partially) , NIC (Partially)

**Layer - Data Unit**

* **Layer 7 (Application)** - Message
* **Layer 4 (Transport)** - Segments / Datagram
* **Layer 3 (Network)** - Packets -> Fragments
* **Layer 2 (Data Link)** - Frame
* **Layer 1 (Physical)** - Bits

**Port - Protocol**

* \==20 - FTP data (TCP)==
* \==21 - FTP control (TCP)==
* \==25 - SMTP (TCP)==
* 53 - DNS (UDP & TCP)
* 67 - DHCP Server (UDP)
* 68 - DHCP Client (UDP)
* \==80 - HTTP/1.x & HTTP/2 (TCP)==
* \==110 - POP3 (TCP)==
* \==143 - IMAP (TCP)==
* 179 - BGP (TCP)
* \==443 - HTTPS/TLS (TCP) _and_ HTTP/3 over QUIC (UDP)==
* 520 - RIP (UDP)

**Application Protocols Stateful or Stateless**

* **Stateless** - DNS, HTTP/1.x, HTTP/2
* **Stateful** - DHCP, FTP, IMAP, POP3, SMTP

***

#### ALL Layers Device/Endpoint

**Socket (4. Transport Layer)**

A **socket** is the ==software endpoint== that programs use to ==send and receive data over a computer network==.

* **What it represents:**
  * A combination of an ==IP address (identifying a host) and a port number== (identifying a specific process or service on that host).
  * Together they form a unique “address” for a communication channel.
* **How it works:**
  * One program creates a socket, binds it to a local address/port, and then either connects to a remote socket (for connection‑oriented protocols like TCP) or sends datagrams to a remote address (for connectionless protocols like UDP).
  * The other side does the same, establishing a two‑way communication path.
* **Common types:**
  * \==**Stream sockets**== – use TCP; provide reliable, ordered byte streams.
  * **==Datagram sockets**== – use UDP; send independent packets with no guarantee of delivery or order.

In short, a socket abstracts the network stack so applications can read/write data just like they would to a file, while the underlying protocol handles routing, reliability, etc.

**Host (3. Network Layer)**

A **host** is any ==end‑system== that ==runs a network protocol stack (typically TCP/IP)== and can originate or receive data on a network. In practice, a host:

* **Has an IP address** – the logical identifier used by the Network layer to route packets to it.
* **Runs applications** that use sockets (or other APIs) to send/receive traffic.
* **Can be a wide range of devices:** desktops, laptops, servers, smartphones, tablets, printers, IoT gadgets, virtual machines, etc.

A host is different from intermediate networking equipment such as routers or switches; those devices forward packets but are not the ultimate source or destination of user data. In the OSI model, a host operates at all layers (Physical up to Application), whereas “host‑to‑host communication” refers specifically to the Network layer’s service of delivering packets between two such end‑systems.

**Node (2. Data Link Layer)**

A **node** is any point‑of‑attachment on a network where data can be created, received, or forwarded. In other words, it’s anything that has a network address and participates in the communication process.

| Characteristic     | Details                                                                                                                                                                                                                          |
| ------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Scope**          | Applies to all layers of the OSI model – physical devices (cables, repeaters) up through application‑level software.                                                                                                             |
| **Types**          | <p>• <strong>End nodes</strong> – hosts that originate or consume data (PCs, servers, phones, IoT sensors).<br>• <strong>Intermediate nodes</strong> – devices that only forward traffic (routers, switches, bridges, hubs).</p> |
| **Addressability** | Usually has a unique identifier at some layer (e.g., MAC address for link‑layer, IP address for network‑layer).                                                                                                                  |
| **Function**       | <p>• Generate data packets (source node).<br>• Receive packets destined to it (destination node).<br>• Relay packets toward their destination (forwarding node).</p>                                                             |

Quick takeaway

* A _host_ is a specific kind of node that acts as an end‑system for user applications.
* All ==hosts are nodes==, but not all nodes are hosts—==routers and switches== are also nodes, just ones that primarily forward traffic.

#### Devices

**Multi‑layer networking devices**

| Device                                       | Layers involved                   | What it does on each layer                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| -------------------------------------------- | --------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Router**                                   | 1, 2, 3                           | <p>• <strong>L1:</strong> Sends/receives bits on each interface (copper, fiber, wireless).<br>• <strong>L2:</strong> Adds/removes the appropriate link‑layer header (Ethernet MAC, PPP, HDLC, etc.) for the outgoing/incoming interface.<br>• ==<strong>L3:</strong> Reads the destination IP address, looks up a routing table and forwards the packet to the selected next hop.==</p>                                                                                                            |
| **Multilayer Switch / Layer‑3 Switch**       | 1, 2, 3 (sometimes 4)             | <p>==• <strong>L1/L2:</strong> Same as an Ethernet switch – learns MAC addresses and forwards frames within a VLAN.==<br>==• <strong>L3:</strong> Performs fast hardware routing between VLANs or subnets (IP lookup).==<br>• <strong>L4 (optional):</strong> May apply ACLs or QoS based on TCP/UDP ports.</p>                                                                                                                                                                                    |
| **Gateway (generic term)**                   | 1 – 7 (depends on the conversion) | <p>• <strong>L1/L2:</strong> Provides physical/link connectivity between dissimilar media (e.g., Ethernet ↔ Serial, copper ↔ fiber).<br>• <strong>L3:</strong> May route or perform address translation when moving between IP domains.<br>==• <strong>L4–L7:</strong> Performs protocol conversion – e.g., IPv4 ↔ IPv6 (NAT64/DNS64), MPLS ↔ IP, or encapsulation for tunnels (GRE, IPsec).==</p>                                                                                                 |
| **Firewall (stateful + NAT)**                | 1, 2, 3, 4, 5‑7 (optional)        | <p>• <strong>L1/L2:</strong> Receives frames and may strip/insert VLAN tags.<br>• <strong>L3:</strong> Filters packets by source/destination IP, applies NAT (translates private ↔ public addresses).<br>• <strong>L4:</strong> Tracks TCP/UDP session state; allows only established connections.<br>• <strong>L5‑L7 (optional):</strong> Deep‑packet inspection (e.g., HTTP header checks) or application‑layer proxying.</p>                                                                    |
| **Application‑Layer Gateway / Proxy**        | 1, 2, 3, 4, 5‑7                   | <p>• <strong>L1/L2:</strong> Normal Ethernet/physical handling.<br>• <strong>L3/L4:</strong> Terminates the client’s TCP connection; opens a separate outbound connection to the server.<br>==• <strong>L5‑L7:</strong> Interprets the application protocol (HTTP, FTP, SMTP, etc.), can modify ==requests/responses, enforce policies, cache content.</p>                                                                                                                                         |
| **VPN Concentrator / IPsec Gateway**         | 1, 2, 3, 4, 5‑7                   | <p>• <strong>L1/L2:</strong> Sends encrypted frames over whatever physical media is used.<br>• <strong>L3:</strong> Encapsulates original IP packets inside a new outer IP header (tunnel mode) or encrypts them directly (transport mode).<br>• <strong>L4:</strong> Secures the transport with ESP/AH; may also perform NAT‑Traversal handling.<br>• <strong>L5‑L7:</strong> May terminate higher‑level protocols (e.g., SSL VPN terminates HTTPS and presents a virtual LAN to the client).</p> |
| **Bridge (Transparent Bridge / MAC Switch)** | 1, 2                              | <p>• <strong>L1:</strong> Sends/receives bits on each port.<br>• <strong>L2:</strong> Learns MAC addresses and forwards frames within the same broadcast domain; no IP processing.</p>                                                                                                                                                                                                                                                                                                             |
| **Modem / Media Converter**                  | 1, 2                              | <p>==• <strong>L1:</strong> Converts signaling (e.g., electrical ↔ optical, DSL line ↔ Ethernet).==<br>• <strong>L2 (optional):</strong> May encapsulate data in PPP or HDLC frames for the WAN side.</p>                                                                                                                                                                                                                                                                                          |

**How to read the table**

_If a device lists a layer, it **touches** that layer – i.e., it either adds/removes a header, makes a decision, or performs translation at that level._\
Devices that only forward without modification (e.g., a simple Ethernet bridge) stop at Layer 2. Anything that needs to look at IP addresses, ports, or application data must climb higher in the stack.

**Quick mental checklist**

| <p>Need to <strong>route</strong>? → Router / Multilayer Switch.<br>Need to <strong>translate protocols/addresses</strong> across different networks? → Gateway / NAT / VPN.<br>Need to <strong>inspect or filter</strong> traffic beyond IP? → Firewall, IDS/IPS, Proxy.<br>Need to <strong>balance load</strong> based on content? → Load Balancer.</p> |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |

This list covers the _principal_ multi‑layer devices you’ll encounter in enterprise and data‑center environments. If you have a specific device or scenario in mind, let me know and I can drill down further.

**Routers are multi‑layer devices.**

| Layer                         | What the router does there                                                                                                                                                                                                                                                                                                                                                                                        |
| ----------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Network layer (Layer 3)**   | _Core function._ The router reads the destination **IP address** in each packet, looks it up in its routing table, and decides which outgoing interface to forward the packet to. This is why we say a router “operates at the network layer.”                                                                                                                                                                    |
| **Data‑link layer (Layer 2)** | Every physical interface on the router has a MAC address (or another link‑layer identifier such as PPP, Frame Relay, etc.). Before sending a packet out, the router encapsulates it in an appropriate **frame** for that specific link technology and adds the correct source/destination MAC addresses. Likewise, when a frame arrives, the router strips off the Layer 2 header to expose the IP packet inside. |
| **Physical layer (Layer 1)**  | The actual electrical/optical signaling on each port – just like any other network device.                                                                                                                                                                                                                                                                                                                        |

**Why the confusion with “node”**

* A **node** is any point that can send, receive, or forward data. That definition is _layer‑agnostic_; a node may be an end host (only Layer 3+), a switch (mostly Layer 2), or a router (Layer 2 + Layer 3).
* When we say “a node exists at the Data‑Link layer,” we mean that every node has a **link‑layer presence** (e.g., a MAC address) on each of its interfaces. It doesn’t imply the node’s _primary_ function is limited to Layer 2.

**Bottom line**

* **Routing decisions → Network layer (IP).**
* **Frame handling, MAC addressing → Data‑Link layer.**

A router therefore works at both layers: it uses Layer 3 information to choose a path and then uses Layer 2 mechanisms to actually move the packet onto the next physical link.
