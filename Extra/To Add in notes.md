
# converting no. to binary



# 🔢 1. Division by 2 Method (Most Standard)

### 🔑 Idea

* Divide number by 2
* Store **remainder**
* Reverse at the end



### ✅ Code

```cpp
string toBinary(int n) {
    if (n == 0) return "0";
    
    string res = "";
    while (n > 0) {
        res.push_back((n % 2) + '0');  // remainder
        n /= 2;
    }
    
    reverse(res.begin(), res.end());
    return res;
}
```



### 🪜 Example (n = 10)

```
10 % 2 = 0
5  % 2 = 1
2  % 2 = 0
1  % 2 = 1

→ reverse → 1010
```

---

# ⚙️ 2. Bit Manipulation Method

### 🔑 Idea

* Check last bit using `n & 1`
* Right shift `n >> 1`



### ✅ Code

```cpp
string toBinary(int n) {
    if (n == 0) return "0";
    
    string res = "";
    while (n > 0) {
        res.push_back((n & 1) + '0');  // last bit
        n = n >> 1;
    }
    
    reverse(res.begin(), res.end());
    return res;
}
```



# 🔄 Comparison

| Method | Operation | Concept            |
| ------ | --------- | ------------------ |
| `% 2`  | Division  | Arithmetic         |
| `& 1`  | Bitwise   | Faster / low-level |


---

#### ⚡ Key Insight

```text
n % 2  ==  n & 1
n / 2  ==  n >> 1
```


### 🚀 Quick Tip

* Use `% 2` → easy & readable
* Use `& 1` → bit manipulation interviews


