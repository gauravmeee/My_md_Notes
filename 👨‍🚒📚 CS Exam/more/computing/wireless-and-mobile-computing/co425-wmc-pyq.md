
---

# Q1. Show the various subsytems of the Cellular System architecture. Differentiate between HLR and VLR. Explain the working of Mobile call termination and location updation in cellular system
>2023 MTE

### Cellular System Architecture: Subsystems

The architecture of a cellular system, such as GSM (Global System for Mobile Communications), is divided into several subsystems. These subsystems handle communication, mobility management, and network services. Below are the major subsystems in a typical cellular system:
#### 1. **Mobile Station (MS)**
   - **Components**: Mobile Equipment (ME) and Subscriber Identity Module (SIM).
   - **Function**: The MS allows the user to access the network. It transmits and receives signals, manages user identity via the SIM, and handles encryption for secure communication.
#### 2. **Base Station Subsystem (BSS)**
   - **Components**: Base Transceiver Station (BTS) and Base Station Controller (BSC).
   - **Function**:
     - **BTS**: Handles the communication with the mobile station via radio waves. It contains antennas and radio transceivers for signal transmission and reception.
     - **BSC**: Controls multiple BTSs, manages radio resource allocation, and handles handover between BTSs within its area.
#### 3. **Network and Switching Subsystem (NSS)**
   - **Components**: Mobile Switching Center (MSC), Home Location Register (HLR), Visitor Location Register (VLR), Authentication Center (AUC), Equipment Identity Register (EIR).
   - **Function**:
     - **MSC**: The core switching system that handles call routing, SMS, and mobility management.
     - **HLR**: Central database storing permanent information about subscribers, such as phone numbers, services subscribed, and the subscriber’s current location.
     - **VLR**: Temporary database containing information about subscribers currently roaming in the area covered by the MSC.
     - **AUC**: Ensures security by storing authentication keys for verifying the identity of the user.
     - **EIR**: Database that maintains information about valid and blacklisted mobile devices.
#### 4. **Operation and Support Subsystem (OSS)**
   - **Function**: Manages network operations, including fault detection, performance monitoring, and system configuration. It also helps with billing and administrative tasks.

### Difference Between HLR and VLR

| **Home Location Register (HLR)**                             | **Visitor Location Register (VLR)**                              |
|--------------------------------------------------------------|------------------------------------------------------------------|
| Centralized database that stores permanent subscriber information. | Temporary database that stores information about subscribers currently roaming in its area. |
| Maintains a record of the subscriber’s profile (e.g., IMSI, MSISDN, services). | Maintains the current location of the roaming subscriber within the area controlled by the MSC. |
| One HLR typically serves an entire cellular network.          | Each MSC is associated with a VLR to manage roaming subscribers in its area. |
| The HLR is queried when a subscriber roams into a new location to provide details to the VLR. | The VLR updates its records when a subscriber enters or leaves its area. |
| Responsible for managing the user’s subscription information and permanent location. | Manages temporary, location-specific data for fast access and call setup while roaming. |

### Mobile Call Termination in a Cellular System

Mobile call termination refers to the process of delivering an incoming call to a mobile subscriber. The key steps involved are:

1. **Call Initiation**:
   - A call is made to a mobile subscriber. The Public Switched Telephone Network (PSTN) or another mobile network sends the call to the Gateway Mobile Switching Center (GMSC) of the mobile subscriber’s network.

2. **Location Query**:
   - The GMSC queries the **HLR** to find the current location of the called mobile subscriber.
   - The HLR provides the address of the **VLR** associated with the subscriber’s current MSC (if the subscriber is roaming).

3. **Call Routing**:
   - The GMSC forwards the call to the **MSC** controlling the area where the mobile user is located, as provided by the HLR.

4. **VLR Query and Paging**:
   - The **MSC** queries the **VLR** to retrieve detailed information about the subscriber and their current BTS location.
   - The MSC then initiates a **paging** process, sending a signal to all **BTSs** in the area to locate the mobile device.

5. **Call Setup**:
   - Once the mobile device responds to the paging signal, the call is set up through the **BTS**, **BSC**, and **MSC**, and the mobile subscriber receives the call.

6. **Call Termination**:
   - The connection between the caller and the mobile subscriber is established, and the conversation can proceed.

### Location Update in a Cellular System

Location update refers to the process of tracking the subscriber’s current location as they move between different areas of the network. The key steps involved are:

1. **Mobile Movement Detection**:
   - When a subscriber moves into a new area controlled by a different **MSC**, the mobile station detects this through the signals of the new **BTS**.

2. **VLR Registration**:
   - The mobile station sends a **location update request** to the new MSC.
   - The MSC checks whether the subscriber is already registered in its **VLR**. If not, the MSC sends a request to the subscriber’s **HLR** to retrieve their profile information.

3. **HLR Notification**:
   - The **HLR** updates its record with the new MSC location of the subscriber and informs the old MSC (if any) to remove the subscriber’s information from its VLR.

4. **VLR Update**:
   - The new MSC’s **VLR** stores the subscriber’s profile and temporary information such as their location in the new area.

5. **Location Update Acknowledgment**:
   - Once the location update process is complete, the mobile station is informed, and the network is now aware of the subscriber’s new location.

This allows the network to route incoming calls or services efficiently based on the subscriber’s latest position.

---
# Q2. Why do we need different MAC frame format for mobile environment in comparison of wired network? Explain the MAC frame format of IEEE 802.11
>2023 MTE

### Need for Different MAC Frame Format in Mobile (Wireless) Environment vs. Wired Network

The **Mobile (Wireless) environment** and **Wired networks** present fundamentally different challenges in terms of communication. As a result, the **Medium Access Control (MAC) frame format** used for mobile (wireless) communication, such as in **IEEE 802.11 (Wi-Fi)**, differs from that of wired networks (like Ethernet). Some key reasons are:

1. **Medium Characteristics**:
   - **Wired Network**: The medium (physical cable) is reliable, controlled, and has minimal interference. Packet collisions and data loss are rare due to the stable nature of the medium.
   - **Wireless Network**: The wireless medium is shared and unreliable due to signal fading, interference, noise, and collisions. Thus, more ==robust error control and recovery mechanisms== are required in wireless communication.

2. **Mobility**:
   - **Wired Network**: Devices are stationary, so there is no need to account for handovers, roaming, or changes in connection.
   - **Wireless Network**: Devices are mobile, ==requiring additional fields in the MAC frame== to support handover, connection to multiple access points (APs), and mobility management.

3. **Collision Avoidance**:
   - **Wired Network**: Uses **CSMA/CD** (Carrier Sense Multiple Access with Collision Detection) to detect and manage collisions.
   - **Wireless Network**: Uses **CSMA/CA** (Carrier Sense Multiple Access with Collision Avoidance) because ==collisions are harder to detect in wireless networks due to the "hidden node" problem.== Thus, wireless MAC frames include additional fields for acknowledgment and control.

4. **Power Efficiency**:
   - **Wired Network**: Power consumption is not a primary concern.
   - **Wireless Network**: Power efficiency is critical since mobile devices operate on battery power. The MAC frame format for wireless networks must support features like ==power-saving modes==, which are absent in wired MAC frames.

5. **Addressing Scheme**:
   - **Wired Network**: Typically only uses **2 addresses** (source and destination) in the MAC frame.
   - **Wireless Network**: Requires up to ==**4 addresses** (source, destination, transmitting AP, and receiving AP)== to handle communication between mobile devices and multiple APs.

### MAC Frame Format of IEEE 802.11 (Wi-Fi)

The **IEEE 802.11 MAC frame format** is specifically designed for wireless communication and addresses the unique challenges mentioned above. It has several fields that enable robust wireless communication, handover management, and collision avoidance. Below is a breakdown of the key components of the IEEE 802.11 MAC frame:

