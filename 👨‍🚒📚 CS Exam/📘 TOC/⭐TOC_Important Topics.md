

# 1. Language

##### **Basic of Formal Language**

**Examples:**

**Ques:** Total no. of substrings possible for `w = GATE`
```
length:      0      1          2           3          4
substrings:  ϵ    G,A,T,E    GA,AT,TE    GAT,ATE     GATE
no. of subs: 1 +    4     +    3    +      2   +      1   = 4(4+1)/2 + 1
```
`ϵ` = null

Total no. of Substrings Formula : `n(n+1)/2+1` , `n=size of string`
Total no. of Non-trivial (not include `ϵ`) substring : `n(n+1)/2`

**Ques :** Find the no. of prefix and suffix possible in `GATE`, where `|w|=n`
prefix:- { ϵ, G, GA, GAT, GATE} `n+1`
prefix:- { ϵ, E, TE, ATE, GATE} `n+1`

### Closure Properties

**Closure under an operation** means:  **If you apply that operation to languages of a particular class, the result will still belong to the same class.**
// OR
A language class is **closed under an operation** if applying that operation to languages in the class always yields a language that is also in the class.

##### **1. Regular languages are closed under the following operations:**

| Operation                | Meaning                                                       | Closed? | Notes                                                                                                                            |
| ------------------------ | ------------------------------------------------------------- | ------- | -------------------------------------------------------------------------------------------------------------------------------- |
| **Union**                | L₁ ∪ L₂ = strings in L₁ or L₂                                 | ✅ Yes   | Constructed using NFA or regex: R₁ + R₂                                                                                          |
| **Concatenation**        | L₁L₂ = strings formed by concatenating strings from L₁ and L₂ | ✅ Yes   | DFA/NFA can simulate                                                                                                             |
| **Kleene Star**          | L* = zero or more repetitions of strings in L                 | ✅ Yes   | Defined using NFA with ε-transitions                                                                                             |
| **Intersection**         | L₁ ∩ L₂                                                       | ✅ Yes   | DFA can be built using product construction                                                                                      |
| **Complement**           | Σ* − L                                                        | ✅ Yes   | Flip final/non-final states in DFA                                                                                               |
| **Difference**           | L₁ − L₂                                                       | ✅ Yes   | Use: L₁ − L₂ = L₁ ∩ (¬L₂)                                                                                                        |
| **Reversal**             | Lᴿ = reverse of all strings in L                              | ✅ Yes   | NFA with reversed transitions                                                                                                    |
| **Substitution**         | Replace symbols by regular languages                          | ✅ Yes   | Preserves regularity                                                                                                             |
| **Homomorphism**         | h(L): map each symbol to a string                             | ✅ Yes   | Still regular                                                                                                                    |
| **Inverse Homomorphism** | h⁻¹(L): pull back by symbol mappings                          | ✅ Yes   | Still regular                                                                                                                    |
| **Quotient (Right)**     | L₁ / L₂ = { x \| ∃ y ∈ L₂ such that xy ∈ L₁ }                 | ✅ Yes   | Removes **suffix** from strings in L₁.<br><br>Checks if adding **some string from L₂** to `x` results in a string in L₁.         |
| **Left Quotient**        | L₂ \ L₁ = { y \| ∃ x ∈ L₂ such that xy ∈ L₁ }                 | ✅ Yes   | Removes **prefix** from strings in L₁.<br><br>Checks if adding **some string from L₂** **before `y`** results in a string in L₁. |

##### **2. Closure Properties of Context-Free Languages (CFLs):** ⭐


- **CFL and DCFL**:  
    Follow → **Inverse Homomorphism**, **Regular ∩ CFL**   ✅
    Not Follow → **Intersection** ❌
    
- **DCFL (in Comparison of CFL)**:  
    Follow → **Complement** (extra over CFL)   ✅
    Not Follow → **Rest All** ❌
    
- **CFL (in Comparison of DCFL)**:  
    Follow → **All Except**  ✅
    Not Follow  → **Complement**   ❌

