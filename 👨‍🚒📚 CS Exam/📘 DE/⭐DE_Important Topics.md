
# Number System and Base Conversion


##### **1. From any base to Decimal (Base-10)**

- Multiply each digit by its base raised to the positional power.
- Add all results.
- **Example**: `(1011)₂` to `decimal`:
```
1×2³ + 0×2² + 1×2¹ + 1×2⁰  
= 8 + 0 + 2 + 1  
= 11₁₀
```


If the ==**binary number is a float**==, you convert **integer part** and **fractional part** separately: ⭐

**Steps:**

1. **Integer part** → Multiply each bit by `2^n` according to its position (same as normal).
2. **Fractional part** → Multiply each bit by `2^(-n)` according to its position after the point.


- **Example:** `(11001.101)₂` to `base-10`
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

##### **2. From Decimal to Any Base**

- Repeatedly divide the decimal number by the target base.
- Write remainders in reverse order.
- **Example:** `(25)₁₀` to `base-2`:

```
25 ÷ 2 = 12 remainder 1  
12 ÷ 2 = 6  remainder 0  
6 ÷ 2  = 3  remainder 0  
3 ÷ 2  = 1  remainder 1  
1 ÷ 2  = 0  remainder 1  
→ 11001₂
```


If the ==**decimal number is a float**==, you convert **integer part** and **fractional part** separately: ⭐

**Steps:**

1. **Integer part** → Use repeated division by `base` (same as normal).
2. **Fractional part** → Multiply repeatedly by `base`, take the integer part each time as the next digit.
- **Example:** `(25.625)₁₀ `to `base-2`

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


##### **4. From One Non-Decimal Base to Another**

- Convert to decimal first, then to target base.
- **Example:** (27)₈ to base-2:
```
1. (27)₈ = 2×8¹ + 7×8⁰  
         = 16 + 7  
         = 23₁₀

2. 23₁₀ = 10111₂
```
    

---

# Boolean Algebra Laws

**1. Identity Laws**
- `A + 0` = `A`    
- `A ⋅ 1`=  `A`

**2. Null Laws**
- `A + 1` = `1`
-  `A ⋅ 0` = `0`
    
**3. Idempotent Laws**
- `A + A` = `A`
- `A ⋅ A` = `A`
    
**4. Complement Laws**
- `A + A′` = `1`
- `A ⋅ A′` = `0`

**5. Domination Laws**
- `A+1`  = `1`
- `A ⋅ 0` = `0`
    
**6. Double Negation**
- `(A′)′`  = `A`
    
**7. Commutative Laws**
- `A + B` = `B + A`
- `A ⋅ B` = `B ⋅ A`
    
**8. Associative Laws**
- `( A + B ) + C` = `A + (B + C)`
- `( A ⋅ B ) ⋅ C` = `A . (B . C)

**9. Distributive Laws** ⭐
- `A ( B + C )` = `AB + AC`
- `A + BC` = `(A + B)(A + C)`

**12. Special Distributive Form** ⭐
- `X + X′Y` = `X + YX + X' Y` = `X + Y`
- Example: `B′+BA` = `B′+AB' + BA` = `B' + A`

**10. Absorption Laws** ⭐
- `A + AB` = `A`
- `A ( A + B )` = `A`

**11. De Morgan’s Laws** ⭐
- `( A + B )′` = `A'B'`
- `(AB)′` = `A' + B'`


### Proofs of Some Important Algebra 


**1. Distributive Laws**

- (a) $A(B+C) = AB + AC$

- (b) $(A+B)(A+C) = A + BC$

$$\begin{aligned} (A + B)(A + C) &= A(A + C) + B(A + C) \\ &= A + AC + AB + BC \\ &= A + AB + AC + BC \\ &= A (1 + B + C) + BC \\ &= A + BC \end{aligned}$$


**2. Special Distributive Laws**

- (a) $X+X′Y= X+Y$

$$\begin{aligned} X + X'Y &= (X + X')(X + Y) \\ &= (1)(X + Y) \\ &= X + Y \end{aligned}$$


**3. Absorption Laws**

- (a) $A+AB = A(1+B) = A(1) =A$ 

- (b) $A(A+B)=AA+AB=A+AB=A$ 


**4. De Morgan’s Laws**

- (a) $(A+B)′=A′B′$

- (b) $(AB)′=A′+B′$


---

# 2'S Complement, BCD Code,  XS-3 Code, Gray Code


### 2’s Complement

