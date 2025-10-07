
# C++ Important Methods.

**Reverse a String**
```cpp
for (int i = 0; i < n / 2; ++i) {
        swap(str[i], str[n - i - 1]);
    }
```

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

**Graph Edge**
```cpp
// Graph Edge
a = [[0,1] , [1,0] , [1,2], [2,1]]

// Adjancy Matrix
If the given adjacency matrix is:
a= [ [0 1 0]
     [1 0 1]
     [0 1 0] ]
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

**Swap Function**
```cpp
int x=5, y=10;

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

// Using Arithmentic Operation
void swap(int &a, int &b){
	a = a + b;
	b = a - b;
	a = a - b;
}
```


**Find Combination <sup>n</sup>C<sub>r</sub> formula**
```cpp
int nCr(int n, int r){
	long long res =1;
	for(i=0; i<r; i++){
	res = res * (n-1); *10*9*8
	res = res/(i+1); 1*2*3
	}
	return res;
}
// nCr = n!/((n-r)!*(r)!)
// 10C3 = 10*9*8/(1*2*3)
```

```cpp
//check if 

#include <cmath>

bool isPerfectSquare(int num) {
    if (num < 0) {
        return false;
    }
    int sqrtNum = static_cast<int>(sqrt(num));
    return (sqrtNum * sqrtNum == num)
}

// or

bool isPerfectSquare(int num) {
    if (num < 0) {
        return false;
    }
    double sqrtNum = sqrt(num);
    return (sqrtNum == static_cast<int>(sqrtNum)); // if double and integer are equal
}
```

---
**Calculate Ceil (x/y)**
```cpp
// (x + y - 1) / y calculates ceil(x / y):

// Exact Multiple Case:
int x1 = 6, y1 = 3;
int result1 = (x1 + y1 - 1) / y1;  // result1 = 2 (same as ceil(6 / 3))

// Non-Multiple Case:
int x2 = 7, y2 = 3;
int result2 = (x2 + y2 - 1) / y2;  // result2 = 3 (same as ceil(7 / 3))

//Note: the method `(x + y - 1) / y` only works for integer division. 
//It does not handle floating-point numbers or decimals directly.
// (6.1 + 3 - 1)/3 = 6/3 != ceil(6/3)
```
ceil(6/3) = (3 + 6 - 1 )/3 = (1 + 2 - 1/3) =  1 + 2 -1 = 2
ceil(7/3) = (3 + 7 -1)/3 = (1 + 3 -1/3) = 1 + 3 - 1 = 3