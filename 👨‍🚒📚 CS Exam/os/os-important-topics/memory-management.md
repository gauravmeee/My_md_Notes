
# Memory Management

```text
Operating Systems
└── Memory Management
    └── Virtual Memory
        ├── Paging
        ├── Demand Paging
        ├── Page Replacement
        ├── Thrashing
        └── Working Set Model
```

## Working Set Model

##### **1. Principle of Locality**

Programs do not access all memory randomly.

They usually access:
- the same data repeatedly (**Temporal Locality**) ⭐
- nearby memory locations (**Spatial Locality**) ⭐

This behavior is called the **Principle of Locality**.

##### **2. Working Set**

The **working set** is: The <mark>set of pages currently being actively used by a process</mark> during a time interval.

Notation:

$$W(t, \Delta)$$
Where:
- $t$ = current time
- $\Delta$ = working set window

It contains all pages referenced in the last $\Delta$ time units.

##### **3. Purpose of Working Set Model**

The OS keeps the <mark>working</mark> set pages in memory to:

- reduce page faults
- improve performance
- prevent thrashing

##### **4. Thrashing**

Thrashing occurs when:
- too many page faults happen
- CPU spends more time swapping pages than executing processes

Cause:
- insufficient frames allocated to processes

##### 5. Relation Between Working Set and Thrashing

- If all working set pages fit in RAM → system works efficiently
- If working sets do not fit → thrashing occurs
    

Thus:

> Working Set Model is used to control/prevent thrashing.

##### **6. Important Exam Point**

| Concept           | Related To                       |
| ----------------- | -------------------------------- |
| Working Set Model | Principle of Locality            |
| Thrashing         | Excessive Paging                 |
| Paging            | Virtual Memory                   |
| Segmentation      | Memory division by logical units |

##### **Important One-Liners**
- Working set model is based on **locality of reference**.
- Working set helps prevent **thrashing**.
- Thrashing increases page faults and reduces CPU utilization.
- Working set is used in **virtual memory management**.
