


| Subject                                        | Approximate Weightage (marks or %) |
| ---------------------------------------------- | ---------------------------------- |
| General Aptitude                               | 15 marks                           |
| [[#2. **Engineering / Discrete Mathematics**]] | ~13 – 15 marks                     |
| [[#3. **Programming & Data Structures**]]      | ~9 – 10 marks                      |
| [[#4. **Algorithm**]]                          | ~8 – 9 marks                       |
| [[#5. **OS**]]                                 | ~9 – 10 marks                      |
| [[#6. **CN**]]                                 | ~8 – 9 marks                       |
| [[#7. **DBMS**]]                               | ~7 – 8 marks                       |
| [[#8. **COA**]]                                | ~7 – 8 marks                       |
| [[#9. **TOC**]]                                | ~6 – 8 marks                       |
| [[#10. **CD**]]                                | ~5 – 7 marks                       |
| [[#11. **DE**]]                                | ~4 – 6 marks                       |


### 1. **General Aptitude**

---

### 2. **Engineering / Discrete Mathematics**

**Theory**  
- Propositional and first-order logic basics  
- Sets, relations, functions, equivalence relations, partial order  
- Counting principles: permutations, combinations, pigeonhole  
- Graph theory fundamentals: connectivity, degree, trees, bipartite, Euler/Hamilton  
- Algebraic structures basics: groups, rings, fields  
- Probability concepts: conditional, independence, Bayes, expectation/variance  
- Recurrences and generating functions fundamentals  
- Limits and linear algebra fundamentals

**Application-Based**  
- Determine validity of logical arguments using implication/contradiction  
- Identify type of relation (reflexive/symmetric/transitive/equivalence/partial order) from domain  
- Detect isomorphism, bipartite property, cut-vertex, articulation points  
- Infer chromatic number / matching / independent set from small graphs  
- Determine type of group / subgroup / cyclic structure from closure table  
- Predict convergence pattern in recurrence / generating function model  
- Trace inclusion-exclusion for overlapping sets to derive count

**Numerical / Proof-Based**  
- Solve recurrence relations (substitution, characteristic equation, Master-style)  
- Calculate probability, expectation, variance, Bayes theorem  
- Solve combinatorics problems using binomial method and inclusion–exclusion  
- Count paths in DAG, spanning trees using Matrix Tree Theorem (when asked)  
- Compute adjacency/degree matrices properties for graph questions  
- Linear algebra problems: rank, inverse, determinant, eigenvalues (as per GATE scope)  
- Solve systems using matrices (Gaussian elimination) where relevant  
- Calculate generating function coefficients for recurrence count problems

**Logic-Construction** (high scoring and matches modern GATE pattern)  
- Form CNF/DNF/PDNF using logical equivalences  
- Construct truth table, principal conjunctive/disjunctive normal form  
- Build finite graphs to satisfy constraints (edges/nodes/degree pattern)  
- Create counting model with recurrence or inclusion–exclusion from story-based question  
- Build probability sample space and random variable model from word-statements  
- Design function composition chains and compute number of onto/into functions  
- Construct Hasse diagram for partial orders from relation table

---
### 3. **Programming & Data Structures**

**Theory**  
- C language fundamentals: variables, pointers, arrays, structures, unions  
- Parameter passing, recursion basics, memory layout (stack/heap/static)  
- Stack, queue, linked list, tree, graph, heap concepts  
- Searching & sorting principles  
- Hashing fundamentals: collision resolution, load factor  
- BST and AVL properties, rotations  
- Generic properties of data structures: time–space trade-offs

**Application-Based**  
- Trace C code and predict exact output (arrays, pointers arithmetic, double pointers)  
- Predict recursion call pattern and final returned value  
- Determine final linked list state after insert/delete operations  
- Infer post/in/order/level traversal from printed sequence  
- Track stack/queue behavior in infix–postfix conversion or expression evaluation  
- Predict heap state after series of insert/delete-max operations  
- Determine whether BST / AVL property is satisfied after updates

**Numerical / Complexity-Based**  
- Time and space complexity of loops, nested loops, recursion  
- Recurrence solving for recursive programs  
- Maximum/minimum number of nodes/levels in BST/heap/complete tree  
- Number of rotations in AVL balancing  
- Expected probe count in hashing (linear/quadratic/double)  
- Amortized complexity of dynamic array / heap operations  
- Cost of operations in union-find, tries, segment tree (when applicable)

**Implementation-Logic Based (high scoring and frequently asked)**  
- Formulate recursive logic for tree + graph traversal  
- Convert iterative code to recursive and vice-versa  
- Write or reason through pointer-based code for linked list reversal, loop detection, merging  
- Implement stack/queue using array, linked list, two stacks, two queues  
- Construct priority queue using heap from array (heapify steps)  
- Design hashing with chaining and open addressing structure  
- Decide correct data structure choice for given constraints (ordered / dynamic / fast search / fast update)

---
### 4. **Algorithm**

**Theory**  
- Asymptotic notation and growth rates  
- Sorting algorithms properties: stability, comparison limits, lower bounds  
- Searching fundamentals, BFS/DFS characteristics  
- Graph theory algorithm properties: MST, SSSP, APSP  
- Greedy vs DP vs Divide-and-Conquer characteristics  
- NP, P, NP-Complete, NP-Hard theory and reductions  
- Amortized analysis concepts

**Application-Based**  
- Identify correct algorithm category (Greedy / DP / BFS / DFS / D&C) for given problem statement  
- Determine algorithm behavior/output on custom input (merge sort recursive split, quicksort pivot behavior, BFS/DFS traversal order, heap operations effect)  
- Detect minimum spanning tree output from sequence of edge choices  
- Identify relaxation pattern in Dijkstra/Bellman-Ford from intermediate table  
- Determine correctness of greedy choice / subproblem optimality for DP  
- Predict effect of hash collision behavior or union-find operations order  
- Identify whether recurrence implies greedy possible or DP required

**Numerical / Complexity-Based**  
- Complexity of nested loops, recursion, divide-and-conquer recurrences (Master theorem)  
- Complexity of BFS/DFS/Topological sort/MST/Shortest path algorithms  
- Complexity of sorting algorithms in average/worst/best cases  
- Counting comparisons/moves in sorting, merging, partitioning  
- Cost of operations in amortized structures (dynamic array, binary heap, disjoint sets)  
- Probability-based cost for randomized algorithms (randomized quicksort expected comparisons)

**Design-Based** (high scoring and frequently asked)  
- Construct recurrence relation for given algorithm  
- Design greedy choice or DP state + recurrence for optimization problem  
- Formulate backtracking/branch-and-bound decisions for search/pruning  
- Design union-find with path compression + union by rank  
- Construct heap from array / heapify steps / k-way merge logic  
- Construct adjacency list/matrix based graph representations for memory and complexity tradeoff

### 5. **OS**

**Theory**  
- Types of OS  
- Process vs Thread  
- System calls and Kernel  
- Deadlock: conditions, prevention, avoidance, detection, recovery  
- Memory management basics: paging, segmentation, fragmentation  
- File system concepts, directory structure, allocation methods  
- I/O management, interrupts, DMA  
- Protection and security fundamentals

**Application-Based**  
- Identify CPU scheduling algorithm from Gantt chart / sequence  
- Detect deadlock possibility from Resource Allocation Graph  
- Determine page fault sequence for a given reference string  
- Identify page replacement policy from behavior (FIFO / LRU / Optimal)  
- Determine output of multithreaded execution with synchronization  
- Predict effect of semaphore operations / monitor code  
- Detect which process will starve / which gets the CPU next  
- Identify best fit / worst fit / first fit from memory block allocation outcome

**Numerical**  
- CPU scheduling problems: waiting time, turnaround time, response time  
- Effective access time (EAT) with TLB / page fault probability  
- Paging: number of pages, page table size, address translation  
- Segmentation address calculation  
- Page replacement numerical: number of page faults  
- Disk scheduling seek time calculations (FCFS, SCAN, C-SCAN)
- Deadlock avoidance numerical (Banker’s algorithm safety check)  
- RAID storage calculation  
- I/O calculation with DMA / interrupt frequency time

---
### 6. **CN**

**Theory**  
- OSI and TCP/IP models, protocol roles, encapsulation  
- ARP, DHCP, DNS fundamentals  
- Error and flow control mechanisms (ARQ, stop-and-wait, sliding window)  
- TCP features: reliability, congestion control phases, RTT estimation concepts  
- Routing concepts: link-state vs distance-vector, IP forwarding basics  
- MAC protocols: ALOHA, CSMA, CSMA/CD, token passing  
- Switching: circuit, packet, virtual circuit  
- Application layer protocols: HTTP, SMTP, FTP, DNS

**Application-Based**  
- Identify congestion control phase (slow start / congestion avoidance / fast recovery) from cwnd pattern  
- Determine which routing algorithm is in use from distance table updates  
- Detect hidden/exposed terminal scenarios in wireless communication  
- Predict frame retransmission behavior based on ARQ and acknowledgment timeline  
- Infer which switching technique is used from delay characteristics  
- Identify correct protocol working based on sequence of messages (ex: ARP request/response, DNS query)  
- Determine output of NAT table translation for packets  
- Detect the correct window movement scenario in TCP sliding window after ACK/timeout  
- Identify packet filtering/FW rules effect on incoming/outgoing traffic

**Numerical**  
- Subnetting and supernetting calculations (network id, broadcast, number of hosts)  
- CRC calculation, Hamming code parity bits and error position  
- Throughput, transmission, propagation, and queuing delay  
- Bandwidth-delay product  
- TCP RTT, timeout interval and congestion window size problems  
- Stop-and-wait and sliding window utilization and efficiency  
- Link-state routing shortest path calculation (Dijkstra) and DV updates  
- Token bucket and leaky bucket rate calculations  
- WLAN probability questions (slotted/unslotted ALOHA, CSMA)

---
### 7. **DBMS**

**Theory**  
- Keys: candidate, primary, super, foreign, surrogate  
- Normalization: 1NF, 2NF, 3NF, BCNF, 4NF, 5NF  
- Transaction properties (ACID) and schedules  
- Concurrency control techniques and protocols (2PL, timestamp ordering, lock types)  
- Indexing concepts: B/B+ tree structure basics, hashing basics  
- SQL concepts: joins, views, triggers, constraints  
- Recovery concepts: checkpoints, logging, shadow paging  
- ER-model concepts: attributes, relationships, participation, cardinality

**Application-Based**  
- Identify correct SQL query output from given data  
- Select best normalization step to remove a specific anomaly  
- Decide which index type (clustered / non-clustered / hash / B+ tree) suits the query pattern  
- Infer highest normal form satisfied from given schema and FDs  
- Detect whether schedule is conflict-serializable or view-serializable by analyzing precedence relations  
- Identify anomaly type (update / delete / insert) from example table state  
- Predict effect of cascaded delete/update through FK constraints  
- Infer locking / deadlock / starvation behavior from lock sequences

**Numerical**  
- Attribute closure / FD closure calculation  
- Candidate key and minimal cover calculation  
- Normalization decomposition validation: lossless join and dependency preservation  
- Serializability check using precedence graph construction  
- Transactions timestamp comparison and conflict resolution decision  
- Disk I/O cost estimation for index scan vs full scan  
- B/B+ tree insertion, deletion and height calculation  
- Hashing bucket calculation / overflow probability  
- Log based crash recovery timeline (redo/undo sets)

---
### 8. **COA**

**Theory**  
- Instruction set architecture, addressing modes  
- Hardwired vs microprogrammed control  
- Pipeline basics, hazards, forwarding, branch handling  
- Memory hierarchy: cache organization, write policies  
- Virtual memory concepts, TLB  
- I/O: interrupts, DMA, programmed I/O  
- Parallel processing and Flynn’s taxonomy  
- RISC vs CISC, superscalar basics

**Application-Based**  
- Identify type of hazard (RAW/WAR/WAW) and forwarding requirement from pipeline diagram  
- Determine whether pipeline stall occurs based on instruction sequence  
- Infer addressing mode from given instruction pattern  
- Decide which cache mapping policy (direct/associative/set) fits the given hit–miss behavior  
- Predict output of micro-operation sequence in control unit  
- Identify instruction cycle phases affected by interrupt/DMA  
- Infer memory consistency issues from multilevel cache behavior

**Numerical**  
- CPI, MIPS, execution time with and without pipelining  
- Speedup and efficiency of pipeline with stalls and branch penalties  
- Cache: hit ratio, average memory access time, tag/index/block calculations  
- Cache replacement numerical (LRU/FIFO)  
- Virtual memory: page number, offset, frame number, number of pages, TLB EAT  
- Address calculation for segmentation and paging  
- Amdahl’s law and parallel speedup  
- DMA and interrupt timing calculations

---
### 9. **TOC**

**Theory**  
- Chomsky hierarchy: Type 0, 1, 2, 3 grammars  
- Regular languages, closure properties, pumping lemma concept  
- CFG properties, ambiguity, CNF/ GNF basics  
- PDA, CFL properties, deterministic vs nondeterministic PDA  
- Turing machine concepts, decidability, halting problem  
- Recursive, recursively enumerable languages  
- Undecidability reduction concepts  
- Myhill–Nerode theorem fundamentals

**Application-Based**  
- Identify if language is regular / CFL / DCFL / recursive / RE from description  
- Detect whether FA, regex, grammar, and regular expression describe same language  
- Choose correct DFA/NFA/regex construction for given language pattern  
- Determine if grammar is ambiguous from sample derivations  
- Predict PDA move sequence and stack behavior for given input  
- Trace TM configuration for given steps to determine acceptance/rejection  
- Decide decidability of problems using known reductions  
- Identify minimal DFA from equivalent states or distinguishable strings

**Numerical**  
- DFA/NFA state count calculation and minimization steps  
- Regex to NFA / NFA to DFA conversion size estimation  
- Number of strings of specific length in language described by automaton/grammar  
- CYK parsing table filling for membership check  
- Context-free pumping lemma derivations (length-based reasoning)  
- Closure proofs using constructions (cross-product automaton state count)**

---
### 10. **CD**

**Theory**  
- Phases of compiler and their roles  
- Lexical analysis, tokens, lexemes, patterns  
- Parsing: top-down vs bottom-up, LL vs LR, left recursion, left factoring  
- Syntax-directed definitions, types of attributes (inherited/synthesized)  
- Intermediate code forms: postfix, 3-address code, DAG basics  
- Runtime environment: storage allocation strategies, activation records  
- Code optimization techniques: peephole, loop optimization basics  
- Symbol table management concepts

**Application-Based**  
- Identify FIRST / FOLLOW impact on grammar parsing decision  
- Predict shift-reduce or reduce-reduce conflicts from LR parsing items  
- Determine correct grammar after removing left recursion / left factoring  
- Detect ambiguity from sample strings or parse trees  
- Infer intermediate code sequence or postfix from expression  
- Predict scope/offset/activation record changes across nested calls  
- Identify which optimization is applied from transformed code fragment

**Numerical**  
- FIRST and FOLLOW calculation  
- Construct LR(0)/SLR/LR(1) item sets and parsing table entries  
- Operator precedence parsing table derivation  
- Number of temporaries / 3-address instructions generated for expression  
- DAG construction for expression and common subexpression elimination count  
- Storage allocation / offset calculation in activation record  
- Expected number of passes / phases based on given language features

---
### 11. **DE**

**Theory**  
- Number systems, complements, BCD, Gray code  
- Boolean algebra laws, canonical forms, SOP/POS  
- Logic gates and universal gates  
- Combinational circuits basics: adder/subtractor, encoder/decoder, mux/demux  
- Sequential circuits basics: flip-flops, latches, counters, registers  
- FSM concepts: Mealy vs Moore  
- Hazards, glitches fundamentals  
- ADC/DAC working principle basics

**Application-Based**  
- Identify logic circuit function (parity generator, comparator, priority encoder, etc.) from diagram  
- Determine output of sequential circuit given flip-flop timing diagram and next-state logic  
- Predict Gray ↔ Binary conversion and BCD correction behavior  
- Detect hazards in logic circuit and removal method through K-map  
- Determine counter sequence (ring, Johnson, mod-N, synchronous/asynchronous) from excitation table  
- Identify whether FSM is Mealy or Moore from transitions  
- Determine effective bit width and overflow behavior in arithmetic circuit

**Numerical**  
- K-map minimization and Boolean expression reduction  
- Propagation delay and timing calculations for combinational/sequential circuits  
- Flip-flop setup/hold time and clock skew margin  
- Maximum operating frequency of sequential circuit (critical path)  
- Counter timing and frequency division calculations  
- ADC/DAC resolution and step size  
- Number of bits required for dynamic range or quantization error  
- Number of states/flip-flops required for FSM design