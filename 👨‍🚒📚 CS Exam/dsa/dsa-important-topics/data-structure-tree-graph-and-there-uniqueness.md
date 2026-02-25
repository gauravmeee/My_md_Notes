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

# Data Structure: Tree Graph and there Uniqueness

## Types of Trees

```mathematica
                      Tree
                   /         \
              Binary      Multi-way 
             /      \              \
         BST        (Balanced,     (B-, B+, Trie, Segment,
      /      \     Full,Complete,   Fenwick Tree, Suffix, 
   AVL  Red-Black   Perfect, Skewed)   Splay Tree, K-D Tree)
                    Degenerate)
```

1. **Tree**
   * **Binary**
     * **BST** (Binary Search Tree)
       * **AVL** (<mark>Self-balancing</mark> BST) ⭐
       * **Red-Black** (Self-balancing BST) ⭐
     * **Balanced** (Binary trees where the height difference between subtrees is minimized)
     * **Full** (Each node has 0 or 2 children)
     * **Complete** (All levels are fully filled except possibly the last level, filled left to right)
     * **Perfect** (A Full Binary Tree where all leaf nodes are at the same level)
     * **Skewed** ⭐
       * **Left-Skewed** (All nodes have left children only)
       * **Right-Skewed** (All nodes have right children only)
     * **Degenerate** (Resembling a linked list where each parent node has only one child)
   * **Multi-way**
     * **B-Tree** (Balanced <mark>multi-way search tree</mark>, used for indexing in databases) ⭐
     * **B+ Tree** (Variant of B-Tree with all data in leaf nodes, used for efficient range queries) ⭐
     * **Trie** (Prefix Tree, used for efficient storage and retrieval of strings) ⭐
     * **Segment Tree** (Used for storing intervals or segments, supporting range queries)
     * **Fenwick Tree** (Binary Indexed Tree, used for efficient range sum queries and updates)
     * **Suffix Tree** (Stores all suffixes of a string, used for fast substring searching and pattern matching)
     * **Splay Tree** (Self-adjusting Binary Search Tree that moves frequently accessed elements to the root)
     * **K-D Tree** (Space-partitioning tree used for multidimensional search problems like nearest neighbor search)

**More Trees (That do not fit in above Categories)**

* **Heap**
  * **Max-Heap** (Binary tree where the parent node is larger than its children)
  * **Min-Heap** (Binary tree where the parent node is smaller than its children)
  * **Used for implementing `priority queues`**
* **Graph-Related**
  * **Spanning Tree** (A tree that connects all vertices of a graph with the minimum number of edges)
* **Decision**
  * **Decision Tree** (A tree used for decision analysis or machine learning)
* **Space Partitioning**
  * **Cartesian Tree** (A tree where in-order traversal gives a sequence while maintaining the heap property)
  * **K-D Tree** (Used in multidimensional search problems)

**Key Points ⭐**

> **Terms**

* **Binary tree** → A tree where each node has **at most two children** (left and right)
* **Multiway search tree** → A search tree where each node can have **more than two children** and keys are kept in **sorted order**
* **Balanced tree** → A tree where the **height difference** between subtrees is bounded, ensuring **O(log n)** operations
* **m-ary tree** → A tree where each node has **at most m children**

> _**Complete graph**_**&#x20;≠&#x20;**_**complete tree**_

* **Complete binary tree** → A binary tree where all levels are full except possibly the last, filled left to right
* **Complete graph** → A graph in which every pair of distinct vertices is connected by an edge

> **Tree ⊂ Forest ⊂ Graph**

* **Graph** → A set of **vertices and edges** with no restriction on cycles or connectivity
* **Forest** → <mark>**acyclic graph**</mark>
* **Tree** → A <mark>**connected</mark>, <mark>acyclic graph**</mark> with a hierarchical structure

> **AVL ⊂ BST** & **Red-Black ⊂ BST**

* **BST (Binary Search Tree)** → A <mark>binary tree</mark> where <mark>**left < root < right**</mark>
* **AVL tree** → A <mark>**self-balancing BST**</mark> with **Strict Balancing** (**<mark>height difference ≤ 1</mark>)**
* **Red-Black tree** → <mark>A **self-balancing BST**</mark> with **Relaxed Balancing** ( using **<mark>color rules to limit height</mark>**)

**Important Trees**

1. **Binary Tree**:
   * A <mark>tree</mark> where each node has <mark>at most two children</mark>, typically referred to as the left and right child.
2. **Heap**:
   * A <mark>binary tree</mark> used to <mark>implement priority queues.</mark> The heap property requires that each <mark>node’s value be greater than or equal to the values of its children (for a max heap)</mark> or less than or equal to the values of its children (for a min heap).
