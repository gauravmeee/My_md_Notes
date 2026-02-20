---
description: From Interview Bits 🏛️
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

# DBMS Important Question (PSU)

## [SJVN Executive Trainee - IT](https://solutionsadda.in/wp-content/uploads/2019/07/SJVNL_1569050019_1258O1990S2D67E1.pdf) PYQ

**\*\*Ques. State whether the following statements are true or false:**

* **Intension** - represents the number of tuples presented in a database relation (table) at any instance. ❌
* **Extension** - gives the name, structure and constraint of a database relation (table). ❌
* **Corrected:** ✅
  * **Intension** - represents the ==**structure** (schema) of a database relation== — includes name, attributes, data types, and constraints.
  * **Extension** - refers to the ==**set of tuples (rows)** in a relation== **at a particular point in time**.

**Ques. What is Inverted File Organisation ⭐⭐**

Inverted file organization is a file organization technique where separate indexes are built on secondary (non-primary) keys, and each index entry stores a list of pointers to all records having that key value.

Two files are maintained:

* **Data file** → actual records stored normally
* **Inverted index file** → key value mapped to a list of record addresses

```
Key Value → [Record Pointer 1, Record Pointer 2, ...]
```

**working**

* Choose one or more secondary attributes
* For each distinct value of the attribute, create an index entry
* Each entry points to all records containing that value
* On query, system directly follows pointers instead of scanning data file

**example**

```
Occupation index
ENG → 2, 7, 15
DOC → 1, 9
MUS → 4, 10, 21
```

**why efficient**

* Eliminates full file scan for secondary key searches
* Supports many-to-many relationships
* Multiple secondary keys can be indexed simultaneously

**advantages**

* Very fast retrieval using secondary keys
* Supports complex queries on non-primary attributes
* Good for read-heavy databases

**disadvantages**

* Extra storage for pointer lists
* Update overhead on insert/delete
* Pointer lists can become large

**why called “inverted”**

* Traditional file: record → field values
* Inverted file: field value → list of records

**\*\*Ques. Which of the following is NOT an aggregate function in SQL? \*\***

* `Round()` -> As it operates on a **single value** -> ✅ Not a Aggregate Function
* `AVG(), SUM(), MAX()` -> operate on a **set of values** and return a single result. -> ❌ Aggregate Function

**Ques. Which of the following statements is/are true about secondary index? ⭐**

* Secondary index may be created on a key field. ✅
* Secondary index may be created on non-key field. ✅
* **Because:**
  * **Secondary Index** can be built on **key** or **non-key** fields.
  * Used when the attribute is **not sorted** or is **not a primary key**.
  * Helps in speeding up **search operations** on **non-clustering** attributes.

**Indexing in DBMS ⭐**

1. **What is Indexing?**
   * Indexing is a ==**data structure technique** to efficiently access records== in a database file.
   * It ==**reduces the time complexity** of searching from **O(n) to O(log n)** ==(e.g., using B+ Trees).
2. **How Indexing Works**
   * An **index** is ==created on one or more columns.==
   * It maintains **pointers** to actual data locations (record/block addresses).
   * Think of it like a **book index**: You search via keyword and find the page quickly.
3. **Types of Indexing** ⭐
   * **A. Primary Index**
     * \==Based on **primary key**== (unique, sorted).
     * One entry per block (in sparse index).
     * **Sparse Index** → Common for primary index.
   * **B. Secondary Index**
     * Based on ==**key or non-key attributes**== (excluding the primary access path).
     * Can be **dense Index** (entry for every record).
     * \==Multiple secondary indexes possible.==
   * **C. Clustering Index**
     * Based on ==**non-key** field,== but records are **physically ordered** by this field.
     * One per table.
     * Useful for range-based queries.
   * **D. Dense Index** ⭐
     * Contains ==**entry for every record**==.
     * Faster searches, more space required.
   * **E. Sparse Index** ⭐
     * Contains ==**entry for only some records**.==
     * Used when records are **sorted**.
   * **F. Multilevel Index**
     * Index is large → Build index on index.
     * **Reduces I/O** using B-tree or B+ tree structure.
   * **G. Composite Index**
     * Index on ==**multiple columns**==.
     * E.g., `INDEX(emp_name, emp_id)`.
4. **Indexing Data Structures**