**Definition:** Binary number ==representation for signed integers== where negative numbers are obtained by taking the 1’s complement and adding 1.  
**Use:** ==Simplifies subtraction== in digital systems.  
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

### Excess-3 Code

**Definition:** A self-complementary decimal code obtained by adding 3 to each decimal digit and converting to 4-bit binary.  
**Use:** Error detection, decimal calculations.

Example table:

|Decimal|Binary|Excess-3|
|---|---|---|
|0|0000|0011 (3)|
|1|0001|0100 (4)|
|2|0010|0101 (5)|
|3|0011|0110 (6)|
|4|0100|0111 (7)|
|5|0101|1000 (8)|
|6|0110|1001 (9)|
|7|0111|1010 (10)|
|8|1000|1011 (11)|
|9|1001|1100 (12)|

### BCD (Binary Coded Decimal)

**Definition:** Represents each decimal digit separately in binary (4 bits per digit).  
**Use:** Digital displays, calculators.

Example:

```
                5    9
Decimal 59 = (0101 1001) in BCD
```

### Gray Code

**Definition:** A binary code where consecutive values differ by only 1 bit (minimizes errors in transitions).  
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

---

# Multiplexer & Demultiplexer


### Multiplexer (MUX)

**Definition:**  
A **Multiplexer** is a combinational circuit that ==selects one input line from multiple inputs and forwards it to a single output line==, based on select lines.

**Key Points:**
- Also called **data selector**
- Reduces number of data lines by combining them
- Requires ==**n** select lines to select from **2ⁿ**== inputs

**Multiplexer (MUX) Significance**
- Allows selection of one data line from many inputs using select lines.
- ==Reduces hardware== by sharing a single communication line.
- Used in ==data routing, ALU input selection, signal switching==.

**Block Diagram:**
```
   I0 ──┌───────┐
   I1 ──| 4 x 1 |── OUT
   I2 ──| MUX   |
   I3 ──└───────┘
          |   |
          S1  S0
       Select Lines
```

**Truth Table (4:1 MUX example):**

|S1|S0|OUT|
|---|---|---|
|0|0|I0|
|0|1|I1|
|1|0|I2|
|1|1|I3|

### Demultiplexer (DEMUX)

**Definition:**  
A _Demultiplexer_ is a combinational circuit that takes a single input and routes it to one of several output lines, based on select lines.

**Key Points:**
- Opposite of MUX
- Requires ==**n** select lines for **2ⁿ**== outputs
    

**Demultiplexer (DEMUX) Significance**
- ==Routes one input signal to one of many output lines== based on select lines.
- Used in ==serial-to-parallel data conversion==.
- Common in communication systems for data distribution.
    
**Block Diagram:**

```
     ┌───────┐── O0
IN ──| 1 x 4 |── O1
     | DEMUX |── O2   
     └───────┘── O3
		|   |
		S1  S0
	 Select Lines
```

**Truth Table (1:4 DEMUX example):**

|S1|S0|O0|O1|O2|O3|
|---|---|---|---|---|---|
|0|0|IN|0|0|0|
|0|1|0|IN|0|0|
|1|0|0|0|IN|0|
|1|1|0|0|0|IN|


**Summary Table:**

|Feature|Multiplexer|Demultiplexer|
|---|---|---|
|Function|Many → One|One → Many|
|Inputs|2ⁿ|1|
|Outputs|1|2ⁿ|
|Control|n select|n select|
|Example|4:1 MUX|1:4 DEMUX|


---

# Encoder & Decoder
### Encoder

**Definition:**  
An _Encoder_ is a combinational circuit that ==converts **2ⁿ input lines** into **n output lines** by ==encoding the active input into binary form.

**Key Points:**
- Works opposite to Decoder
- Only ==one input should be active at a time==
- Example: ==8-to-3 encoder== → 8 inputs, 3 outputs
    
**Encoder Significance**
- Converts ==active input line into binary code==.
- Reduces number of bits needed to represent multiple signals.
- Used in ==keyboards, priority systems, and digital communication==.


**Block Diagram (4-to-2 Encoder):**

```
   I0  I1 I2 I3
    │  │  │  │
    ┌───────┐
    │Encoder│ 4x2
    └───────┘
       │  │
      Y1 Y0   (Binary output)
```

**Truth Table (4-to-2 Encoder):**

