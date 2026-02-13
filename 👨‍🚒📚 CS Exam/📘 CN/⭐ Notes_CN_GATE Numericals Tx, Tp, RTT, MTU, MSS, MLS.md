# ⭐ Notes\_CN\_GATE Numericals Tx, Tp, RTT, MTU, MSS, MLS

#### All Formulas Overview

**1. Transmission Delay** $\boxed{T\_x = \frac{L}{R\}}$

* $T\_x$: Time to serialize all bits of a packet onto the link:
* $L$ = Packet / segment size (bits)
* $R$ = Link bandwidth (bits/sec)
* $T\_{x,\min} = \frac{L}{R\_{\max\}}$
* Effect of segment size:
  * Larger segments → higher $T\_x$, more efficient ❓
  * Smaller segments → lower $T\_x$, higher header overhead ❓

**2. Propagation Delay** $\boxed{T\_p = \frac{d}{v\}}$

* $T\_p$: Time for one bit to travel from sender to receiver:
* $d$ = Distance (m)
* $v$ = Propagation speed (\~$2 \times 10^8$ m/s in fiber/copper, $3 \times 10^8$ m/s in air)
* $T\_{p,\min} = \frac{d\_{\min\}}{v\_{\max\}}$

**3. Total Packet Delay** $\boxed{T\_{\text{total\}} = T\_x + T\_p}$

* First bit arrival: $T\_{\text{first bit\}} = T\_p$
* Last bit arrival: $T\_{\text{last bit\}} = T\_x + T\_p$

**4. Round Trip Time (RTT)**

* Ignoring ACK transmission: $\boxed{RTT = 2T\_p}$ ⭐
* Including ACK transmission: $\boxed{RTT = 2T\_p + T\_{x,\text{data\}} + T\_{x,\text{ack\}}}$

**5. Bandwidth-Delay Product (BDP)** $\boxed{\text{BDP} = R \times T\_p}$ ⭐

* $BDP$: Max number of bits in-flight
* **Minimum TCP window** to fully utilize link: $\text{TCP window size} \geq \text{BDP}$
* Number of segments in-flight: $n = \frac{\text{BDP\}}{\text{MSS\}}$

**6. MTU / MLS / MSS**

* **$MTU$ (Maximum Transmission Unit):** ==Max frame size a link can carry (bytes)==
* **$MLS$ (Maximum Link/Segment Size):** ==Largest segment/frame link allows== $\boxed{ \leq MTU}$
* **$MSS$ (Maximum Segment Size)** $\boxed{\text{MSS} = \text{MLS} - \text{IP Header} - \text{TCP Header\}}$
* Impact on $T\_x = \frac{\text{Segment Size (including headers)\}}{R}$
* **CSMA/CD** ==**minimum frame size**==: $\boxed{L\_{\min} = R \times 2T\_p}$ ⭐

**7. Store-and-Forward / Multiple Links**

* 1 packet across k links: $\boxed{T = k(T\_x + T\_p)}$
* n packets across k links: $\boxed{T = k(T\_x + T\_p) + (n-1)T\_x}$
* Cut-through switching (first packet delay): $T\_{\text{first\}} \approx T\_p + \text{header transmission}$

**8. CSMA/CD & Stop-and-Wait**

* Collision detection requirement: $\boxed{T\_x \geq 2T\_p}$
* \==Stop-and-Wait utilization==: $\boxed{U = \frac{T\_x}{T\_x + 2T\_p\}}$ ⭐
* Minimum frame size for Ethernet / CSMA/CD: $L\_{\min} = R \times 2T\_p$

**9. End-to-End Delay Components** $\boxed{T\_{\text{end-to-end\}} = \sum T\_x + \sum T\_p + \sum T\_q + \sum T\_{\text{process\}}}$

* $T\_x$ = Transmission delay
* $T\_p$ = Propagation delay
* $T\_q$ = Queuing delay
* $T\_{\text{process\}}$ = Processing delay

**Shortcut / GATE-Friendly Formulas ⭐**

1. $T\_x$ in ms: $\boxed{T\_x (\text{ms}) = \frac{L(\text{Mb})}{R(\text{Mbps})} \times 1000}$
2. $T\_p$ in ms (d in km, v ≈ $2 \times 10^8$ m/s): $\boxed{T\_p (\text{ms}) \approx 5 \times d (\text{1000 km})}$
3. Minimum frame size for collision detection: $\boxed{L\_{\min} = R \times 2T\_p}$
4. Number of in-flight segments: $\boxed{n = \frac{\text{BDP\}}{\text{MSS\}}}$