| **Operation**            | **CFL (Non-Det.) Closed?** | **DCFL Closed?** | **Reason / Explanation**                                                                                                                                      |
| ------------------------ | -------------------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Union**                | ✅ Yes                      | ❌ No             | CFLs can be unioned by using nondeterminism in PDA. DCFLs can't use nondeterminism, so union may lead to ambiguity.                                           |
| **Intersection**         | ❌ No                       | ❌ No             | CFL ∩ CFL may not be CFL (e.g., `{aⁿbⁿcⁿ}` ∉ CFL). DCFL also not closed because deterministic machines can't track multiple conditions simultaneously.        |
| **Complement**           | ❌ No                       | ✅ Yes            | CFL not closed: If it were, then CFL would also be closed under intersection (contradiction via De Morgan’s Law). DCFL is closed due to deterministic nature. |
| **Regular ∩ CFL**        | ✅ Yes                      | ✅ Yes            | Intersection with a **regular language** is always CFL or DCFL, since regular part can be simulated without increasing complexity.                            |
| **Concatenation**        | ✅ Yes                      | ❌ No             | CFL is closed using nondeterminism. DCFL is not closed as deterministic PDA can't deterministically concatenate in general.                                   |
| **Kleene Star**          | ✅ Yes                      | ❌ No             | CFL supports repetition via ε-transitions in NPDA. DCFL does not handle unbounded nondeterminism.                                                             |
| **Reversal**             | ✅ Yes                      | ❌ No             | CFLs can be reversed by modifying the PDA. For DCFL, reversal may introduce nondeterminism, hence not closed.                                                 |
| **Substitution**         | ✅ Yes                      | ❌ No             | CFL supports substitution (using PDA construction). DCFL does not, due to deterministic restrictions.                                                         |
| **Homomorphism**         | ✅ Yes                      | ❌ No             | CFLs are closed, but DCFLs are not—homomorphism may break determinism.                                                                                        |
| **Inverse Homomorphism** | ✅ Yes                      | ✅ Yes            | Both closed; input symbol pre-image mapping preserves structure.                                                                                              |

> **Note:** Unlike other language classes, **Deterministic Context-Free Languages (DCFL)** form a **strict subset** of **Context-Free Languages (CFL)**. Therefore, **DCFLs do not share all closure properties of CFLs**, and must be treated separately.


---
### Language Classes - Deterministic vs Non-Deterministic ⭐

| **Language Class**                     | **Non-Deterministic Form**                     | **Deterministic Form**          | Relationship                                                                          |
| -------------------------------------- | ---------------------------------------------- | ------------------------------- | ------------------------------------------------------------------------------------- |
| **Regular Languages (RL)**             | NFA (Non-Deterministic FA)                     | DFA (Deterministic FA)          | Deterministic = Non-<br>Deterministic<br><br>both define same RL set                  |
| **Context-Free Languages (CFL)**       | NPDA (Non-Deterministic PDA)                   | DPDA (Deterministic PDA)        | Deterministic ⊂ Non-Deterministic<br><br>(strict subset)                              |
| **Context-Sensitive Languages**        | Non-deterministic LBA                          | Deterministic LBA (rarely used) | Unclear <br>(generally assumed equal)                                                 |
| **Recursive Languages** <br>(⭐ Extra ) | Non-deterministic TM ~ (Linear Bound Automata) | Deterministic TM                | Deterministic = Non-Deterministic<br><br>Both accept same class (decidable languages) |
| **Recursively Enumerable (RE)**        | Non-deterministic TM ~ (Linear Bound Automata) | Deterministic TM                | Deterministic = Non-Deterministic<br><br>Equivalent in power (semi-decidable)         |

**Important Notes:**

- **Regular Languages**:  
    Always deterministic → NFA ≡ DFA.
    
- **Context-Free Languages (CFL)**:
    - Recognized by **NPDA**
    - **Subset of CFL** can be recognized by **DPDA** → called **DCFL (Deterministic CFL)**

    - Example:
        - `{ aⁿbⁿ | n ≥ 0 }` → in **DCFL**
        - `{ aⁿbⁿcⁿ | n ≥ 0 }` → **not** in CFL at all
        - `{ ww | w ∈ Σ* }` → CFL but **not DCFL**
            
- **Context-Sensitive Languages**:  
    Typically handled by **Linear Bounded Automaton (LBA)**. Deterministic vs non-deterministic distinction exists, but is not widely explored.
    
- **Recursive** and **Recursively Enumerable (RE)** languages:  
    Both can be defined using **Turing Machines**. Every recursive language is **decidable**, and RE languages are **semi-decidable**.

