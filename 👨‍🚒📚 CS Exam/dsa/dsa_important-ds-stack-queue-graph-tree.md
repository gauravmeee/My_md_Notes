# ⭐ DSA\_Important DS - Stack, Queue, Graph, Tree

**ALGORITHMS - PSU MCQ NOTES**

## Concept and Theories

**Stack theory - Concepts and Properties**

A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.

* **Insertion** = `push()` → Top of stack
* **Deletion** = `pop()` → Top of stack
* **Peek/Top** = Returns topmost element without removing

**Basic Operations**

| Operation   | Description             | Time Complexity |
| ----------- | ----------------------- | --------------- |
| `push()`    | Insert element at top   | O(1)            |
| `pop()`     | Remove top element      | O(1)            |
| `top()`     | View top element        | O(1)            |
| `isEmpty()` | Check if stack is empty | O(1)            |

**Stack Properties**

* Works on **LIFO**
* Implemented using ==**Array**== or **==Linked List==**
* Used in **recursion**, **expression parsing**, **backtracking**, **balancing symbols**, etc.

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

* **Static Stack** – Using arrays (fixed size)
* **Dynamic Stack** – Using linked list (no size limit)

**Stack in Recursion**

* Each recursive function call is pushed into the **call stack**. After completion, it's popped off.

**Important Stack-Based Problems**

| Problem                        | Concept Applied            |
| ------------------------------ | -------------------------- |
| ==Valid Parentheses==          | Stack + Matching pairs     |
| ==Next Greater Element==       | Monotonic stack            |
| Largest Rectangle in Histogram | Stack for area calculation |
| Evaluate ==Postfix/Prefix==    | Stack evaluation           |
| Min Stack                      | Stack with auxiliary min   |

***

**\*\*Queue Theory - Concepts & Properties**

A **Queue** is a linear data structure that follows the **FIFO (First In First Out)** principle.

* **Insertion** = `enqueue()` → Rear of queue
* **Deletion** = `dequeue()` → Front of queue
* **Front()** = Returns first element without removing

**Basic Operations**

| Operation   | Description               | Time Complexity  |
| ----------- | ------------------------- | ---------------- |
| `enqueue()` | Insert element at rear    | O(1) (amortized) |
| `dequeue()` | Remove element from front | O(1)             |
| `front()`   | View element at front     | O(1)             |
| `isEmpty()` | Check if queue is empty   | O(1)             |

**Queue Properties**

* Works on **FIFO**
* Implemented using ==**Array**, **Linked List**, or **Two Stacks**==
* Used in **scheduling**, **BFS**, **buffering**, **data streaming**

**Types of Queues**

| Type               | Description                                       |
| ------------------ | ------------------------------------------------- |
| **Simple Queue**   | Basic FIFO queue                                  |
| **Circular Queue** | Last position is connected to the first           |
| **Deque**          | Double-ended queue (insert/delete from both ends) |
| **Priority Queue** | Elements served based on priority                 |

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

* **Array-Based Queue** – Fixed size, may need shifting
* **Linked List Queue** – Dynamic size
* **Circular Queue** – Efficient memory reuse

**Important Queue-Based Problems**

| Problem                                    | Concept Applied           |
| ------------------------------------------ | ------------------------- |
| ==First Non-Repeating Character== ⭐ To Try | Queue + Map               |
| ==Rotten Oranges== (Grid BFS) ⭐ To Try     | Queue for level traversal |
| Course Schedule (Topological)              | Kahn's Algo → uses Queue  |
| ==Sliding Window Maximum== ⭐ To Try        | Deque                     |
| Zigzag Tree Traversal                      | Two Queues or Deque       |

***

**Graph Theory - Concepts and Properties**

**1. Basic Terminologies**

* **Graph (G)**: ==G=(V,E)==, where
  * V = vertices/nodes
  * E = edges
* **Undirected Graph**: Edges have no direction
* **Directed Graph (Digraph)**: Edges have direction

**2. Number of Edges** ⭐

* **Undirected Graph**: `n(n−1)/2`
* **Directed Graph**: Max edges = `n(n−1)`
* **With Self-loops**: Add `n` possible self-loops (directed)
* **Complete Graph `K_n`**: `n(n−1)/2`
* **Complete Directed Graph**: `n(n−1)` edges

**3. Degree of Vertex**

* **Undirected**: Sum of degrees = `2E` ⭐
* **Directed**: `∑ in-degrees` =`∑ out-degrees = E`

**4. Connected Components**

* A connected component is a **maximally connected subgraph**
* In a **tree**, edges = `n−1` ⭐
* In a **connected graph**, ==minimum edges = `n−1`== (i.e. in Spanning Tree) ⭐
* For a graph with `n` vertices and ==`k` connected components==, minimum edges required = ==`n−k`== ⭐
* **Spanning Tree:**
  * A **spanning tree** is a connected, acyclic ==subgraph== that includes all the vertices of the original graph with exactly minimum ==(`n−1`) edges.==
  * **Every spanning tree is acyclic**, but \*\*Not every acyclic graph is a spanning tree
  * So, Every **spanning tree** is a **tree**, but **not every tree** is a **spanning tree**

