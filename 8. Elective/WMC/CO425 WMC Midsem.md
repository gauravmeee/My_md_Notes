

# [IEEE 802.11 architecture| Mobile Computing | Lec-23 | Bhanu priya](https://youtu.be/AWPgmEHVp1c)

### IEEE 802.11 Architecture (Wifi)

2 types of Services 
1. Basic Service Set (BSS) - Stations and AP with same radio coverage form BSS
2. Extended Service set (ESS) - Several BSS connected through API

- Station (STA) - Mobile Nodes
- Access Point (AP) - Stations are connected to Access point.
- Portal - Bridge to other wired Network
- Distributed System - Interconnected network to form a logical Network based on Several BSS

```
              ESS
   
    BSS
     .   .              802.X LAN
 .           .       .  . .
.      💻    .    .         .
  .    📱     .   .    🌐     .
    .        .   .           .
-------[🛜AP]---------[Portal]---
|                             |
|                             |
-------------[🛜AP]--------------
         .           .  
         .     📱     .
            .       .
                 .    BSS
```

*Note:* 802.11 (Wifi), 802.3 (Ethernet)
### IEEE Standard 802.11 ⭐

```
Mobile Terminal    Acess Point             Infrastructre n/w   Fixed Terminal
  
    💻    ⇝   ⇝      🛜 ────────────────────────────────🌐───────────🖥🖥️
    
Wirelss Station                                        Wired Infrastructure
┌-──────────-┐                                         ┌-──────────-┐
│ Application│                                       ˄ │ Application│ 
├────────────┤ |                                     | ├────────────┤
│     TCP    │ |                                     | │    TCP     │
├────────────┤ |                  AP                 | ├────────────┤
│     IP     │ ˅             wireless + wired          │    IP      │
├────────────┤          ┌-──────────────────────-┐     ├────────────┤ 
│    LLC     │          │        LLC             │     |    LLC     │
├────────────┤----------├────────────┬───────────┤-----├────────────┤ 
│ 802.11 MAC │          │ 802.11 MAC | 802.3 MAC │     |  802.3 MAC │
├────────────┤          ├────────────+───────────┤     ├────────────┤ 
│ 802.11 Phy │          │ 802.11 Phy | 802.3 Phy │     |  802.3 Phy │
└────────────┘          └────────────┴───────────┘     └────────────┘
          |                 ↑            |                 ↑
          └-----------------┘            └-----------------┘
```

*Note:* DLL Layer is 802.11 Mac

# [Cellular Concept | Cell Shape and Frequency Reuse Fundamentals](https://youtu.be/kilN06O7mwA?list=PLCyR4nKNLRkFTER9ohRBnbRFK0pWe0Qtf)

### Cellular Concept
- Cellular. concept is system level idea, which calls for replacing single high
power transmitter with many low power transmitters.
-  It offer very high capacity in a limited spectrum allocation.
- Each base station is allocated portion of the total number of channels available
to the entire system.
- Neighboring base stations are assigned different groups of channels so that
interference between base stations is minimized.
### What is Cell?

- Each cellular base station is allocated a group of radio channels to be used
within small geographic area called a cell.

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_4ae1c169-0bc2-42e0-bbed-5a93af7cf018.jpeg)

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_40c181fb-cc48-4535-9041-de090d02a7a2.jpeg)
### Frequency Reuse
- By limiting the coverage area to within the boundaries of a cell, the same ==group of channels== may be used to cover different cells that are separated from one another by distances large enough to keep interference levels within tolerable limits.
- The design process of selecting and allocating channel frequencies for all cellular base stations within a system is known as frequency re-use or frequency planning.

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_ba8dc221-6f85-4ac3-98a9-922945952ff6.jpeg)

Reuse Distance : D = $(3N)^{1/2}.R$
Reuse Factor : q = %D/R%
![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_dfa92314-2b5b-4d06-a2b5-159545777c41.jpeg)

Total Radio Channels in a Cluster= No. of channels per Cell  x Cluster Size of each cell.
Total Radio Channel = No. of Cluster X Total Radio Channel in a Cluster

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_fe2b5ece-99e8-49c3-b37d-2111b57c9b2b.jpeg)

- Let We have given total 28 no. of channels, and We think to made each cell of 4 channels to handle the traffic, than the cluster Size we need is N=7,  is. 28 = 4XN
- If We have total 30 no. of channels, and made each cell of 4 size than, the Cluster size N will be N=7 , 30 = 4xN + 2.  the two extra channels will be used where we have a Extra Traffic

# GPT:
Note: in image, reuse ration is shown as reuse factor


