---
description: From Gate Wallah's Tutorial ▶️ using Google NotebookLM 🔮
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

# TOC Tutorial (GATE Wallah x NotebookLM)

### **1. Introduction to Theory of Computation (ToC)**

**What is ToC?** It is a **mathematical concept** used to study practical situations in computer science.

**Purpose**: To determine which problems are **decidable** (an algorithm exists) and which are **undecidable** (no algorithm exists). It explores what computers can and cannot do.

**Main Areas of Study**:

* **Automata**: ==Finite Automata==, ==Pushdown Automata==, ==Linear Bounded Automata==, and ==Turing Machines==.
* **Formal Languages**: ==Regular Language==, ==Context-Free Language==, ==Context-Sensitive Language==, and ==Recursively Enumerable Language==.
* The entire syllabus focuses on **four types of automata and four types of languages**.

**Practical Applications**: Compiler design, hardware design (e.g., ==Mealy Machine==, ==Moore Machine==).

### **2. Finite Automata (FA)**

**Concept**: An ==**automaton** is simply a **machine**==, specifically a ==**theoretical/mathematical model** used to study the behaviour of practical machines.==

**Types of Finite Automata**:

* **Without Output**: Used in **compilers**, it takes an input and decides to ==**accept or reject**== it.
* **With Output**: Used in **hardware design** (e.g., a `1`'s complement circuit: ==`0` input produces 1 output, `1` input produces `0` output==).

> Finite Automata, Regular Languages, and Regular Expressions are a **major important area**, covering **50-60% of questions** (e.g., 5-6 marks out of 8).

**Key Concepts within FA**: Deterministic Finite Automata (DFA), Non-deterministic Finite Automata (NFA), ε-NFA, Mealy Machine, Moore Machine.

**2.1. Deterministic Finite Automata (DFA)**

**Definition**: A DFA is a **5-tuple** defined as ==(Q, Σ, δ, q0, F)==.

* \==**`Q`**== :A **finite set of states**.
* \==**`Σ`**== : The **input alphabet**.
* \==**`δ` (Transition Function)**== :Maps (Q × Σ → Q). This means **==from every state, for every input symbol, there is exactly one transition**==. This is crucial for DFA detection.
* \==**`q0`**== : The **initial state**, which must be **only one**.
* \==**`F`**== : A **set of final states**. This set can be **empty, contain one, or multiple states**; its size does not affect whether an automaton is a DFA.

**DFA Detection**: To check if an automaton is a DFA, ensure that from **every state, ==for every input symbol, there is exactly one transition**==. The number of final states is not a concern for DFA detection.

**DFA to Language Detection**: Every DFA corresponds to **one language**.

* **Strategy**: For multiple-choice questions, use the **elimination strategy**. Identify the **minimum string accepted** by the DFA and check which option's language matches it.
* **Example**: An automaton accepting strings like "`0`" but going into an infinite loop for "`00`" or "`000`" only accepts "`0`".

**DFA Construction and State Minimization**: ⭐

* **Limitations**: A DFA is **not possible** for languages with **dependencies** (e.g., `a^n b^n`, where the number of 'a's depends on 'b's) or for single-symbol languages without a **common difference** (e.g., `a^prime`, `a^(2^n)`).
* **Generalizations for Minimal DFA States**:
* For strings of ==**exactly length `N`**== : ==**`N+2`**== states (e.g., exactly 4 length needs 6 states).
* For strings of ==**at least length `N`**== : ==**`N+1`** ==states (e.g., at least 5 length needs 6 states).
* For strings of ==**at most length `N`**== : ==**`N+2`**== states (e.g., at most 4 length needs 6 states).
* For strings with ==length **divisible by `N`**==: ==**`N`** states== (e.g., divisible by 4 needs 4 states).
* For languages with **"AND" conditions** (e.g., **number of `A`'s** is even AND **number of `B`'s** is odd): The number of states is the **product of states required for each individual condition** (e.g., 2 states \* 2 states = 4 states). ⭐

**Minimization of DFA**: ⭐

1. **Eliminate Inaccessible States**: Remove any state that cannot be reached from the initial state.
2. **Find Equivalent States (Partitioning Algorithm)**:
   * Group all **non-final states** together and all **final states** together.
   * Iteratively check pairs of states within each group. ==States are equivalent if their transitions on **all input symbols** lead to states within the **same group**==. ==If they lead to different groups, they are separated.==
   * **Example**: If q1 and q2 transition to states within the same group for all inputs, they are equivalent and can be merged into a single state, reducing the total number of states.

**2.2. Non-deterministic Finite Automata (NFA)**

**Definition**: An automaton that is **not a DFA**, meaning it may have ==**missing transitions**==, ==**multiple transitions**== for a single input from a state, or **ε-transitions**.

**Conversion (NFA to DFA)**: ⭐

* Use the **Subset Construction Algorithm**.
* The **initial state of the DFA is the initial state of the NFA**.
* DFA transitions are derived from the NFA table:
* If an ==NFA transition results in an **empty set**==, the ==DFA transition leads to a **dead state**==.
* If an ==NFA transition results in **multiple states**==, the ==DFA creates a **new state**== representing the **union of those states**.
* If an ==NFA transition results in a **single state**==, i==t's copied ==as is.
* **Important**: Transitions must be defined for **every newly added state** in the DFA.
* **Final States in DFA**: Any DFA state that **contains at least one final state** from the original NFA becomes a final state.
* **Maximum States**: An NFA with N states can result in a DFA with up to **2^N maximum states**.

**2.3. ε-NFA (NFA with Epsilon Transitions)**

**Conversion (ε-NFA to NFA without ε)**: ⭐

* The ==**number of states remains the same**==.
* The **initial state remains the same**.
* **Final States**: A state becomes a final state in the new NFA if it can reach a final state in the original ε-NFA **only by ε-transitions**.
* **Transitions**: Consider paths that involve ε-transitions to determine all reachable states for a given input symbol.
* **Example**: An ε-NFA accepting (a+b)\* (the complete language) only requires **one state** in its minimal DFA.

### **3. Regular Expressions (RE)**

**Definition**: Regular expressions are ==built using **union (+)== , ==concatenation (.)==, and ==Kleene closure (\*)**== operators.

**Relationship with Regular Languages**: A regular expression ==exists **only for a regular language**==. If a language is not regular (i.e., a DFA is not possible for it), then a regular expression is also not possible.

**Construction of REs**:

* **Examples where REs are NOT possible**:
  * Languages with dependencies, like `a^n b^n`.
  * \==Palindromes== over more than one symbol.
* **Examples of REs and corresponding DFA states**:
  * For a string where the **Nth symbol from the right is 'X'**: Requires **2^N states** in its minimal DFA (e.g., 4th symbol from right is 'b' needs 2^4 = 16 states).
  * For a string where the **Nth symbol from the left is 'X'**: Requires **N+1 states** (e.g., 4th symbol from left is 'a' needs 5 states).
  * For REs like **A**_**B**_: Requires **(number of symbols + 1)** states in its minimal DFA (e.g., for &#x41;_&#x42;_, 2 symbols + 1 = 3 states; for &#x41;_&#x42;_&#x43;_D_, 4 symbols + 1 = 5 states).
  * For strings **ending with an N-length substring**: Requires **N+1 states** (e.g., ending with "AB" (length 2) requires 3 states). _Note: An example in the source indicates 6 states for "AB" substring, which may be a specific case or a different pattern_.

**RE Equivalence**: Certain regular expressions can represent the same language. For example, `(A+B)*` ==is equivalent to== `(A*B*)*` and `(A*+B*)*`. ⭐

**Conversion (FA to RE)**:

* The **State Elimination Method** is used.
* Simplify the automaton by eliminating states, replacing them with equivalent regular expressions.
* If a state has **multiple self-loops**, its regular expression becomes the **union of the loop expressions, Kleene-closed** (e.g., `(A+B)*` for loops '`A`' and '`B`').
* **Best Approach for MCQs**: If given a DFA and options for its regular expression, the most **powerful tool is elimination**. Check the minimum string accepted by the DFA and eliminate options that don't match.

### **4. Regular Languages (RL)**

**Detection (Regular vs. Non-Regular)**:

* **Finite Languages**: Any finite language (e.g., where '`N`' is at most 1000) is **always regular**.
* **Infinite Languages**:
  * **One-Symbol Languages**: Regular if they exhibit a **common difference** (form an arithmetic progression), otherwise not regular (e.g., `a^prime`, `a^(2^n)` are not regular).
  * **Multi-Symbol Languages**: Check for **dependencies**.
    * **Palindromes** like `W Wᴿ` or `W c Wᴿ` over **more than one symbol** (e.g., `{a, b}`) are **non-regular**.
    * Languages that reduce to the **complete language** (e.g., (A+B)\*) are regular.

**Closure Properties of Regular Languages**:

* Regular languages are **NOT closed** under: **Subset**, **Infinite Union**, **Infinite Intersection**.
* Regular languages are **closed** under: Union, Concatenation, Kleene Closure, Complement, Intersection, Difference, Reverse.
* **Example**: The intersection of L1 = (A+B)\* and L2 = (A+B)\* (ending with B) results in an empty language (∅), which is regular and requires only **one state** in its minimal DFA.

### **5. Grammars**

**Definition**: A grammar ==defines the rules for constructing strings in a language==. It consists of a set of ==non-terminals==, ==terminals==, ==production rules==, and ==a starting symbol==.

**Derivation**: The process of generating strings from a given grammar (e.g., Leftmost Derivation, Rightmost Derivation).

**Parse Tree**: A **graphical representation** of a derivation.

**Language Identification from Grammar**:

* **Example**: `S → aSa | bSb | ε` generates **even-length palindromes** `(WW^R)`.
* **Example**: `S → aA | bA, A → aA | bA | ε` generates **`(a+b)+`**, i.e., any string of '`a`'s and '`b`'s of length at least one.

**Types of Grammars (Chomsky Hierarchy)**: ⭐

* **Regular Grammar**:
  * **Structure**: The right-hand side of a production rule must contain **at most one non-terminal**, and this non-terminal must be at the **rightmost position (Right Linear Grammar)** or **leftmost position (Left Linear Grammar)**.
  * **Example of Non-Regular Grammar (which are CFG)**: `S → aSbS` (more than one non-terminal on RHS), `S → aASb` (non-terminal in middle), `S → aSa` (non-terminal not at extreme end and not a single terminal).
* **Context-Free Grammar (CFG)**:
  * **Structure**: The left-hand side must have **exactly one non-terminal**, and the right-hand side can be **anything** (any combination of terminals and non-terminals).

**Ambiguous Grammars**:

* **Definition**: A grammar is **ambiguous** if at least **one string** in its language can be generated by **more than one parse tree** (or more than one leftmost/rightmost derivation).
* **Ambiguity is Undecidable**: There is **no algorithm** to definitively determine if a grammar is ambiguous; one must use **trial and error**.
* **Example**: A grammar like S → S+S | &#x53;_&#x53; | a is ambiguous for strings like "a+&#x61;_&#x61;".
* **Example**: S → aSa | a is ambiguous for "aaa".
* **Example of Unambiguous Grammar**: A grammar that generates only "ab" or "ba" (e.g., S → aB | bA, B → b, A → a) is unambiguous if each string has only one parse tree.

**Normal Forms of CFG**:

* **Chomsky Normal Form (CNF)**:
  * **Structure**: Production rules must be of the form A → BC (exactly two non-terminals) or A → a (exactly one terminal).
  * **Derivation Steps**: To generate an N-length string from a CNF grammar, **2N-1 derivation steps** are required.
* **Greibach Normal Form (GNF)**:
  * **Structure**: Production rules must be of the form A → aBC... (a terminal followed by zero or more non-terminals). (Terminal followed by variable star).
  * **Derivation Steps**: To generate an N-length string from a GNF grammar, **N derivation steps** are required.

**Simplification of CFG**:

* **Order of Removal**:
  1. **Null Productions** (A → ε).
  2. **Unit Productions** (A → B).
  3. **Useless Variables** (non-terminals that cannot derive any terminal string or cannot be reached from the start symbol).

### **6. Pushdown Automata (PDA)**

**Definition**: A PDA is a **Finite Automata combined with a Stack**.

**Stack Properties**:

* The stack in a PDA has **infinite size**.
* If the stack size is **finite**, the PDA behaves like a Finite Automata and accepts only **Regular Languages**.

**Expressive Power**: PDA is **more powerful** than Finite Automata because it can accept both **Regular Languages** and **Context-Free Languages (CFL)**.

**Formal Definition**: A PDA is a 7-tuple including a stack alphabet (Γ) and an initial stack symbol (Z0). The **transition function** is key: δ: (Q × (Σ ∪ ε) × Γ) → (Q × Γ\*). This means from a (state, input symbol, top-of-stack symbol) combination, it transitions to a (next state, string to push onto stack).

**Acceptance Methods**:

* **Empty Stack (ES) Method**: A string is accepted if the stack is empty at the end of processing.
* **Final State (FS) Method**: A string is accepted if the PDA is in a final state at the end of processing.
* **Equivalence**: For a **Non-Deterministic PDA (NPDA)**, the set of languages accepted by the **Empty Stack Method and the Final State Method are the same**.

**Limitations**:

* PDA accepts **Context-Free Languages (CFL)**.
* A single-stack PDA **cannot handle multiple independent dependencies** (e.g., a^n b^n c^n is not a CFL, as it would require remembering two separate counts simultaneously). Such languages typically require two or more stacks.

**PDA to Language Identification**:

* **Strategy**: Analyze the push and pop operations based on input symbols and stack contents to determine the language accepted.
* **Example 1**: If 'a' pushes 'X', and 'b' pops 'X' when encountered, this indicates equality between 'a's and 'b's. If 'c' is then encountered with no stack operation, it can be any number of 'c's. This could represent a^n b^n c\*.
* **Example 2**: If 'a' pushes 'X', 'b' pops 'X', this generally represents a^n b^n.
* **Example 3**: If 'a' pushes, 'b' pushes, 'c' pops 'b', and 'd' pops 'a', this represents a^n b^m c^m d^n.
* **Example 4 (Palindromes)**: W C W^R (odd-length palindrome with a center marker) can be accepted: push W onto the stack, skip 'C', then pop and match W^R.
* **Example 5 (Non-CFL)**: W W (duplicate string) is **not a CFL** and a single-stack PDA is **not possible** for it, as it cannot check if the first half matches the second half when the first half is at the bottom of the stack.

**Deterministic PDA (DPDA) vs. Non-Deterministic PDA (NPDA)**:

* **DCFL (Deterministic Context-Free Language)**: Languages accepted by a DPDA.
* **CFL but Not DCFL**: Languages accepted by an NPDA but not a DPDA.
* **Example of CFL but not DCFL**: The **union of two DCFLs** (e.g., L1 = a^n b^n c\* and L2 = a\* b^n c^n) is often a CFL but not a DCFL, because a DPDA cannot deterministically decide which path to take at certain points (e.g., when reading 'a', if it should push for a^n b^n or prepare for a\*b^n c^n).

**Language Hierarchy**: **Regular Languages ⊂ DCFL ⊂ CFL**.

**Closure Properties of CFL and DCFL**:

* **Context-Free Languages (CFL)**:
  * **Closed under**: Union, Concatenation, Kleene Closure, **Intersection with Regular Language**.
  * **NOT Closed under**: Complement, Intersection.
* **Deterministic Context-Free Languages (DCFL)**:
  * **Closed under**: Complement, Union, Concatenation, Kleene Closure, **Intersection with Regular Language**.
  * **NOT Closed under**: Intersection.

### **7. Turing Machine (TM)**

**Definition**: A Turing Machine is a **mathematical model used to represent a general-purpose computer**.

**Key Features**:

* An **infinite tape** that extends in both directions.
* Can **move left and right** across the tape.
* Has **read/write capability**: it can read a symbol and replace it with another.

**Expressive Power**: TM is the **most powerful** among all automata. It can accept **Regular Languages, Context-Free Languages (CFL), Context-Sensitive Languages (CSL), and Recursively Enumerable Languages (REL)**.

**Formal Definition**: A TM is a 7-tuple. Its **transition function** is: δ: (Q × Γ) → (Q × Γ × {L,R}). This means from a (current state, symbol read) combination, it transitions to a (next state, symbol to write, move direction (Left/Right)).

**TM Construction**: The construction of a TM depends heavily on the **logic** required to process a language. For example, to check if the number of 'a's and 'b's are equal (a^n b^n), a TM might replace 'a' with 'X', find and replace 'b' with 'Y', then move back to find the next 'a', and repeat until no 'a's or 'b's remain.

**Halting Problem and Loops**:

* A significant characteristic of TMs is that they **can fall into an infinite loop** for certain inputs.
* If a TM goes into an infinite loop, the string is neither accepted nor rejected. For a string to be accepted, the TM must halt in a final state.
* **Example**: A TM designed to accept only the string "0" might loop indefinitely for "00" or "000".

**Language Classification (Based on TM Halting Behavior)**:

* **Recursive Languages (RL)** / Turing Decidable Languages:
  * A TM for an RL **always halts** for every input string. It halts in a final state for strings belonging to the language and in a non-final (rejecting) state for strings not belonging to the language.
  * These languages are considered **decidable**.
* **Recursively Enumerable Languages (REL)** / Turing Recognizable Languages / Type 0 Languages:
  * A TM for an REL **halts in a final state** for strings belonging to the language.
  * For strings **not part of the language**, the TM **may halt in a non-final state OR may loop forever**.
  * These languages are considered **partially decidable**.
* **Non-Recursively Enumerable Languages (Non-REL)**:
  * For these languages, **no Turing Machine exists at all**.

**Language Hierarchy**: **Recursive Languages ⊂ Recursively Enumerable Languages**.

**Closure Properties**: (Crucial to memorize the table)

* **Recursive Languages**: **Closed under** Complement, Union, Intersection.
* **Recursively Enumerable Languages**: **Closed under** Union, Intersection. **NOT Closed under** Complement (the complement of an REL is a Non-REL).

### **8. Decidability and Undecidability**

**Concept**:

* **Decidable Problem**: An algorithm exists that **always halts** and provides a "yes" or "no" answer for every instance of the problem.
* **Undecidable Problem**: **No algorithm exists** that can solve the problem for all possible inputs.

**Key Problems and Their Decidability**: (Refer to the table provided in classes for comprehensive understanding).

* Generally, as you move up the Chomsky Hierarchy (from Regular to REL), more problems become **undecidable**.
* **Regular Languages**: Most problems (e.g., membership, emptiness, finiteness, equivalence, intersection emptiness) are **decidable**.
* **Context-Free Languages (CFL)**: Some problems are decidable, but many are **undecidable** (e.g., ambiguity, equivalence, intersection emptiness).
* **Context-Sensitive Languages (CSL)**: Almost all problems are **undecidable**.
* **Recursively Enumerable Languages (REL)**: Many problems are **undecidable**.

**Important Undecidable Problems**:

* **Halting Problem for TMs**: Classic example of an undecidable problem.
* **Ambiguity of CFG**: Undecidable.
* **Equivalence of CFG**: Undecidable.
