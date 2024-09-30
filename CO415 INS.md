
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
### DES (Data Encryption Standard) . 
- `block size` of plain and Cipher text = `64 bits`.
- `Key size` adopted = `56 bits`.


# [Caesar Cipher Explained with Solved Example ll Information and Cyber Security Course in Hindi](https://youtu.be/euVke4djgDg)


### Substitution Cypher Technique
- Cypher Text Conversion Method: 
- Substitute each alphabet with different alphabet
- Ex: Caesar Cipher (Easiest Method of substitution)

### Caesar Cipher 

*Note:* we will use lowercase alphabets for cipher text, and upper text for plain text, to differentiate between them.
```
Plain Text Alphabets :- A B C D E  F G H I J K L M N O P Q R S T U V W X Y Z
Cipher Text Alphabets:- d e f g h i j k l m n o p q r s t u v w x y z a b c

A(a), B(b), ..... Z(z)
 0      1   ...... 25
```

##### Encryption Function: `C = E(3,P)=(P+3)mod26`
- E: Encryption, P: plain text, C: cipher text

Ex: let P='A'
	C = E(3, P) = ( P+3) => ('A' + 3)%26 => (0+3)%26 => (3) = ('D')
	- Significance: Each Character Shifted by 3 
	- It is a kind of mapping function

Example of Message
```
Plain Text: FIVE MINUTES ENGINEERING
Cipher text: ilyh plqxwhv hgjlqhhulgj
```

how to decrypt??
##### Decryption Function: `C = D(3,C)=(C-3)mod26`
- E: Encryption, P: plain text, C: cipher text


# [Shannon's theory of Confusion and Diffusion | Cryptography and Network Security](https://youtu.be/3NpRhXWWWMQ)

## Shannon's Theory of confusion and Diffusion 

1. The terms confusion and diffusion were introduced by ~ *Claude Shannon*.
2. Shannon's concern was to prevent crypt analysis, based on statistical analysis. The reason is as follows.

	Assume attacker has some knowledge of the statistical characteristics of the plaintext (eg:- in a Msg, the frequency distribution of the various letters may be known.)
	If these statistics are in any way reflected in ciphertext, the cryptanalysis i.e. attacker may be able to deduce the encryption key.

The Shannon's suggested 2 Methods for frustrating the attackers:
**Confusion  & Diffusion :**  Properties for creating a secure Cipher

##### 1. DIFFUSION:
If a symbol in the plaintext is changed, several or all symbols in the ciphertext will also change.
- The Idea of diffusion is to hide the relationship between the `ciphertext` and `plaintext`.

> Wikipedia : Diffusion means that if we change a single bit of the plaintext, then (statically) half of the bits in the ciphertext should change, similarly, if we change 1  bit of ciphertext, then at least one half of the plaintext bits should change.

Diffusion implies that each symbol in the 'ciphertext; is depend on source or all the symbols in the 'plain text'
#### 2. CONFUSION:
If a single bit in the key is changed then most/all bits of the ciphertext will also be changed.
- It hides the relationship between ciphertext and key

> Wikipedia : Confusion means that each bit of the ciphertext should depend on several parts of the key, obscuring (make unclear or difficult to understand) the connection between the two.

In short,
**Diffusion:-** Make statistical relation between `plaintext and ciphertext` as complex as possible.
- if change 1 bit of plain text then half or more bits of cipher should change
- i.e. if we change a single bit of the Plain text then half of the bits in the Cipher text should change and vice versa.

**Confusion:-** Make relation between `key and cipher text` as complex as possible
- each bit of ciphertext should depend on `key`
- changing one bit of the key should change the cipher text completely

# [PlayFair Cipher ll Basics Of Playfair Cipher Explained with Solved Example in Hindi](https://youtu.be/jS8u6bX6Xi4)

let
Message: Jazz
Keyword: Monarchy

Make a table 5x5

Fill the Cells Keyword from left to right.
M, O, N, A, R, C, H, Y

Fill the remaining cells sequentially with 
alphabets that not counted in keyword.
(fill i & j in one cell because there are 25 cells while alphabets are 26)
b, d, e, f, g, i/j , k, l, p, q, s, t, u, v, w, x, z

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
``
Plain Text : Jazz
Pair them in two, there should not be repetition of character in pair (if we choose on alphabet, and next alphabet is same, than take extra 'x' to make its pair) 
If there are no pair for last alphabet, add x