```
Regular ⊆ DCFL ⊆ CFL ⊂ CSL ⊂ RE
        ⬑     ⬑
        DFA    DPDA
         ↑      ↑
        NFA    NPDA
```


---

### Different Language Acceptability


##### **1. Languages Accepted by Turing Machine (Type 0)**

These are called **Recursively Enumerable (RE)** languages.

**Definition:** A **Turing Machine (TM)** accepts **all languages that are computably enumerable**, i.e.,
- There exists a TM that will **accept** any string in the language    
- It **may or may not halt** for strings not in the language
    
**Key Characteristics:**

- Grammar: **Unrestricted Grammar**
- Rules: Productions of the form `α → β`, where `α, β ∈ (V ∪ T)*` and `α ≠ ε`
- Most powerful class of languages
- Includes all **Type 1, 2, 3** languages
- Turing Machines can simulate **any computation**

**Not Accepted:**
Turing Machines do **not** accept:
- **Non-computable languages**, i.e., languages for which no TM exists at all
- **Undecidable** languages can't be fully solved (TM might not halt), but they are **still RE**

**Examples of Turing-Acceptable Languages:**

1. `L = { a^n b^n c^n | n ≥ 1 }`
2. `L = { ww | w ∈ {a, b}* }`
3. `L = { palindromes over {a, b} }`
4. `L = { M | M is a valid C++ program that prints "yes" }`
5. `L = { ⟨M, w⟩ | Turing machine M accepts input w }`
6. Any language that requires **multiple stacks or tapes**
7. Any language describing **complex patterns**, e.g., nested loops, programming logic
8. Any language accepted by:
    - **Finite Automata** (Type 3)
    - **Pushdown Automata** (Type 2)
    - **Linear Bounded Automata** (Type 1)
        

**Examples of Not Turing-Acceptable Languages:**
- `L = { ⟨M⟩ | M does not halt on input ⟨M⟩ }` → **Diagonalization language** (non-RE)

**Conclusion:**
- **Turing Machines accept the broadest class of languages**, including **all formal languages you can describe by any algorithm**.

Here is the complete note in **same format** as above, for **Context-Sensitive Grammar (CSG) / Type 1**:


##### **2. Languages Accepted by Linear Bounded Automata (Type 1 / CSG)**

These are called **Context-Sensitive Languages (CSLs)**.

**Definition:** A **Context-Sensitive Grammar (CSG)** accepts languages where:

- Production rules are of the form: `αAβ → αγβ`, where `|γ| ≥ 1`
- Length of the string **does not decrease** in any derivation step
- Grammar is **non-contracting** (except `S → ε` if ε is in the language)

**Key Characteristics:**

- Grammar: **Context-Sensitive Grammar**
- Machine: **Linear Bounded Automaton (LBA)**
- Memory: **Finite tape bounded by input size**
- More powerful than PDA, but less powerful than TM
- Can handle **multiple dependencies**    
- Includes all **regular** and **context-free** languages

**Not Accepted by CSG:**
- Context-sensitive grammars **cannot accept**:
	- Languages that are **not recursively enumerable**    
	- Languages requiring **unbounded non-linear memory**
	- Languages with **undecidable or non-computable structure**

**Examples of CSG-Acceptable Languages:** ✅
1. `L = { a^n b^n c^n | n ≥ 1 }`
2. `L = { a^n b^m c^n | n, m ≥ 1 }`
3. `L = { a^n b^n a^n | n ≥ 1 }`
4. `L = { ww | w ∈ {a, b}* }`
5. `L = { strings with equal number of a, b, and c in any order }`
6. `L = { an bn cn dm | n, m ≥ 1 }`
7. Any language where **length and symbol position must be preserved**
8. All languages of **Type 2 (CFL)** and **Type 3 (RL)**


**Examples of Not CSG-Acceptable Languages:** ❌
1. `L = { ⟨M⟩ | M does not halt on input ⟨M⟩ }` → **Halting Problem (non-RE)**
2. `L = { w | w is a valid C++ program that prints "yes" }`
3. `L = { M | M is a TM that accepts empty string }`
4. Any language requiring **general Turing-complete logic with unbounded memory**


**Conclusion:**

