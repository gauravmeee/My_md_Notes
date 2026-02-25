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

# Algorithm: Time Complexity Recurrence Relation

**1. What is a Recurrence Relation?**

A recurrence defines **T(n)** in terms of **smaller inputs** like T(n/2), T(n–1), etc.

Example:

* `T(n) = T(n−1) + 1` → Linear recursion
* `T(n) = 2T(n/2) + n` → Divide and Conquer recursion

**2. Methods to Solve Recurrence**

* (a) **Substitution / Recursion Tree**
* (b) **Master Theorem**
* (c) **Iteration / Expansion**

**3. Master Theorem ⭐**

Applies to:

**`T(n) = a·T(n/b) + f(n)`**\
where:

* `a ≥ 1` (number of subproblems)
* `b > 1` (factor subproblem size reduces by)
* `f(n)` = cost outside recursion

**3 Cases:**

| Case | Compare `f(n)` to `n^log_b(a)`          | Result                             |
| ---- | --------------------------------------- | ---------------------------------- |
| 1    | `f(n) = O(n^log_b(a – ε))`              | **`T(n) = Θ(n^log_b(a))`**         |
| 2    | `f(n) = Θ(n^log_b(a))`                  | **`T(n) = Θ(n^log_b(a) · log n)`** |
| 3    | `f(n) = Ω(n^log_b(a + ε)) + regularity` | **`T(n) = Θ(f(n))`**               |

Example 1: **`T(n) = 2T(n/2) + n`**

```
a = 2, b = 2 ⇒ n^log₂2 = n  
f(n) = n = Θ(n)  
→ Case 2 ⇒ T(n) = Θ(n log n)
```

Example 2: **`T(n) = 4T(n/2) + n²`** ⭐

```
a = 4, b = 2 ⇒ n^log₂4 = n²  
f(n) = n² = Θ(n²)  
→ Case 2 ⇒ T(n) = Θ(n² log n)
```

Example 3: **`T(n) = 2T(n/2) + 1`**

```
a = 2, b = 2 ⇒ n^log₂2 = n  
f(n) = 1 = O(n^1–ε)  
→ Case 1 ⇒ T(n) = Θ(n)
```

Example 4: `T(n) = T(n/2) + n²`

```
a = 1, b = 2 ⇒ n^log₂1 = 1  
f(n) = n² = Ω(n^1+ε), regularity holds  
→ Case 3 ⇒ T(n) = Θ(n²)
```

**4. Recursion Tree Method**

* Draw the recursive tree level by level
* Find cost at each level
* Add all levels' costs

Example: **`T(n) = 2T(n/2) + n`**

* Level 0: `n`
* Level 1: `2 × (n/2)` = `n`
* Level 2: `4 × (n/4)` = `n`
* … log n levels ⇒ Total = `n log n`

**5. Substitution (Iterative Method)**

Expand recurrence step-by-step:

**`T(n) = 2T(n/2) + n`**\
\= `2[2T(n/4) + n/2] + n` = `4T(n/4) + n + n` = `8T(n/8) + 3n` After k steps:\
&#xNAN;**`T(n) = 2^k · T(n/2^k) + k·n`**

Let n/2^k = 1 ⇒ k = log n\
⇒ `T(n) = n·T(1) + n·log n = Θ(n log n)`

**6. Important Recurrence Examples**

| Recurrence            | Solution      |
| --------------------- | ------------- |
| `T(n) = T(n–1) + 1`   | `Θ(n)`        |
| `T(n) = T(n–1) + n`   | `Θ(n²)`       |
| `T(n) = 2T(n/2) + n`  | Θ(n log n)    |
| `T(n) = 4T(n/2) + n²` | `Θ(n² log n)` |
| `T(n) = T(n/2) + 1`   | `Θ(log n)`    |
| `T(n) = 2T(n/2) + 1`  | `Θ(n)`        |
| `T(n) = 8T(n/2) + n³` | `Θ(n³ log n)` |
| `T(n) = T(n/2) + n`   | `Θ(n)`        |

***

Here’s the same format for **Decreasing Type Recurrence**:

***

#### **Topic: Recurrence of Decreasing Type (Linear Decrease)**

**General Form**

```
T(n) = a · T(n − b) + f(n)
```

Let:

```
E = n / b
```

**Case 1: a < 1**

* Recursive term dies quickly

```
T(n) = Θ(f(n))
```

**Case 2: a = 1**

* Linear number of calls: `E = n/b`

```
T(n) = Θ(n · f(n))
```

**Case 3: a > 1**

* Exponential number of calls: `≈ a^(n/b)`

```
T(n) = Θ(a^{n/b} · f(n))
```

***

**Master Theorem (Dividing Type Recurrence)**

**General Form**

```
T(n) = a · T(n / b) + f(n)
```

Compare `f(n)` with `n^log_b(a)`

Let:

```
E = log_b(a)
```

**Case 1: f(n) = O(n^E−ε)** for some ε > 0

* f(n) is **polynomially smaller** than `n^E`

```
T(n) = Θ(n^E)
```

**Case 2: f(n) = Θ(n^E · log^k n)** for some k ≥ 0

* f(n) is **equal** to `n^E` (up to log factors)

```
T(n) = Θ(n^E · log^{k+1} n)
```

**Case 3: f(n) = Ω(n^E+ε)** for some ε > 0,\
and **regularity condition** holds:\
`a · f(n/b) ≤ c · f(n)` for some c < 1

* f(n) is **polynomially bigger** than `n^E`

```
T(n) = Θ(f(n))
```

***

**Asymptotic Analysis of Recurrence Relations ( Decreasing vs Dividing Type)**

For **decreasing**, we usually give `O(...)` , while for **dividing**, we use **`Θ(...)` from Master Theorem**

**Decreasing Recurrence (e.g.,** `T(n) = a·T(n − b) + f(n)` **)**

* We **unroll** the recurrence manually.
* Behavior depends on **number of steps = n / b**
* So we often write final result as <mark>**`T(n) = O(...)`** (upper bound focus)</mark>
* Because the depth is predictable and **not exponential**, we **usually care about upper bound**.

**Dividing Recurrence (e.g.,** `T(n) = a·T(n / b) + f(n)` **)**

* Solved using the **Master Theorem**.
* It gives <mark>**tight bound**,</mark> not just upper.
* So we write <mark>**`T(n) = Θ(...)`** to express **exact asymptotic growth**</mark>.
