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

# DSA: Data Structure and Algorithm Use-Cases

**1. Data Structures Uses**

1. **Linear Data Structures**
   * **Array** - Used for storing fixed-size data like employee IDs or scores in a game.
   * **Linked List**
     * **Singly** - Implementing a chain of nodes in blockchain, Playlist.
     * **Doubly** - Navigating forward/backward in a media playlist.
     * **Circular** -Managing processes in an operating system (Round Robin Scheduling).
   * **Stack** - Undo operation in text editors or browsers' backtracking history.
   * **Queue**
     * **Simple** - Ticketing system for customer service or bank counters.
     * **Circular** - Managing buffers in computer systems (e.g., keyboard buffer).
     * **Deque** - Double-ended scheduling (e.g., job queue in multithreading).
     * **Priority Queue** - Task scheduling in operating systems or hospital triage.
2. **Non-Linear Data Structures**
   * **Trees**
     * **Binary Tree** - Represent hierarchical structures like family trees or folder structures.
     * **Binary Search Tree (BST)** - Efficient searching, insertion, and deletion in dictionaries or databases.
     * **AVL Tree** - Self-balancing tree used in database indexing for maintaining sorted data.
     * **Red-Black Tree** - Balances dynamic sets in real-time applications like Java Collections.
     * **Segment Tree** - Efficient range queries for sums/min/max in gaming leaderboards or interval-related tasks.
     * **Fenwick Tree (Binary Indexed Tree)** - Fast cumulative frequency calculations, e.g., in stock trading platforms.
     * **B-Tree, B+ Tree** - Used in database indexing and file systems like NTFS or SQLite.
   * **Graphs**
     * **Directed Graphs** - Represent workflows or dependencies like task scheduling or web page linking.
     * **Undirected Graphs** - Represent social networks where relationships are mutual.
     * **Weighted Graphs** - Model road networks with distances or costs (e.g., Google Maps).
     * **Unweighted Graphs** - Represent connections without weights, e.g., a communication network.
     * **Adjacency Matrix/List** - Efficient storage and traversal of network data in applications like routing protocols.
3. **Hashing**
   * **Hash Tables** - Fast data retrieval, e.g., storing and retrieving login credentials.
   * **Hash Maps** - Efficient key-value pair storage, e.g., implementing a dictionary in a programming language.
   * **Hash Sets** - Fast duplicate detection, e.g., checking unique usernames during registration.
   * **Trie (Prefix Tree)** - Autocomplete and spell-checking in search engines.
