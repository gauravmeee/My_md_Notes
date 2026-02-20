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

# Addressing Modes

### **Types of Addressing Mode**

**A. Non-Computable Addressing Modes**

> Effective address is obtained without arithmetic computation

1. **Implied Mode**\
   Operand is ==**implicitly defined by opcode**== (no address field required).
2. **Immediate Mode**\
   \==Address field contains the **operand== itself** (constant data).
3. **Direct Mode**\
   \==Address field contains the **effective address== (E.A)** of operand.\
   `Operand = M[Address]`
4. **Indirect Mode**\
   \==Address field points to a memory location that contains **E.A**.==\
   `E.A = M[Address]`, `Operand = M[E.A]`
5. **Register Mode**\
   \==Address field specifies a **register** which contains operand.==\
   `Operand = R`
6. **Register Indirect Mode**\
   \==Address field specifies a register which contains **E.A** of operand.==\
   `E.A = R`, `Operand = M[E.A]`

**B. Computable Addressing Modes**

> Effective address is computed using arithmetic like `+` / `-`

1. **Autoincrement / Autodecrement Mode**\
   Register indirect mode where register is **automatically updated** after/before access.\
   `Operand = M[R]`, then `R = R ± d`
2. **Indexed Mode**\
   Effective address = **Base address (instruction)** + **Index register**.\
   `E.A = Address + IndexReg`
3. **PC-Relative Mode**\
   Effective address = **PC (next instruction address)** + **Offset (instruction)**.\
   `E.A = PC + Offset`
4. **Base Register Mode**\
   Effective address = **Base register** + **Offset (instruction)**.\
   `E.A = BaseReg + Offset`

***

### Displacement Addressing Modes

**`EA = Register + Displacement/Offset`**

**1. Indexed Mode ⭐**

`Effective address` = **`Base address` (from instruction)** + **`Index` (from index register)**

`E.A = Address + (IndexReg)`

* \==**Fixed / Not changeable:** `Address` field (Base Address)==
* \==**Changeable:** `IndexReg` value==
* **Use:** Arrays / tables / strings
* **Why:** Base points to start of array, index selects element number

```
              Instruction
  ┌──────────┬──────────┬─────────┐
  │ Opcode   │ Mode     │ Address │ = Base Address (constant in instruction)
  └──────────┴──────────┴───⬇─────┘
                          Base Address
                            │
                     ┌──────┴───────────┐
                     │  ADD    ( + )    │
                     └──────┬───────────┘
                            │
			 ┌──────────┐   │
			 │ IndexReg │───┘ (changes during execution)
			 └────⬇─────┘
				Index
				  │
				 E.A
				  │
			┌───────────┐
			│  Operand  │ = M[E.A]
			└───────────┘
```

**Example (Array):**

* `Address = Base of A[0]`
* `IndexReg = i * size`
* Access `A[i]`

**2. PC-Relative Mode (Position Independent Mode) ⭐**

`Effective address` = **`PC` (next instruction address)** + **`Offset` (from instruction)**

`E.A = PC + Offset`

* **Fixed / Not changeable:** `Offset` field (in instruction)
* **Changeable:** `PC` value (keeps changing automatically)
* **Use:** ==Branch / jump inside code segment== (loops, if-else)
* **Why:** Code can be loaded anywhere → jump still works (Position Independent Code)

```
             Instruction
  ┌──────────┬──────────┬─────────┐
  │ Opcode   │ Mode     │ Address │ = Offset (constant in instruction)
  └──────────┴──────────┴───⬇─────┘
                          Offset
                            │
                     ┌──────┴───────────┐
                     │  ADD    ( + )    │
                     └──────┬───────────┘
                            │
				  ┌─────────┘
				  │
			   ┌──┴───┐
			   │  PC  │ (changes every instruction)
			   └──⬇───┘
	    Addr of NEXT instruction
		 		  │
		 		 E.A
				  │
			┌──────────────┐
			│ Target Instr │ = M[E.A]
			└──────────────┘
```

**Notes:**

* PC contains **address of next instruction**, not current.
* Forward jump: `Offset +ve`
* Backward jump: `Offset -ve`

**Example:**

* `BEQ label`
* `Offset = label - (PC of next instr)`

**Base Register Mode (Inter-Segment Branch)**

Effective address = **`Base Register`** + **`Offset` (from instruction)**

`E.A = (BaseReg) + Offset`

* **Fixed / Not changeable:** `Offset` field
* **Changeable:** `BaseReg` value
* **Use:** ==Segment based addressing, relocation, dynamic memory blocks, inter-segment jump==
* **Why:** Base register selects the memory region/segment, offset selects inside it

