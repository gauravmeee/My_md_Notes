# C++ Important Methods.

```cpp
// Reverse a String
for (int i = 0; i < n / 2; ++i) {
        swap(str[i], str[n - i - 1]);
    }
```

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

```cpp
// Graph Edge
a = [[0,1] , [1,0] , [1,2], [2,1]]

// Adjancy Matrix
If the given adjacency matrix is:
a= [ [0 1 0]
     [1 0 1]
     [0 1 0] ]
```

```cpp
// Two methods in Recursive Call, 
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

```cpp
// a = 6, b = 4

// swapping value of a & b with `temp` variable (Better TC)
temp = a // temp = 6
a = b // a = 4
b = temp // b = 6

// swapping value of a & b without `temp` variable (Better SC)
a = a + b // a = (6+4) = 10
b = a - b // b = (10-4) = 6
a = a - b // a = (10-6) = 4
```

```cpp
// Swap Function : int x=5, y=10;

//Pass by Reference : Call swap(x,y)
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
	}

// Using pointer Arguments : Call swap(&x, &y)
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	}

// Using XOR ( Bitwise Swap) ⭐
void swap(int &a, int &b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	}
```