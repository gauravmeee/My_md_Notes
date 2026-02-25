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

# Transaction Schedules and Concurrency

#### Transaction, Schedules and Serializability

**1. Transaction**

* A **transaction** is a <mark>sequence of operations</mark> performed <mark>as a single logical unit</mark> of work.
* Must satisfy **ACID properties**:
  * **Atomicity** – <mark>All or none</mark> of its operations are executed.
  * **Consistency** – Database remains in a <mark>valid state</mark> before and after transaction.
  * **Isolation** – Concurrent transactions do <mark>not interfere</mark> with each other.
  * **Durability** – Once committed, changes are <mark>permanent.</mark>

**2. Schedule**

* A **schedule** is an <mark>order in which the operations (read/write) of multiple transactions are executed</mark>.
* **Types of Schedules:**
  1. **Serial Schedule:** Transactions are <mark>executed one after another</mark> — no interleaving.
  2. **Concurrent Schedule:** Operations of <mark>multiple transactions are interleaved for better performance.</mark>

**3. Serializability**

* A schedule is **serializable** if its effect on the database is **equivalent to a serial schedule**.
* It <mark>ensures **consistency** in concurrent executions</mark>.

**Types of Serializability** ⭐

1. **Conflict Serializability**
2. **View Serializability**

**Conflict Serializable Schedule**

* **Conflict** ⭐
  * Two operations **conflict** if:
    * They belong to **different transactions**,
    * Access the **same data item**, and
    * At least one is a **write** operation.
* **Conflict Serializability**
  * A schedule is **conflict-serializable** if it can be transformed into a serial schedule by **swapping non-conflicting operations**.

**Precedence Graph (Serialization Graph)**

* Nodes represent transactions.
* Directed edge `Ti -> Tj` means an operation in `Ti` precedes and conflicts with an operation in `Tj`.
* **If the graph has no cycles → Schedule is conflict-serializable.**

***

#### Conflict Serializability & View Serializability

**1. Conflict Serializability**

**1. Transactions & Operations**

* Each transaction: sequence of operations: `r` (read), `w` (write)
* Data items: X, Y, …

**2. Conflict Rules**

* **Conflict occurs** if all three are true:
  1. Same data item
  2. Different transactions
  3. At least one operation is a write
* **No conflict**: r vs r on same item

**3. Steps to Check Conflict Serializability**

1. List all operations in schedule
2. Identify conflicting pairs (use rules above)
3. Draw **Precedence Graph**:
   * Nodes = transactions
   * Edge T1 → T2 if T1’s operation conflicts with T2’s **later** operation
4. Check graph:
   * **Cycle → Not conflict serializable**
   * **No cycle → Conflict serializable**

**4. Common Edge Patterns**

* `r-w` → T1 → T2
* `w-r` → T1 → T2
* `w-w` → T1 → T2
* `r-r` → No edge

**5. Example**

* **Transactions:**
  * T1: `r1(X), r1(Y), w1(X)`
  * T2: `r2(X), r2(Y), w2(Y)`
* **Schedule S1:** `r1(X); r1(Y); r2(Y); w2(Y); w1(X)`
  * Conflicts: `r1(Y)-w2(Y) → T1 → T2`
  * Graph: T1 → T2 → No cycle → **Serializable**
* **Schedule S2:** `r2(X); r2(Y); w2(Y); r1(Y); w1(X)`
  * Conflicts: `w2(Y)-r1(Y), r2(X)-w1(X) → T2 → T1`
  * Graph: T2 → T1 → No cycle → **Serializable**

**View Serializability**

**1. Basic Idea**

* Schedule is **view serializable** if it is **view equivalent** to some serial schedule
* We compare **what values are read and written**, not operation order

**2. View Equivalence Conditions**

Two schedules S and S′ are view equivalent if **all three** hold:

1. **Initial Read Rule**
   * If a transaction `Ti` reads `X` written by **no one** in `S`, then in `S′` also `Ti` must read the **initial value** of `X`
2. **Read-From Rule**
   * If `Ti` reads `X` written by `Tj` in `S`, then in `S′` also `Ti` must read `X` from **the same `Tj`**
3. **Final Write Rule**
   * The transaction that performs the **last write** on X in S must also be the **last writer** of X in S′

**3. Steps to Check View Serializability**

1. Identify **read-from relationships**
2. Identify **final writes** on each data item
3. Try to find a **serial order** satisfying both
4. If possible → View Serializable\
   Else → Not View Serializable

**4. Key Properties**

* View serializability is **weaker** than conflict serializability
* Every conflict-serializable schedule is view-serializable
* Some view-serializable schedules are **not conflict-serializable**

**5. Special Case: Blind Write**

* Write without prior read (`w(X)` only)
* Causes schedules that are:
  * View serializable
  * But **not** conflict serializable

