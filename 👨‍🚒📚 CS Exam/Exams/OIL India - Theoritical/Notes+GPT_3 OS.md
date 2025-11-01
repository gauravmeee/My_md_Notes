# Operating System

|     | Topics                       | Subtopics                             |
| --- | ---------------------------- | ------------------------------------- |
| 1   | Introduction                 | OS types and structure                |
| 2   | Process Management           | Scheduling, states                    |
| 3   | Inter-process Communication  | Pipes, Shared memory, Message passing |
| 4   | Deadlocks, Mutex, Semaphores | Prevention and avoidance              |
| 5   | Memory Management            | Paging, Segmentation, Virtual memory  |
| 6   | I/O Devices                  | Drivers and management                |
| 7   | Protection & Security        | Access control, threats               |
### **1. Introduction to Operating System**

**Definition:** An ==Operating System (OS) is system software== that ==acts as an intermediary between the user and computer hardware==. It manages hardware resources and provides services for program execution.

**Objectives:**
- To make computer systems convenient to use
- To manage hardware resources efficiently
- To execute and provide services for user programs
    
**Functions of OS:**
1. **Process Management:** Handles creation, scheduling, and termination of processes.
2. **Memory Management:** Allocates and deallocates memory space as required.
3. **File Management:** Manages files, directories, and access permissions.
4. **I/O System Management:** Controls and coordinates I/O devices.
5. **Device Management:** Keeps track of all devices and their status.
6. **Security and Protection:** Prevents unauthorized access to data and resources.
7. **Error Detection:** Monitors and handles system errors.
8. **Resource Allocation:** Allocates CPU, memory, and I/O devices to processes.

**Types of OS:**
- **Batch OS:** Executes batches of jobs without user interaction.
- **Multiprogramming OS:** Runs multiple programs concurrently.
- **Multitasking OS:** Allows ==multiple tasks to share CPU time==.
- **Time Sharing OS:** Provides quick switching among users.
- **Real-Time OS:** Responds to events within ==strict timing constraints==.
- **Distributed OS:** Manages ==multiple systems as a single unit==.
- **Network OS:** Provides services to computers connected via a network.
- **Mobile OS:** Designed for smartphones and tablets.

**Components of OS:**
1. **Kernel:** ==Core part== controlling all operations and resource management.
2. **Shell:** ==Interface between user and kernel== (CLI or GUI).
3. **File System:** Organizes and manages data storage.
4. **Device Drivers:** Interface between OS and hardware devices.

**System Calls:**  ==Interface between user programs and OS== ==to request services== like file operations, process control, etc.

**Examples of OS:** Windows, Linux, UNIX, macOS, Android.


### **2. Process Management**

**Definition:**  A ==**process** is a program in execution==. It includes the program code, program counter, registers, and variables.

**Process States:**
1. **New:** Process being created.
2. **Ready:** Waiting to be assigned to CPU.
3. **Running:** Instructions being executed.
4. **Waiting/Blocked:** Waiting for I/O or event completion.
5. **Terminated:** Execution completed.

**Process Control Block (PCB):**  A ==data structure used by OS== to ==store process information==.  
**Contains:**
- Process ID
- Process state
- CPU registers
- Program counter
- Memory management info
- Accounting and I/O status info

**Process Scheduling:** Determines the ==order of process execution==.

**Types of Schedulers:**
1. **Long-term Scheduler:** Controls job admission (==New → Ready==).
2. **Short-term Scheduler:** Selects process to execute next (==Ready → Running==).
3. **Medium-term Scheduler:** ==Handles process suspension and swapping==.

**Scheduling Queues:**
- **Job Queue:** ==All processes in the system==.
- **Ready Queue:** ==Processes waiting for CPU==.
- **Device Queue:** ==Processes waiting for I/O==.
    
**Context Switch:** Switching CPU from one process to another by saving and loading PCB data.

**Operations on Process:**
- Creation
- Scheduling
- Execution
- Suspension
- Termination

**Process Creation (Parent → Child):**
- ==Child gets resources from parent==.
- Execution may be concurrent or sequential.
- Example: ==`fork()`== in UNIX.
    

**Inter-Process Communication (IPC):**  Used for ==data exchange among processes==.  
**Methods:**

- **Shared Memory:** Common memory space.
    
- **Message Passing:** Direct communication via messages.
    

