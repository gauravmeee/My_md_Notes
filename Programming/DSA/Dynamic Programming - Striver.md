Steps
Recursion -> Memoization(Recursion) -> Tabulation -> Space Optimsation (Tabulation)

Memoization - > Recursion -> Top-Down Approach 
Tabulation - > For Loop -> Bottom  Up-Approach

# [DP 5. Maximum Sum of Non-Adjacent Elements | House Robber | 1-D | DP on Subsequences](https://youtu.be/GrMBfJNk_NY?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY)

>Ques.  Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

 -> pick the one with the maximum sum -> try  all subsequences -> recursion -> pick or not pick

### Recursion
```cpp
f(ind, arr){
	// reached to `ind==0` mean -> not picked `ind==1`
	if(ind == 0) return a[ind];
	if(ind < 0) return 0;
	
	pick = a[ind] + f(ind-2) // if picking `ind` can't pick `ind-``
	notPick = 0 + f(ind-1);
	return max(pick, notPick);
}
// Call f(n, arr)
```
- TC: `O(2^n)`
-  SC: `O(n)`

### Memoization
```cpp
f(ind, arr){
	if(ind == 0) return a[ind];
	if(ind < 0) return 0;
	if(dp[ind]!=-1) return dp[ind]; // memoisation Accessing  
	
	pick = a[ind] + f(ind-2) 
	notPick = 0 + f(ind-1); 
	return dp[ind] = max(pick, notPick); // memoisation Assigning
}
// Call f(n, arr)
```
- TC: `O(n)`
- SC: `O(n) + O(n)`

### Tabulation
```cpp
f(ind, arr){
	dp[0] = a[0];
	int neg =0; // if 
	for(int i=1; i<n; i++){
	take = a[ind]; if(i>1) take+=dp[i-2] // if `i-2` >= include
	notTake = 0 + dp[i-1];
	dp[i] = max(take, notTake)}
}
// Call f(n, arr)
```
- TC: `O(n)`
- SC: `O(n)`
### Space Optimization

```cpp
f(ind, arr){
	int prev = a[0];
	int prev2 = 0;
	for(int i=1; i<n; i++){
	take = a[ind]; if(i>1) take+=prev2 // if `i-2` >= include
	notTake = 0 + prev;
	curri = max(take, notTake);
	prev2 = prev;
	prev = curri}
}
// Call f(n, arr)
```
- TC: `O(n)`
- SC: `O(1)`

***C++ Code :***
```cpp
int solve(int n, vector<int>& arr) {
    int prev = arr[0];   // Initialize the maximum sum ending at the previous element
    int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
    }
    
    return prev;  // Return the maximum sum
}

int main() {
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    
    // Call the solve function and print the result
    cout << solve(n, arr);

    return 0;
}
```

# [ DP 6. House Robber 2 | 1D DP | DP on Subsequences](https://youtu.be/3WaxQMELSkw) 