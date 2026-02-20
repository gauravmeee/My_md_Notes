---
description: From Gate Wallah's Tutorial ▶️
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

# CD Tutorial (Gate Wallah)

> Created using Google NotebookLM

### **1. Introduction to Compiler Design**

A **compiler** is a software that primarily performs two main tasks:

* **1. ==Translation**:== It converts a program written in a **high-level language** (e.g., C, C++, Java) into a **low-level language** (e.g., assembly language, machine code). Compilers are often referred to as "translators" because they translate one type of language to another.
* **2. ==Error Detection**:== It detects various errors present in the source program during the translation process.

A compiler is ==not a small piece of software==; it can consist of millions of lines of code. To manage this complexity, the total task of a ==compiler is divided into **six different sub-programs== or phases**. Designing a compiler involves developing each of these sub-programs.

### **2. Phases of a Compiler**

Each phase ==takes a specific input== and ==produces a specific output==, performing a particular task. Some phases are also responsible for detecting specific types of errors.

Here are the **six phases** of a compiler:

* **1. Lexical Analysis (==Scanner)**==:
  * **Input**: High-level language source code.
  * **Output**: **==Tokens==**.
  * **Primary Function**: Reads the source program ==character by character==, groups them into meaningful units called tokens, and detects **lexical errors**.
* **2. Syntax Analysis (==Parser==)**:
  * **Input**: Tokens from the lexical analyser.
  * **Output**: **==Parse Tree==** (or syntax tree).
  * **Primary Function**: Checks if the ==sequence of tokens conforms to the grammatical rules== (syntax) of the programming language and detects **syntax errors**.
* **3. Semantic Analysis**: ⭐
  * **Input**: Parse Tree.
  * **Output**: ==Annotated Parse Tree== (or Intermediate Representation if integrated with Intermediate Code Generation).
  * **Primary Function**: ==Checks for meaning-related errors== (e.g., type mismatches, undeclared variables) ==that syntax analysis cannot catch== and detects **semantic errors**.

> Word Meaning : Semantic - **Actual meaning of words, phrases, or sentences**, not just their structure. Annotated - Supplied with notes, comments, or explanations.

* **4. Intermediate Code Generation**:
  * **Input**: Annotated Parse Tree.
  * **Output**: ==**Three-address code**== (or other intermediate representations like syntax trees, DAGs).
  * **Primary Function**: Generates an intermediate, ==machine-independent representation of the source code==, facilitating optimisation and target code generation.
* **5. Code Optimisation**:
  * **Input**: Three-address code (intermediate code).
  * **Output**: ==**Optimised three-address code**.==
  * **Primary Function**: ==Improves the intermediate code== to make the final target code more efficient (e.g., faster execution, smaller size).
* **6. Code Generation**:
  * **Input**: Optimised three-address code.
  * **Output**: ==Assembly language code== (or machine code).
  * **Primary Function**: Translates the intermediate code into the ==target machine's assembly or machine language.==

> **Note**: For GATE syllabus, the concept of Code Generation is typically **excluded**, so you can skip it if focusing solely on GATE.

* **Lexical, Syntax, Semantic Analysers** -> primarily focus on ==**error detection**==
* **Intermediate Code Generation, Code Optimisation, Code Generation** ->focus on ==**translation**.==

**6 Phases:**

1. **Lexical Analysis** : Tokenization, regular expressions, finite automata.
2. **Syntax Analysis** : CFG, parse trees, parsers (LL, LR, SLR, etc.) ⭐
3. **Semantic Analysis** : Type checking, symbol tables.
4. **Intermediate Code Generation** : Three-address code, abstract syntax trees.
5. **Code Optimization** : Constant folding, dead code elimination.
6. **Code Generation** : Machine-level instruction generation.

> Syntax Analysis (Parsing) is the most important topic in the syllabus, as it forms the basis of grammar-based questions, covers parsing techniques (LL, LR, etc.), and is frequently asked in exams and interviews.

### **3. Lexical Analysis (Scanner)**

The **Lexical Analyser** is the **first program** in the compiler and directly interacts with the high-level language source code.

**3.1. Functions of Lexical Analysis**

* **Reads Source Program**: Reads the source program as a ==**stream of characters**,== character by character. Due to this, the lexical analyser is ==also known as a **Scanner** or **Tokeniser**.==
* **Produces Tokens**: Groups the input characters into **tokens**, which are then produced as output.
* **Detects Lexical Errors**: Identifies errors in the program that can be caught during the token generation process.
* **Removes Comments**: ==Eliminates comment lines== (single-line or multi-line) from the source code, as they have no logical significance to the compiler. ⭐
* **Removes Whitespaces**: ==Removes whitespace characters== (e.g., spaces, tabs, newlines) from the source code. ⭐
* **Partial Symbol Table Construction**: Partially constructs the **symbol table**, which stores ==information about identifiers.==

