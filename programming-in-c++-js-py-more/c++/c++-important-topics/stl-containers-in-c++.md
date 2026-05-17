---
title: STL Containers in C++
---

#### 🔥 **STL Containers Classification:**

1. **Sequence Containers** → Store data sequentially.
   * `vector`
   * `deque`
   * `list`
   * `array`
2. **Associative Containers** → Store key-value pairs with automatic sorting.
   * `map`
   * `set`
   * `multimap`
   * `multiset`
3. **Unordered Associative Containers** → Store key-value pairs without sorting.
   * `unordered_map`
   * `unordered_set`
   * `unordered_multimap`
   * `unordered_multiset`
4. **Container Adapters** → Provide modified interface over other containers.
   * `queue`
   * `stack`
   * `priority_queue`

***

#### Containers that Do Not Support Random Access: ⭐

* **`#include <map>`**: `std::map`, `std::unordered_map` - Access by key `map[key]`
* **`#include <set>`**: `std::set`, `std::unordered_set` - Access via iterator or range-based loop `for (const auto& elem : set)`
* **`#include <list>`**: `std::list`, `std::forward_list` - Access via iterator or range-based loop `for (const auto& elem : list)`
* **`#include <queue>`**: `std::queue` - Access by `queue.front()`, `queue.back()`
* **`#include <stack>`**: `std::stack` - Access by `stack.top()`
* **`#include <deque>`**: `std::deque` - Partially supports indexing but slower than `std::vector` `deque[index]`
* **`#include <utility>`**: `std::pair` - Access by `pair.first`, `pair.second`

***

#### Container Functions vs `std::` Algorithm Functions in C++ ⭐

`find()` -> Vector & map

```cpp
// Sequential Container (use std::find)
std::vector<int> v = {1, 2, 3, 4, 5};
auto it1 = std::find(v.begin(), v.end(), 3);  // O(N)
```

```cpp
// Associative Container (use container.find)
std::map<int, std::string> m = {{1, "One"}, {2, "Two"}, {3, "Three"}};
auto it2 = m.find(2);  // O(log N)
```

`sort()` -> Vector and List

```cpp
// For vector → use std::sort
std::vector<int> v = {5, 3, 1, 4, 2};
std::sort(v.begin(), v.end());  // O(N log N)
```

```cpp
// For list → use container.sort
std::list<int> l = {5, 3, 1, 4, 2};
l.sort();  // O(N log N) using Merge Sort
```

`count` -> Vector and Set

```cpp
// For vector → use std::count
std::vector<int> v = {1, 2, 3, 1, 2, 1};
int count1 = std::count(v.begin(), v.end(), 1);  // O(N)
```

```cpp
// For set → use container.count
std::set<int> s = {1, 2, 3, 4, 5};
int count2 = s.count(3);  // O(log N)
```

`lower_boound()` -> Vector & Map

```cpp
// Vector → std::lower_bound
std::vector<int> v = {1, 3, 5, 7, 9};
auto it1 = std::lower_bound(v.begin(), v.end(), 5);  // O(log N)
```

```cpp
// Map → container.lower_bound
std::map<int, std::string> m = {{1, "One"}, {3, "Three"}, {5, "Five"}};
auto it2 = m.lower_bound(3);  // O(log N)
```

✅ **Best Practices:**

1. Use **container member functions** (`.find()`, `.count()`) for **associative containers** → faster.
2. Use **`std::` algorithm functions** for **sequential containers** → general-purpose algorithms.
3. Prefer **`std::sort()`** for sorting unless using `list`, which has its own `.sort()`.
4. Use **`std::binary_search()`** instead of `std::find()` for **sorted vectors** → faster lookup.

***

#### `.back()` & `.front()`

**Supports `.back()` and `.front()`** ✅

* **`queue`**
* **`deque`**
* **`list`**
* **`vector`**

**Does NOT support `.back()` and `.front()`** ❌

* **`stack`** → Only `.top()` is available.
* **`set` / `unordered_set`** → No `.back()` or `.front()` (since sets are not indexed).

***

#### `push_back` vs `push` (or `pop_back` vs `pop`)

