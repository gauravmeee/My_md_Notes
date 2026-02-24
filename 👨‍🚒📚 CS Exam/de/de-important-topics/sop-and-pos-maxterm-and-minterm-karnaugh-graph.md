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

# SOP and POS, Maxterm and Minterm, Karnaugh Graph

### SOP and POS Notes (GATE – Digital Logic)

**1. Boolean Expression Forms**

A Boolean function can be represented mainly in:

- **SOP (Sum of Products)**
- **POS (Product of Sums)**

These are most used in:

- simplification
- K-map
- logic circuit design

**2. SOP (Sum of Products)**

**Definition:**

- SOP is an **OR ( + )** of multiple **product terms**.
- Each product term is an **AND ( · )** of literals.

**General Form:**

$$F = P_1 + P_2 + P_3 + ...$$ where each $P\_i$ is a product term.

**Example :**

$$F = A'B + ABC' + B'C$$

**Circuit Meaning :**

- AND gates for product terms
- then OR gate at output

**Types of SOP**

**(a) Standard SOP**

- each product term contains **all variables**\
  Example: $F = A'BC + AB'C + ABC$

**(b) Non-standard SOP**

- product terms may miss some variables\
  Example: $F = AB + C$

**(c) Canonical SOP**

- SOP written as **sum of minterms**
- notation: **Σm**\
  Example: $F(A,B,C)=\Sigma m(1,3,5,7)$

**3. POS (Product of Sums)**

**Definition:**

- POS is an **AND ( · )** of multiple **sum terms**.
- Each sum term is an **OR ( + )** of literals.

**General Form:**

$$F = S_1 \cdot S_2 \cdot S_3 ...$$ where each $S\_i$ is a sum term.

**Example :**

