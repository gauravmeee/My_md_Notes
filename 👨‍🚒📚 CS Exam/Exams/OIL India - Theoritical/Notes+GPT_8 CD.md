
# Compiler Design

|     | Topics                      | Subtopics                  |
| --- | --------------------------- | -------------------------- |
| 1   | Syntax Analysis             | Parsers (LL, LR)           |
| 2   | Semantic & Lexical Analysis | Tokens, symbol tables      |
| 3   | Intermediate Code           | Representation, generation |
| 4   | Type Systems                | Checking and inference     |
| 5   | Error Handling              | Detection and recovery     |

# 1. Syntax Analysis (Parser)

## Definition

Syntax analysis is the second phase of a compiler that checks whether the tokens form a valid syntactic structure according to the grammar of the language. It takes input from the lexical analyzer and outputs a parse tree.

## Role of Parser

- Detects syntax errors
    
- Reports meaningful error messages
    
- Produces a parse tree or abstract syntax tree (AST)
    

## Grammar

- Defined using **Context-Free Grammar (CFG)**.
    
- Grammar G = (V, T, P, S)
    
    - V: Variables/Non-terminals
        
    - T: Terminals
        
    - P: Productions
        
    - S: Start symbol
        

## Types of Parsers

1. **Top-Down Parsing**
    
    - Starts from start symbol and tries to derive the input string.
        
    - Example: Recursive Descent, LL(1) Parser
        
    - Problems: Left recursion and backtracking
        
2. **Bottom-Up Parsing**
    
    - Starts from input string and reduces it to the start symbol.
        
    - Example: Shift-Reduce, LR(0), SLR(1), LALR(1), Canonical LR(1)
        

## Top-Down Parsing

### Recursive Descent Parser

- Uses a set of recursive procedures.
    
- Works for grammars without left recursion.
    

### LL(1) Parser

- Uses one input symbol of lookahead.
    
- Table-driven parser with **Predictive Parsing Table (M[A, a])**.
    
- Conditions:
    
    - Grammar must be left-factored and free from left recursion.
        

## Bottom-Up Parsing

### Shift-Reduce Parser

- Uses a stack and input buffer.
    
- Operations: Shift, Reduce, Accept, Error
    
- Handles most programming constructs efficiently.
    

### LR Parsers

- Most powerful deterministic parsers.
    
- Constructed using LR parsing tables (ACTION, GOTO).
    
- Types:
    
    - **LR(0):** No lookahead symbol.
        
    - **SLR(1):** Uses FOLLOW sets for reductions.
        
    - **LALR(1):** Merges similar LR(1) states (used in YACC).
        
    - **Canonical LR(1):** Most powerful but large tables.
        

## Error Recovery Strategies

- **Panic Mode:** Skip tokens until a synchronizing token is found.
    
- **Phrase Level:** Perform local correction.
    
- **Error Productions:** Add error rules to grammar.
    
- **Global Correction:** Find minimum number of changes to make string valid.
    

## Parse Tree vs Abstract Syntax Tree (AST)

- **Parse Tree:** Represents complete grammatical structure.
    
- **AST:** Removes redundant information, focuses on semantics.
    

## Example

Grammar:

```
E → E + T | T  
T → T * F | F  
F → (E) | id
```

For input `id + id * id`, parse tree shows hierarchical structure of expressions.

---
---

# Lexical Analysis

## Definition

Lexical analysis is the first phase of a compiler that converts a stream of characters into a stream of tokens.  
It acts as an interface between source code and the parser.

## Role of Lexical Analyzer

- Reads source program character by character.
    
- Groups characters into lexemes and produces tokens.
    
- Removes whitespace and comments.
    
- Maintains symbol table entries for identifiers and literals.
    

## Tokens, Lexemes, Patterns

- **Token:** A pair (token-name, attribute-value).  
    Example: `<id, 1>`
    
- **Lexeme:** Actual substring that matches a token pattern.
    
- **Pattern:** Rule describing the structure of a lexeme.
    

## Functions of Lexical Analyzer

- Tokenization
    
- Removal of whitespace & comments
    
- Error detection (invalid characters)
    
- Symbol table management
    
- Communication with syntax analyzer
    

## Tools

- **Lex / Flex:** Automatic lexical analyzer generators.
    

## Implementation

- **Finite Automata (FA):** Used to recognize regular expressions.
    
    - Regular Expression → NFA → DFA → Minimization.
        

## Error Handling

- **Panic Mode:** Skip characters until a valid token is found.
    
