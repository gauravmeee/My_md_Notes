# Distributed Systems & Parallel Computing

| Topics                 | Subtopics                        |
| ---------------------- | -------------------------------- |
| Concepts               | Distributed characteristics      |
| Algorithms & Protocols | Consensus, synchronization       |
| Distributed DB Systems | Replication, consistency         |
| Parallel Processing    | Architectures                    |
| Parallel Programming   | Models and algorithms            |
| Security               | Fault tolerance, data protection |
# Concepts and Characteristics of Distributed Systems

## Concept

A **Distributed System** is a collection of independent computers that appear to users as a single coherent system. The components communicate and coordinate their actions through message passing to achieve a common goal.  
Example: Cloud computing platforms, distributed databases, peer-to-peer networks.

## Key Concepts

- **Resource Sharing:** Hardware, software, and data resources are shared among nodes.
    
- **Transparency:** The system hides complexity from users (location, replication, concurrency, etc.).
    
- **Concurrency:** Multiple processes execute simultaneously on different nodes.
    
- **Scalability:** System performance remains efficient as nodes or users increase.
    
- **Fault Tolerance:** System continues functioning correctly despite failures of components.
    
- **Synchronization:** Coordination of time and events across multiple nodes.
    
- **Communication:** Nodes interact via message passing (RPC, message queues, sockets).
    

## Characteristics

1. **Heterogeneity:** Composed of different hardware, OS, and networks.
    
2. **Openness:** System components interact through standard protocols and interfaces.
    
3. **Concurrency:** Many processes execute concurrently on multiple nodes.
    
4. **Scalability:** Supports expansion without performance degradation.
    
5. **Fault Tolerance:** Detects, masks, or recovers from failures automatically.
    
6. **Transparency Types:**
    
    - **Access Transparency:** Uniform access to local/remote resources.
        
    - **Location Transparency:** User unaware of resource location.
        
    - **Replication Transparency:** Multiple copies appear as one.
        
    - **Concurrency Transparency:** Multiple users access resources without conflict.
        
    - **Failure Transparency:** Continues operation despite component failure.
        
    - **Migration Transparency:** Resources/processes move without affecting operations.
        
    - **Performance Transparency:** System adjusts to optimize performance.
        
    - **Scaling Transparency:** System adapts to increase in size/load.
        

## Advantages

- Resource sharing and cost efficiency
    
- Improved reliability and availability
    
- Scalability and modular growth
    
- Better performance via parallelism
    

## Disadvantages

- Complexity in design and management
    
- Security and synchronization issues
    
- Network dependency
    
- Difficulty in debugging and consistency management

---
---

# Distributed Algorithms and Protocols

## Concept

**Distributed algorithms** are procedures enabling independent nodes in a distributed system to cooperate and achieve a common goal using message passing.  
**Distributed protocols** define the communication rules ensuring consistency, coordination, and fault tolerance.

## Key Design Issues

- **Synchronization:** Coordinating clocks or events.
    
- **Coordination:** Electing leaders, achieving consensus.
    
- **Mutual Exclusion:** Ensuring only one process accesses a shared resource at a time.
    
- **Fault Tolerance:** Handling node or communication failures.
    
- **Consistency:** Maintaining identical states across replicas.
    

## Important Distributed Algorithms

### 1. Clock Synchronization Algorithms

- **Cristian’s Algorithm:** A client synchronizes its clock with a time server using round-trip delay estimation.
    
- **Berkeley’s Algorithm:** All nodes adjust their clocks to the average time of the group.
    
- **NTP (Network Time Protocol):** Hierarchical time synchronization using stratum levels.
    

### 2. Mutual Exclusion Algorithms

- **Centralized Algorithm:** One coordinator grants access; simple but a single point of failure.
    
- **Ricart-Agrawala Algorithm:** Processes request permission from all others before entering critical section.
    
- **Token-Based Algorithm:** A unique token circulates; possession grants access to critical section.
    

### 3. Leader Election Algorithms

- **Bully Algorithm:** The process with the highest ID becomes leader after failures are detected.
    
- **Ring Algorithm:** Processes form a logical ring and pass election messages to elect a leader.
    

### 4. Consensus Algorithms

Used to ensure agreement among nodes even with failures.

- **Paxos:** Ensures consensus in asynchronous systems with crash failures.
    
- **Raft:** Simpler alternative to Paxos; divides nodes into leader, follower, and candidate roles.
    
