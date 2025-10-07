

---
---
## [SJVN 2019 Executive Trainee IT - Answer Key ](https://solutionsadda.in/wp-content/uploads/2019/07/SJVNL_1569050019_1258O1990S2D67E1.pdf)

**Syllabus**

- **Technical**
	1. Programming Concepts : C, C++, Java
	2. Data Structures
	3. Algorithms
	4. Operating System
	5. Database Management Systems (DBMS)
	6. Computer Networks
	7. Digital Logic
	8. Computer Organization and Architecture
	9. Theory of Computation
	10. Compiler Design

- **More Technical**
	1. Software Engineering
	2. Programming and Data Structures
	3. Web Technologies
	4. Data Analytics and Cloud Computing

- **Non-Technical/General Section**
	- General Aptitude
	- Reasoning (Verbal/Non-Verbal)
	- Quantitative Aptitude
	- English Language
	- General Awareness

**SJVN Structure**
- **Technical Section**: 120 questions → **120 marks**
- **Aptitude Section**: 30 questions → **30 marks**    
- **Total CBT**: 150 marks

**Cutoff**
- **General/EWS**: **75 marks** (50%)
- **OBC/SC/ST/PwBD**: **60 marks** (40%)

**My Score**

1. **C Programming** `12/16✔️`
2. **Data Structures** `8/12✔️`
3. **Algorithm Design** `3/8✔️`
4. **Operating Systems (OS)** `5/13✔️`
5. **Database Management System (DBMS)**  `16/19✔️`
6. **Computer Networks (CN)** `5/15` ✔️
7. **Digital Logic** `7/10` ✔️
8. **Computer Organisation & Architecture (COA)** `10/10` ✔️
9. **Theory of Computation (TOC)** `6/12` ✔️
10. **Compiler Design** `6/8` ✔️

- **Total Question** - 120

**Attempted** (Without COA and TOC) - 103
- **Correct** - 61  (50.83) %

**Attempted** - 120
- **Correct** - 78 (63.41 %)

- **Expected out of 150** - 76.245 (50.83 %)


From highest % to lowest Subject:
1. **COA** → **100%** (Strongest)
2. **DBMS** → **84.21%**
3. **C Programming** → **75%**
4. **Compiler Design** → **75%**
5. **Digital Logic** → **70%**
6. **Data Structures** → **66.67%**
7. **TOC** → **50%**
8. **OS** → **38.46%**
9. **Algorithm Design** → **37.5%**
10. **CN** → **33.33%** (Weakest)

---
#### **1. C Programming** `12/16✔️`


**Q7.** Consider the 'C' language variables x and y with initial values 100 and 500, respectively. What will be the value of y after executing the following expression? `((x>=100 ) || (y+=100))` ✅⭐
- _Topic: Expression Evaluation_
```
- y = 500 ✔️
```
- In C, `||` (logical OR) **short-circuits**: if the first operand is true, the second is **not evaluated**.
- So, `(y += 100)` is **not executed**, and `y` remains **500**.
- if `((y+=100) || (x>=100 ))` then `y=600`
- In C, **logical operators (`||`, `&&`) work with the truthiness of expressions**, but the expressions themselves **are fully evaluated** for side effects **before the logical operator checks truth**.
- `y += 100` is an **assignment expression** and an assignment **returns the value assigned**. So `y += 100` **returns 600** (which is non-zero → true).


**Q20.** What will be the value of the following arithmetic expression in 'C'? 125 % -4 ✅⭐
- _Topic: Arithmetic Operators & Precedence_
```
- +1 ✔️
```
- In C, the **sign of the result** of `%` follows the **dividend** (the first operand).
- `125 % -4 = 1` (because `125 / -4 = -31` remainder 1).
- `x % -y` **is the same as `x % y` if `x` is positive**.
- If `x` is negative, the result **keeps the sign of `x`**, not `y`.
    
**Q27.** In 'C' language, the scope of a ______ variable extends from the point of definition throughout the remainder of the program. ❌
- _Topic: Variable Scope_
```
- External ✔️
- Static ❗
```
- A variable whose **scope extends from the point of definition to the rest of the program** is an **external (global) variable**. `int x = 10;  // external/global`⭐
- `static` variables have **scope limited to the file** if declared at global level, or to the block if local. `static int count = 0; // local static`

**Q30.** Which of the following is NOT a valid decimal integer constant in 'C'? ✅
- _Topic: Constants Syntax_
```
- 02019 ✔️
```
`02019` is **invalid** because numbers starting with `0` are **octal** in C, and `9` is not allowed in octal.

