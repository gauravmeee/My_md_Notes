---
description: Made by Me 💚
icon: dot
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

# Dynamic Programmic Problems

## [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

```cpp
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<int> maxSell(n,0);
	int maxi=0;
	int maxPro =0;
	for(int i=n-1; i>=0; i--){
		maxi = max(maxi,prices[i]);
		maxPro = max(maxPro,maxi-prices[i]);
	}
	return maxPro;
}
```

## [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) ⭐

```
                Pascals Triangle

r=1, r-1=0              1
r=2, r-2=1            1   1
r=3, r-2=2         1    2   1
r=4, r-4=3      1    3    3   1
r=5, r=5=4    1   4    6    4   1
r=6, r-6=5  1   5   10   10   5   1
```

3 Problems:

#### 1. Give Row `r` and column `c`, find the element at that place

Note: `r` and `c` zero based. first row = r - 1 = 1- 1 =0 first column = c - 1 = 1 -1 =0

Formula of Combination: ${}^nC\_r = \frac{n!}{r!(n-r)!}$

Formula to find `rth` row, and `Cth` column : ${}^{r-1}C\_{c-1} = \frac{r!}{c!(r-c)!}$

> Direct Calculating

Total Time Complexity : O(r!) + O(c!) + O(r-c)!

> Better approach

Note r>=c, because for any `rth` column, there are only `r` no. of columns, so we could choose any columns from starting up-to `r`

