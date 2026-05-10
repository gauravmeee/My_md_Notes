---
description: Made By Me 💚
icon: dot
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
# OS Important Questions (PSU)

## # [SJVN Executive Trainee - IT](https://solutionsadda.in/wp-content/uploads/2019/07/SJVNL_1569050019_1258O1990S2D67E1.pdf) PYQ

**Ques. If a CPU takes 10 ms to decide to execute a process of 100 ms, approximately what percentage of time will be wasted by CPU in scheduling work?**

```
- Scheduling time (overhead) = 10 ms
- Actual process execution time = 100 ms
- Total time taken = 10 ms (scheduling) + 100 ms (execution) = 110 ms
- % Time wasted in Scheduling = (10/110) x 100  = 9.09 % ✅
```

**Ques. In a multithreaded process, threads Do not Share What ? ⭐**

> Multithreading – Shared vs Private Data:

**Shared Among Threads (within the same process):**

```
- Code Section → All threads share the same program code.
- Data Section → Global/static variables are shared.
- Files → File descriptors opened by one thread are visible to others.
```

**Not Shared (Private to Each Thread):**

```
- Stack → Each thread has its own stack for function calls, local variables, return addresses, etc.
```

**Ques. Preemptive scheduling was introduced in which Window Version**

> Preemptive Scheduling in Windows

* **Preemptive scheduling** allows the OS to interrupt a running process and switch the CPU to another process based on priority or time slice. It enables true multitasking.
* **Ans:** Window 95 ✅
* **Windows NT 3.1** : It had **full preemptive multitasking** from the start, but Targeted **enterprise** systems, not mainstream consumers. ⭐
* **Windows 95** : It was the **first consumer Windows OS** to bring **preemptive multitasking (for 32-bit apps)**.

**Windows OS Evolution & Scheduling Type**

| Windows Version    | Release Year | Scheduling Type                                   | Notes                                                                                 |
| ------------------ | ------------ | ------------------------------------------------- | ------------------------------------------------------------------------------------- |
| **Windows 3.0**    | 1990         | Cooperative Scheduling                            | - 16-bit only- Each process voluntarily yields control                                |
| **Windows NT 3.1** | 1993         | Fully Preemptive Scheduling                       | - First NT version- 32-bit OS with full preemptive multitasking                       |
| **Windows 95**     | 1995         | Hybrid: Preemptive (32-bit), Cooperative (16-bit) | - First to support preemptive multitasking for 32-bit apps- Legacy support for 16-bit |
| **Windows NT 4.0** | 1996         | Fully Preemptive Scheduling                       | - GUI similar to Win95- Better performance and stability                              |
| **Windows 98**     | 1998         | Same as Windows 95                                | - Improved multitasking for 32-bit- Still cooperative for 16-bit                      |

**Ques. Which of the following statements is (True/False)**

> Interrupts and Interrupt Vector Table

**What is an Interrupt?**

* An **interrupt** is a ==signal to the CPU indicating an event that needs immediate attention==.
* Interrupts ==pause the current execution to run a specific routine== called an **interrupt handler**. ⭐

**(i) Device controllers raise an interrupt by asserting a signal on the interrupt request line** ✅True

* Device controllers (e.g., keyboard, disk) use a dedicated line (IRQ – Interrupt Request Line) to notify the CPU of an event.

**(ii) Interrupt vector contains the memory addresses of specialized interrupt handlers** ✅True

* An **interrupt vector** is a ==table that stores **pointers (addresses)** to the corresponding **interrupt service routines (ISRs)==** ⭐
* On interrupt, the CPU uses this table to locate and execute the right handler.

**Ques. Which of the following OS/process statements is (True/False)**

> OS Memory Access and Protection

* **CPU can directly access main memory and registers** ✅True\
  Registers are the fastest memory, and main memory is accessed via address buses. ✅True
* **Illegal memory access results in trap interrupt**\
  <mark>Trap is a **synchronous software interrupt**== triggered by events like invalid memory ✅True
* **Memory protection among processes is implemented using base and limit registers** ✅True\
  Base register holds the start address, limit register defines the size. Ensures a process accesses only its own memory.
* **Memory Address Register (MAR) stores the logical address** ❌ False ==MAR stores the **physical address**== for memory access. Logical address is translated before reaching MAR.

**👉 Memory Access & Protection Notes ⭐**

**1. Logical Address vs Physical Address**

* **Logical Address**: Address generated by the CPU.
* **Physical Address**: Actual address in RAM.
* Logical → Physical translation is handled by ==**MMU== (Memory Management Unit)**.

**2. Memory Address Register ==(MAR)==**

* Holds **physical address** to access RAM.
* Works with **Memory Buffer Register ==(MBR)**== to read/write data.

**3. Memory Protection**

* Prevents a process from accessing memory of another process.
* Implemented using:
  * <mark>**Base Register**: ==Holds starting address of process memory.
  * <mark>**Limit Register**:== Holds the range (size) of memory allocated.

**4. Trap Interrupt**