**3.2. Tokens**

A **token** is a ==**sequence of characters that can be treated as a single logical entity**==.

In programming languages, characters are grouped into meaningful entities, which fall into **five main categories:**

* **1. ==Keywords==** : ==Reserved words== with specific meanings (e.g., `int`, `if`, `else`, `for`, `while`, `do`).
* **2. ==Identifiers==** : ==User-defined names== for variables, functions, etc. (e.g., `a`, `b`, `sum`, `_temp`). They typically start with a letter followed by any number of letters or digits.
* **3. ==Constants==** : Fixed values (e.g., `10`, `3.14`, `'c'`, `"hello"`).
  * \==**Integer Constants**:== Sequence of digits (e.g., `100`, `500`).
  * \==**Real Constants**:== Digits followed by a dot and more digits (e.g., `3.14`).
  * \==**Character Constants**:== Single character enclosed in single quotes (e.g., `'a'`).
  * \==**String Constants**:== Sequence of characters enclosed in double quotes (e.g., `"hello"`). A string constant, including the quotes, is considered a single token.
* **4. ==Operators==** : Symbols performing operations (e.g., `+`, `-`, `*`, `/`, `++`, `--`, `=`, `==`, `>=`, `<=`, `!=`, `+=`).
* **5. ==Special Symbols==** : Punctuation marks and other symbols (e.g., `;`, `(`, `)`, `{`, `}`, `,`).

> Note: Pre-built functions, objects like in C++ `cin`, `endl`, `sort` are Not keywords. They are Pre-defined Identifier (from Library)

**Token Generation Challenges (==Longest Match Rule==)**

When generating tokens, especially for operators, the **Lexical Analyser** follows the **longest match rule**. ==If multiple token possibilities exist, it prioritises the longest possible token.==

* **Example 1**: For `++` (increment operator), it's treated as one token, not two separate `+` tokens.
* **Example 2**: For `a +++ b`, it would be parsed as `a , ++ , + , b` (assuming `+++` is not a valid operator). The Lexical Analyser first identifies `+` but then **looks ahead** at the next symbol. If `++` forms a valid longer token, it takes that. If not, it falls back to `+` and then processes the remaining `+`. ⭐
* **Example 3**: For `a <= b`, it's tokenised as `a`, `<=`, `b`, not `a`, `<`, `=`, `b`.
* **Example 4**: For `a += b`, it's tokenised as `a`, `+=`, `b`.

**3.3. Lexical Errors**

A ==**lexical error**== occurs when a **group of characters fails to form a valid token** according to the language's rules. The ==Lexical Analyser's main purpose is to detect these errors.==

**Examples of Lexical Errors**: ⭐

* **==Invalid Identifiers**==: An identifier starting with a digit (e.g., `2abc`) is not a valid token.
* **==Unterminated Strings/Characters==**: A string or character constant that starts with a quote but lacks a closing quote (e.g., `"hello` or `'a`) results in a lexical error because the entire sequence cannot be formed into a valid string/character token.
* **==Unrecognised Characters==**: Symbols or sequences of characters that do not belong to any valid token category in the language (e.g., `int$var`).

**Important Note**:

* Missing semicolons, although an error, is **not ❌ a lexical error**; it's a ==**syntax error**== ✅because individual tokens (`int`, `a`, `b`) are valid, but their arrangement violates grammatical rules.
* Similarly, assigning a string to an integer variable (e.g., `int a = "hello";`) not ❌ a **lexical Error** but a ==**semantic error**==, ✅ as all individual tokens are valid.

### **4. Parsing (Syntax Analysis)**

**Parsing**, also known as **Syntax Analysis**, is the **second phase** of the compiler. It verifies the **grammatical structure** of the token stream.

**4.1. Introduction to Parsing**

* **Input**: Tokens from the Lexical Analyser, and **Grammars** (==Context-Free Grammars== - CFGs).
* **Output**: A **Parse Tree** (or Syntax Tree) if the input is syntactically valid.
* **Primary Function**: Checks if the sequence of tokens forms a valid program structure according to the language's grammar rules. If not, it reports **syntax errors**.

**4.2. Terminology**

