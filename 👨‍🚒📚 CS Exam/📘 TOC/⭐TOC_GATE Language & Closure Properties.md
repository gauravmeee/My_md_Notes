
# Language

##### **Basic of Formal Language**

**Examples:**

**Ques:** Total no. of substrings possible for `w = GATE`
```
length:      0      1          2           3          4
substrings:  ϵ    G,A,T,E    GA,AT,TE    GAT,ATE     GATE
no. of subs: 1 +    4     +    3    +      2   +      1   = 4(4+1)/2 + 1
```
`ϵ` = null

Total no. of Substrings Formula : `n(n+1)/2+1` , `n=size of string`
Total no. of Non-trivial (not include `ϵ`) substring : `n(n+1)/2`

**Ques :** Find the no. of prefix and suffix possible in `GATE`, where `|w|=n`
**prefix:**- { ϵ, G, GA, GAT, GATE} 
	No. of Prefixes -> `n+1`
**suffix:**- { ϵ, E, TE, ATE, GATE} 
	No. of Suffixes -> `n+1`

### Closure Properties

- **Closure under an operation** means:  **If you apply that operation to languages of a particular class, the ==result will still belong to the same class==.**
OR
- A language class is **closed under an operation** if applying that operation to languages in the class always yields a language that is also in the class.

**Which Language Not Closed Under Which Operation** ⭐⭐⭐
```
1. Recursive Language -> Closed under all operations ✅
2. Context Free Language -> Intersection ❌, Complement ❌
3. Context Sensitive Language -> Homomorphism ❌
4. Recursive Language -> Closed under all operations ✅
5. Recursive Enumerable Language -> Complement ❌, Difference ❌
```
##### **1. Regular languages (RL)** -> closed under ==all== operations: ⭐

| Operation                | Meaning                                                         | Closed? | Notes ⭐                                                                                                                          |
| ------------------------ | --------------------------------------------------------------- | ------- | -------------------------------------------------------------------------------------------------------------------------------- |
| **Union**                | `L₁ ∪ L₂` = strings in L₁ or L₂                                 | ✅ Yes   | Constructed using NFA or regex: R₁ + R₂                                                                                          |
| **Concatenation**        | `L₁L₂` = strings formed by concatenating strings from L₁ and L₂ | ✅ Yes   | DFA/NFA can simulate                                                                                                             |
| **Kleene Star**          | `L*` = zero or more repetitions of strings in L                 | ✅ Yes   | Defined using NFA with ε-transitions                                                                                             |
| **Intersection**         | `L₁ ∩ L₂`                                                       | ✅ Yes   | DFA can be built using product construction                                                                                      |
| **Complement**           | `Σ* − L`                                                        | ✅ Yes   | Flip final/non-final states in DFA                                                                                               |
| **Difference**           | `L₁ − L₂`                                                       | ✅ Yes   | Use: L₁ − L₂ = L₁ ∩ (¬L₂)                                                                                                        |
| **Reversal**             | `Lᴿ` = reverse of all strings in L                              | ✅ Yes   | NFA with reversed transitions                                                                                                    |
| **Substitution**         | Replace symbols by regular languages                            | ✅ Yes   | Preserves regularity                                                                                                             |
| **Homomorphism**         | `h(L)` : map each symbol to a string                            | ✅ Yes   | Still regular                                                                                                                    |
| **Inverse Homomorphism** | `h⁻¹(L)`: pull back by symbol mappings                          | ✅ Yes   | Still regular                                                                                                                    |
| **Right Quotient**       | `L₁ / L₂` =` { x \| ∃ y ∈ L₂ such that xy ∈ L₁ }`               | ✅ Yes   | Removes **suffix** from strings in L₁.<br><br>Checks if adding **some string from L₂** to `x` results in a string in L₁.         |
| **Left Quotient**        | `L₂ \ L₁` = `{ y \| ∃ x ∈ L₂ such that xy ∈ L₁ }`               | ✅ Yes   | Removes **prefix** from strings in L₁.<br><br>Checks if adding **some string from L₂** **before `y`** results in a string in L₁. |

##### **2. Context-Free Languages (CFL):** -> Closed Under ==following== Operations ⭐


