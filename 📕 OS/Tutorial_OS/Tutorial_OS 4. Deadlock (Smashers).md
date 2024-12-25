
A **deadlock** in operating systems is a situation where :
- a set of processes or threads are blocked because each one is waiting for a resource that another process is holding. None of the processes can proceed because they are all waiting for a condition that can never be true, leading to a "deadlock."

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


#### Key Conditions for Deadlock (Coffman’s Conditions)

1. **Mutual Exclusion**: Only one process can use the resource at any given time.
2. **Hold and Wait**: A process is holding at least one resource and is waiting for at least one resource resources.
3. **No Preemption**: Resources cannot be forcibly taken away from a process.
4. **Circular Wait**: A set of processes are waiting in a circular chain



#### Resource Allocation Graph (RAG) in Deadlock.

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
        [.]         [....]
    ex:CPU,Monitor  ex: Registers
```

```
      Edge
        |
 ┌------+------┐
 Assign       Request
 Edge         Edge

 (p)           (p)
  ↓             ↓
 [R]           [R]
```

Waiting:
1. Finite -> Starvation
2. Infinite -> Deadlock

|Scenario|Deadlock Status|
|---|---|
|Single Instance + No Circular Wait|No Deadlock|
|Single Instance + Circular Wait|Deadlock|
|Multiple Instances + Circular Wait|May or May Not Deadlock|


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

Example 2, 3, 4 Page64

#### Methods for Handling Deadlocks

1. **Deadlock Prevention**
	- Prevent the system from entering a deadlock state by ensuring that at least one of the necessary conditions for deadlock (mutual exclusion, hold and wait, no preemption, and circular wait) never occurs.
2. **Deadlock Avoidance (Banker's Algorithm)**
	- Dynamically check resource allocation to ensure the system will never enter an unsafe state (i.e., a state that could lead to deadlock).
3. Deadlock Detection & Recovery
	- Detection : Allow the system to enter a deadlock state but detect it through algorithms and then recover. Construct a wait-for graph, If a cycle exists, a deadlock has occurred.
	- Recovery: Once a deadlock is detected, recovery strategies include:
	   1. Process Termination: Abort one or more processes to break the deadlock.
	   2. Resource Preemption: Temporarily take resources away from some processes and allocate them to others to resolve the deadlock.
1. Deadlock Ignorance (Ostrich Method)
	- The system deliberately ignores the possibility of deadlock, assumes that deadlock is rare and the cost of prevention, detection, or recovery outweighs the cost of occasionally restarting the system when a deadlock occur.









### Deadlock Detection Algorithm
- Construct a **wait-for graph**, where nodes represent processes and directed edges represent dependencies between processes.
- Detect cycles in this graph. If a cycle exists, a deadlock has occurred.

### Real-World Example
Consider a system where two programs are trying to access two shared resources (like a printer and a scanner). If one program locks the printer and waits for the scanner while the other locks the scanner and waits for the printer, both will wait indefinitely—this is a deadlock situation.