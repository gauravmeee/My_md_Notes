---
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

# Symbol Table

## 1. Definition

A **Symbol Table** is a data structure used by a compiler to store information about identifiers encountered during compilation.

> **Identifier** → variable names, function names, class names, array names, etc.

Each entry in a symbol table contains:

* Name of identifier
* Type (int, float, function, array, etc.)
* Scope (local, global, block)
* Memory location / offset
* Size
* Additional attributes (parameters, return type, access specifier, etc.)

***

## 2. Purpose of Symbol Table

Symbol table helps the compiler to:

* Check **semantic correctness**
* Perform **type checking**
* Detect **undeclared variables**
* Detect **multiple declarations**
* Allocate **memory**
* Support **scope resolution**

***

## 3. Operations on Symbol Table

### 3.1 Insert

* Adds a new identifier entry
* Error if identifier already exists in same scope

### 3.2 Lookup (Search)

* Finds an identifier
* Searches current scope first, then outer scopes

### 3.3 Delete

* Removes identifiers when scope ends

### 3.4 Update

* Modifies attributes like value, type, memory address

***

## 4. Information Stored in Symbol Table

| Field      | Description         |
| ---------- | ------------------- |
| Name       | Identifier name     |
| Type       | Data type           |
| Scope      | Level of visibility |
| Address    | Memory location     |
| Size       | Memory required     |
| Line No    | Declaration line    |
| Parameters | For functions       |

***

## 5. Symbol Table Implementation Techniques

### 5.1 Linear List (Array / Linked List)

* Simple implementation
* Search time: `O(n)`

**Advantages**

* Easy to implement

**Disadvantages**

* Slow lookup

***

### 5.2 Binary Search Tree (BST)

* Identifiers stored in lexicographical order
* Average search time: `O(log n)`
* Worst case: `O(n)` (skewed tree)

**Advantages**

* Sorted order maintained

**Disadvantages**

* Unbalanced BST degrades performance

***

### 5.3 Balanced BST (AVL / Red-Black Tree)

* Self-balancing
* Search/Insert/Delete: `O(log n)`

**Used when** ordering + performance both required

***

### 5.4 Hash Table (Most Common)

* Identifier → hash function → index
* Average search: `O(1)`
* Worst case: `O(n)` (collision)

**Collision Resolution**

* Chaining
* Open Addressing (Linear / Quadratic / Double Hashing)

**Why preferred?**

* Fast lookup
* Efficient for large symbol tables

***

## 6. Scope Handling in Symbol Table

### 6.1 Scope Rules

* Inner scope hides outer scope identifiers
* Local variables have higher priority

### 6.2 Implementation Methods

#### (a) Separate Symbol Table per Scope

* New table for each block
* Tables destroyed when scope ends

#### (b) Stack of Symbol Tables

* Push on scope entry
* Pop on scope exit

#### (c) Single Table with Scope Level

* Each entry has scope number
* Highest scope searched first

***

## 7. Static vs Dynamic Scoping

| Static Scoping                | Dynamic Scoping          |
| ----------------------------- | ------------------------ |
| Scope decided at compile time | Scope decided at runtime |
| Used in C, C++, Java          | Rarely used              |
| Symbol table sufficient       | Requires runtime stack   |

***

## 8. Errors Detected Using Symbol Table

* Undeclared variable
* Multiple declarations
* Type mismatch
* Function argument mismatch
* Scope violation

***

## 9. Symbol Table vs Literal Table

| Symbol Table        | Literal Table        |
| ------------------- | -------------------- |
| Stores identifiers  | Stores constants     |
| Created by compiler | Created by assembler |

***

## 10. GATE Exam-Oriented Points ⭐

* Hash table is **most preferred** implementation
* BST gives sorted order but may degrade
* Balanced BST ensures `O(log n)` time
* Symbol table is mainly used in **semantic analysis**
* Scope handling is frequently asked

***

## 11. Frequently Asked GATE Questions

1. Which data structure is best for symbol table? → **Hash Table**
2. Can symbol table be implemented using BST? → **Yes**
3. Which compiler phase uses symbol table? → **Lexical + Semantic Analysis**
4. When are entries deleted? → **At scope exit**

***

## 12. One-Line Definition for GATE

> **Symbol Table is a compiler data structure that stores information about identifiers and supports efficient lookup, insertion, and scope management during compilation.**

***

### Want PYQs + memory tricks + diagrams next? 😄
