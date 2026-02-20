---
description: From Gate Smasher's Tutorials ▶️
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

# Indexing in DBMS

#### [Lec-93: Why Indexing is used | Indexing Beginning | DBMS](https://youtu.be/E--yzX05_k8)

> Indexing is a critical topic for GATE, UGC NET, competitive exams, and especially **job interviews**.

**General Architecture**

To understand the need for indexing, the instructor describes the relationship between the three main components of a computer system handling database queries.

**CPU (Processor)**

* It is Responsible for processing queries
* CPU is Extremely fast. It works in **MIPS** (Million Instructions Per Second) and operates in nanoseconds or picoseconds.

**RAM (Main Memory)**

* The CPU communicates directly with RAM, not the Hard Disk.
* Ram is a volatile memory.

**Hard Disk (Secondary Memory)**

* It is Used for permanent storage of Data because RAM is volatile (data is lost if power goes off)
* Hard Disk is Non Volatile
* **Speed:** Very slow compared to the CPU. It generally operates in milliseconds.
* **Structure:** The hard disk is divided into **Logical Blocks** (also called **Pages** in Operating System terms).

```
[ CPU ] ←→ [ RAM ] ←→ [ Hard Disk ]
```

**The Conflict:** There is a ==major speed mismatch==. The **CPU is incredibly fast**, while the **hard disk is very slow**.

* For Example: CPU speed is in **Million Instructions per second (MISP)** while Hard disk only 10-20 Instructions per second
* CPU speed is measured in ns (nano seconds or **peco seconds**) while Hard Disk is in ms (**milli seconds**)
* The **CPU cannot fetch data directly from the hard disk**, So the data must first be moved to RAM. ⭐

**Data Storage in Hard disk**

Data is Stored inside Secondary Memory For Example Records are stored in Hard disk like this

```
Hard Disk
┌──────────────┐
| 1 A 20 M ... |
| 2 N 30 F ... | Block 0
| ............ |
├──────────────┤
| ............ |
| ............ | B1
|              |
├──────────────┤
|              | B2
├──────────────┤
|              |  .
├──────────────┤
|              |  .
└──────────────┘
```

**Secondary Memory** is Divided into Blocks or **Pages** ⭐

* data is stored in blocks.
* **Total Records:** Imagine a Student Table with **10,000 records**.
* **Block Capacity:** Assume 1 block can store **100 records**.
* **Blocks Required:** To store the entire table, the system needs: $$\frac{10,000 \text{ records}}{100 \text{ records per block}} = \mathbf{100 \text{ Blocks}}$$

**4. Query Execution Without Indexing**

Lets Consider the Query

```sql
Select * from Student where Rollno = 1
```

If the data is **unordered (unsorted)** and there is no index: ⭐

1. **Fetching:** The CPU tells the RAM it needs data. **The RAM requests blocks** (Note Whole Data) from the Hard Disk.
2. **Transfer Process:**
   * The system brings **Block 1** from the Hard Disk to RAM.
   * The CPU searches the block in RAM.
   * \==If the record is found, it is a **Hit**.== If not, it is a **Miss**.
   * The block is returned/discarded, and **Block 2** is fetched. This repeats for Block 3, Block 4, etc..
3. **Worst Case:** In a **non-ordered file**, ==you might have to transfer all 100 blocks== to find the record.

**The Main Problem: I/O Cost**

* **Indexing does ==NOT reduce CPU processing== time** ⭐
  * Indexing does not reduce the time it takes to search inside a block once it is already in the RAM.
* \==**Indexing Reduces I/O Cost**==
  * The main issue is the ==cost of transferring data from the Hard Disk to RAM==, known as the **Input/Output (I/O) Cost**.
* Calling many blocks increases the I/O cost significantly because of the **propagation and transmission** time ==involved in fetching from the slow hard disk.==

**The Solution: Indexing**

The primary motive of indexing is to ==**call a lesser number of blocks**== from the hard disk to the RAM.

Lets Understand through comparing the **database to a book** ⭐

* **Scenario A (No Index):** If you need to find the topic "Indexing" in a 1,000-page book without using the index, you must flip through pages one by one.
  * _Worst case:_ You check all 1,000 pages.
  * _Average case:_ You check 500 pages.
* **Scenario B (With Index):** The index itself is only 5–6 pages.
  * You scan the index, find the page number, and go directly to that specific page.
  * You do not need to shuffle through the remaining 990+ pages.

**Conclusion**

* \==Indexing reduces the number of blocks (pages)== the system has to shuffle or transfer.
* Therefore, **Indexing reduces the I/O cost**, ==making the query retrieval process significantly faster.==

#### [Lec-94: Numerical Example on I/O Cost in Indexing | Part-1 | DBMS](https://youtu.be/P24LAhp-ap8)