### **1. Reuse Factor (\(N\))**:
- **Definition**: The reuse factor is the **number of cells in a cluster** that use distinct sets of frequencies.
- It determines how often the same frequency can be reused across the network.
- It is calculated using the formula:

  $N = i^2 + i \cdot j + j^2$

  where \(i\) and \(j\) define the cell layout in a hexagonal grid.

- **Example**: If \(N = 7\), it means that there are 7 cells in a cluster, and each cell in the cluster uses a different set of frequencies.

---

### **2. Reuse Ratio (\(q\))**:
- **Definition**: The reuse ratio is the **distance-to-radius ratio** and represents how far apart cells using the same frequency are, relative to the cell radius.
- It measures the physical separation between cells with the same frequency, helping to reduce interference.
- It is calculated as:

  $q = \frac{D}{R} = \sqrt{3N}$

  where:
  - \(D\): Reuse distance (distance between two cells using the same frequency).
  - \(R\): Radius of a single hexagonal cell.
  - \(N\): Reuse factor (number of cells in a cluster).

| **Aspect**     | **Reuse Factor (\(N\))**         | **Reuse Ratio (\(q\))**                                 |
| -------------- | -------------------------------- | ------------------------------------------------------- |
| **Definition** | Number of cells in a cluster.    | Ratio of reuse distance (\(D\)) to cell radius (\(R\)). |
| **Formula**    | $N = i^2 + i \cdot j + j^2$      | $q = \frac{D}{R} = \sqrt{3N}$                           |
| **Purpose**    | Defines frequency reuse pattern. | Measures physical spacing to avoid interference.        |
| **Unit**       | Dimensionless (count of cells).  | Dimensionless (distance ratio).                         |

---

#### 1. **Spectrum**
- **Definition**: The spectrum refers to the range of frequencies allocated for communication purposes (e.g., cellular networks). It represents the total bandwidth available for transmitting signals.
- **In this problem**: The city has a **40 MHz spectrum**, meaning it can use frequencies within a 40 MHz range to allocate channels for communication.  

#### 2. **Duplex Channel**
- **Definition**: A duplex channel allows two-way communication (sending and receiving) simultaneously. This is achieved by dividing the spectrum into two separate bands:
  - **Uplink**: Signals from the user (e.g., a phone) to the base station.
  - **Downlink**: Signals from the base station to the user.
- **Full Duplex**: In a full-duplex system, communication happens in both directions at the same time, requiring separate bandwidth for uplink and downlink.  
  - For example, if the **full duplex channel bandwidth** is **60 kHz**, it means **30 kHz** is used for uplink and **30 kHz** for downlink.

##### **Step 1: Calculate the Total Number of Channels**
The total number of channels available in the entire cellular system can be calculated using:

$\text{Total Channels} = \frac{\text{Total Spectrum (Hz)}}{\text{Channel Bandwidth (Hz)}}$

In this case:
- Total Spectrum = \( 40 \, \text{MHz} = 40 \times 10^6 \, \text{Hz} \)
- Channel Bandwidth = \( 60 \, \text{kHz} = 60 \times 10^3 \, \text{Hz} \)

$\text{Total Channels} = \frac{40 \times 10^6}{60 \times 10^3} = \frac{40,000,000}{60,000} = 666.67$

So, the total number of channels is approximately **666** (rounded down to the nearest whole number).

##### **Step 2: Distribute Channels Across the Reuse Pattern**
In a **7-cell reuse pattern**, the total channels are divided among the 7 cells:

$\text{Channels per Cell} = \frac{\text{Total Channels}}{\text{Reuse Factor}}$

In this case:
- Total Channels = \( 666 \)
- Reuse Factor = \( 7 \)

$\text{Channels per Cell} = \frac{666}{7} \approx 95$

Thus, each cell has approximately **95 channels**.

# [What is handoff? Handoff Strategies](https://youtu.be/ktnBPBOZY4E?list=PLCyR4nKNLRkFTER9ohRBnbRFK0pWe0Qtf)

#### Handoff

A Process, Which Allows user to remain in touch, even while breaking the connection with one BS(Base Station) and Establish connection with another BS

When a mobile moves into a different cell while a conversation is in progress, the MSC automatically transfer the call to a new channel belonging to the new base station.


- **BSC (Base Station Controller)**: It controls multiple Base Transceiver Stations (BTS) and is responsible for managing radio resources, including handoff between BTSs within the same BSC. It handles intra-BSC handoffs.
    
- **MSC (Mobile Switching Center)**: It manages switching functions in the network and controls several BSCs. It handles handoff when a mobile device moves between different BSCs, known as inter-BSC handoff or inter-MSC handoff (if the handoff involves different MSCs).