#### 1. **Frame Control (2 bytes)**:
   - This field contains control information that defines the type of frame (data, control, or management) and other parameters for managing the communication.
   - **Subfields include**:
     - **Protocol version**: Indicates the protocol version.
     - **Type/Subtype**: Defines the type of frame (control, data, or management).
     - **To DS/From DS**: Indicates if the frame is going to or from the distribution system (DS) for multi-hop communication.
     - **More fragments**: Specifies if the frame is fragmented.
     - **Retry**: Indicates if the frame is a retransmission.
     - **Power management**: Indicates the power state of the sender (active or sleep mode).
     - **More data**: Indicates that more data is buffered for the recipient.
     - **Protected frame**: Indicates whether the frame is encrypted.
     - **Order**: Specifies if the frame is being delivered in sequence.

#### 2. **Duration/ID (2 bytes)**:
   - Specifies the duration of time (in microseconds) the channel is reserved for transmission, or an identifier if the frame is used in power-saving mode.
   - Used for network allocation vectors (NAVs), ensuring that other devices know when the medium will be in use.

#### 3. **Address Fields (6 bytes each)**:
   - **Address 1 (Receiver Address)**: The MAC address of the receiving station or the Access Point (AP).
   - **Address 2 (Transmitter Address)**: The MAC address of the transmitting station or AP.
   - **Address 3 (BSSID)**: The MAC address of the AP if it is involved in the transmission, or the destination if it is going through an AP.
   - **Address 4** (optional, only used in certain types of frames): Used in wireless distribution system (WDS) mode, where frames are forwarded between multiple APs.
#### 4. **Sequence Control (2 bytes)**:
   - Contains the sequence number of the frame to help the receiving station reorder frames and detect duplicates.
#### 5. **Frame Body (0-2304 bytes)**:
   - The actual data being transmitted (payload). It can include user data or management information like authentication and association requests.
#### 6. **Frame Check Sequence (FCS) (4 bytes)**:
   - Used for error detection, ensuring that the data was transmitted without corruption. The FCS is a CRC (Cyclic Redundancy Check) value calculated over the entire frame.
### Detailed Structure of IEEE 802.11 MAC Frame Format

| **Field**                      | **Size**     | **Description**                                                                                  |
| ------------------------------ | ------------ | ------------------------------------------------------------------------------------------------ |
| **Frame Control**              | 2 bytes      | Identifies ==frame type== (data/control/management), flags for retry, ==power management==, etc. |
| **Duration/ID**                | 2 bytes      | Specifies how long the medium will be occupied or used as an ID in power-saving mode.            |
| **Address 1**                  | 6 bytes      | Receiver address (MAC address of the device or AP).                                              |
| **Address 2**                  | 6 bytes      | Transmitter address (MAC address of the device or AP).                                           |
| **Address 3**                  | 6 bytes      | BSSID (Basic Service Set Identifier, which is usually the MAC address of the AP).                |
| **Sequence Control**           | 2 bytes      | Sequence number and fragment number. Helps manage retransmissions and fragmentation.             |
| **Address 4** (Optional)       | 6 bytes      | Used in WDS mode for forwarding frames between APs.                                              |
| **Frame Body**                 | 0-2304 bytes | Data payload (varies depending on frame type).                                                   |
| **FCS (Frame Check Sequence)** | 4 bytes      | Error detection to ensure data integrity.                                                        |
### Conclusion

The MAC frame format for wireless networks (IEEE 802.11) is more complex than that of wired networks (such as Ethernet) due to the added challenges of mobility, unreliable medium, power management, and addressing schemes. Features such as power management, error recovery, and additional address fields allow IEEE 802.11 to handle the dynamic nature of wireless communication effectively.

---
# Q3. How CSMA/CD is different from CSMA/CA? Explain the implementation of CSMA/CA with RTS/CTS. Is it possible to solve hidden and exposed node problems using CSMA/CA with RTS/CTS?
> 2023 MTE

### Difference between **CSMA/CD** and **CSMA/CA**

**CSMA/CD (Carrier Sense Multiple Access with Collision Detection)** and **CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)** are both protocols designed for handling how multiple devices share a communication medium, but they differ in their approach and usage environment. Here's a comparison:

| **Aspect**                  | **CSMA/CD**                                     | **CSMA/CA**                                       |
|-----------------------------|-------------------------------------------------|---------------------------------------------------|
| **Full Form**               | Carrier Sense Multiple Access with Collision Detection | Carrier Sense Multiple Access with Collision Avoidance |
| **Usage Environment**       | Used in **wired networks** (e.g., Ethernet).     | Used in **wireless networks** (e.g., Wi-Fi, IEEE 802.11). |
| **Mechanism**               | Devices detect collisions after they occur and take corrective action. | Devices try to **avoid** collisions before they happen by signaling and waiting for acknowledgments. |
| **Collision Handling**      | If a collision occurs, the devices involved stop transmission, wait for a random backoff time, and retransmit. | Devices use techniques like **RTS/CTS (Request to Send/Clear to Send)** to avoid collisions before starting transmission. |
| **Efficiency**              | Works well in wired networks because collisions can be detected easily. | Designed for wireless networks, where detecting collisions is difficult due to the "hidden node" problem. |
| **Collision Detection**     | Yes, devices detect and respond to collisions.  | No, devices avoid collisions by using proactive strategies. |
| **Approach**                | **Reactive**: Collisions are detected after they happen. | **Proactive**: Devices attempt to avoid collisions before they happen. |

### **CSMA/CA** Implementation with **RTS/CTS**

CSMA/CA, used in wireless networks, cannot detect collisions like CSMA/CD in wired networks. Instead, it employs **collision avoidance** strategies. One common implementation of CSMA/CA involves the **RTS/CTS (Request to Send/Clear to Send)** mechanism, which helps to prevent collisions, particularly in scenarios involving hidden nodes.

#### Step-by-Step Working of CSMA/CA with RTS/CTS:

1. **Station Senses the Channel**: 
   - Before transmitting data, the device (Station A) first **listens** to the channel to check if it is free or busy.
   
2. **RTS (Request to Send)**:
   - If the channel is free, Station A sends a **Request to Send (RTS)** frame to the receiving station (Station B). This RTS frame contains information about the data length and the time required for transmission.

3. **CTS (Clear to Send)**:
   - Upon receiving the RTS, Station B responds with a **Clear to Send (CTS)** frame if it is ready to receive the data. This CTS frame serves as a signal to Station A that the transmission can proceed. Importantly, the CTS frame also informs other nearby stations that the channel will be used for a certain period.

4. **Data Transmission**:
   - After receiving the CTS frame, Station A starts transmitting the data to Station B.

5. **ACK (Acknowledgment)**:
   - Once Station B successfully receives the data, it sends an **ACK (Acknowledgment)** frame to Station A to confirm that the data was received without errors.

6. **Backoff and Retransmission**:
   - If Station A does not receive a CTS or ACK frame within a specified timeout period, it assumes that a collision has occurred and uses a backoff mechanism (random wait time) before retrying.

### Hidden and Exposed Node Problems

In wireless networks, **hidden node** and **exposed node** problems affect communication reliability. Let's explain these and whether **CSMA/CA with RTS/CTS** can help:

#### 1. **Hidden Node Problem**:
   - **Problem**: A hidden node is a device that is out of range of some other devices but within range of the receiving device. This leads to collisions because the hidden device cannot detect ongoing transmissions from the other devices.
     - Example: Station A is communicating with Station B, but Station C is out of range of Station A. C does not know about the ongoing transmission between A and B, so it may transmit, causing a collision at Station B.
   - **Solution via RTS/CTS**: 
     - The RTS/CTS mechanism solves the hidden node problem. When Station A sends an RTS, and Station B responds with a CTS, the CTS is broadcast to nearby stations, including the hidden Station C. Upon hearing the CTS, Station C realizes that Station B is busy and refrains from transmitting, thereby avoiding a collision.

#### 2. **Exposed Node Problem**:
   - **Problem**: An exposed node is a device that refrains from transmitting because it mistakenly thinks that the channel is busy, even though its transmission would not cause interference.
     - Example: Station C wants to send data to Station D. However, Station C hears Station A transmitting to Station B and assumes it should not transmit. In reality, Station C's transmission would not interfere with Station A's transmission because Station D is far enough away.
   - **Solution via RTS/CTS**:
     - The RTS/CTS mechanism does **not fully solve** the exposed node problem. In the exposed node scenario, Station C could still detect ongoing communication between A and B and refrain from transmitting, even though it wouldn't cause a collision. Since RTS/CTS mainly addresses hidden nodes, exposed nodes may still unnecessarily delay their transmissions.