* **Syntax**: Refers to the **structure of program statements**. For example, the syntax of a `for` loop or an `if-else` statement defines how its components must be arranged.
* **Parsing**: The process of determining whether a given **input string (sequence of tokens) is a member of a given grammar** or can be generated from it. This is also known as =="membership"== testing in Theory of Computation.
* **Parser**: The program or algorithm that performs the parsing process. It takes tokens and grammar rules as input and produces a parse tree or reports a syntax error.

**4.3. Grammars**

**Grammars** are ==formal systems used to **describe the syntactic structure (rules)== of a programming language**. These rules are represented in the form of **productions** (e.g., `Alpha -> Beta`), where `Alpha` can be replaced by `Beta`.

* **Components of a Grammar (==NTPS Notation==)**: ⭐
  * **Non-terminals (==N==)**: ==Variables== that can be replaced by other non-terminals or terminals. (e.g., `Expr`, `Term`)
  * **Terminals (==T==)**: Actual tokens of the language that ==cannot be further broken down== (e.g., `int`, `+`, `a`, `;`).
  * **Productions (==P==)**: ==Rules== that specify how non-terminals can be replaced.
  * **Starting Symbol (==S==)**: A ==special non-terminal== that ==represents the entire program structure.==
* **Derivation**: The process of **generating a string from a given grammar** by repeatedly applying production rules. Derivations can be:
  1. **Leftmost Derivation (LMD)**: Always replaces the leftmost non-terminal in each step.
  2. **Rightmost Derivation (RMD)**: Always replaces the rightmost non-terminal in each step.
* **Parse Tree**: A **tree representation of a derivation**. The ==root is the starting symbol==, ==internal nodes are non-terminals==, and ==leaf nodes are terminals== (the input string).
* **Ambiguity**: A grammar is **ambiguous** if ==**there exists at least one string** in the language that has **more than one parse tree**== (or more than one **leftmost/rightmost derivation**). if there exists at least one string in the language that has more than one parse tree (or more than one leftmost/rightmost derivation).
  * **Two different leftmost derivations** for the same string → **Ambiguous** ❌
  * **Two different rightmost derivations** for the same string → **Ambiguous** ❌
  * **One leftmost and one rightmost derivation (that are the same)** → **Not ambiguous** ✅
* **Impact on Parser Design**: ==Ambiguous grammars are **not suitable for designing parsers**== because they introduce ambiguity (confusion) about which parse tree to build or which production rule to apply. This can lead to ==conflicts in parsing tables==, making deterministic parsing difficult or impossible. Compilers should ideally work with unambiguous grammars.

**Example:**

```plaintext
E → E + E  
E → E * E  
E → a
```

**Input String** `a + a * a`

\*\*Parse Tree 1

```plaintext
        E
       /|\
      E + E
      |   |
      a   E
         /|\
        E * E
        |   |
        a   a

Interpret as: a + (a * a)
```

\*\*Parse Tree 2

```plaintext
        E
       /|\
      E * E
     /|\   |
    E + E  a
    |   |
    a   a

Interpret as: (a + a) * a
```

Since the same string `a + a * a` gives **two different parse trees**, the grammar is **ambiguous** and **not suitable** for deterministic parser design.

**4.5. Parser Algorithms: Top-Down vs. Bottom-Up**

Parsers are typically designed using one of two main algorithmic approaches:

1. \==**Top-Down Parsing**==: Starts from the **start symbol** and tries to ==derive the input string== by applying production rules from top to bottom, effectively building the parse tree from the root downwards.
2. \==**Bottom-Up Parsing**:== Starts from the **input string (leaves)** and tries to ==reduce it to the start symbol== by applying production rules in reverse, effectively building the parse tree from the leaves upwards towards the root.

**Comparison of Top-Down and Bottom-Up Parsers**:

| Feature          | Top-Down Parsers                                     | Bottom-Up Parsers                                                                 |
| ---------------- | ---------------------------------------------------- | --------------------------------------------------------------------------------- |
| **Approach**     | Builds parse tree from **root to leaves**            | Builds parse tree from **leaves to root**                                         |
| **Derivation**   | Uses **Leftmost Derivation**                         | Uses **Rightmost Derivation in Reverse Order**                                    |
| **Power**        | ==**Less powerful**== (suitable for fewer languages) | ==**More powerful**== (suitable for more languages, e.g., C, C++, Java compilers) |
| **Complexity**   | Generally **easier** to design                       | Generally **more complex** to design                                              |
| **Example Type** | ==LL(1)== Parsers                                    | LR Parsers (LR(0), SLR(1), LALR(1), CLR(1))                                       |

**Top-Down Parsing**

1. **LL Parsers**
   * LL(1)
   * LL(k)
   * **Recursive Descent** (manual, may use backtracking)
   * **Predictive Parser** (table-driven, no backtracking)

