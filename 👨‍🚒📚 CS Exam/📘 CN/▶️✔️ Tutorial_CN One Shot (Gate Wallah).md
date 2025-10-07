
# [Computer Networks One Shot | CS & IT Engineering Maha Revision | Target GATE 2025](https://youtu.be/hlHXNmbozd8)


**Topics to be covered**
1. OSI & TCP/IP Model
2. Application Layer
3. Transport Layer
4. IPv4 Address
5. IPv4 Packet Header
6. Switching & Routing
7. Flow Control
8. Error Control
9. MAC Sub-layer
10. Framing


✅ **Note:** GATE syllabus follows the **TCP/IP model** (4 layers).  
❌ **Physical Layer is excluded** as it's **not part of GATE syllabus**.

# OSI & TCP/IP Model 

##### **OSI Model** -> 7 Layers

| **Layer No.** | **OSI Layer Name** |
| ------------- | ------------------ |
| Layer 7       | Application Layer  |
| Layer 6       | Presentation Layer |
| Layer 5       | Session Layer      |
| Layer 4       | Transport Layer    |
| Layer 3       | Network Layer      |
| Layer 2       | Data Link Layer    |
| Layer 1       | Physical Layer     |

##### **TCP/IP Model** → Subset of OSI Model


**5-Layer OSI Model (Simplified)**

| **Layer No.** | **OSI Layer Name** |
| ------------- | ------------------ |
| Layer 5       | Application Layer  |
| Layer 4       | Transport Layer    |
| Layer 3       | Network Layer      |
| Layer 2       | Data Link Layer    |
| Layer 1       | Physical Layer     |
✅ We will follow this in our syllabus


**4-Layer TCP/IP Model vs OSI Model**

| **Layer No.** | **OSI Layer**                        | **TCP/IP Layer** |
| ------------- | ------------------------------------ | ---------------- |
| Layer 4       | Application, Presentation, Session → | Application      |
| Layer 3       | Transport →                          | Transport        |
| Layer 2       | Network →                            | Internet         |
| Layer 1       | Data Link, Physical →                | Network Access   |

##### **Layer Services**

- **Higher Layers Order to its Subordinates Lower Layer**
- Lower layers then Provide Services to its upper layer


| Layer          | Provide Services (to its upper layer)                                                                                                                                                              | Data Unit Transferred          |
| -------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------ |
| Application    | ❌ No Upper Layer                                                                                                                                                                                   | Message                        |
| Transport      | Process-to-Process Communication <br>                   OR <br>Two Processes (on different devices) communicate via socket<br>                   OR<br>Socket-to-Socket (End-to-End) Communication | Segment (TCP) / Datagram (UDP) |
| Network        | Host-to-Host Communication<br>                   OR<br>Routing                                                                                                                                     | Packet                         |
| Data Link      | Node-to-Node Communication<br>                 OR<br>Responsible for delivering frames to **adjacent nodes**                                                                                       | Frame                          |
| Physical Layer | Between Nodes on Medium<br><br>                                                                                                                                                                    | Bits (0s and 1s)               |

- **Process** → application-level entities
- **Host** → devices (computers)    
- **Node** → devices on the same link (could be routers, switches, etc.)

**Notes:**
- The processes in **Transport Layer** communication can be on the **same or different devices**, but typically. **In networking context (GATE)**-  It's about communication between **processes on different devices** over a network.

- For **Network Layer**  Communication Node must be a **network device (Layer 3 or above)**, **not a Layer 2 device** like a Hub, Switch or Bridge


##### **Data Flow in a Network Stack** ⭐

> Added by me

**1. Message (Application Layer)**
- This is the **raw data** created by an application (e.g., an email, HTTP request, file transfer).
- Example: 
```
"GET /index.html HTTP/1.1\r\nHost: example.com\r\n\r\n"`
```


**2. Segment (Transport Layer)**
- The application message is passed to the **Transport Layer** (TCP or UDP), which adds its own header.
- **TCP**: Adds source port, destination port, sequence number, etc.
- **UDP**: Adds simpler headers.
- Now it becomes a **segment**.

Example:  
``` 
[TCP Header | Message] = Segment
```

**3.1 Packet (Network Layer)**
The segment is passed to the **Network Layer (IP)**, which adds the IP header.
- This includes source IP, destination IP, TTL, etc.  
    Now it's called a **packet** or **datagram**.
- Example:  
```
[IP Header | TCP Segment] = Packet
```

**3.2. Fragment (Network Layer, if needed)**
- If the packet size > **MTU** (Maximum Transmission Unit), it is split into **fragments**.
- Each fragment gets its own **IP header**
- Only the **first fragment** contains the transport header
- IP header includes: Identification field (same for all fragments), Offset, MF (More Fragments) flag
-  Example:
 ```
 [IP Header + Fragment 1]
 [IP Header + Fragment 2]
 ...
 ```

**4. Frame (Data Link Layer)**
- Each fragment is passed to the **Data Link Layer** (like Ethernet), which adds a **Frame Header and Trailer** (e.g., MAC addresses, checksum).  
- Now it's a **frame** ready for transmission over the physical medium.
- Example:  
```
[ Frame Header | IP Fragment | Frame Trailer] = Frame
```

 **6. Bits (Physical Layer)**
- Finally, the frame is converted into **bits (0s and 1s)** and transmitted over the wire, fiber, or wireless medium.

**Summary Table**

| Term     | Layer               | Contains                         |
| -------- | ------------------- | -------------------------------- |
| Message  | Application         | App data (e.g., HTTP, SMTP)      |
| Segment  | Transport (TCP/UDP) | TCP/UDP header + Message         |
| Packet   | Network (IP)        | IP header + Segment              |
| Fragment | Network (if large)  | IP header + part of Segment      |
| Frame    | Data Link           | MAC header + Fragment + Trailer  |
| Bits     | Physical            | 0s and 1s transmitted physically |


##### **Networking Devices**

| **OSI Layer Name** | **Networking Device**            |
| ------------------ | -------------------------------- |
| Application Layer  | Gateway (Layer 7)                |
| Transport Layer    | ❌ No Device                      |
| Network Layer      | Router (Layer 3) ⭐               |
| Data Link Layer    | Switch / Bridge (Layer 2) ⭐      |
| Physical Layer     | Hub / Repeater / Modem (Layer 1) |

❌ **Gateway is No more in GATE Syllabus**

**Note:**
- **Both Gateway and Router** used for routing and connect two different network. The difference is that
	- **If the two Network Homogeneous** (Similar Type) -> i.e. Running on similar protocol, than Router is enough to route packet between two network
	- **If the two Network are Heterogenous** -> Than a Powerful device is  Required i.e. Gateway (Protocol Converter)

- **Switch (Modern)** is an **advanced version of Bridge**:
    - More ports
    - Features like **cut-through**, **store-and-forward**, etc.
        
- **Transport Layer**:
    - No physical device
    - Handles **logical end-to-end communication** (e.g., TCP/UDP)

❌ **Gateway is No more in GATE Syllabus**


---

# Application Layer


##### **Application Layer Protocols:**

1. DNS : Domain Name System
2. HTTP : Hyper Text Transfer Protocol
3. FTP : File Transfer Protocol
4. SMTP : Simple mail transfer Protocol

**Note:**
- All the 4 protocols work on Client-Server Model


**Client-Server Model:**

- A **Client-Server Model** is a **network architecture** where:
	- One side acts as a **Client**:  
	    → Requests data or services (e.g., browser, mail app)
	- Other side acts as a **Server**:  
	    → Provides the requested data or services (e.g., web server, mail server)

	**Key Point :**
		- Communication is **one-to-one** (Client → Server)
		- Server is always (**24x7**) ON and waiting for client requests

| **Protocol** | **Client Role**                              | **Server Role**                               |
| ------------ | -------------------------------------------- | --------------------------------------------- |
| DNS          | Sends domain name query                      | Resolves domain to IP address                 |
| HTTP         | Sends request for web page                   | Serves web page content                       |
| FTP          | Requests to upload/download files            | Provides file storage and access              |
| SMTP         | Sends email to server (outgoing mail client) | Forwards/delivers email to recipient's server |

##### **Application Layer Protocols and their Transport Layer Protocols**

| **Application Protocol** | **Transport Layer Protocol (TCP or UDP)**                         |
| ------------------------ | ----------------------------------------------------------------- |
| DNS                      | By Default  - **UDP**  (port 53), <br>For zone transfer - **TCP** |
| HTTP/1 & HTTP/2          | **TCP** (port 80) ⭐                                               |
| HTTP/3                   | **UDP** (uses QUIC over port 443)                                 |
| FTP                      | **TCP** (ports 20, 21) ⭐                                          |
| SMTP                     | **TCP** (port 25) ⭐                                               |
| POP/IMAP                 | **TCP** (POP: 110, IMAP: 143) ⭐                                   |
| DHCP                     | **UDP** (ports 67, 68)                                            |
| RIP                      | **UDP** (port 520)                                                |
| BGP                      | **TCP** (port 179)                                                |

❌ BGP is not in Syllabus

**Note:**
- **Application Layer** protocols uses **Transport Layer** Protocol
- **TCP** is used when **reliable**, **connection-oriented** communication is needed.
- **UDP** is used for **faster**, **connectionless** communication where some loss is acceptable.
- Some protocols like **DNS** can use both **UDP** (for queries) and **TCP** (for zone transfers).

##### **Stateful vs Stateless**

**Transport Layer**
- **Stateless** (Doesn't maintain connection/session state):
    - **UDP**  (Also Connection-less )
        
- **Stateful** (Maintains connection/session state):
    - **TCP**  (Also Connection-oriented)

**Application Layer**
- **Stateless** (Doesn't maintain user/session information): ⭐
    - **DNS**, **HTTP**, **SMTP**
        
- **Stateful** (Maintains user/session information): ⭐
    - **FTP**, **IMAP**, **POP**
        
**Note:**

- An **application protocol using UDP** does **not necessarily mean** it is **stateless**  
    → _Example: DHCP uses UDP but is stateful (maintains IP lease info)_


##### **DNS Hierarchy Levels**

| **Level**                | **Description**                  | **Example in `www.pw.live`** |
| ------------------------ | -------------------------------- | ---------------------------- |
| Level 1 - Root           | `.` (implicit)                   | Root Server                  |
| Level 2 - TLD            | Top-Level Domain                 | `.live`                      |
| Level 3 - SLD            | Second-Level Domain              | `pw`                         |
| Level 4 - Subdomain/Host | Hostname or additional subdomain | `www`                        |

**Domain Name Levels** - Example

| **Domain Example**    | **Levels** | **Explanation**                                                                       |
| --------------------- | ---------- | ------------------------------------------------------------------------------------- |
| `www.pw.live`         | 3-Level    | `www` (subdomain/host)  <br>`pw` (domain) <br>`live` (TLD)                            |
| `shop.www.google.com` | 4-Level    | `shop` (sub-subdomain/host) <br>`www` (subdomain)<br>`google` (domain)<br>`com` (TLD) |
| `www.iitd.ac.in`      | 4-Level    | `www` (subdomain/host)<br>`iitd` (domain)<br>`ac` (2nd-level TLD)<br>`in` (TLD)       |
##### **DNS Name Resolver**

- **DNS Resolver**: A program (usually part of OS or ISP) responsible for **resolving domain names** to IP addresses
- The process is called **DNS Name Resolution** or **DNS Lookup**

- **Types of DNS Queries:**
	1. **Recursive Query**  
	    → Resolver takes full responsibility and returns the final IP to the client  
	    → Common in real-world client systems
	    
	2. **Iterative Query**  
	    → Resolver/client contacts each DNS server step-by-step, receiving referrals  
	    → Used more within DNS server infrastructure

**Note:**
- The **DNS Hierarchy (Root → TLD → Authoritative)** remains the **same** for both
- What differs is **who traverses** that hierarchy:
    - **Recursive**: Resolver does it
    - **Iterative**: Client does it (step-by-step)


##### **Iterative Query Resolution**

→ Resolver/client contacts each DNS server step-by-step, receiving referrals  
→ Used more within DNS server infrastructure
```                   
                                       DNS Hierarchy

         ┌--------- DNS Query ------> [ RootName Server ]
         |  ┌------ DNS Reply ------   
         |  |       (.live)
         |  |
         |  |
         |  ↓  
[DNS Resolver] --- DNS Query --->     [TLD Name Server]
         ↑  |  <--- DNS Reply ---      
         |  |       
         |  |
         |  |  
         |  └─----- DNS Query ---->  [Authoritative Name Server]
         └─-------- DNS Reply ----     

