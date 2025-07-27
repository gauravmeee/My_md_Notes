
1. **Coding-Decoding**
	- **Trick:** Find the difference between positions of letters.
	- Ex: A (1) → D (4) → +3  
	    Use **common patterns**: +1, -1, reverse order, or pair logic.

2. **Syllogism**
	- **Trick:** Use **Venn Diagrams**.  
	    Don’t rely on logic, draw and confirm with diagram.
    
3. **Statement-Conclusion**
	- **Trick:** Focus only on what is given, avoid assumptions.  
	    Try **Elimination method**.
    
4. **Calendar Problems**
	- **Trick:** Use **odd days** rule and **Doom’s Day** concept.  
	    Memorize:
	    - Jan 1, 1900 = Monday
	    - 100 years = 5 odd days
        
---
### Alphabet Coding - Decoding


**1. Alphabet Coding (A=1, B=2...)**

| A   | B      | C      | D   | E      |
| --- | ------ | ------ | --- | ------ |
| 01  | ==02== | ==03== | 04  | ==05== |

| F   | G      | H      | I   | J      |
| --- | ------ | ------ | --- | ------ |
| 06  | ==07== | ==08== | 09  | ==10== |

| K   | L      | M      | N   | O      |
| --- | ------ | ------ | --- | ------ |
| 11  | ==12== | ==13== | 14  | ==15== |

| P   | Q      | R      | S   | T      |
| --- | ------ | ------ | --- | ------ |
| 16  | ==17== | ==18== | 19  | ==20== |

| U   | V      | W      | X   | Y      |
| --- | ------ | ------ | --- | ------ |
| 21  | ==22== | ==23== | 24  | ==25== |

| Z   |
| --- |
| 26  |

**2. Alphabet Opposites Table (A↔Z, B↔Y...)**

| ==01== ⭢ | ==02== ⭢ | ==03== ⭢ | ==04== ⭢ | ==05== ⭢ | ==06== ⭢ | ==07== ⭢ | ==08== ⭢ | ==09== ⭢ | ==10== ⭢ | ==11== ⭢ | ==12== ⭢ | ==13== ⭢ |
| -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| A        | B        | C        | D        | E        | F        | G        | H        | I        | J        | K        | L        | M  ↓     |
| Z        | Y        | X        | W        | V        | U        | T        | S        | R        | Q        | P        | O        | N  ↓     |
| ==26== ⭠ | ==25== ⭠ | ==24== ⭠ | ==23== ⭠ | ==22== ⭠ | ==21== ⭠ | ==20== ⭠ | ==19== ⭠ | ==18== ⭠ | ==17== ⭠ | ==16== ⭠ | ==15== ⭠ | ==14== ⭠ |

---
### Day in Calendar

**1. Month Code Table (for Calendar Questions)**

| Month     | Code |
|-----------|------|
| Jan       | 0    |
| Feb       | 3    |
| Mar       | 3    |
| Apr       | 6    |
| May       | 1    |
| Jun       | 4    |
| Jul       | 6    |
| Aug       | 2    |
| Sep       | 5    |
| Oct       | 0    |
| Nov       | 3    |
| Dec       | 5    |

**2. Century Codes (Important to Memorize)**

| Century | Code |
|---------|------|
| 1600    | 6    |
| 1700    | 4    |
| 1800    | 2    |
| 1900    | 0    |
| 2000    | 6    |
| 2100    | 4    |

**Use of Month Code (Odd Days Method)**

- **Formula To find the day of the week for any date:**
```sql
Day = (Last 2 digits of year + (year/4) + Date + Month Code + Century Code) % 7
```

- **Example: `15 August 1947`**
```sql
Step 1: Last 2 digits of year = 47
Step 2: 47/4 = 11 (ignore remainder)
Step 3: Date = 15
Step 4: Month Code for August = 2
Step 5: Century Code for 1900s = 0

Add: 47 + 11 + 15 + 2 + 0 = 75

75 % 7 = 5 → Friday
```

---
### Number-Square-Cube Table (1–20)

| Num | Sq  | Cube |
| --- | --- | ---- |
| 1   | 1   | 1    |
| 2   | 4   | 8    |
| 3   | 9   | 27   |
| 4   | 16  | 64   |
| 5   | 25  | 125  |
| 6   | 36  | 216  |
| 7   | 49  | 343  |
| 8   | 64  | 512  |
| 9   | 81  | 729  |
| 10  | 100 | 1000 |
| 11  | 121 | 1331 |
| 12  | 144 | 1728 |
| 13  | 169 | 2197 |
| 14  | 196 | 2744 |
| 15  | 225 | 3375 |
| 16  | 256 | 4096 |
| 17  | 289 | 4913 |
| 18  | 324 | 5832 |
| 19  | 361 | 6859 |
| 20  | 400 | 8000 |

---
### Clock Angle Quick Formula

```sql
Angle = |(30×H - (11×M)/2)|
```
- E.g. : 3:30 → `|(30×3 - 11×30/2)|` = |90 - 165| = 75°

**Proof :**
1. **Angle moved by hour hand**
	- The hour hand moves **30° per hour** (360° / 12).
	- It also moves **0.5° per minute** (30° / 60).
	- **Hour angle = `30 × H + 0.5 × M`**
	
2. **Angle moved by minute hand**
	- The minute hand moves **6° per minute** (360° / 60).
	- **Minute angle = `6 × M`**

3. **Angle between both hands**
	- **Angle** = Hour angle - Minute angle
	- **Angle** = `30H + 0.5M - 6M` 
	- **Angle** = `30H - 5.5M`
	- **Angle** = `30H - 11M/2`

---