**Q31.** In 'C' language, an unsigned long integer constant can be specified by appending the letters ___ to the ___ of the constant. ❌
- _Topic: Integer Constant Representation_
```
- UL, End ✔️
- UL Beginning  ❗
- LU, End ❗
```
- Correct syntax: **UL or LU at the end** of the constant.
- Cannot put `UL` at the beginning.
- `unsigned long a = 1000UL; // valid` or `unsigned long b = 2000LU; // also valid`
- But here only `UL` is considered correct

**Q42.** Each 'C' program consists of one or more functions, one of which must be named as: ____________. ✅
- _Topic: Structure of C Program_ 
```
- main() ✔️
```
    
**Q54.** Which of the following statements are true?  ✅
- _Topic: Character Arrays and Pointers_
```
- In 'C', a character array always ends with null character (NULL).  ✔️
- The "base address" of an array means the address of the second element. ❗
```
- `char arr[]` always ends with **null character `\0`**.
- Base address of an array is the **address of the first element**, not the second.
- `\0` → marks **end of a string**; `\n` → represents a **newline/line break**.

**Q55.** In 'C' language, an unsigned integer constant can be specified by appending the letter ___ to the ___ of the constant. ❌
- _Topic: Constant Declaration_
```
- U, End ✔️
- U Beginning  ❗
- I, End ❗
```

**Q62.** Variables `a = 0`, `b = 1`, and after expression execution, find value of `b`. `((a>0)&&(b=b+1))` ✅⭐
- _Topic: Expression Evaluation_
```
b = 1 ✔️
b = 2 ❗
```
- `a = 0`, `b = 1`
- `a > 0` is false → `&&` **short-circuits**, `(b = b + 1)` is **not executed**
- `b = 1`

**Q71.** In 'C' language, an identifier name CANNOT start with:` __________` ✅
- _Topic: Variable Naming Rules_
```
- Numerid degit ✔️
- Uppercase Letter
- Lowercase Letter
- Under Score
```
    
**Q83.** With respect to 'C' language, the collection of characters, digits, and symbols enclosed within quotation marks is called `___________`. ✅
- _Topic: String Literals_
```
- String ✔️
```

**Q84.** The 'C' language was originally developed at: ✅⭐
- _Topic: Programming Language History_
```
- Bell Labs ✔️
- IBM ❗
- Intel ❗
- Microsoft ❗
```
- Developed at **Bell Labs** by Dennis Ritchie in the early 1970s.

**Q90.** Comments can be placed anywhere in a 'C' program, as long as they are placed within the delimiters: `__________. ` ✅
- _Topic: Comment Syntax_
```
- /* */ ✔️
```
    
**Q91.** In 'C' language, the gets() function reads a string from the keyboard and terminates reading after encountering a `__________` character. ⭐❌
- _Topic: gets() Function Behavior_
```
- NewLine ✔️
- Space ❗
- Tab ❗
```
- **`gets()` function** Reads input until a **newline (`\n`)** is encountered. `Space` or `Tab` do not terminate** input.
    
**Q93.** What is the associativity of the comma operator in 'C'? ⭐✅
- _Topic: Operator Associativity_
```
Left-to-Right ✔️
```
    
**Q100.** Which of the following is a valid hexadecimal constant in 'C'? ✅
- _Topic: Constant Format_
```
- 0X1234 ✔️
- 0x1234G ❗
```
- Must start with `0x` or `0X` and contain valid hex digits (`0-9`, `A-F`).
- `0X1234` is valid; `0x1234G` is invalid because `G` is not a hex digit.

---

#### **2. Data Structures** `8/12✔️`


**Q3.** Array is a(n) _______ data structure. ✅
- _Topic: Array Classification_
```
- Homogeneous ✔️
- Primitive ❗
```
    
**Q4.** With respect to the organization of elements in a data structure, identify the ==odd one out== from the given options. ⭐❌
- _Topic: Data Structure Types_
```
- Linked List
- Array 
- Stack
- Graph ✔️
```

**Q15.** Consider the height of a tree as the number of edges in the longest path from root to a leaf node. If T is a binary tree of height 3, what is the largest number of nodes in T? ✅⭐🔢
- _Topic: Binary Tree - Max Nodes_

**Q18.** Which of the following probing methods suffers from the problem of secondary clustering? ❌⭐
- _Hashing Techniques_

**Q21.** Consider the height of a tree as the number of edges in the longest path from root to a leaf node. If T is a binary tree of height 4, what is the smallest number of nodes in T? ✅⭐🔢
- _Topic: Binary Tree - Max Nodes_
- _Topic: Binary Tree - Min Nodes_
    
**Q45.** Which of the options represents the postfix of the given infix expression? `L-M/(N*O/P)` ❌⭐🔢
- _Topic: Expression Conversion (Infix to Postfix)_
```
- LMNO*P//- ✔️
- LM-NO*P//
```
    
**Q47.** When no more elements can be added into a stack, the status of the stack is known as `__________` and the "top" index rests at the `__________` position. ✅
- _Topic: Stack Overflow Condition_