- **Context-Sensitive Grammars** accept all languages that need **bounded, but context-aware** structure
- They **include** all **regular** and **context-free** languages
- **Cannot simulate Turing Machines**, hence **cannot accept non-RE or undecidable languages**


##### **3. Languages Accepted by Pushdown Automata (Type 2 / CFG)**

These are called **Context-Free Languages (CFLs)**.

**Definition:**  A **Context-Free Grammar (CFG)** accepts languages where:

- Production rules are of the form: `A → α`, where `A ∈ V (non-terminal)`, `α ∈ (V ∪ T)*`
- Only **one non-terminal on LHS**, and **no context** is required
    

**Key Characteristics:**

- Grammar: **Context-Free Grammar**
- Machine: **Pushdown Automaton (PDA)**
- Memory: Uses **1 stack** (can match nested structures)
- All **regular languages** are also context-free
- Can't match **multiple dependencies** like `a^n b^n c^n`

**Not Accepted by CFG:**
- CFGs **do not accept** languages that require:
	- **More than one dependency check**
	- **Equal count matching across more than two symbols**
	- **Copying/mirroring of substrings**
	- **Non-linear memory** (can’t simulate two stacks)

**Examples of CFG-Acceptable Languages:** ✅
1. `L = { a^n b^n | n ≥ 0 }`
2. `L = { 0^n 1^n | n ≥ 0 }`
3. `L = { a^n b^m | n, m ≥ 0 }`
4. `L = { w ∈ {a, b}* | w is a palindrome }` ⭐
5. `L = { (ⁿ)^n | balanced parentheses }` ⭐
6. `L = { w | number of a's = number of b's, and all a's come before b's }`
7. `L = { a^n b^n + c^m | n, m ≥ 0 }`
8. Any language described by **recursive or nested patterns** using a single stack


**Examples of Not CFG-Acceptable Languages:** ❌ 
1. `L = { a^n b^n c^n | n ≥ 1 }` ⭐
2. `L = { ww | w ∈ {a, b}* }` ⭐
3. `L = { a^n b^n a^n | n ≥ 1 }`
4. `L = { ⟨M, w⟩ | Turing machine M accepts input w }`
5. `L = { strings with equal number of a, b, and c in any order }`
6. `L = { a^n b^m c^n | n, m ≥ 0 }`

**Conclusion:**
- **Context-Free Grammars** accept all languages that can be **parsed using a single stack**
- They **include all regular languages** (Type 3)    
- **Cannot handle** multiple parallel dependencies or simulate Turing machines

##### **4. Languages Accepted by Finite Automata (Type 3 / Regular Grammar)**

These are called **Regular Languages (RLs)**.
**Definition:** A **Regular Grammar (RG)** accepts languages where:
- Production rules are of the form:
    - **Right-linear**: `A → aB | a`
    - **Left-linear**: `A → Ba | a`

- No memory or stack is used    
- Grammar is **contracting** (produces shorter or same-length strings)
    

**Key Characteristics:**
- Grammar: **Regular Grammar (Left or Right Linear)**
- Machine: **Finite Automaton (FA / DFA / NFA)**
- Memory: **No memory (finite states only)**
- **Least powerful** in Chomsky hierarchy
- Cannot count or track nested structures
- Suitable for **simple pattern-based languages**

**Not Accepted by RG:** 
- Regular grammars **cannot accept**:
    - Languages that need **counting/matching**
    - **Nested** or **recursive** structures        
    - Languages requiring **memory or stack**

**Examples of RG-Acceptable Languages:** ✅
1. `L = { a^n | n ≥ 0 }`
2. `L = { a^n b^m | n, m ≥ 0 }`
3. `L = { strings ending with 'ab' }`
4. `L = { strings with no two consecutive b's }`
5. `L = { w ∈ {0,1}* | w contains even number of 0s }`
6. `L = { a^n b^n | n = 0 or 1 }`
7. `L = { w | w does not contain substring 'aa' }`
8. `L = { binary strings divisible by 3 }`
9. Any language defined by a **regular expression**

        
**Examples of RG-Acceptable Languages:** ❌
1. `L = { a^n b^n | n ≥ 1 }` → needs counting 
2. `L = { ww | w ∈ {a, b}* }` → needs memory
3. `L = { a^n b^n c^n | n ≥ 1 }` → not regular
4. `L = { w | w is a palindrome }`
5. `L = { a^p | p is prime }` → non-regular
6. `L = { w | number of a's = number of b's }`
        
