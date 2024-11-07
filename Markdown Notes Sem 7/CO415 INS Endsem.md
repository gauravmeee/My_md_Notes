
# [Euler's Toient Function Explained with Examples in Hindi #38](https://youtu.be/0uRL3ymzWig)

`ϕ(n) for [n>=1]` is defined as the number of positive integer less than `n` that are coprime to `n`

Note: two number are coprime if the greater common divisior (gcd) of them are 1;
a & b are coprime if gcd(a,b)=1
ex: gcd(5,7) =1 -> 5 and 7 are coprime

ϕ(5) = 4  because  positive and coprime no. less then 5 are { 1, 2, 3, 4}
ϕ(6) = 2  because  positive and coprime no. less then 6 are { 1,  5}

Formula to Calculate Euler's Totient Function

1. If `n` is a prime number
	- ϕ(n) = n-1
	- ex: ϕ(23) = 22
1. If `n` is not a prime number
	- ϕ(a*\b) = ϕ(a)\*ϕ(b)   ( where a & b are coprime)
	- ex: ϕ(35) = ϕ(7\*5) = ϕ(7)\*ϕ(5)=6\*4 = 24

# [Euler's Theorem Explained with Examples in Hindi](https://youtu.be/y7sk9XIGdws)

Euler's Theorem is a fundamental result in number theory, often used in cryptography, particularly in algorithms like RSA (Rivest-Shamir-Adleman). In the context of information and network security, it plays a key role in ensuring secure communication by enabling efficient modular exponentiation and key generation.
### Euler's Theorem:

Euler's theorem states that if two numbers  `x` and `n` are **coprime** (i.e., they have no common divisors other than 1), then:

Euler's Theorem:
1. $x^{ϕ(n)}≡1 (mod n)$  (i.e. is when $x^{ϕ(n)}$ divided by n , give remainder 1)

ex: x =4   n = 165
GCD(4,165)=1 -> coprime
ϕ(165) = ϕ(3)\*ϕ(5)\*ϕ(11) = 2\*4\*5 = 80

$4^{ϕ(80)}≡1 (mod 165)$


 *Note :* If `x` and `n` are coprime then   $x^{ϕ(n)} ≢ 0 (mod n)$

2. $x^{ϕ(n)a}≡1 (mod n)$    (for all positive no. a)

# [Primitive Roots #42](https://www.youtube.com/watch?v=DKy98FWHwdg&ab_channel=NesoAcademy)

A number `a` is a primitive root `modulo n` if every number coprime to `n` is congruent to a power of `a` `modulo n`

simply, `a` is said to be a primitive root of prime number `p`, if `a^1 mod p` , `a^2 mod a^3 mod p`, .... `a^(p-1) mod p` are distinct

**Example: Primitive root of prime number 5**:
$2^1 mod 5$  = $2 mod 5$ = 2 
$2^2 mod 5$  = $4 mod 5$ = 4
$2^3 mod 5$  = $8 mod 5$ = 3
$2^4 mod 5$  = $16 mod 5$ =1

So `2` is primitive root of `5` because, the above equation gives all no. from 1 to 5

Note: the order or the numbers are unpredictive

Similarly, 

**Ques. Is 3 is primitive root of 7 ?** -> Yes
$3^1 mod 7$  = $3 mod 7$ = 3 ✅
$3^2 mod 7$  = $3^2mod 7$ = 2 ✅
$3^3 mod 7$  = $(3^2mod 7 * 3^1mod 7)mod7$  = $6 mod 7$ = 6 ✅
$3^4 mod 7$  = $(3^3mod 7*3^1mod 7)mod7$  = $18 mod 7$ = 4 ✅
$3^5 mod 7$  = $(3^4mod 7*3^1mod 7)mod7$  = $12 mod 7$ = 5 ✅
$3^6 mod 7$  = $(3^5mod 7*3^1mod 7)mod7$  = $15 mod 7$ = 1 ✅

