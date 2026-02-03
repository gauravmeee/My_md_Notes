
# const vs static


### `const`:

  ```cpp
  const int x = 10;  // x cannot be changed
  ```

- The `const` keyword defines a variable whose value cannot be changed after initialization (immutable).
- Enforces immutability to ensure a variable is read-only. (i++, i*=2 etc.)
- - Redeclaration, and Reinitialization Not allowed in the same scope.

 Note:
-  must be explicitly initialized at the time of declaration, they do not have a default value.
-  Can be applied to variables, function parameters, and member functions.
- Must be initialized at the point of declaration.
- Can be local or global, depending on where it is declared.

### `static`:

  ```cpp
  void func() {
      static int x = 10;  // Initialized only once
      x++;                // Can be modified
  }
  ```
  
- The `static` keyword controls the lifetime and scope of a variable or function.
- Retains the value of a variable across function calls (for local `static` variables).
- Shares the value across all instances of a class (for static member variables).
- Limits the visibility of functions and variables to the current file (file-scope).

Note:
- variables (int, float, double) have a default value of `0` (or equivalent) if not explicitly initialized.
- Can be applied to local variables, global variables, and class members.
- Initialized only once; retains its value throughout the program's execution.
- Static variables can be modified after initialization.
- Redeclaration and Reinitialization Not allowed in the same scope.

### Combined (`static const`):
- **Definition**: A variable that is both persistent (static) and immutable (const).
-  Used to define constants that retain their value throughout the program's execution.
  ```cpp
  static const int y = 100;  // y is persistent and immutable
  ```


---
## do-while loop ⭐

```cpp
int i = 0;
do { 
	std::cout << i << " ";
	i++; 
} while (i < 5);
```
Note: Unlike `while` , in `do-while` loop Condition is checked after the loop. The loop is guaranteed to execute at least once, even if the condition is `false` from the beginning.

## goto ⭐

```cpp
int num = 1;

start:  // Label

std::cout << num << " ";
num++;

if (num <= 5)
	goto start;  // Jump back to the label
```

Note: The `goto` statement in C++ is used to ==transfer control to a labeled statement== within the same function. It allows for jumping to different parts of code unconditionally.

- it's ==use is generally discouraged== because ==it makes the code harder to read and maintain== (spaghetti code). ⭐
- Use Structured programming with loops and functions

## switch-case ⭐

```cpp
int day = 3;

switch (day) {
	case 1:
		std::cout << "Monday";
		break;
	case 2:
		std::cout << "Tuesday";
		break;
	case 3:
		std::cout << "Wednesday";
		break;
	case 4:
		std::cout << "Thursday";
		break;
	case 5:
		std::cout << "Friday";
		break;
	default:
		std::cout << "Weekend";
}
```

Note: It's a multi-way branch that provides an efficient alternative to using multiple `if-else` statements when there are multiple conditions to check.

```
switch(x){
	case y: 
		// eode to execute if (y=x)
		
	case z:
		// code to execute if(y=x)
	default:
		// code to execute if none match
}
```

## Ternary Operator (`?:`)

```cpp
int max = (a>b) ? a : b;

// (condition) ? expression_if_true : expression_if_false;
```
Note: it assigns a value based on a condition.
## Range-based `for` loop 
>( In C++ 11 and above)

```cpp
int arr[] = {1, 2, 3, 4, 5};

for (int num : arr){
	std::cout << num << " "; // 1 2 3 4 4
	}
```

Note: It is a clean way to iterate over elements of an array or container without needing to use an index.

**Comma Operator (`,`)**:

```cpp
int a=5, b=10;// int a=5; int b=10
```

```cpp
int result = (a+=2, b-=2); // Both a and b are modified, but only b's result is returned
// a : 5+2 = 7
// b : 10-2 = 8
// result = b 
```

Note: allows multiple expressions to be evaluated in a single statement, with only the last expression's result being returned.

## Type Casting

```cpp
double x = 9.75;

// cast double to int
int y = x;
// or 
int y = int(x);
// or
int y = (int)x;
// or
int y = static_cast<int>(x);
```

# Lambda Expression
> C++11 and above

```cpp
auto sum = [](int a, int b) -> int {
	return a + b;
};

sum(5,3); // 5 + 3 = 8
```
Note: Lambdas provide a concise way to define anonymous functions, especially useful in short operations or callbacks.

```
[ captures ] ( parameters ) -> return_type {
    // function body
};
```

## Structured binding
> Allows unpacking of structured types like `std::pair` or `std::tuple`.

```cpp
std::tuple<int, double, char> tup = {10, 3.14, 'A'};

auto [i, d, c] = tup; // Unpacking the tuple

// i = 10;
// d = 3.14
// c = 'A'
```

## `deccltype`

Used to deduce the type of an expression at compile time.
```cpp
decltype(a) b = 20; // 'b' will have the same type as 'a'
```

---

# Lambda Function

In C++, you can declare functions inside other functions using lambdas. This is called a "local function" or "nested function". Here's a simple comparison to help understand:

```cpp
// CANNOT DO THIS - Regular function inside another function ❌
void outerFunction() {
    int regularFunction(int x) {  // This is NOT allowed in C++
        return x + 1;
    }
}
```

```CPP
// CAN DO THIS - Lambda function inside another function ✅
void outerFunction() {
    auto lambda = [](int x) {     // This is allowed!
        return x + 1;
    };
}
```

In our solution, we use a lambda because:
1. We need access to variables from the outer scope (`dp`, `n`, `developmentHours`)
2. We want to keep the recursive function local to `maxRequests`
3. It's more efficient as the function and its context are contained within `maxRequests`

Alternative approach without lambda (less preferred):
```cpp
class Solution {
private:
    map<pair<int, int>, int> dp;
    vector<int>* developmentHours;
    size_t n;
    
    int solve(int day, int remainingHours) {
        // Same logic as before
    }
    
public:
    int maxRequests(vector<int>& devHours, int availableHours) {
        dp.clear();
        developmentHours = &devHours;
        n = devHours.size();
        return solve(0, availableHours);
    }
};
```

The lambda version is cleaner as it keeps all related code together and avoids class member variables.

---

# `exit`

**Purpose:** exit(0);` is valid — it **terminates the program immediately**.
- `exit(0);` ends the program, with `0` meaning **successful termination**.    
- You can use `exit(1);` or other codes to indicate **errors**.
    

**Example:**
```cpp
if(s.at(i)!='0' && s.at(i)!='1'){
	cout << "incorrect binary format" << endl;
	exit(0); // program stops here
}
```

**Better Option in C++:**

Instead of `exit`, it's cleaner to return from the function or throw an exception:
```cpp
throw invalid_argument("Not a binary number");
```
Use `exit(0)` only when you want to **immediately stop the entire program**.