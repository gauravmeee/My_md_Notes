
#  [# Operating System One Shot | CS & IT Engineering | Maha Revision | Target GATE 2025](https://youtu.be/86kN-pdxsl0)
### Operating System

**Operating System** -> It is a Software abstracting hardware
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

**Types of OS**:
1. **Uni-Programming OS** 
	- Degree of Multiprogramming = 1
	- `Main Memory -> Only one process at a time [OS|P1]`
2. **Multi-Programming OS** 
	- `Main Memory -> More than one process at a time [OS | P1 P2 ...]`  ⭐
	- Degree of Multiprogramming > 1
	- CPU Scheduling and Better Resource Utilization (like when P1 doing I/O operation, Execute P2)
3. **Multi-Tasking OS**
	- Type of Multi-Programming in Which Scheduling Process is fixed i.e. Round Robin ⭐

Note: Single Processor/CPU can run one Process at a time.

**Type of Process:**
- Preemptive -> OS can terminate
- Non-Preemptive -> Can't be Stop without process itself

**Degree of Multi Programming** -> No. of Processes in Main Memory (other then OS processes)
- Degree  ∝ Efficiency (Upto Thrashing)

**Thrashing** occurs in **Operating Systems** (mainly in virtual memory systems) when The system spends more time swapping pages in and out of memory than executing actual processes.


**Parts of OS:**
```  
( Shell ( Kernel ) )
```
- **Shell** → Outer layer of OS, provides interface to user via `GUI` or `CLI`
- **Kernel** → Core of OS, directly interacts with **hardware**; manages **CPU, memory, processes, I/O, and devices**

**System Call:** -> A way for program to interact with the operating system.
- It protect privileged systems like files from program, and program need to request Call and Request OS
- Dual Mode of Operation : Transition from user to kernel mode
```
	User Process:
	User Process executing ---> Call Systems call ---> Return from system call
	                            ⬊                          ⬈
x-------------------------------------------------------------------------------x
Kernel :                            ⬊                   ⬈
							 Mode bit =0        Return mode bit = 1
										 ⬊          ⬈
									   Execute system Call			

```
- User mode ( mode bit = 1), Kernel mode (mode bit = 0)


### Processes

**Processes** -> Program under execution

**Representation of Processes**
```
Main Memory        Program P1
┌──┐             . ┌───────┐
|OS|        .      | Stack | -> Local Var, Function Param, return addr.
├──┤.....          ├───↓───┤
|P1| ->            ├───↑───┤
├──┤.....          | Heap  | -> Dynamic Memory Allocation
│  │       .       ├───────┤
└──┘           .   | Data  | -> Static and Global Variable
                   ├───────┤
                   | Code  | -> Program Instructions
                   └───────┘
```

**Ques:** Calling `malloc()` execute System Call ?
Ans: No, malloc uses some area from heap, if heap is already given by OS to program, then there is no need to call system call for using heap

**Program Counter** (PC)-> Store address of Next Instruction -> Program Code Part
```
┌────────┐
|  CPU   |  
│ ┌────┐ │
│ | PC | │
| └────┘ |
└────────┘
```

**Ques:** If a process `P` is running, which section of the process's what address will be stored in PC for the process `P`
Ans: PC will store address of next instruction, i.e. Some address of Code Section of the Process P1 inside Main Memory

**Ques:** In which Section of the Process `P`, the program counter value would be saved
Ans: If some function call or Interrupt happens, PC value is stored Inside Stack of Process P


**PCB** -> Process Control Block
- When Process load into CPU Process content like (instructions, Variables) not goes into CPU, only PCB goes into CPU that stores Process ID, Process current state, Process Priority etc.)
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
- Done By a OS's Program known as `Dispatcher`
- Step 1: Current Running process `Context` from CPU come back to its corresponding PCB
- Step 2: Next Process's Context from PCB load into CPU

```
Context Switch:

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


**Process States :**
```      
                         preemption    
                       ┌------------┐ 
    admitted           ↓            |             exit
{New}--------->   {Ready} -------> {Running} ------------> {Terminated}
                   ↑   |            ↑    |
                   |   └------------┘    |
                   | schedule dispatcher | 
 I/O or event done |                     | waiting for I/O or event
                   └--{Waiting/Blocked}←-┘
                  reserved process by devices
```

**Main Memory vs CPU stored state:** ⭐
- Stored in both  CPU & Main Memory-> `Running`
- Stored in Main memory Only -> `Ready, Blocked`
- Not stored -> `New & Terminated`

**Two Transition are Voluntary by Process:**
- Running to Terminated
- Running to Blocked

**CPU Bound** - If the process is intensive in terms of CPU operations
**IO Bound** - If the process is intensive in terms of IO operations.

Note:
- A good blend of CPU Bound & IO Bound are made for better utilization
- Running Process Can take only two decision by itself, `exit` and `waiting for I/O or event`. and all other are decide by OS


**Scheduling Queues:**  -> Queues of PCB's of different state of process 
- **Job Queue** ->  New State
- **Ready Queue** -> Ready State
- **Device Queue**  -> Blocked State

**Types of Schedulers:**
- **Long-Term Scheduler (Job)** -> Decide process From `New` to `Ready` state
- **Short-Term Scheduler (CPU)** -> Decide process From `Ready` to `Running` state -> CPU Scheduling Algorithms ⭐
- **Mid-Term Scheduler(Medium Term)** -> Swap out Process (Ready or Blocked) from Main memory to new suspended state -> Swapping
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

**Effect of Scheduler on Degree of Multiprogramming:**
- Long Term -> Can Increase
- Short Term -> No effect X
- Mid-Term -> Increase/Decrease (Swap in/out)

Note : Swapping is also Called Rolling Rollout and Rollin if it is based on priority

### CPU Scheduling

**CPU Scheduling:**
- Function -> Make a Selection
- Goal -> Minimize waiting and turn around time, Maximize CPU utilization

**Scheduling Times** 
```

- Arrival Time (AT), 
- Burst Time(BT), 
- Completion Time (CT), 
- Turnaround Time (TAT) = CT- AT ⭐
- Waiting Time (WT) = TAT - BT ⭐
```

**CPU Scheduling:**
- Preemptive
- Non-Preemptive

**Scheduling Algorithms:**

**1. FCFS (First Come First Serve)** -> Non Preemptive 
- Criteria -> Smaller AT first (Tie breaker -> Smaller process_id)
- Problem -> **Convoy Effect** : if a slow moving process schedule first, it will lead to all fast process to suffer.

**2. SJF (Shortest Job First)** -> Non Preemptive
- Criteria -> Smallest BT first (Tie breaker -> FCFS)

**3. SRTF (Shortest Remaining Time First)** -> Preemptive ⭐
- Criteria -> Smallest BT first (Tie breaker -> FCFS) 
- In SRTF whenever a new process arrive at `AT` , we will compare it with current process if it have less remaining burst time, process it first.

**4. Priority based scheduling** -> Preemptive/Non-Preemptive
- Criteria -> Priority static/dynamic (Tie breaker -> Given in Ques)
- Problem -> **Starvation** : If lower priority waiting for too much (Solution-> aging (only for dynamic priority))

**5. Round-Robin** -> Preemptive
- Criteria -> Smaller AT first + Time slice (**Quantum**)
- If two process coming to ready state, one from New State and another from CPU, New process will be forward in queue.
- Quantum Value (Q) : very very small -> No Efficiency, Small -> Interactive, Large -> Less Interactive, Very very large -> RR degrades to FCFS

Note:⭐
- Learn to make `Gantt Chart` for analyze process scheduling.
- Most question are to find **Average TAT** or **Average WT**



**6. Multilevel Queue (MLQ) Scheduling:**
- Different Queue Type of  Processes
```
System Processes
	↓
Foreground Processes
	↓
