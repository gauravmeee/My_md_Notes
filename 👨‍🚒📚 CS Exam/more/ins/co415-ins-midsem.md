# CO415 INS Midsem

> Gaurav Meena

#### Substitution Cipher Examples:

* Caesar Cipher
* Playfair Cipher
* Hill Cipher
* One-Time Pad

#### Transposition Cipher Examples:

* Rail Fence Cipher
* Columnar Transposition Cipher
* Route Cipher
* Double Transposition Cipher

#### DES

The **Data Encryption Standard (DES)** uses a combination of several cryptographic techniques. Here are the main techniques involved:

1. **Feistel Network**: DES is based on the Feistel cipher structure, which splits the data into two halves and applies encryption rounds to each half alternately.
2. **Substitution (S-boxes)**: DES uses 8 substitution boxes (S-boxes) to replace parts of the data with other values, making the output nonlinear and hard to predict.
3. **Permutation (P-boxes)**: DES applies permutations to shuffle the bits of the data, enhancing diffusion by spreading out the influence of each bit across the entire block.
4. **Initial and Final Permutations**: The data is permuted once at the start (Initial Permutation or IP) and again at the end (Final Permutation) for better diffusion.
5. **16 Rounds of Encryption**: DES applies 16 rounds of encryption, where substitution and permutation steps are repeated for security.
6. **Key Schedule**: DES uses a 56-bit key, which is expanded to generate 16 subkeys (one for each round of encryption).
7. **XOR (Exclusive OR)**: The data is XORed with the subkey during each round of encryption.

These techniques combine to provide confusion and diffusion, the core principles of strong encryption, ensuring that each bit of the ciphertext depends on many bits of the key and plaintext.

Encryption

```
			 Sender
				|
				˅
			Plain Text
				|
				˅
		[ ][ ][ ][ ][ ][ ] Divide into blocks
				│
			  (Key) -> // size of key: (40, 56, 64, 128, 256, bits)     
			    │	  
				│
				˅
		[ ][ ][ ][ ][ ][ ] blocks of cipher text
```

Decryption

```
		[ ][ ][ ][ ][ ][ ] blocks of cipher text
				│
			  (Key) -> // size of key: (40, 56, 64, 128, 256, bits)     
			    │	  
				│
				˅
		[ ][ ][ ][ ][ ][ ] Divide into blocks
		        |
		        ˅
		    Plain Text
		        |
		        ˅
		     Reciever
```

Ex : DES block Cipher

#### DES (Data Encryption Standard) .

* `block size` of plain and Cipher text = `64 bits`.
* `Key size` adopted = `56 bits`.

## [Shannon's theory of Confusion and Diffusion | Cryptography and Network Security](https://youtu.be/3NpRhXWWWMQ)

### Shannon's Theory of confusion and Diffusion

1. The terms confusion and diffusion were introduced by \~ _Claude Shannon_.
2.  Shannon's concern was to prevent crypt analysis, based on statistical analysis. The reason is as follows.

    Assume attacker has some knowledge of the statistical characteristics of the plaintext (eg:- in a Msg, the frequency distribution of the various letters may be known.) If these statistics are in any way reflected in ciphertext, the cryptanalysis i.e. attacker may be able to deduce the encryption key.

The Shannon's suggested 2 Methods for frustrating the attackers: **Confusion & Diffusion :** Properties for creating a secure Cipher

**1. DIFFUSION:**

If a symbol in the plaintext is changed, several or all symbols in the ciphertext will also change.

* The Idea of diffusion is to hide the relationship between the `ciphertext` and `plaintext`.

> Wikipedia : Diffusion means that if we change a single bit of the plaintext, then (statically) half of the bits in the ciphertext should change, similarly, if we change 1 bit of ciphertext, then at least one half of the plaintext bits should change.

ex: transpositon

Diffusion implies that each symbol in the 'ciphertext; is depend on source or all the symbols in the 'plain text'

