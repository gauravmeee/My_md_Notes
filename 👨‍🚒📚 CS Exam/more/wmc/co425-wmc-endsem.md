# [L38: Bluetooth Architecture, Protocol Stack, Piconet, Layer Functions | Mobile Computing Lectures](https://www.youtube.com/watch?v=XDwz1XNOkhY&t=702s&ab_channel=EasyEngineeringClasses)

## Bluetooth Technology 

- It is used to implement Personal Area Network (PAN)
- Helps to interconnect a set of devices with embedded computers that individual person might require
	- Ex: Network among appliances - Wireless Bluetooth Earphones & Mobile device
- **Advantage:** It can be used to get rid of wires mesh

**PICONET:** 
- Bluetooth connectivity among a set of devices is called PICONET
- Piconet means very small network
- It is based on Master-Slave Command Architecture,  Slave only responds to master's commands
- This Create a Ad-hoc Network

### Bluetooth Protocol Stack ⭐
- Makes possible communication of both data and control among many devices in PAN

```
   Bluetooth Protocol Stack
┌───────────────────────────────────────────┐
|              Application                  |
└───────────────────────────────────────────┘ 
┌──────────┐                      ┌─────────┐
|          | [TCS] [RFCOMM] [SDP] | Control |
|  Audio   | [      L2CPA       ] |         |
└──────────┘ [      LMP         ] └─────────┘
┌───────────────────────────────────────────┐
|              Base Band                    |
└───────────────────────────────────────────┘ 
┌───────────────────────────────────────────┐
|              Physical Band                |
└───────────────────────────────────────────┘ 

TCS - Telephony Control Protocol specification
RFCOMM - Radio Frequency Communication
SDP  - Service Discovery Protocol
---
L2CPA - Logical link Control and adaptation Protocol
LMP - Link Management Protocol
```

#### Functions of Layers ⭐

**Physical Layer**:
- Handles radio communication, including modulation techniques and RF signal transmission.
- Defines requirements for Bluetooth transceiver devices and ensures signal reliability.

**Baseband Layer**:
- Manages link establishment, synchronization, and power control.
- Defines packet format, handles timing issues, and performs error correction.

**LMP (Link Management Protocol)**:
- Operates at the data link layer.
- Responsible for link setup, authentication, and configuration.

**L2CAP (Logical Link Control and Adaptation Protocol)**:
- Provides connection-oriented and connectionless data services to upper-layer protocols.
- Segments messages into data packets and reassembles packets into messages.

**SDP (Service Discovery Protocol)**:
- Allows devices to discover available services and their characteristics.

**RFCOMM**:
- Emulates RS-232 serial port communication for legacy system compatibility.
- Simplifies wireless connectivity between devices.

**TCS (Telephony Control Protocol Specification)**:
- Defines call control signaling for establishing voice connections between Bluetooth devices.
# [93 IEEE 802.15.1 Bluetooth](https://www.youtube.com/watch?v=ixY0Cau4mBM&ab_channel=NesoAcademy)

**Bluetooth:** 
- Bluetooth is a wireless technology standard used for exchanging data between fixed and mobile devices over short distances using short-wavelength **UHF radio** waves in the ISM radio bands, from 2.400 to 2.485 GHz, and building personal area networks (PANs). ⭐
- It was originally conceived as a wireless alternative to RS-232 data cables. 
- Bluetooth is a wireless technology named after Harald Bluetooth, based on an analogy that Bluetooth technology would unite devices the way Harald Bluetooth united the tribes of Denmark into a single kingdom.
- Bluetooth is specified by an industry consortium called the Bluetooth Special Interest Group.
- It specifies an entire suite of protocols, going beyond the link layer to define application protocols, which it calls profiles, for a range of applications.
	- There is a profile for synchronizing a PDA with personal computer.
	- Another profile gives a mobile computer access to a wired LAN.
- **Piconet** The basic Bluetooth network configuration is called a piconet
	- Consists of a master device and up to seven slave devices.
	- Any communication is between the master and a slave.
	- The slaves do not communicate directly with each other.
	- A slave can be parked: set to an inactive, low-power state.
	- **Scatternet:** Collection of Piconets
- **Bluetooth adapters:** No matter it is a fixed device or mobile device, bluetooth can establish communication between any devices using bluetooth adapters