Background Processes
```

- **Scheduling Among Queues:**
	1. **Fixed priority Preemptive scheduling method :**
		- Different Queue for Different Priority Processes, Higher Priority Queue Process will get CPU first
		- Even if Lower Priority Process let Foreground Processes, are in CPU and if some process enter in ready state of Higher Priority Process ex: System Process Queue, Foreground process will be preempt and System Process will be processed first
		- Problem : Starvation of Low Priority Processes
	
	2. **Time Slicing**
		- Each Type of Process will be given certain Time limit. For ex in every 100ns, 60ns , 30ns and 10ns are given to System, Foreground and Background Process respectively
		- Problem : The type of process with more time slice will be given more time

**7. Multilevel Feedback Queue(MLFQ) Scheduling**
- Different Queue type of Processes with Flexible Priority
- Criteria for Priorities of Queue can be changed based on Feedback
- Round Robing is Used in Each Priority Queue
- It is used in Modern day computers ⭐
```
┌─ System Processess
└─--------------------┐
Foreground Processes ←┘
┌─-----------------------┐
└─ Background Processes ←┘
```


**Advantage and Disadvantage of Each Scheduling Algorithm**
- **FCFS** -> (Easy to Implement, No complex Logic, No starvation)✅ , (No Option of Preemption, Convoy Effect Makes System Slow) ❌
- **SJF** -> (Minimum average waiting time among non-preemptive scheduling, Better throughput in continue run) ✅ , (No Practical Implementation because burst time is not known in advance, No option of preemption, Longer Processes may suffer from starvation) ❌
- **SRTF** -> (Minimum Average waiting time among all algorithms, Better throughput in continue run) ✅, (No practical implementation because Burst time is not known in advance), (Longer Processes may suffer from starvation) ❌
- **Priority Based Algorithm** -> (Better response for real time situations)✅, (Low Priority Processes may suffer from starvation) ❌
- **Round Robin** -> (All processes execute one by one, so no starvation, Better interactive-ness, Burst time is not required to be known in advance) ✅, (Average waiting time and turnaround time is more, Can degrade to FCFS) ❌

### Synchronisation

**Type of Processes:**
1. **Independent** -> Process doesn't communicate with other processes
2. **Cooperating/Coordinating/Communicating** -> Process communicate with each other

**Problems without Synchronization:**
- Inconsistency
- Loss of Data
- DeadLock

**Race Condition** -> A race condition is an undesirable situation, it occurs when the final result of concurrent processes depend on the sequence in which the processes complete their execution. ⭐


**Ques:** How many different values of X are possible after both `P1` and `P2` process finish execution
```
X = 6

P1
X = X/2

P2
X = X+4
```
Ans -> `2` Processes -> `2^n` Possible Sequence,  P1->P2->`X=7`, P2->P1->`X=5`, 
P1 & P2 execute at same time, P1 write later ->`X=3`,  P1 & P2 execute at same time, P2 write later -> `X=10`

**Ques:** Minimum and Maximum possible value of X after all the processes
```
X = 20

P1
X = X+3

P2
X = X+2

P3
X = X-4

P4
X = X-6
```
Ans -> By Race condition `Xmin` = 10 (P3 & P4), `Xmax` = 25(P1 & P2)

**Critical Section :**

**Critical Section** -> The critical section is a code segment where the shared variable can be accessed
```
┌──────┐
│ ---- │
│ ---- │
│ ---- │
|┌-─-─┐|................
||----|| -> Critical Section xxx
||----|| -> Synchronisation Required
|└─-─-┘|...............
│ ---- │
└──────┘
```
- **Shared Variable** -> A way of communication
- **Others Communicating ways** -> message passing, ...


`Critical Section -> Shared variable ->  Synchronization -> Solution `


**Requirement of Critical Section Solution**
1. **Mutual Exclusion** -> If a Process P1 is executing Critical Section, Other Process P2 can't enter critical section i.e. One process can enter critical section at a time
2. **Progress** -> If no process is in Critical Section then process can access it, If it is not allowed due to some reason then there is no progress. If Deadlock -> No Progress
3. **Bounded Waiting** -> If P1 is in critical section and Process P2 is waiting. After Process P1 come out from critical section and again tries to enter it, Stop it and give priority to waiting Process P2 to enter critical section

C.S -> Critical Section
R.S -> Remaining Section
 
**A. Software Solutions**

Solution 1 (`Lock`):
```
		Using Lock
		Boolean lock = false;

P0                               P1
While(true)                      While(true)
{                               {
	while (lock);                 	while (lock); 
	lock=true;                  	lock=true;   
	C.S                             C.S
	lock = false;                	lock = false;
	R.S                             R.S
}                                  }

- Mutual Exclusion ❌
- Progress ✅
- Bounded wait ❌ -> Starvation
```
- `lock=true and while(lock)` -> Infinite Loop
- In Starting, `lock = false` , if Both process execute `while(lock)` at same time and so can enters into critical Section -> So there is no Mutual Exclusion
- If No process inside Critical Section, Last updated Value of Lock always be `false` and so any process can enter -> There is Progress
- If Process P1 enter Critical Section, and made `lock=true`, Process P2 can't enter C.S. After P1 finished its One Cycle, It come out, Make `lock=false` and again it can access Critical section and Make `lock=true` even if P2 is waiting. so there is no procedure to prevent P1 from execution if someone is waiting from more time -> No bound and wait

Solution 1(`Turn`):
```
		Using turn
		int turn=0

P0                               P1
While(true)                      While(true)
{                               {
	while (turn!=0);                  while (turn!=1);  
	C.S                         	  C.S
	turn = 1;                	      turn = 0;
	R.S                               R.S
}                                  }

- Mutual Exclusion ✅
- Progress ❌ -> Starvation
- Bounded wait ✅ 
```
- Each process give another process turn after its execution -> Strict Alternation Manner -> Mutual Exclusion and Bounded wait is there
- If only P1 process executed, `turn=0` in starting, and P1's `while(turn!=1)` -> `while(turn==0)` -> Infinite Loop -> No progress
- Starvation ✅is also there, Each Process Required another Process execution to execute it again.

Solution 3 (`Flag[] & Turn`): Peterson's Solution ⭐
```
		Boolean Flag[2] = {False, False};
		int turn;