```
                   BSC
            /         |        \
         🗼BS1     🗼 BS2    🗼 BS3
                🚗
         
```

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_e5ea79ab-e205-4cf5-8efa-668ae22e9f65.jpeg)

# [Introduction To TDD and FDD in Wireless Communication](https://youtu.be/3qXbdn_IZ-Q?list=PLCyR4nKNLRkFTER9ohRBnbRFK0pWe0Qtf)


## Introduction To Multiple Access

- Simultaneous transmission of information is required, i.e. Duplexing
	- Frequency domain (Frequency Division Duplexing— FDD)
	- Time domain (Time Division Duplexing —TDD)

```
				🗼
				| ˄ 
				| |
				| |
down link	    | |  up ink
	or			| |    or
Forward link	| | Reverse Link
				˅ |
				 📱
		   
```
### 1. Frequency Division Duplexing (FDD)

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_56cbac81-4729-48e7-b8bb-8d74a70b7c59.jpeg)
- It consist two simplex channels.
- Duplexer is required to allow simultaneous bidirectional transmission.
- Frequency separation between two channel is constant through system.

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_52d8b869-52d0-492b-aada-5df315defc87.jpeg)

## 2. Time Division Duplexing

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_5f89f041-b086-416f-b0c6-7e5a0586321f.jpeg)

- Uses time for forward and reverse link.
- Multiple users share a single channel by taking turns in the time domain.
- Each user assigned a time slot.
- Each duplex channel has both forward and reverse time slot to provide bidirectional transmission.
- Separation between forward and reverse time slot is important. 
- Duplexer is not required.

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_3118c363-c96d-43e4-bbc1-a2036bf44b9a.jpeg)

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_9a72d32d-0149-4cfd-bcfa-d7e2175683eb.jpeg)
# IEEE 802.11 wireless standards

Wireless standards are set of services and protocols that determine how a wi-fi  network operates

Wifi(wireless Fidelity) : wireless technology standard for wireless internet access 


> 1997
### IEEE 802.11

Speed - 2Mbps
Frequency - 2.4 GHz
Modulation Method - Infrared+PPM, FHSS+FSK, DSSS+PSK

*Note:* Spread Spectrum Techniques:


> 1999
### IEEE 802.11b ( Wifi 1)

Speed - 11 Mbps
Frequency - 2.4 GHz
Modulation Method - DSSS+CCK

*Note:* 802.11b kickstarts wifies popularity

### IEEE 802.11a ( Wifi 2)
It is a Extension of Wifi 1

Speed - 54 Mbps
Frequency - 5 GHz
Modulation Method - OFDM + (PSK or QAM)

*Note:* 
5 GHz has more difficulties with objects that were in the signal path, So the range was poor.
11a comes after 11b because of OFDM Technology


> 2003
### IEEE 802.11g ( Wifi 3)

Speed - 54 Mbps
Frequency - 2.4 GHz
Modulation Method - OFDM

*Note:* 
upgrade the speed up to 54 Mbps while retaining the usage of reliable 2.4GHz
this result in the widespread adoption of the standards


> 2009
### IEEE 802.11n ( Wifi 4)

Speed - 600 Mbps
Frequency - 2.4/5 GHz
Modulation Method - MIMO, OFDM

*Note:* 
This version had slow initial adoption.
it supported multi channel usage, each channel support max data rate up to 600 Mbps



Modulation Schemes Summary:

- **FHSS - Frequency Hopping Spread Spectrum**: A technique where the signal rapidly switches frequencies to minimize interference and improve security.

- **DSSS - Direct Sequence Spread Spectrum**: A method that spreads the signal over a wide frequency band to reduce interference and increase security.

- **OFDM - Orthogonal Frequency Division Multiplexing**: A multiplexing technique that divides a communication channel into multiple orthogonal sub-channels to enhance data transmission efficiency.

- **CCK - Complementary Code Keying**: A modulation scheme used in wireless networks for improved data transmission efficiency.

- **MIMO - Multiple Input and Multiple Output**: A technology that uses multiple antennas at both the transmitter and receiver to improve communication performance.


# [Hidden Station Problem And Exposed Station Problem in Computer Networks Explained in Hindi](https://youtu.be/Xr_S4kr4fR8)

### Hidden Station Problem

**Definition**: The hidden station problem occurs in wireless networks when two devices, which cannot hear each other, try to communicate with a third device. This can cause interference and data collisions at the third device because the two hidden stations do not know of each other's transmissions.

**Diagram**:

```
   .        . 
      .  .
       .
 A --> B <--C
       .
      . .
   .       .
```

- **A** and **C** are hidden from each other but both can communicate with **B**.
- If **A** and **C** transmit simultaneously, **B** may experience interference or collision because it cannot detect both transmissions.

