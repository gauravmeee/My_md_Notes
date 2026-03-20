
### Basics
##### **1. Introduction to Matrices**

**Definition**: A matrix is a rectangular array of numbers, symbols, or expressions arranged in rows and columns.

**General Form**:

$$A = \begin{bmatrix} a_{11} & a_{12} & a_{13} & \cdots & a_{1n} \\ a_{21} & a_{22} & a_{23} & \cdots & a_{2n} \\ a_{31} & a_{32} & a_{33} & \cdots & a_{3n} \\ \vdots & \vdots & \vdots & \ddots & \vdots \\ a_{m1} & a_{m2} & a_{m3} & \cdots & a_{mn} \end{bmatrix}$$

**Notation**:

- Matrix $A$ of order $m \times n$ (m rows, n columns)
- Element in $i^{th}$ row and $j^{th}$ column: $a_{ij}$
- $A = [a_{ij}]_{m \times n}$

**Order/Dimension**: $m \times n$ where $m$ = number of rows, $n$ = number of columns


##### **2. Types of Matrices**

**Based on Order:**

- **a) Row Matrix**: Matrix with only one row ($1 \times n$)

$$A = \begin{bmatrix} 2 & 5 & 7 & 9 \end{bmatrix}$$

- **b) Column Matrix**: Matrix with only one column ($m \times 1$)

$$B = \begin{bmatrix} 3 \\ 7 \\ 2 \end{bmatrix}$$

- **c) Square Matrix**: Matrix where $m = n$ (equal rows and columns)

$$C = \begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix} \quad (2 \times 2 \text{ square matrix})$$

- **d) Rectangular Matrix**: Matrix where $m \neq n$

**Based on Elements:**

- **e) Zero/Null Matrix**: All elements are zero. Notation: $O$ or $0$

$$O = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$$

- **f) Diagonal Matrix**: Square matrix where all non-diagonal elements are zero $(a_{ij} = 0 \text{ for } i \neq j)$

$$D = \begin{bmatrix} 5 & 0 & 0 \\ 0 & 3 & 0 \\ 0 & 0 & 7 \end{bmatrix}$$

- **g) Scalar Matrix**: Diagonal matrix where all diagonal elements are equal

$$S = \begin{bmatrix} 4 & 0 & 0 \\ 0 & 4 & 0 \\ 0 & 0 & 4 \end{bmatrix}$$

- **h) Identity/Unit Matrix**: Diagonal matrix where all diagonal elements are 1. Notation: $I$ or $I_n$

$$I_3 = \begin{bmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

- **i) Upper Triangular Matrix**: Square matrix where all elements below the diagonal are zero $(a_{ij} = 0 \text{ for } i > j)$

$$U = \begin{bmatrix} 2 & 5 & 7 \\ 0 & 3 & 8 \\ 0 & 0 & 4 \end{bmatrix}$$

- **j) Lower Triangular Matrix**: Square matrix where all elements above the diagonal are zero $(a_{ij} = 0 \text{ for } i < j)$

$$L = \begin{bmatrix} 2 & 0 & 0 \\ 5 & 3 & 0 \\ 7 & 8 & 4 \end{bmatrix}$$

##### **3. Matrix Operations**

**A. Equality of Matrices**

- Two matrices $A$ and $B$ are equal if:
	1. They have the same order
	2. Corresponding elements are equal: $a_{ij} = b_{ij}$ for all $i, j$

**B. Addition and Subtraction**

- **Conditions**: Matrices must have the same order
- **Addition**: $A + B = [a_{ij} + b_{ij}]$
- **Subtraction**: $A - B = [a_{ij} - b_{ij}]$
- **Properties**:
	- Commutative: $A + B = B + A$
	- Associative: $(A + B) + C = A + (B + C)$
	- Additive Identity: $A + O = A$
	- Additive Inverse: $A + (-A) = O$

- **Example**:

$$\begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix} + \begin{bmatrix} 5 & 6 \\ 7 & 8 \end{bmatrix} = \begin{bmatrix} 6 & 8 \\ 10 & 12 \end{bmatrix}$$

**C. Scalar Multiplication**

- **Definition**: Multiplying every element by a scalar $k$

$$kA = [k \cdot a_{ij}]$$

- **Properties**:
	- $k(A + B) = kA + kB$
	- $(k + m)A = kA + mA$
	- $(km)A = k(mA)$
	- $1 \cdot A = A$
	- $0 \cdot A = O$

- **Example**:

$$3\begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix} = \begin{bmatrix} 3 & 6 \\ 9 & 12 \end{bmatrix}$$

**D. Matrix Multiplication**

- **Condition**: Number of columns in first matrix = number of rows in second matrix
- If $A$ is $m \times n$ and $B$ is $n \times p$, then $AB$ is $m \times p$
- **Formula**:

$$(AB)_{ij} = \sum_{k=1}^{n} a_{ik} \cdot b_{kj}$$

- **Properties**:
	- Generally NOT commutative: $AB \neq BA$
	- Associative: $(AB)C = A(BC)$
	- Distributive: $A(B + C) = AB + AC$
	- Identity: $AI = IA = A$
	- $(AB)^T = B^T A^T$

- **Example**:

