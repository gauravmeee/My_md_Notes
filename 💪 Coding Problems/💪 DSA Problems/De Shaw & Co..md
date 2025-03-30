# Question 1 - De Shaw & Co. (Divye 3-march-2025)

In a dynamic tech startup, a group of software engineers is responsible for prioritizing client feature enhancements based o incoming requests.

Over a span of n days, the team receives a new enhancement request on each ith day (where 0<=i<=n-1), and they must choose whether to implement or disregard it.

If the team opts to implement the ith request, it will require developmentHours[i] hours of engineering effort per day, commencing from the day the request is made. If the team chooses to disregard a request, it becomes obsolete and cannot be acted upon.

Moreover, if the team finds themselves unable to allocate the necessary hours for a request on any given day, that request too becomes obsolete and is no longer viable.

prior to the start of the enhancement requests, the team has a total of `availableHours` hours available for development.

The objective is to maximize the number of enhancement requests that can be successfully completed by the end of n days, ensuring that no requests become obsolete and that all are executed within the `totalHours`.

**Examples:**

Test Case 1:
```
Input:
developmentHours [3, 4, 1, 2]
availableHours = 17

Output:
3
```

Test Case 2:
```
Input:
developmentHours [1, 1, 1]
availableHours = 4

Output :
2
```

Test Case 2:
```
Input:
developmentHours [2, 3, 5]
availableHours = 10

Output :
1
```


### Cursor AI Approach
> Dynamic Programming

**Problem Understanding :**
1. We have `n` days, and each day we get a new feature request
2. For each request on day `i`:
   - We must decide to implement or disregard it immediately
   - If implemented, it needs `developmentHours[i]` hours per day from day `i` onwards
   - Once disregarded or if we can't allocate hours, the request becomes obsolete
3. We have `availableHours` total development capacity
4. Goal: Maximize the number of completed requests

**Approach :**

1. **Dynamic Programming Solution**
   - We'll use a DP approach since we need to make optimal decisions at each step
   - State variables:
     - Current day (i)
     - Remaining available hours
   - For each day, we have two choices:
     - Take the current request
     - Skip the current request
     
2. **Implementation Strategy**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRequests(vector<int>& developmentHours, int availableHours) {
        size_t n = developmentHours.size();
        
        // Map to store dp states: {day, hours} -> max requests possible
        map<pair<int, int>, int> dp;
        
        function<int(int, int)> solve = [&](int day, int remainingHours) {
            
            // Base cases
            if (day >= n) return 0;
            if (remainingHours < 0) return INT_MIN;
            
            // If already computed
            auto state = make_pair(day, remainingHours);
            if (dp.find(state) != dp.end()) {
                return dp[state];
            }
            
            // Skip current request
            int skip = solve(day + 1, remainingHours);
            
            // Take current request
            // Calculate required hours from current day till end
            int required = developmentHours[day] * (n - day);
            int take = INT_MIN;
            if (required <= remainingHours) {
                take = 1 + solve(day + 1, remainingHours - required);
            }
            
            // Store and return max result
            return dp[state] = max(skip, take);
        };
        return solve(0, availableHours);
    }
};

int main(){
    int availableHours = 10;
    vector<int> developmentHours = {2, 3, 5};
    Solution sol;
    cout << sol.maxRequests(developmentHours, availableHours) << endl;
    return 0;
}
```

  
1. **Time and Space Complexity**
   - Time Complexity: O(n * `availableHours`)
   - Space Complexity: O(n * `availableHours`)

2. **Test Case Analysis**
  
   For Test Case 1: `developmentHours = [3, 4, 1, 2], availableHours = 17`
   - Day 0: Request needs 3 * 4 = 12 hours total
   - Day 1: Request needs 4 * 3 = 12 hours total
   - Day 2: Request needs 1 * 2 = 2 hours total
   - Day 3: Request needs 2 * 1 = 2 hours total

   For Test Case 2: `developmentHours = [1, 1, 1], availableHours = 4`
   - Day 0: Request needs 1 * 3 = 3 hours total
   - Day 1: Request needs 1 * 2 = 2 hours total
   - Day 2: Request needs 1 * 1 = 1 hour total

This solution efficiently handles both test cases and provides the optimal number of requests that can be completed within the given constraints.

### My Approach 
> Greedy


```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRequests(vector<int>& developmentHours, int availableHours) {
        int n = developmentHours.size();
        vector<int> minArr;
        
        // Compute the minimum required hours for each request
        for (int i = 0; i < n; i++) {
            minArr.push_back(developmentHours[i] * (n - i));
        }
        
        // Sort to prioritize smaller requests
        sort(minArr.begin(), minArr.end());
        
        int count = 0;
        for (int hours : minArr) {
            if (availableHours < hours) break;  // If we can't afford it, stop
            availableHours -= hours;
            count++;
        }
        
        return count;
    }
};