**Bottom-Up Parsing**

2. **Shift-Reduce Parser**
3. **Operator Precedence Parser**
4. **LR Parsers**
   * SLR (Simple LR)
   * LALR (Look-Ahead LR)
   * CLR (Canonical LR / LR(1))

### **5. Bottom-Up Parsing**

Bottom-Up parsers are generally ==more powerful== and are ==widely used in practical compilers==. The core mechanism of bottom-up parsing involves **handle detection** and **shift-reduce operations**.

**5.1. Working Method: Handle Detection**

A ==**handle** is a **substring within the input== that completely matches the right-hand side of a grammar production**. When a ==handle is detected, it is **reduced** by replacing it with the non-terminal on the left-hand side== of the corresponding production. ⭐ This process continues ==until the input string is reduced to the start symbol. ==

**Example of Handle Detection**: Grammar: `S -> aABb`, `A -> c`, `B -> d`

Input String: `acdb`

1. **Step 1**: Initial string `acdb`.
   * **Handle**: `c` (matches `A -> c`).
   * **Reduction**: Replace `c` with `A`. String becomes `aAd b`.
2. **Step 2**: String `aAdb`.
   * **Handle**: `d` (matches `B -> d`).
   * **Reduction**: Replace `d` with `B`. String becomes `aABb`.
3. **Step 3**: String `aABb`.
   * **Handle**: `aABb` (matches `S -> aABb`).
   * **Reduction**: Replace `aABb` with `S`. String becomes `S`.

Since the string has been reduced to the start symbol `S`, the input string is a member of the grammar. In this example, a total of **three handles** were detected.

**5.2. Shift-Reduce Parsing**

\==To automate the handle detection and reduction process==, bottom-up parsers typically ==use a **stack** and an **input buffer**==. This mechanism is known as ==**Shift-Reduce Parsing**,== and parsers employing it are called **Shift-Reduce Parsers**. This structure ==resembles a **Pushdown Automaton (PDA)**.==

* **Shift Action**: When no handle is found on top of the stack, a **symbol is moved (shifted) from the input buffer onto the stack**. This is analogous to a `push` operation.
* **Reduce Action**: When a handle is found at the top of the stack, it is **replaced (reduced)** by its corresponding non-terminal on the left-hand side of the production rule. This effectively pops the handle symbols and pushes the non-terminal.
* **Accept**: If the stack contains only the start symbol and the input buffer is empty, the parsing is successful.
* **Error**: If the parser cannot perform a shift or a reduce action, and the input is not yet fully processed or the stack does not contain the start symbol, a syntax error is declared.

**5.3. Shift-Reduce Conflicts and LR Parsing Tables**

A **common problem** in naive Shift-Reduce parsers is **ambiguity** in deciding whether to perform a shift or a reduce action, or which reduce action to perform ==if multiple handles are present==. These are called ==**conflicts**:== ⭐

* \==**Shift-Reduce (SR)== Conflict**: The parser is in a state where it can perform both a **shift** and a **reduce** action.
* **==Reduce-Reduce (RR)== Conflict**: The parser is in a state where it can perform **multiple reduce** actions using different production rules.

To resolve these conflicts and ==enable deterministic parsing==, **LR parsers** employ a **parsing table**. This table guides the parser's decisions on when to shift, when to reduce, and which specific production to use for reduction. The ==construction of this LR parsing table is a crucial== part of LR parsing.

**5.4. Operator Precedence Parsing**

Operator Precedence Parsing is a type of bottom-up parsing for grammars with operator precedence. It identifies the **precedence** (which operator evaluates first) and **associativity** (left-to-right or right-to-left grouping) of operators from the grammar.

* **Precedence**: Operators at **lower levels** (closer to the leaves) in a parse tree have **higher precedence**.
  * **Example**: In an expression `A + B * C`, `*` will be at a lower level in the parse tree than `+`, indicating `*` has higher precedence.
* **Associativity**: Determined by **recursion** in the grammar rules.
  * **Left Associative**: If the recursive non-terminal is on the **left side** of the operator (e.g., `E -> E + T`).
  * **Right Associative**: If the recursive non-terminal is on the **right side** of the operator (e.g., `E -> T ** E`).

**5.5. Types of LR Parsers**

There are four main types of LR parsing algorithms, each offering different power and complexity in table construction:

* **LR(0)**
* **SLR(1)** (Simple LR)
* **LALR(1)** (Look-Ahead LR)
* **CLR(1)** (Canonical LR)

All these methods ==involve constructing a **Deterministic Finite Automaton (DFA)**== based on "LR Items".

