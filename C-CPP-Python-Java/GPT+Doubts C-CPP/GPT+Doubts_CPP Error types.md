
### 1. Syntax Errors

These errors occur when the code violates the grammatical rules of the C++ language. They are detected at compile-time, and the program won't compile until these errors are fixed.

- **Missing Semicolon**: Forgetting to end a statement with a semicolon.
  ```cpp
  int main() 
  {
      int a = 5  // Missing semicolon
      return 0;
  }
  ```

- **Mismatched Parentheses/Braces**: Not having matching opening and closing parentheses or braces.
  ```cpp
  int main() 
  {
      if (true) {
          // Do something
      // Missing closing brace for the if statement
  }
  ```

- **Type Mismatch**: Assigning a value of one type to a variable of another incompatible type.
  ```cpp
  int x = "hello"; // Type mismatch
  ```

- **Invalid Identifiers**: Using invalid characters in variable or function names.
  ```cpp
  int 1stVariable; // Invalid identifier
  ```

---
### 2. Runtime Errors

These errors occur during the execution of the program, causing it to crash or behave unexpectedly. These are often harder to detect than syntax errors.

- **Segmentation Fault (SIGSEGV)**: Accessing invalid memory, such as dereferencing a null pointer.
  ```cpp
  int* ptr = nullptr;
  *ptr = 10; // Causes segmentation fault
  ```

- **Division by Zero**: Attempting to divide a number by zero, which leads to undefined behavior.
  ```cpp
  int a = 10, b = 0;
  int c = a / b; // Causes runtime error
  ```

- **Stack Overflow**: Occurs due to excessive use of stack memory, often from deep recursion without a proper base case.
  ```cpp
  void recurse() {
      recurse(); // Causes stack overflow
  }
  ```

- **Memory Leak**: Not freeing dynamically allocated memory, leading to wasted resources.
  ```cpp
  void memoryLeak() {
      int* ptr = new int[100]; // Memory allocated but never deleted
  }
  ```

- **Out of Bounds Access**: Accessing an array element outside its bounds.
  ```cpp
  int arr[5];
  int x = arr[10]; // Out of bounds access
  ```

- **Invalid Type Casting**: Performing an invalid type cast that leads to unexpected behavior.
  ```cpp
  void* ptr = nullptr;
  int* intPtr = static_cast<int*>(ptr); // Invalid cast, leads to undefined behavior
  ```

---
### 3. Logical Errors

Logical errors occur when the code compiles and runs without crashing, but it produces incorrect results due to flaws in the algorithm or logic used. These errors can be the hardest to identify.

- **Incorrect Conditions**: Using incorrect logic in conditions (e.g., using `&&` instead of `||`).
  ```cpp
  if (a && b) { // Intended to check if either a or b is true
      // Code
  }
  ```

- **Off-by-One Errors**: Mistakes in loop boundaries or array indexing.
  ```cpp
  for (int i = 0; i <= n; i++) { // Off-by-one error if n is the size of an array
      // Code
  }
  ```

- **Uninitialized Variables**: Using variables that haven't been initialized, leading to unpredictable behavior.
  ```cpp
  int x; 
  std::cout << x; // Using uninitialized variable
  ```

- **Incorrect Return Values**: Functions that do not return the expected value.
  ```cpp
  int add(int a, int b) {
      return a - b; // Incorrect return operation
  }
  ```

- **Algorithm Errors**: Implementing an algorithm incorrectly, leading to wrong results.
  ```cpp
  int factorial(int n) {
      if (n == 1) return 1; 
      return n * factorial(n - 2); // Incorrect, should be n-1
  }
  ```