### Conclusion

- **CSMA/CD** is suitable for **wired** networks where collisions can be easily detected, while **CSMA/CA** is designed for **wireless** networks, focusing on **collision avoidance**.
- The **RTS/CTS** mechanism in CSMA/CA effectively **solves the hidden node problem** by informing nearby stations of ongoing transmissions. However, it is less effective against the **exposed node problem**, which still results in some inefficiencies in network usage.

---
# Q4. What is WAP? Discuss the Components of the wireless application protocol (WAP) architecture ❌
> 2023 MTE

### What is **WAP (Wireless Application Protocol)?**

**WAP (Wireless Application Protocol)** is a technical standard that provides a framework for accessing internet services on mobile and wireless devices. It was primarily designed to enable devices with limited processing power, memory, and display (such as early mobile phones) to access internet services, email, and other online applications. WAP was widely used before the advent of modern mobile operating systems like Android and iOS.

### Key Features of WAP:
1. **Mobile-Friendly**: Designed for mobile devices with smaller screens and limited resources.
2. **Lightweight Protocol**: Uses a simplified protocol stack compared to traditional web protocols to accommodate the lower bandwidth and processing power of mobile devices.
3. **Supports Wireless Networks**: Works over various wireless networks like GSM, CDMA, and GPRS.
4. **Text-Based Pages**: Often uses WML (Wireless Markup Language), a simplified version of HTML, to display content optimized for mobile devices.

### Components of **WAP Architecture**

The WAP architecture is based on a layered design similar to the OSI model. Each layer provides specific services, and these layers work together to offer internet access on wireless devices.

#### 1. **WAE (Wireless Application Environment)**
   - **Purpose**: Provides a platform for executing applications and displaying content.
   - **Components**:
     - **WML (Wireless Markup Language)**: A markup language similar to HTML but designed for small-screen devices. It formats content to be displayed on mobile devices.
     - **WMLScript**: A scripting language that allows logic and interactivity on WAP-enabled devices, similar to JavaScript in web browsers.
     - **WTA (Wireless Telephony Application)**: Provides telephony services such as call control and messaging.
   - **Function**: WAE defines how content is presented to users and how applications operate on wireless devices.

#### 2. **WSP (Wireless Session Protocol)**
   - **Purpose**: Manages communication between the client (mobile device) and the server.
   - **Function**: Establishes and controls the connection session. It operates similarly to HTTP in the web world, ensuring smooth data transfer between client and server.

#### 3. **WTP (Wireless Transaction Protocol)**
   - **Purpose**: Provides reliable and efficient transaction services over wireless networks.
   - **Function**: Facilitates reliable data transmission by handling message acknowledgments and retransmissions when necessary. It can be used for both connectionless (like UDP) and connection-oriented (like TCP) transactions.

#### 4. **WDP (Wireless Datagram Protocol)**
   - **Purpose**: Provides an interface to the underlying network, offering transport services to the higher layers.
   - **Function**: Acts as a common protocol that adapts to different wireless networks (such as GSM, CDMA, GPRS). It ensures that data is transferred efficiently, regardless of the network technology.

#### 5. **Bearer Networks**
   - **Purpose**: Provides the physical and data-link layers for communication.
   - **Function**: These are the actual wireless networks, such as GSM, CDMA, GPRS, or 3G, that carry the data. They provide the basic connectivity for mobile devices to communicate over the air.

### WAP Gateway/Proxy

In addition to the protocol stack, the **WAP Gateway** or **WAP Proxy** is a crucial component of the WAP architecture. It acts as an intermediary between the mobile device and the internet.

- **Function**: The WAP Gateway translates WAP requests from the mobile device into HTTP requests for the internet and vice versa. It compresses and optimizes the content for mobile devices and handles the protocol conversions between WAP and the traditional web.

### How WAP Works (Overview of Data Flow):
1. **Request**: The mobile device sends a request to the WAP Gateway using WML or WMLScript. The request uses the WSP/WTP protocols.
2. **Translation**: The WAP Gateway converts the WSP request into an HTTP request and forwards it to the appropriate web server on the internet.
3. **Response**: The web server processes the request and sends an HTTP response back to the WAP Gateway.
4. **Rendering**: The WAP Gateway converts the HTTP response into WML format and sends it back to the mobile device for display.

### Diagram of WAP Architecture:

Here’s a basic representation of how WAP components interact:

```
  +----------------------------------------+
  |     Application Servers (HTTP/WWW)     |
  +----------------------------------------+
                    |
             (HTTP Conversion)
                    |
  +----------------------------------------+
  |              WAP Gateway               |
  +----------------------------------------+
                    |
                (WAP Stack)
                    |
  +----------------------------------------+
  |          Mobile Network (Bearer)       |
  +----------------------------------------+
                    |
           (WDP, WTP, WSP, WAE Layers)
                    |
  +----------------------------------------+
  |         Wireless Device (Client)       |
  +----------------------------------------+
```

### Conclusion

The **WAP architecture** is a multi-layered design that efficiently enables mobile devices with limited resources to access internet-based services. The main components like WAE, WSP, WTP, WDP, and Bearer Networks work together to ensure that data is transferred seamlessly between the client and the server. The introduction of a WAP Gateway allows for communication between mobile devices and traditional web servers, enabling services such as email, web browsing, and online applications for wireless devices.

---
# Q5. Explain various modulation techniques of digital to analog and analog to digital and modulate data stream 11001001001011100100 using 16-QAM
>2023 MTE
### Modulation Techniques: Digital to Analog and Analog to Digital

#### 1. **Digital to Analog Modulation Techniques:**
   Digital to analog modulation involves converting a digital signal into an analog signal for transmission over an analog medium. There are several techniques used for this process, which include:
   
   **i. Amplitude Shift Keying (ASK):**
   - **Principle**: The amplitude of the carrier signal is varied according to the binary data.
   - **How it works**: A binary '1' is represented by one amplitude level, and binary '0' by another amplitude level (usually 0).
   - **Usage**: ASK is used in low-frequency transmission, such as in RFID systems.
   
   **ii. Frequency Shift Keying (FSK):**
   - **Principle**: The frequency of the carrier signal is varied to represent digital data.
   - **How it works**: Binary '1' and '0' are represented by different frequencies.
   - **Usage**: FSK is widely used in modems and radio systems.
   
   **iii. Phase Shift Keying (PSK):**
   - **Principle**: The phase of the carrier signal is varied to represent binary data.
   - **How it works**: A fixed number of phases (e.g., 2 or 4) are used to represent binary data. The simplest form, BPSK, uses two phases.
   - **Usage**: PSK is used in Wi-Fi (802.11b), satellite communication, and RFID.

   **iv. Quadrature Amplitude Modulation (QAM):**
   - **Principle**: Both the amplitude and the phase of the carrier signal are varied to represent digital data.
   - **How it works**: Multiple levels of both amplitude and phase changes are used to represent more bits per symbol.
   - **Usage**: 16-QAM, 64-QAM, and 256-QAM are widely used in modern telecommunications (e.g., LTE, Wi-Fi).

#### 2. **Analog to Digital Modulation Techniques:**
   Analog to digital modulation refers to the conversion of an analog signal into a digital signal. The key techniques are:

   **i. Pulse Code Modulation (PCM):**
   - **Principle**: An analog signal is sampled at regular intervals and then quantized into discrete values.
   - **How it works**: The amplitude of the analog signal is converted into a binary code by measuring its value at regular intervals.
   - **Usage**: PCM is used in digital telephony and audio transmission (e.g., CDs, VoIP).

   **ii. Delta Modulation (DM):**
   - **Principle**: Instead of encoding absolute values, DM encodes the difference between successive samples.
   - **How it works**: It encodes the difference between two successive samples and represents it in binary format.
   - **Usage**: DM is used in low-bandwidth applications like speech coding.

   **iii. Adaptive Delta Modulation (ADM):**
   - **Principle**: A variation of DM where the step size is dynamically adjusted based on the change in the signal.
   - **How it works**: ADM varies the step size depending on the slope of the input signal.
   - **Usage**: ADM is more efficient than DM and is used in speech compression.

