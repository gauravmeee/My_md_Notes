Steps
Recursion -> Memoization(Recursion + extra) -> Tabulation -> Space Optimsation (Tabulation)

Memoization (Recursion) -> Top-Down Approach 
Tabulation (For Loop) -> Bottom  Up-Approach

 ---
#### Recursion
- **Time Complexity (TC):** `O(2^n)`
  - The recursive solution explores all possible subsets of the array. For each element, it has two choices: either to pick or not pick the element, leading to an exponential time complexity of `O(2^n)`.
- **Space Complexity (SC):** `O(n)`
  - The maximum depth of the recursion tree in the worst case is `n`. Therefore, the space complexity is `O(n)` due to the recursive call stack.

### Memoization
- **Time Complexity (TC):** `O(n)`
  - By storing the results of subproblems, memoization avoids recalculating them, reducing the time complexity to `O(n)` since each state is computed once.
- **Space Complexity (SC):** `O(n) + O(n)`
  - **Recursive Call Stack:** The space used by the recursive call stack is `O(n)`.
  - **DP Array:** An additional `O(n)` space is required to store the results of subproblems.
  - **Total Space Complexity:** `O(n) + O(n) = O(n)`

### Tabulation
- **Time Complexity (TC):** `O(n)`
  - The tabulation method iteratively computes the result for each index from `0` to `n`, leading to a linear time complexity of `O(n)`.
- **Space Complexity (SC):** `O(n)`
  - The space required is `O(n)` for storing the DP table, where each entry corresponds to a subproblem solution.

### Space Optimization
- **Time Complexity (TC):** `O(n)`
  - The time complexity remains `O(n)` as we still compute the result iteratively for each index from `0` to `n`.
- **Space Complexity (SC):** `O(1)`
  - Instead of maintaining an entire DP array, we only keep track of the last two states (because each state depends only on the previous two). Thus, the space complexity is reduced to `O(1)`.

---

# [DP 5. Maximum Sum of Non-Adjacent Elements | House Robber | 1-D | DP on Subsequences](https://youtu.be/GrMBfJNk_NY?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY)

>Ques.  Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

 -> pick the one with the maximum sum -> try  all subsequences -> recursion -> pick or not pick

### Recursion ✅
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

### Memoization ✅
```cpp
f(ind, arr, dp){
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

### Tabulation ✅
```cpp
f(ind, arr, dp){
	dp[0] = arr[0];
	for(int i=1; i<n; i++){
		// if condition is neccesary because, accessing dp[i-2], if i<=1 result in out of bound
		take = arr[ind]; if(i>1) take+=dp[i-2] // if `i-2` >= include
		notTake = 0 + dp[i-1];
		dp[i] = max(take, notTake)
	}
}
// Call f(n, arr)
```
- TC: `O(n)`
- SC: `O(n)`
### Space Optimization ✅
```cpp
f(ind, arr){
	int prev = a[0];
	int prev2 = 0;
	for(int i=1; i<n; i++){
		// I think this is unneccessary, as if i=1, prev=0; so without if condition we should write:
		// take = a[ind] + prev2
		take = a[ind]; if(i>1) take+=prev2 // if `i-2` >= include
		notTake = 0 + prev;
		curri = max(take, notTake);
		prev2 = prev;
		prev = curri
	}
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
> Ques. A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get notified.
> 
>Given an array of integers “Arr'' which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police.

Conclusion : First and Last element are also adjacent

Example:
`arr = [2, 4, 3]`
According to the last question 2 & 3 are not adjacent and can be picked `max = 5`
But now, `first` and `last` i.e. 2 and 3 are adjacent and Cannot be picked, so `max = 4`

Solution:
skip the last element and apply the ques 5 function()
```
 0 1 2 3 ...... n
[             ] X
```

skip the first element and apply the ques 5 function()
```
X  0 1 2 3 ...... n
  [                ]
```

*Changes: *
```cpp
temp1[] : arr[0 -> n-1] // skipped last
ans1 = f(temp1[])

temp2[] : arr[1 -> n] // skipped first
ans2 = f(temp2[])

return max(ans1 , ans2)

```
- TC: `O(n)`
- SC: `O(1)`

### Space Optimization
```cpp
```cpp
// function from question 5.
/*
long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
*/

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1;
    vector<int> arr2;
    
    if(n==1)
       return arr[0];

	// Nice trick to fill in two array with constraints in one loop
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(arr[i]);  // (1) to (n-i)
        if(i!=n-1) arr2.push_back(arr[i]); // (0) to (n-2)
    }
    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    
    return max(ans1,ans2);
}


int main() {

  vector<int> arr{1,5,1,2,6};
  int n=arr.size();
  cout<<robStreet(n,arr);
}
```

# [DP 7. Ninja's Training | MUST WATCH for 2D CONCEPTS 🔥 | Vacation | Atcoder | 2D DP |](https://youtu.be/AE39gJYuRog)

### Recursion 
```cpp
f(day, last){

	// base condition
	if(day == 0){ // last day ( recursion(day--)
		maxi =0
		for(l=0 -> 2)
			if(l!=last) maxi = max(maxi, task[0][l]) // choose last day task
		return maxi;
	}
	maxi = 0;
	for(l =0 -> 2){
		// out of i=0, 1, 2 (one that will be executed last will be ignored)
		if(l!=last){
			points = task[day][l] + f(day-1, l) // choose tasks
			maxi = max(maxi, points)
		}
	}
	return maxi
}
// Call f(day,last) 
// last = 3 in starting , so all 0,1,2 satisfy condition

