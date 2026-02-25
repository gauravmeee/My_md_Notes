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

# DSA: Important Time Complexities

## Asymptotic Notations in Time Complexity

**1. Big-O Notation** `O(f(n))`

* **Worst-case** time complexity.
* Upper bound: algorithm takes **at most** `f(n)` time.
* **Used most commonly** in contests/interviews.
* **Example**: Binary Search → `O(log n)`

**2. Omega Notation** `Ω(f(n))`

* **Best-case** time complexity.
* Lower bound: algorithm takes **at least** `f(n)` time.
* Not very useful alone, because best case may be rare.
* **Example**: Linear Search → `Ω(1)` (if element is at first position)

**3. Theta Notation** `Θ(f(n))`

* **Tight bound** (best and worst both are `f(n)`).
* Algorithm always takes **exactly** `f(n)` time asymptotically.
* **Example**: Merge Sort → `Θ(n log n)`

***

## Complete Recurrence Solutions

#### Part A: Decremental Recurrences $T(n) = a \cdot T(n-b) + f(n)$

**General Form**

$$\boxed{T(n) = a \cdot T(n - b) + f(n)}$$

* where:
  * $a \geq 1$ (<mark>branching factor</mark>)
  * $b > 0$ (<mark>constant decrement</mark>)
  * $f(n)$ is the <mark>non-recursive cost</mark>

**Solution by Unrolling**

* Expand the recurrence $k$ times where $k \approx n/b$:

$$T(n) = a^k \cdot T(n - k \cdot b) + \sum_{i=0}^{k-1} a^i \cdot f(n - i \cdot b)$$

* At base case: $k = n/b$, so $T(0)$ or $T(1) = c$ (constant)

**Case 1: $a < 1$ (<mark>Shrinking Recursion</mark>)**

* **Behavior:** Exponential term $a^k \to 0$ as $k \to \infty$
* **Dominant term:** The summation
* **Result:** $$\boxed{T(n) \approx \sum_{i=0}^{n/b} a^i \cdot f(n - i \cdot b)}$$
* If $f(n)$ is **non-decreasing**, the largest term is $f(n)$:

$$T(n) = O\left(\frac{f(n)}{1-a}\right)$$

> This only work if $f(n)$ is non-decreasing

**Case 2: $a = 1$ (<mark>Linear Accumulation</mark>)**

* **Behavior:** No exponential growth/decay
* **Recurrence becomes:** $$T(n) = T(n-b) + f(n)$$
* **Solution:** Direct summation of all levels

$$\boxed{T(n) = \sum_{i=0}^{n/b - 1} f(n - i \cdot b)}$$

* **Common subcases:**

| $f(n)$         | Result                    | **Can Be Understand as** `T(n-b) * F(n)` ⭐ |
| -------------- | ------------------------- | ------------------------------------------ |
| $c$ (constant) | $T(n) = \Theta(n)$        | `n * c` => `O(n)`                          |
| $n$            | $T(n) = \Theta(n^2)$      | `n * n` => `O(n^2)`                        |
| $n^2$          | $T(n) = \Theta(n^3)$      | `n * n^2` => `O(n^3)`                      |
| $\log n$       | $T(n) = \Theta(n \log n)$ | `n * logn` => `O(nlogn)`                   |

**Case 3: $a > 1$ (<mark>Exponential Growth</mark>)**

* **Behavior:** Exponential term $a^{n/b}$ dominates
* **Recurrence becomes:** $$\boxed{T(n) = a^{n/b} \cdot T(0) + \sum_{i=0}^{n/b - 1} a^i \cdot f(n - i \cdot b)}$$
* **If $f(n)$ is polynomial:**

$$T(n) = \Theta(a^{n/b})$$

* The exponential term **always dominates** polynomial $f(n)$.

> Note: Skipping $f(n)$ only work if $f(n)$ is polynomial (or smaller than exponential)

**General Unrolled Formula for Decremental Recurrence**

**Full Formula** $$\boxed{T(n) = a^{n/b} \cdot T(0) + \sum_{i=0}^{n/b - 1} a^i \cdot f(n - i \cdot b)}$$

**Case 1: $a < 1$ (shrinking recursion)**

