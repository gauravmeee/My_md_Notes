---
description: From Gate Gate Smasher's Tutorial ▶️
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

# L-4: Deadlock

### My Notes ⭐

A **deadlock** in operating systems is a situation where :

* a set of processes or threads are blocked because each one is waiting for a resource that another process is holding. None of the processes can proceed because they are all waiting for a condition that can never be true, leading to a "deadlock."

Deadlock Example

```
               R1
		       [.]  
Allocated  ⬋      ⬉  Request
		    
		(P1)         (p2)
		
Request    ⬊      ⬈  Allocated
		       [.] 
		       R2 
```

```
 ┌-------------------┐
(P1)    P2     P3    |           R1 -> P1
 ↓   ⬋  ↑   ⬋  ↑    |           R1 is allocated to P1
 R1     R2     R3 ←--┘           P2 requests for R1


```

**Key Conditions for Deadlock (Coffman’s Conditions) ⭐**

1. **Mutual Exclusion**: Only one process can use the resource at any given time.
2. **Circular Hold & Wait**
   * **Hold and Wait**: A process is holding at least one resource and is waiting for at least one resource resources.
   * **Circular Wait**: A set of processes are waiting in a circular chain
3. **No Preemption**: Resources cannot be forcibly taken away from a process.

**Resource Allocation Graph (RAG) in Deadlock.**

```
     Vertex
        |
 ┌------+------┐
 Process    Resource
 Vertex      Vertex
 (Pi)           |
         ┌------+------┐
        Single      Multi
        Instance    Instance
        [.]         [...]
    ex:CPU,Monitor  ex: Registers
```

```
      Edge
        |
 ┌------+------┐
 Assign       Request
 Edge         Edge

 (p)           (p)
  ↑             ↓
 [R]           [R]
```

**Waiting:**

1. Finite -> Starvation
2. Infinite -> Deadlock

| Scenario                           | Deadlock Status         |
| ---------------------------------- | ----------------------- |
| Single Instance + No Circular Wait | No Deadlock             |
| Single Instance + Circular Wait    | Deadlock                |
| Multiple Instances + Circular Wait | May or May Not Deadlock |

Examples 1

```
               R1
		       [.]  
    Assign  ⬋      ⬉  Requesting
		    
		(P1)         (p2)  (Circular Wait)
		
Requesting  ⬊      ⬈  Assign
		       [.] 
		       R2 
		    (single Instance)

    | Allocate | Request
----|----------|--------
    | R1  R2   | R1  R2       Availability (0, 0) -> deadlock Method ✅
P1  | 1   0    | 0    1                     R1 R2
P2  | 0   1    | 1    0
```

**Methods for Handling Deadlocks**

1. **Deadlock Prevention**
   * Prevent the system from entering a deadlock state by ==ensuring that at least one of the necessary conditions for deadlock== (mutual exclusion, hold and wait, no preemption, and circular wait) ==never occurs.==
