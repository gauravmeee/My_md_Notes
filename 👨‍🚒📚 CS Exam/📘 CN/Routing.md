
### Bellman-Ford Algorithm vs Dijkstra's Algorithm.

##### **1. Distance Vector Routing Protocols**:
   - **Algorithm Used**: **Bellman-Ford Algorithm**
   - **Why?**:
     - Nodes share only distance vectors (not the entire topology).
     - Suitable for distributed, iterative updates over time.
     - Example Protocols: **RIP (Routing Information Protocol)**.

##### **2. Link State Routing Protocols**:
   - **Algorithm Used**: **Dijkstra's Algorithm**
   - **Why?**:
     - Each node has complete knowledge of the network topology (link states).
     - Computes the shortest path tree from the source to all destinations.
     - Example Protocols: **OSPF (Open Shortest Path First)**, **IS-IS**.


| Feature                | Bellman-Ford (Distance Vector)      | Dijkstra (Link State)                      |
| ---------------------- | ----------------------------------- | ------------------------------------------ |
| **Information Shared** | Distance vectors (next-hop, cost).  | Complete topology (link states).           |
| **Convergence Speed**  | Slower, due to iterative updates.   | Faster, once link states are known.        |
| **Complexity**         | `O(V * E)`                          | `O(V^2)` (or better with priority queues). |
| **Loop Avoidance**     | Prone to loops (count-to-infinity). | Less prone to loops.                       |

##### Why Confusion Happens:
- Both algorithms are used in **shortest path calculations**, but they are applied in different routing protocols.
- **Dijkstra's Algorithm** is often incorrectly associated with distance-vector protocols because both deal with shortest path routing, but the key distinction lies in the **information exchanged and network model**.

---

# [Lec-58: Distance vector routing algorithm in hindi | Computer Networks](https://youtu.be/5ZuP5qjbKSI)

# [Lec-59: Count to Infinity Problem in Distance Vector Routing](https://www.youtube.com/watch?v=UYASPR4jEkk&ab_channel=GateSmashers)
# [Lec-60: Link state routing in computer networks in Hindi](https://youtu.be/kW6zV-040SY)