P0                               P1
While(true)                      While(true)
{                               {
	Flag[0]=true;                   Flag[1]=true;
	turn=1;                         turn=0;
	while (Flag[1] && turn==1);     while (Flag[0] && turn==0;);   
	C.S                             C.S
	Flag[0]=False;                  Flag[1]=False;
	R.S                             R.S
}  

- Mutual Exclusion ✅
- Progress ✅
- Bounded Wait

No Starvation ❌
```

- Is Process P1 and P2 have there own Flag `Flag[0]` and `Flag[1]`, and both false in starting
- `Flag[0]=1` -> P0 want to go in C.S, `Flag[1]=1` => P1 want to go in C.S
- `turn` used for priority and will tell who should go in C.S, at a time `turn=0` or `turn=1`. If Process P0 Execute and Complete C.S, it will set `turn=1` and tell that next time its's P1 turn, So on Completing a Process another want to access C.S waiting one will given priority -> Bounded wait
- In P0 : `while(Flag[1] && turn==1)` -> `Flag[1]` (P1 want to go in C.S) and `turn==1` (Priority is P1), the P0 -> Infinite Loop, Can't Access and vice versa -> Mutual Exclusion
- If another process don't want to go in C.S its `Flag=false` and so, the current process's `while(another Process Flag = false && turn)` -> Not infinity -> can enter C.S


**B. Hardware Solutions**
1. `TestAndSet()`
2. `Swap()` 

Solution 1 `(TestAndSet()`): Returns the current value flag and sets it to `true`
```
		Boolean Lock = False;
		boolean TestAndSet(Boolean *trg)
		{
			boolean rv = *trg;
			*trg = True;
			Return rv;
		}

P0                               P1
While(true)                      While(true)
{                                {
	while (TestAnsdSet(&Lock));     while(TestAnsdSet(&Lock));
	C.S                             C.S
	Lock = false;                	Lock = false;
}                                }

- Mutual Exclusion ✅
- Progress ✅
- Bounded wait ❌
```
- In starting `Lock=False`, let a Process P1, In `while(TestAndSet(&Lock))` `TestAndSet(&Lock)` will return `False` and set `Lock=True`. It goes into Critical Section and Prevent other process from accessing it.
- This is same as S/w solution 1 (`lock`) just the difference is that, there is no preemption between checking of `lock` variable and setting it to `true`  in S/w solution i.e. if `lock=false`, `lock` will set to `true` after `while(lock)`: and if `lock=true`, `while(lock)` will be infinite loop

Solution 2 (`Swap())`:
```
		Boolean Key; // Local
		Boolean Lock = False; // Global and Shared
		void Swap(Boolean *a, Boolean *b)
		{
			boolean temp = *a;
			*a=*b;
			*b=temp;
		}

P0                               P1
While(true)                      While(true)
{                                {
	Key = True; //key0              Key = True; //key1
	while (Key==True);              while(Key==True);
	{                               {
		Swap(&Lock, &Key)              Swap(&Lock, &Key)
	}                               }
	C.S                             C.S
	Lock = False;                	Lock = False;
		R.S                            R.S
}                                }

- Mutual Exclusion ✅
- Progress ✅
- Bounded wait ❌
```
- Each Process P0 and P1 have there own local variable `Key`
- It Swap() swap the value of `Lock` and `Key`
- Let P0 Execute, Initially `Lock=False` and `Key=True`, `While(key==True)` -> Swap `Lock` & `Key`, `Lock=True`, `Key=False` then again `While(Key==True)` -> False -> Critical Section. and other Process can't access C.S until it complete, due to `Lock=true`

**Synchronization Tools :**
1. **Semaphore**
2. **Monitor**

**Semaphore** -> Shared Integer value (non-negative)
- Semaphore (S) value which can be accessed using following function only
1. `Wait()` / `P()` / `Degrade()`
2. `Signal()` / `V()` / `Upgrade()`
```
wait(S){                           Signal(S)
	while(S<=0);                   {
	S--;                              S++
}                                  }
```

```
             Two type of Semaphore
             /                 \
        Binary                Counting
        0,1                   0, 1, 2, 3,......

Binary:
if S=0:                             if S=1:
	wait(s) => X Not Successful       wait(s) => s=0
	signal(s) => S=1                  signal(s) => S=1

Counting:
if S=0:                             if S>0:
	wait(s) => X Not Successful       wait(s) => s--
	signal(s) => S++                  signal(s) => S++
```

**Ques:** A Binary Semaphore `S=1`, 10 Processes P1, P2, P3.....P10. All process have same code as given below but, one process P10 has `signal(S)` in place of `wait(S)` If all processes can execute Multiple times, then maximum no. of processes which can be in critical section together??
```
while(True){
	wait(S)
		C.S
	Signal(S)
}
```
Ans: All `10` Processes can Access Critical section concurrently.
Since P10 Doesn't have `wait(S)` it would never be restricted to enter C.S
Let any one Process P1 enters in C.S initially, and all goes and stay inside C.S, one by one, but P10 Came out and Go in again and again.
(S=1)--->(P1=>S=0)--->(P10=>S=1)--->(P2=>S=0)--->(P10=>S=1)---->(P3=>S=0) ..... ----> P(10=>S=1 (Now it can stay in C.S)) ----> (P9=>S=0)


**Classical Synchronisation Problems:**
1. Bounded Buffer Problem
2. Reader-Writer Problem
3. Dining Philosopher Problem


**1. Bounded Buffer Problem:**
```
                       Bounded buffer with capacity N
                      ┌──────────────────────────────┐
Multiple Producers => │ [A] [B] [C] [D] [ ] ... [ ]  │
                      |  0   1   2   3   4       N-1 |
                      └──────────────────────────────┘
```
- Known as producer-consumer problem also
- Buffer is the shared resources between producers and consumers
- **Solution:**
	- Producers must block if the buffer is full
	- Consumers must block if the buffer is empty
	- **Variables:** **Mutex** -> Binary Semaphore (Initialize S=1) to take lock on buffer (Mutual Exclusion), **Full** -> Counting Semaphore (S=0) to denote the number of occupied slots in buffer, **Empty** -> Counting Semaphore (S=N) to denote the number of empty slots in buffer
```
Producer            Consumer
---------          -----------
wait(empty)        wait(full)
wait(mutex)        wait(mutex)
// buffer          // buffer
signal(mutex)      signal(mutex)
signal(full)       signal(empty)

Note: In Producer : if `wait(empty) & wait(mutex)` are swapped there can be deadlock, similarly in Consumer if `wait(full) & wait(mutex)` are swapped there may be deadlock
```


**2. Reader-Writer Problem**
- If writer is accessing the file, then all other readers and writers will be blocked
- If any reader is reading, then other readers can read but writer will be blocked
- **Variables:** **Mutex** -> Binary Semaphore (Initialize S=1) to provide Mutual Exclusion, **Wrt** ->Binary Semaphore (S=1) to restrict readers and writers if writing is going on, **ReadCount** -> Integer variable( x=0 ), denotes number of active readers

```
Writer             Reader
---------          -----------
wait(wrt)          wait(mutex)
// write           ReadCount++
signal(wrt)        if(ReadCount==1):
				      wait(wrt) // Stuck writer or itself
				   signal(mutex)
				   // reading
				   wait(mutex)
				   ReadCount--
				   if(ReadCount==0)
				      Signal(wrt) // allow writer
				      
Note: ReadCount is not taken as Semaphore, because we required Comparison operators, which are not allowed on Semaphore. Semaphore can only be accessed by wait() and signal
```

**3. Dining Philosopher Problem**
- 3 Professor(processor) 
- 3 Chopsticks (Resources)
- Each one have 1 Chopstick `/`
- But to eat food each required `/ \` two chopsticks

```
              P1
              😋
          \   🍚  /
          
        😋🍚  |   🍚 😋
        P3             P2
```
- **Variable:** Array of binary Semaphores `ch[k]` = {1, 1, 1 }
```
Pi
----
wait(ch[i])
wait(ch[(i+1)modk])
// eating
signal(ch[i])
signal(ch[(i+1)modk)])
```
- **Problem :** Deadlock -> If each professors allocate one chopstick `ch={0, 0, 0}`
- **Solutions:**
	1. There should be at most (k-1) philosophers on the table
	2. A philosopher should only be allowed to pick their chopstick if both are available at the same time
	3. One philosopher should pick the left chopstick first and then right chopstick next; While all others will pick the right one first then left one


### Deadlock

Starvation -> Indefinite wait
Deadlock -> Infinite wait

**Three Operation on Resources:**
1. Request
2. Use
3. Release

**Deadlock** -> If two or more processes are waiting for such an event which is never going to occur
ex:
```
   | Hold     | Wait   
--------------|---------
P1 | Keyboard | Printer
p2 | Printer  | Keyboard
```

**Four Necessary Conditions for Deadlock:**
- Deadlock can occur only when all the following conditions are satisfied:
1. Mutual Exclusion
2. Hold & Wait
3. No-Preemption (of Resources)
4. Circular Wait

**Resource Allocation Graph (RAG):**
- Vertex -> Process `(P)` and Resource `[ ] R`
- Edge -> Allocation `P<-[ ]` , Request `P->[ ]`
```
    R1
   [● ●] ⬉
  ⬋   ⬊    ╲
(P1)  (P2)    (P3)
 ↑ │  ⬈ │    ╱
 │ ↓ ╱  ↓   ⬋
[● ● ●] [● ●]
  R2      R3
```

**Recovery From Deadlock**
1. Make sure that deadlock never occur -> Prevent the system from deadlock or avoid deadlock
2. Allow deadlock, detect and recover
3. Pretend that there is no any deadlock (used modern day OS)

**A. Deadlock Prevention**->Prevent any 4 necessary condition:
1. Mutual Exclusion
	- Make Each Process Independent such that no sharing or resources required? -> ❌ Not Possible
	- or Made CPU with Intensive no. of resources so that each process can have there own? -> ❌ Costly
2. Hold and Wait
	- Either Hold all Resources or Wait, Don't Hold Partially required Resources? -> ❌ But process Need to Required a long time, Bad CPU utilization
3. No Preemption
	- Preempt a Process causing Deadlock? -> If a Process execution stuck in a case if resources is taken away from it, it may goes to a unstable state ❌
4. Circular Wait
	- Allow process to Request for Resource in a specific order, let Increasing Order. So if a Process P1 required Resources R1, R2 and R3. Allow P1 to Request for R3 if it Have R2 already, or Request R2 if it hold R1 already -> **While Holding a resources of lower no. you can request for higher no. resources** ✅

**B. Deadlock Avoidance ->** OS tries to keep system in safe state
```
  Unsafe State     ╱
                 ╱
   [Deadlock]  ╱    Safe State
             ╱     
```
- Banker's Algorithm
```
| Processes | Alloc. | Max | Available |
|           | A B C  |A B C|  A B C    |
|-----------|--------|-----|-----------|
|   ---     |   ---  | --- |    ---    |
|   ---     |   ---  | --- |    ---    |
|   ---     |   ---  | --- |    ---    |