**Conclusion:**
- **Regular Grammars** accept languages with **simple linear structure**
- They are the **fastest and simplest** to evaluate
- They **cannot** handle counting, nesting, or memory-based constraints
- **Subset of CFLs and CSLs**


---
---
# 2. Grammar


### **Types of Grammar**

```
Grammar                            Language  Automata
------------------------------------------------------------------
Regular Grammar(RG) ->                RL ->  Finite Automata (FA)
Context-Free Grammar(CFG) ->          CFL -> Push-down Automata (PDA)
Context-Sensitive Grammar(CSG) ->     CSL -> Linear Bounded Automata (LBA)
Recursively Enumerable Grammar(REG)-> REL -> Turing Machine (TM)
```

##### **Chomsky Hierarchy**

| **Type** | **Name**                  | **Production Form**                               | **Language Class**     | **Accepted By**          |
| -------- | ------------------------- | ------------------------------------------------- | ---------------------- | ------------------------ |
| Type 0   | Unrestricted Grammar      | `α → β` (α ≠ ε)                                   | Recursively Enumerable | Turing Machine           |
| Type 1   | Context-Sensitive Grammar | `αAβ → αγβ` (γ ≠ ε)                               | Context-Sensitive      | Linear Bounded Automaton |
| Type 2   | Context-Free Grammar      | `A → γ` (A ∈ V, γ ∈ (V ∪ T) * )                   | Context-Free           | Pushdown Automaton       |
| Type 3   | Regular Grammar           | `A → aB` or `A → a` (Right-linear or Left-linear) | Regular                | Finite Automaton         |

These types form a hierarchy:  ⭐
```
Type 3 ⊂ Type 2 ⊂ Type 1 ⊂ Type 0
```


##### **Monotonic Grammar

A **monotonic grammar** is a type of formal grammar where:

> For every production rule `α → β`,  
> it must satisfy: `|α| ≤ |β|`  
> i.e., the length of the right-hand side is **greater than or equal to** the left-hand side.

Also known as: **Non-contracting Grammar**


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

# 3. Automata

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

---

### **Different Automata tuple representations.**

Writing Order of 4 types of tuples: 
-> `Sets → Functions → States -> Symbol -> Subset`

##### **1. DFA  

**Purpose:** Accept/reject strings over an input alphabet.

**Tuple Format:**
- **`M = (Q, Σ, δ, q₀, F)`**  

| Component | Meaning                 | Type                  |
| --------- | ----------------------- | --------------------- |
| Q         | Finite set of states    | Set (States)          |
| Σ         | Input alphabet          | Set (Input Alphabets) |
| δ         | Transition function     | Function: Q × Σ → Q   |
| q₀        | Initial state           | State: q₀ ∈ Q         |
| F         | Set of accepting states | Subset (State): F ⊆ Q |

**`5` Tuples:**  
→ 2 Sets: `Q`, `Σ`  
→ 1 Function: `δ`  
→ 1 States: `q₀`
→ 1 Subset: `F`

##### **2. NFA**

**Tuple Format:**
- **`M = (Q, Σ, δ, q₀, F)`** → **Same as DFA**, but:

|Component|Change|
|---|---|
|δ|Q × (Σ ∪ {ε}) → 𝒫(Q) (**power set**)|

**Changes Compared to DFA:**   **`5` Tuples** (Same count)  
→ Only **transition function δ** changes to allow:
- Multiple transitions (nondeterminism)
- ε-transitions (empty string moves)


##### **3. Mealy Machine**

**Purpose:** Produce ==**output** for each input & State==  **on transitions**.

**Tuple Format:**
- **`M = (Q, Σ, Δ, δ, λ, q₀)`**  

|Component|Meaning|Type|
|---|---|---|
|Q|Finite set of states|Set (States)|
|Σ|Input alphabet|Set (Input Alphabets)|
|**Δ**|**Output alphabet**|Set (Output Alphabets)|
|δ|Transition function|Function: Q × Σ → Q|
|**λ**|**Output function**|Function: Q × Σ → Δ|
|q₀|Initial state|State: q₀ ∈ Q|