| Structure      | Used for           | Notes                                       |
| -------------- | ------------------ | ------------------------------------------- |
| **B-Tree**     | Balanced search    | Moderate search time                        |
| **B+ Tree**    | Modern DBs         | Leaf nodes store data, faster range queries |
| **Hash Index** | Exact match search | Fast lookup, but not for range queries      |

5. **Advantages**
   * **Fast data retrieval**
   * Efficient **range queries**
   * Reduces CPU and I/O cost
   * Helps in **ORDER BY**, **GROUP BY**, **JOIN** operations
6. **Disadvantages**
   * **Slower INSERT/UPDATE/DELETE** (index must be updated)
   * Requires **extra space**
   * Can degrade performance if **too many indexes**
7. **Commonly Asked Interview/Exam Questions**

**Ques. In ER Model, an identifying relationship (between weak entity and owner) is represented by:**

* **Double-lined diamond** ✅
  * Identifying relationship
* **Double-lined oval** ❌
  * Represents multivalued attribute)
* **Dashed oval** ❌
  * Represents derived attribute)

**Entity Relationship Model (Weak Entity Representation)**

* **Weak Entity:** ⭐\`
  * A **weak entity** is an ==entity that **cannot exist without** a related strong entity.==
  * It **doesn't have a primary key** of its own.
  * Relies on the **primary key of the owner entity** + its **partial key**.
  * Example : `Dependent` (like a child or spouse) cannot exist without its related `Employee`, and has no unique key of its own.
* **Identifying Relationship :**
  * A **special type of ==relationship** that connects a weak entity to its **owner== (strong entity)**.
  * Called **identifying** because it helps in identifying instances of the weak entity.
  * **Drawn using a double-lined diamond** in ER diagrams.
  * The participation of the weak entity is **always total** (shown by double line connecting to the relationship).
  * Example : `DependentOf` is the identifying relationship that links each `Dependent` to its owning `Employee`, shown with a **double-lined diamond** in ER diagram.
* **Related Special ER Symbols:**

| Symbol                 | Meaning                    |
| ---------------------- | -------------------------- |
| Double-lined rectangle | Weak Entity ⭐              |
| Double-lined diamond   | Identifying Relationship ⭐ |
| Double-lined oval      | Multivalued Attribute      |
| Dashed oval            | Derived Attribute          |

**Ques. In a database, a primary index is an `_____` file whose records are of `____` length.**

* ordered, fixed ✅
* ordered, variable ❌
* unordered, fixed ❌
* unordered, variable ❌
* **Concept:**
  * \==**Primary Index** is built on the **primary key**==, and the data file is **sorted** on that key.
  * Hence, the ==index file is also in **ordered**== form.
  * Each index entry contains a ==**fixed-length pair**: _(key, pointer)_== → making it **fixed-length**.
  * Efficient ==searching using **binary search**== is possible ==due to ordering==.

**Ques. Which of the following is used to represent "total" participation in ER diagram?**

* Double Line ✅ (Correct)
* Dashed Line ❌ (Not used in ER diagrams)
* Single Line ❌ (Represents partial participation)
* Double-lined rectangle ❌ (Represents weak entity, not participation)
* **Total Participation**: ⭐
  * Means **every record** of an entity **must be linked** to at least one record in the related entity.
  * **Example**: Every `Dependent` must be related to some `Employee`.
  * In ER diagram, it is shown by a **double line** connecting the entity to the relationship.
* **Partial Participation**:
  * Means **some records** of the entity **may or may not be linked**.
  * **Example**: Some `Employees` may not have any `Dependent`.
  * In ER diagram, it is shown by a **single line** between the entity and relationship.

**Q117. Which of the following SQL functions does NOT ignore NULL by default?**

* `COUNT()` ✅
* `MAX()` ❌
* `MIN()` ❌
* `SUM()` ❌
* **`COUNT(*)`** → **Includes** NULL values (counts all rows).
* **`COUNT(column_name)`** → **Ignores** NULLs.
* **`MAX(), MIN(), SUM()`** → Always **ignore NULLs** by default.
* To **handle NULLs** explicitly, use:

```mysql
COALESCE(column, default_value)
IFNULL(column, default_value)  -- MySQL
NVL(column, default_value)     -- Oracle
```

* **Note:** **`COUNT(*)`** is the **only standard aggregate function** that **includes NULLs**.

***

***

## Important Concepts

#### B+ Tree in DBMS

A **B+ Tree** is a **balanced m-ary search tree** used for indexing in DBMS, where **all ==actual data records are stored only at the leaf level**==, and **==internal nodes contain only keys**.==

**Properties: of B++ Tree**

1. All leaves are at **same level** (balanced tree).
2. Internal nodes store only **keys**, not actual data.
3. Leaf nodes contain **keys + data pointers**.
4. Leaf nodes are **linked** (for fast range queries).
5. Tree is always **balanced** – height is kept minimal.
6. Efficient for **sequential and random access**.

**Order of B+ Tree:**

* For **order `m`**, each internal node can have:
  * Max `m` children
  * Min `ceil(m/2)` children (except root)
  * Max `m - 1` keys
  * Min `ceil(m/2) - 1` keys

**Types of Nodes:**

* **Internal Node**: Contains only keys and pointers to children.
* **Leaf Node**: Contains keys and pointers to **data records**.
* Leaf nodes are connected using **linked list**.

**Operations:**

1. **Search(key)**:
   * Start from root, go down the tree using keys
   * At leaf node, find exact key and return data pointer
2. **Insertion(key, data)**:
   * Insert in appropriate **leaf node**
   * If leaf node is full:
     * **Split** the node and **promote** middle key to parent
     * Recursively adjust parent if needed
3. **Deletion(key)**:
   * Remove key from leaf
   * If underflow:
     * Try **borrow** from sibling
     * Else, **merge** with sibling and adjust parent
     * Repeat recursively up

**Advantages of B+ Tree:**

* **Fast search**, insert, delete: `O(log n)`
* **Efficient range queries** (due to linked leaf nodes)
* **Reduces disk I/O** (used in disk-based systems)
* Keeps data **sorted**

**Difference: B+ Tree vs B-Tree**

| Feature           | B Tree                | B+ Tree                |
| ----------------- | --------------------- | ---------------------- |
| Data Storage      | Internal + leaf nodes | Only leaf nodes        |
| Internal Nodes    | Keys + data           | Only keys              |
| Sequential Access | Slower                | Faster (linked leaves) |
| Range Queries     | Less efficient        | Very efficient         |

**Use in DBMS:**

* Used for **primary & secondary indexing**
* Used in **file systems**, **databases** (e.g., MySQL, Oracle)

***

#### B Tree in DBMS

**Definition:**

A **B Tree** is a **balanced m-ary search tree** used in DBMS for indexing and storing sorted data, where **data is stored in both internal and leaf nodes**.

**Properties:**

1. All leaves are at the **same level** (balanced).
2. A node with `n` keys has `n+1` children.
3. Keys in a node are **sorted**.
4. Every node (except root) has at least `ceil(m/2) - 1` keys.
5. Maximum `m - 1` keys and `m` children per node.
6. Supports **dynamic insertions/deletions** while maintaining balance.

**Order of B Tree:**

* For **order `m`**, each node has:
  * Max `m` children
  * Min `ceil(m/2)` children
  * Max `m-1` keys
  * Min `ceil(m/2)-1` keys (except root)

**Operations:**

1. **Search(key)**:
   * Start from root, check keys
   * If not found, follow the appropriate child pointer
   * Repeat until leaf
2. **Insertion(key, data)**:
   * Insert in correct position in a node
   * If node overflows (more than `m-1` keys):
     * **Split** node
     * **Promote** middle key to parent
     * Repeat recursively if needed
3. **Deletion(key)**:
   * If in leaf node, delete directly
   * If in internal node:
     * Replace with **in-order predecessor/successor**
   * If node underflows:
     * Try **borrowing** key from sibling
     * Else **merge** with sibling and adjust parent

**Advantages of B Tree:**

* Maintains **sorted data**
* **Balanced**: ensures `O(log n)` time
* Efficient for **insert/delete/search**
* **Minimizes disk access**, suitable for **disk-based systems**

**Difference: B Tree vs B+ Tree**

| Feature           | B Tree                | B+ Tree                        |
| ----------------- | --------------------- | ------------------------------ |
| Data Storage      | Internal + leaf nodes | Only leaf nodes                |
| Internal Nodes    | Keys + data           | Only keys                      |
| Range Queries     | Less efficient        | More efficient (linked leaves) |
| Sequential Access | Slower                | Faster                         |

**Use in DBMS:**

* Used for **indexing** where **fast search + updates** are needed
* Not as common as **B+ Tree** for range queries
