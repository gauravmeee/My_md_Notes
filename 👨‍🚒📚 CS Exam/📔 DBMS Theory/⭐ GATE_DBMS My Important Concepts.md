

### Conflict Serializability

**1. Transactions & Operations**
- Each transaction: sequence of operations: `r` (read), `w` (write)
- Data items: X, Y, …

**2. Conflict Rules**

- **Conflict occurs** if all three are true:
    1. Same data item
    2. Different transactions
    3. At least one operation is a write
- **No conflict**: r vs r on same item

**3. Steps to Check Conflict Serializability**
1. List all operations in schedule
2. Identify conflicting pairs (use rules above)
3. Draw **Precedence Graph**:
    - Nodes = transactions
    - Edge T1 → T2 if T1’s operation conflicts with T2’s **later** operation
        
4. Check graph:
    - **Cycle → Not conflict serializable**
    - **No cycle → Conflict serializable**

**4. Common Edge Patterns**
- r-w → T1 → T2
- w-r → T1 → T2
- w-w → T1 → T2
- r-r → No edge
    

**5. Example**

- **Transactions:**
    - T1: r1(X), r1(Y), w1(X)
    - T2: r2(X), r2(Y), w2(Y)
        
- **Schedule S1:** r1(X); r1(Y); r2(Y); w2(Y); w1(X)
    - Conflicts: r1(Y)-w2(Y) → T1 → T2
    - Graph: T1 → T2 → No cycle → **Serializable**
        
- **Schedule S2:** r2(X); r2(Y); w2(Y); r1(Y); w1(X)
    - Conflicts: w2(Y)-r1(Y), r2(X)-w1(X) → T2 → T1
    - Graph: T2 → T1 → No cycle → **Serializable**
        

**6. Tips for GATE**
- Focus on **conflict pairs** only, ignore same transaction conflicts
- Draw quick **graph with T1, T2, …**
- Edge direction = **first operation → second operation**
    

---
### Relational Algebra Operations

**Primitive (Basic) Operations:**
- Selection (σ)
- Projection (π)
- Cartesian Product (×)
- Union (∪)
- Set Difference (−)
- Rename (ρ)

**Derived Operations:**
- Intersection (∩)
- Join (⨝)
- Division (÷)

**Unary Operations**

| Operation  | Symbol | Purpose                          | Example                |
| ---------- | ------ | -------------------------------- | ---------------------- |
| Selection  | σ      | Select rows satisfying condition | `σ_Age>20(Student)`    |
| Projection | π      | Select specific columns          | `π_Name, Age(Student)` |
| Rename     | ρ      | Rename relation or attributes    | `ρ_Stud(Student)`      |

**Binary Operations**

| Operation         | Symbol | Purpose                                  | Example                         |
| ----------------- | ------ | ---------------------------------------- | ------------------------------- |
| Union             | ∪      | Tuples in either relation                | `Student ∪ Alumni`              |
| Set Difference    | -      | Tuples in first, not in second           | `Student - Alumni`              |
| Intersection      | ∩      | Tuples common to both                    | `Student ∩ Scholarship`         |
| Cartesian Product | ×      | All combinations of tuples               | `Student × Course`              |
| Join              | ⨝      | Combine tuples based on condition        | `Student ⨝_ID=Enroll.ID Enroll` |
| Division          | ÷      | Tuples related to all in second relation | `StudentID ÷ CourseID`          |

- **Unary:** operate on one relation
- **Binary:** operate on two relations
- **Rename (ρ)** helps in queries and avoiding conflicts.


### Tuple Relational Calculus (TRC)

| Feature             | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| Definition          | Non-procedural query language using **tuples as variables**  |
| Tuple Variable      | Represents a tuple from a relation                           |
| Syntax              | `{t `\|` P(t)}`                                              |
| Predicate           | Condition on tuple `t` (comparisons, logical operators)      |
| Operators           | AND (`∧`), OR (`∨`), NOT (`¬`), `=`, `≠`, `<`, `>`, `≤`, `≥` |
| Quantifiers         | `∃` (exists), `∀` (for all)                                  |
| Characteristics     | Non-procedural; specifies **what** to retrieve, not **how**  |
| Difference from SQL | TRC is theoretical; SQL is practical                         |
**Examples** :

