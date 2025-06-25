
---

```cpp
set<int> mySet; // -> {} Empty set
set<int> mySet(n); // -> {1, 2, 3, ...., n-1} set with n unique no.
// same is for unordered_set
```


---

Convert Set to Vector
```cpp
// Create a set of integers 
std::set<int> s = {1, 2, 3, 4, 5}; 
// Convert set to vector 
std::vector<int> v(s.begin(), s.end());
```

``` cpp
s[0] // Direct Acess by index is not possible❌

// use iterator
  for (auto it = s.begin(); it != s.end(); ++it) { ✅
      std::cout << *it << " ";
  }
```
---
### Overview of `std::set`
- **Definition:** `std::set` is an associative container in the C++ Standard Template Library (STL) that stores unique elements following a specific order.
- **Header:** To use `std::set`, include the header `<set>`.

### Key Properties
- **Uniqueness:** No two elements in a set are equal.
- **Order:** Elements in a set are stored in a sorted order based on their values. The default sorting is ascending, but it can be customized using a comparator.
- **Underlying Data Structure:** `std::set` is usually implemented as a **balanced binary** search tree, typically a Red-Black Tree.

### Basic Operations
- **Insertion:** 
  ```cpp
  std::set<int> s;
  s.insert(5);
  s.insert(2);
  s.insert(8);
  ```
  - Insertion is O(log n) as the set maintains order after each insertion.
  - Duplicates are not allowed; if an element is already present, insertion has no effect.

- **Accessing Elements:**
  - Direct access by index is not possible. You must use iterators.
  ```cpp
  for (auto it = s.begin(); it != s.end(); ++it) {
      std::cout << *it << " ";
  }
  ```
  
- **Finding Elements:**
  - Use `find()` to check for the existence of an element.
  ```cpp
  auto it = s.find(5);  // Returns an iterator to the element if found, or s.end() if not found.
  ```
  - Use `count()` to check if an element is present (returns 0 or 1).
  ```cpp
  if (s.count(5)) {
      std::cout << "5 is present in the set.\n";
  }
  ```

- **Deletion:**
  ```cpp
  s.erase(5);  // Removes the element with value 5 if it exists.
  ```

### Common Functions
- **`begin()` / `end()`:** Returns an iterator to the beginning/end of the set.
- **`size()`:** Returns the number of elements in the set.
- **`empty()`:** Checks if the set is empty.
- **`clear()`:** Removes all elements from the set.
- **`lower_bound() / upper_bound()`:** Provides iterators to the first element that is not less than / greater than a given value.

### Example Code
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s;

    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1);  // Duplicate, will not be inserted.
    
    std::cout << "Set elements: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    if (s.find(3) != s.end()) {
        std::cout << "3 is in the set." << std::endl;
    }

    s.erase(3);
    
    std::cout << "Set after erasing 3: ";
    for (int x : s) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Advantages
- **Efficient Operations:** Most operations like insertion, deletion, and lookup are O(log n).
- **Automatic Sorting:** Elements are automatically sorted, making it useful when you need a collection that stays in order.

### Disadvantages
- **No Direct Access:** No random access to elements by index, unlike vectors or arrays.
- **Higher Overhead:** Set uses more memory compared to other containers like `vector` or `list` due to the underlying tree structure.

### When to Use `std::set`
- When you need to maintain a collection of unique elements.
- When you need to keep elements in sorted order.
- When efficient insertion, deletion, and lookup operations are required.