**`push_back` + `pop_back()`**

* Containers - `vector`, `deque`, `list`, \`string
* Adds an element at the end or Removes the last element
* Preserves order
* TC : `O(1)`

**`push()` + `pop()`**

* Containers - `stack`, `queue`, `priority_queue`
* Adds an element at the **top (stack)** or **back (queue)** or Removes the **top (stack)** or **front (queue)** element
* Follows **LIFO** (stack) or **FIFO** (queue) behavior
* TC : `O(1)`

***

#### **C++ Data Structures and Best Containers for Operations**

**1. Lookup / Find**

* **Purpose:** Retrieve the value or check if an element exists.
* **Best Containers:** ⭐
  * **`std::unordered_map` / `std::unordered_set`** → **O(1)** average time, **O(N)** worst case.
  * **`std::map` / `std::set`** → **O(log N)**.
  * **`std::vector` / `std::deque` / `std::list`** → **O(N)** (Linear search).
* **Note:** Use **unordered\_map/set** for fast lookup. Use **map/set** if you need sorted keys. ✅

**2. Insertion**

* **Purpose:** Add new elements to the container.
* **Best Containers:**
  * **`std::unordered_map` / `std::unordered_set`** → **O(1)** average, **O(N)** worst case.
  * **`std::map` / `std::set`** → **O(log N)**.
  * **`std::vector`** →
    * End: **O(1)** amortized.
    * Middle: **O(N)**.
  * **`std::deque`** → **O(1)** at both ends, **O(N)** in the middle.
  * **`std::list`** → **O(1)** insertion at any point (using iterator).
* **Note:** Use **unordered\_map/set** for fast average-time insertion. Use **list** for efficient insertion at any position.

**3. Deletion / Erasure**

* **Purpose:** Remove elements from the container.
* **Best Containers:**
  * **`std::unordered_map` / `std::unordered_set`** → **O(1)** average, **O(N)** worst case.
  * **`std::map` / `std::set`** → **O(log N)**.
  * **`std::vector` / `std::deque`** →
    * End: **O(1)**.
    * Middle: **O(N)** due to shifting.
  * **`std::list`** → **O(1)** deletion (using iterator).
* **Note:** Use **unordered\_map/set** for fast deletion. Use **list** for efficient removal at any position.

**4. Count (Frequency Counting)**

* **Purpose:** Count occurrences of elements.
* **Best Containers:**
  * **`std::unordered_map` / `std::map`** → Store element as the key and count as the value.
  * **`std::unordered_multiset` / `std::multiset`** → Auto-maintains element counts.
* **Note:** Use **unordered\_map** for faster frequency counting. Use **multiset** for built-in count management.

**5. Access (Indexing / Random Access)**

* **Purpose:** Access elements by position.
* **Best Containers:**
  * **`std::vector` / `std::deque` / `int arr[]`** → **O(1)** direct access.
  * **`std::list` / `std::forward_list`** → **O(N)** (No direct access, requires traversal).
  * **`std::map` / `std::set`** → **O(log N)**.
* **Note:** Use **vector** for fast random access. Use **map** for key-based access.

**6. Iteration (Traversal)**

* **Purpose:** Iterate over all elements.
* **Best Containers:**
  * **`std::vector` / `std::deque` / `std::list`** → **O(N)** sequential iteration.
  * **`std::map` / `std::set` / `std::multimap` / `std::multiset`** → **O(N)** in-order traversal.
  * **`std::unordered_map` / `std::unordered_set`** → **O(N)** unordered iteration.
* **Note:** Use **vector** for simple sequential iteration. Use **map** for ordered iteration.

**7. Sorting**

* **Purpose:** Arrange elements in ascending/descending order.
* **Best Containers:**
  * **`std::map` / `std::set`** → Always sorted by default (**O(log N)** insertion maintains order).
  * **`std::vector`** → **O(N log N)** with `std::sort()`.
  * **`std::deque`** → **O(N log N)** with `std::sort()`.
  * **`std::list`** → **O(N log N)** with `std::list::sort()`.
* **Note:** Use **map/set** for automatic sorting. Use **vector** + `std::sort()` for custom sorting.

***
