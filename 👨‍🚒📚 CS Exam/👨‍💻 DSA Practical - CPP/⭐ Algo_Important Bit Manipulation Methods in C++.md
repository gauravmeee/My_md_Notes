# ⭐ Algo\_Important Bit Manipulation Methods in C++

#### Bitwise Operators

| Operator    | Symbol | Use                                 |
| ----------- | ------ | ----------------------------------- |
| AND         | `&`    | Sets bit to 1 if both bits are 1    |
| OR          | \|     | Sets bit to 1 if at least one is 1  |
| XOR         | `^`    | Sets bit to 1 if bits are different |
| NOT         | `~`    | Inverts all bits                    |
| Left Shift  | `<<`   | Shifts bits left (×2 per shift)     |
| Right Shift | `>>`   | Shifts bits right (÷2 per shift)    |

***

#### Left Shift (`<<`) & Right Shift (`>>`)

**Left Shift (`<<`) Operator:**

**Action**: Shifts all bits of the number to the left by `k` positions.\
**How It Works**:

* All bits of the number are shifted left by `k` positions.
* **Zeroes** are inserted into the vacant positions on the right.
* Effectively, this operation multiplies the number by `2^k`.

**Example**: For the number `a = 5` (binary: `101`) and `a << 1`:

* Initial: `101` (binary representation of 5).
* Shift left by 1 position: `101` → `1010` (add `0` on the right)
* `1010` ( binary representation of 10)
* The result is `10` (in decimal), which is `5 × 2^1`.

**Right Shift (`>>`) Operator:**

**Action**: Shifts all bits of the number to the right by `k` positions. **How It Works**:

* All bits of the number are shifted right by `k` positions.
* The leftmost bits are filled with:
  * `0`s for **unsigned integers**.
  * The **sign bit** (the leftmost bit) for **signed integers** in **arithmetic right shift** (preserving the sign of negative numbers).
* Effectively, this operation divides the number by `2^k`.

**Example**: For the number `a = 10` (binary: `1010`) and `a >> 1`:

* Initial: `1010` (binary representation of 10).
* Shift right by 1 position: `1010` → `0101` (remove the rightmost `0`)
* `0101` (binary representation of 5).
* The result is `5` (in decimal), which is `10 ÷ 2^1`.

***

#### Properties of Bitwise Operations

**XOR Properties**

* `a ^ 0 = a` → (Identity) , _Use:_ Resetting or maintaining value
* `a ^ a = 0` → (Self-inverse), _Use:_ Cancel out same elements (e.g., find unique element in array) ⭐
* `a ^ b = b ^ a` → (Commutative)
* `(a ^ b) ^ c = a ^ (b ^ c)` → (Associative), _Use:_ Swapping without temp:

```cpp
a = a ^ b;
b = a ^ b; // now b = a
a = a ^ b; // now a = b
```

**AND Properties**

* `a & 0 = 0`
* `a & 1 = LSB of a`
* `a & a = a`
* `a & ~a = 0`, _Use:_ Bit masking (clearing bits)

**OR Properties**

* `a | 0 = a`
* `a | 1 = sets bit to 1`
* `a | a = a`
* `a | ~a = all bits set (−1)`, _Use:_ Bit setting

**NOT Properties**

* `~a = -(a + 1)` (in 2’s complement), _Use:_ Bit flip, negation

```cpp
~5 → -6
```

**Left Shift (`<<`)**

* `a << k` = a × 2^k, _Use:_ Fast multiplication by power of 2

```cpp
5 << 1 = 10
```

**Right Shift (`>>`)**

* `a >> k` = a / 2^k, _Use:_ Fast division by power of 2

```cpp
10 >> 1 = 5
```

***

#### Important Bit Manipulation methods

**Set/Clear/Toggle a Bit ⭐**

* **Set k-th bit**: Sets the k-th bit to 1.