**Pros of Bluetooth:**
- Low Cost
- Easy to use
- It can also penetrate through walls
- It creates an ad-hoc connection immediately without any wires.
- It is used for voice and data transfer

**Cons of Bluetooth:**
- It can be hacked hence, less secure
- It has slow data transfer rate.
- It has small range: 10 meters.

**BLUESNARFING**
* Bluesnarfing is the unauthorized access of information from a wireless device through a Bluetooth connection, often between phones. desktops, laptops, and PDAs.
- This allows access to calendars, contact lists, emails and text messages, and on some phones, users can copy pictures and private videos.
- Bluesnarfing is the theft of information from the target device.

# [94 Bluetooth Protocol Stack](https://www.youtube.com/watch?v=eJKkEzeGuuo&ab_channel=NesoAcademy)


# [L41: Mobile IP(Internet Protocol) Introduction, Design Goals, Requirements, IP Packet Delivery](https://www.youtube.com/watch?v=5yp3Ti47ZZc&ab_channel=EasyEngineeringClasses)
 ![[Pasted image 20241118210727.png]]
![[Pasted image 20241118210755.png]]
![[Pasted image 20241118210832.png]]
![[Pasted image 20241118210858.png]]
![[Pasted image 20241118210930.png]]
# [wireless application protocol (WAP) | introduction | Mobile Computing | Lec-19 | Bhanu priya ](https://www.youtube.com/watch?v=DPcqnhtvYm8&ab_channel=Education4u)

WAP is a set of protocols which allow **data exchange** for mobile cellular system.
-> It is a device independent
-> It is network independent

Current Constraints of wireless Interface and Mobile Devices (which not use WAP)

**Wireless Interface Constraints:**
1. Less Bandwidth
2. High Latency
3. Less stable connection ⭐
4. device Range of network is standard ⭐

**Mobile Devices**
1. Less CPU power
2. Less memory storage
3. Restricted power consumption
4. Small or Variable size of display

Why use WAP? ⭐
1. **Wireless Networks and Phones:** Meets specific needs of wireless devices not addressed by traditional internet technology.
2. **Flexible Data Transport:** Supports TCP/IP, UDP/IP, SMS, or USSD for data transfer.
3. **Modular Architecture:** Comprises entities forming a fully compliant internet structure.
4. **Standard Markup Languages:** Utilizes XML and WML for lightweight content delivery.

Conclusion: WAP offers network operators a scalable, interoperable, reliable, efficient, and secure solution.

# [WAP architecture | Mobile Computing | Lec-20 | Bhanu priya](https://www.youtube.com/watch?v=nElP0R6r5A0&ab_channel=Education4u)

## WAP Architecture ⭐

```
               WAP Architecture
┌──────────────────────┐  ┌----------------------┐
|   Application (WAE)  |  |                      |
└──────────────────────┘  └──┐  Other Services   |
┌──────────────────────────┐ |       and         |
|   Session Layer (WSP)    | |     Applications  |
└──────────────────────────┘ └───┐               |
┌──────────────────────────────┐ |               |
|   Transaction Layer (WTP)    | |               |
└──────────────────────────────┘ └───┐           |
┌──────────────────────────────────┐ |           |
|   Security Layer (WTLS)          | |           |
└──────────────────────────────────┘ └-----------┘
┌──────────────────────────────────────┐
|   Transport Layer (WDP)              |
└──────────────────────────────────────┘
┌──────────────────────────────────────┐
|  [GSM] [LS:L36] [CDMA] [PHS] [PCP-P] |
|  [IDEN] [FLEx] etc                   |
└──────────────────────────────────────┘
```

#### WAP Layers Function ⭐
**1. Application Layer :** Wireless Application Environment (WAE)
- General  purpose application environment based on a combination of `www` and mobile telephony technologies
- It defines the user interface on the phone. It contains `WML` and `WTA` (Wireless Telephony Application).
- Primary objective: Interoperable environment
- WAE includes a micro browser server environment which provides - WML, WML Script, WTA, Content formats.
- Note: micro browser : - piece of software which make small demands on hardware, memory and CPU

**2. Session Layer:** Wireless Session Protocol (WSP)
- Opens a session of communication between client and server
- Establishes protocol and negotiations
- Exchanges encoded data
- Exchanges requests and replies
- Supports asynchronous transmission of data