#### [Lec-95: Numerical Example on I/O Cost in Indexing | Part 2 | DBMS](https://www.youtube.com/watch?v=s_S_MpLoDEM\&t=74s)

#### [Lec-96: Types Of Indexes | Most Important Video on Indexing](https://www.youtube.com/watch?v=vjrHiaIfOl8)

**Types of Indexes**

1. Primary Index
2. Clustered Index
3. Secondary Index

```
                 ┌───────────┬────────────┐
Ordered File     | Primary   |  Clustered |
                 | (Sparse)  |  (Sparse)  |
                 |───────────|────────────|
Unordered File   | Secondary |  Secondary |
                 | (Dense)   | (Dense)    |
                 └───────────┴────────────┘
                     Key         Non-Key
```

**Think it as Like** ->

* Index in Front of a Book -> Primary Index One entry → one data block (often sparse) tells you _where chapters start_ → direct navigation faster, structured access
* Index in Back of a Book -> Secondary Page One key → **multiple references** to data rows (dense) tells you _where a word appears_ → many scattered pages flexible, but needs extra lookup

#### [Lec-97: Primary Index With Example | GATE, PSU and UGC NET | DBMS](https://www.youtube.com/watch?v=4E-MGnjMhRw\&t=87s)

#### [Lec-98: Clustered Index in Database with Example](https://www.youtube.com/watch?v=UpJ9ICmzaAM\&t=30s)

**For a Index to Be Clustered**

* Search Key should be **non-key (non-unique)**
* Data should be **ordered (sorted)** according to Search Key

**Let we Search on the bases of D/No.**

* If D/No is Key
* If Data is ordered by D/No.
* Then we would use clustered Index

**Let a Department Table**

```
Dno.  Ename Pno
1      A     xxx
2      B     yyy
2      C      .
3      A      .
3      .      . 
.      .      .
```

**Index Table**

```
Index Table

DNo   Pointer
1       B1
2       B1
3       B2
4       B4
5       B5
```

**Clustered Indexing: Non-Key + Ordered**

```
    DNo Ename (Non-Key)
   ┌───────┐
   | 1 - A |<---------┐
B1 | 2 - B |<-------┐ |
   | 2 - C |        | |    Pointer, Key
   | 2 - A |        | |   ┌────┬────┐
   ├───────┤        | └---- ●  | 1  |
   | 3 -   | <--┐   └------ ●  | 2  |           
B2 | 3 -   |    └---------- ●  | 3  |
   | 3 -   |              ├────┼────┤      
   ├───────┤      ┌-------- ●  | 4  |
   | 4     |  <---┘  ┌----- ●  | 5  |
B3 | 4     |         |    | .  |    |
   | 4     |         |    ├────┼────┤
   ├───────┤ ⤸       |    ├────┼────┤
   | 4     |         |    └────┴────┘
B4 | 4     |         |      Index Table
   | 4     |         |
   ├───────┤ ⤸       |
   | 4     |  <------┘
.  | 4     |
   | 5     |  // Sparse
   | 5     |
   | 5     |
   ├───────┤
.  |       |
   └───────┘
```

**Clustered Indexing is Sparse** ⭐

* In clustered indexing, records are physically stored together based on a **non-key attribute**
* Multiple records may have the same search key value
* The index contains **only one entry per distinct search key**, not one per record
* Each index entry points to the **first block of the cluster (Block Anchor)**
* Remaining records with the same search key are stored in **subsequent blocks** and accessed sequentially
* Hence, clustered indexing is called a **sparse index**
* **`No. of Records in Index <= No. of Record in Hard Disk`**

If data for a search key does not fit in a single block and continues in the next block, we use a **Block Anchor (⤸)** or Block hanker ( by Gate Smasher).

**Block Anchor**

* Used in **cluster indexing**
* Index entry points to the **first block** of a cluster
* If records for a search key do not fit in one block\
  → they **continue in next blocks**
* These subsequent blocks are accessed **sequentially**
* \==No overflow pointer== per record (like in secondary key)

**Important Points**

* Index table keys are **unique and ordered**
* One index entry → **one cluster (group of blocks)**
* Pointer in index table is called **Block Anchor**
* Used only to locate the **starting block**

**Cost** ⭐

```
Search in index table blocks = log₂(N)
Search in data blocks = 1 + x
Total cost ≈ log₂(N) + 1 + x
```

* `N` = number of blocks in index table
* `x` = number of additional blocks in the cluster

#### [Lec-99: Secondary Index in Database with Example | Multilevel Indexing](https://www.youtube.com/watch?v=Ua08uVgsk4k)

```
Secondary Index
  ⬋       ⬊
Key       Non-Key
```

**Let the Employee Table**

```
Eid  Name  PAN
1     A    40
2     B    51
3     A    38
.     .     . 
.     .     .
```

**Query Through Key**

