
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
	- $ϕ(a*b) = ϕ(a)*ϕ(b)$   ( where a & b are coprime)
	- ex: $ϕ(35) = ϕ(7*5) = ϕ(7)*ϕ(5)=6*4 = 24$

# [Euler's Theorem Explained with Examples in Hindi](https://youtu.be/y7sk9XIGdws)

Euler's Theorem is a fundamental result in number theory, often used in cryptography, particularly in algorithms like RSA (Rivest-Shamir-Adleman). In the context of information and network security, it plays a key role in ensuring secure communication by enabling efficient modular exponentiation and key generation.
### Euler's Theorem:

Euler's theorem states that if two numbers  `x` and `n` are **coprime** (i.e., they have no common divisors other than 1), then:

Euler's Theorem:
1. $x^{ϕ(n)}≡1 (mod n)$  (i.e. is when $x^{ϕ(n)}$ divided by n , give remainder 1)

ex: x =4   n = 165
GCD(4,165)=1 -> coprime
$ϕ(165) = ϕ(3)*ϕ(5)*ϕ(11) = 2*4*10 = 80$

$4^{ϕ(165)}=4^{80}≡1 (mod 165)$


 *Note :* If `x` and `n` are coprime then   $x^{ϕ(n)} ≢ 0 (mod n)$

2. $x^{ϕ(n)a}$≡$1 (mod n)$    (for all positive no. a)

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

Note: $gcd(n_i​,n_j​)=1$ for i≠j

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

The **discrete logarithm problem (DLP)** is a mathematical challenge that involves finding an integer `x` that satisfies the equation `g^x=h (mod p)`.
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
$a^P- a$ = multiple of p —> `p' is prime if this is a multiple of 'p' for all  1<=a<p.


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
- Public key - known to all users in Network
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


# [Diffie Hellman Key Exchange Algorithm | Cryptography and Network Security](https://www.youtube.com/watch?v=zLNug0LrFiU&ab_channel=AbhishekSharma)

## Diffie-Hellman Key Exchange
(i) It is not an encryption algo
(ii) Used to exchange secret keys between 2 users
(iii) We will use asymmetric encryption to exchange the secret key between users.

Why to use such algorithm??
-> Because when we are sending a key to receiver, it can be attacked in between.

## Diffie-Hellman Algorithm:

1. **Choose Prime no. and Primitive Root**
	- Consider a prime number `q`
	-  Select `α` such that it must be the primitive root of q and `α<q`
```
α is a primitive root of q if

α MOD q
α^2 MOD q
α^3 MOD q 
α^(q-1) MOD q

gives results {1, 2, 3, ....q-1}

ex: 3 is primitive root of 7, 5 is primitive root of 7
```
2. **Key Generation of Person 1**
	-  Assume $X_A$ (Private Key of A) and $X_A < q$
	- Calculate $Y_A=α^{X_A}modq$ (Public Key of A)
3. **Key Generation of Person 2**
	- Assume $X_B$ (Private Key of B) and $X_B < q$
	- Calculate $Y_B=α^{X_B}modq$ (Public Key of B)
4. **Calculate the Secret Key** (using another's public key)
	- $K_A = (Y_B)^{X_A}modq$
	- $K_B = (Y_A)^{X_B}modq$
5. `KA=KB` Thus the Secret Key `KA` and `KB` are Exchanged.


#### Example
1. Let `q=7`(prime) 
2. let `α=5` (primitive root of q) 
3. Assume `XA=3` ($X_A<q$)
4. Calculating Public Key `YA=6` ($Y_A=α^{X_A}modq$ = $5^3mod7$)
5. Assume `XB=4`  ($X_B<q$)
6. Calculate Public Key `YB=2` ($Y_B=α^{X_B}modq$ = $5^4mod7$)
7. Calculate Secret Key `KA=1` ($K_A = (Y_B)^{X_A}modq$ = $(2)^3mod7$)
8. Calculate Secret Key `KB=1` ($K_B = (Y_A)^{X_B}modq$ = $(6)^4mod7$)
9. `KA=KB` Thus the Secret Key `KA` and `KB` are Exchanged.

Note: Both of them don't need any information from anyone. They just use `α` and `q` which are global (known to all).

```
Person 1       Global Elements      Person 2
(A)             ┌────────────┐         (B)
                │ q=7, α=5   |               
                └────────────┘          
                ┌────────────┐ 