Need = Max-Alloc 

Deadlock Avoidance Algo:
- Pi Request for requestᵢ

1. requestᵢ ≤ needᵢ
2. requestᵢ ≤ availableᵢ
3. allocationᵢ = allocationᵢ + requestᵢ
	needᵢ = needᵢ - requestᵢ
	available - available - requestᵢ
4. Run safety algo:
	if safe -> requestᵢ granted
	if unsafe -> requestᵢ rejected
```

**C. Deadlock Detection**
1. When all resources have single instance -> wait for Graph
2. When resources have multiple instances -> Deadlock Detection Algorithm

- **Wait For Graph (WFG)**
	- It is created from resource allocation graph
```
RAG:
       (P5)
        ⬆
[]R1   []R3   []R4
 ⬆   ⬊  ⬆  ⬈  ⬇
(P1)  (P2)    (P3)
 ⬆         ⬊  ⬇
[] ⬅ (P4) ⬅ []
R2        R2
------------------------------
WFG:
        (P5)
         ⬆
(P1) ➡ (P2) ➡ (P3)
    ⬉    ⬇    ⬋
        (P4) 

If Cycle? Yes -> Deadlock
```

- **Deadlock Detection Algorithm:**
	- When resources have multiple instance, Deadlock detection is done using a specific algorithm
	- Similar to Banker's Algorithm. In Banker's Algorithm we are given `Max` and `Alloc`, but in this algorithm `Request` and `Alloc` are there so no need to calculate `need(request)`
```
| Processes | Alloc. | Request | Available |
|           | A B C  |  A B C  |  A B C    |
|-----------|--------|---------|-----------|
|   ---     |   ---  |   ---   |    ---    |
|   ---     |   ---  |   ---   |    ---    |
|   ---     |   ---  |   ---   |    ---    |
```

**Ques:** Three Processes P1, P2, and P3. the process require Resources 5, 6 and 7 respectively to execute. The minimum no. of resources the system should have such that deadlock can never occur?
**Ans:**
```
Max no. of Resources such that deadlock occur:

P1 = 5-1 = 4
P2 = 6-1 = 5
P3 = 7-1 = 6

=> 4 + 5 + 6 = 15

Min no. of Resources such that deadlock never occur:

=> 15 + 1 = 16
```

**Ques:** Consider a system with n processes. All n processes require R resources each to execute. The minimum number of resources the system should have such that deadlock can never occur? ⭐
```
Max no. of Resources such that deadlock occur:

P1 + P2 + ... + Pn

=> (R-1) + (R-1) +...+ (R-1)  n times = n(R-1)

Min no. of Resources such that deadlock never occur:

=> n(R-1)+1
```

**D. Recovery From Deadlock**

There are three basic approaches to recover from deadlock
1. Inform the system operator and allow him/her to take manual intervention
2. Terminate one or more processes involved in the deadlock
3. Preempt resources.

- **Process Termination**
	1. Terminate all processes involved in the deadlock
	2. Terminate processes one by one until the deadlock is broken


### Memory Management

- **Memory Management** -> Module of OS
- **Functions:**
	1. Memory allocation
	2. Memory deallocation
	3. Memory protection
- **Goals:**
	1. Maximum Utilization of space 
	2. Ability to run larger program with limited space

```
		             Memory Management Techniques
		             /                        \
	          Contiguous                     Non-contiguous
	       /            \                      /       \
 fixed partition     variable partition     Paging    Segmentation
```

**Contiguous Memory Allocation** → The whole process is stored in a single continuous block of memory.
1. **Fixed Partitioning** → The memory is divided into a fixed number of partitions at system startup. When a process arrives, it is allocated to a partition based on the partition allocation method (e.g., first-fit, best-fit).
-  **Problem**: **Internal Fragmentation** → Wasted space inside partitions if the process is smaller than the partition size.

2. **Variable Partitioning** → No fixed partitions; memory is allocated dynamically as per the process's need. When a process arrives, a partition of exact size is created.
- **Problem**: **External Fragmentation** → Free memory exists, but it is scattered in non-contiguous blocks, making it unusable for larger processes.
- **Solution: Compaction** -> Rearranges memory contents to place all free memory together in one large block

**Non-Contiguous Memory Allocation** → The process is divided into multiple parts and stored in different locations in memory. This allows better memory utilization but requires mechanisms like paging or segmentation for access.

1. **Paging** -> The process is divided into fixed-size **pages**, and memory is divided into **frames** of the same size.
- A page table maps each page to a frame in physical memory.
- **Eliminates external fragmentation** but may cause **internal fragmentation** if the last page is not fully used.

2. **Segmentation** -> The process is divided into **logical segments** (e.g., code, stack, heap), each of varying size.
- A **segment table** keeps track of each segment’s base address and limit.
- **Eliminates internal fragmentation** but may cause **external fragmentation** (though less than variable partitioning).

### Paging:

- ==Processes is divided in equal size of partitions called as ==`pages`
- ==Physical memory is divided in same equal size of partitions called== `frames`
- Processor will have a view of process and its pages
- Pages are scattered in frames
- ==Page table ==is used to map a process page to a physical frame

**Example of Paging:**
```
                                Physical Memory (Main Memory)
                                  ┌─────────┐
  Process         Page table      │         │ frame 0
┌────────┐         ┌─────┐        ├─────────┤
│ Page 0 │  -->  0 │  3  │  \    /│ page 3  │ frame 1
├────────┤         ├─────┤   \  / ├─────────┤
│ Page 1 │  -->  1 │  6  │  \ \/  │         │ frame 2
├────────┤         ├─────┤   |/\  ├─────────┤
│ Page 2 │  -->  2 │  5  │  \|  ↘ │ page 0  │ frame 3
├────────┤         ├─────┤  /\    ├─────────┤
│ Page 3 │  -->  3 |  1  | / |\   │         │ frame 4
└────────┘         └─────┘   | \  ├─────────┤
	                         |  ↘ | page 2  | frame 5
                              \   ├─────────┤
                                ↘ | page 1  | frame 6
                                  ├─────────┤
                                  |         | frame 7
                                  └─────────┘
                                  
                             


Formulas: ⭐
- No. of enries in P.T.  = No. of pages
- 1 P.T entry size = (frame no. bits) + extra bits(if given)
- P.T. size = (no. of entries in P.T) * (1 P.T. entry size)

```

**Binary Representations of Page and Frames:**
```
No. of pages = 4, bits to represent page no. = 2
No. of frames = 8, bits to represent frame no. = 3

                                 Physical Memory
                                   ┌─────────┐
  Process         Page table       │         │ frame 000
┌─────────┐         ┌─────┐        ├─────────┤
│ Page 00 │       0 │  3  │        │ page 3  │ frame 001
├─────────┤         ├─────┤        ├─────────┤
│ Page 01 │       1 │  6  │        │         │ frame 010
├─────────┤         ├─────┤        ├─────────┤
│ Page 10 │       2 │  5  │        │ page 0  │ frame 011
├─────────┤         ├─────┤        ├─────────┤
│ Page 11 │       3 |  1  |        │         │ frame 100
└─────────┘         └─────┘        ├─────────┤
	                               | page 2  | frame 101
                                   ├─────────┤
                                   | page 1  | frame 110
                                   ├─────────┤
                                   |         | frame 111
                                   └─────────┘

let: page size = 2 byte, 
- total process size = (no. of pages) x (page size) = 4 x 2 byte = 8 byte

note: 1 frame size = 1 page size ⭐

- total Main Memory size = (no. of frames) x (frame size) = 8 x 2 byte = 16 byte
```

**Logical Address and Physical Address:**
```
2 byte -> 1 page or 1 frame
1 byte -> 1 address

Physical Memory -> 16 byte -> 16 address 
-> Physical Address -> 4 bits

