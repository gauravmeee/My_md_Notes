
# Grammar

### **Types of Grammar**

```
Grammar                            Language  Automata
------------------------------------------------------------------
Regular Grammar(RG) ->                RL ->  Finite Automata (FA)
Context-Free Grammar(CFG) ->          CFL -> Push-down Automata (PDA)
Context-Sensitive Grammar(CSG) ->     CSL -> Linear Bounded Automata (LBA)
Recursively Enumerable Grammar(REG)-> REL -> Turing Machine (TM)
```

##### **Chomsky Hierarchy** ⭐

| **Type** | **Name**                  | **Production Form**                                       | **Language Class**     | **Accepted By**          |
| -------- | ------------------------- | --------------------------------------------------------- | ---------------------- | ------------------------ |
| Type 0   | Unrestricted Grammar      | ==`α → β`== (α ≠ ε)                                       | Recursively Enumerable | Turing Machine           |
| Type 1   | Context-Sensitive Grammar | ==`αAβ → αγβ`== (γ ≠ ε)                                   | Context-Sensitive      | Linear Bounded Automaton |
| Type 2   | Context-Free Grammar      | ==`A → γ`== (A ∈ V, γ ∈ (V ∪ T) * )                       | Context-Free           | Pushdown Automaton       |
| Type 3   | Regular Grammar           | ==`A → aB`== or ==`A → a`== (Right-linear or Left-linear) | Regular                | Finite Automaton         |

These types form a hierarchy:  ⭐
```
Type 3 ⊂ Type 2 ⊂ Type 1 ⊂ Type 0
```

##### **Monotonic Grammar

A **monotonic grammar** is a type of formal grammar where:

> For every production rule `α → β`,  
> it must satisfy: `|α| ≤ |β|`  
> i.e., the ==length of the right-hand side is **greater than or equal to** the left-hand side.==

Also known as: ==**Non-contracting Grammar**==


**Example Rule**
- ✅ Allowed: `AB → ABC` (`2 ≤ 3`)
- ❌ Not Allowed: `AB → A` (`2 > 1`)
    
**Key Properties**

| Property                | Description                                                   |
| ----------------------- | ------------------------------------------------------------- |
| **Non-contracting**     | No rule reduces string length (`                              |
| **Includes CSG**        | All **Context-Sensitive Grammars (Type 1)** are monotonic     |
| **Subset of Type 0**    | All monotonic grammars are **Type 0 (Unrestricted)**          |
| **Superset of  Type 1** | Some monotonic grammars are **not** context-sensitive         |
| ==**ε-productions**==   | Generally ==**not allowed**==, unless the language includes ε |
| **Language Generated**  | Always ==**recursively enumerable==**                         |

**Relation to Chomsky Hierarchy**

| Grammar Type                   | Rule Format       | Language Class         |
| ------------------------------ | ----------------- | ---------------------- |
| **Type 0** (Unrestricted)      | `α → β`           | Recursively Enumerable |
| **Monotonic Grammar**          | `α → β` with `    | α                      |
| **Type 1** (Context-Sensitive) | `αAβ → αγβ` and ` | αAβ                    |


**Important Points for PSU Exams**
- ✔ **Monotonic Grammar ⊆ Type 0**
- ✔ **Type 1 Grammar ⊆ Monotonic Grammar**
- ✔ Used in modeling **non-shrinking** computations
- ✔ Acceptable by **non-deterministic Turing Machine**


---
---

# Automata

### **Linear Bounded Automaton (LBA)**

- **Definition**:  
    An ==**LBA** is a **non-deterministic Turing Machine**== where the tape head is restricted to a portion of the tape bounded by a linear function of the input length.  
    (i.e., `Tape size ≤ c·n`, where `_n_` is input length, and `_c_` is a constant)
    

**Key Points:**

- **LBA ≠ Deterministic TM**  
    → An ==LBA may be **non-deterministic**==, though **deterministic LBA** (DLBA) also exists.  
    → Hence, LBA is **not always deterministic**.
    
- **LBA accepts Context-Sensitive Languages (CSL)**  
    → The class of languages accepted by ==LBA is **exactly equal** to **Context-Sensitive Languages**.==
    
- **Every LBA language is Context-Sensitive**  
    → True by definition.  
    → So, **every** language accepted by LBA **must** be **context-sensitive**.
    

---

### **Mealy and Moore Machines**


##### **1. Mealy Machine**

**Definition:** 
A **Mealy Machine** is a finite state machine where ==**output depends on both current state and input**.==

**Formal Definition:**
A Mealy machine is a ==6-tuple==:  
**`M = (Q, Σ, Δ, δ, λ, q₀)`**   (No final State `F`)
Where:

- `Q`: finite set of states    
- `Σ`: input alphabet
- ==`Δ`==: output alphabet
- `δ`: Q × Σ → Q (transition function)
- ==`λ`==: Q × Σ → Δ (output function)
- `q₀`: initial state

In Mealy machines, **output is written on transitions**:
```
        a/x
    q0 -----> q1
```

- On input `a`, move from `q0` to `q1`, output `x`.
    

##### **2. Moore Machine**

**Definition:** 
A **Moore Machine** is a finite state machine where **==output depends only on the current state**==.

**Formal Definition:**
A Moore machine is a 6-tuple:  
**`M = (Q, Σ, Δ, δ, λ, q₀)`**
Where:

- Q: finite set of states
- Σ: input alphabet
- Δ: output alphabet
- δ: Q × Σ → Q (transition function)
- λ: Q → Δ (output function)
- q₀: initial state
    
In Moore machines, **output is written inside the state**:
```
       [q1|x]
    q0 --------> q1
        a
```
- In state `q1`, output `x` regardless of input.
    

**Key Differences:**

| Feature        | **Mealy Machine**           | **Moore Machine**    |
| -------------- | --------------------------- | -------------------- |
| Output depends | State and Input             | Only State           |
| Output timing  | On transitions              | On entering state    |
| Generally      | More compact (fewer states) | Simpler conceptually |
| Diagram style  | Output on edges             | Output inside states |


**Are Mealy and Moore machines DFA?** ?
- ❌ **No**, Mealy and Moore machines are **not DFA**.
- DFA (Deterministic Finite Automaton) is used **only for language acceptance** (decides whether a string is accepted).
- Mealy and Moore machines are used for **transducing** (producing **output** for each input).
    
**Are Mealy and Moore machines finite automata?**
- ✅ **Yes**, both are types of **Finite State Machines (FSM)**.
- They are **finite automata with outputs**.
- DFA = FSM without output
- Mealy/Moore = FSM **with output**