**Changes Compared to DFA:**  **`6` Tuples** (**+1**)
→ 3 Sets: `Q`, `Σ`, **`Δ`** _(+1)_  
→ 2 Functions: `δ`, **`λ`** _(+1)_  
→ 1 State: `q₀`  
→ ❌ No Subset `F` (No final state – Mealy transduces, doesn't accept)

##### **4. Moore Machine**

**Purpose:** Produce ==**output based only on states**==.

**Tuple Format:**
- **`M = (Q, Σ, Δ, δ, λ, q₀)`**  

|Component|λ (Output Function)|
|---|---|
|Moore|λ: Q → Δ|

**Changes Compared to DFA:**  **`6` Tuples** (**+1**)  	
→ 3 Sets: `Q`, `Σ`, **`Δ`** _(+1)_  
→ 2 Functions: `δ`, **`λ`** _(+1)_  
→ 1 State: `q₀`  
→ ❌ No Subset `F` (No final state – Moore also transduces)


##### **5. PDA (Pushdown Automaton)**

**Purpose:** Accept context-free languages using a **stack**.

**Tuple Format:**
- **`M = (Q, Σ, Γ, δ, q₀, Z₀, F)`**  

| Component | Meaning                  | Type                                     |
| --------- | ------------------------ | ---------------------------------------- |
| Q         | States                   | Set (State)                              |
| Σ         | Input alphabet           | Set (Alphabet)                           |
| **Γ**     | **Stack alphabet**       | Set (Alphabet)                           |
| δ         | Transition function      | Function: Q × (Σ ∪ {ε}) × Γ → 𝒫(Q × Γ*) |
| q₀        | Initial state            | State                                    |
| **Z₀**    | **Initial stack symbol** | Symbol ∈ Γ                               |
| F         | Accepting states         | Subset(State) ⊆ Q                        |

**Changes Compared to DFA:**  **`7` Tuples** (**+2**)  
→ 3 Sets: `Q`, `Σ`, **`Γ`** _(+1)_  
→ 1 Complex Function: `δ` using stack  
→ 2 States: `q₀`
→ 1 Symbol: **`Z₀`** _(+1)_ (initial stack symbol)
→ 1 Subset`F` 


##### **6. Turing Machine (TM)**

**Purpose:** Model general computation using a **tape**.

**Tuple Format:**
- **`M = (Q, Σ, Γ, δ, q₀, □, F)`**  

| Component | Meaning                      | Type                             |
| --------- | ---------------------------- | -------------------------------- |
| Q         | Set of states                | Set (State)                      |
| Σ         | Input alphabet (subset of Γ) | Set (Alphabet)                   |
| **Γ**     | Tape alphabet                | Set (includes blank symbol `□`)  |
| δ         | Transition function          | Function: Q × Γ → Q × Γ × {L, R} |
| q₀        | Initial state                | State                            |
| **□**     | **Blank symbol** (not in Σ)  | Symbol                           |
| F         | Accepting states             | Subset (State) ⊆ Q               |

**Changes Compared to DFA:**  **`7` Tuples** (**+2**)  
→ 3 Sets: `Q`, `Σ`, **`Γ`** _(+1)_  
→ 1 Function: `δ` includes read, write, move  
→ 2 States: `q₀`
→ 1 Symbol: **`□`** _(+1)_ (blank symbol)
→ 1 Subset`F` 


Summary Table

| Machine   | Tuple Components                    | Key Additions                    | Notes                           |
| --------- | ----------------------------------- | -------------------------------- | ------------------------------- |
| **DFA**   | (Q, Σ, δ, q₀, **F**)                | –                                | Base model                      |
| **NFA**   | (Q, Σ, δ, q₀, **F**)                | Modified δ                       | Allows nondeterminism & ε-moves |
| **Mealy** | (Q, Σ, **Δ**, δ, **λ**, q₀)         | +Δ, +λ (Q×Σ→Δ) , - F             | Output on transitions           |
| **Moore** | (Q, Σ, **Δ**, δ, **λ**, q₀)         | +Δ, +λ (Q→Δ), - F                | Output on states                |
| **PDA**   | (Q, Σ, **Γ**, δ, q₀, **Z₀**, **F**) | +Γ (stack), +Z₀                  | Stack-based (CFG recognition)   |
| **TM**    | (Q, Σ, **Γ**, δ, q₀, **□**, **F**)  | +Γ (tape), +□ (blank), +movement | General computation model       |
