

> Resources
- [DSA BY Google](https://techdevguide.withgoogle.com/paths/data-structures-and-algorithms/)

# Types of Data Structures

1. **Array**: Contiguous memory block. ✅
2. **Linked List**: Nodes with pointers (Singly/Doubly Linked List). 
3. **Stack**: Array or Linked List. ✅
4. **Queue**: Array or Linked List. ✅
5. **Priority Queue**: Binary Heap. ✅
6. **Binary Search Tree (BST)**: Linked nodes (Binary Tree).
7. **Hash Table**: Array of linked lists (Chaining) or Open Addressing. ✅
8. **Graph**: Adjacency Matrix or Adjacency List. ✅
9. **Trie**: Tree with linked nodes (Prefix Tree).
10. **Heap**: Binary Heap (Array representation).
11. **Deque**: Doubly Linked List or Dynamic Array.
12. **Segment Tree**: Array.
13. **Fenwick Tree (BIT)**: Array.
14. **Set**: Balanced Binary Search Tree (`std::set`) or Hash Table (`std::unordered_set`). ✅
15. **Map**: Balanced Binary Search Tree (`std::map`) or Hash Table (`std::unordered_map`).
16. **Multiset**: Balanced Binary Search Tree (`std::multiset`) or Hash Table (`std::unordered_multiset`).
17. **Multimap**: Balanced Binary Search Tree (`std::multimap`) or Hash Table (`std::unordered_multimap`).
18. **Bitset**: Array of bits (bit-level manipulation).

---

# Data Structure and Algorithm Uses

### **1. Data Structures Uses**

1. **Linear Data Structures**
    - **Array** - Used for storing fixed-size data like employee IDs or scores in a game.
    - **Linked List**
	    - **Singly** - Implementing a chain of nodes in blockchain, Playlist.
	    - **Doubly** - Navigating forward/backward in a media playlist.
	    - **Circular** -Managing processes in an operating system (Round Robin Scheduling).
    - **Stack** - Undo operation in text editors or browsers' backtracking history.
    - **Queue**
	    - **Simple** - Ticketing system for customer service or bank counters.
	    - **Circular** - Managing buffers in computer systems (e.g., keyboard buffer).
	    - **Deque** - Double-ended scheduling (e.g., job queue in multithreading).
	    - **Priority Queue** - Task scheduling in operating systems or hospital triage.

2. **Non-Linear Data Structures**
    
    - **Trees**
        - **Binary Tree** - Represent hierarchical structures like family trees or folder structures.
        - **Binary Search Tree (BST)** - Efficient searching, insertion, and deletion in dictionaries or databases.
        - **AVL Tree** - Self-balancing tree used in database indexing for maintaining sorted data.
        - **Red-Black Tree** - Balances dynamic sets in real-time applications like Java Collections.
        - **Segment Tree** - Efficient range queries for sums/min/max in gaming leaderboards or interval-related tasks.
        - **Fenwick Tree (Binary Indexed Tree)** - Fast cumulative frequency calculations, e.g., in stock trading platforms.
        - **B-Tree, B+ Tree** - Used in database indexing and file systems like NTFS or SQLite.
    - **Graphs**
        - **Directed Graphs** - Represent workflows or dependencies like task scheduling or web page linking.
        - **Undirected Graphs** - Represent social networks where relationships are mutual.
        - **Weighted Graphs** - Model road networks with distances or costs (e.g., Google Maps).
        - **Unweighted Graphs** - Represent connections without weights, e.g., a communication network.
        - **Adjacency Matrix/List** - Efficient storage and traversal of network data in applications like routing protocols.

3. **Hashing**

- **Hash Tables** - Fast data retrieval, e.g., storing and retrieving login credentials.
- **Hash Maps** - Efficient key-value pair storage, e.g., implementing a dictionary in a programming language.
- **Hash Sets** - Fast duplicate detection, e.g., checking unique usernames during registration.
- **Trie (Prefix Tree)** - Autocomplete and spell-checking in search engines.

4. **Specialized Data Structures**

- **Heap (Min-Heap, Max-Heap)** - Priority queues, e.g., finding the shortest path (Dijkstra's algorithm).
- **Disjoint Set (Union-Find)** - Efficiently managing connected components, e.g., network connectivity or Kruskal’s MST algorithm.
- **Skip List** - Optimized search in databases for ordered datasets.
- **Suffix Array** - Pattern matching in search engines or text editors.
- **Suffix Tree** - Efficient substring search, e.g., in bioinformatics for DNA sequencing.


### **2. Algorithms Uses**

1. **Searching Algorithms**

- **Linear Search**: Checking whether an element exists in a list (e.g., searching for a name in a contact list).
- **Binary Search**: Searching in a sorted list or array (e.g., finding a word in a dictionary).
- **Interpolation Search**: Searching for a value in a large, uniformly distributed dataset (e.g., finding a specific price in an e-commerce catalog).
- **Exponential Search**: Searching in an unbounded sorted array (e.g., finding a value in an unknown size list).

2. **Sorting Algorithms**

- **Bubble Sort**: Sorting small datasets or teaching basic sorting concepts.
- **Selection Sort**: Sorting when memory write is costly (e.g., sorting data on embedded systems).
- **Insertion Sort**: Sorting a nearly sorted list (e.g., organizing incoming data in real-time).
- **Merge Sort**: Sorting large datasets or external sorting (e.g., sorting huge files).
- **Quick Sort**: Sorting large datasets efficiently (e.g., database indexing).
- **Heap Sort**: Sorting datasets with limited memory (e.g., priority queues in scheduling).
- **Radix Sort**: Sorting integers or strings efficiently (e.g., sorting large amounts of phone numbers).
- **Bucket Sort**: Sorting floating-point numbers by distributing into buckets (e.g., sorting grades).
- **Counting Sort**: Sorting integers in a specific range (e.g., counting occurrences of words in a text).

3. **Graph Algorithms**

- **Depth First Search (DFS)**: Searching or traversing graphs, e.g., maze solving or network traversal.
- **Breadth First Search (BFS)**: Shortest path in unweighted graphs, e.g., web crawling or peer-to-peer network routing.
- **Dijkstra’s Algorithm**: Shortest path in weighted graphs, e.g., GPS navigation.
- **Bellman-Ford Algorithm**: Handling graphs with negative weights, e.g., currency exchange rate systems.
- **Floyd-Warshall Algorithm**: Finding all-pairs shortest paths, e.g., routing in a transportation network.
- **Kruskal’s Algorithm**: Minimum Spanning Tree for network design, e.g., laying out roads or cable connections.
- **Prim’s Algorithm**: Minimum Spanning Tree for dense graphs, e.g., connecting cities with the minimum road cost.
- **Topological Sorting**: Task scheduling or dependency resolution, e.g., project management tools.
- __A_ Search Algorithm_*: Pathfinding with heuristics, e.g., robot navigation or map-based games.

4. **Dynamic Programming (DP)**

- **Longest Common Subsequence (LCS)**: DNA sequence alignment or file comparison.
- **Longest Increasing Subsequence (LIS)**: Stock market prediction or finding trends in time series.
- **0/1 Knapsack**: Resource allocation, e.g., in logistics or project management.
- **Coin Change Problem**: Calculating minimum coins for change, e.g., cashier systems.
- **Matrix Chain Multiplication**: Optimizing matrix multiplication order in computational problems.
- **Floyd-Warshall Algorithm**: Finding shortest paths in network optimization.
- **DP on Trees**: Solving problems like finding the diameter of a tree (e.g., organizational hierarchy).

5. **Divide and Conquer**

- **Merge Sort**: Efficient sorting for large datasets, e.g., sorting files on disk.
- **Quick Sort**: Fast sorting for large, random datasets (e.g., database query optimization).
- **Binary Search**: Searching in sorted datasets, e.g., finding a product in an online store.
- **Karatsuba Algorithm for Fast Multiplication**: Efficient multiplication of large numbers (e.g., cryptography).

6. **Greedy Algorithms**

- **Activity Selection**: Scheduling tasks or events with minimal overlap, e.g., conference room bookings.
- **Huffman Encoding**: Data compression, e.g., file storage or transmission.
- **Fractional Knapsack**: Optimizing resource allocation with limited weight, e.g., packing for shipping.
- **Kruskal’s MST**: Network optimization, e.g., building cost-efficient infrastructure.
- **Prim’s MST**: Optimizing road/cable connections for a given area.

7. **Backtracking**

- **N-Queens Problem**: Solving puzzles and placement problems, e.g., chessboard puzzle solutions.
- **Sudoku Solver**: Solving Sudoku puzzles or similar constraint satisfaction problems.
- **Hamiltonian Path**: Finding optimal routes, e.g., delivery routing problems.
- **Subset Sum Problem**: Finding subsets that sum to a target value, e.g., budget planning.

8. **String Algorithms**

- **KMP Algorithm**: Pattern matching in search engines or text editors.
- **Rabin-Karp Algorithm**: Searching for patterns in a text, e.g., document search or plagiarism detection.
- **Z Algorithm**: String matching for fast substring searches in large texts.
- **Manacher’s Algorithm (Longest Palindromic Substring)**: Finding the longest palindrome in a string, e.g., in genetic sequences.

9. **Mathematical Algorithms**

- **Euclid’s Algorithm (GCD)**: Finding the greatest common divisor, e.g., for reducing fractions or cryptographic key generation.
- **Sieve of Eratosthenes**: Generating prime numbers, e.g., in cryptography.
- **Modular Exponentiation**: Efficient computation for large powers, e.g., in RSA encryption.
- **Matrix Exponentiation**: Computing Fibonacci numbers or solving linear recurrence relations.
- **Fibonacci Sequence**: Predicting population growth or financial forecasting.

10. **Bit Manipulation**

- **XOR Tricks**: Fast checks for even/odd or finding unique numbers, e.g., in error detection algorithms.
- **Counting Set Bits**: Counting the number of 1s in a binary representation, e.g., in network routing algorithms.
- **Bit Masking**: Optimizing storage or toggling states, e.g., in game state management.
- **Subset Generation**: Generating subsets of a set for combinatorial problems, e.g., in decision-making algorithms.

11. **Advanced Algorithms**

- **Segment Tree (Range Queries)**: Querying and updating ranges in datasets, e.g., in stock market analysis.
- **Fenwick Tree**: Efficient cumulative frequency calculation, e.g., in financial data processing.
- **Sparse Table**: Preprocessing for efficient range queries, e.g., in minimum or maximum queries in time-series data.
- **Fast Fourier Transform (FFT)**: Signal processing or audio/video compression.
- **Convex Hull Algorithm**: Solving geometric problems, e.g., in robotics or 3D modeling.

12. **Miscellaneous**

- **Sliding Window Technique**: Solving problems like longest substring without repeating characters, e.g., in real-time data analysis.
- **Two Pointer Technique**: Solving problems like partitioning arrays or linked lists, e.g., in array-based algorithms.
- **Union-Find Operations**: Managing connected components in network analysis or social networks.
- **Ternary Search**: Finding the optimal point in unimodal functions, e.g., optimizing resource allocation in production.


---
# Implementation Overview



> Resources
- [DSA BY Google](https://techdevguide.withgoogle.com/paths/data-structures-and-algorithms/)


##### 1. **Array**
- **Definition:** A collection of elements identified by index or key.
- **Properties:** 
  - Fixed size.
  - Allows random access to elements.
  - Stores elements of the same data type.
- **Implementation:** Typically implemented using a contiguous block of memory.
  - **Example:**
    ```cpp
    int arr[5] = {1, 2, 3, 4, 5};
    ```

##### 2. **Linked List**
- **Definition:** A linear data structure where elements are stored in nodes, with each node containing data and a reference to the next node.
- **Types:**
  - **Singly Linked List:** Each node points to the next node.
  - **Doubly Linked List:** Each node points to both the next and the previous node.
- **Implementation:** Uses nodes with pointers to create connections between elements.
  - **Example:**
    ```cpp
    struct Node {
        int data;
        Node* next;
    };
    ```

##### 3. **Stack**
- **Definition:** A linear data structure that follows the Last In, First Out (LIFO) principle.
- **Operations:**
  - **push(x):** Insert an element at the top.
  - **pop():** Remove the top element.
  - **peek():** Get the top element without removing it.
- **Implementation:** Can be implemented using an array or linked list.
  - **Example using array:**
    ```cpp
    class Stack {
        int top;
        int arr[100];
    public:
        Stack() : top(-1) {}
        void push(int x) { arr[++top] = x; }
        void pop() { top--; }
        int peek() { return arr[top]; }
    };
    ```

##### 4. **Queue**
- **Definition:** A linear data structure that follows the First In, First Out (FIFO) principle.
- **Operations:**
  - **enqueue(x):** Insert an element at the rear.
  - **dequeue():** Remove the front element.
  - **front():** Get the front element without removing it.
- **Implementation:** Can be implemented using an array or linked list.
  - **Example using linked list:**
    ```cpp
    struct Node {
        int data;
        Node* next;
    };
    class Queue {
        Node *front, *rear;
    public:
        Queue() : front(nullptr), rear(nullptr) {}
        void enqueue(int x) { /* code */ }
        void dequeue() { /* code */ }
    };
    ```

##### 5. **Priority Queue**
- **Definition:** A special type of queue where each element is associated with a priority, and elements are dequeued based on their priority.
- **Implementation:**
  - **Heap-based implementation:** A common method where the highest (or lowest) priority element is always at the root.
    ```cpp
    #include <queue>
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    ```
  - **Binary Heap:** A binary tree where the parent node is always greater (max-heap) or smaller (min-heap) than its children.

##### 6. **Binary Search Tree (BST)**
- **Definition:** A binary tree where each node has a key, and every node's left subtree has smaller keys, and the right subtree has larger keys.
- **Properties:**
  - Allows for efficient searching, insertion, and deletion.
  - No duplicate elements.
- **Implementation:**
  - **Example:**
    ```cpp
    struct Node {
        int data;
        Node *left, *right;
    };
    Node* insert(Node* root, int key) {
        if (!root) return new Node{key, nullptr, nullptr};
        if (key < root->data) root->left = insert(root->left, key);
        else root->right = insert(root->right, key);
        return root;
    }
    ```

##### 7. **Hash Table**
- **Definition:** A data structure that maps keys to values for efficient lookup.
- **Properties:**
  - Uses a hash function to compute an index into an array of buckets or slots.
  - Handles collisions using methods like chaining or open addressing.
- **Implementation:** Commonly implemented using an array of linked lists (chaining).
  - **Example using C++ STL:**
    ```cpp
    #include <unordered_map>
    std::unordered_map<int, std::string> hashTable;
    hashTable[1] = "One";
    hashTable[2] = "Two";
    ```

##### 8. **Graph**
- **Definition:** A collection of nodes (vertices) connected by edges.
- **Types:**
  - **Directed Graph:** Edges have a direction.
  - **Undirected Graph:** Edges do not have a direction.
- **Representation:**
  - **Adjacency Matrix:** 2D array where `matrix[i][j]` represents an edge between `i` and `j`.
  - **Adjacency List:** Array of lists where each list represents a node and contains a list of edges.
    ```cpp
    std::vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(4);
    ```

##### 9. **Trie (Prefix Tree)**
- **Definition:** A tree-like data structure used to store a dynamic set of strings where nodes represent prefixes of strings.
- **Operations:**
  - **Insert:** Add a word to the Trie.
  - **Search:** Check if a word exists in the Trie.
- **Implementation:** Nodes contain an array (or hash map) of children and a boolean to mark the end of a word.
  - **Example:**
    ```cpp
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    ```

##### 10. **Heap**
- **Definition:** A special tree-based data structure that satisfies the heap property.
- **Types:**
  - **Max Heap:** Parent nodes are always greater than or equal to their children.
  - **Min Heap:** Parent nodes are always less than or equal to their children.
- **Implementation:** Usually implemented as a binary heap, where the heap is represented as an array.
  - **Example:**
    ```cpp
    std::priority_queue<int> maxHeap; // Max-Heap by default
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-Heap
    ```

##### 11. **Deque (Double-ended Queue)**
- **Definition:** A linear data structure that allows insertion and deletion at both ends.
- **Properties:**
  - Can operate both as a queue and a stack.
  - Dynamic size.
- **Implementation:** Can be implemented using a doubly linked list or a dynamic array.
  - **Example using C++ STL:**
    ```cpp
    #include <deque>
    std::deque<int> dq;
    dq.push_back(1);   // Insert at rear
    dq.push_front(2);  // Insert at front
    dq.pop_back();     // Remove from rear
    dq.pop_front();    // Remove from front
    ```

##### 12. **Segment Tree**
- **Definition:** A tree data structure used for storing information about intervals or segments.
- **Properties:**
  - Useful for answering range queries like sum, min, max, etc.
  - Can handle dynamic updates to the elements.
- **Implementation:** Built using a recursive approach.
  - **Example:**
    ```cpp
    int tree[4*N]; // Array representation of Segment Tree
    void build(int node, int start, int end) { /* Code */ }
    ```

##### 13. **Fenwick Tree (Binary Indexed Tree)**
- **Definition:** A data structure that provides efficient methods for cumulative frequency tables or ranges.
- **Properties:**
  - Supports point updates and prefix queries.
- **Implementation:** Implemented using an array where each element is responsible for storing cumulative information.
  - **Example:**
    ```cpp
    int BIT[N];
    void update(int idx, int value) { /* Code */ }
    int query(int idx) { /* Code */ }
    ```

These notes provide a summary of common data structures, their properties, and how they can be implemented in C++.

Apologies for missing those! Let's cover `set`, `map`, and other related data structures in C++.

##### 14. **Set**
- **Definition:** A collection of unique elements stored in a specific order.
- **Properties:**
  - Elements are automatically sorted.
  - No duplicate elements are allowed.
- **Types:**
  - **std::set:** Ordered set, implemented as a balanced binary search tree (typically a Red-Black Tree).
  - **std::unordered_set:** Unordered set, implemented using a hash table.
- **Implementation:**
  - **std::set:**
    ```cpp
    std::set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    ```
  - **std::unordered_set:**
    ```cpp
    std::unordered_set<int> us;
    us.insert(10);
    us.insert(5);
    us.insert(20);
    ```

##### 15. **Map**
- **Definition:** A collection of key-value pairs, where each key is unique.
- **Properties:**
  - Keys are automatically sorted.
  - Each key maps to exactly one value.
- **Types:**
  - **std::map:** Ordered map, implemented as a balanced binary search tree (typically a Red-Black Tree).
  - **std::unordered_map:** Unordered map, implemented using a hash table.
- **Implementation:**
  - **std::map:**
    ```cpp
    std::map<int, std::string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    ```
  - **std::unordered_map:**
    ```cpp
    std::unordered_map<int, std::string> um;
    um[1] = "one";
    um[2] = "two";
    um[3] = "three";
    ```

##### 16. **Multiset**
- **Definition:** A set-like container that allows duplicate elements.
- **Properties:**
  - Elements are automatically sorted.
  - Duplicates are allowed.
- **Types:**
  - **std::multiset:** Ordered multiset, implemented as a balanced binary search tree.
  - **std::unordered_multiset:** Unordered multiset, implemented using a hash table.
- **Implementation:**
  - **std::multiset:**
    ```cpp
    std::multiset<int> ms;
    ms.insert(10);
    ms.insert(5);
    ms.insert(10); // Duplicate allowed
    ```
  - **std::unordered_multiset:**
    ```cpp
    std::unordered_multiset<int> ums;
    ums.insert(10);
    ums.insert(5);
    ums.insert(10); // Duplicate allowed
    ```

##### 17. **Multimap**
- **Definition:** A map-like container that allows multiple keys to have the same value.
- **Properties:**
  - Keys are automatically sorted.
  - Duplicates keys are allowed.
- **Types:**
  - **std::multimap:** Ordered multimap, implemented as a balanced binary search tree.
  - **std::unordered_multimap:** Unordered multimap, implemented using a hash table.
- **Implementation:**
  - **std::multimap:**
    ```cpp
    std::multimap<int, std::string> mm;
    mm.insert({1, "one"});
    mm.insert({2, "two"});
    mm.insert({1, "another one"}); // Duplicate key allowed
    ```
  - **std::unordered_multimap:**
    ```cpp
    std::unordered_multimap<int, std::string> umm;
    umm.insert({1, "one"});
    umm.insert({2, "two"});
    umm.insert({1, "another one"}); // Duplicate key allowed
    ```

##### 18. **Bitset**
- **Definition:** A specialized container to store bits efficiently.
- **Properties:**
  - Fixed size.
  - Supports bitwise operations.
- **Implementation:**
  - **Example:**
    ```cpp
    #include <bitset>
    std::bitset<8> b(5); // 00000101
    b.set(2);            // 00000111
    b.flip(0);           // 00000110
    ```

### Summary of Data Structures:
- **Ordered Structures:** `std::set`, `std::map`, `std::multiset`, `std::multimap` use balanced binary search trees.
- **Unordered Structures:** `std::unordered_set`, `std::unordered_map`, `std::unordered_multiset`, `std::unordered_multimap` use hash tables for faster average case operations.
- **Special Structures:** `std::bitset` is optimized for bit-level manipulation.

These additions should complete the set of data structures commonly used in C++!

---

# Inbuilt Linked List and Binary Tree in C++

##### 1. **Linked List**:
   - **`std::list`**: This is a doubly linked list, which allows for efficient insertion and deletion of elements from both ends and the middle. It does not provide random access to elements, unlike arrays or vectors.

   ```cpp
   #include <list>

   int main() {
       std::list<int> myList;
       myList.push_back(1);
       myList.push_front(2);
       myList.pop_back();
       myList.pop_front();
       return 0;
   }
   ```

##### 2. **Binary Tree**:
   - **`std::set` and `std::map`**: These are associative containers that use a balanced binary tree (typically a Red-Black Tree) to store elements. `std::set` is used for storing unique elements, while `std::map` stores key-value pairs.

   ```cpp
   #include <set>
   #include <map>

   int main() {
       std::set<int> mySet;
       mySet.insert(1);
       mySet.insert(2);
       
       std::map<int, std::string> myMap;
       myMap[1] = "One";
       myMap[2] = "Two";
       
       return 0;
   }
   ```