$$\begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix} \begin{bmatrix} 5 & 6 \\ 7 & 8 \end{bmatrix} = \begin{bmatrix} 1 \times 5 + 2 \times 7 & 1 \times 6 + 2 \times 8 \\ 3 \times 5 + 4 \times 7 & 3 \times 6 + 4 \times 8 \end{bmatrix} = \begin{bmatrix} 19 & 22 \\ 43 & 50 \end{bmatrix}$$


##### **4. Transpose of a Matrix**

- **Definition**: Matrix obtained by interchanging rows and columns

- If $A = [a_{ij}]_{m \times n}$, then $A^T = [a_{ji}]_{n \times m}$

- **Properties**:
	- $(A^T)^T = A$
	- $(A + B)^T = A^T + B^T$
	- $(kA)^T = kA^T$
	- $(AB)^T = B^T A^T$

- **Example**:

$$A = \begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \end{bmatrix} \quad \Rightarrow \quad A^T = \begin{bmatrix} 1 & 4 \\ 2 & 5 \\ 3 & 6 \end{bmatrix}$$

**Special Matrices Related to Transpose:**

- **a) Symmetric Matrix**: A square matrix where $A = A^T$ (i.e., $a_{ij} = a_{ji}$)

$$S = \begin{bmatrix} 1 & 2 & 3 \\ 2 & 5 & 6 \\ 3 & 6 & 9 \end{bmatrix}$$

- **b) Skew-Symmetric Matrix**: A square matrix where $A = -A^T$ (i.e., $a_{ij} = -a_{ji}$)

	- All diagonal elements must be zero.

$$K = \begin{bmatrix} 0 & 2 & -3 \\ -2 & 0 & 4 \\ 3 & -4 & 0 \end{bmatrix}$$


- **Important Property**: Any square matrix can be expressed as the sum of a symmetric and skew-symmetric matrix:

$$\boxed{A = \frac{1}{2}(A + A^T) + \frac{1}{2}(A - A^T)}$$

- **Symmetric part:** $\boxed{\frac{1}{2}(A + A^T)}$
- **Skew-symmetric part**: $\boxed{\frac{1}{2}(A - A^T)}$

##### **5 Minor & Cofactor **

**a) Minor of an element**

- **Definition**: The **minor** of an element $a_{ij}$ in a matrix $A$, denoted by $M_{ij}$, is the determinant of the submatrix obtained by deleting the $i$-th row and $j$-th column from $A$.

- **Notation**: $M_{ij}$ or $|M_{ij}|$

- **For a 2×2 Matrix**: $A = \begin{bmatrix} a & b \ c & d \end{bmatrix}$
	$M_{11}$ = determinant after removing 1st row and 1st column = $d$
	$M_{12}$ = determinant after removing 1st row and 2nd column = $c$
	$M_{21}$ = determinant after removing 2nd row and 1st column = $b$
	$M_{22}$ = determinant after removing 2nd row and 2nd column = $a$

- **For a 3×3 Matrix**: $A = \begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{bmatrix}$

	$M_{11} = \begin{vmatrix} a_{22} & a_{23} \\ a_{32} & a_{33} \end{vmatrix} = a_{22}a_{33} - a_{23}a_{32}$

	$M_{12} = \begin{vmatrix} a_{21} & a_{23} \\ a_{31} & a_{33} \end{vmatrix} = a_{21}a_{33} - a_{23}a_{31}$

	$M_{13} = \begin{vmatrix} a_{21} & a_{22} \\ a_{31} & a_{32} \end{vmatrix} = a_{21}a_{32} - a_{22}a_{31}$

**b) Cofactor of an Element**

- **Definition**: The **cofactor** of an element $a_{ij}$, denoted by $C_{ij}$ or $A_{ij}$, is given by:

$$\boxed{C_{ij} = (-1)^{i+j} \cdot M_{ij}}$$

- where $M_{ij}$ is the minor of element $a_{ij}$.

- **Sign Pattern**: The factor $(-1)^{i+j}$ creates a checkerboard pattern of signs:

**For any matrix**: $$\begin{bmatrix}

+ & - & + & - & \cdots \\

- & + & - & + & \cdots \\

+ & - & + & - & \cdots \\

- & + & - & + & \cdots \\ \vdots & \vdots & \vdots & \vdots & \ddots \end{bmatrix}$$

**For 2×2 Matrix**: $$\begin{bmatrix} + & - \\ - & + \end{bmatrix}$$

**For 3×3 Matrix**: $$\begin{bmatrix} + & - & + \\ - & + & - \\ + & - & + \end{bmatrix}$$
**Properties of Minors and Cofactors**

- **Property 1**: The minor $M_{ij}$ is always a determinant value (scalar).
- **Property 2**: The cofactor $C_{ij}$ differs from minor $M_{ij}$ only by sign $(-1)^{i+j}$.
- **Property 3**: When $i + j$ is even, $C_{ij} = M_{ij}$ (positive sign)
- **Property 4**: When $i + j$ is odd, $C_{ij} = -M_{ij}$ (negative sign)
- **Property 5**: For a diagonal matrix, all cofactors on the diagonal are products of the other diagonal elements.

##### **8. Adjoint of a Matrix**

- **Definition**: **Transpose of the cofactor matrix**