int main() {
    int availableHours = 10;
    vector<int> developmentHours = {2, 3, 5};
    Solution sol;
    cout << sol.maxRequests(developmentHours, availableHours) << endl;
    return 0;
}
```

**Explanation**
1. **Compute Required Hours for Each Request**
    - For each `developmentHours[i]`, calculate `developmentHours[i] * (n - i)`.
    - Store these values in `minArr`.
2. **Sort in Ascending Order**
    - Sorting ensures we always process the smallest requests first.
3. **Process Requests Greedily**
    - Start fulfilling requests in increasing order.
    - Deduct from `availableHours` until no more requests can be fulfilled.

**Time Complexity** O(n log n)
- **O(n log n)** (due to sorting)
- **O(n)** (for computing and iterating through `minArr`)

**Space Complexity** : O(n)
- **O(n)** (for `minArr`)

Note:
- **Greedy Approach** is faster and simpler than the recursive DP solution.
- **Sorting helps prioritize cheaper requests first.**
- **Optimal solution for this problem.** ✅

---
---

# Question 2 - De Shaw & Co. (Divye 3-march-2025)


There are n software components arranged in a circular network, labeled from 1 to `n`. Each component relies on its neighboring components to function, meaning component 1 and 2 are neighbors, component 2 and 3 are neighbors, and so forth, With component n also connected back to component 1 to complete the circle.

Initially, `m` of these components have been infected by a malicious bug. Each day, the lead developer can "patch" one uninfected component, making it permanently immune to the bug.

Every day, the following sequence of events unfolds:
- The lead developer selects an uninfected component and patches it. making it permanently bug-free.
- All remaining unpatched and uninfected components with a neighboring infected component get infected by the bug.

The developer's goal is to prevent as many components as possible from bein infected.

Given an integer n representing the total number of software components in the network and an integer array infected of length m, containing the indices of the initially infected components.

Find the maximum number of components that can be saved from being infected if the developer optimally chooses which components to patch each day.

**Note:**
- The developer always applies a patch before the bug spreads to new components each day.
- A patched component will never be infected.

**Example :**

Test Case 1
```
Input:
n=9
infected = [1, 3, 5]

Output:
3
```

### Claude AI Approach

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * Finds the maximum number of components that can be saved from infection.
 * 
 * The approach:
 * 1. We simulate the process day by day
 * 2. On each day, we greedily choose to patch a component that's at risk of being infected
 * 3. If multiple components are at risk, we prioritize those that would cause more damage if infected
 * 4. After patching, we spread the infection to unpatched neighbors of infected components
 * 5. We continue until either all days are used or all components are either infected or patched
 * 
 * @param n Total number of components in the circular network
 * @param infected Vector of initially infected component indices
 * @return Maximum number of components that can be saved
 */
int maxComponentsSaved(int n, vector<int>& infected) {
    // Convert to set for O(1) lookup
    unordered_set<int> currentInfected(infected.begin(), infected.end());
    unordered_set<int> patched;
    
    // Helper function to get neighbors of a component
    auto getNeighbors = [n](int component) -> pair<int, int> {
        int left = (component == 1) ? n : component - 1;
        int right = (component == n) ? 1 : component + 1;
        return {left, right};
    };
    
    // Simulate each day
    for (int day = 0; day < n; day++) {
        // Find all uninfected components
        vector<int> uninfected;
        for (int i = 1; i <= n; i++) {
            if (currentInfected.count(i) == 0 && patched.count(i) == 0) {
                uninfected.push_back(i);
            }
        }
        
        if (uninfected.empty()) {
            break;  // No more components to patch
        }
        
        // Find components at risk of infection
        vector<int> atRisk;
        for (int comp : uninfected) {
            auto [left, right] = getNeighbors(comp);
            if (currentInfected.count(left) || currentInfected.count(right)) {
                atRisk.push_back(comp);
            }
        }
        
        // Select the best component to patch
        int bestToPatch;
        
        if (atRisk.empty()) {
            // If no components are at risk, patch any uninfected
            bestToPatch = uninfected[0];
        } else {
            // Patch the component that would put the most others at risk if infected
            bestToPatch = atRisk[0];
            int maxRisk = 0;
            
            for (int comp : atRisk) {
                auto [left, right] = getNeighbors(comp);
                int riskCount = 0;
                
                if (currentInfected.count(left) == 0 && patched.count(left) == 0) {
                    riskCount++;
                }
                if (currentInfected.count(right) == 0 && patched.count(right) == 0) {
                    riskCount++;
                }
                
                if (riskCount > maxRisk) {
                    maxRisk = riskCount;
                    bestToPatch = comp;
                }
            }
        }
        
        // Patch the selected component
        patched.insert(bestToPatch);
        
        // Spread infection to unpatched neighbors of infected components
        unordered_set<int> newInfected;
        for (int i = 1; i <= n; i++) {
            if (currentInfected.count(i) == 0 && patched.count(i) == 0) {
                auto [left, right] = getNeighbors(i);
                if (currentInfected.count(left) || currentInfected.count(right)) {
                    newInfected.insert(i);
                }
            }
        }
        
        // Update infected set
        for (int comp : newInfected) {
            currentInfected.insert(comp);
        }
    }
    
    // Return number of components saved (patched)
    return patched.size();
}

int main() {
    // Example 1
    vector<int> infected1 = {1, 3, 5};
    cout << "Example 1: " << maxComponentsSaved(9, infected1) << endl;  // Should output 3
    
    // Example 2
    vector<int> infected2 = {2, 5, 9};
    cout << "Example 2: " << maxComponentsSaved(10, infected2) << endl;  // Should output 2
    
    return 0;
}
```