**Q64.** What is the **postorder traversal** of the given tree? ✅
- _Topic: Tree Traversal (Postorder)_
    
**Q73.** Which of the following statements is/are FALSE?  ✅
(i) Breadth-first search algorithm can be implemented using the queue data structure.  
(ii) Depth-first search algorithm can be implemented using the stack data structure.
- _Topic: Graph Traversal Algorithms_
    
**Q98.** How many distinct binary search trees can be created from 4 distinct keys? ❌⭐🔢
- _Topic: Binary Search Trees - Count (Catalan Number)_
```
- 14 ✔️
- 24 ❗
```
    
**Q113.** The operation of displaying or listing all elements of an array is usually called: ✅
- _Topic: Array Traversal_
    
**Q120.** Level-order traversal of a rooted tree can be done by starting from the root and then performing` ___________`. ✅
- _Topic: Tree Traversal using Queue_
    

---

#### **3. Algorithm Design** `3/8✔️`


**Q19.** What is the solution of the given recurrence relation?  `T(n) = 4T(n/2) + n^2` ❌⭐
- _Topic: Recurrence Relations_    
```
- n ❗
- n x logn ❗
- n^2 x logn ✔️
- logn ❗
```

**Q28.** A machine takes 100s to sort 1000 names by quicksort. Time to sort 100 names? ❌⭐
- _Topic: Sorting Time Complexity_    
```
- 6.7s ✔️
```

**Q36.** State whether the following statements are true or false:   ❌⭐
- _Topic: Graph Theory (Shortest Path & Spanning Trees)_
```
- In Bellman-Ford shortest path algorithm, the edge weight can be negative but no negative cycle exists. ✔️
- Spanning tree will always have n-1 edges, where n is the total nodes of a graph. ✔️
```



**Q89.** Recursion: (i) Needs extra space, (ii) Reduces code size. ❌
- _Topic: Recursion Pros and Cons_
```
- Recursion requires extra storage space. ✔️
- Using recursion, the length (size) of the program can be reduced. ✔️
```


**Q79.** What is the correct value of x if (211)base x = (152)base8?  ⭐✅
- _Topic: Bitwise Logic & Algebra_
```
- 7 ✔️
```

**Q105.** Matrix multiplication: optimal order for P(20x30), Q(30x5), R(5x15), S(15x10)? ✅
- _Topic: Dynamic Programming -> Matrix Chain Multiplication_
```
- (PxQ) X (RXS) ✔️
```

**Q106.** DFS traversal tree with m edges, v vertices — number of connected components?
- _Topic: Graph Connectivity_ ✅⭐
```
- v-m ✔️
```

**Q115.** Which sorting algorithm has minimum worst-case time complexity? ❌⭐
- _Topic: Comparison of Sorting Algorithms_
```
- Merge Sort ✔️
- Quick Sort ❗
- Selection sort ❗
- Bubble Sort ❗
```

---
#### **4. Operating Systems (OS)** `5/13✔️`


**Q1.** If a CPU takes 10 ms to decide to execute a process of 100 ms, approximately what percentage of time will be wasted by CPU in scheduling work? ❌⭐🔢
- _Topic: CPU Scheduling Overhead_
```
- 9 ✔️
- 10 ❗
```
    
**Q9.** In a multithreaded process, threads ==CANNOT== share: ❌⭐
- _Topic: Multithreading - Shared vs Private Data_
```
- stack ✔️
- files
- code section
- data section
```
    
**Q11.** A process is a `___________`. ✅
- _Topic: Process Definition_
```
- Program in execution ✔️
```

    
**Q23.** Preemptive scheduling was introduced in `___________`.  ❌
- _Topic: Scheduling Algorithms History_ 
```
- Windows 95 ✔️
- Windows 3.0
- Windows 98
- Windows NT 
```
    
**Q26.** Which of the following statements is/are ==True==?   ❌
(i) Device controllers raise an interrupt by asserting a signal on the interrupt request line.  
(ii) Interrupt vector contains the memory addresses of specialized interrupt handlers.
- _Topic: Interrupt Handling_
```
- Device controllers raise an interrupt by asserting a signal on the interrupt request line. ✔️
- Intrrupt vector contains the memory addresses of specialized interrupt handlers. ✔️
```

**Q43.** Which of the following OS/process statements is TRUE? ✅⭐
- _Topic: OS General Concepts_
```
- CPU can directly access main memory and registers ✔️
- Illegal memory access results in trap interrupt. ✔️
- Memory-address register stors the logical address ❗
- Memory pprotection among processes is implemented using base and limit registers. ✔️
```


