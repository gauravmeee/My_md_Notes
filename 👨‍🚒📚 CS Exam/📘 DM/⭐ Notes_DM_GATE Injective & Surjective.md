
### Composition of Functions –  (GATE Detailed Notes)



### Injective & Surjective


##### **Function**

A function $f: A \to B$ maps **each element of set A to exactly one element of set B**.

```
A         f         B
|  a  ─────────▶  b |
```

##### **Injective (One-to-One)**

```
A                     B
|                     |
|  a1  ─────────▶  b1 |
|  a2  ─────────▶  b2 |
|  a3  ─────────▶  b3 |
|                     |
```

A function $f: A \to B$  is **injective** if:  

$$f(a_1) = f(a_2) \Rightarrow a_1 = a_2  $$

-> Different inputs give different outputs.


##### **Surjective (Onto)**

```
A                     B
|                     |
|  a1  ─────────▶  b1 |
|  a2  ─────┐         |
|           └────▶ b2 |
```

A function $f: A \to B$  is **surjective** if:  
$$\forall b \in B, \exists a \in A \text{ such that } f(a) = b  $$

-> Every element of the codomain is covered.

##### **Bijective**

A function that is **both injective and surjective**.


---

### Cardinality Rules for Functions (Finite Sets): Injective / Surjective / Bijective (Made by me) ⭐

```
A         f         B (finite sets)
|  a  ─────────▶  b |
```

Let 
	$|A| = m$ 
	$|B| = n$

##### **Necessary Conditions for Injective & Surjective Functions (Size Constraints)**

**1. if f is Surjective (Onto)**  
- $|A| >= |B|$ (`m >= n`)
	**Reason**: Surjective means $f(A) = B$ 
	So number of **distinct outputs** = `n`  
	But distinct outputs ≤ number of inputs = m  
	=> `n ≤ m`

**2. if f is Injective (One-One)**  
- $|A| <= |B|$ (`m <= n`)
	**Reason:** Injective means all inputs give distinct outputs  
	So number of distinct outputs = `m`  
	But outputs are inside B which has size n  
	=> m ≤ n

**3. if f is both Injective and Surjective (Bijective)**  
- $|A| = |B|$ (`m = n`)
	**Reason:** From surjective => `m >= n`  
	and from injective => `m <= n`  
	So `m = n`

##### **Possibility Table using Sizes of Sets (`m<n`, `m>n`, `m=n`) + Pigeonhole Principle**

**1. if $|A| < |B|$ (`m < n`)**  

- **Can ==not be Surjective==.**  
	**Reason:** Surjective means every element of B must be hit. But A has only m elements, so f(A) has at most m images. If `m < n`, cannot cover all n elements of B.  
- **Can or cannot be Injective.**  
	**Reason:** Injective only needs different A elements go to different B elements. Since B is larger, it is possible. 
	(Example: `A={1,2}`, `B={a,b,c}`, `f(1)=a`, `f(2)=b` is injective)


**2. if $|A| > |B|$ (`m > n`)**

- **Can ==not be Injective.**==  
	Reason: By ==pigeonhole principle==: more elements in A than B, so at least two elements of A must map to same element of B.  
- **Can or cannot be Surjective.**  
	Reason: Surjective is possible if all elements of B are covered. 
	(Example: `A={1,2,3}`, `B={a,b}`,` f(1)=a`, `f(2)=b`, `f(3)=a` is surjective)

**3. if $|A| = |B|$ (`m = n`)**  

- **Can be Surjective.** 
	**also**, If surjective then injective otherwise not injective.  
	**Reason:** For finite sets with same size, surjective ⇒ injective. If it was not injective, two A map to same B, then some B would be missed, so not surjective.  
- **Can be Injective.** 
	**also**, If injective then surjective otherwise not surjective.  
	**Reason:** For finite sets with same size, injective ⇒ surjective. If some b in B is not hit, then only n-1 elements are hit, impossible with injective mapping of n elements.

- Key fact (only for finite sets):  
	`|A|=|B|`⇒ Injective ⇔ Surjective (and both mean Bijective).


**Note:**

> **Pigeonhole Principle**  
- If you put **more objects than boxes**, then **at least one box will contain 2 or more objects**.
- Mathematically:  If `m > n` and `m` items are distributed into `n` boxes, then some box has **≥ 2** items.
- In functions:  If `|A| > |B|` then **f cannot be injective** (two elements of A must map to same element of B).


---



---
### Composition of Functions

```
A         g       B     f         C
|  a  ─────────▶  b  ─────────▶ c |
```

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



##### **Composition of Functions (`f ∘ g`) : Injective / Surjective Implications** (Made by me ⭐)

```
g       f
A ───▶ B ───▶ C
```


**1. `f ∘ g` -> injective**

- if `f ∘ g` is injective then `g` must be injective.  
    **Reason:** If `g:A->B` is not injective, then multiple elements of A can point to the same element of B.  
    Then applying `f` on that same B gives same output in C.  
    So two different elements of A will map to same element in C, hence `A->C` will not be injective.  
    So `g` must be injective.
- Injective ⇒ blame **earlier function (g)**

**2. `f ∘ g` -> surjective**

- if `f ∘ g` is surjective then `f` must be surjective.  
    **Reason:** If `f:B->C` is not surjective, then some elements of C are not covered by f.  
    Then no matter what g does (A->B), those missing elements of C can never be reached.  
    So `A->C` also cannot be surjective.  
    Hence `f` must be surjective.
- Surjective ⇒ blame **later function (f)**

**Note:** ⭐
> **Injectivity flows backward**  
> **Surjectivity flows forward**


##### **Common GATE Traps ⚠️**

- Confusing injective and surjective implications
- Assuming bijection without proof
- Ignoring codomain vs image