- **Repair Mode:** Insert/delete minimal characters to correct token.
    

---

# 2. Semantic Analysis

## Definition

Semantic analysis is the third phase of compilation that checks for **meaningful correctness** of the program.  
It uses information from syntax analysis and symbol tables.

## Role

- Checks semantic rules not captured by syntax (context-sensitive).
    
- Ensures type correctness and variable usage validity.
    

## Key Tasks

- **Type Checking:** Ensures operand and operator compatibility.
    
- **Scope Resolution:** Verifies variable declarations within scope.
    
- **Identifier Checking:** Detects undeclared/redeclared variables.
    
- **Array Bound Checking (optional).**
    
- **Function Signature Checking:** Arguments, return types match.
    

## Syntax-Directed Translation (SDT)

- Associates semantic rules/actions with grammar productions.
    
- Builds intermediate representations like syntax trees or symbol tables.  
    Example:
    

```
E → E1 + T { E.val = E1.val + T.val }
```

## Attribute Grammar

- Each symbol has attributes (Synthesized, Inherited).
    
- **Synthesized:** Computed from child nodes.
    
- **Inherited:** Computed from parent or sibling nodes.
    

## Type System

- Defines rules for type equivalence, compatibility, and conversion.
    
- **Static Checking:** At compile-time.
    
- **Dynamic Checking:** At run-time.
    

## Intermediate Representation

- Output: Annotated syntax tree or three-address code (TAC).
    

## Error Handling

- **Static Semantic Errors:** Type mismatch, undeclared variable, wrong parameters.
    
- **Recovery:** Use default types or skip erroneous statements.
    

---

---


# 3. Intermediate Code Generation

## Definition

Intermediate Code Generation (ICG) is the fourth phase of the compiler.  
It translates the source program into an **intermediate representation (IR)** that is independent of both source and target machines.

## Role

- Acts as a bridge between front-end (syntax/semantic) and back-end (optimization/code generation).
    
- Makes optimization easier and code generation simpler.
    

## Characteristics of IR

- Easy to produce and manipulate.
    
- Machine-independent but close enough to machine instructions.
    
- Supports optimization effectively.
    

## Types of Intermediate Representations

1. **Syntax Tree / Annotated Syntax Tree**
    
    - Represents structure with operators as internal nodes and operands as leaves.
        
    - Contains semantic information like types or values.
        
2. **Postfix (Reverse Polish) Notation**
    
    - Operator follows operands.
        
    - Example: `a + b * c` → `a b c * +`
        
3. **Three-Address Code (TAC)**
    
    - Each instruction has at most three addresses.
        
    - General form: `x = y op z`
        
    - Example:
        
        ```
        t1 = b * c
        t2 = a + t1
        ```
        
    - Easy for optimization and translation to assembly.
        
4. **Quadruples and Triples**
    
    - **Quadruple:** (op, arg1, arg2, result)
        
    - **Triple:** (op, arg1, arg2) with result implied by position  
        Example:
        
    
    ```
    ( * , b , c , t1 )
    ( + , a , t1 , t2 )
    ```
    

## Types of Operations in TAC

- Assignment: `x = y`
    
- Arithmetic: `x = y op z`
    
- Unary: `x = op y`
    
- Conditional & Unconditional Jumps: `if x relop y goto L1`, `goto L2`
    
- Procedure Calls: `param x`, `call p, n`, `return y`
    
- Array Access: `x = y[i]`, `x[i] = y`
    
- Pointer Access: `x = *y`, `*x = y`
    

## Translation Schemes

- Use **Syntax-Directed Translation** rules to generate TAC from parse tree.  
    Example:
    

```
E → E1 + T { E.place = newtemp()
             emit(E.place = E1.place + T.place) }
```

## Temporary Variables

- Used to store intermediate results.
    
- Named as t1, t2, … during code generation.
    

## Control Flow Representation

- **Basic Block:** A sequence of consecutive statements with single entry and exit.
    
- **Flow Graph:** Nodes = basic blocks, Edges = control flow between them.
    

## Advantages of IR

- Easier optimization.
    
- Portability across machines.
    
- Simplifies code generation.
    

---

---

# 4. Type Systems

## Definition

A **type system** is a set of rules that assigns types to various program constructs (variables, expressions, functions) to ensure that operations are applied to compatible operands.  
It enforces **semantic correctness** and prevents type errors.

## Purpose

- Detects errors at compile-time (static checking).
    