* Exponential term: $a^{n/b} \cdot T(0) \to 0$ (as $n \to \infty$)
* Skip $a^{n/b} T(0)$ Term
* $T(n) \approx \sum\_{i=0}^{n/b - 1} a^i \cdot f(n - i \cdot b)$

**Case 2: $a = 1$ (linear accumulation)**

* Exponential terms: $a^{n/b} = 1$, $a^i = 1$ → no geometric growth
* Skip $a^{n/b}.T(0)$ & $a^i$ Terms
* $T(n) = \sum\_{i=0}^{n/b - 1} f(n - i \cdot b)$

**Case 3: $a > 1$ (exponential growth)**

* Exponential term dominates → **cannot skip anything**
* Use full formula
* $T(n) = a^{n/b} \cdot T(0) + \sum\_{i=0}^{n/b - 1} a^i \cdot f(n - i \cdot b)$

**Summary Table: $T(n) = a \cdot T(n-b) + f(n)$**

| Case | Condition | Dominant Term          | Result                                                                                        |
| ---- | --------- | ---------------------- | --------------------------------------------------------------------------------------------- |
| 1    | $a < 1$   | Summation term         | $O(f(n))$ if $f$ non-decreasing                                                               |
| 2    | $a = 1$   | All terms equal weight | <p>$\Theta\left(n \cdot f(n)\right)$ if $f$ constant<br>$\Theta(n^{k+1})$ if $f(n) = n^k$</p> |
| 3    | $a > 1$   | Exponential term       | $\Theta(a^{n/b})$                                                                             |

* `a < 1` → **F(n) dominates**
* `a = 1` → **F(n) repeats**
* `a > 1` → **T(n) dominates**

**\*\*My Conclusion ⭐**

**Case 1: a < 1**

* Recursive term keeps shrinking
* `T(n-b)` becomes very small
* `F(n)` dominates

```
T(n) ≈ F(n)
```

**Case 2: a = 1**

* Recursive term stays same size
* `F(n)` added again and again
* Both matter, but repetition dominates

```
T(n) ≈ n · F(n)
```

**Case 3: a > 1** ⭐

* Recursive term grows fast
* `T(n-b)` dominates over `F(n)`
* `F(n)` becomes negligible

```
T(n) ≈ a^(n/b)   exponential
```

**Examples**

**Case 1**

* **Example:** $T(n) = 0.5 \cdot T(n-1) + n$ $\begin{align} a &= 0.5 < 1\ T(n) &= \sum\_{i=0}^{n-1} (0.5)^i \cdot (n-i)\ &\approx O(n) \quad \text{(geometric series with } a < 1\text{)} \end{align}$

**Case 2**

* **Example:** $T(n) = T(n-1) + c$ $T(n) = c \cdot n = \Theta(n)$
* **Example:** $T(n) = T(n-1) + n$ $T(n) = n + (n-1) + (n-2) + \cdots + 1 = \frac{n(n+1)}{2} = \Theta(n^2)$
* **Example 3:** $T(n) = T(n-2) + n$ $T(n) = n + (n-2) + (n-4) + \cdots = \Theta(n^2)$

**Case 3**

* **Example:** $T(n) = 2 \cdot T(n-1) + n$ $\begin{align} a = 2 > 1 \quad T(n) = 2^n \cdot T(0) + \sum\_{i=0}^{n-1} 2^i \cdot (n-i) = \Theta(2^n) \quad \text{(exponential dominates)} \end{align}$
* **Example:** $T(n) = 3 \cdot T(n-2) + n^2$ $\begin{align} a &= 3 > 1 \quad T(n) = 3^{n/2} \cdot c + \text{lower order terms} = \Theta(3^{n/2}) = \Theta(\sqrt{3}^n) \end{align}$
* **Example:** $2T(n-1) + n2^n$ $a=2 >1 \quad T(n) = 2^n + \sum\_{i=0}^{n-1} 2^i \cdot [(n-i) \cdot 2^{n-i}] = 2^n \sum_{i=0}^{n-1} (n-i) + 2^n$ $T(n) = 2^n \cdot \frac{n(n+1)}{2} + 2^n \sim \Theta(n^2 \cdot 2^n)$

***

#### Part B: Divide-and-Conquer Recurrences — Master Theorem

