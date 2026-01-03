
# Database Management System

|     | Topics                 | Subtopics                     |
| --- | ---------------------- | ----------------------------- |
| 1   | Architecture           | 3-level architecture          |
| 2   | Query Languages        | SQL, relational algebra       |
| 3   | Database Design        | ER modeling, normalization    |
| 4   | Query Processing       | Optimization and execution    |
| 5   | Storage Strategies     | Indexing, hashing             |
| 6   | Transaction Processing | ACID, concurrency             |
| 7   | Security               | Access control and encryption |
| 8   | SQL Commands           | DDL, DML, DCL, DQL, TCL       |
# 1. Database System Architecture

## 1. Database System Environment

A **Database System** consists of the following components:

- **Hardware:** Physical devices (CPU, memory, storage).
    
- **Software:** DBMS software and related utilities.
    
- **Data:** The actual information stored in the database.
    
- **Users:** DBA, Application Programmers, End Users.
    
- **Procedures:** Instructions and rules for database use and maintenance.
    

## 2. DBMS Architecture Types

### a) **1-Tier Architecture**

- Database and client on the same machine.
    
- Direct access to the database.
    
- Mainly used for development and testing.
    

### b) **2-Tier Architecture**

- Client communicates directly with the database server.
    
- Application logic resides on the client side.
    
- Example: Traditional client-server systems using JDBC/ODBC.
    
- Drawback: Poor scalability.
    

### c) **3-Tier Architecture**

- **Presentation Layer (Client):** User Interface.
    
- **Application Layer (Server):** Business logic and DB access APIs.
    
- **Database Layer (Server):** Data storage and management.
    
- Advantages: Scalability, Security, Modularity, Easier maintenance.
    

## 3. DBMS Components

### a) **Storage Manager**

- Interface between **low-level data** and **applications**.
    
- Components:
    
    - **Authorization & Integrity Manager**
        
    - **Transaction Manager**
        
    - **File Manager**
        
    - **Buffer Manager**
        

### b) **Query Processor**

- Interprets and executes user queries.
    
- Components:
    
    - **DDL Interpreter:** Handles schema definitions.
        
    - **DML Compiler:** Translates DML statements into query plans.
        
    - **Query Optimizer:** Chooses efficient execution strategies.
        

### c) **Database Manager (Runtime System)**

- Executes query plans and manages concurrent transactions.
    

## 4. Data Independence

- **Logical Data Independence:** Ability to change logical schema without affecting application programs.
    
- **Physical Data Independence:** Ability to change physical storage without affecting logical schema.
    

## 5. Three-Level Architecture (ANSI/SPARC Model)

- **External Level:** User views (subschemas).
    
- **Conceptual Level:** Logical structure of the entire database.
    
- **Internal Level:** Physical data storage details.
    
- Goal: Achieve data abstraction and independence.
    

## 6. Data Abstraction Levels

- **Physical Level:** How data is stored.
    
- **Logical Level:** What data is stored and relationships.
    
- **View Level:** How data is presented to users.
    

## 7. Data Models (Used within Architecture)

- **Hierarchical Model**
    
- **Network Model**
    
- **Relational Model**
    
- **Object-Oriented Model**


---
---


# 2. Relational Query Languages, Relational Database Design, Query

## 1. Relational Query Languages

Languages used to manipulate and retrieve data from relational databases.

### a) **Relational Algebra (Procedural)**

Defines operations to retrieve desired data.  
**Basic Operations:**

- **SELECT (σ):** Filters rows → σ(condition)(Relation)
    
- **PROJECT (π):** Selects specific columns → π(attributes)(Relation)
    
- **UNION (∪):** Combines tuples from two relations
    
- **SET DIFFERENCE (−):** Tuples in one relation but not in another
    
- **CARTESIAN PRODUCT (×):** Combines tuples of two relations
    
- **RENAME (ρ):** Renames relation or attributes
    

**Derived Operations:**

- **JOIN (⨝):** Combines related tuples based on a condition
    
- **INTERSECTION (∩)**
    
- **DIVISION (÷)**
    

### b) **Tuple Relational Calculus (TRC) – Non-Procedural**

Specifies _what_ to retrieve, not _how_.  
Form: `{t | P(t)}`  
Example: `{t | t ∈ STUDENT ∧ t.Branch = 'CSE'}`

### c) **Domain Relational Calculus (DRC)**

