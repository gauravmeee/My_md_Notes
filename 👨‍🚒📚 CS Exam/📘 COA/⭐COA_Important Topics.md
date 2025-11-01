
###  Memory Chip Organization and Interleaving


**1. Understanding Chip Specifications**

- Format: ⭐$$CapacityOfChip = (\text{Number of Words}) × (\text{Word Size in bits})$$ 
    - Example: **64K × 1** = 64K words, each word is 1 bit wide → 64K bits total.
    - Example: **512K × 8** = 512K words, each word is 8 bits wide (1 byte) → 512K×8512K  times 8 bits total.


**2. Converting to Bytes and Bits**
- **Bits to Bytes:** Divide by 8.
- **Bytes to Bits:** Multiply by 8.
    

**3. Calculating Number of Chips Needed**  
Formula:

$$Number of chips= \frac{\text{Required capacity in bits}}{\text{Capacity per chip in bits}}$$

Example:
- Required: 512K × 8 bits = 4096K bits.
- Per chip: 64K × 1 bit = 64K bits.
- Chips needed= 4096K / 64K = 64


**4. Organization for Required Word Width**

- To get **8-bit word width** from 1-bit chips, group **8 chips** in parallel (same address lines, separate data lines).
- To get the total memory size, stack enough such groups.
    
Example for 512K × 8 using 64K × 1 chips:
- First, 8 chips in parallel → 64K × 8.
- Required 512K × 8 → 512K / 64K = 8 such groups.
- Total chips = 8 chips/group×8 groups = 64 chips


Here’s the **full PSU-style notes** on **All Common Addressing Modes** (not just the 4 you mentioned):

---

Here’s a compact but complete **PSW & Flags** note for PSU exams:

---

## **Program Status Word (PSW)**

- A special CPU register ==holding **status information** and **control bits**==.
- Updated automatically after most instructions.
- Used by CPU to determine conditional operations, branching, and interrupts.
    

**Contents of PSW**

1. **Status Flags (Condition Codes)** – Reflect result of last ALU operation:
    - **CF (Carry Flag)** → 1 if carry out (unsigned overflow) or borrow occurs.
    - **ZF (Zero Flag)** → 1 if result is 0.
    - **SF (Sign Flag)** → Copies MSB of result (1 = negative in signed representation).
    - **OF (Overflow Flag)** → 1 if signed overflow occurs.
    - **PF (Parity Flag)** → 1 if result has even parity (even no. of 1s).
    - **AC (Auxiliary Carry)** → Carry from bit 3 to bit 4 (used in BCD).
        
2. **Control Bits** – Control processor operation:
    - **Interrupt Enable/Disable** → Allows or blocks interrupts.
    - **Mode bits** → User mode / Supervisor mode.
    - **Trap Flag** → Enables single-step execution for debugging.
        
**Example:** After `ADD AL, BL` in x86:
- ZF = 1 if AL = 0.
- CF = 1 if unsigned carry occurs.
- OF = 1 if signed overflow occurs.
    
**Uses of PSW**
- **Conditional branching** (`JZ`, `JC`, `JNE`, etc.).
- **Exception handling & interrupts**.
- **Debugging & single-step execution**.

---
### Addressing Modes

**Definition:** Addressing mode specifies **how to interpret the operand** in an instruction (where the operand is located or how to get it).


1. **Immediate Addressing Mode** ⭐
	- ==**Operand**== is given directly in the instruction.
	- **Advantage:** Fast, no memory access for operand.
	- **Application:** Constants.
	- **Example:** `MOV A, #5` → Load 5 into A.

2. **Direct (Absolute) Addressing Mode** ⭐
	- *==*Address field**== contains the actual memory address of the operand.
	- **Application:** Access fixed memory location.
	- **Example:** `MOV A, 2000H` → Load from memory 2000H.

3. **Indirect Addressing Mode** ⭐
	- Address field contains a register/memory location holding the **effective address** of the operand.
	- **Application:** ==Pointers==, linked lists.
	- **Example:** `MOV A, @R0` → Effective address from R0.

4. **Register Addressing Mode**
	- Operand is in a **CPU register**.
	- **Application:** Very fast access.
	- **Example:** `MOV A, R1`.

