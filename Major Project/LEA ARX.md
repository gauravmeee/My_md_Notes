

![](https://www.researchgate.net/publication/328922621/figure/fig2/AS:692694397493250@1542162622284/The-round-function-of-LEA.png)

An **ARX (Addition-Rotation-XOR) cipher** is a type of cryptographic algorithm that primarily relies on three operations:

1. **Addition** (`+` or modular addition, usually modulo 2322^{32})**: 
	-  In Many Cryptographic Diagrams represented by a **Square with a plus sign (`[+]`)**.
2. **XOR** (Exclusive OR):
	- Represented by the **circle with a plus sign (`⊕`) inside it**. 
3. **Rotation** (ROL/ROR, circular bit shifts):
    - **Left Rotation (ROL)**: Indicated with the `ROL_x` box (e.g., `ROL_9`).
    - **Right Rotation (ROR)**: Indicated with the `ROR_x` box (e.g., `ROR_5`, `ROR_3`).

---


### ARX Cipher Simple Round Function in C++)


```cpp
#include <iostream>
#include <cstdint>

uint32_t ROR(uint32_t value, int shift) {
    return (value >> shift) | (value << (32 - shift));
}

uint32_t ROL(uint32_t value, int shift) {
    return (value << shift) | (value >> (32 - shift));
}

void ARX(uint32_t &x0, uint32_t &x1, uint32_t key) {
    x0 = x0 + key;      // Modular Addition
    x1 = x1 ^ x0;       // XOR
    x0 = ROL(x0, 7);    // Left Rotation
    x1 = ROR(x1, 3);    // Right Rotation
}

int main() {
    uint32_t x0 = 0x12345678, x1 = 0x9ABCDEF0, key = 0x0F0F0F0F;
    
    std::cout << "Before: x0 = " << std::hex << x0 << ", x1 = " << x1 << std::endl;
    ARX(x0, x1, key);
    std::cout << "After: x0 = " << std::hex << x0 << ", x1 = " << x1 << std::endl;

    return 0;
}
```

**Explanation of Operations:**
1. **Addition**: `x0 = x0 + key;`
2. **XOR**: `x1 = x1 ^ x0;`
3. **Rotation**:
    - Left rotate `x0` by 7 bits (`ROL(x0, 7)`)
    - Right rotate `x1` by 3 bits (`ROR(x1, 3)`)
Note: This is a simplified version of ARX-based cryptographic primitives used in ciphers like **Speck, ChaCha20, and BLAKE**.

---

### Example with 4-bit Blocks

This example illustrates the **basic structure of an ARX round** used in modern cryptographic designs like **Speck, ChaCha, and BLAKE**.

Let’s assume:

- Initial values:
    - X0=0b1010X_0 = 0b1010 (decimal **10**)
    - X1=0b1100X_1 = 0b1100 (decimal **12**)
- Round key: RK=0b0110RK = 0b0110 (decimal **6**)
- We will perform **Addition, XOR, and Rotation**.

Note: `0b` prefix is used in many programming languages (such as **C++, Python, JavaScript, etc.**) to denote a **binary number**.

### **Step-by-Step ARX Computation**

**1. Addition (Modular Addition)**
- We perform modular addition X0=(X0+RK)mod  24X_0 = (X_0 + RK) \mod 2^4:
```
X0=(10102+01102)mod  24X_0 = (1010_2 + 0110_2) \mod 2^4 X0=(10+6)mod  16=16mod  16=0b0000X_0 = (10 + 6) \mod 16 = 16 \mod 16 = 0b0000
```
- Now, X0=0b0000X_0 = 0b0000.

**2. XOR Operation**
- We XOR the new X0X_0 with X1X_1:
```
X1=X1⊕X0X_1 = X_1 \oplus X_0 X1=11002⊕00002=11002X_1 = 1100_2 \oplus 0000_2 = 1100_2
```
- X1X_1 remains **0b1100**.

**3. Bit Rotation**

- Now, we apply rotation:
- **Left Rotate X0X_0 by 1 bit**:  
    ROL1(X0)ROL_1(X_0) on **0b0000** → **0b0000** (unchanged)
- **Right Rotate X1X_1 by 2 bits**:  
    ROR2(X1)ROR_2(X_1):
```
1100 → Right Rotate by 2 → 0011
```
- Now, X1=0b0011X_1 = 0b0011.
    


**Final Output after ARX Round**
- X0=0b0000X_0 = 0b0000 (**0 in decimal**)
- X1=0b0011X_1 = 0b0011 (**3 in decimal**)

**Summary Table**

|Step|X₀ (4-bit)|X₁ (4-bit)|
|---|---|---|
|Initial|`1010` (10)|`1100` (12)|
|Addition|`0000` (0)|`1100` (12)|
|XOR|`0000` (0)|`1100` (12)|
|Rotation|`0000` (0)|`0011` (3)|