### Exposed Station Problem

**Definition**: The exposed station problem occurs when a device is prevented from transmitting even though its transmission would not cause interference to ongoing transmissions from other devices.

**Diagram**:

``` 
     .   .   .
.	          .   .     .
	       .       .      .
	 A --> B        C----> D
	       .       .       .
	        .  .        .
	   .   .     .   . 
```

- **A** is trying to communicate with **B**, while **C** is trying to communicate with **D*.
- **C** might avoid transmitting because it detects **A**'s ongoing transmission to **B**, even though **C**'s transmission would not interfere with **A**'s communication with **B**.


Summary
H**idden Station Problem :**  Node shouldn't send signal, but it send (because wrongly think that medium is free)
**Exposed Station Problem :** Node can send signal, but it is not sending (because wrongly think that medium is not free)
# [wireless network | Types | Adhoc networks | Lec-1| Bhanu Priya](https://youtu.be/HjAxGPd0Oto)

## ADHOC & Senser Networks

Types of Wireless Networks
1. Infrastructure N/w
	- Single hop : ex - Wifi
	- Multiple hop : ex - GSM
	
1. Infrastructure-less N/w
	-  Single hop : ex - Bluetooth
	- Multiple hop : ex - Ad-Hoc

According to Sir There are 4 types of wireless networks

**Access Point Network**
1. **Base Station Wireless:** All communication takes place through an Access point other ends can be fixed as mobile
2. **Infrastructure Wireless Network:** Base station wireless Network with wired Internet
**Peer-to-Peer**
3. **Ad-Hoc Wireless Network:** Devices can connect to directly to each other
4. **MANETS (Mobile Ad-Hoc Network):** Adhoc mobile n/w in which device are allowed to move
# [Lecture 38.2: IEEE 802 .11 WLAN Architecture & Physical Layer Functions | Computer Networks](https://youtu.be/R_3Kytr_ZNY)

IEEE 802.11 standard provides wireless communication with the use of infrared or radio waves.

**802.11 ARCHITECTURE**
- The 802.11 architecture defines two types of services and three different types of Stations
- 802.11 SERVICES
		1. Basic services set (BSS)
		2. Extended Service Set (ESS)
- 802.11 STATION TYPES
		1. No-transition Mobility
		2. BSS-transition Mobility
		3. ESS-transition Mobility

#### IEEE 802.11: SERVICES - 1. BASIC SERVICES SET (BSS)

The network established under BSS, the station in a BSS cannot connect to Station in other BSS. All the stations will be stationary within the same network.
```     
           BSS                                BSS
           .       .                        .      .
      .               .                 .      🛜       .
    .                   .             .       ⬋↓⬊        .
   .      💻 ←  💻      .           .       💻    💻      .
   .       ↑  ⤭  ↓       .           .                     .
    .     💻  ← 💻      .            .      💻    💻      .
      .                 .               .                 .
         .            .                    .            .
             .    .                            .    .
     Adhoc  Network                     Infrastructure Netwokr
```
Two types of Architecture in BSS

- Ad-hoc Network - BSS without AP
	- The stations are connected without the help of any AP or any communication device. The stations are connected directly to each other.
	- Layer 2: The Medium Access Control Responsibility will be on the Stations itself.
	
- Infrastructure Network - BSS with AP
	- The BSS have a communication device i.e. Access Point, All the stations will be connected to the AP, and AP will play the role of transmitting information from one station to other
	- Layer 2: Medium Access Control (MAC), Collision Avoidance Mechanism etc  will be handled by the Access Point


#### IEEE 802.11: SERVICES - 2. EXTEND SERVICE SET (ESS)

The Combination of Multiple BSS is called ESS
```
                             ESS                      
		   . . . . . . . . . . . . . . . . . . . . . . . 
		  .        Ethernet-distribution system          .
		  .   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━     .
		   . . . . . . . . . . . . . . . . . . . . . . . . 
				 /             |            \
				/              |             \
		. . . . . .     .   .  .  .     . . . . . 
	  .    AP🛜      .     AP🛜      .    AP🛜    .   
	 .            .     .          .    .           .    
     .    💻      . 💻 .    💻    . 💻 .    💻     .   
	 .    💻         .      💻       .            .  
	    . . . . . .     . . . . .  .      . . . . .
	  BSS                   BSS              BSS   
```

#### IEEE 802.11: STATION TYPES

1. **No-transition Mobility:** These types of stations are either stationary i.e.
immovable or move only inside a BSS.
2. **BSS-transition Mobility:** These type of stations can move from one BSS to another
but the movement is limited inside an ESS.
3. **ESS-transition Mobility:** These type of stations can move from one ESS to another.
*Note:* The communication may or may not be continuous when a station moves from one
FSS to another FSS.