Process -> 8 byte -> 8 address
-> Locgical Address -> 3 bits

                                        Physical   Physical Memory
                                         Address  ┌─────────┐
                                             0000 |         |
   Logical   Process         Page table      0001 │         │ frame 000
   Address ┌─────────┐         ┌─────┐            ├─────────┤
       000 │ Page 00 │       0 │  3  │       0010 │ page 3  │ frame 001
       001 |         |         |     |       0011 |         |
           ├─────────┤         ├─────┤            ├─────────┤
       010 │ Page 01 │       1 │  6  │       0100 │         │ frame 010
       011 |         |         |     |       0101 |         |
           ├─────────┤         ├─────┤            ├─────────┤
       100 │ Page 10 │       2 │  5  │       0110 │ page 0  │ frame 011
       101 |         |         |     |       0111 |         |
           ├─────────┤         ├─────┤            ├─────────┤
       110 │ Page 11 │       3 |  1  |       1000 │         │ frame 100
       111 |         |         |     |       1001 |         |
           └─────────┘         └─────┘            ├─────────┤
	                                         1010 | page 2  | frame 101
	                                         1011 |         |
                                                  ├─────────┤
                                             1100 | page 1  | frame 110
                                             1101 |         |
                                                  ├─────────┤
                                             1110 |         | frame 111
                                              111 |         |
                                                  └─────────┘
```

**Logical Address to Physical Address**
```
Logical Address
┌─────┬─────┐
│  p  │  d  |     p:page no.  , d: offset
└─────┴─────┘                    |
                                 |
Physical Address                 | equal
┌─────┬─────┐                    ↓
│  f  │  d  |     f:frame no.  , d: offset
└─────┴─────┘

P.T 1 entry
┌─────┬─────────────┐ 
│  f  │  extra bits |   
└─────┴─────────────┘

Note: Main Memory is Byte Addressable, i.e each address can store 1 byte

Formula: ⭐
- No. of bits in offset = log(page size)
- No. of bits in page no. = log(no. of pages)
- No. of bits in Logical Address = log(process size) = p+d
- No. of bits in Physical Address = log(memory size)

Reverse Formula:
- Page size = 2^(no. of bits in offset)
- No. of pages = 2^(No. of bits in page no.)
- Process Size = 2^(No. of bits in Logical address) =  Page size x No. of pages
- Physical Memory size = 2^(No. fo bits in Physical Address)
```

Example
```
Page size -> 2 byte (2 Address)
-> no. of bits in offset(d) -> log(2) = 1 bit

no. of page -> 4
-> no. of bits in page no.(p) -> log(4) = 2 bits

no. of bits in Logical address = 1+2 = 3 bits
-> Process size = 2^3 = 8 byte
```

```
        Logical           Physical 
        address          address   ┌────────┐
              ┌───────────────┐    |        | 
┌─────┐       |               ↓    |Physical|
| CPU | ⭢ [p|d]           [f|d] ⭢ |Address | 
└─────┘     |               ↑      |        |
            | p ┌┌─────┐    |      |        |
            |   └|     |    |      └────────┘
            └───>|-----|────┘
                 |__f__|
                 |     |
                 └─────┘
                 Page Table
```

**Ques:** Consider a paged memory system with logical address of 35-bits and physical address of 29-bits. The page size 2KB. Further consider that one page table entry size is 4 bytes.
Find the following:
A. Bits in page offset
B. C. Bits for page number
C. No. of pages in process
D. Bits for frame number
E. Number of frames in physical memory
F. Page table size
G. Extra bit per entry

**Ans:**
```
Logical Address
[ p |  d ] = 35 bits
       11

Physical Address
[ p |  d ] = 29 bits
       11

A.
page size = 2KB = 2^11 B
no. of bits in offset= log(2^11) = 11 bits

B.
no. of bits in page no. = 35 - 11 = 24 bits

C.
no. of pages in process = 2^24

For verification only:
Process Size = page size x no. of pages = (2^11)*(2^24) = 2^35
no. of bits in Logical address = log(2^35) = 35 ✅

D. 
no. of bits in frame no. = 29-11 = 18 bits

E. 
No. of frames in Physical Address = 2^18

F. 
Page Table Size = (no. of entries) x (1 entry size) = (no. of pages) x 4 byte = 2^24 x 2^2 = 2^26 B = 64MB

G.
no. of bits in Entry = 4B = 32 bits
no. of bits in frame = 18 bits
no. of extra bits = 32-18 = 14 bits
```

**Ques:** Consider a machine with 64 MB physical memory and a 32-bit virtual address space. If page size is 4 KB, what is the approximate size of the page table.
**Ans:**
```
Page Size = 4 KB = 2^12 B
No. of Pages = 2^12
No. of bits in offset = log(2^12) = 12 bits

virtual address
[ p | d ] = 32 bits
 20   12

Physical Memory = 64 MB = 2^26 B
No. of Bits in Physical Address = log(2^26) = 26 bits
No. of Bits in Frame no. = 28-d = 28-20 = 6 bits

Physical address
[ f | d ] = 26 bits
  14  12

-> Size of Page table = (No. of entries) x (size of one entry) = (No. of pages) x (No. of bits in frame no.) = 2^12 x 8 = 2^20 x 14 = 14 Mb = 14/8 ~ 2 MB

Note: if extra bit not given, take it zero
```


Summary
```
                       Logical Address ---------2^(bits)---> = Process size
						┌─────┬─────┐
				page no.│  p  │  d  | offset
					|	└─────┴─────┘   |  
                    |                   |
                  2^(bits)             2^(bits)
                    ↓                   ↓
            = No. of pages          = Page size
                                        ↕ 
            = No. of frames          = frame Size
                   ↑                    ↑
                2^(bits)              2^(bits)
                   |                    |            
				   |	┌─────┬─────┐   |
			   frame no.│  f  │  d  | offset
						└─────┴─────┘  
                       Physical Address --------2^(bits)---> = Memory size
                 

						  Page Table Size = No. of Pages x (f + extra bits)
						┌─────┬─────────────┐ -┐
						│  f  │  extra bits |  | 
						├─────┼─────────────┤  |  
						│  f  │  extra bits |  | No. of entries
						├─────┼─────────────┤  | = No. of Pages
						│  f  │  extra bits |  |
						├─────┼─────────────┤  |
						│  f  │  extra bits |  |
						├─────┼─────────────┤  |
						│  f  │  extra bits |  | 
						└─────┴─────────────┘ -┘

Formula: ⭐
- No. of bits in offset = log(page size)
- No. of bits in page no. = log(no. of pages)
- No. of bits in Logical Address = log(process size) = p+d
- No. of bits in Physical Address = log(memory size)

Reverse Formula:
- Page size = 2^(no. of bits in offset)
- No. of pages = 2^(No. of bits in page no.)
- Process Size = 2^(No. of bits in Logical address) =  Page size x No. of pages
- Physical Memory size = 2^(No. fo bits in Physical Address)
```


**Time Required for Paging**
```
Tₘₘ -> Memory Access Time

Effective Memory Access Time:
	If Page Table Stored in Main Memory:
		E.M.A.T = 2*Tₘₘ ⭐

	If Page Table Stored in Registers (Special case)
		E.M.A.T = Tₘₘ 

why 2*Tₘₘ?
one `Tₘₘ` for accessing Page table (to get physical address) from Memory and another `Tₘₘ` to get the actual content from the Memory
```

**Translation lookaside buffer (TLB)** -> Memory hardware that is used to reduce the time taken to access a user memory location or address translation
```
TLB[p] -> f

 p   f          
┌──┬──┐
├──┼──┤
├──┼──┤
├──┼──┤
├──┼──┤
└──┴──┘
```

```
CPU --->[ p | d ]                                  ┌─────────────────┐
         | |                                       |                 |
         | |    T.L.B                              | Physical Memory |
         | ├─> ┌─┬─┐     TLB HIT                   | (Main Memory)   |
         | ├─> ├─┼─┤ ────────────> [ f | d ] ───>  |                 |
         | ├─> ├─┼─┤                 ^             |                 |
         | └─> └─┴─┘                 |             |                 |
         |  TLB MISS    ┌─────┐      |             |                 |
         └─────────────>├─────┤──────┘             └─────────────────┘
                        ├─────┤
                        └─────┘ 
                        Page Table
                        (Main Memory)

```

**Effective Memory Access Time (with TLB)**
```
E.M.A.T = H*(tₗ + tₘ) + (1-H)(tₗ + 2*tₘ)
        =  tₗ + tₘ + (1-H)tₘ

tₗ - TLB access time
tₘ - Memory access tiem
H - Hit Ratio
```


**TLB Mapping**
1. Direct Mapping
2. Set Associative
3. Full Associative

**1. Direct Mapping**
```
Logical Address
┌────────────────────┬───┐
|           p        | d |
└────────────────────┴───┘
           ⬇         