**Q60.** Suppose in a demand paging environment, the page service time is `10ms` if the page to be replaced is NOT modified, whereas it is `15ms` if the page to be replaced is modified. The main memory access time is `300ns`. What will be the effective access time if page fault rate is 5% and the page to be replaced is modified `60%` of the time? ❌⭐🔢
- _Topic: Paging - Effective Access Time Calculation_
    
**Q66.** Which of the following is a valid 'C' structure to represent process control block in Linux operating system? ❌
- _Topic: PCB Structure_
```
task_struct ✅
```
    
**Q80.** Which of the following is NOT a valid model to represent relationship between user threads and kernel threads? ❌
- _Topic: Thread Models_
```
one-to-many model
```

**Q81.** Which of the following statements is TRUE?  ❌⭐
- _Topic: Threads and Multithreading_
```
- Kernel level threads are managed by operating system. ✔️
- A heavy weight process has multiple threads of execution. ❗
- here are three types of threads: user, kernel, and system level threads. ❗
- User level threads are managed by kernel. ❗
```
    
**Q94.** Which of the following statements is/are ==true==?   ✅⭐
- _Topic: Address Binding_
```
- Execution-time address binding generates different logical and physical  addresses. ✔️
- The user program can access the physical address. ❗
```
    
**Q95.** The CPU fetches instructions from memory according to the value of` __________`. ✅
- _Topic: Program Counter (PC)_
```
program counter ✔️
```
    
**Q111.** Which of the following are valid metrics to compare different CPU scheduling algorithms? ✅
- _Topic: Scheduling Metrics_
```
- Dispatch latency❗
- Turnaround time ✔️
- Throughput ✔️
- Response time ✔️
```

---

#### **5. Database Management System (DBMS)**  `16/19✔️`


**Q6.** Which of the following is maintained by a DBMS to keep track of all transactions that update the database? ✅
- _Topic: Transaction Logging_
```
- Log ✔️
```

**Q17.** Which of the following SQL commands can be used to add new data in a database? ✅
- _Topic: SQL - INSERT Command_
```
- Insert ✔️
```

**Q24.** State whether the following statements are true or false: (i) "Intension" represents the number of tuples present in a database relation. (ii) "Extension" gives the structure and constraints. ✅⭐
- _Topic: Relational Terminology_
```
- "Intension" represents the number of tuples presented in a database relation (table) at any instance. ❗
- "Extension" gives the name, stnrcture and constraint of a database relation (table). ❗
- None ✔️
```

**Q39.** Which of the following SQL "LIKE" expressions can be used to find any string containing "Ch"? ✅
- _Topic: Pattern Matching_
```
- LIKE %ch% ✔️
```

**Q41.** Which of the following is NOT an aggregate function in SQL? ✅⭐
- _Topic: SQL Aggregate Functions_
```
Round() ✔️
AVG() ❗
SUM() ❗
MAX() ❗
```

**Q48.** When a transaction is abnormally terminated, which command is executed by the DBMS? ✅
- _Topic: Transaction Rollback_

**Q53.** Which of the following statements is/are true about secondary index? ❌⭐
- _Topic: Indexing (Key vs Non-key)_
```
- Secondaay index may be created on a key field. ✔️
- Secondary index may be created on non-key field.  ✔️
```

**Q58.** Which of the following is a virtual relation (table) that does NOT physically exist? ✅
- _Topic: Views_

**Q59.** What is the highest normal form satisfied by a relation schema R(A, B, C) with (A, B) as PK and FDs: A→B, B→C? ✅⭐
- _Topic: Normalization (3NF, BCNF)_
```
- 1NF ✔️
- 2NF ❗
- 3NF ❗
- BCNF ❗
```

**Q65.** With respect to database transaction, what is the full-form of 'C' in ACID? ✅
- _Topic: Database Transactions_

**Q67.** In ER Model, an identifying relationship (between weak entity and owner) is represented by: ❌⭐
- _Topic: Entity Relationship Model (Weak Entity Representation)_
```
- dobule-lined diamond ✔️
- double-lined oval ❗
- dashed oval ❗
```

**Q70.** Which normal form ensures non-prime attributes are not functionally dependent on subset of any candidate key? ✅⭐
- _Topic: BCNF Definition_
```
- 2NF ✔️
```
- **2NF**: Removes **partial dependencies** (i.e., no non-prime attribute depends on a **part** of a candidate key).
- **3NF**: Removes **transitive dependencies** (i.e., non-prime attributes should depend **only on candidate keys**, not on other non-prime attributes).
- **BCNF**: Stronger than 3NF — it also eliminates anomalies where a non-superkey determines a candidate key (i.e., every determinant must be a **superkey**).

**Q75.** What is the full-form of ER model? ✅
- _Topic: Entity Relationship Model_

**Q86.** What is the full-form of SQL? ✅
- _Topic: SQL Acronym_

