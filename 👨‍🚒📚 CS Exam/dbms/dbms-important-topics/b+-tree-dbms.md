---
description: Made By Me 💚
icon: dot
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

# B+ Tree in DBMS

B+ Tree – Question Oriented Notes (Improved & Corrected)

What is B+ Tree?\
B+ Tree is a height-balanced multi-level indexing data structure used in DBMS for efficient disk-based storage and retrieval. It is a variant of B-Tree where all actual data pointers (record pointers) are stored only at the leaf level, while internal nodes store only keys for navigation.

Why B+ Tree is used in DBMS?\
Databases reside on secondary storage where disk I/O is costly. B+ Tree reduces disk I/O by:

* Very high fanout (many children per node)
* Very small height
* Efficient equality and range queries due to sorted leaves

Basic Properties (Very Important)\
All keys are stored in sorted order\
All leaf nodes are at the same level (height-balanced)\
Internal nodes contain only keys and child pointers\
Leaf nodes contain keys and record pointers\
Leaf nodes are linked sequentially\
High fanout results in low tree height

Structure of B+ Tree (Frequently Asked)

Root Node\
Topmost node of the tree\
Contains keys and child pointers\
Can act as a leaf if the tree has only one node\
Minimum children: 2 (unless it is a leaf)

Internal Nodes\
Contain search keys and child pointers\
Do not contain record pointers\
Used only for guiding the search\
Keys act as separator values

Leaf Nodes\
Contain search keys and record pointers (or data block pointers)\
All actual data references are stored only at leaf level\
Leaf nodes are connected using next pointers\
Support sequential access and range queries

Diagram (Logical Structure)

```
       [ 20 | 40 ]
      /     |      \
 [5|10]  [20|30]  [40|50|60]
```

All leaf nodes are linked:\
\[5|10] → \[20|30] → \[40|50|60]

Order of B+ Tree\
Order (m) = maximum number of children of an internal node\
Maximum children = m\
Maximum keys in internal node = m − 1\
Minimum children (except root) = ceil(m / 2)\
Minimum keys = ceil(m / 2) − 1

Node Size and Capacity (Numerical Questions)\
Each node fits in exactly one disk block\
Block size = B bytes\
Key size = K bytes\
Pointer size = P bytes

Internal Node Entry\
Contains key + child pointer

Internal Node Size Constraint\
p pointers, each = P bytes\
(p − 1) keys, each = K bytes

Size condition:\
p·P + (p − 1)·K ≤ B

Maximum pointers (fanout) = maximum p satisfying constraint\
Maximum keys = p − 1

Leaf Node Entry\
Key + record pointer (Pr)

Leaf Node Capacity\
Maximum entries = floor(B / (K + Pr))

Fanout (Very Important for Numericals)\
Fanout = number of children of an internal node\
Determines height of the tree\
Higher fanout ⇒ smaller height ⇒ fewer disk accesses\
Depends on block size, key size, pointer size

Height of B+ Tree (Numerical + Theory)\
Height = number of index levels from root to leaf

If R = number of records\
Leaf capacity = L

Number of leaf nodes ≈ ceil(R / L)

If fanout = f\
Height ≈ ⌈log\_f (number of leaf nodes)⌉

Search Operation (Common Question)\
Start from root\
At each internal node, compare keys\
Follow the appropriate child pointer\
Reach leaf node\
Access record using record pointer

Search Example\
Search key = 35\
Root \[20|40] → middle child\
Leaf \[20|30] → key not found

Disk Access Cost (Very Important)\
Each index level requires one disk access\
Accessing data block requires one disk access

Total Disk Accesses = Height + 1

Example\
Height = 3\
Total disk accesses = 3 (index) + 1 (data) = 4

Insertion in B+ Tree\
Find appropriate leaf node\
Insert key in sorted order\
If no overflow, stop\
If overflow occurs:

* Split the leaf node
* Copy first key of new right leaf to parent
* Maintain leaf-level linked list\
  Splitting may propagate upward\
  If root splits, create a new root

