
#### String Input from user

**std: :library**    
- Input a string
`cin>>` can take String as input directly from terminal . (stops reading at whitespace).
```cpp
string s;
cin>>s;
```
- input a line `getline(cin, a)` of strings
```cpp
string a, b;
getline(cin, a);
```

---
#### Sort  `#include <algorithm>`
✅ vec.begin() & vec.end()\
`std::sort(vec.begin(), vec.end()); ` 

✅ begin(vec) & end(vec)\
`std::sort(std::begin(vec),std::end(vec));`

<hr> 

#### max_element() `#include <algorithm>`

note: `std::max_element()` returns an iterator, not an integer.

`int maxx = max_element(arr.begin(), arr.end())`❌

`Auto max_itr = max_element(arr.begin(), arr.end())`\
`int maxx = *max_itr`✅

`int maxx = *max_element(arr.begin(), arr.end())`✅

----
### pow() `#include <cmath>`

To calculate \( x \) raised to the power \( y \) (i.e., \( x^y \)).

```cpp
#include <cmath>
    double x = 2.0;  // Base
    double y = 3.0;  // Exponent
    double result = pow(x, y); // x^y
```
*Note:*  **Result Type**: The `pow` function returns a `double` type, which allows for floating-point calculations.


Note:- 
- **Negative Exponents**: The `pow` function can handle negative exponents. For example, `pow(2, -3)` returns `0.125` (since \( 2^{-3} = \frac{1}{8} \)).
- **Integer and Floating-Point Base/Exponent**: Both `x` and `y` can be integers or floating-point numbers.
-  If both `x` and `y` are integers, you can still use `pow`, but the result will be cast to a `double`. If you need an integer result and both `x` and `y` are integers, you can cast the result back to an integer: 

Result Integer
```cpp
#include <cmath>
    int x = 2;
    int y = 3;
    int result = static_cast<int>(pow(x, y));
}
```

---
#### swap() `#include <utility>`
The in-built `std::swap` function in C++ exchanges the values of two variables. It is defined in the `<utility>` header and works with any data type. Example:

```cpp
#include <utility> 
std::swap(a, b);
```

This function is efficient and widely used in algorithms like sorting.

---
### Max & Min `<Algorithm>`

```cpp
#include <algorithm>  // For std::max and std::min

// Maximum of two
int maximum = std::max(a, b);

// Minimum of two
int minimum = std::min(a, b);

```

---
Yes, that's correct! Your explanation is spot on.

Here's a revised version of your explanation with your code example:

---

### `make_pair()` - `#include <utility>`

The `make_pair` function is defined in the `<utility>` header. However, it is indirectly included when you include headers like `<map>`, `<set>`, `<unordered_map>`, `<unordered_set>`, `<algorithm>`, `<tuple>`, and `<queue>`. These headers often include `<utility>` internally because they use `std::pair` or other utility functions.

Here's an example of how to use `make_pair`:

```cpp
#include <utility>  // For std::make_pair

pair<int, int> p;
p = make_pair(a, b); 
```
or
```cpp

pair<int, int> p;
p = {a,b};
```

This code correctly creates a `std::pair` using the `make_pair` function, where `a` and `b` are the values you want to pair together.

---
### greater\<int> ` <functional>

- **Purpose**: Used to create a min-heap in C++'s `priority_queue` by defining a comparison that returns `true` if the first element is greater than the second.

- **Header**: `<functional>`

- **Usage**: 
  ```cpp
  #include <queue>
  #include <functional>

  int main() {
      // Min-heap declaration
      std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  ```

- **Effect**: 
  - `std::greater<int>` causes the `priority_queue` to behave as a min-heap, where the smallest element is at the top.

### Summary
- **`greater<int>`**: Defines ascending order for a priority queue.
- **Min-Heap**: Smallest element on top.