***

## Transmission & Propagation Delay

> Transmission and propagation delays **belong to the Physical Layer**, but CSMA/CD and Stop-and-Wait _depend_ on them for correctness and performance — that’s why questions appear under those protocols.

**1. Transmission Delay $(Tx)$**

**Definition:** Time required to **serialize** ==(push) all bits of a packet== onto the link.

$$\boxed{T_x = \frac{L}{R}}$$

* $L$ = Packet size (bits)
* $R$ = Link bandwidth / transmission rate (bits/sec)

**Key Properties:**

* Depends on **packet size (L)** and **link (Bandwidth) rate (R)**
  * Larger packet → higher $(T\_x)$
  * Higher bandwidth → lower $(T\_x)$
* Independent of distance
* Also called **serialization delay**

**Minimum Transmission Time:**

* Occurs when bandwidth is maximum for a given packet: $T\_{x, \min} = \frac{L}{R\_\text{max\}}$

**Example:**

* $L = 8\text{ Mb},\ R = 4\text{ Mbps} \implies T\_x = \frac{8 \times 10^6}{4 \times 10^6} = 2\ \text{sec}$

**2. Propagation Delay $(Tp)$**

**Definition:** Time taken by **o==ne bit** to propagate from sender to receiver ==or Time taken for a bit to travel from sender to receiver.

$$\boxed{T_p = \frac{d}{v}}$$

* $d$ = distance (meters)
* $v$ = propagation speed in medium $\~2\times10^8$ m/s in copper/fiber, $3\times10^8$ m/s in air

**Key Properties:**

* Depends on **distance** and **medium**, not on packet size.
  * Long-distance links → $(T\_p)$ dominates
  * Short links → $(T\_x)$ dominates
* Independent of packet size and bandwidth
* Typical values: Fiber/Copper: $( v \approx 2 \times 10^8 ) m/s$ Air/Vacuum: $( 3 \times 10^8 ) m/s$

**Minimum Propagation Time:**

* Occurs when distance is minimum and speed is maximum: $T\_{p, \min} = \frac{d\_\text{min\}}{v\_\text{max\}}$

**Example:**

* $d = 1000\text{ km},\ v = 2 \times 10^8 \text{ m/s} \implies T\_p = \frac{1000 \times 10^3}{2 \times 10^8} = 0.005\ \text{sec}$

**Total Time to Send a Packet $(T\_\text{total})$**

$$\boxed{T_\text{total} = T_x + T_p}$$

**Observation:** ⭐

* **LAN (short distance, high bandwidth)**\
  → $( T\_p )$ is **very small**, $( T\_x )$ may dominate Ex: For LAN: ($T\_x >> T\_p)$
* **WAN / Satellite (long distance)**\
  → $( T\_p )$ dominates Ex: For satellite: $(T\_p >> T\_x)$

**Time for First Bit vs Last Bit**

* **First bit arrival time:** $T\_{\text{first bit\}} = T\_p$
* **Last bit arrival time:** $T\_{\text{last bit\}} = T\_x + T\_p$ ⭐

> This is **frequently tested in GATE**. GATE often asks: _“When does the receiver get the complete packet?”_

**Bandwidth–Delay Product $(BDP)$ ⭐⭐**

**Definition:** Number of bits that can be present “in-flight” in the link at any instant.

$$\boxed{\text{BDP} = R \times T_p}$$

* Number of bits **present in the link simultaneously**

```
Rate at which source sending bits (bits/sec)
   x
Time for one bit to reach destination  (sec)
   =
bits not yet reached destination but midway (bits)
```

* Equals **minimum TCP window size** to fully utilize the link ⭐

```
TCP window size ≥ BDP (to fully utilize link)
```

* Reason:
  * TCP window size = max bits sender can send without ACK
  * If ( TCP window size < BDP ) -> sender stops sending before the “in-flight” capacity of the link is full -> Some link capacity remains idle -> Throughput < R (link rate)

**Significance:**

* Helps design buffer size in routers
* Indicates how many bits are “on the wire”

**Example:**

* $R = 10 \text{ Mbps},\ T\_p = 0.01\text{ sec} \implies \text{BDP} = 10^7 \times 0.01 = 10^5 \text{ bits}$

> If window < BDP → link underutilized (very common GATE concept)

**6. Effect of Packet Segmentation (Pipelining) / Multiple Packets**

**Case 1: Single link, no store-and-forward**

* For **multiple packets sent back-to-back**, total transmission time for (n) packets: $T = nT\_x + T\_p$
* If pipelining (like TCP windowing), $(T\_p)$ can be **overlapped**, so effective total time for large (n): $(T ≈ n \cdot T\_x)$