### IEEE 802.11: IMPLEMENTATION

#### 1. IEEE 802.11 INFRARED
- It USPS diffused infrared light in the range Of 800 to 950 nm.
- It allows two different speeds: 1Mbps and 2Mbps.
- For **1-Mbps** data rate, 4 bits of data are encoded into 16-bit code. This 16-bit code contains fifteen 0s and a single 1.
- For a **2-Mbps** data rate, a 2-bit code is encoded into 4-bit code. This 4 bit code contains three 0s and a single 1.
- The modulation technique used is pulse position modulation (PPM) i.e. for converting digital signal to analog.

#### 2. IEEE 802.11 FHSS
- IEEE 802.11 uses **Frequency Hoping Spread Spectrum (FHSS)** method for signal generation.
- This method uses **2.4 GHz ISM** band.
- This band is divided into (2.402-2.480 GHz) 79 sub bands of 1MHz with some guard bands.
**Function:**
- In this method, at one moment data is sent by using one carrier frequency and then by some other carrier frequency at next moment.
- After this, an idle time is there in communication. This cycle is repeated after regular intervals.
- A pseudo random number generator selects the hopping sequence. The allowed data rates are 1 or 2 Mbps.
- This method uses **frequency shift keying** (two level or four level)

#### 3. IEEE 802.11 DSSS
- This method uses **Direct Sequence Spread Spectrum (DSSS)** method for signal generation.
- Each bit is transmitted as 11 chips using a Barker sequence.
- DSSS uses the 2.4-GHz ISM band.
- It also allows the data rates of 1 or 2 Mbps.
- It uses **phase shift keying (PSK)** technique.

#### 4. IEEE 802.11a OFDM
- This method uses **Orthogonal Frequency Division Multiplexing (OFDM)** for signal generation.
- This method is capable of delivering data up to 18 or 54 Mbps.
- In OFDM all the sub bands are used by one source at a given time. It uses 5 GHz ISM band. This band is divided into 52 sub bands, with 48 sub bands for data and 4 sub bands for control information.
- If **phase shift keying (PSK)** is used for modulation then data rate is 18 Mbps.
- If **quadrature amplitude modulation (QAM)** is used, the data rate can be 54 Mbps.

#### 5. IEEE 802.11b HR-DSSS
- It uses **High Rate Direct Sequence Spread Spectrum** method for signal generation.
- HR-DSSS is similar to DSSS except for encoding method. Here, 4 or 8 bits are encoded into a Special symbol called complementary code key (CCK).
- It uses 2.4 GHz ISM band.
- It supports four data rates: 1,2, 5.5 and 11 Mbps. 1 Mbps and 2 Mbps data rates uses phase shift modulation.
- The 5.5. Mbps version uses BPSK and transmits at 1.375 Mbps with 4-bit CCK encoding.
- The 11 Mbps version uses QPSK and transmits at 1.375 Mbps with 8-bit CCK encoding.

#### 6. IEEE 802.11g OFDM
- It uses OFDM modulation technique. It uses 2.4 GHz ISM band.
- It supports the data rates of 22 or 54 Mbps.
- It is backward compatible with 802.11b.

**Compatibility**
802.11b, 802.11g both uses 2.4Ghz , Transmission of b and g, are compatible with each other and communicate with each other
Similarly 802.11a and  802.11n uses 5Ghz, a and n are compatible with each other

But if you establish two wireless network , let one is using 802.11b and other is  802.11a, then you cannot connect the network with each other because they are not compatible with each other
# [Lecture 38.3: IEEE 802.11 MAC Sub Layer Functions | Computer Networks](https://youtu.be/B5YD1qzfNDw)