**3. Transaction Layer:** Wireless Transaction Protocol (WTP)
- It deals with transaction and retransmission of data, separation and concatenation of data.
- It runs on top of datagram service
- Lightweight transaction oriented protocol
- Three Classes of transaction services
	- Unreliable one-way requests
	- Reliable one-way requests
	- Reliable two-way request-reply

**4. Security Layer:** Wireless Transport Layer security (WTLS)
- Based on industry - Standard Transport Layer security Protocol
- Optimized for use over narrow-band communication channels
- Features:
	- Data Integrity
	- Privacy
	- Authentication
	- Denial-of-service protection 

**5. Transport Layer:** Wireless Datagram protocol (WDP)
- The WAP datagram protocol is the transport layer that sends and receives messages via, any available bearer n/w including `SMS`, `USSD`, `IS-136`, packet data and `GPRS`
- Operates above the data cable bearer services supported by various network types.
- Provides a common interface to the upper layer protocols and hence they function independent of the underlying wireless network.

**Bearers** : which is holding the network for transmitting the data
- Different levels of quality of services with respect to throughput, error rate and delays
- WAP protocols are designed to compensate for tolerate these varying levels of service
- WAP specification lists the bearer that are supported and techniques used to allow WAP protocols to run over Each bearer.
- ex: `WA`

>Unit 3

---

### Database Management Issues in Mobile Environment ⭐

Mobile environments introduce unique challenges in database management due to constraints like limited resources, intermittent connectivity, and variable performance. Below are the key issues in managing databases for mobile systems:

1. **Limited Resources**
   - **Memory & Storage Constraints**: Mobile devices typically have lower memory and storage capacity compared to desktop systems. 
	    -> Databases need to be lightweight, efficient, and optimized to fit into the constrained environment.
   - **Energy Consumption**: Mobile devices are battery-operated. Intensive database operations, like frequent syncing and large data processing, can drain battery life, 
		-> making energy-efficient database management critical.

2. **Intermittent Connectivity**
   - **Disconnection Issues**: Mobile devices often experience unstable network connections, leading to challenges in accessing remote databases. 
	   -> This requires databases to support offline operation and synchronize data when the connection is restored.
   - **Latency**: High latency and low bandwidth can affect the responsiveness of database queries,
	   ->requiring optimization of data transfer and query execution.

3. **Data Consistency & Synchronization**
   - **Synchronization Challenges**: Mobile environments often operate in disconnected or partially connected modes, leading to data inconsistencies when the device reconnects. 
	   -> Synchronization mechanisms must handle conflict resolution, data merging, and consistency maintenance.
   - **Eventual Consistency**: Mobile systems typically use an "eventual consistency" model, where data consistency is not guaranteed in real-time but is updated after synchronization with the central server.

4. **Security & Privacy**
   - **Data Security**: Mobile devices are more prone to physical theft or loss, increasing the risk of unauthorized access to sensitive data. 
	   -> Database systems must employ strong encryption and authentication methods.
   - **Data Privacy**: Privacy concerns arise due to the location-based and personal nature of data stored on mobile devices. 
	   -> Databases must ensure that personal data is protected and compliant with privacy regulations.

5. **Data Heterogeneity**
   - **Device Fragmentation**: There are many different mobile devices with varying hardware and software specifications. This can complicate data storage formats, making it challenging to ensure compatibility across devices.
   - **Multiple Data Sources**: Mobile applications may use a variety of data sources (e.g., cloud-based, local, remote), requiring integration and uniform access mechanisms.

6. **Performance Optimization**
   - **Query Optimization**: Given the limited processing power of mobile devices, optimizing database queries to minimize CPU usage and memory consumption is crucial.
   - **Caching**: To reduce the impact of network latency and frequent database access, caching mechanisms are often used to store frequently accessed data locally.

7. **Database Model Selection**
   - **Relational vs. Non-Relational**: Mobile environments may favor non-relational (NoSQL) databases due to their flexibility in handling unstructured data and scalability. However, relational databases are still preferred for applications requiring complex queries and strong consistency.
   - **Lightweight Database Systems**: Mobile databases need to be lightweight and tailored to the specific requirements of mobile applications, with examples like SQLite for local storage.

8. **Scalability**
   - **Handling Growing Data**: As mobile applications generate increasing amounts of data, the database system must scale efficiently to handle large datasets while minimizing performance degradation.

