
Here’s a **detailed explanation** of each NIST statistical test you mentioned, with simple **examples** and **how to interpret** the results in the context of your File 1 (Original LEA) vs File 2 (LEA + S-box):

---

## 🔢 1. **Approximate Entropy Test**

- **Purpose**: Measures **repeating patterns** (frequency of m-bit patterns).
    
- **High value** = less predictability = more randomness.
    
- **Example**:  
    Sequence `10101010` has low entropy (repetitive)  
    Sequence `10111001` has higher entropy (less repetitive)
    
- **Result**:
    
    - File 1: 0.450521 ✅
        
    - File 2: 0.287752 ❌  
        🔎 **Interpretation**: File 1 has more unpredictability in m-bit patterns.
        

---

## 🟦 2. **Block Frequency Test**

- **Purpose**: Divides sequence into blocks and checks if 0s and 1s are uniformly distributed in each block.
    
- **High value** = more uniform distribution across blocks.
    
- **Example**:  
    Sequence: `000111000111` (not uniform)  
    Sequence: `010101101010` (more uniform)
    
- **Result**:
    
    - File 2 better ⇒ ✅  
        🔎 **Interpretation**: S-box increases uniformity of 1s/0s per block.
        

---

## ➕ 3. **Cumulative Sums Test**

- **Purpose**: Measures randomness by tracking cumulative sum of (+1/-1) from bit stream.
    
- **Looks for**: Sudden bias toward 1s or 0s.
    
- **Example**:  
    Sequence: `111000` → sum drifts, so less random  
    Sequence: `101010` → sum stays close to zero
    
- **Result**:
    
    - File 2 is better ⇒ ✅  
        🔎 **Interpretation**: Better balance between 1s and 0s in File 2
        

---

## 📉 4. **Fast Fourier Transform (FFT)**

- **Purpose**: Detects **periodicity** (repeating patterns) in the sequence.
    
- **Low peak = less periodicity = more randomness**
    
- **Example**:  
    `10101010...` → periodic  
    `10101100...` → non-periodic
    
- **Result**:
    
    - File 2: Better ⇒ ✅  
        🔎 **Interpretation**: S-box adds noise, breaks periodicity
        

---

## 🧮 5. **Frequency (Monobit) Test**

- **Purpose**: Checks if number of 0s ≈ number of 1s
    
- **Ideal**: Equal number of bits
    
- **Example**:  
    `111111` → fails  
    `101010` → passes
    
- **Result**:
    
    - File 1 better ⇒ ✅  
        🔎 **Interpretation**: S-box slightly disturbs overall 0/1 balance
        

---

## 📏 6. **Linear Complexity Test**

- **Purpose**: Measures the length of the shortest LFSR (linear feedback shift register) that can generate the sequence.
    
- **High value = better resistance to linear attacks**
    
- **Example**:  
    Random-like seq = high complexity  
    Repeating pattern = low complexity
    
- **Result**:
    
    - File 1 better ⇒ ✅  
        🔎 **Interpretation**: Original LEA may be harder to break with linear methods
        

---

## 📈 7. **Longest Run of Ones in a Block**

- **Purpose**: Looks for longest sequence of 1s in fixed-size blocks.
    
- **High value = more variability/randomness**
    
- **Example**:  
    `00011110000` → 4 ones  
    `00101010100` → short runs
    
- **Result**:
    
    - File 2 better ⇒ ✅  
        🔎 **Interpretation**: S-box allows more irregular bit-runs
        

---

## 🔲 8. **Non-Overlapping Template Matching Test**

- **Purpose**: Detects known non-repeating patterns (e.g., “111”) without overlaps.
    
- **High variation = better**
    
- **Result**:
    
    - File 2 better ⇒ ✅  
        🔎 **Interpretation**: S-box increases pattern unpredictability
        

---

## 🔁 9. **Overlapping Template Matching Test**

- **Purpose**: Detects small repeating patterns with overlaps (like "111" inside "1111").
    
- **High value = fewer repeating patterns**
    
- **Result**:
    
    - File 2 better ⇒ ✅  
        🔎 **Interpretation**: Less repetitive sequence → more secure
        

---

## 🧮 10. **Rank Test**

- **Purpose**: Measures rank (linearly independent rows) in a matrix built from bit stream.
    
- **Low rank = linear patterns**
    
- **High rank = randomness**
    
- **Result**:
    
    - File 2 MUCH better ⇒ ✅  
        🔎 **Interpretation**: S-box increases data randomness and removes linear dependence
        

---

## 🔃 11. **Runs Test**

- **Purpose**: Checks whether number of 0/1 runs (like "000" or "11") is too high/low.
    
- **Too regular = fails**
    
- **Example**:  
    `111000` → long runs  
    `101010` → good
    
- **Result**:
    
    - File 1 better ⇒ ✅  
        🔎 **Interpretation**: File 2 may have too many short or long runs
        

---

## 📚 12. **Serial Test**

- **Purpose**: Checks pattern frequency of length m and m+1.
    
- **Close results = better**
    
- **Result**:
    
    - File 2 slightly better ⇒ ✅  
        🔎 **Interpretation**: S-box modifies short-length patterns randomly
        

---

## 🌐 13. **Universal Statistical Test**

- **Purpose**: Checks how well the sequence can be compressed.
    
- **More compressible = less random**
    
- **Less compressible = more random**
    
- **Result**:
    
    - File 1 better ⇒ ✅  
        🔎 **Interpretation**: S-box may accidentally introduce structure
        

---

## ✅ Final Summary Table

|Test|Better File|Winner|
|---|---|---|
|Approximate Entropy|File 1|❌ S-box|
|Block Frequency|File 2|✅ S-box|
|Cumulative Sums|File 2|✅ S-box|
|FFT|File 2|✅ S-box|
|Frequency|File 1|❌ S-box|
|Linear Complexity|File 1|❌ S-box|
|Longest Run|File 2|✅ S-box|
|NonOverlapping Template|File 2|✅ S-box|
|Overlapping Template|File 2|✅ S-box|
|Rank|File 2|✅ S-box|
|Runs|File 1|❌ S-box|
|Serial|File 2|✅ S-box|
|Universal|File 1|❌ S-box|

---

Let me know if you want suggestions on improving entropy and frequency in S-box!