**5.5.1. LR(0) Parsing**

* **Augmented Grammar**: The first step in constructing an LR(0) parsing table (or its underlying DFA) is to augment the given grammar. This involves adding a new production `S' -> S`, where `S'` is a new start symbol and `S` is the original start symbol. This helps in identifying the acceptance state.
* **LR(0) Item**: An **LR(0) item** is a grammar production with a ==**dot (`.`) inserted at some position in its right-hand side**. The dot indicates how much of the right-hand side has been seen== so far.
  * **Example**: For production `A -> B C`, possible LR(0) items are `A -> .B C`, `A -> B .C`, `A -> B C.`.
  * `A -> B C.` indicates that the right-hand side `BC` has been fully matched on the stack, and a **reduce** action might be performed.
* **Closure Function**: The `Closure(I)` function takes a set of LR(0) items `I` and adds all necessary LR(0) items.
  * If an item `A → α .B β` is in `I` (where `B` is a non-terminal), then for every production `B → γ` in the grammar, the item `B → .γ` is added to `I`.
* This process builds a **DFA** whose **states are sets of LR(0) items**. This collection of states and transitions is called the **Canonical Collection of LR(0) Items**.

**Example of LR(0) DFA Construction (Conceptual)**:

* Given Grammar: `S -> aA` `A -> c` `A -> d`
* Augmented Grammar: `S' -> S` `S -> aA` `A -> c` `A -> d`

**Step-by-step States**

1. **I₀ (Initial State)**: `Closure({S' -> .S})`
   * Adds `S -> .aA` (since `S` is after dot).
   * No more non-terminals after dot, so I0 = `{S' -> .S, S -> .aA}`.
2. **GoTo(I₀, S)**: `S' -> S.` (Accept state) -> I1
3. **GoTo(I₀, a)**: `S -> a.A`
   * `Closure({S -> a.A})` adds `A -> .c` and `A -> .d` (since `A` is after dot).
   * I2 = `{S -> a.A, A -> .c, A -> .d}`.
4. **GoTo(I₂, c)**: `A -> c.` (Reduce by `A -> c`) -> I3
5. **GoTo(I₂, d)**: `A -> d.` (Reduce by `A -> d`) -> I4
6. **GoTo(I₂, A)**: `S -> aA.` (Reduce by `S -> aA`) -> I5

This results in a DFA with states I0 to I5.

**Conflict Detection in LR(0)**: An LR(0) grammar is free of conflicts if its LR(0) items DFA does not contain any of the following:

* **Shift-Reduce (SR) Conflict**:
  * A state contains an item `A → α .t β` (where `t` is a terminal, indicating a **shift** action) AND
  * an item `B → γ.` (indicating a **reduce** action).
* **Reduce-Reduce (RR) Conflict**: A state contains two or more reduce items (e.g., `A → α.` AND `B → β.` ), indicating ambiguity on which production to use for reduction.
* **Note**: For items `A → α .ε`, treat it as `A → α.`.

If any of these conflicts are present in any state of the LR(0) DFA, the grammar is **not an LR(0) grammar**.

* ✅ If no conflicts → the grammar is **LR(0)**
* ❌ If any SR or RR conflict exists → **Not LR(0)**

**5.5.2. SLR(1) Parsing**

SLR(1) parsers build the **same LR(0) Items DFA**. The only difference lies in how **reduce actions are placed in the parsing table**.

* For an LR(0) item `A -> α.` (a reduce item), the reduce action is placed only in the cells corresponding to the terminals in the **`FOLLOW(A)` set**. In contrast, LR(0) places reduce actions for all terminals.
* **Conflict Detection in SLR(1)**:
  * **Shift-Reduce (SR) Conflict**: A state has an item `A -> α .t β` (shift on `t`) AND an item `B -> γ.` (reduce by `B -> γ`). An SR conflict occurs if `t` is in `FOLLOW(B)`.
  * **Reduce-Reduce (RR) Conflict**: A state has two or more reduce items `A -> α.` AND `B -> β.`. An RR conflict occurs if `FOLLOW(A)` and `FOLLOW(B)` have a **common element** (i.e., `FOLLOW(A) ∩ FOLLOW(B) ≠ ∅`).

If any of these conflicts occur, the grammar is **not an SLR(1) grammar**.

* ✅ If **no conflicts** (i.e., **no SR or RR**) → the grammar **is SLR(1)**
* ❌ If **any SR or RR conflict** → the grammar is **not SLR(1)**

**Relationship with LR(0)**: ⭐

* Every LR(0) grammar is also an SLR(1) grammar.
* However, an SLR(1) grammar may not necessarily be an LR(0) grammar. This implies that ==SLR(1) is **more powerful** than LR(0).==