9. **Data Access & Query Processing**
   - **Local vs. Remote Queries**: Mobile databases need to handle both local queries (on-device) and remote queries (from a central server). Local queries must be optimized for limited resources, while remote queries need to account for connectivity constraints.
   - **Query Execution Efficiency**: With limited CPU and memory resources, mobile database systems must execute queries in a way that minimizes resource consumption while maintaining acceptable performance.

### Solutions and Techniques:
- **Offline Data Management**: Use of local caches and databases (e.g., SQLite) that allow mobile applications to function offline and sync when connectivity is available.
- **Data Replication**: Techniques such as database replication ensure that a copy of the data is maintained both on the mobile device and server, enabling seamless synchronization.
- **Lightweight Protocols**: The use of lightweight protocols like HTTP, REST, or MQTT reduces overhead and improves performance in mobile database access.
- **Compression**: Compressing data before transmission reduces the impact of bandwidth limitations and speeds up data transfer.
---
# [L22: Mobile Databases Introduction, Features, Requirement | Mobile Computing Lectures in Hindi](https://www.youtube.com/watch?v=-h7YaaqaJ7s&ab_channel=EasyEngineeringClasses)

### Mobile Databases
- Allows application for Hand-Held devices to access data stores even while on the move.
- Makes data from database application available all the time to the mobile users.
```
      ←--RES      ←--RES     ⤺
🤳-------------🌐---------🛢  Data Store
     REQ--→         REQ--→   ⤻
     
User           Internet    Application
```

Courier: Collects customer sign while o the move and send to main database

**Features of Mobile Database :**
1. Mobile transaction should be robust towards unexpected disconnection due to mobility.
2. Transaction processing system also needs to cope with restricted resources such as
	- Low Battery Life
	- Slow Processor speed
	- Limited Memory
3. Mobile application should react fast towards frequent environment changes:
	- Location
	- Network Bandwidth

**Requirement for Mobile Databases:**
- Mobile Database should have small footprint (Easily fit into resources constraint)
- Should be able to Run without monitoring (by database administrator)
- Should be easily interoperable (with large Database)
- Needs to support all basic database functionality (insert, update, delete)
- Commercially Available Mobile Relational Database systems
	- IBM DB2 Everywhere
	- Oracle Lite
	- Sybase SQL Anywhere

# [L23: Transaction Processing , Environments, Issue in Mobile Environment | Mobile Computing Lectures](https://www.youtube.com/watch?v=KxKfJP5DT7k&t=21s&ab_channel=EasyEngineeringClasses)

# [L24: Transaction Processing in Mobile Environment | Relaxation in ACID Properties | Mobile Computing](https://www.youtube.com/watch?v=kCO-BQt03ZI&ab_channel=EasyEngineeringClasses)
# [L26: Data Replication - Types(Asynchronous, Synchronous) | Mobile Computing Lectures in Hindi](https://www.youtube.com/watch?v=NnRLY378klA&ab_channel=EasyEngineeringClasses)

>Unit 4
# [Diffie Hellman Key Exchange Algorithm | Cryptography and Network Security](https://www.youtube.com/watch?v=zLNug0LrFiU&ab_channel=AbhishekSharma)

## Diffie-Hellman Key Exchange
(i) It is not an encryption algo
(ii) Used to exchange secret keys between 2 users
(iii) We will use asymmetric encryption to exchange the secret key between users.

Why to use such algorithm??
-> Because when we are sending a key to receiver, it can be attacked in between.

## Diffie-Hellman Algorithm:

1. **Choose Prime no. and Primitive Root**
	- Consider a prime number `q`
	-  Select `α` such that it must be the primitive root of q and `α<q`
```
α is a primitive root of q if

α MOD q
α^2 MOD q
α^3 MOD q 
α^(q-1) MOD q

gives results {1, 2, 3, ....q-1}

ex: 3 is primitive root of 7, 5 is primitive root of 7
```
2. **Key Generation of Person 1**
	-  Assume $X_A$ (Private Key of A) and $X_A < q$
	- Calculate $Y_A=α^{X_A}modq$ (Public Key of A)
3. **Key Generation of Person 2**
	- Assume $X_B$ (Private Key of B) and $X_B < q$
	- Calculate $Y_B=α^{X_B}modq$ (Public Key of B)
