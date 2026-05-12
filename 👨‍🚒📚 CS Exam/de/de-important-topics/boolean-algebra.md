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
# Boolean Algebra

#### Boolean Algebra Laws

**1. Identity Laws**

- `A + 0` = `A`
- `A ⋅ 1`= `A`

**2. Null Laws**

- `A + 1` = `1`
- `A ⋅ 0` = `0`

**3. <mark>Idempotent Laws**</mark>

- `A + A` = `A`
- `A ⋅ A` = `A`

**4. Complement Laws**

- `A + A′` = `1`
- `A ⋅ A′` = `0`

**5. Domination Laws**

- `A+1` = `1`
- `A ⋅ 0` = `0`

**6. Double Negation**

- `(A′)′` = `A`

**7. Commutative Laws**

- `A + B` = `B + A`
- `A ⋅ B` = `B ⋅ A`

**8. Associative Laws** ⭐

- `( A + B ) + C` = `A + (B + C)`
- `( A ⋅ B ) ⋅ C` = \`A . (B . C)

**9. Distributive Laws** ⭐

- `A ( B + C )` = `AB + AC`
- `A + BC` = `(A + B)(A + C)`

**12. Special Distributive Form** ⭐

- `X + X′Y` = `X + YX + X' Y` = `X + Y`
- Example: `B′+BA` = `B′+AB' + BA` = `B' + A`

**10. Absorption Laws** ⭐

- `A + AB` = `A`
- `A ( A + B )` = `A`

**11. De Morgan’s Laws** ⭐

- `( A + B )′` = `A'B'`
- `(AB)′` = `A' + B'`

#### Proofs of Some Important Algebra

**1. Distributive Laws**

- (a) $A(B+C) = AB + AC$
- (b) $(A+B)(A+C) = A + BC$

$$\begin{aligned} (A + B)(A + C) &= A(A + C) + B(A + C) \\ &= A + AC + AB + BC \\ &= A + AB + AC + BC \\ &= A (1 + B + C) + BC \\ &= A + BC \end{aligned}$$

**2. Special Distributive Laws**

- (a) $X+X′Y= X+Y$

$$\begin{aligned} X + X'Y &= (X + X')(X + Y) \\ &= (1)(X + Y) \\ &= X + Y \end{aligned}$$

**3. Absorption Laws**

- (a) $A+AB = A(1+B) = A(1) =A$
- (b) $A(A+B)=AA+AB=A+AB=A$

**4. De Morgan’s Laws**

- (a) $(A+B)′=A′B′$
- (b) $(AB)′=A′+B′$

---

## Note 2

To solve Boolean algebra problems effectively, you need a toolkit of laws that allow you to simplify complex expressions. These laws are divided into basic rules and more advanced theorems.

##### 1. Fundamental Laws (The Basics)

These laws are the building blocks of all Boolean logic.

| **Name**                 | **OR Law (+)**             | **AND Law (⋅)**       |
| ------------------------ | -------------------------- | --------------------- |
| **Identity Law**         | $A + 0 = A$                | $A \cdot 1 = A$       |
| **Null (Annulment) Law** | $A + 1 = 1$                | $A \cdot 0 = 0$       |
| **Idempotent Law**       | $A + A = A$                | $A \cdot A = A$       |
| **Complement Law**       | $A + \bar{A} = 1$          | $A \cdot \bar{A} = 0$ |
| **Double Negation**      | $\overline{(\bar{A})} = A$ | —                     |

##### 2. Commutative, Associative, and Distributive Laws

These function similarly to standard algebra but with one major "Boolean-only" twist.
- **Commutative:** $A + B = B + A$ and $A \cdot B = B \cdot A$
- **Associative:** $(A + B) + C = A + (B + C)$ and $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- **Distributive:** * **Rule 1:** $A(B + C) = AB + AC$ (Same as normal algebra)
    - **Rule 2:** $A + (BC) = (A + B)(A + C)$ (**Unique to Boolean Algebra**)
        - **Proof of Rule 2:** Right Side: $(A + B)(A + C) = AA + AC + AB + BC$
            $= A + AC + AB + BC$ (since $AA = A$)
            $= A(1 + C + B) + BC$ (since $A + AC = A$)            
            $= A(1) + BC = A + BC$.
            

##### 3. Absorption Laws ⭐

These are the most powerful laws for simplifying and "shrinking" expressions.

- **Law 1:** $A + AB = A$
    - **Derivation:** $A(1 + B) = A(1) = A$.
        
- **Law 2:** $A(A + B) = A$
    - **Derivation:** $AA + AB = A + AB = A(1 + B) = A$.
        
- **Redundancy Law:**  ⭐
	- Sum Form: $A + \bar{A}B = A + B$
		- **Derivation:** $(A + \bar{A})(A + B) = 1 \cdot (A + B) = A + B$.
	- Product Form: $A(\bar{A} + B) = AB$    
		- **Deviation: ** $(A \cdot \bar{A}) + (A \cdot B)  = 0 + (A \cdot B) = A \cdot B$

##### De Morgan’s Theorems ⭐

Essential for breaking long "bars" (negations) over expressions.

- **Theorem 1:** $\overline{A + B} = \bar{A} \cdot \bar{B}$ (The complement of a sum is the product of the complements).
- **Theorem 2:** $\overline{A \cdot B} = \bar{A} + \bar{B}$ (The complement of a product is the sum of the complements).    

**Proof (Truth Table for Theorem 2):**

| **A** | **B** | **A⋅B** | **A⋅B** | **Aˉ** | **Bˉ** | **Aˉ+Bˉ** |
| ----- | ----- | ------- | ------- | ------ | ------ | --------- |
| 0     | 0     | 0       | **1**   | 1      | 1      | **1**     |
| 0     | 1     | 0       | **1**   | 1      | 0      | **1**     |
| 1     | 0     | 0       | **1**   | 0      | 1      | **1**     |
| 1     | 1     | 1       | **0**   | 0      | 0      | **0**     |

##### 5. Consensus Theorem

This is an "expert level" law used to eliminate redundant terms in three-variable expressions.

- **Equation:** $AB + \bar{A}C + BC = AB + \bar{A}C$
- **Derivation:**
    1. $AB + \bar{A}C + BC(1)$
    2. $AB + \bar{A}C + BC(A + \bar{A})$ (since $A + \bar{A} = 1$)
    3. $AB + \bar{A}C + ABC + \bar{A}BC$
    4. Group terms: $(AB + ABC) + (\bar{A}C + \bar{A}BC)$
    5. $AB(1 + C) + \bar{A}C(1 + B)$        
    6. $AB(1) + \bar{A}C(1) = AB + \bar{A}C$.
