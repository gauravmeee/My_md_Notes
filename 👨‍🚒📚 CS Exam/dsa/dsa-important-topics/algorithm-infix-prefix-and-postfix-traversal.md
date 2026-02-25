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

# Algorithm: Infix, Prefix and Postfix Traversal

**1. Notations Overview**

| Notation | Format Example | Operator Position |
| -------- | -------------- | ----------------- |
| Infix    | `A + B`        | Between operands  |
| Prefix   | `+ A B`        | Before operands   |
| Postfix  | `A B +`        | After operands    |

**2. Why Use Postfix/Prefix?**

* Removes need for **parentheses** ✅
* **Unambiguous** evaluation ✅
* Ideal for **computers & compilers**
* Easily evaluated using **Stacks**

**3. Operator Precedence**

| Operator | Precedence | Associativity |
| -------- | ---------- | ------------- |
| `^`      | 3          | Right to Left |
| `* / %`  | 2          | Left to Right |
| `+ -`    | 1          | Left to Right |

**4. Infix to Postfix Conversion (Using Stack)**

**Steps:**

1. If operand → **add to output**
2. If `(` → **push to stack**
3. If `)` → **pop till `(`**
4. If operator:
   * Pop operators from stack **≥ precedence**
   * Then push current operator

**Example:** `A + B * C`

```
Postfix: A B C * +
```

**Example:** `(A + B) * C`

```
Postfix: A B + C *
```

**5. Infix to Prefix Conversion**

**Steps:**

1. **Reverse** infix string
2. **Replace** `(` with `)`, and vice versa
3. Convert to postfix
4. **Reverse** result → it's prefix

**Example:** `A + B * C`

```
1. Reverse: C * B + A
2. Postfix: C B * A +
3. Reverse: + A * B C
4. Prefix : + A * B C
```

**6. Prefix/Postfix Evaluation (Using Stack)**

**Postfix Evaluation:**

* Scan **left to right**
* Push operands
* On operator → pop 2, apply, push result

**Example:** `5 6 + 2 *`

```
Step 1: 5 → push  
Step 2: 6 → push  
Step 3: + → pop 5, 6 → push 11  
Step 4: 2 → push  
Step 5: * → pop 11, 2 → push 22  
Result = 22
```

**Prefix Evaluation:**

* Scan **right to left**
* Push operands
* On operator → pop 2, apply, push result

**Example:** `* + 5 6 2`

```
Step 1: 2 → push  
Step 2: 6 → push  
Step 3: 5 → push  
Step 4: + → pop 5, 6 → push 11  
Step 5: * → pop 11, 2 → push 22  
Result = 22
```

**7. All Conversion Examples**

| Infix            | Postfix        | Prefix         |
| ---------------- | -------------- | -------------- |
| A + B            | A B +          | + A B          |
| A + B \* C       | A B C \* +     | + A \* B C     |
| (A + B) \* C     | A B + C \*     | \* + A B C     |
| A \* (B + C) / D | A B C + \* D / | / \* A + B C D |

**8. Applications**

* Compilers and Expression Parsing
* Expression evaluation in calculators
* Intermediate code generation
* Abstract syntax trees