**Case 2: Store-and-Forward, k links (VERY IMPORTANT)**

* For **1 packet** across k links: $T = k(T\_x + T\_p)$
* For **n packets**:\
  $T = k(T\_x + T\_p) + (n-1)T\_x$

> This is **one of the most asked GATE formulas**.

**Case 3: Cut-through switching (rare but asked)**

* Transmission overlaps
* Delay < store-and-forward
* First packet delay ≈ $( T\_p + \text{header transmission} )$

**7. Delay Components in Networks / End-to-End Delay**

1. **Transmission delay:** $(T\_x = \frac{L}{R})$
2. **Propagation delay:** $(T\_p = \frac{d}{v})$
3. **Queuing delay:** Time spent waiting in router queues
4. **Processing delay:** Time routers take to process headers

**Total end-to-end delay:**

* $T\_{\text{end-to-end\}} = \sum T\_x + \sum T\_p + \sum T\_q + \sum T\_{\text{process\}}$
* $T\_\text{end-to-end} = T\_x + T\_p + T\_\text{q} + T\_\text{process}$

Where:

* $( T\_q )$: Queuing delay (variable, load-dependent)
* $( T\_{\text{process\}} )$: Header processing (small but non-zero)

> GATE usually **ignores** queue & processing **unless specified**.

**8. Round Trip Time (RTT)**

**Definition :** It is the total time taken for a data packet to travel from the sender to the receiver **and** for the corresponding acknowledgment (ACK) to travel back to the sender.

**Ignoring ACK Tx**

$$\boxed{RTT = 2T_p}$$

With ACK transmission:\
$$\boxed{RTT = 2T_p + T_{x,\text{data}} + T_{x,\text{ack}}}$$

> Satellite links → RTT dominates TCP performance.

**9. Summary**

**Transmission delay**

* If L in Mb, R in Mbps:\
  $T\_x(\text{ms}) = \frac{L}{R} \times 1000$

**Propagation delay**

* At ( $v = 2 \times 10^8$ ) m/s:\
  $T\_p(\text{ms}) = 5 \times d(\text{in 1000 km})$

**Core Difference**

| Aspect           | Transmission Delay ($T\_x$) | Propagation Delay ($T\_p$)  |
| ---------------- | --------------------------- | --------------------------- |
| Depends on       | Packet size, bandwidth      | Distance, medium            |
| Independent of   | Distance                    | Packet size                 |
| Physical meaning | Time to **send bits**       | Time for bits to **travel** |
| Controlled by    | Sender’s data rate          | Speed of signal             |
| Dominates in     | High-bandwidth links        | Long-distance links         |

**GATE-Style Numericals and Tips**

**Given:** L, R, d, v

* **Step 1:** Convert all units to **bits, seconds, meters**
* **Step 2:** Compute ($T\_x = L / R$)
* **Step 3:** Compute ($T\_p = d / v$)
* **Step 4:** Total delay = ($T\_x + T\_p$)

**Shortcut Formulas for GATE:**

1. ($T\_x$) in milliseconds if L in Mb, R in Mbps: $T\_x (\text{ms}) = \frac{L (\text{Mb})}{R (\text{Mbps})} \times 1000$
2. ($T\_p$) in milliseconds if d in km, v in 10^8 m/s: $T\_p (\text{ms}) = \frac{d (\text{km})}{v (10^8 \text{ m/s})} \times 5$ (Approximation commonly used in GATE calculations)

**Important Tips:**

* For minimum $T\_x$ → maximize $R$
* For minimum $T\_p$ → minimize $d$ or increase $v$
* Bandwidth-delay product tells you **how much data can be “in-flight”** before acknowledgment

***

#### **Critical Condition: ( $\boldsymbol{T\_x \ge 2T\_p}$ )** ⭐

> This condition appears **repeatedly** in **CSMA/CD** and **Stop-and-Wait analysis**, even though $(T\_x)$ and $(T\_p)$ are Physical Layer delays.

$$\boxed{T_x \ge RTT = 2T_p}$$

**Meaning of the Condition** -> The **sender must keep transmitting long enough** so that a signal (or collision) from the farthest node can travel **to the receiver and back** before transmission ends.

**Why does ($2T\_p$) appear?**

* ($T\_p$): time for signal to travel **one way**
* Worst case:
  * Collision occurs at the **farthest node**
  * Collision information must return to sender\
    ->**Round-trip propagation delay = $2T\_p$**

