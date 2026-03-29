
Entire Syllabus Cover :
- Wireless Network
- Mobility
- Mobile Device

---
# Mobile Computing

**Mobile Computing:** Mobile computing can be defined as a computing environment that allows devices to access information, data, and logical objects from any location, at any moment, over any network, and on any device. It enables users to remain connected and productive regardless of their physical location.

**Other Terms for Mobile Computing:**
- **Virtual Home Environment:** The idea that users can access their personal computing environment from anywhere.
- **Anywhere, Anytime Information:** The concept that information can be retrieved at any time and from any place.
- **Global Service Portability:** Services that can be accessed across different geographical locations without constraints.
- **Ubiquitous Computing:** The integration of computing into everyday objects and environments, making technology seamlessly available.

**Key Aspects of Mobile Computing:**
- **User Mobility:** Refers to the ability of users to move freely while remaining connected to the network.
- **Device Mobility/Switching:** The capability of devices to connect to different networks without losing their session.
- **Network Mobility:** The ability to maintain a connection to a network while moving from one location to another.
- **Bearer Mobility:** The support for different types of bearer networks (e.g., Wi-Fi, cellular) to facilitate continuous connectivity.
- **Session Mobility:** The ability to maintain ongoing sessions (like video calls) while switching between networks or devices.

### Limitations of Mobile Computing

**Wireless Limitations:**
- **Communication Bandwidth:** Wireless networks often have limited bandwidth compared to wired connections, which can affect performance and data transmission speeds.
- **Heterogeneity of Fragmented Networks:** Different networks may use various protocols and technologies, leading to compatibility issues and complicating seamless connectivity.

**Mobility Limitations:**
- **Route Breaking:** As users move, network routes may break, leading to interrupted connections and dropped sessions.

**Mobile Device Limitations:**
- **Limited Battery Power:** Mobile devices often have constraints on battery life, affecting their usability, especially during extended use.
- **Limited Computing and Display Capacity:** Mobile devices typically have less processing power and smaller displays compared to desktop computers, which can limit functionality and user experience.

---

# OSI Model Developed

The OSI (Open Systems Interconnection) 1984 model is a framework used to understand how different networking protocols interact. It consists of seven layers, each serving a distinct purpose. It is Developed by International Organization for Standardization (ISO)

**TCP/IP Model:**
- Transmission Control Protocol/ Internet Protocol
- Developed by ARPANET.
- Can be viewed as a simplified version of the OSI model tailored for Internet communications.

| **TCP/IP Model**            | **OSI Model**          | **Description**                                                                      |
| --------------------------- | ---------------------- | ------------------------------------------------------------------------------------ |
| **Application Layer**       | **Application Layer**  | Provides network services directly to user applications (e.g., HTTP, FTP).           |
| ↓                           | **Presentation Layer** | Manages data format translation, encryption, and compression.                        |
| ↓                           | **Session Layer**      | Manages sessions and controls the dialog between applications.                       |
| **Transport Layer**         | **Transport Layer**    | Ensures end-to-end communication, error recovery, and flow control (e.g., TCP, UDP). |
| **Internet Layer**          | **Network Layer**      | Handles packet routing and addressing across multiple networks (e.g., IP).           |
| **Network Interface Layer** | **Data Link Layer**    | Manages physical addressing and node-to-node data transfer (e.g., Ethernet).         |
| ↓                           | **Physical Layer**     | Defines the physical medium and electrical signals for data transmission.            |


*Note:*
- The **TCP/IP model** has 4 layers, whereas the **OSI model** consists of 7 layers..
- The TCP/IP model combines some OSI layers into broader categories (e.g., the Application layer in TCP/IP includes the functionalities of the Application, Presentation, and Session layers in OSI).
- The OSI model is more of a theoretical framework, while the TCP/IP model is a practical implementation used in real-world networking.

### 1. **Physical Layer:**
   - This is the lowest layer of the OSI model, responsible for transmitting raw bits (1s and 0s) over a physical medium, such as cables or radio waves.
   - Converts digital signals into electrical, optical, or radio signals depending on the transmission medium.
     - **Wired Medium:** Converts digital signals into voltage pulses.
     - **Wireless Medium:** Converts digital signals into analog signals for transmission.
   - Also specifies physical characteristics i.e. electrical and mechanical characteristics, such voltage levels, signal timing,  and physical connectors (e.g., cables, switches).
   
   > **Example:** Think of this layer as the actual hardware, like wires and antennas, that transmit data.


### 2. **Data Link Layer:**
   - Responsible for framing groups of bits, node-to-node delivery, and physical addressing (MAC addresses).
	-  Groups bits into frames and adds headers containing MAC (Media Access Control) addresses.
     - **Node-to-Node Delivery:** Ensures reliable communication between directly connected nodes.
     - **Flow Control:** Manages data transmission rates to prevent overwhelming a receiver.
     - **Error Control:** Detects and corrects errors that may occur during transmission.
     - **Access Control:** Manages how multiple devices share the same medium.
     