JA    Z     Z
↓      ↓      ↓
JA   ZX   ZX
ㅡ   ㅡ    ㅡ 

Now Check for Each Alphabets in The table, Pair wise.

Rules: 
1. If the pairs lie in same column -> then substitute the alphabets with there immediate down alphabet (last immediate's down will be first)
	eg. JA->SB : j->s, a->b
	
2. If the pairs lie in same row -> then take immediate right (Last immediate right  will be first)
	eg. ZX->UZ: z->u, x->z

3. If the pairs don't lie in same row and column, Make a rectangle ,consider the pair cells as two corner of the rectangle, and find out two other corner. the new corner cell/Alphabet will be substite the previous one with the same row.
	eg. FX-IV> f->i/j, x->v
		retcangle:
		F - i/j
		v - x
	Note: you can choose i or j any one, from i/j cell


JA   ZX  ZX
 ↓     ↓    ↓
SB   UZ  UZ
ㅡ   ㅡ    ㅡ


More Ex:

Plain Text: GREET
GR  EX  EX  TX
ㅡ   ㅡ   ㅡ   ㅡ

Plain Text: OFF
OF   F
 ↓     ↓
OF  FX
↓      ↓
HP  IV
ㅡ   ㅡ

# [Hill Cipher Encryption Explained in Detail with Solved Example in Hindi](https://youtu.be/xv5lwFxxUw0)

Key = HILL
Plain Text (Message) = Short Example

Consider A =0, B=1...  Z=25

Fill the Keyword into 2x2 matrix. Then change into corresponding number
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

### C = KPmode26

Change is Plaintext number Matrix to  `[P]` Pair to `[KP]` and then convert to corresponding digit to Alphabets.

```
⌈ 18 ⌉ ->  ⌈  7  8 ⌉ X ⌈ 18 ⌉ = ⌈  7*18  8*7 ⌉ = ⌈ 182 mod 26 ⌉ = ⌈ 0  ⌉ = ⌈ A ⌉
⌊  7 」    ⌊ 11 11 」  ⌊  7 」  ⌊ 11*18 11*7 」  ⌊ 275 mod 26」  ⌊ 15 」  ⌊ P 」
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


# [One Time Pad (Vernam Cipher) Encryption Explained with Solved Example in Hindi](https://youtu.be/VFMSnDZ7FEI)

A=0, B=1.... Z=25

Key rule : the length of key should be same as length of plaintext, with random alphabets.

Encryption : `C=P(P+K) mod 26`
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

# [One Time Pad Cipher Decryption Explained With Example in Hindi l Information and Cyber Security](https://youtu.be/rlrpcNYNPBY)

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

# [Feistel Cipher Explained in Hindi ll Information and Cyber Security Course](https://youtu.be/uVeChiA_yv0) ❓

## Feistel Cipher

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


Feistel Cipher model is a structure or a design used to develop many block ciphers such as DES. Feistel cipher may have invertible, non-invertible and self invertible components in its design. Same encryption as well as decryption algorithm is used. A separate key is used for each round. However same round keys are used for encryption as well as decryption.   
 

## Feistel cipher algorithm

- Create a list of all the Plain Text characters.    
- Convert the Plain Text to Ascii and then 8-bit binary format.    
- Divide the binary Plain Text string into two halves: left half (L1)and right half (R1)   
- Generate a random binary keys (K1 and K2) of length equal to the half the length of the Plain Text for the two rounds.   
     

First Round of Encryption 
```
1. Generate function f1 using R1 and K1 as follows:
f1= xor(R1, K1)

2. Now the new left half(L2) and right half(R2) after round 1 are as follows:
R2= xor(f1, L1)
L2=R1
```

Second Round of Encryption  
```
1. Generate function f2 using R2 and K2 as follows:  
f2= xor(R2, K2)

2. left half(L3) and right half(R3) after round 2 are as follows:
R3= xor(f2, L2)
L3=R2

3. Concatenation of R3 to L3 is the Cipher Text
- Same algorithm is used for decryption to retrieve the Plain Text from the Cipher Text.
```

**Examples:** 
```
Plain Text is: Hello
Cipher Text:  E1!w(
Retrieved Plain Text is:  b'Hello'

Plain Text is: Geeks
Cipher Text: O;Q
Retrieved Plain Text is:  b'Geeks'
```