┌─────┬──────────────┬───┐
| Tag | TLB entry no.| d |
└─────┴──────────────┴───┘

No. of bits in TLB entry no. = log(No. of entries in TLB)
```

**2. Set Associative Mapping**
```
Logical Address
┌────────────────────┬───┐
|           p        | d |
└────────────────────┴───┘
           ⬇         
┌─────┬──────────────┬───┐
| Tag | Set offset   | d |
└─────┴──────────────┴───┘

No. of bits in set offset = log(No of sets in TLB)
No. of sets in TLB = (no. of entries in TLB ) / (Associativity)
```

**3. Full Associative Mapping**
```
Logical Address
┌────────────────────┬───┐
|           p        | d |
└────────────────────┴───┘
           ⬇         
┌────────────────────┬───┐
|        Tag         | d |
└────────────────────┴───┘
```

**Ques:** A computer system implements a 40 bit virtual address, page size of 8 kilobytes and a 128-entry translation look-aside buffer (TLB) organized into 32 sets each having four ways. Assume that the TLB tags does not store any process id. The minimum length of the TLB tag in bits is ?

**Ans** 22 bits
```
page size = 8 kB = 2^13 bits
d = log(2^13) = 13

[ p | d ] = 40 bits
 27   13

No. of Sets = 128/4 = 32
no. of bits in Tag = log(32) = 5

[ Tag | Set | d ] = 40 bits
  22     5    13

Tag = 22 bits
```

**Ques:** A computer system implements a 36 bit virtual address, page size of 16 kilobytes and a 256-entry. TLB organized into 64 sets each having 4-ways. Assume that the TLB tags does not store any process id. The minimum length of the TLB tag in bits is ?

**Ans** 16 bits 
```
page size = 16 kB = 2^14 bits
d = log(2^14) = 14

[ p | d ] = 36 bits
 22   14

No. of Sets = 256/4 = 64
no. of bits in Tag = log(64) = 6

[ Tag | Set | d ] = 36 bits
  16     6    14

Tag = 16 bits
```

**Page Table in Memory**

```
Physical Memory
┌───────────┐
├───────────┤
| Page Table|
├───────────┤
│           │
│           │
└───────────┘
```

**Multilevel Paging** ⭐
- Instead of using a single page table, the system divides it into multiple levels, reducing memory overhead and improving lookup efficiency.
- So we Require another page Tables to get  Inner Page Tables

```
Outer Page Table         Inner Page Table
┌───────────┐             ┌───────┐--> f
│       --------------->  └───────┘--> 
│           │             ┌───────┐--> 
│       --------------->  └───────┘--> 
│           │             ┌───────┐--> 
│       --------------->  └───────┘--> 
└───────────┘
```

```
Logical Address
┌─────┬─────┬───┐
| p1  | P2  | d |
└─────┴─────┴───┘
    |
	|		┌─────┐                [ f | d ]
	└──> p₁{├─────┤                /
			├─────┤--->  ┌─────┐  /
			│     │   p₂{├─────┤ / 
			└─────┘      ├──f──┤---> ┌─────┐
                         │     │   d{├─────┤ 
                         └─────┘     ├/////┤
                                     │     │ 
                                     └─────┘

No. of P.T entries per page = (Page Size) / (Entry Size)
```

**Note:** ⭐
`P` -> max no. of bits for Page no.
If outer table fits into a page exactly, then it will use all bits from max no. of bits possible.
- No. of bits in  `Inner page no.  = P`
- No. of bits in `Outer page no. ≤ P`


**Ques:** V.A = 15 bits, Page Size = 128 bytes, Page table entry size = 2 bytes. Number of levels in multilevel page?
```
no. of bits in offset = log(page size) = log(128) = 7
 15 bits

[   p  | d  ] = 15 bits
    8    7

No of Entries = Page size/ page table entry size = 2^7/2 = 2^6

No. of bits in p2 = log(2^6) = 6


[ p1 |   p2  | d  ] = 15 bits
  2      6     7


No. of levels = 2

Repeat the step and break down outer page bits (pᵢ) until  pᵢ≤Pⱼ≤d (where j>i)
```


**Ques:** Consider a virtual memory system with physical memory of  8GB, a page size of 8KB and 46-bit virtual address. Assume every page table exactly fits into a single page. If page table entry size if 4B then how many levels of page tables would be required.
```
Page size = 8KB -> 2^13
Entry size = 4B -> 2^2
no. of bits in d = log(page size)  = 13 bits

No. of entries per page = (Page size) / (Entry size) = 2^11
no. of bits for each page = 11 bits

[ p1 | p2 | p3 |  d ] = 46 bit
  11   11   11   13
```

**Ques:** VA = 26 bits, Page table entry size = 4 bytes, 2-level paging, Outer page table fits into a page exactly. Page size in Kbytes?
**Ans:** 1 KB
```
Page size = 2^x B
No. of bits in d = x

No. of entries per page = 2^xB/4B = 2^(x-2)
Max No. of bits per page = x-2

[ p1  | p2  | d ] = 26 bits
  x-2   x-2   x

3x - 4 = 26 => x = 30/3 = 10

Page Size = 2^10 = 1KB
```

**Ques**  Size of page tables across all levels?
`[ p1 | p2 | d ]`
    1     7     10
**Ans:**
```
D = 10 bits
Page Size = 2^10 B = 1KB

No. of Page to store outer P.T = 1 Page
No. of Page to store Inner P.T = 2^(p1) = 2^1 = 2 Pages
Total No of page = 1 + 2 = 3 Pages
Total Page Table size = 3 Pages *1KB = 3KB
```

**Ques**  Size of page tables across all levels?
`[ p1 | p2 | p3 | d ]`
    1     9      9       11
**Ans:**
```
D = 11 bits
Page Size = 2^11 B = 2KB

No. of Page to store outer P.T = 1 Page
No. of Page to store Middle P.T = 2^(p1) = 2^1 = 2 Page
No. of Page to store Inner P.T = 2^(p1)*2^(p2) = 2^1*2^9 = 2^10 = 1024 Pages
Total No of page = 1 + 2 + 1024 = 1027 Pages
Total Page Table size = 1027 Pages * 2KB = 2054 KB
```


### Segmentation

- Divide Process in Logically related partitions (Segments)
- Segments are scattered in physical memory

### Virtual Memory

- Feature of OS
- Enables to run larger process with smaller available memory

```
vb -> valid bit, is the process in Main memory?
pro. -> process id in Main Memory

   process table
    ┌───┬───┐
0	|   | 0 |
	├───┼───┤
1	| 0 | 1 |     Physical Memory (M.M)
	├───┼───┤         ┌─────────┐           Secondary Memory
2	| 3 | 1 |       0 |  Page 1 |            ┌─────────┐
	├───┼───┤         ├─────────┤            | [0] [3] |
3	|   | 0 |       1 |  Page 6 |            | [5] [7] |
	├───┼───┤         ├─────────┤            |         |
4	| 2 | 1 |       2 |  Page 4 |            └─────────┘
	├───┼───┤         ├─────────┤                 |
5	|   | 0 |       3 |  Page 2 |       Store Remaining Pages
	├───┼───┤         └─────────┘   
6	| 2 | 1 |
	└───┴───┘
	 /       \
process id  Valid bit
(in M.M)    (is in M.M?)
```

**Demand Paging:**

- Bring pages in memory when CPU demands
- Pure Demand Paging -> Don't store any pages in Main Memory in starting of process.

**Page Fault** -> If the page demanding by CPU is not present in main memory.
- Then we Replace page required pages from Secondary memory to Main memory using Page replacement policy

**Page Replacement policy:**

1. First in First Out (FIFO)
2. Optimal Policy ⭐
3. Counting Algorithms : Least Recently Used (LRU) and Least Frequently Used (LFU)
4. Most Frequently Used (MFU)
5. Last In First Out (LIFO)

**1. First In First Out (FIFO)**
- Replace Page Which entered Earliest in Main Memory
Assume:
- No. of frames = 3 (all empty Initially)
- Page reference sequence: 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5

```
M.M
[ , , ]

➡1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, , ] Page Fault

1,➡2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, 2, ] Page Fault

1, 2, ➡3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, 2, 3] Page Fault

1, 2, 3, ➡4, 1, 2, 5, 1, 2, 3, 4, 5
[4, 2, 3]  Page Fault (FIFO:1)