XA=3            │ YA=6, YB=2 │        XB=4
                └────────────┘
             Public Keys         
```

# [Elliptic Curve Cryptography | ECC in Cryptography and Network Security](https://www.youtube.com/watch?v=0NGPhAPKYv4&ab_channel=AbhishekSharma)

## Elliptic Curve Cryptography

Elliptic Curve Cryptography (ECC) is a public key cryptography method based on the algebraic structure of elliptic curves over finite fields. It is known for providing high security with smaller key sizes compared to other cryptographic systems like RSA, making it more efficient in terms of performance and resource usage.

- It is asymmetric public key cryptosystem.
- It provides equal security with smaller key size (eg: as compared to RSA and other non ECC algorithms.)
-  => **Small key size and high security**
- It makes use of Elliptic curves
- Elliptic curves are defined by some mathematical functions - Cubic Functions
$$y^2=x^3+a.x+b$$

![](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c1/ECClines.svg/680px-ECClines.svg.png)

- It is Symmetric to X-axis
- If we draw a line, it will touch a max of `3` points
- It is a Trapdoor function.
**Trapdoor Function**:  a function that is easy to compute in one direction, yet difficult to compute in the opposite direction (i.e. finding its inverse) without special information, called the trapdoor

```      
          easy
     x  ------------> f(x)       
        <------------
         Difficult

but        easy ( if givent 't'-> trapdoor)
       x <----------- f(x)
         
```

- Let $E_p(a,b)$ be the elliptic curve.
- Consider the equation `Q=k.P` ( where `Q`, `P` -> points on curve and K<n)
- Trapdoor / One way function
	- **easy** to find `Q` (If we `k` and `P` given)
	- **extremely difficult** to find `k` (if we know `Q` and `P`)
	- This is called the discrete logarithm problem for elliptic curves

### ECC - Key Exchange Algorithm

1. **Global Public Elements**
	1. $E_q(a,b)$ : Elliptic curve with parameters a, b and `q` (q = prime no. or an integer of the form 2^m)
	2. G : Point on the elliptic curve whose order is large value of `n`
2. **User A Key Generation**
	1. Select Private Key `nA` ( `nA` < `n`) 
	2. Calculate Public Key `PA` -> $P_A = n_A * G$
3. **User B Key Generation**
	1.  Select Private Key `nB` ( `nB` < `n`) 
	2. Calculate Public Key `PB` -> $P_B = n_B * G$
4. **Calculation of Secret Key by user A & B**
	1. `KA` = $K=n_A*P_B$
	2. `KB` = $K=n_B*P_A$
	- `KA=KB

```
A -----------> B
sender         Receiver
```
### ECC Encryption
1. Let the message be `M`
2. first encode this message `M` into a point on elliptic curve
	- Let this point be `Pm` (Now this point is encrypted)
3. for encryption chose a random positive integer `k`
4. The cipher point will be 
	-  For encryption public key of receiver (B) is used
	- $C_m = \{ kG, P_m + k.P_B\}$
	- This point will be sent to the receiver

### ECC Decryption
1. For decryption, multiply 1st point in the pair with receiver's secret key
	- $k.G *n_B$
2. Then subtract it from 2nd point/ coordinate in the pair
	- $P_m+k.P_B-(k.G*n_B)$
	- but we know $P_B = n_B*G$, substitute it
	- => $P_m+k.P_B-(k.P_B)$ = `Pm` (Original point)
	- so receiver gets the same point


This formulation clearly separates the components of the cipher pair for encryption and decryption in terms of C1C_1 and C2C_2.
### Table of NIST Recommended Key Sizes

