# Pointers

Here’s a comprehensive set of notes on pointers in C++:

### Pointers Overview

1. **Definition:**
   A pointer is a variable that stores the address of another variable. It allows indirect access to the value stored in that variable.

2. **Declaration:**
   ```cpp
   int *ptr; // Declares a pointer to an integer
   ```

3. **Initialization:**
   ```cpp
   int a = 10;
   int *ptr = &a; // ptr now holds the address of variable a
   ```

### Basic Operations

1. **Dereferencing:**
   Accessing the value at the address pointed to by the pointer.
   ```cpp
   int value = *ptr; // Gets the value of a through ptr
   ```

2. **Address-of Operator:**
   Gets the address of a variable.
   ```cpp
   int *ptr = &a; // ptr holds the address of a
   ```

3. **Pointer Arithmetic:**
   - **Increment/Decrement:** `ptr++` moves the pointer to the next memory location for the type it points to.
   - **Addition/Subtraction:** Adding or subtracting an integer from a pointer adjusts the pointer by that many elements of its type.

### Function Pointers

1. **Declaration:**
   ```cpp
   int (*funcPtr)(int, int); // Declares a pointer to a function that takes two int arguments and returns int
   ```

2. **Assignment:**
   ```cpp
   funcPtr = &someFunction; // Assigns the function's address to the pointer
   ```

3. **Usage:**
   ```cpp
   int result = funcPtr(5, 3); // Calls the function through the pointer
   ```

### Dynamic Memory Allocation

1. **New Operator:**
   Allocates memory on the heap.
   ```cpp
   int *ptr = new int; // Allocates memory for an integer
   *ptr = 10; // Assigns a value to the allocated memory
   ```

2. **Delete Operator:**
   Frees allocated memory.
   ```cpp
   delete ptr; // Frees the memory allocated for the integer
   ```

3. **Array Allocation:**
   ```cpp
   int *arr = new int[10]; // Allocates memory for an array of 10 integers
   delete[] arr; // Frees the memory for the array
   ```

### Common Pitfalls

1. **Uninitialized Pointers:**
   Pointers that are declared but not initialized can point to any random memory location, leading to undefined behavior.

2. **Dangling Pointers:**
   Pointers that continue to point to memory that has been freed. Always set pointers to `nullptr` after deleting the memory.

3. **Memory Leaks:**
   Occur when dynamically allocated memory is not freed. This can be avoided by always using `delete` or `delete[]` for every `new` or `new[]`.

4. **Pointer Arithmetic Errors:**
   Ensure pointer arithmetic is done within bounds of allocated memory to avoid accessing invalid memory locations.

### Example Code

#### Example 1: Basic Pointer Operations
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptr = &a;

    cout << "Value of a: " << *ptr << endl; // Outputs 5
    cout << "Address of a: " << ptr << endl; // Outputs the address of a

    *ptr = 10; // Modifies the value of a through the pointer
    cout << "New value of a: " << a << endl; // Outputs 10

    return 0;
}
```

#### Example 2: Function Pointers
```cpp
#include <iostream>
using namespace std;

int add(int x, int y) {
    return x + y;
}

int main() {
    int (*funcPtr)(int, int) = &add;
    int result = funcPtr(5, 3);
    cout << "Result: " << result << endl; // Outputs 8

    return 0;
}
```

#### Example 3: Dynamic Memory Allocation
```cpp
#include <iostream>
using namespace std;

int main() {
    int *ptr = new int; // Allocate memory for an integer
    *ptr = 42;
    cout << "Value: " << *ptr << endl; // Outputs 42

    delete ptr; // Free the allocated memory

    // For arrays
    int *arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
    }
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " "; // Outputs: 0 2 4 6 8
    }
    delete[] arr; // Free the array memory

    return 0;
}
```

### Summary

- Pointers are variables that store addresses of other variables.
- They enable dynamic memory management and efficient array handling.
- Proper initialization, usage, and deallocation are crucial to avoid undefined behavior and memory leaks.

---
## how modifications to pointers within a function affect the original variable.

 **Case 1: Changing the Value at the Address**

```cpp
void modifyValue(int *a) {
    *a = 10; // Modify the value at the address pointed to by 'a'
}

int main() {
    int i = 5;
    modifyValue(&i);
    cout<<i; // Prints 10
    return 0;
}
```
- **Function Call:** `modifyValue(&i)` passes the address of `i` to `modifyValue`.
- **Inside `modifyValue`:** The dereferenced pointer `*a` (which points to `i`) is set to `10`.
- **After Calling `modifyValue`:** The value of `i` is modified to `10` because `*a` points to `i` and modifies its value directly.

**Case 2: Changing the Local Pointer**

```cpp
#include <cstdio>

void changePointer(int *a) {
    int b = 20;
    a = &b; // Local pointer 'a' now points to 'b', but this does not affect the original pointer
}

int main() {
    int i = 5;
    changePointer(&i);
    cout<<i; // Still prints 5
    return 0;
}
```
- **Function Call:** `changePointer(&i)` passes the address of `i` to `changePointer`.
- **Inside `changePointer`:** The local pointer `a` is modified to point to the local variable `b`. This change affects only the local pointer `a` and does not alter the original pointer `&i`.
- **After Calling `changePointer`:** The value of `i` remains `5` because the pointer `&i` was not modified, only the local copy `a` was.

**Case 3: Modifying the Address and Value**
```cpp
#include <cstdio>

void modifyAndPoint(int *a) {
    int b = 30;
    *a = 20; // Modify the value at the original address pointed to by 'a'
    a = &b; // Change local pointer 'a' to point to 'b'
}

int main() {
    int i = 5;
    modifyAndPoint(&i);
    cout<<i; // Prints 20
    return 0;
}
```
- **Function Call:** `modifyAndPoint(&i)` passes the address of `i` to `modifyAndPoint`.
- **Inside `modifyAndPoint`:** 
  - `*a = 20;` modifies the value at the address `a` points to (which is `i`), changing `i` to `20`.
  - `a = &b;` changes the local pointer `a` to point to `b`, but this does not affect the original pointer `&i` outside the function.
- **After Calling `modifyAndPoint`:** The value of `i` is `20` because the value at the address `a` pointed to was modified, but the pointer itself remains unaffected by the change inside the function.

# References