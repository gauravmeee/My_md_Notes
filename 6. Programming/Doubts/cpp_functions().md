
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