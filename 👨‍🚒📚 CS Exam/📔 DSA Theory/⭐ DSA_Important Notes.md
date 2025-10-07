**ALGORITHMS - PSU MCQ NOTES**


# Concept and Theories


##### **Stack theory - Concepts and Properties**

 A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.

- **Insertion** = `push()` → Top of stack
- **Deletion** = `pop()` → Top of stack
- **Peek/Top** = Returns topmost element without removing
    

**Basic Operations**

|Operation|Description|Time Complexity|
|---|---|---|
|`push()`|Insert element at top|O(1)|
|`pop()`|Remove top element|O(1)|
|`top()`|View top element|O(1)|
|`isEmpty()`|Check if stack is empty|O(1)|

**Stack Properties**

- Works on **LIFO**
- Implemented using ==**Array**== or **==Linked List==**
- Used in **recursion**, **expression parsing**, **backtracking**, **balancing symbols**, etc.
    

**Applications**

| Use Case                            | Description                               |
| ----------------------------------- | ----------------------------------------- |
| **Expression Evaluation**           | Postfix, Prefix, Infix                    |
| **Syntax Parsing**                  | Used by compilers                         |
| **Backtracking** ⭐ To Try           | DFS, maze solving                         |
| **Function Call Stack**             | Stores function calls and local variables |
| **Undo Feature**                    | Text editors like VS Code, Word, etc.     |
| **Balanced Parentheses Check**      | Using stack to validate parentheses       |
| **Reverse a String** ⭐ To Try       | Push characters and pop to reverse        |
| ==**Next Greater Element**==        | Uses stack in O(n)                        |
| ==**Stock Span Problem**== ⭐ To Try | O(n) solution with stack                  |

**Implementation Types**

- **Static Stack** – Using arrays (fixed size)    
- **Dynamic Stack** – Using linked list (no size limit)
    

**Stack in Recursion**

- Each recursive function call is pushed into the **call stack**. After completion, it's popped off.


**Important Stack-Based Problems**

|Problem|Concept Applied|
|---|---|
|Valid Parentheses|Stack + Matching pairs|
|Next Greater Element|Monotonic stack|
|Largest Rectangle in Histogram|Stack for area calculation|
|Evaluate Postfix/Prefix|Stack evaluation|
|Min Stack|Stack with auxiliary min|

---
##### **Queue Theory - Concepts & Properties


A **Queue** is a linear data structure that follows the **FIFO (First In First Out)** principle.

- **Insertion** = `enqueue()` → Rear of queue
- **Deletion** = `dequeue()` → Front of queue
- **Front()** = Returns first element without removing
    

**Basic Operations**

|Operation|Description|Time Complexity|
|---|---|---|
|`enqueue()`|Insert element at rear|O(1) (amortized)|
|`dequeue()`|Remove element from front|O(1)|
|`front()`|View element at front|O(1)|
|`isEmpty()`|Check if queue is empty|O(1)|

**Queue Properties**

- Works on **FIFO**
- Implemented using ==**Array**, **Linked List**, or **Two Stacks**==
- Used in **scheduling**, **BFS**, **buffering**, **data streaming**
    

**Types of Queues**

|Type|Description|
|---|---|
|**Simple Queue**|Basic FIFO queue|
|**Circular Queue**|Last position is connected to the first|
|**Deque**|Double-ended queue (insert/delete from both ends)|
|**Priority Queue**|Elements served based on priority|


**Applications**

| Use Case                                 | Description                          |
| ---------------------------------------- | ------------------------------------ |
| **Breadth-First Search**                 | Uses queue for level-order traversal |
| **CPU Scheduling** ⭐To Try               | Round-robin algorithm uses queue     |
| **Printer Spooling**                     | Jobs in order                        |
| **Data Buffer**                          | Handles stream data                  |
| **Web Server**                           | Request handling in queue            |
| **Caching (LRU)**                        | Queue helps manage eviction order    |
| **==First Non-Repeating Char==** ⭐To Try | Use queue + frequency array          |

**Implementation Types**

- **Array-Based Queue** – Fixed size, may need shifting
- **Linked List Queue** – Dynamic size
- **Circular Queue** – Efficient memory reuse
    

**Important Queue-Based Problems**

| Problem                                    | Concept Applied           |
| ------------------------------------------ | ------------------------- |
| ==First Non-Repeating Character== ⭐ To Try | Queue + Map               |
| ==Rotten Oranges== (Grid BFS)  ⭐ To Try    | Queue for level traversal |
| Course Schedule (Topological)              | Kahn's Algo → uses Queue  |
| ==Sliding Window Maximum== ⭐ To Try        | Deque                     |
| Zigzag Tree Traversal                      | Two Queues or Deque       |


