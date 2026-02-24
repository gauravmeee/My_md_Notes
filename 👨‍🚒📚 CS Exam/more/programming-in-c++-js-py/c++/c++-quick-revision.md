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

# C++ Quick Revision

**`#include <Algorithms>`:**

1. **Sort**\
   `Sort(startPointer, startPointer + n)`\
   Sorts the range from `startPointer` to `startPointer + n`. ✅ `vector`, `array`, `string` (since they support random access iterators). ❌ `map`, `set`, `list` (they do not support random access iterators).
2. **Fill**\
   `Fill(startPointer, startPointer + n - 1)`\
   Fills the range from `startPointer` to `startPointer + n - 1`. ✅ `vector`, `array`, `string` (since they support random access iterators), `list`, `deque`, `set` (any container that supports forward iterators). ❌
3. **Swap**\
   `Swap(value1, value2)`\
   Swaps the values of `value1` and `value2`. ✅ `vector`, `array`, `string`, `map`, `set`, etc. (**any two objects** of the same type, including ) ❌

**Size of Data Types:**

* **Char**: 1 byte
* **Short**: 2 bytes
* **Int**: 4 bytes
* **Long**: 8 bytes

> _Note_: The size is the same regardless of whether the datatype is signed or unsigned.

**Maximum Values of Data Types:**

* **Short**:
  * Signed: 32 × 10³ = (2¹⁵)
  * Unsigned: 65 × 10³ = (2¹⁶)
* **Int**:
  * Signed: 2 × 10⁹ = (2³¹)
  * Unsigned: 4 × 10⁹ = (2³²)
* **Long Long**:
  * Signed: 9 × 10¹⁸ = (2⁶³)
  * Unsigned: 18 × 10¹⁸ = (2⁶⁴)
* **Long**
  * On a 32-bit system, behave like `int`/`unsigned int` and On a 64-bit system, behave like `long long`/`unsigned long long`.
* **Size\_t**:
  * On both 32-bit and 64-bit, behaves like `unsigned long` on 32-bit and 64-bit.

***

1. Sort vector in descending order
2. Sort `Vector<pair>` based on second value

pair.first, pair.second ?? pair\[0], = pair\[1] doesnot support index

In C++, when using `using namespace std;`, conflicts can arise if variable names clash with standard library types, such as `map`, which conflicts with `std::map`. However, this is not an issue for variable names like `pair` in loop contexts, where `pair` refers to a loop variable and not the `std::pair` type.

comparisons in `std::map` and `std::pair` are lexicographical. For a `std::map`, the comparison of keys is done based on the `first` element first, and if they are equal, the `second` elements are compared.

***

make\_pair `pair<int, char> p1 = make_pair(1, 'A');` same as `P1(1, 'A')` or \`P1={1, 'A'}

#### Data structures that do not support direct access via an index:

1. **Linked List**:
   * In both singly and doubly linked lists, elements are stored in nodes, with each node pointing to the next (and sometimes the previous) node. You cannot directly access an element by index; instead, you must traverse the list from the head to reach the desired node.
2. **Queue**:
   * A queue operates on a First-In-First-Out (FIFO) principle. Access to elements is restricted to the front (for removal) and the back (for insertion). There is no direct access to elements in the middle of the queue.
3. **Stack**:
   * A stack operates on a Last-In-First-Out (LIFO) principle. Similar to a queue, you can only access the top element, and there is no direct access to other elements.
4. **Priority Queue (Heap)**:
   * As mentioned earlier, a priority queue typically implemented with a heap structure only allows access to the top element. You cannot directly access elements by index.
5. **Set and Map (unordered\_set, unordered\_map, set, map)**:
   * In `std::set` and `std::map`, elements are typically organized in a binary search tree (for ordered versions) or a hash table (for unordered versions). Direct indexing is not supported; you must use iterators or lookup functions to access elements.
6. **Tree-Based Data Structures (e.g., Binary Search Tree, AVL Tree, Red-Black Tree)**:
   * In tree structures, elements are accessed via pointers or references by navigating the tree, rather than using an index.

_Note:_ Data structures that do not support direct access via an index are typically non-linear or do not store elements in a contiguous memory block. These data structures typically require traversal or specific access functions to locate or manipulate elements.
