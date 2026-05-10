# Program Status Word (PWS)


* A special CPU register <mark>holding **status information** and **control bits**</mark>.
* Updated automatically after most instructions.
* Used by CPU to determine conditional operations, branching, and interrupts.

**Contents of PSW**

1. **Status Flags (Condition Codes)** – Reflect result of last ALU operation:
   * **CF (Carry Flag)** → 1 if carry out (unsigned overflow) or borrow occurs.
   * **ZF (Zero Flag)** → 1 if result is 0.
   * **SF (Sign Flag)** → Copies MSB of result (1 = negative in signed representation).
   * **OF (Overflow Flag)** → 1 if signed overflow occurs.
   * **PF (Parity Flag)** → 1 if result has even parity (even no. of 1s).
   * **AC (Auxiliary Carry)** → Carry from bit 3 to bit 4 (used in BCD).
2. **Control Bits** – Control processor operation:
   * **Interrupt Enable/Disable** → Allows or blocks interrupts.
   * **Mode bits** → User mode / Supervisor mode.
   * **Trap Flag** → Enables single-step execution for debugging.

**Example:** After `ADD AL, BL` in x86:

* ZF = 1 if AL = 0.
* CF = 1 if unsigned carry occurs.
* OF = 1 if signed overflow occurs.

**Uses of PSW**

* **Conditional branching** (`JZ`, `JC`, `JNE`, etc.).
* **Exception handling & interrupts**.
* **Debugging & single-step execution**.