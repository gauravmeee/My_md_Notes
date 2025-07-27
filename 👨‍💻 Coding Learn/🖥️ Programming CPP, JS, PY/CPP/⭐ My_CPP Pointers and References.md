

---
# Reference vs Pointer

Both references and pointers are related terms. Pointers and references are connected to a variable, but in different ways. The difference is that a pointer stores the address of the variable, while a reference acts as an alias for the variable, directly referring to its value.

### Pointer

- A pointer is a variable that **stores the address of another variable**. 
- It allows indirect access to the value stored in that variable.
- Useful for dynamic memory allocation, arrays, and data structures like linked lists.

```cpp
int* p = &x; // p points to x
```
or
```cpp
int *p;
p = &x
```

```
p -> address
*p -> value at address p
```
- `a`: is a pointer, and it stores the address of `b`.
- `*a`: can be used to access or modify the value stored at the address `a` is pointing to (i.e., the value of `b`).
- **Note**: `*a = c;` will change the value of `b` to `c`.

### Reference

- A **reference** is an **alias** for another variable.
- It must be initialized when declared and cannot refer to a different variable later.
- Simplifies function argument passing and avoids copying.

```cpp
int& r = x; // r is another name for x
```
or
```cpp
int &r;
r = x;
```

```
r -> value of x
&r -> address of x
```
- `a`: is a reference, and it directly refers to the variable `b`. It behaves as an alias to `b`.
- `&a`: gives the address of `b` (because `a` is just another name for `b`).
- **Note**: `a = c;` will change the value of `b` to `c`.


**Null Reference** (Not Allowed ❌) ⭐
```cpp
int *ptr = nullptr;
int &ref = *ptr;  // Error: dereferencing a null pointer
```

---

# Passing Pointer/Reference as Function Parameter

### Passing Pointer as Function Parameter

- Passes the **address** of a variable
- Allows modification of the original variable
- Needs `*` to access or modify the value

```cpp
void func(int* a){
	cout << a << endl;   // prints address of b
	cout << *a << endl;  // prints value of b
}

int b = 10;
func(&b);       // pass address directly

// OR
int* a = &b;
func(a);        // pass pointer
```

### Passing Reference as Function Parameter

- Passes a **reference (alias)** to the original variable
- Allows direct access/modification without dereferencing
- Simpler and safer than pointers

```cpp
void func(int& a){
	cout << a << endl;    // prints value of b
	cout << &a << endl;   // prints address of b
}

int b = 10;
func(b);         // pass by reference
```

---

# Function Pointers/Reference

### Function Pointer 

- A function pointer stores the address of a function.
- Can be reassigned to point to different functions.
- Useful for callbacks and dynamic function calls.

```cpp
int add(int x, int y) {
    return x + y;
}

int main() {
    int (*funcPtr)(int, int) = &add;   // Declare and assign
    int result = funcPtr(5, 3);        // Call via pointer
    cout << "Result: " << result << endl; // Outputs 8
}
```

### Function Reference

- A function reference is an alias for a function.
- Must be initialized during declaration and cannot be changed later.
- Safer and simpler, but less flexible than pointers.
```cpp
int add(int x, int y) {
    return x + y;
}

int main() {
    int (&funcRef)(int, int) = add;  // Reference to function
    int result = funcRef(5, 3);      // Call via reference
    cout << "Result: " << result;    // Outputs 8
}
```


---

# Pointer/Reference Advanced Understanding



```cpp
### Variable
int a = 5;  // 'a' is an integer variable initialized to 5.
a;          // Value of 'a' is 5.
&a;         // Address of 'a' in memory.
*a;         // **error**. 'a' is not a pointer, so dereferencing it with '*' is invalid.
```

**Pointer:**
```cpp
### Pointer
int b2 = 10;  // Assuming you meant to have 'b2' as an integer variable.
int *b = &b2; // 'b' is a pointer to an integer, initialized to the address of 'b2'.
b;            // Value of 'b' is the address of 'b2'.
*b;           // Dereferencing 'b', gives the value stored in 'b2', which is 10.
&b;           // Address of the pointer 'b' itself in memory.
```

**Reference :**
```cpp
### Reference
int c2 = 15;   // Assuming you meant to have 'c2' as an integer variable.
int &c = c2;   // 'c' is a reference to 'c2'.
c;             // Value of 'c' is the same as the value of 'c2', which is 15.
&c;            // Address of 'c' is the same as the address of 'c2'.
*c;            // *error** 'c' is not a pointer, so dereferencing it with '*' is invalid.
```


- **Operator `*` is used for both** 
1. <ins>declaring `pointers`</ins> - When you see `*` before a variable in a declaration, it means the variable is a pointer.
2. <ins>`dereferencing` them</ins> - When you see `*` before a pointer variable (not in a declaration), it means dereferencing that pointer to get the value it points to.

- **Operator `&` is used for both** 
1. <ins>obtaining the `address` of a variable</ins> - When you see `&` before a variable, it typically means you're getting its address.
2. <ins>declaring `references`</ins> - When you see `&` in a declaration, it means you're creating a reference.

