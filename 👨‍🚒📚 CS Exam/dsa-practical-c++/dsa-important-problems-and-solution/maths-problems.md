
#### Fibonacci Without Recursion

```cpp
void fib(int N) {
    int a = 0, b = 1;
    for(int i = 0; i < N; i++) {
        cout << a << " ";
        int temp = a + b;
        a = b;
        b = temp;
    }
}
```


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

ceil(6/3) = (3 + 6 - 1 )/3 = (1 + 2 - 1/3) = 1 + 2 -1 = 2 ceil(7/3) = (3 + 7 -1)/3 = (1 + 3 -1/3) = 1 + 3 - 1 = 3

**Find Combination `nCr` formula**

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

**Find if a Number is Perfect Square**

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

