[LeetCode 40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

```cpp
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans; // vector<vector<int> -> set<vector<int>>
        vector<int> ds;
        help(candidates, target, ans, ds, 0);
        vector<vector<int>> result;
        for(auto &el : ans){
            result.push_back(vector<int>(el.begin(), el.end()));

        }
        return result;
    }

    void help(vector<int>& candidates, int target, set<vector<int>> &ans, vector<int> ds, int i){
        if(i>=candidates.size()){
            if(target==0){
                ans.insert(ds); // push_back() -> insert()
            }
            return;
        }

        ds.push_back(candidates[i]);
        help(candidates, target-candidates[i], ans, ds, i+1);
        ds.pop_back();
        help(candidates, target, ans, ds, i+1);

    }
```

Key Learnings To Prevent Duplicates (Brute force)
- Change Vector to Set
- Time Complexity Changes 
- TC of storing combination in data structure increases form `k` to `klogn` because, set is taking `logn` extra time
- `set` does **not have `push_back()`**; you should use `insert()`.
- **`vector`**: `O(1)` (amortized for `push_back`) or `O(k)` if inserting in sorted order.
- **`set`**: `O(log⁡n)` due to balanced BST (e.g., `std::set` in C++ uses Red-Black Tree).

```cpp
```