- **Steps to Find Adjoint**:
	1. Find the cofactor matrix $C = [C_{ij}]$
	2. Take transpose: $\text{adj}(A) = C^T$

- **Properties**:
	- $A \cdot \text{adj}(A) = \text{adj}(A) \cdot A = \det(A) \cdot I$
	- $\text{adj}(A^T) = (\text{adj }A)^T$
	- $\text{adj}(AB) = \text{adj}(B) \cdot \text{adj}(A)$
	- $\text{adj}(kA) = k^{n-1} \text{adj}(A)$ for $n \times n$ matrix
	- $\det(\text{adj }A) = [\det(A)]^{n-1}$ for $n \times n$ matrix

- **Example for 2×2 Matrix**:

	$\text{If } A = \begin{bmatrix} a & b \\ c & d \end{bmatrix}$

	then  $$\boxed{\text{adj}(A) = \begin{bmatrix} d & -b \\ -c & a \end{bmatrix}}$$



##### **7. Determinant of a Matrix**

- **Definition**: A scalar value that can be computed from a square matrix

- **Notation**: $\det(A)$ or $|A|$

1. **For 2×2 Matrix:**

$$\begin{vmatrix} a & b \\ c & d \end{vmatrix} = ad - bc$$

2. **For 3×3 Matrix:**

$$\begin{vmatrix} a & b & c \\ d & e & f \\ g & h & i \end{vmatrix} = a(ei - fh) - b(di - fg) + c(dh - eg)$$

- **Expansion by Cofactors**:

$$\det(A) = \sum_{j=1}^{n} a_{ij} C_{ij} \quad \text{(along any row or column)}$$

- where $C_{ij} = (-1)^{i+j} M_{ij}$ (cofactor)
- and $M_{ij}$ = minor (determinant of submatrix after removing $i^{th}$ row and $j^{th}$ column)

- **Properties of Determinants**:
	- $\det(I) = 1$
	- $\det(O) = 0$
	- $\det(A^T) = \det(A)$
	- $\det(kA) = k^n \det(A)$ for $n \times n$ matrix
	- $\det(AB) = \det(A) \cdot \det(B)$
	- If two rows/columns are identical, $\det(A) = 0$
	- If we interchange two rows/columns, determinant changes sign
	- Multiplying a row/column by $k$ multiplies determinant by $k$
	- Adding a multiple of one row to another doesn't change determinant

- **Singular Matrix**: $\det(A) = 0$
- **Non-singular Matrix**: $\det(A) \neq 0$

##### **7. Inverse of a Matrix**

- **Definition**: $A^{-1}$ is the inverse of $A$ if $A \cdot A^{-1} = A^{-1} \cdot A = I$

- **Formula**:

$$\boxed{A^{-1} = \frac{1}{\det(A)} \cdot \text{adj}(A)}$$

- **Conditions for Inverse to Exist**:
	- Matrix must be square
	- $\det(A) \neq 0$ (non-singular)

- **Properties**:
	- $(A^{-1})^{-1} = A$
	- $(AB)^{-1} = B^{-1} A^{-1}$
	- $(A^T)^{-1} = (A^{-1})^T$
	- $\det(A^{-1}) = \frac{1}{\det(A)}$
	- $(kA)^{-1} = \frac{1}{k} A^{-1}$

- **Example**:

$$A = \begin{bmatrix} 2 & 3 \\ 1 & 4 \end{bmatrix}$$

$$\det(A) = 2 \times 4 - 3 \times 1 = 8 - 3 = 5$$

$$\text{adj}(A) = \begin{bmatrix} 4 & -3 \ -1 & 2 \end{bmatrix}$$

$$A^{-1} = \frac{1}{5}\begin{bmatrix} 4 & -3 \\ -1 & 2 \end{bmatrix} = \begin{bmatrix} 4/5 & -3/5 \\ -1/5 & 2/5 \end{bmatrix}$$


##### **8. Elementary Row Operations**

Used to solve systems of equations and find inverse:
1. **Row Interchange**: $R_i \leftrightarrow R_j$ (swap two rows)
2. **Row Scaling**: $R_i \to kR_i$ (multiply a row by non-zero scalar)
3. **Row Addition**: $R_i \to R_i + kR_j$ (add multiple of one row to another)

**Elementary Matrices**: Matrices obtained by performing one elementary operation on the identity matrix

##### **9. Rank of a Matrix** 

- **Definition**: The rank of a matrix is the **==maximum number of linearly independent rows==** (or columns)

- **Methods to Find Rank**:
	1. ==Convert to row **echelon** form== using elementary row operations
	2. Count the ==number of **non-zero** rows====

- **Properties**:
	- $\text{rank}(A) \leq \min(m, n)$ for $m \times n$ matrix
	- $\text{rank}(A) = \text{rank}(A^T)$
	- $\text{rank}(AB) \leq \min(\text{rank}(A), \text{rank}(B))$
	- If $A$ is invertible $n \times n$ matrix, $\text{rank}(A) = n$ (full rank)

- Row **Echelon** Form: ⭐
	- All non-zero rows are above zero rows
	- Leading entry of each non-zero row is to the right of the leading entry of the row above

- **Reduced Row Echelon Form**:
	- Row echelon form
	- Leading entry in each non-zero row is 1
	- All entries above and below each leading 1 are zero