**5.5.3. CLR(1) Parsing**

CLR(1) parsers are the most powerful among the LR family. They use **LR(1) items** to construct the DFA.

* **LR(1) Item**: An **LR(1) item** is an **LR(0) item with an associated lookahead symbol**. It is written as `[A -> α .β, a]`, where `a` is the lookahead terminal.
* **Closure Function**: The `Closure(I)` for LR(1) items is more complex. If `[A -> α .B β, a]` is an item in `I`, then for every production `B -> γ`, the item `[B -> .γ, b]` is added, where `b` is any terminal in `FIRST(β a)`. The lookahead calculation is crucial here.
* **GoTo Function**: The `GoTo(I, X)` function works similarly to LR(0), moving the dot and then computing the closure, but it **retains the lookahead symbols**.
* **CLR(1) Items DFA**: This DFA contains states that are sets of LR(1) items. Because lookahead symbols differentiate items, CLR(1) DFAs typically have **more states** than LR(0) or SLR(1) DFAs.

**5.5.4. LALR(1) Parsing**

LALR(1) parsers are created by **merging CLR(1) states that have the same LR(0) core** (i.e., same LR(0) items) but different lookahead sets. When merging, the lookahead sets are **combined (union)**.

* **Advantage**: Reduces the number of states compared to CLR(1), making the parsing table smaller and more practical.
* **Disadvantage**: Merging can introduce new **Reduce-Reduce conflicts** that were not present in the original CLR(1) grammar. A shift-reduce conflict, if not present in CLR(1), will not be introduced by merging in LALR(1).

**Conflict Detection in CLR(1) and LALR(1)**: ⭐ The conflict detection rules are the ==same for CLR(1) and LALR(1):==

* **Shift-Reduce (SR) Conflict**: A state has an item `[A -> α .t β, x]` (shift on `t`) AND an item `[B -> γ., y]` (reduce by `B -> γ`). An SR conflict occurs if `t` is in `y` (the lookahead of the reduce item).
* **Reduce-Reduce (RR) Conflict**: A state has two or more reduce items `[A -> α., y1]` AND `[B -> β., y2]`. An RR conflict occurs if `y1` and `y2` have a **common element** (i.e., `y1 ∩ y2 ≠ ∅`).

If any of these conflicts occur, the grammar is **not a CLR(1)/LALR(1) grammar**.

* ✅ If **no conflicts** (i.e., **no SR or RR**) → the grammar **is CLR(1)/LALR(1)**
* ❌ If **any SR or RR conflict** → the grammar **is not CLR(1)/LALR(1)**

**5.5.5. Parser Power Hierarchy**

The power of LR parsers (from least to most powerful) is as follows: **LR(0) < SLR(1) < LALR(1) < CLR(1)**.

* **Power :** `CLR(1)` > `LALR(1)` > `SLR(1)` > `LR(0)`
* **CLR(1)** is the **most powerful** LR parser.
* **LR(0)** is the **least powerful** LR parser.
* Every CLR(1) grammar is an LALR(1) grammar (if no new RR conflicts are introduced during merging), which is an SLR(1) grammar, which is an LR(0) grammar (not exactly but conceptually in terms of recognition power).

### **6. Top-Down Parsing (LL(1) Parsing)**

**LL(1) parsing** is a type of ==top-down parsing== that uses **Leftmost Derivation**. It is called LL(1) because it scans the input **L**eft-to-right, constructs a **L**eftmost derivation, and ==uses **1** lookahead symbol== to make parsing decisions.

**6.1. LL(1) Parsing Table Construction**

LL(1) parsers also use a **parsing table** to guide their decisions. The LL(1) parsing table is constructed using ==**FIRST and FOLLOW sets** of grammar symbols.==

* The table has ==**non-terminals as rows**== and ==**terminals (including `$`) as columns**.==
* For each production `A -> α`, the production `A -> α` is placed in the table entry `M[A, a]` for every terminal `a` in `FIRST(α)`.
* If `FIRST(α)` contains **epsilon (`ε`)**, then for every terminal `b` in `FOLLOW(A)`, the production `A -> α` is also placed in `M[A, b]`. The epsilon production itself does not act as a column, but its follow set determines its placement.

**6.2. LL(1) Grammar Detection**

\==A grammar is an **LL(1) grammar** if== and only if its LL(1) parsing table contains ==**at most one entry in each cell**.==

* If any cell in the parsing table contains ==**multiple production entries**, it indicates an ambiguity ==or conflict, and the grammar is **not an LL(1) grammar**. This is the primary way to detect if a grammar is LL(1).

