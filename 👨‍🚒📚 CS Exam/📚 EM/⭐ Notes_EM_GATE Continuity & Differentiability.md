
### Comprehensive Notes on , and Related Concepts

##### **1. Functions: Foundation**

A function f: A → B is a rule that assigns each element in set A (domain) exactly one element in set B (codomain).

**Key Concepts**:
- **Domain:** Set of all possible input values
- **Range:** Set of actual output values
- **Codomain:** Set of all possible output values

##### **2. Limits: The Building Block**

We say $\lim_{x \to a^{+}}f(x) = L$ if $f(x)$ gets arbitrarily close to $L$ as $x$ approaches a (from both sides).


**Types of Limits**:
- **Left-hand limit**: $\lim_{x \to a^{-}} f(x)$  approaching from left
- **Right-hand limit**: $\lim_{x \to a^{+}} f(x)$  approaching from right
- **Two-sided limit exists** if and only if both one-sided ==limits exist and are equal==

$$\lim_{x \to a^{-}} f(x) = \lim_{x \to a^{+}} f(x) = \lim_{x \to a} f(x)$$

**Important Limit Theorems**: ⭐
- $\lim_{x \to 0} (sin x)/x = 1$
- $\lim_{x \to 0} (1 - cos x)/x = 0$
- $lim_{x \to ∞} (1 + 1/x)^x = e$

**Indeterminate Forms**: $0/0$, $∞/∞$, $0×∞, $∞-∞$, $0⁰$, $1^∞$, $∞⁰$


##### **3. Continuity**

**Definition**: A function f(x) is continuous at x = a if:

1. $f(a)$ is defined
2. $\lim_{x \to a} f(x)$ exists
3. $\lim_{x \to a} f(x) = f(a)$ 

**Types of Discontinuity**:

1. **Removable Discontinuity**: Limit exists but ≠ $f(a)$ or $f(a)$ undefined
	Example: $f(x) = (x²-1)/(x-1)$ at x = 1

2. **Jump Discontinuity**: Left and right limits exist but are unequal
	Example: $f(x) = |x|/x$ at x = 0

3. **Infinite Discontinuity**: At least one one-sided limit is infinite
	Example: $f(x) = 1/x$ at x = 0

**Properties of Continuous Functions**:
- Sum, difference, product of continuous functions is continuous
- Quotient is continuous where denominator ≠ 0
- Composition of continuous functions is continuous
- All polynomial, exponential, logarithmic, trigonometric functions are continuous in their domains

==**Intermediate Value Theorem (IVT)**: ==
- If $f$ is continuous on $[a,b]$ and k is between $f(a)$ and $f(b)$, 
	then there exists c in $(a,b)$ such that $f(c) = k$.

##### **4. Differentiability**

A function $f(x)$ is differentiable at $x = a$ if:

$$f'(a) = \lim_{h→0} [f(a+h) - f(a)]/h \quad 
\text{exists}$$

This limit is called the **derivative** at x = a.

**Alternative Definition**: $f'(a) = \lim_{x→a} [f(x) - f(a)]/(x-a)$

**Geometric Interpretation**: The derivative represents the slope of the tangent line to the curve at that point.

**Relationship Between Continuity and Differentiability**:
- **If f is differentiable at a, then f is continuous at a** (differentiability ⟹ continuity)
- **The converse is NOT true**: Continuous functions may not be differentiable
- Example: f(x) = |x| is continuous at x = 0 but not differentiable there

**Non-differentiable Points**:

1. **Sharp corners/cusps**: f(x) = |x| at x = 0
2. **Vertical tangents**: f(x) = x^(1/3) at x = 0
3. **Discontinuities**: Any point of discontinuity

##### **5. Differentiation Rules**

**Basic Rules**:
- **Power rule:** 
	- $d/dx(x^n) = nx^(n-1)$

- **Constant rule:** 
	- $d/dx(c) = 0$

- **Sum rule:** 
	- $d/dx[f(x) + g(x)] = f'(x) + g'(x)$

- **Product rule:** 
	- $d/dx[f(x)g(x)] = f'(x)g(x) + f(x)g'(x)$

- **Quotient rule:** 
	- $d/dx[f(x)/g(x)] = [f'(x)g(x) - f(x)g'(x)]/[g(x)]²$

- **Chain rule:** 
	- $d/dx[f(g(x))] = f'(g(x))·g'(x)$


##### **6. Critical Points and First Derivative Test**

**Critical Point**: A point $x = c$ is critical if:

- $f'(c) = 0$, OR
- $f'(c)$ does not exist

**First Derivative Test** (for identifying local extrema): ⭐

At a critical point $x = c$ :
- If $f'(x)$ changes from ==positive to negative== at c, 
	then f has a ==**local maximum**== at c