$$F = (A + B')(B + C)(A' + C')$$

**Circuit Meaning:**

- OR gates for sum terms
- then AND gate at output

**Types of POS**

**(a) Standard POS**

- each sum term contains **all variables**\
  Example: $F = (A + B + C')(A' + B + C)$

**(b) Non-standard POS**

- sum terms may miss some variables\
  Example: $F = (A + B)(C')$

**(c) Canonical POS**

- POS written as **product of maxterms**
- notation: **ΠM**\
  Example: $F(A,B,C)=\Pi M(0,2,4,6)$

**4. SOP vs POS (Quick Difference)**

| Feature            | SOP             | POS             |
| ------------------ | --------------- | --------------- |
| Form               | OR of AND terms | AND of OR terms |
| Based on           | minterms        | maxterms        |
| K-map grouping     | group 1s        | group 0s        |
| Canonical notation | Σm              | ΠM              |

**5. Conversion (Important)**

- SOP can be converted to POS and vice versa using:
  - Boolean algebra
  - DeMorgan's theorem
  - K-map method (best for GATE)

---

### Minterm and Maxterm Notes (GATE – Digital Logic)

**1. Basic Idea**

- Boolean function can be represented using:
  - \==Minterms (Σm) → for SOP form==
  - \==Maxterms (ΠM) → for POS form==

**2. Minterm**

**Definition:**

- A ==minterm is== a ==product (AND) term== that contains all variables exactly once (either complemented or uncomplemented).
- A ==minterm evaluates== to ==1 for exactly one input combination==.

**Notation:**

- $m\_i$
- Function form: $F = \Sigma m(\dots)$

**Example (2 variables A,B):**

- $m\_0 = A'B'$ (00)
- $m\_1 = A'B$ (01)
- $m\_2 = AB'$ (10)
- $m\_3 = AB$ (11)

**Key Point:**

If for an input:

- \==bit = 0 → variable is complemented==
- \==bit = 1 → variable is uncomplemented==

**Example:**

- input 101 (A,B,C) $m\_5 = AB'C$

**3. Maxterm**

**Definition:**

- A ==maxterm is== a ==sum (OR) term== that contains all variables exactly once (either complemented or uncomplemented).
- A ==maxterm evaluates== to ==0 for exactly one input combination==.

**Notation:**

- $M\_i$
- Function form: $F = \Pi M(\dots)$

**Example (2 variables A,B)**

- $M\_0 = (A + B)$ (00)
- $M\_1 = (A + B')$ (01)
- $M\_2 = (A' + B)$ (10)
- $M\_3 = (A' + B')$ (11)

**Key Point:**

If for an input:

- \==bit = 0 → variable is uncomplemented==
- \==bit = 1 → variable is complemented==

Example:

- input 101 (A,B,C) $M\_5 = (A' + B + C')$

**4. Relation between Minterm and Maxterm**

For same index i:

- $m\_i$ is complement of $M\_i$
- $m\_i = (M\_i)'$
- $M\_i = (m\_i)'$

**5. Canonical Forms**

**Canonical SOP (Sum of Minterms):**

- OR of minterms
- Uses Σm
- Example: $F(A,B,C)=\Sigma m(1,3,5,7)$

**Canonical POS (Product of Maxterms):**

- AND of maxterms
- Uses ΠM
- Example: $F(A,B,C)=\Pi M(0,2,4,6)$

**6. Conversion Rule (Very Important)**

If total variables = n, then:

- $F = \Sigma m(S)$
- $F = \Pi M(\text{all indices except }S)$

Example (3 variables → indices 0 to 7):

- If $F=\Sigma m(1,2,6)$
- then $F=\Pi M(0,3,4,5,7)$

Similarly:

- If $F=\Pi M(0,3,4)$
- then $F=\Sigma m(1,2,5,6,7)$

**7. Finding Minterm/Maxterm Index**

**For minterm index:**

- take binary input as number Example:
- $ABCD = 1011$ → index = 11 so minterm = $m\_{11}$

**For maxterm index:**

- same indexing rule (binary → decimal) Example:
- $ABCD = 1011$ → maxterm = $M\_{11}$

**8. K-Map Connection**

- In K-map:
  - place 1s for minterms in Σm
  - place 0s for maxterms in ΠM

**9. Shortcut Table (Must Remember)**

| Form | Represents | Use in K-map | Expression Type |
| ---- | ---------- | ------------ | --------------- |
| Σm   | where F=1  | mark 1       | SOP             |
| ΠM   | where F=0  | mark 0       | POS             |

**10. Common GATE Traps**

- Confusing complement rule in maxterm.
- Mixing Σ and Π.
- Forgetting: maxterm corresponds to 0 output, minterm corresponds to 1 output.
- Wrong conversion between Σm and ΠM.

If you want, I can also give 1 full solved example showing conversion between truth table → Σm → ΠM → K-map in GATE pattern.

---

### K-Map (Karnaugh Map) Notes (GATE Ready)

**1. What is K-Map?**

- \==**Karnaugh Map (K-Map)** is a graphical method== to ==simplify Boolean functions.==
- It gives **minimum literals** expression (best for GATE).
- Used for:
  - \==**SOP minimization** (group 1s)==
  - \==**POS minimization** (group 0s)==

**2. Why Gray Code?**

K-map uses **Gray code ordering** so that ==adjacent cells differ in **only 1 variable**==. Gray order for 2 bits:

- 00, 01, 11, 10

This is the reason why grouping works.

**3. K-Map Tables (Must Remember)**

**(A) 2-Variable K-Map (A,B)**

| A\B | 0   | 1   |
| --- | --- | --- |
| 0   | m0  | m1  |
| 1   | m2  | m3  |

$m\_0=A'B'$, $m\_1=A'B$, $m\_2=AB'$, $m\_3=AB$

**(B) 3-Variable K-Map (A,B,C)**

Rows = A (0,1) Cols = BC in Gray order (00,01,11,10)

| A\BC | 00  | 01  | 11  | 10  |
| ---- | --- | --- | --- | --- |
| 0    | m0  | m1  | m3  | m2  |
| 1    | m4  | m5  | m7  | m6  |

**(C) 4-Variable K-Map (A,B,C,D) (Most Important)**

Rows = AB (00,01,11,10) Cols = CD (00,01,11,10)

| AB\CD | 00  | 01  | 11  | 10  |
| ----- | --- | --- | --- | --- |
| 00    | m0  | m1  | m3  | m2  |
| 01    | m4  | m5  | m7  | m6  |
| 11    | m12 | m13 | m15 | m14 |
| 10    | m8  | m9  | m11 | m10 |

**4. Adjacency in K-Map (GATE Trap)**

Adjacent means **1-bit difference** only.

**Adjacency allowed:**

- left-right
- up-down
- **wrap around**
  - first column adjacent to last column
  - first row adjacent to last row
- corners are adjacent via wrap-around

**Not allowed:**

- diagonal adjacency

**5. Grouping Rules (SOP / POS)**

Groups must have size **$2^n$** only:

- 1,2,4,8,16...

**Rules:**

- group must be **rectangle**
- overlapping allowed
- group can wrap around
- choose **largest groups first**
- cover all required cells

**6. SOP using K-Map (group 1s)**

**SOP Steps:**

1. Put **1** at given minterms.
2. Use **X** (don't care) as 1 if it helps.
3. Make groups of 1s.
4. Write product term for each group.
5. OR all terms.

**Term Formation Rule (SOP):**

Inside a group:

- variable constant 1 → keep as **normal**
- variable constant 0 → keep as **complement**
- variable changing → remove

**7. POS using K-Map (group 0s)**

**POS Steps:**

1. Put **0** at given maxterms.
2. Use **X** as 0 if it helps.
3. Make groups of 0s.
4. Write sum term for each group.
5. AND all terms.

**Term Formation Rule (POS):**

Inside a group:

- variable constant 0 → keep as **normal**
- variable constant 1 → keep as **complement**
- variable changing → remove

**8. Shortcut: Group Size → Remaining Variables**

If variables = n and group size = $2^k$:

- eliminated variables = k
- remaining variables = n − k

**Example:**

- 4-variable K-map
- group of 8 (=$2^3$)
- remaining vars = 4−3 = 1 literal

**9. Prime Implicant and Essential Prime Implicant**

**Prime Implicant (PI):**

- group that cannot be expanded further.

**Essential Prime Implicant (EPI):**

- PI covering a 1 that no other PI covers.
- EPIs are compulsory in answer.

**10. Example (GATE Level SOP)**

**Given:**

$$F(A,B,C) = \Sigma m(1,3,5,7)$$

**Step 1: Put 1s in 3-variable K-map**

3-variable K-map table:

| A\BC | 00  | 01  | 11  | 10  |
| ---- | --- | --- | --- | --- |
| 0    | 0   | 1   | 1   | 0   |
| 1    | 0   | 1   | 1   | 0   |

( 1s at m1, m3, m5, m7 )

**Step 2: Grouping**

All 4 ones form one group of size 4.

**Step 3: Write term**

In this group:

- B changes? No (always 1)
- C changes? Yes? Actually columns 01 and 11 → C=1 always
- A changes (0 and 1) → eliminate A

So remaining: **C**

**Final Answer:**

$$F = C$$

**11. Example (GATE Level POS)**

**Given:**

$$F(A,B,C) = \Pi M(0,2,4,6)$$

This means:

- F=0 at indices 0,2,4,6

**Step 1: Put 0s in K-map**

| A\BC | 00  | 01  | 11  | 10  |
| ---- | --- | --- | --- | --- |
| 0    | 0   | 1   | 1   | 0   |
| 1    | 0   | 1   | 1   | 0   |

(0s at m0, m2, m4, m6)

**Step 2: Group 0s**

All 4 zeros form one group of size 4.

**Step 3: Write POS term**

In this group:

- C is constant 0 (columns 00 and 10 → C=0 always)
- A changes → eliminate
- B changes → eliminate

So sum term = **(C)**

**Final Answer:**

$$F = C$$

(Here POS gives same simplified result.)

**12. Don't Care (X) Notes**

- X can be used as ==1 in SOP== or ==0 in POS==.
- Use X only if it makes **bigger groups**.
- Bigger groups = smaller expression.

**13. Common GATE Mistakes**

- wrong Gray order in table
- ignoring wrap-around
- grouping diagonal cells
- group size not power of 2
- writing wrong literal (complement error)
- not taking largest groups