> **Example:** Consider this layer as a mailman who ensures the delivery of packages (data frames) to the right address within a neighborhood (local network).


### 1. **Network Layer:**
   - Responsible for delivery of packets from the source to the destination across multiple networks, making routing decisions along the way.
    - **Routing:** Determines the best path for data to travel from source to destination, regardless of the physical path.
    - **Logical Addressing:** Uses logical addressing (like IP addresses)  to identify devices on the network, enabling communication across different networks.
    
>**Example:** Think of this layer as a GPS system that finds the best route for a delivery truck to reach its destination, even if it has to pass through several cities.

### 1. **Transport Layer:**
   - This layer ensures the reliable transmission of data segments between devices and manages the flow of information.
	- Provides end-to-end communication, guaranteeing that data is sent and received in the correct order and without errors
    - **Flow Control:** Ensures data is sent at a manageable rate (like prevent a fast sender from overwhelming a slow receiver)
    - **Error Control:** Provides mechanisms for error detection and recovery.
    - **Segmentation and Reassembly:** Divides large messages into smaller segments for transmission and reassembles them at the destination.

>**Example:** Imagine this layer as a delivery service that checks in with the sender and receiver to confirm that packages (data) have arrived safely and on time.


### 1. **Session Layer:**
   - This layer manages sessions, or connections, between applications.
     - **Dialog Control:** Establishes, manages, and terminates connections, allowing applications to communicate.
     - **Synchronization:** Coordinates data exchange, ensuring that data is received in the correct order and at the right times. 
*Note:* The Physical Layer also contributes to synchronization but at the bit level.

>Think of this layer as a conference organizer who schedules meetings (sessions) between different parties and ensures everyone is on the same page.


### 1. **Presentation Layer:**
- prepares data for the application layer, dealing with how data is presented and formatted.
- Deals with the syntax and semantics of the information exchanged between two systems.
     - **Translates data formats** Converts data formats (e.g., from binary to human-readable format i.e. EBCDIC to ASCII).
     - **Encryption/Decryption:** Ensures secure data transmission by encoding messages.
     - **Data Compression:** Reduces the size of data for efficient transmission.
     
> **Example:** Consider this layer as a translator who ensures that everyone speaks the same language and understands the message being conveyed.
### 2. **Application Layer:**
   - This is the topmost layer allow users to interact with network services.
     - Provides protocols and interfaces for applications to communicate over the network (e.g. web browsers, email clients i.e. HTTP, FTP, SMTP).
     - Allows users to access information and services via the network.

> **Example:** Think of this layer as the user interface of an app, where you can view and interact with the content, like browsing the web or sending emails.

### Additional Considerations
**Security Concerns:** Mobile computing introduces unique security challenges, including data privacy, unauthorized access, and secure data transmission.
**Connectivity Issues:** Inconsistent signal strength and coverage can lead to disruptions in service and connectivity challenges.

---
### Effects of Mobility on Protocol Stacks

1. **Physical Layer**:
   - **Transmission Errors**: Mobility increases the likelihood of errors due to signal attenuation, interference, and Doppler effects.
   - **Interface Issues**: Frequent changes in signal strength and quality due to varying environments.

2. **Data Link Layer**:
   - **Media Access**: Dynamic reallocation and deallocation of media access resources are required due to frequent connectivity changes.
   - **Handoffs**: Seamless transitions between access points are necessary to maintain connectivity during mobility.

3. **Network Layer**:
   - **Addressing and Routing**: Mobility requires frequent updates to routing tables and IP address changes, which can lead to increased device activity and delays.

4. **Transport Layer**:
   - **Congestion Control**: Changes in network conditions due to mobility may lead to frequent congestion control mechanism triggers.
   - **Flow Control**: Mobility can cause variability in data flow rates, requiring robust flow control mechanisms.

5. **Application Layer**:
   - **New Applications**: Mobility enables innovative applications like location-based services, augmented reality, and real-time collaboration tools.
   - **Adaptations**: Applications must adapt to varying network conditions and connectivity.

### Benefits of WLAN (Wireless Local Area Network)

1. **Low Implementation Costs**: Eliminates the need for cables, reducing installation and maintenance costs.
2. **Mobility**: Users can access the network while on the move within the coverage area.
3. **Ease of Installation**: Simple and quick setup without the need for extensive physical infrastructure.
4. **Network Expansion**:
   - Adding new devices is seamless and doesn't require additional cabling.
