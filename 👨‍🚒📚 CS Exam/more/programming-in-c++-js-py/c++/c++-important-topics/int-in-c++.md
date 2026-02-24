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

# Int in C++

`int n;`

if n in global scope `n=0` otherwise `undetermined`

`int a, b;` ✅

`int a=b=0` ❌

***

Compile Error ❌

```cpp
int func; // Variable declaration 
void func() {} // Function declaration
```

you cannot declare a function and a variable with the same name in the same scope, but you could declare them in different scope. This is because it would create ambiguity for the compiler

***

Convert `char` to its ASCII value:

```cpp
char ch = 'C'; 
int a = int(ch); ✅// Explicit conversion, ASCII value of 'C' is 67 
int b = ch; //✅ Implicit conversion, also results in 67
```

Convert `char` to its numerical value ('1' to 1):

```cpp
char ch = '5';
int a = ch - '0';  // '5' - '0' = 5-0;
// Ascii Value of 5 - Ascii Value of 0 = 5
```

***

Read a whole line (even if include whitespace)

```cpp
#include iostream
std::string str;
std::getline(std::cin, str);
```

***

```cpp
int a=1;

if(a) cout<<1, a++; ✅
if(a) cout<<1, return 1; ❌
```

Note: comma operator allows two or more expressions to be executed sequentially, but `return` is a control statement, not an expression, so it cannot be used in this way.

***

`bool` with Arithmetic Operations in C++

```cpp
bool a = true, b = false, c = 3, d = 0;
int e = 1;
int sum = a + b + c + d + e; // 1 + 0 + 1 + 0 + 1 = 3
```

* `bool` behaves like integers (`0` or `1`) in arithmetic.
* Any non-zero assigned to `bool` becomes `true` (i.e., 1).
* In expressions, `bool` values are added like `int`.

***

Cpp Invalid Variable Declaration

```cpp
int a, b, c = 0, 1, 2; // ❌ Only 'c' initialized to 2, rest are undeclared
int a = 0, int b = 1, int c = 2; // ❌ Wrong syntax
```

Cpp valid Variable Declaration

```cpp
int a = 0, b = 1, c = 2; // ✅ Preferred: single-line declaration
int a = 0; int b = 1; int c = 2; // ✅ Valid but less clean
```

* In C++, type is specified once per declaration line.
* `int a, b = 0, 1;` means only `b` is initialized with 1; `a` is uninitialized.
* Unlike Python/JS, C++ doesn’t support unpacking style (`a, b, c = 0, 1, 2`).
