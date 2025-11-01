
# Computer Networks

| Topics              | Subtopics                           |
| ------------------- | ----------------------------------- |
| Data Communication  | Transmission components             |
| OSI & TCP/IP Models | Layers and functions                |
| Switching & Routing | Circuit, packet, routing algorithms |
| Subnetting          | IPv4/IPv6 addressing                |
| Network Security    | Firewalls, VPNs                     |
| Wireless Networks   | WLAN, Bluetooth                     |
| SDN                 | Architecture and applications       |

# Data Communication Components

**Definition:**  
Data communication refers to the exchange of data between two devices through a transmission medium.

**Five Main Components:**

1. **Message:**
    
    - The actual data or information to be communicated.
        
    - Examples: text, numbers, images, audio, video.
        
2. **Sender (Source):**
    
    - Device that sends the data message.
        
    - Examples: computer, smartphone, server.
        
3. **Receiver (Destination):**
    
    - Device that receives the data message.
        
    - Examples: computer, printer, workstation.
        
4. **Transmission Medium:**
    
    - The physical path through which data travels.
        
    - Examples: copper cable, fiber optics, radio waves.
        
5. **Protocol:**
    
    - A set of rules governing data communication.
        
    - Defines format, timing, error control, and synchronization.
        
    - Examples: TCP/IP, HTTP, FTP.
        

**Requirements of Effective Communication:**

- **Delivery:** Data must reach the correct destination.
    
- **Accuracy:** Data must be delivered without alteration.
    
- **Timeliness:** Data must be delivered in time (especially for real-time systems).

----
----

# OSI Model & TCP/IP Model

**1. OSI (Open Systems Interconnection) Model**

- Developed by ISO, it defines a standard framework for network communication.
    
- Consists of **7 layers**, each with specific functions.
    

|Layer|Function|Protocols/Devices|
|---|---|---|
|7. **Application**|User interface, network services to end users|HTTP, FTP, SMTP, DNS|
|6. **Presentation**|Data translation, encryption, compression|SSL, JPEG, MPEG|
|5. **Session**|Establish, manage, terminate sessions|NetBIOS, RPC|
|4. **Transport**|Reliable data transfer, segmentation, flow control|TCP, UDP|
|3. **Network**|Logical addressing, routing|IP, ICMP, Routers|
|2. **Data Link**|Framing, error detection, MAC addressing|Ethernet, PPP, Switches|
|1. **Physical**|Transmission of raw bits, hardware interface|Cables, Hubs, NIC|

**Key Features:**

- Conceptual and theoretical model.
    
- Helps standardize networking functions.
    

---

**2. TCP/IP Model (Transmission Control Protocol / Internet Protocol)**

- Practical model used for Internet communication.
    
- Consists of **4 layers**.
    

|Layer|Function|Protocols|
|---|---|---|
|**Application Layer**|Provides services to user applications|HTTP, FTP, DNS, SMTP|
|**Transport Layer**|End-to-end communication, reliability|TCP, UDP|
|**Internet Layer**|Logical addressing, routing|IP, ICMP, ARP|
|**Network Access Layer**|Physical transmission, framing|Ethernet, Wi-Fi, PPP|

**Key Features:**

- Developed by DARPA (ARPANET project).
    
- Basis of the modern Internet.
    

---

**3. Comparison: OSI vs TCP/IP**

|Aspect|OSI Model|TCP/IP Model|
|---|---|---|
|Layers|7|4|
|Developed By|ISO|DARPA|
|Approach|Theoretical reference model|Practical implementation model|
|Protocol Dependency|Protocol-independent|Protocol-specific (TCP/IP suite)|
|Session/Presentation Layers|Present|Not separate (handled in Application layer)|
|Standardization|General model for any network|Designed specifically for Internet|
|Example Protocols|FTP, SMTP, IP, Ethernet|TCP, IP, HTTP, FTP|

**Summary:**

- **OSI** provides a clear conceptual framework for understanding communication.
    
- **TCP/IP** is the real-world model used in all Internet communications.

---
---

# Switching and Routing

**1. Switching**

