
Wireless networks use radio frequency channels as 
their physical medium for communications.

> PPT - MANET-DV-DSDV
## Wireless Network Types
1. **Infrastructure-based wireless networks**
	- Uses Fixed Base stations/access points 
	- Access point are responsible for coordinating communication between hosts.
	- Single-hop communications
1. **Infrastructure-less wireless networks  (Ad-hoc networks)**
	- No fixed infrastructure support are available
	- Consist of nodes which communicates with  each other through wireless medium without any fixed infrastructure
	- Multi-hop communications
1. **Hybrid wireless networking architecture**

## Ad-hoc network

**Properties of ad-hoc networks**
- No pre-build infrastructure
- All nodes are wireless capable
- Base station are not necessary
- Easy of Deployment
- Quickly deploy

**Some Emerging types of wireless networks**
- MANETs (Mobile Ad-hoc Networks)
- WSNs (Wireless Sensor Networks)
- VANET (Vehicle Ad-hoc Networks)
- WMN (Wireless Mesh Networks)

# Routing protocols for Wireless networks - MANETs

#### Main Issues
1. MANETs are more **unstable** than wired-networks because of the lack of a centralized entity
2.  Mobility will cause network **topology to change**, which results in a great change in connection between two hosts.
3. Between network nodes **connectivity  is not guaranteed**, so intermittent connectivity is common

**Properties of ad-hoc networks :**
1. Topology may be quite dynamic
2. No administrative host
3. Hosts with finite power

**Properties of ad-hoc network Routing Protocol**
- Simple
- Less storage space
- Loop free
- Short control message (Low overhead)
- Less power consumption
- Multiple disjoint routes
- Fast rerouting mechanism



# Routing Protocol

### 1. Proactive (Table-driven)
- **Periodic updates:** based on periodic exchange of control messages and maintaining routing tables.
- have complete information about the network topology locally
- **Exchange of Routing table:** The information is collected through proactive exchange of partial routing tables stored at each node
- **Low Latency / Fast:** Since each node knows the complete topology, a node can immediately find the best route to a destination
-  **High Bandwidth consumption** control messages may consume almost the entire bandwidth because of large volume of control messages, large no. of nodes and increased mobility. 

- ex Routing protocols for MANETs 
	1. Destination Sequenced Distance Vector (DSDV)
	2. Cluster head gateway switch routing protocol (CGSR)
	3. Wireless Routing Protocol (WRP)
### 2. Reactive (Source-initiated on-demand)
- **On demand:** route is discovered only when it is necessary
- **Less Bandwidth consumption:** much less control traffic at the cost of latency
- **High Latency** It usually takes more time to find a route compared to a proactive protocol.
- ex Routing protocols for MANETs 
	1. Dynamic Source routing (DSR)
	2. Ad-hoc On-demand Distance Vector (AODV)
	3. Temporally Ordered Routing Algorithm (TORA)
	
# Routing Algorithm
### 1. Link-State Algorithm
- Each node maintains a view of the network topology (with a cost for each link)
- Periodically broadcast link costs to its outgoing links to all other nodes such as flooding
	
### 2. Distance-Vector algorithm
- Also known as Distributed Bellman-Ford or RIP (Routing Information Protocol)
- Each node maintains a routing table contains 
	1. All available destinations
	2. The next node to reach to destination
	3. The no. of hops to reach the destination
- Periodically send table to all neighbors to maintain topology

##### Problems with Distance Vector

1. **Routing Loop :** 
	- Distance Vector protocols may encounter routing loops, where packets circulate between routers endlessly due to inconsistent or outdated routing information.
1. **Count to Infinity Problem** : 
	- Occurs when a link failure or network issue is propagated through the network.
	- Routers incrementally update their distance metrics, resulting in an endless increase toward infinity.