**Ques. Is 2 is primitive root of 7 ?** -> No
$2^1 mod 7$  = $2 mod 7$ = 2 ✅
$2^2 mod 7$  = $4mod 7$ = 4 ✅
$2^3 mod 7$  = $8 mod 7$ = 1 ✅
$2^4 mod 7$  = $16 mod 7$ = 2 ❌ Repeat
$2^5 mod 7$  = $4 mod 7$ = 4 ❌ Repeat
$2^6 mod 7$  = $8 mod 7$ = 1 ❌ Repeat


# [Fermat's Theorem Explained with Examples in Hindi #47](https://youtu.be/N0aLkfJaX1E)


It's Special case of Euler's Theorem ($x^{ϕ(n)}≡1 (mod n)$ ) Where n is a  prime no.
If n is prime no. ϕ(n)= n-1

Fermat's Theorem: 
1. $x^{n-1} ≡ 1 modn$

ex: x=3 n=5
$3^{5-1} ≡ 1mod5$
$3^{4} ≡ 1mod5$
$81 ≡ 1mod5$

2. $x^n ≡ x modn$

ex: x=3 n=5

$3^5=3mod5$
243 = 3mode5

Conclusion
This is the theorem $x^n ≡ x modn$ , that would be required to understand and deal with public/private RSA


---

# [The Chinese Remainder Theorem (Solved Example 1)](https://youtu.be/e8DtzQkjOMQ)

The Chinese Remainder Theorem (CRT) is used to solve a set of different congruent equations with one variable but different moduli which are relatively prime as shown below:

$X≡a_1(mod m_1)$
$X≡a_1(mod m_1)$
...
$X≡a_n(mod m_n)$

CRT states that the above equations have a unique solution of the moduli are relatively prime.

$X = (a_1M_1M_1^{-1} + a_2M_2M_2^{-1} + ... + a_nM_nM_n^{-1}) mod M$

where, 
$M = m_1 * m_2 * ... m_n$
$M_n = M/m_n$
$M_n . M_n^{-1} =1\: mod\:m_n$



Example 1: Solve the following equations using CRT
$X≡2(mod 3)$
$X≡3(mod 5)$
$X≡2(mod 7)$

Solution:
$X = (a_1M_1M_1^{-1} + a_2M_2M_2^{-1} + a_3M_3M_3^{-1}) mod M$

Given
$a_1=2$, $a_2=3$, $a_3=2$
$m_1=3$, $m_2=5$, $m_3=7$

To find :
$M_1, M_1^{-1} , M_2, M_2^{-1}, M_3, M_3^{-1}, M$

$M = 3 * 5 * 7 = 105$
$M_1 = 105/3= 35$
$M_2 = 105/5= 21$
$M_3 = 105/7= 15$

$35.M_1^{-1} = 1\:mod \:3$ -> $M_1^{-1}=$  1❌, 2✅
$21.M_1^{-1} =1\:mod \:5$ -> $M_1^{-1}=$  1✅
$15.M_1^{-1} = 1\:mod \:7$ -> $M_1^{-1}=$  1✅

$X = (2.35.2 + 3.21.1 + 2.15.1) mod 105$
$X = (140 + 63 + 30) mod 105$
$X = (233) mod 105$
$$
X = 23
$$

Verify:
$23≡2(mod 3)$ ✅
$23≡3(mod 5)$ ✅
$23≡2(mod 7)$ ✅


# [The Discrete Logarithm Problem #49](https://youtu.be/za9azzh4v9A)

The **discrete logarithm problem (DLP)** is a mathematical challenge that involves finding an integer `x` that satisfies the equation `g=h (mod p)`.
- The DLP is considered computationally hard, meaning there is no known efficient classical algorithm for computing discrete logarithms in general.

Understanding of DLP

Here `5` is primitive root of `17`
$5^1mod17$ = 5
$5^2mod17$ = 8
$5^3mod17$ = 6
$5^4mod17$ = 13
$5^5mod17$ = 14
$5^6mod17$ = 2
$5^7mod17$ = 10
$5^8mod17$ = 16
$5^9mod17$ = 12
$5^{10}mod17$ = 9
$5^{11}mod17$ = 11
$5^{12}mod17$ = 4
$5^{13}mod17$ = 3
$5^{14}mod17$ = 15
$5^{15}mod17$ = 7
$5^{16}mod17$ = 1

