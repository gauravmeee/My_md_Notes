
# [Lec-74: ACID Properties of a Transaction | Database Management System](https://youtu.be/-GS0OxFJsYQ)

ACID : Atomicity Consistency Isolation Durability

#### 1. Atomicity:
- Either All or None
- If any operation in a transaction fail before commit, we will roll back. Either All operation should be executed or only one.
- A failed Transaction cannot be resumed, it will be restart.

Ex: - Sending money to a bank account. if OTP failed, you need to restart from first step.

For a Transaction
```
 T1
----
R(A)
A=A-50
W(A)
R(B) x -> Roll back
R(C)
.
.
```

#### 2. Consistency

- Before transaction start and  after the transaction completed, sum of money should be same. 
- The sum of money of the receiver and sender bank account should be same.

#### 3. Isolation
- Converting Parallel Schedule to Serial Schedule (If we could, then the transaction would be consistent)
```
T1   ⇆   T2
```

#### Durability
- The changes Done through transaction should be permanent.
- Like we store data on Harddisk rather than Ram for Durability

# [Lec-80: Irrecoverable Vs Recoverable Schedules in Transactions | DBMS](https://youtu.be/g2gZKA8E1yA)


#### Classification of Schedules

When discussing transactions in DBMS, schedules are generally classified in two primary ways: 
1. **serializability** 
2. **recoverability**.

**Importance:** These two classifications are core in DBMS transactions. Serializability is the most critical concept for exam questions.

**Serializability:** Ensures a concurrent schedule is equivalent to some serial schedule, preserving consistency.

**Recoverability:** Indicates whether a schedule can be safely recovered after failures, i.e., transactions commit only after all transactions whose values they read have committed.

#### Defining an Irrecoverable Schedule

An **Irrecoverable Schedule** is a **schedule where recovery is impossible** if a transaction fails, because some other transaction has already committed using its uncommitted values.

To identify irrecoverability → check if a transaction **commits after reading uncommitted data** of another transaction that later fails.

**Example:**
```
Schedule S

 T1    | T2
-------|------
 R(A)  |
 A=A-5 |
 W(A)  |
       | R(A)
       | A=A-2
       | W(A)
       | commit
 R(B)  |
 *fail | 
```

**Initial State:** Let Database Value A=10, B=20  
- **Step 1:** T1 → R(A)=10  
- **Step 2:** T1 → A=A−5=5 (transaction-local)  
- **Step 3:** T1 → W(A)=5 (shared memory=5)  
- **Step 4:** T2 → R(A)=5  
- **Step 5:** T2 → A=A−2=3 (transaction-local)  
- **Step 6:** T2 → W(A)=3 (shared memory=3)  
- **Step 7:** T2 → commit (database A=3)  
- **Step 8:** T1 → R(B)=20  
- **Step 9:** T1 → fail → rollback required

**Rollback:** When T1 fails, atomicity requires undoing all of T1’s effects. Initial A was 10, so rollback must restore database A=10. But T2 has already committed using the uncommitted value produced by T1 (A=5). Since T1 later fails, we cannot undo T2’s commit. Hence recovery becomes impossible → irrecoverable schedule.

**Rollback:** When T1 fails, atomicity requires undoing all of T1’s effects. Initial A was 10, so rollback must restore database A=10. But T2 has already committed using the uncommitted value produced by T1 (A=5). Since T1 later fails, we cannot undo T2’s commit. Hence recovery becomes impossible → **Irrecoverable schedule.**

**Atomicity Principle:** This property dictates an =="either all or none" rule.== Either all the transaction's operations are performed, or not a single one is performed.

**Note:**  
- Read → no value change  
- Arithmetic → changes local to transaction  
- Write → updates shared memory  
- Commit → updates database

#### Why Schedule S is Irrecoverable

1. T2 reads A=5 written by T1, but T1 has not committed.
2. T2 commits using this uncommitted value, making A=3 permanent due to durability.
3. T1 then fails and rolls back, restoring A=10 as per atomicity.
4. The value A=5 that T2 relied on is invalidated.
5. T2’s committed value A=3 is now inconsistent and cannot be corrected, because a committed transaction cannot be undone safely.
- Hence the schedule is **Irrecoverable**.

**Analogy** : T2 builds on a foundation created by T1. The foundation is unapproved. When the foundation is removed later, the completed building remains but is now standing on invalid ground.

# [Lec-81: Cascading vs Cascadeless Schedule with Example | Recoverability | DBMS](https://youtu.be/Fxt1pk5LEBU)


