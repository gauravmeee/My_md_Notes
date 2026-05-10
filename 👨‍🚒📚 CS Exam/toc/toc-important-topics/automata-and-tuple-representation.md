---
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
# Automata and tuple representations.

Writing Order of 4 types of tuples: -> `Sets → Functions → States -> Symbol -> Subset`

### \*\*1. DFA

**Purpose:** Accept/reject strings over an input alphabet.

**Tuple Format:**

* **`M = (Q, Σ, δ, q₀, F)`**

| Component | Meaning                 | Type                  |
| --------- | ----------------------- | --------------------- |
| Q         | Finite set of states    | Set (States)          |
| Σ         | Input alphabet          | Set (Input Alphabets) |
| δ         | Transition function     | Function: Q × Σ → Q   |
| q₀        | Initial state           | State: q₀ ∈ Q         |
| F         | Set of accepting states | Subset (State): F ⊆ Q |

**`5` Tuples:**\
→ 2 Sets: `Q`, `Σ`\
→ 1 Function: `δ`\
→ 1 States: `q₀` → 1 Subset: `F`

### **2. NFA**

**Tuple Format:**

* **`M = (Q, Σ, δ, q₀, F)`** → **Same as DFA**, but:

| Component | Change                                |
| --------- | ------------------------------------- |
| δ         | Q × (Σ ∪ {ε}) → 𝒫(Q) (**power set**) |

**Changes Compared to DFA:** **`5` Tuples** (Same count)\
→ Only **transition function δ** changes to allow:

* Multiple transitions (nondeterminism)
* ε-transitions (empty string moves)

### **3. Mealy Machine**

**Purpose:** Produce ==**output** for each input & State== **on transitions**.

**Tuple Format:**

* **`M = (Q, Σ, Δ, δ, λ, q₀)`**

| Component | Meaning              | Type                   |
| --------- | -------------------- | ---------------------- |
| Q         | Finite set of states | Set (States)           |
| Σ         | Input alphabet       | Set (Input Alphabets)  |
| **Δ**     | **Output alphabet**  | Set (Output Alphabets) |
| δ         | Transition function  | Function: Q × Σ → Q    |
| **λ**     | **Output function**  | Function: Q × Σ → Δ    |
| q₀        | Initial state        | State: q₀ ∈ Q          |

**Changes Compared to DFA:** **`6` Tuples** (**+1**) → 3 Sets: `Q`, `Σ`, **`Δ`** _(+1)_\
→ 2 Functions: `δ`, **`λ`** _(+1)_\
→ 1 State: `q₀`\
→ ❌ No Subset `F` (No final state – Mealy transduces, doesn't accept)

### **4. Moore Machine**

**Purpose:** Produce ==**output based only on states**==.

**Tuple Format:**

* **`M = (Q, Σ, Δ, δ, λ, q₀)`**

| Component | λ (Output Function) |
| --------- | ------------------- |
| Moore     | λ: Q → Δ            |

**Changes Compared to DFA:** **`6` Tuples** (**+1**) → 3 Sets: `Q`, `Σ`, **`Δ`** _(+1)_\
→ 2 Functions: `δ`, **`λ`** _(+1)_\
→ 1 State: `q₀`\
→ ❌ No Subset `F` (No final state – Moore also transduces)

### **5. PDA (Pushdown Automaton)**

**Purpose:** Accept context-free languages using a **stack**.

**Tuple Format:**

* **`M = (Q, Σ, Γ, δ, q₀, Z₀, F)`**

| Component | Meaning                  | Type                                      |
| --------- | ------------------------ | ----------------------------------------- |
| Q         | States                   | Set (State)                               |
| Σ         | Input alphabet           | Set (Alphabet)                            |
| **Γ**     | **Stack alphabet**       | Set (Alphabet)                            |
| δ         | Transition function      | Function: Q × (Σ ∪ {ε}) × Γ → 𝒫(Q × Γ\*) |
| q₀        | Initial state            | State                                     |
| **Z₀**    | **Initial stack symbol** | Symbol ∈ Γ                                |
| F         | Accepting states         | Subset(State) ⊆ Q                         |

**Changes Compared to DFA:** **`7` Tuples** (**+2**)\
→ 3 Sets: `Q`, `Σ`, **`Γ`** _(+1)_\
→ 1 Complex Function: `δ` using stack\
→ 2 States: `q₀` → 1 Symbol: **`Z₀`** _(+1)_ (initial stack symbol) → 1 Subset`F`

### **6. Turing Machine (TM)**

**Purpose:** Model general computation using a **tape**.

**Tuple Format:**

* **`M = (Q, Σ, Γ, δ, q₀, □, F)`**

| Component | Meaning                      | Type                             |
| --------- | ---------------------------- | -------------------------------- |
| Q         | Set of states                | Set (State)                      |
| Σ         | Input alphabet (subset of Γ) | Set (Alphabet)                   |
| **Γ**     | Tape alphabet                | Set (includes blank symbol `□`)  |
| δ         | Transition function          | Function: Q × Γ → Q × Γ × {L, R} |
| q₀        | Initial state                | State                            |
| **□**     | **Blank symbol** (not in Σ)  | Symbol                           |
| F         | Accepting states             | Subset (State) ⊆ Q               |

**Changes Compared to DFA:** **`7` Tuples** (**+2**)\
→ 3 Sets: `Q`, `Σ`, **`Γ`** _(+1)_\
→ 1 Function: `δ` includes read, write, move\
→ 2 States: `q₀` → 1 Symbol: **`□`** _(+1)_ (blank symbol) → 1 Subset`F`

Summary Table

| Machine   | Tuple Components                    | Key Additions                    | Notes                           |
| --------- | ----------------------------------- | -------------------------------- | ------------------------------- |
| **DFA**   | (Q, Σ, δ, q₀, **F**)                | –                                | Base model                      |
| **NFA**   | (Q, Σ, δ, q₀, **F**)                | Modified δ                       | Allows nondeterminism & ε-moves |
| **Mealy** | (Q, Σ, **Δ**, δ, **λ**, q₀)         | +Δ, +λ (Q×Σ→Δ) , - F             | Output on transitions           |
| **Moore** | (Q, Σ, **Δ**, δ, **λ**, q₀)         | +Δ, +λ (Q→Δ), - F                | Output on states                |
| **PDA**   | (Q, Σ, **Γ**, δ, q₀, **Z₀**, **F**) | +Γ (stack), +Z₀                  | Stack-based (CFG recognition)   |
| **TM**    | (Q, Σ, **Γ**, δ, q₀, **□**, **F**)  | +Γ (tape), +□ (blank), +movement | General computation model       |
