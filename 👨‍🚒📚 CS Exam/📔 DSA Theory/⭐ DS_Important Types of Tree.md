
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
            - **AVL** (Self-balancing Binary Search Tree) ⭐
            - **Red-Black** (Self-balancing Binary Search Tree) ⭐
        - **Balanced** (Binary trees where the height difference between subtrees is minimized)
        - **Full** (Each node has 0 or 2 children)
        - **Complete** (All levels are fully filled except possibly the last level, filled left to right)
        - **Perfect** (A Full Binary Tree where all leaf nodes are at the same level)
        - **Skewed**
            - **Left-Skewed** (All nodes have left children only)
            - **Right-Skewed** (All nodes have right children only)
        - **Degenerate** (Resembling a linked list where each parent node has only one child)
    - **Multi-way**
        - **B-Tree** (Balanced multi-way search tree, used for indexing in databases) ⭐
        - **B+ Tree** (Variant of B-Tree with all data in leaf nodes, used for efficient range queries) ⭐
        - **Trie** (Prefix Tree, used for efficient storage and retrieval of strings) ⭐
        - **Segment Tree** (Used for storing intervals or segments, supporting range queries)
        - **Fenwick Tree** (Binary Indexed Tree, used for efficient range sum queries and updates)
        - **Suffix Tree** (Stores all suffixes of a string, used for fast substring searching and pattern matching)
        - **Splay Tree** (Self-adjusting Binary Search Tree that moves frequently accessed elements to the root)
        - **K-D Tree** (Space-partitioning tree used for multidimensional search problems like nearest neighbor search)

# More Trees (That do not fit in above Categories)

- **Heap**
	- **Max-Heap** (Binary tree where the parent node is larger than its children)
	- **Min-Heap** (Binary tree where the parent node is smaller than its children)
	- **Used for implementing `priority queues`**
- **Graph-Related**
	- **Spanning Tree** (A tree that connects all vertices of a graph with the minimum number of edges)
- **Decision**
	- **Decision Tree** (A tree used for decision analysis or machine learning)
- **Space Partitioning**
	- **Cartesian Tree** (A tree where in-order traversal gives a sequence while maintaining the heap property)
	- **K-D Tree** (Used in multidimensional search problems)


---

# Important Trees

1. **Binary Tree**:
   - A ==tree== where each node has ==at most two children==, typically referred to as the left and right child.

2. **Heap**:
   - A ==binary tree== used to ==implement priority queues.== The heap property requires that each ==node’s value be greater than or equal to the values of its children (for a max heap)== or less than or equal to the values of its children (for a min heap).

3. **Binary Search Tree (BST)**:
   - A ==binary tree ==where for each node, the ==left child’s value is less than the node’s value==, and the ==right child’s value is greater==. This property allows efficient searching, insertion, and deletion operations.

3. **Balanced Binary Search Trees**:
   - **AVL Tree**: A ==self-balancing binary search tree== where the ==heights of two child subtrees of any node differ by== no more than one.
   - **Red-Black Tree**: A ==self-balancing binary search tree== with additional properties to ensure that the ==tree remains approximately balanced== during ==insertions and deletions.==

4. **B-Tree**:
   - A ==self-balancing tree== data structure that ==maintains sorted data== and ==allows searches, sequential access, insertions, and deletions== in logarithmic time. It is commonly used in ==databases and file systems.==

5. **B+ Tree**:
   - A ==variation of the B-tree== where all ==values are stored at the leaf level==, and internal nodes only store keys. It is used extensively in ==database indexing.==

**More:**

7. **Segment Tree**:
   - A ==binary tree== used for answering range queries efficiently. It is often used for problems that involve querying sums or minimums over an interval of an array.

8. **Trie (Prefix Tree)**:
   - A tree-like data structure ==used to store associative data structures==, such as dictionaries. It is ohow ften used for string storage and retrieval.

9. **Fenwick Tree (Binary Indexed Tree)**:
   - A data structure that provides efficient methods for querying and updating prefix sums in an array.