5. **Register Indirect Addressing Mode**
	- Register contains the address of operand in memory.
	- **Application:** Table lookups.
	- **Example:** `MOV A, @R2`.

6. **Base Addressing Mode** ⭐
	- **Effective Address (EA)** = Base Register + Displacement.
	- **Application:** ==Relocatable programs.==    
	- **Example:** `MOV A, 1000(RB)`.

7. **Index Addressing Mode** ⭐
	- **EA** = Index Register + Base Address.
	- **Application:** Arrays.
	- **Example:** `MOV A, ARR(RI)`.

8. **Relative Addressing Mode** ⭐
	- **EA** = Program Counter (PC) + Displacement.
	- **Application:** Branching instructions.
	- **Example:** `BEQ LABEL`.
    

9. **Autoincrement / Autodecrement Addressing**
	- Register points to operand and is **incremented/decremented automatically** after/before use.
	- **Application:** Stack operations, sequential data.
	- **Example:** `MOV A, (R1)+`.
    

**Quick Match for PSU-type Questions:**

- Immediate → Constants
- Direct → Fixed data
- Indirect → Pointers
- Register → Fast data access
- Base → Relocatable programs
- Index → Arrays
- Relative → Branching
- Auto inc/dec → Stack or sequential access

**Difference between Base, Index, and Relative Addressing Modes.**

1. **Base Addressing**
	- **Base** → relocation flexibility.   
    - _Base_ comes from a ==**base register** that can be changed at runtime.==
    - Useful for **relocatable programs**: move the whole program in memory, just update the base register.
    - Example: OS loads a process at a new memory location without changing its instructions.
        
2. **Index Addressing**
	- **Index** → array element access.
    - _Base_ is a **constant** in the instruction (start of an array), ==_displacement_ is an **index register** that changes.==
    - Perfect for **arrays/tables**: just increment the index register to access the next element.
    - Example: Loop accessing array elements sequentially.
        
3. **Relative Addressing**
	- **Relative** → branching within a short distance.
    - _Base_ is the **PC**, ==_displacement_ is a constant offset in instruction.==
    - Used for **branching/jumps**: target is always relative to the current instruction, making code **position-independent**.
    - Example: `BEQ LABEL` works even if program is loaded at a different address.


| Mode                | Base Source             | Displacement Source | Main Use                             |
| ------------------- | ----------------------- | ------------------- | ------------------------------------ |
| Base Addressing     | Base Register           | Constant            | Relocatable programs                 |
| Index Addressing    | Constant (Base Address) | Index Register      | Arrays, tables                       |
| Relative Addressing | Program Counter         | Constant            | Branching, position-independent code |

    
---

# Sequential Logic Circuits

### Latch & Flip Flop

- **Latch** - Basic 1-bit storage element (level-triggered). changes output as long as enable is active
- **Flip-Flop** - Built from latches, 1-bit storage (edge-triggered). changes output only on clock edge
- **Shift Register** - Sequential circuit made from multiple flip-flops connected in series, used to store and shift data bit-by-bit.
- Flip-flops are built **using latches** (typically two latches in master–slave configuration).

##### **Types of Latch**

**1. SR Latch (Set-Reset)**
- **Inputs:** S (Set), R (Reset)
- **Operation:**
    - `S=1, R=0` → `Q=1` (Set)
    - `S=0, R=1` → `Q=0` (Reset)
    - `S=0, R=0` → `Q` holds value
    - `S=1, R=1` → Invalid state in basic form
- **Diagram:**
```
 S ──┐        ┌── Q
     │        │
    NOR────┐  │
     ▲     │  │
     │    NOR─┘
     │     ▲
     └─────R
```

**2. Gated SR Latch**
- **Inputs:** S, R, Enable (E)
- **Operation:**
    - Works like SR latch but changes output **only when E=1**.
    -  E=0 → output holds.
- **Diagram:**
```
 S ─┐AND      ┌── Q
 E ─┘         │
              │
             NOR────┐
              ▲     │
 R ─┐AND      │    NOR─┘
 E ─┘         │     ▲
              └─────┘
```