**6. Example (View Serializable but NOT Conflict Serializable)**

* **Transactions**
  * T1: `w1(X)`
  * T2: `w2(X)`
* **Schedule**
  * `w1(X); w2(X)`
* No reads → no read-from constraints
* Final write on `X` is by `T2`
* Equivalent to serial order **`T1` → `T2`**
* **View Serializable**
* But `w1(X)` conflicts with `w2(X)` → cycle possible in precedence graph
* **Not Conflict Serializable**

**Comparison: Conflict vs View Serializability**

| Aspect        | Conflict Serializability | View Serializability    |
| ------------- | ------------------------ | ----------------------- |
| Based on      | Conflicting operations   | Read-from + final write |
| Test Method   | <mark>Precedence graph</mark>     | <mark>Logical checking</mark>    |
| Blind Writes  | Not allowed              | Allowed                 |
| Power         | Stronger                 | Weaker                  |
| Practical Use | Easy to test             | Hard (NP-complete)      |

**8. Exam-Oriented Conclusion**

* If **precedence graph has no cycle** → Conflict Serializable → View Serializable
* If **cycle exists**, still **may be View Serializable**
* GATE/PSU exams:
  * Conflict serializability → graph-based
  * View serializability → focus on **blind writes + final write**

***

#### Concurrency Control

* Mechanism to control the **simultaneous execution** of transactions to preserve **isolation** and **consistency**.

**Objectives**

* Maintain <mark>database consistency</mark>.
* Allow <mark>maximum parallelism</mark>.
* Prevent anomalies like: ⭐
  1. **Lost Update**
  2. **Temporary Update (Dirty Read)**
  3. **Incorrect Summary**
  4. **Unrepeatable Read**

**Anomalies Overview**

**1. Lost Update**

* Occurs when **two or more transactions** read the same data item and update it simultaneously, causing **one update to be overwritten by another**.
* **Problem:** The final value reflects only one transaction’s update; others are lost.
*   **Example:**

    ```
    T1: Read(X=100)
    T2: Read(X=100)
    T1: X = X + 50  → X=150
    T2: X = X - 30  → X=70
    ```

    Final value = 70 (T1’s update lost)

**2. Temporary Update (Dirty Read)**

* Occurs when a transaction **reads a data item updated by another uncommitted transaction**.
* If the updating transaction **rolls back**, the first transaction has read an **invalid (dirty)** value.
* **Problem:** Leads to **inconsistent or incorrect results**.
*   **Example:**

    ```
    T1: Write(X=500)  → Not yet committed
    T2: Read(X=500)
    T1: Rollback  → X restored to old value
    ```

    T2 used a value (500) that never actually existed in the database.

**3. Incorrect Summary**

* Occurs when a transaction **computes an aggregate (e.g., SUM, AVG)** on data that is **being modified** by other transactions concurrently.
* **Problem:** Some updates are reflected while others are not, leading to **partial or incorrect results**.
*   **Example:**

    ```
    T1: SUM(salaries) of all employees
    T2: Update salary of one employee
    ```

    If T1 reads part of the table before and part after T2’s update → incorrect total.

**4. Unrepeatable Read**

* Occurs when a transaction **reads the same data item twice** and **gets different values** because another transaction modified the data in between.
* **Problem:** Inconsistent view of the same data within one transaction.
*   **Example:**

    ```
    T1: Read(X=100)
    T2: Write(X=200) → Commit
    T1: Read(X=200)
    ```

    T1 reads different values for X in the same execution → unrepeatable read.

***

#### Concurrency Control Protocols

1. **Lock-Based Protocols** (e.g., Two-Phase Locking)
   * Two Phase Locking (2PL)
   * Strict Two Phase Locking (Strict 2PL)
2. **Timestamp-Based Protocols**
   * Timestamp Ordering
   * Thomas’ Write Rule

**1. Two-Phase Locking (2PL) Protocol**

* Transactions use **locks** to control access to data items.
* Lock types:
  * <mark>**Shared Lock (S)**</mark> – For reading (multiple transactions can share).
  * <mark>**Exclusive Lock (X)**</mark> – For writing (only one transaction can hold).

**Phases**

1. **Growing Phase** – Transaction **acquires locks**, cannot release any.
2. **Shrinking Phase** – Transaction **releases locks**, cannot acquire new ones.

**Properties**

* **Conflict Serializability:** Ensured.
* **No Deadlock Freedom:** Not guaranteed (deadlocks may occur).
* **No Recoverability:** Possible, but not always guaranteed — depends on lock release timing. Cascading rollbacks **can occur** if a transaction releases locks before commit.

**2. Strict Two-Phase Locking (Strict 2PL)**