Based on domain variables.  
Form: `{<x1, x2, ... xn> | P(x1, x2, ... xn)}`  
Example: `{<sname> | ∃ sid, branch (STUDENT(sid, sname, branch) ∧ branch='CSE')}`

### d) **Structured Query Language (SQL)**

Declarative standard language for RDBMS.

- **DDL (Data Definition Language):** CREATE, ALTER, DROP
    
- **DML (Data Manipulation Language):** SELECT, INSERT, UPDATE, DELETE
    
- **DCL (Data Control Language):** GRANT, REVOKE
    
- **TCL (Transaction Control Language):** COMMIT, ROLLBACK, SAVEPOINT
    

---

## 2. Relational Database Design

### a) **Functional Dependency (FD)**

If two tuples have same value for attribute X, they must have same value for attribute Y.  
`X → Y` (X determines Y)

### b) **Keys**

- **Candidate Key:** Minimal attribute set uniquely identifying tuples.
    
- **Primary Key:** Chosen candidate key.
    
- **Super Key:** Any superset of a candidate key.
    
- **Foreign Key:** Attribute referencing primary key of another table.
    

### c) **Normalization**

Process to eliminate redundancy and anomalies.

- **1NF:** Atomic values only.
    
- **2NF:** 1NF + No partial dependency (on part of composite key).
    
- **3NF:** 2NF + No transitive dependency.
    
- **BCNF:** For every FD X→Y, X must be a super key.
    
- **4NF:** No multivalued dependency.
    
- **5NF:** No join dependency.
    

**Goal:** Reduce redundancy, ensure data integrity, simplify updates.

### d) **Denormalization**

Intentional introduction of redundancy for performance improvement.

---

## 3. Query (SQL)

### a) **Basic SELECT**

```sql
SELECT name, branch FROM student WHERE marks > 75;
```

### b) **Aggregate Functions**

```sql
SELECT COUNT(*), AVG(salary), MAX(age) FROM employee;
```

### c) **GROUP BY and HAVING**

```sql
SELECT dept, AVG(salary)
FROM employee
GROUP BY dept
HAVING AVG(salary) > 50000;
```

### d) **JOIN**

```sql
SELECT e.name, d.dept_name
FROM employee e JOIN department d ON e.dept_id = d.id;
```

### e) **Subquery**

```sql
SELECT name FROM student
WHERE marks > (SELECT AVG(marks) FROM student);
```

### f) **Set Operations**

```sql
SELECT name FROM student_CSE
UNION
SELECT name FROM student_ECE;
```


---
---

# 3. Processing and Optimization

## 1. Query Processing

Converting a **high-level query (SQL)** into an **efficient low-level execution plan**.

### Steps:

1. **Parsing and Translation**
    
    - SQL query → internal representation (query tree / relational algebra).
        
    - Syntax and semantic checks performed.
        
2. **Optimization**
    
    - Query tree transformed into equivalent but more efficient forms.
        
    - Choice of algorithms and access paths optimized.
        
3. **Evaluation (Execution)**
    
    - Optimized query plan executed using physical operators (joins, scans, sorting).
        

---

## 2. Query Optimization

### a) **Definition**

Process of finding the **most efficient query execution plan (QEP)** among alternatives that produce the same result.

### b) **Types**

- **Heuristic Optimization:**  
    Uses rule-based transformations (simpler, faster).
    
- **Cost-Based Optimization:**  
    Estimates cost of each plan (I/O, CPU, memory) and selects the cheapest.
    

### c) **Cost Components**

- **Disk I/O cost:** Reading/writing pages.
    
- **CPU cost:** Comparisons, sorting, joins.
    
- **Communication cost:** Data transfer in distributed DBs.
    

---

## 3. Heuristic Query Optimization

Applies transformation rules to minimize cost before actual execution.

**Common Heuristics:**

1. Perform **selection (σ)** as early as possible.
    
2. Perform **projection (π)** early to reduce tuple size.
    
3. Combine **cascaded selections** into one.
    
4. Replace **cartesian product + selection** with **join**.
    
5. Reorder **joins** for smaller intermediate results.
    
6. Push selections/projections down the query tree.
    

---

## 4. Cost-Based Optimization

- Generates multiple **logical and physical query plans**.
    
- Estimates their **execution cost** using database statistics.
    