3. **Binary Search Tree (BST)**:
   * A <mark>binary tree <mark>where for each node, the <mark>left child’s value is less than the node’s value</mark>, and the <mark>right child’s value is greater</mark>. This property allows efficient searching, insertion, and deletion operations.
4. **Balanced Binary Search Trees**: ⭐
   * **AVL Tree**: A <mark>self-balancing binary search tree</mark> where the <mark>heights of two child subtrees of any node differ by</mark> no more than one.
   * **Red-Black Tree**: A <mark>self-balancing binary search tree</mark> with additional properties to ensure that the <mark>tree remains approximately balanced</mark> during <mark>insertions and deletions.</mark>
5. **B-Tree**:
   * A <mark>self-balancing tree</mark> data structure that **</mark>maintains sorted data</mark>** and <mark>allows **searches, sequential access, insertions, and deletions**</mark> in **logarithmic time**. It is commonly used in <mark>databases and file systems.</mark>
6. **B+ Tree**:
   * A <mark>variation of the B-tree</mark> where all <mark>**values are stored at the leaf level**</mark>, and internal nodes only store keys. It is used extensively in <mark>database indexing.</mark>

**More:**

7. **Segment Tree**:
   * A <mark>binary tree</mark> used for answering range queries efficiently. It is often used for problems that involve querying sums or minimums over an interval of an array.
8. **Trie (Prefix Tree)**:
   * A tree-like data structure <mark>used to store associative data structures</mark>, such as dictionaries. It is ohow ften used for string storage and retrieval.
9. **Fenwick Tree (Binary Indexed Tree)**:
   * A data structure that provides efficient methods for querying and updating prefix sums in an array.

***

### Classification of Trees Based on Structural Uniqueness ⭐

**Uniqueness Order Dependent vs Order Indepedent**

**A. Insertion order-independent structures (shape)**

* **Heap** → Complete tree shape enforced
* **AVL tree** → Strict height balance via rotations
* **Red-Black tree** → Relaxed balance via coloring rules
* **B-tree** → Multiway balanced tree; node split/merge removes order effect
* **B+ tree** → Balanced multiway tree with fixed-height leaves

**B. Insertion order-dependent structures (shape)**

* **BST** → Shape depends on insertion order (only local ordering, no shape constraint)
* **Unbalanced binary tree** → No balancing or shape rules

> **Heap vs BST Structure Uniqueness Intuition:**

* **Heap** → Structure depends only on **value hierarchy** (max/min property), not insertion order → for a given set, the heap <mark>shape is **fixed** once heapified</mark>.
* **BST** → Structure depends on **insertion order**; different orders produce <mark>**different shapes** while maintaining BST property</mark>.

**A. Unique Shape (structure) with Given Set of Values (Insertion Order Doesn’t Matter)**

These trees have a **fixed structure** for a given set of keys.

**1. Min Heap / Max Heap**

* **Min Heap / Max Heap** – Shape and heap property fix structure
* **Property:** Complete binary tree with heap property; structure fixed for given keys.
* **Rule used:** insert at end (complete tree), then percolate-up (swap with parent while child < parent) to restore min-heap property.
* **Example (Min Heap):** Keys = {10, 20, 5, 6, 1}
* Insert 10

```
  10
  
Every Children < Parent : Rule Followed
```

* Insert 20

```
   10
  /
20

Every Children < Parent : Rule Followed
```

* Insert 5

```
   10
  / \    
20   5 

5(children) < 10(parent) : Swap

   5
  / \    
20   10
```

* Insert 6

```
     5 
    / \
  20  10 
  /
 6
 
6(children) < 20(parent) : Swap

     5 
    / \
   6  10 
  /
 20
 
Every Children < Parent : Rule Followed
```

* Insert 1

```
     5 
    / \
   6  10 
  / \
 20  1

1(children) < 6(parent) : Swap

     5 
    / \
   1  10 
  / \
 20  6
 
1(children) < 5(parent) : Swap

     1 
    / \
   5  10 
  / \
 20  6
 
Every Children < Parent : Rule Followed
```

**2. B Tree**

* **B Tree** – Deterministic splits make same structure
* **Property:** Deterministic node splits based on order and capacity (fixed structure for same keys).
* **Rule:**
  * Each node can have **at most m–1 keys** and **m children**.
  * Each node (except root) must have **at least ⌈m/2⌉–1 keys**
  * **Keys in each node are sorted** in ascending order.
  * **Children are separated** by key ranges:
    * All keys in the left subtree < parent key
    * All keys in the right subtree > parent key
  * **Insertion** always happens at a **leaf**, then the tree may **split** upward if a node exceeds `m–1` keys.
* **Example (Order = 3):** Keys = {10, 20, 5, 6, 12}
* Definitions: order=3 ⇒ max children = 3 ⇒ max keys = 2, min keys = 1.
* Insert 10

