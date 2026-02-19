---
description: Made By Me 💚
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

# CD Important Concepts

## Compiler

#### Parts of Compiler

1. **Frontend** focuses on **analysis** of the source code (language-specific) to check correctness and produce an **Intermediate Representation (IR)** independent of hardware.
2. **Backend** focuses on **synthesis** – converting IR into optimized machine code for a specific target architecture.

**1. Frontend**

Responsible for **analyzing the source code** (syntax + semantics)

* **Lexical Analysis**\
  → Converts code into tokens\
  → Done by **Lexer / Scanner**
* **Syntax Analysis**\
  → Checks grammar (CFG)\
  → Builds **Parse Tree / Syntax Tree**\
  → Done by **Parser**
* **Semantic Analysis**\
  → Checks for semantic correctness (type checks, undeclared vars)\
  → Uses **Symbol Table**
* **Intermediate Code Generation (ICG)**\
  → Converts code to intermediate representation (IR) like **Three Address Code (TAC)**

**2. Backend**

Responsible for **optimizing and converting IR to target code**

* **Code Optimization**\
  → Improves IR for performance (speed, memory)\
  → e.g., Constant Folding, Dead Code Elimination
* **Code Generation**\
  → Converts IR to **Machine Code / Assembly**
* **Code Linking & Assembly** ❌ → Combines code with libraries and prepares executable

| Phase                 | Part     | Task                        |
| --------------------- | -------- | --------------------------- |
| Lexical Analysis      | Frontend | Tokenization                |
| Syntax Analysis       | Frontend | Parse Tree creation         |
| Semantic Analysis     | Frontend | Type checking, Symbol Table |
| Intermediate Code Gen | Frontend | Generate IR                 |
| Optimization          | Backend  | Improve IR                  |
| Code Generation       | Backend  | Generate Machine Code       |
| Linking & Assembly ❌  | Backend  | Final Executable            |

***

**Error Detection and Code Generation**

**First Three Phases – Used for: ==Error Detection==**

1. **Lexical Analysis**\
   → Detects **lexical errors** (invalid tokens, unknown symbols)
2. **Syntax Analysis**\
   → Detects **syntax errors** (missing brackets, wrong structure)
3. **Semantic Analysis**\
   → Detects **semantic errors** (type mismatches, undeclared variables)

**Remaining Phases – Used for: ==Code Generation== & Optimization** 4. **Intermediate Code Generation** – Platform-independent code 5. **Code Optimization** – Improves performance 6. **Code Generation** – Machine code 7. **Linking & Assembly** – Final executable ❌

> **In most compiler design syllabi (e.g., GATE, SJVN, etc.)**, the last phase **Linking & Assembly** is **not explicitly included**.

***

## Lexical Anaylser

#### Characters

**Keyword vs Identifier in C++**

**1. Keywords (Predefined Words)**

* Reserved by the language.
* Cannot be used as names.
* **Examples:** `int`, `if`, `else`, `while`, `return`

**2. Identifiers**

* **a. Predefined Identifiers** _(from libraries)_
  * Provided by the C++ Standard Library.
  * Not keywords but act as names for predefined objects/functions.
  * **Examples:**
    * **Object** - `cin`, `cout`
    * **Function** - `sort()`, `strlen()`
    * **Manipulator** - `endl`, `setw()`
* **b. User-Defined Identifiers**
  * Created by the programmer.
  * Used for variables, functions, classes, etc.
  * **Example:**
    * **Variable** - `sum`, `Student`
    * **Function -** `main()`, `calculate()`

***

***

## Syntax Analyser

#### Grammar

**Non-Terminal vs Terminal – Real C++ Example**

\*\*In the statement:

```sh
int a = b + 5;
```

| **Non-Terminal** | **Replaced By (Terminal / Expression)** |
| ---------------- | --------------------------------------- |
| `DeclStmt`       | `int a = b + 5 ;`                       |
| `Type`           | `int`                                   |
| `Identifier`     | `a`, `b`                                |
| `Expr`           | `b + 5`                                 |
| `Number`         | `5`                                     |
| `Operator`       | `+`                                     |

* **Non-terminals** are grammar symbols (e.g., `Expr`, `DeclStmt`)
* **Terminals** are actual C++ tokens (e.g., `int`, `a`, `+`, `5`, `;`)\
  Non-terminals get **replaced** by terminals and other non-terminals during parsing.

***

#### Parser Algorithms

**1. Top-Down Parsers**

