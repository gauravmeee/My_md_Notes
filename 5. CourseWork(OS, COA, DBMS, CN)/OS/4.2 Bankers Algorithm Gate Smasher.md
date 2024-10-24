

# [L-4.5: Deadlock Avoidance Banker's Algorithm with Example](https://www.youtube.com/watch?v=k8BHyy6gBls&ab_channel=GateSmashers)

- Deadlock Avoidance
- Also used for Deadlock Detection


#### Example: 
There may be deadlock In future or not ??  Given the no. of resources allocated and required to each process.

3 Type of Resources = A, B, C  (let CPU, Memory and Printer)
5 Processed = P1, P2, P3, P4, P5

| Total Units of Resources | A=10 | B=5 | C=7 |
| ------------------------ | ---- | --- | --- |

| Process | Resources Allocated to the Process | Resource Required/Need of process |
| ------- | ---------------------------------- | --------------------------------- |
|         | A      B      C                    | A      B     C                    |
| P1      | 0      1       0                   | 7      5      3                   |
| P2      | 2      0       0                   | 3      2      2                   |
| P3      | 3      0       2                   | 9      0      2                   |
| P4      | 2       1      1                   | 4      2      2                   |
| P5      | 0       0      2                   | 5      3      3                   |

Solution :
We have To find whether 
- **Safe** (No Deadlock will Occur)
- or **Unsafe**(Deadlock will occur) ??

Step 1: Calculate Remaining Need for Each Process by = (Required Need - Already Allocated)

| Process   | Allocation     | Max Need  | Remaining Need = Need - Allocated |
| --------- | -------------- | --------- | --------------------------------- |
|           | A   B   C      | A   B   C | A      B      C                   |
| P1        | 0   1    0     | 7   5   3 | 7      4       3                  |
| P2        | 2   0    0     | 3   2   2 | 1      2       2                  |
| P3        | 3   0    2     | 9   0   2 | 6      0       0                  |
| P4        | 2    1   1     | 4   2   2 | 2      1       1                  |
| P5        | 0    0   2     | 5   3   3 | 5      3       1                  |
| **Total** | **7   2    5** |           |                                   |
Step 2: Find Current Available Of Resources = (Total Resources in System - Current Available Resources)

| Process   | Allocation     | Max Need  | Remaining Need = Need - Allocated | Current Available = Total (10 5 7) - Total Allocated (7 2 5) |
| --------- | -------------- | --------- | --------------------------------- | ------------------------------------------------------------ |
|           | A   B   C      | A   B   C | A      B      C                   | A      B      C                                              |
| P1        | 0   1    0     | 7   5   3 | 7      4       3                  | 3      3       2                                             |
| P2        | 2   0    0     | 3   2   2 | 1      2       2                  |                                                              |
| P3        | 3   0    2     | 9   0   2 | 6      0       0                  |                                                              |
| P4        | 2    1   1     | 4   2   2 | 2      1       1                  |                                                              |
| P5        | 0    0   2     | 5   3   3 | 5      3       1                  |                                                              |
| **Total** | **7   2    5** |           |                                   |                                                              |
Step 3: 
1. From P1 to P5 , Find Process that's ( Remaining Need for each resources type <= Current Availability of each  Resource type). 
- If none of such found, than deadlock will occur.

- P2 Requirement Could be full-filled
	P2✅ : (1 2  2) < (3 3 2)

2. Terminate The P2 Resource, And free its allocated Resources
	Current Available Resource = P2 Allocated(2 0 0) + Current = (5 3 2)

Similarly Repeat the process.
P2 -> P4 -> P5 -> P1 -> P3
Final Total Resource = Initial Total Available Resources = ( 10  5  7)
Safe ✅

