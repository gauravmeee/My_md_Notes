
# Transmission & Propagation Delay

> Transmission and propagation delays **belong to the Physical Layer**, but CSMA/CD and Stop-and-Wait _depend_ on them for correctness and performance — that’s why questions appear under those protocols.

##### **1. Transmission Delay $(Tx)$**

**Definition:**  Time required to **serialize** (push) all bits of a packet onto the link.

 
$$\boxed{T_x = \frac{L}{R}}$$


* (L) = Packet size (bits)
* (R) = Link bandwidth / transmission rate (bits/sec)

**Key Properties (EXAM-IMPORTANT):**
- Depends on **packet size (L)** and **link (Bandwidth) rate (R)**
	- Larger packet → higher $(T_x)$
	* Higher bandwidth → lower $(T_x)$
- Independent of distance
- Also called **serialization delay**

**Minimum Transmission Time:**
* Occurs when bandwidth is maximum for a given packet:  $T_{x, \min} = \frac{L}{R_\text{max}}$

**Example:**
- $L = 8\text{ Mb},\ R = 4\text{ Mbps} \implies T_x = \frac{8 \times 10^6}{4 \times 10^6} = 2\ \text{sec}$

##### **2. Propagation Delay $(Tp)$**


**Definition:** Time taken by **one bit** to propagate from sender to receiver 
	or  Time taken for a bit to travel from sender to receiver.
 
$$\boxed{T_p = \frac{d}{v}}$$  

* (d) = distance (meters)
* (v) = propagation speed in medium (~(2\times10^8) m/s in copper/fiber, (3\times10^8) m/s in air)

**Key Properties:**

- Depends on **distance** and **medium**, not on packet size.
	- Long-distance links → $(T_p)$ dominates
	* Short links → $(T_x)$ dominates
- Independent of packet size and bandwidth
- Typical values:
	Fiber/Copper: $( v \approx 2 \times 10^8 ) m/s$
	Air/Vacuum: $( 3 \times 10^8 ) m/s$

**Minimum Propagation Time:**
- $T_{p, \min} = \frac{d_\text{min}}{v_\text{max}}$

**Example:**
- $d = 1000\text{ km},\ v = 2 \times 10^8 \text{ m/s} \implies T_p = \frac{1000 \times 10^3}{2 \times 10^8} = 0.005\ \text{sec}$


##### **3. Total Time to Send a Packet $(T_\text{total})$**


$$\boxed{T_\text{total} = T_x + T_p}$$



**Observation:**
- **LAN (short distance, high bandwidth)**  
    → $( T_p )$ is **very small**, $( T_x )$ may dominate
	    Ex: For LAN: ($T_x >> T_p)$
    
- **WAN / Satellite (long distance)**  
    → $( T_p )$ dominates
		Ex: For satellite: $(T_p >> T_x)$


##### **4. Time for First Bit vs Last Bit**


- **First bit arrival time:** $T_{\text{first bit}} = T_p$  
- **Last bit arrival time:** $T_{\text{last bit}} = T_x + T_p$

> This is **frequently tested in GATE**.
> GATE often asks: _“When does the receiver get the complete packet?”_


##### **5. Bandwidth–Delay Product $(BDP)$ ⭐**


**Definition:** Number of bits that can be present “in-flight” in the link at any instant.

$$\boxed{\text{BDP} = R \times T_p}$$

**Meaning:**
- Number of bits **present in the link simultaneously**
- Equals **minimum TCP window size** to fully utilize the link

**Significance:**
* Helps design buffer size in routers
* Indicates how many bits are “on the wire”

**Example:**
- $R = 10 \text{ Mbps},\ T_p = 0.01\text{ sec} \implies \text{BDP} = 10^7 \times 0.01 = 10^5 \text{ bits}$

> If window < BDP → link underutilized (very common GATE concept)


#### **6. Effect of Packet Segmentation (Pipelining) / Multiple Packets**


 **Case 1: Single link, no store-and-forward**
  
-  For multiple packets sent back-to-back, total transmission time for (n) packets: 
	$T = nT_x + T_p$

- If pipelining (like TCP windowing), $(T_p)$ can be **overlapped**, so effective total time for large (n):
	$(T ≈ n \cdot T_x)$ 

**Case 2: Store-and-Forward, k links (VERY IMPORTANT)**

- For **1 packet** across k links: 
	$T = k(T_x + T_p)$

- For **n packets**:  
	$T = k(T_x + T_p) + (n-1)T_x$ 

> This is **one of the most asked GATE formulas**.


**Case 3: Cut-through switching (rare but asked)**

- Transmission overlaps
- Delay < store-and-forward
    
- First packet delay ≈ $( T_p + \text{header transmission} )$


##### **7. Delay Components in Networks / End-to-End Delay**


1. **Transmission delay:** $(T_x = \frac{L}{R})$
2. **Propagation delay:** $(T_p = \frac{d}{v})$
3. **Queuing delay:** Time spent waiting in router queues
4. **Processing delay:** Time routers take to process headers

**Total end-to-end delay:**

- $T_{\text{end-to-end}} =  \sum T_x + \sum T_p + \sum T_q + \sum T_{\text{process}}$
- $T_\text{end-to-end} = T_x + T_p + T_\text{q} + T_\text{process}$


