
---
# OS Process Scheduling

> Made from the PDF Notes

Process Scheduling Algorithm : A way of Selecting an algorithm from ready queue & putting it on the CPU

```
	  RAM                                        UniProcessor
      *****                                         *****    
   **       **                                   **       **  
  *   READY   *  ------Scheduling Algo.------>  *   CPU    * 
   **       **                                   **       **  
      *****                                         *****  
        ^
        |
More Processes
p1, p2, ....  pn
```


If a process is taken out from ready queue or RAM and is put in running process (queue/ CPU).

Preemptive Scheduling: then we can stop the process P1 and give another process p2, and send p1 to ready queue. (It provides responsiveness)
```
       P2
        ↷ 
(Ready)   (Running)
        ⤾
        P1
```

Non-preemptive Scheduling: then P1 would be processed till its, BT(burst time), after then only new process can be introduced.
```
       P1
        ↷ 
(Ready)   (Running)
        ⤿
        P2
```


| Preemptive                           | Non-Preemptive                   |
| ------------------------------------ | -------------------------------- |
| SRTF (Shortest Remaining time first) | SJF (Shortest Job first)         |
| LRTF (Shortest Remaining time first) | LJF (Longest Job first)          |
| Round Robin                          | FCFS (First come first Serve)    |
| Priority based                       | Priority Queue                   |
|                                      | Multilevel Queue                 |
|                                      | HRRN (High response ration next) |

Arrival Time(AT) - The time at which process enters the ready Queue or stack
Burst Time(BT) - Time Required by a process to is get executed on CPU
Completion Time(CT) - The time at which Process completes its execution
Turn Around Time (TAT), Waiting Time (WT), Response Time (RT)


$Turnaround Time = Completion - Arrival Time = Burst Time + Waiting Time$
$Waiting Time = Turn around  - Burst Time$
$Response Time = The Time At Which Process Get CPU -  Arrival Time$

**Criteria of Scheduling**
AT (Arrival Time) Dependent : FCFS
BT (Burst Time) Dependent : SJF, LJF, SRTF, LRTF
TQ (Time Quantum) Dependent : Round Robin


```
Arrival Time --- process execution duration --> Completion time
(poin of time)                                  (point of time)
```


## 1. First Come First Serve (FCFS)
>Mode : Non Preemptive
Criteria : Arrival Time 

FCFS is an OS Scheduling algorithm that automatically executes queued requests and process in order of their arrival.

1. The process which requests the CPU first get the CPU allocation first
2. Managed using FIFO queue

Example:

| Process No. | Arrival Time | Burst Time |
| ----------- | ------------ | ---------- |
| P1          | 0            | 2          |
| P2          | 1            | 2          |
| P3          | 5            | 3          |
| P4          | 6            | 4          |

Solution:

| When CPU Assigned = max(AT, ACT of previous Process) | Process No. | AT  | BT  | CT = max(AT, CT of previous) + BT | TAT = CT-AT | WT=TAT-BT | RT = when CPU Assigned - AT |
| ---------------------------------------------------- | ----------- | --- | --- | --------------------------------- | ----------- | --------- | --------------------------- |
| 0                                                    | P1          | 0   | 2   | 0+2 =2                            | 2-2=0       | 2-2=0     | 0-0=0                       |
| 2                                                    | P2          | 1   | 2   | 2+2 = 4                           | 4-1=3       | 4-2=1     | 2-1=1                       |
| 5                                                    | P3          | 5   | 3   | 5+3 = 8                           | 8-5=3       | 3-3=0     | 5-5=0                       |
| 8                                                    | P4          | 6   | 4   | 8+4 = 12                          | 12-6=6      | 6-42      | 8-6=2                       |

```
Gantt Chart:
 [P1P1|P2P2|X|P3P3P3|P4P4P4P4]
0     2    4 5      8    12
       time ->
```
Note : X-> idle

Avg. TAT = 14/4
Avg. WAT = 3/4

## 2. Shortest Job First (SJF)
>Mode: Non-Preemptive
Criteria - Burst Time

SJF is an algorithm in which process having the smallest execution time is choosen for next execution

1. It can be preemptive (SJF) or non-preemptive (SRTF)
2. It reduces the waiting time for other process
3. It is a greedy Algo

Example:

