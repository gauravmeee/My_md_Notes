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

# Vectors in C++

## Vector `# include <vector>`

#### Vector Declaration

**1D Vector Declarations**

```cpp
// 1. Initialize with values
vector<int> v{1, 2, 3};     // (Brace-init)        Size = 3, values = 1, 2, 3
std::vector<int> v = {1, 2, 3}; // (Copy-list init)    Size = 3, values = 1, 2, 3

// 2. Initialize with constructor
vector<int> v;    // (Default constructor)      Empty vector
vector<int> v(0);   // 0 default-initialized ints → []
vector<int> v(5);   // 5 default-initialized ints → [0, 0, 0, 0, 0]
vector<int> v(5, 3);  // 5 ints, all set to 3  → [3, 3, 3, 3, 3]

vector<int> v(); ❌   // Function declaration (not a vector!)

```

**2D Vector Declarations**

```cpp
vector<vector<int>> v;                              // Empty 2D vector
vector<vector<int>> v(5);                           // 5 empty rows (default constructed)
vector<vector<int>> v(5, vector<int>(3));           // 5 rows, each of size 3, default 0
vector<vector<int>> v(5, vector<int>(3, -1));       // 5x3 matrix with all values = -1
```

**Common Mistakes**

```cpp
// 1. Initialization with values
vector<vector<int>> vec{{3, 2, 5}, {1, 9, 7}, {4, 2, 8}};  // Brace-init
vector<vector<int>> vec = {{3, 2, 5}, {1, 9, 7}, {4, 2, 8}}; // Copy-list init

// 2. Initialization with constructor
vector<vector<int>> vec(2, vector<int>(3)); // 2 rows × 3 columns, all 0 → {{0,0,0}, {0,0,0}}
vector<vector<int>> vec(2, vector<int>(3, 4)); // 2 rows × 3 columns, all 4 → {{4,4,4}, {4,4,4}}


vector<int> v();   // ❌ Function declaration, not a vector
```

***

#### Sorting of Vectors

**1D Vector Sorting**

```
std::vector<int> v = {4, 2, 1, 5, 3};
```

1. Sorting in Ascending Order

```cpp
std::sort(v.begin(), v.end());  
// Result: {1, 2, 3, 4, 5}

sort(v.begin(), v.end(),[](const int &a, const int &b) {
    return a < b;  // ascending order
}); 
```

2. Sorting in Descending Order

```cpp
sort(v.begin(), v.end(), greater<int>());  // inbuilt comparator
// or 
sort(v.begin(), v.end(),[](const int &a, const int &b) {
    return a > b;  // descending order
}); 

// Result: {5, 4, 3, 2, 1}
```

| Usage                            | Works | Preferred for ints | Preferred for big types (like `vector<int>`) |
| -------------------------------- | ----- | ------------------ | -------------------------------------------- |
| `[](int a, int b)`               | ✅     | ✅                  | ❌ (copies large objects)                     |
| `[](const int &a, const int &b)` | ✅     | ✅ (best practice)  | ✅ (efficient)                                |

**2D Vector Sorting**

```
vector<std::vector<int>> vec = {{3, 2, 5}, {1, 9, 7}, {4, 2, 8}};
```

1. Lexicographical Row Sorting

```cpp
sort(vec.begin(), vec.end());
// or
sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
});

// Result: {{1, 9, 7}, {3, 2, 5}, {4, 2, 8}}
```

2. Sorting by a Specific Column (e.g., 2nd column):

```cpp
sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
});
// Result: {{3, 2, 5}, {4, 2, 8}, {1, 9, 7}}
```

3. Sorting in Descending Order (Lexicographically)

```cpp
sort(vec.begin(), vec.end(), greater<vector<int>>()); // inbuilt comparator
// or
sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] > b[0];
});

// Result: {{4, 2, 8}, {3, 2, 5}, {1, 9, 7}}
```

4. Sorting in Descending Order Based on Specific Column (e.g., 2nd column)

```cpp
sort(vec.begin(), vec.end(), [](const std::vector<int>& a, const vector<int>& b) {
    return a[1] > b[1];
});

// Result: {{4, 2, 8}, {3, 2, 5}, {1, 9, 7}}
```

**Note:**

* `greater<type>()` is an **inbuilt comparator** from the `<functional>` header.

***

#### Vector Functions

**Basic Operations:**

* **`push_back(const T& value)`**:
  * Adds an element to the end of the vector.
  * Example: `vec.push_back(10);`
* **`pop_back()`**:
  * Removes the last element from the vector.
  * Example: `vec.pop_back();`
* **`insert(iterator pos, const T& value)`**:
  * Inserts an element before the position specified by `pos`.
  * Example: `vec.insert(vec.begin() + 1, 5);`
* **`erase(iterator pos)`**:
  * Removes the element at the specified position.
  * Example: `vec.erase(vec.begin() + 1);`
