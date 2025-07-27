
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
- The processes in **Transport Layer** communication can be on the **same or different devices**, but typically:
	- **In networking context (GATE)**:  It's about communication between **processes on different devices** over a network.

- For **Data Link Layer**  Communication Node must be a **network device (Layer 3 or above)**, **not a Layer 2 device** like a Hub, Switch or Bridge

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
- **TCP** is used when reliable, connection-oriented communication is needed.
- **UDP** is used for faster, connectionless communication where some loss is acceptable.
- Some protocols like **DNS** can use both **UDP** (for queries) and **TCP** (for zone transfers).

##### **Stateful vs Stateless**

**Transport Layer**
- **Stateless** (Doesn't maintain connection/session state):
    - **UDP**  (Also Connection-less )
        
- **Stateful** (Maintains connection/session state):
    - **TCP**  (Also Connection-oriented)

**Application Layer**
- **Stateless** (Doesn't maintain user/session information):
    - **DNS**, **HTTP**, **SMTP**
        
- **Stateful** (Maintains user/session information):
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
[DNS Resolver] --- DNS Query --->     [TL Name Server]
         ↑  |  <--- DNS Reply ---      
         |  |         ()
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

Two types of HTTP connections ⭐

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

- One-time use: connection is closed after the response
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

- Multiple objects can be transferred over a single TCP connection
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
    Application like Gmail, Outlook, etc. used to compose, send, receive, and read emails.
- **Mail Server:**  
    Each user has a mail server (e.g., Gmail, Yahoo) that temporarily stores and forwards messages.

**Protocols:**

1. **SMTP (Simple Mail Transfer Protocol)**
    - Used for **mail transmission** (User Agent → Mail Server → Mail Server)
    - Works in **push mode**
    - **Persistent TCP connection** ⭐
    - **Stateless** – User Agent 1 and Mail Server 1 do **not maintain** the state of sent mails (once sent, no tracking of delivery status or read status) ⭐
        
2. **IMAP (Internet Message Access Protocol)**
    - Used for **mail download** (Mail Server → User Agent)
    - Supports multiple device login
    - Allows **hierarchical storage**: folders, labels, inbox, etc.
    - **Stateful** – Mail Server 2 and User Agent 2 **maintain state** of mails (e.g., read/unread status, spam alerts for repeated mails, flags, folders) ⭐

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
    - **Persistent TCP connection**
        
2. **Data Connection**
    - Created **separately** for each file transfer (upload/download)
    - Closed after the transfer completes
    - **Non-persistent TCP connection**
- Data Connection can also be from client to server as upload

**Upload & Download:**
- **Upload:** Client → Server (Data connection initiated by client)
- **Download:** Server → Client (Data connection may be initiated by server depending on mode)

**Modes of FTP:**
- **Active Mode:** Server initiates data connection to client
- **Passive Mode:** Client initiates both control and data connections (common in modern systems due to firewalls)

---
# Transport Layer

Provide logical communication between application processes (Processes running on different hosts)

Two Transport Layer Protocols :
1. UDP - User Datagram Protocol
2. TCP - Transmission Control Protocol

**1. UDP (User Datagram Protocol)**
- **Connection-less** and **unreliable** service
- Messages may be **lost**, **duplicated**, or **arrive out of order**
- Lightweight, **simple**, and **fast**
- Preferred for **short communications** like query-response
- Used by: **DNS**, **SNMP**, **HTTP/3**, **RIP**, and **real-time multimedia streaming** ⭐
    
**2. TCP (Transmission Control Protocol)**
- **Connection-oriented** and **reliable** service
- Ensures **in-order delivery**, and detects/retransmits lost packets
- Provides **flow control**, **error control**, and **congestion control** ⭐
- Preferred for **long communication** and **data integrity-sensitive applications**

##### **Sequence Number**

- **TCP is a byte-stream protocol** (Stream-oriented)
- Uses **32-bit sequence numbers**
- A **unique sequence number is assigned to each byte** (not segment) ⭐
- The **sequence number in a TCP segment** represents the **sequence of the first byte in the payload**
- Using this, we can calculate:
    - Sequence numbers of all bytes in the segment    
    - Sequence number of the **next segment** (by adding payload size to current sequence number)
    
- 🔄 **Common doubt:**
    - Sequence number is assigned **per byte**, **not per segment**

---

##### **Acknowledgment Number (TCP)**

- **TCP acknowledgments are piggybacked**
    - Meaning: The TCP header has a field for acknowledgment; even when sending data, acknowledgment info is included in the same segment
    - No separate ACK-only packet is needed if data is also being sent
        
- **TCP uses cumulative acknowledgment**
    - Receiver acknowledges the **next expected byte sequence number**
    - This implies that **all previous bytes (Ack No - 1 and before)** have been received successfully
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

**Doubt Clarification**

- **In Data Link Layer (e.g., Stop-and-Wait / Go-Back-N):**
    - **Sequence numbers are assigned to Frames**
    - Acknowledgment numbers refer to **Frame Numbers** (Frame 0, 1, etc.)
        
- **In TCP (Transport Layer):**
    - **Sequence numbers are assigned to Bytes**
    - Acknowledgment number refers to the **next expected Byte**
    - So, even if a segment (packet) contains 500 bytes, **sequence and acknowledgment tracking is per byte**, not per segment
        

##### **Maximum Segment Lifetime (MSL)** ⭐

**What is MSL?**

- **MSL (Maximum Segment Lifetime)** is the **maximum time** a TCP segment is allowed to exist in the network before being discarded.
- It also relates to **wrap-around time**, i.e., the **minimum time** in which a **sequence number can be reused**.
    
 
 **Understanding Sequence Numbers in TCP**
 
- TCP assigns a **sequence number to each byte** of data.
- The **sequence number field** in TCP is **32 bits** long ⇒ can represent numbers from `0` to `2³² - 1`.
- So, total sequence number range = `2³² = 4,294,967,296` bytes = **4 GB**
- Once the value reaches `2³² - 1`, it wraps around to `0`, `1`, and so on.  
    This phenomenon is called **sequence number wrap-around**.
    

**Initial Sequence Number (ISN)**

- During **TCP connection establishment**, both client and server **randomly choose an ISN**.
- The ISN itself is **consumed** during the handshake.
- So, the **first byte of actual data** sent has **sequence number = ISN + 1**
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
- If `Message 1` has 100 bytes:
    - Sequence numbers: 1234 → 1333
    - Message 2: 1334 → 1433
    - ... and so on
        
- TCP socket maintains state to **track the next sequence number** and **received ACKs**
    

**Problem: What if File Size > 4GB?**

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
- Repeating sequence numbers **within wrap-around time** may cause confusion
    

**Maximum Segment Lifetime (MSL)**

- MSL is the **maximum time a segment can stay alive in the network**
- To avoid confusion with repeated sequence numbers, **MSL must be ≤ wrap-around time**
- **To maximize MSL**:  Ensure that **wrap-around time is large enough** (by limiting bandwidth or using sequence number extensions)

|Term|Description|
|---|---|
|ISN|Initial Sequence Number (chosen randomly during handshake)|
|TCP Seq No.|Assigned to **each byte**, not segment|
|Wrap-Around Time|Minimum time after which a sequence number can repeat|
|Wrap-Around Formula|`2^32 / Bandwidth`|
|MSL|Time after which a TCP segment is considered **invalid**|
|Condition|`MSL ≤ Wrap-around time`|

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
....................|⬋	            ⬋      |
					|            ⬋         |
	FIN-WAIT-2	 {  |	     ⬋	  FIN       |
					|   ⬋                  |
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

- **Any side** can initiate termination (hence named as TCP A and TCP B)
    
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


**Submetting**


##### **Classless IPv4 Addressing (CIDR - Classless Inter-Domain Routing)**

```
P.Q.R.S/x
```

- **Dynamic assignment**: NetID size is **explicitly defined** using a **subnet mask** or **CIDR notation**.
- Example: `192.168.10.0/22` → first 22 bits are Network ID, remaining 10 bits are Host ID.
- More **efficient**, **flexible**, and **scalable** than classful addressing.
- Solves problem of **IP wastage** and allows **subnetting**.


---
---
---


# Transport

Application - Transport
Port(DNA) - Socket(TCP/UDP)

TCP - Connection oriented and Reliable protocol
UDP - Connection less and unreliable protocol (But UDP is fast)

DHCB -> Broad Cast Mode -> cannot stablish connection -> Cannot Use TCP
RIP - Used in Routing -> If we use connection for each, it will be complex -> so use UDP

For Connections, The Node should no each others IP address 


Stateless - No state is maintined/Accounted how much data send or received

Statefullness in Transport Layer and Application Layers are not dependent

FTP - 2 TCP Connection (Control (maintain state/log) + Data)


TcP - Logical Connection (log maintain which socket is connected to which)
Circuit Switching - Phyiscal Connection

DNS Resolver = Host Name + Query =  Host Id + Port no.


3 Tier `www.pw.live` Hierarchy have only one TLD
4 tier `www.dtu.ac.in` 2 TLD
`dtu` -> Authoritative Name server
`ac` -> 2nd TLD
`in` -> Root Name Server
TLD - Top Level domain `.com`, `.edu` `.org`, `.in`


Http 1.0 -> one time use tcp connection -> 1 object (html, image or video ) -> autoclose connection
Syn - connection request
Syn + Ack - Connection Ack
HTTP Request - GET


HTTP 1.1 -> Back to Back object transfer (in pipeline fashion)

Modern Browser operate in - Pipeline Mode
Connection Established
Connection Established ? -> Request Base html file
Which Objects are Required? (written in Base html) -> Back to Back send object


Mail Transmit -> SMTP protocol
Mail Download -> Imap protocol 

IMAP -> modern protocol
POP -> old protocol -> doesnot support parrallel login, doesnot support labelling, heirarchy folder , different inboxes etc.


SMTP - 1 Tcp connection for both (command+mail)
FTP Server - Server of Files
FTP - 2 TCP connection - control + data


TCP is intelligent protocol , and so it doen't lead fragmentation of IP address

---
# Transport Layer

Transmitted byte = LastByteSent - LastByteAcked

CWND - Congestion Window 
RWND - Flow

Congestion Control Important ⭐


### Network





Net ID + Subnet ID + Host ID = IP Address (32-BIT)

In Modern Time Subnet ID Can be all zero to all 1, to prevent waste of Cluster of IP id
No. of subnet reduce by 2 i.e `2^(subnet bits)-2` and no. of wasted host id `(2^(SUBNET BITS)-2)* SUBNET SIZE`

- Subnet Address : Host ID = 0.......0 -> Special IP Address -> not assigned to any host
- Subnet Broadcast Address (32-bit) : Host ID = 1.....1

No. of subnets `2^(subnet bits)`
Sub-net size = `2^(host bits) - 2`


Network mask -> genrate network address from given ip address

Subnet Mask ->  generate subnet address from given ip address
- net id = all one bits
- subnet id = all one bits
- host id = all zero bits

subnet address = Ip adress x subnet mask

VLSM variable length subnet  mask

Variable length network prefixes, Allow variable size sub-neworks (subnet)

![[Pasted image 20250130151521.png]]


Router Forwarding Table

```
Nework address     Mask   Interface ID Next hop
    .....          ...     ......       ....
    .....          ...     ......       ....
    .....          ...     ......       .... 
```

Router use Longest Prefix match to find whom to send the packet -> router chooses more specifix (more one 1...) option over generic one (Les one 0....)

IPd - Destination IP address 
NA - Network address

IPd  && Mask 1 == NA1?? transfer to Router 1
IPd  && Mask 2 == NA2?? Transfer to router 2
IPd  && Mask 3 == NA3?? Transfer to Router 3


Classless Inter -Domain Routing (CIDR) - with this you can find where the ip adreess is (country, state, city, service provider etc) using IP address prefix only
-> IP address allocation method for better routing
-> Based on VLSM
-> Allows flexibility in creating 'supernets'


##### ARP
**DDL**
Address Resolution Protocol (ARP)  -> find MAC address of device from IP address
- MAP logical to physical address
- DDL Protocol

ARP Packet
 ARP Query - Broad Cast, FF:FF:FF:FF:FF:FF (48 bits)
ARP Reply - Unicast


##### NAT

NAT - Network Address Translation

IPv4 address assigned by ISP
total no. of networks worldwide = 2^32

Outgoing datagram - Source IP convert private to public
Incoming datagram - Destination IP convert public to private


-----
----
Example - If a TCP segment with sequence 200, and have 100 byte
so its mean its bytes sequence no's are

In DDL Sequence no. are assigned to Frames
In Transport Layer , seq no. are assigned to bytes not segments
```
byte 1,   2   3  .............. 98 99 100
seq no. 200 201 202 ...............297 298 299

So next segment Sequence no. will start from `300`
```


Culmulative Acknowledgement - Acknowledgement for 1 + upto which data is received (Main/Base header)
Selective Acknowledgment -  (Optional Header) If Receiver already get higher seq no. segment before required one, it will stored it in the buffer, and it will acknowledge the sender that these selected future bytes are received already, and lower bytes are missing


⭐ Important 3 question in GATE - Maximum segment Lifetime

Socket is a Data structure, that created corresponding to every Network processes
Whenever a Process become Network process than socket no. need to be created, and port no. is assigned
- Socket data structure have to two buffer - sending and Receiver

ISN - Initial sequence no. (need not be zero) - Random no.

ISN - Created randomly and consumed for Connection establishing bytes
ISN + 1 - First Message byte


MSL is equal to Wrap-around time

TCP connection - i.e Logical connection between two sockets


Roorke fav topic - connection termination, CRC


Connection Can be terminated by any one Client or Server i.e  TCP A or Tcp B


TCP sockets

TCP socket() will created first
process will system call and Request OS to create a Socket

listen() can be get out of only two - client or if process close abruptly