
# [# L-4.2: Pipelining Introduction and structure | Computer Organisation](https://youtu.be/nv0yAm5gc-E)


**Definition of Pipelining**
- Pipelining is the Process of arrangement of hardware elements of CPU such that Hs Overall Performance is increased
- Simultaneous execution of more than one instructor takes place in pipelined processor
- In pipelining multiple instructions are overlapped in execution
- Example – Reduced Instruction Set (RISC) Pipeline
```
                     
      Stage/Segment       Interface Register (IR)
        /                  /
Input  /   R1          R2 /          R3           R4
  ┌─────┐ ┌─┐  ┌─────┐ ┌─┐  ┌─────┐ ┌─┐  ┌─────┐ ┌─┐
->│ S1  │-│ │->│ S2  │-│ │->│ S3  │-│ │->│ Sn  │-│ │->
  └─────┘ └─┘  └─────┘ └─┘  └─────┘ └─┘  └─────┘ └─┘
    └──────┴──────┴─────┴──────┴─────┴──────┴─────┴ Clock
```

- **IR (Interface Register)**: Latches placed **after each stage** to store intermediate results between stages.
- They isolate stages so each can work in parallel during the same clock cycle.
- Common in **RISC architectures** to achieve high instruction throughput.
- **Clock Pulse**: Synchronizes all pipeline stages so each stage starts its operation at the same time. On each clock edge, IRs transfer stored data to the next stage, enabling overlapped execution of multiple instructions.

**Standard:**
- In a pipeline, the **registers (pipeline registers)** are placed **after each stage**, not before.
- **S1 → R1 → S2 → R2 → S3 → R3 → Sn → Rn**
- Each **R** stores the output of the previous stage so that the next stage can work on it in the next clock cycle.
- This ensures all stages operate in parallel without interfering.



**Common Pipeline Stage Configurations**

- **3-stage pipeline** (simple microcontrollers, early ARM)
    1. IF – Instruction Fetch
    2. ID/EX – Instruction Decode + Execute (combined)
    3. WB – Write Back 
        
- **4-stage pipeline** (basic processors)
    1. IF – Instruction Fetch
    2. ID – Instruction Decode & Register Fetch
    3. EX – Execute / Memory Address Calculation ➕
    4. WB – Write Back
        
- **5-stage pipeline** (classic RISC)
    
    1. IF – Instruction Fetch
    2. ID – Instruction Decode / Register Fetch
    3. EX – Execute / Address Calculation
    4. MEM – Memory Access ➕
    5. WB – Write Back
        
- **6-stage pipeline** (higher clock speed)
    1. IF – Instruction Fetch
    2. ID – Instruction Decode
    3. OF – Operand Fetch ➕
    4. EX – Execute
    5. MEM – Memory Access
    6. WB – Write Back
        
- **More than 6 stages** – Used in high-performance CPUs by splitting stages further (e.g., multiple fetch, decode, and execute phases).
    

---
# [L-4.3: Pipelining Vs Non-Pipelining | Instruction Execution | Speedup, Efficiency, Utilization | COA](https://youtu.be/R9s34-lnd9k)


5 Stages Pipeline (ex: RISE) :
- `S1` - (IF)  Instruction Fetch
- `S2` - (ID)  Instruction Decode
- `S3` - (EX)  Execute
- `S4` - (MEM)  Memory
- `S5` - (WB)  Write Back


**Given:** Program with `8` Instructions (`I1 to I8`)

> If for each Stage, time is not given , Consider **Uniform Clock Cycle** (Each Stage take 1 CC)

**Non Pipelined Architecture**
```
┌───┐
|   └──

1 Stage -> Take 1 CC (Clock Cycle) 

1 Instruction -> 5 Stages -> Take 5 CC
```

```
P = 8I , I1-I8


 S1  S2  S3  S4  S5  S6  S7  S8
┌───┬───┬───┬───┬───┬───┬───┬────┐
|I1 |I1 |I1 |I1 |I1 |I1 |I1 |I1  |
└───┴───┴───┴───┴───┴───┴───┴────┴→ Time
    1   2   3   4   5   6   7   8  

 S1  S2  S3  S4  S5  S6  S7  S8
┌───┬───┬───┬───┬───┬───┬───┬────┐
|I2 |I2 |I2 |I2 |I2 |I2 |I2 |I2  |
└───┴───┴───┴───┴───┴───┴───┴────┴→ Time
    9   10  11  12  13   14  15  16  

... and so I3, I4, I5, I6, I7, 

 S1  S2  S3  S4  S5  S6  S7  S8
┌───┬───┬───┬───┬───┬───┬───┬────┐
|I8 |I8 |I8 |I8 |I8 |I8 |I8 |I8  |
└───┴───┴───┴───┴───┴───┴───┴────┴→ Time
   33   34   35   36   37   38   39   40  

Total Time = 40 CC 
```