```

**Iterative Query Example :** `www.pw.live` : 
1. **Client** → **DNS Resolver:** Asks: “What is the IP of `www.pw.live`?”
2. **Root Server**
	- **DNS Resolver → Root Server**:  Asks: “What is the IP of `www.pw.live`?”
	- **Root Server → DNS Resolver**:  “Ask `.live` TLD server”
3. **TLD Server**
	- **DNS Resolver → TLD Server (.live)**:  “What is the IP of `www.pw.live`?”
	- **TLD Server → DNS Resolver**:  “Ask `pw.live` authoritative server”
4. **Authoritative Server**
	- **DNS Resolver → Authoritative Server**:   “What is the IP of `www.pw.live`?”
	- **Authoritative Server → DNS Resolver:   Returns IP `192.0.2.1`
5. **DNS Resolver** → **Client**

##### **Recursive Query Resolution**
→ Resolver takes full responsibility and returns the final IP to the client  
→ Common in real-world client systems
```
                         
                                      DNS Hierarchy

         ┌--------- DNS Query ------> [ Root Name Server ]
         |  ┌------ DNS Reply ------      ↑  |
         |  |                             |  | 
         |  |                       Reply |  | Query
         |  |                             |  |
         |  ↓                             |  ↓ 
    [DNS Resolver]                    [ TLD Name Server]
                                          ↑  |
                                          |  |
                                    Reply |  | Query
                                          |  ↓
							        [Authoritative Name Server]
							              
```

**Recursive Query Example :** `www.pw.live` : 
1. **DNS Query**
	- **Client → DNS Resolver**:  Sends a **recursive query** for `www.pw.live`
	- **DNS Resolver → Root Server (.)**:  Asks: “Who knows about `.live`?”
	- **Root Server → TLD Server (.live)**:  Asks: “Who knows about `pw.live`?”
	- **TLD Server → Authoritative Server**:  Replies with **Authoritative server** for `pw.live`

2. **DNS Reply**
	- **Authoritative Server → TLD Server**:  Returns **IP address** (e.g., `192.0.2.1`)
	- **TLD Server → Root Server**:  Returns **IP address** (e.g., `192.0.2.1`)
	- **Root Server → DNS Resolver:  Returns **IP address** (e.g., `192.0.2.1`)
	- **DNS Resolver → Client**:  Sends back final IP `192.0.2.1`

**Note:**
- We **don’t need to handle DNS hierarchy manually**
- Our **ISP or OS DNS Resolver** takes care of:
- As users or application developers,  we just request a domain name (e.g., `www.google.com`) and the **resolver returns the IP address**


##### **HTTP Connections**

**Two types of HTTP connection**s ⭐

==- HTTP relies on TCP's 3 way handshake==

- **Non-persistent HTTP** : `HTTP/1.0`
    - At most one object is sent over a single TCP connection
    - Downloading multiple objects requires multiple TCP connections
        
- **Persistent HTTP** : `HTTP/1.1`
    - Multiple objects can be sent over a single TCP connection (between client and server)

**1. Non-persistent HTTP (HTTP 1.0)**
```
HTTP Client        HTTP Server
	| ⬊     	    |
	|	  ⬊	 SYN    |
	|		  ⬊	    |
    |		      ⬊ |
	| SYN+ACK     ⬋ |
	|	     ⬋      |
	|	 ⬋		    |
 ...|⬋	            |...
	|⬊  ACK + HTTP  |
	|    ⬊  Req.	|
	|	      ⬊     |
    |		      ⬊ |
	| Object      ⬋ |
	|Transmit ⬋     |
	|	  ⬋	        |
 ...| ⬋	            |...
```

- ==One-time use: connection is closed after the response==
- For each new object, a new TCP connection is required
- `n` TCP connections are needed to send `n` objects (can be parallel)
- Objects include HTML, images, CSS, JS, videos, etc.


**2. Persistent HTTP (HTTP 1.1)**

```
HTTP Client        HTTP Server
	| ⬊     	    |
	|	  ⬊	 SYN    |
	|		  ⬊	    |
    |		      ⬊ | 
	| SYN+ACK     ⬋ |
	|	     ⬋      |
	|	 ⬋		    |
 ...|⬋	            | ...
	|⬊  ACK + HTTP  |
	|    ⬊  Req.	|
	|	      ⬊     |
    |		      ⬊ | 
	| Object      ⬋ |
	|Transmit ⬋     |
	|	  ⬋	        |
 ...| ⬋	            |...
 	|⬊      HTTP    |
	|    ⬊  Req.	|
	|	      ⬊     |
    |		      ⬊ |
	| Object      ⬋ |
	|Transmit ⬋     |
	|	  ⬋	        |
 ...| ⬋	            |...
    .               .
    .               .
    .               .
```

- ==Multiple objects can be transferred over a single TCP connection==
- Connection is closed explicitly by client (via 4-way FIN-ACK handshake)
- Requests can be pipelined (sent without waiting for previous responses)

**Pipeline Mode:**
```
 	|⬊⬊⬊      Multiple|
	|    ⬊⬊⬊  Requests|
	|	     ⬊⬊⬊      |
    | Multiple   ⬊⬊⬊  |
	| Objects    ⬋⬋⬋  |
	|         ⬋⬋⬋     |
	|	  ⬋⬋⬋         |
    | ⬋⬋⬋             |
```
- Not necessary to send → receive → send in strict sequence
- Multiple requests can be sent back-to-back without waiting for responses
- Pipelining support is optional (browser & server dependent)
- Most modern browsers use pipelining or parallel persistent connections

##### **Email**


```
                  SMTP                         (message queue)
User Agent 1  -------------------→  Mail Server 1
	↑									|                               |                                   |
	|									| SMTP
	|									|
	|									↓
User Agent 2   ←------------------   Mail Server 2
                    IMAP                         (Mail Box)
                                                 
 ```

**Key Components:**
- **User Agent (UA):**  
    Application like Gmail, Outlook, etc. used to compose, **send, receive, and read** emails.
- **Mail Server:**  
    Each user has a mail server (e.g., Gmail, Yahoo) that temporarily stores and forwards messages.

**Protocols:**

1. **SMTP (Simple Mail Transfer Protocol)**
    - Used for **mail transmission** (User Agent → Mail Server → Mail Server)
    - Works in **push mode**
    - **Persistent TCP connection** ⭐
    - ==**Stateless** ==– User Agent 1 and Mail Server 1 do **not maintain** the state of sent mails (once sent, no tracking of delivery status or read status) ⭐
        
2. **IMAP (Internet Message Access Protocol)**
    - Used for **mail download** (Mail Server → User Agent)
    - Supports ==multiple device login==
    - Allows ==**hierarchical storage**==: folders, labels, inbox, etc.
    - ==**Stateful**== – Mail Server 2 and User Agent 2 **maintain state** of mails (e.g., read/unread status, spam alerts for repeated mails, flags, folders) ⭐

-  **POP (Post Office Protocol):**
    - Older version of IMAP
    - Problem: If logged in on one device, others may be logged out
    - No proper sync or folder structure support


##### **FTP**

```
            (1) FTP Control Connection (Persistent TCP)
[FTP Client] -----------------------------------------→ [FTP Server]
             ←----------------------------------------


             (2) FTP Data Connection (Non-Persistent TCP)
[FTP Client] -----------------------------------------→ [FTP Server]
             ←-----------------------------------------

FTP Server : Server of Files
```

**FTP uses two separate TCP connections:**
1. **Control Connection**
    - Established at the beginning and remains open throughout the session
    - Used to send **commands** (e.g., login, list files, initiate transfer)
    - ==**Persistent TCP connection**==
        
2. **Data Connection**
    - Created **separately** for each file transfer (upload/download)
    - Closed after the transfer completes
    - ==**Non-persistent TCP connection**==
- Data Connection can also be from client to server as upload

**Upload & Download:**
- **Upload:** Client → Server (Data connection initiated by client)
- **Download:** Server → Client (Data connection may be initiated by server depending on mode)

**Modes of FTP:**
- **Active Mode:** ==Server initiates data connection to client==
- **Passive Mode:** ==Client initiates both control and data connections== (common in modern systems due to firewalls)

---
# Transport Layer

Provide logical communication between application processes (Processes running on different hosts)

Two Transport Layer Protocols :
1. UDP - User Datagram Protocol
2. TCP - Transmission Control Protocol

**1. UDP (User Datagram Protocol)**
- ==**Connection-less** and **unreliable** service==
- Messages may be **lost**, **duplicated**, or **arrive out of order**
- Lightweight, **simple**, and **fast**
- ==Preferred for **short communications**== like query-response
- Used by: **DNS**, **SNMP**, **HTTP/3**, **RIP**, and **real-time multimedia streaming** ⭐
    
**2. TCP (Transmission Control Protocol)**
- ==**Connection-oriented** and **reliable** service==
- Ensures **in-order delivery**, and detects/retransmits lost packets
- Provides ==**flow control**, **error control**, and **congestion control**== ⭐
- ==Preferred for **long communication**== and **data integrity-sensitive applications**

##### **Sequence Number**

- **TCP is a byte-stream protocol** (Stream-oriented)
- Uses ==**32-bit sequence numbers**==
- A **unique sequence number is assigned to each byte** (not segment) ⭐
- The **sequence number in a TCP segment** represents the **sequence of the first byte in the payload**
- Using this, we can calculate:
    - Sequence numbers of all bytes in the segment    
    - Sequence number of the **next segment** (by adding payload size to current sequence number)

- 🔄 **Common doubt:**
    - ==Sequence number is assigned **per byte**, **not per segment**== ⭐

---

##### **Acknowledgment Number (TCP)**

- **TCP acknowledgments are piggybacked**
    - **Meaning:** The TCP header has a field for acknowledgment; even when sending data, acknowledgment info is included in the same segment
    - No separate ACK-only packet is needed if data is also being sent
        
- **TCP uses cumulative acknowledgment**
    - Receiver ==acknowledges the **next expected byte== sequence number**
    - This implies that **all previous bytes (Ack No - 1 and before)** have been received successfully ⭐
    - Example: If `Ack = 501`, it means bytes `0–500` have been received
        
- **Ack Number Formula:**  
    `Ack Number = Last Received Byte’s Sequence Number + 1`
- **Selective Acknowledgment (SACK)**
    - An **optional TCP header extension**
    - Used when **out-of-order segments** are received
    - Tells sender: “I’ve already received these segments even if earlier ones are missing, so don’t resend them”
    - Improves performance over poor networks
        
**Cumulative vs Selective ACK**

|Type|Location|Behavior|
|---|---|---|
|Cumulative|TCP Base Header|Acknowledges **up to** the last contiguous byte received|
|Selective|TCP Optional Field|Acknowledges **specific higher-order byte ranges** already received|



**Note:** ⭐

- **In Data Link Layer (e.g., Stop-and-Wait / Go-Back-N):**
    - ==**Sequence numbers are assigned to Frames**==
    - Acknowledgment numbers refer to **Frame Numbers** (Frame 0, 1, etc.)
        
- **In TCP (Transport Layer):**
    - ==**Sequence numbers are assigned to Bytes**==
    - Acknowledgment number refers to the **next expected Byte**
    - So, even if a segment (packet) contains 500 bytes, **sequence and acknowledgment tracking is per byte**, not per segment
        

##### **Maximum Segment Lifetime (MSL)** ⭐

**What is MSL?**

- ==**MSL (Maximum Segment Lifetime)**== is the **maximum time** a TCP segment is allowed to exist in the network before being discarded.
- It also relates to ==**wrap-around time**==, i.e., the **minimum time** in which a **sequence number can be reused**.
    
 
 **Understanding Sequence Numbers in TCP**
 
- TCP assigns a **sequence number to each byte** of data.
- The **sequence number field** in TCP is **32 bits** long ⇒ can represent numbers from `0` to `2³² - 1`.
- So, total sequence number range = `2³²` = `4,294,967,296` bytes = **4 GB** ⭐
- Once the value reaches `2³² - 1`, it wraps around to `0`, `1`, and so on.  
    ==This phenomenon is called **sequence number wrap-around**.== 
    

**Initial Sequence Number (ISN)**

- During **TCP connection establishment**, both client and server **randomly choose an ISN**.
- The ISN itself is **consumed** during the handshake.
- So, the **first byte of ==actual data** sent has **sequence number = ISN + 1**==
- **Example:**
```text
TCP Socket (Process P1)

Send Buffer:  [ Message 1 | Message 2 | Message 3 | .... ]
               ^ (starting at sequence no. = ISN + 1 = 1234)
```

**Sequence Number Wrap-Around**

- Consider ISN = `1233`, then:
    - First data byte → sequence no. `1234`
    - If 4 GB of data is sent, sequence number goes from `1234 → 2³²-1 → 0 → 1 → ... → 1233 → 1234`
    - Sequence number **wraps around** to the original value
```text
TCP Socket (Process P1)

Send Buffer: [ Message 1 | Message 2 | .... ]
               1234 .... (2³²-1), 0, 1 .... 1233, 1234
               |                                    |
               ╰---------- 2³² bytes ------------╯