**2. CONFUSION:**

If a single bit in the key is changed then most/all bits of the ciphertext will also be changed.

* It hides the relationship between ciphertext and key

> Wikipedia : Confusion means that each bit of the ciphertext should depend on several parts of the key, obscuring (make unclear or difficult to understand) the connection between the two.

ex: substitution

In short, **Diffusion:-** Make statistical relation between `plaintext and ciphertext` as complex as possible.

* if change 1 bit of plain text then half or more bits of cipher should change
* i.e. if we change a single bit of the Plain text then half of the bits in the Cipher text should change and vice versa.

**Confusion:-** Make relation between `key and cipher text` as complex as possible

* each bit of ciphertext should depend on `key`
* changing one bit of the key should change the cipher text completely

## [Classical Encryption Techniques](https://youtu.be/UJiLgUtddlM)

1. Substitution Technique
2. Transposition Technique Here are the two revised tables:

| **Substitution**       | **Block Cipher** | **Stream Cipher** |
| ---------------------- | ---------------- | ----------------- |
| Caesar Cipher          |                  | Yes               |
| Monoalphabetic Cipher  |                  | Yes               |
| Playfair Cipher        | Yes              |                   |
| Hill Cipher            | Yes              |                   |
| Polyalphabetic Ciphers |                  | Yes               |
| One-Time Pad           |                  | Yes               |

| **Transposition**        | **Block Cipher** | **Stream Cipher** |
| ------------------------ | ---------------- | ----------------- |
| Rail Fence               |                  | Yes               |
| Row Column Transposition | Yes              |                   |

**Substitution Technique**

* Letters are replaced by other Letters or symbols
* ex:

```
| a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z |

a -> M
b -> X
x -> Z
g -> A

Plaintext : bag
Ciphertext : XMA
```

**Transposition Technique**

* Applying some sort of permutation on the plaintext letters.
* ex:

```
Plaintext : NESO
Ciphertext: ESON, SONE, ONES or ENOS....
```

## [Caesar Cipher Explained with Solved Example ll Information and Cyber Security Course in Hindi](https://youtu.be/euVke4djgDg)

#### Substitution Cypher Technique

Letters are replaced by other letters or symbols.

Caesar Cipher :

* The earlier known and simplest method used by Julius Caesar.
* Replacing each letter of the alphabet with the letter standing three places further down the alphabet.
* Ex: Caesar Cipher (Easiest Method of substitution)

#### Caesar Cipher

_Note:_ we will use lowercase alphabets for cipher text, and upper text for plain text, to differentiate between them.

```
Plain Text Alphabets :- A B C D E  F G H I J K L M N O P Q R S T U V W X Y Z
Cipher Text Alphabets:- d e f g h i j k l m n o p q r s t u v w x y z a b c

A(a), B(b), ..... Z(z)
 0      1   ...... 25
```

**Encryption Function: `C = E(3,P)=(P+3)mod26`**

* E: Encryption, P: plain text, C: cipher text

Ex: let P='A' C = E(3, P) = ( P+3) => ('A' + 3)%26 => (0+3)%26 => (3) = ('D') - Significance: Each Character Shifted by 3 - It is a kind of mapping function

Example of Message

```
Plain Text: FIVE MINUTES ENGINEERING
Cipher text: ilyh plqxwhv hgjlqhhulgj
```

how to decrypt??

**Decryption Function: `C = D(3,C)=(C-3)mod26`**

* E: Encryption, P: plain text, C: cipher text

## [PlayFair Cipher ll Basics Of Playfair Cipher Explained with Solved Example in Hindi](https://youtu.be/jS8u6bX6Xi4)

let Message: Jazz Keyword: Monarchy

Make a table 5x5

Fill the Cells Keyword from left to right. M, O, N, A, R, C, H, Y

