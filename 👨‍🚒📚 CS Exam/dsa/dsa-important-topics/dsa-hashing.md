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

# DSA: Hashing

### Hashing

Hashing is a ==technique to map a key to an index== of a hash table using a ==hash function==, enabling $O(1)$ ==average time== for search, insert, and delete operations.

> **Hash Table:** A hash table is a **data structure** that stores ==key–value pair==s and uses a **hash function** to ==map each key to an index in an array==, allowing **O(1) average-time** search, insertion, and deletion.

**Terminology**

* **Key (k):** Input value to be stored/searched
* **Hash Function h(k):** Maps key k to table index
* **Hash Table:** Array of size m (table size)
* **Slot/Bucket:** Each index position in hash table
* **Load Factor ($\alpha$):** $\alpha = \frac{n}{m}$ where n = number of keys, m = table size
* **Collision:** When two different keys map to same index
* **Clustering:** Keys accumulate in consecutive slots

**Properties of a Good Hash Function**

1. **Deterministic:** Same key always gives same index
2. **Uniform Distribution:** Keys spread evenly across table
3. **Fast Computation:** Should compute in $O(1)$ time
4. **Minimizes Collisions:** Reduces probability of two keys mapping to same slot
5. **Uses all table positions:** No slot should be favored
6. **Low clustering:** Avoids grouping of keys

**Hash Functions**

**1. Division Method:**

$$h(k) = k \bmod m$$

* **Best practice:** m should be prime
* **Avoid:** Powers of 2 (causes poor distribution)
* **Why prime?** Better distribution, reduces patterns
* **Example:** k = 85, m = 11 → h(85) = 85 mod 11 = 8

**2. Multiplication Method:**

$$h(k) = \lfloor m \times (kA \bmod 1) \rfloor, \quad 0 < A < 1$$

* **Knuth suggests:** $A \approx 0.6180339887$ (golden ratio - 1)
* **Less sensitive to m:** m can be power of 2
* **Steps:**
  1. Multiply k by A
  2. Extract fractional part
  3. Multiply by m
  4. Take floor
* **Example:** k = 123, m = 1000, A = 0.618
  * $kA = 76.014$
  * Fractional part = 0.014
  * $0.014 \times 1000 = 14$
  * h(123) = 14

**3. Mid-Square Method:**

* Square the key: $k^2$
* Extract middle r digits
* Use as hash value
* **Example:** k = 60, $k^2 = 3600$, middle 2 digits = 60

**4. Folding Method:**

* **Fold-Shift:** Split key into parts, add them
* **Fold-Boundary:** Reverse alternate parts before adding
* **Example:** k = 123456789
  * Split: 123 | 456 | 789
  * Add: 123 + 456 + 789 = 1368

**5. Universal Hashing (Advanced):**

$$h(k) = ((ak + b) \bmod p) \bmod m$$

* a, b are random coefficients
* p is prime > universe of keys
* Provides theoretical guarantees

***

#### **Collision**

A collision occurs in hashing when **two or more different keys are mapped to the same hash table index** by a hash function.

* When $h(k\_1) = h(k\_2)$ but $k\_1 \neq k\_2$
* **Unavoidable when:** $n > m$ (Pigeonhole Principle)
* **Types:**
  * **Primary Clustering:** Long runs of occupied slots (in Linear Probing)
  * **Secondary Clustering:** Keys follow same probe sequence (in Quadratic Probing)

**Collision Resolution Techniques**

* **A. Separate Chaining (Closed Addressing)**
* **B. Open Addressing (Open Hashing)**
  1. Linear Probing
  2. Quadratic Probing
  3. Double Hashing

**A. Separate Chaining (Closed Addressing)**

**Method:**

* Each table slot contains pointer to linked list
* All keys hashing to same index stored in that list

**Operations:**

* **Insert:**

```
1. Compute h(k)
2. Insert k at head of list at table[h(k)]
3. Time: O(1)
```

* **Search:**

```
1. Compute h(k)
2. Traverse list at table[h(k)]
3. Time: O(1 + α) average
```

* **Delete:**

```
1. Compute h(k)
2. Search in list at table[h(k)]
3. Delete node
4. Time: O(1 + α) average
```

