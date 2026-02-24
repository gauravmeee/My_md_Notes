---
description: Made By Me 💚
icon: dot
---

# Sequential Circuit

## **Latch**

A **Latch** is a level-triggered ==bistable circuit that stores 1 bit of data==. ==Output changes as long as the control signal (Enable) is active==.

**Key Points:**

- **Level sensitive** (transparent when enabled)
- **Basic types:**
  1. \==SR Latch==,
  2. \==D Latch==
- **Built using** ==NAND/NOR== gates

#### **1. SR Latch**

An **SR Latch** is a basic ==**bistable memory circuit**== formed using **cross-coupled NAND or NOR gates**. It stores **1 bit** of data.

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

**Inputs:**

- **S (Set)** → sets Q = 1
- **R (Reset)** → resets Q = 0

**Operations:**

1. **NOR-based SR latch (active-HIGH)**
   - S = 1 → **Set**
   - R = 1 → **Reset**
   - S = R = 0 → Hold
   - S = R = 1 → Invalid
2. **NAND-based SR latch (active-LOW)** ← _your table_
   - S = 0 → **Set**
   - R = 0 → **Reset**
   - S = R = 1 → Hold
   - S = R = 0 → Invalid

**Truth Table (Nand-Based):**

| S   | R   | Q(next) | Q′(next) | Operation |
| --- | --- | ------- | -------- | --------- |
| 1   | 1   | Q(prev) | Q′(prev) | Hold      |
| 0   | 1   | 1       | 0        | Set       |
| 1   | 0   | 0       | 1        | Reset     |
| 0   | 0   | X       | X        | Invalid   |

> **S-Set** **R-Reset**

**Key Points:**

- **Level sensitive**
- Has an **invalid condition**
- Output depends on present input + previous state
- Used as **foundation of all memory elements**

**SR Latch Significance**

- Basic ==1-bit memory element==.
- Stores data as long as power is on.
- \==Building block for flip-flops and registers==.

#### **2. D Latch** ⭐ (Better than SR Latch)

A **D Latch** is a ==modified SR latch== that ==eliminates the **invalid state**== by using a **single data input (D)**.

A **D Latch** stores the value of **D** when **Enable (E) is active**, and holds the value when **E is inactive**.

**D Latch (NAND) Diagram:**

```
            ┌───────┐
 D ───┬─────| NAND  |─────┐
      |     └───────┘     |
      |                   ▼
      |               ┌───────┐       ┌───────┐
      |        E ─────| NAND  |-------| NAND  |─── Q
      |               |       |       |       |
      |               └───────┘   ┌───|       |
      |                           |   └───────┘
      |     ┌───────┐             |
 D̅ ────┴────| NAND  |─────────────┘
            └───────┘
                         ▲
                         |
                         └──────────── Q'

```

\*\*Equations \*\*

1. **(NOR-based, active-HIGH SR core):**
   - **S = D · E**
   - **R = D̅ · E**
2. **(NAND-based, active-LOW SR core):**
   - **S̅ = (D · E)̅**
   - **R̅ = (D̅ · E)̅**

**Operation:**

1. **(NOR-based, active-HIGH SR core):**
   - **E = 1** → **Q follows D** (Transparent mode)
   - **E = 0** → **Q holds previous value**
2. **(NAND-based, active-LOW SR core):**
   - **E = 1** → **Q follows D** (Transparent mode)
   - **E = 0** → **Q holds previous value**

- \==External behavior is **identical** in both cases==
- Difference is only \*\*internal active-HIGH vs active-LOW realization

**Truth Table:**

| E   | D   | Q(next) |
| --- | --- | ------- |
| 0   | X   | Q(prev) |
| 1   | 0   | 0       |
| 1   | 1   | 1       |

> **D-Data/Delay** **E-Enable/Disable** (updating)

**Why called D:**

- **Data** → what you want to store
- **Delay** → output follows input after gate delay when enabled

**Key Points:**

- **No invalid state**
- **Level sensitive**
- More stable than SR latch
- Used in ==**registers and flip-flops**==

#### **SR vs D Latch (Why D is Better)**

| Feature       | SR Latch | D Latch |
| ------------- | -------- | ------- |
| Inputs        | S, R     | D, E    |
| Invalid State | Yes      | No      |
| Ease of use   | Low      | High    |
| Practical use | Rare     | Common  |

**Best opinion:** SR latch is **conceptual**, D latch is **practical**. Real systems almost always use **D-based storage**.

## **Flip-Flop**

A **Flip-Flop** is an **edge-triggered bistable circuit** that **==stores 1 bit of data==** and changes state only on a clock edge (rising or falling). OR A flip-flop is a ==**bistable sequential circuit** that stores **one bit (0 or 1)**==. It ==changes state on a **clock pulse**.==

**Key Points:**

- **Edge sensitive** (clock controlled)
- Types: SR, JK, D, T Flip-Flop
- Used in counters, registers, memory

**Flip-Flop Significance**

- Edge-triggered storage element.
- \==Used in counters, register==s, and sequential circuits.
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

| CLK Edge | D   | Q(next) |
| -------- | --- | ------- |
| ↑        | 0   | 0       |
| ↑        | 1   | 1       |

#### **1. SR Flip-Flop ==(Set–Reset)**==

- Inputs: S (Set), R (Reset)
- Operation
  - S=1, R=0 → Set (Q=1)
  - S=0, R=1 → Reset (Q=0)
  - S=0, R=0 → No change
  - \==S=1, R=1 → Invalid state==
- \==Limitation: Invalid input condition==

#### **2. JK Flip-Flop** ==(**J=Set** and **K=Reset**)== ⭐

- Improvement over SR flip-flop
- Inputs: J, K
- Operation
  - J=1, K=0 → Set
  - J=0, K=1 → Reset
  - J=0, K=0 → No change
  - \==J=1, K=1 → Toggle==
- \==Advantage: No invalid state==

#### **3. D Flip-Flop ==(Data / Delay)**== ⭐

- Input: D
- Output follows input on clock edge
- Operation: Q = D
- Advantage: Simple, widely used
- Application: Registers, memory elements

#### **4. T Flip-Flop ==(Toggle)**==

- Input: T
- Operation
  - \==T=0 → No change==
  - \==T=1 → Toggle==
- Application: Counters

## **Shift Register**

A **Shift Register** is a group of flip-flops connected in series, used to store and shift data bits left or right under clock control.

**Key Points:**

- \==Made using D Flip-Flops==
- Modes: SISO, SIPO, PISO, PIPO
- Used in data transfer, serialization, delay circuits

**Modes:**

- **SISO** → Serial In Serial Out
- **SIPO** → Serial In Parallel Out
- **PISO** → Parallel In Serial Out
- **PIPO** → Parallel In Parallel Out

**Shift Register Significance**

- \==Stores multiple bits and shifts them serially or in parallel==.
- Used for data transfer (serial ↔ parallel), ==temporary storage==, and time delays.
- Common in communication interfaces and digital processing.

**4-bit Serial-In Serial-Out (SISO) Diagram:**

```
 Data In → [DFF1] → [DFF2] → [DFF3] → [DFF4] → Data Out
             ↑        ↑         ↑       ↑
            CLK      CLK       CLK     CLK
```

**Summary Table:**

| Device         | Bits Stored | Triggering   | Use Case                 |
| -------------- | ----------- | ------------ | ------------------------ |
| Latch          | 1           | Level        | Simple data storage      |
| Flip-Flop      | 1           | Edge         | Registers, counters      |
| Shift Register | n           | Edge (Clock) | Data shift, storage, I/O |
