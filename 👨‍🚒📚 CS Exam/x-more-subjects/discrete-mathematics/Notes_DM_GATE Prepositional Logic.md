
## Propositional Logic (GATE Detailed Notes)

##### **Proposition**

- A declarative statement
- Has a definite truth value: True (T) or False (F)
- Cannot be both true and false simultaneously

**Examples:**

- "2 + 3 = 5" → Proposition (True)
- "Paris is in France" → Proposition (True)
- "5 > 10" → Proposition (False)
- "Close the door" → Not a proposition (command)
- "What time is it?" → Not a proposition (question)
- "x + 2 = 5" → Not a proposition (depends on x)

**Non-propositions:**

- Questions
- Commands
- Exclamations
- Statements with variables (until assigned values)

##### **Atomic and Compound Propositions**

**Atomic Proposition:**

- Single, indivisible statement
- Cannot be broken down further
- Denoted by: p, q, r, s, etc.
- Examples:
    - p: "It is raining"
    - q: "The sun is shining"

**Compound Proposition:**

- Formed by combining atomic propositions using logical connectives
- Examples:
    - $p \land q$: "It is raining AND the sun is shining"
    - $p \lor q$: "It is raining OR the sun is shining"
    - $\neg p$: "It is NOT raining"

##### **Logical Connectives**

**1. NOT (Negation)  $\neg p$**

|p|$\neg p$|
|---|---|
|T|F|
|F|T|

- Reverses truth value
- Also written as: ~p, ¬p, !p

**2. AND (==Conjunction==)  $p \land q$**

|p|q|$p \land q$|
|---|---|---|
|T|T|T|
|T|F|F|
|F|T|F|
|F|F|F|

- True only when BOTH are true
- Also written as: p ∧ q, p · q, p & q

**3. OR (==Disjunction==)  $p \lor q$**

|p|q|$p \lor q$|
|---|---|---|
|T|T|T|
|T|F|T|
|F|T|T|
|F|F|F|

- True when AT LEAST ONE is true
- Inclusive OR (both can be true)
- Also written as: p ∨ q, p + q, p | q

**4. XOR (Exclusive OR)  $p \oplus q$**

|p|q|$p \oplus q$|
|---|---|---|
|T|T|F|
|T|F|T|
|F|T|T|
|F|F|F|

- True when EXACTLY ONE is true
- $p \oplus q \equiv (p \lor q) \land \neg(p \land q)$
- $p \oplus q \equiv (p \land \neg q) \lor (\neg p \land q)$

**5. Implication (==Conditional==)  $p \to q$**

|p|q|$p \to q$|
|---|---|---|
|T|T|T|
|T|F|F|
|F|T|T|
|F|F|T|

- **False only when p is true and q is false**
- Read as: "if p then q", "p implies q", "p only if q"
- p = hypothesis/antecedent, q = conclusion/consequent
- **Key equivalence:** $p \to q \equiv \neg p \lor q$
- **Vacuous truth:** When p is false, implication is automatically true

**6. Biconditional (Double Implication) - $p \leftrightarrow q$**

|p|q|$p \leftrightarrow q$|
|---|---|---|
|T|T|T|
|T|F|F|
|F|T|F|
|F|F|T|

- True when both have SAME truth value
- Read as: "p if and only if q", "p iff q"
- $p \leftrightarrow q \equiv (p \to q) \land (q \to p)$
- $p \leftrightarrow q \equiv (p \land q) \lor (\neg p \land \neg q)$

##### **Operator Precedence (Highest to Lowest)**  ⭐

1. $\neg$ (NOT)
2. $\land$ (AND)
3. $\lor$ (OR)
4. $\to$ (Implication)
5. $\leftrightarrow$ (Biconditional)

**Example:** $p \lor q \land r$ means $p \lor (q \land r)$

##### **Truth Table Construction**

**Steps:**