4. **Specialized Data Structures**
   * **Heap (Min-Heap, Max-Heap)** - Priority queues, e.g., finding the shortest path (Dijkstra's algorithm).
   * **Disjoint Set (Union-Find)** - Efficiently managing connected components, e.g., network connectivity or Kruskal’s MST algorithm.
   * **Skip List** - Optimized search in databases for ordered datasets.
   * **Suffix Array** - Pattern matching in search engines or text editors.
   * **Suffix Tree** - Efficient substring search, e.g., in bioinformatics for DNA sequencing.

**2. Algorithms Uses**

1. **Searching Algorithms**
   * **Linear Search**: Checking whether an element exists in a list (e.g., searching for a name in a contact list).
   * **Binary Search**: Searching in a sorted list or array (e.g., finding a word in a dictionary).
   * **Interpolation Search**: Searching for a value in a large, uniformly distributed dataset (e.g., finding a specific price in an e-commerce catalog).
   * **Exponential Search**: Searching in an unbounded sorted array (e.g., finding a value in an unknown size list).
2. **Sorting Algorithms**
   * **Bubble Sort**: Sorting small datasets or teaching basic sorting concepts.
   * **Selection Sort**: Sorting when memory write is costly (e.g., sorting data on embedded systems).
   * **Insertion Sort**: Sorting a nearly sorted list (e.g., organizing incoming data in real-time).
   * **Merge Sort**: Sorting large datasets or external sorting (e.g., sorting huge files).
   * **Quick Sort**: Sorting large datasets efficiently (e.g., database indexing).
   * **Heap Sort**: Sorting datasets with limited memory (e.g., priority queues in scheduling).
   * **Radix Sort**: Sorting integers or strings efficiently (e.g., sorting large amounts of phone numbers).
   * **Bucket Sort**: Sorting floating-point numbers by distributing into buckets (e.g., sorting grades).
   * **Counting Sort**: Sorting integers in a specific range (e.g., counting occurrences of words in a text).
3. **Graph Algorithms** ⭐
   * **Depth First Search (DFS)**: Searching or ==traversing graphs==, e.g., maze solving or network traversal.
   * **Breadth First Search (BFS)**: ==Shortest path== in ==unweighted graphs==, e.g., web crawling or peer-to-peer network routing.
   * \==**Dijkstra’s Algorithm**==: ==Shortest path== in ==weighted graphs==, e.g., GPS navigation.
   * \==**Bellman-Ford Algorithm**==: Handling graphs with negative weights, e.g., currency exchange rate systems.
   * \==**Floyd-Warshall Algorithm**:== Finding ==all-pairs shortest paths==, e.g., routing in a transportation network.
   * \==**Kruskal’s Algorithm**==: ==Minimum Spanning Tree== for ==network design==, e.g., laying out roads or cable connections.
   * \==**Prim’s Algorithm**:== ==Minimum Spanning Tree== for ==dense graphs==, e.g., connecting cities with the minimum road cost.
   * **Topological Sorting**: Task scheduling or dependency resolution, e.g., project management tools.
   * **==A`*` Search Algorithm==:** Pathfinding with heuristics, e.g., robot navigation or map-based games.
4. **Dynamic Programming (DP)**
   * **Longest Common Subsequence (LCS)**: DNA sequence alignment or file comparison.
   * **Longest Increasing Subsequence (LIS)**: Stock market prediction or finding trends in time series.
   * **0/1 Knapsack**: Resource allocation, e.g., in logistics or project management.
   * **Coin Change Problem**: Calculating minimum coins for change, e.g., cashier systems.
   * **Matrix Chain Multiplication**: Optimizing matrix multiplication order in computational problems.
   * **Floyd-Warshall Algorithm**: Finding shortest paths in network optimization.
   * **DP on Trees**: Solving problems like finding the diameter of a tree (e.g., organizational hierarchy).
5. **Divide and Conquer**
   * **Merge Sort**: Efficient sorting for large datasets, e.g., sorting files on disk.
   * **Quick Sort**: Fast sorting for large, random datasets (e.g., database query optimization).
   * **Binary Search**: Searching in sorted datasets, e.g., finding a product in an online store.
   * **Karatsuba Algorithm for Fast Multiplication**: Efficient multiplication of large numbers (e.g., cryptography).
6. **Greedy Algorithms**
   * **Activity Selection**: Scheduling tasks or events with minimal overlap, e.g., conference room bookings.
   * **Huffman Encoding**: Data compression, e.g., file storage or transmission.
   * **Fractional Knapsack**: Optimizing resource allocation with limited weight, e.g., packing for shipping.
   * **Kruskal’s MST**: Network optimization, e.g., building cost-efficient infrastructure.
   * **Prim’s MST**: Optimizing road/cable connections for a given area.
7. **Backtracking**
   * **N-Queens Problem**: Solving puzzles and placement problems, e.g., chessboard puzzle solutions.
   * **Sudoku Solver**: Solving Sudoku puzzles or similar constraint satisfaction problems.
   * **Hamiltonian Path**: Finding optimal routes, e.g., delivery routing problems.
   * **Subset Sum Problem**: Finding subsets that sum to a target value, e.g., budget planning.
8. **String Algorithms**
   * **KMP Algorithm**: Pattern matching in search engines or text editors.
   * **Rabin-Karp Algorithm**: Searching for patterns in a text, e.g., document search or plagiarism detection.
   * **Z Algorithm**: String matching for fast substring searches in large texts.
   * **Manacher’s Algorithm (Longest Palindromic Substring)**: Finding the longest palindrome in a string, e.g., in genetic sequences.
9. **Mathematical Algorithms**
   * **Euclid’s Algorithm (GCD)**: Finding the greatest common divisor, e.g., for reducing fractions or cryptographic key generation.
   * **Sieve of Eratosthenes**: Generating prime numbers, e.g., in cryptography.
   * **Modular Exponentiation**: Efficient computation for large powers, e.g., in RSA encryption.
   * **Matrix Exponentiation**: Computing Fibonacci numbers or solving linear recurrence relations.
   * **Fibonacci Sequence**: Predicting population growth or financial forecasting.
10. **Bit Manipulation**
    * **XOR Tricks**: Fast checks for even/odd or finding unique numbers, e.g., in error detection algorithms.
    * **Counting Set Bits**: Counting the number of 1s in a binary representation, e.g., in network routing algorithms.
    * **Bit Masking**: Optimizing storage or toggling states, e.g., in game state management.
    * **Subset Generation**: Generating subsets of a set for combinatorial problems, e.g., in decision-making algorithms.
11. **Advanced Algorithms**
    * **Segment Tree (Range Queries)**: Querying and updating ranges in datasets, e.g., in stock market analysis.
    * **Fenwick Tree**: Efficient cumulative frequency calculation, e.g., in financial data processing.
    * **Sparse Table**: Preprocessing for efficient range queries, e.g., in minimum or maximum queries in time-series data.
    * **Fast Fourier Transform (FFT)**: Signal processing or audio/video compression.
    * **Convex Hull Algorithm**: Solving geometric problems, e.g., in robotics or 3D modeling.
12. **Miscellaneous**
    * **Sliding Window Technique**: Solving problems like longest substring without repeating characters, e.g., in real-time data analysis.
    * **Two Pointer Technique**: Solving problems like partitioning arrays or linked lists, e.g., in array-based algorithms.
    * **Union-Find Operations**: Managing connected components in network analysis or social networks.
    * **Ternary Search**: Finding the optimal point in unimodal functions, e.g., optimizing resource allocation in production.