Insertion Example\
Leaf capacity = 3\
Insert: 10, 20, 30, 40\
Overflow after 40\
Split into \[10|20] and \[30|40]\
Promoted key = 30

Deletion in B+ Tree\
Delete key from leaf\
If node has minimum required keys, stop\
If underflow occurs:

* Try redistribution from sibling
* Else merge with sibling\
  Update parent separator keys\
  May propagate upward\
  Tree remains height-balanced

Ordered Index vs Clustered Index (Conceptual Trap)

Ordered Index\
Keys are stored in sorted order\
Supports range queries\
Can be primary or secondary\
All B+ Trees are ordered indexes

Clustered Index\
Data records stored in same order as index keys\
Leaf nodes store actual data records\
Only one clustered index per table

Primary Index vs Secondary Index

Primary Index\
Index on primary key\
Usually implemented as clustered B+ Tree\
Leaf nodes contain actual data records

Secondary Index\
Index on non-primary key\
Implemented as non-clustered B+ Tree\
Leaf nodes contain key–record pointer pairs\
Multiple secondary indexes allowed

Important Clarification (Very Important)\
B+ Tree does not imply clustered index\
B+ Tree only ensures sorted keys\
Clustered or non-clustered depends on leaf node contents

Advantages of B+ Tree\
Always balanced\
Low height due to high fanout\
Minimizes disk I/O\
Efficient point and range queries\
Fast sequential access\
Standard indexing structure in DBMS

Disadvantages of B+ Tree\
Insertion and deletion are complex\
Extra space overhead due to pointers\
Frequent updates are costly compared to static indexes

Exam Tips\
Numericals mostly depend on fanout and height\
Always compute node capacity first\
Height questions use log base fanout\
Disk access questions usually = height + 1\
Ordered index ≠ clustered index

**Ques Consider a database implemented using B+ tree for file indexing and installed on a disk drive with block size of 4KB . The size of search key is 12 bytes and the size of tree/disk pointer is 8 bytes . Assume that the database has one million records. Also assume that no node of the B+ tree and no records are present initially in main memory. Consider that each record fits into one disk block. The minimum number of disk accesses required to retrieve any record in the database is `__________`**

**Solution:**

* Block size = 4096 bytes
* One index entry = 12 (key) + 8 (pointer) = 20 bytes
* Entries per node ≈ 4096 / 20 ≈ 204 → fanout ≈ 204
* Leaf entries = 1,000,000 → leaf nodes ≈ 1,000,000 / 204 ≈ 4902
* 204² = 41616 > 4902 → tree height = 3 (root + internal + leaf)
* Disk accesses: root (1) + internal (1) + leaf (1) + data block (1)
* Minimum disk accesses = 4

**Explanation** Think of a **B+ tree** as a multilevel index kept on disk. To find a record, the database starts from the **root node**, then goes down level by level until it reaches a **leaf node**, and finally accesses the **data block** that contains the actual record. Each of these steps needs **one disk access**, because initially nothing is in main memory.

Each node of the B+ tree must fit inside one disk block of size **4096 bytes**. Every entry in an index node consists of a **search key (12 bytes)** and a **pointer (8 bytes)**, so one entry takes **20 bytes**. This means one B+ tree node can store about **4096 / 20 ≈ 204 entries**. Hence, from any node, the tree can branch to roughly **204 child nodes**. This is called the **fanout** of the tree.

The database has **1,000,000 records**, and each leaf entry can point to only one record. Since each leaf node can hold about **204 entries**, the total number of leaf nodes required is **1,000,000 / 204 ≈ 4902** leaf blocks. Now, starting from the root, one level of pointers can reach **204** nodes, and two levels can reach **204 × 204 = 41616** nodes, which is already more than the required **4902 leaf nodes**. So the B+ tree needs **three levels** in total: the root, one internal level, and the leaf level.

To retrieve a record, the database performs one disk access for the **root**, one for the **internal node**, and one for the **leaf node**. After reaching the leaf, one more disk access is needed to fetch the **actual data block**, because the record itself is stored separately. Therefore, the **minimum number of disk accesses** required is **4**.
