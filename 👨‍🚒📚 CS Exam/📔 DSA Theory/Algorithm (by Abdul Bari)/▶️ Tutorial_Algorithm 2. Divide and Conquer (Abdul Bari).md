

# [2. Divide and Conquer](https://www.youtube.com/watch?v=2Rr2tW9zvRg&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=18&pp=iAQB)

##### **Introduction to Divide and Conquer Strategy**

- The "Divide and Conquer" ==strategy is a **design approach for solving computational problems**==.
- It is one of several problem-solving strategies in algorithms, a==longside methods like the greedy method, dynamic programming, backtracking==, and branch and bound.
- There's ==no strict formula to determine if this strategy is applicable to a problem==; suitability is often understood through practice, following a few general guidelines.

##### **The Core Principle of Divide and Conquer**

The fundamental idea is to ==tackle large problems by breaking them into smaller==, more manageable parts:

**1. Divide**: If a problem **P** of a large input size **n** is given, ==**break it down into smaller subproblems**== (e.g., P1, P2, P3, up to PK). The initial large problem is thus broken into smaller-sized problems.

**2. Conquer**: ==**Solve these smaller subproblems== individually** to obtain their respective solutions (e.g., solution1, solution2, solution3, up to solutionK). If a subproblem is still large, the Divide and Conquer strategy is applied recursively to it.

**3. Combine**: Once solutions for the subproblems are obtained, **these solutions are then ==combined to derive the overall solution== for the original, main problem**.

##### **Key Characteristics and Guidelines for Divide and Conquer**

For a problem to be solvable using the Divide and Conquer strategy, it must adhere to certain characteristics:

**1. Homogeneous Subproblems**: ==**The subproblems created must be of the same type as the original problem**==. 
- For example, if the main problem is to sort a list, then the subproblems must also be sorting problems. This ensures the strategy is recursive in nature. 
- An example of what is _not_ Divide and Conquer would be breaking down a workshop into different tasks like preparing invitations and arranging speakers, as these are different tasks, not smaller versions of the "conduct workshop" problem.

**2. Combinability of Solutions**: It is crucial to **have a method for combining the solutions of the subproblems to arrive at the main solution**. 
- If the individual subproblem solutions cannot be effectively combined, this strategy is not suitable.

**3. Recursive Nature**: Due to the property of breaking problems into smaller, identical subproblems and recursively solving them, ==**Divide and Conquer algorithms are inherently recursive**.==


##### **General Method for Divide and Conquer Strategy**

This outlines the typical structure of an algorithm employing this strategy:

**`Divide_and_Conquer(Problem P)`**:
- **If `P` is small**, then **solve `P` directly**. (There must be a straightforward solution for small instances of the problem).
- **Else (`P` is large)**:
	- **Divide `P` into subproblems P1, P2, ..., PK**.
	- **Recursively apply `Divide_and_Conquer` on each of P1, P2, ..., PK**.
	- **Combine the results/solutions obtained from the recursive calls** (i.e., from `Divide_and_Conquer(P1)`, `Divide_and_Conquer(P2)`, etc.) to formulate the solution for the main problem `P`.


##### **Algorithms that Utilize Divide and Conquer**

Several well-known algorithms are designed using the Divide and Conquer strategy:
	
1. **Binary Search**
2. Finding maximum and minimum values in a list
3. **Merge Sort**
4. **Quick Sort**
5. Strassen's Matrix Multiplication

These specific algorithms are typically covered in detail in separate videos due to their complexity.

##### **Importance for Algorithm Analysis**

- Given the recursive nature of Divide and Conquer algorithms, it's essential to understand **how to write and analyze recursive algorithms and functions**.
- The **time complexities** of such algorithms are often determined using **recurrence relations**.
- The next video in this series is dedicated to explaining recurrence relations, their various types, and methods for solving them, which is crucial for analyzing Divide and Conquer algorithms.
### [2.1.1: Recurrence Relation T(n) = T(n-1) + 1](https://www.youtube.com/watch?v=4V30R3I1vLI&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=19&pp=iAQB)

**Summary**
- **`T(n)` ->  `T(n-1) + 1` -> `T(0) + 1 +...+ 1` ->  `T(0) + n` -> `1 + n` 
- **`n + 1` -> `O(n)`** ✅

How to trace recursive functions, write recurrence relations, and solve them.