* **`clear()`**:
  * Removes all elements from the vector.
  * Example: `vec.clear();`

**Accessing Elements:**

* **`operator[](size_t index)`**:
  * Accesses the element at the specified index. Does not perform bounds checking.
  * Example: `int value = vec[2];`
* **`at(size_t index)`**:
  * Accesses the element at the specified index with bounds checking.
  * Example: `int value = vec.at(2);`
* **`front()`**:
  * Returns a reference to the first element in the vector.
  * Example: `int first = vec.front();`
* **`back()`**:
  * Returns a reference to the last element in the vector.
  * Example: `int last = vec.back();`
* **`data()`**:
  * Returns a pointer to the underlying array serving as the vector’s storage.
  * Example: `int* ptr = vec.data();`

**Iterators:**

* **`begin()`**:
  * Returns an iterator to the first element of the vector.
  * Example: `auto it = vec.begin();`
* **`end()`**:
  * Returns an iterator to the position just after the last element of the vector.
  * Example: `auto it = vec.end();`
* **`rbegin()`**:
  * Returns a reverse iterator to the last element of the vector.
  * Example: `auto it = vec.rbegin();`
* **`rend()`**:
  * Returns a reverse iterator to the position just before the first element of the vector.
  * Example: `auto it = vec.rend();`

**Capacity:**

* **`size()`**:
  * Returns the number of elements in the vector.
  * Example: `size_t s = vec.size();`
* **`empty()`**:
  * Checks if the vector is empty.
  * Example: `bool isEmpty = vec.empty();`
* **`reserve(size_t n)`**:
  * Requests that the vector capacity be at least enough to contain `n` elements.
  * Example: `vec.reserve(100);`
* **`capacity()`**:
  * Returns the number of elements that the vector can hold without reallocating.
  * Example: `size_t cap = vec.capacity();`
* **`shrink_to_fit()`**:
  * Requests the container to reduce its capacity to fit its size.
  * Example: `vec.shrink_to_fit();`

**Others:**

* **`assign(size_t count, const T& value)`**:
  * Assigns new values to the vector, replacing its current contents.
  * Example: `vec.assign(5, 10);` // 5 elements of value 10
* **`emplace_back(Args&&... args)`**:
  * Constructs an element in place at the end of the vector.
  * Example: `vec.emplace_back(10);`
* **`swap(vector& other)`**:
  * Swaps the contents of the vector with another vector.
  * Example: `vec.swap(otherVec);`

***

#### Ways to Make a Vector from Existing Array/Vector

```cpp
vector<int> vec = {1, 2, 3};  // ✅ Valid vector initialization
int arr[] = vec;     // ❌ Invalid: Cannot directly assign a vector to an array

int arr[] = {1, 2, 3};    // ✅ Valid array initialization
vector<int> vec = arr;     // ❌ Invalid: Cannot directly assign an array to a vector

vector<int> vec = {1, 2, 3};   // ✅ Valid vector initialization
vector<int> tempVec1 = vec;    // ✅ Valid: Direct copy of a vector
vector<int> tempVec2(vec.begin(), vec.end()); // ✅ Valid: Copy elements from one vector using iterators
vector<int> trimmedVec(vec.begin() + i, vec.begin() + j); //// ✅ Valid: Copy elements from range (i to j )incluseive, from one vector using the range constructor.
```

```cpp
// vec.begin() -> iterator points to the first element, which is vec[0]
// vec.end() -> iterator points to one past the last element, which is vec[vec.size()]
```

***

#### Take care while using `push_back` in Vector of Vector

`push_back` on `ans[0]`, you need to ensure that `ans` has at least one inner vector.❌

```cpp
vector<vector<int>> ans(); // Initializes 2 D vector
ans[0].push_back(1); // Error : Directly accessing `ans[0]` will cause an error if `ans` is empty.
// The 2D vector `ans` is declared but not yet populated with any inner vectors.
```

1.  **Initialize with an inner vector**: ✅

    ```cpp
    vector<vector<int>> ans(1); // Initializes with one empty inner vector
    ans[0].push_back(1); // This will work now
    ```
2.  **Add an inner vector before accessing**: ✅

    ```cpp
    vector<vector<int>> ans;
    ans.push_back(vector<int>()); // Adds an empty vector
    ans[0].push_back(1); // Now you can use push_back
    ```

Either method ensures that you have a valid inner vector to work with.

***

#### Steps to Remove Duplicate Elements from a Vector

> `unique(vec.begin, vec.end())`

1. **Sort the Vector**: Use `std::sort` to arrange elements. Sorting is necessary because `std::unique` only removes consecutive duplicates.
2. **Remove Consecutive Duplicates**: Apply `std::unique` to rearrange elements so that all unique elements are at the beginning. It returns an iterator to the end of the unique range.
3. **Erase Trailing Duplicates**: Use `std::vector::erase` to remove elements after the end of the unique range returned by `std::unique`.