**Process Scheduling Algorithms:**
1. **FCFS (First Come First Serve):** Non-preemptive, simple, but high waiting time.
2. **SJF (Shortest Job First):** Minimum average waiting time, may cause starvation.
3. **Priority Scheduling:** Based on priority, starvation possible.
4. **Round Robin:** ==Fixed time quantum==, preemptive, used in time-sharing.
5. **Multilevel Queue:** ==Different queues for process types==.
6. **Multilevel Feedback Queue:** ==Processes can move between queues==.


**Performance Metrics:**
- CPU Utilization
- Throughput
- Turnaround Time
- Waiting Time
- Response Time

### **3. Inter-Process Communication (IPC)**

**Definition:**  ==IPC allows processes to== ==communicate and synchronize== their actions when executing concurrently. It enables data exchange among processes within the same or different systems.

**Objectives:**
- ==Data sharing== between processes
- ==Synchronization== of concurrent tasks
- Modularity in system design
- Efficient resource utilization

**Types of IPC Models:**

1. ==**Shared Memory Model==:**
    - Processes ==share a common memory space==.
    - Communication via read/write on shared region.
    - ==Fast==, as it avoids kernel intervention after setup.
    - ==Requires synchronization== (e.g., semaphores).
    - **Example:** ==Producer-Consumer problem==.
        
2. ==**Message Passing Model==:**
    - Processes communicate by ==exchanging messages through the kernel==.
    - No shared memory required.
    - ==Suitable for distributed systems==.
    - Easier synchronization but slower than shared memory.

**Message Passing Mechanisms:**

- **Direct Communication:**
    - Processes must name each other explicitly.
    - **Example:** `send(P, message)` and `receive(Q, message)`
        
- **Indirect Communication:**
    - Messages are sent via mailboxes (ports).
    - Mailbox has unique ID; processes share it for communication.


**Communication Methods:**
- **Synchronous (==Blocking==):** Sender ==waits until receiver acknowledges==.
- **Asynchronous (==Non-blocking==):** Sender ==continues after sending message==.

**Synchronization in IPC:** == Ensures correct execution order== among cooperating processes.
- Achieved using ==**Semaphores**, **Mutexes**, **Monitors**, or **Condition Variables**.==

**Classical IPC Problems:**
1. **Producer-Consumer Problem** – Synchronizing shared buffer access.
2. **Reader-Writer Problem** – Managing concurrent reads and exclusive writes.
3. **Dining Philosophers Problem** – Avoiding deadlocks during resource sharing.

**Advantages of IPC:**
- Efficient data exchange
- Modularity and scalability
- Enables concurrency and parallelism

**Disadvantages:**
- Synchronization overhead
- Potential for deadlock and race conditions

### **4. Deadlocks, Mutex, Semaphores**

##### **Deadlocks**

**Deadlock Definition:**  A **deadlock** occurs when a set of processes are blocked because each process is holding a resource and waiting for another resource held by another process.

**Necessary Conditions for Deadlock (==Coffman Conditions==):**
1. ==**Mutual Exclusion==:** Only one process can use a resource at a time.
2. ==**Hold and Wait==:** A process holding a resource can request additional resources.
3. ==**No Preemption==:** Resources cannot be forcibly taken away.
4. ==**Circular Wait==:** A circular chain of processes exists where each waits for a resource held by the next.
    

**Resource Allocation Graph (==RAG==):**  Used to represent processes and resources.
- ==Deadlock occurs if there is a **cycle**== (for single instance per resource).
    

**Deadlock Handling Methods:**

1. **Deadlock Prevention:** Ensure ==at least one of the necessary conditions never holds==.
    - No hold and wait → request all resources at once.
    - Allow preemption → forcibly release resources.
    - Impose ordering on resources → prevent circular wait.
        
2. **Deadlock Avoidance:** Dynamically check safe state before allocation.
    - ==**Banker’s Algorithm:**== Ensures the system always remains in a safe state.
        
3. **Deadlock Detection:**
    - ==Detects cycle in RAG== or uses a wait-for graph.
    - Requires recovery (abort or preempt processes).
        
4. **Deadlock Recovery:**
    - Terminate processes or preempt resources to break deadlock.

##### **Mutex**

**Mutex (==Mutual Exclusion Lock==):**  Used to ==protect shared resources== so that ==only one process/thread can acces==s them ==at a time==.
- **Lock():** Acquire ownership of critical section.
- **Unlock():** Release ownership.
- Binary (`0` or `1`) state.
- Used in multithreading synchronization.

**Example (C-style Pseudocode):**
```cpp
mutex.lock();
// critical section
mutex.unlock();
```

##### **Semaphores**

**Semaphores:** A ==synchronization tool== that ==uses an integer variable to control access== to shared resources.
- ==Introduced by Dijkstra==.
    

