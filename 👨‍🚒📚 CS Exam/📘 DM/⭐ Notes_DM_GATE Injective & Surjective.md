
### Composition of Functions –  (GATE Detailed Notes)


### Injective & Surjective


##### **Function**

A function $f: A \to B$ maps **each element of set A to exactly one element of set B**.


##### **Injective (One-to-One)**

```
A                  B
|                  |
|  a1  ─────────▶  b1
|  a2  ─────────▶  b2
|  a3  ─────────▶  b3
|                  |

```

A function $f: A \to B$  is **injective** if:  

$$f(a_1) = f(a_2) \Rightarrow a_1 = a_2  $$

-> Different inputs give different outputs.


##### **Surjective (Onto)**

```
A                  B
|                  |
|  a1  ─────────▶  b1
|  a2  ─────┐
|           └────▶ b2

```

A function $f: A \to B$  is **surjective** if:  
$$\forall b \in B, \exists a \in A \text{ such that } f(a) = b  $$

-> Every element of the codomain is covered.

##### **Bijective**

A function that is **both injective and surjective**.


---
### Composition of Functions

If:
- $g: A \to B$ 
- $f: B \to C$

Then the **composition**:  
$$(f \circ g)(a) = f(g(a))  $$

is a function from **A to C**.


##### **Properties of Composition** ⭐

**Injectivity**
- If **both ( f ) and ( g )** are injective → ( $f \circ g$ ) is injective
- If ($f \circ g$ ) is injective → **( g ) must be injective**
- Injectivity of ( $f \circ g$ ) gives ==**no guarantee** about injectivity of ( f )== ⭐


**Surjectivity**
- If **both ( f ) and ( g )** are surjective → ( $f \circ g$ ) is surjective
- If ( $f \circ g$ ) is surjective → **( f ) must be surjective**
- Surjectivity of ( $f \circ g$ ) gives ==**no guarantee** about surjectivity of ( g )== ⭐
    
##### **Option Analysis Pattern**

When given properties of $f$, $g$, and $f \circ g$:

|     | Given                                  | Result                                  |
| --- | -------------------------------------- | --------------------------------------- |
| 1   | $f \circ g$ is **injective**           | ✅ $g$ is **injective**                  |
| 2   | $f \circ g$ is **surjective**          | ✅ $f$ is **surjective**                 |
| 3   | $f$ and $g$ are **injective**          | ✅ $f \circ g$ is **injective**          |
| 4   | $f$ and $g$ are **surjective**         | ✅ $f \circ g$ is **surjective**         |
| 5   | $g$ and $f \circ g$ are **injective**  | ❌ **$f$ is not necessarily Injective**  |
| 6   | $f$ and $f \circ g$ are **surjective** | ❌ $g$ **is not necessarily Surjective** |



$f \circ g$ is **injective** 
- $f \circ g$ is **injective**  ------> $g$ is **injective**
- $f \circ g$ is **injective** <------ $f$ and $g$ are **injective**

$f \circ g$ is **surjective**
- $f \circ g$ is **surjective** -----> $f$ is **surjective**
- $f \circ g$ is **surjective** <----- $f$ and $g$ are **surjective**

**Not Guaranteed**
- $f$ and$f \circ g$ are **surjective** --X-->  **No guarantee about $g$
- $g$ and$f \circ g$ are **injective** --X--> **No guarantee about $f$**




##### **Proofs: Composition Properties**

- Let $g:A \to B$ and $f:B \to C$.

**1. $f \circ g$ injective $\implies g$ injective**

- **Proof:**  
	- Suppose $g(x_1) = g(x_2)$ for $x_1, x_2 \in A$. 
	- Apply $f$ to both sides:  $f(g(x_1)) = f(g(x_2) \implies (f \circ g)(x_1) = (f \circ g)(x_2)$  
	- Since $(f \circ g)$ is injective, we must have $x_1 = x_2$.  
	- $\therefore g \text{ is injective.}$  

**2. $f \circ g$ surjective $\implies f$ surjective**

- **Proof:**  
	- Let $c \in C$ be arbitrary. 
	- Since $f \circ g$ is surjective, there exists $a \in A$ such that 
	- $(f \circ g)(a) = c \implies f(g(a)) = c$
	- Let $b = g(a) \in B$. Then $f(b) = c$. 
	- Since this holds for all $c \in C$,  
	- $\therefore f \text{ is surjective.}$

**3. $f$ and $g$ injective $\implies$ $f \circ g$ injective**

- **Proof:**  
	- Suppose $(f \circ g)(x_1) = (f \circ g)(x_2)$. 
	- Then  $f(g(x_1)) = f(g(x_2))$   
	- Since (f) is injective, $g(x_1) = g(x_2)$
	- Since (g) is injective, $x_1 = x_2$.  
	- $\therefore f \circ g \text{ is injective.}$  

**4. $f$ and $g$ surjective $\implies f \circ g$ surjective**

- **Proof:**  
	- Let $c \in C$ be arbitrary. 
	- Since $f$ is surjective, there exists $b \in B$ such that $f(b) = c$.
	- Since $g$ is surjective, there exists $a \in A$ such that $g(a) = b$.
	- Substituting:  $(f \circ g)(a) = f(g(a)) = f(b) = c$
	- $\therefore f \circ g \text{ is surjective.}$ 

##### **Counterexample:  Clarifying “No Guarantee” Cases**

**1. $g$ and $f \circ g$ injective $\implies$ ❌ No guarantee about $f$**

- **Counterexample:**  
	- $A = \{1\}, \quad B = \{a, b\}, \quad C = \{X\}$ 
	- $g(1) = a \quad (\text{injective})$,
	- $f(a) = X , f(b) = X \quad (\text{not injective}$)   
	- $(f \circ g)(1) = X \quad (\text{injective})$ 

- Here, $f$ is **not injective**, but $f \circ g$ is injective.
>  Note: $f$ only needs to be injective on the **range of $g$**, not on all of $B$.

**2. $f$ and $f \circ g$ surjective $\implies$ ❌ No guarantee about $g$**

- **Counterexample:**  
	- $A = \{1\}, \quad B = \{1,2\}, \quad C = \{1\}$  
	- $g(1) = 1 \quad (\text{not surjective, since 2 is missed})$, 
	- $f(1) = 1$ , $f(2) = 1 \quad (\text{surjective})$ 
	- $(f \circ g)(1) = 1 \quad (\text{surjective onto } C)$  

- Here, $g$ is **not surjective**, but $f \circ g$ is surjective.
> Note: $f$ can map multiple elements of $B$ to the same element in $C$ as long as the image of $g$ covers $C$.

---

If you want, I can **also make a clean table of all 6 injective/surjective combinations with their guarantees**, fully formatted in LaTeX for easy study.

Do you want me to do that?

##### **Memory Rule**

> **Injectivity flows backward**  
> **Surjectivity flows forward**

- Injective ⇒ blame **earlier function (g)**
- Surjective ⇒ blame **later function (f)**


##### **Common GATE Traps ⚠️**


- Confusing injective and surjective implications
- Assuming bijection without proof
- Ignoring codomain vs image