1. **Find all students older than 20**  
    `{ t | Student(t) ∧ t.Age > 20 }`
    
2. **Find all students enrolled in a 4-credit course**  
    `{ t | ∃c (Course(c) ∧ t.CourseID = c.ID ∧ c.Credit = 4) }`
    
3. **Find all students with marks > 80**  
    `{ t | Student(t) ∧ t.Marks > 80 }`
    
4. **Find names of students in “DBMS” course**  
    `{ t.Name | ∃c (Course(c) ∧ t.CourseID = c.ID ∧ c.CourseName = 'DBMS') }`
    
5. **Find students who have taken all courses offered**  
    `{ s | Student(s) ∧ ∀c (Course(c) → ∃e (Enroll(e) ∧ e.StudentID = s.ID ∧ e.CourseID = c.ID)) }`

---

### **B-Tree and B+ Tree Notes for Practical DBMS Questions**

---

## **1. B-Tree**

### **Definition**

- Balanced search tree used for **dynamic indexing** in databases.
    
- Maintains **sorted data** and allows **search, insert, delete** in **O(log n)** time.
    

### **Properties**

1. All leaves appear at the **same level**.
    
2. Each node can have **at most m children** (order = m).
    
3. Each internal node has **k keys** such that `ceil(m/2)-1 ≤ k ≤ m-1`.
    
4. Keys in a node separate **subtrees**:
    
    ```
    For node keys K1 < K2 < ... < Kk:
    Child C1 < K1 < C2 < K2 < ... < Ck < Kk < Ck+1
    ```
    
5. **Root** can have **minimum 2 children** (or 1 key if leaf).
    

### **Operations**

- **Search:** Follow keys recursively → O(log n)
    
- **Insertion:** Split node if full
    
- **Deletion:** Merge or redistribute nodes
    

### **Advantages**

- Balanced → guaranteed O(log n) search
    
- Efficient for **disk storage** (minimizes disk access)
    

---

## **2. B+ Tree**

### **Definition**

- Variant of B-tree used in **databases and file systems**.
    
- **All values stored at leaf nodes**, internal nodes only store **keys for indexing**.
    

### **Properties**

1. Leaf nodes are **linked as a linked list** → efficient range queries.
    
2. Internal nodes store **keys only**, not actual records.
    
3. Order m: Internal nodes have `ceil(m/2) ≤ children ≤ m`
    
4. Leaf nodes store **d ≤ keys ≤ 2d**
    

### **Advantages over B-Tree**

- Range queries and sequential access → very fast (linked leaves)
    
- Less duplication of data in internal nodes → more keys per node → fewer levels → fewer disk I/O
    
- Insert/Delete easier to manage
    

### **Operations**

- **Search:** Follow keys from root to leaf → O(log n)
    
- **Insertion:** Split leaf if full; propagate key to parent
    
- **Deletion:** Merge or redistribute leaves; propagate changes up
    

---

### **Comparison Table**

|Feature|B-Tree|B+ Tree|
|---|---|---|
|Keys in leaf|Yes|Only pointers in internal nodes, values in leaves|
|Leaf nodes|Not linked|Linked list → fast sequential access|
|Range query|Slower|Fast|
|Tree height|Slightly taller|Slightly shorter (more keys per node)|
|Search|O(log n)|O(log n)|
|Insert/Delete|Complex|Simpler in leaves, internal nodes only updated|

---

### **Practical Tips for Solving Questions**

1. **Given order (m) and keys**, always check **min/max keys per node**.
    
2. **Insertion:**
    
    - Start from leaf → insert → split if full → propagate middle key up.
        
3. **Deletion:**
    
    - Borrow from sibling → if underflow persists → merge nodes → update parent.
        
4. **Range search in B+ Tree:**
    
    - Go to starting key leaf → traverse linked leaf nodes.
        
5. **B+ Tree usually preferred in DBMS** for indexing because of **faster range queries** and **disk I/O efficiency**.
---
---

### **Heap vs BST vs B-Tree (DBMS Practical Notes)**

---