|I3|I2|I1|I0|Y1|Y0|
|---|---|---|---|---|---|
|0|0|0|1|0|0|
|0|0|1|0|0|1|
|0|1|0|0|1|0|
|1|0|0|0|1|1|

---

### Decoder

**Definition:**  
A _Decoder_ is a combinational circuit that ==converts **n input lines** into **2ⁿ output lines**==, activating only one output for each input combination.

**Key Points:**
- Opposite of Encoder
- Used for ==address decoding== in memory systems
- Example: 2-to-4 decoder → 2 inputs, 4 outputs
    
**Decoder Significance**
- ==Converts binary input into a single active output line==.
- Used for ==address decoding in memory==, display systems, and instruction decoding.


**Block Diagram (2-to-4 Decoder):**

```
    A1 A0  (Inputs)
     │ │
   ┌───────┐
   │Decoder│ 2X4
   └───────┘
  │  │  │  │
 O0 O1 O2 O3
```

**Truth Table (2-to-4 Decoder):**

|A1|A0|O0|O1|O2|O3|
|---|---|---|---|---|---|
|0|0|1|0|0|0|
|0|1|0|1|0|0|
|1|0|0|0|1|0|
|1|1|0|0|0|1|


**Summary Table:**

|Feature|Encoder|Decoder|
|---|---|---|
|Function|Many→Few|Few→Many|
|Inputs|2ⁿ|n|
|Outputs|n|2ⁿ|
|Example|8:3 Encoder|3:8 Decoder|

---

# Latch , Flip-flop and Shift Register
### Latch

**Definition:**  
A **Latch** is a level-triggered ==bistable circuit that stores 1 bit of data==. ==Output changes as long as the control signal (Enable) is active==.

**Key Points:**

- **Level sensitive** (transparent when enabled)
- Basic types: SR Latch, D Latch
- Built using NAND/NOR gates

**SR Latch Significance**
- Basic ==1-bit memory element==.
- Stores data as long as power is on.
- ==Building block for flip-flops and registers==.


**SR Latch (NAND) Diagram:**

```
      ┌───────┐       ┌───────┐
 S ---|       |-------|       |--- Q
      | NAND  |       | NAND  |
 R ---|       |---┐   |       |
      └───────┘   |   └───────┘
                  |           
                  └----------- Q'
```



>**SR latch** → Official/common term in books & PSU exams
> **RS latch** → Same thing, just order of inputs swapped in naming

---

### Flip-Flop

**Definition:**  
A **Flip-Flop** is an **edge-triggered bistable circuit** that **==stores 1 bit of data==** and changes state only on a clock edge (rising or falling).

**Key Points:**
- **Edge sensitive** (clock controlled)
- Types: SR, JK, D, T Flip-Flop
- Used in counters, registers, memory


**Flip-Flop Significance**
- Edge-triggered storage element.
- ==Used in counters, register==s, and sequential circuits.
- Essential for synchronous digital systems.

**D Flip-Flop Symbol:**
```
    D ────────┐
              │
            ┌─────┐
   CLK ────►│ DFF │─── Q
            └─────┘
                 │
                 └── Q'
```

**Characteristic Table (D Flip-Flop):**

|CLK Edge|D|Q(next)|
|---|---|---|
|↑|0|0|
|↑|1|1|

---

### Shift Register

**Definition:**  
A **Shift Register** is a group of flip-flops connected in series, used to store and shift data bits left or right under clock control.

**Key Points:**
- Made using D Flip-Flops
- Modes: SISO, SIPO, PISO, PIPO
- Used in data transfer, serialization, delay circuits

**Modes:**
- **SISO** → Serial In Serial Out
- **SIPO** → Serial In Parallel Out
- **PISO** → Parallel In Serial Out
- **PIPO** → Parallel In Parallel Out

**Shift Register Significance**
- ==Stores multiple bits and shifts them serially or in parallel==.
- Used for data transfer (serial ↔ parallel), ==temporary storage==, and time delays.
- Common in communication interfaces and digital processing.

**4-bit Serial-In Serial-Out (SISO) Diagram:**
```
 Data In → [DFF1] → [DFF2] → [DFF3] → [DFF4] → Data Out
             ↑        ↑         ↑       ↑
            CLK      CLK       CLK     CLK
```


**Summary Table:**

|Device|Bits Stored|Triggering|Use Case|
|---|---|---|---|
|Latch|1|Level|Simple data storage|
|Flip-Flop|1|Edge|Registers, counters|
|Shift Register|n|Edge (Clock)|Data shift, storage, I/O|