let r = 5, c =3 ----> ${}^{5-1}C\_{3-1} = \frac{4!}{2!(4-2)!} = \frac{&#x34;_&#x33;}{&#x32;_&#x31;}$

Similarly r=7, c=4 ----> $\frac{&#x36;_&#x34;_&#x33;}{&#x33;_&#x32;_&#x31;}$

Conclusion: for any `r` and `c` $\frac{(r-1)_(r-2)_(r-3)....(C-1)_times}{&#x31;_&#x32;\*3 ....(C-1)\*times}$ i.e $\frac{r-1}{1} \* \frac{r-2}{2} \* \frac{r-3}{3} ... (c-1)\*times$

```cpp
//pass nCr(r-1, c-1)
int nCr(int n, int r){ 
	long long res =1;
	for(int i=0; i<r; i++){
		res = res*(n-i); 
		res = res/(i+1); // res (r-i)
	}
}
```

***

1. Doubt : why this will not work if we update `res` in for loop `res=res/(r-1)` i.e. `r-i` decreasing in each iteration.

* Reason : Because, in each iteration it is not necessary `r-1` divide `res` completely.

```cpp
for(int i=0; i<r; i++){
	res = res*(n-i); // multipling intermediate result with intermediate numerator
	
	// denominator decreasingingly divide, r, then r-1, r-2. ....1
	res = res/(r-i); //multipling intermediate result with intermediate denominator
}
```

```
 n   (n-1)   (n-2)        (n-r+1)
-- * ----- * ----- *...* ------  ❌ Incorrect answer
 r   (r-1)   (r-2)        (1)
```

2. Doubt : What is the guarantee that it, `i+1` will divide `res` completely

* Proof : In `n` consecutive sequence of number, it is obvious that, one of the number will be multiple of `n`. because multiple of `n` come after each `n` counting.
* ex: - In 3 no. consecutive (5,6,7) , (22,23,24), (56, 57, 58) there will be one multiple of `3` i.e 6, 24, and 57.
* So in `ith` iteration of for loop, `res` will have been multiplied by some `i` no. consecutive number. So there will be some number in numerator that would be multiple of `i`, and so on dividing by denominator `i` perfect.

```cpp
for(int i=0; i<r; i++){
	res = res*(n-i);  // multipling intermediate result with intermediate numerator
	// denominator increasingly divide, 1, then 2, 3, ... r
	res = res/(i+1); //multipling intermediate result with intermediate denominator
}
```

```
n    (n-1)   (n-2)       (n-r+1)
_ *  ----   * ---- *...* -------  ✅ Correct answer
1     (2)     (3)         (r)
```

3. Simply calculating numerator and denominator separately, and then finally calculating result would be easy, but required two extra variable `num` and `denom`

```cpp
for(int i=0; i<r; i++){
	num = res*(n-i);  // numerator calculate in one go
	denom = res/(i+1); // Denominator Calculate in one go
}
res = num/denom ; // dividing overall numerator with overall dunemerator
```

```
n * (n-1) * (n-2).... (n-r+1)   
-----------------------------  ✅ Obvious it will give correct answer
r * (r-1) * (r-2) .... 1       
```

***

Total Time Complexity : O(c) ✅ and SC:O(1)

#### 2. Print any row `r` of the pascal triangle

> Brute force : using the formula `nCr()`

```cpp
for(c=1; c<n; c++){
	cout<<nCr(n-1,c-1)<<" "; // nCr():TC=O(n)
}
```

Time Complexity : O(n \* r)

> Better Approach

```cpp
long long ans =1; // in starting there is always 1
cout<<ans<<" "; // print the starting 1

for(i=1; i<n; i++){
	ans = ans*(n-i);
	ans = ans/(i);
	cout<<ans<<" ";
}
```

TC: O(n) and SC: O(n)

#### 3. Provide list of Pascal Triangle up to `nth` row

> Brute Force

```cpp
ans = []
for(row = 1->n){
	tempLis = []
	for(col = 1->row)
		tempLis.add(nCr(row-1, Col-1)); // nCr():TC=O(n)
	}
	ans.add(tempLis);
}
return ans;
```

TC: O(n \* n \* r) , Note: ans is used to store answer `SC:O(n*n)`, not for computation, so its obvious to use the space. In such cases no extra space is used, and we didn't talk about space complexity.

> Better Approach : using type 2 , to generate row

```cpp
// r * times
vector<int> generateRow(int row){
	long long ans =1;
	vector<int> ansRow;
	ansRow.push_back(1); // in starting there is always 1
	for(int col =1 ; col<row; col++){
		ans = ans * (row-col);
		ans = ans/ (col);
		ansrow.push(ans);
	}
	return ansRow;
}

// n * times
vector<vector<itn>> pascalTriangle(int N){
	vector<vector<int>> ans;
	for(int i=1; i<=N; i++){
		ans.push_back(generateRow(i));
	}
	return ans;
}
```

TC: O(n \* r)

***

## [Ninja’s Training](https://www.naukri.com/code360/problems/ninja-s-training_3621003?source=youtube\&campaign=striver_dp_videos\&utm_source=youtube\&utm_medium=affiliate\&utm_campaign=striver_dp_videos\&leftPanelTabValue=PROBLEM)

Memoization ✅ Tabulation(+space optimization) ✅

My Code Better TC then Striver 😃😃

* On the first day, you have **3 choices** (task 0, task 1, or task 2), resulting in **3 recursive calls**.
* On every subsequent day, for a given task `p`, you have exactly **2 choices** (the other two tasks), resulting in **2 recursive calls** from that point onwards.
* So time complexity is $O(3 \* 2^{n-1}))$

Striver : He was calling all three calls, and then finding max of the two whose p previous choosen is not same. (Wasting 1 call)

* So his time complexity was $O(3^n)$

Conclusion : - I was make recursive call, only with `non same task` i.e pre choosen. He was choosing out of three calls, 2 which `previous task is not same`

```cpp
// d -> day, p-> last point
int func(vector<vector<int>> arr, int d, int p, vector<vector<int>>& dp){
    if(d>=arr.size()) return 0;
    // If choosed Alternate Option : if(p!=-1 and dp[d][p]!=-1) return...
    if(dp[d][p]!=-1) return dp[d][p];

    int ans1 =0;
    int ans2 =0;
    int ans3 =0;

	// Logically we implemented :
	// if p = 0 , ans = max(ans1, ans2)
	// if p = 1 , ans = max(ans0, ans2)
	// if p = 2 . ans = max(ans0, ans1)
    if(p!=0)
    ans1 = arr[d][0] + func(arr, d+1, 0, dp);

    if(p!=1)
    ans2 = arr[d][1] + func(arr, d+1, 1, dp);

    if(p!=2)
    ans3 = arr[d][2] + func(arr, d+1, 2, dp);

	// If we choosed Alternate option
	//  if(p!=-1) return dp[d][p] = max(ans1, max(ans2, ans3));  
    // return max(ans1, max(ans2, ans3));
    return dp[d][p] = max(ans1, max(ans2, ans3));  

}

int ninjaTraining(int n, vector<vector<int>> &points)

{   
    if(n==0) return 0;
    // Alternative: If we used 3xDP  ....dp(n,vector<int>(3,-1)
    vector<vector<int>> dp(n,vector<int>(4,-1));
    
    // If choosed Alternate option : ....func(points, 0, -1, dp)
    return func(points, 0, 3, dp);
}
```

TC : O(2^n), SC:O(n)

Note: If `DP size = n` not n+1 and passing initial p=-1 `func(points, 0, -1, dp)` Then Required Changes in `func()` would be

1. using `(p!=-1)` constraint in the equation `if(dp[d][p]!=-1) return dp[d][p];`
2. `if(p!=-1) return dp[d][p] = max(ans1, max(ans2, ans3))`  `return max(ans1, max(ans2, ans3))`;

#### Why 1D dp not work

Using 1 DP Array ❌

```cpp
int func(vector<vector<int>> arr, int d, int p, vector<int>& dp){
    if(d>=arr.size()) return 0;
    if(dp[d]!=-1) return dp[d];
    
    int ans1 =0;
    int ans2 =0;
    int ans3 =0;

    if(p!=0)
    ans1 = arr[d][0] + func(arr, d+1, 0, dp);
    if(p!=1)
    ans2 = arr[d][1] + func(arr, d+1, 1, dp);
    if(p!=2)
    ans3 = arr[d][2] + func(arr, d+1, 2, dp);

    return dp[d] = max(ans1, max(ans2, ans3));  

}

int ninjaTraining(int n, vector<vector<int>> &points){   
    if(n==0) return 0;
    vector<int> dp(n,-1);
    return func(points, 0, -1, dp);
}
```

```
        1  2  5
array = 3  1  1
        3  3  3

```

Without Memoisation

```
 f(d,p) = ans=11
                                      |11
		                          func(0,-1)
		              5/             8|                      11 \          
		         a[0][0]            a[0][1]                  a[0][2] 
		           +                   +                         +
		       f(1,0)                 f(1,1)                    f(1,2)
	      4/        \4             6/        \4                6/       \4
	   a[1][1]    a[1][2]        a[1][0]   a[1][2]           a[1][0]  a[1][1]
	     +          +               +         +                 +         +
      f(2,1)      f(2,2)         f(2,0)     f(2,2)          f(2,0)       f(2,1)
    3/    \3      3/    \3     3/    \3      3/   \3        3/    \3     3/   \3  a[2,0] a[2,2] a[2,0] a[2,1] a[2,1] a[2,2] a[2,0] a[2,1]  a[2,1] a[2,2] a[2,0] [2,2]
   +      +      +      +      +      +       +      +     +      +       +    + f(3,0) f(3,2) f(3,0) f(3,1) f(3,1) f(3,-1) f(3,-1) f(3,1) f(3,1)f(3,2) f(3,0)(3,2)
  0       0       0    0      0        0      0        0     0      0    0     0 
```

With 1D DP Wrong Answer ❌

```
 f(d,p) , ans=9
                                      | 9
		                          func(0,-1)
		              4/             |6                      \5        
		         a[0][0]            a[0][1]                  a[0][2] 
		           +                   +                         +
		       f(1,0)                dp[1]✅                     dp[1]✅
	      4/        \4                = 4                         =4
	   a[1][1]    a[1][2]        
	     +          +              
      f(2,1)      dp[2]✅        
    3/    \3       = 3             
 a[2,0]  a[2,2] 
   +      +    
f(3,0)  f(3,2)
 0        0    
```

This 1d DP logic is wrong because there are two parameter on which value of a state is define

```
if you found f(1,0) and storing it as dp[1]=f(1,0)

f(1,1) and f(1,2) not necessary will be same.

Sp we Required a 2D DP
```

Tabulation + Space optimization (Chatgpt + me)

```cpp
int ninjaTraining(int n, vector<vector<int>>& points) {   

    // Base Case - Day 0
    int task0 = max(points[0][1], points[0][2]);  // max if we didn't do task 0
    int task1 = max(points[0][0], points[0][2]);  // max if we didn't do task 1
    int task2 = max(points[0][0], points[0][1]);  // max if we didn't do task 2

    // For each day from 1 to n-1
    for (int i = 1; i < n; i++) { // i = day

        // Temporary variables to store max points for each task on the current day
        int temp0 = 0, temp1 = 0, temp2 = 0;

        // Calculate max points for task0 (not doing task 0)
        temp0 = max(points[i][1] + task1, points[i][2] + task2);

        // Calculate max points for task1 (not doing task 1)
        temp1 = max(points[i][0] + task0, points[i][2] + task2);

        // Calculate max points for task2 (not doing task 2)
        temp2 = max(points[i][0] + task0, points[i][1] + task1);

        // Update all tasks for the next iteration
        task0 = temp0;
        task1 = temp1;
        task2 = temp2;
    }
    // The maximum points for the last day with any activity can be found in task0, task1, or task2

    return max(task0, max(task1, task2));  // Return overall maximum points
}
```

***

## [Unique Paths](https://www.naukri.com/code360/problems/total-unique-paths_1081470?source=youtube\&campaign=striver_dp_videos\&utm_source=youtube\&utm_medium=affiliate\&utm_campaign=striver_dp_videos)

Memoization , Tabulation, Space Optimsation✅

Memoisation by me

```cpp
int solve(int m, int n, vector<vector<int>>& dp){

    if(m<1 or n<1) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
  
    int l = solve(m-1,n,dp);
    int r = solve(m,n-1,dp);
    return dp[m][n] = l+r;

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			dp[i][j]= dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m][n];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
    
    for(int i=1; i<=n; i++){
        dp[1][i]=1;
    }
    
    for(int i=1; i<=m; i++){
        dp[i][1]=1;
    }
    
    return solve(m, n, dp);

}


// Learning, why always declare dp with size m+1, n+1, because using 1-based indexing, and prevent out of bound access of dp[m][n]

// solve(int m, int n, vector<int>& dp[]){}

//The error you're seeing is because of incorrect syntax when declaring the dp parameter. You cannot declare vector& dp[], as it is interpreted as an array of references, which is not allowed in C++.
```

Tabulation by me

```cpp
int solve(int m, int n, vector<vector<int>>& dp){

    // no need, because dp[0][0]=0
    // if(m<1 or n<1) return 0;
    
    // no need, we are starting from a position dp[2][2] that is not initialised, and so no need to check for dp[1][1]!=0, if dp[1][1]=0, for loop will not be traversed, and result same `return dp[1][1]` without this below if condition.
    // if(dp[m][n]!=0) return dp[m][n];
    
    // int l = solve(m-1,n,dp);
    // int r = solve(m,n-1,dp);
    // return dp[m][n] = l+r;

    for(int i=2; i<=m; i++){
        for(int j=2; j<=n; j++){
            dp[i][j]= dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m][n];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        dp[1][i]=1;
    }
    for(int i=1; i<=m; i++){
        dp[i][1]=1;
    }
    return solve(m, n, dp);
}
```

Space Optimization by me.

```cpp
int uniquePaths(int n, int m) {
	// Setting first row of DP matrics
    vector<int> prev(m,1);
    for(int i=1; i<n; i++){
        vector<int> curr(m);
        curr[0]=1;
        // Filling current row of DP matrics
        for(int j=1; j<m; j++){
            curr[j] = prev[j] + curr[j-1];
        }
        prev = curr; // Storing current row into previous row
    }
    
    return prev[m-1];
}
```

***

## [Unique Path II](https://www.naukri.com/code360/problems/maze-obstacles_977241?source=youtube\&campaign=striver_dp_videos\&utm_source=youtube\&utm_medium=affiliate\&utm_campaign=striver_dp_videos\&leftPanelTabValue=PROBLEM)

Memoization ✅, Tabulation ✅

```cpp
const int MOD = 1e9 + 7;
int solve(int y, int x, vector<vector<int>> &mat, vector< vector< int> > &dp ) {

    if(y<0 || x<0) return 0;
    if(dp[y][x]!=-1) return dp[y][x];
    if(mat[y][x]==-1) return dp[y][x]=0;

    int up = solve(y-1,x, mat, dp) % MOD;
    int left = solve(y,x-1, mat, dp) % MOD;
    return dp[y][x]= (up+left) % MOD;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0]=(mat[0][0]==-1)?0 : 1;
    return solve(n-1, m-1, mat, dp);
}
```

Space optimisation (because use already matrix ) by me

```cpp
const int MOD = 1e9 + 7;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {

    // why create new dp[], use the matrics given : )
    // better then space optimisation
    mat[0][0]=(mat[0][0]==-1)? 0 : 1;

    for(int j=1; j<m; j++){
        // if obstacle? than current cells and all its right set to 0
        mat[0][j]=(mat[0][j]==-1 || mat[0][j-1]==0)? 0 : 1;
    }

    for(int i=1; i<n; i++){
        mat[i][0]=(mat[i][0]==-1 || mat[i-1][0]==0 )? 0 : 1;
        for(int j=1; j<m; j++){
            // obstacle? than current cells and all its below set to 0
            if(mat[i][j]==-1) mat[i][j]=0;
            else mat[i][j]= (mat[i-1][j] + mat[i][j-1]) % MOD;
        }
    }
    return mat[n-1][m-1];
}
```


### [Construct The Array](https://www.hackerrank.com/challenges/construct-the-array/problem)