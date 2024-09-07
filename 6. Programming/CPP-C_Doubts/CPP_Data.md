
---
#### Double to Integer Conversion

1. **Direct Assignment (Truncation)** Assigning a `double` to an `int` variable truncates the decimal part, effectively rounding toward zero.
```cpp
double num = 2.9;
int truncated = num;  // truncated = 2
```

2. **`static_cast<int>()` (Truncation)** Assigning a `double` to an `int` variable truncates the decimal part, effectively rounding toward zero.
```cpp
double num = 3.7;
int result = static_cast<int>(num);  // result = 3

```

3. **`round()`** Rounds the `double` to the nearest integer. If exactly halfway, it rounds toward positive infinity.
```cpp
double num = 2.5;
int rounded = round(num);  // rounded = 3
// round(2.5) -> 3
// round(-1.5) -> -1
```

4. **`floor()`** Rounds down to the nearest integer (toward negative infinity).
```cpp
double num = 2.9;
int floored = floor(num);  // floored = 2
// floor(2.9) -> 2
// floor(-1,1) -> -2
```

5. **`ceil()`** Rounds up to the nearest integer (toward positive infinity).
```cpp
double num = 2.1;
int ceiled = ceil(num);  // ceiled = 3
// ceil(2.1) -> 3 
// ceil(-1.7) gives -1
```

---
#### NULL & nullptr
`NULL`
 is an integer constant typically defined as `0`, which can lead to type ambiguity.

`nullptr` is a keyword introduced in C++11 that represents a null pointer of type std::nullptr_t, providing type safety.

---
#### Data structures that do not support direct access via an index:

1. **Linked List**:
   - In both singly and doubly linked lists, elements are stored in nodes, with each node pointing to the next (and sometimes the previous) node. You cannot directly access an element by index; instead, you must traverse the list from the head to reach the desired node.

2. **Queue**:
   - A queue operates on a First-In-First-Out (FIFO) principle. Access to elements is restricted to the front (for removal) and the back (for insertion). There is no direct access to elements in the middle of the queue.

3. **Stack**:
   - A stack operates on a Last-In-First-Out (LIFO) principle. Similar to a queue, you can only access the top element, and there is no direct access to other elements.

4. **Priority Queue (Heap)**:
   - As mentioned earlier, a priority queue typically implemented with a heap structure only allows access to the top element. You cannot directly access elements by index.

5. **Set and Map (unordered_set, unordered_map, set, map)**:
   - In `std::set` and `std::map`, elements are typically organized in a binary search tree (for ordered versions) or a hash table (for unordered versions). Direct indexing is not supported; you must use iterators or lookup functions to access elements.

6. **Tree-Based Data Structures (e.g., Binary Search Tree, AVL Tree, Red-Black Tree)**:
   - In tree structures, elements are accessed via pointers or references by navigating the tree, rather than using an index.

*Note:* Data structures that do not support direct access via an index are typically non-linear or do not store elements in a contiguous memory block. These data structures typically require traversal or specific access functions to locate or manipulate elements.

---

### Common Integers in  C++

- **`int`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: Typically 4 bytes (32 bits), but may vary by platform.
  - **Range**: Generally −2,147,483,648 to 2,147,483,647 (32-bit).

- **`unsigned int`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Typically 4 bytes (32 bits), like `int`.
  - **Range**: Generally 0 to 4,294,967,295 (32-bit).

- **`size_t`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Varies by platform; typically 4 bytes on 32-bit systems, 8 bytes on 64-bit systems.
  - **Range**: Large enough to hold the size of any object in memory, platform-dependent.

- **`short`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: Typically 2 bytes (16 bits).
  - **Range**: Generally −32,768 to 32,767.

- **`unsigned short`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Typically 2 bytes (16 bits).
  - **Range**: Generally 0 to 65,535.

- **`long`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: Typically 4 bytes (32 bits) on 32-bit systems, 8 bytes (64 bits) on 64-bit systems.
  - **Range**: On a 32-bit system, typically −2,147,483,648 to 2,147,483,647; on a 64-bit system, it extends to a larger range.

- **`unsigned long`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Typically 4 bytes (32 bits) or 8 bytes (64 bits).
  - **Range**: Varies with size; e.g., 0 to 4,294,967,295 (32-bit) or larger (64-bit).

- **`long long`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: At least 8 bytes (64 bits).
  - **Range**: Generally −9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (64-bit).

- **`unsigned long long`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: At least 8 bytes (64 bits).
  - **Range**: Generally 0 to 18,446,744,073,709,551,615 (64-bit).