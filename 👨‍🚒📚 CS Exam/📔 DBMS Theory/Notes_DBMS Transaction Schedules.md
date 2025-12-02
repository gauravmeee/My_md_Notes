
#### **DBMS Transaction Schedules — Quick Detection Cheat Sheet**

Small headings, code-block formats where useful, short and to the point.

##### **1. Recoverability**

```
Check:
1. If Ti reads a value written by Tj, then Tj must commit before Ti commits.
2. If Ti commits before Tj (whose data Ti used), schedule is NOT recoverable.
```

- *Recoverable:*
```sql
T1: W(X) -------- Commit
T2: R(X) ---------------- Commit
Check: T2 reads X from T1, and T1 commits before T2 → Recoverable
```

- *Non-Recoverable:*
```sql
T2: R(X) ----- Commit
T1: W(X) --------------- Commit
T2 read uncommitted data of T1 and committed before T1 → Not Recoverable
```

##### **2. Avoids Cascading Aborts (ACA / Non-Cascadability)**

```
Check:
1. If Ti reads a value written by Tj, Tj must COMMIT before Ti reads.
2. No READ allowed from an uncommitted write.
3. If any read happens from an uncommitted write → Cascading possible.
```

- *Non-Cascadability (ACA) Example*
```sql
T1: W(X) ---- Commit
T2:     R(X) -------- Commit
Read happens only after T1 commits → ACA
```

- *Cascading:*
```sql
T1: W(X)
T2:   R(X) ---- Abort T1 → T2 must abort → Cascading
```

##### **3. Strictness (Stricter than ACA)**

```
Check:
1. No READ or WRITE allowed on an item written by an uncommitted txn.
2. Both read-after-write and write-after-write must wait for commit.
3. If any op touches data of an uncommitted write → Not Strict.
```

- *Strict:*
```sql
T1: W(X) ---- Commit
T2:      W(X) -------- Commit
No R/W on X until T1 commits → Strict
```

- *Not strict:*
```sql
T1: W(X)
T2:   W(X) ---- Commit
T2 writes X before T1 commits → Not Strict
```
##### **4. Conflict Serializability**

```
Steps:
1. Build precedence graph (Ti → Tj if Ti’s conflicting op comes before Tj).
2. Conflicting ops: R-W, W-R, W-W on SAME data item.
3. If graph has a cycle → Not conflict serializable.
4. If no cycle → Conflict serializable.
```

- *Conflict Serializability:*
```sql
T1: R(X) ---- W(X)
T2:      R(X) ---- W(X)

Conflicts:
T1 W(X) before T2 R(X) → T1→T2
T1 W(X) before T2 W(X) → T1→T2
Graph has no cycle → Conflict Serializable (order T1,T2)
```

- *Non-conflict-serializable:*
```sql
T1:      R(X) ----- W(Y)
T2: W(X) ----- R(Y)

Conflicts:
T2 W(X) → T1 R(X)  → T2→T1
T1 W(Y) → T2 R(Y)  → T1→T2
Cycle → Not conflict serializable
```
##### **5. View Serializability**

```
Check:
1. Same initial reads.
2. Same reads-from relationships.
3. Same final writes.
4. If matches some serial order → View serializable.
5. If not → View non-serializable.
```

- *View Serializability*
```sql
T1: W(X)
T2:      R(X) ---- W(X)

Initial reads same, reads-from same, final write by T2 → View serializable (T1,T2)
```

- *Not view serializable:*
```sql
T1: W(X)
T2:      W(X)
T3:           R(X) (but ambiguous origin)

Ambiguous reads-from → Not view serializable
```
##### **6. Cascading Aborts Detection**

```
If Tj aborts and Ti has read uncommitted data of Tj → Ti must abort.
If any such chain exists → Cascading abort schedule.

```

- *Cascading Aborts:*
```
T1: W(A)
T2:   R(A)
T1 aborts → T2 must abort → Cascading aborts
```

- *Dirty Read:*
```
T1: W(X)
T2:   R(X)
T1 not committed → Dirty read
```
##### **7. Dirty Read Detection**

```
If Ti reads data written by uncommitted Tj → Dirty read.
```

- *Dirty Read:*
```sql
T1: W(X)
T2:   R(X)
T1 not committed → Dirty read
```

##### **8. Dirty Write Detection**
```
If Ti writes to an item previously written by uncommitted Tj → Dirty write.
```

- *Dirty Write:*
```sql
T1: W(X)
T2:   W(X)
T1 uncommitted → Dirty write
```

##### **9. Serial Schedule Check**
```
All transactions execute in non-overlapping blocks.
If operations of each transaction are contiguous → Serial.
```

- *Serial Schedule:*
```sql
T1: R(X), W(X), Commit
T2: R(Y), W(Y), Commit
All T1 ops then all T2 ops → Serial
```
##### **10. Serializable but Not Conflict Serializable**
```
If precedence graph is cyclic but schedule still maintains view conditions → 
View-serializable but NOT conflict-serializable.
```

- *Serializable but Not Conflict Serializable*
```sql
T1: W(X)
T2:      W(X)
T3:           R(X)

Final write and reads-from match a serial order → View serializable
But W-W conflicts cause cycles → Not conflict serializable
```
##### **11. Precedence Graph Rules (Quick)**
```
Ti→Tj when:
1. Ti writes X before Tj reads X
2. Ti reads X before Tj writes X
3. Ti writes X before Tj writes X
```

##### **12. Strict vs ACA vs Recoverable (Hierarchy)**
```
Strict → ACA → Recoverable
Reverse not always true.
```
