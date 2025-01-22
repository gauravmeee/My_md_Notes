
**Operating System** 
- It is a Software abstracting hardware
- It is a Interface between user and hardware

**Services of Operating Systems**
- User Interface
- Program Execution  ⭐
- I/O Operation
- File-System Manipulation
- Inter Process Communication
- Error Detection Allocation
- Accounting
- Protection & Security


**Resource Management** : CPU, Memory, Storage -> for different tasks & Processes
**File Management** : Structure for data storage,  File Operations (CRUD)
**Process Management** : Schedule processes, inter-process communication 
**Device Management** :  Communication btw H/w & S/w


**Types of OS**
- Uni-Programming OS 
	- Non Preemptive process , Degree of Multiprogramming = 1
	- `Main Memory -> Only one process at a time [OS|P1]`
- Multi-Programming OS 
	- `Main Memory -> More than one process at a time [OS | P1 P2 ...]` 
	- Preemptive Process, Degree of Multiprogramming > 1
	- CPU Scheduling and Better Resource Utilization (like when P1 doing I/O operation, Execute P2)
- Multi-Tasking OS
	- Type of Multi-Programming in Which Scheduling Process is fixed i.e. Round Robin

Note: Single Processor/CPU can run one Process at a time.

Type of Process
- Preemptive -> OS can terminate
- Non-Preemptive -> Can't be Stop without the process itself

Degree of Multi Programming -> No. of Processes in Main Memory (other then OS processes)
Degree  -> Efficiency (Upto Threshing)
```
Efficiency
^ 
|
|          .  . 
|       .    ^    .
|   .        |       .
|.           |           .
|            |
|           thrashing
|
└────────────────────────────> Degree
```

**Parts of OS**
```
( Shell ( Kernel ) )
```
- Shell ->  Outer layer of OS, Provide a way to use OS using `GUI` or `CLI`

System Call -> A way for program to interact with the operating system.
- It protect privileged systems like files from program, and program need to request Call and Request OS
- Dual Mode of Operation : Transition from user to kernel mode
```
User Process:
User Process executing -> Call Systems call -> Return from system call
----------------------------------------------------------------------
Kerner :                            ⬊                   ⬈
			                 Mode bit =0        Return mode bit = 1
			                             ⬊          ⬈
			                           Execute system Call			

```
- User mode ( mode bit = 1), Kernel mode (mode bit = 0)


**Processes** -> Program under execution

**Representation of Processes**
```
Main Memory        Program P1
┌──┐             . ┌───────┐
|OS|        .      | Stack | -> Local Var, Function Param, return addr.
├──┤. . .          ├───↓───┤
|P1| ->            ├───↑───┤
├──┤.  .           | Heap  | -> Dynamic Memory Allocation
│  │       .       ├───────┤
└──┘           .   | Data  | -> Static and Global Variable
                   ├───────┤
                   | Code  | -> Program Instructions
                   └───────┘
```

**Ques:** Calling `malloc()` execute System Call ?
Ans -> No, malloc uses some area from heap, if heap is already given by OS to program, then there is no need to call system call for using heap
Program Counter -> Store address of Next Instruction -> Program Code Part

**PCB** -> Process Control Block
- When Process load into CPU Process content like (instructions, Variables) not goes into CPU, only PCB go
```
Main Memory                OS
                  . ┌──────────────────┐
┌──┐ .     .        | PCB P1 [.....]   |
|OS|---->           | PCB P2 [.....]   |
├──┤ .     .        | PCB P3 [.....]   |
|P1|              . └──────────────────┘
├──┤
└──┘

Attributes of PCB
[ PID, PC, GPR, List of Devices, Type, Size, Memory Limits, Priority, State, List of Files]
```

**Context** -> The content of PCB of a process are collectively knowns as 'Context' of that process
```
Context Switch -> Done By a OS's Program known as `Dispatcher`
- Step 1: Current Running process `Context` from CPU come back to its corresponding PCB
- Step 2: Next Process's Context from PCB load into CPU


   CPU                      OS
┌──────────┐       ┌──────────────────┐
| [PC][AR] |  ->   | PCB P1 [.....]   |
|[..] [] []|  <-   | PCB P2 [.....]   |
└──────────┘       ├──────────────────┤
                   |        P1        |
                   ├──────────────────┤
                   |        P2        |
                   └──────────────────┘
```

**Ques :** Is context switch same as preemption.
- Ans - It is not necessary to have preemption for Context Switch, because preemption is forcefully unload running process while, without preemption, if a Processing is going to do I/O there can be context switch


Process States :
```      
                         preemption    
                       ┌------------┐ 
    admitted           ↓            |             exit
{New}--------->   {Ready} -------> {Running} ------------> {Terminated}
                   ↑   |            ↑    |
                   |   └------------┘    |
                   | schedule dispatcher | 
 I/O or event done |                     | waiting for I/O or event
                   └------{Waiting}←-----┘
                          {Blocked}
                    blocked/reserved process by devices
```