|Feature|**Heap**|**BST (Binary Search Tree)**|**B-Tree**|
|---|---|---|---|
|**Definition**|Complete binary tree satisfying **heap property** (Max/Min)|Binary tree where **left < node < right**|Balanced m-ary search tree used for **indexing** in DBMS|
|**Purpose**|Efficient **priority queue operations**|Efficient **search, insert, delete** in memory|Efficient **disk-based search, insert, delete**|
|**Node Children**|2 (binary heap)|2|m (order of tree)|
|**Balance**|Complete binary → height ≈ log n|Not necessarily balanced → height can be n|Always balanced → height ≈ logₘ n|
|**Search**|O(n) (no ordering for arbitrary search)|O(h), h = height → worst O(n)|O(log n) guaranteed|
|**Insertion**|O(log n) (heapify up)|O(h)|O(log n)|
|**Deletion**|O(log n) (delete root, heapify)|O(h)|O(log n)|
|**Range Queries**|Not efficient|Possible but traversal required|Very efficient (leaves linked in B+ tree)|
|**Use Case**|Priority queue, scheduling|In-memory search|Database indexing, file systems|
|**Storage**|Array / in-memory|Pointer-based nodes|Disk blocks / nodes designed for I/O|

---

**Summary Notes:**

- **Heap:** Best for **priority-based retrieval**, not good for search.
    
- **BST:** Good for **in-memory search**, can degrade if unbalanced.
    
- **B-Tree/B+ Tree:** Best for **disk-based databases**, ensures **balanced structure** and **efficient search, insert, delete**, especially for large datasets.
    

---

If you want, I can make a **super-short formula-style comparison table** with **height, search, insert, delete, use-case** for quick GATE revision.

Do you want me to do that?

---

If you want, I can make a **very short one-page B-Tree & B+ Tree formula-style note** with **all practical rules + min/max keys per node + insertion/deletion steps**, perfect for solving DBMS problems quickly.

Do you want me to make that?

---
### Weak Entity Set

- **Definition:** Cannot be uniquely identified by its own attributes; depends on a **strong entity**.
- **ER Representation:**
    - Weak entity → **Double rectangle**
    - Identifying relationship → **Double diamond**
    - Partial key → **Dashed underline**
- **Participation:** **Total** (every weak entity must be related to a strong entity)

**Example:**
- **Entities:** `Department` (strong), `Employee` (weak)
- **Relationship:** `WorksIn` (identifying)    
- Each `Employee` must belong to a `Department`
- All Employees are linked → **total participation**.

---
### Indexing in DBMS

Indexing is a data structure ==technique used to quickly locate and access data== in a database table. It works like an index in a book—rather than scanning the entire table, the DBMS uses the index to find the desired record faster.

Indexes are ==created on one or more columns== of a table to ==improve retrieval speed== at the cost of additional storage and maintenance overhead.


###### **Types of Indexes (Overview)**

1. **Primary Index**
    - ==Created automatically== on the ==primary key== of a table.        
    - The index is ==based on the primary key== field, which is unique and sorted.
    - One entry per data block.

2. **Secondary Index**
    - ==Created on non-primary key attributes== to ==speed up queries==.
    - Can have duplicates.
    - Useful when searching on non-key columns.

3. **Clustered Index**
    - ==Determines the physical order of data== in the table.        
    - A table can have only one clustered index because data can be physically sorted in only one order.

4. **Non-Clustered Index**    
    - Does ==not affect the physical order of data==.
    - Contains pointers to the actual data blocks.
    - A table can have multiple non-clustered indexes.

5. **Dense Index** ⭐
    - Contains ==one index entry for every record== in the data file.
    - Provides ==faster lookups== because each record has a direct index entry.
    - Requires ==more storage space== and has ==higher maintenance cost==.        
    - Commonly used in ==secondary indexes==.

6. **Sparse Index** ⭐
    - Contains ==index entries for only some records== (typically the first record of each block).
    - Requires ==less storage space== and ==lower maintenance==.
    - Searching involves locating the correct block and then scanning it.
    - Commonly used in ==primary indexes== where data is ==sorted sequentially==.
    - **Note:** Sparse indices can be used only if the relation is stored in the sorted order of the search key. ⭐

##### **Sparse Index vs Dense Index**

