### [Add Binary](https://leetcode.com/problems/add-binary/)

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

- Time: `O(max(n, m))`, Space: `O(max(n, m))`
    
**In Bitwise Style**


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