##### **1. Example Function (`test(n)`)** The function `test(n)` is defined as follows:

```cpp
test(n) {
    if (n > 0) {
        print(n);
        test(n - 1); // Recursive call
    }
}
```

**Function Tracing (for n = 3):** To understand the execution, we can trace the calls:

**`test(3)`**:
- `3 > 0` is true.
- Prints `3`.
- Calls `test(2)`.
**`test(2)`**:
- `2 > 0` is true.
- Prints `2`.
- Calls `test(1)`.
**test(1)`**:
- `1 > 0` is true.
- Prints `1`.
- Calls `test(0)`.
**`test(0)`**:
- `0 > 0` is false.

- The function stops without further calls or prints.

**Tracing Tree Diagram:** This tracing forms a simple linear tree:
```
       test(3)  (Print 3, Call test(2))
           |
           v
       test(2)  (Print 2, Call test(1))
           |
           v
       test(1)  (Print 1, Call test(0))
           |
           v
       test(0)  (Stop)
```
- The "major work" done by this function is printing values. For an input `n`, it prints `n` times. Each `printf` statement takes one unit of time. The function makes `n+1` calls in total (from `n` down to `0`).

##### **2. Recurrence Relation Formulation** Assume the time taken by `test(n)` is `T(n)`.

- Inside the function, a condition is checked (constant time, can be ignored or taken as 1).
- A `printf` statement is executed, which takes **1 unit of time**.
- A recursive call `test(n-1)` is made, which takes `T(n-1)` time. Therefore, the recurrence relation for `n > 0` is: **`T(n) = T(n-1) + 1`**

- For the base case, when `n = 0`, the function stops without performing significant work. Even though it's not doing anything, it still takes a constant amount of time to execute and return. So, `T(0)` is considered a **constant (e.g., 1)**. **`T(0) = 1`**

##### **3. Solving the Recurrence Relation**

There are ==two primary methods to solve recurrence relations:== Recursion Tree Method and Back Substitution Method.

**a) Recursion Tree Method:**

- **Tree Structure:**
	
	- The root node represents `T(n)`. The work done at this level (excluding recursive calls) is `1`.
	- `T(n)` calls `T(n-1)`. The work at the `T(n-1)` level is also `1`.
	- This continues until `T(0)`.
    
    ```
  T(n)  --> Cost = 1
	|
  T(n-1) --> Cost = 1
	|
  T(n-2) --> Cost = 1
	|
   ...
	|
  T(1)  --> Cost = 1
	|
  T(0)  --> Cost = 1 (Base case)
    ```
    
- **Summing the Costs:** The total time is the sum of the costs at each level.
	- There are `n` levels where `1` unit of work is done (from `T(n)` down to `T(1)`).
	- Plus, the base case `T(0)` also takes `1` unit of time.
	- Total time `T(n) = (1 + 1 + ... + 1) + T(0)` (n times for the '1's).
	- ==`T(n) = n + 1`.==

**b) Back Substitution Method:** 

- This method involves repeatedly substituting the recurrence relation into itself until a pattern emerges, then using the base case to find a closed-form solution.

1. Start with the recurrence relation: **`T(n) = T(n-1) + 1`**
2. Substitute `T(n-1)`: Since `T(n-1) = T((n-1)-1) + 1 = T(n-2) + 1`, substitute this into the first equation: `T(n) = (T(n-2) + 1) + 1` **`T(n) = T(n-2) + 2`**
3. Substitute `T(n-2)`: Since `T(n-2) = T((n-2)-1) + 1 = T(n-3) + 1`, substitute this: `T(n) = (T(n-3) + 1) + 2` **`T(n) = T(n-3) + 3`**
4. Observe the pattern: After `k` substitutions, the pattern is ==`T(n) = T(n-k) + k`.==
5. Determine `k` using the base case: We know `T(0) = 1`. To reach the base case, we set the argument `n-k` to `0`. `n - k = 0` Therefore, **`k = n`**.
6. Substitute `k = n` back into the general pattern: `T(n) = T(n-n) + n` `T(n) = T(0) + n`
7. Substitute the value of `T(0)`: ==`T(n) = 1 + n`==

##### **4. Time Complexity** 

Both methods yield the same result: `T(n) = n + 1`. In asymptotic notation, this is **O(n)** or **Θ(n)**, indicating linear time complexity.

### [2.1.2 Recurrence Relation T(n) = T(n-1) + n](https://www.youtube.com/watch?v=IawM82BQ4II&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=20&pp=iAQB)

**Summary** ⭐
- **`T(n)` -> `T(n-1) + n` -> `T(0) + n + (n-1) +...+ 1` -> `1 + n + (n-1) +...+ 1` -> 
- **Arithmetic Progression:** `1 + 2 +...+ n` = `n(n+1)/2`
- `1 + n * (n +1)/2`**
- **`1 + n * (n +1)/2` -> `O(n^2)`** ✅

Recursive function with a loop inside, leading to a different recurrence relation.

##### **1. Example Function (Implicit)** The function's structure implies:

```
test(n) {
    if (n > 0) {
        // Some constant work (condition check)
        for (i = 0; i < n; i++) { // Loop runs n times
            // Statement inside loop
        }
        test(n - 1); // Recursive call
    }
}
```

##### **2. Recurrence Relation Formulation** Assume the time taken by `test(n)` is `T(n)`.

- The `for` loop runs `n` times. The work inside the loop is constant, so the loop contributes a time proportional to `n` (e.g., `2n+2` which simplifies to `n` in asymptotic notation).
- The recursive call `test(n-1)` takes `T(n-1)` time. Therefore, the recurrence relation for `n > 0` is: **`T(n) = T(n-1) + n`**

For the base case, when `n = 0`, the function does nothing but returns. So, `T(0)` is considered a **constant (e.g., 1)**. **`T(0) = 1`**

##### **3. Solving the Recurrence Relation**

**a) Recursion Tree Method:**

- **Tree Structure:**
    
    - The root node represents `T(n)`. The work at this level is `n`.
    - `T(n)` calls `T(n-1)`. The work at the `T(n-1)` level is `n-1`.
    - This continues, reducing the work by `1` at each level, until `T(0)`.
    
    ```
          T(n)  --> Cost = n
            |
          T(n-1) --> Cost = n-1
            |
          T(n-2) --> Cost = n-2
            |
           ...
            |
          T(1)  --> Cost = 1
            |
          T(0)  --> Cost = 1 (Base case)
    ```
    
- **Summing the Costs:** The total time is the sum of the costs at each level.
    - ==`T(n) = n + (n-1) + (n-2) + ... + 1 + T(0)`==
    - The sum `n + (n-1) + ... + 1` is the sum of the first `n` natural numbers.
    - This sum is given by the formula `n(n+1)/2`.
    - So, ==`T(n) = n(n+1)/2 + T(0) = n(n+1)/2 + 1`.==

**b) Back Substitution Method:**

1. Start with the recurrence relation: **`T(n) = T(n-1) + n`**
2. Substitute `T(n-1)`: Since `T(n-1) = T((n-1)-1) + (n-1) = T(n-2) + (n-1)`, substitute this into the first equation: `T(n) = (T(n-2) + (n-1)) + n` **`T(n) = T(n-2) + (n-1) + n`**
3. Substitute `T(n-2)`: Since `T(n-2) = T((n-2)-1) + (n-2) = T(n-3) + (n-2)`, substitute this: `T(n) = (T(n-3) + (n-2)) + (n-1) + n` **`T(n) = T(n-3) + (n-2) + (n-1) + n`**
4. Observe the pattern: After `k` substitutions, the pattern is: ==`T(n) = T(n-k) + (n-k+1) + ... + (n-1) + n`==
5. Determine `k` using the base case: Set `n-k` to `0`. `n - k = 0` Therefore, **`k = n`**.
6. Substitute `k = n` back into the general pattern: ==`T(n) = T(n-n) + (n-n+1) + ... + (n-1) + n` `T(n) = T(0) + 1 + 2 + ... + (n-1) + n`==
7. Substitute the value of `T(0)` and sum the series: ==`T(n) = 1 + n(n+1)/2`==

##### **4. Time Complexity** Both methods confirm that `T(n)` is approximately `n²/2`. In asymptotic notation, this is **O(n²)** or **Θ(n²)**, indicating quadratic time complexity.

---

### [2.1.3: Recurrence Relation T(n) = T(n-1) + log n](https://www.youtube.com/watch?v=MhT7XmxhaCE&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=21&pp=iAQB)

**Summary** ⭐
- **`T(n)` -> `T(n-1) + log n` -> `T(0) + log n + log (n-1) +...+ log 1` -> `1 + log n + log (n-1) +...+ log 1` -> 
- **logarithm property:** `log a + log b` = `log ( a + b)`
- `1 + log (n * (n-1) *...*1)`   ->  `1 + log(n!)`** ~ `n log n`
- **`1 + log(n!)`  `O(n log n)`** ✅

This video introduces a function where the non-recursive part involves a loop with logarithmic time complexity.

##### **1. Example Function (Implicit)** The function's structure implies:

```
test(n) {
    if (n > 0) {
        // Some constant work
        for (i = 1; i <= n; i *= 2) { // Loop runs log n times
            // Statement inside loop (e.g., printing values)
        }
        test(n - 1); // Recursive call
    }
}
```

##### **2. Recurrence Relation Formulation** Assume the time taken by `test(n)` is `T(n)`.

- The `for` loop, `for (i=1; i<=n; i*=2)`, takes **log n time** because the loop variable `i` doubles in each iteration.
- The recursive call `test(n-1)` takes `T(n-1)` time. Therefore, the recurrence relation for `n > 0` is: **`T(n) = T(n-1) + log n`**

For the base case, `T(0)` is a **constant (e.g., 1)**. **`T(0) = 1`**

##### **3. Solving the Recurrence Relation**

**a) Recursion Tree Method:**

- **Tree Structure:**
    - The root node represents `T(n)`. The work at this level is `log n`.
    - `T(n)` calls `T(n-1)`. The work at the `T(n-1)` level is `log(n-1)`.
    - This continues until `T(0)`.
    
    ```
          T(n)  --> Cost = log n
            |
          T(n-1) --> Cost = log(n-1)
            |
          T(n-2) --> Cost = log(n-2)
            |
           ...
            |
          T(1)  --> Cost = log 1
            |
          T(0)  --> Cost = 1 (Base case)
    ```
    
- **Summing the Costs:** The total time is the sum of the costs at each level.
    - ==`T(n) = log n + log(n-1) + log(n-2) + ... + log 1 + T(0)`==
    - Using the logarithm property `log a + log b = log (a * b)`: `log n + log(n-1) + ... + log 1 = log(n * (n-1) * ... * 1) = log(n!)`
    - So, `T(n) = log(n!) + T(0) = log(n!) + 1`.
    - Asymptotically, `log(n!)` is ==approximated by `n log n` (e.g., using Stirling's approximation== or the ==upper bound `log(n^n) = n log n`==).

**b) Back Substitution Method:**

1. Start with the recurrence relation: **`T(n) = T(n-1) + log n`**
2. Substitute `T(n-1)`: Since `T(n-1) = T(n-2) + log(n-1)`, substitute this: `T(n) = (T(n-2) + log(n-1)) + log n` **`T(n) = T(n-2) + log(n-1) + log n`**
3. Substitute `T(n-2)`: Since `T(n-2) = T(n-3) + log(n-2)`, substitute this: `T(n) = (T(n-3) + log(n-2)) + log(n-1) + log n` **`T(n) = T(n-3) + log(n-2) + log(n-1) + log n`**
4. Observe the pattern: After `k` substitutions, the pattern is: `T(n) = T(n-k) + log(n-k+1) + ... + log(n-1) + log n`
5. Determine `k` using the base case: Set `n-k` to `0`. `n - k = 0` Therefore, **`k = n`**.
6. Substitute `k = n` back into the general pattern: `T(n) = T(n-n) + log 1 + log 2 + ... + log n` `T(n) = T(0) + (log 1 + log 2 + ... + log n)`
7. Substitute the value of `T(0)` and sum the logarithmic series: `T(n) = 1 + log(n!)`

##### **4. Time Complexity** 

Both methods yield `T(n) = 1 + log(n!)`. In asymptotic notation, this is **O(n log n)** or **Θ(n log n)**.

##### **5. General Observation for Decreasing Functions (Preview of Master's Theorem)** 

The video highlights a pattern for recurrence relations of the form `T(n) = T(n-1) + f(n)` (where the coefficient of `T(n-1)` is `1`):

- `T(n) = T(n-1) + 1` has a complexity of **O(n)** (`1 * n`).
- `T(n) = T(n-1) + n` has a complexity of **O(n²)** (`n * n`).
- `T(n) = T(n-1) + log n` has a complexity of **O(n log n)** (`log n * n`). The observation is that if the recurrence relation is `T(n) = T(n-1) + f(n)`, the time complexity appears to be `n * f(n)`.

### [2.1.4 Recurrence Relation T(n) = 2T(n-1) + 1](https://www.youtube.com/watch?v=JvcqtZk2mng&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=22&pp=iAQB)

**Summary** ⭐
- **Geometric Progression :**

This video introduces a recurrence relation where the recursive calls are multiplied by a coefficient.

##### **1. Example Function (Implicit)** The function's structure implies:

```
test(n) {
    if (n > 0) {
        // Some constant work (e.g., print)
        test(n - 1); // First recursive call
        test(n - 1); // Second recursive call
    }
}
```

##### **2. Recurrence Relation Formulation** Assume the time taken by `test(n)` is `T(n)`.

- There's some constant work (e.g., `1` unit for print statement or condition check).
- There are **two recursive calls** to `test(n-1)`, each taking `T(n-1)` time. Therefore, the recurrence relation for `n > 0` is: **`T(n) = 2T(n-1) + 1`**

For the base case, `T(0)` is a **constant (e.g., 1)**. **`T(0) = 1`**

##### **3. Solving the Recurrence Relation**

**a) Recursion Tree Method:**

- **Tree Structure:**
    
    - The root `T(n)` performs `1` unit of work and makes two calls.
    - Each of these calls (at level 1) also performs `1` unit of work and makes two more calls.
    - This branches out, forming a binary tree structure.
    
    ```
                                T(n)
                            /      \
                  (Cost = 1)      (Cost = 1)
                  T(n-1)          T(n-1)
                 /    \          /    \
        (Cost = 1) (Cost = 1) (Cost = 1) (Cost = 1)
        T(n-2) T(n-2) T(n-2) T(n-2)
         ... (continues for k levels) ...
    ```
    
- **Cost at each Level:**
    - Level 0 (Root): `1` unit of work. Number of nodes: `2^0 = 1`.
    - Level 1: `1` unit of work for each of the `2` nodes. Total cost: `1 * 2 = 2` units. Number of nodes: `2^1 = 2`.
    - Level 2: `1` unit of work for each of the `4` nodes. Total cost: `1 * 4 = 4` units. Number of nodes: `2^2 = 4`.
    - Level `i`: `1` unit of work for each of the `2^i` nodes. Total cost: `1 * 2^i = 2^i` units. Number of nodes: `2^i`.
- **Total Cost:** The tree proceeds for `n` levels until the base case `T(0)` is reached.
    - Total time `T(n) = Sum of costs at each level`
    - `T(n) = 1 + 2 + 4 + ... + 2^(n-1) + T(0)` (where `T(0)` contributes to the final level).
    - This is a geometric progression sum: `a + ar + ar² + ... + ar^(k-1) = a(r^k - 1) / (r-1)`.
    - Here, `a = 1`, `r = 2`, and there are `n` terms (from `2^0` to `2^(n-1)`). The `k` in the formula refers to the number of terms.
    - So, `1 + 2 + ... + 2^(n-1) = (1 * (2^n - 1)) / (2 - 1) = 2^n - 1`.
    - Therefore, `T(n) = (2^n - 1) + T(0)`.
    - Since `T(0) = 1`, `T(n) = 2^n - 1 + 1 = 2^n`.
    - More accurately, considering `T(0)` as the `n`-th level, the sum goes up to `2^n`: `1 + 2 + ... + 2^n = 2^(n+1) - 1`. (The video states `k` up to `n`, so `2^k` implies `2^n`, leading to `2^(n+1)-1` for the sum of `n+1` terms from `2^0` to `2^n`).

**b) Back Substitution Method:**

1. Start with the recurrence relation: **`T(n) = 2T(n-1) + 1`**
2. Substitute `T(n-1)`: Since `T(n-1) = 2T(n-2) + 1`, substitute this: `T(n) = 2 * (2T(n-2) + 1) + 1` `T(n) = 2²T(n-2) + 2¹ + 1`
3. Substitute `T(n-2)`: Since `T(n-2) = 2T(n-3) + 1`, substitute this: `T(n) = 2² * (2T(n-3) + 1) + 2¹ + 1` `T(n) = 2³T(n-3) + 2² + 2¹ + 1`
4. Observe the pattern: After `k` substitutions, the pattern is: `T(n) = 2^k T(n-k) + (2^(k-1) + 2^(k-2) + ... + 2¹ + 2⁰)`
5. Determine `k` using the base case: Set `n-k` to `0`. `n - k = 0` Therefore, **`k = n`**.
6. Substitute `k = n` back into the general pattern: `T(n) = 2^n T(n-n) + (2^(n-1) + 2^(n-2) + ... + 2¹ + 2⁰)` `T(n) = 2^n T(0) + (2^n - 1)` (sum of geometric series)
7. Substitute the value of `T(0)`: `T(n) = 2^n * 1 + (2^n - 1)` `T(n) = 2^n + 2^n - 1` **`T(n) = 2^(n+1) - 1`**

##### **4. Time Complexity** 

Both methods consistently derive `T(n) = 2^(n+1) - 1`. In asymptotic notation, this is **O(2^n)** or **Θ(2^n)**, indicating exponential time complexity.


### [2.2 Masters Theorem Decreasing Function](https://www.youtube.com/watch?v=CyknhZbfMqc&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=23&pp=iAQB)


Master's Theorem for decreasing functions provides a **direct method for solving certain types of recurrence relations** without needing to use methods like recursion trees or back substitution. This theorem is particularly useful for recurrence relations where the problem size decreases by a fixed amount (e.g., `n-1`, `n-2`, `n-b`).

Before defining the theorem, let's recall some previously solved recurrence relations (from videos 1 to 4) and their respective time complexities:

- `T(n) = T(n-1) + 1` had a time complexity of **Order of n** (`O(n)`).
- `T(n) = T(n-1) + n` had a time complexity of **Order of n²** (`O(n²)`).
- `T(n) = T(n-1) + log n` had a time complexity of **Order of n log n** (`O(n log n)`).
- `T(n) = 2T(n-1) + 1` had a time complexity of **Order of 2ⁿ** (`O(2ⁿ)`).

These examples demonstrate a pattern that the Master's Theorem formalises.

##### **General Form of Recurrence Relation (Decreasing Function)**

The general form of a recurrence relation suitable for this Master's Theorem is: 
```cpp
T(n) = a T(n - b) + f(n)
```

Where:

- **`a`**: A coefficient, representing how many times the recursive call is made. It is assumed that `a > 0`.
- **`b`**: The amount by which the input `n` is decreased in each recursive call. It is assumed that `b > 0`.
- **`f(n)`**: The non-recursive part of the work done at each step. This term is typically taken in its **asymptotic notation** (e.g., `Big O`, `Theta`).
    - `f(n)` is assumed to be in the form of **`O(n^k)`**, where `k >= 0`.

Based on the value of `a`, there are three cases in Master's Theorem for decreasing functions:


##### **Case 1: If `a < 1`**
```
f(n)
```
`T(n-b)` = `1`

**Condition**:
- `a` is less than 1 (e.g., 0.5, 0.75).

**Solution**:
- The time complexity is simply **`O(f(n))`** or **`O(n^k)`** (as `f(n)` is `O(n^k)`).
- This means the non-recursive part (`f(n)`) dominates the overall time complexity.

##### **Case 2: If `a = 1`**
```sh
n * f(n)
```
- `T(n - b)` = `n`

**Condition**:
- `a` is equal to 1.

 **Solution**: 
- The time complexity is **`O(n * f(n))`** or **`O(n^(k+1))`** (if `f(n)` is `O(n^k)`).
- This implies that whatever `f(n)` is, it gets multiplied by `n`.
- **Examples from previous videos illustrating this case**:
	- `T(n) = T(n-1) + 1`: Here `a = 1`, `f(n) = 1` (which is `n^0`, so `k=0`). The solution is `O(n * 1)` which is `O(n)`.
	- `T(n) = T(n-1) + n`: Here `a = 1`, `f(n) = n` (which is `n^1`, so `k=1`). The solution is `O(n * n)` which is `O(n²)`.
	- `T(n) = T(n-1) + log n`: Here `a = 1`, `f(n) = log n`. The solution is `O(n * log n)`.
- **Generalisation for `a = 1`**: If `f(n)` is `n^k`, the answer is `n^(k+1)`. If `f(n)` is `n^k log n`, the answer is `n^(k+1) log n`. Whatever the `f(n)` term is, it's essentially multiplied by `n`.
- It also applies even if `b` is not 1 (e.g., `T(n) = T(n-100) + n`), the answer remains `O(n^2)` (or `O(n*f(n))`) for large `n` because `n/b` still gives `O(n)`.

##### **Case 3: If `a > 1`**
```
a^(n/b) * f(n)
```
- `T(n-b)` -> `a^(n/b)`


**Condition**: 
- `a` is greater than 1 (e.g., 2, 3).

**Solution**: 
- The time complexity is **`O(a^(n/b))`** multiplied by `f(n)`. Or, as presented, **`O(f(n) * a^(n/b))`** or **`O(n^k * a^(n/b))`**.
- This indicates that the base `a` raised to the power of `n/b` becomes the dominant factor.
- **Examples from previous videos illustrating this case**:
	- `T(n) = 2T(n-1) + 1`: Here `a = 2`, `b = 1`, `f(n) = 1`. The solution is `O(1 * 2^(n/1))` which is `O(2ⁿ)`.
	- `T(n) = 3T(n-1) + 1`: Similarly, this would be `O(3ⁿ)`.
	- `T(n) = 2T(n-1) + n`: Here `a = 2`, `b = 1`, `f(n) = n`. The solution would be `O(n * 2ⁿ)`.
- It's important to note that if `b` is greater than 1 (e.g., `T(n) = 2T(n-2) + 1`), the solution will be `O(a^(n/b))` (e.g., `O(2^(n/2))`).

##### **Key Takeaway**

The Master's Theorem for decreasing functions provides a **quick way to determine the time complexity** for recurrence relations fitting the `T(n) = a T(n - b) + f(n)` form. Understanding the three cases based on the value of `a` (less than 1, equal to 1, or greater than 1) is crucial.

It is recommended to **practice solving these recurrence relations yourself** and spend time observing the patterns to properly remember and apply the theorem.

#####  My Notes ⭐

**General Form**
```
T(n) = a · T(n − b) + f(n)
```

It behaves like:
```
T(n) ≈ T(n) * f(n)
```


**Case 1: If a < 1**
- `T(n − b) `contributes almost nothing
- Behaves like:
```
T(n) ≈ f(n)
```


**Case 2: If a = 1**
- `T(n − b)` behaves like **linear accumulation**
- Number of terms ≈ `n/b` ⇒ `O(n)`
```
T(n) ≈ n * f(n)
```


**Case 3: If a > 1**
- `T(n − b)` **grows exponentially**
- Number of terms ≈ `n/b`
- So, `T(n-b)` ≈ `a^(n/b)`
- Geometric progression of a terms
```
T(n) ≈ a^(n/b) * f(n)
```


---
### [2.3.1 Recurrence Relation Dividing Function T(n)=T(n/2)+1 (1)](https://youtu.be/8gt0D0IqU5w?list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O)

### [2.3.2 Recurrence Relation Dividing Function T(n)=T(n/2)+n (2)](https://www.youtube.com/watch?v=XcZw01FuH18&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=25&pp=iAQB)

### [2.3.3 Recurrence Relation Dividing Function T(n)=2T(n/2)+n (3)](https://www.youtube.com/watch?v=1K9ebQJosvo&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=26&pp=iAQB)

### [2.4.1 Masters Theorem in Algorithms for Dividing Function (1)](https://www.youtube.com/watch?v=OynWkEj0S-s&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=27&pp=iAQB)


##### My Notes⭐


**General Form**
```
T(n) = a · T(n / b) + f(n)
```
- `a > 0`
- `b > 1`
- `f(n) = n^k · log^P(n)`
    

**Case 1: `log_b(a) > k`** ⭐

- f(n) is **polynomially smaller**
```
T(n) ≈ n^(log_b(a)) 
```


**Case 2: `log_b(a) = k`**

- `f(n)` is **equal to `n^(log_b(a))`** (polylog variations)
```
P ≥ 0       ⇒  T(n) ≈ n^k · log^{P+1}(n) ---> f(n) * logn
P = -1      ⇒  T(n) ≈ n^k · log log n   
P < -1      ⇒  T(n) ≈ n^k
```


**Case 3: `log_b(a) < k`**

- f(n) is **polynomially bigger**
```
P ≥ 0       ⇒  T(n) ≈ n^k · log^P(n) ---> f(n)
P < 0       ⇒  T(n) ≈ n^k
```



### [2.4.2 Examples for Masters Theorem (2)](https://www.youtube.com/watch?v=kGcO-nAm9Vc&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=28&pp=iAQB)