**Time Complexity:**

* **Best Case:** $O(1)$ when all keys in different slots
* **Average Case:** $O(1 + \alpha)$ where $\alpha = n/m$
* **Worst Case:** $O(n)$ when all keys hash to same slot (single long chain)

**Space Complexity:**

* $O(n + m)$

**Expected chain length:**

* $\alpha = n/m$

**Advantages:**

* Simple implementation
* Table never fills ($\alpha$ can be > 1)
* Deletion is easy
* Less sensitive to hash function quality

**Disadvantages:**

* Extra memory for pointers
* Cache unfriendly (poor locality)
* Memory overhead per node

**GATE Formula:**

* Average search time = $1 + \frac{\alpha}{2}$ (successful search)
* Average search time = $\alpha$ (unsuccessful search)

**B. Open Addressing (Open Hashing)**

**Method:**

* All keys stored in table itself
* No external storage
* One key per slot
* **Critical:** $\alpha < 1$ (must have empty slots)

**Probe Sequence:** $h(k, i)$ where i = 0, 1, 2, ..., m-1

**General Algorithm:**

```
Insert(k):
  i = 0
  repeat:
    j = h(k, i)
    if table[j] is empty or deleted:
      table[j] = k
      return j
    i = i + 1
  until i == m
```

**1. Linear Probing:**

$$h(k, i) = (h(k) + i) \bmod m$$

* **Probe sequence:** $h(k), h(k)+1, h(k)+2, ..., (h(k)+m-1) \mod m$
* **Example:** $h(k) = 5$, $m = 10$
  * Sequence: 5, 6, 7, 8, 9, 0, 1, 2, 3, 4
* **Primary Clustering:**
  * Long runs of occupied consecutive slots form
  * Increases average search time
  * New keys tend to cluster around existing clusters
* **Number of probes (average):**
  * **Successful search:** $\frac{1}{2}(1 + \frac{1}{1-\alpha})$
  * **Unsuccessful search:** $\frac{1}{2}(1 + \frac{1}{(1-\alpha)^2})$
* **Advantages:**
  * Best cache performance
  * No extra memory
* **Disadvantages:**
  * Severe primary clustering
  * Performance degrades rapidly as $\alpha \to 1$

**2. Quadratic Probing:**

$$h(k, i) = (h(k) + c_1 i + c_2 i^2) \bmod m$$

* Common choice: $c\_1 = 0, c\_2 = 1$ → $h(k, i) = (h(k) + i^2) \bmod m$
* **Probe sequence:** $h(k), h(k)+1, h(k)+4, h(k)+9, h(k)+16, ...$
* **Secondary Clustering:**
  * Keys with same initial hash follow same probe sequence
  * Less severe than primary clustering
* **Important Theorem:**
  * If m is prime and $\alpha \leq 0.5$, quadratic probing will find empty slot
* **Advantages:**
  * Eliminates primary clustering
  * Better than linear probing
* **Disadvantages:**
  * Secondary clustering
  * May not probe all slots
  * Requires m to be prime for guarantee

**3. Double Hashing:**

$$h(k, i) = (h_1(k) + i \times h_2(k)) \bmod m$$