* Start from the **start symbol** and try to derive the input string.
* Work by **expanding non-terminals**.
* Follow **Left-to-Right scan** and **Leftmost derivation**.

| **Top-Down Parser Type** | **Description**                         |
| ------------------------ | --------------------------------------- |
| **LL Parsers**           | Left-to-right scan, Leftmost derivation |

**LL Parsers Subtypes**

| **Type**              | **Full Form / Explanation**                                                     |
| --------------------- | ------------------------------------------------------------------------------- |
| **LL(1)**             | Left-to-right scan, Leftmost derivation with **1 lookahead** symbol             |
| **LL(k)**             | Left-to-right scan, Leftmost derivation with **k lookahead** symbols            |
| **Recursive Descent** | Manually written parser, uses recursive functions for each non-terminal (LL(k)) |
| **Predictive Parser** | Non-recursive LL(1) parser using a parsing table (no backtracking)              |

**2. Bottom-Up Parsers**

* Start from the **input string** and try to **reduce** it to the start symbol.
* Work by **shifting and reducing symbols** on a stack.
* Follow **Left-to-Right scan** and **Rightmost derivation in reverse**.

| **Bottom-Up Parser Type**         | **Description**                              |
| --------------------------------- | -------------------------------------------- |
| **1. Shift-Reduce Parser**        | Basic bottom-up parser using stack + actions |
| **2. Operator Precedence Parser** | Uses precedence relations to guide parsing   |
| **3. LR Parsers**                 | Most powerful deterministic parsers          |

**LR Parsers Subtypes**

| **Type** | **Full Form / Explanation**                            |
| -------- | ------------------------------------------------------ |
| **SLR**  | Simple LR – based on FOLLOW sets                       |
| **LALR** | Look-Ahead LR – optimized for size, same states as SLR |
| **CLR**  | Canonical LR / LR(1) – uses full lookahead, largest    |

> **LL Parsers** → **Top-Down**, Left-to-right scan + **Leftmost derivation**\
> **LR Parsers** → **Bottom-Up**, Left-to-right scan + **Rightmost derivation (in reverse)**

***

#### Parser Types and Lookahead Meaning

The value inside parentheses `(k)` denotes **number of lookahead symbols** used while making parsing decisions.

**LL(k) Parser**

* **L** → Scans input from Left to right
* **L** → Produces Leftmost derivation
* **(k)** → Uses _k_ lookahead symbols
* Common: **LL(1)** → Predictive or Recursive Descent Parser

**LR(0) Parser**

* **L** → Scans input from Left to right
* **R** → Produces Rightmost derivation in reverse
* **(0)** → Uses 0 lookahead symbols
* Simplest LR parser but least powerful

**SLR(1) Parser** (Simple LR)

* **L** → Scans input from Left to right
* **R** → Produces Rightmost derivation in reverse
* **(1)** → Uses 1 lookahead symbol
* Based on **LR(0)** items + **FOLLOW sets** for reduce decisions
* Easier to construct but less powerful

**LALR(1) Parser** (Look-Ahead LR)

* **LA** → Look-Ahead
* **L** → Scans input from Left to right
* **R** → Produces Rightmost derivation in reverse
* **(1)** → Uses 1 lookahead symbol
* Combines states of **LR(1)** having same core
* Smaller table than LR(1), same power for most grammars
* Used in **YACC**, **Bison**

**Canonical LR(1) Parser**

* **Canonical** → full, unmerged, standard form with **all LR(1) items distinct**.
* **L** → Scans input from Left to right
* **R** → Produces Rightmost derivation in reverse
* **(1)** → Uses 1 lookahead symbol
* Most general and powerful LR parser
* Builds separate states for each unique lookahead
* Large table size, but handles all deterministic context-free grammars

| Parser          | Derivation | Parsing Type | Lookahead | Power           | Remarks                 |
| --------------- | ---------- | ------------ | --------- | --------------- | ----------------------- |
| LL(1)           | Leftmost   | ==Top-down== | 1         | Medium          | Predictive parser       |
| LR(0)           | Rightmost  | Bottom-up    | ==0==     | ==Weak==        | Simple, less practical  |
| SLR(1)          | Rightmost  | Bottom-up    | 1         | Medium          | Uses FOLLOW sets        |
| LALR(1)         | Rightmost  | Bottom-up    | 1         | ==Strong==      | Efficient & widely used |
| Canonical LR(1) | Rightmost  | Bottom-up    | 1         | ==Very Strong== | Large tables            |
