---
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

# My Common Errors

### Error : Comparison between `long unsigned int` & `int`

```
Error -> 'std::unordered_set<int>::size_type' {aka 'long unsigned int'} and 'int' [-Wsign-compare] ❌
```

means you're **comparing two values of different signedness**:

* `arr.size()` returns `size_t` (an **unsigned** type).
* `n` is an `int` (a **signed** type).

**Fix 1 (recommended):** cast `n` to `size_t`

```cpp
if (plankNailed.size() == static_cast<size_t>(n)) {
```

**Fix 2:** declare `n` as `size_t` from the beginning:

```cpp
size_t n = A.size();
```

***

### Error: `size_t` in reverse `for` loop causing segmentation fault

```cpp
for (size_t i = A.size() - 1; i >= 0; i--) ❌ // Segmentation fault
```

**Why:**

* `size_t` is **unsigned**, so when `i == 0` and you do `i--`, it wraps to a huge value (e.g., `18446744073709551615`)
* This leads to **out-of-bounds access** → segmentation fault

**Fix:** use a signed type like `int` for reverse iteration:

```cpp
for (int i = A.size() - 1; i >= 0; i--) ✅
```

***

## Types of Errors

* **Syntax Errors** – Detected at **compile time** due to incorrect code structure.\
  &#xNAN;_&#x65;.g., missing semicolon, undeclared variable, unmatched braces._
* **Runtime Errors** – Detected during **program execution**.\
  &#xNAN;_&#x65;.g., division by zero, segmentation fault, invalid memory access._
* **Logical Errors** – Code runs without errors, but **output is wrong** due to incorrect logic.\
  &#xNAN;_&#x65;.g., wrong condition in `if`, incorrect loop bounds._

### 1. Syntax Errors

These errors occur when the code violates the grammatical rules of the C++ language. They are detected at compile-time, and the program won't compile until these errors are fixed.

**A. Missing or Misplaced Symbols**

* **Missing Semicolon** ⭐

```cpp
int main() {
	int a = 5  // Missing semicolon
	return 0;
}
```

```
error: expected ';' before 'return'
```

* **Mismatched Parentheses/Braces** ⭐

```cpp
int main() {
	if (true) {
		// Do something
	// Missing closing brace
}
```

```
error: expected '}' at end of input
```

* **Expected ')' before '}' token**

```cpp
int main() {
	if (true {
		cout << "Yes";
	}
}
```

```
error: expected ')' before '}' token
```

* **Expected primary-expression before 'xxx'**

```cpp
int main() {
	int x = ;
}
```

```
error: expected primary-expression before ';' token
```

* **Expected unqualified-id before '{' token**

```cpp
int main() {
	int = 5;
{
	cout << "Hello";
}
```

```
error: expected unqualified-id before '{' token
```

* **Missing terminating " character**

```cpp
int main() {
	cout << "Hello;
}
```

```
error: missing terminating " character
```

**B. Identifier and Declaration Issues**

* **Using Undeclared Variable/Function** ⭐

```cpp
int main() {
	cout << cnt;
}
```

```
error: 'cnt' was not declared in this scope
```

* **Invalid Identifiers**

```cpp
int 1stVariable = 10;
```

```
error: expected unqualified-id before numeric constant
```

* **Conflicting declaration**

```cpp
int x = 10;
float x = 5.5;
```

```
error: conflicting declaration 'float x'
```

* **Redeclaration of 'xxx'**

```cpp
int x;
int x;
```

```
error: redeclaration of 'int x'
```

**C. Type Errors**

* **Type Mismatch**

```cpp
int main() {
	int x = "hello";
}
```

```
error: invalid conversion from 'const char*' to 'int'
```

* **Invalid conversion from 'xxx' to 'yyy'**

```cpp
int* ptr;
double d = ptr;
```

```
error: invalid conversion from 'int*' to 'double'
```

**D. Class-Related Errors**

* **Expected class-name before '{' token**

```cpp
class Derived : Base {
};
```

```
error: expected class-name before '{' token
```

* **Invalid use of incomplete type 'class xxx'**

```cpp
class A;
A obj;
```

```
error: invalid use of incomplete type 'class A'
```

**E. Function Definition Errors**

* **A function-definition is not allowed here before '{' token**

```cpp
int main() {
	void fun() {
		// invalid
	}
}
```

```
error: a function-definition is not allowed here before '{' token
```

* **No matching function for call to 'xxx'** ⭐

```cpp
void fun(int);
int main() {
	fun();
}
```

```
error: no matching function for call to 'fun()'
```

***

### 2. Runtime Errors

These errors occur during the execution of the program, causing it to crash or behave unexpectedly. These are often harder to detect than syntax errors.

**A. Illegal Memory Access**

* **Segmentation Fault (SIGSEGV)** ⭐\
  Accessing memory not allowed by the OS (null/dangling/wild pointer).

```cpp
int* ptr = nullptr;
*ptr = 10;
```

```
Segmentation fault (core dumped)
```

* **Out of Bounds Access** ⭐\
  Accessing array index beyond declared bounds.

```cpp
int arr[5];
int x = arr[10];
```

```
Segmentation fault (core dumped)
```

**B. Arithmetic Errors**

* **Division by Zero** ⭐\
  Dividing integer or float by zero.

```cpp
int a = 10, b = 0;
int c = a / b;
```

```
Floating point exception (core dumped)
```

**C. Infinite Recursion / Stack Overuse**

* **Stack Overflow**\
  Exceeding stack memory (usually due to infinite or deep recursion).

```cpp
void recurse() {
	recurse();
}
```

```
Segmentation fault (core dumped)
```

**4. Dynamic Memory Issues**

* **Memory Leak**\
  Not releasing dynamically allocated memory.

```cpp
void memoryLeak() {
	int* ptr = new int[100]; // Never deleted
}
```

(No error immediately, but leads to memory waste)

**5. Invalid Type Conversion**

* **Invalid Type Casting**\
  Improper casting of pointers leads to undefined behavior.

```cpp
void* ptr = nullptr;
int* intPtr = static_cast<int*>(ptr);
```

(Behavior is undefined; may crash or corrupt memory)

**F. Program Aborted by Library/Internal Check**

* **Aborted (core dumped)**\
  Raised by `assert()`, STL bounds checks, or other critical failures.

```cpp
#include <cassert>
int main() {
	assert(false);
}
```

```
Aborted (core dumped)
```

***

### 3. Logical Errors

Logical errors occur when the code compiles and runs without crashing, but it produces incorrect results due to flaws in the algorithm or logic used. These errors can be the hardest to identify.

*   **Incorrect Conditions**: Using incorrect logic in conditions (e.g., using `&&` instead of `||`).

    ```cpp
    if (a && b) { // Intended to check if either a or b is true
        // Code
    }
    ```
*   **Off-by-One Errors**: Mistakes in loop boundaries or array indexing.

    ```cpp
    for (int i = 0; i <= n; i++) { // Off-by-one error if n is the size of an array
        // Code
    }
    ```
*   **Uninitialized Variables**: Using variables that haven't been initialized, leading to unpredictable behavior.

    ```cpp
    int x; 
    std::cout << x; // Using uninitialized variable
    ```
*   **Incorrect Return Values**: Functions that do not return the expected value.

    ```cpp
    int add(int a, int b) {
        return a - b; // Incorrect return operation
    }
    ```
*   **Algorithm Errors**: Implementing an algorithm incorrectly, leading to wrong results.

    ```cpp
    int factorial(int n) {
        if (n == 1) return 1; 
        return n * factorial(n - 2); // Incorrect, should be n-1
    }
    ```
