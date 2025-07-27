
Singular matrix -> Determinant of matrix = 0

If rank < min(m,n) -> singular matrix
possible rank <=min(m,n)


Elementary operations

Echelon form -> settle all zeroes increasing order rowise -> to find rank 

Matrics Derived from a Matrix using Elementary operations -> Equivalent matrix
All 3 Elementeray transformation do not change rank -> Rank is same for equivalent Matrices -> Rank is invarient property of a matrix 
3rd Elementary operation -> do not change determinant


Non homogeneous system

AX=B 

1. P(A)!=P(A:B) ->P(A)< min(no. of row) -> for one or more eques. LHS(A)=0 and RHS(B)=constant -> inconsistent solution
2. P(A)=P(A:B) = no. of variable = P(B) -> for all eques LHS(A)=equs RHS(B)=constant -> Unique Solution
3. P(A)=P(A:B) < no. of variable = P(B) -> A & B linearly Dependent -> for some eques LHS(A)=0 and RHS(0) -> Infinite Solution


|A|=0 -> Singular -> Linearly Dependent Colum -> No Unique Solution &
1. (adj.A)B=0 -> infinite solution
2. (adj.A)B!=0 -> no Solution
3. |A|!=0 -> Non Linear Dependent Colum -> Unique Solution

B=0, Trivial solution = zero sollution = unique solution
B!=0, non trivial solution = non - zero solution = infinite solution

Homogeneous system (AX=0) either (A=0 & B=0 infinite) or (A=const & B=0 unique) is always consistent, 


Dolittle(left matrix diagonal unit) & Crout(right matrix diagonal unit) Method Lower upper triangle


Vector -> column Matrix

AX = Multiplication of Matrix A into Vector X
 λX = Multiplication of Number  λ into Vector X

AX =  λX Stretch Vector (if  λ>1) or shrink vector if ( 0<λ<1)
if ( λ<0 or negative) rotate of column vector by 180 and then shrink or stretch



 λ : Special value that shrink or stretch  vector  λ no. of time

AX=  λI X =   λX
AX- λX = (A- λI) = 0
 λ = eigne value , X = eigen vector
 A- λ Characteristic matrix
 |A- λI| characteristic polynomial
 |A- λI| = 0 characteristic Equation

eigen vector is a column matrix

Eigen value of equivalent matrix need not be same, i.e. applying elmentary operation change eigen value.

Spectrum of A - set of eighen values of A
Spectral Radius - Largest eigen value

![[Pasted image 20250130124133.png]]

![[Pasted image 20250130124307.png]]

---

Factorisation - (x^3 - 9)/(x-3) at x = 3

0/0 or infinity/infinity ?? -> L hospital Rule

f(x)/g(x) = f(x)'/g(x)' = f(x)''/g(x)'' = f(x)^n/g(x)^n

e^x in maclaurine series remember

![[Pasted image 20250129214206.png]]


---

