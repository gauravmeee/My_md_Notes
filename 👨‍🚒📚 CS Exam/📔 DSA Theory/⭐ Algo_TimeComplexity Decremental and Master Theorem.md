
# Complete Recurrence Solutions


## Part A: Decremental Recurrences $T(n) = a \cdot T(n-b) + f(n)$

##### **General Form**

$$\boxed{T(n) = a \cdot T(n - b) + f(n)}$$

- where:
	- $a \geq 1$ (==branching factor==)
	- $b > 0$ (==constant decrement==)
	- $f(n)$ is the ==non-recursive cost==

##### **Solution by Unrolling**

- Expand the recurrence $k$ times where $k \approx n/b$:

$$T(n) = a^k \cdot T(n - k \cdot b) + \sum_{i=0}^{k-1} a^i \cdot f(n - i \cdot b)$$

- At base case: $k = n/b$, so $T(0)$ or $T(1) = c$ (constant)

###### **Case 1: $a < 1$ (==Shrinking Recursion==)**

- **Behavior:** Exponential term $a^k \to 0$ as $k \to \infty$
- **Dominant term:** The summation
- **Result:** $$T(n) \approx \sum_{i=0}^{n/b} a^i \cdot f(n - i \cdot b)$$
- If $f(n)$ is **non-decreasing**, the largest term is $f(n)$:

$$T(n) = O\left(\frac{f(n)}{1-a}\right)$$

##### **Case 2: $a = 1$ (==Linear Accumulation==)**

- **Behavior:** No exponential growth/decay
- **Recurrence becomes:** $$T(n) = T(n-b) + f(n)$$
- **Solution:** Direct summation of all levels

$$T(n) = \sum_{i=0}^{n/b - 1} f(n - i \cdot b)$$

- **Common subcases:**

| $f(n)$         | Result                    | **Can Be Understand as** `F(n)*T(n-b)` ⭐ |
| -------------- | ------------------------- | ---------------------------------------- |
| $c$ (constant) | $T(n) = \Theta(n)$        | `c * n` => `O(n)`                        |
| $n$            | $T(n) = \Theta(n^2)$      | `n * n` => `O(n^2)`                      |
| $n^2$          | $T(n) = \Theta(n^3)$      | `n * n^2` => `O(n^3)`                    |
| $\log n$       | $T(n) = \Theta(n \log n)$ | `n * logn` => `O(nlogn)`                 |


##### **Case 3: $a > 1$ (==Exponential Growth==)**

- **Behavior:** Exponential term $a^{n/b}$ dominates
- **Recurrence becomes:** $$T(n) = a^{n/b} \cdot T(0) + \sum_{i=0}^{n/b - 1} a^i \cdot f(n - i \cdot b)$$

- **If $f(n)$ is polynomial:**

$$T(n) = \Theta(a^{n/b})$$

- The exponential term **always dominates** polynomial $f(n)$.



##### **Summary Table: $T(n) = a \cdot T(n-b) + f(n)$**

|Case|Condition|Dominant Term|Result|
|---|---|---|---|
|1|$a < 1$|Summation term|$O(f(n))$ if $f$ non-decreasing|
|2|$a = 1$|All terms equal weight|$\Theta\left(n \cdot f(n)\right)$ if $f$ constant<br>$\Theta(n^{k+1})$ if $f(n) = n^k$|
|3|$a > 1$|Exponential term|$\Theta(a^{n/b})$|

- `a < 1` → **F(n) dominates**
- `a = 1` → **F(n) repeats**    
- `a > 1` → **T(n) dominates**

###### **My Conclusion  ⭐

**Case 1: a < 1**
- Recursive term keeps shrinking
- `T(n-b)` becomes very small
- `F(n)` dominates
```
T(n) ≈ F(n)
```

**Case 2: a = 1**
- Recursive term stays same size
- `F(n)` added again and again
- Both matter, but repetition dominates
```
T(n) ≈ n · F(n)
```