- Stored in both  CPU & Main Memory-> Running
- Stored in Main memory Only -> Ready, Blocked
- Not stored -> New & Terminated

Running Process Can take only two decision by itself, `exit` and `waiting for I/O or event`. and all other are decide by OS

**CPU Bound** - If the process is intensive in terms of CPU operations
**IO Bound** - If the process is intensive in terms of IO operations.
A good blend of CPU Bound & IO Bound are made for better utilization


Scheduling Queues  -> Queues of PCB's of different state of process 
- Job Queue ->  New State
- Ready Queue -> Ready State
- Device Queue  -> Blocked State

Types of Schedulers
- Long-Term Scheduler (Job) : Decide process From `New` to `Ready` state
- Short-Term Scheduler (CPU) : Decide process From `Ready` to `Running` state ->CPU Scheduling Algorithms
- Mid-Term Scheduler : Swap out Process (Ready or Blocked) from Main memory to new suspended state
```
               ┌-resume-->                     // other states connected
{Suspended Ready}       {Ready}
     ^         <-suspend-┘   
     |                         
	 |					    
     |           ┌-suspend--> 
{Suspended blocked}       {Blocked}
                  <-resume-┘
```

Effect of Scheduler on Degree of Multiprogramming
Long Term -> Can Increase
Short Term -> No effect X
Mid-Term -> Increase/Decrease (Swap in/out)

Note : Swapping is also Called Rolling Rollout and Rollin if it is based on priority


**CPU Scheduling:**
- Function -> Make a Selection
- Goal -> Minimize waiting and turn around time, Maximize CPU utilization

**Scheduling Times** 
- Arrival Time (AT), 
- Burst Time(BT), 
- Completion Time (CT), 
- Turnaround Time (TAT) = CT- AT
- Waiting Time (WT) = TAT - BT

CPU Scheduling
- Preemptive
- Non-Preemptive

**1. FCFS (First Come First Serve)** -> Non Preemptive 
- Criteria -> Smaller AT first (Tie breaker -> Smaller process_id)
- Problem -> Convoy Effect : if a slow moving process schedule first, it will lead to all fast process to suffer.

**2. SJF (Shortest Job First)** -> Non Preemptive
- Criteria -> Smallest BT first (Tie breaker -> FCFS)

**3. SRTF (Shortest Remaining Time First)** -> Preemptive
- Criteria -> Smallest BT first (Tie breaker -> FCFS)

Note: in SRTF whenever a new process arrive at `AT` , we will compare it with current process if it is more better to process it first

**4. Priority based scheduling** -> Preemptive/Non-Preemptive
- Criteria -> Priority static/dynamic (Tie breaker -> Given in Ques)
- Problem -> If lower priority waiting for too much (Solution-> aging (only for dynamic priority))




- Gantt Chart
- Most question are to find Average TAT or Average WT


Modern Days computer use -> MFQS
Shared Variable -> A way of communication
others -> message passing, ...
Critical Section -> Shared variable ->  Synchronization -> Solution 

Code -> Why mot M.E x ???

Study all the code solution skipped

hardware solution skipped

Synchronization tools skipped


in reader-writer problem, we made Readcount integer not semphore, because on semaphore only signal and wait function is allowed but on readcount we required comparisons 


philospher problem skipped

Soho, JMD, Aria, PayU, AKM Global, ArgenBright Group, Spinny, Spaze, Spinny  skymark, spaze Arcus, EThiess, JMD Megapolis, Spazedge, RenewBuy.com, 


Deadlock

ME  solution not possible x
Hold and wait -> either hold or wait
preemtion -> not good, abnormal behavior if deallocate resource for process midway
Circular wait soltion->  While holding a resource for lower no. than you can request for higher no. otherwise u need to drop the biggere no. resources to access lower. i.e aquicre resource in sequence


Deadlock avoidance -> Bankers algorithm -> Safe Sequences (may be multiplef)


Resource Request Algorithm <- only execute if there is deadlock avoidance to allocate only if there is safety

Deadlock Detection
-> only tell for  single resource instance : Wait for Graph (of process only ) from RAG -> cycle -> deadlock
-> multiple resources : banker's algorithm

deadlock recovery


page size and offset map recap 

question VVI 2

H TLB hit ratio

3 mapping

multilevel paging and ques

virtual memory -> page fault

page replacement policy


pure demanding paging -> no pages in mm in starting of process

PAGE FAULT

6 PAGE REPLACEMENT POLICIES, hit ratio, advantage disadvantage

fIFO - HIT RATION
	MORE PAGE FRAME -> MORE HIT RATIO -> sUFFER from balaody anamoly
optimal policy -> minimum page fault