### Modulation of Data Stream using **16-QAM**

**Quadrature Amplitude Modulation (QAM)** is a modulation scheme that varies both the amplitude and the phase of the carrier signal to represent digital data. In **16-QAM**, 16 distinct combinations of amplitude and phase are used to encode 4 bits per symbol.

Each of the 16 possible states represents 4 bits of binary data. These states are represented in a constellation diagram where:
- The X-axis represents in-phase components.
- The Y-axis represents quadrature-phase components.
- Each state is a point on the diagram corresponding to a specific amplitude and phase.

#### **Steps to Modulate a Data Stream (e.g., 11001001001011100100) using 16-QAM:**

1. **Convert the Binary Data Stream into 4-Bit Symbols**:
   Since 16-QAM represents 4 bits per symbol, split the binary data into groups of 4 bits:
   ```
   1100 1001 0010 1110 0100
   ```
   
2. **Map the 4-Bit Symbols to 16-QAM Constellation Points**:
   Each 4-bit sequence corresponds to a point on the 16-QAM constellation. An example mapping (assuming Gray coding) might look like:
   
   - **1100** → Point 1: Amplitude (2, 2)
   - **1001** → Point 2: Amplitude (1, -2)
   - **0010** → Point 3: Amplitude (-1, 1)
   - **1110** → Point 4: Amplitude (3, 1)
   - **0100** → Point 5: Amplitude (-2, -1)
   
   (Note: Exact mapping can vary depending on the specific implementation.)

3. **Generate the Modulated Signal**:
   For each group of 4 bits, the modulator generates a carrier signal with the corresponding amplitude and phase shift. For example:
   
   - For **1100**, the modulator generates a signal with amplitude and phase corresponding to point 1 in the constellation (e.g., In-phase = 2, Quadrature-phase = 2).
   - Similarly, the modulator generates signals for each of the remaining 4-bit sequences.

### Solving Hidden and Exposed Node Problems

In 16-QAM, modulation handles the transmission of data using both amplitude and phase shifts, but issues like the hidden and exposed node problem are addressed at the **Medium Access Control (MAC)** level rather than the modulation scheme level.

---

# Q6. What is GPRS? Explain its architecture in details and also explain authentication and ciphering in GSM
> 2023 MTE
### General Packet Radio Service (GPRS)

**GPRS (General Packet Radio Service)** is a ==packet-oriented mobile data standard== used in 2G and 3G cellular communication systems. It enables users to transmit data in packets, which is much more ==efficient than the circuit-switched== data transmission used in earlier systems like GSM.

#### Key Features of GPRS:
- It supports data rates from ==56 kbps up to 114 kbps==.
- It allows for continuous internet access, i.e., always-on connectivity.
- It is used for services like internet browsing, multimedia messaging (MMS), email, and push-to-talk.

### GPRS Architecture:

GPRS is an ==overlay network on top of the existing GSM network== and introduces several new network elements to handle packet-switched services. The key components of the GPRS architecture are:

#### 1. **Mobile Station (MS):**
   The user’s mobile device (phone, tablet, or modem) that supports GPRS. It connects to the GPRS network through the GSM base station and uses IP-based protocols to access the internet.

#### 2. **Base Station Subsystem (BSS):**
   The BSS is responsible for the radio communication between the mobile station and the network. It consists of:
   - **Base Transceiver Station (BTS)**: Manages radio channels.
   - **Base Station Controller (BSC)**: Manages the radio resources and controls multiple BTSs.

#### 3. **Serving GPRS Support Node (SGSN):**
   The SGSN is a critical component in the GPRS architecture that:
   - Tracks the location of the mobile station within its service area.
   - Handles data routing, delivery, and mobility management.
   - Manages user authentication, charging, and billing.

#### 4. **Gateway GPRS Support Node (GGSN):**
   The GGSN acts as an ==interface between the GPRS network and external packet-switched== networks like the internet. Its functions include:
   - Converting GPRS packets into IP packets for external networks.
   - Assigning IP addresses to mobile devices.
   - Handling data tunneling between the GGSN and SGSN using the GPRS Tunneling Protocol (GTP).

#### 5. **Packet Control Unit (PCU):**
   The PCU is responsible for managing the packet-switched data on the air interface between the mobile device and the network. It ensures that radio resources are shared efficiently.

#### 6. **Home Location Register (HLR):**
   The HLR stores permanent subscriber data and GPRS subscription information. It is used to authenticate users and provide their profile to the SGSN.

#### 7. **Authentication Centre (AUC):**
   The AUC provides encryption keys for the mobile device and ensures secure transmission over the GPRS network.

#### 8. **Equipment Identity Register (EIR):**
   The EIR checks the validity of the mobile equipment by verifying the device’s International Mobile Equipment Identity (IMEI). It helps prevent the use of stolen or unauthorized devices.

### GPRS Packet Flow:

1. When a user requests data (e.g., opening a website), the MS sends the request to the **BTS**, which forwards it to the **SGSN** via the **BSC**.
2. The **SGSN** routes the request to the **GGSN**, which is connected to the external network (like the internet).
3. The GGSN forwards the request to the internet, and the requested data is transmitted back through the same path to the MS.

### Authentication and Ciphering in GSM

In GSM networks, **authentication** and **ciphering** are used to ensure the security of user data and prevent unauthorized access.

#### 1. **Authentication in GSM:**
   Authentication ensures that the user accessing the network is legitimate and not an imposter. GSM uses a challenge-response method for user authentication. Here's how it works:

   - When the **Mobile Station (MS)** connects to the network, the **SGSN** or **MSC** sends a random number (**RAND**) to the MS.
   - The MS uses this RAND number, along with its secret **Authentication Key (Ki)**, to compute a response (**SRES**) using the **A3 algorithm**.
   - The **SGSN** or **MSC** performs the same computation using the subscriber's Ki stored in the **Authentication Centre (AUC)** and compares the result with the SRES received from the MS.
   - If the two values match, the authentication is successful, and the user is granted access to the network.

   This ensures that even if the communication is intercepted, the secret key (Ki) remains unknown to the attacker.

#### 2. **Ciphering in GSM:**
   Ciphering is used to encrypt the data sent between the mobile station and the network to ensure privacy. The ciphering process works as follows:

   - Once the authentication process is successful, the network generates a **ciphering key (Kc)**.
   - Both the **MS** and the **network** (SGSN or MSC) use this Kc to encrypt and decrypt the data using the **A5 algorithm**.
   - All subsequent communication between the mobile and the network is encrypted using this key, ensuring that the data cannot be read if intercepted.

### GPRS and GSM Security:

- **Authentication**: GPRS uses the same authentication procedure as GSM. The **RAND** challenge is sent to the MS, and the **SRES** response is computed using the **Ki**.
- **Ciphering**: Like GSM, GPRS encrypts data using a ciphering key derived during the authentication process, ensuring secure packet-switched communication.
---
---
# Q1. Describe the Protocol architecture of WLAN IEEE 802.11 standard and explain the MAC frame format of MAC sub Layer.
>2018 MTE
### A) Protocol Architecture of WLAN IEEE 802.11 Standard

The **IEEE 802.11 standard** defines the protocol architecture for **Wireless Local Area Networks (WLAN)**, which allows wireless communication between devices over short distances. It includes several sub-layers and protocols to ensure effective communication, security, and quality of service (QoS) over wireless channels. The standard specifies both **Physical Layer (PHY)** and **Data Link Layer (DLL)** functionalities, with particular attention to the **Medium Access Control (MAC)** sublayer.

#### 1. **Protocol Stack of IEEE 802.11:**
The protocol architecture of IEEE 802.11 is organized into several layers and sublayers:

##### a) **Physical Layer (PHY)**
- The PHY layer is responsible for the transmission and reception of data over the wireless medium.
- It defines modulation, demodulation, encoding, decoding, and the wireless channel characteristics.
- IEEE 802.11 supports different physical layer implementations, such as DSSS (Direct Sequence Spread Spectrum), OFDM (Orthogonal Frequency Division Multiplexing), and others.
  
