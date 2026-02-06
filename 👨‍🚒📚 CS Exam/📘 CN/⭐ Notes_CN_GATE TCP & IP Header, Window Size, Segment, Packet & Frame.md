
### TCP Header vs IP Header

##### **1. TCP Header (Transport Layer)**

```
0                 8            16                               31 (bits)
┌─────────────┬──────────────────┬────────────────────────────────┐
│ Source Port │ Destination Port │        Sequence Number         │
│   (16b)     │      (16b)       │            (32b)               │
├─────────────┴──────────────────┴────────────────────────────────┤
│                Acknowledgment Number (32b)                      │
├─────────────────────────────────────────────────────────────────┤
│ Data Off (4b) │ Reserved (3b) │ Flags (9b) │ Window Size (16b)  │
├─────────────────────────────────────────────────────────────────┤
│               Checksum (16b)             │  Urgent Pointe (16b) │
├─────────────────────────────────────────────────────────────────┤
│                   Options (0–40 bytes)                          │
├─────────────────────────────────────────────────────────────────┤
│                          Data                                   │
└─────────────────────────────────────────────────────────────────┘
```

- **Size:** 
	- ==**20 bytes**== (without options)
	- **20–60 bytes** (with options).
- **Purpose:** 
	- Reliable delivery, flow control, and connection management.
- **Key Fields:**
    - **Source Port (16B), Destination Port (16B)** – identifies sending/receiving apps
    - **Sequence Number (32B)** – order of bytes
    - **Acknowledgment Number (32B)** – confirms received bytes
    - **Data Offset (4B)** – TCP header length
    - **Flags (9 bits)** – SYN, ACK, FIN, RST, PSH, URG
    - **Window Size (16B)** – flow control / in-flight data limit
    - **Checksum (16B)** – error detection
    - **Urgent Pointer (16B)** – optional
    - **Options (variable)** – optional, max header 60B
- **Function:** Ensures **reliable, ordered, and flow-controlled delivery** of data.

##### **2. IP Header (Network Layer)**


**IPv4 Header** ⭐
- **Size:**
	- ==**20 bytes**== (without options)
	- **20–60 bytes** (with options).
- **Purpose:** 
	- Routing data from source to destination across networks.
- **Key Fields:**
    - **Version (4B)** – IPv4/IPv6
    - **Header Length (4B)** – length of IP header
    - **Type of Service / DSCP (8B)** – priority / QoS
    - **Total Length (16B)** – IP packet size (header + data)
    - **Identification / Flags / Fragment Offset** – fragmentation control
    - **TTL (8B)** – Time to Live, decremented at each hop
    - **Protocol (8B)** – indicates encapsulated protocol (TCP=6, UDP=17)
    - **Header Checksum (16B)** – error detection
    - **Source IP / Destination IP (32B each)** – identifies endpoints
    - **Options (variable)** – rarely used
- **Function:** **Routes the packet** across networks, handles fragmentation, and identifies endpoints.

**IPv6 Header**
- **Size:** **==40 bytes== (fixed)**
	- Unlike IPv4, IPv6 header **does not have variable length** unless there are extension headers.    
- **Purpose:** Routing packets across networks, similar to IPv4, but simplified for faster processing and larger address space.

- **Key Fields (Fixed 40 bytes):**
	1. **Version (4 bits):** Always 6
	2. **Traffic Class (8 bits):** Like IPv4 DSCP, for QoS
	3. **Flow Label (20 bits):** For special routing of flows
	4. **Payload Length (16 bits):** Length of data after header
	5. **Next Header (8 bits):** Indicates transport protocol (TCP=6, UDP=17)
	6. **Hop Limit (8 bits):** Replaces TTL, decremented at each hop
	7. **Source Address (128 bits)**
	8. **Destination Address (128 bits)**

- **Notes:**
	- **No Header Checksum** → routers don’t recompute, faster processing
	- **No Fragmentation fields** → fragmentation handled by source host, not routers
	- **Extension Headers:** Optional, separate from main 40-byte header

**IPv4 header diagram**
```
0                 8            13                               31 (bits)
┌─────────┬───────┬─────────────┬────────────────────────────────┐
│ Version │  IHL  │ Type of Ser.│          Total Length          │
│ (4b)    │  (4b) │     (8b)    │             (16b)              │
├─────────┴───────┴─────────────┴────────────────────────────────┤
│       Identification (16b)    │ Flags (3b) │ Frag Offset (13b) │
├────────────────────────────────────────────────────────────────┤
│ Time To Live (8b) │  Protocol (16b)  │ Header Checksum (8b)    │
├────────────────────────────────────────────────────────────────┤
│                      Source IP Address (32b)                   │
├────────────────────────────────────────────────────────────────┤
│                     Destination IP Address (32b)               │
├────────────────────────────────────────────────────────────────┤
│                        Options (0–40 bytes)                    │
└────────────────────────────────────────────────────────────────┘

```