* A stricter form of 2PL ensuring **recoverability** and avoiding **cascading rollbacks**.

**Rules**

* **All exclusive (write) locks** are held until the transaction **commits or aborts**.
* Locks are **released only after completion** of the transaction.

**Features:**

* **Conflict Serializability:** Guaranteed.
* **No Deadlock Freedom:** Not guaranteed (deadlocks can still occur).
* **Recoverability:** Guaranteed (no cascading rollbacks or dirty reads).
* **Strictness:** Ensures strict schedules (safe for recovery).

**3. Timestamp-Ordering Protocol**

* Each transaction <mark>**T** gets a **unique timestamp (TS(T))**</mark> when it starts.
* The DBMS ensures that **all conflicting operations** execute in **timestamp order**.

**For Each Data Item (Q):**

* <mark>**read\_TS(Q):**</mark> Largest timestamp of any transaction that read Q.
* <mark>**write\_TS(Q):**</mark> Largest timestamp of any transaction that wrote Q.

**Rules:**

1. **Read Rule:**
   * If `TS(T) < write_TS(Q)` → **Abort T** (T is too old).
   * Else, execute read and set `read_TS(Q) = max(read_TS(Q), TS(T))`.
2. **Write Rule:**
   * If `TS(T) < read_TS(Q)` or `TS(T) < write_TS(Q)` → **Abort T**.
   * Else, perform write and set `write_TS(Q) = TS(T)`.

**Features:**

* **Conflict Serializability:** Ensured.
* **Deadlock Freedom:** Guaranteed (no waiting; ordered by timestamps).
* **No Recoverability:** Achieved if transactions are executed strictly in timestamp order. However, **not guaranteed by default** — requires additional mechanisms to ensure commit order consistency.
* Can cause **many aborts** due to timestamp conflicts.

**4. Thomas’ Write Rule (with Timestamp-Ordering Protocol) ⭐**

* A <mark>modification of the timestamp-ordering protocol</mark> that allows <mark>**ignoring obsolete writes**</mark>.
* If a transaction tries to **write** an item **older** than the current version, its write is **skipped** instead of aborting the transaction.

**Rule:**

* If `TS(T) < write_TS(Q)` → **Ignore the write** (instead of abort).

**Advantages:**

* **Serializability:** Maintained (though not strict).
* **Deadlock Freedom:** Guaranteed (same as timestamp ordering).
* **Recoverability:** Same as basic timestamp ordering — must enforce commit ordering to ensure full recoverability.
* **Improved Concurrency:** Fewer aborts, better throughput.
* **No Strictness:** Not ensured (obsolete writes may be ignored).

**Concurrency Control Protocols Comparison (Transposed)**

| **Property**                 | **Two-Phase Locking (2PL)**                                                | **Strict Two-Phase Locking (Strict 2PL)**                                                | **Timestamp Ordering (TO)**                                          | **Thomas’ Write Rule**                                                      |
| ---------------------------- | -------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- | -------------------------------------------------------------------- | --------------------------------------------------------------------------- |
| **Conflict Serializability** | ✅ Ensured                                                                  | ✅ Ensured                                                                                | ✅ Ensured                                                            | ✅ Ensured (non-strict)                                                      |
| **Recoverability**           | ❌ Conditional                                                              | ✅⭐ Guaranteed                                                                            | ❌ Conditional (depends on commit order)                              | ❌ Conditional (similar to TO)                                               |
| **Deadlock Freedom**         | ❌ Deadlocks possible                                                       | ❌ Deadlocks possible                                                                     | ✅ Deadlock-free                                                      | ✅ Deadlock-free                                                             |
| **Strictness**               | ❌ Not strict                                                               | ✅ Strict                                                                                 | ❌ Not strict                                                         | ❌ Not strict                                                                |
| **Cascading Rollback**       | ❌ Possible                                                                 | ✅ Prevented                                                                              | ✅ Prevented                                                          | ✅ Prevented                                                                 |
| **Extra Notes / Remarks**    | Basic protocol; ensures serializability but may cause cascading rollbacks. | Most used; ensures serializability + recoverability + strictness; only issue: deadlocks. | Deadlock-free but causes frequent aborts due to timestamp conflicts. | Ignores obsolete writes; improves concurrency; serializable but non-strict. |

***

### Transaction Schedules - Property Detection Cheat Sheet

**1. Recoverability**

```
Check:
1. If Ti reads a value written by Tj, then Tj must commit before Ti commits.
2. If Ti commits before Tj (whose data Ti used), schedule is NOT recoverable.
```

* _Recoverable:_

```sql
T1: W(X) -------- Commit
T2: R(X) ---------------- Commit
Check: T2 reads X from T1, and T1 commits before T2 → Recoverable
```

* _Non-Recoverable:_

