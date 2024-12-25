
# [Binary Search](https://leetcode.com/problems/binary-search/)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;  // Find the middle index
            
            if (nums[mid] == target) {
                return mid;  // Target found, return the index
            } else if (nums[mid] < target) {
                l = mid + 1;  // Search in the right half
            } else {
                r = mid - 1;  // Search in the left half
            }
        }
        
        return -1;  // Target not found
    }
};

```