5. **Scalability**: Supports various topologies such as bus, mesh, and star, allowing flexible network design.
6. **Reliability**: Wireless networks are less prone to issues like cable damage, enhancing uptime and dependability.
7. **High User-to-Install Base Ratio**: Accommodates more users per unit infrastructure compared to traditional wired setups.
8. **Use of ISM Bands**: Operates on unlicensed Industrial, Scientific, and Medical (ISM) bands, making it cost-effective and globally usable.
---
# Cellular System.
### Cellular Network Components

In a cellular network, various components work together to ensure communication, authentication, and efficient resource management. Below are the key components and their roles:

#### 1. **SIM (Subscriber Identity Module) Components:**
A SIM card contains essential information that allows a mobile device to connect to a network. Key components include:
- **IMSI (International Mobile Subscriber Identity):** A unique identifier assigned to each subscriber. It's used by the network to identify and authenticate the user.
- **Authentication Key (Ki):** A secret key used for authentication between the mobile device and the network.
- **Voice Privacy Key Generation:** Used to encrypt voice data for secure communication.
- **PIN (Personal Identification Number)/PUK (Personal Unblocking Key):** Codes for securing access to the SIM card and unlocking it in case it's locked.

#### 2. **Base Station Subsystem (BSS):**
- **BSC (Base Station Controller):** Manages the allocation, deallocation, and handoff of resources, such as radio channels, for connected mobile devices.
- **BTS (Base Transceiver Station):** The radio equipment that communicates directly with mobile devices.

#### 3. **Mobile Switching Center (MSC):**
- **Role:** The MSC is the central component in a cellular network responsible for routing voice calls and data, handling **handoffs** (switching the mobile from one BTS to another), and managing **roaming**.
- **Functions:**
  - **Billing and Accounting:** Tracks call durations, data usage, and other metrics for customer billing.
  - **Echo Cancellation:** Eliminates echo during voice calls to improve quality.
  - **Paging and Alerting:** Finds and notifies mobile devices about incoming calls or messages.
  - **Integration with HLR, VLR, EIR, AUC:** Connects with other databases to manage mobile user data, services, and security.

#### 4. **HLR (Home Location Register):**
- **Role:** A permanent database that stores the details of subscribers who belong to a particular network.
- **Functions:**
  - **MSRN (Mobile Station Roaming Number):** Temporary identifier used to route calls to a mobile device when it is roaming.
  - **IMSI Management:** Stores the IMSI and other subscription details.
  - **Service Management:** Maintains information about the services (e.g., data plans, call forwarding) that the subscriber has access to.

#### 5. **VLR (Visitor Location Register):**
- **Role:** A temporary database that stores information about subscribers currently roaming within the coverage area of a particular MSC.
- **Functions:**
  - **Temporary Info Storage:** Stores location and other details of subscribers while they are in the area controlled by the MSC.
  - **Authentication:** Works in conjunction with the HLR to authenticate users in the area.

#### 6. **EIR (Equipment Identity Register):**
- **Role:** A database used to identify mobile devices and manage their status based on their IMEI (International Mobile Equipment Identity) numbers.
- **Functions:**
  - **White List:** Contains IMEI numbers of devices that are fully authorized for use and have no reported issues.
  - **Grey List:** Stores IMEI numbers of devices that are under observation due to faults or service issues but are not completely blocked.
  - **Black List:** Contains IMEI numbers of devices that are barred from accessing the network due to theft, fraud, or other violations.

### 7. **AUC (Authentication Center)**:

- **Definition**: The **AUC** is a component that ensures security and user authentication in the cellular network. It works in conjunction with the **HLR**.
- **Function**:
    - The AUC generates and verifies **authentication data** for mobile subscribers to protect against fraud and unauthorized access.
    - It uses a combination of the subscriber’s identity (IMSI), a **random number**, and a **security key** to authenticate the mobile device.
    - When a mobile device tries to register with the network, the AUC validates the device's credentials.
- **Example**: The AUC ensures that only authorized users can connect to the network and make calls or use data services.

---
### Additional Terms and Concepts:

- **IMSI (International Mobile Subscriber Identity):** A globally unique identifier stored on the SIM card to identify the subscriber.
- **MSRN (Mobile Station Roaming Number):** A temporary number assigned to a mobile station (phone) while roaming, used for routing calls.
- **IMEI (International Mobile Equipment Identity):** A unique identifier for mobile devices, used to track and identify devices on the network.

---

### Summary of Network Management:

- **BSS (Base Station Subsystem):** Handles communication with mobile devices and allocates resources.
- **MSC (Mobile Switching Center):** Responsible for call routing, roaming, billing, and paging.
- **HLR (Home Location Register):** Stores permanent subscriber information.
- **VLR (Visitor Location Register):** Temporarily stores information about roaming users.
- **EIR (Equipment Identity Register):** Manages the authorization status of mobile devices based on their IMEI numbers.

---