- **Byzantine Fault Tolerance (BFT):** Ensures agreement even if some nodes act maliciously.
    

### 5. Distributed Deadlock Detection

- **Wait-for Graph (WFG):** Nodes share dependency graphs to detect cycles indicating deadlocks.
    
- **Edge-Chasing Algorithms:** Probes circulate among processes to detect circular waits.
    

### 6. Distributed Commit Protocols

- **Two-Phase Commit (2PC):** Coordinator asks all participants to prepare → commit/abort.
    
- **Three-Phase Commit (3PC):** Adds a pre-commit phase to reduce blocking in case of coordinator failure.
    

## Communication Protocols

- **Remote Procedure Call (RPC):** Allows calling procedures on remote machines.
    
- **Message-Oriented Communication:** Using message queues, sockets, or middleware (e.g., Kafka).
    
- **Gossip Protocols:** Nodes periodically share state information with random peers (used in fault detection and replication).
    
- **Group Communication Protocols:** Ensure reliable and ordered message delivery to a group (used in replicated databases).
    

## Goals

- Achieve **coordination, consistency, and reliability** among distributed nodes.
    
- Handle **failures, latency, and concurrency** effectively without centralized control.


---
---


# Distributed Database Systems

## Concept

A **Distributed Database System (DDBS)** is a collection of multiple logically interrelated databases distributed across different locations, connected by a computer network, and managed by a distributed database management system (DDBMS).  
It provides users with a single integrated view as if it were a single centralized database.

## Components

- **Local Databases:** Data stored at multiple sites.
    
- **DDBMS:** Software managing distribution, replication, and query execution.
    
- **Communication Network:** Connects the databases for data exchange.
    

## Characteristics

1. **Distribution Transparency:** Users access data without knowing its location.
    
2. **Replication Transparency:** Multiple copies of data appear as a single logical entity.
    
3. **Fragmentation Transparency:** Data may be split (fragmented) and stored at different sites.
    
4. **Concurrency Control:** Maintains data consistency with parallel transactions.
    
5. **Fault Tolerance:** System continues working despite site or network failures.
    

## Data Distribution Techniques

1. **Fragmentation:** Dividing database into fragments.
    
    - **Horizontal Fragmentation:** Rows based on predicates.
        
    - **Vertical Fragmentation:** Columns based on attributes.
        
    - **Hybrid Fragmentation:** Combination of both.
        
2. **Replication:** Storing copies of data at multiple sites for reliability and quick access.
    
3. **Allocation:** Assigning fragments or replicas to specific sites based on usage.
    

## Types

- **Homogeneous DDBS:** All sites use the same DBMS software.
    
- **Heterogeneous DDBS:** Different DBMS software and schemas at sites.
    
- **Federated DDBS:** Independent databases cooperate while retaining autonomy.
    

## Distributed Query Processing

- Queries are decomposed, optimized, and executed across multiple sites.
    
- Involves **data localization**, **query optimization**, and **result integration**.
    
- Objectives: Minimize data transfer and response time.
    

## Distributed Transaction Management

Transactions must satisfy **ACID** properties across all sites.

- **Two-Phase Commit (2PC):** Ensures atomicity across distributed nodes.
    
- **Concurrency Control:** Uses distributed locking or timestamp ordering.
    
- **Recovery:** Involves checkpoints and logs maintained at each site.
    

## Concurrency Control Methods

- **Distributed Locking:** Locks maintained globally.
    
- **Timestamp Ordering:** Operations ordered by global timestamps.
    
- **Optimistic Concurrency Control:** Validation-based approach minimizing locking.
    

## Advantages

- Improved reliability and availability
    
- Scalability and local autonomy
    
- Faster access for local queries
    
- Load balancing through data distribution
    

## Disadvantages

- Complex management and synchronization
    
- Higher communication overhead
    
- Difficult recovery and consistency maintenance
    
- Security and data integrity challenges

---
---

# Parallel Processing Architectures

## Concept

**Parallel processing** involves simultaneous execution of multiple tasks or sub-tasks to improve performance and efficiency.  
It exploits hardware and software concurrency using multiple processors or cores.

## Objectives

- Increase computational speed
    
- Improve throughput and resource utilization
    
- Handle large-scale data or computation-intensive tasks
    

## Classification (Flynn’s Taxonomy)

1. **SISD (Single Instruction Single Data):** Sequential execution on a single processor (traditional CPU).
    
