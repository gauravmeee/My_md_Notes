
### Abstract Algebra

**Meaning**
- **Abstract Algebra** studies **algebraic structures**
- Focus: **sets + operations** and their properties (rules)

**Algebraic Structure**
- An algebraic structure is:
	`(S, operations)`
- **Example:**
	- $(ℤ, +)$ integers under addition
	- $(ℕ, +, ×)$ naturals under addition and multiplication

**Binary Operation**

- A binary operation on set $S$:
	$*: S × S → S$
- **Properties often checked:**
	1. **Closure**: $a*b ∈ S$
	2. **Associativity**: $(a_b)_c = a_(b_c)$
	3. **Commutativity**: $a_b = b_a$
	4. **Identity**: $e_a = a_e = a$
	5. **Inverse**: $a_a⁻¹ = a⁻¹_a = e$
	6. **Distributive**: $a*(b+c) = a_b + a_c$

```css
Algebraic Structures
│
├─ Magma (set + binary operation)
│  │
│  └─ Semigroup (associative)
│     │
│     └─ Monoid (has identity)
│        │
│        └─ Group (has inverses)
│           │
│           ├─ Abelian Group (commutative)
│           │
│           └─ Non-Abelian Group
│
│
├─ Ring (two operations: +, ×)
│  │
│  ├─ Commutative Ring
│  │  │
│  │  ├─ Integral Domain (no zero divisors)
│  │  │  │
│  │  │  └─ Field (division possible)
│  │  │
│  │  └─ Ring with Zero Divisors
│  │
│  └─ Non-Commutative Ring
│     │
│     ├─ Division Ring (non-commutative field)
│     │
│     └─ Matrix Ring
│
│
└─ Vector Space (over a field)
   │
   └─ Algebra (vector space + multiplication)
```
##### **1. Semigroup**

A semigroup $(S, *)$:

- Closure
- Associativity

**Examples:**

- $(ℕ, +)$
- $(ℕ, ×)$
- $(ℤ, +)$
- $(ℤ, ×)$
- $(S, \text{max})$, $(S, \text{min})$

##### **1.1 Monoid**

A monoid $(M, *)$:

- Semigroup
- Identity element exists

**Examples:**

- $(ℕ, +)$, identity $0$
- $(ℕ, ×)$, identity $1$
- $(ℤ, +)$, identity $0$
- $(ℤ, ×)$, identity $1$
- $(P(S), ∪)$, identity $∅$
- $(P(S), ∩)$, identity $S$

##### **1.1.1 Group**

A group $(G, *)$:

- Monoid
- Inverse exists for every element

**Examples:**

- $(ℤ, +)$
- $(ℚ, +)$
- $(ℝ, +)$
- $(ℚ\setminus{0}, ×)$
- $(ℝ\setminus{0}, ×)$

##### **1.2 Abelian Monoid (Commutative)**

An Abelian Monoid:

- Monoid
- Commutative

**Examples:**

- $(ℕ, +)$
- $(ℕ, ×)$
- $(ℤ, +)$
- $(P(S), ∪)$
- $(P(S), ∩)$

##### **1.2.1 Abelian Group (Commutative)**

An Abelian Group:

- Group
- Commutative

**Examples:**

- $(ℤ, +)$
- $(ℚ, +)$
- $(ℝ, +)$
- $(ℚ\setminus{0}, ×)$
- $(ℝ\setminus{0}, ×)$

##### **2. Ring**

A ring $(R, +, ×)$ satisfies:

1. $(R, +)$ is an abelian group
2. $(R, ×)$ is a semigroup
3. Distributive laws:
    - $a×(b+c) = a×b + a×c$
    - $(a+b)×c = a×c + b×c$

**Important correction:**

- Ring being an abelian group refers only to addition
- Multiplication is independent of addition

**Examples:**

- $(ℤ, +, ×)$
- $(ℚ, +, ×)$
- $(ℝ, +, ×)$
- $(M_n(ℝ), +, ×)$ (non-commutative ring)

##### **2.1 Commutative Ring**

A commutative ring:

- Ring
- Multiplication is commutative

**Clarification (important):**

- Ring is abelian only under addition
- Multiplication need not be commutative
- Hence commutative ring is defined separately

**Examples:**

- $(ℤ, +, ×)$
- $(ℚ, +, ×)$
- $(ℝ, +, ×)$

**Non-example:**

- $(M_n(ℝ), +, ×)$ is a ring but not commutative

##### **2.2 Ring with Identity (Unity)**

A ring with identity:

- Ring
- Multiplicative identity $1$ exists
- $1×a = a×1 = a$

**Clarification (important):**

- Ring axioms do not require multiplicative identity
- Semigroup under multiplication does not guarantee identity
- Hence defined separately

**Examples:**

- $(ℤ, +, ×)$
- $(ℚ, +, ×)$
- $(ℝ, +, ×)$
- Polynomial ring $(ℝ[x], +, ×)$

##### **2.1.1 Integral Domain**

A commutative ring with unity such that:
- No zero divisors

**Meaning:** If $a×b = 0$ then $a=0$ or $b=0$

**Example:**
- $(ℤ, +, ×)$ integral domain

##### **2.1.1.1 Field**

A **field** $(F, +, ×)$ satisfies:

1. $(F, +)$ is abelian group
2. $(F − {0}, ×)$ is abelian group
3. Distributive laws

**Example:**

- $(ℚ, +, ×)$ field
- $(ℝ, +, ×)$ field

##### **3. Vector Space**

A **vector space** is built over a field:

