
# Data Structure and Algorithms

|     | Topics                             | Subtopics                             |
| --- | ---------------------------------- | ------------------------------------- |
| 1   | Stacks and Queues                  | Implementation and operations         |
| 2   | Arrays, Linked Lists               | Types and applications                |
| 3   | Searching, Sorting and Hashing     | Algorithms and complexity             |
| 4   | Graph and Tree Algorithms          | Traversal and optimization techniques |
| 5   | Design and Analysis of Algorithms  | Divide and Conquer, Greedy, DP        |
| 6   | Tractable and Intractable Problems | P, NP, NP-Complete concepts           |
| 7   | Time & Space Complexity            | Asymptotic notations and analysis     |

---
# 1. Stacks and Queues

## Stack

A **stack** is a linear data structure that follows **LIFO (Last In, First Out)** order. The element inserted last is removed first.

### Basic Operations

- **push(x):** Insert element x on top of stack
- **pop():** Remove top element
- **peek()/top():** Return top element without removing
- **isEmpty():** Check if stack is empty
- **isFull():** Check if stack is full (in case of fixed-size stack)

### Implementation

1. **Using Array** – Simple but fixed size
2. **Using Linked List** – Dynamic size
    

```cpp
struct Stack {
    int top;
    int arr[MAX];
    Stack() { top = -1; }
    void push(int x) { if(top < MAX-1) arr[++top] = x; }
    int pop() { return (top >= 0) ? arr[top--] : -1; }
    int peek() { return (top >= 0) ? arr[top] : -1; }
    bool isEmpty() { return top == -1; }
};
```

### Applications

- Function call management (Recursion)
- Expression evaluation & conversion (Infix, Prefix, Postfix)
- Undo/Redo operations
- Syntax parsing
- Backtracking (e.g., maze, N-Queens)

## Queue

A **queue** is a linear data structure that follows **FIFO (First In, First Out)** order. The element inserted first is removed first.

### Basic Operations

- **enqueue(x):** Insert element x at rear    
- **dequeue():** Remove element from front
- **front():** Access first element
- **rear():** Access last element
- **isEmpty():** Check if empty
- **isFull():** Check if full (for fixed size)
    

### Implementation

1. **Array-based Queue** (uses two indices `front`, `rear`)
2. **Linked List Queue**
3. **Circular Queue** – Solves wasted space issue
    

```cpp
struct Queue {
    int front, rear, arr[MAX];
    Queue() { front = rear = -1; }
    void enqueue(int x) {
        if(rear == MAX-1) return;
        if(front == -1) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if(front == -1 || front > rear) return -1;
        return arr[front++];
    }
    bool isEmpty() { return front == -1 || front > rear; }
};
```

### Variants

- **Circular Queue:** Connects rear to front
- **Deque (Double-Ended Queue):** Insertion/deletion from both ends
- **Priority Queue:** Each element has priority; highest priority dequeued first
    

### Applications

- Scheduling (CPU, Disk, Print)
- Buffer management (I/O queues)
- BFS (Breadth-First Search)
- Handling requests in order
    

---

**Key Difference:**

|Feature|Stack|Queue|
|---|---|---|
|Order|LIFO|FIFO|
|Insertion/Deletion|One end (top)|Opposite ends (front/rear)|
|Example|Function calls|Process scheduling|

---
---

# 2. Arrays and Linked Lists

## Array

An **array** is a collection of elements stored in **contiguous memory locations** and accessed using **indices**.

### Characteristics

- Fixed size (static memory allocation)
- Random access using index
- Homogeneous elements (same data type)

### Time Complexities

| Operation | Time |
| --------- | ---- |
| Access    | O(1) |
| Search    | O(n) |
| Insertion | O(n) |
| Deletion  | O(n) |

### Implementation Example

```cpp
int arr[5] = {1,2,3,4,5};
for(int i=0; i<5; i++) cout<<arr[i]<<" ";
```

### Advantages

- Direct element access
- Simple and cache-friendly

### Disadvantages

- Fixed size    
- Costly insertion/deletion (shifting elements)
- Inefficient memory use if sparsely filled


---

## Linked List

A **linked list** is a collection of **nodes** where each node contains **data** and a **pointer** to the next node.