---

##### **Graph Theory - Concepts and Properties**

**1. Basic Terminologies**

- **Graph (G)**: ==G=(V,E)==, where    
    - V = vertices/nodes
    - E = edges
        
- **Undirected Graph**: Edges have no direction
- **Directed Graph (Digraph)**: Edges have direction
    

**2. Number of Edges**
- **Undirected Graph**: ==Max edges = `n(n−1)/2`== ⭐
- **Directed Graph**:  Max edges = `n(n−1)`  = ==2 * Max Edge (Directed Graph)==
- **With Self-loops**:  Add `n` possible self-loops (directed)
- **Complete Graph `K_n`**:  `n(n−1)/2`
- **Complete Directed Graph**:  `n(n−1)` edges
    
**3. Degree of Vertex**
- **Undirected**:  Sum of degrees = `2E` ⭐
- **Directed**:  `∑ in-degrees` =`∑ out-degrees = E`
    

**4. Connected Components**
- A connected component is a **maximally connected subgraph**
- In a **tree**, edges = `n−1` ⭐
- In a **connected graph**, ==minimum edges = `n−1`== (i.e. in Spanning Tree) ⭐
- For a graph with `n` vertices and ==`k` connected components==, minimum edges required = ==`n−k`== ⭐

- **Spanning Tree:**
	- A **spanning tree** is a connected, acyclic ==subgraph== that includes all the vertices of the original graph with exactly minimum (`n−1`)  edges.
	- **Every spanning tree is acyclic**, but **Not every acyclic graph is a spanning tree
	- So, Every **spanning tree** is a **tree**, but **not every tree** is a **spanning tree**
    
**5. Tree Properties**

- A tree is a ==connected acyclic undirected graph==
- Nodes = `n`, Edges = `n-1`
- Exactly one path between any pair of nodes
- A **forest** is a collection of disjoint trees

    
**6. DFS & BFS**

- Used for traversal/search
- DFS uses **stack** or recursion
- BFS uses **queue**
    

**7. Cycles**

- **Undirected Graph**:
    - Use DFS; if you reach a visited node not equal to parent → cycle
        
- **Directed Graph**:
    - Use DFS with recursion stack
    - Or use **Kahn’s algorithm**: if topological sort not possible → cycle exists
        

**8. Topological Sort**

- Only for DAG (Directed Acyclic Graph)
- Order of tasks based on dependencies
- DFS post-order or Kahn’s algorithm (BFS)
    

**9. Spanning Tree**

- Subgraph that connects all nodes with `n−1` edges
- **Minimum Spanning Tree (MST)**:
    - Minimum total edge weight
    - Algorithms:
        - **Kruskal’s** (uses DSU)
        - **Prim’s** (uses priority queue)
        

**10. Shortest Path Algorithms**

- **Dijkstra**: Weighted graphs, no negative weights, greedy
- **Bellman-Ford**: Handles negative weights, `O(VE)`
- **Floyd-Warshall**: All-pairs shortest path, `O(V^3)`


**11. Bipartite Graph**

- 2-colorable graph with no odd-length cycle    
- BFS-based coloring


**12. Strongly Connected Components (SCC)**

- Every vertex is reachable from every other vertex in component
- **Kosaraju’s Algorithm**: 2 DFS traversals
- **Tarjan’s Algorithm**: Low-link values (DFS based)
    

**13. Bridges & Articulation Points**

- **Bridge**: Removing edge increases connected components
- **Articulation Point**: Removing vertex increases components
- Found using **Tarjan’s algorithm** with low and discovery time
    

**14. Disjoint Set (Union-Find)**

- Used in Kruskal’s algorithm
- Optimizations:
    - **Path Compression**
    - **Union by Rank/Size**
        

**15. Eulerian & Hamiltonian**

- **Eulerian Path**: uses every edge exactly once
    - Exists if 0 or 2 vertices have odd degree
        
- **Hamiltonian Path**: uses every vertex exactly once (NP-complete)
    

**16. Graph Representation**

- **Adjacency Matrix**: `O(n^2)` space
- **Adjacency List**: `O(n + e)` space
- **Edge List**: For ==Kruskal’s algo==
    

**17. Time Complexities**