Fill the remaining cells sequentially with alphabets that not counted in keyword. (fill i & j in one cell because there are 25 cells while alphabets are 26) b, d, e, f, g, i/j , k, l, p, q, s, t, u, v, w, x, z

There are 36 Letter in

```
---------------------
| M | O | N | A | R |
|---+---+---+---+---|
| C | H | Y | b | d |
|---+---+---+---+---|
| e | f | g |i/j| k |
|---+---+---+---+---|
| l | p | q | s | t |
|---+---+---+---+---|
| u | v | w | x | z |
---------------------
```

_Note:_ If the keyword has repeated element , like in BALLOON than eliminate duplicate one, and the key will be BALON

Plain Text : Jazz Pair them in two, there should not be repetition of character in pair (if we choose on alphabet, and next alphabet is same, than take extra 'x' to make its pair) If there are no pair for last alphabet, add x

JA Z Z ↓ ↓ ↓ JA ZX ZX ㅡ ㅡ ㅡ

Now Check for Each Alphabets in The table, Pair wise.

Rules:

1. If the pairs lie in same column -> then substitute the alphabets with there immediate down alphabet (last immediate's down will be first) eg. JA->SB : j->s, a->b
2. If the pairs lie in same row -> then take immediate right (Last immediate right will be first) eg. ZX->UZ: z->u, x->z
3. If the pairs don't lie in same row and column, Make a rectangle ,consider the pair cells as two corner of the rectangle, and find out two other corner. the new corner cell/Alphabet will be substite the previous one with the same row. eg. FX-IV> f->i/j, x->v retcangle: F - i/j v - x Note: you can choose i or j any one, from i/j cell

JA ZX ZX ↓ ↓ ↓ sb uz uz ㅡ ㅡ ㅡ

More Ex:

Plain Text: GREET GR EX ET ㅡ ㅡ ㅡ kn gu lk

Plain Text: OFF OF F ↓ ↓ OF FX ↓ ↓ hp iv ㅡ ㅡ

## [Hill Cipher Encryption Explained in Detail with Solved Example in Hindi](https://youtu.be/xv5lwFxxUw0)

Key = HILL Plain Text (Message) = Short Example

Consider A =0, B=1... Z=25

Fill the Keyword into 2x2 matrix. Then change into corresponding number Matrix should be square of 2x2 and 3x3

```
key = ⌈ H I ⌉
	  ⌊ L L 」
	    ↓ 
	  ⌈  7  8 ⌉
	  ⌊ 11 11 」
```

Fill the Plain Text Pairs into 2x1. Then change into corresponding number

```
⌈ S ⌉ ⌈ O ⌉ ⌈ T ⌉ ⌈ X ⌉ ⌈ M ⌉ ⌈ L ⌉ 
⌊ H 」⌊ R 」⌊ E 」⌊ A 」⌊ P 」⌊ E 」
 ↓     ↓    ↓    ↓     ↓    ↓
⌈ 18 ⌉ ⌈ 14 ⌉ ⌈ 19 ⌉ ⌈ 23 ⌉ ⌈ 12 ⌉ ⌈ 11 ⌉ 
⌊  7 」⌊ 17 」⌊  4 」⌊  0 」⌊ 15 」⌊  4 」		
```

#### C = KPmod26

Change is Plaintext number Matrix to `[P]` Pair to `[KP]` and then convert to corresponding digit to Alphabets.

Encrypt: C = K x P

```
⌈ 18 ⌉ ->  ⌈  7  8 ⌉ X ⌈ 18 ⌉  mod26 = ⌈  7*18  8*7 ⌉ = ⌈ 182 mod 26 ⌉ = ⌈ 0  ⌉ = ⌈ A ⌉
⌊  7 」    ⌊ 11 11 」  ⌊  7 」         ⌊ 11*18 11*7 」  ⌊ 275 mod 26」   ⌊ 15 」  ⌊ P 」
```

Similarly

```
⌈ 14 ⌉ ->  ⌈ A ⌉ 
⌊ 17 」    ⌊ D 」

⌈ 19 ⌉ ->  ⌈ J ⌉ 
⌊  4 」    ⌊ T 」

⌈ 23 ⌉ ->  ⌈ F ⌉ 
⌊  0 」    ⌊ T 」

⌈ 12 ⌉ ->  ⌈ W ⌉ 
⌊ 15 」    ⌊ L 」

⌈ 11 ⌉ ->  ⌈ F ⌉ 
⌊ 4  」    ⌊ J 」
```

The Cipher Text

```
⌈ A ⌉ ⌈ A ⌉ ⌈ J ⌉ ⌈ F ⌉ ⌈ W ⌉ ⌈ F ⌉ 
⌊ P 」⌊ D 」⌊ T 」⌊ T 」⌊ L 」⌊ J 」
```

Cipher text : A P A D J T F T W L F J

Decrypt : P = C$K^{-1}$

```
1 2  = K
3 4

Determinat = 4*1-3*2

4 -2
-3 1  X Determinant = K^-1
```

## [One Time Pad (Vernam Cipher) Encryption Explained with Solved Example in Hindi](https://youtu.be/VFMSnDZ7FEI)

A=0, B=1.... Z=25

Key rule : the length of key should be same as length of plaintext, with random alphabets.

Encryption : `C=(P+K) mod 26`

```
Plain Text:     H  E  L  L  O
                7  4 11 11  14
                      +
Key :           b  a  x  y  c
                1  0  23 24 2

Add(P+K):        8  4  34 35 16

Subtract(-26):   8  4  8  9  16   (-26 if (K+P>26)) 
Ciphertext :     i  e  i  j  q
```

## [One Time Pad Cipher Decryption Explained With Example in Hindi l Information and Cyber Security](https://youtu.be/rlrpcNYNPBY)

Decryption `P=(C-K)mod26`

```
Ciphertext :    i  e  i  j  q
                8  4  8  9  16

Key :           b   a   x   y   c
                1   0   23  24  2

Subtract(C-K)   7  4  -15  -15  14

Add(+26) :      7  4   11   11  14   (+26 if (C-K<0))
Cipher Text:    H  E   L    L   O

```

## [Monoalphabetic Cipher](https://youtu.be/J-utjSeUq_c)

## [Polyalphabetic Cipher (Vigenère Cipher)](https://youtu.be/Ic4BzVggNY8)

## Transposition Cypher

## [Rail Fence Technique](https://youtu.be/knE4G8DGLoY)

* The simplest Transposition Cipher is the rail fence Cipher
* In Rail Fence Technique, The plaintext is written down as a sequence of diagonals and then read off as a sequence of rows.

Example: Plain text : `neso academy is the best` Depth : `2`

```
|n| |s| |a| |a| |e| |y| |s| |h| |b| |s| | -> NSAAEYSHBS
| |e| |o| |c| |d| |m| |i| |t| |e| |e| |t| -> EOCDMITEET

NSAAEYSHBSN+EOCDMITEET
Ciphertext: NSAAEYSHBSEOCDMITEET
```

Plaintext : `Thankyou very much` Depth : `3`

```
|T| | | |k| | | |v| | | |m| | | | -> TKVM
| |h| |n| |y| |u| |e| |y| |u| |h| -> HNYUEYUH
| | |a| | | |o| | | |r| | | |c| | -> AORC

TKCM+HNYUEYUH+AORC
Ciphertext: TKCMHNYUEYUHAORC
```

## [Row Column Transposition Ciphering Technique](https://youtu.be/cPQXaYUMOjQ)

Row Column Transposition / Columnar Transposition

* A more complex scheme than Rail fence
* Rectangle
* Row and Column of Rectangle decided by Sender and Receiver
* Write : Row-by-Row
* Read : Column-by-Column
* Key : Order of the column

Example: Plaintext : `Kill Corona Virus at twelve am tomorrow` Key : `4312567`

```
- let 5 row and 6 column rectangle
- Fill row by row

|K|i|l|l|c|o|r|
|o|n|a|v|i|r|u|
|s|a|t|t|w|e|l|
|v|e|a|m|t|o|m|
|o|r|r|o|w| | |

- fill random symbols in empty cell

 4 3 1 2 5 6 7    <- KEY
|K|i|l|l|c|o|r|   <- Plaintext (input)
|o|n|a|v|i|r|u|
|s|a|t|t|w|e|l|
|v|e|a|m|t|o|m|
|o|r|r|o|w|y|z|

1 -> LATAR
2 -> LVTMO
3 -> INAER
4 -> KOSVO
5 -> CIWTW
6 -> OREOY
7 -> RULMZ

LATAR+LVTMO+INAER+KOSVO+CIWTW+OREOY+RULMZ
Cipher Text: LATARLVTMOINAERKOSVOCIWTWOREOYRULMZ
```

To make the scheme more complex one, take the cipher text and pass this cipher text to the process again

```
- Cipher Text 1

 4 3 1 2 5 6 7    <- KEY
|L|A|T|A|R|L|V|   <- Cipher text 1(input)
|T|M|O|I|N|A|E|
|R|K|O|S|V|O|C|
|I|W|T|W|O|R|E|
|O|Y|R|U|L|M|z|

1 -> TOOTR
2 -> AISWU
3 -> AMKWY
4 -> lTRIO
5 -> RNVOL
6 -> LAORM
7 -> VECEZ

TOOTR+AISWU+AMKWY+lTRIO+RNVOL+LAORM+VECEZ
Cipher Text: TOOTRAISWUAMKWYlTRIORNVOLLAORMVECEZ
```

## [Feistel Cipher Explained in Hindi ll Information and Cyber Security Course](https://youtu.be/uVeChiA_yv0) ❓

### Feistel Cipher

```
				 [Plaintext Block]
			    ⤷   L           R ⤶
				⌈   ↓           ↓  ⌉
			R1	∣   ⊕← F(K,R)  ↓   ∣  K1
				⌊   ↓           ↓  ⌋
				    ↘         ↙
			  	         ⤩
			  		 ↙       ↘
				    L         R  
				⌈   ↓          ↓  ⌉
			R2	∣   ⊕← F(K,R) ↓   ∣ K2
				⌊   ↓          ↓   ⌋
			        .          .
			        .          .
			        .          .  
				    ↘         ↙
			  	         ⤩
			  		 ↙       ↘
				   L          R 
				⌈   ↓          ↓  ⌉
		Rn  	∣   ⊕← F(K,R) ↓   ∣ Kn
				⌊   ↓          ↓   ⌋
				    ↘         ↙
			  	         ⤩
			  		 ↙       ↘
			         ↓        ↓ 
				 [Ciphertext Block]
```

Feistel Cipher model is a structure or a design used to develop many block ciphers such as DES. Feistel cipher may have invertible, non-invertible and self invertible components in its design. Same encryption as well as decryption algorithm is used. A separate key is used for each round. However same round keys are used for encryption as well as decryption. \
&#x20;

### Feistel cipher algorithm

* Create a list of all the Plain Text characters.  &#x20;
* Convert the Plain Text to Ascii and then 8-bit binary format.  &#x20;
* Divide the binary Plain Text string into two halves: left half (L1)and right half (R1)&#x20;
* Generate a random binary keys (K1 and K2) of length equal to the half the length of the Plain Text for the two rounds.&#x20;

Generally there are 16 rounds. &#x20;

First Round of Encryption&#x20;

```
1. Generate function f1 using R1 and K1 as follows:
f1= xor(R1, K1)

2. Now the new left half(L2) and right half(R2) after round 1 are as follows:
R2= xor(f1, L1)
L2=R1
```

Second Round of Encryption&#x20;

```
1. Generate function f2 using R2 and K2 as follows:  
f2= xor(R2, K2)

2. left half(L3) and right half(R3) after round 2 are as follows:
R3= xor(f2, L2)
L3=R2

3. Concatenation of R3 to L3 is the Cipher Text
- Same algorithm is used for decryption to retrieve the Plain Text from the Cipher Text.
```

**Examples:**&#x20;

```
Plain Text is: Hello
Cipher Text:  E1!w(
Retrieved Plain Text is:  b'Hello'

Plain Text is: Geeks
Cipher Text: O;Q
Retrieved Plain Text is:  b'Geeks'
```

## [Feistel Cipher Structure](https://youtu.be/8l9xAvuGJFo)

#### Encryption

![](https://www.tokenex.com/wp-content/uploads/2022/09/22-Feistel-Cipher-01-606x779.png)

#### Decryption

![](https://www.tokenex.com/wp-content/uploads/2022/09/22-Feistel-Cipher-Decrypt-02-02-606x779.png)

**Fiestel Structure Design Features**

* Block Size - Fiestal structure is a block cipher not a stream cypher , where group of bits are given as input
  * let's say if it is 64 bits the the block size is of 64. Input block size? output block size?
  * The DES (Data encryption standard) algorithm uses 64 bits block size and AES (Advance encryption standard) uses 128 bit block size.
  * AES - most popular algorithm that we are using in today's contemporary and secured world. Many Feature of AES are still unbreakable, that's why it widely used.
  * DES - Outdated! no more in use because it can be easily hacked
* Key Size - For n rounds, we need n keys. All round keys are generated from the original What is the original key size? round key size?
  * For greater security we need bigger key size but unfortunately it may decrease the encryption and decryption speed, we need high speed also. more time for encryption and decryption obviously we will not prefer such algorithm/block cypher algorithms. at the same time if the key size is smaller, it will be vulnerable to brute force attack and it le to lesser confusion.
  * From Fiestel cypher we need greater confusion, diffusion and high security
* Number of Rounds - If there is one round, it can be easily broken. How many rounds?? we need to carry out in order to gerater the cypher text.
  * for Encryption there are `16`rounds, and obviously we need `16` for decryption, because it is a symmetric encryption model. (Same key is used for encryption and decryption). The only difference is the order of usage, so the real security relies in the number of rounds.
* Subkey generation algorithm - we need subkey generation algorithm to generate round keys from original keys. If the key size is great it will be difficult to break, so key should also have greater complexity
* Round Function(F) - We need some complex design in there round function for better confusion and diffusion. that is complex design
* Fast Encryption/Decryption Algorithm - In most of the cases, encryption is actually a part of the application or in hardware. so wee need this to be carried out as fast as it should be be, because ultimately we are going to transfer the data.
* Ease of Analysis - In crypt analyst perspective, it should not be easy for them to analyze what is happening in the entire process

## [Introduction to Data Encryption Standard (DES)](https://youtu.be/j53iXhTSi_s?list=PLBlnK6fEyqRiOCCDSdi6Ok_8PU2f_nkuf)

#### Data Encryption Standard

* Symmetric Block Cipher
* A.k.a Data Encryption Algorithm
* Adopted by NIST in 1977
* Advanced Encryption Standard (AES) in 2001
* Input : 64 bits.
* Output : 64 bits
* Main Key : 64 bits.
* Subkey : 56 bits.
* Round Key : 48 bits.
* No. of rounds : 16 rounds.

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_b0143080-68a6-4966-8603-415f230d1fdc.jpeg)

## [Single Round of DES Algorithm](https://youtu.be/nynAQ593HdU?list=PLBlnK6fEyqRiOCCDSdi6Ok_8PU2f_nkuf)

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_3a15f9be-5a99-42a6-884a-f08c5c7be5e3.jpeg)

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_308901d2-ad6d-4461-82f7-185cf8eb7273.jpeg)