2. **Deadlock Avoidance (Banker's Algorithm)**
   * Dynamically check resource allocation to ==ensure the system will never enter an unsafe state== (i.e., a state that could lead to deadlock).
3. **Deadlock Detection & Recovery**
   * Detection : Allow the system to enter a deadlock state but detect it through algorithms and then recover. ==Construct a **wait-for graph**, If a cycle exists, a deadlock has occurred.==
   * Recovery: Once a deadlock is detected, recovery strategies include:
     1. **Process Termination:** ==Abort one or more processes== to break the deadlock.
     2. **Resource Preemption:** ==Temporarily take resources away from some processes== and allocate them to others to resolve the deadlock.
4. **Deadlock Ignorance (Ostrich Method)**
   * The system deliberately ignores the possibility of deadlock, assumes that deadlock is rare and the cost of prevention, detection, or recovery outweighs the cost of occasionally restarting the system when a deadlock occur.

**Difference between Deadlock Prevention & Deadlock Avoidance**

Here is the table showing the clear difference: Here is the table showing the clear difference:

Here is the table with examples:

| Aspect              | **Deadlock Prevention**                                                                | **Deadlock Avoidance (Banker’s Algorithm)**                                                                                                                                                                                                                                                                                                                                                  |
| ------------------- | -------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Strategy**        | Eliminates one or more necessary conditions for deadlock                               | Dynamically checks if granting resource keeps system in safe state                                                                                                                                                                                                                                                                                                                           |
| **Example**         | Prevent _Hold and Wait_: Process must request all resources (printer, scanner) at once | System with 3 resources, 2 processes (Max=2, Alloc=1). Checks if granting keeps system safe before allowing                                                                                                                                                                                                                                                                                  |
| **Decision Time**   | Before execution (design-time)                                                         | At runtime                                                                                                                                                                                                                                                                                                                                                                                   |
| **System Behavior** | Conservative, may lead to low resource utilization                                     | More efficient, but requires complex checks                                                                                                                                                                                                                                                                                                                                                  |
| **Unsafe State**    | Never entered                                                                          | May be close, but avoided through safe-state checking                                                                                                                                                                                                                                                                                                                                        |
| Example:            | A process must acquire both printer and scanner together or wait without holding any.  | <p>If a process requests a resource, <strong>System checks:</strong><br>- If granting keeps the system in a <strong>safe state</strong> (i.e., enough resources remain for other processes to complete) → <strong>Request granted</strong><br>- If granting leads to an <strong>unsafe state</strong> (i.e., no process can finish) → <strong>Request denied</strong> (deadlock avoided)</p> |

**Deadlock Detection Algorithm**

* Construct a **wait-for graph**, where nodes represent processes and directed edges represent dependencies between processes.
* Detect cycles in this graph. If a cycle exists, a deadlock has occurred.

**Real-World Example**

* Consider a system where two programs are trying to access two shared resources (like a printer and a scanner). If one program locks the printer and waits for the scanner while the other locks the scanner and waits for the printer, both will wait indefinitely—this is a deadlock situation.

***

## [L-4.1: DEADLOCK concept | Example | Necessary condition | Operating System](https://www.youtube.com/watch?v=rWFH6PLOIEI\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=38\&pp=iAQB)

***

## [L-4.2: Resource Allocation Graph in Deadlock | Single Instance with example | Operating System](https://www.youtube.com/watch?v=BW74JYB3QOM\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=39\&pp=iAQB)

***

## [L-4.3: Multi-Instance Resource Allocation Graph with Example | Operating System](https://www.youtube.com/watch?v=hJhB2ddOQtg\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=40\&pp=iAQB)

***

## [L-4.4: Deadlock Handling Methods and Deadlock Prevention | Operating System](https://www.youtube.com/watch?v=pPM9Ajqmy_4\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=41\&pp=iAQB)

***

## [L-4.5: Deadlock Avoidance Banker's Algorithm with Example](https://www.youtube.com/watch?v=k8BHyy6gBls\&ab_channel=GateSmashers)

* Deadlock Avoidance
* Also used for Deadlock Detection

**Example:**

There may be deadlock In future or not ?? Given the no. of resources allocated and required to each process.

3 Type of Resources = A, B, C (let CPU, Memory and Printer) 5 Processed = P1, P2, P3, P4, P5

| Total Units of Resources | A=10 | B=5 | C=7 |
| ------------------------ | ---- | --- | --- |

| Process | Resources Allocated to the Process | Resource Required/Need of process |
| ------- | ---------------------------------- | --------------------------------- |
|         | A B C                              | A B C                             |
| P1      | 0 1 0                              | 7 5 3                             |
| P2      | 2 0 0                              | 3 2 2                             |
| P3      | 3 0 2                              | 9 0 2                             |
| P4      | 2 1 1                              | 4 2 2                             |
| P5      | 0 0 2                              | 5 3 3                             |

Solution : We have To find whether

* **Safe** (No Deadlock will Occur)
* or **Unsafe**(Deadlock will occur) ??

Step 1: Calculate Remaining Need for Each Process by = (Required Need - Already Allocated)

| Process                                                                                                 | Allocation | Max Need | Remaining Need = Need - Allocated |
| ------------------------------------------------------------------------------------------------------- | ---------- | -------- | --------------------------------- |
|                                                                                                         | A B C      | A B C    | A B C                             |
| P1                                                                                                      | 0 1 0      | 7 5 3    | 7 4 3                             |
| P2                                                                                                      | 2 0 0      | 3 2 2    | 1 2 2                             |
| P3                                                                                                      | 3 0 2      | 9 0 2    | 6 0 0                             |
| P4                                                                                                      | 2 1 1      | 4 2 2    | 2 1 1                             |
| P5                                                                                                      | 0 0 2      | 5 3 3    | 5 3 1                             |
| **Total**                                                                                               | **7 2 5**  |          |                                   |
| Step 2: Find Current Available Of Resources = (Total Resources in System - Current Available Resources) |            |          |                                   |

| Process   | Allocation | Max Need | Remaining Need = Need - Allocated | Current Available = Total (10 5 7) - Total Allocated (7 2 5) |
| --------- | ---------- | -------- | --------------------------------- | ------------------------------------------------------------ |
|           | A B C      | A B C    | A B C                             | A B C                                                        |
| P1        | 0 1 0      | 7 5 3    | 7 4 3                             | 3 3 2                                                        |
| P2        | 2 0 0      | 3 2 2    | 1 2 2                             |                                                              |
| P3        | 3 0 2      | 9 0 2    | 6 0 0                             |                                                              |
| P4        | 2 1 1      | 4 2 2    | 2 1 1                             |                                                              |
| P5        | 0 0 2      | 5 3 3    | 5 3 1                             |                                                              |
| **Total** | **7 2 5**  |          |                                   |                                                              |
| Step 3:   |            |          |                                   |                                                              |

1. From P1 to P5 , Find Process that's ( Remaining Need for each resources type <= Current Availability of each Resource type).

* If none of such found, than deadlock will occur.
* P2 Requirement Could be full-filled P2✅ : (1 2 2) < (3 3 2)

2. Terminate The P2 Resource, And free its allocated Resources Current Available Resource = P2 Allocated(2 0 0) + Current = (5 3 2)

Similarly Repeat the process. P2 -> P4 -> P5 -> P1 -> P3 Final Total Resource = Initial Total Available Resources = ( 10 5 7) Safe ✅

| Process                          | Allocation | Max Need | Remaining Need = Need - Allocated | Current Available = Total (10 5 7) - Total Allocated (7 2 5) |
| -------------------------------- | ---------- | -------- | --------------------------------- | ------------------------------------------------------------ |
|                                  | A B C      | A B C    | A B C                             | A B C                                                        |
| P1                               | 0 1 0      | 7 5 3    | 7 4 3                             | 3 3 2                                                        |
| P2                               | 2 0 0      | 3 2 2    | 1 2 2                             | 5 3 2 (+ P2 Free up)                                         |
| P3                               | 3 0 2      | 9 0 2    | 6 0 0                             | 7 4 3 (+ P4 Free up)                                         |
| P4                               | 2 1 1      | 4 2 2    | 2 1 1                             | 7 4 5 (+ P5 Free up)                                         |
| P5                               | 0 0 2      | 5 3 3    | 5 3 1                             | 7 5 5 (+ P1 Free up)                                         |
| **Total**                        | **7 2 5**  |          |                                   | 10 5 7 (+ P3 Free up)                                        |
| There could be multiple sequence |            |          |                                   |                                                              |
| P2 -> P4 -> P3 -> P5 -> P1       |            |          |                                   |                                                              |
| P2 -> P4 -> P1 -> P5 -> P3       |            |          |                                   |                                                              |
| P2 -> P5 -> P3 -> P1 -> P4 etc.  |            |          |                                   |                                                              |

Note: Banker's Algorithm is not possible In real life, because Process Resource Requirement are Dynamic and at Run time. And this approach require predefined knowledge of Total, Allocated and Required Resources.

***

## [L-4.6: GATE 2018 Question on Banker's Algorithm | Deadlock avoidance | Operating System](https://youtu.be/k8BHyy6gBls)

Ques: Find If it is Safe or Not??

| Process   | Allocation | Max Need | Available |
| --------- | ---------- | -------- | --------- |
|           | E F G      | E F G    | E F G     |
| P1        | 1 0 1      | 4 3 1    | 3 3 0     |
| P2        | 1 1 2      | 2 1 4    |           |
| P3        | 1 0 3      | 1 3 3    |           |
| P4        | 2 0 0      | 5 4 1    |           |
| **Total** | **7 2 5**  |          |           |

Solution

Total Resource = Available + Allocated = (8 4 6)

| Process   | Allocation | Max Need | Remaining | Available             |
| --------- | ---------- | -------- | --------- | --------------------- |
|           | E F G      | E F G    | E F G     | E F G                 |
| P1        | 1 0 1      | 4 3 1    | 3 3 0     | 3 3 0                 |
| P2        | 1 1 2      | 2 1 4    | 1 0 2     | 4 3 1 ( + P1 Free up) |
| P3        | 1 0 3      | 1 3 3    | 0 3 0     | 5 3 4 (+ P3 Free up)  |
| P4        | 2 0 0      | 5 4 1    | 3 4 1     | 6 4 6 (+ P2 Free up)  |
| **Total** | **5 1 6**  |          |           | 8 4 6 (+ P4 Free up)  |

***

## \[L-4.7: Question Explaination on Deadlock | Operating System]\(deadlock avoidance in operating system)

#### Ques. A System is having 3 process each require 2 units of resources `R` The Minimum no. of Units of `R` such that no deadlock will occur ?

a) 3 b) 5 c) 6 d) 4

