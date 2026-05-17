---
title: Recursion Problems
---

**No. of ways to climb**

```cpp
// no. of ways to climb(possible step 1,2)
int climbStairs(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
```

```cpp
// no. of ways to climb(possible step 1,2,3) using DP
int climbStairs(int n) {
        int arr[n+1];
        arr[0]=1;
        arr[1]=1;
        for(int i=2; i<=n; i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
```

**Two methods in Recursive Call :**

```cpp
//Sum of all number in arr = [1, 3, 4, 5], n = 4

// 1. passing extra `n` and `ind=0`  | Call : f(0, arr, n, 0)
	f(int ind, int arr[], int n, int &sum){ 
		if(ind >= n) return sum;
		sum = sum + arr[ind];
		ind = ind + 1;
		f(ind, arr, n, sum); 
		}

// 2. passing only `ind=n` |  Call : f(n, arr, 0)
	f(int ind, int arr[], int &sum){
		if(ind < 0) return sum;
		sum = sum + arr[ind];
		ind = ind - 1;
		f(ind, arr, sum); 
		}
```