| **Operation**                                             | **CFL (Non-Det.) Closed?** ⭐ For Exam | **DCFL Closed?** | **Reason / Explanation**                                                                                                                                      |
| --------------------------------------------------------- | ------------------------------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Union**                                                 | ✅ Yes                                 | ❌ No             | CFLs can be unioned by using nondeterminism in PDA. DCFLs can't use nondeterminism, so union may lead to ambiguity.                                           |
| ==**Intersection**==                                      | ❌ ==No==                              | ❌ No             | CFL ∩ CFL may not be CFL (e.g., `{aⁿbⁿcⁿ}` ∉ CFL). DCFL also not closed because deterministic machines can't track multiple conditions simultaneously.        |
| ==**Complement**==                                        | ❌ ==No==                              | ✅ ==Yes==        | CFL not closed: If it were, then CFL would also be closed under intersection (contradiction via De Morgan’s Law). DCFL is closed due to deterministic nature. |
| **Regular ∩ CFL**<br>(Intersection with regular language) | ✅ Yes                                 | ✅ ==Yes==        | ==Intersection with a **regular language** is always CFL or DCFL==, since regular part can be simulated without increasing complexity.                        |
| **Concatenation**                                         | ✅ Yes                                 | ❌ No             | CFL is closed using nondeterminism. DCFL is not closed as deterministic PDA can't deterministically concatenate in general.                                   |
| **Kleene Star**                                           | ✅ Yes                                 | ❌ No             | CFL supports repetition via ε-transitions in NPDA. DCFL does not handle unbounded nondeterminism.                                                             |
| **Reversal**                                              | ✅ Yes                                 | ❌ No             | CFLs can be reversed by modifying the PDA. For DCFL, reversal may introduce nondeterminism, hence not closed.                                                 |
| **Substitution**                                          | ✅ Yes                                 | ❌ No             | CFL supports substitution (using PDA construction). DCFL does not, due to deterministic restrictions.                                                         |
| **Homomorphism**                                          | ✅ Yes                                 | ❌ No             | CFLs are closed, but DCFLs are not—homomorphism may break determinism.                                                                                        |
| ==**Inverse Homomorphism**==                              | ✅ Yes                                 | ✅ ==Yes==        | Both closed; input symbol pre-image mapping preserves structure.                                                                                              |

**For Remembering:**
- **CFL and DCFL**:  
    Follow → **Inverse Homomorphism**, **Regular ∩ CFL**   ✅
    Not Follow → **Intersection** ❌
    
- **DCFL (in Comparison of CFL)**:  
    Follow → **Complement** (extra over CFL)   ✅
    Not Follow → **Rest All** ❌
    
- **CFL (in Comparison of DCFL)**:  
    Follow → **All Except**  ✅
    Not Follow  → **Complement**   ❌
    
> **Note:** Unlike other language classes, **Deterministic Context-Free Languages (DCFL)** form a **strict subset** of **Context-Free Languages (CFL)**. Therefore, **DCFLs do not share all closure properties of CFLs**, and must be treated separately.


##### **3. Context-Sensitive Languages (CSL)** → Closed under **most operations** ⭐

| **Operation**            | **Closed?** | **Reason / Explanation**                                                  |
| ------------------------ | ----------- | ------------------------------------------------------------------------- |
| **Union**                | ✅ Yes       | Two LBA computations can be simulated sequentially.                       |
| **Intersection**         | ✅ Yes       | LBA can check both conditions using linear space.                         |
| **Complement**           | ✅ Yes       | By **Immerman–Szelepcsényi Theorem** (NSPACE(n) closed under complement). |
| **Concatenation**        | ✅ Yes       | Split input nondeterministically; linear space preserved.                 |
| **Kleene Star**          | ✅ Yes       | Finite repetitions; space remains linear.                                 |
| **Reversal**             | ✅ Yes       | Input can be scanned backward with linear space.                          |
| **Substitution**         | ✅ Yes       | CSL substituted into CSL preserves linear boundedness.                    |
| ==**Homomorphism**==     | ❌ ==No==    | Can shrink strings and break length constraints.                          |
| **Inverse Homomorphism** | ✅ Yes       | Pre-image mapping does not increase space.                                |

**Remember:**  
CSL = **NSPACE(n)**  
Key highlight → **Complement is closed** (unlike CFL)

---

##### **4. Recursive (Decidable) Languages** → Closed under **all standard operations** ⭐⭐

|**Operation**|**Closed?**|**Reason / Explanation**|
|---|---|---|
|**Union**|✅ Yes|Run both deciders and OR results.|
|**Intersection**|✅ Yes|Run both deciders and AND results.|
|**Complement**|✅ Yes|Flip accept/reject since TM always halts.|
|**Difference**|✅ Yes|A − B = A ∩ ¬B.|
|**Concatenation**|✅ Yes|Enumerate splits; both machines halt.|
|**Kleene Star**|✅ Yes|Finite decomposition + halting guarantee.|
|**Reversal**|✅ Yes|Reverse input then decide.|
|**Homomorphism**|✅ Yes|Transform input, then decide.|
|**Inverse Homomorphism**|✅ Yes|Decide on all mapped strings.|

**Remember:**  
Recursive languages = **Total Turing Machines**  
→ **Best closure behavior after Regular languages**


##### **5. Recursive Enumerable (RE / Semi-Decidable) Languages** → Closed under **many but NOT complement** ❗

| **Operation**            | **Closed?** | **Reason / Explanation**                   |
| ------------------------ | ----------- | ------------------------------------------ |
| **Union**                | ✅ Yes       | Dovetailing simulations of two TMs.        |
| **Intersection**         | ✅ Yes       | Accept only if both machines accept.       |
| ==**Complement**==       | ❌ ==No==    | Halting problem: TM may loop forever.      |
| ==**Difference**==       | ❌ ==No==    | Requires complement.                       |
| **Concatenation**        | ✅ Yes       | Enumerate all splits nondeterministically. |
| **Kleene Star**          | ✅ Yes       | Enumerate repetitions.                     |
| **Reversal**             | ✅ Yes       | Reverse then enumerate.                    |
| **Homomorphism**         | ✅ Yes       | Map then enumerate.                        |
| **Inverse Homomorphism** | ✅ Yes       | Pre-image enumeration.                     |