##### **10. System of Linear Equations**  (❌ Not all important for GATE)

- **General Form**:

$$\begin{cases} a_{11}x_1 + a_{12}x_2 + \cdots + a_{1n}x_n = b_1 \\ a_{21}x_1 + a_{22}x_2 + \cdots + a_{2n}x_n = b_2 \\ \vdots \\ a_{m1}x_1 + a_{m2}x_2 + \cdots + a_{mn}x_n = b_m \end{cases}$$

- **Matrix Form**: $\boxed{AX = B}$
- where $A$ is coefficient matrix, $X$ is variable matrix, $B$ is constant matrix


**Methods of Solution**

- **a) Matrix Inversion Method** (when $A$ is square and non-singular): ⭐

$$\boxed{X = A^{-1}B}$$

- **b) Cramer's Rule** (for square systems with $\det(A) \neq 0$):

$$x_i = \frac{\det(A_i)}{\det(A)}$$
	- where $A_i$ is $A$ with $i$-th column replaced by $B$

- **c) Gaussian Elimination**:
	- Convert augmented matrix $[A|B]$ to row **echelon** form
	- Use back substitution

- **d) Gauss-Jordan Elimination**:
	- Convert to reduced row **echelon** form
	- Read off solutions directly

**Consistency of System:**  ( ⭐GATE 2025 )

- **Augmented Matrix**: $[A|B]$
- Using rank:
	- **Consistent** (has solution): $\text{rank}(A) = \text{rank}([A|B])$
	    1. Unique solution: $\text{rank}(A) = \text{rank}([A|B]) = n$ (number of variables)
	    2. Infinite solutions: $\text{rank}(A) = \text{rank}([A|B]) < n$
	- **Inconsistent** (no solution): $\text{rank}(A) < \text{rank}([A|B])$

##### **11. Special Products and Matrices** ( ❌Not important for GATE)

**a) Idempotent Matrix**: $A^2 = A$
- Example: Identity matrix

**b) Nilpotent Matrix**: $A^k = O$ for some positive integer $k$
- Smallest such $k$ is called index of nilpotency

**c) Involutory Matrix**: $A^2 = I$
- $A$ is its own inverse: $A^{-1} = A$

**d) Orthogonal Matrix**: $AA^T = A^T A = I$
- $A^{-1} = A^T$
- $\det(A) = \pm 1$
- Columns (and rows) form orthonormal sets

**e) Hermitian Matrix** (for complex matrices): $A = \bar{A}^T$ (conjugate transpose)

**f) Unitary Matrix**: $A\bar{A}^T = I$


##### **12. Trace of a Matrix** 

**Definition**: Sum of diagonal elements of a square matrix

$$\boxed{\text{tr}(A) = \sum_{i=1}^{n} a_{ii}}$$

==**Trace–Eigenvalue Relation**==: (⭐GATE 2023)

- **==Summation of the eigenvalue== is equal to the ==trace of the matrix==**
    $$\boxed{\text{tr}(A)=\sum_{i=1}^{n}\lambda_i}$$
 

- Holds for **any square matrix** (diagonalizable or not)
- Follows from characteristic polynomial
- Works over real or complex field
- Frequently used to find unknown eigenvalues using trace shortcut

**Properties**:

- $\text{tr}(A + B) = \text{tr}(A) + \text{tr}(B)$
- $\text{tr}(kA) = k \cdot \text{tr}(A)$
- $\text{tr}(AB) = \text{tr}(BA)$
- $\text{tr}(A^T) = \text{tr}(A)$
- $\text{tr}(ABC) = \text{tr}(CAB) = \text{tr}(BCA)$ (cyclic property)



##### **13. Applications of Matrices** ( ❌Not important for GATE)

1. **Solving Linear Equations**: Systems of equations in science, engineering, economics
2. **Computer Graphics**: Transformations (rotation, scaling, translation)
3. **Cryptography**: Encoding and decoding messages
4. **Economics**: Input-output models, Leontief models
5. **Network Analysis**: Graph theory, connectivity
6. **Quantum Mechanics**: State vectors, operators
7. **Statistics**: Correlation matrices, covariance matrices
8. **Machine Learning**: Data representation, neural networks


##### **14. Summary of Key Formulas** ⭐⭐

**Determinant (2×2)**:

$$\boxed{ |A| = \begin{vmatrix} a & b \\ c & d \end{vmatrix} = ad - bc}$$

**Inverse**:

$$\boxed{A^{-1} = \frac{1}{|A|} \cdot \text{adj}(A)}$$

**Adjoint (2×2)**:

$$\boxed{\text{adj}\begin{bmatrix} a & b \\ c & d \end{bmatrix} = \begin{bmatrix} d & -b \\ -c & a \end{bmatrix}}$$

**Product Rules**:

$$\boxed{(AB)^T = B^T A^T}$$

$$\boxed{(AB)^{-1} = B^{-1} A^{-1}}$$

**Rank Property**:

$$\boxed{\text{rank}(A) = \text{rank}(A^T)}$$

**Solution of $AX = B$**:

$$\boxed{X = A^{-1}B \quad \text{(when } A \text{ is invertible)}}$$

---

## Eigenvalues & Eigenvectors


##### **1. Eigenvalues and Eigenvectors** ⭐