| Process   | Allocation     | Max Need  | Remaining Need = Need - Allocated | Current Available = Total (10 5 7) - Total Allocated (7 2 5) |
| --------- | -------------- | --------- | --------------------------------- | ------------------------------------------------------------ |
|           | A   B   C      | A   B   C | A      B      C                   | A      B      C                                              |
| P1        | 0   1    0     | 7   5   3 | 7      4       3                  | 3      3       2                                             |
| P2        | 2   0    0     | 3   2   2 | 1      2       2                  | 5      3       2   (+ P2 Free up)                            |
| P3        | 3   0    2     | 9   0   2 | 6      0       0                  | 7      4       3  (+ P4 Free up)                             |
| P4        | 2    1   1     | 4   2   2 | 2      1       1                  | 7      4       5  (+ P5 Free up)                             |
| P5        | 0    0   2     | 5   3   3 | 5      3       1                  | 7      5       5  (+ P1 Free up)                             |
| **Total** | **7   2    5** |           |                                   | 10     5      7 (+ P3 Free up)                               |
There could be multiple sequence 
P2 -> P4 -> P3 -> P5 -> P1  
P2 -> P4 -> P1 -> P5 -> P3
P2 -> P5 -> P3 -> P1 -> P4 etc.



Note: Banker's Algorithm is not possible In real life, because Process Resource Requirement are Dynamic and at Run time. And this approach require predefined knowledge of Total,  Allocated and Required Resources.


# [L-4.6: GATE 2018 Question on Banker's Algorithm | Deadlock avoidance | Operating System](https://youtu.be/k8BHyy6gBls)


Ques: Find If it is Safe or Not??

| Process   | Allocation     | Max Need  | Available        |
| --------- | -------------- | --------- | ---------------- |
|           | E   F   G      | E   F   G | E      F      G  |
| P1        | 1   0    1     | 4   3   1 | 3      3       0 |
| P2        | 1   1    2     | 2   1   4 |                  |
| P3        | 1   0    3     | 1   3   3 |                  |
| P4        | 2   0    0     | 5   4   1 |                  |
| **Total** | **7   2    5** |           |                  |

Solution

Total Resource = Available + Allocated = (8  4  6)

| Process   | Allocation     | Max Need  | Remaining    | Available                       |
| --------- | -------------- | --------- | ------------ | ------------------------------- |
|           | E   F   G      | E   F   G | E    F    G  | E      F      G                 |
| P1        | 1   0    1     | 4   3   1 | 3    3     0 | 3      3       0                |
| P2        | 1   1    2     | 2   1   4 | 1    0     2 | 4      3      1 ( + P1 Free up) |
| P3        | 1   0    3     | 1   3   3 | 0    3     0 | 5      3      4 (+ P3 Free up)  |
| P4        | 2   0    0     | 5   4   1 | 3    4     1 | 6      4      6 (+ P2 Free up)  |
| **Total** | **5   1    6** |           |              | 8      4      6 (+ P4 Free up)  |

# [L-4.7: Question Explaination on Deadlock | Operating System](deadlock avoidance in operating system)

#### Ques. A System is having 3 process each require 2 units of resources `R` The Minimum no. of Units of `R` such that no deadlock will occur ?
 a) 3    b) 5   c) 6   d) 4

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

Answer:
Minimum no. of Resources so no deadlock = 4
Max no. of Resources with Deadlock = Min Resources with No deadlock - 1 = 4-1 = 3 


#### Ques What is the Minimum Requirement of Resources To Prevent Deadlock. where each Processes  P1, P2 and P3 with required  3 , 4 and 5 unit respectively

Answer:
```
P1    P2     P3
3      4      5
2      3      4 (Max no. of Resources with Deadlock = ∑(Each Required - 1)
       
       +1   (Min no. of Resources with No Deadlock) = ∑(Each Required - 1) +1

```

Answer 
Minimum no. of Resources so no deadlock = 2 + 3 + 4 (+1) = 10
Max no. of Resources with Deadlock = 2+3 + 4 (+1) = 9





### Formula 
- if  each process `P` Required same amount of Resources `R`
1. Maximum Resource Required (for Deadlock) = `P * (R-1)`
2. Minimum Resource Required (No Deadlock ) = `P * (R-1) + 1`