### Types

1. **Singly Linked List** – Each node points to the next node
2. **Doubly Linked List** – Each node points to both next and previous nodes    
3. **Circular Linked List** – Last node points back to first node

### Node Structure

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};
```

### Basic Operations

- **Insertion:** At beginning, end, or any position
    
- **Deletion:** By value or position
    
- **Traversal:** Visit each node sequentially
    
- **Search:** Linear search through nodes
    

### Time Complexities

|Operation|Time|
|---|---|
|Access|O(n)|
|Search|O(n)|
|Insertion|O(1) (at head)|
|Deletion|O(1) (if pointer given)|

### Advantages

- Dynamic size
    
- Efficient insertion/deletion
    

### Disadvantages

- No random access
    
- Extra memory for pointers
    
- Sequential traversal only
    

---

### Comparison

|Feature|Array|Linked List|
|---|---|---|
|Memory|Contiguous|Non-contiguous|
|Access|O(1) Random|O(n) Sequential|
|Insertion/Deletion|Costly (O(n))|Efficient (O(1))|
|Memory Overhead|Less|More (pointers)|
|Size|Fixed|Dynamic|

---

### Applications

- **Arrays:** Lookup tables, matrix representation
    
- **Linked Lists:** Stacks, queues, dynamic memory structures, graph adjacency lists

---
---

# 3. Searching, Sorting and Hashing

## Searching

Searching means finding the location of a target element in a data structure.

### 1. Linear Search

Sequentially checks every element until match is found.

```cpp
int linearSearch(int arr[], int n, int key) {
    for(int i=0;i<n;i++) if(arr[i]==key) return i;
    return -1;
}
```

**Time:** O(n) **Space:** O(1)

### 2. Binary Search

Efficient search on **sorted array** using divide and conquer.

```cpp
int binarySearch(int arr[], int n, int key) {
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) l=mid+1;
        else r=mid-1;
    }
    return -1;
}
```

**Time:** O(log n) **Space:** O(1)

---

## Sorting

Sorting arranges data in increasing/decreasing order.

### 1. Bubble Sort

Repeatedly swaps adjacent elements if in wrong order.  
**Time:** O(n²) **Space:** O(1)

```cpp
void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
}
```

### 2. Selection Sort

Selects minimum element and places it at beginning.  
**Time:** O(n²) **Space:** O(1)

### 3. Insertion Sort

Builds sorted array one element at a time.  
**Time:** O(n²) **Best:** O(n) for nearly sorted

### 4. Merge Sort

Divide array, sort halves, then merge.  
**Time:** O(n log n) **Space:** O(n) **Stable**

### 5. Quick Sort

Picks a pivot, partitions array, recursively sorts.  
**Time:** O(n log n) **Worst:** O(n²) **Space:** O(log n)

### 6. Heap Sort

Builds max heap and repeatedly extracts max.  
**Time:** O(n log n) **Space:** O(1) **Not stable**

---

## Hashing

A technique for **fast data retrieval** using **key-value pairs**.

### Basic Terms

- **Hash Function:** Maps key → index in hash table
    
- **Hash Table:** Array storing data at hashed indices
    
- **Collision:** Two keys hash to same index
    

### Collision Handling

1. **Chaining:** Use linked list at each index
    
2. **Open Addressing:** Find next available slot
    
    - **Linear Probing:** (h(k)+i)%m
        
    - **Quadratic Probing:** (h(k)+i²)%m
        
    - **Double Hashing:** h1(k)+i*h2(k)
        

```cpp
int hashFunc(int key, int size){ return key % size; }
```

### Performance

|Operation|Average|Worst|
|---|---|---|
|Search|O(1)|O(n)|
|Insert|O(1)|O(n)|
|Delete|O(1)|O(n)|

### Applications

- Symbol tables in compilers
    
- Databases, caching
    
- Password storage
    
- Implementing sets/maps in STL

---
---

# 4. Graph and Tree Algorithms

## Graph

A **graph** consists of **vertices (nodes)** and **edges (links)** representing relationships between pairs of nodes.

### Types

- **Directed / Undirected**
    
- **Weighted / Unweighted**
    
- **Cyclic / Acyclic**
    
- **Sparse / Dense**
    

### Representation

1. **Adjacency Matrix:** `O(V²)` space
    
2. **Adjacency List:** `O(V+E)` space
    

```cpp
vector<int> adj[V]; // adjacency list
```

### Traversal Algorithms

#### 1. Breadth First Search (BFS)

Level-wise traversal using **queue**

```cpp
void BFS(int s, vector<int> adj[], int V){
    vector<bool> vis(V,false);
    queue<int> q;
    vis[s]=true; q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:adj[u])
            if(!vis[v]){ vis[v]=true; q.push(v); }
    }
}
```

**Time:** O(V+E)

#### 2. Depth First Search (DFS)

Recursive traversal using **stack (implicit)**

```cpp
void DFS(int u, vector<int> adj[], vector<bool>& vis){
    vis[u]=true;
    for(int v:adj[u])
        if(!vis[v]) DFS(v,adj,vis);
}
```

**Time:** O(V+E)

### Shortest Path Algorithms

- **Dijkstra’s Algorithm:** For weighted graphs with non-negative edges (O(V²) / O(E log V) using priority queue)
    
- **Bellman-Ford:** Handles negative weights (O(VE))
    
- **Floyd-Warshall:** All-pairs shortest path (O(V³))
    
- **Topological Sort:** For DAGs (linear order using DFS or Kahn’s algorithm)
    

### Minimum Spanning Tree (MST)

- **Kruskal’s Algorithm:** Sort edges; use union–find (O(E log E))
    
- **Prim’s Algorithm:** Grow MST from a start vertex (O(E log V))
    

---

## Tree

A **tree** is a connected acyclic graph with **N nodes and N−1 edges**.  
Special cases include **Binary Tree, Binary Search Tree (BST), AVL Tree, Heap**, etc.

### Tree Traversals

For binary trees:

1. **Inorder (L, Root, R)**
    
2. **Preorder (Root, L, R)**
    
3. **Postorder (L, R, Root)**
    
4. **Level Order (BFS)**
    

```cpp
struct Node{ int data; Node *left,*right; };
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
```

### Binary Search Tree (BST)

Left subtree < root < right subtree.

- **Insertion/Search/Deletion:** O(h), where h = height
    
- **Balanced BST (AVL/Red-Black):** O(log n)
    

### Binary Heap

Complete binary tree satisfying heap property.

- **Max-Heap:** Parent ≥ children
    
- **Min-Heap:** Parent ≤ children  
    Used in **priority queues**, **heap sort**, **Dijkstra’s**.
    

### Common Algorithms

- **Height/Depth Calculation**
    
- **Lowest Common Ancestor (LCA)**
    
- **Diameter of Tree**
    
- **Balanced Tree Check**
    
- **Tree Traversal Conversions (Inorder + Preorder → Tree)**
    

---

### Comparison

|Feature|Graph|Tree|
|---|---|---|
|Cycles|May have|No|
|Connectivity|May be disconnected|Always connected|
|Edges|≤ V²|= V−1|
|Root|None (general)|One root|
|Traversal|BFS, DFS|Inorder, Preorder, Postorder|

---

**Applications:**

- **Graphs:** Networks, routing, dependency analysis, social networks
    
- **Trees:** Hierarchical data (file systems, XML), search trees, heaps, parsers

---
---

# 5. Design and Analysis of Algorithms

## Algorithm

An **algorithm** is a finite set of well-defined instructions to solve a problem.

### Characteristics

- Input and Output
    
- Finiteness
    
- Definiteness
    
- Effectiveness
    
- Correctness and Efficiency
    

---

## Algorithm Design Techniques

### 1. Divide and Conquer

Divide problem → Solve subproblems → Combine results  
**Examples:** Merge Sort, Quick Sort, Binary Search  
**Time:** O(n log n) typical

### 2. Greedy Method

Builds solution step-by-step choosing the **locally optimal** option.  
**Examples:** Kruskal’s, Prim’s, Dijkstra’s, Huffman Coding  
**Time:** O(E log V) (for graph-based problems)

### 3. Dynamic Programming (DP)

Stores results of subproblems to avoid recomputation (optimal substructure + overlapping subproblems).  
**Examples:** Fibonacci, Knapsack, Matrix Chain Multiplication, Floyd–Warshall  
**Time:** Depends on state count; generally polynomial

### 4. Backtracking

Tries all possibilities and **backtracks** on failure.  
**Examples:** N-Queens, Sudoku, Subset Sum, Graph Coloring  
**Time:** Exponential (O(2ⁿ))

### 5. Branch and Bound

Optimization over backtracking; uses **bounds** to prune unpromising branches.  
**Examples:** 0/1 Knapsack (using upper bound), Travelling Salesman Problem

---

## Algorithm Analysis

### 1. Asymptotic Notations

Used to describe time/space complexity for large input size (n).

|Notation|Meaning|Description|
|---|---|---|
|**O(f(n))**|Upper Bound|Worst Case|
|**Ω(f(n))**|Lower Bound|Best Case|
|**Θ(f(n))**|Tight Bound|Average Case|

### 2. Time Complexity

Measures computational steps as function of input size.

- **Constant:** O(1)
    
- **Logarithmic:** O(log n)
    
- **Linear:** O(n)
    
- **Quadratic:** O(n²)
    
- **Cubic:** O(n³)
    
- **Exponential:** O(2ⁿ)
    

### 3. Space Complexity

Measures memory usage = input space + auxiliary space.  
**Example:** Recursive algorithms consume stack space.

---

## Recurrence Relations

Express running time of recursive algorithms.

- **Example:** T(n) = 2T(n/2) + O(n) → T(n) = O(n log n) (by Master Theorem)
    

**Master Theorem:**  
If T(n) = aT(n/b) + O(nᵏ)  
Then

- If a < bᵏ → T(n) = O(nᵏ)
    
- If a = bᵏ → T(n) = O(nᵏ log n)
    
- If a > bᵏ → T(n) = O(n^(log_b a))
    

---

## Algorithm Efficiency

To choose best algorithm, consider:

- Time and space trade-off
    
- Input constraints and scalability
    
- Deterministic vs. non-deterministic approaches
    

---

## Example: Comparing Sorting Algorithms

|Algorithm|Approach|Time (Avg)|Space|Stable|
|---|---|---|---|---|
|Quick Sort|Divide & Conquer|O(n log n)|O(log n)|No|
|Merge Sort|Divide & Conquer|O(n log n)|O(n)|Yes|
|Heap Sort|Selection|O(n log n)|O(1)|No|
|Insertion Sort|Incremental|O(n²)|O(1)|Yes|

---

**Key Idea:**  
Design aims for **correctness**, **efficiency**, and **scalability**; analysis quantifies performance to choose the most suitable algorithm for given constraints.

---
---


# 6. Tractable and Intractable Problems

## Computational Problems

A **computational problem** is a task solved by an algorithm, mapping inputs to desired outputs.  
Example: Sorting numbers, finding shortest paths, etc.

---

## Tractable Problems

Problems that can be solved by an algorithm in **polynomial time** (P class).

### Characteristics

- Solvable efficiently (in reasonable time)
    
- Time complexity: O(nᵏ) where k is constant
    
- Belong to class **P (Polynomial time problems)**
    

### Examples

- Searching and sorting (O(n log n))
    
- Shortest path (Dijkstra – O(V²))
    
- Minimum spanning tree (Prim/Kruskal – O(E log V))
    
- Matrix multiplication (O(n³))
    

### Significance

Tractable problems are **feasible** for large inputs in practice.

---

## Intractable Problems

Problems that **cannot be solved in polynomial time** or for which **no polynomial algorithm is known**.

### Characteristics

- Require **exponential** or **factorial** time
    
- Belong to class **NP (Nondeterministic Polynomial)** or harder
    
- Feasible only for small inputs
    

### Examples

- Travelling Salesman Problem (TSP) – O(n!)
    
- Knapsack Problem (exponential)
    
- Graph Coloring – O(kⁿ)
    
- Hamiltonian Cycle Problem
    

---

## P, NP, NP-Complete, NP-Hard

|Class|Definition|
|---|---|
|**P**|Solvable in polynomial time|
|**NP**|Verifiable in polynomial time|
|**NP-Complete**|Problems in NP that are as hard as any other NP problem|
|**NP-Hard**|At least as hard as NP-Complete but not necessarily in NP|

**Relation:**  
P ⊆ NP ⊆ NP-Hard  
NP-Complete ⊆ NP-Hard

### Examples

|Category|Example Problems|
|---|---|
|P|Shortest Path, Sorting|
|NP|TSP (decision version), SAT|
|NP-Complete|Subset Sum, 3-SAT, Hamiltonian Cycle|
|NP-Hard|TSP (optimization version), Halting Problem|

---

## The P vs NP Question

- **Open problem:** Is P = NP ?
    
- If yes → all efficiently verifiable problems become efficiently solvable.
    
- If no → some problems are fundamentally hard.
    

---

## Summary

|Property|Tractable|Intractable|
|---|---|---|
|Time Complexity|Polynomial (≤ O(nᵏ))|Exponential / Factorial|
|Feasibility|Practically solvable|Impractical for large n|
|Example|Dijkstra, Sorting|TSP, Knapsack|
|Class|P|NP, NP-Complete, NP-Hard|

---

**Key Idea:**  
Tractable problems are _algorithmically feasible_, while intractable ones define the _limits of computation_. Understanding them helps in approximations and heuristics for real-world hard problems.



---
---

# 7. Time Complexity and Space Complexity

## Time Complexity

**Definition:**  
Time complexity measures the **amount of time** an algorithm takes as a function of input size _n_.

### 1. Types of Time Complexity

- **Best Case:** Minimum time (e.g., already sorted array for linear search)
    
- **Average Case:** Expected time for random inputs
    
- **Worst Case:** Maximum time required
    

### 2. Asymptotic Notations

|Notation|Meaning|Describes|
|---|---|---|
|**O(f(n))**|Big-O|Upper bound (worst case)|
|**Ω(f(n))**|Omega|Lower bound (best case)|
|**Θ(f(n))**|Theta|Tight bound (average case)|

**Example:**  
For Linear Search → O(n), Ω(1), Θ(n)

---

### 3. Common Time Complexities

|Complexity|Description|Example|
|---|---|---|
|O(1)|Constant|Accessing array element|
|O(log n)|Logarithmic|Binary search|
|O(n)|Linear|Linear search|
|O(n log n)|Quasi-linear|Merge sort|
|O(n²)|Quadratic|Bubble sort|
|O(2ⁿ)|Exponential|Recursion in subset problems|
|O(n!)|Factorial|Travelling salesman problem|

---

### 4. Methods for Analysis

- **Counting Basic Operations:** Identify the most frequent operation.
    
- **Recurrence Relations:** For recursive algorithms (e.g., Merge Sort: T(n)=2T(n/2)+O(n))
    
- **Master Theorem:** Provides asymptotic bounds for divide-and-conquer recurrences.
    

---

## Space Complexity

**Definition:**  
Space complexity measures the **total memory** used by an algorithm with respect to input size _n_.  
It includes:

1. **Input Space** – Memory to store input
    
2. **Auxiliary Space** – Temporary memory used by algorithm
    
3. **Output Space** – Memory for output data
    

**Total Space = Input Space + Auxiliary Space + Output Space**

---

### Common Examples

|Algorithm|Auxiliary Space|Reason|
|---|---|---|
|Linear Search|O(1)|Constant variables|
|Merge Sort|O(n)|Temporary arrays|
|Quick Sort|O(log n)|Recursive stack|
|DFS (Recursive)|O(V)|Recursion stack|

---

### Space-Time Tradeoff

Some algorithms use **more memory** to reduce time, or vice versa.  
**Example:** Hashing uses O(n) space for O(1) time access.

---

**Summary Table**

|Aspect|Time Complexity|Space Complexity|
|---|---|---|
|Measures|Execution time|Memory usage|
|Depends on|Input size, algorithm structure|Data structures, recursion|
|Goal|Minimize time|Optimize memory|
|Trade-off|Faster → more memory|Less memory → slower|

---

**Key Idea:**  
Time complexity measures _speed_, space complexity measures _memory_. Efficient algorithms balance both for optimal performance.