Solution

R = 6 ?

```
R = 3 Process x Each Require 2 Resouces.
P1   P2   P3
2    2    2

But Note, We have to find Minimum ❌
```

If R = 2 ?

```
P1  P2   P3
1    1       ❌ Deadlock
```

```
P1  P2   P3
 1
 1

P2 P3 (+ P1 Free)
 1
 1

P3 (+P2 Free)
 1
 1

All Free :)
But this not meen It is deadlock Free ❌
Because, After P1 Free, Its not Necessary that Resources both unit will be allocated to P2, And may stuck in Deadlock
```

R = 3?

```
P1  P2  P3
1   1    1  Deadlock ❌
```

```
P1  P2  P3
1   1
1 

P2  P3    (+P1 free)    P2  P3
1   1        or         1   1
1                       1

P3    (+P2/P3 free)   P2
1        or           1
1                     1

All Free : )
But its not necessary 2 Resource Allocated to P1 in Starting, it is one of the suitable case. but we have to find minimum that satisfy all cases ❌
```

R = 4?

```
P1    P2   P3
1     1    1
1

P2   P3  (+P1 Free)
1    1
1    1

Deadlock will Never Occur✅
```

Answer: Minimum no. of Resources so no deadlock = 4 Max no. of Resources with Deadlock = Min Resources with No deadlock - 1 = 4-1 = 3

**Ques: What is the Minimum Requirement of Resources To Prevent Deadlock. where each Processes P1, P2 and P3 with required 3 , 4 and 5 unit respectively**

```
P1    P2     P3
3      4      5
2      3      4 (Max no. of Resources with Deadlock = ∑(Each Required - 1)
       
       +1   (Min no. of Resources with No Deadlock) = ∑(Each Required - 1) +1

Minimum no. of Resources so no deadlock = 2 + 3 + 4 (+1) = 10
Max no. of Resources with Deadlock = 2+3 + 4 (+1) = 9
```

**Formula ⭐**

* if each process `P` Required same amount of Resources `R`

1. Maximum Resource Required (for Deadlock) = `P * (R-1)`
2. Minimum Resource Required (No Deadlock ) = `P * (R-1) + 1`

***

## [L-4.8: GATE 2018 Question Explaination on deadlock | Operating system](https://www.youtube.com/watch?v=6uEf_F1S-Jo\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=45\&pp=iAQB)

***