1. Distributed Coordination Function (DCF) - For Ad-hoc wireless Networks
2. Point Coordination Function (PCF) - For Infrastructure Network.
![](https://youtu.b)

Watch this Youtube video 📺 at time 3:00 to 10:00 for good Diagram DFS Explanation 

#### DCF
802.11 standard uses Network Allocation Vector (NAV) for collision avoidance. The
procedure used in NAV is explained below:
1.  Whenever a station sends an RTS frame, it includes the duration of time for which
the station will occupy the channel.
2. All other stations that are affected by the transmission creates a timer called
network allocation vector (NAV).
3. This NAV (created by other stations) specifies for how much time these stations
must not check the channel.
4. Each station before sensing the channel, check its NAV to see if has expired or not.
If its NAV has expired, the station can send data, otherwise it has to wait.

#### PCF
- PCF method is used in infrastructure network.
- In this Access point is used to control the network activity.
- It is implemented on top of the DCF and is used for time sensitive transmissions. PCF uses centralized, contention free polling access method.
- The AP performs polling for stations that wants to transmit data. The various stations are polled one after the other.
- To give priority to PCF over DCF, another interframe space called PIFS is defined. PIFS (PCF IFS) is shorter than DIFS.

- If at the same time, a station is using DCF and AP is using PCF, then AP is given priority over the station.
- Due to this priority of PCF over DCF, stations that only use DCF may not gain access to the channel.
- To overcome this problem, a repetition interval is defined that is repeated continuously.
- This repetition interval starts with a special control frame called **beacon frame.** When a station hears beacon frame, it starts their NAV for the duration of the period of the repetition interval.

#### Frame Format of 802.11


```
  bytes bytes bytes  bytes  bytes  bytes   bytes   bytes       bytes
    2     2    6      6      6       2      6     0 to 2312      4
┌──────┬────┬───────┬───────┬───────┬────┬───────┬─────────────┬──────┐
│  FC  │  D │ Addr1 │ Addr2 │ Addr3 │ SC │ Addr4 │ Frame Body  │ FCS  │
└──────┴────┴───────┴───────┴───────┴────┴───────┴─────────────┴──────┘
.       .
.               .
.                          .
.                                      .
.                                                 .
.    Frame Control                                             .
┌─-─────┬────--┬─────-┬────┬──────┬───-─-┬─────┬──────-┬─────-┬-────┬─────┐
│ Prot. │ Type │ Sub  │ To │ From │ More │ Re- │ Power │ More │ WEP |Rsvd |
│ Vers. │      │ type │ DS │  DS  │ Flag │ try |  Mgt  │ Data |     |     |
└─────-─┴─-───-┴──────┴────┴──────┴──-──-┴─────┴───────┴──────┴─────┴─────┘
    2      2      4     1     1      1      1      1     1      1     1
    bit    bit    bit   bit   bit    bit    bit   bit   bit    bit    bit

	 FC = 16 bit = 2 bytes
```


1. **Frame Control (FC)** : This is 2-byte field and defines the type of frame and some control information. This field contains several different subfields.

- **Version:** The current version is 0.
- **Type:** Specific 	- 00-management, 01-control, and 10-data
- **Subtype:** It defines the subtype of each type.
	- 1011-RTS, 1100-CTS, 1101-ACK
- **To DS:** Indicate frame is going to distributed system.
- **From DS:** Indicate frame is coming from distributed system.
- **More flag:** If the value is 1, Means more fragments.
- **Retry:** If the value is 1, means retransmitted frame.
- **Power Mgt. :** If the value is 1, means station is in power management mode.
- **More data:** If the value is 1, means station has more data to send
- **WEP:** WEP stands for wired equivalent privacy ; if set to 1 means encryption is implemented.
- **Rsvd:** Reserved

1. **Duration(D):** it stands for duration and is of 2 bytes. This field defines the duration for which the frame and its acknowledgement will occupy the channel. It is also used to set the value of NAV for other stations.
2. **Addresses:** There are 4 address fields of 6-bytes length. These four addresses represent source, destination, source base station and destination base station.
3. **Sequence Control(SC):** This 2-byte field defines the sequence number of frame to be used in flow control.
4. **Frame body:** This field can be between 0 and 2312 bytes. It contains the information
5. **FCS:** this field is 4-bytes long and contains CRC-32 error detection sequence

**FRAME TYPES IEEE 802.11**
1. Management Frame: These are used for initial communication between stations and access points.
2. Control frame: These are used for accessing the channel and acknowledging frames. The control frame are RTS and CTS.
3. Data frame: These are used for carrying data and control information.


#### 802.11 Addressing
Base Station (BS) -> Device
Distributed System (DS) -> Access Point

| TO DS | From DS | Address 1      | Address 2      | Address 3       | Address 4  | Type of Network/Access Method |
|-------|---------|----------------|----------------|-----------------|------------|--------------------------------|
|   0   |    0    | Destination    | Source         | BSS ID          | N/A        | **Independent BSS (IBSS)**, DCF |
|   0   |    1    | Destination    | Sending AP     | Source          | N/A        | **From AP to Station (Infrastructure Mode)**, DCF/PCF |
|   1   |    0    | Receiving AP   | Source         | Destination     | N/A        | **From Station to AP (Infrastructure Mode)**, DCF/PCF |
|   1   |    1    | Receiving AP   | Sending AP     | Destination     | Source     | **Wireless Distribution System (WDS)**, DCF/PCF |

1. **TO DS = 0, From DS = 0**: This scenario describes an Independent Basic Service Set (IBSS), also known as an ad-hoc network, where there is no access point (AP), and devices communicate directly with each other using the Distributed Coordination Function (DCF).

2. **TO DS = 0, From DS = 1**: This represents communication from an Access Point (AP) to a station in an infrastructure network. This scenario can occur in both DCF and PCF, depending on whether the network is operating in a contention-based mode (DCF) or a contention-free mode (PCF).

3. **TO DS = 1, From DS = 0**: This scenario is when a station sends data to an Access Point (AP) in an infrastructure network. Like the previous case, it can occur in both DCF and PCF.

4. **TO DS = 1, From DS = 1**: This represents a Wireless Distribution System (WDS) where the frame is being relayed between two APs. It could also occur in networks utilizing either DCF or PCF.
# [Non-persistent , 1-Persistent , P-Persistent CSMA Techniques Explained with Examples in Hindi](https://youtu.be/f7sH3QzyRUw)

**Carrier-sense multiple access** (CSMA) is a medium access control (MAC) protocol in which a node verifies the absence of other traffic before transmitting on a shared transmission medium, such as an electrical bus or a band of the electromagnetic spectrum.


```
  ˅
--.-----------.-----------.--
  |           |           |
 (1)         (2)         (3)
```
⭐
##### 1. **Non-Persistent CSMA**
1. **Operation**:
   - A station (e.g., A) checks if the medium is busy at regular intervals (`T`).
   - If the medium is busy, it waits for `T` time and checks again.
   - This continues until the medium is free, at which point the station transmits.
2. **Disadvantage**:
   - If the medium becomes free and is occupied again within the interval `T`, the station misses the opportunity to transmit.
   - **Low Bandwidth Utilization**: Time is wasted during the waiting intervals.

##### 2. **1-Persistent CSMA**
1. **Operation**:
   - Stations (e.g., A and B) continuously monitor the medium.
   - If the medium is busy, they keep checking without waiting.
   - As soon as the medium is detected as free, the stations transmit immediately with a probability of 1.
2. **Disadvantage**:
   - If multiple stations detect the medium as free simultaneously (e.g., A and B), they transmit at the same time, causing a **collision**.
   - **Higher Collision Rate**: Continuous monitoring increases the chance of simultaneous transmissions.
##### 3. **P-Persistent CSMA**
1. **Operation**:
   - Stations (e.g., A and B) continuously monitor the medium.
   - When the medium is detected as free, each station transmits with a probability \( P \).
   - If a station does not transmit in the first attempt, it waits for a short period and tries again in subsequent slots.
2. **Advantage**:
   - Reduces the chances of collisions compared to 1-persistent CSMA, as transmissions are probabilistic rather than immediate.
3. **Disadvantage**:
   - Collisions can still occur if multiple stations decide to transmit simultaneously within the same probability slot.
   - **Throughput Decrease**: Choosing too low or too high a probability \( P \) can result in underutilization or increased collisions, respectively.
# [DCF, PCF, HCF](https://youtu.be/rmZ-WRgrV9Y)


# [Point Coordination Function (PCF) and Distributed Coordination Function (DCF)](https://youtu.be/HSEVzYKhpU4)


- **DCF** is "distributed" because medium access is managed independently by each station in the network.
- **PCF** is "point" based because a central controller (the AP) manages medium access.

These names reflect the core difference between the two functions: DCF distributes control among all devices, while PCF centralizes control at a single point (the AP).
## WLAN - Wireless Local Area Network

- A small network consisting of Access Points (APs) and Stations (STAs).
- DCF (Distributed Coordination Function) and PCF (Point Coordination Function) are medium access methods defined in the IEEE 802.11 WLAN standard.
- These mechanisms implement **CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)** in a Wireless LAN.

