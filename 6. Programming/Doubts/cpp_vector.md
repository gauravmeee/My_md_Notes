
# Vector `# include <vector>`

```cpp
//Default Initialization
vector<int> v; // Empty vector.
    
// Initialized Vector
vector<int> v(5);  // Vector of size 5, all elements are initialized to (for int, float, double).
vector<int> v(5, 100);    // Vector of size 5, all elements are initialized to
```

<hr>

find maximum from Vector:\
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