1. Identify number of variables (n)
2. Number of rows = $2^n$
3. List all possible combinations
4. Evaluate expression step by step

**Example:** $(p \to q) \land (q \to r)$

|p|q|r|$p \to q$|$q \to r$|$(p \to q) \land (q \to r)$|
|---|---|---|---|---|---|
|T|T|T|T|T|T|
|T|T|F|T|F|F|
|T|F|T|F|T|F|
|T|F|F|F|T|F|
|F|T|T|T|T|T|
|F|T|F|T|F|F|
|F|F|T|T|T|T|
|F|F|F|T|T|T|

##### **Tautology, Contradiction, Contingency**

**1. Tautology:**

- Always true (all rows = T)
- Examples:
    - $p \lor \neg p$ (Law of Excluded Middle)
    - $p \to p$
    - $(p \land q) \to p$
    - $p \to (p \lor q)$
    - $(p \to q) \lor (q \to p)$

**2. Contradiction:**

- Always false (all rows = F)
- Examples:
    - $p \land \neg p$
    - $(p \to q) \land (p \land \neg q)$

**3. Contingency:**

- Sometimes true, sometimes false
- Neither tautology nor contradiction
- Examples:
    - $p \land q$
    - $p \to q$
    - $p \lor q$

**GATE Important:**

- Tautology = Valid formula
- Contradiction = Unsatisfiable formula

##### **Logical Equivalence**

**Definition:** Two propositions are logically equivalent if they have identical truth tables

**Notation:** $p \equiv q$ or $p \Leftrightarrow q$

**Test:** Show $(p \leftrightarrow q)$ is a tautology

**Important Equivalences:**

**1. De Morgan's Laws (Most Important for GATE):** $$\neg(p \land q) \equiv \neg p \lor \neg q$$ $$\neg(p \lor q) \equiv \neg p \land \neg q$$

**Extended form:** $$\neg(p_1 \land p_2 \land ... \land p_n) \equiv \neg p_1 \lor \neg p_2 \lor ... \lor \neg p_n$$

**2. Double Negation:** $$\neg(\neg p) \equiv p$$

**3. Implication Equivalences:** $$p \to q \equiv \neg p \lor q$$ $$p \to q \equiv \neg q \to \neg p \text{ (Contrapositive)}$$ $$\neg(p \to q) \equiv p \land \neg q$$

**4. Biconditional Equivalences:** $$p \leftrightarrow q \equiv (p \to q) \land (q \to p)$$ $$p \leftrightarrow q \equiv (p \land q) \lor (\neg p \land \neg q)$$ $$p \leftrightarrow q \equiv (\neg p \lor q) \land (\neg q \lor p)$$

**5. Idempotent Laws:** $$p \land p \equiv p$$ $$p \lor p \equiv p$$

**6. Commutative Laws:** $$p \land q \equiv q \land p$$ $$p \lor q \equiv q \lor p$$

**7. Associative Laws:** $$(p \land q) \land r \equiv p \land (q \land r)$$ $$(p \lor q) \lor r \equiv p \lor (q \lor r)$$

**8. Distributive Laws:** $$p \land (q \lor r) \equiv (p \land q) \lor (p \land r)$$ $$p \lor (q \land r) \equiv (p \lor q) \land (p \lor r)$$

**9. Absorption Laws:** $$p \land (p \lor q) \equiv p$$ $$p \lor (p \land q) \equiv p$$

**10. Identity Laws:** $$p \land T \equiv p$$ $$p \lor F \equiv p$$

**11. Domination Laws:** $$p \land F \equiv F$$ $$p \lor T \equiv T$$

**12. Negation Laws:** $$p \land \neg p \equiv F$$ $$p \lor \neg p \equiv T$$

**13. Complement Laws:** $$\neg T \equiv F$$ $$\neg F \equiv T$$

##### **Implication Variations**

**Given:** $p \to q$ ("if p then q")

**1. Converse:** $q \to p$ ("if q then p")

