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

# STL Functions in C++

#### Standard Library Items ⭐

In C++, `std::` is used before standard library items like data types (`std::string`, `std::vector`, `std::map`, `std::set`, `std::pair`, `std::array`), input/output (`std::cin`, `std::cout`, `std::cerr`, `std::endl`), algorithms (`std::sort`, `std::find`, `std::reverse`, `std::min`, `std::max`), utility functions (`std::move`, `std::swap`, `std::make_pair`, `std::make_tuple`, `std::to_string`), smart pointers (`std::unique_ptr`, `std::shared_ptr`), and exception handling (`std::exception`, `std::runtime_error`, `std::logic_error`, `std::invalid_argument`). This usage avoids naming conflicts and clarifies that these are standard library elements.

***

**String Input from user**

**std: :library**

* Input a string `cin>>` can take String as input directly from terminal . (stops reading at whitespace).

```cpp
string s;
cin>>s;
```

* input a line `getline(cin, a)` of strings

```cpp
string a, b;
getline(cin, a);
```

***

***

Content:

1. Algorithm
2. Utility
3. Functional
4. Math

***

***

## A. `<algorithm>`

#### 1. `Sort()`

> `<algorithm>`

**1. Using `vec.begin()` & `vec.end()`**

```cpp
std::sort(vec.begin(), vec.end());
```

**2. Using`begin(vec)` & `end(vec)`**

```cpp
std::sort(std::begin(vec),std::end(vec));
```

#### 2. `max_element()`

> `<algorithm>`

**1. Storing Pointer, then Assigning Point value**

```cpp
Auto max_itr = max_element(arr.begin(), arr.end())
int maxx = *max_itr`✅
```

**2. Assigning Pointer value directly**

```cpp
int maxx = *max_element(arr.begin(), arr.end())`✅
```

**Incorrect: Storing Iterator in an `int`** ❌

```cpp
int maxx = max_element(arr.begin(), arr.end())  // Error
```

note: `std::max_element()` returns an iterator, not an integer.

#### 3. `max()` & `min()`

> `<algorithm>`

```cpp
#include <algorithm>  // For std::max and std::min

// Maximum of two
int maximum = std::max(a, b);

// Minimum of two
int minimum = std::min(a, b);

```

#### 4. `binary_search()` (for Sorted Containers)

> `<Algorithm>`

```cpp
bool found = std::binary_search(v.begin(), v.end(), 3);
```

* **Complexity:** **O(log N)**.
* **Works with:** `std::vector`, `std::deque`, `std::array` (sorted).

***

## B. `<utility>`

#### 1. `swap()`

> `<utility>`

The in-built `std::swap` function in C++ exchanges the values of two variables. It is defined in the `<utility>` header and works with any data type. Example:

```cpp
#include <utility> 
std::swap(a, b);
```

This function is efficient and widely used in algorithms like sorting.

#### 2. `make_pair()`

> `<utility>`

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

***

## C. `<functional>`

#### 1. `greater<int>`

> `<functional>`

**Purpose**

* Used to create a min-heap in C++'s `priority_queue` by defining a comparison that returns `true` if the first element is greater than the second.

**Usage**:

```cpp
#include <queue>
#include <functional>

int main() {
    // Min-heap declaration
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

```

**Effect**:

* `std::greater<int>` causes the `priority_queue` to behave as a min-heap, where the smallest element is at the top.

**Summary**

* **`greater<int>`**: Defines ascending order for a priority queue.
* **Min-Heap**: Smallest element on top.

***

## D. `<cmath>`

#### 2. `ceil()`

> `<cmath>`

**Summary of Using `double ceil` vs. `int ceil` with `10/3`**

* **`int ceil(10/3)`**:
  * **Integer Division**: `10 / 3` evaluates to `3` (truncated).
  * **Result**: `ceil(3)` returns `3`, not the correct ceiling of the division.
* **`double ceil(10/3)`**:
  * **Floating-Point Division**: Use `10.0 / 3` or `static_cast<double>(10) / 3` to get `3.333...`.
  * **Result**: `ceil(3.333...)` correctly returns `4`.

**Conclusion**

* Using `double` with `ceil` is essential for accurate ceiling calculations, as it ensures floating-point division, yielding the correct result.

#### 3. `pow()`

> `<cmath>`

To calculate ( x ) raised to the power ( y ) (i.e., ( x^y )).

```cpp
#include <cmath>
    double x = 2.0;  // Base
    double y = 3.0;  // Exponent
    double result = pow(x, y); // x^y
```

_Note:_ **Result Type**: The `pow` function returns a `double` type, which allows for floating-point calculations.

Note:-

* **Negative Exponents**: The `pow` function can handle negative exponents. For example, `pow(2, -3)` returns `0.125` (since ( 2^{-3} = \frac{1}{8} )).
* **Integer and Floating-Point Base/Exponent**: Both `x` and `y` can be integers or floating-point numbers.
* If both `x` and `y` are integers, you can still use `pow`, but the result will be cast to a `double`. If you need an integer result and both `x` and `y` are integers, you can cast the result back to an integer:

Result Integer

```cpp
#include <cmath>
    int x = 2;
    int y = 3;
    int result = static_cast<int>(pow(x, y));
}
```

***

## E. `<numeric>`

#### 1. `accumulate()`

> `<numeric`

**accumulate()** returns the **sum** of elements in a range.

```cpp
vector<int> A = {2, 1, 5, 1, 2, 2, 2};
int total = accumulate(A.begin(), A.end(), 0);  // total = 15
//  accumulate(start_iterator, end_iterator, initial_value)
```