- Chooses plan with **minimum estimated cost**.
    

**Example Metrics:**

- Number of disk accesses.
    
- Size of intermediate results.
    
- Available indexes and join algorithms.
    

---

## 5. Query Execution Plan (QEP)

A **tree structure** showing sequence of operations.

- **Logical Plan:** Algebraic representation.
    
- **Physical Plan:** Specifies algorithms (e.g., nested-loop join, hash join).  
    Chosen by the optimizer.
    

---

## 6. Query Execution Techniques

### a) **Selection**

- Linear search
    
- Binary search (if ordered)
    
- Index scan
    

### b) **Join Algorithms**

- Nested Loop Join
    
- Sort-Merge Join
    
- Hash Join
    

### c) **Sorting**

- External merge sort for large datasets.
    

### d) **Projection**

- Remove unwanted columns.
    
- Eliminate duplicates using sorting or hashing.
    

---

## 7. Database Statistics (for Optimization)

- Relation cardinality (number of tuples)
    
- Attribute cardinality (distinct values)
    
- Index availability
    
- Tuple and page size
    

---

## 8. Goal of Optimization

- Minimize query response time.
    
- Minimize disk I/O and resource usage.
    
- Improve concurrency and throughput.

---
---

# 4. Storage Strategies

## 1. Overview

Storage strategy defines **how data is physically stored, organized, and accessed** in a database to ensure efficiency, reliability, and fast retrieval.

---

## 2. Storage Hierarchy

1. **Primary Storage:**
    
    - Volatile memory (RAM, cache).
        
    - Fast access, temporary data during processing.
        
2. **Secondary Storage:**
    
    - Non-volatile (HDD, SSD).
        
    - Stores database files permanently.
        
3. **Tertiary Storage:**
    
    - Backup devices (magnetic tapes, optical disks).
        
    - Used for archival and recovery.
        

---

## 3. Storage Structure in DBMS

- **Database Files:** Store data, indexes, and metadata.
    
- **Pages (Blocks):** Fixed-size units of data transfer between disk and memory.
    
- **Records:** Collection of related fields stored within pages.
    
- **Fields:** Smallest unit of data (attributes).
    

---

## 4. File Organization

Defines how records are physically arranged on storage.

### a) **Heap (Unordered) File Organization**

- Records stored in random order.
    
- Insertion is fast, searching is slow.
    
- Suitable for small datasets or bulk loads.
    

### b) **Sequential File Organization**

- Records stored in sorted order based on key field.
    
- Efficient for range queries and sequential access.
    
- Update/insertion expensive due to reordering.
    

### c) **Hashing File Organization**

- Hash function maps key to data block.
    
- Direct access possible.
    
- Efficient for equality searches, poor for range queries.
    

---

## 5. Indexing Strategies

Indexes speed up data retrieval.

### a) **Primary Index:**

- Built on sorted data file’s primary key.
    
- Ordered index (sparse or dense).
    

### b) **Secondary Index:**

- Built on non-key or unsorted attributes.
    
- Usually dense.
    

### c) **Clustering Index:**

- Index on non-key attribute that groups similar records.
    

### d) **Multilevel Index:**

- Hierarchical index structure (index of indexes).
    

### e) **B+ Tree Index:**

- Balanced tree structure.
    
- Efficient for both range and equality queries.
    
- Widely used in modern DBMS.
    

### f) **Hash Index:**

- Uses hash function to locate data blocks quickly.
    
- Best for equality lookups.
    

---

## 6. Data Access Methods

- **Sequential Access:** Record-by-record in order.
    
- **Direct (Random) Access:** Jump directly using address or index.
    
- **Indexed Sequential Access (ISAM):** Combines both for flexibility.
    

---

## 7. Buffer Management

- **Buffer Pool:** Part of main memory used for temporary storage of pages.
    
- **Replacement Policies:**
    
    - LRU (Least Recently Used)
        
    - MRU (Most Recently Used)
        
    - FIFO (First In First Out)
        

Goal: Minimize disk I/O by caching frequently used pages.

---

## 8. Storage Optimization Techniques

- **Compression:** Reduce data size for faster I/O.
    
- **Partitioning:** Divide large tables into smaller parts.
    
- **Replication:** Store copies for faster access and fault tolerance.
    
- **Caching:** Store frequently accessed data in memory.
    
- **Use of SSDs:** Improve random access and throughput.
    