## CSMA/CA - Carrier Sense Multiple Access with Collision Avoidance

- **Carrier sense** refers to a station sensing the medium to determine whether it is occupied.
- There are basically two mechanisms to sense the medium:
    1. **Physical Carrier Sensing (Layer 1):** The station checks the physical layer to detect the presence of a carrier.
    2. **Virtual Carrier Sensing (NAV - Network Allocation Vector):** The station uses the NAV timer to determine medium occupancy based on the duration field in the frame.

_Note:_ It is better to check both of the above mechanisms to accurately determine the idle state of the medium.

The NAV is essentially a timer that is updated by the station based on the frame duration field in the 802.11 frame. This duration field typically includes enough time to account for the transmission of the WLAN frame as well as the reception of the acknowledgment (ACK) frame.

For example, suppose station A is transmitting a frame to station C. In this case, station B updates its NAV equal to the duration of the MAC frame being transmitted by A. Station B also ensures that it does not transmit until the NAV timer reaches zero.

```
				     🛜AP
				   ⬈  |    ╲
			msg	 ╱  msg|     ╲ msg
			   ╱       ↓      ⬊
			  💻      💻      💻 
			  A       B        C

- A: Message sent to C, with a duration = 10ms
- B: Sets NAV = 10ms

```

_Note:_ Once the NAV is set, stations can update it further if the frame duration exceeds the currently set value of NAV. If the frame duration is less than the already set NAV, it will not be changed or altered.


