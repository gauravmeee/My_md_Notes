
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
