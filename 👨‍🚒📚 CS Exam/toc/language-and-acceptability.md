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

# Language and Acceptability

### **1. Languages Accepted by ==Turing Machine== ==(Type 0)**==

These are called ==**Recursively Enumerable (RE)** ==languages.

**Definition:** A **Turing Machine (TM)** accepts **all languages that are computably enumerable**, i.e.,

* There exists a TM that will **accept** any string in the language
* It **may or may not halt** for strings not in the language

**Key Characteristics:**

* Grammar: ==**Unrestricted Grammar**==
* Rules: Productions of the form `α → β`, where `α, β ∈ (V ∪ T)*` and `α ≠ ε`
* Most powerful class of languages
* Includes all **Type 1, 2, 3** languages
* Turing Machines can simulate **any computation**

**Not Accepted:** ==Turing Machines do **not** accept:==

* \==**Non-computable languages**==, i.e., languages for which no TM exists at all
* \==**Undecidable**== languages can't be fully solved (TM might not halt), but they are **still RE**

**Examples of Turing-Acceptable Languages:**

1. `L = { a^n b^n c^n | n ≥ 1 }`
2. `L = { ww | w ∈ {a, b}* }`
3. `L = { palindromes over {a, b} }`
4. `L = { M | M is a valid C++ program that prints "yes" }`
5. `L = { ⟨M, w⟩ | Turing machine M accepts input w }`
6. Any language that requires **multiple stacks or tapes**
7. Any language describing **complex patterns**, e.g., nested loops, programming logic
8. Any language accepted by:
   * **Finite Automata** (Type 3)
   * **Pushdown Automata** (Type 2)
   * **Linear Bounded Automata** (Type 1)

**Examples of Not Turing-Acceptable Languages:**

* `L = { ⟨M⟩ | M does not halt on input ⟨M⟩ }` → ==**Diagonalization language** (non-RE)==

**Conclusion:**

* **Turing Machines accept the broadest class of languages**, including **all formal languages you can describe by any algorithm**.

### **2. Languages Accepted by ==Linear Bounded Automata== (==Type 1 / CSG==)**

These are called **Context-Sensitive Languages (CSLs)**.

**Definition:** A **Context-Sensitive Grammar (CSG)** accepts languages where:

* Production rules are of the form: `αAβ → αγβ`, where `|γ| ≥ 1`
* Length of the string **does not decrease** in any derivation step
* Grammar is **non-contracting** (except `S → ε` if ε is in the language)

**Key Characteristics:**

* Grammar: ==**Context-Sensitive Grammar**==
* Machine: **Linear Bounded Automaton (LBA)**
* Memory: **==Finite tape bounded by input size==**
* More powerful than PDA, but less powerful than TM
* Can handle **multiple dependencies**
* Includes all **regular** and **context-free** languages

**Not Accepted by CSG:**

* Context-sensitive grammars **cannot accept**:
  * Languages that are **not recursively enumerable**
  * Languages requiring **unbounded non-linear memory**
  * Languages with **undecidable or non-computable structure**

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

* **Context-Sensitive Grammars** accept all languages that need **bounded, but context-aware** structure
* They **include** all **regular** and **context-free** languages
* **Cannot simulate Turing Machines**, hence **cannot accept non-RE or undecidable languages**

### **3. Languages Accepted by Pushdown Automata (Type 2 / CFG)**

These are called **Context-Free Languages (CFLs)**.

**Definition:** A **Context-Free Grammar (CFG)** accepts languages where:

* Production rules are of the form: `A → α`, where `A ∈ V (non-terminal)`, `α ∈ (V ∪ T)*`
* Only **one non-terminal on LHS**, and **no context** is required

**Key Characteristics:**

* Grammar: **Context-Free Grammar**
* Machine: **Pushdown Automaton (PDA)**
* Memory: Uses **1 stack** (can match nested structures)
* All **regular languages** are also context-free
* Can't match **multiple dependencies** like `a^n b^n c^n`

**Not Accepted by CFG:**

* CFGs **do not accept** languages that require:
  * **More than one dependency check**
  * **Equal count matching across more than two symbols**
  * **Copying/mirroring of substrings**
  * **Non-linear memory** (can’t simulate two stacks)

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

* **Context-Free Grammars** accept all languages that can be **parsed using a single stack**
* They **include all regular languages** (Type 3)
* **Cannot handle** multiple parallel dependencies or simulate Turing machines

### **4. Languages Accepted by Finite Automata (Type 3 / Regular Grammar)**

These are called **Regular Languages (RLs)**. **Definition:** A **Regular Grammar (RG)** accepts languages where:

* Production rules are of the form:
  * **Right-linear**: `A → aB | a`
  * **Left-linear**: `A → Ba | a`
* No memory or stack is used
* Grammar is **contracting** (produces shorter or same-length strings)

**Key Characteristics:**

* Grammar: **Regular Grammar (Left or Right Linear)**
* Machine: **Finite Automaton (FA / DFA / NFA)**
* Memory: **No memory (finite states only)**
* **Least powerful** in Chomsky hierarchy
* Cannot count or track nested structures
* Suitable for **simple pattern-based languages**

**Not Accepted by RG:**

* Regular grammars **cannot accept**:
  * Languages that need **counting/matching**
  * **Nested** or **recursive** structures
  * Languages requiring **memory or stack**

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

* **Regular Grammars** accept languages with **simple linear structure**
* They are the **fastest and simplest** to evaluate
* They **cannot** handle counting, nesting, or memory-based constraints
* **Subset of CFLs and CSLs**