**Example of an LL(1) Table (Conceptual)**: For a production `S -> aA | bB`

* `FIRST(aA) = {a}`
* `FIRST(bB) = {b}` The table would have `S -> aA` in `M[S, a]` and `S -> bB` in `M[S, b]`. No conflicts here.

**Example of a non-LL(1) Grammar**: `S -> A | B` `A -> a` `B -> a` `FIRST(A) = {a}`, `FIRST(B) = {a}`. When constructing the table, `M[S, a]` would try to place both `S -> A` and `S -> B`, leading to multiple entries in one cell, making it not LL(1).

**6.3. Relationship between LL(1) and LR Parsers**

There's a relationship between Top-Down (LL(1)) and Bottom-Up (LR) parsers:

* **Every LL(1) grammar is also a CLR(1) grammar**.
* However, a CLR(1) grammar is not necessarily an LL(1) grammar.
* This means **LR parsers (especially CLR(1)) are generally more powerful than LL(1) parsers**.

### **7. Syntax Directed Translation (SDT)**

**Syntax Directed Translation (SDT)** involves associating **semantic rules** with grammar productions. The combination of a Context-Free Grammar (CFG) and a set of semantic rules is called an SDT or a **Syntax Directed Definition (SDD)**.

**7.1. Purpose of SDT**

SDTs are theoretical frameworks used to facilitate various phases of compilation:

* **Semantic Analysis**: SDTs can be used to perform **semantic error detection** (e.g., type checking, ensuring variables are declared before use).
* **Intermediate Code Generation**: SDTs are instrumental in **generating intermediate code** (e.g., three-address code).
* **Symbol Table Construction**: SDTs can guide the **complete construction of the symbol table**.

**7.2. SDT Structure and Evaluation**

An SDT explicitly specifies a relationship between the grammar's syntactic structure and the meaning (semantics) of the language. Each grammar production rule `A -> alpha` is associated with a semantic rule.

**Example of SDT (Conceptual)**: `E -> E + T { E.val = E.val + T.val }` `E -> T { E.val = T.val }` `T -> id { T.val = id.value }`

Here, `.val` is an **attribute**, and the rules specify how these attributes are computed.

**Evaluation of SDTs (Annotated Parse Tree)**: To evaluate an SDT for a given input string:

1. **Construct a Parse Tree**: First, build the parse tree for the input string using the grammar productions.
2. **Create an Annotated Parse Tree**: This is a parse tree where **attribute values are computed and attached to the nodes** based on the semantic rules.
3. **Evaluate Attributes**: Traverse the parse tree and execute the semantic rules associated with each production used to build the tree. The order of execution depends on the type of attributes and the specific SDT.

**Example Walkthrough (from source)**: Input: `A + B` Rules for calculating value based on some rules: `id.val` is the value of the identifier. Suppose `A.val = 1`, `B.val = 2`. Rule: `E -> E + T { E.val = E.val + T.val }`

1. Construct parse tree for `A + B`.
2. At the leaf nodes for `A` and `B`, assign their respective `val` attributes (e.g., `A.val = 1`, `B.val = 2`).
3. When reducing `id` to `T`, `T.val` gets `id.val` (e.g., `T.val = 1` for `A`, `T.val = 2` for `B`).
4. When reducing `T` to `E`, `E.val` gets `T.val` (e.g., `E.val = 1` for first `E`).
5. Finally, for `E -> E + T`, the rule `E.val = E.val + T.val` is applied. If first `E.val` is 1 and `T.val` (from B) is 2, then `E.val` becomes `1 + 2 = 3`.

**Translation Schemes**: SDTs where semantic actions (rules) are embedded within the right-hand side of productions are called **Translation Schemes**. These actions can appear at the beginning, middle, or end of a production.

* To evaluate such a scheme, construct the parse tree, treating the semantic actions as special nodes. Then, perform a **Depth-First Search (DFS) traversal from left to right** on the parse tree. The actions are executed in the order they are encountered during this traversal.

**7.3. Attributes**

Attributes are values associated with grammar symbols that carry semantic information.

* **Synthesised Attributes**: The value of a synthesised attribute at a node is computed **from the values of its children nodes** in the parse tree.
  * **Example**: In `E.val = E1.val + T.val`, `E.val` is synthesised from `E1.val` and `T.val` (its children).
* **Inherited Attributes**: The value of an inherited attribute at a node is computed **from the values of its parent node or its left sibling nodes** in the parse tree.
  * **Example**: If a variable's type is inherited from its parent scope.