**Eigenvector**: A non-zero vector $\vec{v}$ is called an eigenvector of a square matrix $A$ if there exists a scalar $\lambda$ such that:

$$\boxed{A\vec{v} = \lambda\vec{v}}$$

**Eigenvalue**: The scalar $\lambda$ is called the eigenvalue corresponding to the eigenvector $\vec{v}$.

- $\vec{v}$: Eigen Vector
- $\lambda$: Eigen Value

**Geometric Interpretation**: When matrix $A$ acts on eigenvector $\vec{v}$, the result is a vector in the same direction (or opposite direction) as $\vec{v}$, scaled by factor $\lambda$.


##### **2. Characteristic Equation** ⭐

- To find eigenvalues, we solve:

$$A\vec{v} = \lambda\vec{v}$$
$$A\vec{v} - \lambda\vec{v} = \vec{0}$$
$$(A - \lambda I)\vec{v} = \vec{0}$$

- **For non-trivial solution** (where $\vec{v} \neq \vec{0}$):

$$\boxed{\det(A - \lambda I) = 0}$$

- This is called the **Characteristic Equation** of matrix $A$.

- **Characteristic Polynomial**: 
$$\boxed{p(\lambda) = \det(A - \lambda I)}$$


##### **3. Finding Eigenvalues and Eigenvectors** ⭐⭐⭐

**Step-by-Step Process**:

1. **Step 1**: Find eigenvalues by solving $\det(A - \lambda I) = 0$
2. **Step 2**: For each eigenvalue $\lambda_i$, find eigenvectors by solving $(A - \lambda_i I)\vec{v} = \vec{0}$


**Example**: Find eigenvalues and eigenvectors of $A = \begin{bmatrix} 4 & 2 \\ 1 & 3 \end{bmatrix}$

**Solution**:

1. Step 1: Find eigenvalues

	$A - \lambda I = \begin{bmatrix} 4-\lambda & 2 \\ 1 & 3-\lambda \end{bmatrix}$

	$\det(A - \lambda I) = (4-\lambda)(3-\lambda) - 2 = \lambda^2 - 7\lambda + 10 = 0$

	$(\lambda - 5)(\lambda - 2) = 0 \quad$, Eigenvalues: $\lambda_1 = 5, \lambda_2 = 2$

2. Step 2: Find eigenvectors

	- For $\lambda_1 = 5$:
		$(A - 5I)\vec{v} = \begin{bmatrix} -1 & 2 \\ 1 & -2 \end{bmatrix} \begin{bmatrix} v_1 \\ v_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} \quad$, Solution:  $\vec{v}_1 = \begin{bmatrix} 2 \\ 1 \end{bmatrix}$ (or any scalar multiple)

	- For $\lambda_2 = 2$:
		$(A - 2I)\vec{v} = \begin{bmatrix} 2 & 2 \ 1 & 1 \end{bmatrix}\begin{bmatrix} v_1 \ v_2 \end{bmatrix} = \begin{bmatrix} 0 \ 0 \end{bmatrix} \quad$, Solution: $\vec{v}_2 = \begin{bmatrix} 1 \ -1 \end{bmatrix}$ (or any scalar multiple)


##### **4. Properties of Eigenvalues** ⭐

1. **Property 1**: Sum of eigenvalues = Trace of matrix

$$\sum_{i=1}^{n} \lambda_i = \text{tr}(A) = \sum_{i=1}^{n} a_{ii}$$

2. **Property 2**: Product of eigenvalues = Determinant of matrix

$$\prod_{i=1}^{n} \lambda_i = \det(A)$$

3. **Property 3**: If $\lambda$ is an eigenvalue of $A$, then:

- $\lambda^k$ ==is an eigenvalue of== $A^k$ (⭐GATE 2023)
- $\lambda + c$ ==is an eigenvalue of== $A + cI$
- $k\lambda$ ==is an eigenvalue== of $kA$
- $\frac{1}{\lambda}$ is an eigenvalue of $A^{-1}$ (if $A$ is invertible and $\lambda \neq 0$)
3. **Property 4**: ==Eigenvalues of $A$ and $A^T$ are the same==

4. **Property 5**: For triangular (upper or lower) and diagonal matrices, eigenvalues are the diagonal elements

5. **Property 6**: If $A$ is singular, then $\lambda = 0$ is an eigenvalue

6. **Property 7**: Eigenvalues of a real symmetric matrix are always real

7. **Property 8**: Eigenvalues of an orthogonal matrix have absolute value 1

8. **Property 9**: Eigenvalues of a Hermitian matrix are real

9. **Property 10**: Eigenvalues of a skew-Hermitian matrix are purely imaginary or zero


##### **5. Properties of Eigenvectors**

1. **Property 1**: Eigenvectors ==corresponding to distinct eigenvalues== are **linearly independent**

2. **Property 2**: If $\vec{v}$ is an eigenvector, then $k\vec{v}$ (for any non-zero scalar $k$) is also an eigenvector with the same eigenvalue

3. **Property 3**: For a real symmetric matrix, eigenvectors corresponding to distinct eigenvalues are orthogonal

4. **Property 4**: The eigenvectors corresponding to an eigenvalue with algebraic multiplicity $m$ span a subspace of dimension $\leq m$

##### **6. Algebraic and Geometric Multiplicity** ( ❌Not important for GATE)