4. **Calculate the Secret Key** (using another's public key)
	- $K_A = (Y_B)^{X_A}modq$
	- $K_B = (Y_A)^{X_B}modq$
5. `KA=KB` Thus the Secret Key `KA` and `KB` are Exchanged.


#### Example
1. Let `q=7`(prime) 
2. let `α=5` (primitive root of q) 
3. Assume `XA=3` ($X_A<q$)
4. Calculating Public Key `YA=6` ($Y_A=α^{X_A}modq$ = $5^3mod7$)
5. Assume `XB=4`  ($X_B<q$)
6. Calculate Public Key `YB=2` ($Y_B=α^{X_B}modq$ = $5^4mod7$)
7. Calculate Secret Key `KA=1` ($K_A = (Y_B)^{X_A}modq$ = $(2)^3mod7$)
8. Calculate Secret Key `KB=1` ($K_B = (Y_A)^{X_B}modq$ = $(6)^4mod7$)
9. `KA=KB` Thus the Secret Key `KA` and `KB` are Exchanged.

Note: Both of them don't need any information from anyone. They just use `α` and `q` which are global (known to all).

```
Person 1       Global Elements      Person 2
(A)             ┌────────────┐         (B)
                │ q=7, α=5   |               
                └────────────┘          
                ┌────────────┐ 
XA=3            │ YA=6, YB=2 │        XB=4
                └────────────┘
             Public Keys         
```
# [RSA Algorithm](https://www.youtube.com/watch?v=VUxfDCmWM0U&ab_channel=GateSmashers)

**RSA (Rivest-Shamir-Adleman)** is a widely used public-key cryptosystem for secure data transmission. It was developed by *Ron Rivest*, *Adi Shamir*, and *Leonard Adleman* in 1977. 

RSA is based on the mathematical fact that it is easy to multiply large prime numbers together, but it is hard to factorize the resulting product.


1. **Public and Private Keys**: 
   - **Public Key**: Used to encrypt the message and can be shared openly.
   - **Private Key**: Used to decrypt the message and must be kept secret.

2. **How RSA Works**:
   - **Key Generation**:
     1. Choose two large prime numbers, `p` and `q`.
     2. Compute `n = p*q`. `n` is used as the modulus in both the public and private keys.
     3. Compute Euler’s totient function `ϕ(n) = (p-1)(q-1)`.
	     - i.e. find number of coprime of `n` Smaller then n
     4. Choose a public exponent `e` such that `1 < e < ϕ(n)` and `gcd(e,ϕ(n)) = 1.
	     - i.e. select one `e` from the coprime of `n` that  are smaller than n
     5. using the extended Euclidean algorithm, Compute the private exponent `d` such that `e*d ≡ 1 mod ϕ(n)`
	     - i.e. find smallest Integer `d` using `d*e = 1 + Kϕ(n)`by trying different values of K=0, 1, 2, 3.... 
     6. The public key is `(e, n)` and the private key is `(d, n)`.
	     - e=public key, d=private key

Ques. In a RSA cryptosystem a particular A uses two prime no. p=13 and q=17 to generate his public and private keys. If the public key of A is 35. Then find the private key of A

Step 1:  choose two different large random no. `p` and `q`
	p=13 , q =17 (Given)

Step 2: Calculate `n = p*q`
	n = p* q = 221
	
Step 3: Calculate `ϕ(n)=(p-1)*(q-1)`.
	ϕ(221) = 12 * 16 = 192
	
Step 4: choose `e` such that `1<e<ϕ(n)` such that `gcd(e,ϕ(n))=1`
	e=35 (Given)
	
Step 5: Calculate d, such that `d*e ≡ 1 mod ϕ(n)`
	find `d = (1 + Kϕ(n))/e` for k=0, 1, 2,....
	for K=0,   d = 0.02
	for K=1,   d = 5.5
	for K=2,   d = 11 ✅
	so d = 11

Step 6:
	public key = 35
	private key = 11
	
# Wireless Network Types
```
Network
├── Infrastructure Network
│   ├── Wired Networks
│   └── Wireless Infrastructure Networks
│       └── Cellular Networks
├── Non-Infrastructure Network
    └── Ad Hoc Networks
        ├── Mobile Ad Hoc Networks (MANET)
        │   ├── Vehicular Ad Hoc Networks (VANET)
        │   └── Flying Ad Hoc Networks (FANET)
        ├── Wireless Sensor Networks (WSN)
        └── Hybrid Ad Hoc Networks

```

### Single-hop vs Multi-hop Network

| Feature           | **Single-Hop Network**                         | **Multi-Hop Network**                        |
| ----------------- | ---------------------------------------------- | -------------------------------------------- |
| **Communication** | Direct from source to destination              | Source to destination via intermediate nodes |
| **Latency**       | Low latency (direct communication)             | Higher latency (due to intermediate nodes)   |
| **Range**         | Limited by the transmission range              | Extended range through relays                |
| **Complexity**    | Simple (no routing or relaying needed)         | More complex (requires routing protocols)    |
| **Scalability**   | Limited to small areas or devices within range | Scalable to large, wide-area networks        |
| **Examples**      | Wi-Fi, Bluetooth                               | MANETs, WSNs, cellular networks              |
# [L43: Mobile Adhoc Network Introduction | Characteristics, Properties, Challenges, Applications](https://www.youtube.com/watch?v=acdn4Q6YCY4&ab_channel=EasyEngineeringClasses)

### Mobile Ad-hoc Network (MANET)

MANET: A Mobile Ad Hoc Network (MANET) is a decentralized wireless network where mobile devices communicate directly without relying on a fixed infrastructure
or
Collection of mobile nodes that can be dynamically setup anywhere anytime without the need of fixed infrastructure

**MANET**
- Wireless Network
- No fixed infrastructure
- Dynamic Topologies
- Node in MANET can act as HOST or Router
- MANET is a autonomous collection of mobile users that communicate over wireless Links.

**Characteristics of MANET:**
- Dynamic Topology
- Energy constrained nodes.
- Limited Security
- Autonomous
- Distributed

**Properties of MANET:**
- Fast network establishment
- Peer-to-peer connectivity
- Independent computation
- No requirement of access point.
- Less wireless connectivity Range

**Challenges:**
- Topology
- Security
- Bandwidth
- Energy
- Routing

**Applications:**
- Battlefield - In War Zones  (because of Less time, and no infrastructure)
- Sensor network
- VANET - One car send info. about road block etc to other car.
- PAN

# [L44: MANET Routing Introduction | Types - Proactive, Reactive, Hybrid Routing in Mobile Computing](https://www.youtube.com/watch?v=nd87TUA_42M&t=5s&ab_channel=EasyEngineeringClasses)

Routing in MANET is Difficult than Normal Network due to non-fixed infrastructure and rapid change in topology (Due to node Mobility)

Routing Protocols should have:
- Reliability
- Least cost in routing traffic in Network
- Maximum throughput

### Three Types of Routing
##### 1. Proactive Routing
- Route is determined in advance
- Also called Table Driven Routing
- **Advantage:**
	- Low Route Latency
	- State information is there
	- Quality of Service is Guaranteed
- **Disadvantage:** 
	- More Overhead
	- Periodic update is needed
- Ex- GSR, DSDV, FSR
##### 2. Reactive Routing
- Route is determined only when needed.
- **Advantage:**
	- Less Overhead
	- No Periodic updates
	- Scalability is good
- **Disadvantage:** 
	- Route Latency is high
	- Route caching can be reduced.
- Ex- DSR, AODV, Location Aided routing.
##### 3. Hybrid Routing
- Proactive + Reactive
- Near by Nodes : Proactive, Information is stored
- Far away Nodes : Reactive, only on need basic

# Routing Algorithm by GPT

You are correct! **Global State Routing (GSR)** is a **proactive routing protocol**, not hybrid. Here's the corrected table:

| **Protocol** | **Full Form**                         | **Type**                            | **Description**                                                                                                                                                    |
| ------------ | ------------------------------------- | ----------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **GSR**      | Global State Routing                  | Proactive <br>+ <br>Link state      | Maintains global routing tables and periodically exchanges full routing information, making it suitable for static or less dynamic networks.                       |
| **DSDV**     | Destination-Sequenced Distance Vector | Proactive <br>+ <br>Distance Vector | A table-driven protocol that maintains routes to all nodes, e**nsuring loop-free paths using sequence numbers**. Based on the Bellman-Ford algorithm.              |
| **FSR**      | Fisheye State Routing                 | Proactive<br>+<br>Link State        | Optimizes routing by frequently updating routing information for nearby nodes and less frequently for distant nodes, reducing control message overhead.            |
| **DSR**      | Dynamic Source Routing                | Reactive<br>+<br>Link State         | Utilizes source routing, where the **sender includes the full path to the destination in the packet header**. Suitable for small or medium-sized dynamic networks. |
| **AODV**     | Ad Hoc On-Demand Distance Vector      | Reactive<br>+<br>Distance Vector    | Establishes routes only when needed using route discovery and maintenance. It ensures loop-free and fresh routes with the help of sequence numbers.                |
| **ASR**      | Adaptive State Routing                | Reactive                            | Adapts routing strategies based on network conditions, combining proactive and reactive approaches for better performance in dynamic environments.                 |
| **TORA**     |                                       | Reactive                            |                                                                                                                                                                    |


# [L12: Destination Sequenced Distance Vector(DSDV) Routing Protocol | Adhoc Sensor Network Lectures](https://www.youtube.com/watch?v=gxJR_4NLB24&ab_channel=EasyEngineeringClasses)


# [L14: Dynamic Source Routing(DSR) Protocol | Adhoc Network Routing Protocol | ASN Lectures in Hindi](https://www.youtube.com/watch?v=7RSm19cLcko&t=312s&ab_channel=EasyEngineeringClasses)

![[Pasted image 20241118212059.png]]

![[Pasted image 20241118212152.png]]
# [L15: Adhoc On-Demand Distance Vector(AODV) Routing Protocol | Adhoc Network Routing Protocol](https://www.youtube.com/watch?v=6Q4A_snx4MQ&ab_channel=EasyEngineeringClasses)

## Ad-hoc On-Demand Distance vector (AODV) Routing Protocol

**Type**: Reactive (On-Demand)
**Algorithm:** Distance Vector

**Overview**
AODV combines features of DSDV (sequence numbers for loop-free paths) and DSR (on-demand route discovery), 
- Unlike DSR, AODV does **not maintain complete paths** at the source, reducing packet overhead.
- Unlike DSDV, AODV reduces overhead by initiating route discovery only when needed, unlike the periodic updates in DSDV `+` avoids maintaining extensive routing tables, keeping only **next-hop** and **previous-hop** information for active routes.

It operates on two Phases
1. Route Discovery
2. Route maintenance

-> Unlike DSR, Source node will not carry the complete path. (i.e. Each node doesn't maintains Route Cache)
-> Each node only knows its `previos` and `next` hop information


### Phases of AODV

#### 1. Route Discovery
When a source node needs a route to a destination, it initiates the **Route Discovery** process:
- **RREQ (Route Request)**: The source broadcasts a Route Request packet containing:
    
    1. Source Node ID
    2. Destination Node ID
    3. Broadcast ID (to prevent duplicate processing)
    4. Hop Count (to measure distance to destination)
    5. Recent Sequence Number (to ensure the freshness of the route)
- Intermediate nodes either reply with a Route Reply (RREP) if they have a fresh route or forward the RREQ further toward the destination.
    

#### 2. Route Maintenance
Routes are maintained only as long as they are in use.

- When a link break is detected, an **RERR (Route Error)** packet is sent to affected nodes to invalidate the broken route.
- Nodes receiving RERR initiate a new Route Discovery if needed.
 
## AODV vs DSR (RREQ and RREP)

Both **AODV (Ad hoc On-Demand Distance Vector)** and **DSR (Dynamic Source Routing)** use similar concepts for route discovery, but they handle RREQ and RREP messages differently.

- **AODV (Ad hoc On-Demand Distance Vector)** uses **RREQ** (Route Request) and **RREP** (Route Reply) messages, but the routing information is stored in routing tables at each node. The RREQ is broadcasted to discover a route, and the RREP provides a route back to the source.
    
- **DSR (Dynamic Source Routing)** also uses **RREQ** and **RREP** for route discovery, but the main difference is that **DSR** uses source routing, where the sender node includes the complete route (a list of intermediate nodes) in the **RREQ** message. When the RREQ reaches the destination or a node with a valid route, the **RREP** message is sent back along the same path.


# [TORA(Temporally Ordered Routing Algorithm) MANET Routing Protocols](https://www.youtube.com/watch?v=Tr8WtiYQGqQ&ab_channel=HowTo)

