---
description: Made By Me 💚
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# OS Doubts Concepts

## My Doubts Questions Notes

> Made using GPT

**Virtual Memory ⭐**

* **Virtual Memory** is a memory management technique where the OS uses **disk space as an extension of RAM**, allowing execution of large programs or multiple programs even if actual physical RAM is limited.
* It provides **an illusion of a large, continuous memory** to processes.
* Implemented using **paging** or **segmentation**.
* Uses **page replacement algorithms** when RAM is full.

**Multiprogramming vs. Multithreading vs. Multiprocessing (Tech Evolution Order)**

1. **Multiprogramming**
   * Oldest concept
   * **Multiple programs loaded into memory** ⭐
   * CPU switches between them to improve utilization
   * Programs are independent
2. **Multithreading**
   * A single process is divided into multiple threads
   * Threads **share same memory/resources**
   * Can **run independently** and concurrently
   * Improves CPU utilization **within one app**
3. **Multiprocessing**
   * Multiple CPUs or cores used simultaneously
   * **Each core handles one process independently** ⭐
   * Enables real parallel execution
   * Maximizes computational efficiency

**Multiprocessing: 8-core system can run 8 processes simultaneously?**

✔ **Yes**\
Each core can execute one process independently.\
So, in theory, 8 processes can run **truly parallel** on an 8-core system.

**Quad-core PC runs many apps at once?**

✔ **Yes**, because of:

1. **Context Switching**
   * CPU switches between tasks rapidly
   * Creates illusion of parallelism
2. **Multithreading**
   * Apps can use multiple threads even on fewer cores
3. **Efficient OS Resource Management**
   * OS divides CPU time among processes
4. **Task Scheduling**
   * OS uses scheduling algorithms to assign tasks to cores

**Is Context Switching same as Task Scheduling?**

**No**, they are different:

* **Task Scheduling**
  * Decides **which** task/thread to run next
  * Uses algorithms like Round Robin, SJF, etc.
* **Context Switching**
  * Happens **when switching** from one task to another
  * Saves current state & loads new one (registers, PC, etc.)

**Fragmentation and Segmentation**

1. **Fragmentation**
   * Fragmentation ==refers to wasted memory space== in storage or RAM due to allocation strategies.
   * **Types:**
     * \*\*External Fragmentation: \*\* Occurs in **contiguous** memory allocation, Free memory is divided into small scattered blocks, ==Enough total space exists, but not in a single contiguous block==
     * **Internal Fragmentation** : Occurs when memory is allocated in fixed-size blocks, A process may not use the entire allocated block, ==Wasted space **inside** allocated memory==
   * **Solution Techniques:**
     * **Compaction** (for external) : Rearranges memory to combine free blocks
     * **Paging/Segmentation** : Allocates memory in fixed-size (pages) or logical (segments) units to avoid external fragmentation
2. **Segmentation** ⭐
   * Segmentation is a ==memory management scheme== that divides a program into **logical segments**.
   * **Key Points:**
     * Each segment represents a **logical unit** (e.g., code, data, stack)
     * Segments have **variable sizes**
     * Each segment has: **Segment number** & **Offset (within the segment)**
     * Address = (Segment Number, Offset)
   * **Advantages:**
     * Reflects **logical view** of program
     * Enables **protection and sharing** per segment
     * Avoids internal fragmentation
     * Easy to grow individual segments (e.g., stack)
   * **Disadvantages:**
     * Can cause **external fragmentation**
     * Requires **segment table** and hardware support

| Feature             | Fragmentation                 | Segmentation                            |
| ------------------- | ----------------------------- | --------------------------------------- |
| Type                | Memory Wastage Problem        | Memory Management Scheme                |
| Types               | Internal, External            | Only logical segments                   |
| Purpose             | Describes memory inefficiency | Divides program into logical components |
| Allocation Unit     | Blocks or Pages               | Segments (code, data, stack)            |
| Address Structure   | Single address or offset      | Segment No. + Offset                    |
| Fragmentation Issue | May occur                     | May cause external fragmentation        |

**Many Internal Fragmentations Lead to External Fragmentation ?**

-> No, internal and external fragmentation are **related to memory allocation**, but **one does not directly cause the other**. Here's the correct explanation:

**Internal Fragmentation**

* Occurs when memory is allocated **more than required**.
* Example: If a process needs 28KB, but the memory block is 32KB, then 4KB is wasted **inside** the allocated block.
* → Wasted **within** allocated space.