- If $f'(x)$ changes from ==negative to positive== at c, 
	then f has a ==**local minimum**== at c

- If $f'(x)$ does ==not change sign==, 
	then c is ==neither a local max nor min== (could be an **inflection point**)

**Sign Analysis**:
- $f'(x) > 0$ on an interval 
	⟹ f is **increasing** on that interval
- $f'(x) < 0$ on an interval 
	⟹ f is **decreasing** on that interval


##### **7. Local Maxima and Minima**

**Local Maximum**: 
- f has a local maximum at $x = c$ if $f(c) ≥ f(x)$ for all x in some open interval containing c.
- If $f'(c) = 0$  and $f''(c) < 0$ then f has a **local maximum** at c

**Local Minimum**:
- f has a local minimum at $x = c$ if $f(c) ≤ f(x)$ for all x in some open interval containing c.
- If $f'(c) = 0$  and $f''(c) > 0$ then f has a **local maximum** at c

**Global (Absolute) Maximum**: 
- $f(c) ≥ f(x)$ for all x in the domain

**Global (Absolute) Minimum**: 
- $f(c) ≤ f(x)$ for all x in the domain

**Note**: 
- **==Fermat's Theorem**==: If f has a local extremum at x = c and f'(c) exists, then f'(c) = 0.
- Not every point where $f'(c) = 0$ is a local extremum (example: f(x) = x³ at x = 0)

##### **8. Second Derivative and Concavity**

**Second Derivative**: $$f''(x) = d/dx[f'(x)]$$

**Concavity**:

- $f''(x) > 0$ on an interval ⟹ f is **concave up** (curves upward like ∪)
- $f''(x) < 0$ on an interval ⟹ f is **concave down** (curves downward like ∩)

**Point of Inflection**: A point where the concavity changes (where the curve changes from concave up to concave down or vice versa). At inflection points, $f''(x) = 0$ or $f''(x) does not exist$.

**Second Derivative Test** (for local extrema):

At a critical point where f'(c) = 0: ⭐

- If $f''(c) > 0$, then f has a **local minimum** at c 
- If $f''(c) < 0$, then f has a **local maximum** at c
- If $f''(c) = 0$, the test is **inconclusive** (use first derivative test)


##### **9. Mean Value Theorem (MVT)**

==**Rolle's Theorem**: ==
- If f is continuous on $[a,b]$, differentiable on $(a,b)$, and $f(a) = f(b)$, then there exists at least one c in $(a,b)$ such that $f'(c) = 0$.

==**Mean Value Theorem**: ==
- If f is continuous on $[a,b]$ and differentiable on $(a,b)$, then there exists at least one c in $(a,b)$ such that: $f'(c) = [f(b) - f(a)]/(b-a)$

**Interpretation**: 
- There exists at least one point where the instantaneous rate of change equals the average rate of change.

**Applications**:
- Proving inequalities
- Establishing relationships between functions and their derivatives
- Showing that if f'(x) = 0 everywhere, then f is constant


##### **10. Monotonicity and Extrema**

**Monotonic Functions**:

- **Increasing**: 
	- $f'(x) ≥ 0$ for all x in the interval (strictly increasing if $f'(x) > 0$)
- **Decreasing**: 
	- $f'(x) ≤ 0$ for all x in the interval (strictly decreasing if $f'(x) < 0$)

**Finding Absolute Extrema on $[a,b]$**:
1. Find all critical points in $(a,b)$
2. Evaluate $f$ at all critical points
3. Evaluate $f$ at endpoints $a$ and $b$
4. The largest value is the absolute maximum, smallest is the absolute minimum

==**Extreme Value Theorem**: ==
- If f is continuous on a closed interval $[a,b]$, then f attains both an absolute maximum and an absolute minimum on that interval.


##### **11. L'Hôpital's Rule** ⭐

For indeterminate forms 0/0 or ∞/∞:

if $lim_{x→a} f(x)/g(x)$ gives $0/0$ or $∞/∞$, then:
	$$lim_{x→a} f(x)/g(x) = lim_{x→a} f'(x)/g'(x)$$

(provided the limit on the right exists)

Can be applied repeatedly if needed.

##### **12. Summary of Relationships**

**Sequential Flow**:

1. **Function** → 2. **Limit** → 3. **Continuity** → 4. **Differentiability** → 5. **Critical Points** → 6. **Extrema**

**Key Hierarchy**:

- Differentiable ⟹ Continuous ⟹ Limit exists
- Continuous ⏸ Differentiable (not always)
- f'(c) = 0 ⏸ Local extremum at c (not always)

**Analysis Process for Finding Extrema**:
1. Find the domain
2. Find f'(x)
3. Find critical points (f'(x) = 0 or undefined)
4. Apply first derivative test or second derivative test
5. Check endpoints if on a closed interval
6. Identify local and global extrema
