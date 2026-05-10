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

**Definition:** Addressing mode specifies **how to interpret the operand** in an instruction (where the operand is located or how to get it).

1. **Immediate Addressing Mode** ⭐
   * <mark>**Operand**</mark> is given directly in the instruction.
   * **Advantage:** Fast, no memory access for operand.
   * **Application:** Constants.
   * **Example:** `MOV A, #5` → Load 5 into A.
2. **Direct (Absolute) Addressing Mode** ⭐
   * <mark>Address field</mark> contains the actual memory address of the operand.
   * **Application:** Access fixed memory location.
   * **Example:** `MOV A, 2000H` → Load from memory 2000H.
3. **Indirect Addressing Mode** ⭐
   * Address field contains a register/memory location holding the **effective address** of the operand.
   * **Application:** <mark>Pointers</mark>, linked lists.
   * **Example:** `MOV A, @R0` → Effective address from R0.
4. **Register Addressing Mode**
   * Operand is in a **CPU register**.
   * **Application:** Very fast access.
   * **Example:** `MOV A, R1`.
5. **Register Indirect Addressing Mode**
   * Register contains the address of operand in memory.
   * **Application:** Table lookups.
   * **Example:** `MOV A, @R2`.
6. **Base Addressing Mode** ⭐
   * **Effective Address (EA)** = Base Register + Displacement.
   * **Application:** <mark>Relocatable programs.</mark>
   * **Example:** `MOV A, 1000(RB)`.
7. **Index Addressing Mode** ⭐
   * **EA** = Index Register + Base Address.
   * **Application:** Arrays.
   * **Example:** `MOV A, ARR(RI)`.
8. **Relative Addressing Mode** ⭐
   * **EA** = Program Counter (PC) + Displacement.
   * **Application:** Branching instructions.
   * **Example:** `BEQ LABEL`.
9. **Autoincrement / Autodecrement Addressing**
   * Register points to operand and is **incremented/decremented automatically** after/before use.
   * **Application:** Stack operations, sequential data.
   * **Example:** `MOV A, (R1)+`.

**Quick Match for PSU-type Questions:**

* Immediate → Constants
* Direct → Fixed data
* Indirect → Pointers
* Register → Fast data access
* Base → Relocatable programs
* Index → Arrays
* Relative → Branching
* Auto inc/dec → Stack or sequential access

**Difference between Base, Index, and Relative Addressing Modes.**

1. **Base Addressing**
   * **Base** → relocation flexibility.
   * _Base_ comes from a <mark>**base register** that can be changed at runtime.</mark>
   * Useful for **relocatable programs**: move the whole program in memory, just update the base register.
   * Example: OS loads a process at a new memory location without changing its instructions.
2. **Index Addressing**
   * **Index** → array element access.
   * _Base_ is a **constant** in the instruction (start of an array), <mark>displacement_ is an **index register** that changes.</mark>
   * Perfect for **arrays/tables**: just increment the index register to access the next element.
   * Example: Loop accessing array elements sequentially.
3. **Relative Addressing**
   * **Relative** → branching within a short distance.
   * _Base_ is the **PC**, <mark>displacement_ is a constant offset in instruction.</mark>
   * Used for **branching/jumps**: target is always relative to the current instruction, making code **position-independent**.
   * Example: `BEQ LABEL` works even if program is loaded at a different address.

| Mode                | Base Source             | Displacement Source | Main Use                             |
| ------------------- | ----------------------- | ------------------- | ------------------------------------ |
| Base Addressing     | Base Register           | Constant            | Relocatable programs                 |
| Index Addressing    | Constant (Base Address) | Index Register      | Arrays, tables                       |
| Relative Addressing | Program Counter         | Constant            | Branching, position-independent code |



---
### **Types of Addressing Mode**

**A. Non-Computable Addressing Modes**

> Effective address is obtained without arithmetic computation

1. **Implied Mode**: Operand is <mark>**implicitly defined by opcode**</mark> (no address field required).
2. **Immediate Mode**:  itself** (constant data).
3. **Direct Mode**: <mark>Address field contains the **effective address</mark> (E.A)** of operand.
   `Operand = M[Address]`
4. **Indirect Mode**: <mark>Address field points to a memory location that contains **E.A**.</mark>
   `E.A = M[Address]`, `Operand = M[E.A]`
5. **Register Mode**: <mark>Address field specifies a **register** which contains operand.</mark>
   `Operand = R`
6. **Register Indirect Mode**: <mark>Address field specifies a register which contains **E.A** of operand.</mark>
   `E.A = R`, `Operand = M[E.A]`

**B. Computable Addressing Modes**

> Effective address is computed using arithmetic like `+` / `-`

1. **Autoincrement / Autodecrement Mode**\
   Register indirect mode where register is **automatically updated** after/before access.
   `Operand = M[R]`, then `R = R ± d`
2. **Indexed Mode**\
   Effective address = **Base address (instruction)** + **Index register**.
   `E.A = Address + IndexReg`
3. **PC-Relative Mode**\
   Effective address = **PC (next instruction address)** + **Offset (instruction)**.
   `E.A = PC + Offset`
4. **Base Register Mode**\
   Effective address = **Base register** + **Offset (instruction)**.
   `E.A = BaseReg + Offset`

***

### Displacement Addressing Modes

**`EA = Register + Displacement/Offset`**

**1. Indexed Mode ⭐**

`Effective address` = **`Base address` (from instruction)** + **`Index` (from index register)**

`E.A = Address + (IndexReg)`

* <mark>**Fixed / Not changeable:** `Address` field (Base Address)</mark>
* <mark>**Changeable:** `IndexReg` value</mark>
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
* **Use:** <mark>Branch / jump inside code segment</mark> (loops, if-else)
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
* **Use:** <mark>Segment based addressing, relocation, dynamic memory blocks, inter-segment jump</mark>
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

* Register is <mark>**IndexReg**</mark> (a normal register <mark>chosen by programmer</mark>)
* It changes because **you change it** (loop variable i)
* Purpose: **Data access pattern**
  * arrays, tables, strings

**Meaning:**\
"Base is fixed, index moves element-to-element"

**2) PC-Relative Mode**

`E.A = PC + Offset`

* Register is **PC** (not selectable)
* It <mark>changes **automatically** every instruction</mark>
* Purpose: **Control flow**
  * branch/jump target

**Meaning:**\
"Target is near current instruction"

Main benefit: **Position Independent Code (PIC)**
(load program anywhere, jumps still work)

**3) Base Register Mode**

`E.A = BaseReg + Offset`

* Register is **BaseReg** (chosen/maintained by system/program)
* It <mark>changes when **segment/region changes**</mark>
* Purpose: **Relocation / segmentation**
  * move whole block by changing base

**Meaning:**
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
