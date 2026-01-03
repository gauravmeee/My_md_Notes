
# SOP & POS Form 
### [Sum of Products (Part 1) | SOP Form](https://youtu.be/xnLBbOYYnHM)


In Boolean algebra, functions can be expressed in various forms, two of the most important being the Sum of Products (SOP) form and the Product of Sums (POS) form. This explanation focuses on the SOP form, also written as **SOP**, where 'S' stands for Sum, 'O' for Of, and 'P' for Product.

##### **Understanding Combinations and Truth Tables**

A fundamental concept in Boolean algebra is the t==ruth table, which lists all possible input combinations== for a function and their corresponding outputs.

- **Total Combinations**: The total number of possible combinations for '`n`' variables is given by the formula `2^n`.

- **Example**: For three variables (A, B, C), the total number of combinations is 2^3 = 8. These combinations range from 000 (binary) to 111 (binary).

Let's consider an example truth table for a function F with three variables A, B, and C:

| Decimal <br>Equivalent | A   | B   | C   | F (Output) |
| ---------------------- | --- | --- | --- | ---------- |
| 0                      | 0   | 0   | 0   | 0          |
| 1                      | 0   | 0   | 1   | 0          |
| 2                      | 0   | 1   | 0   | **1**      |
| 3                      | 0   | 1   | 1   | 0          |
| 4                      | 1   | 0   | 0   | **1**      |
| 5                      | 1   | 0   | 1   | **1**      |
| 6                      | 1   | 1   | 0   | **1**      |
| 7                      | 1   | 1   | 1   | **1**      |
Note: 
- The decimal equivalent columns and min term columns are added for a more complete understanding as explained later. The original source provides the A, B, C, F columns and indicates the F values.)_


In Boolean Algebra, we can express this function `F` in two Forms
1. **SOP (Sum of Products)**: OR of multiple AND terms (e.g., `F = A'B + AB'`).
2. **POS (Product of Sums)**: AND of multiple OR terms (e.g., `F = (A + B')(A' + B)`).

Also, we can represent these in two way 
- **Canonical(Standard) form**: SOP or POS expression where each term contains **all variables** in the system (either complemented or uncomplemented).
    
- **Minimal form**: Simplified SOP or POS expression with the **least number of literals and terms** possible.

##### **Standard or Canonical SOP Form**

The **SOP form is ==written only when the function's output (F) is HIGH (1)**==. For each ==combination where F is 1==, a 'product' term is formed.