Unique result for  `a^x mod n` where (a is primitive root of n and , x = 1 to n-1)

**One-way function**: Function with property, finding solution is easy in one direction, but hard in the reverse direction
```
Finding `?`

------Easy------->
5^9 MOD 17 = ?

<-----Difficult---
5^? MOD 17 = 12
```

- $g^Xmodp$
-  $2^Xmod7=4$; X = 2, 5, etc.
- For smaller value of `p` is may be easy to find x.
- If `p` is very large, then finding `X` is hard.
- if `p` is large, then the time and effort to find `X` is very hard.
- The strength of one-way function is depending on how much time it takes to break it.


# [The Discrete Logarithm Problem (Solved Example) #50](https://www.youtube.com/watch?v=yKNTfeqSEhc&t=6s&ab_channel=NesoAcademy)

Example 1: Solve $log_29mod11$
Solution : 
Here, p=11, g=2, X=9
-> $log_gX ≡ n(modp)$
-> $X ≡ g^n (mod p)$
-> $9 ≡ 2^n (mod11)$

Try `n` = 1, 2, 3, ....

| `n` | `X`                 |
| --- | ------------------- |
| 1   | $2mod11$ = 2 ❌      |
| 2   | $4mod11$ = 4 ❌      |
| 3   | $8mod11$ = 8 ❌      |
| 4   | $16mod11$ = 5 ❌     |
| 5   | $32mod11$ = 10 ❌    |
| 6   | $64mod11$ = 9 = 9 ✅ |
Ans : 6

# Principle of Public Key Cryptography

# [Testing for Primality (Fermat's Test)](https://www.youtube.com/watch?v=sDrXeCs3ghQ&ab_channel=NesoAcademy)

It answer whether a given number is prime no. or not.

**Is 'p' prime?**