| **Symmetric Key Size (bits)** | **RSA and Diffie-Hellman Key Size (bits)** | **Elliptic Curve Key Size (bits)** |
|-------------------------------|-------------------------------------------|------------------------------------|
| 80                            | 1024                                      | 160                                |
| 112                           | 2048                                      | 224                                |
| 128                           | 3072                                      | 256                                |
| 192                           | 7680                                      | 384                                |
| 256                           | 15360                                     | 521                                |

### Significance of Elliptic Curve Cryptography (ECC) over RSA:

1. **Smaller Key Sizes**:
   - ECC achieves equivalent security with significantly smaller key sizes than RSA.
   - Example: A 256-bit ECC key provides similar security to a 3072-bit RSA key.

2. **Performance**:
   - ECC computations are faster and require less processing power compared to RSA, making it ideal for devices with limited resources like IoT devices and smartphones.

3. **Reduced Bandwidth**:
   - Smaller keys mean less data is exchanged during encryption processes, improving performance in bandwidth-constrained environments.

4. **Enhanced Security**:
   - ECC is based on the mathematical difficulty of the Elliptic Curve Discrete Logarithm Problem, which is harder to break than the integer factorization problem on which RSA relies.

5. **Energy Efficiency**:
   - ECC requires less energy for computations, making it suitable for battery-powered devices.

6. **Longevity**:
   - As computational power grows, ECC is better positioned to remain secure with smaller key sizes compared to RSA, which would require impractically large keys in the future.


# [Authentication functions and 3 ways to produce authentication | Message authentication](https://www.youtube.com/watch?v=SAz7-A6rNKM&list=PL0wXpxSD7pqV6zUknwtFSKke90Cw7xuN3&index=1&ab_channel=AbhishekSharma)
- Raman ----------> John
->It is one of the 5 principles of security
->Authentication -> Verifying the users identity
->An authenticator must be there to authenticate the message

### Types of Authentication or Types of function to produce authentication