```sql
T2: R(X) ----- Commit
T1: W(X) --------------- Commit
T2 read uncommitted data of T1 and committed before T1 → Not Recoverable
```

**2. Avoids Cascading Aborts (ACA / Non-Cascadability)**

```
Check:
1. If Ti reads a value written by Tj, Tj must COMMIT before Ti reads.
2. No READ allowed from an uncommitted write.
3. If any read happens from an uncommitted write → Cascading possible.
```

* _Non-Cascadability (ACA) Example_

```sql
T1: W(X) ---- Commit
T2:     R(X) -------- Commit
Read happens only after T1 commits → ACA
```

* _Cascading:_

```sql
T1: W(X)
T2:   R(X) ---- Abort T1 → T2 must abort → Cascading
```

**3. Strictness (Stricter than ACA)**

```
Check:
1. No READ or WRITE allowed on an item written by an uncommitted txn.
2. Both read-after-write and write-after-write must wait for commit.
3. If any op touches data of an uncommitted write → Not Strict.
```

* _Strict:_

```sql
T1: W(X) ---- Commit
T2:      W(X) -------- Commit
No R/W on X until T1 commits → Strict
```

* _Not strict:_

```sql
T1: W(X)
T2:   W(X) ---- Commit
T2 writes X before T1 commits → Not Strict
```

**4. Conflict Serializability**

```
Steps:
1. Build precedence graph (Ti → Tj if Ti’s conflicting op comes before Tj).
2. Conflicting ops: R-W, W-R, W-W on SAME data item.
3. If graph has a cycle → Not conflict serializable.
4. If no cycle → Conflict serializable.
```

* _Conflict Serializability:_

```sql
T1: R(X) ---- W(X)
T2:      R(X) ---- W(X)

Conflicts:
T1 W(X) before T2 R(X) → T1→T2
T1 W(X) before T2 W(X) → T1→T2
Graph has no cycle → Conflict Serializable (order T1,T2)
```

* _Non-conflict-serializable:_

```sql
T1:      R(X) ----- W(Y)
T2: W(X) ----- R(Y)

Conflicts:
T2 W(X) → T1 R(X)  → T2→T1
T1 W(Y) → T2 R(Y)  → T1→T2
Cycle → Not conflict serializable
```

**5. View Serializability**

```
Check:
1. Same initial reads.
2. Same reads-from relationships.
3. Same final writes.
4. If matches some serial order → View serializable.
5. If not → View non-serializable.
```

* _View Serializability_

```sql
T1: W(X)
T2:      R(X) ---- W(X)

Initial reads same, reads-from same, final write by T2 → View serializable (T1,T2)
```

* _Not view serializable:_

```sql
T1: W(X)
T2:      W(X)
T3:           R(X) (but ambiguous origin)

Ambiguous reads-from → Not view serializable
```

**6. Cascading Aborts Detection**

```
If Tj aborts and Ti has read uncommitted data of Tj → Ti must abort.
If any such chain exists → Cascading abort schedule.

```

* _Cascading Aborts:_

```
T1: W(A)
T2:   R(A)
T1 aborts → T2 must abort → Cascading aborts
```

* _Dirty Read:_

```
T1: W(X)
T2:   R(X)
T1 not committed → Dirty read
```

**7. Dirty Read Detection**

```
If Ti reads data written by uncommitted Tj → Dirty read.
```

* _Dirty Read:_

```sql
T1: W(X)
T2:   R(X)
T1 not committed → Dirty read
```

**8. Dirty Write Detection**

```
If Ti writes to an item previously written by uncommitted Tj → Dirty write.
```

* _Dirty Write:_

```sql
T1: W(X)
T2:   W(X)
T1 uncommitted → Dirty write
```

**9. Serial Schedule Check**

```
All transactions execute in non-overlapping blocks.
If operations of each transaction are contiguous → Serial.
```

* _Serial Schedule:_

```sql
T1: R(X), W(X), Commit
T2: R(Y), W(Y), Commit
All T1 ops then all T2 ops → Serial
```

**10. Serializable but Not Conflict Serializable**

```
If precedence graph is cyclic but schedule still maintains view conditions → 
View-serializable but NOT conflict-serializable.
```

* _Serializable but Not Conflict Serializable_

```sql
T1: W(X)
T2:      W(X)
T3:           R(X)

Final write and reads-from match a serial order → View serializable
But W-W conflicts cause cycles → Not conflict serializable
```

**11. Precedence Graph Rules (Quick)**

```
Ti→Tj when:
1. Ti writes X before Tj reads X
2. Ti reads X before Tj writes X
3. Ti writes X before Tj writes X
```

**12. Strict vs ACA vs Recoverable (Hierarchy)**

```
Strict → ACA → Recoverable
Reverse not always true.
```