**A. Role in CSMA/CD (MOST IMPORTANT USE)**

**Collision Detection Requirement**

For CSMA/CD to detect a collision, the sender **must still be transmitting** when the collision signal returns.

Hence,

$\boxed{T\_x \ge 2T\_p}$

Consequence:

* Determines **minimum frame size**\
  $L\_{\min} = R \cdot 2T\_p$

If $(T\_x < 2T\_p)$:

* Sender finishes transmission early
* Collision goes undetected ❌
* CSMA/CD fails

**B. Role in Stop-and-Wait**

In Stop-and-Wait, utilization depends on the relation between $(T\_x)$ and $(2T\_p)$:

$U = \frac{T\_x}{T\_x + 2T\_p}$

**Cases:**

| Relation           | Effect                                |
| ------------------ | ------------------------------------- |
| $(T\_x \ll 2T\_p)$ | Very low utilization (long idle wait) |
| $(T\_x = 2T\_p)$   | Boundary condition                    |
| $(T\_x \gg 2T\_p)$ | High utilization                      |

-> Satellite links → ($2T\_p$) dominates → poor Stop-and-Wait performance

**Where GATE Uses This Condition**

* Minimum frame size
* Ethernet design
* CSMA/CD correctness
* Stop-and-Wait utilization
* RTT-dominated links

***

### Transmission & MTU / MSS / MLS

**MTU (Maximum Transmission Unit)**

* **Maximum frame size** that a **link layer protocol can carry.**
* **Example:** Ethernet → MTU = 1500 bytes.
* Limits the maximum IP packet size, which in turn limits TCP segment size / MLS.

**MLS (Maximum Link / Segment Size)**

* **Largest allowed segment** or frame a **link can transmit** in a single transmission.
* Often determined by MTU.
* Ensures minimum transmission time for CSMA/CD / Stop-and-Wait:

$$\text{MLS} \geq L_{\text{min}} = R \times 2T_p$$

* TCP segment size must not exceed MLS; otherwise, fragmentation occurs.

**MSS (Maximum Segment Size / Largest Segment Size)**

* **Maximum TCP payload that can fit inside IP packet** without fragmentation:

$$\text{MSS} = \text{MLS} - \text{IP Header} - \text{TCP Header}$$

* Example: Ethernet MTU = 1500B → MLS = 1500B, IP header = 20B, TCP header = 20B → MSS = 1460B

**Impact on Transmission Delay ($T\_x$)**

* Transmission delay is proportional to segment size ($L$):

$$T_x = \frac{L}{R} \text{ , } L = \text{TCP Segment Size (including TCP/IP headers)}$$

* Smaller segments → smaller $T\_x$, more header overhead
* Larger segments (near MLS) → higher $T\_x$, fewer headers → better efficiency
* Minimum frame size / minimum $T\_x$ in CSMA/CD:

$$L_{\text{min}} = R \times 2T_p$$

* If MTU / MLS < $L\_{\text{min\}}$, padding is required to detect collisions.

**Bandwidth-Delay Product (BDP) & MSS**

* BDP tells how many bits can be "in-flight" in the link.
* TCP window must accommodate multiple segments if MSS < BDP:

$$\text{Number of segments in-flight} = \frac{\text{BDP}}{\text{MSS}}$$

* Large MLS / MSS → fewer segments → better pipelining efficiency.

**Propagation Delay vs MTU / Segment Size**

* Large segments (near MLS / MTU) → higher $T\_x$ → can overlap with $T\_p$ → better link utilization.
* Small segments → low $T\_x$ → $T\_p$ dominates → poor Stop-and-Wait or CSMA/CD utilization.

**Example Including MTU / MLS**

**Link:** R = 10 Mbps, $T\_p$ = 0.01 s, MTU / MLS = 1500B (12,000 bits)

$$T_x = \frac{L}{R} = \frac{12,000}{10,000,000} = 0.0012 \text{ s}$$

$$T_p = 0.01 \text{ s}$$

$$\text{BDP} = R \times T_p = 10,000,000 \times 0.01 = 100,000 \text{ bits}$$

**Number of segments in-flight to fully utilize link:**

$$n = \frac{\text{BDP}}{L} = \frac{100,000}{12,000} \approx 9 \text{ segments}$$

**Integration with CSMA/CD / Stop-and-Wait**

* Minimum frame size: $L\_{\text{min\}} = R \times 2T\_p$
* MLS / MTU must allow minimum $L\_{\text{min\}}$, otherwise padding is required.
* Stop-and-Wait utilization improves if segment size ≈ MLS / MTU to maximize $T\_x$.