2. **SIMD (Single Instruction Multiple Data):** Same instruction executed on multiple data simultaneously (e.g., GPUs, vector processors).
    
3. **MISD (Multiple Instruction Single Data):** Multiple instructions operate on the same data (rare, used in fault-tolerant systems).
    
4. **MIMD (Multiple Instruction Multiple Data):** Multiple processors execute different instructions on different data (used in clusters, multicore CPUs).
    

## MIMD Architectures

1. **Shared Memory Architecture:**
    
    - All processors share a global memory.
        
    - Communication via shared variables.
        
    - Examples: Multicore processors, symmetric multiprocessors (SMP).
        
    - Types:
        
        - **UMA (Uniform Memory Access):** Equal memory access time for all CPUs.
            
        - **NUMA (Non-Uniform Memory Access):** Access time depends on memory location.
            
2. **Distributed Memory Architecture:**
    
    - Each processor has its own local memory.
        
    - Communication via message passing (MPI).
        
    - Example: Cluster systems, supercomputers.
        
3. **Hybrid Architecture:**
    
    - Combines shared and distributed memory.
        
    - Example: Multi-node clusters with multi-core nodes.
        

## Parallel Processing Models

- **Data Parallelism:** Same operation performed on different data sets.
    
- **Task Parallelism:** Different tasks executed concurrently.
    
- **Pipeline Parallelism:** Tasks divided into stages forming a processing pipeline.
    

## Interconnection Networks

Defines how processors and memory modules are connected.

- **Bus-based:** Shared bus for communication.
    
- **Crossbar Switch:** Direct connection between any pair of processors and memory.
    
- **Multistage Networks:** e.g., Omega, Butterfly networks.
    
- **Hypercube / Mesh:** Processors arranged geometrically for scalability and low latency.
    

## Performance Metrics

- **Speedup (S):** ( S = T_s / T_p )
    
- **Efficiency (E):** ( E = S / N )
    
- **Scalability:** Ability to maintain performance with more processors.
    
- **Latency & Throughput:** Measures of communication delay and processing rate.
    

## Advantages

- Faster execution of large computations
    
- Efficient utilization of hardware resources
    
- High scalability and reliability
    

## Disadvantages

- Complex synchronization and communication
    
- Load balancing challenges
    
- Debugging and programming complexity

---
---

# Basics of Parallel Programming & Parallel Algorithms

## Concept

**Parallel programming** is the method of writing programs that divide tasks into subtasks executed simultaneously on multiple processors to reduce runtime.  
**Parallel algorithms** are designed to exploit concurrency efficiently by splitting computations across processors.

## Goals

- Reduce execution time
    
- Improve performance and scalability
    
- Utilize hardware resources effectively
    

## Steps in Parallel Programming

1. **Decomposition (Partitioning):** Divide the main problem into independent subproblems or tasks.
    
2. **Assignment (Mapping):** Distribute tasks among processors to balance load.
    
3. **Synchronization:** Coordinate execution to maintain data consistency.
    
4. **Communication:** Exchange required data among processors.
    
5. **Merging (Result Combination):** Combine partial results to form the final output.
    

## Types of Parallelism

1. **Data Parallelism:** Same operation on different data (e.g., matrix operations).
    
2. **Task Parallelism:** Different tasks executed simultaneously (e.g., pipeline stages).
    
3. **Pipeline Parallelism:** Output of one process is input to the next, executed in a pipeline.
    

## Parallel Programming Models

- **Shared Memory Model:** Threads access common memory (e.g., OpenMP, Pthreads).
    
- **Distributed Memory Model:** Each process has private memory; uses message passing (e.g., MPI).
    
- **Hybrid Model:** Combination of both shared and distributed memory.
    
- **Dataflow Model:** Computation triggered by availability of data.
    

## Parallel Algorithm Design Principles

1. **Divide and Conquer:** Recursively divide tasks into independent sub-tasks.
    
2. **Work and Depth Analysis:**
    
    - **Work (W):** Total operations performed.
        
    - **Depth (D):** Longest chain of dependent operations.
        
    - **Parallelism = W / D**
        
3. **Load Balancing:** Equal distribution of workload to minimize idle time.
    
4. **Minimize Communication:** Reduce inter-processor communication overhead.
    
5. **Avoid Synchronization Bottlenecks:** Minimize waiting times due to dependencies.
    

## Common Parallel Algorithms

- **Parallel Sorting:** Bitonic sort, parallel quicksort, merge sort.
    