**Case 3: a > 1** ⭐

- Recursive term grows fast
- `T(n-b)` dominates over `F(n)`
- `F(n)` becomes negligible
```
T(n) ≈ a^(n/b)   exponential
```


##### **Examples**

**Case 1**

- **Example:** $T(n) = 0.5 \cdot T(n-1) + n$
	$\begin{align} a &= 0.5 < 1\ T(n) &= \sum_{i=0}^{n-1} (0.5)^i \cdot (n-i)\ &\approx O(n) \quad \text{(geometric series with } a < 1\text{)} \end{align}$

**Case 2**

- **Example:** $T(n) = T(n-1) + c$ 
	$T(n) = c \cdot n = \Theta(n)$

- **Example:** $T(n) = T(n-1) + n$ 
	$T(n) = n + (n-1) + (n-2) + \cdots + 1 = \frac{n(n+1)}{2} = \Theta(n^2)$

- **Example 3:** $T(n) = T(n-2) + n$ 
	$T(n) = n + (n-2) + (n-4) + \cdots = \Theta(n^2)$

**Case 3**

- **Example:** $T(n) = 2 \cdot T(n-1) + n$
	$\begin{align} a &= 2 > 1\ T(n) &= 2^n \cdot T(0) + \sum_{i=0}^{n-1} 2^i \cdot (n-i)\ &= \Theta(2^n) \quad \text{(exponential dominates)} \end{align}$

- **Example:** $T(n) = 3 \cdot T(n-2) + n^2$
	$\begin{align} a &= 3 > 1\ T(n) &= 3^{n/2} \cdot c + \text{lower order terms}\ &= \Theta(3^{n/2}) = \Theta(\sqrt{3}^n) \end{align}$

---

## Part B: Divide-and-Conquer Recurrences — Master Theorem

##### **General Form**

$$\boxed{T(n) = a \cdot T(n/b) + f(n)}$$

**Constraints:**
- $a \geq 1$ (number of subproblems)
- $b > 1$ (input size reduction factor)
- $f(n)$ asymptotically positive


###### Critical Parameter ⭐

$$\boxed {c = \log_b(a)}$$ 

- This represents the **exponent of the recursive tree cost**.
- **Interpretation:** Compare $f(n)$ with $n^c$


##### **Case 1: $f(n)$ is polynomially smaller than $n^c$**

- **Condition:** $f(n) = O(n^{c-\epsilon})$ for some $\epsilon > 0$
- **Result:** $$T(n) = \Theta(n^c)$$
- **Intuition:** Recursive calls dominate.

##### **Case 2: $f(n)$ balances with $n^c$**

- **Condition:** $f(n) = \Theta(n^c \cdot \log^P n)$ for some $P$
- **Result:**

| Subcase | Condition | Solution                                |
| ------- | --------- | --------------------------------------- |
| 2a      | $P > -1$  | $T(n) = \Theta(n^c \cdot \log^{P+1} n)$ |
| 2b      | $P = -1$  | $T(n) = \Theta(n^c \cdot \log \log n)$  |
| 2c      | $P < -1$  | $T(n) = \Theta(n^c)$                    |

- **Intuition:** Work is evenly distributed across levels.


##### **Case 3: $f(n)$ is polynomially larger than $n^c$**

- **Condition:** $f(n) = \Omega(n^{c+\epsilon})$ for some $\epsilon > 0$
- **AND regularity condition:** $$a \cdot f(n/b) \leq k \cdot f(n) \text{ for some } k < 1 \text{ and sufficiently large } n$$
- **Result:**

|Subcase|Condition|Solution|
|---|---|---|
|3a|$P \geq 0$|$T(n) = \Theta(n^k \cdot \log^P n)$ where $f(n) = \Theta(n^k \cdot \log^P n)$|
|3b|$P < 0$|$T(n) = \Theta(n^k)$|