| Feature              | **Dense Index**                                            | **Sparse Index**                                                                 |
| -------------------- | ---------------------------------------------------------- | -------------------------------------------------------------------------------- |
| **Index Entries**    | Contains one entry for **every record** in the data file.  | Contains entries for **some records only** (typically one per data block).       |
| **Search Speed**     | Faster—direct mapping to every record. ⭐                   | Slower—may need to search the data block after locating the closest index entry. |
| **Storage Space**    | Requires more storage space due to more index entries.     | Requires less storage space. ⭐                                                   |
| **Maintenance Cost** | Higher—each record insertion/deletion affects the index.   | Lower—only some index entries need updates.                                      |
| **Usage Scenario**   | Suitable for small datasets or frequently queried columns. | Suitable for large sequential files where data is sorted.                        |

**Note:** Typically, ==**primary indexes** are **sparse**==, and ==**secondary indexes** are **dense**==.

**Dense Index**

```
Data File (sorted on key):
+---------+---------+---------+
| Key=10  | Key=20  | Key=30  |
+---------+---------+---------+

Dense Index:
+------+---------+
| Key  | Pointer |
+------+---------+
| 10   | → Rec10 |
| 20   | → Rec20 |
| 30   | → Rec30 |
+------+---------+
```
- Every record in the data file has a corresponding entry in the index.

**Sparse Index**
```
Data File (sorted on key):
Block1: 10, 20, 30
Block2: 40, 50, 60
Block3: 70, 80, 90

Sparse Index:
+------+----------+
| Key  | Pointer  |
+------+----------+
| 10   | → Block1 |
| 40   | → Block2 |
| 70   | → Block3 |
+------+----------+
```
- Only the first key of each block appears in the index.  
- To find `Key=50`, the DBMS locates Block2 from the index and then searches within that block.

---

### Database Transaction Schedules and 


##### **Transaction**
- A **transaction** is a ==sequence of operations== performed ==as a single logical unit== of work.    
- Must satisfy **ACID properties**:
    - **Atomicity** – ==All or none== of its operations are executed.
    - **Consistency** – Database remains in a ==valid state== before and after transaction.
    - **Isolation** – Concurrent transactions do ==not interfere== with each other.
    - **Durability** – Once committed, changes are ==permanent.==
        
##### **Schedule**
- A **schedule** is an ==order in which the operations (read/write) of multiple transactions are executed==.
- **Types of Schedules:**
    1. **Serial Schedule:** Transactions are ==executed one after another== — no interleaving.
    2. **Concurrent Schedule:** Operations of ==multiple transactions are interleaved for better performance.==
        
##### **Serializability**

- A schedule is **serializable** if its effect on the database is **equivalent to a serial schedule**.    
- It ==ensures **consistency** in concurrent executions==.
    
**Types of Serializability** ⭐

1. **Conflict Serializability**
2. **View Serializability**
    
##### **Conflict Serializable Schedule**

- **Conflict**
	- Two operations **conflict** if:
		- They belong to **different transactions**,
		- Access the **same data item**, and
		- At least one is a **write** operation.
    
- **Conflict Serializability**
	- A schedule is **conflict-serializable** if it can be transformed into a serial schedule by **swapping non-conflicting operations**.
    
##### **Precedence Graph (Serialization Graph)**

- Nodes represent transactions.
- Directed edge  `Ti -> Tj` means an operation in `Ti` precedes and conflicts with an operation in `Tj`.
- **If the graph has no cycles → Schedule is conflict-serializable.**

---
### Concurrency Control

- Mechanism to control the **simultaneous execution** of transactions to preserve **isolation** and **consistency**.

**Objectives**
- Maintain ==database consistency==.
- Allow ==maximum parallelism==.
- Prevent anomalies like: ⭐
    1. **Lost Update**
    2. **Temporary Update (Dirty Read)**
    3. **Incorrect Summary**
    4 **Unrepeatable Read**

##### **Anomalies Overview**

**1. Lost Update**
- Occurs when **two or more transactions** read the same data item and update it simultaneously, causing **one update to be overwritten by another**.
- **Problem:** The final value reflects only one transaction’s update; others are lost.
- **Example:**
    ```
    T1: Read(X=100)
    T2: Read(X=100)
    T1: X = X + 50  → X=150
    T2: X = X - 30  → X=70
    ```
    Final value = 70 (T1’s update lost)
 

