
### Data Link Layer - Important Topics Done

**1. Framing**
- Character count
- Byte stuffing
- Bit stuffing   
- Flag-based framing

**2. Error Detection & Correction**
- Parity check
- Checksum
- CRC (VERY IMPORTANT)

**3. Flow Control** ⭐
- **Stop-and-Wait** ✅
- Sliding Window
    - Go-Back-N
    - Selective Repeat

**4. Error Control** ⭐
- Stop-and-Wait ARQ
- Go-Back-N ARQ    
- Selective Repeat ARQ

 **5. Multiple Access Protocols** ⭐⭐⭐
- **CSMA/CD** ✅
- CSMA/CA
- ALOHA
- Slotted ALOHA
- Token Passing (Token Ring, FDDI)
    
 **6. LAN Technologies**
- Ethernet (IEEE 802.3)
- MAC address
- Frame format
- Minimum & maximum frame size

---


### Stop-and-Wait Protocol

##### 1. What is Stop-and-Wait?

**Definition:**  Stop-and-Wait is a **flow control and error control protocol** in which the sender transmits **one frame at a time** and waits for an acknowledgment (ACK) from the receiver before sending the next frame.

-> At any instant, **only one unacknowledged frame** can be present in the network.

##### 2. Why Stop-and-Wait is Needed (Reason)

- Sender and receiver may operate at **different speeds**
- Network may introduce **errors or losses**    
- Prevents sender from **overrunning the receiver**

Hence, Stop-and-Wait ensures:
- **Reliability**
- **Flow control**

##### 3. Working Principle (Step-by-Step)

1. Sender sends **Frame 0**
2. Sender **stops and waits**
3. Receiver receives frame and sends **ACK 0**
4. Sender receives ACK and sends **Frame 1**
5. Process repeats

-> Uses **sequence numbers (0 and 1)** to detect duplicates.


##### **4. Delays Involved**

- Transmission delay: ( $T_x$ )
- Propagation delay: ( $T_p$ )
- ACK transmission delay (usually negligible)
- **Round Trip Time (RTT) :** $RTT \approx 2T_p$

##### **5. Timing of One Transmission Cycle**

- Total time for sending **one frame and receiving its ACK**:
	$T_{\text{cycle}} = T_x + 2T_p$

- Useful transmission time:  
	$T_{\text{useful}} = T_x$


##### **6. Link Utilization** ⭐


$$\boxed{  
U = \frac{T_x}{T_x + 2T_p}  
} $$


This measures how efficiently the link is used.


##### **7. Utilization Analysis**

Case 1: $( 2T_p \gg T_x )$
- Long distance
- Sender waits idle for ACK    
- **Very low utilization**  : (
- Example: Satellite links

**Case 2: $( T_x \gg 2T_p )$**
- Short distance or large frames
- ACK arrives quickly
- **High utilization (≈1)** : )
- Example: LAN


##### Boundary Condition ⭐

$$  
\boxed{T_x = 2T_p}  
$$

Sender finishes transmission exactly when ACK arrives.

##### **8. Error Handling in Stop-and-Wait**

- If ACK not received within timeout:
    - Sender retransmits the frame
        
- Sequence numbers prevent duplication
	-> Called **Stop-and-Wait ARQ**

##### **9. Advantages**

- Simple to implement
- Ensures reliable communication
- No buffer requirement at sender
    

##### **10. Disadvantages**

- Poor utilization for long-delay links
- Inefficient for high-speed networks
	-> Leads to **Sliding Window Protocols**

##### **11. Relation with Physical Layer Delays**

- Stop-and-Wait logic is **Data Link Layer**
- Performance depends on **Transmission and Propagation delay**
- RTT dominated by $(T_p)$
    
##### **12. GATE Exam Focus Areas**

- Utilization calculation
- RTT involvement
- Dominance of $(T_x)$ vs $(2T_p)$
- Comparison with Sliding Window
    

