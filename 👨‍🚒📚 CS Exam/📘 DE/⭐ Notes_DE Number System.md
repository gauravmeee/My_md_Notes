# ⭐ Notes\_DE Number System

### Number System and Base Conversion

**1. From any base to Decimal (Base-10)**

* Multiply each digit by its base raised to the positional power.
* Add all results.
* **Example**: `(1011)₂` to `decimal`:

```
1×2³ + 0×2² + 1×2¹ + 1×2⁰  
= 8 + 0 + 2 + 1  
= 11₁₀
```

If the ==**binary number is a float**==, you convert **integer part** and **fractional part** separately: ⭐

**Steps:**

1. **Integer part** → Multiply each bit by `2^n` according to its position (same as normal).
2. **Fractional part** → Multiply each bit by `2^(-n)` according to its position after the point.

* **Example:** `(11001.101)₂` to `base-10`

```
Integer part (11001):

1×2⁴ + 1×2³ + 0×2² + 0×2¹ + 1×2⁰  
= 16 + 8 + 0 + 0 + 1  
= 25

Fractional part (.101):

1×2⁻¹ + 0×2⁻² + 1×2⁻³  
= 0.5 + 0 + 0.125  
= 0.625

Final:
(11001.101)₂ = (25.625)₁₀
```

**2. From Decimal to Any Base**

* Repeatedly divide the decimal number by the target base.
* Write remainders in reverse order.
* **Example:** `(25)₁₀` to `base-2`:

```
25 ÷ 2 = 12 remainder 1  
12 ÷ 2 = 6  remainder 0  
6 ÷ 2  = 3  remainder 0  
3 ÷ 2  = 1  remainder 1  
1 ÷ 2  = 0  remainder 1  
→ 11001₂
```

If the ==**decimal number is a float**==, you convert ==**integer part** and **fractional part** separately==: ⭐

**Steps:**

1. **Integer part** → Use repeated division by `base` (same as normal).
2. **Fractional part** → Multiply repeatedly by `base`, take the integer part each time as the next digit.

* **Example:** `(25.625)₁₀` to `base-2`

```
Integer part (25):

25 ÷ 2 = 12 remainder 1  
12 ÷ 2 = 6  remainder 0  
6 ÷ 2  = 3  remainder 0  
3 ÷ 2  = 1  remainder 1  
1 ÷ 2  = 0  remainder 1  
→ 11001

Fractional part (0.625):

0.625 × 2 = 1.25   → 1  
0.25  × 2 = 0.5    → 0  
0.5   × 2 = 1.0    → 1  
→ .101

Final:
(25.625)₁₀ = (11001.101)₂
```

**4. From One Non-Decimal Base to Another**

* Convert to decimal first, then to target base.
* **Example:** (27)₈ to base-2:

```
1. (27)₈ = 2×8¹ + 7×8⁰  
         = 16 + 7  
         = 23₁₀

2. 23₁₀ = 10111₂
```

***

### Base Conversion

**1. Binary to Decimal Conversion**

**Steps:**

1. **Write Down the Binary Number:**
   * Example: `1101`
2. **Identify the Positional Values:**
   * Each bit represents a power of 2, starting from (2^0) for the rightmost bit.
3. **Multiply Each Bit by Its Corresponding Power of 2:**
   * For `1101`:
     * `1 \times 2^3 = 8`
     * `1 \times 2^2 = 4`
     * `0 \times 2^1 = 0`
     * `1 \times 2^0 = 1`
4. **Sum the Results:**
   * `8 + 4 + 0 + 1 = 13`

**Result:**

* Binary `1101` is decimal `13`.

**2. Decimal to Binary Conversion**

**Steps:**

1. **Divide the Decimal Number by 2:**
   * Record the remainder.
2. **Divide the Quotient by 2:**
   * Continue dividing and recording remainders until the quotient is 0.
3. **Write Down the Remainders in Reverse Order:**
   * This gives the binary representation.

**Example: Convert `13` to Binary**

* `13 ÷ 2 = 6` with remainder `1`
* `6 ÷ 2 = 3` with remainder `0`
* `3 ÷ 2 = 1` with remainder `1`
* `1 ÷ 2 = 0` with remainder `1`

**Result:**

* Binary representation is `1101`.

**3. Hexadecimal to Decimal Conversion**

**Steps:**

1. **Write Down the Hexadecimal Number:**
   * Example: `0x2F3`
2. **Identify the Positional Values:**
   * Each digit represents a power of 16, starting from (16^0) for the rightmost digit.
3. **Convert Each Hexadecimal Digit to Decimal:**
   * `2`, `F (15)`, and `3`.