##### **Changes in Transit**


**1. TCP Header Fields & Changes in Transit**

|Field|Size|Changes During Transit?|Why / Notes|
|---|---|---|---|
|Source Port|16b|No|Application port of sender|
|Destination Port|16b|No|Application port of receiver|
|Sequence Number|32b|No|Assigned by sender, stays same|
|Acknowledgment Number|32b|No|Set by receiver, does not change mid-transit|
|Data Offset|4b|No|Header length, constant|
|Reserved|3b|No|Always 0|
|Flags|9b|No|SYN, ACK, FIN, etc. are fixed per segment|
|Window Size|16b|No|Flow control; fixed in segment|
|Checksum|16b|**Recomputed if any field changes**|Usually unchanged; only if network modifies bits (rare)|
|Urgent Pointer|16b|No|Only used if URG flag set|
|Options|0–40B|No|Usually unchanged|
|Data|Variable|No|Payload unchanged|

- TCP headers **do not change during transit**, except ==rarely for **checksum if bits are corrupted and fixed**==.

**2. IPv4 Header Fields & Changes in Transit**

| Field                  | Size     | Changes During Transit?                       | Why / Notes                                 |
| ---------------------- | -------- | --------------------------------------------- | ------------------------------------------- |
| Version                | 4b       | No                                            | Always 4 for IPv4                           |
| IHL (Header Length)    | 4b       | No                                            | Constant per packet                         |
| Type of Service / DSCP | 8b       | Sometimes                                     | Routers may set QoS bits for priority       |
| Total Length           | 16b      | No                                            | Includes header + payload; does not change  |
| Identification         | 16b      | No                                            | Same for all fragments                      |
| Flags                  | 3b       | ==Fragmentation may set MF (More Fragments)== | If packet fragmented                        |
| Fragment Offset        | 13b      | ==Changes if fragmented==                     | Indicates position of fragment              |
| TTL (Time To Live)     | 8b       | ==**Decrements at each hop**==                | Prevents loops; drops at 0                  |
| Protocol               | 8b       | No                                            | Identifies transport layer protocol (TCP=6) |
| Header Checksum        | 16b      | ==**Recomputed at each hop**==                | Because TTL changes, checksum changes       |
| Source IP              | 32b      | No                                            | Original sender IP                          |
| Destination IP         | 32b      | No                                            | Final receiver IP                           |
| Options                | variable | Rarely                                        | Usually unchanged                           |

- Only ==**TTL== and ==Header Checksum==** always change at routers. ⭐
- Fragmentation fields (==Flags, Fragment Offset==) change **only ==if packet is fragmented**.==
    


##### **Key Differences**

| Feature   | TCP Header                            | IP Header                         |
| --------- | ------------------------------------- | --------------------------------- |
| Layer     | Transport                             | Network                           |
| Size      | 20–60B                                | 20B                               |
| Purpose   | Reliability, sequencing, flow control | Routing, addressing               |
| Key Field | Sequence Number, Window Size, Flags   | Source IP, Destination IP, TTL    |
| Affects   | TCP Segment size, in-flight data      | Packet routing, total packet size |

**Field Changes during Transit**
- Network (IP) → ==TTL, Checksum, Fragmentation fields== may change. ⭐
- Transport (TCP) → Usually nothing changes.
        

---
### TCP Window Size vs Segment vs Packet vs Frame

##### **1. TCP Window Size**

- ==Max **application data** sender can send without ACK.==
- Measured in **bytes**, controls ==**in-flight data**==.
- Does **not include headers**, only counts **payload**.

```
Throughput = min(Window size / RTT, Link bandwidth)
```

##### **2. TCP Segment**

- TCP **payload + ==TCP header** (20–60B)==.
- Carries **application data** for transport.
- Segment size limited by **MSS**:

```
MSS = MTU – IP header – TCP header
```

##### **3. IP Packet**

- Segment + ==IP header (20B).==
- IP packet = TCP segment + IP header.    
- Packet is what **network layer** transmits to next hop.

##### **4. Frame (Data Link Layer)**

- Packet + Link header + ==trailer (Ethernet example: 14B + 4B)==.
- Max frame size limited by **MTU** (typically 1500B Ethernet).
- Physical layer transmits **bits of frame**.