---

### CSMA/CD


##### **1. What is CSMA/CD?**

**CSMA/CD (Carrier Sense Multiple Access with Collision Detection)** is a **multiple access protocol** used in **shared broadcast networks**, where multiple nodes compete to use the same communication channel.

-> Used in **classic Ethernet (IEEE 802.3, half-duplex)**.


##### **2. Why CSMA/CD is Needed (Reason)**

- Multiple nodes share a **common medium**
- Simultaneous transmissions cause **collisions**
- CSMA/CD minimizes wasted bandwidth by **detecting collisions early**
    
##### **3. Components of CSMA/CD**

**1️. Carrier Sense (CS)**
- Station listens to the channel before transmitting    
- Transmits only if channel is idle

**2. Multiple Access (MA)**

- Many stations share the same channel
- Any station can attempt transmission

**3. Collision Detection (CD)**
- Station monitors the channel **while transmitting**
- Detects collision by signal mismatch

##### **4. Working of CSMA/CD (Step-by-Step)**

1. Sense the channel
2. If idle → start transmitting
3. If collision occurs:
    - Detect collision
    - Send **jam signal**        
    - Stop transmission

4. Wait for **random backoff time**
5. Retry transmission

##### **5. Why Collisions Occur (Physical Reason)**

- Signals take time to propagate
- Two distant nodes may sense channel idle at the same time
- Their signals collide in the medium
##### **6. Minimum Frame Size Condition** ⭐⭐

For collision detection to work:
  
$$\boxed{T_x \ge 2T_p} $$ 

Where:
- $(T_x)$ = transmission delay
- $(T_p)$ = propagation delay
    

**Reason:**

- Worst-case collision occurs at the **farthest node**
- Collision signal takes **round-trip propagation time** to reach sender
- Sender must still be transmitting to detect it

##### **7. Minimum Frame Size Formula** ⭐

$$\boxed{  
L_{\min} = R \times 2T_p  
}  $$

Where:
- (R) = bandwidth (bps)

##### **8. Ethernet Insight (Real-World Example)**

- 10 Mbps Ethernet
- Max cable length ≈ 2.5 km
	$L_{\min} \approx 512 \text{ bits} = 64 \text{ bytes}$

- This is why Ethernet enforces a **minimum frame size**.

##### **9. What Happens If Frame Is Smaller?**

- Sender finishes transmission before collision returns
- Collision goes undetected    
- Frame loss without awareness : (

##### **10. Backoff Algorithm (Binary Exponential Backoff)**

After collision:
- Choose random $(k \in [0, 2^i - 1])$
- Wait (k \times \text{slot time})
- Retry transmission
- Slot time = (2T_p)

##### **11. Slot Time (VERY IMPORTANT)**

$$\boxed{  
\text{Slot time} = 2T_p  
}$$

- Minimum time to detect collision
- Used in backoff calculation

##### **12. Why CSMA/CD is Not Used in Wireless?**

- Cannot detect collisions while transmitting
- Signal power difference too high
- Hidden terminal problem
- Wireless uses **CSMA/CA** ⭐


##### **13. CSMA/CD vs CSMA/CA**

|Feature|CSMA/CD|CSMA/CA|
|---|---|---|
|Collision handling|Detection|Avoidance|
|Used in|Wired Ethernet|Wireless LAN|
|ACK|Not for collision|Mandatory|
|Medium|Shared wired|Wireless|

##### **14. Advantages**

- Better than ALOHA
- Reduces wasted bandwidth   
- Efficient for low-load LANs
 
##### **15. Disadvantages**

- Inefficient under high load
- Not suitable for wireless
- Obsolete in full-duplex Ethernet

##### **16. GATE Exam Traps**

- Forgetting (2T_p)
- Confusing minimum frame size with MTU
- Assuming CSMA/CD works in full-duplex Ethernet    
- Using CSMA/CD for Wi-Fi ❌

