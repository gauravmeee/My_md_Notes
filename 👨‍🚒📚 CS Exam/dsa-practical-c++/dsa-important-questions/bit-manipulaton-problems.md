---
title: Bit Manipulation Problems
---

### [Add Binary](https://leetcode.com/problems/add-binary/)

**Arithmetic Version**

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
```
    
**Bitwise Version**
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.size() > b.size()) b = string(a.size() - b.size(), '0') + b;
        else if (a.size() < b.size()) a = string(b.size() - a.size(), '0') + a;

        int n = a.size();
        int carry = 0;
        string ans = "";

        for(int i = n - 1; i >= 0; i--){
            int abit = a[i] - '0';
            int bbit = b[i] - '0';

            int sumBit = abit ^ bbit ^ carry; // XOR
            carry = (abit & bbit) | (abit & carry) | (bbit & carry); // AND

            ans = char(sumBit + '0') + ans;
        }

        if(carry) ans = '1' + ans;

        return ans;
    }
};
```

- `sumBit = a ⊕ b ⊕ carry`
- `carry = (a & b) | (a & carry) | (b & carry)` ← full adder

- Time: `O(max(n, m))`, 
- Space: `O(max(n, m))

### [Reverse Bits](https://leetcode.com/problems/reverse-bits/)

**Arithmetic Version**
```cpp
class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int bit = n & 1;
            ans = (ans * 2) + bit;
            n = n >> 1;
        }
        return ans;
    }
};
```
- `ans = (ans * 2) + bit;`
	- `ans * 2` → same as left shift
	- `+ bit` → add extracted bit

**Bitwise Version**
```cpp
class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int bit = n & 1;
            ans = (ans << 1) | bit;
            n >>= 1;
        }
        return ans;
    }
};
```

- `ans = (ans << 1) | bit;`
	- `ans << 1` → shift left (multiply by 2)
	- `| bit` → insert extracted bit at LSB


- **Time Complexity:** `O(32) ≈ O(1)`
- **Space Complexity:** `O(1)`