- Process of forwarding data packets between devices within the same network or LAN.
    
- Operates mainly at **Data Link Layer (Layer 2)** of OSI Model.
    

**Types of Switching:**

1. **Circuit Switching:**
    
    - A dedicated path is established before communication.
        
    - Used in telephone networks.
        
    - Example: PSTN.
        
    - **Advantage:** Fixed bandwidth and guaranteed delivery.
        
    - **Disadvantage:** Inefficient for bursty data.
        
2. **Packet Switching:**
    
    - Data is divided into packets and sent independently through the network.
        
    - Used in computer networks and the Internet.
        
    - **Advantage:** Efficient bandwidth utilization.
        
    - **Disadvantage:** Variable delay and possible congestion.
        
3. **Message Switching:**
    
    - Entire message is treated as a single unit and stored-and-forwarded at intermediate nodes.
        
    - **Advantage:** No dedicated path required.
        
    - **Disadvantage:** High delay due to storage at each node.
        

**Switch:**

- A Layer 2 device that forwards frames using MAC addresses.
    
- Provides collision-free communication within LAN using micro-segmentation.
    

---

**2. Routing**

- Process of selecting a path for data packets to travel across networks.
    
- Operates at **Network Layer (Layer 3)** of OSI Model.
    

**Router:**

- A device that connects multiple networks and forwards packets using **IP addresses**.
    

**Routing Types:**

1. **Static Routing:**
    
    - Routes are manually configured.
        
    - **Pros:** Simple, secure.
        
    - **Cons:** Not scalable.
        
2. **Dynamic Routing:**
    
    - Routes are learned automatically using routing protocols.
        
    - **Pros:** Adapts to network changes.
        
    - **Cons:** More overhead.
        

**Common Routing Protocols:**

- **RIP (Routing Information Protocol):** Distance-vector, uses hop count metric.
    
- **OSPF (Open Shortest Path First):** Link-state, uses cost metric.
    
- **BGP (Border Gateway Protocol):** Used for Internet routing between autonomous systems.
    

**Key Difference:**

- **Switching** deals with forwarding within a network (LAN).
    
- **Routing** deals with forwarding between networks (WAN).

---
---

# Subnetting

**Definition:**  
Subnetting is the process of dividing a large IP network into smaller, manageable sub-networks (subnets) to improve efficiency, security, and utilization of IP addresses.

---

**1. Purpose of Subnetting:**

- Efficient use of IP addresses.
    
- Reduces network congestion.
    
- Improves security and management.
    
- Enables hierarchical addressing.
    

---

**2. IP Address Structure:**  
An IP address consists of **Network ID** and **Host ID** parts.  
Example: `192.168.10.25/24`

- Network ID: `192.168.10`
    
- Host ID: `25`
    
- Subnet Mask: `255.255.255.0`
    

---

**3. Subnet Mask:**

- Determines which portion of the IP address is the network part and which is the host part.
    
- Example:
    
    - Class C Default Mask: `255.255.255.0`
        
    - Binary: `11111111.11111111.11111111.00000000`
        

---

**4. Borrowing Bits:**  
To create subnets, bits are borrowed from the host portion.

- More borrowed bits ⇒ More subnets, fewer hosts per subnet.
    

**Formulas:**

- **Number of Subnets = 2ⁿ**, where n = number of bits borrowed.
    
- **Hosts per Subnet = 2ʰ – 2**, where h = remaining host bits.  
    (Subtract 2 for network and broadcast addresses.)
    

---

**5. Example:**  
Given: `192.168.10.0/26`

- Default mask: `/24` → Borrowed 2 bits → `/26`
    
- Subnet mask: `255.255.255.192`
    
- Subnets = 2² = 4
    
- Hosts per subnet = 2⁶ – 2 = 62
    

Subnets:

|Subnet|IP Range|Broadcast|
|---|---|---|
|1|192.168.10.0 – 192.168.10.63|192.168.10.63|
|2|192.168.10.64 – 192.168.10.127|192.168.10.127|
|3|192.168.10.128 – 192.168.10.191|192.168.10.191|
|4|192.168.10.192 – 192.168.10.255|192.168.10.255|