- NOT logically equivalent to original

**2. Inverse:** $\neg p \to \neg q$ ("if not p then not q")

- NOT logically equivalent to original
- Logically equivalent to converse

**3. Contrapositive:** $\neg q \to \neg p$ ("if not q then not p")

- **Logically equivalent to original** (Very important for GATE)

**Key Facts:**

- $p \to q \equiv \neg q \to \neg p$ (always)
- Converse $\equiv$ Inverse (but both $\not\equiv$ original)
- Original $\equiv$ Contrapositive

**Truth Table:**

|p|q|$p \to q$|Converse $q \to p$|Inverse $\neg p \to \neg q$|Contrapositive $\neg q \to \neg p$|
|---|---|---|---|---|---|
|T|T|T|T|T|T|
|T|F|F|T|T|F|
|F|T|T|F|F|T|
|F|F|T|T|T|T|

##### **Validity and Satisfiability**

**Satisfiable:**

- At least one truth assignment makes it true
- Has at least one row with T
- Example: $p \land q$ (satisfiable when both true)

**Unsatisfiable:**

- No truth assignment makes it true
- All rows are F
- Contradiction
- Example: $p \land \neg p$

**Valid:**

- Every truth assignment makes it true
- All rows are T
- Tautology
- Example: $p \lor \neg p$

**Relationships:**

- Valid ⇒ Satisfiable (but not vice versa)
- Unsatisfiable ⇒ Not Valid
- $p$ is valid ⟺ $\neg p$ is unsatisfiable

**GATE Note:**

- Valid = Tautology
- Unsatisfiable = Contradiction
- Satisfiable ≠ Valid (can be contingency)

##### **Arguments and Validity**

**Argument Structure:**

- Premises: $p_1, p_2, ..., p_n$
- Conclusion: q
- Form: $p_1, p_2, ..., p_n \therefore q$

**Valid Argument:**

- Conclusion logically follows from premises
- If all premises are true, conclusion MUST be true
- $(p_1 \land p_2 \land ... \land p_n) \to q$ is a tautology

**Testing Validity:** **Method 1:** Truth table - check if conclusion is true whenever all premises are true **Method 2:** Prove $(p_1 \land p_2 \land ... \land p_n) \to q$ is tautology **Method 3:** Assume premises true and conclusion false - if contradiction, argument is valid

**Example (Valid):**

- Premise 1: $p \to q$
- Premise 2: $p$
- Conclusion: $q$
- Test: $(p \to q) \land p \to q$ is tautology ✓

**Example (Invalid):**

- Premise 1: $p \to q$
- Premise 2: $q$
- Conclusion: $p$
- Test: $(p \to q) \land q \to p$ is NOT tautology ✗ (Fallacy: Affirming the consequent)

##### **Rules of Inference (Very Important for GATE)**

**1. Modus Ponens (MP):** $$\frac{p \to q, \quad p}{\therefore q}$$

**2. Modus Tollens (MT):** $$\frac{p \to q, \quad \neg q}{\therefore \neg p}$$

**3. Hypothetical Syllogism (HS):** $$\frac{p \to q, \quad q \to r}{\therefore p \to r}$$

**4. Disjunctive Syllogism (DS):** $$\frac{p \lor q, \quad \neg p}{\therefore q}$$

**5. Addition (Add):** $$\frac{p}{\therefore p \lor q}$$

**6. Simplification (Simp):** $$\frac{p \land q}{\therefore p}$$

**7. Conjunction (Conj):** $$\frac{p, \quad q}{\therefore p \land q}$$

**8. Resolution:** $$\frac{p \lor q, \quad \neg p \lor r}{\therefore q \lor r}$$

**9. Constructive Dilemma:** $$\frac{(p \to q) \land (r \to s), \quad p \lor r}{\therefore q \lor s}$$