**Remember:**  
RE = **TM that may not halt**  
Biggest class before **Undecidable**

##### **Final Big Picture (Strict Hierarchy)** ⭐⭐⭐

`RL ⊂ DCFL ⊂ CFL ⊂ CSL ⊂ Recursive ⊂ RE`

- **RL** → closed under ==everything==
- **DCFL** → only strong property: **Complement**
- **CFL** → powerful but **==no complement==, ==no intersection==**
- **CSL** → complement closed (big jump)
- **Recursive** → ==fully decidable==, ==perfect closure==
- **RE** → expressive but **not complement closed**

This hierarchy is **strict** and **exam-critical**.

---

### Determinism and Decideabliltiy

##### **Deterministic vs Non-Deterministic ⭐**

| **Language Class**                     | **Non-Deterministic Form**                     | **Deterministic Form**          | Relationship                                                                              |
| -------------------------------------- | ---------------------------------------------- | ------------------------------- | ----------------------------------------------------------------------------------------- |
| **Regular Languages (RL)**             | NFA (Non-Deterministic FA)                     | DFA (Deterministic FA)          | ==Deterministic = Non-<br>Deterministic==<br><br>both define same RL set                  |
| **Context-Free Languages (CFL)**       | NPDA (Non-Deterministic PDA)                   | DPDA (Deterministic PDA)        | ==Deterministic ⊂ Non-Deterministic== ⭐<br><br>(strict subset)                            |
| **Context-Sensitive Languages**        | Non-deterministic LBA                          | Deterministic LBA (rarely used) | Unclear <br>(generally assumed equal)                                                     |
| **Recursive Languages** <br>(⭐ Extra ) | Non-deterministic TM ~ (Linear Bound Automata) | Deterministic TM                | ==Deterministic = Non-Deterministic==<br><br>Both accept same class (decidable languages) |
| **Recursively Enumerable (RE)**        | Non-deterministic TM ~ (Linear Bound Automata) | Deterministic TM                | ==Deterministic = Non-Deterministic==<br><br>Equivalent in power (semi-decidable)         |

**Important Notes:**

- **Regular Languages**:  
    Always deterministic → NFA ≡ DFA.
    
- **Context-Free Languages (CFL)**:
    - Recognized by **NPDA**
    - **Subset of CFL** can be recognized by **DPDA** → called **DCFL (Deterministic CFL)**

    - Example:
        - `{ aⁿbⁿ | n ≥ 0 }` → in **DCFL**
        - `{ aⁿbⁿcⁿ | n ≥ 0 }` → **not** in CFL at all
        - `{ ww | w ∈ Σ* }` → ==CFL but **not DCFL**==
            
- **Context-Sensitive Languages**:  
    Typically handled by **Linear Bounded Automaton (LBA)**. Deterministic vs non-deterministic distinction exists, but is not widely explored.
    
- **Recursive** and **Recursively Enumerable (RE)** languages:  
    Both can be defined using **Turing Machines**. Every ==recursive language is **decidable**==, and ==RE languages are **semi-decidable**.==
	
```
Regular ⊆ DCFL ⊆ CFL ⊂ CSL ⊂ RE
        ⬑     ⬑
        DFA    DPDA
         ↑      ↑
        NFA    NPDA
```


##### **Decidable vs Recognizable Language** ⭐

- ==Recursive  -> Turing-decidable languages== 
- ==Recursive Enumerable -> Turing-recognizable language==

| Feature                  | ==**Turing Decidable (Recursive)**==           | ==**Turing Recognizable (RE)**==               |
| ------------------------ | ---------------------------------------------- | ---------------------------------------------- |
| Machine type             | **Total Turing Machine** -> Stronger Guarantee | **Partial Turing Machine** -> Weaker Guarantee |
| Decideability            | **Decideable**                                 | **Semi-Decideable**                            |
| TM halts on              | **Every input**                                | **Only on inputs in `L`**                      |
| Acceptance               | Accepts strings in `L`                         | Accepts strings in `L`                         |
| Rejection                | Rejects strings not in `L`                     | May loop forever on strings not in `L`         |
| Halting guarantee        | Always halts (accept/reject)                   | No halting guarantee for non-members           |
| Complement               | `L` and `¬L` are both RE                       | ¬L may not be recognizable                     |
| Closure under complement | ✅ Yes                                          | ❌ No                                           |
| Language power           | Less powerful                                  | More expressive                                |
| Relationship             | Decidable ⊂ RE                                 | Superset of Decidable                          |
| Classic example          | Regular, CFL, CSL                              | Halting Problem language                       |

    
**Key Relations**
- Decidable ⊂ Recognizable
- Some recognizable languages are **not decidable** (e.g., Halting Problem)

**One-line exam difference**

> Decidable ⇒ TM halts on all inputs  
> Recognizable ⇒ TM halts only on accepted inputs