**Attribute Definitions**: SDTs are classified based on the types of attributes they use:

* **S-attributed Definition**: An SDT that uses **only synthesised attributes**.
* **L-attributed Definition**: An SDT where attributes are either synthesised, or inherited such that the inherited attribute of a symbol depends only on the values of attributes of its parent, or its left siblings (or the attributes of the symbol itself, inherited from left siblings).

### **8. Intermediate Code Generation**

The **Intermediate Code Generation** phase ==translates the source program into an intermediate representation== that is easier to process for optimisation and target code generation.

**8.1. Advantages of Intermediate Code**

* **Machine Independence**: It is machine-independent, making the compiler more portable.
* **Optimisation**: It provides a suitable level for performing various code optimisations.
* **Target Code Generation**: It ==simplifies the process== of generating the final target code.

**8.2. Types of Intermediate Code**

* \==**Syntax Tree**:== A hierarchical representation where internal ==nodes represent operations== and ==leaf nodes represent operands==. Each sub-expression forms a separate subtree.
  * **Example**: For `a + b * c - b * c`

```
         -
       /  \
      +     *
     / \   / \
    a  *  b   c
      / \
     b   c
```

* \==**Directed Acyclic Graph (DAG)**:== Similar to a syntax tree, but ==**common sub-expressions are identified and shared**== (represented by a single node) rather than being duplicated. This helps in identifying opportunities for optimisation.
  * **Example**: For `a + b * c - b * c`

```
        -
       /  \
      +    |
     / \   |
    a   * /  
       / \
      b   c
```

Note: Expression: `a + b * c - b * c`

* It contains **two occurrences** of `b * c`.
* But both are **identical in computation** → same operands, same operator.
* In DAG, We **don’t duplicate** `b * c` and **reuse** the same `*` node with `b` and `c` as children
* \==**Three-Address Code (TAC)**:== A linear sequence of instructions, where each instruction typically involves **at most three addresses** (two operands and one result). Temporary variables are often used to store intermediate results.
  * **Example**: For `x = y + z * w`, TAC might be: `t1 = z * w` `t2 = y + t1` `x = t2`
  * Unlike DAGs, **common sub-expressions are generally&#x20;**_**not**_**&#x20;eliminated** in raw three-address code; they appear as separate instructions.
* **Static Single Assignment (SSA) Form**: A variation of three-address code where each variable is assigned a value **exactly once**. This simplifies dataflow analysis for optimisations.

**8.3. Three-Address Code for Control Flow**

Three-address code can also represent control flow statements like `if-else`, `for` loops, and `while` loops using jump instructions (e.g., `goto`, `if_false goto`).

### **9. Code Optimisation**

The **Code Optimisation** phase aims to improve the intermediate code's efficiency without changing its meaning. It often focuses on reducing execution time, memory usage, or power consumption.

Key concepts in code optimisation include:

* **Basic Blocks**: A sequence of consecutive statements in which ==flow of control enters at the beginning and leaves only at the end==. They have exactly one entry point and exactly one exit point.
* **Control Flow Graph (CFG)**: A graphical representation of the basic blocks and the possible paths of execution (control flow) between them.
* **Liveness Analysis**: A **data-flow** analysis technique that determines, for each point in the program, which variables will be used (are "live") after that point.

### **Conclusion and General Advice**

Compiler design involves understanding the intricate interplay between its various phases, from tokenisation to code generation. For GATE preparation, it is crucial to ==focus on the core concepts:==

* **Token generation and lexical errors**.
* **Parsing**: Especially the working of ==**bottom-up (LR) parsers**==, ==LR item construction==, and ==**conflict detection (SR, RR)** ==for LR(0), SLR(1), CLR(1), and LALR(1) grammars. Understanding the **power hierarchy of LR parsers** is also important.
* **Top-down ==(LL(1)) parsing table construction==** and **LL(1) grammar detection**.
* **Syntax Directed Translation**: Evaluating SDTs using parse trees and understanding synthesised/inherited attributes.
* **Intermediate Code Generation**: Constructing **DAGs** and writing **Three-Address Code** for expressions and control flow.
* **Code Optimisation**: Basic understanding of **basic blocks** and **control flow graphs**.

**Important advice for GATE preparation**:

* **Prioritise Revision**: Focus on thoroughly revising concepts you have already studied. Avoid starting new, complex topics in the last week before the exam.
* **Solve Previous Year Questions (PYQs)**: PYQs are **extremely important** for Compiler Design. Solving them will give you insight into the types of questions asked and the common pitfalls.
* **Stay Confident**: Don't get discouraged by a few difficult questions; it's normal. Focus on what you know well.
