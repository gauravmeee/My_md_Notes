
# Principles of Programming Languages

| Topics                   | Subtopics                 |
| ------------------------ | ------------------------- |
| History & Classification | Paradigms                 |
| Data Abstraction         | Encapsulation and ADTs    |
| Syntax & Semantics       | Grammar and meaning       |
| Type Systems             | Static, dynamic typing    |
| Language Evaluation      | Design and implementation |
# History & Classification of Programming Languages

## History of Programming Languages

1. **Machine Language (1st Generation)**
    
    - Consists of binary instructions (0s and 1s) executed directly by CPU.
        
    - Hardware dependent, difficult to program and debug.
        
    - Example: `10110000 01100001`
        
2. **Assembly Language (2nd Generation)**
    
    - Uses mnemonics instead of binary codes.
        
    - Requires assembler to convert to machine code.
        
    - Example: `MOV A, B`
        
    - Easier than machine language but still hardware specific.
        
3. **High-Level Languages (3rd Generation)**
    
    - Closer to human language, machine-independent.
        
    - Needs compiler or interpreter for translation.
        
    - Examples: FORTRAN, COBOL, BASIC, C, Pascal.
        
4. **Very High-Level Languages (4th Generation)**
    
    - Focus on problem-solving, less coding effort.
        
    - Often domain-specific.
        
    - Examples: SQL, MATLAB, R, SAS.
        
5. **Object-Oriented & Modern Languages (5th Generation)**
    
    - Emphasize objects, reusability, AI & logic-based design.
        
    - Examples: C++, Java, Python, Prolog.
        

---

## Classification of Programming Languages

1. **Based on Programming Paradigm**
    
    - **Imperative Languages:**  
        Describe _how_ to perform tasks using statements that change program state.  
        Examples: C, Pascal.
        
    - **Declarative Languages:**  
        Describe _what_ the program should accomplish, not how.  
        Examples: SQL, Prolog.
        
2. **Based on Abstraction Level**
    
    - **Low-Level:** Machine and Assembly languages.
        
    - **High-Level:** C, Java, Python.
        
    - **Very High-Level:** SQL, MATLAB.
        
3. **Based on Execution Method**
    
    - **Compiled Languages:** Entire code translated before execution. (C, C++)
        
    - **Interpreted Languages:** Line-by-line translation during execution. (Python, JavaScript)
        
4. **Based on Application Domain**
    
    - **System Programming Languages:** C, C++.
        
    - **Scientific/Engineering:** FORTRAN, MATLAB.
        
    - **Business Applications:** COBOL.
        
    - **Web Development:** JavaScript, PHP.
        
    - **AI/Logic Programming:** Lisp, Prolog.
        

---

## Evolution Trend

- Shift from hardware-dependent → machine-independent.
    
- From procedural → object-oriented → functional and declarative paradigms.
    
- Emphasis on reusability, modularity, portability, and safety.

---
---

# Data Abstraction and Data Structures

## Data Abstraction

- **Definition:** Process of hiding internal implementation details and showing only essential features.
    
- **Purpose:** Simplifies programming by focusing on _what_ an object does rather than _how_ it does it.
    

### Levels of Data Abstraction

1. **Physical Level:**  
    Describes how data is actually stored (files, memory layout).
    
2. **Logical Level:**  
    Describes what data is stored and relationships among data (schemas, classes).
    
3. **View Level:**  
    Describes only part of the database relevant to a user (interfaces, APIs).
    

### Benefits

- Reduces complexity
    
- Increases reusability and maintainability
    
- Enables modularity and encapsulation
    

### Example (C++)

```cpp
class Stack {
private:
    int arr[100], top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
};
```

Here, user interacts via `push()` and `pop()` without knowing internal implementation → _abstraction_.

---

## Data Structures

- **Definition:** Organized way to store, manage, and access data efficiently.
    
- **Types:**
    
    1. **Primitive:** int, float, char, bool
        
    2. **Non-Primitive:** Arrays, Linked Lists, Stacks, Queues, Trees, Graphs, Hash Tables
        

### Linear Data Structures

- **Array:** Contiguous memory; random access.
    
- **Linked List:** Dynamic size; sequential access via pointers.
    
- **Stack:** LIFO; operations – push(), pop().
    
- **Queue:** FIFO; operations – enqueue(), dequeue().
    

### Non-Linear Data Structures

- **Tree:** Hierarchical structure with root and child nodes.
    
- **Graph:** Set of nodes (vertices) connected by edges; can represent networks.
    

### Applications

- Arrays → Static data storage
    
- Linked List → Dynamic memory allocation
    
- Stack → Function call management, expression evaluation
    
- Queue → Scheduling, buffering
    
- Tree → Hierarchical databases, parsing
    
