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

# C++ Preparation SJVN

#### Questions

Here’s a set of **practice questions for C/C++** that cover common competitive/programming exam topics:

**Expression Evaluation & Operators**

1. What is the value of `int a = 5; int b = a++ + ++a;`?
2. Evaluate: `(3 && 0) || (2 || 0)`
3. What is the output of `printf("%d", 10 & 3 | 2);`?

**Variables & Scope**\
4\. Difference between `auto`, `register`, `static`, and `extern` variables.\
5\. What will be printed if a **local static variable** is incremented in a function called multiple times?

**Constants & Literals**\
6\. Which of the following is a valid octal constant: `075`, `089`, `0x1F`?\
7\. How do you define a **long double constant**?\
8\. Difference between `const int x = 10;` and `#define X 10`.

**Arrays & Pointers**\
9\. What is the difference between `char *p` and `char arr[]`?\
10\. What is printed by `printf("%d", sizeof(arr)/sizeof(arr[0]));`?\
11\. Can you increment a pointer to a multi-dimensional array?

**Strings & I/O**\
12\. Difference between `gets()`, `fgets()`, and `scanf("%s")`.\
13\. What happens if you forget `\0` at the end of a string?\
14\. Explain `strlen`, `strcpy`, `strcmp` with examples.

**Functions & Recursion**\
15\. Difference between **call by value** and **call by reference**.\
16\. Write a recursive function to calculate factorial.\
17\. What is a function pointer and how is it used?

**Control Statements**\
18\. Difference between `while` and `do-while`.\
19\. What is the output of nested loops with `break` and `continue`?\
20\. Explain switch-case fallthrough with an example.

**Preprocessor & Macros**\
21\. Difference between `#include <file>` and `#include "file"`.\
22\. What is the output of using `#define SQR(x) x*x` in `SQR(1+2)`?

**Miscellaneous**\
23\. Difference between `NULL`, `nullptr`, and `0` in C++.\
24\. What is the result of `sizeof(char*)`, `sizeof(int*)` on a 64-bit machine?\
25\. Explain short-circuit evaluation with `&&` and `||`.

#### Answers

**Expression Evaluation & Operators**

1. `int a = 5; int b = a++ + ++a;`
   * **Answer:** `b = 12`
   * **Explanation:** `a++` uses `5`, then `a` becomes `6`; `++a` increments to `7` then uses it → `5 + 6`? Actually compute step by step:
     * `a = 5`
     * `a++` = 5, `a = 6`
     * `++a` = 7, `a = 7`
     * `b = 5 + 7 = 12` ✅ Correction: b = 12
2. `(3 && 0) || (2 || 0)`
   * **Answer:** `1`
   * **Explanation:**
     * `3 && 0` → `0` (false)
     * `2 || 0` → `1` (true)
     * `0 || 1` → `1`
3. `printf("%d", 10 & 3 | 2);`
   * **Answer:** `2`
   * **Explanation:**
     * `10 & 3` → `1010 & 0011` = `0010` = 2 ⭐
     * `2 | 2` → `2`

**Variables & Scope**

4. `auto`, `register`, `static`, `extern`
   * **Answer / Explanation:**
     * `auto` → default local variable
     * `register` → ==hint to store in CPU register==
     * `static` → retains value, scope limited (local static) or file-level (global static)
     * `extern` → global variable declared in another file
5.  Local static variable incremented multiple times

    ```c
    void fun() {
        static int x = 0;
        x++;
        printf("%d ", x);
    }
    ```

    * **Answer:** `1 2 3 ...` on repeated calls
    * **Explanation:** `static` retains value across function calls
    * Even if you write ==`static int x = 0;` **inside the function**, the initialization happens **only once**==, when the program first encounters the function. On subsequent calls, `x` **keeps its previous value**; it is **not re-initialized**.

**Constants & Literals** 6. Valid octal constant: `075` ✅, `089` ❌, `0x1F` ❌ (hexadecimal)

7.  Long double constant:

    ```c
    long double x = 3.14159L;
    ```
8. Difference:
   * `const int x = 10;` → type-checked, read-only
   * `#define X 10` → preprocessor text substitution, no type checking

**Arrays & Pointers** 9. `char *p` vs `char arr[]` - `char *p` → pointer, can point elsewhere - `char arr[]` → actual array in memory, cannot be reassigned

10. `sizeof(arr)/sizeof(arr[0])` → number of elements in array
11. Pointer increment in multi-dimensional array: yes, pointer arithmetic depends on row/column layout

**Strings & I/O**

12. `gets()` → ==reads until newline==, unsafe\
    `fgets()` → reads max n chars, includes newline, safe\
    `scanf("%s")` → ==reads until whitespace==
13. Forget `\0` → undefined behavior when using string functions
14. `strlen` → length of string\
    `strcpy` → copy string\
    `strcmp` → compare strings

**Functions & Recursion**

15. Call by value → copies value, original unchanged\
    Call by reference → modifies original variable
16. Factorial (recursive):

```c
int fact(int n){ return (n<=1)?1:n*fact(n-1); }
```

17. Function pointer: stores address of function ⭐

```c
int (*fp)(int,int) = &add; fp(2,3);
```

**Control Statements** 18. `while` → check condition before execution\
`do-while` → executes at least once

19. Nested loops: `break` exits loop, `continue` skips current iteration
20. Switch-case fallthrough: no `break` → executes next case

**Preprocessor & Macros**

21. `#include <file>` → ==system headers==\
    `#include "file"` → ==user-defined files==
22. `#define SQR(x) x*x; SQR(1+2)` → expands to `1+2*1+2 = 5` ❌ (wrong math if not parenthesized) ⭐⭐

**Miscellaneous**

23. `NULL` → 0 in C, `nullptr` → C++11 null pointer, `0` → integer literal usable as null
24. `sizeof(char*) = 8`, `sizeof(int*) = 8` (on 64-bit machine)
25. Short-circuit: `&&` stops if first is false, `||` stops if first is true