```
              Instruction
   ┌──────────┬──────────┬─────────┐
   │ Opcode   │ Mode     │ Address │ = Offset (constant in instruction)
   └──────────┴──────────┴───⬇─────┘
                          Offset
                            │
                     ┌──────┴───────────┐
                     │  ADD    ( + )     │
                     └──────┬───────────┘
                            │
			 ┌──────────┐   │
			 │ BaseReg  │───┘ (changeable by program)
			 └────⬇─────┘
			 	Base
				  │
				 E.A
				  │
		   ┌──────────────┐
		   │ Target/Opnd  │ = M[E.A]
		   └──────────────┘
```

**Example:**

* BaseReg = start address of segment (code/data/stack)
* Offset = location inside that segment

**Key Differences (Most Important)**

```
Indexed Mode:      E.A = Address + IndexReg
PC-Relative Mode:  E.A = PC + Offset
Base Reg Mode:     E.A = BaseReg + Offset
```

| Point                    | **Indexed Mode**                             | **PC-Relative Mode**                           | **Base Register Mode**                          |
| ------------------------ | -------------------------------------------- | ---------------------------------------------- | ----------------------------------------------- |
| EA formula               | `EA = Address + IndexReg`                    | `EA = PC + Offset`                             | `EA = BaseReg + Offset`                         |
| Constant part comes from | **Instruction Address field** (Base Address) | **Instruction Address field** (Offset)         | **Instruction Address field** (Offset)          |
| Variable part comes from | **Index Register**                           | **PC register**                                | **Base Register**                               |
| Which register is used   | Special/general **Index Reg**                | **PC only** (fixed register)                   | Special/general **Base Reg**                    |
| What changes frequently  | **IndexReg** changes                         | **PC** changes automatically every instruction | **BaseReg** changes when segment/region changes |
| What stays same mostly   | Base address (array start)                   | Offset for that branch instruction             | Offset inside segment                           |
| Main purpose             | **Array/Table access**                       | **Branch/Jump** (control flow)                 | **Relocation/Segmentation**                     |
| Typical operand          | **Data** (A\[i])                             | **Instruction address** (label target)         | **Data/Instruction** inside a segment           |
| Best use-case            | Strings, arrays, lookup tables               | Loops, if-else, function local jumps           | Memory segments, modules, dynamic blocks        |
| Why needed               | Efficient element selection                  | **Position independent code**                  | Segment relocation with single register update  |
| Example meaning          | `A[i]`                                       | `goto label`                                   | access `segment_base + k`                       |

**Similarity**

`E.A = (Some Register) + (Some Constant from instruction)`

* Instruction (Fixed)
  * `Address` (in Indexed Register Mode)
  * `Offset` (in PC-Relative and Base Register Mode)
* Register (Changeable)
  * `IndexReg` (in Indexed Register Mode)
  * `PC` (in PC-Relative Mode)
  * `BaseReg` (in Base Register Mode)

**What changes?**

* **Indexed:** Index changes → moving across array elements
* **PC-relative:** PC changes → branch depends on current location
* **Base reg:** BaseReg changes → switch segment / memory region

**Best use:**

* **Indexed:** arrays/tables
* **PC-relative:** short/near jumps, loops, position-independent code
* **Base register:** segment relocation, far addressing, inter-segment jumps

### Similarity & Difference (Indexed vs PC-Relative vs Base Register Modes)

#### What is SAME (core similarity)

* **Instruction provides a constant displacement**
  * Indexed: constant = **Base Address**
  * PC-relative/Base: constant = **Offset**
* **One register provides a variable part**
* CPU does **addition** to get E.A

***

### What is DIFFERENT (real difference)

**1) Indexed Mode**

`E.A = Address + IndexReg`

* Register is ==**IndexReg**== (a normal register ==chosen by programmer==)
* It changes because **you change it** (loop variable i)
* Purpose: **Data access pattern**
  * arrays, tables, strings

**Meaning:**\
"Base is fixed, index moves element-to-element"

**2) PC-Relative Mode**

`E.A = PC + Offset`

* Register is **PC** (not selectable)
* It ==changes **automatically** every instruction==
* Purpose: **Control flow**
  * branch/jump target

**Meaning:**\
"Target is near current instruction"

Main benefit: **Position Independent Code (PIC)**\
(load program anywhere, jumps still work)

**3) Base Register Mode**

`E.A = BaseReg + Offset`

* Register is **BaseReg** (chosen/maintained by system/program)
* It ==changes when **segment/region changes**==
* Purpose: **Relocation / segmentation**
  * move whole block by changing base

**Meaning:**\
"Offset stays same, but base shifts entire region"

**Why 3 types if formula same?**

Because they solve **3 different problems**:

* **Indexed** → _where is `A[i]`?_ (data traversal)
* **PC-relative** → _where is next code label?_ (branch target)
* **BaseReg** → _where is my segment/block currently located?_ (relocation)

**Best 3-line exam difference**

* **Indexed:** for **arrays/tables** ($IndexReg$ changes)
* **PC-relative:** for **branches/jumps** ($PC$ changes automatically)
* **Base register:** for **relocation/segments** ($BaseReg$ changes when region shifts)
