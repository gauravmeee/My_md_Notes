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
# DSA: Algorithms and Graphs

#### Graph Algorithms & their key properties

**A. Linear Time - `O(V + E)` ✅ (Graph traversal, ordering, SCC)**

**BFS (Breadth-First Search)**

* **Time:** `O(V + E)`
* **Used for:** <mark>Shortest path in **unweighted** graphs</mark>
* **Approach:** Queue-based, Level-order traversal
* **Output:** Distance from source, BFS tree

**DFS (Depth-First Search)**

* **Time:** `O(V + E)`
* **Used for:**
  * <mark>Cycle detection</mark>
  * <mark>Topological sort</mark>
  * <mark>Connected components</mark>
* **Approach:** Stack/Recursion
* **Output:** Discovery/Finish time, Tree/Back edges

**Topological Sort**

* **Time:** `O(V + E)`
* **Used for:** Ordering of nodes in **DAG**
* **Approach:** DFS or <mark>Kahn’s algorithm</mark>

**Tarjan’s Algorithm**

* **Time:** `O(V + E)`
* **Used for:** Strongly Connected Components (</mark>SCCs</mark>)
* **Approach:** DFS with low-link values

**Kosaraju’s Algorithm**

* **Time:** `O(V + E)`
* **Used for:** <mark>SCCs</mark> in a directed graph
* **Steps:**
  * DFS + Stack
  * Transpose Graph
  * DFS again

**B. Heap-based - `O((V + E) log V)` ✅ (Greedy + Min Heap / Priority Queue)**

**Dijkstra’s Algorithm ⭐**

* **Time:** <mark>`O((V + E) log V)`</mark> using Min Heap
* **Used for:** <mark>Shortest path</mark> (**non-negative** weights)
* **Approach:** <mark>Greedy</mark>, Priority Queue
* **Limitation:** Fails with negative weights

**Prim’s Algorithm** ⭐

* **Time:** <mark>`O((V + E) log V)`</mark> with Min Heap
* **Used for:** <mark>Minimum Spanning Tree (MST)</mark>
* **Approach:** <mark>Greedy</mark>
* **Start from any node**

**C. Sorting-based `O(E log E)` ✅ (Edge sorting)**

**Kruskal’s Algorithm** ⭐

* **Time:** <mark>`O(E log E)`</mark>
* **Used for:** <mark>Minimum Spanning Tree (MST)</mark>
* **Approach:** <mark>Greedy</mark> + Disjoint Set (Union-Find)
* **Sort edges by weight**

**D. DSU (Special Function Time)**

**Disjoint Set Union (DSU) / Union-Find**

* **Time:** `O(α(n))` per operation (inverse Ackermann)
* **Used in:** <mark>Kruskal's</mark>, cycle detection
* **Operations:** `Find`, `Union`, `Path compression`
  * `Find(x)` (representative/parent)
  * `Union(a, b)` (merge sets)
* **Optimizations:** Path compression + Union by rank/size

**E. Polynomial Time ✅ (DP-based shortest paths)**

**Bellman-Ford Algorithm**⭐

* **Time:** <mark>O(V·E) <mark>
* **Used for:** <mark>Shortest path</mark> (handles <mark>**negative weights**</mark>)
* **Detects:** <mark>Negative weight cycles</mark>
* **Approach:** <mark>Dynamic Programming</mark>
* **Relaxation:** V−1 times

**Floyd-Warshall Algorithm** ⭐

* **Time:** <mark>O(V³)</mark>
* **Used for:** All-pairs shortest path
* **Works with:** <mark>Negative edges</mark> (but no negative cycle)
* **Approach:** <mark>Dynamic Programming</mark>

> `O(V + E)` < `O((V + E) log V)` < `O(E log E)` < `O(V · E)` < `O(V³)`

| **Purpose**                                                                                                           | **Algorithm**                                      |
| --------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------- |
| Graph Traversal                                                                                                       | BFS, DFS                                           |
| Topological Sorting (DAG)                                                                                             | DFS-based Topo Sort, Kahn's Algo                   |
| Strongly Connected Components (SCCs)                                                                                  | <mark>Kosaraju’s</mark>, <mark>Tarjan’s</mark>                       |
| <mark>Shortest Path</mark> (Unweighted)                                                                                        | <p>BFS<br><code>O(V+E)</code> ⭐</p>                |
| <mark>Shortest Path</mark> (Non-negative weights)                                                                              | <p>Dijkstra’s<br><code>O((V+E) log V</code>) ⭐</p> |
| <mark>Shortest Path</mark> (With negative weights + Detect Negative Cycles)                                                    | <p>Bellman-Ford<br><code>O(V · E)</code> ⭐</p>     |
| <mark>Shortest Path Pairs</mark> - Shortest Path Between Every Pair (</mark>negative weights allowed</mark>, but **no** negative cycles) | <p>Floyd-Warshall<br><code>O(V³)</code> ⭐</p>      |
| <mark>Minimum Spanning Tree (MST)</mark>                                                                                       | Prim’s, Kruskal’s ⭐                                |
| Cycle Detection (Undirected/Directed)                                                                                 | DFS, Union-Find                                    |
| Disjoint Set Operations                                                                                               | Union-Find (DSU)                                   |
| Detecting Bridges / Articulation Points                                                                               | Tarjan’s                                           |