// better and simple base conditon could be:
// if(day<0) return 0;
// no require to calculate if(day==0) in base condition, it could be done by recursion
```
- TC: `O(3*(2^(n-1))`
- SC: `O(n)`
### Memoization 
```cpp
f(day, last){
	else if(day == 0){
		maxi =0
		for(l=0 -> 2)
			if(l!=last) maxi = max(maxi, task[0][l]) // Doubt: why this required, why it not solved only in base case and recursion
		return maxi;

	if(dp[day][last]!= -1) return dp[day][last] // DP return to skip recursion
	
	}
	maxi = 0;
	for(l =0 -> 2){
		if(l!=last){
			points = task[day][l] + f(day-1, l)
			maxi = max(maxi, points)
			}
	}
	return dp[day][l] = maxi // assign dp 
}
```
```
2D DP : dp[N][4]
N -> Days
4 -> [ 0, 1, 2, 3 ] -> Tasks  ( state 3 for none of the task done yet)
```
- TC: `O(n*4)*3` : `4` is the no. of possible choices (state) of the last task plus a state for not having chosen a task, and for each state running for loop of size `3`
- SC: `O(n)+O(n*4)` : n\*4 for dp table
### Tabulation
```cpp
int f(int n, points[][]){
	vector<vector<int>> dp(n, vector<int>(4,0));
	// base case
	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][0], points[0][1]);
	dp[0][3] = max(points[0][1], points[0][1], points[0][2]);
	// main loop
	for(int day=1; day<n; day++){
		for(int last=0; last<4; last++){
			dp[day][last]=0; // this statement is useless ig.
		
			for(int task =0; task<3; task++){
				if(task!=last){
					int point = points[day][task]+dp[day-1][task];
					dp[day][last] = max(dp[day][last], points);
				}
			}
		}
	}
	return dp[n-1][3];
}
```
- TC: `O(n*4*3)` 
- SC: `O(n*4)` : recursion stack reduced
### Space Optimization
```cpp
int f(int n, points[][]){
	vector<vector<int>> prev(4,0);
	// base case
	
	// if choosed 0 as last task 
	prev[0] = max(points[0][1], points[0][2]);

	// if choosed 1 as last task
	prev[1] = max(points[0][0], points[0][2]);

	// if choosed 2 as last task
	prev[2] = max(points[0][0], points[0][1]);

	// if choosed nothing before
	prev[3] = max(points[0][1], points[0][1], points[0][2]);
	
	// main loop
	for(int day=1; day<n; day++){
		vector<int> temp(4, 0);
		for(int last=0; last<4; last++){
			temp[last]=0;
			
			for(int task =0; task<3; task++){
				if(task!=last){
					temp[last] = max(temp[last], points[day][task]+prev[task]);
				}
			}
		}
		prev = temp;
	}
	return prev[3];
}
```
- TC: `O(n*4*3)` 
- SC: `O(4)` 

# [DP 8. Grid Unique Paths | Learn Everything about DP on Grids | ALL TECHNIQUES 🔥](https://youtu.be/sdE0A2Oxofw)

DP on Grids/ 2D Matrix
- Count paths
- Count Paths with obstacles
- Min Path Sum
- Max Path Sum
- Triangle Problem
- 2 Start points

Revisiting Recursion Lecture 7
```
count ways()
	// base case
	return 1
	return 0

	l = f()
	r = f()

	return l+r
```


>Ques .

# [Unique Paths II](https://www.naukri.com/code360/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM)

>Ques. Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. 

Note: Since the answer can be large, print it modulo 10^9 + 7.

*Input: *
```
Consider the maze below :
0   0   0 
0  -1   0 
0   0   0
```
*Output:*
```
2

path 1: (1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
path 2: (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)
```

Unique Path II  = Unique Path I + Condition for Obstacle/dead Cell

#### Recursion
```cpp

const int MOD = 1e9 + 7

// bottome right corner to top left corner
f(i,j){
	if(i<0 || j=<0) return 0;
	
	// Obstacle Condition
	if(a[i][j]==-1) return 0; // if a[0][0] cannot be '-1' only then this condition can also be written below the below stament.
	 
	if(i==0 && j==0 ) return 1;
	

	up = f(i-1, j)/MOD  // up could be large enoug for int, so MOD
	left = f(i, j-i)/MOD // left could be large enough for int, so MOD

	return (up + left)/MOD // Answer could be large enough for int, so MOD
}
```

#### Recursion
```cpp
// bottome right corner to top left corner
f(i,j){
	if(i<0 || j=<0) return 0;
	if(a[i][j]==-1) return 0;
	if(i==0 && j==0 ) return 1;

	// dp array check
	if(dp[i][j]!=-1) return dp[i][j]

	up = f(i-1, j)
	left = f(i, j-i)

	return dp[i][j]= up + left // dp add and return 
}
```