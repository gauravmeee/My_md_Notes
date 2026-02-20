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

# Threading

* \==**Thread** = lightweight execution== unit inside a process
* A thread is a **lightweight subprocess** inside a process that ==**shares `code, data, and OS resources`** with other threads== of the same process
* A **process** provides _resource ownership_, while a **thread** provides _CPU execution flow_

#### **Why Threads?**

* Allows **parallel/concurrent execution within a single program**
* Example: one thread handles **UI**, another handles **network**, another handles **calculations**
* **Context switching is faster** than processes
* because **same address space** and most resources are shared
* Improves:
  * **Responsiveness**
  * **CPU utilization**
  * **Throughput**
  * **Resource sharing**

#### **Process vs Thread**

**Process**

* Has its own:
  * address space
  * code + data
  * open files (separate)
  * PCB (Process Control Block)
* Switching between processes is **costly**

**Thread**

* Belongs to a process
* Threads of same process share:
  * **Code section (text)**
  * **Data section (global variables, heap)**
  * **Open files**
  * **OS resources**
* Thread switching is **cheaper**

#### **Multithreading**

* **Multithreading** = multiple threads inside the same process executing concurrently
* Used in:
  * browsers
  * IDEs
  * OS services
  * servers (handling multiple clients)
  * games
  * database engines

#### **Multithreaded Process (Important)**

A multithreaded process contains:

**Shared among threads:**

* **Code / text segment**
* **Global variables**
* **Heap memory**
* **Open files / sockets**
* **Signals / resources**
* **Address space**

**Private to each thread:** ⭐

* \==**Program Counter (PC)**== (next instruction)
* \==**CPU registers**==
* \==**Stack**== (function calls, local variables)
* **Thread ID**
* **Thread state**
* **Thread Control Block (TCB)**

**Key point:** ⭐

* \==**Local variables are private** (stack) ==
* \==**Global variables are shared** (data/heap)==

#### **Thread Control Block (TCB)**

TCB stores thread-specific info:

* thread id
* thread state (ready/running/blocked)
* program counter
* registers
* stack pointer
* scheduling info (priority etc)

#### **Thread States**

Same as process states:

* **New**
* **Ready**
* **Running**
* **Blocked / Waiting**
* **Terminated**

#### **Types of Threads** ⭐

**1) User-level Threads (ULT)**

* \==Managed by **thread library**== in user space (not by OS kernel)
* \==OS sees the whole process as **single unit**==
* **Advantages:**
  * \==very fast create/switch== (no kernel call)
  * portable (library-based)
* **Disadvantages:**
  * \==**one blocking system call blocks all threads**==
  * OS cannot schedule threads independently
  * \==no true parallelism== on multi-core (in pure ULT model)
* Example libraries:
  * green threads
  * user-space threading packages

**2) Kernel-level Threads (KLT)**

* \==Managed directly by **OS kernel**==
* \==Each thread is known to OS== and scheduled separately
* **Advantages:**
  * \==true parallelism== on multi-core CPU
  * if one thread blocks, others can continue
  * better scheduling by OS
* **Disadvantages:**
  * \==thread operations slower (system calls)==
  * more overhead
* Examples:
  * Linux `pthreads` (mapped to kernel threads)
  * Windows threads

#### **User vs Kernel Threads (Comparison)** ⭐\`

| Feature                  | User-level thread  | Kernel-level thread         |
| ------------------------ | ------------------ | --------------------------- |
| Managed by               | thread library     | OS kernel                   |
| Switching                | fast               | slower                      |
| ==Blocking system call== | blocks all threads | ==only blocks that thread== |
| ==Parallelism==          | not true           | ==true==                    |
| OS scheduling            | process level      | thread level                |
| Overhead                 | low                | high                        |

#### **Thread Models (ULT-KLT Mapping)** ⭐

> \==**How many&#x20;**_**User-Level Threads (ULT)==**_**&#x20;are ==associated/implemented== using ==how many&#x20;**_**Kernel-Level Threads (KLT)**_**.**==\
> i.e., **how ULTs are “mapped onto” KLTs for CPU execution**

**1. Many-to-One:**

* many user threads → 1 kernel thread
  * **Many ULT share 1 KLT**
  * So ==OS sees only **1 schedulable entity**==
  * If that KLT blocks → **all ULT stop**
* fast but no parallelism + ==blocking problem==

**2. One-to-One:**

* each user thread → 1 kernel thread
  * **Each ULT gets its own KLT**
  * \==OS can schedule them independently== ⭐(like kernel thread)
  * \==Real parallelism== possible ⭐(like kernel thread)
* true parallelism, more overhead (most modern OS follow this)

**3. Many-to-Many:**

* many user threads → many kernel threads
  * Many ULT mapped to **a pool of KLT**
  * \==ULT can run in parallel== up to number of KLT available ⭐ (like kernel thread)
  * \==Blocking one KLT doesn’t stop all ULT== ⭐(like kernel thread)
* balances overhead + parallelism

> **One-to-Many (1 ULT → many KLT)** generally **doesn’t make sense** because:

* A **single thread** is defined as ==**one execution flow** (one PC + one register set + one stack)==.
* So **one ULT cannot execute on multiple CPUs at the same time**.

#### **Thread Issues / Problems**

**1) Race Condition:**

* occurs when multiple threads access shared data simultaneously and result depends on timing
* Example: shared variable `count++` by multiple threads → wrong output

**2) Critical Section:**

* code segment where shared data is accessed/modified
* must be protected

**3) Mutual Exclusion:**

* only one thread enters critical section at a time
* achieved using:
  * mutex locks
  * semaphores
  * monitors

**4) Deadlock:**

* threads wait forever for resources held by each other

**5) Starvation:**

* thread never gets CPU/resources due to low priority

#### **Thread Synchronization (Must Know)**

To handle shared data safely:

* **Mutex** (binary lock)
* **Semaphore** (counting lock)
* **Condition variables**
* \==**Monitors**==

Goal:

* avoid race condition
* ensure correctness

#### **Context Switching (Thread vs Process)**

**Thread context switch:**

* saves/restores:
  * registers
  * program counter
  * stack pointer
* no address space switch (same process)
* faster

**Process context switch:**

* also switches:
  * memory mapping
  * page tables
  * TLB flush etc
* slower

#### **When Threads are Better than Processes?**

**Threads are better when:**

* tasks share large data
* need fast communication
* need high responsiveness
* need parallel work inside same program

**Processes are better when:**

* need isolation and security
* separate applications

#### **Key Ratana (Rote Points)**

* Thread = lightweight subprocess inside process
* Threads share: **code, data, heap, files**
* Threads have private: **stack, registers, PC**
* ULT: fast but blocking call blocks all
* KLT: true parallelism but overhead
* race condition → needs synchronization