**Q87.** What is the purpose of the SELECT statement in SQL? ✅
- _Topic: SQL Querying_

**Q96.** Consider relation `R(A, B, C, D)`. What is the **maximum number of attributes in a candidate key**? ✅
- _Topic: Relational Database Design (Keys & Normalization)_
```
- 4 ✔️
```

**Q97.** In a database, a primary index is an `_____` file whose records are of `____` length. ❌⭐
- _File Organization and Indexing_
```
- ordered, fixed ✔️
- ordered, variable ❗
- unordered, fixed ❗
- unordered, variable ❗
```

**Q116.** Which of the following is used to represent "total" participation in ER diagram? ✅⭐
- _Topic: ER Diagram Notation_
```
- Doouble Line ✔️
- Dashed Line ❗
- Single Line ❗
- Double-lined rectangle ❗
```


**Q117.** Which of the following SQL functions does NOT ignore NULL by default? ✅⭐
- _Topic: SQL NULL Handling_    
```
- COUNT() ✔️
- MAX() ❗
- MIN() ❗
- SUM() ❗
```

---
#### **6. Computer Networks (CN)** `5/15` ✔️


**Q13.** Which of the following statements are true? (OSI layer functions) ✅⭐
- _Topic: OSI Model Responsibilities_
```
- EncryptionDecryption and compression are the functions of presentation layell ✔️
- TCP handles both congestion and flow control. ✔️
- Data link layer provides error control but not flow control. ❗
- Service point addressing is the job of network layer. ❗
```


**Q14.** A 10 KBPS satellite link... What is the possible throughput using go-back-N ARQ? ❌🔢 (To do.....⭐ )
- _Topic: ARQ Protocol Efficiency_
```
- 6.89 KBps ✔️
```


**Q16.** Match the columns: (i) Breach of confidentiality, (ii) Breach of integrity, (iii) Breach of availability. ✅
- _Topic: CIA Triad (Confidentiality, Integrity, Availability)_
```
- (i) -> Theft of information ✔️
- (ii) -> Unauthorised modification of data ✔️
- (iii) -> Unauthorised destruction of data  ✔️
```

**Q29.** In IPv4 datagram header, which field signifies the number of hops allowed? ✅
- _Topic: TTL Field in IPv4_
```
- Time to Live ✔️
```

**Q32.** Which of the following is ==**NOT**== an error control technique? ✅ (To do.....⭐ )
- _Topic: Error Control Protocols_
```
- Sliding Window ✔️
- Go-Back-N ARQ ❗
- Stop-and-Wait ARQ ❗
- Selective Repeat ARQ ❗
```

**Q35.** What type of address is 255.255.255.255? ✅
- _Topic: IP Address Types_
```
- Limited broadcast address ✔️
- Direct broadcast address ❗
- Multicast address ❗
```

**Q50.** What is the ==port number== for HTTP protocol? ✅⭐
- _Topic: Well-known Ports_
```
- 80 ✔️
```

**Q52.** Leaky bucket algorithm rate calculation. ❌🔢(To do.....⭐ )
- _Topic: Traffic Shaping Algorithms_
```
- 44.4 MBps ✔️
```

**Q56.** Which of the following implementations uses UDP as its transport layer protocol? ✅⭐
- _Topic: Transport Layer Protocols_
```
- DNS ✔️
- HTTP ❗
- FTP ❗
- IMAP ❗
```

**Q68.** In the given diagram, if link V2-V4 is removed, how does the routing table for distance vector routing protocol vary for the node V2 ✅⭐
```
     4              3
(V1)---------(V2)---------(V5)
 |            |
 | 5          | 2
 |      3     |      1
(V3)----------(V4)--------(V6)
```
- _Topic: Routing Table Updates_
```
- 4, 0, 9, 12, 3, 13 ✔️
```

**Q82.** Which OSI layer maintains data and dialog synchronization? ✅⭐
- _Topic: Session Layer_
```
- Session Layer ✔️
- Network Layer ❗
- Transport Layer ❗
- Data Link Layer ❗
```


**Q102.** Match IEEE 802 standards (LLC, Ethernet, Token Bus, Token Ring) ❌(To do.....⭐ ) (a) 802.3, (b) 802.4, (c) 802.5, (d) 802.2
```
- Logical Link Control
- Ethernet
- Token Bus
- Token Ring
```
- _Topic: IEEE LAN Protocols_

**Q104.** In a single-router scenario, how often does each layer (Application, network and data Link) process the packet? ❌(To do.....⭐ )
- _Topic: Layer-wise Packet Processing_
```
- 2, 3, 4 ✔️
```

