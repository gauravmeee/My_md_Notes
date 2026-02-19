---
description: Made By Me 💚
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

# Cache Memory Access Time

#### **Average Memory Access Time (AMAT)**

**AMAT** is the _average time taken by the CPU to access data_, considering all possible memory access scenarios (hit/miss).

**2-Level AMAT Formula**

**Simultaneous Access** $$\boxed{AMAT = H \cdot T_c + (1-H)\cdot T_m}$$

**Hierarchical Access**

$$\boxed{AMAT = T_c + (1-H)\cdot T_m}$$

**Where:**

* $T\_c$ = Cache access time
* $T\_m$ = Main memory access time
* $H$ = Cache hit ratio

**3-Level AMAT Formula**

**Simultaneous Access**

$$$
AMAT = H_1T_1 + (1-H_1)\Big[H_2T_2 + (1-H_2)T_m\Big]  
}$$

**Hierarchical Access**
$$\boxed{  
AMAT = T_1 + (1-H_1)\Big[T_2 + (1-H_2)T_m\Big]  
}$$

**Where:**
- $T_1$ = L1 cache access time
- $T_2$ = L2 cache access time
- $T_m$ = Main memory access time
- $H_1$ = L1 hit ratio
- $H_2$ = L2 hit ratio **(given L1 miss)**

##### **1. Simultaneous Access Model**

**Idea**
- **Cache and Main Memory are accessed at the same time**
- CPU does **not wait** to know whether it’s a hit or miss

**What happens?**
- If **cache hit** → data comes from cache
- If **cache miss** → data already coming from main memory (==no extra wait==)
    
**AMAT Formula**
 
$$\boxed{AMAT = H \cdot T_c + (1-H)\cdot T_m}$$
    
**Reason (WHY this formula?)**
- Both memories are accessed **in parallel**
- Time depends on **where the data is finally taken from**
- ==No **miss penalty**== added separately ⭐

**Characteristics**
- Simple logic : )
- **Wastes memory bandwidth**   : (
- Expensive hardware : (
- **Rare in real systems** : (


###### **2. Hierarchical (Sequential) Access Model** ⭐ (Most Important)

**Idea**
- Memory is ==accessed **level by level**==
- Cache first → then main memory **only if miss occurs**
    

**What happens?**
1. CPU checks **cache**
2. If **hit** → done
3. If **miss** → extra time to access main memory
    

**AMAT Formula**


$$\boxed{AMAT = T_c + (1-H)\cdot T_m}  $$

If miss penalty (P) is given separately:

$$AMAT = T_c + (1-H)\cdot P $$

Where:
- $P$ = Miss penalty (time to fetch block from next level)



**Reason (WHY this formula?)**
- ==Cache access time $T_c$ is **always paid**==
- Main memory time $T_m$ is paid **only on a miss**
- Hence ==weighted by miss ratio== ($1-H$)
    

**Characteristics**
- Efficient  : )
- No wasted bandwidth  : )
- **Used in real processors** : )


##### **Side-by-Side Comparison**

- **Simultaneous** → _Weighted average_ : $H.T_c + (1-H)T_m$  
- **Hierarchical** → _Cache time + miss cost_  : $T_c + (1-H)T_m$  

$$AMAT_\text{simultaneous} <= AMAT_\text{Hierarchical} \quad \because H<1$$

| Aspect               | Simultaneous | Hierarchical |
| -------------------- | ------------ | ------------ |
| Access style         | Parallel     | Sequential   |
| Cache checked first? | ❌            | ✅            |
| Miss penalty concept | ❌            | ✅            |
| Memory bandwidth     | Wasted       | Efficient    |
| Used in practice     | ❌            | ✅            |
| GATE relevance       | Low          | ⭐⭐⭐          |

---

# Three-Level Memory System

##### **1. Simultaneous Access (Parallel)**

- L1, L2, and Main Memory are accessed **simultaneously**
- CPU takes data from the **first level that hits**

**AMAT** for 3-Level Memory System

- Original Form:
$$\boxed{  
AMAT = H_1T_1 + (1-H_1)\Big[H_2T_2 + (1-H_2)T_m\Big]  
}$$
- Distribute $(1-H_1)$:
$$$

AMAT =\
H\_1 T\_1

* (1-H\_1)H\_2 T\_2
* (1-H\_1)(1-H\_2) T\_m\
  \$$

Let