```

**File Transfer & Sequence Management**

- Each file is divided into **messages** or **segments**
- The **sequence number** marks the **first byte** in that segment.
- If **Message 1** starts at sequence **1234** and has **100 bytes**, it ends at **1333** (since 1234 + 100 − 1 = 1333).
- **Message 2** then starts at **1334** and continues similarly.
- ... and so on
        
- TCP socket maintains state to **track the next sequence number** and **received ACKs**
    

**Problem: What if File Size > 4GB ?** ⭐

- Then sequence numbers **repeat**
- But this creates **ambiguity** in identifying if a segment is **new** or a **duplicate**
    
**Wrap Around Time**

- **Wrap-around time** = time taken to transmit 4GB of data at the given bandwidth
- **Formula:**
```
Wrap-around time = 2^32 Bytes / Bandwidth
                 = 4 GB / Bandwidth
```
- **Faster bandwidth ⇒ shorter wrap-around time**
- ==Repeating sequence numbers **within wrap-around time** may cause confusion==
    

**Maximum Segment Lifetime (MSL)**

- MSL is the **maximum time a segment can stay alive in the network**
- To ==avoid confusion with repeated sequence numbers==, **MSL must be ≤ wrap-around time** ⭐
- **To maximize MSL**:  Ensure that **wrap-around time is large enough** (by limiting bandwidth or using sequence number extensions)

| Term                | Description                                                |
| ------------------- | ---------------------------------------------------------- |
| ISN                 | Initial Sequence Number (chosen randomly during handshake) |
| TCP Seq No.         | Assigned to **each byte**, not segment                     |
| Wrap-Around Time    | Minimum time after which a sequence number can repeat      |
| Wrap-Around Formula | `2^32 / Bandwidth`                                         |
| MSL                 | Time after which a TCP segment is considered **invalid** ⭐ |
| Condition           | `MSL ≤ Wrap-around time`                                   |

##### **TCP Operation**

- TCP communication happens over a **TCP connection**
- This connection is established **between two TCP sockets**
- It is **not a physical** connection but a **logical (virtual)** connection between two endpoints

- TCP is a stateful protocol because it maintains connection state across three phases: connection establishment (3-way handshake), data transfer (tracking sequence and acknowledgment numbers), and connection termination (4-way handshake), ensuring reliable and ordered communication. ⭐ 

**Three Phases of TCP Operation:**

1. **Connection Establishment**
    - Done via a **3-way handshake**
2. **Data Transfer**
    - Reliable, ordered delivery of bytes
3. **Connection Termination**
    - Done via a **4-way handshake**

**1. TCP Connection Establishment (3-Way Handshake)**
```
				TCP Client        TCP Server
				(ISN = x)         (ISN = Y)
..........................................
					| ⬊      SYN +  	  |     
	                |	 ⬊  Seq no. = x   | 
					|		 ⬊	          |  }  LISTEN
				    |		    ⬊         |      
	SYN - SENT {    |		        ⬊     |      
				    |		           ⬊  |     
				    |...........................................
				    |       SYN +      ⬋   |
					|  Seq no. = y  ⬋      |
					|	   +    ⬋          |  }  SYN - RCVD
					|	     ⬋	 ACK +      |
					|    ⬋  ACK no. = x+1   |
				    |⬋	                    |
........................................... |
				    | 				        | 
					| ⬊    Seq no. = x+1    |  
					|	   ⬊                |  
					|  ACK     ⬊            |  
				    |	+	       ⬊        |
   ESTABLISHED	{   | ACK No. = y+1    ⬊    |
				    |		              ⬊ |   
				    |..............................................
				    |                        |
                    |                        | } Established
                    |                        | 
                    .                        .
                    .                        .
                    .                        .
```
- **Client chooses ISN = x**, sends SYN with Seq = x
- **Server chooses ISN = y**, sends SYN+ACK (Seq = y, Ack = x+1)
- **Client replies with ACK** (Seq = x+1, Ack = y+1)
- Both sides now enter **ESTABLISHED** state
    
 **Note:**
 - **Server is passive** (always ready to accept connections)
 - **Client initiates** the connection


**2. TCP Connection Termination (4-Way Handshake)**
```
				TCP A              TCP B
		
				    .                     .
	ESTABLISHED {   .                     .
				    .                     .
...........................................
					| ⬊      FIN     	  |     
	                |	   ⬊              | 
					|		   ⬊	      |  } ESTABLISHED 
	  FIN-WAIT-1  { |		       ⬊      |      
				    |		           ⬊  |     
				    |...........................................
				    |                     |
				    |                  ⬋  |
					|     ACK     ⬋       |  } CLOSE-WAIT
					|	      ⬋	           .....................
					|    ⬋             ⬋  |
