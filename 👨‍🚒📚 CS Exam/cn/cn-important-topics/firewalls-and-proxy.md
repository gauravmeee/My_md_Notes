
# Firewalls and Proxy


# Firewall

## What is a Firewall?

A firewall is a network security system that <mark>monitors and controls incoming/outgoing traffic</mark> based on pre-defined security rules. It creates a barrier between a trusted internal network and an untrusted external network (like the internet).

## Types of Firewalls

### 1. Packet Filter Firewall

OSI layer: Network (3) + Transport (4)

Works by <mark>inspecting individual packets without any knowledge of the session or connection state</mark>. Decisions are made purely on header fields.

Filters based on: source IP, destination IP, source port, destination port, protocol (TCP/UDP/ICMP), direction of packet.

Characteristics:

- Stateless — each packet judged independently
- Fastest and simplest type
- No awareness of connection state or application data
- Cannot detect IP spoofing easily
- Cannot prevent all attacks since it doesn't track session context

Example rule: "Block all incoming TCP packets to port 23 (Telnet)."


### 2. Stateful Inspection Firewall

> Dynamic Packet Filtering

OSI layer: Network (3) + Transport (4), with a state table

An improvement over the basic packet filter. <mark>Maintains a state table of active connections</mark>. A return packet is allowed only if it matches a known active session.

Characteristics:

- Tracks connection state (SYN, SYN-ACK, established, etc.)
- More secure than plain packet filter
- Still doesn't inspect application-layer payload
- Most widely used type in practice ⭐
- Also called <mark>dynamic packet filtering</mark>

Key difference from packet filter: <mark>stateful knows whether an incoming packet is a legitimate response to an outgoing request</mark>; packet filter doesn't.

---

### 3. Circuit Level Gateway

OSI layer: Transport (4) + Session (5)

Operates at the session layer. <mark>Validates the TCP/UDP handshake before allowing traffic</mark>. Once the session is established, data flows freely — it doesn't inspect individual packets in the session.

Characteristics:

- <mark>Hides internal network topology (acts as a proxy)</mark>
- Validates handshake legitimacy (checks SYN, SYN-ACK, ACK sequence)
- <mark>Does not inspect payload content</mark>
- Faster than application-layer firewalls
- Cannot detect malicious content within an allowed session

---

### 4. Application Layer Firewall (Proxy Firewall)

OSI layer: Application (7)

The most intelligent type. Acts as a full proxy — it <mark>terminates the client connection, inspects the entire payload, then forwards (or blocks) it to the destination</mark>. Understands specific application protocols like HTTP, FTP, DNS, SMTP.

Characteristics:

- Can filter based on content, not just headers
- Can detect malware, SQL injection, XSS in traffic
- Slowest due to deep inspection overhead
- Can block specific URLs, commands (e.g., FTP PUT but not GET)
- Hides internal network entirely
- Also called proxy firewall or application gateway

---

### 5. Next-Generation Firewall (NGFW)

OSI layer: All layers (1–7)

Combines packet filtering + stateful inspection + application awareness + intrusion prevention (IPS) + deep packet inspection (DPI) in one system.

Characteristics:

- Application identity awareness (can identify apps regardless of port)
- User identity awareness (can apply per-user rules)
- Integrated IPS and threat intelligence
- SSL/TLS decryption and inspection
- Most comprehensive but highest overhead

---

## Quick Comparison Table

|Feature|Packet filter|Stateful|Circuit level|Application|NGFW|
|---|---|---|---|---|---|
|OSI layer|3–4|3–4|4–5|7|1–7|
|Stateful?|No|Yes|Yes|Yes|Yes|
|Payload inspection?|No|No|No|Yes|Yes|
|Speed|Fastest|Fast|Fast|Slow|Slowest|
|Hides topology?|No|No|Yes|Yes|Yes|
|Also called|—|Dynamic PF|Session-layer FW|Proxy FW|—|

---

## Firewall Architectures (Important for PSU)

### Bastion Host

A hardened, single-purpose machine exposed to the internet. All external traffic passes through it. Runs minimal services to reduce attack surface.

### Screened Host Architecture

A bastion host sits behind a packet-filtering router. The router filters traffic before it reaches the bastion host.

```
Internet → Router (packet filter) → Bastion Host → Internal Network
```

### Screened Subnet (DMZ — Demilitarized Zone)

The most secure architecture. A separate subnet (DMZ) is placed between two firewalls. Public-facing servers (web, mail, DNS) live in the DMZ. Internal network is protected by the inner firewall.

```
Internet → Outer Firewall → DMZ (web/mail servers) → Inner Firewall → Internal Network
```

Key point: even if the DMZ is compromised, the inner firewall protects the internal network.

---

## Limitations of Firewalls (Common Exam Point)

Firewalls cannot protect against: attacks that bypass them entirely (e.g., via modem or USB), insider threats, viruses in email attachments (unless application-layer), tunnelled attacks within allowed protocols, and social engineering.

---

## One-Line Memory Tricks

| Firewall      | One-line memory                                                |
| ------------- | -------------------------------------------------------------- |
| Packet filter | "Checks the envelope, not the letter"                          |
| Stateful      | "Remembers who started the conversation"                       |
| Circuit level | "Checks the handshake, then steps aside"                       |
| Application   | "Reads every word of the letter"                               |
| NGFW          | "Reads the letter, knows the author, and checks the signature" |


---
# Proxy

A **proxy** is an intermediary — something that acts _on behalf of_ someone else.

In networking, a proxy server sits between a client (your browser) and the destination server. Instead of you connecting directly to, say, google.com, your request goes to the proxy first, which then forwards it, gets the response, and sends it back to you.The destination server never directly sees the client — it only sees the proxy. This is the core idea everything else builds on.

## Why use a proxy?

**Anonymity** — the <mark>destination sees the proxy's IP, not yours</mark>. This is how VPNs and tools like Tor work at a conceptual level.

**Caching** — the proxy can store frequently requested content (a webpage, an image) and serve it from its own memory instead of fetching it again. Faster for users, less load on the server. Corporate networks do this heavily.

**Content filtering** — the proxy can block certain URLs or categories. Schools and offices use forward proxies this way — "no social media during work hours."

**Security / inspection** — the proxy reads the actual content of requests and responses. This is exactly what an application layer firewall does. It can detect malware in downloads, block SQL injection attempts, etc.

**Load balancing** — a reverse proxy (like Nginx) sits in front of multiple servers and distributes incoming requests across them so no single server gets overwhelmed.

---

## Forward vs Reverse Proxy

These two get confused a lot in exams:

|                  | Forward proxy                     | Reverse proxy               |
| ---------------- | --------------------------------- | --------------------------- |
| Sits in front of | The client                        | The server                  |
| Used by          | Client (user's side)              | Server owner                |
| Hides            | Client's identity                 | Server's identity/structure |
| Example use      | VPN, content filter, school proxy | Load balancer, CDN, Nginx   |

A forward proxy acts on behalf of the client. A reverse proxy acts on behalf of the server.

## Connection to firewalls

The application layer firewall you saw in the previous notes is essentially a proxy firewall — it terminates your connection, reads the full payload, decides whether to allow it, then opens a fresh connection to the destination. Because it's a full proxy, the destination never directly communicates with the client. That's what gives it both its security strength (full inspection) and its speed weakness (double connection overhead).