```
[10]
```

* Insert 20

```
[10,20]
```

* Insert 5

```
[5, 10, 20]

3 keys > 2 ( max keys allowed) : split around median 10
  
  [10]
  /   \
[5]   [20]
```

Insert 6

```
     [10]
    /    \
  [5,6]  [20]
```

Insert 12

```
     [10]
   /      \
[5,6]  [12,20]
```

**3. B+ Tree**

* **B+ Tree** – Deterministic leaf linking and splits fix structure
* **Property:** All data in leaf nodes, internal nodes only for indexing; unique structure for same keys.
* **Example (Order = 3):** Keys = {10, 20, 5, 6, 12}
* Insert 10

```
[10]
```

* Insert 20

```
[10,20]
```

* Insert 5

```
[5, 10, 20]

3 keys > 2 ( max keys allowed) : split around median 10 + New root created with separator key 10
  
  [10]
  /   \
[5]   [10,20]
```

Insert 6

```
      [10]
    /     \
  [5,6]  [10,20]
```

Insert 12

```
     [10]
   /      \
[5,6]  [10,12,20]

3 keys > 2 ( max keys allowed) : split around median 12 + promoter separator key 12 to root

        [ 10 , 12 ]
       /     |      \
   [5,6]   [10,12]  [20]
   

Simplified (merged by display form): 
- [10,12] (two internal keys) is condensed to one split point [10]
- The right child [10,12] and its promoted key 12 are visually merged with the next leaf [20] to look simpler.
  

     [10]
    /    \
 [5,6]    [12,20]
```

**4. Trie / Prefix Tree**

* **Trie / Prefix Tree** – Depends only on key strings, not insertion order
* **Property:** Based purely on key patterns (characters/strings), not insertion order.
* **Example:** (Keys = {"bat", "ball", "cat"}):

```
(root)
 ├─ b
 │   ├─ a
 │   │   ├─ l ─ l (end: ball)
 │   │   └─ t (end: bat)
 └─ c
     └─ a ─ t (end: cat)
```

**B. Unique Shape (structure) Only for Given Insertion Order (Otherwise Different Structures Possible)**

**1. Binary Search Tree (BST)**

* **Binary Search Tree (BST)** – Shape changes if insertion order changes
* **Property:** Shape changes with insertion sequence.
* **Example:**
* Insert Order 1: 10, 5, 15, 2, 7

```
      10
     /  \
    5    15
   / \
  2   7
```

* Insert Order 2: 5, 2, 10, 7, 15

```
      5
     / \
    2   10
       /  \
      7    15
```

* (Same values, different shape)

**2. AVL Tree**

* **AVL Tree** – Rotations depend on insertion order
* **Property:** Balanced BST; rotations depend on insertion order.
* **Example:**
* Insert: 10, 20, 30 (Right rotation on 20 → final tree)

```
   20
  /  \
 10  30
```

* Insert: 30, 20, 10 (Left rotation on 20 → final tree)

```
   20
  /  \
 10  30
```

* (Same keys, different insertion order gives different rotation path)

**3. Red-Black Tree**

* **Red-Black Tree** – Color and rotation pattern depend on insertion order
* **Property:** Balancing (color and rotation) depends on insertion order.
* **Example:**
* Insert: 10, 20, 30 → right rotation at 20
* Insert: 20, 10, 30 → no rotation needed
* Both yield different intermediate color/rotation steps.

**4. Splay Tree**

* **Splay Tree** – Final structure depends on access/insertion order
* **Property:** Final structure depends on the access or insertion sequence (recently accessed node moves to root).
* **Example:**
* Insert: 10, 20, 30 → After splaying, root = 30

```
   30
  /
 20
/
10
```

* Access 10 again → After splay, root = 10

```
  10
    \
     30
    /
   20
```

* (Same values but final shape depends on access/insertion pattern)

## B-Tree and B+ - Tree

**B-Tree**

* A **self-balancing search tree** that maintains sorted data and allows searches, insertions, deletions, and sequential access in logarithmic time.
* **Used in databases and file systems.**

**Properties**

1. A B-Tree of **order m** can have:
   * **At most m children.**
   * **At most m−1 keys.**
   * **At least ⌈m/2⌉ children** (except root).
   * **At least ⌈m/2⌉−1 keys.**
2. All leaves appear at the same level.
3. Keys within a node are sorted in ascending order.
4. Subtrees between keys follow the same order property as in BST.
5. The root can have minimum 2 children (if not a leaf).

**Search**

* Similar to binary search within each node, then traverse the appropriate child.
* Time Complexity: **O(logₘ n)**

**Insertion**