![](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_cf3a3a89-d5d4-439e-b512-1239c307eb7d.jpeg)

## AES

## [Rings, Fields and Finite Fields](https://youtu.be/oBL-Cb5GxA0)

#### Group and Abelian Group

**Group: Group satisfied the Properties**

A1- Closure : $a,b \in G$ then $(a●b) \in G$ A2- Associative : $a●(b●c)=(a●b)●c$ for all $a, b, c \in G$ A3- Identity element : $(a●e)=(e●a)=a$ for all $a,e \in G$ A4- Inverse element : $(a●a')=(a'●a)=e$ for all $a, a' \in G$

**Abelian Group: Group with Commutative Property**

A5- Commutative : $(a●b)=(b●a)$ for all $a, a' \in G$

#### Rings

A ring `R` denoted by `{R,+,*}` is a set of elements with two binary operations, called addition and multiplication, such that for all c = a●b, `a, b, c ∈ R` the followoing axioms are obeyed:

* R is an Abelian Group(A1-A5) with respect to Addition
* Closure under Multiplication (M1) 🤷??? this is not obvious if it is a group
* Associativity of Multiplication (M2) 🤷??? this is not obvious if it is a group
* Distributive laws (M3):
* $a.(b+c)= a.b +a.c$ for all $a, b, c ∈ R$
* $(a+b).c= a.c +b.c$ for all $a, b, c ∈ R$