##### **Quick Comparison & Relation**

**Relationship / Flow**

```
Application Data
   ↓
TCP Segment = TCP header + data
   ↓
IP Packet = IP header + TCP segment
   ↓
Frame = Link header + IP packet + trailer
   ↓
Bits on wire
```


**Comparison Table**

|Term|Size|Includes|Role|Relation to Window Size|
|---|---|---|---|---|
|TCP Window Size|Bytes|Only TCP payload|Max in-flight data|Controls throughput|
|TCP Segment|TCP payload + TCP header (20–60B)|TCP header + data|Transport unit|Must fit in window|
|IP Packet|Segment + IP header (20B)|TCP + IP headers + data|Network unit|Size affects MSS|
|Frame|Packet + Link header + trailer|TCP/IP headers + data + Link headers|Physical transmission|MTU limits max segment size|

**Key Points to Understand:**
- **Window size** → logical, controls how many bytes can be “in-flight”.
- **Segment / Packet / Frame** → physical encapsulations, headers reduce actual data per unit.
- **Header sizes** → overhead, reduce payload per transmission.
- **Frame size / MTU** → limits maximum segment size (MSS).

---
### TCP Data Units, Window Size, and Bandwidth–Delay Product (BDP)

##### **Data Units in Networking**

1. **Bit** – Smallest unit of data (0 or 1).    
2. **Byte** – 8 bits.
3. **Segment (TCP Layer)**
    - Contains **TCP header + application data**.
    - TCP header: 20–60 bytes.
    - TCP segment = **piece of application data ready to send**.
        
4. **Packet (Network/IP Layer)**
    - TCP segment is wrapped in **IP header** → becomes packet.
    - IP header: 20 bytes.
    - Packet = **TCP segment + IP header**.
        
5. **Frame (Data Link Layer)**
    - Packet is wrapped in **Link Layer header + trailer** → Frame.
    - Ethernet example: Header = 14 bytes, Trailer (FCS) = 4 bytes.
    - Frame = **Packet + Link Layer header + trailer**.
        
6. **On-the-Wire**
    - Physical layer transmits **frames as bits**.
        

**Flow Diagram (Layer-wise)**

```
Application Data
   ↓
TCP Segment (TCP Header + Data)
   ↓
IP Packet (IP Header + TCP Segment)
   ↓
Ethernet Frame (Link Header + Packet + Trailer)
   ↓
Bits transmitted on physical medium
```

---

##### **TCP Window Size**

- **Definition:** Maximum amount of data sender can send without receiving ACK from receiver.
- Measured in **bytes**.
- **Purpose:** Controls “in-flight” data to match network capacity.

**Key Concept:**
- Link can hold only limited bits at a time → called **Bandwidth–Delay Product (BDP)**.
- TCP window size must be ≥ BDP to fully utilize the link.
    

**Equation:**
```
BDP (bits) = Link bandwidth (bits/sec) × Round Trip Time (sec)
TCP Window Size (bytes) ≥ BDP / 8
```


**Why Window Size Matters**

1. **If TCP window < BDP:**
    - Sender stops after sending window-sized data, waits for ACK.
    - Link capacity is not fully used → throughput < max bandwidth.
        
2. **If TCP window ≥ BDP:**
    - Sender continuously sends data → link is full → max throughput achieved.
        
**Visualization:**
```
Link capacity = pipe
BDP = pipe volume
Window size = amount sender can push into pipe at once

Window < BDP → pipe not full → wasted capacity
Window ≥ BDP → pipe full → maximum data in-flight
```

##### **Relationship Between Units, Window, and Throughput**

- **Data flows as:** Application → TCP Segment → IP Packet → Frame → Bits on wire.
- **Window size** controls how many TCP segments are in-flight.
- **BDP** tells **ideal number of bits in-flight** to fully utilize link.
- **Throughput** = min (Link capacity, Window/RTT)

**Throughput Equation:**
```
Throughput = TCP Window Size / RTT  (bytes/sec)
If Window < BDP → Throughput < Bandwidth
If Window ≥ BDP → Throughput ≈ Bandwidth
```


##### **Summary Table**

|Layer|Unit|Header|Content|In-Flight Control|
|---|---|---|---|---|
|Application|Data|-|User info|-|
|Transport|Segment|20–60B|TCP header + Data|TCP Window|
|Network|Packet|20B|IP header + Segment|-|
|Link|Frame|14B+4B|Packet + Header + Trailer|-|
|Physical|Bits|-|Frame bits|Controlled indirectly by Window & BDP|
