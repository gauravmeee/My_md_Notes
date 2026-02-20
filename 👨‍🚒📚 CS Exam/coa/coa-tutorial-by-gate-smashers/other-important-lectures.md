---
description: From Gate Smasher's Tutorial ▶️
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

# L: Other Important Lectures

### [Lec-10: Floating Point Representation with examples | Number System (Gate Smashers)](https://youtu.be/4gNs7B4ZTjc)

* **Fixed representation** -> has fixed number of bits for integer part and for fractional part.
* ex: `10.` or `10.0`, `.15` or `0.15` decimal point is to the extreme left or right
* **Floating point** -> refers to the fact that a number's radix point (decimal point, or, more commonly in computers, binary point) can "float"; that is, it can be placed anywhere relative to the significant digits of the number.
* ex: `5.5` Fraction point is floating

Floating Point is use to make Value Better Representative

**Floating Point**

`101.1` Binary => `2^2 + 2^0 + 2^(-1)` => `5.5` Decimal

Move binary point by `n` bit right => Multiply by`2^(-n)` Move binary point by `n` bit left => Multiply by `2^n`

**Example** `101.1` Move floating point by one bit right\
`1011 * 2^(-1)` => `(2^3 + 2^1 + 2^0)` x `2^(-1)` => `101.1`

**Normalization**

**Explicit:** `(-1)^S x 0.M x 2^E` -> Binary point to the immediate left of Most Significant `1` Bit

* Ex : `101.1` =>`(-1)^0` x `.1011` x `2^3`

**Implicit:** `(-1)^S x 1.M x 2^E` -> Binary point to the immediate right of Most Significant `1` Bit

* Ex : `-101.1` =>`(-1)^1` x `1.011` x `2^2`

**IEEE 754 format** : Common structure in floating-point representation

`[ S | E | M ]`

* `S` -> (Sign) -> 0(+), 1(-) Always 1 bit
* `E` -> (Exponent) -> 2^`E`
* `M` -> (Mantissa) -> significant digits of the number (Represent Precision)

**Ques :** Let `E` is of 4 bit , `M` is of 5 bit Represent `101.1` Explicit in IEEE 754 format **Ans** : `101.1` -> `(-1)^0` x `.1011` x `2^3` `E` -> `3` Decimal -> `11` binary -> `0011` (in 4 bit) `M` -> `1011` binary -> `10110` (in 5 bit) `[ S | E | M ]` => `[0 | 0011 | 10110 ]`

Note:

* Without changing value, `0` can be added to the right most of a value after floating point, or left most of value before floating point
* In Mantissa `.10110` : `M[10110]` -> `.101100`: `M[101100]` , `0` bit are added to the right most as we can't add it to left most because in Mantissa format, `.` exist at leftmost

**Ques :** Let `E` is of 4 bit , `M` is of 5 bit Represent `.0110` Implicit in IEEE 754 format **Ans** : `.0110` -> `(-1)^0` x `1.10` x `2^(-2)` `M` -> `1011` binary -> `10110` (in 5 bit)

**Negative E by 2's Complement** `E` -> `-2` Decimal -> Represent Negative by 2's complement -> 2's complement of (`2`) -> 2's complement of (`10`) -> 2's complement of (`0010`) (in 4 bit) -> `0010` + `1101`(one value less than max) + `1` -> `1110` `[ S | E | M ]` => `[0 | 1110 | 10110 ]`

or

**Negative E by Biasing** `E` -> `-2` Decimal + Excess Code ( 4 bit ) -> `-2` + Excess Code ( `-2^(4-1)` to `2^(4-1)-1`) -> `-2` + Excess code (`-8` to `7`) -> `-2` + `8` (max abs value) -> `6` -> `0110` `[ S | E | M ]` => `[0 | 0110 | 10110 ]`

**Biasing**

Formula to Get value back if Biasing done in format => `(-1)^S` x `0.M` x `2^[E-B]`

**Ques:** Find value of `[0 | 0110 | 10110 ]` if biasing was done on it. **Ans:** `(-1)^0` x `0.10110` x `2^[6-8]`

***

***

## Interrupt

### [I/O Interface in Computer Organization](https://www.youtube.com/watch?v=PM728r4oGcE\&list=PLxCzCOWd7aiHMonh3G6QNKq53C6oNXGrX\&index=61\&pp=iAQB)

***

### [Interrupts in 8085 microprocessor | Types of Interrupts in Computer Organization](https://www.youtube.com/watch?v=1aG3aFEKxyA\&list=PLxCzCOWd7aiHMonh3G6QNKq53C6oNXGrX\&index=62\&pp=iAQB)

***

### [Daisy Chaining in Priority Interrupt | Priority Based Interrupt in I/O Organization](https://www.youtube.com/watch?v=QvSmbkcmff0\&list=PLxCzCOWd7aiHMonh3G6QNKq53C6oNXGrX\&index=63\&pp=iAQB) ⭐

***

### [Parallel priority interrupt | I/O organization](https://www.youtube.com/watch?v=dXOH3Czy5aw\&list=PLxCzCOWd7aiHMonh3G6QNKq53C6oNXGrX\&index=64\&pp=iAQB)

***

### [Question on Interrupt Handling(I/O organization) | Computer Organization | UGC NTA NET June 2021](https://www.youtube.com/watch?v=-IlIVW1F5dw\&list=PLxCzCOWd7aiHMonh3G6QNKq53C6oNXGrX\&index=65\&pp=iAQB)

***

### [Question on DMA (Direct Memory Access) | Input/Output Organization| COA | UGC NTA NET June 2021](https://www.youtube.com/watch?v=qhbgkyi_fbw\&list=PLxCzCOWd7aiHMonh3G6QNKq53C6oNXGrX\&index=66\&pp=iAQB)

***
