---
description: Made by Me 💚
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# Binary Search Problems

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

## [MinMaxDivision](https://app.codility.com/programmers/lessons/14-binary_search_algorithm/min_max_division/) ⭐

**Learned from GPT**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Helper function to count how many blocks are needed 
// if no block is allowed to have sum > maxBlockSum
int countBlocks(vector<int> &A, int maxBlockSum) {
    int blocks = 1;     // Start with one block
    int currSum = 0;    // Current block sum

    for (int a : A) {
        // If adding this element keeps sum within limit, add it
        if (currSum + a <= maxBlockSum) {
            currSum += a;
        } else {
            // Otherwise, start a new block from current element
            currSum = a;
            blocks++;
        }
    }
    return blocks;
}

// Main function to find the minimal possible value of the largest block sum
int solution(int K, int M, vector<int> &A) {
    // The lower bound of the answer is the largest element (can't split it further)
    int low = *max_element(A.begin(), A.end());

    // The upper bound is the total sum (1 block case)
    int high = accumulate(A.begin(), A.end(), 0);

    int ans = high;  // Initialize with max possible value

    // Binary search to find the minimal valid large sum
    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if we can divide array into at most K blocks with max sum <= mid
        if (countBlocks(A, mid) <= K) {
            // It's a valid solution, try to minimize further
            ans = mid;
            high = mid - 1;
        } else {
            // Not enough blocks, increase allowed block sum
            low = mid + 1;
        }
    }
    return ans;  // Final minimized large sum
}

```

## [NailingPlanks](https://app.codility.com/programmers/lessons/14-binary_search_algorithm/nailing_planks/)

My Solution -> Wrong Approach (Without Binary Tree) ❌

```cpp
int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n = A.size();
    int m = C.size();
    vector<vector<int>> planks(n, vector<int>(2));
    for(int i=0; i<n; i++){
        planks[i][0] = A[i];
        planks[i][1] = B[i];
    }
    int plankNailed = 0;
    int ans =0;
    for(int nail=0; nail<m; nail++){
        while(C[nail]<=B[plankNailed] && C[nail]>=A[plankNailed]){
            plankNailed++;
        }
        if(plankNailed==n){
           ans = nail;
           break;
        }
    }
    return ans+1;
}
```

Your current approach **cannot be fixed by small modifications**. Even with the new condition.

It is **still fundamentally flawed**, because:

* Checking only **one plank at a time** (`plankNailed`)
* Trying to progress based on **only the current nail**
* Missing that a nail can hit a plank **out of order**

**Why Binary Search (or Other Efficient Method) is Needed:**

1. **Use nails in order** from `C[0]` to `C[J]`
2. **Ensure all planks are nailed using only first J nails**
3. Check for each plank: is **any** nail in that subarray in its range?

This can be done using:

* Binary Search over `J` (min nails needed)
* Prefix minimums to speed up checking whether a plank can be nailed

***

#### ✅ Recommendation:

Use a binary search solution with:

* Binary search on `J` (min # of nails)
* Preprocess `C` with index
* For each plank, check if any nail in \[A\[i], B\[i]] exists within first `J` nails using a segment tree or prefix minimum

My `Binary Search` Solution with Help of GPT ✅

```cpp
int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n = A.size();
    int m = C.size();
    int low =0;
    int high = m-1;
    int ans = -1; // added
    while(low<=high){ // `<` changed to -> `<=`
        int mid = (low + high)/2;
        unordered_set<int> plankNailed;
        for(int j=0; j<=mid; j++){
            for(int i=0; i<n; i++){
                if(C[j]>=A[i] && C[j]<=B[i]) plankNailed.insert(i) ;
            }
        }  
        if (plankNailed.size() == static_cast<size_t>(n)){
            ans = mid+1;
            high = mid-1;
        } else{
            low = mid+1;
        }
    }
    return ans;
}
```