1, 2, 3, 4, ➡1, 2, 5, 1, 2, 3, 4, 5
[4, 1, 3]  Page Fault (FIFO:2)

1, 2, 3, 4, 1, ➡2, 5, 1, 2, 3, 4, 5
[4, 1, 2]  Page Fault (FIFO:3)

1, 2, 3, 4, 1, 2, ➡5, 1, 2, 3, 4, 5
[5, 1, 2]  Page Fault (FIFO:4)

1, 2, 3, 4, 1, 2, 5, ➡1, 2, 3, 4, 5
[5, 1, 2]  No Page Fault X 

1, 2, 3, 4, 1, 2, 5, 1, ➡2, 3, 4, 5
[5, 1, 2]  No Page Fault X 

1, 2, 3, 4, 1, 2, 5, 1, 2, ➡3, 4, 5
[5, 3, 2]  Page Fault (FIFO:1) ⭐ Note: `Earliest In = 1` is considered, `Not Earliest Demanded = 5`

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, ➡4, 5
[5, 3, 4]  Page Fault (FIFO:2)

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, ➡5
[5, 3, 4]  No Page Fault X

No. of Page References = 12
No. of Page Fault = 9
Hit Ration = 9/12
```
- **Belady's Anomaly** (only in FIFO)-> Some Page references sequences are such that, Increasing the **No. of Frames (No. of Page stored in Memory)** Increases the no. of Fault

- **Advantage of FIFO**
	- Simple and easy to implement
	- Low overhead
- **Disadvantage FIFO:**
	- Poor performance
	- Doesn't consider the frequency of use or last used time, simply replaces the old page.
	- Suffers from Belady's Anomaly


**2. Optimal Policy**
- Replace page which will not be used for longest time
Assume:
- No. of frames = 3 (all empty Initially)
- Page reference sequence: 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5

```
M.M
[ , , ]

➡1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, , ] Page Fault

1,➡2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, 2, ] Page Fault

1, 2, ➡3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, 2, 3] Page Fault

1, 2, 3, ➡4, 1, 2, 5, 1, 2, 3, 4, 5
[1, 2, 4]  Page Fault (required after longest time: 3)

1, 2, 3, 4, ➡1, 2, 5, 1, 2, 3, 4, 5
[1, 2, 4]  No Page Fault X

1, 2, 3, 4, 1, ➡2, 5, 1, 2, 3, 4, 5
[1, 2, 4]  No Page Fault X

1, 2, 3, 4, 1, 2, ➡5, 1, 2, 3, 4, 5
[1, 2, 5]  Page Fault (required after longest time: 4)

1, 2, 3, 4, 1, 2, 5, ➡1, 2, 3, 4, 5
[1, 2, 5]  No Page Fault X 

1, 2, 3, 4, 1, 2, 5, 1, ➡2, 3, 4, 5
[1, 2, 5]  No Page Fault X 

1, 2, 3, 4, 1, 2, 5, 1, 2, ➡3, 4, 5
[3, 2, 5]  Page Fault (required after longest time: 1 or 2 + FIFO(1,2)=1)

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, ➡4, 5
[3, 4, 5]   Page Fault (required after longest time: 2)

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, ➡5
[5, 3, 4]  No Page Fault X

No. of Page References = 12
No. of Page Fault = 7
Hit Ration = 7/12
```

-  **Advantages of Optimal Policy:**
	- Easy to Implement
	- Simple data structure are used
	- Highest efficient (provide minimum page fault)
- **Disadvantages of Optimal Policy**
	- Requires future knowledge of the program -> Practically Impossible
	- Time Consuming

**3. Least Recently Used (LRU)**
- Replace Page which is used/demanded Earliest

```
M.M
[ , , ]

➡1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, , ] Page Fault

1,➡2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, 2, ] Page Fault

1, 2, ➡3, 4, 1, 2, 5, 1, 2, 3, 4, 5
[1, 2, 3] Page Fault

1, 2, 3, ➡4, 1, 2, 5, 1, 2, 3, 4, 5
[4, 2, 3]  Page Fault (LRU:1)

1, 2, 3, 4, ➡1, 2, 5, 1, 2, 3, 4, 5
[4, 1, 3]  Page Fault (LRU:2)

1, 2, 3, 4, 1, ➡2, 5, 1, 2, 3, 4, 5
[4, 1, 2]  Page Fault (LRU:3)

1, 2, 3, 4, 1, 2, ➡5, 1, 2, 3, 4, 5
[5, 1, 2]  Page Fault (LRU:4)

1, 2, 3, 4, 1, 2, 5, ➡1, 2, 3, 4, 5
[5, 1, 2]  No Page Fault X 

1, 2, 3, 4, 1, 2, 5, 1, ➡2, 3, 4, 5
[5, 1, 2]  No Page Fault X 

1, 2, 3, 4, 1, 2, 5, 1, 2, ➡3, 4, 5
[3, 1, 2]  Page Fault (LRU:1) ⭐ Note: Here is the difference Between FIFO & LRU

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, ➡4, 5
[3, 4, 2]  Page Fault (LRU:1)

1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, ➡5
[3, 4, 5]  Page Fault (LRU:2)

No. of Page References = 12
No. of Page Fault = 10
Hit Ration = 10/12
```

-  **Advantages of LRU:**
	- Efficient
	- Doesn't suffer from Belady's Anomaly
- **Disadvantages of LRU**
	- Complex Implementation
	- Expensive
	- Requires hardware support


**3. Counting Algorithms**

- Counting algorithms look at the number of occurrences of particular pages and use this as the criterion for replacements.
1. **LFU (Least Frequently Used)**
2. **MFU (Most Frequently Used)**

**4. Last In First Out (LIFO)** 
- Replace page which entered in Last
- Very Bad Algorithm -> Usually Last In process are Replaced, and the starting Processes are Remained for Long time without any replacement


### Frame Allocation

- How many frames do we allocate per process?
- If it is a single-user, single-tasking system, it's simple - all the frames belong to the user's process
1. Equal Allocation
2. Proportional Allocation
### New EMAT Formula (with Page Fault)

Effective Memory Access Time Formula (with Page Fault)
```
E.M.A.T = H*(tₗ + tₘ) + (1-H)(tₗ + tₘ + tnew)
		                               ↓					
