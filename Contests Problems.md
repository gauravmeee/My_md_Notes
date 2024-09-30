```cpp
#include <iostream>
#include <string>

std::string toBinary(int n) {
    std::string binary = "";
    while (n > 0) {
        binary = std::to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

int main() {
    std::string numericString = "25"; // Example numeric string
    int number = std::stoi(numericString); // Convert string to integer

    std::string binaryString = toBinary(number); // Convert to binary
    std::cout << "Binary representation: " << binaryString << std::endl;

    return 0;
}

```

```
std::string substr(size_t pos = 0, size_t len = npos) const;
```

Ans
```cpp
class Solution {
public:
    string toBinary(int num){
        string ans ="";
        while(num>0){
            ans=to_string(num%2) + ans;
            num/=2;
        }
        return ans;
    }
    
    string convertDateToBinary(string date) {
        int day =stoi(date.substr(8,2));
        int month = stoi(date.substr(5,2));
        int year = stoi(date.substr(0,4));
        
        string ans= toBinary(year)+"-"+toBinary(month)+"-"+toBinary(day);
        return ans;
    }
};
```

```cpp
class Solution(object):
    def maxPossibleScore(self, start, d):
        start.sort()
        def f(md):
            p = start[0]
            for i in range(1, len(start)):
                if p + md <= start[i] + d:
                    p = max(p + md, start[i])
                else:
                    return False
            return True
        l, r=0, start[-1]+d - start[0]
        m = 0
        while l<= r:
            mid = (l + r) //2
            if f(mid):
                m = mid
                l = mid +1
            else:
                r = mid-1
        return m

```