**External Fragmentation**

* Occurs when **free memory** is scattered in small non-contiguous blocks.
* Total free memory may be enough, but not in a single continuous block to satisfy a large request.
* → Wasted **between** allocated spaces.

**Relation**

* They are **not a cause-effect** of each other.
* Internal fragmentation happens due to **fixed-size allocations**.
* External fragmentation happens due to **variable-size allocations** and **freeing** of memory.

**How Data is Written on a Hard Disk:**

1. **Platter**: The hard disk has one or more spinning disks (platters) coated with a **magnetic material**.
2. **Read/Write Head**:
   * Floats just above the surface of the platter.
   * Does **not touch** the surface physically.
3. **Writing Data**:
   * The write head generates a **magnetic field**.
   * It **magnetizes tiny regions (bits)** of the platter in different directions (e.g., clockwise for `0`, counterclockwise for `1`).
   * These magnetic polarities represent binary data.
4. **Reading Data**:
   * The read head detects the magnetic orientation of each region.
   * Converts it back into digital data (`0` and `1`).

***

***

## Confusion & Doubts Topics

#### Resource Management

> Swapping, Thrashing Control, , Cache Management

**Cache Management**

**Cache** is ==small, fast memory== between CPU and RAM to ==reduce average memory access time==

**Locality of reference:**

* Temporal locality: recently accessed data likely to be accessed again
* Spatial locality: nearby memory locations likely to be accessed soon

**Mapping Techniques:**

* **==Direct Mapping:==** each block maps to one cache line
* **==Associative Mapping:==** any block can go to any line
* **==Set Associative Mapping:==** block maps to any line in a specific set

**Replacement Policies:**

* LRU (Least Recently Used) – removes least recently accessed block
* FIFO – removes block loaded first
* LFU – removes least frequently accessed block

**Write Policies:**

* Write Through – writes to cache and memory simultaneously
* Write Back – writes only to cache, updates memory on replacement

**Swapping**

* Moving an entire process between ==main memory and secondary storage== (backing store)
* When **memory is full, OS swaps out** a process to free space, and **later swaps it back** when required
* Helps support multiprogramming and larger processes than physical memory
* Overhead occurs due to disk I/O, used less in modern systems except in memory pressure situations

**Thrashing Control**

* Thrashing happens when the ==**OS spends most of the time swapping pages== instead of executing processes due to excessive page faults**
* **Cause :** very low degree of multiprogramming, processes not getting enough frames
* **Working Set Model :** allocate frames based on the actively used pages (working set). If total demand exceeds available memory, reduce multiprogramming level
* **Page Fault Frequency (PFF) :** monitor fault rate. If **high** → allocate more frames; If **low** → take away frames
* Goal: maintain fault rate in acceptable range and avoid constant swapping

***

#### Device management -

> DMA, Buffering, Spooling, Polling vs Interrupt, SCAN vs LOOK

**Polling vs Interrupt**

**Polling:**

* CPU repeatedly checks device status register
* Simpler but wastes CPU time

**Interrupt**:

* Device notifies CPU by sending an interrupt signal
* Efficient, CPU works on other tasks until interrupt arrives

**DMA (Direct Memory Access)**

* Allows devices to **transfer data directly to/from main memory** ==without CPU involvement==
* \==CPU sets DMA controller with address, count, I/O command== → DMA handles transfer → interrupts CPU when done
* \==Reduces CPU overhead== and increases I/O throughput

**Buffering**

**Temporary storage** area ==to match speed difference between producer–consumer== (I/O device and CPU)

**How Buffering Works**

* Producer (device) puts data into buffer and Consumer (CPU) takes data out
* If ==device is faster== than CPU → buffer ==prevents data loss by storing extra data== temporarily
* If ==CPU is faster than device== → buffer ==prevents CPU from waiting by giving stored data==

**Cycle:**

1. Producer writes data into buffer
2. Consumer reads data from buffer
3. Buffer is reused after read

**Types:**

* **Single Buffer:** one buffer used
* **Double Buffer:** ==two buffers for parallel filling/emptying==
* **Circular Buffer:** multiple buffers in a cycle for continuous data flow
* Double and Circular buffering reduce waiting by providing additional buffers so producer and consumer can work in parallel rather than blocking each other

**Spooling (Simultaneous Peripheral Operation -Line ⭐)**

* \==Used when **CPU or multiple processes are faster than an I/O device** ==
* Data meant for a ==**slow device is first stored on secondary storage (spool area)** instead of sending directly==
* The **device works independently** and pulls one job at a time from the spool area