| Process No. | Arrival Time | Burst Time |
| ----------- | ------------ | ---------- |
| P1          | 1            | 3          |
| P2          | 2            | 4          |
| P3          | 1            | 2          |
| P4          | 4            | 4          |
Solution:
1. Upto T=0: No one Ready

2. Upto T=1 : P1 & P3 Ready
- Execution : P3 -> P1  (BT: P3<P1)

3. Upto T= 2 : P1, P2 and P3 Ready
- Execution: P3 -> P1 -> P3

4. Upto T=4 : P1, P2, P3 and P4 Ready
- Execution: P3 -> P1 -> P3 -> P4

```
Gantt Chart:

[X|P3P3|P1P1P1|P2P2P2P2|P4P4P4P4]
0 1   3       6        10       14
```

| When CPU Assigned = max(AT, ACT of previous Process) | Process No. | AT  | BT  | CT = max(AT, CT of previous) + BT | TAT = CT-AT | WT=TAT-BT | RT = when CPU Assigned - AT |
| ---------------------------------------------------- | ----------- | --- | --- | --------------------------------- | ----------- | --------- | --------------------------- |
| 1                                                    | P3          | 1   | 2   | 1+2 =3                            | 3-1=2       | 2-2=0     | 1-1=0                       |
| 3                                                    | P1          | 1   | 3   | 3+3 = 6                           | 6-1=5       | 5-3=2     | 3-1=2                       |
| 6                                                    | P2          | 2   | 4   | 6+4 = 10                          | 10-2=8      | 8-4=4     | 10-6=4                      |
| 10                                                   | P4          | 4   | 4   | 10+4 = 14                         | 14-4=10     | 10-4=6    | 10-4=6                      |
Note: When burst time is same, see the one having less Arrival time, else can use process id.

Avg. TAT = 25/4
Avg. WAT = 12/4 = 3



## 3. Shortest Remaining Time First (SRTF)
SRTF = SJF + Preemptive
>Mode: Preemptive
>Criteria - Burst Time


Example:

| Process No. | Arrival Time | Burst Time |
| ----------- | ------------ | ---------- |
| P1          | 0            | 5          |
| P2          | 1            | 3          |
| P3          | 2            | 4          |
| P4          | 4            | 1          |
Solution:

1. Upto T = 0 : Only P1 Ready
- Execution : P1 
```
[P1]
0  1 

BT[P1]--
BT[P1]=4
```


2. Upto T = 1 : P1 & P2 Ready
- Execution : P2 -> P1 (BT: P2<P1)
```
[P1|P2]
0  1  2

BT[P2]--
BT[P2]=2
```

3. Upto T = 2 : P1, P2 and P3 Ready
- Execution : P2 -> P1->P3 (BT: P2<P1=P3)
```
[P1|P2P2P2]
0  1      4

BT[P2]-=2
BT[P2]=0 X Done
```

3. Upto T = 4 : P1, P3 and P4 Ready
- Execution : P2 -> P1->P3 (BT: P4<P1=P3)
```
[P1|P2P2P3|P4]
0  1      4  5

BT[P4]--
BT[P4]=0 X Done
```

3. Upto T = 5 : P1 and P3 Ready
- Execution :  P1->P3 (BT:P1=P3, BUT AT: P1<P3 ) Note: if BT same, AT will be prioritize
```
[P1|P2P2P3|P4|P1P1P1P1]
0  1      4  5        9

BT[P1]-=4
BT[P1]=0 X Done
```

3. Upto T = 9 : P3 Ready
- Execution :  P3
```
[P1|P2P2P2|P4|P1P1P1P1|P3P3P3P3]
0  1      4  5        9        13

BT[P3]-=4
BT[P3]=0 X Done
```

| When CPU Assigned= From Gantt Diagram | Process No. | AT  | BT            | CT = From Gantt Diagram | TAT = CT-AT | WT=TAT-BT | RT = when CPU Assigned - AT |
| ------------------------------------- | ----------- | --- | ------------- | ----------------------- | ----------- | --------- | --------------------------- |
| 0                                     | P1          | 0   | ~~5~~ ~~4~~ 0 | 9                       | 9-0=9       | 9-5=4     | 0-0=0                       |
| 1                                     | P2          | 1   | ~~3~~ 0       | 4                       | 4-1=3       | 3-3=0     | 1-1=0                       |
| 9                                     | P3          | 2   | ~~4~~ 0       | 13                      | 13-2=11     | 11-0=11   | 9-2=7                       |
| 4                                     | P4          | 4   | ~~1~~ 0       | 5                       | 5-4=1       | 1-1=0     | 4-4=0                       |
Note: When burst time is same, see the one having less Arrival time, else can use process id.