The Physical Layer is divided into two sublayers:
- **Physical Medium Dependent (PMD)**: Defines the method for wireless transmission (e.g., modulation techniques).
- **Physical Layer Convergence Protocol (PLCP)**: Responsible for framing, synchronization, and data encoding.

##### b) **Data Link Layer (DLL)**

The DLL consists of two sublayers:

**i) Logical Link Control (LLC)**:
   - The LLC provides the interface between the network layer and the MAC layer.
   - It is responsible for multiplexing protocols over the MAC layer and providing flow control and error control.
   - LLC in IEEE 802.11 is based on the IEEE 802.2 standard.

**ii) Medium Access Control (MAC) Sub-layer**:
   - The MAC sublayer governs how devices access the shared wireless medium.
   - It includes mechanisms such as **Carrier Sense Multiple Access with Collision Avoidance (CSMA/CA)** to avoid collisions and ensure reliable communication.
   - It manages coordination functions, packet framing, fragmentation, and reassembly.

### 2. MAC Frame Format of IEEE 802.11 MAC Sublayer

The MAC frame format defines how data is organized and transmitted at the MAC sublayer in IEEE 802.11 networks. The MAC frame includes several fields, each serving specific purposes such as addressing, control, data transmission, and error handling.

#### Key Fields in the MAC Frame:

1. **Frame Control**:
   - 16 bits used to define the type of frame, control information, and protocol version.
   - Contains subfields such as protocol version, type (management, control, data), subtype, and flags (e.g., more fragments, retry, power management, etc.).

2. **Duration/ID**:
   - 16 bits used to specify the duration for which the medium will be reserved.
   - In power-saving modes, it can also carry the identification (ID) of a station.

3. **Address Fields**:
   - IEEE 802.11 frames can have up to four **address fields**, each 48 bits long.
   - These fields include:
     1. **Receiver Address**: The address of the device receiving the frame.
     2. **Transmitter Address**: The address of the device transmitting the frame.
     3. **Source Address**: The address of the original source device (in case of forwarding).
     4. **Destination Address**: The address of the final destination device (in case of forwarding).
   - The number of address fields depends on the specific operation mode (e.g., infrastructure, ad-hoc).

4. **Sequence Control**:
   - 16 bits used to ensure proper ordering of fragmented frames and to detect duplicate frames.
   - Includes a sequence number and a fragment number.

5. **Data**:
   - The payload section of the frame. Contains the actual data being transmitted, such as application-layer data.
   - The maximum frame size is 2304 bytes.

6. **Frame Check Sequence (FCS)**:
   - 32 bits used for error detection using a cyclic redundancy check (CRC) code.
   - Ensures that corrupted frames can be detected by the receiver.

### IEEE 802.11 MAC Frame Structure:

The general format of an IEEE 802.11 MAC frame consists of the following fields:

| **Field**               | **Size (bits)** | **Description**                                    |
|-------------------------|-----------------|----------------------------------------------------|
| Frame Control            | 16              | Control information like frame type and version    |
| Duration/ID              | 16              | Duration for medium reservation or station ID      |
| Address 1 (Receiver)     | 48              | MAC address of the receiver                        |
| Address 2 (Transmitter)  | 48              | MAC address of the transmitter                     |
| Address 3 (Source)       | 48              | MAC address of the source device                   |
| Sequence Control         | 16              | Ensures proper ordering and no duplicate frames    |
| Address 4 (optional)     | 48              | MAC address used in some forwarding cases          |
| Data (Payload)           | Variable        | Contains the actual data                           |
| Frame Check Sequence     | 32              | Error detection using CRC                          |

### 3. MAC Sublayer Functions in IEEE 802.11:

The MAC sublayer provides several functions that support the reliable transmission of data over wireless networks:

#### a) **Medium Access Control (MAC) Protocol**:
   - IEEE 802.11 uses **CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)** to avoid collisions in the wireless medium.
   - Stations first sense the medium for any activity, and if idle, they initiate transmission.
   - Collisions are avoided using random back-off timers and acknowledgments.

#### b) **Retransmissions**:
   - If a frame is not acknowledged (ACK) by the receiver, the transmitter automatically retransmits the frame.
   
#### c) **Power Management**:
   - Power-saving mechanisms are included in the MAC layer, allowing devices to enter sleep mode and periodically wake up to check for incoming frames.

#### d) **Frame Fragmentation**:
   - Large data frames can be fragmented into smaller frames to improve transmission reliability, especially in noisy environments.
   
#### e) **Frame Aggregation**:
   - Multiple frames can be combined into a single frame to improve efficiency and reduce overhead.

---
# Q2. Show the various subsystems of the GSM architecture. Differentiate between HLR and.VLR and also discuss authentication & access in GSM.
>2018 MTE

### B) Subsystems of GSM Architecture

**GSM (Global System for Mobile Communications)** is a standard developed to describe the protocols for second-generation (2G) digital cellular networks. GSM architecture is divided into several subsystems that work together to provide seamless mobile communication. The architecture can be broadly divided into three key subsystems:

### 1. **Mobile Station (MS)**:
- **Mobile Equipment (ME)**: The actual mobile device (e.g., a mobile phone) that allows a user to communicate with the network.
- **Subscriber Identity Module (SIM)**: A removable card that securely stores the subscriber’s identity, authentication keys, and personal data. It is essential for connecting to the network.

### 2. **Base Station Subsystem (BSS)**:
- **Base Transceiver Station (BTS)**: The equipment that facilitates wireless communication between the user’s mobile device and the network. It transmits and receives radio signals to and from the mobile station.
- **Base Station Controller (BSC)**: Controls multiple BTSs, handling tasks like frequency allocation, handover management, and power control. It acts as a middleman between the BTS and the Network Subsystem.

### 3. **Network and Switching Subsystem (NSS)**:
This is the core of the GSM architecture and handles the routing, switching, and management of mobile communications.
- **Mobile Switching Center (MSC)**: The central component responsible for call routing and mobility management. It connects calls between the mobile users and the public switched telephone network (PSTN).
- **Home Location Register (HLR)**: A centralized database that stores the permanent subscriber information like IMSI (International Mobile Subscriber Identity), authentication keys, and current location.
- **Visitor Location Register (VLR)**: A temporary database that stores the subscriber information of mobile users currently in the MSC’s geographical area. It provides local management and minimizes the need for constant communication with the HLR.
- **Authentication Center (AuC)**: Responsible for authenticating subscribers and ensuring secure access to the network. It stores cryptographic algorithms and authentication keys for this purpose.
- **Equipment Identity Register (EIR)**: Stores the IMEI (International Mobile Equipment Identity) of mobile devices. It helps track stolen or invalid devices by classifying them into white, gray, or blacklists.

### 4. **Operation and Support Subsystem (OSS)**:
- Manages network operation and maintenance, providing tools to monitor and control the network.

### HLR vs. VLR

| **Feature**                          | **HLR (Home Location Register)**                              | **VLR (Visitor Location Register)**                            |
|--------------------------------------|---------------------------------------------------------------|----------------------------------------------------------------|
| **Purpose**                          | Stores permanent subscriber data (e.g., IMSI, service profile). | Stores temporary data about subscribers visiting an MSC area.  |
| **Location**                         | Centralized database, usually one per network or region.       | Distributed across different regions, linked to MSCs.           |
| **Role**                             | Manages subscriber identity, authentication keys, and services. | Provides local control and management of subscribers in a specific MSC area. |
| **Updates**                          | Updated when there are permanent changes, like a new subscriber. | Continuously updated as subscribers move between regions.       |
| **Communication**                    | Interacts with the MSC and VLR to provide data when needed.    | Communicates with HLR to authenticate subscribers in its area.  |
| **Data Storage**                     | Holds long-term data like subscriber profiles and billing information. | Stores temporary data like location, current services, and active calls. |
| **Capacity**                         | One HLR typically serves a large region or entire network.      | Each VLR serves a specific geographic area.                     |

### Authentication and Access in GSM

In GSM networks, **authentication and security** are critical to ensure only valid users can access network services and to protect communication from eavesdropping or tampering. The authentication process in GSM involves a series of steps designed to verify the identity of the subscriber and secure communication.