Note:- Associative have only one operation `Multiplication or Addition` Distributive have both operations `Addition and Multiplication`

_Note:_ as we have only `+` and `*` operation, we considered equations `a-b` as : `a+(-b)` where `a and (-b) ∈ R`. (`-b` belongs to `R` because it is inverse element of `b` where `b∈R`)

#### Commutative Rings

A ring is said to be commutative, if it satisfies the additional condition

* Commutative of Multiplication (M4): $ab=ba$ for all $a, b \in R$

#### Integral Domain

An integral domain is a commutative ring that obeys the following axiom. its mean integral domain is already in commutative ring.

* Multiplicative Identity (M5): There is an element `1∈R` such that `a1 = 1a = a` for all \`a∈R
* No zero divisor (M6): If a, b ∈ R and ab=0, then either a=0 or b=0 \`

Group - A1-A4 Abelian Group = Group + Commutative (A5)

Ring = Addition(A1-A5) + Closure, Associative, Distributive (M1-M3) Commutative = Ring + Commutative of Multiplication (M4) Integral Domain = Commutative Ring + Axioms

#### Field

A field F, sometimes denoted by `{F,+,*}` is a set of elements with two binary operations, called addition and multiplication, such that for all a, b, c ∈ F the following axioms are obeyed.

* (A1-M6): F is an integral domain; that is F satisfies axioms A1-A5 and M1-M6.
* (M7) Multiplicative inverse: For each a in F, except 0, there is an element $a^{-1}$ in F such that $aa^{-1} = (a^{-1})a$

Note: $a/b = a(b^{-1})$

Example of Fields:

* Rational numbers
* Real numbers
* Complex numbers

![Groups, Rings and Fields](https://storage.googleapis.com/askify-screenshot/80s40bjtPRfJdbBekhl200tg7Et2/extension_screenshots/screenshot_default_974a00c8-90a6-4871-b6b9-0a96e39f9e43.jpeg)

#### Finite Fields

A finite field or Galois field (so-named in honor of Evariste Galois) is a field that contains a finite number of elements.

* As with any field, a finite field is a set on which the operation of multiplication, addition, subtraction and division are defined and satisfy certain basic rules.
* The most common examples of finite fields are given by the integer `(mod p)` when p is a prime number

Application areas:

* Mathematics and computer science - Number theory, Algebraic geometry, Galois theory, Finite geometry, Cryptography and Coding theory.
