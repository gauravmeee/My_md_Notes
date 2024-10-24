

---
# Keyence

#### Q. There are five boys, A, B, C, D, and E, who are running a marathon in a single file. At a particular point in the race, the following was observed. A is running next to B, but B's position is not adjacent to C. D is running adjacent to E, who is running at the front of the file. C's position is not adjacent to B, who is running beside E. Give there position
Ans: EDBAC

.... -> means more boys may place between them
x -> means more boys must place between tem

1. A is running next to B :
	A and B are front and behind -> ...AB... , or ...BA...
	
2. B's position is not adjacent to C :
	B and C are not at same position-> ...BxC... and ...CxB... 
	
3. D is running adjacent to E, who is running at the front of the file.:
	E(front of file) , D(Adjacent and same position at E) ->   ED......
	
4. C's position is not adjacent to B, who is running beside E. -> ED
	B(behind E, also behind D because E and D are adjacent) -> EDB...

from the 4 , conlcude -> EDBAC


#### Q. A gardener sold roses at 20% profit if she had sold them at 5 /4 times the selling price. What would be the percentage of profit?
Ans: 50% 

Cost price : x
Sell price(20% more): 1.2x
if he sold 5/4 x time of selling price = 1.2x * 5/4 = 1.5x

profit = (final sell price - cost price )*100 / Cost price 
	 = (1.5x - x)*100 / x = 
	 = 0.5x * 100 / x
	 = 50 %

#### Q. In April, Jack anticipated received a 10% raise on the regular monthly income, but instead received a $360 raise, which was only 40% of the raise he had anticipated, which was Jack's regular monthly income before the raise.
Ans : $900

monthly income = x
Anticipated raise = x * 10/100 = 0.1x
0.1x * 40/100 = 360
0.04x = 360
x = 900


#### Q. A man sells a pen at 20% profit and a pencil at 33.33% profit. The selling price of pen is thrice that of the pencil. If the selling price of the pen and the pencil are interchanged, what would be the profit percentage in selling one pencil?

Ans : 300%


Cost of Pen = Cpen
Cost of Pencil = Cpencil

Sell price of Pen = Spen = 1.2Cpen
Sell price of Penicil = 1.3333 Cpencil

Spen = 3 * Spencil

SPen and SPencil Interchanged

Spen = 1.3333 Cpencil
Spencil = 1.2Cpen = 3 * 1.3333 Cpencil = 4 Cpencil

Profit = (Spencil-Cpencil)/Cpencil * 100 =  (4* Cpencil-Cpencil)/(Cpencil) * 100 = 3* 100 = 300 

---

# Reliance

#### Q. A + B' means A is the daughter of B'. A $ B' means 'A is the husband of B'. A@B' means A is the brother of B'. 'A & B' means 'A is the mother of B'. A % B' means A is the son of B'. If 'W @ S % K $ G & U & T @ R + C, then which of the following statements is correct?

1. G is the father of W.  ❌ G is Female, because G is  mother of  U
2. G is the maternal grandmother of R.  ✅ G is Maternal Grandmother of T, and T and R are brother
3. C is the father-in-law of K.   ❌ No mention of C
4. C is the wife of U. ❌ No mention of C

A+B: A is daughter of B
A$B: A is husband of B
A@B: A is brother of B
A&B: A is mother of B
A%B: A is son of B

W@S%K$G&U&T@R+C

```
W <-- brother of -- S
S <-- son of -- K
K <-- husband of -- G
G <-- mother of -- U
U <-- mother of -- T
T <-- Brother of -- R
R <-- Daughter of -- C
```

#### what should be come next 91 131 99 147 126 228 190 484 315? 
Ans: 1109

```
	(2^3)    (3^3)      (4^3)      (5^3) 
     +8       +27        +64       +125
91   ->   99   ->    126   ->   190   ->   315

↑          ↑          ↑           ↑          ↑
91  131   99   147   126   228   190  484   315    ??
     ↓          ↓           ↓          ↓           ↓
     
    131   ->   147   ->    228   ->   484   -> ?  1109 ✅
        +16        +81         +256       +625✅
       (4^2)      (9^2)       (16^2)     (25^2)
```

↑↓