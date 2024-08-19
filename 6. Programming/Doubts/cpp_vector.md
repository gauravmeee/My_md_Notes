
# Vector `# include <vector>`



#### Steps to Remove Duplicate Elements from a Vector

1. **Sort the Vector**: Use `std::sort` to arrange elements. Sorting is necessary because `std::unique` only removes consecutive duplicates.

2. **Remove Consecutive Duplicates**: Apply `std::unique` to rearrange elements so that all unique elements are at the beginning. It returns an iterator to the end of the unique range.

3. **Erase Trailing Duplicates**: Use `std::vector::erase` to remove elements after the end of the unique range returned by `std::unique`.
```cpp
vec = {1, 3, 2, 2, 4, 5, 3, 3, 5}
std::sort(vec.begin(), vec.end());  // Sorts the vector of vectors 
// {1, 2, 2, 3, 3, 3, 4, 5, 5};
 
auto last = std::unique(vec.begin(), vec.end()); // Removes consecutive duplicate vectors and return iterator just after the unique range
// vec = {1, 2, 3, 4, 5, 3, 3, 4, 5} 
//       ^------------^  unique range

vec.erase(last, vec.end()); // Erases the trailing duplicates 
// vec = {1, 2, 3, 4, 5}
```
*Note:*  `auto last` last will be of datatype `std::vector<int>::iterator`

---
#### set insert vs vector insert

```cpp
// std::set::insert
set.insert(element); // Adds element, maintains order, no duplicates

// std::vector::insert
vector.insert(position, element); // Inserts element at specific position
```

```cpp
//Default Initialization
vector<int> v; // Empty vector.
    
// Initialized Vector
vector<int> v(5);  // Vector of size 5, all elements are initialized to (for int, float, double).
vector<int> v(5, 100);    // Vector of size 5, all elements are initialized to
```

---
### push_back() vs insert()

- **`vec.push_back(value)`**:
    - Adds `value` to the end of the vector.
    - Amortized `O(1)` time complexity.

- **`vec.insert(position, value)`**:
    
    - Inserts `value` before the specified `position`.
    - Linear `O(n)` time complexity, where `n` is the number of elements moved.
<hr>

##### Find Maximum from Vector:\
`int maxx = *max_element(vec.begin(), vec.end());`
**Sort the vector of pair, based on second values of Pairs**

```cpp
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });
```

<hr>

#### 2-D Vector 

2D vector Declaration
```cpp
// delcaration + assignment
vector<vector<int>> vec = {{3, 2, 5}, {1, 9, 7}, {4, 2, 8}};

// declaration with size
vector<vector<int>> vec(rows, vector<int>(cols, 0));
```

**2D vector sorting**
```cpp
// Lexicographical Row Sorting
std::sort(vec.begin(), vec.end());
// Result: {{1, 9, 7}, {3, 2, 5}, {4, 2, 8}}


// Sorting by a Specific Column (e.g., first column):
std::sort(vec.begin(), vec.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0];
});
// Result: {{1, 9, 7}, {3, 2, 5}, {4, 2, 8}}
// Replace `a[0]` with another index for different column sorting.
```

---
#### initialize a `std::vector` in C++ with values ranging from 1 to \( n \),

**The `std::iota` function is specifically designed to fill a range with sequentially increasing values.**
```cpp
#include <numeric>  // Required for std::iota

std::vector<int> vec(n);
std::iota(vec.begin(), vec.end(), 1);  // Fills vec with values 1 to n
```
In most cases, the **`std::iota` method** is the most concise and efficient for initializing a vector from 1 to \( n \).

---
**In build Swap Func**
```cpp
#include <algorithm>
    std::swap(vec[1], vec[3]);
```
---

### Vector Functions

Here’s a summary of common `std::vector` functions and methods in C++:

### Basic Operations

- **`push_back(const T& value)`**:
  - Adds an element to the end of the vector.
  - Example: `vec.push_back(10);`

- **`pop_back()`**:
  - Removes the last element from the vector.
  - Example: `vec.pop_back();`

- **`insert(iterator pos, const T& value)`**:
  - Inserts an element before the position specified by `pos`.
  - Example: `vec.insert(vec.begin() + 1, 5);`

- **`erase(iterator pos)`**:
  - Removes the element at the specified position.
  - Example: `vec.erase(vec.begin() + 1);`

- **`clear()`**:
  - Removes all elements from the vector.
  - Example: `vec.clear();`

### Accessing Elements

- **`operator[](size_t index)`**:
  - Accesses the element at the specified index. Does not perform bounds checking.
  - Example: `int value = vec[2];`

- **`at(size_t index)`**:
  - Accesses the element at the specified index with bounds checking.
  - Example: `int value = vec.at(2);`

- **`front()`**:
  - Returns a reference to the first element in the vector.
  - Example: `int first = vec.front();`

- **`back()`**:
  - Returns a reference to the last element in the vector.
  - Example: `int last = vec.back();`

- **`data()`**:
  - Returns a pointer to the underlying array serving as the vector’s storage.
  - Example: `int* ptr = vec.data();`

### Iterators

- **`begin()`**:
  - Returns an iterator to the first element of the vector.
  - Example: `auto it = vec.begin();`

- **`end()`**:
  - Returns an iterator to the position just after the last element of the vector.
  - Example: `auto it = vec.end();`

- **`rbegin()`**:
  - Returns a reverse iterator to the last element of the vector.
  - Example: `auto it = vec.rbegin();`

- **`rend()`**:
  - Returns a reverse iterator to the position just before the first element of the vector.
  - Example: `auto it = vec.rend();`

### Capacity

- **`size()`**:
  - Returns the number of elements in the vector.
  - Example: `size_t s = vec.size();`

- **`empty()`**:
  - Checks if the vector is empty.
  - Example: `bool isEmpty = vec.empty();`

- **`reserve(size_t n)`**:
  - Requests that the vector capacity be at least enough to contain `n` elements.
  - Example: `vec.reserve(100);`

- **`capacity()`**:
  - Returns the number of elements that the vector can hold without reallocating.
  - Example: `size_t cap = vec.capacity();`

- **`shrink_to_fit()`**:
  - Requests the container to reduce its capacity to fit its size.
  - Example: `vec.shrink_to_fit();`

### Others

- **`assign(size_t count, const T& value)`**:
  - Assigns new values to the vector, replacing its current contents.
  - Example: `vec.assign(5, 10);` // 5 elements of value 10

- **`emplace_back(Args&&... args)`**:
  - Constructs an element in place at the end of the vector.
  - Example: `vec.emplace_back(10);`

- **`swap(vector& other)`**:
  - Swaps the contents of the vector with another vector.
  - Example: `vec.swap(otherVec);`