- Ensures reliability, safety, and predictability of programs.
    
- Enables compiler optimizations based on type information.
    

## Type Expressions

Used to denote the type of language constructs.  
Examples:

- Basic types: `int`, `float`, `char`, `bool`
    
- Constructed types:
    
    - Array: `array(n, T)`
        
    - Function: `T1 → T2`
        
    - Record: `record(f1:T1, f2:T2, …)`
        
    - Pointer: `pointer(T)`
        

## Type Equivalence

Determines when two types are considered the same.

1. **Name Equivalence:** Two types are equal if they have the same name.
    
2. **Structural Equivalence:** Two types are equal if their structures (fields, types) are identical.
    

## Type Compatibility

Defines when a value of one type can be used in a context expecting another type.

1. **Compatible Types:** Can be implicitly converted (e.g., `int → float`).
    
2. **Incompatible Types:** Require explicit cast or are invalid.
    

## Type Conversion (Coercion)

Automatic conversion between compatible types.  
Example: `int + float → float`

## Type Checking

Verifies type correctness during compilation or execution.

1. **Static Type Checking:** Performed at compile-time.
    
    - Detects most type errors early.
        
    - Languages: C, C++, Java.
        
2. **Dynamic Type Checking:** Performed at run-time.
    
    - More flexible but slower.
        
    - Languages: Python, JavaScript.
        

## Polymorphism

Ability to use a single function or operator for multiple types.

1. **Ad-hoc Polymorphism:** Function/operator overloading.
    
2. **Parametric Polymorphism:** Generic types (e.g., templates in C++).
    
3. **Subtype Polymorphism:** Inheritance-based (e.g., derived class → base class).
    

## Type Inference

Process of deducing the type of an expression automatically without explicit type declarations.  
Used in languages like ML, Haskell, Python.

## Type Safety

A program is **type safe** if it prevents operations on incompatible data types (e.g., adding integer to pointer).

## Example

```
int a = 5;
float b = 3.2;
float c = a + b;  // implicit conversion of int → float
```

---
---


# 5. Error Detection and Recovery

## Definition

Error detection and recovery is the process of identifying and handling errors that occur during compilation so the compiler can continue analyzing the rest of the program without stopping abruptly.

## Types of Errors

1. **Lexical Errors:** Invalid tokens, unrecognized characters.  
    Example: `#var = 10;`
    
2. **Syntax Errors:** Violations of grammar rules.  
    Example: `if (a > b) else`
    
3. **Semantic Errors:** Meaningless constructs or type mismatches.  
    Example: `int a = "abc";`
    
4. **Logical Errors:** Valid syntax but incorrect logic (not caught by compiler).  
    Example: `if (a = b)` instead of `if (a == b)`
    

## Phases Responsible for Error Detection

- **Lexical Analyzer:** Invalid characters or identifiers.
    
- **Syntax Analyzer:** Grammar/syntax structure issues.
    
- **Semantic Analyzer:** Type and scope violations.
    
- **Runtime System:** Errors detected at execution (division by zero, null access).
    

## Error Handling Process

1. Detect the error.
    
2. Report it with precise location and message.
    
3. Attempt recovery to continue analysis.
    

## Error Reporting

An error message should contain:

- Line number
    
- Type of error
    
- Description and possible cause
    

Example:

```
Error: Line 5: Missing semicolon ';' after statement
```

## Error Recovery Strategies

### 1. Panic Mode Recovery

- Discards input symbols until a synchronizing token (like `;` or `}`) is found.
    
- Simple and widely used.
    
- Example: Skip to next semicolon after syntax error.
    

### 2. Phrase Level Recovery

- Makes minimal local corrections (insert/delete tokens) to continue parsing.
    
- Example: Automatically inserting a missing `;` or `)`.
    

### 3. Error Productions

- Extend grammar with rules that handle common errors.
    
- Example:
    
    ```
    Stmt → error ';'
    ```
    

### 4. Global Correction

- Attempts to find the minimal number of changes to make input valid.
    
- Computationally expensive; used rarely in practice.
    

## Error Recovery in Different Phases

- **Lexical:** Skip invalid characters or replace with valid token.
    
- **Syntax:** Use panic mode or phrase-level strategies.
    
- **Semantic:** Use default values or types for undeclared variables.
    
- **Runtime:** Abort execution or handle via exception handling mechanisms.
    

## Example

For incorrect input:

```
if (a > b { c = d; }
```

Parser might use **panic mode** to skip until `}` and resume parsing safely.