```cpp
vec = {1, 3, 2, 2, 4, 5, 3, 3, 5}

std::sort(vec.begin(), vec.end());  // Sorts the vector of vectors 
// {1, 2, 2, 3, 3, 3, 4, 5, 5};
 
auto last = std::unique(vec.begin(), vec.end()); 
// Moves unique values to the front and returns iterator past the last unique element
// 'last' points to one-past-the-last unique element
// vec = {1, 2, 3, 4, 5, ?, ?, ?, ?} 
//        -------------  ↑
//         unique range  last


vec.erase(last, vec.end()); 
// // Erases redundant elements beyond unique range
// vec = {1, 2, 3, 4, 5}
```

_Note:_ `auto last` last will be of datatype `std::vector<int>::iterator`

***

**initialize a `std::vector` in C++ with values ranging from 1 to ( n ),**

**The `std::iota` function is specifically designed to fill a range with sequentially increasing values.**

```cpp
#include <numeric>  // Required for std::iota

std::vector<int> vec(n);
std::iota(vec.begin(), vec.end(), 1);  // Fills vec with values 1 to n
```

In most cases, the **`std::iota` method** is the most concise and efficient for initializing a vector from 1 to ( n ).

***

**In build Swap Func**

```cpp
#include <algorithm>
    std::swap(vec[1], vec[3]);
```

***

***

## Doubt Comparisons

#### Array of Vector vs Vector of Vector ⭐

> `vector<int> adj[]` vs `vector<vector<int>> adj`

| **Feature**           | **Array of Vectors**                                                                          | **Vector of Vectors**                                                                     |   |
| --------------------- | --------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- | - |
| **Definition**        | C-style array of vectors                                                                      | Fully STL-based 2D vector                                                                 |   |
| **Syntax**            | `vector<int> adj[N];`                                                                         | `vector<vector<int>> adj(N);`                                                             |   |
| **Memory Allocation** | Fixed-size array of vectors                                                                   | Dynamically sized outer and inner vectors                                                 |   |
| **Size Flexibility**  | Fixed size of the outer array                                                                 | Dynamic resizing for both outer and inner vectors                                         |   |
| **Initialization**    | Predefined size (e.g., `vector<int> adj[10];`)                                                | Can initialize with size or dynamically add/remove (e.g., `vector<vector<int>> adj(10);`) |   |
| **Access Syntax**     | `adj[i][j]`                                                                                   | `adj[i][j]`                                                                               |   |
| **Resizing**          | Only individual vectors can be resized; outer array size is fixed                             | Both outer vector and inner vectors can be resized dynamically                            |   |
| **Use Case**          | Suitable for fixed-size data structures where the number of elements is known at compile time | Suitable for dynamic data structures where the size can change during runtime             |   |

* **Array of Vectors** is suited for fixed-size collections where the outer array size does not change.
* **Vector of Vectors** is more flexible and allows for dynamic resizing, which is useful when the size of the data structure can vary.

**Array of Vectors:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> adj[5]; // Array of 5 vectors

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);

    for (int i = 0; i < sizeof(adj) / sizeof(adj[0]); i++) {
        cout << "Node " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

// Use sizeof(adj) / sizeof(adj[0]) to get array size:
```

**Vector of Vectors:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> adj(5); // Vector of 5 vectors

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);

    for (int i = 0; i < adj.size(); i++) {
        cout << "Node " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

// Use adj.size() to get vector size
```

***

#### Set Insertion v/s Vector Insertion:

> `set.insert()` vs `vector.insert()`

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
vector<int> v(5, 100);    // Vector of size 5, all elements are initialized to 100
```

***

#### Push back vs Insertion

> `push_back()` vs `insert()`

* **`vec.push_back(value)`**:
  * Adds `value` to the end of the vector.
  * Amortized `O(1)` time complexity.
* **`vec.insert(position, value)`**:
  * Inserts `value` before the specified `position`.
  * Linear `O(n)` time complexity, where `n` is the number of elements moved.

***

#### Vectors Back vs Front

> **`.back()` vs `.front()`**

Vector

```cpp
vector<int> v = {1, 2, 3};
cout << v.front(); // 1
cout << v.back();  // 3
```

**These Data structure support Back and Front Access**

* **`queue`**
* **`deque`**
* **`list`**
* **`vector`**

**Note: Stack , Set and Unordered set Does not support Front and Back Access**

* **`stack`** → Only `.top()` is available.
* **`set` / `unordered_set`** → No `.back()` or `.front()` (since sets are not indexed).

***

#### Find Maximum from Vector:

```cpp
int maxx = *max_element(vec.begin(), vec.end());
```

**Sort the vector of pair, based on second values of Pairs**

#### Sort a Vector of Pair

```cpp
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });
```

***
