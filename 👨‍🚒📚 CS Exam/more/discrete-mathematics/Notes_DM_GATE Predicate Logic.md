

## Predicate Logic (First Order Logic) – GATE Detailed Notes

##### **Limitation of Propositional Logic**

- Cannot represent statements involving objects and their properties
- Cannot express "for all" or "there exists"
- Cannot handle relationships between objects
- Cannot generalize patterns

**Example limitations:**

- "All students passed" - cannot express relationship between students and passing
- "Some number is prime" - cannot quantify over numbers
- "Every integer has a successor" - cannot express universal property
- Propositional logic treats "John is tall" and "Mary is tall" as unrelated

##### **Predicate Logic**

- Extends propositional logic with variables, predicates, and quantifiers
- Also called **First Order Logic (FOL)**
- Can express properties of objects and relationships
- More expressive power than propositional logic

**Components:**

1. **Variables:** x, y, z (represent objects)
2. **Predicates:** P(x), Q(x,y) (properties/relations)
3. **Quantifiers:** ∀ (for all), ∃ (there exists)
4. **Connectives:** ¬, ∧, ∨, →, ↔ (same as propositional logic)
5. **Constants:** a, b, c (specific objects)
6. **Functions:** f(x), g(x,y) (map objects to objects)

##### **Predicate**

- A predicate is a statement with variables that becomes a proposition when values are assigned
- Notation: P(x), Q(x,y), R(x,y,z)
- P(x) - unary predicate (one variable)
- Q(x,y) - binary predicate (two variables)

**Examples:**

- P(x): "x is even"
    - P(4) → True (4 is even)
    - P(5) → False (5 is not even)
- Q(x,y): "x > y"
    - Q(5,3) → True
    - Q(2,7) → False
- R(x): "x is a prime number"
- S(x,y): "x is a parent of y"

**Truth value:**

- Predicate alone has NO truth value
- Becomes proposition when:
    - Variables are assigned values, OR
    - Variables are quantified

##### **Domain (Universe of Discourse)**

- Set of all possible values that variables can take
- Must be clearly defined
- Affects truth value of quantified statements

**Examples:**

- Domain = $\mathbb{Z}$ (Integers): {..., -2, -1, 0, 1, 2, ...}
- Domain = $\mathbb{N}$ (Natural numbers): {0, 1, 2, 3, ...}
- Domain = Students in a class
- Domain = All humans
- Domain = Real numbers $\mathbb{R}$

**GATE Important:**

- Same statement can be true in one domain, false in another
- Always check domain carefully

**Example:**

- $\forall x (x^2 \geq 0)$
    - True if domain = $\mathbb{R}$ (Real numbers)
    - Also true if domain = $\mathbb{Z}$ (Integers)

##### **Quantifiers**

Used to specify how many elements in the domain satisfy a predicate

##### **Universal Quantifier (∀) - "For All"**

**Notation:** $\forall x , P(x)$

**Meaning:** P(x) is true for ALL x in the domain

**Truth condition:**

- True: P(x) is true for every single element
- False: If even ONE element violates P(x)

**Examples:**

- $\forall x (x > 0)$ - "All x are positive"
    
    - False in domain $\mathbb{Z}$ (integers include negatives)
    - True in domain $\mathbb{N}^+$ (positive naturals)
- $\forall x (x^2 \geq 0)$ - "Square of every x is non-negative"
    
    - True in domain $\mathbb{R}$ (real numbers)
- $\forall x , \text{Student}(x) \to \text{Passed}(x)$ - "All students passed"
    

**Key point:** One counterexample makes it false

##### **Existential Quantifier (∃) - "There Exists"**

**Notation:** $\exists x , P(x)$

**Meaning:** There exists AT LEAST ONE x such that P(x) is true

**Truth condition:**

- True: If at least one element satisfies P(x)
- False: If NO element satisfies P(x)

**Examples:**

- $\exists x (x^2 = 4)$ - "There exists x whose square is 4"
    
    - True in domain $\mathbb{Z}$ (x = 2 or x = -2)
- $\exists x (x > 10)$ - "There exists x greater than 10"
    
    - True in domain $\mathbb{N}$ (many such numbers exist)
    - False in domain {1, 2, 3, 4, 5}
- $\exists x , \text{Prime}(x) \land \text{Even}(x)$ - "There exists an even prime"
    
    - True (x = 2)

**Key point:** One example makes it true

##### **Unique Existential Quantifier (∃!)**

**Notation:** $\exists! x , P(x)$

**Meaning:** There exists EXACTLY ONE x such that P(x) is true

