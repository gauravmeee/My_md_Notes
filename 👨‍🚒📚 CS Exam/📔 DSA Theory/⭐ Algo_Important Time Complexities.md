
# Asymptotic Notations in Time Complexity

**1. Big-O Notation** `O(f(n))`
- **Worst-case** time complexity.
- Upper bound: algorithm takes **at most** `f(n)` time.
- **Used most commonly** in contests/interviews.
- **Example**:  Binary Search → `O(log n)`


**2. Omega Notation** `Ω(f(n))`
- **Best-case** time complexity.
- Lower bound: algorithm takes **at least** `f(n)` time.
- Not very useful alone, because best case may be rare.
- **Example**:  Linear Search → `Ω(1)` (if element is at first position)


**3. Theta Notation** `Θ(f(n))`
- **Tight bound** (best and worst both are `f(n)`).
- Algorithm always takes **exactly** `f(n)` time asymptotically.

- **Example**:  Merge Sort → `Θ(n log n)`


---

### Map Time Complexity

Map : 
Implemented by self-belencing bst (like a Red-Black Tree)
Ordered Map : The time complexity for insertion, deletion, and access is `O(log n)
`
Unordered Map : 
uses hash tables for faster lookups.
The average time complexity for insertion, deletion, and access is `O(1)`, but in the worst case, it can degrade to `O(n)` if there are many hash collisions.


---

# Time Complexity in Competitive Programming

### 1. How to Analyze Required Time Complexity for a Problem

You need to estimate **what time complexity is acceptable based on the input size `n`**. Here's a practical guide:

**Note**: 1 In second ~ 10^7 to 10^8 operations in C++ (for competitive programming).

```
1 sec = ~10^8 operations    
For a time complexity function
Code within this limit is likely to run in time
```

|Input Size (`n`)|Acceptable Time Complexity|
|---|---|
|≤ 10|`O(n!)`, `O(2^n)`|
|≤ 15–20|`O(2^n)` or `O(n * 2^n)`|
|≤ 100|`O(n^4)`|
|≤ 1,000|`O(n^3)`|
|≤ 10,000|`O(n^2)`|
|≤ 1e5 (10^5)|`O(n log n)`|
|≤ 1e6 (10^6)|`O(n)`|
|~1e9 (10^9)|`O(log n)` or `O(1)`|


**1. Given Input Size → Find Suitable Time Complexity**
- If input size is `x`
- Then choose a time complexity `f(n)` such that:  
    **`f(x) < 10^8` (operations in 1 second limit)**
    
**2. Given Time Complexity → Find Maximum Input Size**
- If time complexity is `f(n)`
- Then choose the maximum input size `x` such that:  
    **`f(x) < 10^8`**

**Note:** `f(x)` represents the **number of operations** your program performs for input size `x`, and it should satisfy , **`f(x) < 10^8`** to run within **1 second** (standard time limit in competitive programming).


###  2. Why `10^8` Operations Matter in Competitive Programming

When you write code for competitive programming, the **judge gives you 1 second** to run your solution for each test case.
Now, a modern computer can perform around **10⁷ to 10⁸ basic C++ operations in 1 second**.
So you should always make sure that:
- For a given input size, your code should **not do more than `10^8` operations**.
- If it does, the program will likely **TLE (Time Limit Exceeded)**.
- So you would need to optimise
    
This is why we estimate time complexity `f(n)` and ensure:

> **`f(n) < 10^8`**  
> So that your code completes within the time limit.

**Example**:  
If your algorithm is `O(n^2)`, then `n` must be ≤ `10^3`, because:  
→ `10^3 * 10^3 = 10^6` operations (safe)  
But if `n = 10^5`, then → `10^10` operations (TLE)

### 3. Examples of Time Complexities and Max Input Sizes

1. **Brute-force Search (2 nested loops)**
    - Time Complexity: `O(n^2)`
    - Max `n`: ~`10^3`
    - Example: Check all pairs `(i, j)` in an array
        
2. **Triple Nested Loop**
    
    - Time Complexity: `O(n^3)`
    - Max `n`: ~`100`
    - Example: Matrix multiplication (naive)
        
3. **Backtracking / Subset Generation**
    - Time Complexity: `O(2^n)`
    - Max `n`: ~`20`
    - Example: Generating all subsets, permutations
        
4. **Factorial Time**
    - Time Complexity: `O(n!)`
    - Max `n`: ~`10`
    - Example: Traveling Salesman Problem (TSP)
        
5. **Sorting Algorithms (Merge Sort, Quick Sort)**
    - Time Complexity: `O(n log n)`
    - Max `n`: ~`10^5 to 10^6`
    - Example: `std::sort()` in C++
        
6. **Binary Search**
    - Time Complexity: `O(log n)`
    - Max `n`: up to `10^9`
    - Example: Find element in sorted array
        
7. **Linear Search / Prefix Sum / One-pass Scan**
    - Time Complexity: `O(n)`
    - Max `n`: ~`10^7`
    - Example: Finding max in array
        
8. **Map / Set Insert-Search (Unordered)**
    - Time Complexity: `O(1)` average
    - Max `n`: ~`10^6`
    - Example: `unordered_map` in C++
        
9. **Heap / Priority Queue Operations**
    - Time Complexity: `O(log n)`
    - Max `n`: ~`10^6`
    - Example: Dijkstra's algorithm
        
10. **Dijkstra / BFS / DFS**
    - Time Complexity: `O(V + E)`
    - Max `V` or `E`: ~`10^5`
    - Example: Graph traversal
        
11. **Segment Tree / BIT (Fenwick Tree)**
    - Time Complexity: `O(log n)` per operation
    - Max `n`: ~`10^6`
    - Example: Range queries and updates
        
12. **Matrix Exponentiation / Fast Power**
    - Time Complexity: `O(log n)`
    - Max `n`: ~`10^18`
    - Example: Compute `a^b mod m`
        
13. **Sieve of Eratosthenes**
    - Time Complexity: `O(n log log n)`
    - Max `n`: ~`10^7`
    - Example: Prime numbers up to `n`
        
14. **DP with 1D array**
    - Time Complexity: `O(n)`
    - Max `n`: ~`10^6`
    - Example: Fibonacci with memoization
        
15. **DP with 2D array**
    - Time Complexity: `O(n^2)`
    - Max `n`: ~`1000`
    - Example: Longest Common Subsequence (LCS)
        
16. **Knapsack (DP O(n*W))**
    - Time Complexity: `O(n * W)`
    - Max `n*W`: ~`10^7`
    - Example: 0/1 Knapsack
        
        

---
