
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
#### pow `#include <cmath>`

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