- **Variable Representation in Product Terms**:
    - If a variable is **low (0)**  it is represented by its **complement** 
	    - (e.g., A low ⭢ A complement or A').
    - If a variable is **high (1)**, it is represented **as it is** 
	    - (e.g., B high ⭢ B).

Note: 
- The '**product**' in Sum of Products refers to the **AND operator** (`.`) and the '**sum**' refers to the **OR operator** (`+`)
- Although they look like arithmetic product and sum, they represent logical AND and OR operations.

Let's derive the canonical SOP form for our example function F:

- **Case 1**: `A=0, B=1, C=0` ⭢ `F=1`. This gives the term **A'BC'**.

- **Case 2**: `A=1, B=0, C=0` ⭢ `F=1`. This gives the term **AB'C'**.

- **Case 3**: `A=1, B=0, C=1` ⭢ `F=1`. This gives the term **AB'C**.

- **Case 4**: `A=1, B=1, C=0` ⭢ `F=1`. This gives the term **ABC'**.

- **Case 5**: `A=1, B=1, C=1` ⭢ `F=1`. This gives the term **ABC**.

The **Standard or Canonical SOP form** is the sum (OR) of all these product terms where the function is high:
```
            SOP Form
    ╭-------------------------------╮
    
F = A'BC' + AB'C' + AB'C + ABC' + ABC
```

==This form is called **standard or canonical** because it is derived directly from the truth table.==

##### **Min Terms**


A **min term** is a ==product term where all variables of the function appear, either in their true form or complemented form==.
- Example: Minterm `m3 = A' B C`


**In Detail:**
- A **min term** is a `AND` of all variables (each in true or complemented form) that gives **1 for exactly one combination** of inputs. 
- so, **minterm** is a product (AND) of all variables where only **one specific input combination** makes the minterm equal to `1`; for all other combinations it will be `0`.
- Minterm `A' B C`  So, `A=0, B=1, C=1` → `A'=1`, so `1·1·1 = 1` ✅
- Any other input combination → at least one variable in the AND will be 0, so result = 0 ❌
- So a minterm is "true" for only **one row** of the truth table.

**Min term Relation with SOP**
- **SOP** form is the Sum(**OR) of minterms**. 
- Each minterm represents a single input combination where the function is 1.

**Notation**: Min terms are represented by a **small 'm'** followed by the decimal equivalent of the binary input combination. For example, 000 is m0, 001 is m1, and so on.


Referring back to our truth table, we can list the min terms:

| A   | B   | C   | F     | Min Term |
| --- | --- | --- | ----- | -------- |
| 0   | 0   | 0   | 0     | m0       |
| 0   | 0   | 1   | 0     | m1       |
| 0   | 1   | 0   | **1** | m2       |
| 0   | 1   | 1   | 0     | m3       |
| 1   | 0   | 0   | **1** | m4       |
| 1   | 0   | 1   | **1** | m5       |
| 1   | 1   | 0   | **1** | m6       |
| 1   | 1   | 1   | **1** | m7       |

Therefore, the function F can also be expressed as the sum (OR) of the min terms for which F is high:

```
              Sum of Min Terms = SOP
             ╭--------------------╮
F(A, B, C) = m2 + m4 + m5 + m6 + m7
```

This can also be concisely written using the summation notation:
```
             Summation of Min Terms = SOP
             ╭--------------------╮
F(A, B, C) = Σm(2, 4, 5, 6, 7)
```

The summation symbol (`Σ`) indicates that you are taking the s`um (OR operation)` of these min terms. 

> This notation is often used in exams to provide the function's definition without a full truth table.

##### **Minimal SOP Form**

The ==**Standard (Canonical) SOP form** derived directly from the truth table== can often be ==simplified or **minimized** using Boolean algebra rules==. The goal of minimization is to reduce the complexity of the expression, which translates to using fewer logic gates when implementing the circuit. Both the canonical and minimal forms will produce the same truth table output.

Let's minimize our function F = A'BC' + AB'C' + AB'C + ABC' + ABC using Boolean algebra, following the steps outlined in the source:

```
            Canonical SOP Form
    ╭-------------------------------╮
F = A'BC' + AB'C' + AB'C + ABC' + ABC
```

**Step 1: Apply Distributive Law (X.Y + X.Z = X(Y+Z)) to common terms.** We can see common terms in the last four parts:
- `AB'` is common in `AB'C'` and `AB'C`.
- `AB` is common in `ABC'` and `ABC`.
```
F = A'BC' + (AB'C' + AB'C) + (ABC' + ABC)
F = A'BC' + AB'(C' + C) + AB(C' + C)
```

**Step 2: Apply the Complement Law (X' + X = 1).** We know that `C' + C = 1`.
```
F = A'BC' + AB'(1) + AB(1)
F = A'BC' + AB' + AB
```

**Step 3: Apply Distributive Law again.** We can take `A` common from `AB'` and `AB`.
```
F = A'BC' + A(B' + B)
```

**Step 4: Apply the Complement Law again.** We know that `B' + B = 1`.
```
F = A'BC' + A(1)
F = A'BC' + A
```

**Step 5: Apply the Distributive Law (A + A'X = A + X).** Here, `A` corresponds to `A`, and `X` corresponds to `BC'`.

```
    Minimal SOP Form
    ╭----╮
F = A + BC'
```

This final expression, `A + BC'`, is the **Minimal SOP form** of the function. It is a much simpler expression compared to the canonical form, yet it performs the identical logical operation.

##### **Summary**

- **Standard or Canonical SOP Form**: Derived directly from the truth table by ORing all product terms where the function is high. All variables are present in each product term (either complemented or uncomplemented).
- **Minimal SOP Form**: A simplified version of the canonical form achieved through Boolean algebra rules, resulting in fewer terms or fewer literals per term, thus requiring fewer logic gates for implementation.


---

### [Sum of Products (Part 2) | SOP Form](https://youtu.be/NGgNoa0_zns)


##### **Revisiting Canonical (Standard) SOP Form**

The **Canonical or Standard SOP form** is characterised by each product term (also known as a min term) containing **all the variables** of the function, either in their normal (uncomplemented) form or complemented form.

- **Definition**: In a canonical SOP expression, if a function has 'n' variables, every min term will explicitly contain all 'n' variables.
- **Variable Representation**:
    - A variable in its **normal form** (e.g., A, B) represents a HIGH (1) state.
    - A variable in its **complemented form** (e.g., A', B') represents a LOW (0) state.

Let's consider an Same example truth table for a function F with three variables A, B, and C:

Consider a function `F` with two variables, `A` and `B`. 

| Decimal <br>Equivalent | A   | B   | C   | F (Output) |
| ---------------------- | --- | --- | --- | ---------- |
| 0                      | 0   | 0   | 0   | 0          |
| 1                      | 0   | 0   | 1   | 0          |
| 2                      | 0   | 1   | 0   | **1**      |
| 3                      | 0   | 1   | 1   | 0          |
| 4                      | 1   | 0   | 0   | **1**      |
| 5                      | 1   | 0   | 1   | **1**      |
| 6                      | 1   | 1   | 0   | **1**      |
| 7                      | 1   | 1   | 1   | **1**      |

An example of a canonical SOP expression is:
```
F = A'B + AB + A'B'
```

In this example:

- `A'B` (Min term 1, or m1) has `A` in complemented form and `B` in normal form.
- `AB` (Min term 3, or m3) has both `A` and `B` in normal form.
- `A'B'` (Min term 0, or m0) has both `A` and `B` in complemented form.

As you can see, each product term (`A'B`, `AB`, `A'B'`) includes both variables `A` and `B`, satisfying the requirement for canonical SOP.

##### **Understanding Minimal SOP Form**

The **Minimal SOP form** is a simplified version of the canonical form where **not all variables are necessarily present** in each product term. The primary goal of achieving a minimal form is to reduce the complexity of the Boolean expression, which translates to a simpler and more efficient logic circuit implementation.

- **Minimisation Methods**: This form is obtained by simplifying the canonical SOP expression using methods like:
    - ==**Boolean Algebra**:== Applying Boolean identities and theorems.
    - ==**Karnaugh Maps (K-maps)**:== A graphical method for simplifying Boolean expressions.
    - ==**Tabular Method (Quine-McCluskey)**:== A systematic algorithmic method for larger expressions.

**Example**: Consider a function `G` with three variables, `A`, `B`, and `C`. An example of a minimal SOP expression is:

```
G = A + BC
```

In this example:

- The first product term (`A`) is missing variables `B` and `C`.
- The second product term (`BC`) is missing variable `A`.

This clearly demonstrates that in a minimal SOP form, product terms do not always contain all variables of the function. Both canonical and minimal forms describe the same logic, but the minimal form is more compact.
##### **Problem 1: Minimising SOP from a Truth Table**

**Question**: For the given truth table, minimize the SOP expression.

**Truth Table**:

|A|B|Y|
|---|---|---|
|0|0|0|
|0|1|**1**|
|1|0|0|
|1|1|**1**|

**Solution**:

**Step 1: Write the Canonical SOP Form from the Truth Table.** As established, we write the SOP form only when the output `Y` is **HIGH (1)**.

- For `A=0, B=1, Y=1`: This corresponds to the product term `A'B` (A complement B).
- For `A=1, B=1, Y=1`: This corresponds to the product term `AB`.

Combining these, the canonical SOP form is:
```
Y = A'B + AB
```

**Step 2: ==Minimize the SOP Expression using Boolean Algebra.==** We need to simplify `Y = A'B + AB`.
- **Identify Common Terms**: Both terms have `B` in common.
- **Apply Distributive Law (X.Y + X.Z = X(Y+Z))**:
    ```
    Y = B(A' + A)
    ```
    
- **Apply Complement Law (X' + X = 1)**: We know that `A' + A` equals `1`
    ```
    Y = B(1)
    ```
    
- **Apply Identity Law (X.1 = X)**:
    ```
    Y = B
    ```
    

Therefore, the **minimal SOP form** for this function is `Y = B`.

**Verification**: Let's quickly check this against the truth table:
- When `B` is 0, `Y` is 0.
- When `B` is 1, `Y` is 1. This matches the truth table exactly, confirming our minimal expression is correct.

##### **Problem 2: Minimising SOP from Given Min Terms**

**Question**: Simplify the expression for `Y(A,B) = Σm(0, 2, 3)`.

**Understanding the Input**: The notation `Σm(0, 2, 3)` indicates that the function `M` is HIGH (1) for min terms `m0`, `m2`, and `m3`. Since the highest min term is `m3`, this implies a function with **two variables** (as 2^2 = 4 combinations, m0 to m3). Let's assume the variables are `A` and `B`.

**Step 1: Write the Canonical SOP Form from Min Terms.** First, we need to map the min terms to their corresponding binary values and then to product terms:

- **m0**: Binary `00`. If `A=0, B=0`, the term is `A'B'`.
- **m2**: Binary `10`. If `A=1, B=0`, the term is `AB'`.
- **m3**: Binary `11`. If `A=1, B=1`, the term is `AB`.

Combining these, the canonical SOP form is:

```
Y = A'B' + AB' + AB
```

**Step 2: Minimize the SOP Expression using Boolean Algebra.** We need to simplify `Y = A'B' + AB' + AB`. There are a few ways to group terms. The source suggests taking `B'` common from the first two terms or `A` common from the last two terms. Let's follow the first approach:

- **Option 1: Take `B'` common from the first two terms.**
    ```
    Y = (A'B' + AB') + AB
    Y = B'(A' + A) + AB
    ```
    
- **Apply Complement Law (X' + X = 1)**: `A' + A` equals `1`.
    ```
    Y = B'(1) + AB
    Y = B' + AB
    ```
    
- **Apply ==Distributive Law== (==`X + X'Y = X + Y`==)**: Here, `X` is `B'` and `Y` is `A`.  ⭐

    ```
    Y = B' + A
    ```

Therefore, the **minimal SOP form** for this function is `Y = B' + A`.


**Note:**
- In Distributive Law neglect '`B`' in 'AB' resulting in B' + A. This is a special form of the distributive law `X + X'Y = X + Y` (or `B' + B(A) = B' + A`).


---
---

### [Product of Sums (Part 1) | POS Form](https://youtu.be/nXsiLPJfDZ4?list=TLGGCrsqH0J5jiQxMDA4MjAyNQ)


**Product of Sums (POS) form**, which is a method for representing Boolean functions, complementing the previously studied Sum of Products (SOP) form.

##### **Introduction to POS Form**

- **POS Form**: An abbreviation for **Product of Sums** form.

- **Purpose**: POS form is primarily used to represent Boolean functions when the **output (Y) is zero (low)**. This is in contrast to the SOP form, which is used when the output is high (one).

- **Functionality**: Regardless of whether a Boolean function is represented in POS or SOP form, its functionality remains the same, yielding a certain output depending on the input.

##### **Truth Table Example**

The explanation uses a truth table with three variables: A, B, and C. With three variables, there are `2^3` = 8 possible combinations.

**Example Truth Table:**

|A|B|C|Output (Y)|
|---|---|---|---|
|0|0|0|**0**|
|0|0|1|**0**|
|0|1|0|1|
|0|1|1|**0**|
|1|0|0|1|
|1|0|1|1|
|1|1|0|1|
|1|1|1|1|

**Note:** 
- For POS form, we focus on the cases where the output Y is **0**. In this example, there are three such cases.

##### **Variable Representation in POS Form**

The way variables are represented in ==POS form is **opposite** to that in SOP== form:
- If a variable (e.g., A) is **0**, it is written as **A** (normal form).
- If a variable (e.g., A) is **1**, it is written as **A complement** (A').

This convention is crucial for directly writing the POS form from the truth table.

##### **Deriving Canonical (Standard) POS Form from the Truth Table**

The canonical POS form is derived by considering only the cases where the output Y is **low (zero)**.

1. **Identify Zero Output Cases**: From the example truth table, the output Y is 0 for the following combinations:

    - Case 1: `A=0, B=0, C=0`
    - Case 2: `A=0, B=0, C=1`
    - Case 3: `A=0, B=1, C=1`

2. **Formulate Max Terms**: For each case where Y is 0, create a Max term using the POS variable representation rules:
    
    - **Case 1 (`A=0, B=0, C=0`)**:
        - A is 0, so write **A**.
        - B is 0, so write **B**.
        - C is 0, so write **C**.
        - Max term: **`(A + B + C)`**.

    - **Case 2 (`A=0, B=0, C=1`)**:
        - A is 0, so write **A**.
        - B is 0, so write **B**.
        - C is 1, so write **C complement (C')**.
        - Max term: **`(A + B + C')`**.

    - **Case 3 (`A=0, B=1, C=1`)**:
        - A is 0, so write **A**.
        - B is 1, so write **B complement (B')**.
        - C is 1, so write **C complement (C')**.
        - Max term: **`(A + B' + C')`**.

3. **Combine Max Terms**: The canonical POS form for Y is the **product (AND)** of these Max terms: 
```
                POS Form
    ╭------------------------------------------╮
Y = (A + B + C) . (A or B or C') . (A + B' + C')
```

- **Canonical (Standard) POS Form Definition**: In canonical or standard POS form, **each Max term must contain all variables** (in normal or complemented form). For instance, in the example above, each of the three Max terms includes all three variables (A, B, and C).

##### **Proving POS Form from SOP Form (using De Morgan's Law)** ⭐

It is possible to derive the POS form from the SOP form by using **De Morgan's Law**. This method also serves to prove the direct derivation from the truth table.

1. **Start with the Complement of Y in SOP**: To derive POS from SOP, consider the cases where the output Y is 0. If Y is 0, then its complement (Y') is 1. We ==**represent Y' using SOP conventions**== (where 0 is complement, 1 is normal):
    
    - For `A=0, B=0, C=0` ⭢ `Y'=1`: `A'B'C'`
    - For `A=0, B=0, C=1` ⭢ `Y'=1`: `A'B'C`
    - For `A=0, B=1, C=1` ⭢ `Y'=1`: `A'BC` 
	  So, `**Y' = (A' B' C') + (A' B' C) + (A' B C)**`

2. **Take the Complement of Both Sides**: To get Y, take the complement of Y' and the entire SOP expression: 
	**`Y = (Y')' = [ (A'B'C') + (A'B'C) + (A'BC) ]'`**
    
3. **Apply De Morgan's Law**: De Morgan's Law states that (`X + Y)'` = `X' Y'`. Apply this law sequentially:
    
    - First application (across the OR operators): **Y = (A'B'C')' AND (A'B'C)' AND (A'BC)'**
    - Second application (within each term, transforming AND to OR):
        - `(A'B'C')'` becomes `(A'') + (B'') + (C'')` 
	        => **(`A + B + C`)**
        - `(A'B'C)'` becomes `(A'') + (B'') + (C')` 
	        =>  **(`A + B + C'`)**
        - `(A'BC)'` becomes `(A'') + (B') + (C')` 
	        => **(`A + B' + C')`**

4. **Result**: **`Y = (A + B + C).(A + B + C').(A + B' + C')`** This result is identical to the canonical POS form derived directly from the truth table, confirming the validity of both methods.

- **Direct Conversion**: It is **not necessary** to use **==De Morgan's theorem==** every time to convert SOP to POS or to write the POS form. One can directly write the POS form using the established convention: variable as normal for 0, and complemented for 1.

##### **Max Terms**


A **max term** is a ==sum term where all variables of the function appear, either in their true form or complemented form==.
- Example: Maxterm M3=A+B′+C′M3 = A + B' + C'

**Structure**: A Max term is a **sum (OR) of literals** (variables in normal or complemented form), for example, (A or B or C).

**Naming**: Max terms are named "Max term" due to their perceived "size" when written, like (A or B or C), which appears larger than a Min term like (A and B and C). There is no special reason beyond this visual size for the naming convention.

**In Detail:**

- A **max term** is an `OR` of all variables (each in true or complemented form) that gives **0 for exactly one combination** of inputs.
    
- So, a maxterm is a sum (OR) of all variables where only **one specific input combination** makes the maxterm equal to `0`; for all other combinations it will be `1`.
    
- Maxterm `A + B′ + C′` → For `A=0, B=1, C=1`:  
    `A=0` , `B′=0`, `C'=0` → `0 + 0 + 0` = 0 
    
- Any other input combination → at least one variable in the OR will be 1, so result = 1 ❌
    
- So a maxterm is "false" for only **one row** of the truth table.
    

**Max term Relation with POS**

- **POS** form is the Product (**AND**) of maxterms.
    
- Each maxterm represents a single input combination where the function is 0.
    


**Notation**: Max terms are represented by a **capital 'M'** followed by the decimal equivalent of the binary input combination. For example, 000 is M0, 001 is M1, and so on.


Referring back to the truth table, we can list the max terms:

| A   | B   | C   | F     | Max Term |
| --- | --- | --- | ----- | -------- |
| 0   | 0   | 0   | **0** | M0       |
| 0   | 0   | 1   | **0** | M1       |
| 0   | 1   | 0   | 1     | M2       |
| 0   | 1   | 1   | **0** | M3       |
| 1   | 0   | 0   | 1     | M4       |
| 1   | 0   | 1   | 1     | M5       |
| 1   | 1   | 0   | 1     | M6       |
| 1   | 1   | 1   | 1     | M7       |

Therefore, the function F can also be expressed as the product (AND) of the max terms for which F is low:
```
              Product of Max Terms = POS
             ╭----------╮
F(A, B, C) = M0 · M1 · M3
```

This can also be concisely written using the product notation:
```
             Product of Max Terms = POS
             ╭--------╮
F(A, B, C) = ΠM(0, 1, 3)
```

The product symbol (`Π`) indicates that you are taking the `product (AND operation)` of these max terms.

In POS form, the ==individual terms are called **Max terms**.==

##### **Reducing Canonical POS to Minimal POS Form**

The canonical POS form can often be simplified to a **minimal POS form** using Boolean algebra. The minimal form typically has fewer literals or terms, making it more efficient for implementation.

**Example of Reduction:** Starting with the canonical POS form: **`Y = (A + B + C) . (A + B + C') . (A + B' + C')**

1. **Apply Distributive Law to the first two terms**: Recall the distributive law: `(X + Y)(X + Z) = X + (Y . Z)`. 
	Here, let `X = (A + B)`, `Y = C`, `Z = C'`.
	Then `(A + B + C)(A + B + C')` = `(A + B) + (C · C')` = `(A + B) + 0` = `(A + B)`.
	So with the third term: `Y` = `(A + B) · (A + B' + C')`

    
2. **Apply Distributive Law again**: 
	Start from: `Y = (A + B) · (A + B' + C')`
	Let `X = A`, so `Y = A + [B · (B' + C')]`
	Compute: `B · (B' + C')` = `(B · B') + (B · C')` = `0 + (B · C')` = `B · C`'
	Thus: `Y = A + (B · C')`
    
3. **Apply Distributive Law one more time (reverse direction)**: 
	`Y = (A + B) . (A + C')`
    
    This is the **minimal POS form** for the given function.

- **Minimal POS Form Definition**: In minimal POS form, **not all variables are necessarily present** in every Max term. For instance, in `(A or B)`, the variable C is missing, and in `(A or C')`, the variable B is missing.
    
- **Conversion from Minimal to Canonical**: In examinations, you might be given a minimal POS form and asked to convert it back to canonical POS. Two methods exist:
    
    1. **Using the Truth Table**: Evaluate the minimal expression for all input combinations to determine the output Y, then write the canonical POS form based on the zero outputs.
    2. **Another Method**: (To be explained in a separate presentation).

---

### [Product of Sums (Part 2) | POS Form](https://youtu.be/ihTH1C6qCYI?list=TLGGdbs5XF6nP9wxMDA4MjAyNQ)



This presentation delves deeper into the **Product of Sums (POS) form**, covering its types, standard representation, and methods for simplification and alternative notation.

#### 1. Types of POS Forms

As previously discussed, POS form primarily exists in two types:

- **Canonical Form**: Also known as the **Standard Form**.
- **Minimal Form**.

#### 2. Truth Table Example (Two Variables)

This part of the lecture uses a simpler truth table with two variables, A and B, to illustrate the concepts. With two variables, there are $2^2 = 4$ possible combinations.

**Example Truth Table:**

|A|B|Output (Y)|
|---|---|---|
|0|0|1|
|0|1|**0**|
|1|0|1|
|1|1|**0**|

_Note: For POS form, we focus on the cases where the output Y is **0**. In this example, there are two such cases._

#### 3. Deriving Canonical (Standard) POS Form

To derive the canonical POS form, we follow the established convention for variable representation and focus on cases where the output Y is **low (zero)**.

- **Variable Representation Rule (POS)**:
    - If a variable (e.g., A) is **0**, it is written as **A** (normal form).
    - If a variable (e.g., A) is **1**, it is written as **A complement** (A').

1. **Identify Zero Output Cases**: From the example truth table, the output Y is 0 for the following combinations:
    
    - Case 1: A=0, B=1 (Decimal equivalent: 1)
    - Case 2: A=1, B=1 (Decimal equivalent: 3)
2. **Formulate Max Terms**: For each case where Y is 0, create a Max term using the POS variable representation rules:
    
    - **Case 1 (A=0, B=1)**:
        
        - A is 0, so write **A**.
        - B is 1, so write **B complement (B')**.
        - Max term: **(A or B')**.
    - **Case 2 (A=1, B=1)**:
        
        - A is 1, so write **A complement (A')**.
        - B is 1, so write **B complement (B')**.
        - Max term: **(A' or B')**.
3. **Combine Max Terms**: The canonical POS form for Y is the **product (AND)** of these Max terms: **Y = (A or B') AND (A' or B')**
    

#### 4. Deriving Minimal POS Form

The canonical POS form can be simplified to a **minimal POS form** using Boolean algebra, specifically the distributive law in this case.

**Starting with the canonical POS form:** **Y = (A or B') AND (A' or B')**

1. **Apply Distributive Law**: Recall the distributive law: **(X or Y) AND (X or Z) = X or (Y AND Z)**. In our expression, notice that **B' is common** to both terms. Let X = B'. So, Y = (B' or A) AND (B' or A') Applying the distributive law: Y = B' or (A AND A')
    
2. **Simplify using Boolean Identity**: We know that **A AND A' = 0**. So, Y = B' or 0
    
3. **Final Minimal Form**: Finally, **Y = B'**
    
    This is the **minimal POS form** for the given function.
    
#### 5. Max Term Representation

In exams, truth tables are not always provided. Instead, Boolean functions in POS form are often represented using **Max term notation**.

- **Max Term Symbol**: Max terms are represented by a **capital M (M)**. A subscript is used to denote the decimal equivalent of the input combination for that Max term.
    
    - M0 for (A or B or C) when A=0, B=0, C=0.
    - M1 for (A or B or C') when A=0, B=0, C=1.
    - M3 for (A or B' or C') when A=0, B=1, C=1. (from Part 1 example)
- **POS Function Notation**: For Product of Sums, the **Greek letter Pi ($\Pi$)** is used instead of summation ($\Sigma$) which is used for SOP. This $\Pi$ signifies the "product" of Max terms.
    
- **Example from Truth Table**: From our 2-variable example truth table, the output Y is 0 for:
    
    - A=0, B=1 (decimal 1) $\rightarrow$ Max term M1
    - A=1, B=1 (decimal 3) $\rightarrow$ Max term M3
    
    Therefore, the function Y can be represented as: **Y = $\Pi$ M (1, 3)** This compact notation indicates that the function Y is the product of Max terms M1 and M3.
    

#### 6. Relationship between Max Terms and Min Terms

Max terms and Min terms are complementary.

- If a function is defined by its Max terms (where Y=0), then the Min terms (where Y=1) are simply the **missing decimal equivalents**.
    
- **Example**: If Y = $\Pi$ M (1, 3) (for a 2-variable function with combinations 0, 1, 2, 3), Then the Min terms (where Y=1) would be for decimal values **0 and 2**. So, in SOP form, this would be Y = $\Sigma$ m (0, 2).
    

This shows how you can find the Max terms if Min terms are known, and vice versa, just by identifying the complement set of decimal values within the total possible combinations.

#### 7. Comparison of SOP and POS Forms (Gate Usage)

The choice between SOP and POS forms can sometimes depend on the preferred type of logic gates for implementation.

- **Sum of Products (SOP) Form**:
    
    - Typically uses **more AND gates**.
    - Uses **fewer OR gates**.
    - Example: A AND B OR A' AND B' uses two AND gates and one OR gate.
    - **Ideal when**: You want to use more AND gates.
- **Product of Sums (POS) Form**:
    
    - Typically uses **more OR gates**.
    - Uses **fewer AND gates**.
    - Example: (A OR B') AND (A' OR B') uses two OR gates and one AND gate.
    - **Ideal when**: You want to use more OR gates.

This concludes the basic introduction to POS form, its standard and minimal representations, notation, and a brief comparison with SOP forms based on gate implementation.

For n variables, Minterm index i ↔ Maxterm index j = (2^n - 1) - i

Example for 3 variables (A, B, C):

|Binary|Decimal|Minterm|Maxterm|
|---|---|---|---|
|000|0|m0 = A'B'C'|M0 = (A + B + C)|
|001|1|m1 = A'B'C|M1 = (A + B + C')|
|010|2|m2 = A'BC'|M2 = (A + B' + C)|
|011|3|m3 = A'BC|M3 = (A + B' + C')|
|100|4|m4 = AB'C'|M4 = (A' + B + C)|
|101|5|m5 = AB'C|M5 = (A' + B + C')|
|110|6|m6 = ABC'|M6 = (A' + B' + C)|
|111|7|m7 = ABC|M7 = (A' + B' + C')|

### [Binary Coded Decimal (BCD) Code](https://www.youtube.com/watch?v=0rLiYpy2CqQ)

### [Excess-3 Code (XS-3 Code)](https://youtu.be/LHw8TVk9iOY)

### [Excess-3 Code Addition](https://www.youtube.com/watch?v=CXn4lxBlO2U)

### [Introduction to Gray Code](https://youtu.be/0dPN4gh0CKI)

### [Binary to Gray Code Conversion](https://youtu.be/cF-Q5j7RUEw)

### [Karnaugh Map (K' Map) - Part 1](https://youtu.be/FPrcIhqNPVo)

### [Karnaugh Map (K' Map) - Part 2](https://youtu.be/uWjKzsWXAF4)

### [Karnaugh Map (K' Map) - Part 3](https://youtu.be/p7ittaZrZ1g)