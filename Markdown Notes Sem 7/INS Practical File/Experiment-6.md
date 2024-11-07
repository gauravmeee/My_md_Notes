
#### Aim: 
To implement S-DES sub key Generation

### Theory:

S-DES is a version of DES with significantly reduced parameters, while preserving the structure of DES. The goal of S-DES is to help beginners understand the structure of DES, serving as a foundation for further study. It is a teaching tool similar to Phan's. The encryption algorithm involves five functions: an initial permutation (IP); a complex function called `fK`, which involves both permutation and substitution operations depending on the key; a simple permutation function that switches the two halves of the data; `fK` again; and a permutation function that is the inverse of the initial permutation (IP-1).
### Code:
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::rotate
using namespace std;

class DESKeyGenerator {
    const vector<int> P10 = {2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
    const vector<int> P8 = {5, 2, 6, 3, 7, 4, 9, 8};
    vector<int> initialKey;
    // Permutation function
    vector<int> permute(const vector<int>& arr, const vector<int>& pTable) {
        vector<int> res;
        for (int i : pTable) res.push_back(arr[i]);
        return res;
    }
    // Left shift function
    void leftShift(vector<int>& v, int n) {
        rotate(v.begin(), v.begin() + n, v.end());
    }
    // Split function
    pair<vector<int>, vector<int>> split(const vector<int>& v) {
        int sz = v.size();
        vector<int> left(v.begin(), v.begin() + sz / 2);
        vector<int> right(v.begin() + sz / 2, v.end());
        return {left, right};
    }
    // Merge function
    vector<int> merge(const vector<int>& left, const vector<int>& right) {
        vector<int> res = left;
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
    // Utility function to show intermediate steps
    void show(const vector<int>& v, const string& label) {
        cout << label;
        for (int i : v) cout << i;
        cout << endl;
    }
public:
    DESKeyGenerator(const vector<int>& key) : initialKey(key) {}
    vector<vector<int>> generate() {
        show(initialKey, "Initial 10-bit key: ");
        // Step 1: Initial P10 permutation
        auto initialPerm = permute(initialKey, P10);
        show(initialPerm, "Initial P10 permutation: ");
        // Step 2: Split the permuted key
        auto splitKey = split(initialPerm);
        
        cout << "------------------------------------------" << endl;
        cout << "Key split: " << endl;
        show(splitKey.first, "Left: "); show(splitKey.second, "Right: ");
        // Step 3: Left shift each half by 1 for first subkey
        leftShift(splitKey.first, 1);
        leftShift(splitKey.second, 1);
        show(splitKey.first, "After 1-bit left shift (Left): "); show(splitKey.second, "After 1-bit left shift (Right): ");
        // Step 4: Merge and apply P8 to get first subkey
        auto mergedKey = merge(splitKey.first, splitKey.second);
        show(mergedKey, "Merged key 1: ");
        auto generatedKey1 = permute(mergedKey, P8);
        show(generatedKey1, "Generated key 1: ");
        
        // Step 5: Split again, shift by 2 for second subkey
        splitKey = split(mergedKey);
        cout << "------------------------------------------" << endl;
        cout << "Key split: " << endl;
        show(splitKey.first, "After 2-bit left shift (Left): "); show(splitKey.second, "After 2-bit left shift (Right): ");
        leftShift(splitKey.first, 2);
        leftShift(splitKey.second, 2);
        // Step 6: Merge and apply P8 to get second subkey
        mergedKey = merge(splitKey.first, splitKey.second);
        show(mergedKey, "Merged key 2: ");
        auto generatedKey2 = permute(mergedKey, P8);
        show(generatedKey2, "Generated key 2: ");
        return {generatedKey1, generatedKey2};
    }
};

int main() {
    vector<int> key = {1, 0, 1, 0, 0, 0, 0, 0, 1, 0}; // Example 10-bit key
    DESKeyGenerator keyGen(key);
    vector<vector<int>> keys = keyGen.generate();
    return 0;
}
```

### Output:
![[Pasted image 20241107140149.png]]