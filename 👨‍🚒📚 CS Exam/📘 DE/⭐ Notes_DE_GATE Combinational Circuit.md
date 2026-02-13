# ⭐ Notes\_DE\_GATE Combinational Circuit

### Combinational Logic Circuits

**Definition**

A **Combinational Logic Circuit (CLC)** is a digital circuit whose **output depends only on the present inputs**. There is **no memory** of past inputs.

**Characteristics**

* Output depends solely on current inputs
* No storage or feedback
* Delay exists due to gate propagation
* Used for arithmetic, data routing, and logic operations

**Basic Logic Gates**

**1. AND Gate:** Output = $A \cdot B$ (High if all inputs are 1)

```
A ──┐
    ├─·─ Output
B ──┘
```

**2. OR Gate:** Output = $A + B$ (High if any input is 1)

```
A ──┐
    ├─ + ─ Output
B ──┘
```

**3. NOT Gate (Inverter):** Output = $\overline{A}$ (Inverts input)

```
A ──⊙─ Output
```

**4. XOR Gate:** Output = $A \oplus B$ (High if inputs are different)

```
A ──┐
    ├─⊕─ Output
B ──┘
```

**5. NAND Gate** – Output = $\overline{A \cdot B}$ (NOT-AND)

```
A ──┐
    ├─⊼─ Output
B ──┘

- Universal GATE
```

**6. NOR Gate** – Output = $\overline{A + B}$ (NOT-OR)

```
A ──┐
    ├─⊽─ Output
B ──┘

- Universal GATE
```

**7. XNOR Gate** – Output = $\overline{A \oplus B}$ (High if inputs are same)

```
A ──┐
    ├─⊕⊙─ Output
B ──┘
```

**Universal Gate**

A **universal gate** can implement **any logic function**

**1. `NAND` as Universal Gate** ⭐

* **NAND** can implement **any logic function**
* **NAND** gate can form:
  * **NOT:** $\overline{A} = A \text{ NAND } A$
  * **AND:** $A \cdot B = \overline{A \text{ NAND } B} = (A \text{ NAND } B) \text{ NAND } (A \text{ NAND } B)$
  * **OR:** $A + B = (\overline{A} \text{ NAND } \overline{B}) = (A \text{ NAND } A) \text{ NAND } (B \text{ NAND } B)$
* **Reason:** NAND combinations can generate all basic gates
* **Advantage:** Simplifies hardware design, reduces cost

**2. `NOR` as Universal Gate** ⭐

* **NOR** can also implement **any logic function**
* **NOR** gate can form:
  * **NOT:** $\overline{A} = A \text{ NOR } A$
  * **OR:** $A + B = \overline{\overline{A} \text{ NOR } \overline{B\}} = (A \text{ NOR } A) \text{ NOR } (B \text{ NOR } B)$
  * **AND:** $A \cdot B = \overline{A \text{ NOR } B} = (A \text{ NOR } B) \text{ NOR } (A \text{ NOR } B)$
* **Reason:** NOR combinations can generate all basic gates
* **Advantage:** Useful in memory circuits and logic simplification

**Basic Combinational Circuits**

**1. Half Adder** ⭐

* Adds two single-bit numbers (A, B)
* **Sum (S) = $A \oplus B$**
* **Carry (C) = $A \cdot B$**

```
A ───┐
     ├─⊕─ S
B ───┘

A ───┐
     ├─·─ C
B ───┘
```

**2. Full Adder**

* Adds three bits (A, B, Cin)
* \==**Sum== = $A \oplus B \oplus C\_{in}$**
* **==Carry== = $(A \cdot B) + (B \cdot C\_{in}) + (A \cdot C\_{in})$** ⭐

**3. Half Subtractor:**

* \==**Diff**== = $A \oplus B$,
* \==**Borrow**== = $\overline{A} \cdot B$ ⭐

**4. Full Subtractor:**

* **Diff** = $A \oplus B \oplus B\_{in}$,
* **Borrow** = $\overline{A} \cdot B + (\overline{A} \oplus B) \cdot B\_{in}$

**5. Multiplexer (MUX)**

* \==Selects one input== from many
* n-to-1 MUX has **n inputs, $\log\_2 n$ select lines, 1 output**

**6. Demultiplexer (DEMUX)**

* \==Routes single input to one of many outputs==
* 1-to-n DEMUX has **1 input, $\log\_2 n$ select lines, n outputs**

**7. Encoder**

* \==Converts $2^n$ inputs into **n-bit** code==
* Example: 8-to-3 encoder

**8. Decoder**

* \==Converts **n-bit** input to $2^n$ outputs==
* Example: 3-to-8 decoder

**Applications**

* Arithmetic operations (Adders, Subtractors)
* Data routing (MUX/DEMUX)
* Code conversion (Encoder/Decoder)
* Logic functions in processors

***

### Important Combinational Circuits

**1. Half Adder ⭐**

* \==Adds two single-bit== numbers (A, B)
* **Sum (S) = A ⊕ B**
* **Carry (C) = A · B**