**10. Destructive Dilemma:** $$\frac{(p \to q) \land (r \to s), \quad \neg q \lor \neg s}{\therefore \neg p \lor \neg r}$$

##### **Common Fallacies (Invalid Arguments)**

**1. Affirming the Consequent:** $$\frac{p \to q, \quad q}{\therefore p} \quad \text{(INVALID)}$$

**2. Denying the Antecedent:** $$\frac{p \to q, \quad \neg p}{\therefore \neg q} \quad \text{(INVALID)}$$

##### **Conjecture (Logic Context)**

- A proposition assumed or proposed to be true
- Requires proof or counterexample
- Common in mathematical reasoning
- Until proven, remains a conjecture
- Once proven, becomes a theorem

**Example:**

- Goldbach's Conjecture: Every even integer > 2 is sum of two primes (unproven)

##### **Normal Forms**

**Literal:** Variable or its negation (p, ¬p)

**Conjunctive Normal Form (CNF):**

- AND of ORs
- $(p \lor q) \land (\neg p \lor r) \land (q \lor \neg r)$
- Product of Sums (POS)

**Disjunctive Normal Form (DNF):**

- OR of ANDs
- $(p \land q) \lor (\neg p \land r) \lor (q \land \neg r)$
- Sum of Products (SOP)

**Every formula can be converted to CNF or DNF**

##### **GATE Focus Points**

1. **Implication truth table** - Know when $p \to q$ is false
2. **De Morgan's laws** - Distribute negation
3. **Valid vs Satisfiable vs Tautology** - Understand differences
4. **Argument validity** - Test using truth tables or rules
5. **Conversion:** $p \to q \equiv \neg p \lor q$
6. **Contrapositive equivalence:** $p \to q \equiv \neg q \to \neg p$
7. **Difference between implication and converse** - Not equivalent
8. **Rules of inference** - Modus Ponens, Modus Tollens, etc.
9. **Logical equivalences** - All laws listed above
10. **CNF/DNF conversion**

##### **GATE Common Traps**

1. **Converse ≠ Implication**
    
    - $p \to q \not\equiv q \to p$
2. **Inverse ≠ Implication**
    
    - $p \to q \not\equiv \neg p \to \neg q$
3. **Only Contrapositive = Implication**
    
    - $p \to q \equiv \neg q \to \neg p$
4. **Implication is false only in one case**
    
    - True antecedent, False consequent
5. **Valid ≠ Satisfiable**
    
    - Valid means always true (tautology)
    - Satisfiable means at least once true
6. **De Morgan's - watch the flip**
    
    - AND becomes OR, OR becomes AND
    - Don't forget to negate each part
7. **Affirming consequent is invalid**
    
    - $p \to q, q \not\Rightarrow p$
8. **Denying antecedent is invalid**
    
    - $p \to q, \neg p \not\Rightarrow \neg q$

##### **Quick Formula Reference**

$$p \to q \equiv \neg p \lor q$$ $$\neg(p \land q) \equiv \neg p \lor \neg q$$ $$\neg(p \lor q) \equiv \neg p \land \neg q$$ $$p \leftrightarrow q \equiv (p \to q) \land (q \to p)$$ $$p \to q \equiv \neg q \to \neg p$$ $$\neg(p \to q) \equiv p \land \neg q$$ $$p \oplus q \equiv (p \land \neg q) \lor (\neg p \land q)$$

##### **Final Insights**

1. **Master implication** - Most GATE questions involve $\to$
2. **Know De Morgan's laws cold** - Used everywhere
3. **Contrapositive is your friend** - Equivalent to original
4. **Truth tables never lie** - When in doubt, construct one
5. **Valid arguments preserve truth** - Tautology test
6. **Logical equivalence is transitive** - Chain them
7. **Precedence matters** - NOT > AND > OR > IMPLIES > IFF
8. **Practice conversion** - Between different forms
9. **Rules of inference** - Memorize common patterns
10. **Fallacies are tricky** - Know what's invalid