* **Synchronous** interrupt caused by:
  * Illegal memory access
  * Divide by zero
  * Invalid instruction
* CPU transfers control to OS interrupt handler.

**5. CPU Access Capabilities**

* CPU can directly access:
  * **Registers** (fastest)
  * **Main Memory** (RAM)
* <mark>Cannot access **secondary memory** directly== (==needs I/O controller==).

**6. Protection Mechanisms**

* **Segmentation**: Divides **process** into segments (code, data, stack).
* **Paging**: Divides **both process and physical memory** into fixed-size units (pages and frames).
* **Page Table**: Maps logical to physical addresses.

| Concept                       | Description                                        |
| ----------------------------- | -------------------------------------------------- |
| Logical Address               | Generated by CPU                                   |
| Physical Address              | Actual location in RAM                             |
| MAR (Memory Address Register) | Stores physical address for access                 |
| Trap Interrupt                | Triggered by invalid memory actions                |
| Base & Limit Registers        | Used for enforcing process-level memory protection |
| CPU Memory Access             | Can directly access registers & main memory        |
| MMU                           | Translates logical to physical address             |

**Q60. What will be the Effective Access Time in Demand Paging**

> Demand Paging - Effective Access Time

```
1. Inputs for Total Time to Access Memory:
	- Memory access time (ma) = 300 ns = 0.003 ms
	- Page fault rate (p) = 5% = 0.05


2. Inputs for Page Fault Service Time:
	- If page to be replaced is:
	    - Not modified (40%) → service time = 10 ms
	    - Modified (60%) → service time = 15 ms
```

**Page Fault Service Time (PFST)**

```sh
PFST = (%Modified × Modified_Time) + (%Not_Modified × Not_Modified_Time)
```

```
Page fault service time = 0.6 × 15 + 0.4 × 10 = 13 ms
```

**Effective Access Time (EAT)** ⭐

```sh
EAT = (1 - p) × (ma) + p × (Page fault service time)
```

```
EAT = (1 - 0.05) × 0.0003 + 0.05 × 13
    = 0.95 × 0.0003 + 0.05 × 13
    = 0.000285 + 0.65
    = 0.650285 ms
    
    => 650.285 μs ✅
```

**Ques. Which of the following is a valid 'C' structure to represent process control block in Linux operating system?**

> Process Control Block in Linux

* **PCB (Process Control Block)**: Stores all info about a process (state, registers, PID, memory, etc.)
* In **Linux**, the PCB is represented using the structure:

```c
struct task_struct ✅
```

* It includes:
  * Process ID (PID)
  * Process state
  * Scheduling info
  * Pointers to parent/child processes
  * CPU context, file descriptors, memory info, etc.

> `task_struct` is the core data structure used by the Linux kernel to manage processes.

**Invalid options:** ❌

* `job_struct` – Not used in Linux PCB
* `program_struct` – Not defined
* `process_struct` – Incorrect name

**Ques. Which of the following are valid model to represent relationship between user threads and kernel threads?**

> User Threads vs Kernel Threads – Mapping Models

