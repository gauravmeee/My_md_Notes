# 🤖 Doubts+GPT\_CPP Binary & Bit Manipulation

## Binary & Bits

**Integer to Binary Conversion**

* **Method 1:** Using `bitset` (fixed length only)

```cpp
# include <bitset>
cout << bitset<8>(18); // Output: 00010010 (8-bit)
```

* **Method 2:** Custom Function (Dynamic length):

```cpp
// Convert to Binary
string toBinary(int n) {
    if (n == 0) {
        return ""
    }
    string bin = "";
    while (n > 0) {
        bin = char(n % 2 + '0') + bin;
        n /= 2;
    }
    return bin
}

// Calling Function
toBinary(num); // output 1010
```

**Find the number of bits required to Represent a decimal number**

```cpp
int countBits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        // n = n>>1
        n >>= 1; // right shift by n by 1 bit, and Assign the shifted value back to `n`
    }
    return count;
}
```

***

## Bit Manipulation

#### **Bit Manipulation Property: XOR from `0` to `x`**

* When you compute the XOR of all numbers from `0` to `x`: `0⊕1⊕2⊕...⊕x0`
* It follows a **repeating pattern** based on the value of `x % 4`.

**Key Property**

* The result of XOR from `0` to `x` depends on `x % 4`:

```cpp
int xorFrom0ToX(int x) {
    if (x % 4 == 0) return x;         // x if x % 4 == 0
    if (x % 4 == 1) return 1;         // 1 if x % 4 == 1
    if (x % 4 == 2) return x + 1;     // x + 1 if x % 4 == 2
    return 0;                          // 0 if x % 4 == 3
}
```

**Explanation of the Pattern**: The XOR result forms a **cyclic pattern** with a period of `4`:

* For `x % 4 == 0`: XOR(0,1,2,...,x) = x
* For `x % 4 == 1`: XOR(0,1,2,...,x) = 1
* For `x % 4 == 2`: XOR(0,1,2,...,x) = x + 1
* For `x % 4 == 3`: XOR(0,1,2,...,x) = 0

\*\*Visual Pattern: \*\* For values from `0` to `7`

```
x = 0 → 0       → 0 % 4 == 0 → 0  
x = 1 → 0^1     → 1 % 4 == 1 → 1  
x = 2 → 0^1^2   → 2 % 4 == 2 → 3  
x = 3 → 0^1^2^3 → 3 % 4 == 3 → 0  

x = 4 → 0^1^2^3^4       → 4 % 4 == 0 → 4  
x = 5 → 0^1^2^3^4^5     → 5 % 4 == 1 → 1  
x = 6 → 0^1^2^3^4^5^6   → 6 % 4 == 2 → 7  
x = 7 → 0^1^2^3^4^5^6^7 → 7 % 4 == 3 → 0  
```

**Mathematical Reason**: The XOR from `0` to `x` behaves cyclically because:

* **XOR properties:**
  * `a⊕a = 0`
  * `a⊕0 = a`
* The pairs cancel out periodically every `4` numbers, creating a cycle.

**Use Cases**

1. **Finding if XOR from `0` to `x` equals `x`:**

```cpp
if (xorFrom0ToX(x) == x) {
    cout << x << " is beautiful" << endl;
}
```

2. **Efficient XOR range calculation:**

* Instead of iterating from `0` to `x` (O(N) time complexity), this formula allows you to compute it in **O(1)** time.

**Time Complexity Analysis**

* **Naive Method:** O(N) for iterating through `0` to `x`
* **Optimized Method:** O(1) using `x % 4` pattern

***

## **Bit Manipulation – Complete Guide with All Important Properties and Tricks**

#### **Basic Bitwise Operators**

Bitwise operations manipulate individual bits of integers.

| **Operator** | **Symbol** | **Operation**                  | **Example (x = 5, y = 3)**        |
| ------------ | ---------- | ------------------------------ | --------------------------------- |
| AND          | `&`        | Bitwise AND                    | `5 & 3 = 1` (`101 & 011 = 001`)   |
| OR           | `\|`       | Bitwise OR                     | `5 \| 3 = 7` (`101 \| 011 = 111`) |
| XOR          | `^`        | Bitwise XOR                    | `5 ^ 3 = 6` (`101 ^ 011 = 110`)   |
| NOT          | `~`        | Bitwise Complement (Flip bits) | `~5 = -6` (Inverts bits)          |
| Left Shift   | `<<`       | Shifts bits to the left        | `5 << 1 = 10` (`101 → 1010`)      |
| Right Shift  | `>>`       | Shifts bits to the right       | `5 >> 1 = 2` (`101 → 10`)         |
|              |            |                                |                                   |