....................|⬋	           ⬋      |
					|          ⬋          |
	FIN-WAIT-2	 {  |	   ⬋	  FIN      |
					|  ⬋                   |
........................................... |  } LAST-ACK
					| ⬊               	   |     
	                |	   ⬊     ACK       | 
					|		   ⬊	       |  
	 TIME-WAIT    { |		       ⬊       |      
	 = 2 xMSL	    |		            ⬊  |     
				    |...........................................
                    |                      |
                    |                      |  CLOSED
                    |                      |
                    |                      |
                    |                      |
                    |                      |
....................|                      |

CLOSED
```

- ==**Any side** can initiate termination== (hence named as TCP A and TCP B)
    
- The **side that initiates first (TCP A)**:
    - Sends **FIN** first
    - **Closes last**, after entering **TIME-WAIT**
        
- The **other side (TCP B)**:
    - Moves to **CLOSE-WAIT**
    - Responds with **FIN**
    - Enters **CLOSED** after receiving ACK (from TCP A)

**Note:**
- The TCP side that initiates the connection termination will be the last to fully close the connection (after TIME-WAIT).

##### **TCP Socket**

- **Server creates `socket()` first.**
- `socket()` and other related functions (like `bind()`, `listen()`, `accept()`) are **library functions that make system calls** to the kernel.
- When the server calls `listen()`, it **enters a blocking state** and **waits for client requests**. It cannot proceed until a connection is accepted (unless closed forcefully).
- The client calls `connect()`, which initiates the **3-way handshake**.
```
		TCP Client					TCP Server
		----------                 -----------
	(a)	socket()   					Socket()   (1)
		        				    bind()     (2)
		        				    
		        	(3-way Handshake)			
		        	  SYN			
	(b)	connecct()  ------------->  listen()   (3)
                      SYN + ACK
					<-------------  accept()
					   ACK 
					------------->
	
				   (Data Transfer)
		write()     ------------>   read()
		read()      <------------   write()

                 ( 4-way Handshake)
		close()		<------------>	close()
```

- **After `accept()`, data can be exchanged using `read()` and `write()`**
- **Connection termination** is handled via a **4-way handshake**

- `socket()`, `write()`, `close()` → used by **both client and server**
- `connect()` → used **only by client**
- `bind()`, `listen()`, `accept()` → used **only by server**


##### **TCP Buffer**

> Added by me, not from lecture

**Buffer** is a memory space used to temporarily store data during transmission.

**TCP Buffer**
- **Sender Buffer**:
    - Stores **data to be sent** and **data sent but not yet acknowledged**.
    - Works with `CWND` to manage _how much can be sent_ at a time.
        
- **Receiver Buffer**:
    - Stores **received data** until the application reads it.
    - Advertises available space using `RWND`.

**Purpose:**
- Smooth data transfer despite speed mismatch between sender, network, and receiver.
- Prevent overflow/loss.

- **Buffer** = Physical memory space
- **CWND / RWND** = Limits/variables to control how much of the buffer can be used in transit


#### **TCP Flow and Congestion Control**

To avoid **buffer overflow**, **both sender's and receiver's buffers must be managed carefully**.

**Key Terms**
- **`LastByteSent`**: Sequence number of the **last byte sent** by the sender.
    
- **`LastByteAcked`**: Sequence number of the **last byte acknowledged** by the receiver.
    
- **`CWND`**: **Congestion Window** (sender's side, for congestion control).

- **`RWND`**: **Receiver Window** (receiver's advertised available buffer size, for flow control).
    
**Important Concept**

- The **amount of unacknowledged data in flight** is:
    ```
    LastByteSent - LastByteAcked
    ```
    
- This **in-flight data** must always satisfy:
    ```
    [LastByteSent - LastByteAcked] ≤ min(CWND, RWND)
    ```
    

**When Sending New Segment of Y Bytes**

Suppose sender wants to send a segment containing `Y` bytes:
- Condition to check:
    ```
    [(LastByteSent - LastByteAcked) + Y] ≤ min(CWND, RWND)
    ```
- If this condition **fails**, the segment **cannot be sent** — it would exceed allowed limits.
    
**Solution if Not Allowed**
- **Wait for more ACKs** → frees up space by moving `LastByteAcked` forward, reducing in-flight data.
- **Window may increase** automatically:
    - **CWND** grows if no congestion (congestion control).
    - **RWND** grows as receiver reads data (flow control).
    
**Control Summary**
- Use **CWND** for: **Congestion Control** (network condition).
- Use **RWND** for: **Flow Control** (receiver's capacity).
- Use `min(CWND, RWND)` to obey **both**.

**Note:**

**CWND** and **RWND** are   **variables (limits)** that control how much data can be sent:

- **CWND (Congestion Window)**:
    - A _sender-side_ dynamic variable.
    - Controls how many **bytes** the sender can transmit _without congestion_.
    - Adjusted based on network conditions (loss/delay).
        
- **RWND (Receive Window)**:
    - A _receiver-side_ advertised variable.
    - Tells how many **bytes** the receiver's buffer can currently accept.
    - Sent in ACK packets.


##### **Congestion Control Algorithm** ⭐V.V.I

**`SSThresh` (Slow Start Threshold)**:  
A threshold value used to switch between **Slow Start** and **Congestion Avoidance** phases.

**Two Phases of TCP Congestion Control (Condition Based)**

- TCP uses **two distinct phases** to manage congestion, based on the current value of the **Congestion Window (CWND)** in comparison to the **Slow Start Threshold (`SSThresh`)**:

1. **`[CWND < SSThresh]`** → **Slow Start Phase**
    
2. **`[CWND ≥ SSThresh]`** → **Congestion Avoidance Phase**
    
**1. Slow Start Phase**

- This is the starting phase when a TCP connection begins or restarts after a timeout.    
- In this phase, TCP tries to probe the network capacity **aggressively but safely**.
- The Congestion Window (CWND) **grows exponentially**.
- For **every successful acknowledgment (ACK)** received, TCP **increases CWND by 1 MSS**.
- So, for every RTT (Round Trip Time), CWND **approximately doubles** in size.
- This exponential growth continues **until CWND reaches SSThresh**.
- **Implementation Formula**:  
    `CWND = CWND + 1` (per ACK)
    
This phase helps in rapidly utilizing the available bandwidth but still avoids flooding the network initially.

**2. Congestion Avoidance Phase**

- Once CWND grows large enough and **crosses or equals SSThresh**, TCP enters this more cautious phase.    
- Now, CWND **grows linearly**, not exponentially.
- This is done to **avoid pushing the network into congestion**.
- Here, for every full window of data acknowledged (i.e., for every RTT), TCP increases CWND by **only 1 MSS**.
- For each ACK, the growth is more gradual, following:  
    `CWND = CWND + (1 / CWND)`
- Hence, CWND increases by **1 MSS per RTT**, assuming all ACKs are received properly.
    
This phase is designed for **stable network conditions**, preventing congestion and keeping transmission reliable.


**Note:**
- **MSS (Maximum Segment Size)**:  
    It defines the **maximum data (payload) size** a TCP segment can carry, **excluding TCP and IP headers**.
- **MSS Formula**:  
    `MSS = MTU - IP Header Size - TCP Header Size`
- **MTU (Maximum Transmission Unit)** is the maximum size of a packet that the network can handle without fragmentation.
- **TCP is an intelligent protocol**. It always takes care of its underlying protocol (IP). It automatically **respects the MTU limit**, so it calculates how much data to put in the segment, avoiding IP-layer fragmentation altogether.
- **UDP, in contrast, is careless**. It sends data without checking the MTU. So if data is too big, IP has to **fragment** the packet, which can lead to inefficiencies and losses.
    
TCP’s **adaptive nature and respect for network limits** make it a highly reliable and stable transport protocol in the internet stack.


**Algorithm:**


**1. When TCP connection is established**

**Initialize:**
- `SSThresh` = ∞ (in practice, initialized to a **large number**)
- `CWND` = 1 MSS 
- This puts TCP in **Slow Start** phase.

**2. When a timeout occurs**

**Update:**
- `SSThresh` = `CWND / 2`  
    (rounded down to the nearest MSS)
- `CWND` = 1 MSS  
    (restarts from Slow Start phase)
- Timeout is treated as severe congestion, so CWND is reset, and growth restarts cautiously.


Example:

**Initialise Phase**
```
SSThresh = ∞
CWND = 1 MSS   
             ⬊ 
       2 MSS ⬋
            ⬊   
       4 MSS ⬋
             ⬊ 
       8 MSS ⬋
            ⬊ 
      16 MSS ⬋ (let ack. of 16 not recevied -> timeout X )
      
 -------Timeout------
```

**Timeout Phase**
```
-> SSThresh = CWND/2  (its is because when previous size segment i.e. CWND/2 sentno timeout)

SSThresh = 16/2 = 8
CWND = 1 MSS ...............................
             ⬊ 
       2 MSS ⬋         (CWND < 8)
            ⬊      Slow Start Phase  
       4 MSS ⬋
             ⬊ 
       8 MSS ⬋............................
            ⬊  
       9 MSS ⬋ 
             ⬊ 
      10 MSS ⬋         (CWND >= 8)
            ⬊      Congestion Avoidance Phase 
             .
             .
             .

  ------ Again Timeout at some point -------

Process Repeated
with: 
	SSThres = CWND/2 
	CWND = 1 MSS
```

**Note:**
- **Theoretically:** TCP's congestion window (`CWND`) is often explained in terms of **MSS (Maximum Segment Size)**, e.g., `CWND = 1 MSS`, `2 MSS`, etc., for easier understanding. ⭐
- **Practically:** In real implementations, `CWND` is measured and maintained in **bytes**, not in MSS units.

> In **GATE exams**, **important numericals** from **TCP congestion control** are often asked.
> The paper is **set smartly** — timeouts and growths are usually given in **powers of 2** (like 1, 2, 4, 8, …), to **match exponential growth** in **Slow Start Phase**.
> So, **answers become deterministic**, and can be solved quickly if you understand the behavior of **CWND growth per RTT**.


##### **TCP Timers**

**TCP uses Five Timers:**

1. **Retransmission Timer**
    - Used to **retransmit lost segments** if ACK not received within timeout.
    - Timeout is based on **Estimated RTT**.
        
2. **Persistence Timer**
    - Prevents **deadlock** when window size is 0 (Receiver’s buffer full).
    - Ensures sender **periodically probes** receiver to check if window opened.
        
3. **Keepalive Timer** _(Optional)_
    - Used to **detect dead peers** when connection is idle for too long.
    - Sends probe packets after long inactivity.
        
4. **Time-Wait Timer**
    - Ensures last ACK of 4-way termination is **received properly**.
    - Also allows **delayed segments** to expire in network before reuse of same port pair.
    - Duration = **2 × MSL (Maximum Segment Lifetime)**
        
5. **Delayed ACK Timer**
    - Receiver waits for a short time before sending ACK.
    - Optimizes by allowing **ACK + data to be sent together**.
    - Usually ~200ms.

> Not much important (But 1 marks True/False can be in GATE)

---
# Network Layer


##### **IP Address**

IP Address is a **logical address** used for identifying devices on a network.  
(It is different from **MAC address**, which is a **physical/hardware-level address** assigned to the network interface card.)

An IP address is composed of **two parts**:

1. **Network Identifier (Net ID)**
    - Denoted by `x` bits.
    - Identifies the **network** to which the device belongs.
    - All devices in the same network will share the same Net ID.
    - Works as the **prefix** of the IP address.
        
2. **Host Identifier (Host ID)**
    
    - Denoted by `y` bits.
    - Identifies the **individual machine** (host) within the network.
    - Host ID must be **unique within a network**.
    - Works as the **suffix** of the IP address.

```
[ Network Id | Host Id ]
     x-bits     y-bits
Total = x + y = IP address size
```

**Two Types of IP Versions** :

**IPv4 Address**

- IPv4 address is **32 bits** in size.
- Network bits = x, Host bits = y = 32-x
- One of the problems: **How many bits are allocated to Net ID?**
- Based on this, IPv4 addressing is divided into two schemes:

**IPv6 Address**

- IPv6 has **128-bit** address size.    
- There is **no concept of classful addressing** in IPv6.
- IPv6 provides a **very large address space**, solving the exhaustion problem of IPv4.
- IPv6 is **currently removed from GATE syllabus** for this year.


##### **Classful IPv4 Addressing**

- **Static assignment**: NetID bits are **fixed implicitly** by class.
- There are **5 classes** (A to E), out of which A, B, and C are commonly used.

| Class | IP           | Address Range               | NetID Bits | First Octet Range | Host Count                    | Efficiency |
| ----- | ------------ | --------------------------- | ---------- | ----------------- | ----------------------------- | ---------- |
| A     | (0...).x.x.x | 0.0.0.0 – 127.255.255.255   | 8 bits     | 0 – 127           | ~16 million                   | 50%        |
| B     | (10...).x.x  | 128.0.0.0 – 191.255.255.255 | 16 bits    | 128 – 191         | ~65,000                       | 25%        |
| C     | (110...).x   | 192.0.0.0 – 223.255.255.255 | 24 bits    | 192 – 223         | 254                           | 12.5%      |
| D     | (1110...)    | 224.0.0.0 – 239.255.255.255 | N/A        | 224 – 239         | Reserved for multicast        | 6.25%      |
| E     | (1111...)    | 240.0.0.0 – 255.255.255.255 | N/A        | 240 – 255         | Reserved for experimental use | 6.25%      |

**A, B, and C** are the only classes used for assigning IPs to hosts and used by us.
- **Class A:** For very large organizations (millions of hosts) ✅
- **Class B:** For medium-sized organizations (thousands of hosts) ✅
- **Class C:** For small organizations or private networks (hundreds of hosts) ✅
- **Class D:** Reserved for **Multicast** (not for host communication) ❌
- **Class E:** Reserved for **Experimental/Research** purposes (not used publicly) ❌

**Note:** Classful addressing leads to **IP address wastage**, especially in Class A and B.


**Two types of Address** :

**1. Network Address**
- Special IP address
- It can not be an IP address of any host in the network
- Used to represent a Network
	- NetID field = As Assigned
	- HostID field = All Zero Bits
```
[ Network Id |  Host Id (00000...00) ]
    x-bit             y-bit
```

**1. Broadcast Address**
- Special IP address
- Network Directed Broadcast Address
- It can not be an IP address of any host in the network
- Used to broadcast a packet to all hosts belongs to a network
	- NetID field = As Assigned
	- HostID field = All One Bits
```
[ Network Id |  Host Id (11111...11) ]
    x-bit             y-bit
```



**Network Size** ⭐

- **Network Size**: Maximum number of hosts in a network    
- **HostID field** → `y` bits
- **Network Size = `2^y - 2` hosts per network**
    - `-2` because two IPs are **reserved**:
        - One for **Network Address** (all 0s in HostID)
        - One for **Broadcast Address** (all 1s in HostID)
            
**Network Mask**

- **Network Mask (Netmask)** → 32-bit binary
- NetID field = All **1s**
- HostID field = All **0s**
```
Netmask: [ 11111.....11 | 00000...00 ]
```

- A binary tool used to derive **Network Address** from any IP
- **Operation**: `IP Address & Netmask = Network Address`
- `&` is bitwise AND:
    - `1 & x = x` (keeps actual bits of NetID)
    - `0 & x = 0` (makes HostID part all zero)
- **All hosts in the same network must have same Network Address**
    

**Note:** 
- Netmask is **not** an IP address.  
- It's a binary tool that helps computers **identify the network** to which an IP belongs.

> ✅ **Network Size** and **Network Mask** are **important numericals** in GATE.


##### **Subnetting**

- Dividing (logically) a network into ==smaller manageable sub-networks==
- Sub-network (subnet) : Clustering of hosts inside a network
- Clustering of hosts based on ==some bits of host identifier== (HostId) field 
- In practice, subnetting is based on ==most significant bits== of host identifier.)

After subnetting, IP address having three sections:
1. **Network Identifier** (Net ID) : `x` bits
2. **Sub-network Identifier**  (Subnet ID) : `y1` bits
3. **Host Identifier**  (Host ID) : `y2` bits
- Size of IP address field = ( `x` + `y1` + `y2`) bits
- Where (`y` = `y1` + `y2`)


**Sub-network Address**
- Special IP address (32 bits)
- Used to represent a **sub-network**
1. **NetID field** = As Assigned
2. **Subnet ID** = Anything ⭐
3. **HostID field** = All Zeros

```
Subnet: [ Net Id | Subnet ID | 0000...0000]
           x bits     y1 bits   y2 bits     
```

**Sub-network Broadcast Address**
- Special IP address (32 bits)
- Used to broadcast a packet to **all hosts in a sub-network**
1. **NetID field** = As Assigned
2. **Subnet ID** = Anything ⭐
3. **HostID field** = All Ones

```
Subnet: [ Net Id | Subnet ID | 1111...1111]
           x bits     y1 bits   y2 bits     
```


> **Note**:
- In **latest convention**, **all-zero** and **all-one** **Subnet IDs** are **allowed**, unlike older standards.
- In the **old convention**, they were **not allowed**, leading to **IP address wastage**.
- If **both SubnetID and HostID** are all 0s or all 1s, it's not a network address or broadcast address—but a **subnet** address.
- Whether it's a **Network** or **Sub-network** can be identified using the **subnet mask**—so **clashes are easily manageable**.

**Sub-network Size**
- Sub-network size: Maximum possible number of hosts in a sub-network
- **HostID field** = `y2` bits
- **Sub-network Size** = `2^y2 - 2` hosts per subnet ⭐  
    `-2` because two addresses are reserved:
- One for **sub-network address**
- One for **sub-network broadcast address**

**Number of Subnets**
- **Subnet ID field** = `y1` bits
- **Number of Subnets** = `2^y1` per network

> **Note**:
- In old convention: `Number of Subnets = 2^y1 - 2` (reserved all-0 and all-1 subnet IDs)    
- In modern convention: all subnet IDs are **allowed**- Subnet ID field (`y` bits)
- **Number of subnets** = `2^y1` per network


**Sub-network Mask**
- **Subnet Mask** (32-bits): Used to extract **subnet address** from an IP address
	- NetID bits = All 1s
	- SubnetID bits = All 1s
	- HostID bits = All 0s
```
Subnet Mask: [ 11...11 | 11...11 | 00...00 ]
               x bits    y1 bits    y2 bits  
```
- **For a given IP Address**
	- **Subnet Mask** `&` IP Address extracts **Subnet ID**
	- **Network Mask** `&` IP Address extracts **Network ID**

    
---

##### **Classless IPv4 Addressing (CIDR - Classless Inter-Domain Routing)**  ⭐

```
P.Q.R.S/x
```
- `P.Q.R.S` → IP Address    
- `/x` → Number of bits used for **Network ID**

- **Dynamic assignment**:  
    NetID size is **explicitly defined** using a **subnet mask** or **CIDR notation**.
    
- **Example**:  
    `192.168.10.0/22`  
    → First **22 bits** = Network ID  
    → Remaining **10 bits** = Host ID  
    → Allows **1022** usable hosts (`2^10 - 2`)
- **Advantages**:
    - More **efficient**, **flexible**, and **scalable** than classful addressing
    - Solves problem of **IP wastage**
    - Allows **subnetting** and **route summarization**

**Technical Overview**

- **Full Form**: Classless Inter-Domain Routing
- **Nature**:  
    CIDR is an **IP address allocation method** for routing.  
    It builds upon the concept of **VLSM (Variable Length Subnet Masking)**.
- **Key Feature**:
    - Allows for **flexible creation of "supernets"**
    - Enables **hierarchical routing**
- **Impact**:
    - CIDR revolutionized routing by allocating IP addresses in **hierarchical blocks**
    - Enables **aggregation** of routing information using **common prefixes**
    - Dramatically reduces the size of **backbone routing tables**
    - IP prefix can help identify **country**, **city**, or **ISP**


> GATE questions on CIDR (sometimes combined with VLSM) are present.

#### **Variable Length Subnet Mask (VLSM)**

**VLSM**: Variable Length Subnet Mask

- Uses **variable-length network prefixes** (unlike fixed-length subnetting)    
- Allows **different subnet sizes** → efficient utilization of IP address space
- Subnetting is done **recursively** using available HostID bits
- **NetID remains fixed**, only HostID is divided into subnet ID and host ID
    
**Visual Subnetting Breakdown**

Let's assume you are given a classful **Class C network**: `192.168.0.0/24`  
This gives **256 total IPs** (254 usable)

Step 1: Divide into **two /25 subnets** (1-bit subnetting)
- Subnet 1: `192.168.0.0/25` → Hosts: 192.168.0.1 to 192.168.0.126
- Subnet 2: `192.168.0.128/25` → Hosts: 192.168.0.129 to 192.168.0.254
```
192.168.0.0/24
     ↓ (1-bit subnetting)
┌────────────────────┬────────────────────┐
│ 192.168.0.0/25     │ 192.168.0.128/25   │
└────────────────────┴────────────────────┘
```

Step 2: Further divide **192.168.0.128/25** into two **/26 subnets** (2-bit subnetting)
- Subnet A: `192.168.0.128/26` → 62 hosts
- Subnet B: `192.168.0.192/26` → 62 hosts
```
192.168.0.128/25
     ↓ (2-bit subnetting)
┌──────────────────┬──────────────────┐
│ 192.168.0.128/26 │ 192.168.0.192/26 │
└──────────────────┴──────────────────┘
```

Step 3: Further divide `192.168.0.192/26` into two **/27 subnets** (3-bit subnetting)
- Subnet A: `192.168.0.192/27` → 30 hosts
- Subnet B: `192.168.0.224/27` → 30 hosts
    
```
192.168.0.192/26
     ↓ (3-bit subnetting)
┌──────────────────┬──────────────────┐
│ 192.168.0.192/27 │ 192.168.0.224/27 │
└──────────────────┴──────────────────┘
```

**Summary**
```
┌───────────────────┐
│                   │
│   Network '/24'   │
│                   │
└───────────────────┘

┌─────────┬─────────┐
│         │         │
│ subnet1 │ subnet2 │
│ '/25'   │  '/25'  │
└─────────┴─────────┘

┌─────────┬─────────┐
│         │ '/26'    → subnet 2.1
│ subnet1 ├─────────┤
│  '/25'  │  '/26'   → subnet 2.2
└─────────┴─────────┘

         subnet 2.1.1 & 2.1.2
┌─────────┬─ ↑ ┬ ↑ ─┐
│         │    │    │
│ subnet1 ├────┴────┤
│         │  '/26'   → subnet 2.2
└─────────┴─────────┘
```


 **Key Points**
- **We never touch NetID (192.168.0)**
- All subnetting is done by dividing **HostID bits**
- Each time we divide, we are **adding bits to the subnet mask**
- Smaller subnets → Longer prefix (e.g., /27), fewer hosts
- Larger subnets → Shorter prefix (e.g., /25), more hosts

**Why VLSM?**
- Real-world networks have different size needs (e.g., 100 hosts vs 10 hosts)
- VLSM prevents **IP wastage**
- Used with **CIDR (Classless Inter-Domain Routing)** in most modern routing

##### **Classful vs Classless Addressing**

> Added by me

| Feature                  | Classful Addressing                                              | Classless Addressing (CIDR)                                            |
| ------------------------ | ---------------------------------------------------------------- | ---------------------------------------------------------------------- |
| **Introduced**           | Early days of IP (1980s)                                         | 1993 (to reduce wastage)                                               |
| **Address Division**     | **Fixed Classes**: A, B, C (based on first few bits)             | **No Fixed Classes**: Use prefix length like `/x` (e.g., `/20`, `/26`) |
| **Subnet Mask**          | Fixed by class (e.g., Class A → /8, B → /16, C → /24)            | Variable length subnet mask (`/x`)                                     |
| **IP Allocation**        | Rigid and wasteful                                               | Efficient and flexible                                                 |
| **Routing**              | No prefix, router assumes class-based mask                       | Uses prefix (`IP/prefix`) for routing decisions                        |
| **Supported Subnetting** | Allowed within class                                             | More flexible and precise subnetting                                   |
| **Efficiency**           | **Wastage**: Large chunks of IPs wasted (unused hosts)           | **Efficient** Allocates IPs as per need (small/large networks)         |
| **Example**              | `192.168.1.0` → Automatically assumed `/24` because it's Class C | `192.168.1.0/26` → 64 IPs instead of 256 (as per Class C)              |
|**Address Utilization**|High wastage (due to fixed blocks)|Optimized for varying network sizes|

**Classful to CIDR Mapping Table**

|**Class**|**Starting Bits**|**Address Range**|**Default CIDR Prefix**|**IP Count**|**Purpose**|
|---|---|---|---|---|---|
|A|`0xxx`|`0.0.0.0` – `127.255.255.255`|`/8`|~16 million per network|Large networks|
|B|`10xx`|`128.0.0.0` – `191.255.255.255`|`/16`|~65K per network|Medium networks|
|C|`110x`|`192.0.0.0` – `223.255.255.255`|`/24`|254 per network|Small networks|
|D|`1110`|`224.0.0.0` – `239.255.255.255`|**No CIDR prefix**|NA|**Multicast**|
|E|`1111`|`240.0.0.0` – `255.255.255.255`|**No CIDR prefix**|NA|**Reserved / Research**|

**Note:**
- **CIDR Prefixes (`/x`)** are only used for **Class A, B, and C** (for subnetting & routing).
- **Class D** (Multicast) and **Class E** (Experimental) **do not use CIDR prefixes** like `/8`, `/16`, etc.
- `IP/32` in CIDR refers to a **single host**, not Class D or E.


---

##### **Forwarding Table in Routing** ⭐

```
       [R2]
          \  
           2           
          ┌────┐
          │ R  │1 ─[R1]
          └────┘  
           3              
          /
       [R3]
```

**Routing (Forwarding Table)**
```
Network Address       Mask              Interface ID      Next Hop
-------------------------------------------------------------------
Network Address 1     Mask 1                 1               R1
Network Address 2     Mask 2                 2               R2
0.0.0.0 [default]     0.0.0.0                3               R3
```

- **Interface ID**: The port number through which the router is connected to the next hop.
    
- **Next Hop**: Practically, it's the **IP address** of the next router, but theoretically represented as `R1`, `R2`, etc.
    


**How Routing Works**
When a **packet arrives** at the router:
1. **Extract Destination IP**: Let it be `IP_D`.
2. **Compare using longest prefix (most 1s in mask)**:
    - First try **Mask 2** (assume it have longest `1s` prefix).
        - Compute: `IP_D & Mask2 → Result2`
        - If `Result2 == Network Address 2`, forward to **Interface 2 → R2**
    - Else, try **Mask 1** (assume it have 2nd longest `1s` prefix):
        - `IP_D & Mask1 → Result1`
        - If `Result1 == Network Address 1`, forward to **Interface 1 → R1**
3. If **no match found**, use:
    - `IP_D & 0.0.0.0 → 0.0.0.0` → **Default Route** → Interface 3 → **R3**
        
> Note: **Default entry (0.0.0.0)** is **optional**. It’s used to catch all unmatched packets.


**Why Longest Prefix Match (LPM)?**
- **Most Accurate Route**: A longer prefix means more matching bits → more specific route.
- **Avoid Wrong Routing**: Ensures packets don’t take a broad/default path when a specific path exists.
- **Efficient Routing**: Reduces unnecessary hops and improves performance.

> **Example**:  
> If both `192.168.0.0/16` and `192.168.1.0/24` match the destination IP,  
> `/24` is selected because it's more specific (24 > 16).

**Longest Prefix Matching**
- Router chooses more specific option over generic one
- Router chooses the matched entry in which more number of ones in netmask.

##### **Supernetting**

> Only one time ask in GATE, not much important


It is **Prefix (Route) Aggregation**

- **Definition**:  
    A technique to combine multiple **contiguous smaller networks** (subnets) into a **single summarized route**.
    
**Purpose**
- To **reduce** the size of the **routing table**.
- To make **routing more efficient** by advertising fewer entries.
- Used widely in **CIDR** and **Classless routing**.
    
**How It Works**

- Instead of advertising each subnet individually, routers advertise a **single aggregated (supernet) route**.
- This is possible only if:
    - All subnets have **contiguous IP addresses**.
    - All have the **same prefix length** or can be expressed using a **common shorter prefix**.
        

**Example**

```
Networks:

192.168.0.0/24  
192.168.1.0/24  
192.168.2.0/24  
192.168.3.0/24
```

These can be **aggregated** into:
```
192.168.0.0/22
```

- Because The first 22 bits of all these addresses are the same.


Here is the **formatted and clean version** of your ARP notes with the same level of explanation:

---

##### **Address Resolution Protocol (ARP)**

- **ARP**: Address Resolution Protocol
- Data Link Layer (L2) Protocol
- Used to find **MAC address of device from IP address
- Map **logical address** into corresponding **physical address**

```
IP Address   ----[ ARP ]---->  MAC Address 
(Logical)                      (Physical)
```

- ARP Packet always encapsulated into payload field of "Frame"
- IP packets need to be encapsulated in **frames**, and frames need **MAC addresses**    

```
ARP Query (Request) always broadcast
-------------------------------------
- Destination MAC address = `FF:FF:FF:FF:FF:FF` (All 48 bits are one) Broadcast MAC address
```

```
ARP Reply always unicast
-------------------------------
- Destination MAC address = MAC address of Host who raised ARP query
```


**Example:**
- Host A wants MAC of IP `192.168.1.5`:
    - Sends ARP Request to all (broadcast)
    - Host B (which has IP `192.168.1.5`) replies with its MAC in ARP Reply (unicast)

**Important Properties**

| Property          | Value                                                              |
| ----------------- | ------------------------------------------------------------------ |
| **Layer**         | Data Link Layer (L2), but bridges to Network Layer (L3)            |
| **Scope**         | Only works **within the same network/subnet** ⭐ i.e. Local Network |
| **Request**       | **Broadcast** → MAC: `FF:FF:FF:FF:FF:FF` (All 48 bits = 1)         |
| **Reply**         | **Unicast** → Sent only to the querying host                       |
| **Encapsulation** | ARP message is inside **Payload** of a **Data Link Layer frame**   |


> **Key Points (GATE Relevance)**
- ARP Request = Broadcast 
- ARP Reply = Unicast
- Works only in local network
- Always encapsulated in **Frame's payload**


##### **Network Address Translation (NAT)**

- NAT : Network Address Translation
- Every network connected to the internet is assigned a **unique public IPv4 address** (by ISP).
- Internally, each network is treated as a **private network**.
- **Hosts inside** the private network are assigned **private IP addresses**.
- This setup forms a **public-private combination**:
    - **Outer world (Internet)** → Public IP
    - **Inner network (LAN)** → Private IPs
        
- **Old Concept**: IPv4 has 2³² addresses → only 2³² total hosts possible
- **With NAT**:
    - `2³²` unique public IPs → `2³²` **networks**
    - Each network has its own **private space of 2³² addresses** (in theory)
        
- So, NAT **overcomes IPv4 address exhaustion**
- Allows **multiple devices in a private LAN** to access the internet using **one public IP**


- NAT Device update address field of every outgoing and incoming datagram
```
For every outgoing datagram
-------------------------------
- it modify `Source IP address` from `private IP address` to `Public IP address` of NAT device
```

```
For every incoming datagram
-------------------------------
- it modify `Destination IP address` from `public IP address` to Correct `Private IP address` (via mapping)
```

As per requirement, NAT device can modify ⭐ 
> Considered as very Deep. (Very last chance to come in Exam) 
1. `Source Port Number` field for outgoing packet
2. `Destination Port Number` field for incoming packet

- NAT maintains a **Translation Table**:
    ```
    (Private IP, Port) ⟷ (Public IP, Port)
    ```
    

**Key Points**
- Devices in LAN use **private IPs** (e.g., `192.168.x.x`, `10.x.x.x`)
- These private IPs are **not routable** on the public internet
- A **NAT-enabled device** (typically a router):
    - Has **one or more public IPs**
    - Connects the private network to the internet
- Implemented in **routers/firewalls**
- Used only in **IPv4** networks
- **Private IP ranges** (RFC 1918):
    - `10.0.0.0/8`
    - `172.16.0.0/12`
    - `192.168.0.0/16`
        
- NAT is **not needed in IPv6**, due to its **vast address space**
- IPv6 provides a **globally unique address to every device**
    

#### **IPv4 Header**

- Header represented in **Words** (Words 4 bytes / 32 bits)
- Minimum (Base) Header Size is  5 Words (20 Bytes)
- Our IPv4 Header is of Variable Size IPV5 Header, due to options (Optional)

**Header Length**
- Header Length (HLEN)
- HLEN field is 4 bits long
- Size of header in **words** ( Word of 4 bytes )
- `Header Length = HLEN Words = (HLEN x 4) Bytes`
- Minimum Header Size = 5 Words (20 Bytes ) -> Base Header
- Maximum Header Size = 15 Words ( 60 bytes)
- 5 <= HLEN <= 15

**Total Length**
- Total Length field is 16 bits long
- Define size of IPv4 packet (datagram) in **bytes**  (including header)
- `Total Length = Header Length + Payload`

**Payload**
```
Size of Payload = Total Length - (HLEN * 4) bytes ⭐
```

> Header Length -> Words (4 Bytes)
> Total Length -> Bytes
##### **Maximum Transmission Unit (MTU)**

- MTU : Maximum Transmission Unit
- Measurement in bytes
- MTU = Size of largest PDU (datagram) that can be communicated over a network

- Source hosts creates IPv4 datagram as per source network MTU
- At intermediate IPv4 router, for an received IPv4 datagram ⭐
	- If datagram length is greater then next network (link) MTU size -> then need to do fragmentation according to MTU

> MTU -> Bytes
> MTU is important for Numerical Questions, used to Evaluate Datagram Size
##### **Fragmentation Offset**

**Fragmentation** is the process of **breaking a large IP datagram into smaller pieces (fragments)**. This occurs when a datagram's size exceeds the MTU of the next network link it needs to traverse.

- **Where it occurs**:
    1. **At the Source Host**: The host originating the datagram creates it according to its own network's MTU.
    2. **At an Intermediate IPv4 Router**: If a router receives a datagram that is larger than the MTU of the _next_ network it needs to forward the datagram onto, it performs fragmentation.

- Fragmentation offset is 13 bit long
- It is Used to identify the sequence of fragments
- It contains payload's starting word number (Words of 8 bytes)
- Word number according to "Service Data Unit" (SDU)
- Offset value for the first fragment in the sequences always "Zero"


**MF Flag**
- MF : More fragment
- Used to identify last fragment in the sequence of fragments
- For last fragment, MF bit should be "Zero"
	- **MF = 0** → This is the **last fragment**
- For intermediate fragments, MF bit should be "One"
	- **MF = 1** → More fragments follow this one


**Also, DF Flag**
- DF: Do not Fragment
- Source host can restrict further fragmentation (division) of datagram at any intermediate router
- In such cases, sources host set DF bit `[DF=1]`
- Default value of DF flag  is "Zero"
- Set/reset by source host only.
- e.g. Used in  "Remote Booting"

The IPv4 fragment in which offset value is "Zero", is the first fragment in the sequence

**Payload Size Rules**
- For **all intermediate fragments** (`MF = 1`):  
    → **Payload size must be a multiple of 8 bytes** (i.e., in 8-byte **words**)
- For the **last fragment** (`MF = 0`):  
    → **No restriction** on payload size

**Note:**

- **SDU (Service Data Unit)** → Corresponds to **UDP Packet**
- **Fragmentation is performed on SDU**, typically in **UDP**, because:
    - UDP does **not** handle segmentation itself
    - Large UDP packets may exceed the MTU → require **IP-level fragmentation**
        
- **TCP Segments** usually **do not require fragmentation** because:
    - TCP performs **segmentation** at the transport layer
    - Ensures each segment fits within MTU → avoids fragmentation at IP layer


> Header Length - Word  ( of 4 byte)
>  Offset - Word (of 8 byte)

##### **Fragmentation at Source Host**

 ```
 IPv4 Datagram Size <= Source Network MTU ⭐
```


**Numericals to Find: Total Length of Last Fragment**  ⭐Important

**1. Payload Size (D)** : Payload refers to how much data can be carried in each fragment (excluding the header).  
```cpp
D = MTU - HLEN * 4   // in bytes
```
- `MTU` = Maximum Transmission Unit (given)
- `HLEN` = IPv4 header length in 32-bit words (multiply by 4 to convert to bytes)
    
**2. Number of Fragments (N)** : Total number of fragments formed from the original SDU (UDP packet).  
```cpp
N = ceil(SDU_Size / D)
```
- `SDU_Size` = Size of the UDP packet (including UDP header)   
- `D` = Payload size from step 1
- `ceil()` = Take ceiling value (since partial fragments also count as 1 full fragment)

**3. Offset of Last Fragment (O)** : Offset indicates the position of data (in 8-byte units) from the start of the original SDU.  
```cpp
O = (N - 1) * D / 8     // Since last fragment is at (N-1)th position

// also
O = (D - L) / 8         // General form, where L is last fragment payload
```
- Fragment offset is always in multiples of 8 bytes
- Offset value used in IPv4 Fragmentation Header
    
**4. Total Length of Last Fragment** : This is the actual size of the last fragment (i.e., header + payload).  
**Formula:**
```cpp

Total_Length_Last = HLEN * 4 + SDU_Size - (N - 1) * D
// or
Total_Length_Last = HLEN * 4 + (SDU_Size - O * 8)
```
- `O * 8` gives the amount of data already covered before the last fragment    
- Remaining part is carried by the last fragment
    

##### **Fragmentation at Router**

```
IPv4 Datagram Size ≤ Intermediate Network MTU ✅
```


**Numericals to Find: Total Length of Last Fragment**

**1. Old Payload Size (D)** : Payload of the original datagram received by the router
```cpp
Old_D = TL - HLEN * 4    // in bytes
```
- `TL` = Total Length of original datagram
- `HLEN` = Header length (in 32-bit words, multiply by 4 to convert to bytes)

**2. New Payload Size (after fragmentation)** : Payload capacity of the new fragments to be created (MTU limited)
```cpp
New_D = MTU - HLEN * 4   // in bytes
```

**3. Number of Fragments (N)** : Total fragments that the original datagram will be divided into
```cpp
N = ceil(Old_D / New_D)
```

**4. Offset of Last Fragment (O)** : Offset of the last fragment in the series
```cpp
O = Original_Offset + (N - 1) * New_D / 8

// OR (general formula)
O = (D - L) / 8   // where L is the last fragment's payload
```
- Offset is in **units of 8 bytes**
- Used in **Fragment Offset** field of IPv4 header

**5. Total Length of Last Fragment** : Size of last fragment (Header + remaining payload)

```cpp
Total_Length_Last = HLEN * 4 + Old_D - (N - 1) * New_D
// OR
Total_Length_Last = HLEN * 4 + (SDU_Size - O * 8)
```


##### **Reassembly of Fragments**

- Reassembly of fragments, only at ==destination host== ⭐
- Destination wait for some time
- if any of the fragment is missing (or lost) in the sequence, this may lead reassembly failure

##### **Time-to-Live**

- Time-to-live (TTL) is 8-bit field
- Life time of an IP datagram
- Avoid indefinite traversing of an IP datagram in the network (due to routing loops)

**Working:**
- Each intermediate router decrease TTL value by one. `TTL--`
- If TTL value decremented to zero `TTL <= 0 `
	- then router discard the datagram and send **ICMP error message** "Time Exceeded" to source host

##### **Circuit Switching**

- Establish (physical) dedicated circuit between sender and receiver, before transmission (Over the links of the network)
- Phases of Circuit Switching:
	1. Circuit establishment
	2. Data transfer
	3. Circuit disconnect
- All data (or packets) follow each other on reserved path (Data having same end-to-end delays)
- **Advantage** 
	- But No any congestion occur, during data transfer
- **Disadvantage**
	- Congestion may occur during circuit establishment
	- Inefficient utilization of network resources
	- Expensive
- Example : Telephone Network
- PSTN : Public Switched Telephone Network
##### **Packet Switching**

- message is divided into smaller size packets (packets may be same or different size)
- Store and Forward (Datagram Network), No any established circuit required between sender and receiver
- Every packet is treated independently at every intermediate router (because destination ID is written on each)
- Congestion may occur during routing
- Packets may follow different routing paths
- Packets may have different end-to-end delay
- **Advantage**
	- Efficient utilization of network resources (sharing mode), Lead to better utilization of bandwidth resource
	- Cheap mode (sharing mode)
- **Disadvantage**
	- More per packet processing overhead at intermediate router
- Example : Internet


##### **Type of Services**

- **Circuit Switching** - Provide connection oriented and Reliable services
- **Packet Switching** - Provide Connection Less and Unreliable services

**Note:** Sometimes packet switching may require reordering of packets at receiver

##### **Optimum Packet Size**

```
[ Hs] -----------( R )-----------( R )--------------[ Hr ]

here, k=3
```

- K = Number of Links
- M = Message Size
- H = Packet Header Size
- P = Packet Payload Size

**Packet Payload Size**
```
P = square root ( MH/(K-1) )
```

**Optimum Packet Size** ⭐
```
Optimum Packet Size = H + P
```


##### **Routing Protocols**

**Two categories:**

**1. Interior Gateway Protocol** (IGP)
- 1.1 Routing Information Protocol (RIP) -> Distance Vector Routing
- 1.2 Shortest Path First (OSPF)  -> Link State Routing


**2. Exterior Gateway Protocol** (EGP)
- 2.1 Border Gateway Protocol (BGP) -> Path Vector Algorithm 


**Communication with IP**
```
Routing            Transport Layer        Network Layer
Protocol            Protocol               Protocol

 RIP <--------------> UDP <---------------> IP

BGP <---------------> TCP <---------------> IP

OSPF <------------------------------------> IP  



Note: OSPF Directly communicate to IP, No Transport Layer
```

> BGP is not in Our syllabus
##### **Distance Vector Routing**

1. Each router maintain sperate "Distance vector" estimate
	-> Best known minimum distance to all other routers

2. Each router sends their own "Distance Vector" estimate to their neighbor routers only

3. When a router receives "Distance Vector" estimate from any neighbor,  It update its own "Distance Vector" using Bellman-Ford equation

**using Bellman-Ford**: When a router receives a distance vector from a neighbor, it updates its own distance vector using the **Bellman-Ford equation**. This involves comparing its current best path to a destination with the path through the neighbor, choosing the shortest one.


**DVR Problem and Solution :**

**Problem:** May suffer with "Count to infinity" problem ( Link to infinity problem, occur due to routing loop in DVR)

1. **Solution 1** : Advertise routing path in 'Distance Vector' (Send 'Next Hop' (via) with distance vector)

2. **Solution 2:** "Split horizon hack" (Do not advertise the distance to a neighbor, if the neighbor is the Next Hop for corresponding entry)

3. **Solution 3:** "Poison reverse" (Advertise infinite distance to a neighbor, if the neighbor is the Next Hop for corresponding entry) ⭐ (best solution)

##### **Link State Routing**

Centralized Routing Algorithm
Link State Routing is divided into three steps:
1. Maintain Link State Information
	-> Every Router maintain information about adjacent link only 
	-> i.e. Adjacent (neighbor router only)
2. Link State broadcast
	-> Every Router flood (broadcast) its "Link State" information
	-> i.e. To all other routers in the network
3. Shared updated Link State Information
	-> Makes it Adaptive

 **Dijkstra's Algorithm**: Once all link-state information is collected, _each router locally runs Dijkstra's shortest path algorithm_ to compute the shortest path to all other destinations in the network and construct its own forwarding table.


|Feature|**Link State Routing**|**Distance Vector Routing**|
|---|---|---|
|**Algorithm Type**|Newer|Older|
|**Information Maintained**|Info about **neighbors only**|Info about **entire network**|
|**Info Shared To**|Broadcast to **all routers**|Shared only with **neighbors**|
|**Update Method**|Sends **entire topology (LSA)**|Sends **distance vectors**|
|**Convergence Speed**|**Faster**|**Slower**|
|**Scalability**|Better for **large networks**|Suitable for **smaller networks**|
|**Examples**|OSPF, IS-IS|RIP, IGRP|


---

# Data Link Layer

##### **End-toEnd Delay**

```
             [frame] ->
Transmitter --------------------------- Receiver
(Sender)
```

**Transmission Delay**
- Transmission Time / Delay - `tx` (in seconds)
- Time required to transmit a packet over a link
- `Transmission Delay = (Packet Size) / (Data Transfer Rate)`

**Propagation Delay**
- Propagation Time / Delay - `tp`(in seconds)
- Time required to travel a signal from one end to other end of a link
- `Propagation Delay = (Distance) / (Signal Speed)`

**End-to-end Delay**
- One-way delay
- Time required for a packet to be transmitted from Transmitter to Receiver
```
End-to-end delay = (Transmission delay) + (Propagation delay)
```

```
End-to-end Delay = tx + tp
		
		       Transmitter         Receiver
		  ......|⬊                  |
		  	tx  |   ⬊               |
tx + tp	{ ......|      ⬊            |
			 	|⬊       ⬊          |
	 			|   ⬊       ⬊       |
				|      ⬊       ⬊    |
			tp  |         ⬊       ⬊ |.....
			    |            ⬊      |
			    |               ⬊   | tx
		  ......|..................⬊|......
   
```

##### **End-to-End Delay** (with Intermediate Device like Switch/Router)


```          
             <---tp1--->                <---tp2--->
Transmitter ------------- Switch/Router-------------- Receiver
(Sender)
```

- then store and forward Delay would be added
- Suppose each link have same bandwidth and same propagation delay
- Time required for a packet to be transmitted from Transmitter to Receiver
- **Queuing delay is negligible (~0)** unless specified

**Single Packet End-to-End Delay**
```
End-to-end delay:
	  = (Transmission delay) + (Propagation delay) 
	  + (Queuing delay at device) + (Processiing delay by device)
	  + (Transmission delay) + (Propagation delay)
```


**N Packets End-to-End Delay**
```
End-to-end delay:
	  = (N * Transmission delay) + (Propagation delay) 
	  + (Queuing delay at device) + (Processiing delay by device)
	  + (Transmission delay) + (Propagation delay)
```
Or more compactly:
```sh
End-to-End Delay = (N × tx + tp1) + Processing Delay + (tx + tp2)
```


##### **Cycle Time**

Cycle
```
             [frame] ->
Transmitter --------------------------- Receiver
(Sender)
```

```
Cycle Time:
	  = (Transmission delay) + (Propagation delay) 
	  + (Queuing delay at receiver) + (Processiing delay by receiver for frame)
	  + (Transmission delay for ACK) + (Propagation delay)
```
Or more compactly:
```
Cycle time = ( tx + tp ) + Processing Delay + ( txA + tp)
```

```
Cycle Time = tx + tp + Procssing + txA + tp
		
		       Transmitter         Receiver
		  ......|⬊                  |
		  	tx  |   ⬊               |
          ......|  F   ⬊            |
			 	|⬊   R   ⬊          |
	 			|   ⬊   A   ⬊       |
				|      ⬊   M   ⬊    |
			tp  |         ⬊   E   ⬊ |.....
			    |            ⬊      |
			    |               ⬊   | tx
		  ......|..................⬊|......
		        |                    | Processing
		        |....................|......
		  	    |                 ⬋ | txA
                |              ⬋   ⬋|........
			 	|          ⬋    ⬋   |
	 			|       ⬋  K ⬋      |
				|    ⬋  C ⬋         | tp
		        | ⬋  A ⬋            |
			    |   ⬋                |
			    |⬋                   |
		  ......|.....................|......
		   ⬆
		1 Cycle

txA : Transmission delay for ACK
txA << tx
```


##### **Q. Why end-to-end delay in pipelining is measured from the last packet's point of view (especially when intermediate device like switch/router exists)?**


Concept: **Pipelining**
- In pipelining, **multiple packets are sent back-to-back** without waiting for ACKs.
- Packets travel **in parallel**, each using a part of the link or device at different times.
    
Why consider delay **from the last packet's point of view**?
- We're calculating **total time to deliver all `N` packets** from sender to receiver.
- First packet may reach early, but we want the time **after the last packet is fully received**.
- This gives **complete transmission time** for the entire data.
    

What if Intermediate Device (Switch/Router) Exists?
- Intermediate devices like switches/routers cause:
- **Store-and-forward delay**
- **Processing delay**
    
Hence, we account for these **once** in the path — they **don’t repeat** for each packet due to pipelining.


- For `N` packets with pipelining:
- `End-to-End Delay ≈ (N × tx + tp1) + Processing Delay + (tx + tp2)`


So finally,
- In pipelining, we consider **last packet's arrival** because it marks **completion of the whole message**.  
- Intermediate device adds **fixed delay** once (store-and-forward), not per packet, hence included just once.

---
##### **Flow Control**

**Flow Control Protocols for Noisy Channel:** ⭐
1. **Stop-and-Wait ARQ**
2. **Sliding Window ARQ**
3. **Go-Back-N ARQ**
4. **Selective Repeat ARQ**

**ARQ (Automatic Repeat reQuest):**  
If acknowledgment (ACK) for a frame is **not received** within a timeout period, the sender **automatically retransmits** the frame.

##### **Stop-and-Wait ARQ**

**Transmitter Protocol:**
1. Transmitter **transmit** one frame (with sequence number) and **wait for ACK** of it until time-out
2. After **time-out**, transmitter **retransmit** the frame (**same sequence no.**) and **wait for ACK** of it until time-out
3. Transmitter transmit next frame only **after receiving ACK** of transmitted frame

**Receiver Protocol:**
1. Receiver transmit acknowledgment for every received frame after processing
2. Acknowledgments carry corresponding frame sequence number

**Important Points**
- Transmitter's **transmitting window Size**  = `1`
- Receiver's **receiving window** = `1`
- Total **number of sequences** = `2` (0 or 1)
	- (Transmitter's + Receiver's) window size
	- Hence, also known as "**Alternate bit Protocol**"

**Efficiency of Stop-and-wait ARQ**
```
Efficiency =  (Transmisson delay) / (Cycle Time)
```

If considering, Processing Delay, Queuing Delay and Transmission Delay for ACK

```
Efficiency = tx / (tx + 2tp)
```

**Cycle Time = RTT?**
- When transmission time (`tx`) is **very small** compared to propagation delay (`tp`)
- Common assumption in Stop-and-Wait efficiency calculations


**Limitation of Stop-and-Wait ARQ**
- Cannot achieve **100% efficiency**
- To reach 100% efficiency, **propagation delay (tp) must be 0**, which is **not possible in real networks**
- **Link underutilized** during wait time
- Not suitable for **long-delay** or **high-bandwidth** links
##### **Sliding Window ARQ**

- Transmitter's transmitting window size = `N` (N>1)
- Transmitter's transmit `N` frames continuously without any ACK
- Overlapping, unlike Stop-and-wait ARQ (To increase utilization)

```
Efficiency = (N × tx) / (Cycle Time)
           ≈ (N × tx) / RTT
```
- Assumes `tx << RTT`, so cycle time ≈ RTT
- **Higher N → better efficiency**

**Important Points**
- Transmitter's **transmitting window Size**  = `N` (N>1)
- Receiver's **receiving window** = `N`
- Total **number of sequences** = `N` (0 to N-1)
	- = (Transmitter's) window size

##### **Go Back N ARQ**

- Transmitter's **transmitting window Size**  = `N`
- Receiver's **receiving window** = `1`
- Total **number of sequences** = `N+1` (0 to N)
	- (Transmitter's + Receiver's) window size

**Key points:**
- **"Cumulative (combine) acknowledgment"** may exist. (Acknowledges more than one frame)
- Whenever transmitter gets **time-out** or **received NACK**, it retransmit all `N` frames (those resides in transmitting window)
- Receiver discard the frame which is **out of order**, and send ACK of the frame which is correctly received recently

##### **Selective Repeat ARQ**

- Transmitter's **transmitting window Size**  = `N`
- Receiver's **receiving window** = `N`
- Total **number of sequences** = `2N` (0 to 2N-1)
	- (Transmitter's + Receiver's) window size

**Key points:**
- **"Cumulative (combine) acknowledgment"** does not exist in this protocol
- Whenever transmitter gets **time-out** or **received NACK**, it retransmit that particular frame only (mostly first frame, resides in transmitting window)
- Receiver buffer the frame which is **out of the order** (excepted sequence numbers) and send individual **acknowledgment of the frame**

##### **Optimal Window Size**

**Optimal Window Size:**
- For maximum channel utilization
- For minimum transmitter's transmitting window size.

```sql
Optimal Window Size = ceil ( RTT / tx )
                    = ceil ( Cycle Time / Transmission Time )
```
- This is the **minimum value of N** required to fully utilize the link    
- Larger N than this won't increase efficiency further


- **Optimal Window Size** defines how many frames can be sent **in one cycle (RTT)** to ensures **full link utilization** without idle time
- **Example:**
    - Cycle Time (RTT) = 20 sec
    - Frame Transmission Time = 2 sec
    - ⇒ Optimal Window Size = 20 / 2 = **10**
- So, best utilization is achieved by sending **10 frames per cycle**
- It might provide 100% Efficiency

##### **Channel Utilization**

- Also called Link utilization or Throughput (in bits or bytes per sec)
- Total number of bytes (or bits) transmitted in Cycle time (RTT)

**Throughput**
```
= (Transmitter window size * Packet  Size) / (Cycle Time (RTT))
```
or
```
( Efficiency) * (Data transfer rate at transmitter)
```


##### **Flow Control - Sequence Number**

Minimum **number of bits** (k) required for sequence number field
```sql
= ceil( log2(Total number of sequences) ) bits
```

**Total Number of Sequences**
```sql
= 2^k
```

**Total number of Sequence**
- Transmitter's transmitting window size = `N`
- Sliding Window: `Total number of sequences = N`
- Go Back N ARQ: `Total number of sequences = N+1`
- Selective Repeat: `Total number of sequences = 2N`

**Transmitter Window Size**
- Number of bits in sequence number field = `k`
- Sliding Window: `Transmitter Window Size = 2^k`
- Go Back N ARQ: `Transmitter Window Size = (2^k-1)`
- Selective Repeat: `Transmitter Window Size = 2^(k-1)`

---
##### **Error Control**

**Error:** Corrupted data (flipped data bits)

**Types of error:**
1. Single bit error
2. Burst error 

**Error Control**

- Based on Redundant bits (parity bits or extra bits)
	1. Error detection
	2. Error detection and correction

**1. Error Detection**

- Can only detect error(s)
- Unable to Correct
- Retransmission of corrupted data
- **Two error detection technique :** ⭐
	1. **Cycle Redundancy Check (CRC)** -> Data Link layer ( in TCP/IP )
	2. **Checksum** -> Transport Layer

**2. Error detection and Correction**

- Can detect as well as correct error(s)
- Forward error correction (FEC) -> No Retransmission
- **Two Detection and correction Technique :** ⭐
	1. 2D Parity
	2. Hamming Code


>No questions on **Checksum** have appeared in the GATE exam.  
>In GATE 2008, there was a question on **2D Parity**.  
>In GATE 2021, there was a question on **Hamming Code**.

##### **Cyclic Redundancy Check (CRC)**

- It is a Error detection technique used in 'Data Link Layer' (In TCP/IP Model)

- **G(x)** : Generator Polynomial function
	- (`n+1`) terms (`x^n` to `X^0`)
	- Degree( G(x) ) = `n`
	- Coefficient of term `X^0` should be "one" ( G(x) should not be divisible by `X`)
	- Both transmitter and receiver must agree on same G(X)
	- **G(X)** = `X^n + ..... + 1`

- **Divisor**
	- It is a binary string, (`n+1` bits) `[1...1]` (i.e. divisor will always start and end with `1`)
	- **Example:**
		- G(X) = `X^3 + X^2 + 1` = `1.X^3 + 1.X^2 + 0.X^1 + 1.X^0`
		- Divisor = `1101`

```

[ G(X) = X^n + .....+ 1 ]

Sender (Transmitter)
┌──────────────────────────┐
│                          │
│   [  Data   | 00...00 ]  │
│    <-------> <------->   │
│     m bits    n bits     │
│                          │
│   mdoulo-2 divsion with  │ <- here:
│        [DIVISOR]         │     modulo-2 arithmetic -> XOR ✅
|        <------->         |     Not binary arithmetic ❌
|        (n+1) bits        |
│                          │
|     Remainder will be    |
|         [ CRC ]          | <- CRC should be n bit
|         n bits           |    Add extra zeros after Remainder 
│                          │    if needed
└──────────────────────────┘

                         |
	┌───────────┬───┐    |
	│    DATA   │CRC│    | Transmitting
	└───────────┴───┘    |
    <-------------->     |
    (m+n) bits codeword  |
                         ↓

Receiver
┌──────────────────────────┐
│                          │
│   [  Data   |   CRC   ]  │
│    <-------> <------->   │
│     m bits    n bits     │
│                          │
│   mdoulo-2 divsion with  │ <- here:
│        [DIVISOR]         │     modulo-2 arithmetic -> XOR ✅
|        <------->         |     Not binary arithmetic ❌
|        (n+1) bits        |
│                          │
|      Remainder will be   |  <- If R`(X) = 0, Correct Data
|          R`(X)           |     else, Invalid Data
└──────────────────────────┘
```

**CRC (Cyclic Redundancy Check) – Error Detection at Receiver** ⭐
- The **transmitter** sends the **message polynomial M(X)** appended with the **CRC bits (R(X))**, forming the **transmitted polynomial T(X) = M(X) × Xⁿ + R(X)**.
- The **receiver** divides the received polynomial T′(X) by the same generator polynomial G(X).
- Let the **remainder** at the receiver be **R′(X)**.
- **At Receiver:**
	- If **R′(X) = 0**
		- No error detected → Balance maintained → Message assumed correct.
	- If **R′(X) ≠ 0**
		- Error detected → Balance broken → Message corrupted.


**CRC Property**  (⭐ Asks in CS-2009, CS-2017 by IIT Roorkee)
- CRC can detect any length burst error, upto the degree of generator polynomial function
- For odd number of errors, E(X) must have odd number of terms
- if (X+1) is a factor of G(X) then CRC can detect "all odd number of errors"
- "(X+1) is factor of G(X)" means "G(X) is completely divisible by (X+1)" and "G(X) has even number of terms"

**Note:** CRC will always be appended at the Footer i.e. after payload

**Ques:** 
```
G(X) = X^3 + X + 1
Message = 11001010
What Codeword will Transmitter Transmit?
```

**Solution:**
- G(X) = because X^3 + X + 1 
- n = Degree = 3
- Divisor =  1011
- Message + n  0's = 11001010 + 000 = 11001010|000
- Message (modulo-2 ÷) Divisor -> 11001010 (XOR) 1011 
```
1011 )  1 1 0 0 1 0 1 0 | 0 0 0
        1 0 1 1 . . . .   . . .
        ─────── ↓ . . .   . . .
          1 1 1 1 . . .   . . .
          1 0 1 1 . . .   . . .
          ─────── ↓ . .   . . .
            1 0 0 0 . .   . . .
            1 0 1 1 . .   . . .
            ─────── ↓ ↓   . . .
                1 1 1 0   . . .
                1 0 1 1   . . .
                ───────── ↓ . .
                  1 0 1   0 . .
                  1 0 1   1 . .
                  ───────── ↓ ↓
                          1 0 0  <- CRC       
```

- Codeword =  `1100101010|000` + `100` = `1100101010|100`
- So, this Codeword `[1100101010100]`, Transmitter will transmit in the channel

##### **2D Parity**

- Both **sender** and **receiver** must agree on same block size and same parity (either even or odd parity)
- Block Size = `m * n`   (`m` rows & `n` columns)
- Number of Data bits =  `(m-1) * (n-1)` bits
- Number of parity bits = `( m + n - 1 )`
```

│ d   d  .  d | R1 │
| d   d  .  d | R2 │
| .   .  .  d | .  |
│ d   d  .  d | R  |  
| -- -- -- -- ┼ -- |
| C1 C2  .  C | X  |  ← Column parity
                     
                ↑
                Row parity
```

**Transmitter:**
- Generates **row-wise** and **column-wise** parity bits as per agreed parity type.
- Ensures entire block is **balanced** (each row and column satisfies the parity).

**Receiver:**
- Recalculates parity for all rows and columns.
- If **all parities are balanced** → No error detected.
- If **any parity is unbalanced** → Error detected.

**Minimum Number of Bits Corrupted (Guaranteed Detection):** ⭐
```
= maximum ( total number of row wise parity unbalanced
          total number of column wise parity unbalanced)
```

**Note:**  
- Parity type (even/odd) will be **given**.  
- Receiver just **verifies** whether the block is still balanced (as per parity).  
- If not, it concludes that **an error has occurred**.

##### **Hamming Code**

- Single bit error-correcting code
- Both Sender and receiver must agree on same parity (either "Even Parity" or "Odd Parity")
- Number of data bits = `m`
- Number of parity bits = `r`
- Code length (n) = `(m + r)` bits
- `Hamming(n,m)`

**Parity bit** placed at position = `2^i` (where i = 0, 1, 2, 3, ....)
```    
Example: 

d7  d6  d5  d4  R3  d3  d2  d1  R2  d0  R1  R0
12  11  10   9   8   7   6   5   4   3   2   1
                 ^               ^       ^   ^      Parity bits
                 2^3             2^2     2^1  2^0 : Position
```
- Parity bit Position Numbering will always start from '1'
- But Parity bit positions (R0, R1, ...) may start from LSB(Left) or MSB(Right) depending on the question's bit ordering.
- More number of data ↑  -> More no. of parity bits↑

**Minimum number of Parity bits required :**
```
= 2^r > (m + r)
```
- Minimum Code length = 3 (contains only one data bit and two parity bit)

**Even or Odd Parity**
```
    Position:
    ↓
R0  1    Position of Data bits:
R1  2       ↓
d0  3  <- 2 + 1
R2  4
d1  5  <- 4 + 1        
d2  6  <- 4 + 2        
d3  7  <- 4 + 3
R3  8
d4  9  <- 8 + 1
d5  10 <- 8 + 2
d6  11 <- 8 + 3
d7  12 <- 8 + 4
```

```
Mapping:

R0 (position 1) covers bits where binary position has 1 in LSB:
R0 = d0 d1 d3 d4 d6  -> 0 = 3, 5, 7, 9, 11 

R1 (position 2) covers bits where binary position has 1 in 2nd bit
R1 = d0 d2 d3 d5 d6  -> 2 = 3, 6, 7, 10, 11

R2 (position 4) covers bits where binary position has 1 in 3rd bit:
R2 = d1 d2 d3 d7     -> 4 = 5, 6, 7, 12

R3 (position 8) covers bits where binary position has 1 in 4th bit:
R3 = d4 d5 d6 d7     -> 8 = 9, 10, 11, 12
```

**Note:**  
- Parity type (even/odd) will be **given**.  
- You generate parity (even or odd) for each group during **transmission**.
- Receiver rechecks these parity bits to detect (and possibly correct) single-bit errors.


##### **Hamming Distance** 

- Metric for comparing two binary strings of equal length
- Hamming distance between two binary strings of equal length = Number of Position at which the corresponding bits are different
- Let suppose A and B are two binary strings of equal length and d(A,B) is Hamming distance between A and B
```
d(A,B) = Hamming Weight of [A bit-wise XOR B]
```
- Represents **number of bit changes needed** to convert A to B or vice versa


**Let Suppose set of valid codewords:**
```
Codeword : C1
Codeword : C2
Codeword : C3
Codeword : C4

Minimum Hamming Distance = 
	Minimum ( d(c1,c2), d(c1,c3), d(c1,c4), d(c2,c3), d(c2, c4), d(c3, c4) )
```

If (minimum) Hamming Distance is `D`
	-> then receiver can detect upto `(D-1)` bits error
	-> and receiver can correct upto Floor `[(D-1)/2]` bits error 

To detect upto `x`-bits error
	-> Minimum Hamming Distance should be `(x+1)`

To detect `y`-bits error
	-> Minimum Hamming Distance should be `(2y + 1)`

> Hamming Distance is Important topic for GATE, 3x time question from it.


##### **Media Access Control (MAC) **

- The lower sub layer
- Determine "who can access the media" (in multipoint (multidrop) line configuration)
- No any use, in point-to-point line configuration
- Multiple access protocols

##### **Multiple Access Protocol**

- Distributed Algorithm:
	- Determine "how node shares channel"
	- Determine "when node can transmit"

- Communication about channel sharing must use channel itself
- **Fully decentralized:** No any special node to coordinate

**Types of Protocol:**
1. Random Access Protocol (like ALOHA, CSMA)
2. Controlled Access Protocols (like Polling, Token Passing)
3. Channelization Protocols (like FDMA, TDMA, CDMA)
##### **Random Access Protocols**

- Random Access MAC protocols are:
	- ALOHA
		- Pure ALOHA
		- Slotted ALOHA
	- Carrier Sense Multiple Access (CSMA)
		- CSMA
		- CSMA/CD (for wired) 
		- CSMA/CA (for wireless)


##### **ALOHA**

- Any station can transmit whenever it has data.
- **No sensing**: Stations do **not check** if the channel is busy before transmitting.
- **If collision occurs**: Wait for a **random backoff time** and **retransmit**.
- **Pure ALOHA**: Transmit anytime.
- **Slotted ALOHA**: Transmit only at fixed time slots (improves efficiency).

**Vulnerable Time** : The duration in which no transmission should done to avoid collision ⭐
- **`G:`** Mean number of transmissions per frame time (Average number of frame transmitted in one frame transmission time)
- **`S`** : Throughput per frame time (Average number of frame transmitted successfully in one frame transmission time)
- **`P`:** Probability that a frame does not involve in a collision
```
S = G * P
```


**1. Pure ALOHA**

- When node has packet to transmit, it transmit immediately
- Allow collision to happen (recover via "retransmission")
- Use **randomization** in choosing "when to transmit" (Back-off time)
- All frames are of **equal size**
- Receiver send acknowledgment to source ( for every correctly (without collision) received frame
- After transmitting a frame, Source wait for an ACK upto time-out
- Time-out time = Round Trip Propagation Delay

- **Vulnerable Time**
```
= 2 * Frame Transmission Time = 2 * tx
```

- According to **Poisson's distribution**
```
P = e^(-2G)
S = G * e^(-2G)
```
- Maximum throughput can be achieve at `G = 0.5`
- Maximum throughput = `1/2e = 0.1839 = 18.39 %` ⭐

**2. Slotted ALOHA**

- To improve the efficiency in Pure ALOHA
- Divide the time into equal size slots (Slot time = One frame transmission time)
- Nodes are synchronous
- Whenever a node has packet to transmit, it will start transmission only at begin of slot

- **Vulnerable Time**
```
= Frame Transmission Time =  tx
```

- According to **Poisson's distribution**
```
P = e^(-G)
S = G * e^(-G)
```
- Maximum throughput can be achieve at `G = 1`
- Maximum throughput = `1/e = 0.3678 = 36.78 %` ⭐

- **Slotted ALOHA Efficiency** ⭐
	- Suppose N nodes with many frames to transmit
	- Each node transmits in slot with probability `p`
	- Probability that ==given== node has success in a given slot 
		- = `p * (1-p)^ (N-1)`
	- Probability that ==any== node has success in a given slot 
		- = `N * p * (1-p)^ (N-1)`

 >ALOHA is not very important, but **vulnerable time** and **probability of success** for given/any node are asked in GATE.


##### **Carrier Sense Multiple Access (CSMA)**

- Sense before transmit (Sense the channel, before transmission)
- if channel sensed idle  -> **"transmit entire frame"**
- if channel sensed busy -> **"defer transmission"**  

**CSMA/CD**
- CSMA with **Collision Detection**
- Applicable only for wired LAN (bus topology)
- Also Sense while (during) transmission
- No any feedback (acknowledgment) from receiver
- To detect collisions,
	- minimum frame transmission delay should be greater than equal to (maximum) round trip propagation delay
	- frame transmission delay >= round trip propagation delay
	- `tx >= 2*tp`
	- minimum Frame size
```
		= 2 * tp * Bandwidth
```

- **Types of CSMA/CD**
	1. 1-Persistent CSMA/CD
	2. Non-Persistent CSMA/CD
	3. **p-Persistent CSMA/CD** (used in slotted channels)

> CSMA/CA is Skipped, Not Important for GATE Exam


**Why CSMA/CD is used only on wired Ethernet and CSMA/CA on wireless LANs**

- **CSMA/CD requires the ability to listen while sending**; only practical on a shared wired medium.
- **Wireless nodes cannot do that**, so they rely on **CSMA/CA**, which minimises (rather than detects) collisions through carrier sensing, random back-off, and control frames.

|Feature|CSMA/CD (Collision Detection) – **Wired**|CSMA/CA (Collision Avoidance) – **Wireless**|
|---|---|---|
|**Medium sensing while transmitting**|A wired NIC can transmit and **simultaneously measure** voltage/current on the same copper pair (full-duplex transceiver). If the signal it “hears” differs from what it is putting on the wire, it detects a collision instantly.|A radio transceiver is **half-duplex on a single channel**: when it is transmitting, its own signal overwhelms the receiver front-end, so it **cannot listen** for other transmissions at the same time. Collision detection is therefore impossible.|
|**Collision handling**|If a collision is detected, stations abort immediately, saving time and bandwidth; then they back-off (binary exponential).|Because detection is impossible, stations try to **avoid** collisions: they listen _before_ transmitting, randomise a back-off, and optionally use RTS/CTS + ACK frames to reserve the channel. Collisions that still occur are discovered only by **missing acknowledgments**.|
|**Hidden-terminal problem**|Absent (all nodes share the same cable and can hear every other node’s carrier).|Present: two stations out of radio range of each other can both sense “idle,” transmit, and collide at an AP. CSMA/CA’s RTS/CTS exchanges mitigate this.|
|**Practical deployment**|Traditional shared-hub Ethernet (10BASE-T, 100BASE-TX in half-duplex) – now mostly replaced by switched full-duplex links where collisions do not occur.|IEEE 802.11 (Wi-Fi) physical layers (2.4 GHz, 5 GHz, 6 GHz). Collision avoidance remains necessary even with modern rates.|


##### **LAN Standards (Only Important for GATE)**
- `IEEE 802.3` : Ethernet ---> (Bus Topology) ---> CSMA/CD
- `IEEE 802.4` : Token Bus ---> (Bus Topology) ---> Token
- `IEEE 802.5` : Token Ring ---> (Ring Topology) ---> Token
- `IEEE 802.11` : Wireless ---> (Wi-Fi) ---> CSMA/CA

> Wireless is not in Syllabus
##### **Ethernet**

- IEEE 802.3
- Based on 1-persistent CSMA/CD
- So same `tx >= 2tp`


##### **Framing**

**Problem:**  How receiver identify boundaries while receiving multiples frames? (Variable length frames and transmitted without time-gap)

```             
         [Frame1 | Frame 2 | Frame 3 | Frame 4] ⭢
[Sender]-----------------------------------------[Receiver]
```

**Solution**
1. Byte (Character) Count
2. Byte (Character) Stuffing
3. Bit Stuffing

> 2004, 2014 Question on Bit Stuffing

##### **BIT Stuffing**

**FLAG:** "`~`"
- Primary (bit pattern) = "`01111110"
- ASCII Value = `126` = `0x7E`

**Transmitter Protocol:**
1. Transmit **"FLAG"** character, just before frame transmission start.
2. Transmit **"FLAG"** character, just after frame transmission completed
3. **Stuff "Zero Bit"** after **every five continuous one's** while transmission. (Except start and end of frame)

**Receiver Protocol:**
1. Looking for **"Start of Frame"** (FLAG)
2. After Start of Frame, it is looking for "End of Frame" (FLAG)
3. **Discard "Zero Bit"** that found after every **five continuous one's** while receiving data frame

**Conclusion:**  ⭐
- Six continuous one's can only appear in the start and end of frame while transmission

**Advantage:** (over byte stuffing )
- For every five continuous one's present in the data frame, length of frame increases by "one-bit".


---

The end ✔️