---

**6. CIDR (Classless Inter-Domain Routing):**

- Allows flexible subnetting by using variable-length subnet masks (VLSM).
    
- Example: `/27` means 27 bits for network, 5 for hosts.
    
- CIDR enables aggregation and reduces routing table size.
    

---

**Summary:**

- Subnetting optimizes IP address usage.
    
- Uses binary division of network bits.
    
- Essential for scalable and efficient network design.

---
---

# Network Security & Firewalls

**1. Network Security**  
Network Security refers to protecting data during transmission and ensuring confidentiality, integrity, and availability of network resources.

**Objectives (CIA Triad):**

- **Confidentiality:** Prevent unauthorized access to data.
    
- **Integrity:** Ensure data is not altered during transmission.
    
- **Availability:** Ensure network resources are accessible to authorized users.
    

**Common Threats:**

- **Viruses/Worms/Trojans:** Malicious software disrupting systems.
    
- **Phishing & Social Engineering:** Deceptive attempts to gain credentials.
    
- **Denial of Service (DoS):** Flooding network resources to make them unavailable.
    
- **Man-in-the-Middle Attack:** Intercepting communication between two devices.
    
- **IP Spoofing:** Impersonating another system’s IP address.
    

**Security Measures:**

- **Encryption (SSL/TLS, IPSec):** Protects data in transit.
    
- **Authentication:** Verifies identity (passwords, biometrics).
    
- **Access Control:** Restricts unauthorized access.
    
- **Intrusion Detection/Prevention Systems (IDS/IPS):** Detect and block attacks.
    
- **Antivirus & Firewalls:** Protect endpoints and network boundaries.
    

---

**2. Firewalls**  
A firewall is a network security device that monitors and controls incoming and outgoing traffic based on predefined security rules.  
It acts as a **barrier between trusted (internal) and untrusted (external) networks**.

**Functions:**

- Packet filtering
    
- Blocking unauthorized access
    
- Logging and monitoring traffic
    
- Preventing malware and intrusions
    

**Types of Firewalls:**

1. **Packet-Filtering Firewall (Layer 3):**
    
    - Inspects IP headers and port numbers.
        
    - Simple and fast, but limited security.
        
2. **Stateful Inspection Firewall (Layer 3/4):**
    
    - Monitors connection states and packet context.
        
    - More secure than simple packet filtering.
        
3. **Proxy Firewall (Application Layer):**
    
    - Acts as an intermediary between users and services.
        
    - Can inspect application-level data (e.g., HTTP, FTP).
        
4. **Next-Generation Firewall (NGFW):**
    
    - Combines deep packet inspection, intrusion prevention, and application awareness.
        

---

**Firewall Techniques:**

- **Allow/Deny Rules:** Based on IP, port, protocol.
    
- **Network Address Translation (NAT):** Masks internal IP addresses.
    
- **VPN Support:** Secure remote access.
    

---

**Summary:**

- Network security safeguards data and systems against threats.
    
- Firewalls are the first line of defense controlling network access.
    
- Layered security with firewalls, encryption, and monitoring ensures robust protection.

---
---



# Fundamentals of Wireless Networks

**Definition:**  
Wireless networks use radio waves or infrared signals to transmit data without physical cables.

---

**1. Components of Wireless Network:**

- **Access Point (AP):** Connects wireless devices to wired network.
    
- **Wireless Clients:** Devices like laptops, mobiles, IoT sensors.
    
- **Wireless Medium:** Radio frequency used for data transmission.
    
- **Antennas:** Convert electrical signals to electromagnetic waves.
    

---

**2. Characteristics:**

- Uses electromagnetic spectrum (2.4 GHz, 5 GHz, 6 GHz).
    
- Provides mobility and flexibility.
    
- Subject to interference and signal attenuation.
    

---

**3. Types of Wireless Networks:**

1. **WPAN (Wireless Personal Area Network):**
    
    - Range: Few meters.
        
    - Example: Bluetooth, ZigBee.
        