```
Formula:

No. of Instructions (N) = 8
No. of Stages (K) = 5
Time per Stage (T) = 1CC (Uniform)

Total Time = N x K x T⭐
		   = 8 x 5 x 1
		   = 40 CC  
```

**Pipelined Architecture**
```

Phase (Space) Time Diagram

P = 8I , I1-I8

   Stage
    ↑
    ├───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
S1  |I1 |I2 |I3 |I4 |I5 |I6 |I7 |I8 |   |   |   |   |
    ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
S2  |   |I1 |I2 |I3 |I4 |I5 |I6 |I7 |I8 |   |   |   |
    ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
S3  |   |   |I1 |I2 |I3 |I4 |I5 |I6 |I7 |I8 |   |   |  
    ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
S4  |   |   |   |I1 |I2 |I3 |I4 |I5 |I6 |I7 |I8 |   |
    ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
S5  |   |   |   |   |I1 |I2 |I3 |I4 |I5 |I6 |I7 |I8 |
    └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴─→ Time
       1   2   3   4   5   6   7   8   9  10  11  12
                  
    ╰-──-───-──-──-───-╯╰-─╯╰-─╯╰-─╯╰-─╯╰-─╯╰-─╯╰-─╯
          I1             I2  I3  I4  I5  I6  I7  I8

Total Time = 12 CC


I1 -> takes 5CC
I2 to I7 -> takes 1CC Each

So, 
1 Instruction take -> All stage x 1CC
N-1 Instruction take -> One Stage x 1 CC Each
```

```
Formula: 
No. of Instructions (N) = 8
No. of Stages (K) = 5
Time per Stage (T) = 1CC (Uniform)


Total Time = (1.K + (N-1).1)
		   = (K + N - 1)
		   = (5 + 8 - 1)
		   = 12 CC
```


```
Speedup = Non Pipeline / Pipeline
		= 40 CC / 12 CC = 3 (aprrox 3 x times)

Efficiency = Cells Utilised / Totan no. of Cells
		   = 40 / 60 
		   = 2/3
```

**Goal of Pipeline:** To make **Cycles Per Instruction (CPI) ≈ 1**

**CPI formula:**

$$CPI=\frac{\text{Total CPU Cycles}}{\text{Number of Instructions}}$$


- It’s practically not possible to achieve exactly 1 due to hazards and stalls.
    
- But theoretically, for ideal pipelining:
    - **Example 1:** No. of instructions = `8`, No. of stages = `12` → CPI > 1 because pipeline fill time dominates.
    - **Example 2:** No. of instructions = `1000`, No. of stages = `5` → Total cycles = `5 + (1000 - 1)` = `1004` ≈ `1000` → CPI ≈ 1.004 ≈ 1 for large instruction counts.


# [L-4.4: Stage Delay in Pipeline | Previous Year GATE Question | Computer Organisation & Architecture](https://youtu.be/-YtmPoGCdfM)

**Ques.** A 4-stage pipeline has stage delays as `150`, `120`, `160`, and `140` ns. Registers are used between stages and have a delay of `5` ns each. Assuming Const Clock rate, the total time taken to process `1000` data items on this pipeline will be?

**Theory **

- **This is 4 Stage pipeline**

- IR - If there is no uniform stage delay, then it is required to store Intermediate Result in Interface Register, because if one stage take more time than other, than there is speed mismatch and so we need the buffer

- Clock Pulse - Clock pusle is provide to each stage for work. Here we will asume constant clock rate, so will provide single clock pusle to all. so that all frequency will be same.
```   
      S1     R1     S2    R2    S3    R3     S4    R4
    ┌─────┐ ┌─┐  ┌─────┐ ┌─┐  ┌─────┐ ┌─┐  ┌─────┐ ┌─┐
  ->│ 150 │-│5│->│ 120 │-│5│->│ 160 │-│5│->│ 140 │-│5│->
    └─────┘ └─┘  └─────┘ └─┘  └─────┘ └─┘  └─────┘ └─┘
      └──────┴──────┴─────┴──────┴─────┴──────┴─────┴ Clock
```