* $T\_1$ = L1 cache access time
* $T\_2$ = L2 cache access time
* $T\_m$ = Main memory access time
* $H\_1$ = L1 hit ratio
* $H\_2$ = L2 hit ratio **(given L1 miss)**

**2. Hierarchical Access (Sequential) ⭐⭐⭐**

* Memory is accessed **level by level**
* L2 checked only if L1 misses
* Memory accessed only if both caches miss

**AMAT** for 3-Level Memory System

* Original Form:

$$$
AMAT = T_1 + (1-H_1)\Big[T_2 + (1-H_2)T_m\Big]  
}$$

- Distribute $(1-H_1)$:
$$$

AMAT =\
T\_1

* (1-H\_1)T\_2
* (1-H\_1)(1-H\_2)T\_m

***

#### **Understanding: Hierarchical vs Simultaneous Access**

| Model            | Is $T\_c$ always paid? | Is $T\_m$ always paid? |
| ---------------- | ---------------------- | ---------------------- |
| **Hierarchical** | Yes                    | No. Only on Miss       |
| **Simultaneous** | No. Only on Hit        | No. Only on Miss       |

**1. How the access starts**

* **Hierarchical:** CPU sends the address **only to cache**.
* **Simultaneous:** CPU sends the address **to cache and main memory at the same time**.

**2. What the CPU waits for**

* **Hierarchical:** CPU **must wait for cache** to finish lookup before doing anything else.
* **Simultaneous:** CPU waits for **the first valid data** from either cache or memory.

**3. Can cache access be skipped?**

* **Hierarchical:** No. Cache lookup **cannot be bypassed**, even on a miss.
* \==**Simultaneous:** Yes. Cache response can be **ignored** if memory responds first==.

**4. What happens on a cache miss**

* **Hierarchical:** Cache miss occurs **after cache time has already elapsed**.
* **Simultaneous:** Cache miss does **not delay** memory access, because memory is already running.

**5. Effect on cache access time**

* **Hierarchical:** Cache access time $T\_c$ is an **unconditional cost**. $\text{Every access pays } T\_c$
* **Simultaneous:** Cache access time $T\_c$ is a **conditional cost**. $\text{Cache time is paid only if cache supplies data}$

**6. Probability aspect**

* **Hierarchical:** Cache is always accessed ⇒ **no probability attached** to ($T\_c$). $\text{Cache time contribution} = T\_c$
* **Simultaneous:** Cache supplies data with probability (H). $\text{Cache time contribution} = H \cdot T\_c$

**7. Memory access behavior**

* **Hierarchical:** Memory is accessed **only after a cache miss**.
* **Simultaneous:** Memory is accessed **in parallel for every request**.

**8. Effect on memory access time**

* **Hierarchical:**\
  Memory time is an **extra delay**, paid only on miss. $\text{Memory cost} = (1-H)\cdot T\_m$
* **Simultaneous:** Memory time is a **possible completion time**, not a penalty. $\text{Memory cost} = (1-H)\cdot T\_m$

_(Same weighting, but different meaning)_

**9. Do delays accumulate?**

* **Hierarchical:** Yes. Cache time happens **first**, memory time happens **after**. $AMAT = T\_c + (1-H)T\_m$
* **Simultaneous:** No. Only **one component determines final time**. $AMAT = H T\_c + (1-H)T\_m$

**Interpretation of AMAT formula**

* **Hierarchical:** AMAT = **base cost + miss penalty**
* **Simultaneous:** AMAT = **expected value of response time** or
* **Hierarchical AMAT = base + penalties**
* **Simultaneous AMAT = weighted average**

**Final Conclusion (Lock This In)**

* In **hierarchical access**, cache access time is **always paid** because cache lookup is **mandatory and blocking**.
* In **simultaneous access**, cache access time is **paid only when cache supplies data**, because CPU accepts **the earliest valid response**.

***

## Special Concept: “Penalty already included” in next level time

> Similar Concept Question in GATE 2025

* If the access time of next level **already includes previous level miss penalty**, then **don’t use pure hierarchical (nested) formula directly**.
* Instead, use the **simultaneous-looking weighted formula**, because times are already \_cumulative.

Meaning:

* $t\_2$ already contains $t\_1$
* $t\_3$ already contains $(t\_1+t\_2)$

So **no need to subtract penalties**.

**2-level hierarchy: L1 → M**

**Given:**