---

## 9. RAID (Redundant Array of Independent Disks)

Technique for reliability and performance improvement.

- **RAID 0:** Striping (performance)
    
- **RAID 1:** Mirroring (redundancy)
    
- **RAID 5:** Block-level striping with parity
    
- **RAID 10:** Combination of mirroring + striping
    

---

## 10. Goals of Efficient Storage Strategy

- Fast data retrieval
    
- Reduced redundancy
    
- Optimal disk utilization
    
- Reliable recovery and fault tolerance
    



---
---


# 5. Transaction Processing

## 1. Definition

A **transaction** is a sequence of operations performed as a single logical unit of work, transforming a consistent database state into another consistent state.

---

## 2. ACID Properties

Ensure reliability and correctness of transactions.

- **Atomicity:** Transaction is all or nothing.
    
- **Consistency:** Preserves database integrity constraints.
    
- **Isolation:** Concurrent transactions should not interfere.
    
- **Durability:** Once committed, changes persist even after failure.
    

---

## 3. Transaction States

1. **Active:** Executing operations.
    
2. **Partially Committed:** After last statement, before commit.
    
3. **Committed:** All changes made permanent.
    
4. **Failed:** Error encountered.
    
5. **Aborted:** Rolled back to previous consistent state.
    

---

## 4. Schedules and Serializability

### a) **Schedule:**

Order of operations from multiple transactions.

### b) **Serial Schedule:**

Transactions executed sequentially (no interleaving).

### c) **Concurrent Schedule:**

Operations interleaved for better throughput.

### d) **Serializability:**

Ensures that the effect of concurrent execution equals some serial schedule.

**Types:**

- **Conflict Serializability:** Based on operation conflicts (read/write).
    
- **View Serializability:** Based on data dependency and read-from relations.
    

---

## 5. Conflicting Operations

Two operations conflict if:

- They belong to different transactions,
    
- Access the same data item, and
    
- At least one is a write.
    

Conflicts: **Read–Write, Write–Read, Write–Write**

---

## 6. Concurrency Control

Ensures isolation while allowing safe concurrent execution.

### a) **Lock-Based Protocols**

- **Binary Lock:** Locked / Unlocked state.
    
- **Shared (S) Lock:** Read only.
    
- **Exclusive (X) Lock:** Read + Write.
    
- **Two-Phase Locking (2PL):**
    
    - **Growing Phase:** Acquire locks.
        
    - **Shrinking Phase:** Release locks.  
        Ensures serializability but may cause deadlocks.
        

### b) **Timestamp-Based Protocols**

- Each transaction gets a unique timestamp.
    
- Ensures execution in timestamp order.
    
- Uses ReadTS and WriteTS to check validity.
    

### c) **Optimistic Concurrency Control**

- Transactions execute without locks; validation done at commit time.
    
- Suitable for low-conflict environments.
    

### d) **Multiversion Concurrency Control (MVCC)**

- Maintains multiple versions of data items for concurrent reads and writes.
    
- Used in PostgreSQL, Oracle, etc.
    

---

## 7. Deadlock Handling

Occurs when transactions wait indefinitely for each other’s locks.

**Methods:**

- **Deadlock Prevention:** Ordering resource requests.
    
- **Deadlock Detection:** Wait-for graph.
    
- **Deadlock Recovery:** Abort and restart one transaction.
    

---

## 8. Transaction Recovery

### a) **Failure Types**

- Transaction failure (logical error)
    
- System crash (power failure)
    
- Media failure (disk damage)
    

### b) **Recovery Techniques**

- **Immediate Update:** Changes written before commit; undo needed.
    
- **Deferred Update:** Changes written after commit; redo only.
    

### c) **Log-Based Recovery**

Maintain a log of operations.  
Each log record:  
`<Transaction-ID, Data-item, Old-value, New-value>`

**Operations:**

- **UNDO:** Restore old value.
    
- **REDO:** Reapply new value.
    

### d) **Checkpointing**

- Periodically saves database and log state.
    
- Reduces recovery time after crash.
    

---

## 9. Shadow Paging

- Uses two copies: current page table and shadow page table.
    
- Shadow table represents consistent state; no logging required.
    
- Simpler but less flexible for concurrency.
    

---

## 10. Goal of Transaction Processing

- Maintain database consistency.
    
- Ensure reliability under concurrent access and failures.
    