| Algorithm        | Time Complexity    |
| ---------------- | ------------------ |
| BFS/DFS          | `O(V+E)`           |
| Dijkstra (PQ)    | `O((V + E) log V)` |
| Bellman-Ford     | `O(VE)`            |
| Floyd-Warshall   | `O(V^3)`           |
| Kruskal’s        | `O(Elog⁡E)`        |
| Prim’s (PQ)      | `O((V+E)log⁡V)`    |
| Topological Sort | `O(V+E)`           |
| Kosaraju’s (SCC) | `O(V+E)`           |

Here are the **Complete Tree Theory Notes** tailored for **PSU exams** (like ISRO, BARC, GATE, DRDO). It includes **definitions, properties, formulas**, and **important points** you must remember.

##### **Tree Theory - Concept and Properties**


**1. Definition**
- A **tree** is a **connected, acyclic, undirected graph** with `n` nodes and `n−1` edges.
- Only **one unique path** between any pair of vertices.
    
**2. Basic Properties**

| Property                           | Formula / Description          |
| ---------------------------------- | ------------------------------ |
| ==Edges== in a tree with `n` nodes | `n − 1`                        |
| ==Nodes== in a tree with `e` edges | `e + 1`                        |
| ==Adding== one edge to a tree      | Creates **exactly one cycle**  |
| ==Removing== one edge from a tree  | Graph becomes **disconnected** |
| Acyclic + Connected                | ⇒ ==Tree==                     |
| Acyclic + Not Connected            | ⇒ ==Forest==                   |
| Connected + `n−1` edges            | ⇒ Tree                         |


**3. Forest**

- A **forest** is a collection of disjoint trees
- A forest with `k` components (trees) and `n` nodes has:  
    **Edges = `n − k`**
    

**4. Height & Depth**

| Term                                                | Formula / Definition                 |
| --------------------------------------------------- | ------------------------------------ |
| **Height of Tree**                                  | Longest path from **root to a leaf** |
| **Height of Node**                                  | Longest path from **node to a leaf** |
| **Depth of Node**                                   | Distance from **root to that node**  |
| **Max nodes at level l**                            | `2^l` (in binary tree)               |
| **Height (h) of ==Full Binary Tree== with n nodes** | `log₂(n + 1) - 1`                    |

**5. Types of Trees**

| Type                         | Properties                                                      |
| ---------------------------- | --------------------------------------------------------------- |
| **Rooted Tree**              | One node is root, defines parent-child relationships            |
| **Binary Tree**              | Each node has ≤ 2 children                                      |
| **==Full== Binary Tree**     | Every node has 0 or 2 children                                  |
| **==Complete== Binary Tree** | All levels full except possibly last (left to right fill)       |
| **Perfect Binary Tree**      | All internal nodes have 2 children and all leaves at same level |
| **==Balanced== Binary Tree** | Height = `O(log n)` ⭐                                           |
| **Skewed Tree**              | All nodes only on one side (worst case height = `n−1`) ⭐        |

**6. Tree Traversals**

|Traversal Type|Order|
|---|---|
|**Preorder**|Root → Left → Right|
|**Inorder**|Left → Root → Right|
|**Postorder**|Left → Right → Root|
|**Level Order**|BFS → Level-wise traversal (uses Queue)|

**7. Number of Trees**

|Type|Formula|
|---|---|
|**Number of labeled trees**|`n^(n−2)` (Cayley’s Formula)|
|**Number of binary trees**|`C(n) = (2n)! / (n+1)!n!` (Catalan Number)|
|**Full binary trees with n internal nodes**|`2n + 1` total nodes|

**8. Binary Search Tree (BST)**

- Left subtree < root < right subtree
- **Average case height** = `O(log n)`
- **Worst case height** = `O(n)` (skewed tree)
- **Operations**: Insert, Delete, Search → `O(h)`
    

**9. Lowest Common Ancestor (LCA)**

- The **lowest** node in the tree that is ancestor of both nodes
    
- Can be computed using:
    - Binary Lifting
    - Euler Tour + Segment Tree
    - Naive: parent tracking and comparison
        

**10. Special Trees**

|Tree Type|Use/Property|
|---|---|
|**Spanning Tree**|Acyclic, connected subgraph with `n−1` edges|
|**AVL Tree**|Self-balancing BST (height balanced)|
|**Segment Tree**|Range queries (sum, min, max)|
|**Trie**|Efficient prefix-based string searching|
|**Heap Tree**|Complete binary tree, used in priority queues|

**11. Time Complexities**