* L1: $(H\_1, t\_1)$
* Memory: $t\_m$ includes L1 miss penalty (cumulative)

**1. Hierarchical Formula :**

$$\boxed{AMAT=t_1+(1-H_1)t_{m,actual}}$$

**2. Direct (cumulative time) formula :**

$$t_{m,actual}=t_m-t_1$$ $$=t_1+(1-H_1)(t_m-t_1)$$$$\boxed{AMAT = H_1t_1 + (1-H_1)t_m}$$

* This is Similar to Simultaneous Access

**3-level hierarchy (L1 → L2 → L3)**

Given:

* L1: $(H\_1, t\_1)$
* L2: $(H\_2, t\_2)$ where $t\_2$ includes L1 miss penalty
* L3: time $t\_3$ includes L1+L2 miss penalty

**1. Hierarchical Formula :**\
$$\boxed{t_1+(1-H_1)\Big((t_2-t_1)+(1-H_2)(t_3-t_2)\Big)}$$

**2. Direct (cumulative time) formula :**

$$t_{2,actual}=t_2-t_1$$$$t_{3,actual}=t_3-t_2$$$$=t_1+(1-H_1)\Big((t_2-t_1)+(1-H_2)(t_3-t_2)\Big)$$$$= t_1+(1-H_1)\Big(H_2t_2+(1-H_2)t_3-t_1\Big)$$$$= t_1+(1-H_1)(-t_1) + (1-H_1)\Big(H_2t_2+(1-H_2)t_3\Big)$$ $$\boxed{AMAT = H_1t_1 + (1-H_1)\Big(H_2t_2 + (1-H_2)t_3\Big)}$$

* This is Similar to Simultaneous Access

> If next-level access time is **cumulative (includes previous miss penalties)** ⇒ **use simultaneous weighted formula directly** (no subtraction needed), or subtract to get actual times and apply hierarchical formula (both give same AMAT).

**Ques. Given**

**L1:**

* Hit rate $H\_1 = 0.95$
* Access time $t\_1 = 10ns$

**L2:**

* Hit rate $H\_2 = 0.85$
* Access time including L1 miss penalty $t\_2 = 20ns$

**Main Memory:**

* Access time including L1 + L2 miss penalty $t\_m = 200ns$

> Gate 2025 Question

**Answer**

**Two ways to compute AMAT:**

1. Direct (simultaneous-looking) formula works when given times already include previous penalties
2. Hierarchical access formula works when you first convert times into actual per-level times (remove penalties)

**Way 1: Direct formula (times already include penalties)**

Since:

* $t\_2$ already includes L1 time
* $t\_m$ already includes L1+L2 time

So: $$AMAT = H_1t_1 + (1-H_1)\Big(H_2t_2 + (1-H_2)t_m\Big)$$

Put values: $$= 0.95(10) + 0.05\Big(0.85(20) + 0.15(200)\Big)$$ $$= 9.5 + 0.05(17 + 30)$$ $$= 9.5 + 0.05(47) = 9.5 + 2.35 = 11.85ns$$

$$\boxed{AMAT = 11.85ns}$$

**Way 2: Hierarchical formula (remove penalties first)**

Hierarchical AMAT formula: $$AMAT = t_1 + (1-H_1)\Big(t_{2,actual} + (1-H_2)t_{m,actual}\Big)$$

**Step 1: Remove penalties**

L2 given time includes L1: $$t_{2,actual} = t_2 - t_1 = 20 - 10 = 10ns$$

Main memory time includes (L1+L2 total path time). Given $t\_m = 200$ includes $t\_2 = 20$ (and that 20 already includes L1): $$t_{m,actual} = t_m - t_2 = 200 - 20 = 180ns$$

**Important note:** $$t_{m,actual} \ne 200 - 20 - 10$$ because 10 is already inside 20

**Step 2: Apply hierarchical formula**

$$AMAT = 10 + 0.05\Big(10 + 0.15(180)\Big)$$ $$= 10 + 0.05(10 + 27)$$ $$= 10 + 0.05(37) = 10 + 1.85 = 11.85ns$$

$$\boxed{AMAT = 11.85ns}$$

### Understanding: Why both methods give same answer

* Way 1 uses $t\_2, t\_m$ as cumulative times (already include previous penalties)
* Way 2 converts them into pure level times and then applies hierarchical nesting
* Both represent the same expectation, so same result

***
