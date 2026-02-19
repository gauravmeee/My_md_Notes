---
description: By Google 🏛️
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

# Data Structure: All Data Structures

> Resources

* [DSA BY Google](https://techdevguide.withgoogle.com/paths/data-structures-and-algorithms/)

## Types of Data Structures

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

***

## Implementation Overview

> Resources

* [DSA BY Google](https://techdevguide.withgoogle.com/paths/data-structures-and-algorithms/)

**1. Array**

* **Definition:** A collection of elements identified by index or key.
* **Properties:**
  * Fixed size.
  * Allows random access to elements.
  * Stores elements of the same data type.
* **Implementation:** Typically implemented using a contiguous block of memory.
  *   **Example:**

      ```cpp
      int arr[5] = {1, 2, 3, 4, 5};
      ```

**2. Linked List**

* **Definition:** A linear data structure where elements are stored in nodes, with each node containing data and a reference to the next node.
* **Types:**
  * **Singly Linked List:** Each node points to the next node.
  * **Doubly Linked List:** Each node points to both the next and the previous node.
* **Implementation:** Uses nodes with pointers to create connections between elements.
  *   **Example:**

      ```cpp
      struct Node {
          int data;
          Node* next;
      };
      ```

**3. Stack**

* **Definition:** A linear data structure that follows the Last In, First Out (LIFO) principle.
* **Operations:**
  * **push(x):** Insert an element at the top.
  * **pop():** Remove the top element.
  * **peek():** Get the top element without removing it.
* **Implementation:** Can be implemented using an array or linked list.
  *   **Example using array:**

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

**4. Queue**

* **Definition:** A linear data structure that follows the First In, First Out (FIFO) principle.
* **Operations:**
  * **enqueue(x):** Insert an element at the rear.
  * **dequeue():** Remove the front element.
  * **front():** Get the front element without removing it.
* **Implementation:** Can be implemented using an array or linked list.
  *   **Example using linked list:**

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

**5. Priority Queue**

* **Definition:** A special type of queue where each element is associated with a priority, and elements are dequeued based on their priority.
* **Implementation:**
  *   **Heap-based implementation:** A common method where the highest (or lowest) priority element is always at the root.

      ```cpp
      #include <queue>
      std::priority_queue<int> pq;
      pq.push(10);
      pq.push(5);
      pq.push(20);
      ```
  * **Binary Heap:** A binary tree where the parent node is always greater (max-heap) or smaller (min-heap) than its children.

**6. Binary Search Tree (BST)**

* **Definition:** A binary tree where each node has a key, and every node's left subtree has smaller keys, and the right subtree has larger keys.
* **Properties:**
  * Allows for efficient searching, insertion, and deletion.
  * No duplicate elements.
* **Implementation:**
  *   **Example:**

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

**7. Hash Table**

* **Definition:** A data structure that maps keys to values for efficient lookup.
* **Properties:**
  * Uses a hash function to compute an index into an array of buckets or slots.
  * Handles collisions using methods like chaining or open addressing.
* **Implementation:** Commonly implemented using an array of linked lists (chaining).
  *   **Example using C++ STL:**

      ```cpp
      #include <unordered_map>
      std::unordered_map<int, std::string> hashTable;
      hashTable[1] = "One";
      hashTable[2] = "Two";
      ```

**8. Graph**

* **Definition:** A collection of nodes (vertices) connected by edges.
* **Types:**
  * **Directed Graph:** Edges have a direction.
  * **Undirected Graph:** Edges do not have a direction.
* **Representation:**
  * **Adjacency Matrix:** 2D array where `matrix[i][j]` represents an edge between `i` and `j`.
  *   **Adjacency List:** Array of lists where each list represents a node and contains a list of edges.

      ```cpp
      std::vector<int> adj[5];
      adj[0].push_back(1);
      adj[0].push_back(4);
      ```

**9. Trie (Prefix Tree)**

* **Definition:** A tree-like data structure used to store a dynamic set of strings where nodes represent prefixes of strings.
* **Operations:**
  * **Insert:** Add a word to the Trie.
  * **Search:** Check if a word exists in the Trie.
* **Implementation:** Nodes contain an array (or hash map) of children and a boolean to mark the end of a word.
  *   **Example:**

      ```cpp
      struct TrieNode {
          TrieNode* children[26];
          bool isEndOfWord;
          TrieNode() : isEndOfWord(false) {
              for (int i = 0; i < 26; i++) children[i] = nullptr;
          }
      };
      ```

**10. Heap**

* **Definition:** A special tree-based data structure that satisfies the heap property.
* **Types:**
  * **Max Heap:** Parent nodes are always greater than or equal to their children.
  * **Min Heap:** Parent nodes are always less than or equal to their children.
* **Implementation:** Usually implemented as a binary heap, where the heap is represented as an array.
  *   **Example:**

      ```cpp
      std::priority_queue<int> maxHeap; // Max-Heap by default
      std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-Heap
      ```

**11. Deque (Double-ended Queue)**

* **Definition:** A linear data structure that allows insertion and deletion at both ends.
* **Properties:**
  * Can operate both as a queue and a stack.
  * Dynamic size.
* **Implementation:** Can be implemented using a doubly linked list or a dynamic array.
  *   **Example using C++ STL:**

      ```cpp
      #include <deque>
      std::deque<int> dq;
      dq.push_back(1);   // Insert at rear
      dq.push_front(2);  // Insert at front
      dq.pop_back();     // Remove from rear
      dq.pop_front();    // Remove from front
      ```

**12. Segment Tree**

* **Definition:** A tree data structure used for storing information about intervals or segments.
* **Properties:**
  * Useful for answering range queries like sum, min, max, etc.
  * Can handle dynamic updates to the elements.
* **Implementation:** Built using a recursive approach.
  *   **Example:**

      ```cpp
      int tree[4*N]; // Array representation of Segment Tree
      void build(int node, int start, int end) { /* Code */ }
      ```

**13. Fenwick Tree (Binary Indexed Tree)**

* **Definition:** A data structure that provides efficient methods for cumulative frequency tables or ranges.
* **Properties:**
  * Supports point updates and prefix queries.
* **Implementation:** Implemented using an array where each element is responsible for storing cumulative information.
  *   **Example:**

      ```cpp
      int BIT[N];
      void update(int idx, int value) { /* Code */ }
      int query(int idx) { /* Code */ }
      ```

These notes provide a summary of common data structures, their properties, and how they can be implemented in C++.

Apologies for missing those! Let's cover `set`, `map`, and other related data structures in C++.

**14. Set**

* **Definition:** A collection of unique elements stored in a specific order.
* **Properties:**
  * Elements are automatically sorted.
  * No duplicate elements are allowed.
* **Types:**
  * **std::set:** Ordered set, implemented as a balanced binary search tree (typically a Red-Black Tree).
  * **std::unordered\_set:** Unordered set, implemented using a hash table.
* **Implementation:**
  *   **std::set:**

      ```cpp
      std::set<int> s;
      s.insert(10);
      s.insert(5);
      s.insert(20);
      ```
  *   **std::unordered\_set:**

      ```cpp
      std::unordered_set<int> us;
      us.insert(10);
      us.insert(5);
      us.insert(20);
      ```

**15. Map**

* **Definition:** A collection of key-value pairs, where each key is unique.
* **Properties:**
  * Keys are automatically sorted.
  * Each key maps to exactly one value.
* **Types:**
  * **std:**:map: Ordered map, implemented as a balanced binary search tree (typically a Red-Black Tree).
  * **std::unordered\_map:** Unordered map, implemented using a hash table.
* **Implementation:**
  *   **std:**:map:

      ```cpp
      std::map<int, std::string> m;
      m[1] = "one";
      m[2] = "two";
      m[3] = "three";
      ```
  *   **std::unordered\_map:**

      ```cpp
      std::unordered_map<int, std::string> um;
      um[1] = "one";
      um[2] = "two";
      um[3] = "three";
      ```

**16. Multiset**

* **Definition:** A set-like container that allows duplicate elements.
* **Properties:**
  * Elements are automatically sorted.
  * Duplicates are allowed.
* **Types:**
  * **std::multiset:** Ordered multiset, implemented as a balanced binary search tree.
  * **std::unordered\_multiset:** Unordered multiset, implemented using a hash table.
* **Implementation:**
  *   **std::multiset:**

      ```cpp
      std::multiset<int> ms;
      ms.insert(10);
      ms.insert(5);
      ms.insert(10); // Duplicate allowed
      ```
  *   **std::unordered\_multiset:**

      ```cpp
      std::unordered_multiset<int> ums;
      ums.insert(10);
      ums.insert(5);
      ums.insert(10); // Duplicate allowed
      ```

**17. Multimap**

* **Definition:** A map-like container that allows multiple keys to have the same value.
* **Properties:**
  * Keys are automatically sorted.
  * Duplicates keys are allowed.
* **Types:**
  * **std::multimap:** Ordered multimap, implemented as a balanced binary search tree.
  * **std::unordered\_multimap:** Unordered multimap, implemented using a hash table.
* **Implementation:**
  *   **std::multimap:**

      ```cpp
      std::multimap<int, std::string> mm;
      mm.insert({1, "one"});
      mm.insert({2, "two"});
      mm.insert({1, "another one"}); // Duplicate key allowed
      ```
  *   **std::unordered\_multimap:**

      ```cpp
      std::unordered_multimap<int, std::string> umm;
      umm.insert({1, "one"});
      umm.insert({2, "two"});
      umm.insert({1, "another one"}); // Duplicate key allowed
      ```

**18. Bitset**

* **Definition:** A specialized container to store bits efficiently.
* **Properties:**
  * Fixed size.
  * Supports bitwise operations.
* **Implementation:**
  *   **Example:**

      ```cpp
      #include <bitset>
      std::bitset<8> b(5); // 00000101
      b.set(2);            // 00000111
      b.flip(0);           // 00000110
      ```

#### Summary of Data Structures:

* **Ordered Structures:** `std::set`, `std::map`, `std::multiset`, `std::multimap` use balanced binary search trees.
* **Unordered Structures:** `std::unordered_set`, `std::unordered_map`, `std::unordered_multiset`, `std::unordered_multimap` use hash tables for faster average case operations.
* **Special Structures:** `std::bitset` is optimized for bit-level manipulation.

These additions should complete the set of data structures commonly used in C++!

***

## Inbuilt Linked List and Binary Tree in C++

**1. Linked List:**

* **`std::list`**: This is a doubly linked list, which allows for efficient insertion and deletion of elements from both ends and the middle. It does not provide random access to elements, unlike arrays or vectors.

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

**2. Binary Tree:**

* **`std::set` and `std::map`**: These are associative containers that use a balanced binary tree (typically a Red-Black Tree) to store elements. `std::set` is used for storing unique elements, while `std::map` stores key-value pairs.

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