**5. Tree Properties**

* A tree is a ==connected acyclic undirected graph==
* Nodes = `n`, Edges = `n-1`
* Exactly one path between any pair of nodes
* A **forest** is a collection of disjoint trees

**6. DFS & BFS**

* Used for traversal/search
* DFS uses **stack** or recursion
* BFS uses **queue**

**7. Cycles**

* **Undirected Graph**:
  * Use DFS; if you reach a visited node not equal to parent → cycle
* **Directed Graph**:
  * Use DFS with recursion stack
  * Or use **Kahn’s algorithm**: if topological sort not possible → cycle exists

**8. Topological Sort**

* Only for DAG (Directed Acyclic Graph)
* Order of tasks based on dependencies
* DFS post-order or Kahn’s algorithm (BFS)

**9. Spanning Tree**

* Subgraph that connects all nodes with `n−1` edges
* **Minimum Spanning Tree (MST)**:
  * Minimum total edge weight
  * Algorithms:
    * **Kruskal’s** (uses DSU)
    * **Prim’s** (uses priority queue)

**10. Shortest Path Algorithms**

* **Dijkstra** → Weighted graphs ( but **no negative weights**), greedy **`O((V + E) log V)`** with priority queue
* **Bellman-Ford** → Handles **negative weights** ( but **no negative cycles)**, DP **`O(VE)`**
* **Floyd-Warshall** → **All-pairs shortest path**, works with negative weights ( but **no negative cycles** ), DP **`O(V³)`**\`==

> **All three fail to give correct shortest paths** if a negative cycle exists ⭐

**11. Bipartite Graph**

* 2-colorable graph with no odd-length cycle
* BFS-based coloring

**12. Strongly Connected Components (SCC)**

* Every vertex is reachable from every other vertex in component
* **Kosaraju’s Algorithm**: 2 DFS traversals
* **Tarjan’s Algorithm**: Low-link values (DFS based)

**13. Bridges & Articulation Points**

* **Bridge**: Removing edge increases connected components
* **Articulation Point**: Removing vertex increases components
* Found using **Tarjan’s algorithm** with low and discovery time

**14. Disjoint Set (Union-Find)**

* Used in Kruskal’s algorithm
* Optimizations:
  * **Path Compression**
  * **Union by Rank/Size**

**15. Eulerian & Hamiltonian**

* **Eulerian Path**: uses every edge exactly once
  * Exists if 0 or 2 vertices have odd degree
* **Hamiltonian Path**: uses every vertex exactly once (NP-complete)

**16. Graph Representation**

* **Adjacency Matrix**: `O(n^2)` space
* **Adjacency List**: `O(n + e)` space
* **Edge List**: For ==Kruskal’s algo==

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

**Tree Theory - Concept and Properties**

**1. Definition**

* A **tree** is a **connected, acyclic, undirected graph** with `n` nodes and `n−1` edges.
* Only **one unique path** between any pair of vertices.

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

* A **forest** is a collection of disjoint trees
* A forest with `k` components (trees) and `n` nodes has:\
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

| Traversal Type  | Order                                   |
| --------------- | --------------------------------------- |
| **Preorder**    | Root → Left → Right                     |
| **Inorder**     | Left → Root → Right                     |
| **Postorder**   | Left → Right → Root                     |
| **Level Order** | BFS → Level-wise traversal (uses Queue) |

**7. Number of Trees**

| Type                                        | Formula                                    |
| ------------------------------------------- | ------------------------------------------ |
| **Number of labeled trees**                 | `n^(n−2)` (Cayley’s Formula)               |
| **Number of binary trees**                  | `C(n) = (2n)! / (n+1)!n!` (Catalan Number) |
| **Full binary trees with n internal nodes** | `2n + 1` total nodes                       |

**8. Binary Search Tree (BST)**

* Left subtree < root < right subtree
* **Average case height** = `O(log n)`
* **Worst case height** = `O(n)` (skewed tree)
* **Operations**: Insert, Delete, Search → `O(h)`

**9. Lowest Common Ancestor (LCA)**

* The **lowest** node in the tree that is ancestor of both nodes
* Can be computed using:
  * Binary Lifting
  * Euler Tour + Segment Tree
  * Naive: parent tracking and comparison

**10. Special Trees**

| Tree Type         | Use/Property                                  |
| ----------------- | --------------------------------------------- |
| **Spanning Tree** | Acyclic, connected subgraph with `n−1` edges  |
| **AVL Tree**      | Self-balancing BST (height balanced)          |
| **Segment Tree**  | Range queries (sum, min, max)                 |
| **Trie**          | Efficient prefix-based string searching       |
| **Heap Tree**     | Complete binary tree, used in priority queues |

**11. Time Complexities**

| Operation                     | Time Complexity      |
| ----------------------------- | -------------------- |
| Tree Traversals (DFS/BFS)     | `O(n)`               |
| Insert/Search in BST          | `O(h)`               |
| Insert/Search in Balanced BST | `O(log n)`           |
| LCA (Binary Lifting)          | `O(log n)` per query |
| Building Segment Tree         | `O(n)`               |
| Segment Tree Query/Update     | `O(log n)`           |