**Algebraic Multiplicity**: The number of times an eigenvalue appears as a root of the characteristic polynomial

**Geometric Multiplicity**: The dimension of the eigenspace (number of linearly independent eigenvectors) corresponding to an eigenvalue

$$\text{Geometric Multiplicity} \leq \text{Algebraic Multiplicity}$$

**Example**:

$$A = \begin{bmatrix} 5 & 0 & 0 \\ 0 & 5 & 0 \\ 0 & 0 & 3 \end{bmatrix}$$

- **Characteristic equation:** $(5-\lambda)^2(3-\lambda) = 0$
- **Eigenvalues:** $\lambda_1 = 5$ (algebraic multiplicity 2), $\lambda_2 = 3$ (algebraic multiplicity 1)
- For $\lambda_1 = 5$: geometric multiplicity = 2 (two independent eigenvectors)


##### **7. Diagonalization** 

A matrix $A$ is ==**diagonalizable** if there exists== an **==invertible matrix==** $P$ such that:

$$\boxed{P^{-1}AP = D}$$

where $D$ is a diagonal matrix containing eigenvalues of $A$, and columns of $P$ are the corresponding eigenvectors.

$$D = \begin{bmatrix} \lambda_1 & 0 & \cdots & 0 \\ 0 & \lambda_2 & \cdots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ 0 & 0 & \cdots & \lambda_n \end{bmatrix}$$

**Condition for Diagonalization**: An $n \times n$ matrix is diagonalizable if and only if it has $n$ linearly independent eigenvectors.

**Guaranteed Diagonalizable**:
- Matrices with $n$ distinct eigenvalues
- Real symmetric matrices
- Hermitian matrices
- Orthogonal matrices
- Unitary matrices

**Applications of Diagonalization**:
1. **Computing Powers**: $A^k = PD^kP^{-1}$
2. **Matrix Functions**: $f(A) = Pf(D)P^{-1}$
3. **Solving Differential Equations**

##### **8. Similarity of Matrices** ( ❌Not important for GATE)

==Two matrices== $A$ and $B$ ==are **similar**== if ==there exists an invertible matrix== $P$ such that:

$$\boxed{B = P^{-1}AP}$$

**Properties of Similar Matrices**:
- Same eigenvalues
- Same determinant
- Same trace
- Same rank
- Same characteristic polynomial


##### **9. ==Cayley-Hamilton== Theorem** ( ❌Not important for GATE)

**Theorem**: Every square matrix satisfies its own characteristic equation.

If $p(\lambda) = \det(A - \lambda I)$ is the characteristic polynomial, then:

$$p(A) = O$$

**Example**: If $A = \begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}$

- Characteristic equation: $\lambda^2 - 5\lambda - 2 = 0$

- Then: $A^2 - 5A - 2I = O$

- **Applications**:
	- Finding matrix inverse
	- Computing higher powers of matrices
	- Simplifying matrix polynomials

**Finding Inverse using Cayley-Hamilton**:

- If characteristic equation is $\lambda^n + c_{n-1}\lambda^{n-1} + \cdots + c_1\lambda + c_0 = 0$

- Then: $A^n + c_{n-1}A^{n-1} + \cdots + c_1A + c_0I = O$

- If $c_0 \neq 0$ (i.e., $\det(A) \neq 0$):

$$A^{-1} = -\frac{1}{c_0}(A^{n-1} + c_{n-1}A^{n-2} + \cdots + c_1I)$$

##### **10. Special Eigenvalue Problems** ( ❌Not important for GATE)

**Symmetric Matrices**:

- All eigenvalues are real
- Eigenvectors corresponding to distinct eigenvalues are orthogonal
- Always diagonalizable

**Orthogonal Matrices** ($A^TA = I$):

- All eigenvalues have absolute value 1
- $|\lambda| = 1$ or $\lambda = e^{i\theta}$

**Positive Definite Matrices**:

- All eigenvalues are positive
- All leading principal minors are positive

**Idempotent Matrices** ($A^2 = A$):

- Eigenvalues are either 0 or 1

**Nilpotent Matrices** ($A^k = O$):

- All eigenvalues are 0

**Involutory Matrices** ($A^2 = I$):

- Eigenvalues are either 1 or -1

##### **11. Power Method (Finding Dominant Eigenvalue)** ( ❌Not important for GATE)

The **power method** is an iterative technique to find the largest (dominant) eigenvalue and its corresponding eigenvector.

- **Algorithm**:
	1. Start with initial guess $\vec{x}_0$ (non-zero)
	2. Iterate: $\vec{x}_{k+1} = \frac{A\vec{x}_k}{|A\vec{x}_k|}$
	3. Eigenvalue: $\lambda \approx \frac{\vec{x}_k^T A \vec{x}_k}{\vec{x}_k^T \vec{x}_k}$

- **Converges to**: Dominant eigenvalue (eigenvalue with largest absolute value)

---

## System of Linear Equations (Advanced Concepts)


###### **1. Matrix Representation**

**System of equations**:

$$\begin{cases} a_{11}x_1 + a_{12}x_2 + \cdots + a_{1n}x_n = b_1 \\ a_{21}x_1 + a_{22}x_2 + \cdots + a_{2n}x_n = b_2 \\ \vdots \\ a_{m1}x_1 + a_{m2}x_2 + \cdots + a_{mn}x_n = b_m \end{cases}$$