**Expansion:** $$\exists! x , P(x) \equiv \exists x , (P(x) \land \forall y , (P(y) \to y = x))$$

**Example:**

- $\exists! x (x + 5 = 8)$ - "There exists exactly one x such that x + 5 = 8"
    - True (only x = 3)

##### **Nested Quantifiers**

- Multiple quantifiers in same statement
- **Order matters critically**

**Examples:**

**1. $\forall x , \exists y , P(x,y)$**

- "For every x, there exists some y such that P(x,y)"
- For each x, we can pick DIFFERENT y
- Example: $\forall x , \exists y , (y > x)$ - True in $\mathbb{Z}$
    - For any integer x, there exists larger integer y

**2. $\exists y , \forall x , P(x,y)$**

- "There exists one y that works for ALL x"
- Same y must work for every x
- Example: $\exists y , \forall x , (y > x)$ - False in $\mathbb{Z}$
    - No single integer is greater than all integers

**Key GATE Point:** $$\forall x , \exists y , P(x,y) \not\equiv \exists y , \forall x , P(x,y)$$

**More Examples:**

**3. $\forall x , \forall y , P(x,y)$**

- Same as $\forall y , \forall x , P(x,y)$ (order doesn't matter for same quantifier)
- "For all x and all y, P(x,y) is true"

**4. $\exists x , \exists y , P(x,y)$**

- Same as $\exists y , \exists x , P(x,y)$ (order doesn't matter for same quantifier)
- "There exist x and y such that P(x,y) is true"

**5. $\forall x , \exists y , \forall z , P(x,y,z)$**

- For every x, there exists y (possibly different for each x), such that for all z, P(x,y,z)

**Truth Table for Nested Quantifiers:**

|Statement|Meaning|
|---|---|
|$\forall x , \forall y , P(x,y)$|P holds for all pairs|
|$\exists x , \exists y , P(x,y)$|P holds for at least one pair|
|$\forall x , \exists y , P(x,y)$|For each x, some y works|
|$\exists x , \forall y , P(x,y)$|Some x works for all y|
|$\exists y , \forall x , P(x,y)$|Some y works for all x (NOT same as above)|

##### **Free and Bound Variables**

**Bound Variable:**

- Variable that is quantified
- Scope limited to quantifier

**Free Variable:**

- Variable NOT quantified
- Truth value depends on assignment

**Examples:**

**1. $\forall x , P(x, y)$**

- x → bound (quantified by ∀)
- y → free (not quantified)
- Truth value depends on value of y

**2. $\exists x , (P(x) \land Q(x, y))$**

- x → bound
- y → free

**3. $\forall x , \exists y , R(x, y, z)$**

- x → bound by ∀
- y → bound by ∃
- z → free

**4. $\forall x , P(x)$**

- x → bound
- No free variables (closed formula)

**GATE Important:**

- Formula with no free variables = **Sentence/Closed Formula**
- Formula with free variables = **Open Formula**
- Only sentences have definite truth values

##### **Scope of Quantifier**

- Portion of formula where quantifier applies
- Usually indicated by parentheses

**Examples:**

**1. $\forall x , (P(x) \to Q(x))$**

- Scope of ∀x: entire $(P(x) \to Q(x))$

**2. $(\forall x , P(x)) \to Q(y)$**

- Scope of ∀x: only $P(x)$
- y is free in Q(y)

**3. $\forall x , P(x) \land Q(y)$**

- Ambiguous! Use parentheses
- Could mean: $\forall x , (P(x) \land Q(y))$ OR $(\forall x , P(x)) \land Q(y)$

**Convention:**

- Quantifier has lowest precedence
- $\forall x , P(x) \land Q(x)$ means $\forall x , (P(x) \land Q(x))$

##### **Predicate Logic Connectives**

Same connectives as propositional logic, but operate on predicates:

- $\neg P(x)$ - NOT
- $P(x) \land Q(x)$ - AND
- $P(x) \lor Q(x)$ - OR
- $P(x) \to Q(x)$ - Implication
- $P(x) \leftrightarrow Q(x)$ - Biconditional

**Examples:**

- $\forall x , (P(x) \to Q(x))$ - "If x has property P, then x has property Q"
- $\exists x , (P(x) \land Q(x))$ - "There exists x with both properties P and Q"
- $\forall x , (P(x) \lor Q(x))$ - "Every x has property P or property Q"

##### **Negation of Quantifiers (Very Important for GATE)**

**Rule 1:** $$\neg(\forall x , P(x)) \equiv \exists x , \neg P(x)$$

**Meaning:**

- "NOT all x satisfy P" = "There exists x that does NOT satisfy P"

**Example:**

- Statement: "All students passed"
- Negation: "At least one student did not pass"

**Rule 2:** $$\neg(\exists x , P(x)) \equiv \forall x , \neg P(x)$$

**Meaning:**

- "There does NOT exist x satisfying P" = "All x do NOT satisfy P"

**Example:**

- Statement: "There exists a perfect square that is negative"
- Negation: "All perfect squares are non-negative"

**Nested Quantifiers Negation:**

**1. $\neg(\forall x , \exists y , P(x,y))$** $$\equiv \exists x , \neg(\exists y , P(x,y))$$ $$\equiv \exists x , \forall y , \neg P(x,y)$$

**2. $\neg(\exists x , \forall y , P(x,y))$** $$\equiv \forall x , \neg(\forall y , P(x,y))$$ $$\equiv \forall x , \exists y , \neg P(x,y)$$

**General Rule:**

- Push negation inward
- Flip each quantifier (∀ becomes ∃, ∃ becomes ∀)
- Negate the predicate at the end

**GATE Major Trap:**

- $\neg \forall x , P(x) \not\equiv \forall x , \neg P(x)$
- Correct: $\neg \forall x , P(x) \equiv \exists x , \neg P(x)$

##### **Logical Equivalence in Predicate Logic**

**Definition:** Two formulas are equivalent if they have same truth value for all interpretations

**Important Equivalences:**

**1. Distributive Laws:** $$\forall x , (P(x) \land Q(x)) \equiv (\forall x , P(x)) \land (\forall x , Q(x))$$ $$\exists x , (P(x) \lor Q(x)) \equiv (\exists x , P(x)) \lor (\exists x , Q(x))$$

**WARNING - NOT Equivalent:** $$\forall x , (P(x) \lor Q(x)) \not\equiv (\forall x , P(x)) \lor (\forall x , Q(x))$$ $$\exists x , (P(x) \land Q(x)) \not\equiv (\exists x , P(x)) \land (\exists x , Q(x))$$

**2. De Morgan's for Quantifiers:** $$\neg(\forall x , P(x)) \equiv \exists x , \neg P(x)$$ $$\neg(\exists x , P(x)) \equiv \forall x , \neg P(x)$$

**3. Implication:** $$\forall x , (P(x) \to Q(x)) \equiv \forall x , (\neg P(x) \lor Q(x))$$

**4. Contrapositive:** $$\forall x , (P(x) \to Q(x)) \equiv \forall x , (\neg Q(x) \to \neg P(x))$$

**5. Quantifier Commutation (Same Type):** $$\forall x , \forall y , P(x,y) \equiv \forall y , \forall x , P(x,y)$$ $$\exists x , \exists y , P(x,y) \equiv \exists y , \exists x , P(x,y)$$

**6. Different Quantifiers - NOT Commutative:** $$\forall x , \exists y , P(x,y) \not\equiv \exists y , \forall x , P(x,y)$$

**7. Prenex Normal Form:**

- All quantifiers moved to front
- Example: $\forall x , \exists y , (P(x) \to Q(y))$ is in prenex form

##### **Validity and Satisfiability**

**Valid (Logically True):**

- True for ALL interpretations (all domains, all predicates)
- Example: $\forall x , P(x) \to \exists x , P(x)$
    - "If P holds for all, then P holds for at least one"

**Satisfiable:**

- True for AT LEAST ONE interpretation
- Example: $\exists x , P(x)$
    - Can be true in some domain

**Unsatisfiable (Contradiction):**

- False for ALL interpretations
- Example: $\forall x , P(x) \land \exists x , \neg P(x)$
    - "All x have P AND some x doesn't have P"

**Relationships:**

- Valid ⇒ Satisfiable
- Unsatisfiable ⇒ Not Valid
- $F$ is valid ⟺ $\neg F$ is unsatisfiable

##### **Conjecture (Predicate Logic)**

- A statement with quantifiers assumed to be true
- Requires formal proof or counterexample
- Common in mathematical reasoning

**Examples:**

- Goldbach's Conjecture: $\forall n , (n > 2 \land \text{Even}(n) \to \exists p , \exists q , (\text{Prime}(p) \land \text{Prime}(q) \land n = p + q))$
- Collatz Conjecture: Properties of iterative sequences

##### **English to Predicate Logic Translation**

**Domain: All people**

|English|Predicate Logic|
|---|---|
|"All students are intelligent"|$\forall x , (\text{Student}(x) \to \text{Intelligent}(x))$|
|"Some student is intelligent"|$\exists x , (\text{Student}(x) \land \text{Intelligent}(x))$|
|"No student is lazy"|$\forall x , (\text{Student}(x) \to \neg \text{Lazy}(x))$|
|"Not all students passed"|$\neg \forall x , (\text{Student}(x) \to \text{Passed}(x))$|
|"Every student loves some professor"|$\forall x , (\text{Student}(x) \to \exists y , (\text{Professor}(y) \land \text{Loves}(x,y)))$|
|"Some professor is loved by all students"|$\exists y , (\text{Professor}(y) \land \forall x , (\text{Student}(x) \to \text{Loves}(x,y)))$|

**Key Pattern:**

- "All A are B" → $\forall x , (A(x) \to B(x))$ (use →)
- "Some A is B" → $\exists x , (A(x) \land B(x))$ (use ∧)
- "No A is B" → $\forall x , (A(x) \to \neg B(x))$

**GATE Trap:**

- $\forall x , (\text{Student}(x) \land \text{Passed}(x))$ is WRONG for "All students passed"
- Correct: $\forall x , (\text{Student}(x) \to \text{Passed}(x))$

##### **GATE Focus Points**

1. **Difference between ∀ and ∃**
    - ∀ = all, ∃ = at least one
2. **Negation of quantified statements**
    - Flip quantifier, negate predicate
3. **Order of quantifiers**
    - $\forall x , \exists y \not\equiv \exists y , \forall x$
4. **Bound vs free variables**
    - Quantified vs not quantified
5. **Valid vs satisfiable statements**
    - Valid = always true, Satisfiable = sometimes true
6. **Translation from English to logic**
    - "All" uses →, "Some" uses ∧
7. **Scope of quantifiers**
    - Use parentheses clearly
8. **Distributive property limitations**
    - Works for ∀ with ∧, ∃ with ∨ only
9. **Contrapositive in predicate logic**
    - $\forall x (P(x) \to Q(x)) \equiv \forall x (\neg Q(x) \to \neg P(x))$
10. **Nested quantifier negation**
    - Push negation through, flip each quantifier

##### **Common GATE Traps**

1. **Universal with AND (Wrong):**
    
    - "All students passed" ≠ $\forall x , (\text{Student}(x) \land \text{Passed}(x))$
    - Correct: $\forall x , (\text{Student}(x) \to \text{Passed}(x))$
2. **Existential with Implication (Wrong):**
    
    - "Some student passed" ≠ $\exists x , (\text{Student}(x) \to \text{Passed}(x))$
    - Correct: $\exists x , (\text{Student}(x) \land \text{Passed}(x))$
3. **Negation Flip:**
    
    - $\neg \forall x , P(x) \not\equiv \forall x , \neg P(x)$
    - Correct: $\neg \forall x , P(x) \equiv \exists x , \neg P(x)$
4. **Quantifier Order:**
    
    - $\forall x , \exists y , P(x,y)$ very different from $\exists y , \forall x , P(x,y)$
5. **Distribution Error:**
    
    - $\exists x , (P(x) \land Q(x)) \not\equiv (\exists x , P(x)) \land (\exists x , Q(x))$
6. **Free Variables:**
    
    - Formula with free variables has no definite truth value

##### **Quick Formula Reference**

$$\neg(\forall x , P(x)) \equiv \exists x , \neg P(x)$$ $$\neg(\exists x , P(x)) \equiv \forall x , \neg P(x)$$ $$\forall x , (P(x) \land Q(x)) \equiv (\forall x , P(x)) \land (\forall x , Q(x))$$ $$\exists x , (P(x) \lor Q(x)) \equiv (\exists x , P(x)) \lor (\exists x , Q(x))$$ $$\forall x , (P(x) \to Q(x)) \equiv \forall x , (\neg Q(x) \to \neg P(x))$$ $$\forall x , \forall y , P(x,y) \equiv \forall y , \forall x , P(x,y)$$ $$\forall x , \exists y , P(x,y) \not\equiv \exists y , \forall x , P(x,y)$$

##### **Final Insights**

1. **Quantifier negation is critical** - flip and negate
2. **Order matters for different quantifiers** - $\forall \exists \not\equiv \exists \forall$
3. **Use → for "all", ∧ for "some"** - standard pattern
4. **Bound variables are dummy variables** - can be renamed
5. **Free variables prevent truth assignment** - only sentences have truth values
6. **Distributive laws are limited** - only certain combinations work
7. **Domain affects truth** - always check universe of discourse
8. **Nested quantifiers need care** - work from outside in
9. **Prenex form simplifies** - move all quantifiers to front
10. **Practice translation** - English ↔ Predicate Logic is key skill