- **Parallel Matrix Operations:** Matrix multiplication, LU decomposition.
    
- **Parallel Search:** Parallel binary search, branch and bound.
    
- **Parallel Graph Algorithms:** BFS/DFS, shortest path (e.g., parallel Dijkstra).
    
- **Reduction/Prefix Sum:** Used for aggregation and scanning problems.
    

## Performance Metrics

- **Speedup (S):** ( S = T_s / T_p )
    
- **Efficiency (E):** ( E = S / N )
    
- **Scalability:** Performance improvement with increased processors.
    
- **Overhead:** Time spent in communication and synchronization.
    

## Challenges

- Data dependency and race conditions
    
- Synchronization and communication overhead
    
- Load imbalance
    
- Debugging and testing complexity

---
---

# Distributed Systems Security

## Concept

**Distributed systems security** involves protecting data, resources, and communication across multiple interconnected nodes from unauthorized access, failures, or attacks.  
Since nodes are geographically dispersed and communicate over networks, ensuring confidentiality, integrity, and availability becomes complex.

## Security Goals

1. **Confidentiality:** Data accessible only to authorized users.
    
2. **Integrity:** Data cannot be altered or tampered with.
    
3. **Availability:** System and data remain accessible during failures or attacks.
    
4. **Authentication:** Verification of user or node identity.
    
5. **Authorization:** Granting permissions based on authenticated identity.
    
6. **Non-repudiation:** Proof that a message or action occurred.
    

## Security Challenges

- Lack of centralized control
    
- Insecure communication channels
    
- Heterogeneity of systems and platforms
    
- Node compromise or insider threats
    
- Synchronization and trust management issues
    

## Security Mechanisms

### 1. Authentication Mechanisms

- **Password-based Authentication:** Simple but weak against attacks.
    
- **Public Key Infrastructure (PKI):** Uses digital certificates and keys.
    
- **Kerberos:** Ticket-based centralized authentication protocol.
    
- **OAuth / SAML:** Token-based distributed authentication mechanisms.
    

### 2. Encryption

- **Symmetric Encryption:** Same key for encryption/decryption (e.g., AES, DES).
    
- **Asymmetric Encryption:** Public and private key pairs (e.g., RSA, ECC).
    
- **Hashing:** One-way functions for data integrity (e.g., SHA, MD5).
    
- **Digital Signatures:** Ensure authenticity and integrity of messages.
    

### 3. Access Control Models

- **DAC (Discretionary Access Control):** Owner defines access permissions.
    
- **MAC (Mandatory Access Control):** Central authority defines policies.
    
- **RBAC (Role-Based Access Control):** Access based on user roles.
    
- **ABAC (Attribute-Based Access Control):** Access based on user attributes and context.
    

### 4. Secure Communication Protocols

- **SSL/TLS:** Secure socket communication for data transfer.
    
- **IPSec:** Provides security at the network layer.
    
- **SSH:** Secure remote access to distributed nodes.
    
- **HTTPS:** Secure web-based communication.
    

### 5. Intrusion Detection & Prevention

- **Host-Based IDS:** Monitors activities on individual nodes.
    
- **Network-Based IDS:** Monitors traffic across distributed networks.
    
- **Firewalls:** Filter and control incoming/outgoing network packets.
    

### 6. Trust and Key Management

- **Certificate Authorities (CA):** Issue and validate digital certificates.
    
- **Key Distribution Centers (KDC):** Manage cryptographic keys.
    
- **Blockchain-based Trust Models:** Decentralized verification mechanisms.
    

## Security in Distributed Components

- **Distributed File Systems:** Secure replication, access control, and data encryption.
    
- **Distributed Databases:** Secure transactions, replication integrity, and audit logs.
    
- **Cloud and Grid Systems:** Virtualization security, isolation, and multi-tenant protection.
    

## Common Attacks

- **Eavesdropping:** Intercepting communication.
    
- **Man-in-the-Middle Attack:** Tampering with data in transit.
    
- **Denial of Service (DoS):** Overloading resources to make them unavailable.
    
- **Replay Attack:** Reusing valid data transmissions.
    
- **Spoofing:** Faking node or user identity.
    
- **Sybil Attack:** One node assumes multiple identities.
    

## Best Practices

- Use strong authentication and encryption
    
- Regular security updates and patching
    
- Implement redundancy and fault tolerance
    
- Continuous monitoring and intrusion detection
    
- Principle of least privilege for access control