**Matrix form**: $AX = B$

where:

$$A = \begin{bmatrix} a_{11} & a_{12} & \cdots & a_{1n} \\ a_{21} & a_{22} & \cdots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} & a_{m2} & \cdots & a_{mn} \end{bmatrix}, \quad X = \begin{bmatrix} x_1 \\ x_2 \\ \vdots \\ x_n \end{bmatrix}, \quad B = \begin{bmatrix} b_1 \\ b_2 \\ \vdots \\ b_m \end{bmatrix}$$

==**Augmented Matrix**==: $[A | B]$ ⭐⭐



##### **2. Types of Linear Systems**

1. **Homogeneous System**: $AX = 0$ (where $B = 0$) ⭐
	- Always ==has at least the trivial solution== $X = 0$
	- Non-trivial solutions exist if and only if $\det(A) = 0$ (for square matrices) ⭐

2. **Non-homogeneous System**: $AX = B$ (where $B \neq 0$)


##### **3. Consistency and Solution Types** ⭐⭐

**For Square Systems** ($m = n$):

| Determinant Condition                                    | Determinant | Solution Type                  |
| -------------------------------------------------------- | ----------- | ------------------------------ |
| $\det(A) \neq 0$                                         | Non-zero    | Unique solution: $X = A^{-1}B$ |
| $\det(A) = 0$ and $\text{rank}(A) = \text{rank}([A\|B])$ | Zero        | Infinite solutions             |
| $\det(A) = 0$ and $\text{rank}(A) < \text{rank}([A\|B])$ | Zero        | No solution (inconsistent)     |

**For General Systems** ($m \times n$):

Let $r = \text{rank}(A)$ and $r' = \text{rank}([A|B])$

|Rank Condition|Solution Type|
|---|---|
|$r < r'$|Inconsistent (no solution)|
|$r = r' = n$|Unique solution|
|$r = r' < n$|Infinite solutions (with $n - r$ free parameters)|

##### **4. ==Rouché-Capelli== Theorem** ( ❌Not important for GATE)

A system $AX = B$ is **consistent** if and only if:

$$\boxed{\text{rank}(A) = \text{rank}([A|B])}$$

Number of free variables = $n - \text{rank}(A)$


##### **5. Homogeneous Systems**

**System**: $AX = 0$

**Properties**:

- Always has trivial solution $X = 0$
- Has non-trivial solution if and only if $\det(A) = 0$ (for square $A$)
- For $m \times n$ system with $m < n$: always has infinite solutions
- Solution space forms a **vector space** (null space or kernel of $A$)

**Dimension of solution space**: $n - \text{rank}(A)$ (called **nullity** of $A$)

**==Rank-Nullity== Theorem**: For $m \times n$ matrix $A$:

$$\text{rank}(A) + \text{nullity}(A) = n$$


##### **6. Solution Methods** ( ❌ Not all important for GATE)

**A. ==Cramer's== Rule**

- For square system with $\det(A) \neq 0$:

$$x_i = \frac{\det(A_i)}{\det(A)}$$

- where $A_i$ is the matrix obtained by replacing the $i$-th column of $A$ with $B$.

- **Example**: Solve $\begin{cases} 2x + 3y = 8 \ x + 4y = 9 \end{cases}$

	$A = \begin{bmatrix} 2 & 3 \ 1 & 4 \end{bmatrix}, \quad B = \begin{bmatrix} 8 \ 9 \end{bmatrix}$

	$\det(A) = 8 - 3 = 5$

	$A_1 = \begin{bmatrix} 8 & 3 \ 9 & 4 \end{bmatrix}, \quad \det(A_1) = 32 - 27 = 5$

	$x = \frac{5}{5} = 1$

	$A_2 = \begin{bmatrix} 2 & 8 \ 1 & 9 \end{bmatrix}, \quad \det(A_2) = 18 - 8 = 10$
	
	$y = \frac{10}{5} = 2$

- **Limitation**: Computationally expensive for large systems


**B. Matrix Inversion Method** ⭐

- For square system with $\det(A) \neq 0$:

$$ \boxed{X = A^{-1}B}$$

- **Steps**:
	1. Find $A^{-1}$ using $A^{-1} = \frac{1}{\det(A)} \text{adj}(A)$
	2. Compute $X = A^{-1}B$


**C. Gaussian Elimination**

- **Process**:
	1. Form augmented matrix $[A|B]$
	2. Use elementary row operations to convert to **row echelon form**
	3. Use **back substitution** to find solutions

- **Elementary Row Operations**:
	- $R_i \leftrightarrow R_j$ (interchange rows)
	- $R_i \to kR_i$ (multiply row by non-zero constant)
	- $R_i \to R_i + kR_j$ (add multiple of one row to another)

- **Row Echelon Form**:
	- All zero rows are at the bottom
	- Leading coefficient (pivot) of each non-zero row is to the right of the pivot above it