| Operation                     | Time Complexity      |
| ----------------------------- | -------------------- |
| Tree Traversals (DFS/BFS)     | `O(n)`               |
| Insert/Search in BST          | `O(h)`               |
| Insert/Search in Balanced BST | `O(log n)`           |
| LCA (Binary Lifting)          | `O(log n)` per query |
| Building Segment Tree         | `O(n)`               |
| Segment Tree Query/Update     | `O(log n)`           |

---
---

# Important Algorithms


#####  **Graph Algorithms & their key properties**


**A. Linear Time - `O(V + E)`** ✅  (Graph traversal and SCC detection)

1. **BFS (Breadth-First Search)**
	- **Time:** `O(V + E)`
	- **Used for:** ==Shortest path in **unweighted** graphs==
	- **Approach:** Queue-based, Level-order traversal
	- **Output:** Distance from source, BFS tree
    
2. **DFS (Depth-First Search)**
	- **Time:** `O(V + E)`
	- **Used for:**
	    - ==Cycle detection==
	    - ==Topological sort==
	    - ==Connected components==
	- **Approach:** Stack/Recursion
	- **Output:** Discovery/Finish time, Tree/Back edges

3. **Topological Sort**
	- **Time:** `O(V + E)`
	- **Used for:** Ordering of nodes in **DAG**
	- **Approach:** DFS or ==Kahn’s algorithm==

4. **Tarjan’s Algorithm**
	- **Time:** `O(V + E) `
	- **Used for:** Strongly Connected Components (==SCCs==)
	- **Approach:** DFS with low-link values
    

5. **Kosaraju’s Algorithm**
	- **Time:** `O(V + E)` 
	- **Used for:** ==SCCs== in a directed graph
	- **Steps:**
	    - DFS + Stack
	    - Transpose Graph
	    - DFS again


**B. Heap-based - `O((V + E) log V)`** ✅ ( Greedy algorithms using priority queue (Min Heap) )

6. Dijkstra’s Algorithm ⭐
	- **Time:** ==`O((V + E) log V)`== using Min Heap
	- **Used for:** ==Shortest path== (**non-negative** weights)
	- **Approach:** Greedy, Priority Queue
	- **Limitation:** Fails with negative weights

7. **Prim’s Algorithm**
	- **Time:** ==`O((V + E) log V)`== with Min Heap
	- **Used for:** Minimum Spanning Tree (MST)
	- **Approach:** Greedy
	- **Start from any node**

**C. Sorting-based  `O(E log E)`** ✅ For algorithms that sort edges

8. **Kruskal’s Algorithm**
	- **Time:** O(E log E)
	- **Used for:** Minimum Spanning Tree (MST)
	- **Approach:** Greedy + Disjoint Set (Union-Find)
	- **Sort edges by weight**    

**D. DSU (Special Function Time)**

9. **Disjoint Set Union (DSU) / Union-Find**
	- **Time:** O(α(n)) per operation (inverse Ackermann)
	- **Used in:** ==Kruskal's==, cycle detection
	- **Operations:** `Find`, `Union`, `Path compression`

**E. Polynomial Time**

9. Bellman-Ford Algorithm⭐
	- **Time:** ==O(V·E) ==
	- **Used for:** ==Shortest path== (handles ==**negative weights**==)
	- **Detects:** ==Negative weight cycles==
	- **Relaxation:** V−1 times

10. Floyd-Warshall Algorithm ⭐
	- **Time:** ==O(V³)==
	- **Used for:** All-pairs shortest path
	- **Works with:** ==Negative edges== (no negative cycle)
	- **Approach:** Dynamic Programming


`O(V + E)` < `O((V + E) log V)` < `O(E log E)` < `O(V · E)` < `O(V³)`

| **Purpose**                                                                                                       | **Algorithm**                    |
| ----------------------------------------------------------------------------------------------------------------- | -------------------------------- |
| Graph Traversal                                                                                                   | BFS, DFS                         |
| Topological Sorting (DAG)                                                                                         | DFS-based Topo Sort, Kahn's Algo |
| Strongly Connected Components (SCCs)                                                                              | ==Kosaraju’s==, ==Tarjan’s==     |
| ==Shortest Path== (Unweighted)                                                                                    | BFS <br>`O(V+E)`                 |
| ==Shortest Path== (Non-negative weights)                                                                          | Dijkstra’s <br>`O((V+E) log V`)  |
| ==Shortest Path== (With negative weights + Detect Negative Cycles)                                                | Bellman-Ford<br>`O(V · E)`       |
| ==Shortest Path Pairs== - Shortest Path Between Every Pair (negative weights allowed, but **no** negative cycles) | Floyd-Warshall<br>`O(V³)`        |
| Minimum Spanning Tree (MST)                                                                                       | Prim’s, Kruskal’s                |
| Cycle Detection (Undirected/Directed)                                                                             | DFS, Union-Find                  |
| Disjoint Set Operations                                                                                           | Union-Find (DSU)                 |
| Detecting Bridges / Articulation Points                                                                           | Tarjan’s                         |