### DCF - Distributed Coordination Function

- Like Ethernet, DCF first checks to see if the radio link is clear before transmitting. To avoid collisions, stations use a **random backoff** after each frame, with the first transmitter seizing the channel.
- Most WLAN traffic uses the DCF MAC access method because it is similar to standard Ethernet, providing a contention-based service.

**There are two main rules** that apply to all transmissions based on the DCF concept:

1. Transmission can be initiated immediately if the medium has been idle for longer than the DIFS (Distributed Interframe Space) period. Carrier sensing is performed at both the PHY layer and using the Network Allocation Vector (NAV).
2. If the medium is occupied and not free, the station (STA) must wait until the channel becomes free or idle. This waiting period in 802.11 is considered access deferral. When access is deferred, the STA waits for the medium to become free for a duration equivalent to DIFS and then prepares for exponential backoff.

*Note:* DIFS (Distributed Interframe Space) The time a station must wait after the medium becomes idle before it can initiate a data transmission.


### PCF - Point Coordination Function

- To gain priority over standard contention based services, the PCF gives certain stations a priority over others by allowing them to transmit frames after a shorter time interval known as the **Short Interframe Space (SIFS)**. (DCF use longer interval i.e. DIFS)
- The PCF is not widely implemented. However, the IEEE designed the PCF so stations that implement only the distributed coordination function (DCF) will interoperate with point coordinators.
- PCF does not guarantee contention-free access to the medium at all times.
- When the PCF is used, time on the medium is divided into the contention-free period (CFP) and the contention period. 
- During the **Contention-Free Period (CFP)**, the access point (AP) controls access to the medium, allowing only designated stations to transmit, preventing collisions, and ensuring efficient use of the channel. After CFP ends, the **Contention Period (CP)** begins, where all stations compete for access using the standard DCF method, allowing general data transmission without the strict timing control of PCF.

---
Here's the updated and streamlined explanation of the cellular system components:

### Cellular Network Components

#### 1. **SIM (Subscriber Identity Module)**
- **Role**: Contains essential information for mobile device identification and network access.
- **Key Components**:
  - **IMSI**: Unique identifier for the subscriber used for authentication.
  - **Authentication Key (Ki)**: Secret key used to secure communications.
  - **PIN/PUK**: Codes to protect access to the SIM card.

#### 2. **Base Station Subsystem (BSS)**
- **BSC (Base Station Controller)**: Manages radio resources, including allocation, deallocation, and handoff between Base Transceiver Stations (BTS).
- **BTS (Base Transceiver Station)**: The radio equipment that connects to mobile devices for communication.

#### 3. **Mobile Switching Center (MSC)**
- **Role**: Routes voice calls, data, and handles handoffs between BTSs, managing both local and roaming users.
- **Functions**: 
  - Routes calls and data.
  - Manages roaming and handoffs.
  - Works with databases like HLR, VLR, EIR, and AUC for user authentication, billing, and service access.

#### 4. **HLR (Home Location Register)**
- **Role**: A permanent database that stores information about subscribers in the network.
- **Functions**:
  - Stores the **IMSI**, service profiles, and user data.
  - Provides routing information for roaming users through **MSRN**.

#### 5. **VLR (Visitor Location Register)**
- **Role**: A temporary database that stores information about subscribers roaming in the area managed by an MSC.
- **Functions**: 
  - Stores location and status information of subscribers.
  - Works with the HLR to authenticate users and route calls.

#### 6. **EIR (Equipment Identity Register)**
- **Role**: A database that checks the status of mobile devices based on their IMEI (International Mobile Equipment Identity) numbers.
- **Functions**:
  - **White List**: Devices that are authorized for use.
  - **Grey List**: Devices under observation.
  - **Black List**: Devices barred due to theft or fraud.

#### 7. **AUC (Authentication Center)**
- **Role**: Ensures security and authenticates users when they access the network.
- **Functions**:
  - Works in conjunction with the **HLR** to authenticate users.
  - Uses the IMSI, a random number, and a secret key to verify the mobile device's identity.
  - Ensures only authorized users can access the network services.