**General Form**

$$\boxed{T(n) = a \cdot T(n/b) + f(n)}$$

**Constraints:**

* $a \geq 1$ (number of subproblems)
* $b > 1$ (input size reduction factor)
* $f(n)$ asymptotically positive

**Critical Parameter ⭐**

$$\boxed {c = \log_b(a)}$$

* This represents the **exponent of the recursive tree cost**.
* **Interpretation:** Compare $f(n)$ with $n^c$

**Case 1: $f(n)$ is polynomially smaller than $n^c$**

* **Condition:** $f(n) = O(n^{c-\epsilon})$ for some $\epsilon > 0$
* **Result:** $$T(n) = \Theta(n^c)$$
* **Intuition:** Recursive calls dominate.

**Case 2: $f(n)$ balances with $n^c$**

* **Condition:** $f(n) = \Theta(n^c \cdot \log^P n)$ for some $P$
* **Result:**

| Subcase | Condition | Solution                                |
| ------- | --------- | --------------------------------------- |
| 2a      | $P > -1$  | $T(n) = \Theta(n^c \cdot \log^{P+1} n)$ |
| 2b      | $P = -1$  | $T(n) = \Theta(n^c \cdot \log \log n)$  |
| 2c      | $P < -1$  | $T(n) = \Theta(n^c)$                    |

* **Intuition:** Work is evenly distributed across levels.

**Case 3: $f(n)$ is polynomially larger than $n^c$**

* **Condition:** $f(n) = \Omega(n^{c+\epsilon})$ for some $\epsilon > 0$
* **AND regularity condition:** $$a \cdot f(n/b) \leq k \cdot f(n) \text{ for some } k < 1 \text{ and sufficiently large } n$$
* **Result:**

| Subcase | Condition  | Solution                                                                      |
| ------- | ---------- | ----------------------------------------------------------------------------- |
| 3a      | $P \geq 0$ | $T(n) = \Theta(n^k \cdot \log^P n)$ where $f(n) = \Theta(n^k \cdot \log^P n)$ |
| 3b      | $P < 0$    | $T(n) = \Theta(n^k)$                                                          |

* **Intuition:** Root cost dominates.

**Examples**

**Case 1**

* **Example:** $T(n) = 4T(n/2) + n$ $\begin{align} a = 4, \quad b = 2, \quad f(n) = n, \quad c = log\_2(4) = 2, \quad k = 1 \end{align}$
  * **Compare:** $c = 2 > k = 1$ → **Case 1**
  * **Solution:** $T(n) = \Theta(n^2)$

**Case 2a**

* **Example:** $T(n) = 2T(n/2) + n$ $\begin{align} a &= 2, \quad b = 2, \quad f(n) = n, \quad c = log\_2(2) = 1, \quad f(n) = n^1 \cdot \log^0 n \Rightarrow k = 1, P = 0 \end{align}$
  * **Compare:** $c = k = 1$ → **Case 2a** ($P = 0 > -1$)
  * **Solution:** $T(n) = \Theta(n \log n)$

**Case 2b**

* **Example:** $T(n) = 2T(n/2) + \frac{n}{\log n}$ $\begin{align} a &= 2, \quad b = 2, \quad f(n) = n \cdot \log^{-1} n, \quad c = \log\_2(2) = 1, \quad k = 1, \quad P = -1 \end{align}$
  * **Compare:** $c = k = 1$ → **Case 2b** ($P = -1$)
  * **Solution:** $T(n) = \Theta(n \log \log n)$

**Case 2c**

* **Example:** $T(n) = 2T(n/2) + \dfrac{n}{\log^2 n}$ $\begin{align} a &= 2,\quad b = 2,\quad f(n) = n\cdot \log^{-2} n, \quad c = \log\_2(2) = 1 \quad k = 1,\quad P = -2 \end{align}$
  * **Compare:** (c = k = 1) → **Case 2c** ((P < -1))
  * **Solution:** $T(n) = \Theta(n)$

**Case 3a**

* **Example:** $T(n) = 2T(n/2) + n^2$) $\begin{align} a &= 2,\quad b = 2,\quad f(n) = n^2 \quad c = \log\_2(2) = 1 \quad k = 2,\quad P = 0 \end{align}$
  * **Compare:** (c = 1 < k = 2) → **Case 3a** ((P \ge 0))
  * **Solution:** $T(n) = \Theta(n^2)$

