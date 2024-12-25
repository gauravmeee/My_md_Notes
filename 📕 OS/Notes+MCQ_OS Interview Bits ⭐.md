
Fragmentations and Segmentation study

# [Operating System Interview Questions](https://www.interviewbit.com/operating-system-interview-questions/)

What do you mean By Operating System
- **Operating System(OS)**  -> basically a software program that `manages` and `handles` all resources of a computer such as `hardware` and `software`. 
- An OS is responsible for ->  `managing, handling, and coordinating` overall activities and sharing of computer resources. 
- It acts as an -> `intermediary` among users of computer and computer hardware.
- The first OS was introduced in the early 1950s known as GMOs. 

![]()

What are basic functions of OS
- Memory and Processor Management
- Providing user interface to users
- File Management and Device Management
- Scheduling of resources and jobs
- Error Detection
- Security

### Basic Questions


What's the main purpose of an OS?
- The main purpose of an OS is to -> `execute user programs and make it easier for users to understand and interact with computers as well as run applications`. 
- It is specially designed to ensure that ->  the computer system performs better by managing all computational activities. 
- It also manages -> computer `memory`, `processes`, and `operation` of all hardware and software.

What are different types of OS?
- **Batched OS**  -> Executes jobs in batches `without user interaction`. _(Example: Payroll System, Transactions Process, etc.)_
- **Multi-Programmed OS**  -> Maximizes CPU utilization by `running multiple programs simultaneously`. _(Example: Windows O/S, UNIX O/S, etc.)_
- **Timesharing OS**  -> Allows `multiple users to interact with the system simultaneously` through time-sharing. _(Example: Multics, etc.)_
- **Distributed OS**  -> Manages a `group of networked computers as a single system`. _(Example: LOCUS, etc.)_
- **Real-Time OS**  -> Ensures `tasks are completed within a strict deadline`. _(Example: PSOS, VRTX, etc.)_

What are the benefits of a multiprocessor system?
- **Multiprocessor system** -> a type of system that includes  two or more CPUs. 
- It involves -> the processing of different computer programs at the same time mostly by a computer system with two or more CPUs that are sharing `single memory`.
- Benefits:  
	- Improve performance in systems that are running multiple programs concurrently.
	- Increasing the number of processors, a greater number of tasks can be completed in unit time.
	-  Increase in throughput and is cost-effective also as all processors share the same resources.
	- Improves the reliability of the computer system.

What is Raid structures in OS
- **Redundant Arrays of Independent Disks (RAID)** ->  a method used to store data on Multiple hard disks (therefore it is considered as data storage virtualization technology that combines multiple hard disks).
- It simply balances -> `data protection`, `system performance`, `storage space`, etc. 
- improve the overall -> performance and reliability of data storage.

Different Levels of Raid Configuration? ❓
- `RAID O`  - **(Non-redundant striping)** ->This level is used to `increase the performance` of the server.
- `RAID 1`  - **(Mirroring and duplexing)** -> This level is also known as disk mirroring and is considered the simplest way to `implement fault tolerance`.
- `RAID 2`  - **(Memory-style error-correcting codes)** -> This level generally uses dedicated hamming code parity i.e., a liner form of error correction code.
- `RAID 3` - **(Bit-interleaved Parity)** -> This level requires a dedicated parity drive to store parity information.
- `RAID 4` - **(Block-interleaved Parity)** -> This level is similar to RAID 5 but the only difference is that this level confines all parity data to a single drive.
- `RAID 5` - **(Block-interleaved distributed Parity**) ->  This level provides far better performance than disk mirroring and fault tolerance.
- `RAID 6` - **(P+Q Redundancy)** -> This level generally provides fault tolerance for two drive failures.

What is IPC? ❓
- **Interprocess Communication(IPC)**  -> a `mechanism that requires the use of resources like a memory that is shared between processes or threads`. 
-  In this mechanism, different processes can -> communicate with each other with the approval of the OS.
- It is simply used for -> exchanging data between multiple threads in one or more programs or processes.

What are the Different IPC Mechanisms? ❓
- `Pipes`, `Message Queuing`, `Semaphores`, `Socket`, `Shared Memory`, `Signals`

What is Pipe and when it is used? ❓
- **Pipe** ->a connection among two or more processes that are interrelated to each other.
- It is a mechanism that is used for -> inter-process communication using `message passing`. 
- One can easily send information such as the output of one program process to another program process using a pipe.
- It can be used when two processes want to communicate one-way i.e., `inter-process communication (IPC).`

Different kinds of operations that are possible on semaphore?
- There are basically two atomic operations that are possible -> `Wait()` & `Signal()`

What is a bootstrap program in OS?
- **Bootstrap** ->  a program that initializes OS during startup i.e., first code that is executed whenever computer system startups. 
- OS is loaded through a bootstrapping process or program commonly known as booting. (It also locates the kernel and loads it into the main memory after which the program starts its execution)
- It is fully stored in boot blocks at a fixed location on the disk. 


Explain Demand Paging?

What do you mean by RTOS

Types of RTOS

What do you mean by Process Synchronisation

Difference between Main memory and Secondary Memmory

What do you mean by Overlays in OS

Examples of OS

### Intermediate Questions

### Advanced Questions

### MCQ

---

```
❓
Which of the following usually provides the interface to get access to the services of OS?
- System Call ✅
- Library ✅
- API ✅
```

```
❓
The program that runs first just after booting the computer and loading the GUI?
- Authentication ✅
```

``` 
❓
In which of the following components is paging implemented?
- Software
- Hardware ✅
- Operating System
```

```
What Does the OS create from a physical computer?
- Virtual Computer ✅
```

```
❓
What is the use of the Fence Register?
- Disk Protection
- CPU Protection
- Memory Protection ✅
```

```
❓
Which of the following is not considered as an OS?
- Linux ✅
- Fedora
```

```
Purpose of Bankers Algorithm
- Prevent Deadlock ✅
```


### Diagrams

Operating System
![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/138/original/OS.png?1615544880)

Bootstrap
![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/140/original/boostrap_program_in_os.png?1615546151)

Real Time Operating System (RTOS)
![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/141/original/RTOS.png?1615546454)