---

# Quick Notes 

**1. Time Complexity (Important)**

| Algorithm              | Time Complexity                    |
| ---------------------- | ---------------------------------- |
| Binary Search          | ==O(log n)==                       |
| Merge Sort / Heap Sort | O(n log n)                         |
| Quick Sort             | Avg: O(==n log n==), Worst: O(n^2) |
| Insertion Sort         | O(n^2)                             |
| Selection Sort         | O(n^2)                             |
| Bubble Sort            | O(n^2)                             |
| Counting Sort          | O(n + k)                           |
| Radix Sort             | O(nk)                              |
| BFS / DFS              | O(V + E)                           |
| Dijkstra (Min Heap)    | O(==(V + E) log V==)               |
| Bellman-Ford           | O(==VE==)                          |
| Floyd-Warshall         | O(==V^3==)                         |
| Prim/Kruskal (MST)     | O(E log V)                         |
| Topological Sort       | O(V + E)                           |
| KMP (Pattern Matching) | O(n + m)                           |

**2. Sorting Algorithms**
- **Stable Sorts:** Merge, Bubble, Insertion
- **Unstable Sorts:** Quick, Selection, Heap
- **Comparison-based Sorting:** Lower bound = O(n log n)
- **Non-comparison based:** Counting, Radix, Bucket


**3. Recurrence Relations (Master Theorem)**

General Form:
```
T(n) = a T(n / b) + f(n)
Let E = log_b(a)
```
- **Case 1:** `f(n) = O(n^E - ε)` ➔ `T(n) = Θ(n^E)`
- **Case 2:** `f(n) = Θ(n^E * log^k(n))` ➔ `T(n) = Θ(n^E * log^{k+1} n)`
- **Case 3:** `f(n) = Ω(n^E + ε)`, and regularity holds ➔ `T(n) = Θ(f(n))`
    

For **Decreasing Relation**:
```
T(n) = a T(n - b) + f(n)
```
-  **Case 1:**  `a < 1` ➔ `T(n) = Θ(f(n))`
-  **Case 2:** `a = 1` ➔ `T(n) = Θ(n * f(n))`
-  **Case 3:** `a > 1` ➔ `T(n) = Θ(a^{n/b} * f(n))`

**4. Graph Algorithms**

- **BFS/DFS:** O(V + E), for traversal, connected components, cycle detection
- **Dijkstra:** No negative weight, shortest path, Greedy
- **Bellman-Ford:** Works with negative weight, no negative cycles
- **Floyd-Warshall:** All-pairs shortest path
- **Prim’s/Kruskal’s:** MST algorithms, Greedy
- **Topological Sort:** Only for DAGs
- **Cycle Detection:**
    - Directed: DFS with recursion stack
    - Undirected: DFS with parent or Union-Find
        
**5. Greedy Algorithms**

- **Properties:** Optimal substructure, Greedy choice
- **Used in:** Activity Selection, Kruskal, Prim, Dijkstra, Huffman
    

**6. Dynamic Programming (DP)**
- Used when:
    - Optimal Substructure
    - Overlapping Subproblems

- Examples: 0/1 Knapsack, LCS, Matrix Chain Multiplication, LIS
    

**7. Divide and Conquer**

- Break into subproblems, solve recursively, combine
- Examples: Merge Sort, Quick Sort, Binary Search, Closest Pair
    

**8. Complexity Classes**

- **P:** Solvable in polynomial time
- **NP:** Verifiable in polynomial time
- **NP-Complete:** Both in NP and as hard as any in NP
    


**9. Tree Properties**

- Tree with `n` nodes has `n-1` edges
- Traversals: Inorder, Preorder, Postorder
- BST: Left < Root < Right
- Heap: Complete binary tree, Min/Max root
 
 
 **10. Hashing**

- Collision resolution: Chaining, Open addressing
- Good hash function: Uniform distribution
- Load factor: n / table size
    