#### 1. **Authentication Process**:
   - **Subscriber Identity Module (SIM)**: The SIM card plays a crucial role in GSM authentication. It stores a unique authentication key, known as **Ki**, and the subscriber’s IMSI.
   - **Authentication Center (AuC)**: Stores the Ki for all subscribers and the algorithms needed for authentication.
   
   The authentication process works as follows:
   1. **Challenge-Response Mechanism**:
      - The Mobile Switching Center (MSC) requests authentication from the AuC when a mobile station attempts to connect.
      - The AuC generates a random number (RAND) and sends it to the mobile station.
      - The SIM card, using the RAND and the stored **Ki**, computes a response known as **SRES (Signed Response)** and sends it back to the MSC.
      - The AuC calculates the expected response using the same RAND and Ki.
      - If the response from the SIM matches the one calculated by the AuC, the authentication is successful, and the mobile station is granted access to the network.
      
#### 2. **Ciphering Process**:
   - **Ciphering Key (Kc)**: GSM ensures the privacy of communication through encryption. The SIM and the network generate a **ciphering key (Kc)** during the authentication process using the RAND and Ki.
   - **Encryption Algorithm (A5)**: The Kc is used to encrypt the data exchanged between the mobile station and the base station using the **A5 encryption algorithm**.
   - This encryption ensures that even if the data is intercepted, it cannot be deciphered without the correct encryption key.

#### Steps Involved in Authentication & Ciphering:
1. **Authentication**:
   - The MSC sends a RAND to the mobile station.
   - The SIM computes SRES using RAND and Ki, sends it back to the MSC.
   - If verified, the mobile station is authenticated.

2. **Ciphering**:
   - The Kc is derived and used to encrypt all communication.
   - The data transmitted between the mobile device and the network is encrypted using Kc and the A5 algorithm to protect user data from interception.

---
# Q3. Explain worjingng of CDMA vvfth suitable example. How codes are assigned to the stations?

>2018 MTE
### A) Working of CDMA (Code Division Multiple Access) with Example

**Code Division Multiple Access (CDMA)** is a multiple access technique where multiple users can transmit information simultaneously over the same frequency band. Unlike **FDMA (Frequency Division Multiple Access)** and **TDMA (Time Division Multiple Access)**, where users are separated by frequency or time, in CDMA, they are separated by unique codes. Each user is assigned a distinct code sequence, which helps distinguish their data from others' data, even though they share the same frequency and time slot.

#### Working of CDMA

The basic idea behind CDMA is **spread spectrum technology**, which spreads a signal over a wide bandwidth that is significantly larger than the minimum bandwidth required. This makes the signal more resistant to interference and easier to distinguish from other signals using different codes.

CDMA works as follows:

1. **Unique Code Assignment**:
   - Each user is assigned a unique **code** known as a **PN (Pseudo-Noise) sequence** or a **spreading code**.
   - This code is used to **spread** the user's data over a wider frequency band.
   - The code has a much higher bit rate than the actual data, resulting in what is called a **chip rate**. Each bit of user data is mapped to several bits (chips) using the spreading code.

2. **Transmission**:
   - The user’s data is **multiplied by the spreading code** and then transmitted over the shared frequency spectrum. The data is "spread" across a wide frequency range.
   - Multiple users can transmit at the same time over the same frequency, but each one uses a different spreading code.

3. **Reception and Decoding**:
   - At the receiver's end, the signal is **correlated with the same spreading code** that was used for transmission.
   - This correlation process helps the receiver to extract the specific user’s data from the combined signal of all users.
   - Since the spreading codes of other users appear as noise or interference, they have minimal impact on the target signal.

#### Example of CDMA

Consider three users (A, B, and C) who want to transmit data simultaneously over the same frequency band.

1. **Code Assignment**:  
   - User A is assigned the code **[1, -1, 1, -1]**  
   - User B is assigned the code **[1, 1, -1, -1]**  
   - User C is assigned the code **[1, -1, -1, 1]**

2. **Data Transmission**:  
   - User A wants to send a `1`, so their data is spread using their code:  
     `Data: 1 → 1 * [1, -1, 1, -1] = [1, -1, 1, -1]`
   - User B wants to send a `0`, so their data is spread using their code, but with a sign change (since `0` is represented as `-1` in CDMA):  
     `Data: 0 → -1 * [1, 1, -1, -1] = [-1, -1, 1, 1]`
   - User C wants to send a `1`, so their data is spread using their code:  
     `Data: 1 → 1 * [1, -1, -1, 1] = [1, -1, -1, 1]`

3. **Combined Signal**:  
   - All three signals are transmitted simultaneously and added together to create a combined signal.  
     Combined signal = `[1, -1, 1, -1] + [-1, -1, 1, 1] + [1, -1, -1, 1] = [1 + (-1) + 1, -1 + (-1) + (-1), 1 + 1 + (-1), -1 + 1 + 1] = [1, -3, 1, 1]`

4. **Reception and Decoding**:
   - To decode User A’s data, the receiver multiplies the combined signal by User A's code and sums the result.  
     `[1, -3, 1, 1] * [1, -1, 1, -1] = [1*1, -3*-1, 1*1, 1*-1] = [1, 3, 1, -1]`  
     Sum = `1 + 3 + 1 + (-1) = 4`  
     Since the result is positive, the decoded data is `1` for User A.
   - Similarly, for User B and User C, the respective codes are used for decoding, and their data can be retrieved from the combined signal.

#### How Codes are Assigned to Stations

In CDMA, the **spreading codes** are carefully designed to have specific properties:
- **Orthogonality**: Ideally, the codes should be orthogonal, meaning that the cross-correlation between any two codes should be zero. This ensures minimal interference between users. In practice, however, some interference exists, but it is small enough to allow effective communication.
- **Pseudo-Randomness**: The codes used are typically **pseudo-random sequences**, meaning they appear random but are actually deterministic and repeatable. The most commonly used codes in CDMA are **Walsh codes** or **Gold codes**.
- **Code Length**: The length of the spreading code (number of chips per bit) affects the bandwidth usage and the ability to distinguish users. A longer code provides more robust communication but consumes more bandwidth.

In practical CDMA systems, codes are either assigned dynamically based on system needs or pre-assigned based on the total number of users expected in the network.

#### Hidden and Exposed Node Problem

CDMA naturally mitigates the **hidden node** and **exposed node** problems often encountered in wireless communication systems:
- **Hidden Node Problem**: This occurs when two stations that cannot hear each other (due to being out of range) transmit simultaneously to a common receiver, leading to collision.
- **Exposed Node Problem**: This occurs when a station refrains from transmitting because it detects the signal from a nearby transmitter, even though it could transmit to another receiver without interference.

Because CDMA separates users by codes rather than by time or frequency, multiple users can transmit simultaneously without interference, significantly reducing these problems.

---
# Q4. Explain Wireless LAN security Issues and also explain hidden and exposed node problem in Wireless LAN?

>2018 MTE

### B) Wireless LAN Security Issues

Wireless LANs (WLANs), such as those based on the IEEE 802.11 standard (Wi-Fi), are convenient for providing network access without the constraints of physical cables. However, the open nature of wireless communication makes WLANs more vulnerable to various security threats compared to wired networks.

#### Common Security Issues in WLANs

1. **Unauthorized Access (Rogue Access Points)**
   - **Description**: Unauthorized users can set up their own access points (rogue APs) to bypass security policies and gain access to the network.
   - **Impact**: Rogue APs can be used by attackers to intercept network traffic, steal sensitive information, or launch further attacks.
   - **Solution**: Regular monitoring of the network for unauthorized access points and using strong access control mechanisms like **WPA3** for encryption and authentication.

2. **Data Interception (Eavesdropping)**
   - **Description**: Wireless communication can be easily intercepted by attackers using sniffer tools like Wireshark. Attackers can listen to or capture unencrypted data being transmitted.
   - **Impact**: This leads to the disclosure of confidential data, such as passwords, financial information, or personal details.
   - **Solution**: Implementing robust encryption standards like **WPA3** and using secure protocols such as **HTTPS**, **SSL/TLS**, and **VPNs** to ensure data confidentiality.