```cpp
n | (1 << k)`
```

* **Clear k-th bit**: Clears the k-th bit (sets it to 0).

```cpp
n & ~(1 << k)
```

* **Check k-th bit**: Checks if the k-th bit is set (1) or not (0).

```cpp
n & (1 << k)
```

* **Toggle k-th bit**: Flips the k-th bit (if it's 0, it becomes 1; if it's 1, it becomes 0).

```cpp
n ^ (1 << k)
```

**Check Power of 2**

* A number that is a power of 2 will have only one bit set to 1.
* The bitwise operation `(n & (n - 1))` clears the least significant 1 bit in `n`, and if the result is 0, it means the number was a power of 2.

```cpp
bool isPowerOf2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

**Count Set Bits (Brian Kernighan’s Algorithm)**

* This algorithm efficiently counts the number of set bits (1s) in a number
* In each iteration, the least significant set bit is removed, and the counter is incremented.

```cpp
int countSetBits(int n){
    int count = 0;
    while(n){
        n &= (n - 1); // removes last set bit
        count++;
    }
    return count;
}
```

**Check if a Number is Even or Odd**

* **To check if a number is even :** just check if the least significant bit is 0:

```cpp
bool isEven(int n) {
    return (n & 1) == 0; // Returns true if even
}
```

* **To check if a number is Odd :** , just check if the least significant bit is not 0:

```cpp
bool isOdd(int n) {
    return (n & 1) != 0; // Returns true if odd
}
```

***

#### Advance Bit Manipulation methods

**Left Circular Shift (Rotate Left)**

* A left circular shift moves the leftmost bit to the rightmost position and shifts all other bits to the left.

```cpp
int leftRotate(int n, int d) {
    int numBits = sizeof(n) * 8;
    d = d % numBits; // Ensure d is within bounds
    return (n << d) | (n >> (numBits - d)); // Left rotate
}
```

**Right Circular Shift (Rotate Right)**

* A right circular shift moves the rightmost bit to the leftmost position and shifts all other bits to the right.

```cpp
int rightRotate(int n, int d) {
    int numBits = sizeof(n) * 8;
    d = d % numBits; // Ensure d is within bounds
    return (n >> d) | (n << (numBits - d)); // Right rotate
}
```

**Set/Clear All Bits**

* **Clear All Bits After k-th Bit (Set k-th Bit to 0) :** To clear all bits after the k-th bit (inclusive of the k-th bit):

```cpp
n & ((1 << k) - 1)
```

* **Set All Bits After k-th Bit (Set k-th Bit to 1):** To set all bits after the k-th bit to 1:

```cpp
n | ((1 << (numBits - k)) - 1)
```

**Get/Find Set Bits**

* **Get the Rightmost Set Bit** :This operation helps you to isolate the rightmost set bit in a number. The rightmost set bit is the bit that is farthest to the right in the binary representation of the number.

```cpp
int rightmostSetBit(int n) {
    return n & (-n); // returns the rightmost set bit
}
```

* **Find the Position of the Rightmost Set Bit :** To find the position of the rightmost set bit in a number (index starting from 1):

```cpp
int rightmostSetBitPos(int n) {
    return log2(n & (-n)) + 1;
}
```

* **Find the Highest Set Bit:** To find the highest set bit (most significant bit):

```cpp
int highestSetBit(int n) {
    return 31 - __builtin_clz(n); // Using GCC built-in function
}
// The function `__builtin_clz` returns the number of leading zeroes in `n`.
```

* **Find the Least Significant Set Bit :** This operation finds the least significant bit (rightmost set bit) of a number:

```cpp
int leastSignificantSetBit(int n) {
    return n & (-n); // Isolates the least significant set bit
}
```

**Toggle All Bits of a Number**

* To toggle all bits of a number (invert all bits):

```cpp
n = ~n; // Bitwise NOT
```

**Clear the Rightmost Set Bit**

* This operation clears (sets to 0) the rightmost set bit of a number.

```cpp
n = n & (n - 1); // Clears the rightmost set bit
```