1. **Message Encryption :** Cipher text act as authenticator
2. **MAC (Message authentication code:** We will have some authentication function `c` and we apply them on the plain text `M` along with the key `K` which produces a fixed length code called MAC that act as a authenticator.  `c(M,K)=fixed length code(MAC)`
3. **Hash Function(H):** It is Independent of Key, produce fixed length code `h` that act as authenticator `H(M)=fixed lenght code (Hash code 'h')

# 1. Message Encryption
- Cipher text is an authenticator

##### A. **Symmetric Key Encryption :** Key K1 shared only between sender and receiver only
```
sender(A)    cipher text    receiver(B)

[M]--->(E)--->[//M//]--->(D)--->[M]
        ↑                 ↑
        K                 K
```
- Authentication✅  Confidentiality✅

##### B. **Asymmetric encryption :** Receiver Public key for Encryption, and Receiver Private Key for Decryption
```
sender(A)    cipher text    receiver(B)

[M]--->(E)--->[//M//]--->(D)--->[M]
        ↑                 ↑
       KPuB              KPrB
```
- Authentication❌  Confidentiality✅

##### C. **Asymmetric encryption :** Senders Private key for Encryption, and Senders Public Key for Decryption
```
sender(A)    cipher text    receiver(B)

[M]--->(E)--->[//M//]--->(D)--->[M]
        ↑                 ↑
       KPrA              KPuA
```
- Authentication✅  Confidentiality❌
#### D. **Asymmetric Encryption :** To get both, authentication and confidentiality, and also signature. Use dual encryption and Decryption 
```
sender(A)               cipher text                  receiver(B)

[M]-->(E)-->[/M/]-->(E)-->[//M//]-->(D)-->[/M/]-->(D)-->[M]
       ↑             ↑               ↑             ↑ 
      KPrA          KPuB            KPrB          KPuA
```
- Authentication✅  Confidentiality✅
Note: We also get Digital Signature because, we are using private key of senders for encryption

# 2. [MAC in Cryptography || Message Authentication Code in Cryptography and network security](https://www.youtube.com/watch?v=Om4O14irGzA&list=PL0wXpxSD7pqV6zUknwtFSKke90Cw7xuN3&index=3&ab_channel=AbhishekSharma)

-> We will use a secret key to generate a small `fixed size block` of data called MAC or cryptographic checksum

-> It is then appended with the message.
-> The communicating parties will share a secret common key which will be use to create the MAC

When A sends a Msg to B, it calculates the MAC as a function of the message and the key.
`MAC = C(K,M)`
Where:
- M= input message
- C=MAC function
- K=shared secret key

#### A. MAC for Authentication
```                  .
                    .               K
Sender        append .  ┌-----┐      ↓
[Msg]--------->(||)---->| Msg |----(C)----↓ compare
  |              ↑   .  |-----|         (= or !=)? 
  ↓              |   .  | MAC |-----------↑
(Mac Func C)-----┘   .  └-----┘
 ↑                   .
 K                   .

Comparison:if equal message is authentic
```
- Authentication✅  Confidentiality❌

#### B. MAC for Authentication and Confidentiality (tied to Plain text i.e. `[Msg|MAC]`)
```               
                                              K2
Sender  append                   ┌-------┐    ↓
[Msg]-->(||)---[Msg|MAC]---(E)-->|//Msg//|---(D)---[Msg|MAC]-----↓ compare
  |      ↑                  ↑    |-------|           |           (= or !=)? 
  ↓      |                  K2   |//MAC//|           └---(C)------↑
(C)------┘                       └-------┘                ↑
 ↑                                                        K1
 K1               
```
- Authentication✅  Confidentiality✅

#### B. MAC for Authentication and Confidentiality ( tied to Cipher text i.e. `[//Msg//|MAC]` )
```                                 Msg  
                                     ↑
                                K1->(D)
         K1                          |         K2    K1
Sender   ↓     cipher    append  ┌-------┐     ↓      ↓
[Msg]-->(E)--[//Msg//]-->(||)--->|//Msg//|----(C)----(D)-----↓ compare
 |                        ↑      |-------|                    (= or !=)? 
 ↓                        |      |  MAC  |-------------------↑
(C)-----------------------┘      └-------┘              
 ↑       
 K2

 M---->E(M,k)---------->[C(M,k2),(E(M,k1))]-->E(M,k1)-->M	(Make this type of function for all diagram above and below)			
```
- Authentication✅  Confidentiality✅

Significance of MAC
i. ensures that receiver knows whether the msg has been altered or not
ii. authentication ensured - receiver is ensured that the message come from the correct sender

#### Difference between MAC `B` and `C`

- B: **Encrypt-and-MAC** can miss tampering with encrypted data.
	- Limitation: The MAC is created _before_ encryption. So, if someone modifies the encrypted data (ciphertext), the system might not detect it.
	-  Ex: Used in **file transfers** (e.g., SFTP).
- **Limitation**: 
- C: **Encrypt-then-MAC** is better because it checks for tampering in both the plaintext and the ciphertext.
	- Limitation: The MAC is created _after_ encryption, so it protects both the message and the encrypted data. If someone tampers with the ciphertext, it will fail verification.
	- Ex: Used in **TLS** for secure communication.

# [Hash Functions in Cryptography](https://www.youtube.com/watch?v=jNoUtbK8hv4&list=PL0wXpxSD7pqV6zUknwtFSKke90Cw7xuN3&index=5&ab_channel=AbhishekSharma)

## Hash function
- It is similar to MAC but it does not use a key
- It takes in variable size message and produce **fixed size output** Called Hash code ( Hash Value  or Message Digest)
- The only input in the message is message `M`
- A hash value `h` is generated by a function `H` (Also called compression function )
	- `H(M)=h` (fixed length code)

## Different Hash methods to provide authentication in different situations

## Symmetric

1 E(M|h)
![[Pasted image 20241121001215.png]]
Authentication✅  Confidentiality ✅

2 M|E(h) . Reduce processing time
![[Pasted image 20241121001355.png]]
Authentication✅  Confidentiality ❌

## Asymmetric

3 M|E(h) . Reduce processing time
![[Pasted image 20241121001921.png]]
Authentication✅  Confidentiality ❌

4 E(M|E(h)) : Asymmetric(private key) for signing algorithm + Symmetric for Confidentiality
![[Pasted image 20241121002112.png]]
Authentication✅  Confidentiality ✅


## Secret code

- above h = H(M)
- here hs=H(M|S)

5 M | hs
![[Pasted image 20241121002634.png]]
Authentication✅  Confidentiality ❌

6  E(M | hs) , Secret Code for signing algorithm + Symmetric for Confidentiality
![[Pasted image 20241121003156.png]]
# [#42 Public key Infrastructure (PKI), Architecture Of PKI|CNS|](https://youtu.be/lYxZ6c8VN7o)



## Public key Infrastructure (PKI)

- It is a standard followed for **managing, storing and revoking the digital certificate**
- It follows asymmetric key cryptography
- It includes:
	1. Message Digests - for Integrity
	2. Digital Signature - for Authentication and Non-Repudiation
	3. Encryption Services - for Confidentiality

Note: 
1. Authentication : -> authenticate message come from correct person
2. No-Repudiation:-> The receiver cannot deny
3. Confidentiality:-> Only the authorized receiver can access the message.

**Architecture of PKI** : It consists of 4 parts
1. Certificate Repository : Store Certificates + Info.
2. Entity - User (Single Person, Organization or Router)
3. Registration Authority (RA) - Register and Verify User
4. Certification Authority (CA) - Decide if It would give certificate or not, or for how much time it would give access to the user

# [#26 Symmetric Key Distribution - Methods |CNS|](https://www.youtube.com/watch?v=d7T-7pmfr74&ab_channel=Trouble-Free)

## Key Distribution in Symmetric Key
1. **Physical Delivery** : directly meeting the receiver (but it take time)
2. **Key Distribution Center (KDC)** : Generate the key and send to sender and Receiver (but you should be rely on third party)
3. **Using Previous keys** : Generate new key by encrypting it using old key 
4. **Using Third Party** :  In place of (A->B) use (A->C->B)

# [#37 Digital Signature In Cryptography |CNS|](https://www.youtube.com/watch?v=xPRdrzo46HI&ab_channel=Trouble-Free)

## Digital Signature

- It is used for authentication and Non-Repudiation
- It is a Asymmetric key cryptography
- Encryption : using private key of sender
- Decryption : using public key of sender
- It is used for authentication (comes from correct person)

-> Signature : Proof of Identity : is it from correct sender/ or not

```
                                                       (Y)
		      [M]───────────────┐                        |
		       ↓                |                        ˅
		┌─────────────────┐     |   ┌───┐       ┌─────────────────┐
(X)->	│ Digital Sign.   │     └── | M | =>    │ Digital Sign.   │
		│ Generation Algo.│     ┌── ├───┤       │ Generation Algo.│ 
		└─────────────────┘     |   | S |       └─────────────────┘
		       ↓                |   └───┘               |
		      [S]───────────────┘                       ˅
		                                              Valid or not

X - Private Key
Y - Public Key
If msg match -> valid otherwise nto
```

**DSS ensures :**
- Receiver can verify the claimed identity of the sender
- Sender cannot later repudiate the contents of the message
- Receiver cannot possibly have manipulated the message itself

GPT
A **Digital Signature** primarily uses a **hash function** and **encryption** (not MAC) as part of its operation. Here's a breakdown:

1. **Hash Function**:
- A hash function (e.g., SHA-256) is used to create a fixed-size digest (or hash) of the original message.
- The hash ensures **integrity** (any change in the message will result in a completely different hash).

2. **Encryption**:
- The hash is **encrypted using the sender's private key** (asymmetric encryption) to create the digital signature.
- This ensures **authenticity** (only the sender's private key could have created the signature) and **non-repudiation** (the sender cannot deny their involvement).