* Insert key in proper leaf position.
* If overflow (more than m−1 keys) occurs → **split** the node.
* Middle key moves up to parent.

**Deletion**

* If underflow (less than ⌈m/2⌉−1 keys) occurs → **borrow** or **merge** from sibling.
* Maintain balance after each operation.

**B+ Tree**

* An **extension of B-Tree** used in databases for efficient range queries.
* All actual data is stored only in **leaf nodes**, internal nodes store **keys for indexing**.

**Properties**

1. A B+ Tree of **order d** can have:
   * **Between d and 2d keys per node.**
   * Hence, **between d+1 and 2d+1 children.**
   * Root has at least 2 children if not a leaf.
2. **Leaf nodes are linked** to form a **linked list** for sequential access.
3. All leaves appear at the same level.
4. Searching uses internal nodes; data found in leaves.

**Search**

* Traverse internal nodes like B-Tree → reach leaf → fetch actual record.
* Time Complexity: **O(logₙ)**

**Insertion**

* Insert in leaf → if overflow (more than 2d keys) → **split** leaf.
* Middle key copied to parent (not moved).

**Deletion**

* Remove from leaf → if underflow (< d keys) → **borrow or merge** → update parent keys.

**Differences Between B-Tree and B+ Tree**

| Feature            | B-Tree                     | B+ Tree                            |
| ------------------ | -------------------------- | ---------------------------------- |
| Data Storage       | In internal and leaf nodes | Only in leaf nodes                 |
| Leaf Linking       | Not linked                 | Linked sequentially                |
| Range Queries      | Less efficient             | Very efficient                     |
| Access Path Length | Variable                   | Always same (leaves at same level) |
| Redundancy         | No repetition of keys      | Keys may repeat in internal nodes  |
| Search Efficiency  | Slower for range           | Faster for range queries           |

**Order Terminology Summary**

| Convention          | Definition       | Keys per Node | Children per Node |
| ------------------- | ---------------- | ------------- | ----------------- |
| B-Tree (order = m)  | m = Max children | ⌈m/2⌉−1 … m−1 | ⌈m/2⌉ … m         |
| B+ Tree (order = d) | d = Min keys     | d … 2d        | d+1 … 2d+1        |

## Data Structures by Use Case

**1. In-Memory Searching and Storage**

**Trees/Graphs Used:**

* Binary Search Tree (BST) – simple in-memory search, insert, delete
* AVL Tree – balanced BST for guaranteed O(log n) search
* Red-Black Tree – balanced BST with faster insertion/deletion
* Hash Tables – fast key-value access (not a tree, but common)

**2. Disk-Based Databases / File Systems**

**Trees/Graphs Used:**

* B-Tree – disk-friendly, keeps tree shallow for fewer I/Os
* B+ Tree – all data in leaves, linked leaves for range queries

**Dense vs Shallow Indexing**

* **B-Tree:** Can store keys and data in all nodes (internal + leaves). Used when you want **shallow indexing**, i.e., fewer levels to search for a key, but range queries are less efficient because data is scattered across nodes.
* **B+ Tree:** Stores all actual data only in the **leaf nodes**, while internal nodes only store keys for navigation. Leaf nodes are linked, making it **better for dense data and range queries**. It’s also more disk-efficient because internal nodes can have a higher fan-out, keeping the tree shallower.

**3. Priority Management**

**Trees/Graphs Used:**

* Heap (Min/Max) – efficient access to smallest/largest element
* Fibonacci Heap – faster amortized decrease-key for algorithms like Dijkstra

**4. String Storage and Searching**

**Trees/Graphs Used:**

* Trie (Prefix Tree) – fast prefix search and autocomplete
* Suffix Tree / Suffix Array – substring search, pattern matching

**5. Graph Modeling and Network Analysis**

**Trees/Graphs Used:**

* Adjacency List – sparse graph representation
* Adjacency Matrix – dense graph representation
* Directed/Undirected Graphs – for connectivity and path finding

**6. Range Queries / Interval Problems**

**Trees/Graphs Used:**

* Segment Tree – range sum/min/max queries with updates
* Fenwick Tree (Binary Indexed Tree) – efficient prefix sums

**7. Connectivity / Disjoint Components**

**Trees/Graphs Used:**

* Disjoint Set (Union-Find) – track connected components in a graph

**8. Spatial Data / Geometric Problems**

**Trees/Graphs Used:**

* Quad-tree – 2D space partitioning, collision detection
* Octree – 3D space partitioning, 3D graphics, simulations

**9. String Matching / Text Processing**

**Trees/Graphs Used:**

* Suffix Tree – substring search, pattern matching
* Suffix Array – space-efficient alternative to suffix tree

**10. Event Scheduling / Simulation**

**Trees/Graphs Used:**

* Heap – manage events by priority/time efficiently
