
---


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