**Types:**
1. ==**Binary Semaphore:**== Works like a ==mutex (0 or 1==).
2. ==**Counting Semaphore:**== Allows ==multiple instances of a resource==.
    

**Operations:**
- **wait() / P():** Decrements semaphore; if value < 0, process waits.
- **signal() / V():** Increments semaphore; if value ≤ 0, a waiting process resumes.
    

Example (==Producer-Consumer== using Semaphore):
```cpp
semaphore mutex = 1, full = 0, empty = n;

wait(empty);
wait(mutex);
// produce item
signal(mutex);
signal(full);
```

**Difference Between Mutex and Semaphore:**

| Feature   | Mutex                       | Semaphore                       |
| --------- | --------------------------- | ------------------------------- |
| Ownership | ==Owned by process/thread== | No ownership                    |
| Type      | ==Binary only==             | Binary or Counting              |
| Use       | Mutual exclusion            | ==Signaling between processes== |
| Example   | Thread synchronization      | ==Producer-Consumer problem==   |

##### **5. Memory Management Techniques**

**Definition:**  Memory management is the process of controlling and coordinating computer memory—allocating blocks to processes and freeing them when no longer needed.

**Objectives:**
- Efficient memory utilization
- Fast access and allocation
- Protection and isolation of processes

##### **1. Contiguous Memory Allocation**

**Contiguous Memory Allocation:**  Processes are allocated a single continuous block of memory.

**a. Fixed Partitioning:**
- Memory divided into fixed-size partitions.
- One process per partition.
- Simple but causes **internal fragmentation**.

**b. Variable Partitioning:**
- Partitions created dynamically based on process size.
- Reduces internal fragmentation but may cause **external fragmentation**.

**Allocation Methods:**
- **First Fit:** Allocate first sufficient free block.
- **Best Fit:** Allocate smallest block large enough.
- **Worst Fit:** Allocate largest available block.

##### **2. Non-Contiguous Memory Allocation**

**Non-Contiguous Memory Allocation:**  Memory blocks of a process are placed in non-adjacent locations.

**a. Paging:**
- Physical memory divided into fixed-size blocks called **frames**.
- Logical memory divided into same-size **pages**.
- Page table maps logical pages to physical frames.
- Eliminates external fragmentation; small **internal fragmentation** possible.

**b. Segmentation:**

- Memory divided into variable-sized **segments** based on logical divisions (code, data, stack).
- Each segment has a segment number and offset.
- Provides logical view but can cause **external fragmentation**.

**c. Segmented Paging (Hybrid):**
- Logical memory divided into segments; each segment divided into pages.
- Combines flexibility of segmentation and efficiency of paging.

##### **3. Virtual Memory**

**Virtual Memory:**  Technique that allows execution of processes not fully in main memory.
- Implemented using **paging** and **demand paging**.
- **Page Fault:** Occurs when required page not in main memory.

**Advantages:**
- Enables large programs to run.
- Efficient memory utilization.
- Provides isolation between processes.
    
**Techniques in Virtual Memory:**
- **Demand Paging:** Load pages only when required.
- **Page Replacement Algorithms:**
    - **FIFO:** Replace oldest page.
    - **LRU (Least Recently Used):** Replace least recently used page.
    - **Optimal:** Replace page not used for longest time (theoretical best).
    - **Clock Algorithm:** Approximation of LRU.
##### **Fragmentation**

**4. Fragmentation:**
- **Internal Fragmentation:** ==Unused memory within allocated partition==.
- **External Fragmentation:** ==Free memory scattered in small blocks==.
- **Compaction:** ==Rearranging processes== to ==remove external fragmentation==.

##### **Swapping**

**5. Swapping:**  Entire process moved temporarily from main memory to secondary storage (backing store) and vice versa to ==free space for other processes==.


### **6. I/O Devices**

**Definition:** Input/Output (I/O) devices are hardware components used for communication between the computer system and the external environment. The OS manages and coordinates all I/O operations.

**Types of I/O Devices:**
1. **Input Devices:** Keyboard, Mouse, Scanner, Microphone.
2. **Output Devices:** Monitor, Printer, Speaker.
3. **Storage Devices:** Hard Disk, SSD, USB, CD/DVD.
4. **Communication Devices:** Network Card, Modem, Router.
    

**I/O System Components:**
1. **I/O Hardware:** Physical devices for data transfer.
2. **Device Drivers:** ==Software modules== that control I/O devices and ==provide standard interface== to the OS.
3. **I/O Controller:** ==Hardware that manages data exchange== between CPU and device.
4. **Interrupt Handlers:** ==Manage signals when I/O operation completes== or errors occur.
    