3. **Man-in-the-Middle (MITM) Attacks**
   - **Description**: In MITM attacks, an attacker intercepts communication between two parties (e.g., client and AP) and relays or alters the data between them without either party being aware.
   - **Impact**: Sensitive information like login credentials and personal data can be stolen or altered.
   - **Solution**: Using **encryption** to ensure data integrity and employing techniques like **certificate-based authentication** to verify the identity of communication parties.

4. **Denial of Service (DoS) Attacks**
   - **Description**: Attackers flood the wireless network with unnecessary traffic (e.g., **deauthentication frames** or **jamming** the radio frequencies), overwhelming the network and preventing legitimate users from accessing it.
   - **Impact**: This disrupts the availability of the network and leads to a loss of productivity or service.
   - **Solution**: Implementing **intrusion detection systems (IDS)** to detect unusual traffic patterns and using **frequency-hopping techniques** or **robust security protocols** to reduce vulnerability to DoS attacks.

5. **Weak Authentication Mechanisms**
   - **Description**: Many WLANs still use weak authentication methods (like **WEP**) that are vulnerable to brute-force attacks or can be easily cracked using tools like Aircrack-ng.
   - **Impact**: Attackers can gain unauthorized access to the network and exploit it for malicious purposes.
   - **Solution**: Use strong authentication and encryption methods such as **WPA2-Enterprise** or **WPA3** with **RADIUS servers** for enhanced security.

6. **MAC Address Spoofing**
   - **Description**: Attackers can disguise their device’s MAC address to appear as a legitimate user on the network.
   - **Impact**: This allows attackers to bypass access controls and impersonate legitimate users, leading to unauthorized access.
   - **Solution**: Implement **MAC filtering**, but also use **WPA3 encryption** and **802.1x authentication** to provide stronger security layers.

7. **Replay Attacks**
   - **Description**: Attackers capture transmitted data (such as authentication packets) and retransmit it later to trick the receiver into granting access.
   - **Impact**: This can lead to unauthorized access to resources or data, even if the original session has ended.
   - **Solution**: Use encryption with **nonces** (numbers used once) and **timestamps** to prevent replay attacks, and ensure secure key exchange mechanisms.

### Hidden and Exposed Node Problems in Wireless LANs

The **hidden node** and **exposed node** problems are common challenges in wireless communication, particularly in wireless LANs. These issues arise because wireless communication relies on shared media (airwaves) and suffers from signal attenuation and interference.

#### 1. Hidden Node Problem