**Truth Table:**

| A | B | Sum (S) | Carry (C) |
| - | - | ------- | --------- |
| 0 | 0 | 0       | 0         |
| 0 | 1 | 1       | 0         |
| 1 | 0 | 1       | 0         |
| 1 | 1 | 0       | 1         |

**Circuit Diagram:**

```
A ───┐
     ├─⊕─ S
B ───┘

A ───┐
     ├─·─ C
B ───┘
```

**2. Full Adder**

* \==Adds three bits== (A, B, Cin)
* **Sum = A ⊕ B ⊕ Cin**
* **Carry = (A · B) + (B · Cin) + (A · Cin)** ⭐

**Truth Table:**

| A | B | Cin | Sum | Carry |
| - | - | --- | --- | ----- |
| 0 | 0 | 0   | 0   | 0     |
| 0 | 0 | 1   | 1   | 0     |
| 0 | 1 | 0   | 1   | 0     |
| 0 | 1 | 1   | 0   | 1     |
| 1 | 0 | 0   | 1   | 0     |
| 1 | 0 | 1   | 0   | 1     |
| 1 | 1 | 0   | 0   | 1     |
| 1 | 1 | 1   | 1   | 1     |

**Circuit Diagram:**

```
   A ──┐
       ├─⊕─\
   B ──┘     \
              ⊕ ─ Sum
   Cin ──────/
   
   A ──┐
       ├─·─\
   B ──┘     \
              + ─ Carry
   Cin ──────/
```

**3. Half Subtractor**

* **Diff = A ⊕ B**
* **Borrow = A̅ · B**

**Truth Table:**

| A | B | Diff | Borrow |
| - | - | ---- | ------ |
| 0 | 0 | 0    | 0      |
| 0 | 1 | 1    | 1      |
| 1 | 0 | 1    | 0      |
| 1 | 1 | 0    | 0      |

**Circuit Diagram:**

```
A ───┐
     ├─⊕─ Diff
B ───┘

A ──┐
    ├─⊙─\
         ·─ Borrow
B ──────/
```

**4. Full Subtractor**

* **Diff = A ⊕ B ⊕ Bin**
* **Borrow = A̅ · B + (A̅ ⊕ B) · Bin**

**Truth Table:**

| A | B | Bin | Diff | Borrow |
| - | - | --- | ---- | ------ |
| 0 | 0 | 0   | 0    | 0      |
| 0 | 0 | 1   | 1    | 1      |
| 0 | 1 | 0   | 1    | 1      |
| 0 | 1 | 1   | 0    | 1      |
| 1 | 0 | 0   | 1    | 0      |
| 1 | 0 | 1   | 0    | 0      |
| 1 | 1 | 0   | 0    | 0      |
| 1 | 1 | 1   | 1    | 1      |

**Circuit Diagram:**

```
   A ──┐
       ├─⊕─\
   B ──┘     \
              ⊕ ─ Diff
   Bin ──────/
   
   A ──┐
       ├─⊙─\
   B ──┘     \
              + ─ Borrow
   Bin ──────/
```

**5. Multiplexer (MUX)**

* **Function:** Selects one input from many based on select lines
* **n-to-1 MUX:** $n$ inputs, $log\_2n$ select lines, 1 output
* **Truth Table (4-to-1 example):**

| S1 | S0 | Y  |
| -- | -- | -- |
| 0  | 0  | I0 |
| 0  | 1  | I1 |
| 1  | 0  | I2 |
| 1  | 1  | I3 |

**Circuit Diagram (4-to-1):**

```
I0 ──┐
I1 ──┤
I2 ──┤───┐
I3 ──┘   ├─ Y
         │
S1 ──────┘
S0 ──────┘
```

**6. Demultiplexer (DEMUX)**

* **Function:** Routes single input to one of many outputs based on select lines
* **1-to-n DEMUX:** 1 input, $log\_2n$ select lines, $n$ outputs
* **Truth Table (1-to-4 example):**

| S1 | S0 | Y0 | Y1 | Y2 | Y3 |
| -- | -- | -- | -- | -- | -- |
| 0  | 0  | I  | 0  | 0  | 0  |
| 0  | 1  | 0  | I  | 0  | 0  |
| 1  | 0  | 0  | 0  | I  | 0  |
| 1  | 1  | 0  | 0  | 0  | I  |

**Circuit Diagram (1-to-4):**

```
      ┌─ Y0
I ────┤
      ├─ Y1
      ├─ Y2
      └─ Y3

S1 ──┐
S0 ──┘
```

**7. Encoder**

* **Function:** Converts $2^n$ inputs into n-bit code
* Example: **8-to-3 encoder**

| Inputs (I0-I7) | Output (Y2 Y1 Y0) |
| -------------- | ----------------- |
| 00000001       | 000               |
| 00000010       | 001               |
| 00000100       | 010               |
| 00001000       | 011               |
| 00010000       | 100               |
| 00100000       | 101               |
| 01000000       | 110               |
| 10000000       | 111               |

**Circuit Diagram (8-to-3):**