**Example (Printer):**

1. Many processes send print requests
2. Requests are stored in a **spool directory on disk**
3. **Printer picks jobs one by one** in background while CPU continues other work

**Why useful:**

* **Multiprogramming support:** ==many jobs queued without blocking processes==
* **Device-independent:** programs don’t wait for a specific device to finish
* **Prevents device hold:** single device not occupied by one process continuously

**Spooling vs Buffering**

| Feature          | Spooling                                                  | Buffering                                                |
| ---------------- | --------------------------------------------------------- | -------------------------------------------------------- |
| Storage location | Secondary storage (disk)                                  | Main memory (RAM)                                        |
| Purpose          | ==Queue jobs for slow device and let processes continue== | ==Match speed difference between producer and consumer== |
| Data handling    | Entire job stored before device uses it                   | Data transferred continuously in small chunks            |
| Device sharing   | Enables multiple processes to share a single device       | Not primarily for sharing, only for speed matching       |
| Example          | Print jobs queued on disk                                 | Keyboard data stored in memory while CPU reads           |

**Key Difference:**\
Spooling works offline using disk to hold full jobs for a device, while Buffering works in memory to allow smooth continuous data flow between device and CPU.

**SCAN vs LOOK (Disk Scheduling)**

**SCAN (Elevator algorithm):**

* Head moves end-to-end across disk, servicing requests along the way, then reverses direction
* Covers entire disk even if no request exists at extremes

**LOOK:**

* Similar to SCAN but head ==reverses direction at last request== instead of disk end
* Lower seek time because unnecessary movement to disk ends is avoided

***

#### **Process Management**

> Multilevel Queue, and Multilevel Feedback Queue, Threads, IPC, Pipes, message passing, semaphores, Critical Section, Synchronization

**Multilevel Queue (MLQ)**

* Processes are **permanently assigned to a queue** based on type (system/interactive/batch etc.)
* **Each queue has separate scheduling** (example: top queue uses RR, lower queue uses FCFS)
* **Fixed priority order:** higher-priority queues always run first; lower queues get CPU only when higher ones are empty
* **No movement between queues**, so a low-priority process may **starve** if high-priority queues stay busy

**Multilevel Feedback Queue (MLFQ)**

* Processes **can move between queues** depending on how much CPU time they use
* **Starts at highest priority:** if the job finishes quickly → stays at top; if it takes long → moves down gradually
* **Short jobs and interactive jobs get high priority**, long CPU-bound jobs settle in lower queues
* **Aging support:** long-waiting processes are promoted to avoid starvation

**Essence:**

* MLQ is rigid with fixed queue assignment and risk of starvation.
* MLFQ is adaptive, dynamic, and fair by adjusting priority based on execution behavior.

**Threads**

* **Lightweight ==subprocess** inside a process== that ==shares **code, data, and OS resources** with other threads of the same process==
* \==Allows **parallel execution within a single program**,== e.g., one thread handles UI while another handles calculations
* **Context switching is faster** than switching between processes because memory and resources are shared
* **Types:**
  * \==**User-level threads:**== managed by thread library in user space, fast switching but one blocking call can block all threads
  * **Kernel-level threads:** managed by OS kernel, true parallelism across CPUs but slower switching due to kernel involvement

**Process Management / Concurrency Control / IPC:**

```
                        ┌──────────────┐
                        │   Processes  │
                        └──────┬───────┘
                               │
                               │ need to communicate & coordinate
                               ▼
                    ┌────────────────────────┐
                    │ IPC (Inter-Process Comm)│
                    └──────────┬─────────────┘
                               │
                ┌──────────────┴───────────────┐
                │                              │
                ▼                              ▼
     ┌───────────────────┐            ┌────────────────────┐
     │ Shared Memory     │            │ Message Passing    │
     └────────┬──────────┘            └─────────┬──────────┘
              │                                 │
              │ requires sync to avoid RC       │ primitive-based, no shared mem
              ▼                                 ▼
 ┌─────────────────────────┐          ┌─────────────────────────────┐
 │ Critical Section Problem│<-------->│ Pipes / Message queues /    │
 └───────────┬─────────────┘          │ Sockets (network IPC)       │
             │                        └─────────────────────────────┘
             │ solved by
             ▼
 ┌─────────────────────────┐
 │ Synchronization Tools   │
 └───────────┬─────────────┘
             │
 ┌───────────┼───────────────────────────────────────────────┐
 │           │                      │                        │
 ▼           ▼                      ▼                        ▼
Mutex   Semaphores             Condition Vars          Monitors / Barriers
(locks) (counter-based)        (thread signaling)      (higher-level sync)
```