- **Explanation**:
  The hidden node problem occurs when two stations (A and C) are unable to detect each other’s transmissions because they are out of each other’s range, but both can communicate with a common access point or station (B). As a result, both stations may try to transmit data to the access point at the same time, leading to collisions at the access point (B), even though A and C are unaware of each other.

  ![Hidden Node Problem](https://upload.wikimedia.org/wikipedia/commons/4/4a/Hidden_Terminal.png)

  In the diagram, station A and station C cannot "see" each other, but both can communicate with station B. Since A and C are unaware of each other’s transmissions, they may transmit at the same time, causing a collision at B.

- **Impact**: 
  The hidden node problem leads to increased packet collisions, resulting in data loss, retransmissions, and degraded performance of the wireless network.

- **Solution**:
  The **RTS/CTS (Request to Send / Clear to Send)** mechanism is commonly used to solve the hidden node problem. Before sending data, a station sends an RTS packet to the access point. If the access point approves the transmission, it replies with a CTS packet, indicating that the channel is clear for transmission. Other stations that hear the CTS packet will defer their transmissions, reducing collisions.

#### 2. Exposed Node Problem

- **Explanation**:
  The exposed node problem occurs when a station refrains from transmitting data because it erroneously believes that its transmission will interfere with an ongoing transmission to a nearby station. For example, if station B is transmitting to station A, station C, which can "hear" B’s transmission but is not within the range of A, will defer its own transmission to station D. This results in **under-utilization of the network**.

  ![Exposed Node Problem](https://upload.wikimedia.org/wikipedia/commons/thumb/5/54/Exposed_Terminal.png/320px-Exposed_Terminal.png)

  In the diagram, station B is transmitting to station A. Station C can hear the transmission from B and wrongly assumes that it cannot transmit to station D, even though C’s transmission would not interfere with A's reception.

- **Impact**:
  The exposed node problem causes unnecessary transmission delays, leading to lower throughput and inefficiency in network usage.

- **Solution**:
  The RTS/CTS mechanism also helps mitigate the exposed node problem. When station B sends an RTS to A, station C, upon hearing the CTS response from A, understands that it is free to transmit to another station (D) since its transmission will not interfere with the communication between A and B.

---
--- 
# Q1. Show the various subsytems and units in the GSM architecture and their functions and also explain the working of HLR and VLR
>2018 ETE
### GSM Architecture: Subsystems and Units

The GSM (Global System for Mobile Communications) architecture is divided into several subsystems, each responsible for different aspects of communication, mobility, and network management. The key subsystems and their functions are:

#### 1. **Mobile Station (MS)**
   - **Components**: Mobile Equipment (ME) and Subscriber Identity Module (SIM).
   - **Functions**:
     - The **ME** is the physical device (mobile phone) that communicates over the network.
     - The **SIM** contains user information such as IMSI (International Mobile Subscriber Identity) and encryption keys for securing communication.
     - Together, the MS is responsible for voice/data transmission, authentication, and managing user identity.

#### 2. **Base Station Subsystem (BSS)**
   - **Components**: Base Transceiver Station (BTS) and Base Station Controller (BSC).
   - **Functions**:
     - **BTS**: Handles radio transmission between the mobile station and the network. It contains radio equipment (antenna and transceivers) for the physical layer of the network.
     - **BSC**: Manages multiple BTSs. It controls the handover between BTSs and allocates radio channels.
     - The BSS enables wireless communication between mobile phones and the network.

#### 3. **Network and Switching Subsystem (NSS)**
   - **Components**: Mobile Switching Center (MSC), Home Location Register (HLR), Visitor Location Register (VLR), Authentication Center (AUC), Equipment Identity Register (EIR).
   - **Functions**:
     - **MSC**: Main switch that handles ==call setup, routing, and call termination==. It connects mobile users to other users (mobile or fixed).
     - **HLR**: Centralized database storing permanent information about the subscribers (IMSI, services subscribed, etc.).
     - **VLR**: Stores temporary information about roaming subscribers, such as their current location, while they are in the MSC area.
     - **AUC**: Provides security by storing encryption keys for validating the subscriber's identity.
     - **EIR**: Stores information about mobile equipment to detect stolen or invalid devices.

#### 4. **Operation and Support Subsystem (OSS)**
   - **Functions**:
     - The OSS is responsible for network management, fault detection, and configuration of the network.
     - It helps in managing the quality of service, and operational tasks such as billing and monitoring performance.

### Explanation of HLR and VLR

#### 1. **Home Location Register (HLR)**
   - The **HLR** is a central database in the GSM architecture that contains the permanent subscriber information.
   - **Functions**:
     - Stores unique identity (IMSI) and mobile number (MSISDN) of the subscriber.
     - Keeps track of the services subscribed to, such as call waiting, voicemail, and data services.
     - Maintains the current location of the subscriber by pointing to the MSC where the subscriber is located.
     - When a subscriber turns on their phone or roams into a different area, the HLR is updated with the new location information.

#### 2. **Visitor Location Register (VLR)**
   - The **VLR** is a temporary database that stores information about subscribers who are currently in the geographical area covered by an MSC (roaming subscribers).
   - **Functions**:
     - The VLR dynamically updates the location of the mobile user within the MSC area.
     - When a subscriber enters a new MSC area, the VLR requests the subscriber's information from the HLR and stores it temporarily.
     - The VLR eliminates the need to constantly query the HLR for subscriber information by storing it locally for fast access.
     - It also handles call setup for the subscriber while they are roaming.

### Working of HLR and VLR Together
1. **Location Update**:
   - When a mobile user enters a new region covered by an MSC, the MSC checks whether the user is already registered in the local VLR.
   - If not, the MSC requests the user’s details from the HLR. The HLR sends the relevant information (e.g., services, authentication keys) to the VLR.
   - The VLR then stores this information locally and notifies the HLR of the user’s current MSC area.

2. **Call Setup**:
   - When someone calls a GSM subscriber, the MSC contacts the HLR to find the subscriber’s current location.
   - The HLR provides the MSC/VLR location, and the call is routed to the corresponding VLR.
   - The VLR then delivers the call to the subscriber’s mobile station through the BTS.

This interaction between the HLR and VLR ensures that subscribers can be reached and served efficiently regardless of their location.

---

# Endsem


### **Ques 1: How DES is different from AES?**

| **Aspect**        | **DES**                                                 | **AES**                                                 |
|--------------------|---------------------------------------------------------|---------------------------------------------------------|
| **Full Form**      | Data Encryption Standard                                | Advanced Encryption Standard                           |
| **Key Size**       | 56 bits (effectively)                                   | 128, 192, or 256 bits                                  |
| **Block Size**     | 64 bits                                                 | 128 bits                                               |
| **Rounds**         | 16 rounds                                               | 10, 12, or 14 rounds (based on key size)              |
| **Algorithm Type** | Symmetric block cipher, based on Feistel Network        | Symmetric block cipher, based on Substitution-Permutation Network |
| **Security**       | Vulnerable to brute force attacks due to small key size | Highly secure due to larger key size and complex rounds|
| **Speed**          | Faster in hardware implementation                      | More efficient in software implementation              |
| **Applications**   | Legacy systems, outdated in modern cryptography         | Widely used in modern cryptography for secure communications |
| **Adoption**       | Developed in 1977 by IBM and NIST                       | Adopted as the encryption standard by NIST in 2001     |

---

### Ques 2: A certain city has •an area of 1300 square miles and is covered by a cellular system using a seven cell reuse pattern. Each cell has a radius of 4 miles and the city has 40 MHz spectrum with a full duplex channel bandwidth of 60KHz. Find: 
(i) The number of cells in the service area. 
(ii) The number of channels per cell. 
(iii) TotaLuumber of subscribers that can be served.

#### Given:
- Area of the city = \( 1300 \, \text{square miles} \)
- Reuse pattern = 7
- Cell radius \( r = 4 \, \text{miles} \)
- Total spectrum = \( 40 \, \text{MHz} \)
- Full duplex channel bandwidth = \( 60 \, \text{kHz} \)

#### Formulae:
1. **Area of a cell**:  
   $A_{\text{cell}} = \frac{3\sqrt{3}}{2} r^2 \approx 4.62 r^2$

2. **Number of cells in the service area**:
   $N_{\text{cells}} = \frac{\text{Total area}}{A_{\text{cell}}}$

3. **Number of channels per cell**:
   $C_{\text{cell}} = \frac{\text{Total spectrum}}{\text{Reuse factor} \times \text{Channel bandwidth}}$

4. **Total number of subscribers**:
   Assuming one subscriber per channel in the entire network:
   $T_{\text{subscribers}} = N_{\text{cells}} \times C_{\text{cell}}$

#### Solution:
1. **Area of a cell**:  
   $A_{\text{cell}} = 4.62 \times 4^2 = 73.92 \, \text{square miles}$

2. **Number of cells in the service area**:  
   $N_{\text{cells}} = \frac{1300}{73.92} \approx 17.59 \, \text{(round down to 17 cells)}$

3. **Number of channels per cell**:  
   $C_{\text{cell}} = \frac{40 \, \text{MHz}}{7 \times 60 \, \text{kHz}} = \frac{40,000}{420} \approx 95 \, \text{channels per cell}$

4. **Total number of subscribers**:  
   $T_{\text{subscribers}} = 17 \times 95 = 1615 \, \text{subscribers}$

---

### Ques 3: Explain working of RSA algorithm for encryption and decryption and also find cipher text corresponding to plain text M=9, also generate public key and secret key using RSA algorithm by taking two prime numbers p=61. and q=53.

#### Given:
- Prime numbers: \( p = 61, q = 53 \)
- Plaintext \( M = 9 \)

#### Steps:
1. **Calculate \( n \)**:
   $n = p \times q = 61 \times 53 = 3233$

2. **Calculate \( \phi(n) \)**:
   $\phi(n) = (p - 1) \times (q - 1) = 60 \times 52 = 3120$

3. **Select \( e \) (Public Exponent)**:
   - Choose $e$ such that $1 < e < \phi(n)$ and $\text{gcd}(e, \phi(n)) = 1$.  
   - Let $e = 17$

4. **Calculate $d$ (Private Key)**:
   - $d$ satisfies $e \cdot d \mod \phi(n) = 1$.  
   - Using Extended Euclidean Algorithm:
     $d = 2753$

5. **Public Key**:
   $(e, n) = (17, 3233)$

6. **Private Key**:
   $(d, n) = (2753, 3233)$

7. **Encryption**:
   $C = M^e \mod n = 9^{17} \mod 3233 = 2015$
8. **Decryption**:
   $M = C^d \mod n = 2015^{2753} \mod 3233 = 9$

---

### **Ques 4: Problems and Approaches for TCP in Wireless Networks**

#### Problems:
1. **High Packet Loss**:
   - Caused by signal interference, fading, and mobility.
   - TCP may mistake packet loss for congestion.

2. **Variable Bandwidth**:
   - Wireless links have fluctuating bandwidth, leading to delays and retransmissions.

3. **Latency**:
   - Increased round-trip time affects acknowledgments and throughput.

4. **Handoff and Mobility**:
   - TCP connections can break during transitions between cells.

5. **Energy Constraints**:
   - Wireless devices have limited power, leading to restricted transmission rates.

#### TCP Improvement Approaches:
1. **Explicit Loss Notification (ELN)**:
   - The receiver notifies the sender whether the packet loss is due to congestion or link errors.

2. **Split TCP Connections**:
   - A proxy divides the TCP connection into a wired and wireless part, optimizing each separately.

3. **Link-Layer Retransmissions**:
   - Errors are corrected at the link layer itself to avoid TCP retransmissions.

4. **TCP Variants**:
   - Use wireless-specific TCP variants such as **TCP Reno**, **TCP Westwood**, or **TCP Vegas**.

5. **Congestion Avoidance Algorithms**:
   - Techniques like **Selective Acknowledgments (SACK)** and **Fast Retransmit** improve performance over lossy networks.

## Ques5: Authentication and Access in GSM (Short Answer)

1. **Authentication**:
   - GSM uses a challenge-response mechanism.
   - The network sends a random number (**RAND**) to the SIM.
   - SIM computes a response (**SRES**) using a secret key (**Ki**) and the A3 algorithm.
   - Network verifies the SRES; if it matches, authentication succeeds.

2. **Access**:
   - Access control ensures only authenticated users can connect.
   - The SIM's **IMSI (International Mobile Subscriber Identity)** and **Ki** are crucial for validation.
   - Temporary identities like **TMSI** are used to protect IMSI from interception.

### Ques 6: Explanation of TORA and also discuss route maintenance in TORA assuming that at time t link fails between node 6 and node 7. 
![[Pasted image 20241118132816.png]]
**1. Working of TORA:**
   - **Multi-Hop Routing Protocol:** TORA is designed for mobile ad-hoc networks (MANETs).
   - **Directed Acyclic Graph (DAG):** TORA creates a DAG rooted at the destination node, where all nodes have paths leading to the destination.
   - **Three Phases:**
     1. **Route Creation:** A source node broadcasts a query packet to find the destination. Once the destination is found, a reverse path is created.
     2. **Route Maintenance:** When a link failure occurs, TORA uses local reconfiguration to re-establish routes without disrupting the network.
     3. **Route Erasure:** Removes invalid routes when they are no longer needed.

**2. Route Maintenance in TORA:**
   - **Link Failure Between Node 6 and Node 7:**
     - At time \( t \), when the link between nodes 6 and 7 fails, node 6 detects the failure and broadcasts an **update message** with a higher height value.
     - All neighboring nodes adjust their heights to reconfigure the DAG while avoiding the failed link.
     - The failure propagates until an alternate path is found. For example, traffic from node 6 can now route through node 3 or node 5 to reach node 7.
   - **Minimizes Network-Wide Disruption:** Only local nodes are updated.

This localized maintenance ensures efficient handling of link failures, making TORA highly scalable for dynamic networks.