Test:
$a^P- a$ —> `p' is prime if this is a multiple of 'p' for all  1<=a<p.


**Example: Is '5' prime?**
Solution:
$a^p-a$ -> 'p' is prime if this is a multiple of 'p' for all `1<=a < p`.
a = 1, 2, 3, 4.

$1^5-1 = 1-1 = 0$
$2^5-2 = 32-2 = 30$
$3^5-3 = 243-3 = 240$
$4^5-4 = 1024-4 = 1024$
∴ 5 is prime



**Drawbacks of Fermat's Primarily test :**
1. If prime number is very large, we need to carry out the process, from a = 0, 1, 2 .... (p-1) or `a^p-a` non multiple of `p` and so time consuming.
2. Accuracy is not 100%. (ex: 561=3x11x17 is a composite no., but fermat's test say its prime no.)

# [Testing for Primality (Miller-Rabin Test)](https://youtu.be/8i0UnX7Snkc)
~ Michael Oser Rabin  & Gary Lee Miller

**Miller-Rabin Primality Test**
- Miller-Rabin primality test or Rabin-Miller primality test.
- It perform Probabilistic primality test.
- Similar to Fermat primality test and the Solovay-Strassen primality
test.
- Checks whether a specific property, which is known to hold for prime
values, holds for the number under testing.

**Algorithm :**
- To test whether `n` is prime no. or not
Step 1:
	Find $n-1 = 2^k*m$
Step 2:
	Choose `a` such that `1<a<n-1`
Step 3:
	Compute $b_0 = a^m(modn), ..., b_i = b^2_{i-1}(modn)$
		if $b_0=+1$  then Composite
		if $b_0=-1$ Probably Prime

- if $b_0$ neither +1 or -1, move to next value of $b_{i+1} =b^2_{i}(modn)$ until find $b_x =$ +1 or -1


**Is 561 prime?**

Solution:
	Given n = 561

Step 1:
	$561-1 = 560 = 2^4 * 35$
	So `k=4`, and `m=35`
Step 2: 
	Choosing `a=2`; 1<2<560
Step3:
	Compute $b_0=a^m(mod n)$
	$b_0=a^{35}(mod 561) = 263$ 
	(above expression Solved using modular exponentiation, study it)
	$b0 =$ not +1 or -1

	$b_1 = b_0^2(mod n)$
	$b_1=263^2(mod 561) = 166$
	$b1 =$ not +1 or -1

	$b_2 = b_1^2(mod n)$
	$b_2=166^2(mod 561) = 67$
	$b2 =$ not +1 or -1

	$b_3 = b_2^2(mod n)$
	$b_3=67^2(mod 561) = 1$
	$b1 =$ +1
	561 -> composite no. 
	
	
# [RSA Algorithm in Cryptography and Network Security](https://youtu.be/rlJTMUBXhKE)

RSA (Rivest-Shamir-Adleman) developed in 1978

- It is an asymmetric cryptographic algo. (2 keys) i.e. public and private key concept is used here.
- Public key - known to all users in N/W
- Private key - Kept secret, not sharable to all.

If public key of user A - is used for encryption, we have to use the private key of same user for decryption

The RSA Scheme is a `block cipher` in which the plain text and cipher text are integers b/w `0` and `n-1` for some value n.

# [RSA Algorithm](https://www.youtube.com/watch?v=VUxfDCmWM0U&ab_channel=GateSmashers)

**RSA (Rivest-Shamir-Adleman)** is a widely used public-key cryptosystem for secure data transmission. It was developed by *Ron Rivest*, *Adi Shamir*, and *Leonard Adleman* in 1977. 

RSA is based on the mathematical fact that it is easy to multiply large prime numbers together, but it is hard to factorize the resulting product.


1. **Public and Private Keys**: 
   - **Public Key**: Used to encrypt the message and can be shared openly.
   - **Private Key**: Used to decrypt the message and must be kept secret.

2. **How RSA Works**:
   - **Key Generation**:
     1. Choose two large prime numbers, `p` and `q`.
     2. Compute `n = p*q`. `n` is used as the modulus in both the public and private keys.
     3. Compute Euler’s totient function `ϕ(n) = (p-1)(q-1)`.
	     - i.e. find number of coprime of `n` Smaller then n
     4. Choose a public exponent `e` such that `1 < e < ϕ(n)` and `gcd(e,ϕ(n)) = 1.
	     - i.e. select one `e` from the coprime of `n` that  are smaller than n
     5. using the extended Euclidean algorithm, Compute the private exponent `d` such that `e*d ≡ 1 mod ϕ(n)`
	     - i.e. find smallest Integer `d` using `d*e = 1 + Kϕ(n)`by trying different values of K=0, 1, 2, 3.... 
     6. The public key is `(e, n)` and the private key is `(d, n)`.
	     - e=public key, d=private key

Ques. In a RSA cryptosystem a particular A uses two prime no. p=13 and q=17 to generate his public and private keys. If the public key of A is 35. Then find the private key of A

Step 1:  choose two different large random no. `p` and `q`
	p=13 , q =17 (Given)

Step 2: Calculate `n = p*q`
	n = p* q = 221
	
Step 3: Calculate `ϕ(n)=(p-1)*(q-1)`.
	ϕ(221) = 12 * 16 = 192
	
Step 4: choose `e` such that `1<e<ϕ(n)` such that `gcd(e,ϕ(n))=1`
	e=35 (Given)
	
Step 5: Calculate d, such that `d*e ≡ 1 mod ϕ(n)`
	find `d = (1 + Kϕ(n))/e` for k=0, 1, 2,....
	for K=0,   d = 0.02
	for K=1,   d = 5.5
	for K=2,   d = 11 ✅
	so d = 11

Step 6:
	public key = 35
	private key = 11

# [Security Of RSA - Applied Cryptography](https://youtu.be/-SK3qIjz5P8)

Given `(e,n)` it is hard to find `d`.

- Easy for an attacker who knows `n=p.q` the factors of n
- such attacker could compute `d` using $d = e^{-1}modϕ(n)$, `ϕ(n)=ϕ(p)*ϕ(q) = (p-1)(q-1)`

1. Showing that all ways of breaking RSA would allow easy ways to factor n.
2. Claim that factoring `n` is hard.