**2. Temporary Update (Dirty Read)**
- Occurs when a transaction **reads a data item updated by another uncommitted transaction**.
- If the updating transaction **rolls back**, the first transaction has read an **invalid (dirty)** value.
- **Problem:** Leads to **inconsistent or incorrect results**.
- **Example:**
    ```
    T1: Write(X=500)  → Not yet committed
    T2: Read(X=500)
    T1: Rollback  → X restored to old value
    ```
    T2 used a value (500) that never actually existed in the database.
    
**3. Incorrect Summary**
- Occurs when a transaction **computes an aggregate (e.g., SUM, AVG)** on data that is **being modified** by other transactions concurrently.
- **Problem:** Some updates are reflected while others are not, leading to **partial or incorrect results**.
- **Example:**
    ```
    T1: SUM(salaries) of all employees
    T2: Update salary of one employee
    ```
    If T1 reads part of the table before and part after T2’s update → incorrect total.
    
**4. Unrepeatable Read**
- Occurs when a transaction **reads the same data item twice** and **gets different values** because another transaction modified the data in between.
- **Problem:** Inconsistent view of the same data within one transaction.
- **Example:**
    ```
    T1: Read(X=100)
    T2: Write(X=200) → Commit
    T1: Read(X=200)
    ```
    T1 reads different values for X in the same execution → unrepeatable read.
##### **Concurrency Control Protocols**

1. **Lock-Based Protocols** (e.g., Two-Phase Locking)   
	- Two Phase Locking (2PL)
	- Strict Two Phase Locking (Strict 2PL)
2. **Timestamp-Based Protocols**
	- Timestamp Ordering
	- Thomas’ Write Rule

##### **1. Two-Phase Locking (2PL) Protocol**

- Transactions use **locks** to control access to data items.
- Lock types:
    - ==**Shared Lock (S)**== – For reading (multiple transactions can share).
    - ==**Exclusive Lock (X)**== – For writing (only one transaction can hold).

**Phases**
1. **Growing Phase** – Transaction **acquires locks**, cannot release any.
2. **Shrinking Phase** – Transaction **releases locks**, cannot acquire new ones.

**Properties**
- **Conflict Serializability:** Ensured.
- **No Deadlock Freedom:** Not guaranteed (deadlocks may occur).
- **No Recoverability:** Possible, but not always guaranteed — depends on lock release timing. Cascading rollbacks **can occur** if a transaction releases locks before commit.
##### **2. Strict Two-Phase Locking (Strict 2PL)**

- A stricter form of 2PL ensuring **recoverability** and avoiding **cascading rollbacks**.

**Rules**
- **All exclusive (write) locks** are held until the transaction **commits or aborts**.
- Locks are **released only after completion** of the transaction.
    
**Features:**
- **Conflict Serializability:** Guaranteed.
- **No Deadlock Freedom:** Not guaranteed (deadlocks can still occur).
- **Recoverability:** Guaranteed (no cascading rollbacks or dirty reads).
- **Strictness:** Ensures strict schedules (safe for recovery).

##### **3. Timestamp-Ordering Protocol**

- Each transaction ==**T** gets a **unique timestamp (TS(T))**== when it starts.
- The DBMS ensures that **all conflicting operations** execute in **timestamp order**.

**For Each Data Item (Q):**
- ==**read_TS(Q):**== Largest timestamp of any transaction that read Q.
- ==**write_TS(Q):**== Largest timestamp of any transaction that wrote Q.

**Rules:**
1. **Read Rule:**
    - If `TS(T) < write_TS(Q)` → **Abort T** (T is too old).
    - Else, execute read and set `read_TS(Q) = max(read_TS(Q), TS(T))`.

2. **Write Rule:**
    - If `TS(T) < read_TS(Q)` or `TS(T) < write_TS(Q)` → **Abort T**.
    - Else, perform write and set `write_TS(Q) = TS(T)`.
        
**Features:**
- **Conflict Serializability:** Ensured.
- **Deadlock Freedom:** Guaranteed (no waiting; ordered by timestamps).
- **No Recoverability:** Achieved if transactions are executed strictly in timestamp order. However, **not guaranteed by default** — requires additional mechanisms to ensure commit order consistency.
- Can cause **many aborts** due to timestamp conflicts.

##### **4. Thomas’ Write Rule** (with Timestamp-Ordering Protocol) ⭐