Avg. TAT = 24/4
Avg. WAT = 15/4 


## 4. Longest Job First (LJF)
>Mode: Non-Preemptive
Criteria - Burst Time

## 5. Longest Remaining Time First (LRTF)
LRTF = LJF + Preemptive
>Mode: Preemptive
>Criteria - Burst Time

## 6. Round Robin Scheduling Algorithm
>Mode: Preemptive
>Criteria - Time Quantum

Round robin is 
- preemptive process scheduling algorithm
- Each process is provided a fix time to execute, it is called quantum.
- Once a process is executed for given time period, it is preempted and other process executes for a given time period
```
        2
        ↷ 
(Ready)   (Running)
        ⤾
```

Example:

| Process No. | Arrival Time | Burst Time |
| ----------- | ------------ | ---------- |
| P1          | 0            | 5          |
| P2          | 1            | 3          |
| P3          | 2            | 4          |
| P4          | 4            | 1          |
TQ = 2

Solution:

1. Upto T = 0 : Only P1 Ready
-  Queue (AT) : P1 
- Execution : P1 x TQ
```
[P1P2]
0    2 

BT[P1]--2
BT[P1]=3
```


3. Upto T = 2 : P2 and P3 Ready
- Queue : P2 P3 P1  ( P1 push last of the queue)
```
[P1P1|P2P2]
0    2    4

BT[P2]-=2
BT[P2]=2
```

3. Upto T = 4 : P1, P3 and P4 Ready, 
- Queue :  P3 P1 P4 P2 (P2 push last of the queue)
```
[P1P1|P2P2|P3P3]
0    2    4    6

BT[P3]-=2
BT[P3]=0 X Done
```

3. Upto T = 6 : P1 and P4 Ready, 
- Queue :  P1 P4 P2 (P3 Completed)
```
[P1P1|P2P2|P3P3|P1P1]
0    2    4    6    8

BT[P1]-=2
BT[P1]=1
```

3. Upto T = 8 : P4 and P2 Ready, 
- Queue :  P4 P2 P1 (P1 Pushed at end of the queue)
```
[P1P1|P2P2|P3P3|P1P1|P4]
0    2    4    6    8  9

BT[P4]-=1 ( because only BT of 1 is remaining)
BT[P4]=0
```

3. Upto T = 9 : P2 and P1 Ready, 
- Queue :   P2 P1 (P4 Completed)
```
[P1P1|P2P2|P3P3|P1P1|P4|P2P2]
0    2    4    6    8  9    11

BT[P2]-=2
BT[P2]=0
```

3. Upto T = 11 : P1 Ready, 
- Queue :   P1 (P2 Completed)
```
[P1P1|P2P2|P3P3|P1P1|P4|P2P2|P1]
0    2    4    6    8  9   11  12

BT[P1]-=1
BT[P1]=0
```

All Completed
```
[P1P1|P2P2|P3P3|P1P1|P4|P2P2|P1]
0    2    4    6    8  9   11  12
```

| When CPU Assigned = From Gantt Diagram | Process No. | AT  | BT                  | CT = From Gantt Diagram | TAT = CT-AT | WT=TAT-BT | RT = when CPU Assigned - AT |
| -------------------------------------- | ----------- | --- | ------------------- | ----------------------- | ----------- | --------- | --------------------------- |
| 0                                      | P1          | 0   | ~~5~~ ~~3~~ ~~1~~ 0 | 12                      | 12-0=12     | 12-5=7    | 1-1=0                       |
| 2                                      | P2          | 1   | ~~4~~ ~~2~~ 0       | 11                      | 11-1=10     | 10-4=6    | 2-1=1                       |
| 4                                      | P3          | 2   | ~~2~~ 0             | 6                       | 6-2=4       | 4-2=2     | 4-2=2                       |
| 8                                      | P4          | 4   | ~~1~~ 0             | 9                       | 9-4=5       | 5-1=4     | 8-4=4                       |
Avg. TAT = 31/4
Avg. WT = 19/4