**The five crucial concepts regarding recoverability are:**

1. Recoverable schedule -> Done
2. Irrecoverable schedule -> Done
3. **Cascading schedule**
4. **Cascadeless schedule**
5. Strict recoverable schedule

#### Cascading Schedule

The basic meaning of cascading is that **due to the occurrence of one event, multiple events are automatically occurring**.

**The Write-Read Problem (Dirty Data Read)** : A cascading schedule occurs when a transaction reads data that has been written by another transaction that has **not yet committed**.

**Example:** Let A = 100
```
 T1         |  T2  | T3   | T4
 -----------|------|------|---------
 R(A)  ~100 |      |      |
 A=A-50 ~50 |      |      |
 W(A)   ~50 | ~50  |      |
            | R(A) | ~50  |
            |      | R(A) | ~50
            |      |      | R(A)
 * fail     |      |      |
```
- T1 writes A=50 (uncommitted).
- T2, T3, T4 read the uncommitted value 50.
- T1 fails → rollback restores A=100.
- T2, T3, T4 now hold dirty data.

**Cascading Effect :** Because they read T1’s uncommitted value, T2, T3, and T4 must also be aborted hence rolled back automatically.

**Disadvantages :** Wasted work and reduced CPU efficiency, since all dependent transactions must abort.

**Analogy:** Four students are writing an exam. T1 writes an answer first, and T2, T3, T4 copy it without checking. Later T1 erases the answer. Since their work depended on T1’s erased answer, T2, T3, and T4 must erase their work too, wasting all the effort they put in.

#### Cascadeless Schedule

A cascadeless schedule avoids cascading rollbacks by **not allowing any transaction to read uncommitted data**.

**How to make a schedule cascadeless:**  If T1 writes A, no other transaction may read A until T1 commits or aborts.

**Example:**
```
  T1   |  T2    |  T3    |  T4
 ------|--------|--------|------
  R(A) |        |        |
  W(A) |        |        |
       | R(A) X |        |
       |        | R(A) X |
       |        |        | R(A) X
       
T1’s write is uncommitted, so all reads are blocked → Cascadeless.
```

```
  T1    |  T2  |  T3  |  T4
 -------|------|------|------
  R(A)  |      |      |
  W(A)  |      |      |
 commit |      |      |
        | R(A) |      |
        |      | R(A) |
        |      |      | R(A) 
        
T1 Write commited, T2, T3, T4 Read Allowed

T1 commits, so others may read → Cascadeless.
```

**Identification:**  Read after an uncommitted write → Cascading  
Read after commit → Cascadeless

**Limitation: Write-Write Problem (Lost Updation)** : Cascadeless avoids dirty reads but **does not stop a write after an uncommitted write**.

**Example:**
1. T1: R(A=100)
2. T2: R(A=100)
3. T1: W(A=90)
4. T2: W(A=80)
5. T1 fails → rollback restores A=100
    
T2’s update (80) is lost even though T2 never read dirty data.  
This is the **Lost Updation Problem**.

Strict schedules fix this by also blocking writes on uncommitted data.

**Analogy:**  Cascadeless is like allowing workers to continue only after the previous layer of work is approved. This avoids copying mistakes. But two teams may still work separately on the same area, and if one team’s work is later discarded, the other team’s work may also become invalid—leading to lost updation.

#### Strict Recoverable Schedule ⭐

A **Strict Schedule** is the strongest form of recoverability. It prevents both:

- Write-Read problem (dirty reads)
- Write-Write problem (lost updates)
    
**Rule:**  If T1 writes A, **no other transaction can read or write A** until T1 commits or aborts.

This blocks both reads and writes on uncommitted data.

**Properties:**
1. Prevents cascading rollbacks (no dirty reads).
2. Prevents lost updates (no write-after-uncommitted-write).
3. Guarantees easy and safe recovery after any failure.

**Example:**
```
   T1   |  T2
--------|------
  W(A)  |
        |  R(A) X 
        |  W(A) X
 commit |
        |  R(A)
        |  W(A)
```
T2 waits until T1 commits before any access → strict.

**Identification:**  If a transaction waits for both **read and write** until the previous writer commits → strict.

**Advantage:**  ==Most reliable schedule==; rollback never forces undoing of other committed work.

**Relation:**  Strict ⇒ Cascadeless ⇒ Recoverable.
# [Lec-82: Introduction to Serializability | Transactions Concurrency and Control | DBMS](https://youtu.be/s8QlJoL1G6w) ⭐⭐