Where:
- $( T_q )$: Queuing delay (variable, load-dependent)
- $( T_{\text{process}} )$: Header processing (small but non-zero)

> GATE usually **ignores** queue & processing **unless specified**.


##### **8. Round Trip Time (RTT)**

**Definition :** It is the total time taken for a data packet to travel from the sender to the receiver **and** for the corresponding acknowledgment (ACK) to travel back to the sender.

**Ignoring ACK Tx**

$$\boxed{RTT = 2T_p}$$

With ACK transmission:  
$$\boxed{RTT = 2T_p + T_{x,\text{data}} + T_{x,\text{ack}}}$$

> Satellite links → RTT dominates TCP performance.

##### **9. Summary**

**Transmission delay**
- If L in Mb, R in Mbps:  
	$T_x(\text{ms}) = \frac{L}{R} \times 1000$

**Propagation delay**
- At ( $v = 2 \times 10^8$ ) m/s:  
	$T_p(\text{ms}) = 5 \times d(\text{in 1000 km})$

**Core Difference**

| Aspect           | Transmission Delay ($T_x$) | Propagation Delay ($T_p$)   |
| ---------------- | -------------------------- | --------------------------- |
| Depends on       | Packet size, bandwidth     | Distance, medium            |
| Independent of   | Distance                   | Packet size                 |
| Physical meaning | Time to **send bits**      | Time for bits to **travel** |
| Controlled by    | Sender’s data rate         | Speed of signal             |
| Dominates in     | High-bandwidth links       | Long-distance links         |


##### **8. GATE-Style Numericals and Tips**

**Given:** L, R, d, v
* **Step 1:** Convert all units to **bits, seconds, meters**
* **Step 2:** Compute ($T_x = L / R$)
* **Step 3:** Compute ($T_p = d / v$)
* **Step 4:** Total delay = ($T_x + T_p$)

**Shortcut Formulas for GATE:**

1. ($T_x$) in milliseconds if L in Mb, R in Mbps:
   $T_x (\text{ms}) = \frac{L (\text{Mb})}{R (\text{Mbps})} \times 1000$
2. ($T_p$) in milliseconds if d in km, v in 10^8 m/s:
   $T_p (\text{ms}) = \frac{d (\text{km})}{v (10^8 \text{ m/s})} \times 5$
   (Approximation commonly used in GATE calculations)

**Important Tips:**

* For minimum (T_x) → maximize (R)
* For minimum (T_p) → minimize (d) or increase (v)
* Bandwidth-delay product tells you **how much data can be “in-flight”** before acknowledgment

##### **9. Example Problem**

**Problem:**
* L = 1 Mb, R = 10 Mbps, 
* d = 2000 km, v = 2 × 10^8 m/s

**Solution:**
-> $T_x = \frac{10^6}{10^7} = 0.1\ \text{sec}$
-> $T_p = \frac{2 \times 10^6}{2 \times 10^8} = 0.01\ \text{sec}$
-> $T_\text{total} = 0.1 + 0.01 = 0.11\ \text{sec}$
-> $\text{BDP} = 10^7 \cdot 0.01 = 10^5 \text{ bits}$

---

### **Critical Condition: ( $\boldsymbol{T_x \ge 2T_p}$ )** ⭐

> This condition appears **repeatedly** in **CSMA/CD** and **Stop-and-Wait analysis**, even though $(T_x)$ and $(T_p)$ are Physical Layer delays.


$$\boxed{T_x \ge 2T_p}  $$

**Meaning of the Condition**
	-> The **sender must keep transmitting long enough** so that a signal (or collision) from the farthest node can travel **to the receiver and back** before transmission ends.

##### **Why does ($2T_p$) appear?**

- ($T_p$): time for signal to travel **one way**
    
- Worst case:
    - Collision occurs at the **farthest node**
    - Collision information must return to sender  
        ->**Round-trip propagation delay = (2T_p)**
        

##### **A. Role in CSMA/CD (MOST IMPORTANT USE)**

**Collision Detection Requirement**

> For CSMA/CD to detect a collision, the sender **must still be transmitting** when the collision signal returns.

Hence,

$\boxed{T_x \ge 2T_p}$

Consequence:
- Determines **minimum frame size**  
    $L_{\min} = R \cdot 2T_p$
    
If $(T_x < 2T_p)$:
- Sender finishes transmission early
- Collision goes undetected ❌
- CSMA/CD fails

##### **B. Role in Stop-and-Wait**

In Stop-and-Wait, utilization depends on the relation between $(T_x)$ and $(2T_p)$:


$U = \frac{T_x}{T_x + 2T_p}$

**Cases:**

| Relation         | Effect                                |
| ---------------- | ------------------------------------- |
| $(T_x \ll 2T_p)$ | Very low utilization (long idle wait) |
| $(T_x = 2T_p)$   | Boundary condition                    |
| $(T_x \gg 2T_p)$ | High utilization                      |

-> Satellite links → ($2T_p$) dominates → poor Stop-and-Wait performance

##### **Where GATE Uses This Condition**

- Minimum frame size
- Ethernet design
- CSMA/CD correctness
- Stop-and-Wait utilization
- RTT-dominated links