**Q110.** Match networking devices with their function/layer. ❌⭐
(i) Hubs, (ii) Gateways, (iii) Switches, (iv) Bridges
- _Topic: Network Device Classification_
```
- (i) -> Physical layer device having multiple ports to forward data
- (ii) -> A device connecting two networks functioning on two different entwork models  
- (iii) -> Data link layer device that performs error checking before forwarding data.
- (iv) -> Data link layer device with functionality of filtering content and forwarding data.
```

**Q114.** Match protocols to actions: ping, send mail, transfer file. ✅⭐
- _Topic: Protocol Usage (ICMP, SMTP, FTP)_    
```
- DNS, SMPTP, FTP ✔️
- HTTP, SMTP, FTP ❗
```

---
#### **7. Digital Logic** `7/10` ✔️

**Q12.** State true/false: (i) Excess-3 code is BCD variant, in which each decimal digit is coded into a 4-bit binary code. (ii) K-map of n variables has 2^n cells. ❌⭐
- _Topic: Coding Systems and Karnaugh Maps_
```
- (i) True 
- (ii) True ✔️
```

- **Excess-3 Code**
    - It is a _self-complementary_ form of **BCD code**.
    - Each decimal digit (0–9) is represented by its 4-bit BCD code **plus 3 (0011)**.
    - Used in decimal arithmetic and error detection.
        
- **Karnaugh Map (K-Map)**
    - A K-map of **n variables** contains **2ⁿ cells**.
    - Each cell represents a **minterm** (or maxterm) of the function.
    - Used to simplify Boolean expressions.


**Q25.** Let f(A, B) = A'+B. What is simplified form of `f(f(x+y, y), z)`? ✅
- _Topic: Boolean Function Simplification_
```
- xy' + z ✔️
```

**Q46.** What is the Excess-3 code for decimal 13? ✅
- _Topic: Excess-3 Code Conversion_
```
- 01000110 ✔️
```

**Q49.** Which of the following is equivalent to the decimal number `(0.6875)₁₀`? ✅⭐⭐⭐
- _Topic: Number System Conversion (Decimal ↔ Octal)_
```
- (0.54)₈
```

**Q57.** Using which of the following can decimal digits be converted into binary format? ✅⭐
- _Topic: Combinational Circuits (Encoders)_
```
- Encoder ✔️
```

> Study Multiplexer, Demultiplexer, Encoder, Decoder Theory

**Q85.** Simplify `F(x,y,z) = pi(0,1,4,5)` to product of sums. ❌⭐⭐⭐
- _Topic: Boolean Algebra (POS)_
```
- y ✔️
- x
- z
- xyz
```