2. **WLAN (Wireless Local Area Network):**
    
    - Range: 100 m (approx).
        
    - Standard: IEEE 802.11 (Wi-Fi).
        
3. **WMAN (Wireless Metropolitan Area Network):**
    
    - Range: Up to 50 km.
        
    - Standard: IEEE 802.16 (WiMAX).
        
4. **WWAN (Wireless Wide Area Network):**
    
    - Covers large geographic areas.
        
    - Examples: 3G, 4G, 5G cellular networks.
        

---

**4. IEEE 802.11 Standards (Wi-Fi):**

|Standard|Frequency|Max Speed|Notes|
|---|---|---|---|
|802.11a|5 GHz|54 Mbps|Short range, less interference|
|802.11b|2.4 GHz|11 Mbps|Longer range, more interference|
|802.11g|2.4 GHz|54 Mbps|Backward compatible with b|
|802.11n|2.4/5 GHz|600 Mbps|MIMO technology|
|802.11ac|5 GHz|>1 Gbps|High throughput|
|802.11ax (Wi-Fi 6)|2.4/5/6 GHz|>10 Gbps|High efficiency, OFDMA|

---

**5. Wireless Network Topologies:**

1. **Infrastructure Mode:** Devices connect via Access Point.
    
2. **Ad-hoc Mode:** Devices connect directly (peer-to-peer).
    

---

**6. Security in Wireless Networks:**

- **WEP (Wired Equivalent Privacy):** Basic, outdated encryption.
    
- **WPA/WPA2/WPA3:** Advanced encryption standards for Wi-Fi.
    
- **MAC Filtering:** Allows only authorized devices.
    

---

**7. Advantages & Disadvantages:**  
**Advantages:** Mobility, flexibility, scalability, easy installation.  
**Disadvantages:** Interference, lower speed, limited range, security risks.

---

**Summary:**  
Wireless networks enable communication without cables, based on IEEE 802.11 standards, offering mobility with trade-offs in range, reliability, and security.


---
---


# SDN (Software Defined Networking)

**Definition:**  
Software Defined Networking (SDN) is a modern network architecture that separates the **control plane** (decision-making) from the **data plane** (packet forwarding) to enable centralized and programmable network management.

---

**1. Traditional vs SDN Networks:**

|Feature|Traditional Network|SDN|
|---|---|---|
|Control & Data Plane|Integrated in each device|Separated|
|Management|Manual configuration|Centralized control|
|Flexibility|Limited|Highly programmable|
|Scalability|Complex|Simplified via automation|

---

**2. SDN Architecture:**  
**a) Application Plane:**

- Contains network applications (e.g., routing, security, load balancing).
    
- Communicates with the control plane via **northbound APIs**.
    

**b) Control Plane:**

- Centralized **SDN Controller** manages the entire network.
    
- Translates application requirements into network configurations.
    
- Examples: OpenDaylight, ONOS, Cisco APIC.
    

**c) Data Plane:**

- Consists of forwarding devices (switches, routers) that execute instructions from the controller.
    
- Communicates with controller via **southbound APIs** (mainly OpenFlow).
    

---

**3. Key Protocol – OpenFlow:**

- Standard protocol for communication between SDN controller and switches.
    
- Enables the controller to define flow rules for packet forwarding.
    

---

**4. Advantages:**

- **Centralized Control:** Easier configuration and management.
    
- **Programmability:** Networks can be dynamically adjusted through software.
    
- **Scalability:** Simplifies management of large networks.
    
- **Cost Efficiency:** Uses commodity hardware.
    
- **Enhanced Security:** Controller enforces uniform security policies.
    

---

**5. Challenges:**

- **Single Point of Failure:** If controller fails, network may halt.
    
- **Complex Implementation:** Requires skilled administration.
    
- **Interoperability Issues:** Between legacy and SDN devices.
    

---

**6. Applications:**

- Data centers and cloud networks.
    
- Network virtualization.
    
- Dynamic traffic engineering.
    
- Security policy enforcement.
    

---

**Summary:**  
SDN decouples control and data planes, offering centralized, programmable, and flexible network management — a foundation for modern cloud and data center networks.