> VVI Topic

**Serializability** determines whether a given schedule possesses the ability to become serializable. Essentially, if you are given a schedule, the goal is to determine: **Can I make that schedule serial?**.

**What is a Schedule?**
- A **schedule** is formed by gathering a collection of transactions. For instance, a schedule might contain two transactions, T1 and T2.

**The Core Problem**
- When dealing with serializability questions, you will **always** be given a **parallel schedule**, never a serial one, because a serial schedule is already serial.
- **The Goal:** The concept of serializability requires you to find a **clone** of a given parallel schedule, where that clone **must be serial**. You must check if an equivalent serial schedule exists for the parallel schedule.

**Types of Schedules :**
**1. Serial Schedules**
**2. Parallel Schedules**

#### Serial Schedules

A schedule is serial if one transaction executes and completes fully, and **after that**, the next transaction starts. ==There is **no interleaving** of operations in the middle.==

A ==**serial schedule** is already serial==, so it is pointless to ask if it can be made serializable.

**Graphical Representation (Precedence Graph) of Serial Schedules**

If we have two transactions, T1 and T2, there are two possibilities for a serial schedule:

**Possibility 1: T1 then T2**
``` 
            S
	   T1   |  T2
	--------|------
	  R(A)  |
	  W(A)  |
	        |  R(A)
	        |  W(A)
```
```
	T1 -> T2
	T1 started and finished first, and then T2 began.
```

**Possibility 2: T2 then T1**
```
            S
	   T1   |  T2
	--------|------
	        | R(A)
	        | W(A)
	  R(A)  |
	  W(A)  |
```
```
	T1 <- T2
	T2 started and finished first, and then T1 began.
```

#### Parallel Schedules

A parallel schedule is one where operations of different transactions are interleaved.

**Example:**
```
            S
	   T1   |  T2
	--------|------
	  R(A)  | 
	        | R(A)
	        | W(A)
	  W(A)  |
```

Since operations of T1 and T2 are mixed, this is a **parallel** schedule.

**Graphical Representation (Precedence Graph) of Parallel**
In a parallel schedule, tracing dependencies between T1 and T2 forms a **loop** in the precedence graph.

```
(T1) ────> (T2)
  ↑         |
  └─────────┘
  
Parallel ⇒ loop always exists.
```

#### Converting Parallel to Serial (Finding the Clone)

To check serializability, find if the parallel schedule matches one of the two serial orders.

**A. Two possible serial forms**: For two transactions T1 and T2, only two serial schedules exist:

1. **T1 → T2** (T1 finishes first, then T2)
2. **T2 → T1** (T2 finishes first, then T1)

**Possibilities for Multiple Transactions (T1, T2, T3)**

```
          S
          
  T1   |  T2  |  T3 
 ------|------|-----
       | R(A) | R(A)     
       |      | W(A)  
       | W(A) |     
  R(B) |      |    
  W(B) |      |
       | W(B) |      
```

With three transactions, the number of serial schedules is:  `3! = 6`  

The six possible serial orders are:
1. T1 → T2 → T3
2. T1 → T3 → T2
3. T2 → T3 → T1
4. T2 → T1 → T3
5. T3 → T1 → T2
6. T3 → T2 → T1

If the given parallel schedule matches any one of these, it is **serializable**.

**Methods for Checking Serializability** : To verify if a parallel schedule has a valid serial clone, two methods are used:
1. **Conflict Serializability**
2. **View Serializability**

Both determine whether the interleaved schedule is equivalent to a serial one.

**Analogy:**  A parallel schedule is like a mixed dance routine. If its final effect matches one of the possible solo sequences, it is serializable.
# [Lec-83: Conflict Equivalent Schedules with Example | Transaction concurrency and Control | DBMS](https://youtu.be/ckqDozxECp0)

**Goal of Conflict Equivalence** : Given a schedule S, we try to find another schedule S′ that is conflict equivalent to S, or check whether two given schedules S and S′ are conflict equivalent.  
Two schedules may look different, but they can still be conflict equivalent.

**Conflict vs Non-Conflict Pairs** : Operations from different transactions are checked in pairs.

```
R(A) R(A) ] Non-Conflict Pairs

R(A) W(A) ┐ 
W(A) R(A) │ Conflict Pairs
W(A) W(A) ┘

R(A) R(B) ┐
W(B) R(A) │ Non-Conflict Pairs
R(A) W(B) │
W(A) W(B) ┘
```