* Uses two hash functions: $h\_1(k)$ and $h\_2(k)$
* **Critical requirement:** $h\_2(k)$ must never be 0
* **Best practice:** $h\_2(k)$ relatively prime to m
* **Common choices:**
  * $h\_1(k) = k \bmod m$
  * $h\_2(k) = 1 + (k \bmod m')$ where $m' < m$
  * If m is prime: $h\_2(k) = 1 + (k \bmod (m-1))$
* **Example:**
  * m = 13, $h\_1(k) = k \bmod 13$, $h\_2(k) = 1 + (k \bmod 11)$
  * k = 14: $h\_1(14) = 1$, $h\_2(14) = 4$
  * Sequence: 1, 5, 9, 0, 4, 8, 12, 3, 7, 11, 2, 6, 10
* **Advantages:**
  * Best distribution among open addressing
  * Eliminates both primary and secondary clustering
  * Different keys have different probe sequences
* **Number of probes (average):**
  * **Successful search:** $\frac{1}{\alpha} \ln(\frac{1}{1-\alpha})$
  * **Unsuccessful search:** $\frac{1}{1-\alpha}$

**Comparison Table**

| Technique         | Primary Cluster | Secondary Cluster | Probes (Success)                          | Probes (Fail)                             | Cache Performance |
| ----------------- | --------------- | ----------------- | ----------------------------------------- | ----------------------------------------- | ----------------- |
| Chaining          | No              | No                | $1 + \alpha/2$                            | $\alpha$                                  | Poor              |
| Linear Probing    | Yes             | No                | $\frac{1}{2}(1 + \frac{1}{1-\alpha})$     | $\frac{1}{2}(1 + \frac{1}{(1-\alpha)^2})$ | Best              |
| Quadratic Probing | No              | Yes               | Medium                                    | Medium                                    | Good              |
| Double Hashing    | No              | No                | $\frac{1}{\alpha}\ln(\frac{1}{1-\alpha})$ | $\frac{1}{1-\alpha}$                      | Good              |

**Deletion in Hashing**

**Chaining:**

* Simply delete node from linked list
* No special handling needed
* Time: $O(1 + \alpha)$

**Open Addressing:**

* **Problem:** Cannot simply mark slot as empty
* **Why?** Breaks probe sequence for future searches
* **Solution:** Lazy Deletion (mark as DELETED)

**States of a slot:**

* **EMPTY:** Never used
* **OCCUPIED:** Contains key
* **DELETED:** Had key, now removed

**Search algorithm:**

* Continue probing through DELETED slots
* Stop only at EMPTY slot

**Insert algorithm:**

* Can reuse DELETED slots
* Stop at first DELETED or EMPTY slot

**GATE Important:** Search stops at EMPTY, not DELETED

**Load Factor Effects**

**Definition:** $\alpha = \frac{n}{m} = \frac{\text{number of keys\}}{\text{table size\}}$

**Chaining:**

* $\alpha$ can be > 1
* Average chain length = $\alpha$
* Performance degrades linearly with $\alpha$

**Open Addressing:**

* Must maintain $\alpha < 1$
* Performance degrades exponentially as $\alpha \to 1$
* Recommended: $\alpha \leq 0.7$ for good performance

**Critical values:**

* $\alpha = 0.5$: Reasonable performance
* $\alpha = 0.7$: Typical rehashing threshold
* $\alpha = 0.9$: Severe performance degradation
* $\alpha = 1.0$: Table full (open addressing fails)

**Rehashing**

**When to rehash:**

* When $\alpha$ exceeds threshold (typically 0.7)
* Table becomes too full
* Too many collisions

**Process:**

1. Create new table of size $m' \approx 2m$ (choose prime)
2. Recompute hash for all keys
3. Insert all keys into new table
4. Delete old table

**Time Complexity:**

* $O(n)$ to rehash all n keys
* Amortized cost: $O(1)$ per insertion

**GATE Note:** Rehashing changes all hash values (new table size)

**Time Complexity Summary**

**Average Case (with good hash function):**

| Operation        | Chaining        | Open Addressing   |
| ---------------- | --------------- | ----------------- |
| Insert           | $O(1)$          | $O(1/(1-\alpha))$ |
| Search (success) | $O(1 + \alpha)$ | Varies by method  |
| Search (fail)    | $O(1 + \alpha)$ | $O(1/(1-\alpha))$ |
| Delete           | $O(1 + \alpha)$ | $O(1/(1-\alpha))$ |

**Worst Case:**

* **Chaining:** $O(n)$ - all keys in one chain
* **Open Addressing:** $O(n)$ - must probe entire table

**Space Complexity:**

* **Chaining:** $O(n + m)$ - table + linked lists
* **Open Addressing:** $O(m)$ - table only

**Applications**

1. **Symbol Tables:** Compiler design, variable storage
2. **Databases:** Index structures, quick lookups
3. **Caching:** Web browsers, DNS cache
4. **Sets/Maps:** Dictionary implementations
5. **Password Storage:** Hash + salt
6. **Checksums:** Data integrity verification
7. **Cryptography:** Digital signatures, blockchain
8. **Routers:** IP address lookup
9. **Spell Checkers:** Word lookup
10. **Duplicate Detection:** File systems

**GATE Focus Points**

1. **Hash function identification:** Division, multiplication, mid-square
2. **Collision resolution:** Identify chaining vs open addressing
3. **Probe sequence calculation:** Linear, quadratic, double hashing
4. **Number of comparisons:** Given $\alpha$ and technique
5. **Clustering detection:** Primary vs secondary
6. **Lazy deletion:** When to stop search in open addressing
7. **Load factor calculations:** Effect on performance
8. **Rehashing:** When triggered, new table size
9. **Prime table sizes:** Why important for division method
10. **Double hashing requirements:** $h\_2(k) \neq 0$, relatively prime to m

**Common GATE Traps**

1. **Linear Probing Stop Condition:**
   * Stop at EMPTY slot, NOT at DELETED slot
   * DELETED slots must be probed through
2. **Open Addressing Load Factor:**
   * Must maintain $\alpha < 1$
   * Table can become full
3. **Prime Table Size:**
   * Division method works best with prime m
   * Avoids patterns and improves distribution
4. **Double Hashing Independence:**
   * $h\_2(k)$ must be independent of $h\_1(k)$
   * $h\_2(k)$ must never return 0
5. **Quadratic Probing Guarantee:**
   * Only guaranteed to find slot if m is prime and $\alpha \leq 0.5$
6. **Chaining vs Open Addressing:**
   * Chaining allows $\alpha > 1$
   * Open addressing requires $\alpha < 1$
7. **Deletion in Open Addressing:**
   * Cannot simply empty the slot
   * Must use lazy deletion (DELETED marker)
8. **Rehashing Effect:**
   * All hash values change (new m)
   * Not just copying keys to new table

**Key Formulae (Must Remember)**

**Load Factor:** $$\alpha = \frac{n}{m}$$

**Division Method:** $$h(k) = k \bmod m$$

**Multiplication Method:** $$h(k) = \lfloor m \times (kA \bmod 1) \rfloor$$

**Linear Probing:** $$h(k, i) = (h(k) + i) \bmod m$$

**Quadratic Probing:** $$h(k, i) = (h(k) + c_1 i + c_2 i^2) \bmod m$$

**Double Hashing:** $$h(k, i) = (h_1(k) + i \times h_2(k)) \bmod m$$

**Average Probes (Linear Probing - Success):** $$\frac{1}{2}\left(1 + \frac{1}{1-\alpha}\right)$$

**Average Probes (Linear Probing - Failure):** $$\frac{1}{2}\left(1 + \frac{1}{(1-\alpha)^2}\right)$$

**Average Search Time (Chaining - Success):** $$1 + \frac{\alpha}{2}$$

**Average Search Time (Chaining - Failure):** $$\alpha$$

**Performance Comparison Chart**

**For $\alpha = 0.5$:**

| Method            | Successful Search | Unsuccessful Search |
| ----------------- | ----------------- | ------------------- |
| Chaining          | 1.25 probes       | 0.5 probes          |
| Linear Probing    | 1.5 probes        | 2.5 probes          |
| Quadratic Probing | \~1.4 probes      | \~2.2 probes        |
| Double Hashing    | 1.39 probes       | 2 probes            |

**For $\alpha = 0.9$:**

| Method            | Successful Search | Unsuccessful Search |
| ----------------- | ----------------- | ------------------- |
| Chaining          | 1.45 probes       | 0.9 probes          |
| Linear Probing    | 5.5 probes        | 50.5 probes         |
| Quadratic Probing | \~3 probes        | \~10 probes         |
| Double Hashing    | 2.56 probes       | 10 probes           |

**Final Insights**

1. **Hashing provides $O(1)$ average time, NOT worst case**
2. **Choice of hash function critically affects performance**
3. **Load factor is the single most important performance metric**
4. **Open addressing degrades faster than chaining as $\alpha$ increases**
5. **Double hashing is theoretically best for open addressing**
6. **Linear probing is practically fastest due to cache locality**
7. **Prime table sizes matter for division method and quadratic probing**
8. **Lazy deletion is essential for open addressing**
9. **Rehashing is expensive but necessary for maintaining performance**
10. **Universal hashing provides theoretical worst-case guarantees**
