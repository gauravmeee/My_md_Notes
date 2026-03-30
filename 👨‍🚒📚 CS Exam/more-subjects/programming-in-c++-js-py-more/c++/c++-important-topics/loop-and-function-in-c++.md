---
description: Made By Me 💚
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

# Loop and Function in C++

## Function Declaration

* Functions in C++ are not allowed to be nested inside other functions like in some other languages (e.g., JavaScript or Python, where you can define functions inside other functions).
* A function must be declared and defined outside of any other function (including `main`).

```cpp
void printMessage(); // Function declaration (prototype)

int main() {
	// void Func() ❌
    printMessage(); // Function call
    return 0;
}

void printMessage() { // Function Definition
    cout << "Hello, World!" << endl;
}
```

* The declaration tells the compiler about the function before it's used in `main()`.
* The definition provides the actual code that runs when the function is called.

## Loop / Iteration

`while (int i<n) valid?` ❌ In C++, you cannot declare a variable inside the condition of a while loop.\
The variable must be declared and initialized before the loop.

***

for loop in increment \`+2\` \`for (int i=0; i

***

## Functions

in `non-void function`, it is necessary to `return` some value; `non-void` we use `return` to stop the function

***

**when not to pass variables, arrays, etc., as references in functions:**

**When to Pass by Reference:**

1. **Constant Variable Across Recursions**: Prevent unnecessary copying.
2. **Backtracking**: Allows the variable to retain its modified state after the function backtracks.

**When Not to Pass by Reference:**

1. **Avoiding Side Effects**: Ensure that the function does not modify the original variable.

Always Avoid copying. Pass large objects like arrays, vectors, or custom classes by reference to avoid the overhead of copying, especially when the object doesn’t need to be modified (use `const` reference). Always consider passing by reference for efficiency when copying would be costly in terms of time or memory.

***

**Class Function** Let permute() is a function of Solution Class.

❌ direct class function can't be called

```cpp
int main(){
    permute();
}
```

✅ create class instance and call the function

```cpp
    Solution sol; 
    sol.permute()
```

***

datatype -> declaration + initialisation

function -> declaration + definiton