If the variables differ, the pair is non-conflicting.

**Why Variables Matter**

If one operation works on A and the other on B, they do not interfere.  
So R(A)–W(B), R(B)–R(A), W(A)–R(B), etc., are all non-conflict pairs.

**Method: Swapping Adjacent Non-Conflict Pairs**
Conflict equivalence is checked by swapping.
1. Look at pairs that are **adjacent**.
2. Identify if the pair is conflict or non-conflict.
3. **Swapping Rule:**
    - If the pair is **non-conflict**, we may swap them.
    - If the pair is **conflict**, no swap is allowed.

If S can be turned into S′ only through a sequence of swaps of adjacent non-conflict pairs, then S and S′ are **conflict equivalent**.

**Example 1** 

```
      S              
   T1 |  T2  
------|------ 
 R(A) |       
 W(A) |       
      | R(A)
      | W(A)
 R(B) |
      |
```

```
      S              
   T1 |  T2  
------|------ 
 R(A) |       
 W(A) |       
      | R(A)
      ⬋ W(A)
 R(B) ⬈
      |
 
 T1:R(B) & T2:W(A) are Non Conflicting -> Swap
```

```
       S              
   T1 |  T2  
------|------ 
 R(A) |       
 W(A) |       
      ⬋ R(A)
 R(B) ⬈
      | W(A)
      
T1:R(B) & T2:R(A) are Non Conflicting -> Swap
```

```
      S              
   T1 |  T2  
------|------ 
 R(A) |       
 W(A) |       
 R(B) |
      | R(A)
      | W(A)
```
(orders after swaps show all T1 ops before T2 ops)
Result: schedule is **conflict-equivalent to serial** `T1 → T2`.


**Example 2**

```
      S              
   T1 |  T2  
------|------ 
 R(A) |       
 W(A) |       
      | R(A)
 W(A) |
 R(B) | 
```

```
      S              
   T1 |  T2  
------|------ 
 R(A) |       
 W(A) |       
      ⬋ R(A)
 W(A) ⬈
 R(B) |
 
T1:W(A) & T2:R(A) are Conflict
```

```
      S              
   T1 |  T2  
------|------ 
 R(A) |       
 W(A) ⬊       
      ⬉ R(A)
 W(A) |
 R(B) | 
 
T1:W(A) & T2:R(A) are conflict
```

Therefore S is **not conflict-serializable** (cannot be transformed into any serial schedule).


**Conflict Equivalence and Serializability**

If a schedule **S** can be converted into another schedule **S'** using only adjacent **non-conflicting swaps**, then **S and S' are conflict equivalent**.  
If such an **S'** exists, it will always be a **serial schedule**, meaning all operations of one transaction appear before the other.
Thus, whenever conflict equivalence holds, **conflict serializability** also holds. This provides a direct method to test serializability through swapping.

**Analogy** : Conflict equivalence works like a sliding-block puzzle. Each operation is a block. You may slide two adjacent blocks only when the swap does not alter the final effect (non-conflict). If a swap would change the result (conflict pair), the move is prohibited.  If schedule **S** can be rearranged block by block into **S'** using only allowed swaps, the schedules are conflict equivalent.

# [Lec-84: Conflict Serializability | Precedence Graph | Transaction | DBMS](https://youtu.be/zv0ba0Iok1Y) ⭐

> Important Topic in Gate ⭐

#### Conflict Serializability

**Purpose :** To check **conflict serializability**, we build a **precedence graph** showing which transaction must come before another due to conflicts.

**Vertices** : Number of vertices = number of transactions in the schedule.  
Here we have **T1, T2, T3**.

**Conflict Pairs** : Conflicts occur only when operations are on the **same variable**.

1. **RW** (Read–Write)
2. **WR** (Write–Read)
3. **WW** (Write–Write)

If such a pair appears in order on the same data item, we draw a directed edge.

**Edge Rule :** If an operation of **`Ti`** conflicts with a **later** operation of **``Tj``**, draw:  **`Ti` → `Tj`**, This shows `Tj` depends on `Ti`.


**Precedence Graph Construction**

**Goal:** Check conflict serializability by building a directed graph from conflicts.

**Example:**
```
  T1  |  T2  | T3
 -----|------|----
 R(x) |      | 
      |      | R(y)
      |      | R(x)
      | R(y) | 
      | R(z) |
      |      | W(y)
      | W(z) |
 R(z) |      |
 W(x) |      |
 W(z) |      |
```