- Guarantee atomic, isolated, and durable execution of transactions.
    


---
----

# 6. Database Security

## 1. Definition

Database security protects data from unauthorized access, misuse, or corruption while ensuring confidentiality, integrity, and availability.

---

## 2. Database Security Objectives

- **Confidentiality:** Prevent unauthorized data disclosure.
    
- **Integrity:** Prevent unauthorized or improper data modification.
    
- **Availability:** Ensure authorized users can access data when needed.
    

---

## 3. Threats to Database

1. **Unauthorized Access** – Intruders gaining access to data.
    
2. **SQL Injection** – Malicious query manipulation.
    
3. **Privilege Abuse** – Authorized users misusing rights.
    
4. **Malware & Viruses** – Data corruption or leakage.
    
5. **System Crashes or Hardware Failures** – Data loss or inaccessibility.
    
6. **Human Errors** – Accidental deletion or modification.
    

---

## 4. Security Mechanisms

### a) **Authentication**

Verifies user identity before access.  
Methods: Passwords, Biometrics, Tokens, Two-Factor Authentication.

### b) **Authorization (Access Control)**

Determines what operations an authenticated user can perform.

- **Discretionary Access Control (DAC):**
    
    - Based on privileges and access rights (GRANT, REVOKE).
        
- **Mandatory Access Control (MAC):**
    
    - Based on system-defined security labels (used in defense systems).
        
- **Role-Based Access Control (RBAC):**
    
    - Access assigned through roles rather than individual users.
        

### c) **Views for Security**

Create limited data views for users to restrict access to sensitive attributes.

```sql
CREATE VIEW emp_public AS
SELECT name, dept FROM employee;
```

---

## 5. Encryption

Protects stored or transmitted data by encoding it.

- **At Rest:** Encrypt files or database storage.
    
- **In Transit:** Use SSL/TLS for secure communication.
    
- **Techniques:** AES, RSA, SHA, MD5 (for hashing).
    

---

## 6. Audit and Monitoring

- **Auditing:** Tracks user actions (who accessed or modified data).
    
- **Logging:** Records database events for accountability.
    
- **Intrusion Detection Systems (IDS):** Identify suspicious activities.
    

---

## 7. Database Integrity Controls

- **Domain Constraints:** Valid attribute values.
    
- **Entity Integrity:** Primary key not NULL.
    
- **Referential Integrity:** Foreign key consistency.
    
- **Application-Based Checks:** Enforced at application or trigger level.
    

---

## 8. Backup and Recovery Security

- Regular backups to prevent data loss.
    
- Secure storage of backup files.
    
- Use of encryption for backup media.
    
- Implement proper recovery procedures.
    

---

## 9. SQL Security Features

```sql
GRANT SELECT, INSERT ON student TO user1;
REVOKE INSERT ON student FROM user1;
```

Use of triggers and stored procedures to control indirect access.

---

## 10. Physical and Network Security

- **Physical:** Controlled server room access, CCTV, fire protection.
    
- **Network:** Firewalls, VPNs, intrusion prevention, strong authentication.
    

---

## 11. Best Practices

- Principle of **Least Privilege**.
    
- Regular **patching and updates**.
    
- **Strong password** policies.
    
- **Periodic security audits**.
    
- **Encryption + Access Control** integration.
    

---

## 12. Database Security Challenges

- Balancing performance with encryption overhead.
    
- Managing large user bases and privileges.
    
- Protecting against evolving cyber threats.


---
---

# 7. ACID Properties

## 1. Overview

ACID properties ensure that database transactions are processed **reliably and consistently**, even in the presence of failures or concurrent operations.

---

## 2. Atomicity

- Ensures that a transaction is treated as a **single indivisible unit**.
    
- Either **all operations are executed** or **none**.
    
- Handled by the **Transaction Manager** using log records.
    
- **Failure Recovery:** If a failure occurs, all partial changes are **rolled back (UNDO)**.
    

**Example:**  
If transferring ₹1000 from A to B:

- Debit A by ₹1000
    
- Credit B by ₹1000  
    If credit fails, debit is undone.
    

---

## 3. Consistency

- Ensures that a transaction **preserves database integrity constraints**.
    
- Database moves from one **consistent state to another**.
    
- Any violation of constraints (e.g., key, referential, domain) causes the transaction to abort.
    

