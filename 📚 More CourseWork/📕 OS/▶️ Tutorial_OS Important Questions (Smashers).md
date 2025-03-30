

# [Top 15 OS Interview Questions | Operating System Interview | Placement Strategy](https://youtu.be/K1GFwYzCQlw)

1. **Process States and PCB**:
   - **Process States**: A process can be in several states such as **New** (being created), **Ready** (waiting for CPU), **Running** (executing), **Waiting** (awaiting an event), **Blocked** (waiting for a resource), and **Terminated** (finished). **Suspended Ready** and **Suspended Blocked** are additional states where a process is swapped out of memory.
   - **Process Control Block (PCB)**: A PCB is a data structure used by the operating system to store information about a process, including its state, Process ID (PID), program counter, CPU registers, memory management details, I/O status, and accounting information. It is crucial for process management and context switching.

2. **Mutex vs Binary Semaphore**:
   - **Mutex**: A mutual exclusion object used to protect shared resources from concurrent access by multiple threads. Only one thread can hold the mutex at a time.
   - **Binary Semaphore**: A type of semaphore that has only two states, 0 and 1, used for synchronization. Unlike a mutex, it does not necessarily enforce ownership and can be signaled from different threads.

3. **Process vs Thread**:
   - **Process**: An independent program in execution, with its own memory space and resources.
   - **Thread**: A lightweight unit of execution within a process, sharing the same memory space and resources with other threads of the same process. Threads enable parallelism within a single process.

4. **Monolithic vs Microkernel**:
   - **Monolithic Kernel**: A kernel architecture where the entire operating system runs in a single address space, leading to high performance but less modularity.
   - **Microkernel**: A kernel architecture that runs only essential functions (e.g., communication, process management) in kernel mode, while other services run in user mode, providing better modularity and stability.

5. **System Call**:
   - A system call is a mechanism that allows user-level programs to request services from the operating system kernel, such as file operations, process management, and communication.

6. **Demand Paging**:
   - A memory management scheme that loads pages into memory only when they are needed, rather than loading the entire program into memory at once. This helps in managing memory more efficiently.

7. **Virtual Memory**:
   - A memory management technique that provides an application with the illusion of a large, contiguous block of memory, while physical memory may be fragmented. It uses paging or segmentation to map virtual addresses to physical addresses.

8. **Chmod Command**:
   - The `chmod` command in Unix/Linux systems is used to change the permissions of files and directories. It allows users to set read, write, and execute permissions for the owner, group, and others.

9. **Paging vs Segmentation**:
   - **Paging**: A memory management scheme that divides the process's memory into fixed-size pages. It eliminates external fragmentation but can lead to internal fragmentation.
   - **Segmentation**: A memory management scheme that divides memory into variable-sized segments based on logical divisions of the program. It provides better modularity but can lead to external fragmentation.

10. **Internal vs External Fragmentation**:
    - **Internal Fragmentation**: Occurs when memory blocks are allocated larger than needed, leaving small unused spaces within allocated memory.
    - **External Fragmentation**: Occurs when free memory is scattered in small chunks across the system, making it difficult to allocate large contiguous blocks.

11. **Preemptive vs Non-Preemptive Scheduling**:
    - **Preemptive Scheduling**: Allows the operating system to interrupt a running process to allocate CPU time to another process, enabling more responsive multitasking.
    - **Non-Preemptive Scheduling**: A process cannot be interrupted and will run until it finishes or voluntarily relinquishes control of the CPU.

12. **Deadlock**:
    - A situation where a set of processes are blocked because each process is holding a resource and waiting for another resource held by another process, leading to a cycle of dependencies with no resolution.

13. **Multiprogramming vs Multitasking**:
    - **Multiprogramming**: Running multiple programs simultaneously to maximize CPU utilization by keeping the CPU busy with a variety of tasks.
    - **Multitasking**: Refers to the concurrent execution of multiple tasks or processes on a single CPU, often achieved through time-sharing or preemptive scheduling.

14. **Spatial Locality vs Temporal Locality**:
    - **Spatial Locality**: The tendency for processes to access memory locations that are close to each other.
    - **Temporal Locality**: The tendency for processes to access the same memory locations repeatedly within a short time interval.

15. **Virus, Worm, Trojan, Malware, Spyware**:
    - **Virus**: Malicious code that attaches itself to a legitimate program and spreads to other programs or systems.
    - **Worm**: A standalone malware that replicates itself to spread to other systems, often without the need to attach to other programs.
    - **Trojan**: A type of malware disguised as a legitimate program or file, which, once executed, performs harmful actions.
    - **Malware**: A broad term for any malicious software designed to harm, exploit, or otherwise compromise a system.
    - **Spyware**: A type of malware that secretly monitors and collects user information, often without consent.