**Step-by-Step Conflict Detection**

**1. T1 : R(x)**
- Conflict target: W(x).
- Later W(x) only in T1 → **no edge**.

**2. T1 : R(y)**
- Conflict target: W(y).
- No later W(y) in T2/T3 before T1 ends → **no edge**.

**3. T3 : R(y)**
- Conflict target: W(y) in same T3 → **no edge**.

**4. T3 : R(x)**
- Conflict with later T1:W(x).
- **Edge: T3 → T1**.

**5. T2 : R(y)**
- Conflict with later T3:W(y).
- **Edge: T2 → T3**.

**6. T2 : R(z)**
- Conflict with later T1:W(z).
- **Edge: T2 → T1**.

**7. T3 : W(y)**
- Conflicts: R(y), W(y).
- No later R(y)/W(y) in T1/T2 → **no new edge**.

**8. T2 : W(z)**
- Conflicts: R(z), W(z).
- Later T1:R(z) exists → edge already (T2 → T1).

Remaining T1 ops conflict within T1 → ignore.


**Final Precedence Graph**
```
T3 ----→ T1
↑        ↑
└-- T2 --┘
```

Graph is **acyclic**, so schedule is **conflict serializable**.

**Equivalent Serial Order (Topological Sort)**

Indegrees:
- T2 = 0
- T3 = 1
- T1 = 2
    
Order of selection:
1. **T2** (indegree 0)
2. **T3** (becomes 0 after removing T2)
3. **T1**

**Serial Order:**
```
T2 → T3 → T1
```

This is the serial schedule equivalent to the given parallel schedule.

**Cycle Detection (Key Rule)** : A schedule is conflict serializable ==(Consistent)== iff the precedence graph has **no cycle**.
- A cycle means you can start at a node, follow directed edges, and return to the same node.
- The given edges (T2→T3, T2→T1, T3→T1) do **not** form any backward path.

Thus, the schedule is **serializable and consistent**.

```
No Loop / Acyclic
	   ↓
Conflict Serializable
       ↓
Serializable
       ↓
Consistent
```

**Interpretation** : Acyclic precedence graphs guarantee that although operations were interleaved, their effect matches some serial execution (here: **T2, T3, T1**).

# [Lec-85: Why View Serializability is Used | Introduction to View Serializability | DBMS](https://www.youtube.com/watch?v=8LKM_RWeroM)


#### Conflict Serializability Failure

The standard approach to determine if a parallel transaction schedule (S) is serializable is by checking for **Conflict Serializability**.

**Example:**
```
  T1  |  T2  | T3
 -----|------|----
 R(A) |      | 
      | W(A) | 
      |      |
 W(A) |      |
      |      | W(A)
```

**Precedence Graph**
```
┌---------┐
↓         |
T1 ----→ T2
|         |
└--→ T3 ←-┘
```

The graph immediately shows a loop (cycle) between T1 and T2: **T1 $\rightarrow$ T2 $\rightarrow$ T1**.

A cycle means conflict serializability cannot decide; the schedule becomes non-answerable under this test.

```
  Loop / Cyclic
	   ↓
  Serializable?
( Cannot be decide )
```

**The Failure:** When a loop is present, the Conflict Serializability method cannot provide an answer about whether the schedule is truly serializable or not. It becomes **"non answerable"**.

#### View Serializability: The Solution

**View Serializability** is the second method used when Conflict Serializability fails (i.e., when a loop is found). This is the primary reason why View Serializability is needed.

When conflict serializability fails, view serializability checks if the schedule matches the input–read dependencies and final writes of some serial order.

**View Equivalence:** Two schedules are **View Equivalent** if they produce the same final result, even if they do not look identical. View equivalence is achieved by checking if the schedule produces the same outcome as _some_ serial schedule.

**Example:**
```
          S
  T1  |  T2  | T3
 -----|------|----
 R(A) |      | 
      |A=A-40|
      | W(A) | 
      |      |
 W(A) |      |
      |      | W(A)
```

Convert S into a candidate serial schedule `S′`:
``` 
         S'
  T1  |  T2  | T3
 -----|------|----
 R(A) |      | 
 W(A) |      |
      | W(A) | 
      |      | W(A)
```

Let initial A = 100.

**Execution of S**
```
T1: 100
T1: R(A)=100

T2: A=A-40 → 60
T2: W(A)=60

T1: A=A-40 → 20
T1: W(A)=20

T3: A=A-20 → 0
T3: W(A)=0

Final A = 0
```