***

#### Quick Notes

**1. Time Complexity (Important)**

| Algorithm              | Time Complexity                    |
| ---------------------- | ---------------------------------- |
| Binary Search          | <mark>O(log n)</mark>                       |
| Merge Sort / Heap Sort | O(n log n)                         |
| Quick Sort             | Avg: O(<mark>n log n</mark>), Worst: O(n^2) |
| Insertion Sort         | O(n^2)                             |
| Selection Sort         | O(n^2)                             |
| Bubble Sort            | O(n^2)                             |
| Counting Sort          | O(n + k)                           |
| Radix Sort             | O(nk)                              |
| BFS / DFS              | O(V + E)                           |
| Dijkstra (Min Heap)    | O(<mark>(V + E) log V</mark>)               |
| Bellman-Ford           | O(<mark>VE</mark>)                          |
| Floyd-Warshall         | O(<mark>V^3</mark>)                         |
| Prim/Kruskal (MST)     | O(E log V)                         |
| Topological Sort       | O(V + E)                           |
| KMP (Pattern Matching) | O(n + m)                           |

**2. Sorting Algorithms**

* **Stable Sorts:** Merge, Bubble, Insertion
* **Unstable Sorts:** Quick, Selection, Heap
* **Comparison-based Sorting:** Lower bound = O(n log n)
* **Non-comparison based:** Counting, Radix, Bucket

**3. Recurrence Relations (Master Theorem)**

General Form:

```
T(n) = a T(n / b) + f(n)
Let E = log_b(a)
```

* **Case 1:** `f(n) = O(n^E - ε)` ➔ `T(n) = Θ(n^E)`
* **Case 2:** `f(n) = Θ(n^E * log^k(n))` ➔ `T(n) = Θ(n^E * log^{k+1} n)`
* **Case 3:** `f(n) = Ω(n^E + ε)`, and regularity holds ➔ `T(n) = Θ(f(n))`

For **Decreasing Relation**:

```
T(n) = a T(n - b) + f(n)
```

* **Case 1:** `a < 1` ➔ `T(n) = Θ(f(n))`
* **Case 2:** `a = 1` ➔ `T(n) = Θ(n * f(n))`
* **Case 3:** `a > 1` ➔ `T(n) = Θ(a^{n/b} * f(n))`

**4. Graph Algorithms**

* **BFS/DFS:** O(V + E), for traversal, connected components, cycle detection
* **Dijkstra:** No negative weight, shortest path, Greedy
* **Bellman-Ford:** Works with negative weight, no negative cycles
* **Floyd-Warshall:** All-pairs shortest path
* **Prim’s/Kruskal’s:** MST algorithms, Greedy
* **Topological Sort:** Only for DAGs
* **Cycle Detection:**
  * Directed: DFS with recursion stack
  * Undirected: DFS with parent or Union-Find

**5. Greedy Algorithms**

* **Properties:** Optimal substructure, Greedy choice
* **Used in:** Activity Selection, Kruskal, Prim, Dijkstra, Huffman

**6. Dynamic Programming (DP)**

* Used when:
  * Optimal Substructure
  * Overlapping Subproblems
* Examples: 0/1 Knapsack, LCS, Matrix Chain Multiplication, LIS

**7. Divide and Conquer**

* Break into subproblems, solve recursively, combine
* Examples: Merge Sort, Quick Sort, Binary Search, Closest Pair

**8. Complexity Classes**

* **P:** Solvable in polynomial time
* **NP:** Verifiable in polynomial time
* **NP-Complete:** Both in NP and as hard as any in NP

**9. Tree Properties**

* <mark>Tree with `n` nodes has `n-1` edges</mark>
* Traversals: Inorder, Preorder, Postorder
* BST: Left < Root < Right
* Heap: <mark>Complete binary tree</mark>, Min/Max root

**10. Hashing**

* Collision resolution: Chaining, Open addressing
* Good hash function: Uniform distribution
* Load factor: n / table size