**solution:**
- M0 + M1 + M4+ M4 
- => (X + Y + Z ).( X + Y + Z' ).(X' + Y + Z).(X' + Y + Z') 
- => (X + Y).(X' + Y)  - Using Absorption Law
- => Y - Using Absorption Law

**Absorption Law** : `(A+B)(A+B')`=`A+(B⋅B′)`=`A+0`=`A`

**Q99.** Complement of Boolean function: `F = x(y'z' + yz)` ✅
- _Topic: Boolean Function Complement_
```
- x' + yz' + y'z ✔️
```



**Q107.** State true/false: (i) RS latch is 1-bit memory. (ii) Encoder has n inputs, 2^n outputs. ✅⭐
- _Topic: Latches & Encoders_
```
- (i) True  ✔️
- (ii) False 
```

> Study - Encoder, RS Latch, Flip Flop Theory

**Q108.** What is range of 2's complement for k-digit number? ❌⭐
- _Topic: Number Representation_
```
- [ -(2^(k-1))] to (2^(k-1)-1) ✔️
- [ -(2^(k-1) -1)] to (2^(k-1)-1)
- [ -(2^(k-1))] to (2^(k-1))
- [ -(2^(k-1) -1)] to (2^(k-1))
```
- The number of negative numbers is one more because in 2’s complement, zero has only one representation, so the extra bit pattern is used for an extra negative number, and 0 is counted in the positive side.
- **Minimum value** = when MSB = 1 and all other bits = $0 → 2^{k-1}$
- **Maximum value** = when MSB = 0 and all other bits = $1 → 2^{k-1} - 1$

> Study 2's Complement Theory

**Q118.** Match digital components: (i) Shift Register, (ii) Multiplexer, (iii) Decoder. ✅⭐
- _Topic: Digital Components Matching_
```
- (i) - To convert parallel data to serial data ✔️
- (ii) - To transmit large no. of information units over a smaller no. of channels ✔️
- (iii) - To design seven segment dislplay ✔️
```

> Study - Multiplexer, Decoder, Shift Register

---

#### **8. Computer Organisation & Architecture (COA)** `10/10` ✔️

**Q5.** A 4-stage pipeline has stage delays of 150, 120, 160, and 140ns, respectively. Registers used between the stages have a delay of 5ns. Assuming constant clocking rate, what is the total time required to process 1000 data items on this pipeline? ✅⭐
- _Topic: Pipelining and Performance_
```
- 165.5 us ✔️

Solution:
Non Uniform Cycle - Take max time = 160 + 5 = 165ns
Total Time = (No. of Stages + No. of Instructins - 1)x time
		   = (4 + 1000 - 1) x 165ns 

```

**Q10.** How many 64K x 1 RAM chips are needed to provide 512K x 8  memory? ✅
- _Topic: Memory Chip Calculation_
```
- 64 ✔️

Solution:

(512K x 8 bits) / (64K x 1 bits) = 64
```


**Q38.** Match the columns with addressing modes and their applications.
- _Topic: Addressing Modes_
```
- Indirect addressing mode -> → (d) Pointers ✔️
- Immediate addressing mode -> (a) Constant operands ✔️
- Base addressing mode -> (b) Relocatable program ✔️
- Index addressing mode -> (c) Arrays ✔️
```

**Q44.** State true/false: (i) . (ii) PSW contains CPU status bits. ✅
- _Topic: Memory & Processor Status Word_
```
- DRAM uses capacitors  ✔️
- PSW contains status bits ✔️
```

**Q61.** Given a **7-stage instruction pipeline** and instruction sequence, find the number of cycles required for complete execution. ✅
- _Topic: Instruction Pipelining & Timing_
```
- 16 ✔️

but answer should be 14 ❗
(7 + 8-1) = 14
```

**Q74.** Output sequence of JK Flip-Flop for 6 pulses with J=Q', K=1. ✅
- _Topic: Sequential Circuits - JK Flip-Flop_
```
- 010101 ✔️

but answer should be '101010' ❗
```

**Q109.** Memory chip with 20 address and 16 data pins: how many locations? ✅
- _Topic: Addressable Memory Calculation_
```
- 2^20 ✔️
```

---
#### **9. Theory of Computation (TOC)** `6/12` ✔️


**Q2.** Every monotonic grammar is a ______ `_____` grammar. ❌❓⭐
- _Topic: Grammar Hierarchy_
```
- Type 1 ✔️
```
- Every monotonic grammar is a **type 1 grammar**—that is, a **context-sensitive grammar**.
- ❗Chatgpt giving ambiguous answer, In note I added that Every monotonic grammar is subset of Type 0  

**Q8.** A grammar that produces more than one leftmost or rightmost derivation is known as `________` ✅
- _Topic: Ambiguous Grammar_
```
- Ambiguous
```

**Q22.** The concatenation of two regular expressions R1 and R2 is represented using: ________. ❌
- _Topic: Regular Expression Operations_
```
- R1 R2 ✔️
- R1 + R2
```

**Q40.** The language `{aⁿbⁿcⁿ | n≥1}` is: ❌⭐
- _Topic: Language Classification (Chomsky Hierarchy)_
```
Context-Sensitive but not context-free ✔️
```
`aⁿbⁿ` needs one dependency (CFG can handle), but `aⁿbⁿcⁿ` needs two (CFG can't handle).

**Q51.** Match the grammar types with their Chomsky classification. (i) Regular language (ii) Context-free language , (iii) Context-sensitive language ✅⭐
- _Topic: Chomsky Grammar Hierarchy_
```
(i) Type-3 grammar  ✔️
(ii) Type-2 grammar ✔️
(iii) Type-1 grammar ✔️
```

**Q63.** In Automata Theory, a production without any restriction is called ______ production. ✅
- _Topic: Unrestricted Grammar_
```
Type 0 ✔️
```

**Q69.** What is the correct production rule for the language `L = {a^m b^n | m < n, m ≥ 1}`? ✅⭐
- _Topic: Grammar Rule Derivation_
```
S-> Sb|Bb, B -> aBb, B -> ab ✔️
```

**Q72.** Linear bounded automaton :  ❌⭐
- _Topic: Linear Bounded Automaton (LBA)_
```
- Same as Deterministic Turing Machine?  ❌ 
- Language not always context-sensitive? ❌
```
Note: **LBA** is a non-deterministic Turing Machine

**Q77.** According to Chomsky classification, the language of Finite Automata is: ✅⭐
- _Topic: Regular Languages (Type-3)_ 
```
- Type 3 ✔️
```

**Q78.** Which of the following are True? ✅⭐
- _Topic: Finite Automata (Mealy & Moore Machines)_
```
- In Mealy machine, output depends on both the present state and current input symbol. ✔️
- In Moore machine, output depends only on the present state of the machine. ✔️
- An NFA can also have NULL moves (i.e., moves without input symbol) ✔️
- Mealy machine is infinite state machinine ❌
```

**Q88.** Deterministic context-free languages are closed under ______. ❌⭐
- _Topic: Closure Properties- _
```
- Complementation ✔️
- union
- intersection
- addition
```
Note: CFL Don't Follow Complement, But DCFL Do

**Q112.** State True/False: (i) Union of Regular expression not always regular. (ii) Concatenation of Regular expression is regular. ❌⭐
- _Topic: Regular Expression Properties_
```
(i) False - Union of Two RL is Closed
(ii) True - Concatenation of Two RL is Closed ✔️
```


---
#### **10. Compiler Design** `6/8` ✔️


**Q33.** Which of the following statements is true? ✅
- _Topic: General Programming Statement_
```
- A Type 2 production is of the form A->a or A-> aB, where A, B are variables and a is a terminal. ✔️

- In Type 2 production rule, left hand side has no left or right context ❌
- In Type 2 production rule, left hand side has only left context ❌
- In Type 2 production rule, left hand side has only right context ❌
```

**Q34.** The analysis part of a compiler is also called ______. ✅⭐
- _Topic: Compiler Phases_
```
- Frontend ✔️
```
- **Frontend** - Lexical Analyses, Syntax Analysis, Semantic Analysis, Intermediate Code Generation
- **Backend** - Optimization, Code Generation , Linking & Assembly

**Q37.** Which of the following is done by attaching rules or program fragments to productions in a grammar? ✅
- _Topic: Syntax-Directed Translation_
```
- Syntax-directed translation ✔️
```

    
**Q76.** ______ takes tokens from lexer and constructs syntax tree by derivation. ✅
- _Topic: Syntax Analysis (Parser)_
```
- Syntax analysis ✔️
```


**Q92.** Which of the following holds information about identifiers? ✅
- _Topic: Symbol Table Management_
```
- Symbol table ✔️
```
    
    
**Q101.** Which statements are TRUE about code optimization? ❌⭐
- _Topic: Local Optimization & Code Motion_
```
- (i) Code optimization within a basic block is called local code optimization. ✔️
- (ii) Code motion finds the expression outside a loop that yields the different results and evaluates it inside loop ❌
```

**Q103.** Which compiler component converts lexemes into tokens? ✅
- _Topic: Lexical Analysis_ 
```
- Lexical analyzer ✔️
```
    
**Q119.** Type checking validates syntax tree consistency. Front-end handles source structure. ❌⭐
- _Topic: Type Checking and Compiler Front-End_
```
- (i) Type checking analyses the syntax tree to determine if the program vioates certain consistency requirements. ✔️

- (ii) Details of the source is confined to the front end. ✔️  
```


---

## To Study

**Database Management Systems (DBMS)****
- **ER Model**
	- Weak Entity Set
	- Total Participation vs Partial Participation
	- Identifying Relationship
- **Indexing in DBMS**
	- Primary vs Secondary Index
	- Dense vs Sparse Index
	- Ordered (Clustered) vs Unordered Index
	- Multilevel Indexing
	- B-Tree and B+ Tree (overview)
- **B-Tree & B+ Tree**
	- Structure & Node Properties
	- Insertion & Deletion
	- Differences Between B and B+ Tree
	- Use in DBMS Indexing
    

**Data Structures**
- **Hashing**
	- Hash Functions
	- Collisions: Causes and Solutions
	- Probing Methods:
	    - Linear Probing (Primary Clustering)
	    - Quadratic Probing (Secondary Clustering)
	    - Double Hashing (No Clustering)
	- Chaining
	- Load Factor
- **Sorting Algorithms**
	- Bubble Sort – Stable, O(n²), Swapping Adjacent
	- Selection Sort – Unstable, O(n²), Minimum selection
	- Insertion Sort – Stable, O(n²), Good for Nearly Sorted
	- Merge Sort – Stable, O(n log n), Divide and Conquer
	- Quick Sort – Unstable, O(n log n), In-place but recursive
	- Heap Sort – Unstable, O(n log n), Not recursive
	- Counting Sort – Stable, O(n + k), Not comparison-based
	- Radix Sort – Stable, O(nk), Uses Counting Sort
	**→ Focus:** Uniqueness, Time, Space, and Use-Cases

**Algorithms**

- **Shortest Path Algorithms**
	- **Bellman-Ford Algorithm**
	    - Works with negative weights	        
	    - Detects negative cycles
	    - O(VE) Time
	- **Dijkstra’s Algorithm**
	    - No negative weights allowed
	    - Greedy approach using Min-Heap
	    - O(V + E log V) with Priority Queue	
	**→ Differences:**
	- Negative weight handling
	- Efficiency
	- Use-case scenarios

- **Recurrence Relations & Time Complexity**
	- Recurrence Relation Basics
	- Solving via:
	    - Iteration method
	    - Substitution method
	    - Master Theorem
	- Master Theorem Cases
	- Apply on Merge Sort, Binary Search, Quick Sort, etc.
    