```
I0 ──┐
I1 ──┤
I2 ──┤───> Y0,Y1,Y2
I3 ──┤
I4 ──┤
I5 ──┤
I6 ──┤
I7 ──┘
```

**8. Decoder**

* **Function:** Converts **n-bit** input to $2^n$ outputs
* Example: **3-to-8 decoder**

| Input (A2 A1 A0) | Output (Y0-Y7) |
| ---------------- | -------------- |
| 000              | 00000001       |
| 001              | 00000010       |
| 010              | 00000100       |
| 011              | 00001000       |
| 100              | 00010000       |
| 101              | 00100000       |
| 110              | 01000000       |
| 111              | 10000000       |

**Circuit Diagram (3-to-8):**

```
A0 ──┐
A1 ──┤ ───> Y0,Y1,Y2,Y3,Y4,Y5,Y6,Y7
A2 ──┘
```

***

## Multiplexer & Demultiplexer

**1. Multiplexer (MUX)**

**Definition:**\
A **Multiplexer** is a combinational circuit that ==selects one input line from multiple inputs and forwards it to a single output line==, based on select lines.

**Key Points:**

* Also called **data selector**
* Reduces number of data lines by combining them
* Requires ==**n** select lines to select from **2ⁿ**== inputs

**Multiplexer (MUX) Significance**

* Allows selection of one data line from many inputs using select lines.
* \==Reduces hardware== by sharing a single communication line.
* Used in ==data routing, ALU input selection, signal switching==.

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

| S1 | S0 | OUT |
| -- | -- | --- |
| 0  | 0  | I0  |
| 0  | 1  | I1  |
| 1  | 0  | I2  |
| 1  | 1  | I3  |

**2. Demultiplexer (DEMUX)**

**Definition:**\
A _Demultiplexer_ is a combinational circuit that takes a single input and routes it to one of several output lines, based on select lines.

**Key Points:**

* Opposite of MUX
* Requires ==**n** select lines for **2ⁿ**== outputs

**Demultiplexer (DEMUX) Significance**

* \==Routes one input signal to one of many output lines== based on select lines.
* Used in ==serial-to-parallel data conversion==.
* Common in communication systems for data distribution.

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

| S1 | S0 | O0 | O1 | O2 | O3 |
| -- | -- | -- | -- | -- | -- |
| 0  | 0  | IN | 0  | 0  | 0  |
| 0  | 1  | 0  | IN | 0  | 0  |
| 1  | 0  | 0  | 0  | IN | 0  |
| 1  | 1  | 0  | 0  | 0  | IN |

**Summary Table:**

| Feature  | Multiplexer | Demultiplexer |
| -------- | ----------- | ------------- |
| Function | Many → One  | One → Many    |
| Inputs   | 2ⁿ          | 1             |
| Outputs  | 1           | 2ⁿ            |
| Control  | n select    | n select      |
| Example  | 4:1 MUX     | 1:4 DEMUX     |

***

#### Encoder & Decoder

**Encoder**

An _Encoder_ is a combinational circuit that ==converts **2ⁿ input lines** into **n output lines** by ==encoding the active input into binary form.

**Key Points:**

* Works opposite to Decoder
* Only ==one input should be active at a time==
* Example: ==8-to-3 encoder== → 8 inputs, 3 outputs

**Encoder Significance**

* Converts ==active input line into binary code==.
* Reduces number of bits needed to represent multiple signals.
* Used in ==keyboards, priority systems, and digital communication==.

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

| I3 | I2 | I1 | I0 | Y1 | Y0 |
| -- | -- | -- | -- | -- | -- |
| 0  | 0  | 0  | 1  | 0  | 0  |
| 0  | 0  | 1  | 0  | 0  | 1  |
| 0  | 1  | 0  | 0  | 1  | 0  |
| 1  | 0  | 0  | 0  | 1  | 1  |

**Decoder**

A _Decoder_ is a combinational circuit that ==converts **n input lines** into **2ⁿ output lines**==, activating only one output for each input combination.

**Key Points:**

* Opposite of Encoder
* Used for ==address decoding== in memory systems
* Example: 2-to-4 decoder → 2 inputs, 4 outputs

**Decoder Significance**

* \==Converts binary input into a single active output line==.
* Used for ==address decoding in memory==, display systems, and instruction decoding.

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

| A1 | A0 | O0 | O1 | O2 | O3 |
| -- | -- | -- | -- | -- | -- |
| 0  | 0  | 1  | 0  | 0  | 0  |
| 0  | 1  | 0  | 1  | 0  | 0  |
| 1  | 0  | 0  | 0  | 1  | 0  |
| 1  | 1  | 0  | 0  | 0  | 1  |

**Summary Table:**

| Feature  | Encoder     | Decoder     |
| -------- | ----------- | ----------- |
| Function | Many→Few    | Few→Many    |
| Inputs   | 2ⁿ          | n           |
| Outputs  | n           | 2ⁿ          |
| Example  | 8:3 Encoder | 3:8 Decoder |