* A **thread** is the ==smallest unit of CPU execution within a process==. It defines a **single sequence of instructions**.
* **User Threads**: Managed in **user space** by user-level libraries (fast, but kernel doesn't know them).
* **Kernel Threads**: Managed by the **OS kernel** (can be scheduled by the OS on CPUs).

-> To run user threads on the CPU, they must eventually use **kernel threads** ⭐

**1. One-to-One Model** ✅ Valid Model

* ( `1` user threads runs on `1` kernel threads)
* **1 user thread → 1 kernel thread**
* True **parallel execution** possible (if multiple cores).
* More memory overhead (1 kernel thread per user thread).
* **Example**: Windows, Linux (POSIX threads).

```
User Threads:   T1   T2   T3
				||   ||   ||
Kernel Threads: K1   K2   K3
```

**2. Many-to-One Model** ✅ Valid Model

* ( `n` user threads share `1` kernel thread)
* **Many user threads → 1 kernel thread**
* If **one thread blocks**, all are blocked (since only 1 kernel thread).
* Fast thread switching (done in user space), but **no real parallelism**.
* **Example**: Java green threads, some older systems.

```
User Threads:  T1  T2  T3
                 \  |  /
                [Kernel Thread K1]
```

**3. Many-to-Many Model** ✅ Valid Model

* ( `n` user threads are scheduled over `m` kernel threads,)
* **Many user threads → Many kernel threads (less or equal)**
* Kernel can schedule some threads in parallel, block others.
* Combines benefits of above two models.
* **Example**: Solaris, modern threading libraries.

```
User Threads:   T1  T2  T3  T4
					||  |  |
Kernel Threads:     K1  K2
```

**4. One-to-Many Model** ❌ Invalid Model

* ( `1` user threads are scheduled over `m` kernel threads) ❌
* **1 user thread → multiple kernel threads** ❌
* **Illogical**: A single user thread **can’t control or split** into multiple kernel threads.
* Not supported or implemented in any OS.

```
User Threads:          T1   ❌
					 /  |  \
Kernel Threads:     K1  K2  K3
```

**👉 User Threads, Kernel Threads & Mapping Model**

\*\*User vs Kernel Threads: \*\*

| Feature        | User Thread                      | Kernel Thread                     |
| -------------- | -------------------------------- | --------------------------------- |
| Managed by     | User-level libraries             | OS Kernel                         |
| Speed          | Fast (no kernel call)            | Slower (system call overhead)     |
| Scheduling     | Done in user space               | Done by OS                        |
| Blocking       | One blocked thread can block all | Only the blocked thread is paused |
| Visible to OS? | NO                               | YES                               |
| Parallelism?   | Depends                          | YES                               |

**Role in Models :**

* Thread-to-kernel mapping models define **how efficiently** threads utilize system resources (CPU, memory, parallelism).
* Example:
  * **One-to-One** model → true parallelism
  * **Many-to-One** model → low overhead but no parallelism
  * **Many-to-Many** model → best of both worlds

| Mapping Type     | Description                                        | Managed By         |
| ---------------- | -------------------------------------------------- | ------------------ |
| **One-to-One**   | 1 user thread runs on 1 kernel thread              | Kernel (OS)        |
| **Many-to-One**  | Many user threads share 1 kernel thread            | User-level library |
| **Many-to-Many** | `n` user threads over `m` kernel threads (`n ≥ m`) | Both               |

**Note:** "User-level threads are ==not managed by kernel== in **many-to-one** model because The **kernel sees only 1 thread**, so it can't manage individual user threads. ⭐

**Ques. Which of the following OS/process statements is TRUE**

1. **Kernel level threads are managed by operating system.** ✅
2. **A heavy weight process has multiple threads of execution** ❌
   * **A heavyweight process** is  a traditional process with its own memory space and a single thread of execution
   * **A multithreaded process** is a single program that can execute multiple tasks concurrently by using multiple threads
3. **here are three types of threads: user, kernel, and system level threads.** ❌
   * There are **Two standard types** of Threads - User level and Kernel Levl.
4. User level threads are managed by kernel\*\* ❌
   * **User-level threads** are managed by **user-space libraries**, not by the OS/kernel directly.

**Ques. Which of the following statements is/are TRUE**

* **Execution-time address binding generates different logical and physical addresses. ✅**
  * **Execution-time address binding** (done by MMU) means:
  * Logical address ≠ Physical address
  * Logical addresses are translated to physical **during execution**
* **The user program can access the physical address. ❌**
  * A **user program cannot access physical addresses** directly.\
    It always deals with **logical (virtual) addresses**.\
    The **OS + MMU** translates them to physical addresses.

**Address Binding and Memory Management**

| Address Binding Time | Logical = Physical? | Example                        |
| -------------------- | ------------------- | ------------------------------ |
| Compile-time         | ✅ Yes (if fixed)    | No relocation allowed          |
| Load-time            | ❌ No                | Logical → Physical during load |
| **Execution-time**   | ❌ Yes               | Done using MMU (hardware)      |

> Only OS or kernel mode code can directly access physical memory.\
> User programs work with **logical/virtual addresses only**.

**Ques. The CPU fetches instructions from memory according to the value of `------` ?**

**Program Counter** ✅

* The **Program Counter (PC)** holds the **address** of the **next instruction**.
* The CPU uses this address to **fetch the instruction from memory**.
* The fetched instruction is then loaded into the **Instruction Register (IR)** for decoding and execution.

| Register                 | Role                                                       |
| ------------------------ | ---------------------------------------------------------- |
| **Program Counter**      | Holds address of next instruction (**used to fetch**)      |
| **Instruction Register** | Holds the current fetched instruction **(after fetching)** |
| **Status Register**      | Stores flags (zero, carry, overflow, etc.)                 |
| **Data Register**        | Temporarily holds data being processed                     |

**\*\*Ques. Valid Metrics to Compare CPU Scheduling Algorithms:**

1. **CPU Utilization** – % of time CPU is busy
2. **Throughput** – No. of processes completed per unit time
3. **Turnaround Time** – Completion time − Arrival time
4. **Waiting Time** – Turnaround time − Burst time
5. **Response Time** – First response − Arrival time
6. **Fairness** (optional) – How equally processes are treated

***

## Companies Assessment Questions

What is the primary purpose of a cache memory?

```
- TO store frequently accessed data and instructions to speed up the operation Of the
computer ✅
```

What is a segmentation fault? ⭐

```
An error caused by accessing memory that the CPU cannot physically address ✅
```

Which of the following scheduling algorithms can lead to starvation?

```
- Priority Scheduling ✅
- Shortest Job Next (SJN) 
```

Which of the following is true about deadlocks?

```
- Deadlocks can occur when the four necessary conditions (mutual exclusion, hold
and wait, no preemption, circular wait) are satisfied ✅
```

When would the SCAN disk scheduling algorithm exhibit starvation?

```
When the disk arm repeatedly oscillates back and forth
```
