
## # Overflow & Underflow in DSA (Complete Notes)

---

## # 1. Actual Data Type Limits (C++)

```cpp
#include <climits>

// int (32-bit)
INT_MIN  = -2147483648        // ~ -2e9
INT_MAX  =  2147483647        // ~  2e9

// long long (64-bit)
LLONG_MIN = -9.22e18
LLONG_MAX =  9.22e18
```

---

## # 2. Misconception

```
int range = -1e9 to 1e9 ❌
```

Reality:

```
int range ≈ -2e9 to 2e9
```

👉 `1e9` is NOT limit → it's a **safe working value**

---

## # 3. What is Overflow / Underflow

### overflow

```cpp
int x = INT_MAX;
x = x + 1;   // overflow → garbage value
```

### underflow

```cpp
int x = INT_MIN;
x = x - 1;   // underflow → garbage value
```

---

## # 4. Where it Happens in DSA

### (a) DP (most common mistake)

```cpp
return grid[i][j] + min(left, up);
```

If:

```cpp
left = INT_MAX
```

Then:

```cpp
INT_MAX + grid[i][j] → overflow ❌
```

---

### (b) Graph (Dijkstra / BFS variants)

```cpp
dist[u] + wt   // overflow if dist[u] = INF
```

---

### (c) Binary Search

```cpp
mid = (l + r) / 2;   // overflow possible
```

---

### (d) Multiplication

```cpp
int x = 1e9;
x * x → overflow ❌
```

---

## # 5. Sentinel Values (MOST IMPORTANT)

### Wrong

```cpp
int INF = INT_MAX;   // dangerous ❌
```

### Correct

```cpp
int INF = 1e9;       // safe ✔
long long INF = 1e18;
```

---

## # 6. Why `1e9` Works

Constraint logic:

```
max path sum ≤ 1e5 or 1e6
```

So:

```
1e9 + 1e6 < INT_MAX
```

👉 No overflow → safe

---

## # 7. Safe Patterns

### Pattern 1: Guard before adding

```cpp
if (val == INT_MAX) return INT_MAX;
return grid[i][j] + val;
```

---

### Pattern 2: Use safe INF

```cpp
const int INF = 1e9;
```

---

### Pattern 3: Use long long

```cpp
long long ans = grid[i][j] + val;
```

---

### Pattern 4: Binary Search safe mid

```cpp
int mid = l + (r - l) / 2;
```

---

### Pattern 5: Multiplication safe

```cpp
long long res = 1LL * a * b;
```

---

## # 8. Invalid State Handling (DP/Grid)

### Wrong

```cpp
if(out_of_bound) return INT_MAX;
```

### Better

```cpp
if(out_of_bound) return 1e9;
```

OR

```cpp
if(out_of_bound) return -1e9;   // for max problems
```

---

## # 9. Min vs Max Problems

### Minimize

```
invalid → return +INF (1e9)
```

### Maximize

```
invalid → return -INF (-1e9)
```

---

## # 10. Best Practice (My Opinion)

- Never use `INT_MAX` in DP transitions
    
- Prefer:
    

```cpp
int INF = 1e9;
long long INF = 1e18;
```

- If values can grow → directly use `long long`
    
- Always think:
    

```
"Will I add/multiply this?"
```

If yes → avoid extreme limits

---

## # 11. Quick Checklist (Before Coding)

- Will I add values? → avoid `INT_MAX`
    
- Will multiplication happen? → use `long long`
    
- DP with invalid states? → use `±1e9`
    
- Binary search? → safe mid formula
    

---

## # 12. Final Insight

```
INT_MAX = limit
1e9     = tool
```

👉 Limits define range  
👉 Sentinels define safety

Most DSA bugs are not logic bugs → they are **overflow bugs**.