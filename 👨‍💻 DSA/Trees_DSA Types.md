

# Types of Trees

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
    - **Binary**
        - **BST** (Binary Search Tree)
            - **AVL** (Self-balancing Binary Search Tree)
            - **Red-Black** (Self-balancing Binary Search Tree)
        - **Balanced** (Binary trees where the height difference between subtrees is minimized)
        - **Full** (Each node has 0 or 2 children)
        - **Complete** (All levels are fully filled except possibly the last level, filled left to right)
        - **Perfect** (A Full Binary Tree where all leaf nodes are at the same level)
        - **Skewed**
            - **Left-Skewed** (All nodes have left children only)
            - **Right-Skewed** (All nodes have right children only)
        - **Degenerate** (Resembling a linked list where each parent node has only one child)
    - **Multi-way**
        - **B-Tree** (Balanced multi-way search tree, used for indexing in databases)
        - **B+ Tree** (Variant of B-Tree with all data in leaf nodes, used for efficient range queries)
        - **Trie** (Prefix Tree, used for efficient storage and retrieval of strings)
        - **Segment Tree** (Used for storing intervals or segments, supporting range queries)
        - **Fenwick Tree** (Binary Indexed Tree, used for efficient range sum queries and updates)
        - **Suffix Tree** (Stores all suffixes of a string, used for fast substring searching and pattern matching)
        - **Splay Tree** (Self-adjusting Binary Search Tree that moves frequently accessed elements to the root)
        - **K-D Tree** (Space-partitioning tree used for multidimensional search problems like nearest neighbor search)

# More Trees (That do not fit in above Categories)

- **Heap**
	- **Max-Heap** (Binary tree where the parent node is larger than its children)
	- **Min-Heap** (Binary tree where the parent node is smaller than its children)
	- **Used for implementing priority queues**
- **Graph-Related**
	- **Spanning Tree** (A tree that connects all vertices of a graph with the minimum number of edges)
- **Decision**
	- **Decision Tree** (A tree used for decision analysis or machine learning)
- **Space Partitioning**
	- **Cartesian Tree** (A tree where in-order traversal gives a sequence while maintaining the heap property)
	- **K-D Tree** (Used in multidimensional search problems)