**I/O Techniques:**
1. ==**Programmed I/O:**==
    - ==CPU actively waits for I/O operation to complete.==
    - Simple but ==inefficient (CPU busy-waiting)==.
        
2. ==**Interrupt-Driven I/O:**==
    - Device ==sends interrupt to CPU upon completion==.
    - CPU performs other tasks while waiting.
        
3. ==**Direct Memory Access (DMA):**==
    - DMA controller ==transfers data directly between I/O device== and memory without CPU involvement.
    - CPU only initializes and completes the transfer.
    - ==Increases throughput and efficiency==.
        
==**I/O Buffering:**==  Used to match speed differences between CPU and I/O devices.
- **Single Buffering:** One buffer in main memory.
- **Double Buffering:** Two buffers; one used while the other fills/empties.
- **Circular Buffering:** Multiple buffers managed in circular queue form.
    
**I/O Scheduling:**  Decides the order of servicing I/O requests for efficiency.  

==**Disk Scheduling Algorithms:**==
- **FCFS (==First Come First Serve==):** Serves requests in arrival order.
- **SSTF (==Shortest Seek Time First==):** Selects request closest to current head.
- **SCAN (==Elevator==):** Moves head back and forth servicing requests.
- **C-SCAN:** One-way scan; more uniform wait time.
- **LOOK / C-LOOK:** Like SCAN/C-SCAN but ==stops at last request before reversing==.
*Note* : **LOOK** stops at last request; **SCAN** goes to disk end before reversing.

==**Spooling== (==Simultaneous Peripheral Operations On-Line==):** ⭐
- Technique where ==data is temporarily stored on disk== ==before being sent to device== (e.g., printer queue).
- Allows ==CPU and I/O device to work concurrently==.
    
**Error Handling:**
- Performed by I/O controllers and drivers.
- Includes retries, timeouts, and interrupt signaling for failures.

### **7. OS Protection and Security**

**Definition:** Protection and Security in an Operating System ensure that system resources (CPU, memory, files, devices) are used and accessed only in authorized ways, ==maintaining system integrity and confidentiality==.

##### **1. Protection**

**Protection:**  Concerned with ==**controlled access**== to system resources among processes.  
**Goals:**
- Prevent interference between processes.
- Enforce access control policies.
    
**Protection Domain:**
- A set of (object, rights) pairs defining what operations a process can perform on objects.
- Each process operates within a domain; switching domains changes access rights.
    
**Access Matrix Model:**
- A matrix representation where rows represent **subjects (users/processes)** and columns represent **objects (files/devices)**.
- Entry (i, j) defines allowed operations of subject _i_ on object _j_.

**Implementation Methods:**
- **Access Control Lists (ACLs):** Per-object list of subjects and permissions.
- **Capability Lists:** Per-subject list of objects and permissions.

##### **2. Security**  

**Security:** Concerned with ==**defending the system**== against external or internal threats.

**Goals of Security:**
1. **Confidentiality:** Prevent unauthorized disclosure of data.
2. **Integrity:** Prevent unauthorized modification of data.
3. **Availability:** Ensure system resources are accessible to authorized users.
    
**Security Threats:**
- **Malware:** Viruses, Worms, Trojans, Ransomware.
- **Unauthorized Access:** Breaking authentication mechanisms.
- **Denial of Service (DoS):** Overloading system resources.
- **Spoofing:** Imitating legitimate users.
- **Phishing/Social Engineering:** Manipulating users into revealing credentials.
    
**Security Mechanisms:**
1. **Authentication:** Verifies user identity (password, biometric, token).
2. **Authorization:** Determines access rights after authentication.
3. **Encryption:** Converts data into unreadable form using cryptographic keys (symmetric/asymmetric).
4. **Audit and Logging:** Records system activities to detect and trace security breaches.
5. **Intrusion Detection Systems (IDS):** Monitors and analyzes system behavior for suspicious activities.

**Protection Mechanisms:**
- **User Modes:** Distinguish between user and kernel operations.
- **Memory Protection:** Prevents access to unauthorized memory (base and limit registers, paging protection bits).
- **File Protection:** Controlled through permissions (read/write/execute).
- **I/O Protection:** Ensures safe and exclusive access to I/O devices.
    
**Security Policies:**
- Define rules for user access and data handling.
- Examples: Discretionary Access Control (DAC), Mandatory Access Control (MAC), Role-Based Access Control (RBAC).
    
**Summary:**
- **Protection** ensures controlled use of resources by processes.
- **Security** defends the system against malicious activities and unauthorized access.