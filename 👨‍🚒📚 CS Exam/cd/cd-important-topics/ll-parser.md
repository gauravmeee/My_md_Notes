
# LL Parsers 


> Top-Down Parsing

### Meaning of LL

**LL(k)** means:
- **L** → Left to right scan of input
- **L** → Leftmost derivation
- **k** → number of lookahead symbols used

So an LL parser:

> Builds a parse tree from **root → leaves**, using **leftmost derivation**, by looking ahead up to **k symbols**.

### Types of LL Parsers

##### **1. LL(1) Parser (Most important)**

- Uses **1 symbol lookahead**
- Most commonly used in exams
- Works only for **simple grammars**

##### **Key idea:**

At every step:

> Decide the correct production using only the next input symbol

### Conditions for LL(1) Grammar

A grammar is LL(1) if:

1. No left recursion
2. Left factoring is done
3. FIRST/FOLLOW conditions are satisfied:
    - FIRST sets of alternatives must be disjoint
    - If ε exists, FIRST and FOLLOW must not overlap

### LL(1) Parsing Table

- Rows → Non-terminals
- Columns → Terminals
- Each cell → one production

If a cell has multiple entries → ❌ not LL(1)


### LL(k) Parsers (General Idea)

##### **LL(2), LL(3), LL(4)...**

- Use k-symbol lookahead
- More powerful than LL(1)
- Less used in practice due to complexity

##### **Rule:**

Higher k → more power, but more complex parser

### Top-Down Parsing Types

##### 1. Recursive Descent Parser

- Manual implementation
- May use backtracking (if not predictive)

##### 2. Predictive Parser

- No backtracking
- Uses LL(1) table
- Efficient and widely used

### Problems in LL Parsing

##### 1. Left Recursion (NOT allowed)

Example:  
`S → S + a | a` ❌

Fix:  
Convert to right recursion

##### 2. Common Prefix (needs left factoring)

Example:  
`S → aA | aB` ❌

Fix:  
`S → aS'`  
`S' → A | B`

##### **Question:** Which LL Grammar `S → m | mn | mno` s 


So the language generates:

- `m`
- `mn`
- `mno`
    
**Step 1:** Check common prefix

All productions start with **`m`**, so we need lookahead beyond 1 symbol.

**Step 2:** Try LL(1)

With 1 token:

- All choices begin with **m** → cannot distinguish  
    ❌ Not LL(1)

**Step 3:** Try LL(2)

With 2 tokens:
- `m` → `m`
- `mn` → `m n`
- `mno` → `m n`


Now notice:
- `mn` and `mno` both start with **m n**
- Still ambiguous at 2-token lookahead  
    ❌ Not LL(2)

**Step 4:** Try LL(3)

With 3 tokens:
- `m` → `m`
- `mn` → `m n`
- `mno` → `m n o`

Now all are distinguishable:

- `m` vs `mn` vs `mno` differ within 3 symbols

So the grammar becomes predictive with 3-symbol lookahead.

**Ans:** **The grammar is LL(3)** ✅

---

### FIRST & FOLLOW (Very Important)

##### **FIRST(X)**

Set of terminals that begin strings derived from X

##### **FOLLOW(X)**

Set of terminals that can appear **after X**

Used in LL(1) table construction.

### LL vs LR (Quick Comparison)

|Feature|LL Parser|LR Parser|
|---|---|---|
|Direction|Top-down|Bottom-up|
|Derivation|Leftmost|Rightmost (reverse)|
|Power|Less|More|
|Grammar type|Simple|Complex|
|Example|LL(1), LL(k)|LR(0), SLR, LALR|

### One-line Summary

> LL parser is a **top-down predictive parser** that builds a parse tree using **leftmost derivation and lookahead symbols**.

---

# LL(1) Parsing

### FIRST and FOLLOW (Syntax Analysis)

* Used in <mark>**Top-Down Parsing</mark>**
* Essential for <mark>**LL(1) grammar**</mark>
* Helps in <mark>**predictive parsing</mark> <mark>table construction**</mark>

**Grammar Basics**

* **Terminal (T)**: tokens (`id`, `+`, `*`, `(`, `)`, etc.)
* **Non-terminal (NT)**: variables (`E`, `T`, `F`, etc.)
* **ε (epsilon)**: <mark>empty string</mark>
* **$**: <mark>input end</mark> marker
* Grammar: `A → α`

**FIRST Set**

* **FIRST(X)** = <mark>set of terminals</mark> that can <mark>appear as the **first symbol**</mark> of any <mark>string derived from X</mark>

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

* FIRST is about <mark>**starting terminals**</mark>
* ε only included if whole RHS can derive ε

**FOLLOW Set**

* **FOLLOW(A)** = <mark>set of terminals</mark> that can <mark>appear **immediately after A**</mark> in some sentential form

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

* FOLLOW <mark>depends on **context**</mark>
* FOLLOW never contains ε

**Algorithm (GATE-Oriented)**

1. Initialize all **FIRST** and **FOLLOW** as empty
2. Apply <mark>FIRST rules</mark> until <mark>no change</mark>
3. Apply <mark>FOLLOW rules</mark> iteratively until <mark>fixed point</mark>

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

<mark>FOLLOW usually means RFOLLOW</mark>** ⭐

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

* <mark>FIRST of RHS</mark>** tells **which terminal can start**
* If ε ∈ FIRST(RHS), mark it

**Step 2: Compute FOLLOW**

* <mark>FOLLOW of LHS</mark>** tells **what can appear next**
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
* Even though `ε ∈ FIRST(S)`, **FOLLOW(A) is not used here** because <mark>grammar would cause conflict (LL(1) violation if added)</mark>

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
