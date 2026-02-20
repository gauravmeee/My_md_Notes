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

# LL(1) Parsing

### FIRST and FOLLOW (Syntax Analysis)

* Used in ==**Top-Down Parsing**==
* Essential for ==**LL(1) grammar**==
* Helps in ==**predictive parsing== ==table construction**==

**Grammar Basics**

* **Terminal (T)**: tokens (`id`, `+`, `*`, `(`, `)`, etc.)
* **Non-terminal (NT)**: variables (`E`, `T`, `F`, etc.)
* **ε (epsilon)**: ==empty string==
* **$**: ==input end== marker
* Grammar: `A → α`

**FIRST Set**

* **FIRST(X)** = ==set of terminals== that can ==appear as the **first symbol**== of any ==string derived from X==

**Rules to Compute FIRST** ⭐

1.  If `X` is a **terminal**

    ```css
    FIRST(X) = {X}
    ```
2.  If `X → ε`

    ```css
    ε ∈ FIRST(X)
    ```
3. If `X → Y1 Y2 ... Yk` ⭐
   * Add `FIRST(Y1) − {ε}` to `FIRST(X)`
   * If `ε ∈ FIRST(Y1)`, then add `FIRST(Y2) − {ε}`
   * Continue until:
     * ε not found, or
     * All `Yi` contain ε → then add ε to FIRST(X)

**Key Points**

* FIRST is about ==**starting terminals**==
* ε only included if whole RHS can derive ε

**FOLLOW Set**

* **FOLLOW(A)** = ==set of terminals== that can ==appear **immediately after A**== in some sentential form

**Rules to Compute FOLLOW** ⭐

1.  If `A` is **start symbol**

    ```css
    $ ∈ FOLLOW(A)
    ```
2.  For production `X → α A β`

    ```css
    FIRST(β) − {ε} ⊆ FOLLOW(A)
    ```
3.  If `X → α A` OR `X → α A β` and `ε ∈ FIRST(β)`

    ```css
    FOLLOW(X) ⊆ FOLLOW(A)
    ```

**Key Points**

* FOLLOW ==depends on **context**==
* FOLLOW never contains ε

**Algorithm (GATE-Oriented)**

1. Initialize all **FIRST** and **FOLLOW** as empty
2. Apply ==FIRST rules== until ==no change==
3. Apply ==FOLLOW rules== iteratively until ==fixed point==

**Example ⭐**

Grammar:

```css
E → T E'
E' → + T E' | ε
T → F T'
T' → * F T' | ε
F → ( E ) | id
```

FIRST:

```css
FIRST(E)  = { (, id }
FIRST(E') = { +, ε }
FIRST(T)  = { (, id }
FIRST(T') = { *, ε }
FIRST(F)  = { (, id }
```

FOLLOW:

```css
FOLLOW(E)  = { ), $ }
FOLLOW(E') = { ), $ }
FOLLOW(T)  = { +, ), $ }
FOLLOW(T') = { +, ), $ }
FOLLOW(F)  = { *, +, ), $ }
```

> **Note:** **X′ (X prime)** is a **new non-terminal** introduced to remove **left recursion** and make the grammar suitable for **LL(1) parsing**

**FIRST of String ⭐**

For string `α = X1 X2 ... Xn`

* FIRST(α) computed same as RHS rule
* Used directly in parsing table

**LL(1) Grammar Condition**

Grammar is LL(1) iff for every non-terminal A:

1.  For `A → α | β`

    ```css
    FIRST(α) ∩ FIRST(β) = ∅
    ```
2.  If `ε ∈ FIRST(α)`

    ```css
    FIRST(β) ∩ FOLLOW(A) = ∅
    ```

**FOLLOW vs LFOLLOW vs RFOLLOW ⭐**

**FOLLOW**

* **FOLLOW(A)** = set of terminals that can appear **immediately after non-terminal A** in some sentential form
* Used in **LL(1) parsing**
* `$ ∈ FOLLOW(start symbol)`
* ε never appears in FOLLOW
* **Example:**

```css
S → A b
A → a | ε
```

```css
FOLLOW(S) = { $ }
FOLLOW(A) = { b }
```

**LFOLLOW (Left FOLLOW)**

* **LFOLLOW(A)** = terminals that can appear **immediately to the left of A**
* Used in **operator precedence / LR parsing concepts**
* Not used in LL(1)
* **Example:**

```css
S → a A
```

```css
LFOLLOW(A) = { a }
```