**Bitwise AND `&`**

* **AND** sets bits to `1` only if both bits are `1`.
* **Properties**:
  * `a & 0 = 0`
  * `a & 1 = a` (bit remains the same)
  * `a & a = a`
  * `a & ~a = 0`
* ✅ **Use cases**:
  *   **Checking if a number is even/odd**:

      ```cpp
      if (x & 1) cout << "Odd";  // LSB = 1 → odd  
      else cout << "Even";       // LSB = 0 → even  
      ```

**Bitwise OR `|`**

* **OR** sets bits to `1` if either of the bits is `1`.
* **Properties**:
  * `a | 0 = a`
  * `a | 1 = 1`
  * `a | a = a`
  * `a | ~a = ~0` (all bits set to 1)
*   **Use cases**: **Setting specific bits**

    ```cpp
    x = 5;    // `101`
    x = x | (1 << 1);  // Sets the 2nd bit → `111` (7)
    ```

**Bitwise XOR `^`**

* **XOR** sets bits to `1` if the bits are different.
* **Properties**:
  * `a ^ 0 = a`
  * `a ^ 1 = ~a`
  * `a ^ a = 0`
  * `a ^ ~a = ~0`
*   **Use cases**: **Swapping two numbers without a temp variable**

    ```cpp
    int a = 5, b = 7;
    a = a ^ b;
    b = a ^ b;  // Now b = 5
    a = a ^ b;  // Now a = 7
    ```

**Bitwise NOT `~`**

* **NOT** flips all bits of a number.
* **Properties**:
  * `~0 = -1`
  * `~a = -a - 1` (two's complement)
*   **Use cases**: **Finding negative of a number**

    ```cpp
    int x = 5;
    cout << ~x;  // Output: -6
    ```

***

**Left Shift `<<`**

* Shifts bits to the left, filling with `0` on the right.
* **Properties**:
  * `a << n` **returns the left-shifted value** of `a` by `n` positions but **does not change** the value of `a`.
  * `a << n` same `a * (2^n)`
*   **Use cases**: **Multiplying by powers of 2**

    ```cpp
    int x = 5;  // `101`
    cout << (x << 1);  // `1010` → 10
    ```

**Right Shift `>>`**

* Shifts bits to the right.
* **Properties**:
  * `a << n` **returns the right-shifted value** of `a` by `n` positions but **does not change** the value of `a`.
  * `a >> n` same as `a / (2^n)`
*   **Use cases**: **Dividing by powers of 2**

    ```cpp
    int x = 10;  // `1010`
    cout << (x >> 1);  // `101` → 5
    ```

**Masking and Clearing Bits**

* **Masking** → Set or check specific bits using AND.
* **Clearing** → Clear specific bits using AND with NOT.

```cpp
// Masking (checking if the 2nd bit is set)
int x = 5;  // `101`
if (x & (1 << 1)) cout << "2nd bit is set";

// Clearing (resetting the 2nd bit)
x = x & ~(1 << 1);  // `101` → `001` (1)
```

**Toggle Bits**

* Toggle a bit using XOR with `1`:

```cpp
int x = 5;  // `101`
x = x ^ (1 << 1);  // Toggle the 2nd bit → `111` (7)
```

**10. Checking Powers of 2**

* A power of `2` has only **1 bit set**.

```cpp
bool isPowerOfTwo(int x) {
    return (x && !(x & (x - 1)));
}
```

**Counting Set Bits (`__builtin_popcount`)**

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 7;  // `111`
    cout << __builtin_popcount(x);  // Output: 3
    return 0;
}
```

**Checking the Parity (Even/Odd Set Bits)**

* Use XOR:

```cpp
bool isOddParity(int x) {
    return (__builtin_popcount(x) & 1);
}
```

**Reverse Bits**

```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}
```

**Isolating the Rightmost `1`**

```cpp
int isolateRightmostOne(int x) {
    return x & (-x);
}
```

**Clearing the Rightmost `1`**

```cpp
int clearRightmostOne(int x) {
    return x & (x - 1);
}
```

**Setting the Rightmost `0`**

```cpp
int setRightmostZero(int x) {
    return x | (x + 1);
}
```

**Rounding Up to the Next Power of 2**

```cpp
int nextPowerOfTwo(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}
```

**Bit Manipulation in STL**

* `__builtin_clz(x)` → Count leading zeros
* `__builtin_ctz(x)` → Count trailing zeros
* `__builtin_popcount(x)` → Count set bits
* `__builtin_parity(x)` → Parity of set bits

***

***