- **Example**: $\begin{cases} x + 2y + z = 9 \ 2x - y + 3z = 8 \ 3x + y + 2z = 13 \end{cases}$

	Augmented matrix: $\left[\begin{array}{ccc|c} 1 & 2 & 1 & 9 \\ 2 & -1 & 3 & 8 \\ 3 & 1 & 2 & 13 \end{array}\right]$

	After row operations: $\left[\begin{array}{ccc|c} 1 & 2 & 1 & 9 \\ 0 & -5 & 1 & -10 \\ 0 & 0 & -2 & -4 \end{array}\right]$

	Back substitution: $z = 2, y = 2, x = 1$


**D. Gauss-Jordan Elimination**

- **Process**:
	1. Form augmented matrix $[A|B]$
	2. Convert to **reduced row echelon form** (RREF)
	3. Read solutions directly

- **Reduced Row Echelon Form**:
	- Row echelon form
	- Leading coefficient (pivot) in each row is 1
	- Each pivot is the only non-zero entry in its column

- **Example**: Same system as above

	After Gauss-Jordan: $\left[\begin{array}{ccc|c} 1 & 0 & 0 & 1 \\ 0 & 1 & 0 & 2 \\ 0 & 0 & 1 & 2 \end{array}\right]$

	Solution: $x = 1, y = 2, z = 2$

**E. LU Decomposition**

- Decompose $A$ into product of lower triangular $L$ and upper triangular $U$:

$$A = LU$$

- **Process**:
	1. Find $L$ and $U$ such that $A = LU$
	2. Solve $LY = B$ (forward substitution)
	3. Solve $UX = Y$ (backward substitution)

- **Advantage**: Efficient for solving multiple systems with same $A$ but different $B$


##### **7. Particular and General Solutions** ( ❌ Not important for GATE)

For non-homogeneous system $AX = B$:

**General Solution** = **Particular Solution** + **Homogeneous Solution**

$$X = X_p + X_h$$

where:

- $X_p$ is any particular solution of $AX = B$
- $X_h$ is the general solution of $AX = 0$

**Example**: If $AX = B$ has particular solution $X_p = \begin{bmatrix} 1 \\ 2 \\ 0 \end{bmatrix}$

and homogeneous solution $X_h = t\begin{bmatrix} 1 \\ -1 \\ 1 \end{bmatrix}$ (where $t$ is any real number)

Then general solution: $X = \begin{bmatrix} 1 \\ 2 \\ 0 \end{bmatrix} + t\begin{bmatrix} 1 \\ -1 \\ 1 \end{bmatrix} = \begin{bmatrix} 1+t \\ 2-t \\ t \end{bmatrix}$


##### **8. Vector Space Interpretation** ( ❌ Not important for GATE)

**Column Space** (Range/Image of $A$): $C(A) = {A\vec{x} : \vec{x} \in \mathbb{R}^n}$

- Dimension = $\text{rank}(A)$

**Null Space** (Kernel of $A$): $N(A) = {\vec{x} : A\vec{x} = \vec{0}}$

- Dimension = $\text{nullity}(A) = n - \text{rank}(A)$

**Row Space**: Space spanned by rows of $A$

- Dimension = $\text{rank}(A)$

**Left Null Space**: Null space of $A^T$

**Fundamental Theorem**:

$$\text{rank}(A) + \text{nullity}(A) = n$$

$$\dim(C(A)) + \dim(N(A^T)) = m$$

##### **9. Least Squares Solution** ( ❌ Not important for GATE)

For **overdetermined systems** ($m > n$, more equations than unknowns) with no exact solution:

**Normal Equation**:

$$A^TAX = A^TB$$

**Least Squares Solution**:

$$X = (A^TA)^{-1}A^TB$$

This minimizes $|AX - B|^2$

**Application**: Best fit line, curve fitting, data regression


##### **10. Condition Number and Stability** ( ❌ Not important for GATE)

**Condition Number**: Measures sensitivity of solution to changes in $A$ or $B$

$$\kappa(A) = |A| \cdot |A^{-1}|$$

For eigenvalue-based definition:

$$\kappa(A) = \frac{\lambda_{\max}}{\lambda_{\min}}$$

**Well-conditioned**: $\kappa(A)$ is small (close to 1)

**Ill-conditioned**: $\kappa(A)$ is large

**Singular matrix**: $\kappa(A) = \infty$


##### **11. Important GATE Concepts Summary** ( ❌ Not important for GATE)

**For Homogeneous Systems** ($AX = 0$):

- Always consistent (at least trivial solution)
- Non-trivial solution exists $\iff$ $\det(A) = 0$ (for square $A$)
- Number of free variables = $n - \text{rank}(A)$

**For Non-homogeneous Systems** ($AX = B$):

- Consistent $\iff$ $\text{rank}(A) = \text{rank}([A|B])$
- Unique solution $\iff$ $\text{rank}(A) = \text{rank}([A|B]) = n$
- Infinite solutions $\iff$ $\text{rank}(A) = \text{rank}([A|B]) < n$

**Key Formulas**:

- Cramer's Rule: $x_i = \frac{\det(A_i)}{\det(A)}$
- Matrix Inversion: $X = A^{-1}B$
- Rank-Nullity: $\text{rank}(A) + \text{nullity}(A) = n$

**Solution Methods Priority** (for GATE):

1. Cramer's Rule (for 2×2 or 3×3 with unique solution)
2. Matrix Inversion (for small square non-singular systems)
3. Gaussian Elimination (for general systems)
4. Rank method (for consistency check)