**Execution of `S′`**
```
T1: 100
T1: R(A)=100

T2: A=A-40 → 60
T2: W(A)=60

T1: A=A-40 → 20
T1: W(A)=20

T3: A=A-20 → 0
T3: W(A)=0

Final A = 0
```

Both schedules end with **A = 0**, and the final write is done by **T3** in both. Thus S and S′ are **View Equivalent**.

**Precendence Graph of `S'`**
```
    T2
  ⬈ 
T1
  ⬊ 
    T3
```
A valid serial order exists.

**Conclusion:** Since S matches the reads and final write of the serial schedule T1 → T2 → T3, it is **view serializable**.

**Hierarchy of Checks**
1. Apply Conflict Serializability.
2. If no cycle → serializable.
3. If cycle → use View Serializability.

Conflict Serializability is sufficient but not necessary. Some schedules failing conflict checks are still serializable through View Serializability, as in this example.

# [Lec-114: What is RAID? RAID 0, RAID 1, RAID 4, RAID 5, RAID 6, Nested RAID 10 Explained]

#### RAID
- Redundant Array of Independent Disks
- Also, Redundant Array of Inexpensive Disks

Redundant - Copy of Data
Array - Multiple Disks
Independent - If one fail, other will not affected
Inexpensive - Cheap Storage (Cost : Registers > Cache > Ram > Disk)
Disks - To Store Data

Why Raid ??
1. Performance (Read/Write)
2. Security (Available 24x7)

##### **RAID 0**
- Level 0
- Data Stripping
- Parallel Read and Write-> Performance Fast


```
Let Original Data A, B, C, D

break down the data and store in seperate disk

A->A1+A2
B->B1+B2
C->C1+C2
D->D1+D2
```

Divide each data into two parts and store parallelly
```
            RAID 0
            /     \
        A1          A2
        B1          B2
        C1          C2
        D1          D2
      (Disk 0)    (Disk 1)
```

##### **RAID 1**
- Level 1
- Data Mirroring
- Data Secure and Reliable
- Cost Expensive? No (We are using Inexpensive Disks)

```
            RAID 1
           /     \
         A         A
         B         B
         C         C
         D         D
      (Disk 0)    (Disk 1)
```

##### **RAID 10 or RAID 01**
- RAID + RAID 2
- Stripping & Mirroring
- Reliable and Fast Performance
- Very Useful In real life
- ex: Email Servers, Web Servers

```
                 RAID 1+0

                     RAID 0
                   /      \
             RAID 1           RAID 1      
           /   \              /    \
        A1      A1           A2     A2
        B1      B1           B2     B2
        C1      C1           C2     C2
        D1      D1           D2     D2
      (Disk 0)  (Disk 1)   (Disk 2)  (Disk 3)
```


##### **RAID 2**
- Bit Level Breaking of Data
- Raid 2 is Obsolete

##### **RAID 3**
- Slicing + Store The All data into Parity Disk
- Reliable and Secure : If a Disk Fail, Can be recover from Parity Disk
- Bottle Neck Problem: Every time write in disk, Parity Disk should also be update
- Parity Disk over Utilized Problem
- If any Parity Disk failed, Can't be recovered

```
               RAID 3
   /       /           \          \    
A1         A2         A3        Ap(1-3)
B1         B2         B3        Bp(1-3)
C1         C2         C3        Cp(1-3)
D1         D2         D3        Dp(1-3)
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3)
                                   ˄
                                  Parity Disk
```

##### **RAID 4**
- Not much changes from RAID 3
```
               RAID 4
   /        /          \        \    
A1         A2         A3        Ap
B1         B2         B3        Bp
C1         C2         C3        Cp
D1         D2         D3        Dp
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3)

```


##### **RAID 5**
- RAID 3 + Parity Distributed Among Disks
- All disks will be equally utilized
```
               RAID 5
   /        /          \        \    
A1         A2         A3        Ap
B1         B2         Bp        B3
C1         Cp         C3        C3
Dp         D2         D3        D3
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3)
```

##### **RAID 6**
- RAID 5 + 2 Parity Distribution
- If any one Parity disk failed, It could be recovered (but not 2)
```
                     RAID 6
   /        /          |       \         \   
A1         A2         A3        Ap       Aq
B1         B2         Bp        Bq       B3
C1         Cp         Cq        C2       C3
Dp         Dq         D1        D2       D3
Eq         E1         E2        E3       Ep
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3) (Disk 4)
```