**Example:**  
Sum(A.balance + B.balance) remains constant before and after transfer.

---

## 4. Isolation

- Concurrent transactions must execute as if they were **run sequentially**.
    
- Prevents interference among transactions.
    
- Achieved through **locking** or **timestamp ordering**.
    

**Isolation Problems:**

1. **Dirty Read:** Read uncommitted data.
    
2. **Non-repeatable Read:** Data changes between reads.
    
3. **Phantom Read:** New rows appear in repeated queries.
    

**Isolation Levels (SQL Standard):**

- Read Uncommitted
    
- Read Committed
    
- Repeatable Read
    
- Serializable
    

---

## 5. Durability

- Ensures that once a transaction commits, its changes are **permanent**, even after system failures.
    
- Achieved via **log-based recovery** and **checkpointing**.
    
- The **Recovery Manager** redoes committed transactions after crash.
    

---

## 6. Implementation Components

- **Transaction Manager:** Ensures atomicity and isolation.
    
- **Concurrency Control Manager:** Enforces isolation using locks or timestamps.
    
- **Recovery Manager:** Ensures atomicity and durability via logs and checkpoints.
    

---

## 7. Significance of ACID

- Maintains database correctness.
    
- Prevents data anomalies and corruption.
    
- Ensures reliability in multi-user and failure-prone environments.

---
---

# 8. Normalization and Joins

## 1. Normalization

Process of **organizing data in a database** to reduce redundancy and improve data integrity.

---

## 2. Objectives

- Eliminate data redundancy.
    
- Avoid insertion, deletion, and update anomalies.
    
- Ensure data dependencies make sense.
    
- Simplify maintenance and improve consistency.
    

---

## 3. Functional Dependency (FD)

A relationship **X → Y** means if two tuples have the same X values, they must have the same Y values.  
Used to identify redundancy and determine normal forms.

---

## 4. Types of Anomalies

- **Insertion Anomaly:** Cannot insert data due to missing related data.
    
- **Deletion Anomaly:** Deleting one record removes essential information.
    
- **Update Anomaly:** Same data repeated in multiple places must all be updated.
    

---

## 5. Normal Forms

### a) **1NF (First Normal Form)**

- Each attribute contains only **atomic values**.
    
- No repeating groups or arrays.
    

**Example:**  
`Phone = {123, 456}` → Split into separate tuples.

---

### b) **2NF (Second Normal Form)**

- Must be in 1NF.
    
- **No partial dependency** on a part of composite key.
    
- Every non-prime attribute depends on the whole key.
    

---

### c) **3NF (Third Normal Form)**

- Must be in 2NF.
    
- **No transitive dependency.**
    
- Non-key attributes depend only on the primary key.
    

---

### d) **BCNF (Boyce-Codd Normal Form)**

- Stronger than 3NF.
    
- For every FD X → Y, X must be a **superkey**.
    

---

### e) **4NF**

- Must be in BCNF.
    
- No **multivalued dependencies**.
    

---

### f) **5NF**

- Eliminates **join dependencies**.
    
- Used for complex, rarely required decomposition.
    

---

## 6. Denormalization

- Intentional merging of tables to improve performance.
    
- Increases redundancy but speeds up joins and queries.
    

---

## 7. Joins

Used to **combine rows** from two or more tables based on related columns.

### a) **Inner Join**

Returns rows with matching values in both tables.

```sql
SELECT e.name, d.dept_name
FROM employee e
INNER JOIN department d ON e.dept_id = d.id;
```

### b) **Left Outer Join**

Returns all rows from left table + matched rows from right table.  
Unmatched right rows are NULL.

```sql
SELECT e.name, d.dept_name
FROM employee e
LEFT JOIN department d ON e.dept_id = d.id;
```

### c) **Right Outer Join**

Returns all rows from right table + matched rows from left table.

### d) **Full Outer Join**

Returns all rows from both tables, with NULLs where no match exists.

### e) **Cross Join (Cartesian Product)**

Combines all rows of both tables.

```sql
SELECT * FROM A CROSS JOIN B;
```

### f) **Self Join**

Joins a table with itself.

```sql
SELECT e1.name, e2.name AS manager
FROM employee e1
JOIN employee e2 ON e1.manager_id = e2.id;
```

---

## 8. Join Conditions

- **Equi Join:** Based on equality (most common).
    