**Case 3b**

* **Example:** $T(n) = 2T(n/2) + n^2 \log n$ $\begin{align} a &= 2,\quad b = 2,\quad f(n) = n^2 \log n \quad c = 1 \quad k = 2,\quad P = 1 \end{align}$
  * **Compare:** (c < k) → **Case 3b**
  * **Solution:** $T(n) = \Theta(n^2 \log n)$

**Case 3c**

* **Example:** $T(n) = 2T(n/2) + \dfrac{n^2}{\log n}$ $\begin{align} a &= 2,\quad b = 2,\quad f(n) = n^2 \log^{-1} n \quad c = 1 \quad k = 2,\quad P = -1 \end{align}$
  * **Compare:** (c < k) → **Case 3c** ((P < 0))
  * **Solution:** $T(n) = \Theta(n^2)$

#### Key Differences

| Feature              | $T(n-b)$ (Decremental)    | $T(n/b)$ (Divide-and-Conquer)        |
| -------------------- | ------------------------- | ------------------------------------ |
| **Growth type**      | Arithmetic reduction      | Geometric reduction                  |
| **Number of levels** | $\Theta(n)$               | $\Theta(\log n)$                     |
| **When $a=1$**       | $\Theta(n \cdot f(n))$    | Use Master Theorem Case 2            |
| **When $a>1$**       | $\Theta(a^n)$ exponential | Depends on $f(n)$ vs $n^{\log\_b a}$ |
| **Master Theorem**   | **Does NOT apply**        | **Applies**                          |

***

### Time Complexity in Competitive Programming

**Summary ⭐**

* Most competitive programming platforms allow **\~10^8 operations per second**.
* Generally allowed time limit: 1–2 seconds.
* So, our algorithm should have **≤ 10^8 steps/operations**.

(Assume 1 input = 1 operation)

* $O(1) ≤ 10^8$ -----→ N can be very large (practically infinite)
* $O(log N) ≤ 10^8$ -----→ $N ≤ 2^{10^{8}}$ (extremely large, practically infinite)
* $O(N) ≤ 10^8$ -----→ $N ≤ 10^8$
* $O(N log N) ≤ 10^8$ -----→ $N ≤ 10^8 / log2(10^8) ≈ 3.7 × 10^6$
* $O(N^2) ≤ 10^8$ -----→ $N ≤ √(10^8) ≈ 10^4$
* $O(N^3) ≤ 10^8$ -----→ $N ≤ ∛(10^8) ≈ 464$
* $O(2^N) ≤ 10^8$ -----→ $N ≤ log2(10^8) ≈ 27$
* $O(N!) ≤ 10^8$ -----→ $N ≤ 12$

**How to Analyze Required Time Complexity for a Problem**

You need to estimate **what time complexity is acceptable based on the input size `n`**. Here's a practical guide:

**Note**: 1 In second \~ 10^7 to 10^8 operations in C++ (for competitive programming).

```
1 sec = ~10^8 operations    
For a time complexity function
Code within this limit is likely to run in time
```

| Input Size (`n`) | Acceptable Time Complexity |
| ---------------- | -------------------------- |
| ≤ 10             | `O(n!)`, `O(2^n)`          |
| ≤ 15–20          | `O(2^n)` or `O(n * 2^n)`   |
| ≤ 100            | `O(n^4)`                   |
| ≤ 1,000          | `O(n^3)`                   |
| ≤ 10,000         | `O(n^2)`                   |
| ≤ 1e5 (10^5)     | `O(n log n)`               |
| ≤ 1e6 (10^6)     | `O(n)`                     |
| \~1e9 (10^9)     | `O(log n)` or `O(1)`       |

**1. Given Input Size → Find Suitable Time Complexity**

* If input size is `x`
* Then choose a time complexity `f(n)` such that:\
  &#xNAN;**`f(x) < 10^8` (operations in 1 second limit)**

**2. Given Time Complexity → Find Maximum Input Size**

* If time complexity is `f(n)`
* Then choose the maximum input size `x` such that:\
  &#xNAN;**`f(x) < 10^8`**

