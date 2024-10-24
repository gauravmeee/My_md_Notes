

### Range of Number in C++


32-bit Data Types

| Data Type          | Power Range            | Actual Range                                   | Power of 10          | Power of 2         |
|--------------------|------------------------|------------------------------------------------|-----------------------|---------------------|
| `int`              | ±2 billion             | −2,147,483,648 to 2,147,483,647                | ±2 × 10^9            | ±2^31               |
| `unsigned int`     | 0 to 4 billion         | 0 to 4,294,967,295                             | 0 to 4 × 10^9        | 0 to 2^32           |
| `short`            | ±32 thousand           | −32,768 to 32,767                              | ±3.2 × 10^4          | ±2^15               |
| `unsigned short`   | 0 to 65 thousand       | 0 to 65,535                                    | 0 to 6.5 × 10^4      | 0 to 2^16           |
| `long`             | ±2 billion             | Platform-dependent                              | ±2 × 10^9            | ±2^31               |
| `unsigned long`    | 0 to 4 billion         | Platform-dependent                              | 0 to 4 × 10^9        | 0 to 2^32           |
| `size_t`           | 0 to 4 billion         | Platform-dependent                              | 0 to 4 × 10^9        | 0 to 2^32           |

Platform-Independent Data Types (32/64 bit)

| Data Type          | Power Range             | Actual Range                                   | Power of 10          | Power of 2         |
|--------------------|-------------------------|------------------------------------------------|-----------------------|---------------------|
| `size_t`           | 0 to 4 billion          | Platform-dependent                              | 0 to 4 × 10^9        | 0 to 2^32           |
|                    | 0 to 18 quintillion     | Platform-dependent                              | 0 to 1.8 × 10^19     | 0 to 2^64           |
| `long`             | ±2 billion              | Platform-dependent                              | ±2 × 10^9            | ±2^31               |
|                    | ±9 quintillion          | Platform-dependent                              | ±9 × 10^18           | ±2^63               |
| `unsigned long`    | 0 to 4 billion          | Platform-dependent                              | 0 to 4 × 10^9        | 0 to 2^32           |
|                    | 0 to 18 quintillion     | Platform-dependent                              | 0 to 1.8 × 10^19     | 0 to 2^64           |

64-bit Data Types

| Data Type            | Power Range         | Actual Range                                            | Power of 10      | Power of 2 |
| -------------------- | ------------------- | ------------------------------------------------------- | ---------------- | ---------- |
| `long long`          | ±9 quintillion      | −9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | ±9 × 10^18       | ±2^63      |
| `unsigned long long` | 0 to 18 quintillion | 0 to 18,446,744,073,709,551,615                         | 0 to 1.8 × 10^19 | 0 to 2^64  |

Note:  

`size_t` is always unsigned

32 bit vs platform independent
- `int/unsigned int` ≡ `long / unsigned long` (in 32 bit)
- `unsigned int`   ≡  `unsigned long` (in 32 bit)  ≡  `size_t` (in 32)

64 bit vs platform independent 
- `unsigned long long`   ≡   `size_t`(64 bit)    ≡    `unsigned long` (in 64 bit)
- `long long/unsigned long long` ≡ `long / unsigned long` (in 64 bit)

platform independent vs platform independent
2. `size_t` (in 32/64)   ≡   `unsigned long` (in 32/64) 


(15 bit) - `short/unsigned int`
(32 bit) - `int/unsigned int`
Platform Independent (32 bit or 64 bit) :  `size_t`, `long/unsigned long`, 
(64 bit) 0 `long long / unsigned long long`

---

### Datatypes in C++

| Data Type            | Size (bytes) | Range                                                            | Power of 2               |
| -------------------- | ------------ | ---------------------------------------------------------------- | ------------------------ |
| `char`               | 1            | -128 to 127                                                      | ±2^7                     |
| `unsigned char`      | 1            | N/A                                                              | 0 to 2^8                 |
| `short`              | 2            | -32,768 to 32,767                                                | ±2^15                    |
| `unsigned short`     | 2            | N/A                                                              | 0 to 2^16                |
| `int`                | 4            | -2,147,483,648 to 2,147,483,647                                  | ±2^31                    |
| `unsigned int`       | 4            | N/A                                                              | 0 to 2^32                |
| `long`               | 4 or 8       | -2,147,483,648 to 2,147,483,647 (32-bit)                         | ±2^31 (32-bit)           |
|                      |              | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (64-bit) | ±2^63 (64-bit)           |
| `unsigned long`      | 4 or 8       | N/A                                                              | 0 to 2^32 (32-bit)       |
|                      |              | 0 to 18,446,744,073,709,551,615 (64-bit)                         | 0 to 2^64 (64-bit)       |
| `long long`          | 8            | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807          | ±2^63                    |
| `unsigned long long` | 8            | N/A                                                              | 0 to 2^64                |
| `wchar_t`            | 2 or 4       | Depends on the platform (e.g., UTF-16/32)                        | Varies based on encoding |
| `bool`               | 1            | false (0) or true (1)                                            | N/A                      |
| `float`              | 4            | ±3.4 × 10^38 (approx)                                            | N/A                      |
| `double`             | 8            | ±1.7 × 10^308 (approx)                                           | N/A                      |
| `long double`        | 8, 10, or 16 | Varies by platform (typically 15 to 18 decimal digits)           | Varies                   |
| `float128`           | 16           | ±1.18973149535723176502129 × 10^4932 (approx)                    | ±2^127                   |
| `std::string`        | Varies       | Dependent on string content                                      | N/A                      |
| `std::vector<T>`     | Varies       | Dependent on the number of elements                              | N/A                      |

- **Size**: The size may vary based on the platform and compiler.
- **Range**: For floating-point types, the range is approximate and can vary based on the precision and representation.
- **Power of 10** and **Power of 2**: Not all types have meaningful powers of 10 or 2 (especially for floating-point types).
- **`wchar_t`**: The size and range depend on whether it is UTF-16 (2 bytes) or UTF-32 (4 bytes) on your platform.
- **`float128`**: Not part of the standard C++ but available in some implementations for higher precision. 
- The sizes of `long` and `unsigned long` may vary depending on whether they are 32-bit or 64-bit, which can vary across different platforms and compilers.
---
### Ceil in C++:
- Use `std::ceil()` from `<cmath>` to find the smallest integer greater than or equal to a number.
- Example: `std::ceil(4.3)` returns `5.0`.

### Integer Division in C++:
- Dividing `int` by `int` results in an `int`.
- Fractional part is truncated (e.g., `7 / 2` gives `3`).
- To get a floating-point result, cast one operand: `static_cast<double>(a) / b`.
---
#### Double to Integer Conversion

1. **Direct Assignment (Truncation)** Assigning a `double` to an `int` variable truncates the decimal part, effectively rounding toward zero.
```cpp
// implicit truncate
double num = 2.9;
int truncated = num;  // truncated = 2
```

2. **`static_cast<int>()` (Truncation)** Assigning a `double` to an `int` variable truncates the decimal part, effectively rounding toward zero.
```cpp
// explicitly truncate
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