```
                        ┌────────────────┐
                        │   Signals      │
                        └──────┬─────────┘
                               │
                               │ async notifications for process control
                               ▼
                        Affects process/thread execution
```

**Intuition:**

* IPC allows processes to exchange data.
* If data is shared (shared memory), synchronization is mandatory to protect the **critical section**.
* Synchronization uses primitives like **mutexes, semaphores, monitors, condition variables**.
* If communication is via **message passing** (pipes, sockets), consistency is handled by messaging and less synchronization is needed.
* **Signals** are separate — they interrupt a process to notify an event (not mainly for data transfer).

This is how all components connect logically in OS.

**Critical Section**

* \==Code segment where shared data is accessed and must not be executed by more than one thread at a time==
* Problem: ensure mutual exclusion, progress, and bounded waiting

**Synchronization**

* \==Coordination among processes/threads to avoid **race conditions**== when accessing shared resources
* Achieved using ==locks, semaphores, monitors, condition variables, barrier==s
* **Goal:** enforce safe execution order while maximizing concurrency

**IPC (Inter-Process Communication)**

* Mechanism that allows **processes to exchange data and coordinate their actions**, whether running on the **same system or different networked systems**
* Required because processes have **separate address spaces**, so data cannot be shared directly
* **Models:** Shared Memory and Message Passing

**Pipes**

* IPC mechanism using a unidirectional communication channel
* Writer writes to pipe buffer and reader reads from it
* Ordinary Pipes for related processes; Named Pipes (FIFOs) for unrelated processes

**Message Passing**

* Processes communicate by sending messages via OS primitives send() and receive()
* No shared memory required; useful in distributed systems
* Can be blocking or non-blocking

**Mutex (Mutual Exclusion Lock)**

* Synchronization mechanism used to ==ensure **only one thread/process enters the critical section at a time**==
* Works like a **lock**: a thread must acquire the mutex before accessing shared data and release it afterward
* If another thread tries to lock an already locked mutex, it **blocks and waits**
* Guarantees **mutual exclusion**, preventing race conditions when accessing shared resources

**Semaphores**

* Integer ==synchronization variable used to control access to shared resources==
* Operations: wait(P) decrements; signal(V) increments
* \==Binary semaphore (0/1) for mutual exclusion==; counting semaphore for multiple instances

**Sockets**

* IPC mechanism for communication between processes over a network or across different machines
* Works on client–server model using IP address and port
* Supports both **connection-oriented (TCP)** and **connectionless (UDP)** data transfer
* Suitable for distributed systems and internet-based communication

**Signals**

* Software interrupts sent to a process to notify an event or trigger an action
* Used for **process control** (e.g., terminate, pause, resume)
* Process can handle signals using **signal handlers** or follow default OS actions
* Common example: `SIGINT` generated when user presses `Ctrl + C` to stop a program

***

#### File Management - Inodes, Mounting and Unmounting, Directory Structure, File Allocation Method

**Inodes**

* **Data structure** in **Unix-like** file systems storing metadata about a file
* Stores: file size, owner, permissions, timestamps, disk block pointers
* Does not store file name; directory links names to inode numbers
* Inode contains direct, indirect, double-indirect, triple-indirect block pointers for locating file data on disk

**Mounting and Unmounting**

**Mounting:**

* \==Attaching a **file system** to a directory (mount point) so its contents become accessible ==
* Requires device name and file system type; OS updates mount table

**Unmounting:**

* Detaches file system from mount point after ensuring no open files or active processes
* Prevents corruption and ensures data consistency

**Directory Structure**

Organizes files logically in file system

Types:

* Single-level: all files in one directory
* Two-level: separate directory per user
* Tree-structured: hierarchical, supports subdirectories
* Acyclic graph: allows shared directories using links without cycles
* General graph: supports links with cycle detection required

**File Allocation Method**

Determines how disk blocks are assigned to files

Types:

* **Contiguous Allocation:** file occupies continuous blocks; fast access but causes external fragmentation
* **Linked Allocation:** each block points to next block; no fragmentation but slow random access
* **Indexed Allocation:** index block stores all block addresses; supports random access but index overhead
* Hybrid approach used in many file systems (e.g., inode’s direct + indirect pointers)