**RFOLLOW (Right FOLLOW)**

* **RFOLLOW(A)** = terminals that can appear **immediately to the right of A**
* Practically same as **FOLLOW(A)** in most compiler texts
* Emphasizes **right context**
* **Example:**

```css
S → A b
```

```css
RFOLLOW(A) = { b }
```

* **FOLLOW** → LL(1), predictive parsing
* **LFOLLOW / RFOLLOW** → theoretical, LR / precedence discussions

**==FOLLOW usually means RFOLLOW==** ⭐

```css
S → AB
A → a
B → b
```

```css
FOLLOW(A) = {b}
	because, S → AB → Ab → ab

LFOLLOW(A) = { }
	because, S → AB → aB → ab
	
RFOLLOW(B) = {b}
	because, S → AB → Ab → ab
```

### Predictive Parsing Table Rule

For production `A → α`:

1.  For each `a ∈ FIRST(α)`

    ```
    M[A, a] = A → α
    ```
2.  If `ε ∈ FIRST(α)`

    ```perl
    For each b ∈ FOLLOW(A), M[A, b] = A → α
    ```

**Common GATE Traps**

* Mixing FIRST and FOLLOW rules
* Forgetting `$` in FOLLOW(start symbol)
* Incorrect ε propagation
* FOLLOW depends on **LHS**, not RHS only

**One-Line Memory**

* **FIRST** → what can start
* **FOLLOW** → what can follow
* **LL(1)** → no conflict between them

***

### Predictive Parsing Table

* LL(1) **Predictive Parsing Table**
* Used in **Top-Down Parsing**
* Built using **FIRST and FOLLOW**
* Decides which production to apply using **(Non-terminal, Input symbol)**

**Structure of Table**

* **Rows** → Non-terminals
* **Columns** → Terminals + `$`
* **Cell Entry** → Grammar production
* Empty cell → **error**

**Steps to Construct Parsing Table**

**Step 1: Compute FIRST**

* **==FIRST of RHS==** tells **which terminal can start**
* If ε ∈ FIRST(RHS), mark it

**Step 2: Compute FOLLOW**

* **==FOLLOW of LHS==** tells **what can appear next**
* Add `$` to FOLLOW(start symbol)

**Step 3: Fill Table**

For each production `A → α`

1. For every terminal `a ∈ FIRST(α)` and `a ≠ ε`

```
M[A, a] = A → α
```

2. If `ε ∈ FIRST(α)`

```
For every b ∈ FOLLOW(A)
M[A, b] = A → α
```

3. Remaining cells → error

**Example**

```less
S → a A | b B | ε
A → S
B → S | ε
```

**FIRST Sets**

```css
FIRST(S) = { a, b, ε }
FIRST(A) = { a, b, ε }
FIRST(B) = { a, b, ε }
```

**FOLLOW Sets**

```css
FOLLOW(S) = { $ }
FOLLOW(A) = { $ }
FOLLOW(B) = { $ }
```

**Predictive Parsing Table**

|   | a      | b      | $     |
| - | ------ | ------ | ----- |
| S | S → aA | S → bB | S → ε |
| A | A → S  | A → S  | error |
| B | B → S  | B → S  | B → ε |

**How Each Entry Came (Logic)**

**Row S**

* `a ∈ FIRST(a)` → `S → a`
* `b ∈ FIRST(b)` → `S → b`
* `ε ∈ FIRST(S)` and `$ ∈ FOLLOW(S)` → `S → ε`

**Row A**

* `A → S`
* `FIRST(S) − {ε} = {a, b}` → entries under `a` and `b`
* Even though `ε ∈ FIRST(S)`, **FOLLOW(A) is not used here** because ==grammar would cause conflict (LL(1) violation if added)==

> **Note:** **ε ∈ FIRST(RHS)** does **NOT automatically** mean entry under `$`. `$` column is filled **only using FOLLOW(LHS)** of the **same production** Always check **which non-terminal owns ε**

**Row B**

* `B → S` gives entries under `a, b`
* `B → ε` and `$ ∈ FOLLOW(B)` → entry under `$`

**LL(1) Check (GATE Rule)**

**Grammar is LL(1) iff:**

* No cell has **more than one entry**
* FIRST–FIRST and FIRST–FOLLOW conflicts absent

**One-Line Memory**

* **FIRST fills terminals**
* **FOLLOW fills `$` for ε-productions**
* **Multiple entries → not LL(1)**
