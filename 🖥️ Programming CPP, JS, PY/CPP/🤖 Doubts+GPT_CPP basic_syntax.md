## Int
`int n;`

if n in global scope `n=0`
otherwise `undetermined`

`int a, b;` ✅

`int a=b=0` ❌

---
Compile Error ❌
```cpp
int func; // Variable declaration 
void func() {} // Function declaration
```

you cannot declare a function and a variable with the same name in the same scope, but you could declare them in different scope. This is because it would create ambiguity for the compiler

---

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

---

Read a whole line (even if include whitespace)
```cpp
#include iostream
std::string str;
std::getline(std::cin, str);
```

---


```cpp
int a=1;

if(a) cout<<1, a++; ✅
if(a) cout<<1, return 1; ❌
```
Note: comma operator allows two or more expressions to be executed sequentially, but `return` is a control statement, not an expression, so it cannot be used in this way.