- **Natural Join:** Automatically joins columns with same names.
    
- **Theta Join:** Uses comparison operators (<, >, ≤, ≥, ≠, =).
    

---

## 9. Relation Between Normalization and Joins

- Normalization decomposes tables → reduces redundancy → requires joins to reconstruct original relations.
    
- Denormalization reduces number of joins → increases redundancy but improves performance.
    

---

## 10. Summary

|Normal Form|Removes|Key Concept|
|---|---|---|
|1NF|Repeating Groups|Atomic Attributes|
|2NF|Partial Dependency|Full Dependency on Key|
|3NF|Transitive Dependency|Direct Key Dependency|
|BCNF|Non-Key Determinants|Superkey Condition|
|4NF|Multivalued Dependency|Independent Attributes|
|5NF|Join Dependency|Lossless Decomposition|


---
---

# 9. DDL, DML, DCL, DQL, TCL

## 1. Overview

SQL (Structured Query Language) is divided into **five main categories** based on the type of operations performed on the database.

---

## 2. DDL (Data Definition Language)

Used to **define or modify** database schema objects like tables, views, and indexes.

### Commands:

- **CREATE:** Create new database objects.
    
    ```sql
    CREATE TABLE student (
        rollno INT PRIMARY KEY,
        name VARCHAR(50),
        branch VARCHAR(20)
    );
    ```
    
- **ALTER:** Modify existing objects.
    
    ```sql
    ALTER TABLE student ADD age INT;
    ```
    
- **DROP:** Delete objects permanently.
    
    ```sql
    DROP TABLE student;
    ```
    
- **TRUNCATE:** Remove all records but keep structure.
    
    ```sql
    TRUNCATE TABLE student;
    ```
    
- **RENAME:** Change object name.
    
    ```sql
    RENAME TABLE student TO students;
    ```
    

**Effect:** Auto-committed (cannot be rolled back).

---

## 3. DML (Data Manipulation Language)

Used to **manipulate or modify data** within tables.

### Commands:

- **INSERT:** Add new records.
    
    ```sql
    INSERT INTO student VALUES (1, 'Rahul', 'CSE');
    ```
    
- **UPDATE:** Modify existing data.
    
    ```sql
    UPDATE student SET branch='ECE' WHERE rollno=1;
    ```
    
- **DELETE:** Remove specific records.
    
    ```sql
    DELETE FROM student WHERE rollno=1;
    ```
    

**Effect:** Can be rolled back or committed using TCL.

---

## 4. DQL (Data Query Language)

Used to **retrieve data** from the database.

### Command:

- **SELECT:**
    
    ```sql
    SELECT name, branch FROM student WHERE branch='CSE';
    ```
    

**Purpose:** Query and view data without altering it.

---

## 5. DCL (Data Control Language)

Used to **control user access and privileges** in the database.

### Commands:

- **GRANT:** Provide privileges.
    
    ```sql
    GRANT SELECT, INSERT ON student TO user1;
    ```
    
- **REVOKE:** Withdraw privileges.
    
    ```sql
    REVOKE INSERT ON student FROM user1;
    ```
    

---

## 6. TCL (Transaction Control Language)

Used to **manage transactions** within DML operations.

### Commands:

- **COMMIT:** Save all changes permanently.
    
    ```sql
    COMMIT;
    ```
    
- **ROLLBACK:** Undo uncommitted changes.
    
    ```sql
    ROLLBACK;
    ```
    
- **SAVEPOINT:** Set a point within a transaction to roll back partially.
    
    ```sql
    SAVEPOINT sp1;
    ROLLBACK TO sp1;
    ```
    
- **SET TRANSACTION:** Define transaction properties (like isolation level).
    
    ```sql
    SET TRANSACTION READ ONLY;
    ```
    

---

## 7. Summary Table

|Category|Full Form|Purpose|Example Command|Rollback Possible|
|---|---|---|---|---|
|DDL|Data Definition Language|Define structure|CREATE, ALTER, DROP|❌|
|DML|Data Manipulation Language|Modify data|INSERT, UPDATE, DELETE|✅|
|DQL|Data Query Language|Retrieve data|SELECT|Not Applicable|
|DCL|Data Control Language|Manage access|GRANT, REVOKE|❌|
|TCL|Transaction Control Language|Manage transactions|COMMIT, ROLLBACK, SAVEPOINT|✅|