- Graph → Routing, social networks
    

---

## Relationship Between Abstraction & Data Structures

- Data abstraction defines _interface_; data structure defines _implementation_.
    
- Example: Abstract Data Type (ADT) like Stack can be implemented using array or linked list.

---
---


# Syntax and Semantics of Programming Languages

## Syntax

- **Definition:** Set of rules defining the structure and form of valid statements in a programming language.
    
- **Purpose:** Specifies _how_ programs must be written.
    
- **Described by:** Grammars (often BNF – Backus-Naur Form).
    

### Example (C++)

```cpp
int sum(int a, int b) { return a + b; }
```

Syntax specifies keywords, punctuation, and order of tokens.

### Types of Syntax Rules

1. **Lexical Rules:** Define valid tokens (identifiers, literals, operators).
    
2. **Grammatical Rules:** Define how tokens combine into expressions, statements, and programs.
    

### Syntax Errors

- Violations of grammatical structure detected by compiler’s parser.  
    Example: Missing semicolon, unmatched braces.
    

---

## Semantics

- **Definition:** Defines the _meaning_ of syntactically correct statements.
    
- **Purpose:** Explains what a valid statement actually does during execution.
    

### Types of Semantics

1. **Static Semantics:**  
    Rules checked at compile time (type checking, declaration before use).  
    Example: Assigning string to integer variable.
    
2. **Dynamic Semantics:**  
    Describes meaning during execution (control flow, variable binding).  
    Example: Runtime behavior of loops and function calls.
    

### Example

```cpp
int a = 5, b = 2;
int c = a / b;
```

- **Syntax:** Expression `a / b` is valid.
    
- **Semantics:** Division of integers results in integer (2), not 2.5.
    

---

## Syntax vs Semantics

|Aspect|Syntax|Semantics|
|---|---|---|
|Meaning|Structure/grammar|Behavior/meaning|
|Checked by|Parser|Semantic analyzer/interpreter|
|Error Type|Syntax error|Logical/runtime error|
|Example Error|Missing semicolon|Wrong computation result|

---

## Relation

- Syntax ensures correct _form_ of code.
    
- Semantics ensures correct _meaning_ of code.
    
- Both together define the complete specification of a programming language.

---
---


# Types in Programming Languages (Features / Design / Implementation)

## Definition

A **type** defines a set of values and operations that can be performed on those values.  
It provides a way to classify data and ensure correctness of operations in a program.

---

## Features of Types

1. **Type Safety:** Prevents operations on incompatible data (e.g., adding int + string).
    
2. **Type Checking:** Ensures operations follow type rules.
    
3. **Type Conversion (Casting):** Allows conversion between compatible types.
    
4. **Polymorphism:** Enables one interface to handle multiple data types.
    
5. **Type Inference:** Compiler deduces data type automatically (e.g., `auto` in C++).
    
6. **Type Equivalence:** Determines when two types are considered the same (name vs structure equivalence).
    

---

## Type System Design Issues

1. **Primitive Types:**
    
    - Basic built-in types (int, float, char, bool).
        
2. **Composite (Structured) Types:**
    
    - Formed by combining primitive types.
        
    - Examples: Arrays, Structures, Classes, Records.
        
3. **Abstract Types:**
    
    - User-defined types that encapsulate data and operations (e.g., ADTs, classes).
        
4. **Strong vs Weak Typing:**
    
    - **Strongly Typed:** Prevents implicit conversions (Java, Python).
        
    - **Weakly Typed:** Allows implicit conversions (C, JavaScript).
        
5. **Static vs Dynamic Typing:**
    
    - **Static Typing:** Type checked at compile time (C, C++).
        
    - **Dynamic Typing:** Type checked at runtime (Python, JavaScript).
        

---

## Type Implementation

1. **Type Representation:**
    
    - Determines how types are stored in memory (size, alignment, encoding).
        
    - Example: `int` (4 bytes), `float` (4 bytes), `double` (8 bytes).
        
2. **Type Checking Mechanisms:**
    
    - **Compile-Time:** Detects mismatches early (faster, safer).
        
    - **Run-Time:** More flexible but slower.
        
3. **Type Conversion Mechanisms:**
    
    - **Implicit (Coercion):** Done automatically by compiler.
        
    - **Explicit (Casting):** Programmer-specified.
        

### Example (C++)

```cpp
int a = 5;
double b = 2.5;
double c = a + b;   // implicit conversion of int → double
int d = (int)b;     // explicit conversion
```

---

## Importance of Type Systems

- Ensures **program correctness** and **safety**
    
- Enables **compiler optimization**
    
- Facilitates **readability and maintainability**
    
- Prevents **runtime errors** and **unexpected behaviors**