4. **Multiply Each Digit by Its Corresponding Power of 16:**
   * For `0x2F3`:
     * `3 \times 16^0 = 3`
     * `15 \times 16^1 = 240`
     * `2 \times 16^2 = 512`
5. **Sum the Results:**
   * `512 + 240 + 3 = 755`

**Result:**

* Hexadecimal `0x2F3` is decimal `755`.

**4. Decimal to Hexadecimal Conversion**

**Steps:**

1. **Divide the Decimal Number by 16:**
   * Record the remainder (convert to hexadecimal if needed).
2. **Divide the Quotient by 16:**
   * Continue dividing and recording remainders until the quotient is 0.
3. **Write Down the Remainders in Reverse Order:**
   * This gives the hexadecimal representation.

**Example: Convert `755` to Hexadecimal**

* `755 ÷ 16 = 47` with remainder `7`
* `47 ÷ 16 = 2` with remainder `15` (F in hexadecimal)
* `2 ÷ 16 = 0` with remainder `2`

**Result:**

* Hexadecimal representation is `0x2F7`.

**5. Binary to Hexadecimal Conversion**

**Steps:**

1. **Group the Binary Digits into Sets of Four (from right to left):**
   * Example: `10111011` becomes `1011 1011`.
2. **Convert Each Group to Hexadecimal:**
   * `1011` is `B`
   * `1011` is `B`

**Result:**

* Binary `10111011` is hexadecimal `0xBB`.

**6. Hexadecimal to Binary Conversion**

**Steps:**

1. **Convert Each Hexadecimal Digit to Its 4-Bit Binary Equivalent:**
   * Example: `0x2F3`:
     * `2` is `0010`
     * `F` is `1111`
     * `3` is `0011`
2. **Combine All Binary Groups:**

**Result:**

* Hexadecimal `0x2F3` is binary `0010 1111 0011`.

***

#### 2'S Complement, BCD Code, XS-3 Code, Gray Code

**n’s Complement**

* For a number system with base **n**, **n’s complement** of a number is obtained by\
  **subtracting the number from nᵏ**, where **k = number of digits**.
* **Formula**\
  n’s complement of X = nᵏ − X
* **Types**
  * Binary (n = 2) → **2’s complement**
  * Decimal (n = 10) → **10’s complement**
  * Octal (n = 8) → **8’s complement**
  * Hexadecimal (n = 16) → **16’s complement**
* **Relation with (n−1)’s complement** ⭐ ==n’s complement = (n−1)’s complement + 1==
* **Use**
  * Subtraction using addition
  * Representation of negative numbers
* **Example (Decimal)**\
  Number = 275\
  10’s complement = 1000 − 275 = 725
* **Example (Binary)**\
  Number = 1010\
  2’s complement = 0101 + 1 = 0110

**2’s Complement**

**Definition:** Binary number ==representation for signed integers== where negative numbers are obtained by taking the 1’s complement and adding 1.\
**Use:** ==Simplifies subtraction== in digital systems.\
**Steps (for negative numbers):**

1. Write the number in binary.
2. Take 1’s complement (invert bits).
3. Add 1 to the result.

Example (–5 in 8-bit):

```
+5   = 00000101  
1's  = 11111010  
+1   = 11111011  → –5
```

**1. Excess-3 Code**

**Definition:** A self-complementary decimal code obtained by adding 3 to each decimal digit and converting to 4-bit binary.\
**Use:** Error detection, decimal calculations.

Example table:

| Decimal | Binary | Excess-3  |
| ------- | ------ | --------- |
| 0       | 0000   | 0011 (3)  |
| 1       | 0001   | 0100 (4)  |
| 2       | 0010   | 0101 (5)  |
| 3       | 0011   | 0110 (6)  |
| 4       | 0100   | 0111 (7)  |
| 5       | 0101   | 1000 (8)  |
| 6       | 0110   | 1001 (9)  |
| 7       | 0111   | 1010 (10) |
| 8       | 1000   | 1011 (11) |
| 9       | 1001   | 1100 (12) |

**2. BCD (Binary Coded Decimal)**

**Definition:** Represents each decimal digit separately in binary (4 bits per digit).\
**Use:** Digital displays, calculators.

Example:

```
                5    9
Decimal 59 = (0101 1001) in BCD
```

**3. Gray Code**

**Definition:** A binary code where consecutive values differ by only 1 bit (minimizes errors in transitions).\
**Use:** Position encoders, error reduction.

Example (3-bit Gray code):

| Decimal | Binary | Gray |
| ------- | ------ | ---- |
| 0       | 000    | 000  |
| 1       | 001    | 001  |
| 2       | 010    | 011  |
| 3       | 011    | 010  |
| 4       | 100    | 110  |
| 5       | 101    | 111  |
| 6       | 110    | 101  |
| 7       | 111    | 100  |