- **Intuition:** Root cost dominates.

##### **Examples**

**Case 1**
- **Example:** $T(n) = 4T(n/2) + n$
	$\begin{align} a = 4, \quad b = 2, \quad f(n) = n, \quad c = log_2(4) = 2, \quad k = 1 \end{align}$
	- **Compare:** $c = 2 > k = 1$ → **Case 1**
	- **Solution:** $T(n) = \Theta(n^2)$

**Case 2a**
- **Example:** $T(n) = 2T(n/2) + n$
	$\begin{align} a &= 2, \quad b = 2, \quad f(n) = n, \quad c = log_2(2) = 1, \quad f(n) = n^1 \cdot \log^0 n \Rightarrow k = 1,  P = 0 \end{align}$
	- **Compare:** $c = k = 1$ → **Case 2a** ($P = 0 > -1$)
	- **Solution:** $T(n) = \Theta(n \log n)$

**Case 2b**
- **Example:** $T(n) = 2T(n/2) + \frac{n}{\log n}$
	$\begin{align} a &= 2, \quad b = 2, \quad f(n) = n \cdot \log^{-1} n, \quad c = \log_2(2) = 1, \quad k = 1, \quad P = -1 \end{align}$
	- **Compare:** $c = k = 1$ → **Case 2b** ($P = -1$)
	- **Solution:** $T(n) = \Theta(n \log \log n)$

**Case 2c**
- **Example:**  $T(n) = 2T(n/2) + \dfrac{n}{\log^2 n}$
	$\begin{align}  a &= 2,\quad b = 2,\quad f(n) = n\cdot \log^{-2} n, \quad  c = \log_2(2) = 1 \quad  k = 1,\quad P = -2  \end{align}$  
	- **Compare:** (c = k = 1) → **Case 2c** ((P < -1))
	- **Solution:**   $T(n) = \Theta(n)$  


**Case 3a**
- **Example:**  $T(n) = 2T(n/2) + n^2$) 
    $\begin{align}  a &= 2,\quad b = 2,\quad f(n) = n^2 \quad  c = \log_2(2) = 1 \quad  k = 2,\quad P = 0  \end{align}$
	- **Compare:** (c = 1 < k = 2) → **Case 3a** ((P \ge 0))
	- **Solution:**  $T(n) = \Theta(n^2)$

**Case 3b**
- **Example:**  $T(n) = 2T(n/2) + n^2 \log n$
    $\begin{align}  a &= 2,\quad b = 2,\quad f(n) = n^2 \log n \quad  c = 1 \quad  k = 2,\quad P = 1  \end{align}$  
	- **Compare:** (c < k) → **Case 3b**
	- **Solution:** $T(n) = \Theta(n^2 \log n)$

**Case 3c**
- **Example:**  $T(n) = 2T(n/2) + \dfrac{n^2}{\log n}$
	$\begin{align}  a &= 2,\quad b = 2,\quad f(n) = n^2 \log^{-1} n \quad  c = 1 \quad  k = 2,\quad P = -1  \end{align}$
	- **Compare:** (c < k) → **Case 3c** ((P < 0))
	- **Solution:**  $T(n) = \Theta(n^2)$ 

---

### Key Differences

| Feature              | $T(n-b)$ (Decremental)    | $T(n/b)$ (Divide-and-Conquer)       |
| -------------------- | ------------------------- | ----------------------------------- |
| **Growth type**      | Arithmetic reduction      | Geometric reduction                 |
| **Number of levels** | $\Theta(n)$               | $\Theta(\log n)$                    |
| **When $a=1$**       | $\Theta(n \cdot f(n))$    | Use Master Theorem Case 2           |
| **When $a>1$**       | $\Theta(a^n)$ exponential | Depends on $f(n)$ vs $n^{\log_b a}$ |
| **Master Theorem**   | **Does NOT apply**        | **Applies**                         |