- But here each stages require different time (delay) to perform

- So we need to choose Maximum Stage Delay because

**Solve**
```
Max Stage Delay  = 160 + 5 ns = 165 ns

so here, 1 Clock Cycle(CC) = 165 ns

Also, frequencey = 1/t = 1/165

here instructions/data to process = 1000

Pipeline: 
Total time = (K + N - 1) CC
		  = (4 + 1000 - 1) CC
		  = 1003 CC
		  = 1003 x 165 ns
		  = 165495 ns
		  = 165.495 us

```


# [Lec-10: Floating Point Representation with examples | Number System (Gate Smashers)](https://youtu.be/4gNs7B4ZTjc)

- **Fixed representation** -> has fixed number of bits for integer part and for fractional part.
- ex: `10.` or `10.0`, `.15` or `0.15` decimal point is to the extreme left or right

- **Floating point** -> refers to the fact that a number's radix point (decimal point, or, more commonly in computers, binary point) can "float"; that is, it can be placed anywhere relative to the significant digits of the number.
- ex: `5.5` Fraction point is floating

Floating Point is use to make Value Better Representative
#### Floating Point

`101.1` Binary => `2^2 + 2^0 + 2^(-1)` => `5.5` Decimal

Move binary point by `n` bit right =>  Multiply by`2^(-n)`
Move binary point by `n` bit left => Multiply by `2^n`


**Example** 
`101.1` 
Move floating point by one bit right  
`1011 * 2^(-1)` => `(2^3 + 2^1 + 2^0)` x `2^(-1)` => `101.1`


#### Normalization

**Explicit:** `(-1)^S x 0.M x 2^E` -> Binary point to the immediate left of Most Significant `1` Bit
- Ex : `101.1` =>`(-1)^0` x `.1011` x `2^3` 

**Implicit:** `(-1)^S x 1.M x 2^E` -> Binary point to the immediate right of Most Significant `1` Bit
- Ex : `-101.1` =>`(-1)^1` x `1.011` x `2^2` 

**IEEE 754 format** : Common structure in floating-point representation

`[ S | E | M ]`
- `S`  -> (Sign) -> 0(+), 1(-)   Always 1 bit
- `E` -> (Exponent) -> 2^`E`
- `M` -> (Mantissa) -> significant digits of the number (Represent Precision)


**Ques :**  Let `E` is of 4 bit , `M` is of 5 bit Represent `101.1`  Explicit in IEEE 754 format
**Ans** :  `101.1` -> `(-1)^0` x `.1011` x `2^3`
`E` -> `3` Decimal -> `11` binary -> `0011` (in 4 bit)
`M` -> `1011` binary -> `10110` (in 5 bit)
`[ S | E | M ]` => `[0 | 0011 | 10110 ]`

Note:  
- Without changing value, `0` can be added to the right most of a value after floating point, or left most of value before floating point
- In Mantissa `.10110` : `M[10110]` -> `.101100`: `M[101100]` , `0` bit are added to the right most as we can't add it to left most because in Mantissa format, `.` exist at leftmost

**Ques :**  Let `E` is of 4 bit , `M` is of 5 bit Represent `.0110`  Implicit in IEEE 754 format
**Ans** :  `.0110` -> `(-1)^0` x `1.10` x `2^(-2)`
`M` -> `1011` binary -> `10110` (in 5 bit)

**Negative E by 2's Complement**
 `E` -> `-2` Decimal -> Represent Negative by 2's complement -> 2's complement of (`2`) -> 2's complement of (`10`) -> 2's complement of (`0010`) (in 4 bit) -> `0010` + `1101`(one value less than max) + `1` -> `1110`
`[ S | E | M ]` => `[0 | 1110 | 10110 ]`

or 

**Negative E by Biasing**
`E` -> `-2` Decimal + Excess Code ( 4 bit ) -> `-2` + Excess Code ( `-2^(4-1)` to `2^(4-1)-1`) -> `-2` + Excess code (`-8` to `7`) -> `-2` + `8` (max abs value) -> `6` -> `0110`
`[ S | E | M ]` => `[0 | 0110 | 10110 ]`

#### Biasing

Formula to Get value back if Biasing done in format
=> `(-1)^S` x `0.M` x `2^[E-B]`

**Ques:** Find value of `[0 | 0110 | 10110 ]` if biasing was done on it.
**Ans:** `(-1)^0` x `0.10110` x `2^[6-8]`