**Note:** `f(x)` represents the **number of operations** your program performs for input size `x`, and it should satisfy , **`f(x) < 10^8`** to run within **1 second** (standard time limit in competitive programming).

**Why `10^8` Operations Matter in Competitive Programming ?**

When you write code for competitive programming, the **judge gives you 1 second** to run your solution for each test case. Now, a modern computer can perform around **10⁷ to 10⁸ basic C++ operations in 1 second**. So you should always make sure that:

* For a given input size, your code should **not do more than `10^8` operations**.
* If it does, the program will likely **TLE (Time Limit Exceeded)**.
* So you would need to optimise

This is why we estimate time complexity `f(n)` and ensure:

> **`f(n) < 10^8`**\
> So that your code completes within the time limit.

**Example**:\
If your algorithm is `O(n^2)`, then `n` must be ≤ `10^3`, because:\
→ `10^3 * 10^3 = 10^6` operations (safe)\
But if `n = 10^5`, then → `10^10` operations (TLE)

**Examples of Time Complexities and Max Input Sizes**

1. **Brute-force Search (2 nested loops)**
   * Time Complexity: `O(n^2)`
   * Max `n`: \~`10^3`
   * Example: Check all pairs `(i, j)` in an array
2. **Triple Nested Loop**
   * Time Complexity: `O(n^3)`
   * Max `n`: \~`100`
   * Example: Matrix multiplication (naive)
3. **Backtracking / Subset Generation**
   * Time Complexity: `O(2^n)`
   * Max `n`: \~`20`
   * Example: Generating all subsets, permutations
4. **Factorial Time**
   * Time Complexity: `O(n!)`
   * Max `n`: \~`10`
   * Example: Traveling Salesman Problem (TSP)
5. **Sorting Algorithms (Merge Sort, Quick Sort)**
   * Time Complexity: `O(n log n)`
   * Max `n`: \~`10^5 to 10^6`
   * Example: `std::sort()` in C++
6. **Binary Search**
   * Time Complexity: `O(log n)`
   * Max `n`: up to `10^9`
   * Example: Find element in sorted array
7. **Linear Search / Prefix Sum / One-pass Scan**
   * Time Complexity: `O(n)`
   * Max `n`: \~`10^7`
   * Example: Finding max in array
8. **Map / Set Insert-Search (Unordered)**
   * Time Complexity: `O(1)` average
   * Max `n`: \~`10^6`
   * Example: `unordered_map` in C++
9. **Heap / Priority Queue Operations**
   * Time Complexity: `O(log n)`
   * Max `n`: \~`10^6`
   * Example: Dijkstra's algorithm
10. **Dijkstra / BFS / DFS**
    * Time Complexity: `O(V + E)`
    * Max `V` or `E`: \~`10^5`
    * Example: Graph traversal
11. **Segment Tree / BIT (Fenwick Tree)**
    * Time Complexity: `O(log n)` per operation
    * Max `n`: \~`10^6`
    * Example: Range queries and updates
12. **Matrix Exponentiation / Fast Power**
    * Time Complexity: `O(log n)`
    * Max `n`: \~`10^18`
    * Example: Compute `a^b mod m`
13. **Sieve of Eratosthenes**
    * Time Complexity: `O(n log log n)`
    * Max `n`: \~`10^7`
    * Example: Prime numbers up to `n`
14. **DP with 1D array**
    * Time Complexity: `O(n)`
    * Max `n`: \~`10^6`
    * Example: Fibonacci with memoization
15. **DP with 2D array**
    * Time Complexity: `O(n^2)`
    * Max `n`: \~`1000`
    * Example: Longest Common Subsequence (LCS)
16. **Knapsack (DP O(n\*W))**
    * Time Complexity: `O(n * W)`
    * Max `n*W`: \~`10^7`
    * Example: 0/1 Knapsack

**Map Time Complexity**

**Map :**

* Implemented by self-balancing bst (like a Red-Black Tree)
* Ordered Map : The time complexity for insertion, deletion, and access is `O(log n)` **Unordered Map :**
* uses hash tables for faster lookups.
* The average time complexity for insertion, deletion, and access is `O(1)`, but in the worst case, it can degrade to `O(n)` if there are many hash collisions.