* here, **Employee Id (Eid)** is Primary Key
* Ex: Find Details of Employee through **Eid**
* When Query are through Eid , We will use Primary Indexing

**When we need to Query through Non Key**

* Ex: Find Details of Employee through **Name** and **PAN No.**
* We Can't use Primary Index, because its implemented on **Eid** (Key). And Non Key are Not Ordered
* In that Case We will use Secondary Index.
  1. **Key (Unique) + Unordered** : Pan No.
  2. **Non Key(Non Unique) + Unordered**: Name

**1. Secondary Indexing: Key + Unordered**

```
    Eid Name Pan No.
   ┌───────────┐
   | 1  A   40 | <------┐      Pointer, PAN Key
B1 | 2  B   51 | <------|─┐   ┌────┬────┐
   | 3  A   62 | <----┐ | └---- ●  | 51 |
   | 4  C   33 | <----|-|------ ●  | 33 |
   ├───────────┤      | | ┌---- ●  | 23 |
   | 5  A   71 | <--┐ └-|-|---- ●  | 62 |           
B2 | 6  D   82 | <-┐└---└-|---- ●  | 40 |
   | 7  E   91 | <┐└------|-┐ ├────┼────┤      
   | 8  F   23 | <|-------┘ └─- ●  | 82 |
   ├───────────┤  └------------ ●  | 91 |
   | 9  K   120| <------------- ●  | 120|
B4 | .  .    . |   // Dense     .  |  . |
   | .  .    . |              └────┴────┘
   ├───────────┤                 Index Table
.  |           |
   └───────────┘
```

**Cost for Key**

```
Search in index table blocks = log₂(N)
Search in data blocks = 1
Total cost ≈ log₂(N) + 1
```

* `N` = number of blocks in index table
* `x` = number of additional blocks in the cluster

**2. Secondary Indexing: Non-Key + Unordered** (Worst Case)

```
    Eid Name Pan No.
   ┌───────────┐                    Pointer, Name
   | 1  A   40 | <--------┐         ┌───┬───┐
B1 | 2  C   51 | <-----┐ {● ●}A<----- ● | A |  
   | 3  C   62 | <---┐ | {● |}  ┌---- ● | B |
   | 4  A   33 | <---|-|--┘ |   | ┌-- ● | C |
   ├───────────┤     | |    |   | | | . | . |
   | 5  A   71 | <---|-|----┘   | | └───┴───┘
B2 | 6  B   82 | <---|-|--┐     | |   Index Table
   | 7  C   91 | <-┐ | | {● ●}B<┘ |
   | 8  B   23 | <-|-|-|----┘     |
   ├───────────┤   | | |          |
B4 | .  .    . |   | | | {● ● ●}C<┘       
   | .  .    . |   | | └--┘ | |  // Sparse
   ├───────────┤   | └------┘ |            
.  |           |   └----------┘
   └───────────┘ // Dense
   
                    Intermediate Layers
                    (Block of Record Pointers)
```

**Intermediate Layer / Block Pointer (Record Pointer)** `{● ● ●}`

* Used in **secondary indexing**
* Holds **record pointers (block + offset)**
* Index entry points to the **exact record location**
* Data records are **unordered** on the search key
* If multiple records share the same key\
  → pointers are stored in an **intermediate layer**
* Secondary index and intermediate layer are **sparse w.r.t. distinct keys**
* Link between intermediate layer and data file is **dense**
* No **block anchor**
* No **sequential block access guarantee**
* Overall secondary indexing is considered **dense** because\
  **every record is reachable via pointers**

**Inverted File (in this context)**

* An ==**inverted file** is secondary indexing== on a ==**non-key, unordered== attribute**
*   Structure:

    ```
    Search Key → { list of record pointers }
    ```
* **Secondary Index (Non-Key + Unordered) + Intermediate Layer = Inverted File**

**One-line**\
An inverted file maps each non-key value to all records containing that value using a list of record pointers.

**Cost for Non-Key**

```
Search in index table blocks = log₂(N)
Search in Record Pointer Blocks = 1
Search in Data Blocks = 1
Total cost ≈ log₂(N) + 1 + 1
```

* `N` = number of blocks in index table
* `x` = number of additional blocks in the cluster

**Secondary Indexing is Dense** ⭐

* Secondary indexing is built on an attribute **other than the ordering key**
* Data records are **not physically ordered** on the search key
* Index contains **one entry per record**
* Each index entry stores **(search key, record pointer)**
* If search key is **unique** → one index entry per record
* If search key is **non-unique** → multiple index entries with same key
* Index entries are **sorted**, but data file is unordered
* Uses **record pointers**, not block anchors
* Hence, secondary indexing is called a **dense index**
* **`No. of Records in Index = No. of Records in Hard Disk`**

**Key Distinction**

* Cluster Index → Block Anchor
* Secondary Index → Block / Overflow Pointer