tnew = (1-p)*tₘ + p*[(1-d)*(PFST with not dirty + d*(PFST with dirty]

tₗ - TLB access time
tₘ - Memory access tiem
H - Hit Ratio
p - page fault rate
d - dirty page fraction
PFST  - Page Fault Service Time
```


```
      If Page Fault (p)
       /           \
dirty page (d)    not dirty page(1-d)
```

- **Dirty Page:** A memory page that has been modified in RAM but not yet written back to disk.

- **Not Dirty Page (Clean Page):** A page that is either unmodified or already saved to disk.

**Page Fault Service Time**
```
PFST for Not Dirty Page = 
 Page transfer time from disk to Main memory + (tₘ)

PFST for Dirty Page = 
Page transfer time from disk to Main memory + Page transfer time from dist to Main Memory  + (tₘ)
```

### Logical Address in Decimal to Physical Address?

```
p =  LA / Page Size -> search in P.T -> f
d = LA % Page Size

Physical Address (PA) = (f*page size) + d


p - page no.
d - offset no.
LA - Logical Address in Decimal
PA - Physical Address
```

### Thrashing

When the degree of **multiprogramming** (number of processes in memory) **increases beyond a limit**, thrashing occurs because of More processes share limited RAM, reducing frames per process, leading to frequent page faults.

```
CPU Utilisation (Efficiency)
^ 
|
|          .  . 
|       .    ^    .
|   .        |       .
|.           |           .
|            |
|           thrashing
|
└────────────────────────────> Degree of Multiprogramming
```

After thrashing, the pages in main memory become **insufficient** to store the required process pages, leading to **frequent page faults** and excessive swapping between RAM and disk, further degrading system performance.
- i.e. after thrashing -> CPU spend more time in Page fault Service, and less time in Process execution

### File System

**File** -> file is named collection of related information that is recorded on secondary storage

**File Attributes**
- Name, Extension, Size, Date, Author, (Created, Modified & Accessed), (Attributes: Read-only, hidden), Default Program, Security Details

**File System** -> Module of OS which manages, controls and organizes files and related structures.

**Disk Blocks** -> smallest units of data storage on a disk, where files are divided and stored.
- Two time of Disk Block Formatting
1. Low Level (Physical) -> when manufactures making track and sectors on Disk
2. High Level (Logical) -> Disk Partition and Making drives, Making blocks

**File Allocation Methods** -> determines how the disk's blocks are assigned to store file data.
1. Contiguous Allocation
```
Secondary Storage (Disk)
┌─────────────┐
│ [1] [2] [3] │          ┌────┬────┬───┐
│ [4] [5] [6] │          ├────┼────┼───┤
│ [7] [8] [9] │          └────┴────┴───┘
└─────────────┘

Pefromance:
1. Fragmentation: Internal, External : (
2. Increase in File Size: Inflexible : (
3. Type of access: Sequential, Random/Direct : )
```

2. Linked Allocation
```
Secondary Storage (Disk)
┌──────────────┐
│ [1]->[2] [3] │          ┌────┬────┬───┐
│ [4]  [5] [6] │          ├────┼────┼───┤
│ [7] [8]<-[9] │          └────┴────┴───┘
└──────────────┘
-> A file is represented in Linked List Form i.e. Each Disk Block will keep address of Next Block of containing the file

Pefromance:
1. Fragmentation: Internal : )
2. Increase in File Size: Flexible : )
3. Type of access: Only Sequential : (
```

3. Indexed Allocation
```
Secondary Storage (Disk)
┌─────────────┐
│ [1] [2] [3] │          ┌────┬────┬───┐
│ [4] [5] [6] │          ├────┼────┼───┤
│ [7] [8] [9] │          └────┴────┴───┘
└─────────────┘
                  ⬊ 
                     
				   Index Block
					┌───┐
					├─6─┤
					├─12┤
					├─5─┤
					└───┘

-> For a File, Array Store the All the Block representing file
-> Used in Now a days computers

Pefromance:
1. Fragmentation: Internal : )
2. Increase in File Size: Flexible : )
3. Type of access: Random Access : )
```

### Unix I-node Structure

The `inode` (index node) is a data structure in a Unix-style file system that describes a file-system object such as a file or a directory.

```
Disk Blocks                                 Index   Index
┌────┬────┬────┬────┬────┬────┬────┬────┐    ┌───┐  ┌───┐
│    │    │    │    │    │    │    │    ──── │   |->│   | -> [] }
└─|──┴──|─┴────┴──|─┴────┴────┴────┴────┘    │   |  └───┘ -> [] } Indeirect Access
  |     |         |                          │   |->┌───┐ -> [] } File blocks
(  )   (  )       |                          └───┘  │   | -> [] }
Direct Access   ┌───┐                               └───┘
blocks of file  │   │-> [] } Indirect Access
                │   │-> [] } blocks of files
                └───┘-> [] }
                Index
```

**Ques:** The index node (1inode) of a Unix-like file system has 12 direct, one single-indirect and one double-indirect pointer. The disk block size is 4 kB, and the disk block addresses 32-bits long. The maximum possible file size is (rounded off to 1 decimal place) ❓
**Ans:** 
```
disk block size = 4KB
disk block address = 32 bits = 4B

No. of indexes per block = 4KB/4B = 1K

File Size by Direct Index = 12*4KB
File Size by Single-Indirect Pointer = (1*1k*4KB)
File Size by Double-Indifect Pointer = (1*1k*1k*4KB)

Max File Size = 12*4kB + (1*1k*4kb) + (1*1k*1k*4kb) = 48KB + 4 MB + 4GB = 4.004048 GB
```
### Disk Scheduling

**Cylinder:**
- Collection of tracks of same radius from all surfaces
- In Disk we store Data in Cylinder wise so for a seek time we can cover maximum Sectors

**Disk Scheduling:**
- Done by operating system to schedule I/O  request arriving for the disk

**Disk Scheduling Algorithms:**
1. FCFS (First Come First Serve)
2. SSTF (Shortest Seek Time First)
3. Scan
4. C-Scan (Circular-Scan)
5. Look
6. C-Look (Circular-Look)

**1. FCFS (First Come First Serve)**

Assume:
- 200 Cylinder : 0 - 199
- Suppose the order of request is : 72, 160, 33, 130, 14, 6, 180
- The Read/Write arm is at 50

```
50

FCFS:  ➡ 72, 160, 33, 130, 14, 6, 180
50 -> 72 = abs(72-50) = 22 movements

FCFS:  ➡ 160, 33, 130, 14, 6, 180
72 -> 160 = abs(160-72) = 88 movements 

FCFS:  ➡ 33, 130, 14, 6, 180
160 -> 33 = abs(33-160) = 127 movements

FCFS:  ➡ 130, 14, 6, 180
33 -> 130 = abs(130-33) =97 movements

FCFS:  ➡ 14, 6, 180
130 -> 14 = abs(14-130) = 116 movements

FCFS:  ➡6, 180
14 -> 6 = abs(6-14) = 8 movements

FCFS:  ➡180
6 -> 180 = abs(180-6) = 174 movements

Total no. of head movements = 22 + 88 + 127 + 97 + 116 + 8 + 174 = 632 movements

```

- **Advantages:**
	- Every request gets a fair chance
	- No indefinite postponement

- **Disadvantages:**
	- Does not try to optimize seek time
	- May not provide the best possible service


**2. SSTF (Shortest Seek Time First)**

Assume:
- 200 Cylinder : 0 - 199
- Suppose the order of request is : 72, 160, 33, 130, 14, 6, 180
- The Read/Write arm is at 50

```
50 :

SSTF : 72, 160, ➡33, 130, 14, 6, 180
50 -> 33 =  (50-33) Movements

SSTF : 72, 160, 130, ➡14, 6, 180
33 -> 14 = (33-14) Movements

SSTF : 72, 160, 130, ➡6, 180
14 -> 6 = (14-6) Movements

SSTF : ➡72, 160, 130, 180
6 -> 72 = (72-6) Moevements

SSTF : 160, ➡130, 180
72 -> 130 = (130-72) Movements

SSTF : ➡160, 180
130 -> 160 = (160-130) Movements

SSTF : ➡180
160 -> 180 = (180-160) Movements

Total no. of head movements = (50-33) + (33-14) + (14-6) + (72-6) + (130-72) + (160-130) + (180-160) = (50-6) + (180-6) = 218 movements
```

- **Advantages:**
	- Average Response Time decrease
	- Throughput Increase

- **Disadvantages:**
	- Overhead to calculate seek time in advance
	- Can cause Starvation for a request if it has higher seek time as compared to incoming requests
	- Higher variance of Response time as SSTF favors only some requests

**3. SCAN (Elevator):**
- Initial Direction is given
- Goes up to last request track in one direction before changing direction
- Also Go to Initial Direction Edge `0`(If going left) or `199`(if going right)
```
current at track no. -> 50
minum/maximum requested track -> x

if going rightward :
                       50-------------->199
                x <---------------------199

if going leftward :
                       
        0 <-------------50
        0 ------------------>x

```
- **Advantage:**
	- High throughput
	- Low Variance of Response time
	- Average Response time

- **Disadvantage:**
	- Long waiting time for request for location just visited by disk arm


**4. LOOK**
- Same as Scan, but not go to the edge track if not requested
```
current at track no. -> 50
minum requested track -> xmin
maximum requested track -> xmax

if going rightward :
                       50----------->xmax
                xmin <---------------xmax

if going leftward :
                       
        xmin <---------50
        xmin ------------------>xmax

```

**5. C-SCAN**
- Initial Direction is given
- Does not Change Direction
- Also Go to Edge Track `0` as well as  `199` 
```
current at track no. -> 50
minum/maximum requested track -> x

if going rightward :                     ↷
                       50-------------->199
        0 ---------->x

if going leftward :
       ↶               
        0 <-------------50
                           <------------199

```
- **Advantage**
	- Provides more uniform wait time compared to SCAN

**6. C-Look**
- Same as C-Scan, but not go to the edge track if not requested
```
current at track no. -> 50
minum requested track -> xmin
maximum requested track -> xmax
minimum requested track>50 or maximum requested track<50 -> x

if going rightward :                 ↷
                       50---------->xmax
         xmin------->x

if going leftward :
          ↶               
         xmin<---------50
                           x<------------xmax

```

# ---x---

Completed ✅