$(V, +)$ is abelian group

Scalar multiplication: $F × V → V$

**Example:**
- $ℝ^n$ over field $ℝ$

##### **Lattice (Important in Discrete Math)**

A structure $(L, ∨, ∧)$ satisfying:

- Idempotent, commutative, associative
- Absorption laws

**Example:**

- $(P(S), ∪, ∩)$ power set forms lattice

##### **Homomorphism (Structure Preserving Map)**

A function $f: A → B$ that preserves operation:

**For groups:** $f(a*b) = f(a) * f(b)$

**For rings:**

- $f(a+b)=f(a)+f(b)$
- $f(a×b)=f(a)×f(b)$

##### **Isomorphism**

A **bijective homomorphism**
- Means two structures are "same" algebraically

##### **17) Quick Summary Table**

|     | Structure     | Operations | Key Condition                    |
| --- | ------------- | ---------- | -------------------------------- |
| 1   | Semigroup     | $*$        | associative                      |
| 2   | Monoid        | $*$        | associative + identity           |
| 3   | Group         | $*$        | monoid + inverse                 |
| 4   | Abelian Group | $*$        | group + commutative              |
| 5   | Ring          | $+,×$      | $+$ abelian group + distributive |
| 6   | Field         | $+,×$      | ring + every nonzero has inverse |


---

### Abelian Group & Abelian Monoid


**Basic Idea**
- These are algebraic structures: a set + an operation
- Operation is usually written as: `*` or `+`

**Binary Operation**
- Let $S$ be a set. A binary operation on $S$ is a function:
	$*: S × S → S$
- **Meaning:** for any $a, b ∈ S$, result $a * b ∈ S$

##### **1. Semigroup**

A semigroup is $(S, *)$ such that:
1. **Closure:** $a*b ∈ S$
2. **Associative:** $(a_b)_c = a_(b_c)$ for all $a,b,c ∈ S$

##### **2. Monoid**

A monoid is a **==semigroup + identity==**.
A monoid $(M, *)$ satisfies:
1. Closure
2. Associativity
3. ==Identity element exists==
    - There exists $e ∈ M$ such that:
    - $e_a = a_e = a$ for all $a ∈ M$

**Example:**
- $(ℕ, +)$ is a monoid
    - identity = $0$

##### **3. Abelian Monoid (Commutative Monoid)**

An abelian monoid is a monoid + commutativity.

So $(M, *)$ satisfies:
1. Closure
2. Associativity
3. ==Identity exists==
4. ==**Commutative:**== $a_b = b_a$ for all $a,b ∈ M$

**Example:**
- $(ℕ, +)$ is abelian monoid (identity = 0)
- $(ℕ, ×)$ is also abelian monoid (identity = 1)

##### **4. Group**

A group $(G, *)$ is a monoid + inverse for every element.

It satisfies:

1. Closure
2. Associativity
3. Identity exists
4. **Inverse exists**
    - For every $a ∈ G$, there exists $a⁻¹ ∈ G$ such that:
    - $a_a⁻¹ = a⁻¹_a = e$

**Example:**

- $(ℤ, +)$ is a group
    - identity = $0$
    - inverse of $a$ is $-a$

##### **5. Abelian Group (Commutative Group)**

An abelian group is a group + commutativity.

So $(G, *)$ satisfies:

1. Closure
2. Associativity
3. Identity exists
4. Inverse exists
5. **Commutative:** $a_b = b_a$

**Example:**

- $(ℤ, +)$ abelian group
- $(ℚ, +)$ abelian group
- $(ℝ, +)$ abelian group

##### **Key Difference (Monoid vs Group)**

- **Monoid:** **identity exists**, but ==inverse may not exist==
- **Group:** **identity exists + every element has inverse**

**Example:**
- $(ℕ, +)$ is monoid but not group (no inverse for 5 in ℕ)
- $(ℤ, +)$ is group (inverse for 5 is -5 in $ℤ$)

| Structure          | Closure | Associative | Identity | Inverse | Commutative   | ℕ Operations                        | $ℤ$ Operations          |
| ------------------ | ------- | ----------- | -------- | ------- | ------------- | ----------------------------------- | ----------------------- |
| Semigroup          | Yes     | Yes         | No       | No      | Not necessary | `+` , `×`, `max`, `min`             | `+` , `×`, `max`, `min` |
| Monoid             | Yes     | Yes         | ==Yes==  | No      | Not necessary | `+(0)`, `×(1)`, `max(0)`, `min((∞)` | `+(0)`, `×(1)`          |
| ==Abelian== Monoid | Yes     | Yes         | ==Yes==  | No      | ==Yes==       | `+` , `×`, `max`, `min`             | `+` , `×`, `max`, `min` |
| Group              | Yes     | Yes         | ==Yes==  | ==Yes== | Not necessary | ❌                                   | `+`                     |
| ==Abelian== Group  | Yes     | Yes         | ==Yes==  | ==Yes== | ==Yes==       | ❌                                   | `+`                     |

**Key Points**
- ==ℕ is **not** a group== (no inverse)
- `(ℤ, +)` is **Abelian group**
- ==`(ℤ, ×)` is **not** a group== (no inverse for 2)    
- `−` and `/` are **not binary operations** on ℤ or ℕ

**To Memorize** ⭐⭐
- Closure + Associativity → present in all algebraic structures
- Semigroup → Closure + Associativity    
- ==Monoid== → Semigroup + ==Identity==
- ==Group== → Monoid + ==Inverse==
- Abelian → Commutative