**3. D Latch (Data / Transparent Latch)** 
- **Inputs:** D, Enable (E)
- **Operation:**
    - `E=1` → `Q` follows `D`.
    - `E=0` → `Q` holds previous value.
    - Built from SR latch with gating to avoid invalid state.
- **Diagram:**
```
 D ─┐         ┌── S
    │AND      │
 E ─┘         │
              │
             SR Latch → Q
  D'─┐AND     │
 E ──┘        └── R
```

**4. JK Latch** 
- **Inputs:** J, K, Enable (E)
- **Operation:**
    - `J=1, K=0` → Set
    - `J=0, K=1` → Reset
    - `J=0, K=0` → Hold
    - `J=1, K=1` → Toggle
    - Level-sensitive (changes when `E=1`)
- **Diagram (conceptual):**
```
 J, K + E → Logic → SR Latch → Q
```

**5. T Latch (Toggle)**
- **Inputs:** T, Enable (E)
- **Operation:**
    - `T=1, E=1` → Toggle `Q`
    - `T=0 or E=0` → Hold `Q`     
    - Often built from JK latch with `J=K=T`.
- **Diagram:**
```
 T + E → XOR with Q → SR/D Latch → Q
```


##### **Types of Flip-Flop** ⭐

**1. SR Flip-Flop (Set-Reset)**
- **Inputs:** S (Set), R (Reset)
- **Operation:**
    - **`S=1, R=0` → `Q=1` (set)**
    - **`S=0, R=1` → `Q=0` (reset)**
    - **`S=0, R=0` → `Q` holds previous value**
    - **`S=1, R=1` → Invalid (in basic form)**
- **Diagram:**
```
   S ───┐
        │
      ┌─┴─┐
      │   │
      │   ├── Q
      │   │
      └─┬─┘
        │
   R ───┘
```


**2. JK Flip-Flop**
- **Inputs:** J, K
- **Operation:**
    - **J=1, K=0 → Set Q=1**
    - **J=0, K=1 → Reset Q=0**
    - **J=0, K=0 → Q holds**
    - **J=1, K=1 → Q toggles each clock**
- **Advantage:**  Just removes **SR** invalid state. ( Rest Same as **SR** )⭐
- **Diagram:**
```
   J ───┐
        │
      ┌─┴─┐
CLK──>│   │── Q
      │   │
   K ─┴───┘
```


**3. D Flip-Flop (Data/Delay)**
- **Input:** D    
- **Operation:**
    - **On clock edge, `Q` takes the value of `D`.**
    - **Eliminates ambiguity of SR and JK.**
- **Use:** Data storage and synchronization.
- **Diagram:**
```
   D ─────┐
          │
      ┌───┴───┐
CLK──>│       │── Q
      └───────┘
```


**4. T Flip-Flop (Toggle)**
- **Input:** T
- **Operation:**
    - **`T=0` → `Q` holds value**
    - **`T=1` → `Q` toggles on each clock**
- **Use:** Counters, frequency division.
- **Diagram:**
```
   T ─────┐
          │
      ┌───┴───┐
CLK──>│       │── Q
      └───────┘
```


---



##### **Write Through & Write Back** ⭐

**Definitions**

- **Write Through:** Every write operation ==updates both the cache (if present) and the main memory.==
- **Write Back:** Write operations ==update only the cache==; the main memory is updated later when the block is replaced (if dirty).
- **Write Allocate:** On a write miss, the block is first loaded into cache, then written into.
- **No-write Allocate:** On a write miss, data is written directly to memory without loading the block into cache.
    


**1. Write Through (No-write Allocate)**

- **Read**
    - **Hit:** Take directly from cache.        
    - **Miss:** Read from memory and place the block into cache.
        
- **Write**
    
    - **Hit:** ==Write in both cache and main memory== **(Write Through)**.
    - **Miss:** ==Write directly to main memory== without bringing the block into cache **(No-write Allocate)**.


**2. Write Back (Write Allocate)**

- **Read**    
    - **Hit:** Take directly from cache.
    - **Miss:** Read from memory; if the block being replaced is dirty, write it back to memory before replacement.
        
- **Write**
    - **Hit:** ==Write in cache and set **Dirty bit = 1**== **(Write Back)**.
    - **Miss:** ==Bring block from main memory into cache, then update it in cache== **(Write Allocate)**.