Example
```
Routing Loop  Problem
      A                     A 
    ⬈  ⬉                 ⬈  
  ⬋      ⬊             ⬋      
B ⭠-----⭢ C          B ⭠-----⭢ C

Consider a network with three routers: A, B, and C, connected in a triangle topology:

- Initially, all routers know the shortest path to each other.

Routing Loop Example:

1. The link between A and C fails.
2. A updates its routing table, removing C as a reachable destination.
3. However, B still has an outdated route to C via A and advertises it to A.
4. A believes it can reach C via B, creating a loop between A and B, where packets for C circulate endlessly.

Count-to-Infinity Example:

1. When the link between **A** and **C** fails, **A** sets its distance to **C** as infinite.
2. **B**, unaware of the failure, advertises its route to **C** (via **B**) with a distance of 2.
3. **A** updates its table, thinking it can reach **C** through **B** with a distance of 3.
4. This process continues, with the distance to **C** incrementing indefinitely (or until it reaches the protocol-defined maximum, such as 16 in RIP).
```

The formation of loops and the problem of counting to infinity are due  to the use of old information about the network

- This issue arises because distance-vector routing protocols share only the distance metrics (e.g., hop count) and not the path information (i.e., the exact route through which the destination is reached).

New Solution -> Distance Vector + Time stamp -> DSDV Protocol

**Timestamps**
- This avoids looping and counting to infinity
- Whenever a link breaks, the affected Node `A` updates its routing table and broadcasts the new information.
- Each time a node broadcasts its routing table, it adds an increasing **sequence number** (timestamp) to the broadcast
- Any node receiving the broadcast rejects old routing information and takes the new  information for updating its routing table
- The broadcasts are done through a **flooding scheme**.

# DSDV 

**Type**: Table-Driven (Proactive)  
**Algorithm**: Distance Vector (Enhanced Bellman-Ford)

**Overview**
- DSDV routing protocol is an enhanced version of the distributed Bellman-Ford algorithm (where each node maintain a table that contain the shortest distance and the first node on the shortest path to every other node in the network.)
- Each node's routing table contains:
	1. Next Hop
	2. Cost Metric (e.g., hops, delay, data rate, congestion)
	3. Sequence Number (assigned by the destination to ensure freshness)

##### Routing Table Maintenance :
- **Periodic Updates**: Nodes share their routing tables with neighbors periodically or upon changes.
- **Sequence Numbers**:
	- Each route table entry in S is tagged with a sequence number that is originated by the destination node. 
	- Routes with higher sequence numbers are prioritized.
	- A node increments the sequence number for its advertised routes. ⭐
	- Upon link breakage, the sequence number is incremented, and the route is advertised with an infinite metric. ⭐
	- The destination advertises a new sequence number for updated routes ⭐


```
(x) <-------- (Y)         (Z)

When X receives information from Y about a route to Z

1- S(X)>S(Y) : then X ignores the routing information 
received from Y 
2- S(X)=S(Y) : X sets Y as the next hop to Z (only if cost of going through Y is smaller than 
the route known to X)
3- S(X)<S(Y) : then X sets Y as the next hop to Z, and S(X) is updated to equal S(Y)
```


#### Key Features

- **Loop-Free Paths**: Guaranteed by sequence numbers.
- **Fast Propagation**: Broken link information is quickly disseminated.
- **Efficient Metric Updates**: Broadcasts only lower-cost updates.
##### Advantages of DSDV
1. **Very Low latency for route Discovery** whenever a route to a new destination is required, it already exists at the source
2. guarantees loop-free paths.
##### Disadvantages of DSDV 
1. **High volume of traffic for high-density and highly mobile networks** Send a lot of control messages (important for maintaining the network topology at each node)


**To prevent the bandwidth to be taken up by control traffic** is to avoid excessive control traffic (route update information) in such networks.

##### Solution/Optimization :
1. **Full Dump:** Infrequent, broadcasts the complete routing table.
2. **Incremental dump** : Frequent, broadcasts only changes since the last full dump. When incremental data grows too large, a full dump is preferred.


```
  
 ┌─------x---------┐
 |                 ˅
i -------y-------> j
 |                 ˄
 └-------z---------┘

- A node i may receive the same update message from another node j through several different paths.

- Suppose, one of the updates has a lowest distance to j

- It is better to avoid broadcasting every new update and instead broadcast only the lower metric updates ⭐
```