- A ==modification of the timestamp-ordering protocol== that allows ==**ignoring obsolete writes**==.
- If a transaction tries to **write** an item **older** than the current version, its write is **skipped** instead of aborting the transaction.
    
**Rule:**
- If `TS(T) < write_TS(Q)` → **Ignore the write** (instead of abort).

**Advantages:**
- **Serializability:** Maintained (though not strict).
- **Deadlock Freedom:** Guaranteed (same as timestamp ordering).
- **Recoverability:** Same as basic timestamp ordering — must enforce commit ordering to ensure full recoverability.
- **Improved Concurrency:** Fewer aborts, better throughput.
- **No Strictness:** Not ensured (obsolete writes may be ignored).


**Concurrency Control Protocols Comparison (Transposed)**

| **Property**                 | **Two-Phase Locking (2PL)**                                                | **Strict Two-Phase Locking (Strict 2PL)**                                                | **Timestamp Ordering (TO)**                                          | **Thomas’ Write Rule**                                                      |
| ---------------------------- | -------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- | -------------------------------------------------------------------- | --------------------------------------------------------------------------- |
| **Conflict Serializability** | ✅ Ensured                                                                  | ✅ Ensured                                                                                | ✅ Ensured                                                            | ✅ Ensured (non-strict)                                                      |
| **Recoverability**           | ❌ Conditional                                                              | ✅⭐ Guaranteed                                                                            | ❌ Conditional (depends on commit order)                              | ❌ Conditional (similar to TO)                                               |
| **Deadlock Freedom**         | ❌ Deadlocks possible                                                       | ❌ Deadlocks possible                                                                     | ✅ Deadlock-free                                                      | ✅ Deadlock-free                                                             |
| **Strictness**               | ❌ Not strict                                                               | ✅ Strict                                                                                 | ❌ Not strict                                                         | ❌ Not strict                                                                |
| **Cascading Rollback**       | ❌ Possible                                                                 | ✅ Prevented                                                                              | ✅ Prevented                                                          | ✅ Prevented                                                                 |
| **Extra Notes / Remarks**    | Basic protocol; ensures serializability but may cause cascading rollbacks. | Most used; ensures serializability + recoverability + strictness; only issue: deadlocks. | Deadlock-free but causes frequent aborts due to timestamp conflicts. | Ignores obsolete writes; improves concurrency; serializable but non-strict. |

---

### Referential Integrity Constraints (Notes)


- **Referential Integrity (RI)** ensures that a **foreign key (FK)** in one relation **must match an existing primary key (PK)** value in another relation.
- It maintains **consistency among related tables**.
    
**Key Rule**
- If relation **R2** has a **Foreign Key (FK)** referring to the **Primary Key (PK)** of relation **R1**:
- Every FK value in **R2** must either be:
    - **NULL**, or
    - **Exist as a PK** value in **R1**.

**Possible Operations and Violations** ⭐

| **Operation**           | **Effect on Referential Integrity** | **Reason**                                                                               |
| ----------------------- | ----------------------------------- | ---------------------------------------------------------------------------------------- |
| **I. INSERT into R1**   | ✅ **No violation**                  | Adding new PK values in parent table (R1) does not break RI.                             |
| **II. INSERT into R2**  | ❌ **May violate**                   | If the FK value inserted in R2 does **not exist in R1**, RI is violated.                 |
| **III. DELETE from R1** | ❌ **May violate**                   | If a PK value is deleted from R1 while it is still **referenced in R2**, RI is violated. |
| **IV. DELETE from R2**  | ✅ **No violation**                  | Removing child rows (R2) doesn’t affect references.                                      |

**May cause violation:**
- **II. INSERT into R2**
- **III. DELETE from R1**

**Handling Violations (Actions)**

- To maintain referential integrity, DBMS can take predefined actions on **DELETE/UPDATE** in parent table (**R1**):
	- **CASCADE:** Automatically delete or update matching rows in child (R2).
	- **SET NULL:** Set FK values in child to NULL.
	- **SET DEFAULT:** Set FK to a default valid value.
	- **NO ACTION / RESTRICT:** Reject the operation.
    
**Summary**
- Referential integrity ensures **consistency between related tables**.
- **Violations occur** when:
    - Inserting invalid FK in child (R2).
    - Deleting referenced PK in parent (R1).

