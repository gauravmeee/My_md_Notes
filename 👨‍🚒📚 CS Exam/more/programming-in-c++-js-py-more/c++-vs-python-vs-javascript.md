---
description: C++ Code to Python & JavaScript
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

# C++ vs Python vs JavaScript

**Basic Syntax**

| **Feature**               | **C++**                             | **Python**                       | **JavaScript**                            |
| ------------------------- | ----------------------------------- | -------------------------------- | ----------------------------------------- |
| **Case Sensitivity**      | ✅ Case-Sensitive                    | ✅ Case-Sensitive                 | ✅ Case-Sensitive                          |
| **Blocks & Statements**   | `{ }` and `;` for multiple lines    | Indentation and newline          | `{ }` and `;` for multiple lines          |
| **Comments**              | `//` (single-line), `/* */` (multi) | `#` (single-line)                | `//` (single-line), `/* */` (multi)       |
| **Boolean Values**        | `true`, `false`                     | `True`, `False`                  | `true`, `false`                           |
| **Data Type Declaration** | `int`, `char`, `float`, etc.        | No explicit type (e.g., `a = 2`) | `let`, `const`, `var` (e.g., `var a = 2`) |
| **Characters**            | `char a = 'A';`                     | `"A"` or `'A'` (strings used)    | `"A"` or `'A'` (strings used)             |
| **Newline**               | `\n`, `endl`                        | `\n`                             | `\n`                                      |
| **Logical AND/OR**        | `&&`, \| \|                         | `and` , `or`                     | `&&`, \| \|                               |
| **Null Equivalent**       | `nullptr`, `NULL`                   | `None`                           | `null`                                    |
| **Function Declaration**  | `int add(int a, int b) {}`          | `def add(a, b):`                 | `function add(a, b) {}`                   |
| **Arrays**                | `int arr[] = {1, 2, 3, 4};`         | `arr = [1, 2, 3, 4]`             | `var arr = [1, 2, 3, 4];`                 |
| **Print Output**          | `cout << "Hello" << " " << 2;`      | `print("Hello", 2)`              | `console.log("Hello", 2);`                |
| String                    | Mutable, needs `<string>`           | Immutable, built-in              | Immutable, built-in                       |

`and`/`or`

* In **Python**, only the keywords `and` and `or` are used for logical AND/OR.
* In **C++** and **JavaScript**, only the symbols `&&` and `||` are used for logical AND/OR, but in **C++**, the keywords `and` and `or` also work if `#include <iso646.h>` is added.

**`print`**

* **Javascript & Python** : Both `print()` in Python and `console.log()` in JavaScript automatically add **whitespace** between **comma-separated values** when printing.
* **Python:** `print()` **automatically adds a newline (`\n`)** after printing. use `end=""` to prevent new line, `print("Hello", end="")` ⭐

**Comments**

* **Python:** Python does not have a built-in syntax for multi-line comments, but **Triple Quotes (`'''` or `"""`)** can be used for multi-line strings, if comment is not assigned to a variable.

```python
'''
This is a multi-line comment.
You can write multiple lines here.
'''
print("Hello, World!")
```

***

**Variable Declaration**

| **C++**                       | **JavaScript**            | **Python**                              |
| ----------------------------- | ------------------------- | --------------------------------------- |
| `std::string s = "Hello";`    | `let s = "Hello";`        | `s = "Hello"`                           |
| `char c = 'A';`               | `let c = 'A';`            | `c = 'A'`                               |
| `int n = 5;`                  | `let n = 5;`              | `n = 5`                                 |
| `const int n = 5;`            | `const n = 5;`            | `n = 5` (use `final` in advanced cases) |
| `auto x = 3.14;`              | `let x = 3.14;`           | `x = 3.14`                              |
| `const char* s = "Hi";`       | `const s = "Hi";`         | `s = "Hi"`                              |
| `int a, b = 0;` ✅ (a=garbage) | `a, b = 0` (a = b = 2 ) ✅ | `let a, b = 0;` ✅ (a=undefined)         |
| `int a, b = 1, 2;` ❌ Invalid  | `a, b = 1, 2` ✅           | `int a, b = 1, 2;` ❌ Invalid            |
|                               |                           |                                         |

**Data types**

* **C++**: Requires explicit data types (`int`, `char`, `string`). `auto` for type inference.
* **JavaScript**: Dynamic typing using `let`, `const`, and `var` (deprecated).
* **Python**: Dynamic typing, no explicit type declaration.

**Constant**

* **C++**: Use `const` for constant variables.
* **JavaScript**: Use `const` to declare immutable variables.
* **Python**: No native constant, but conventionally, uppercase names (`PI = 3.14`) indicate constants. **`""` vs `''`**
* **JavaScript & Python**: No distinction between char and string—both use `' '` or `" "`.

**`a,b=2`**

* **Python** `a, b = 2` is **valid** in Python, but it assigns `2` only to `b`, while `a` becomes `2` as well due to implicit unpacking.

***

**Loops**

| **C++**                         | **Python**                 | **JavaScript**                   |
| ------------------------------- | -------------------------- | -------------------------------- |
| `for(int i = 0; i < 5; i++)`    | `for i in range(5):`       | `for (let i = 0; i < 5; i++)`    |
| `for(int i = 1; i < 5; i++)`    | `for i in range(1, 5):`    | `for (let i = 1; i < 5; i++)`    |
| `for(int i = 1; i < 5; i += 2)` | `for i in range(1, 5, 2):` | `for (let i = 1; i < 5; i += 2)` |
| `for(auto i : str)`             | `for i in "string":`       | `for (let i of "string")`        |
| `for(auto i : arr)`             | `for i in (1,6,9):`        | `for (let i of [1,6,9])`         |

* **C++/JavaScript**: Uses **curly braces `{}`** for multi-line blocks.

***

**Conditionals**

| **Python**                                                     | **C++**                                                    | **JavaScript**                                                |
| -------------------------------------------------------------- | ---------------------------------------------------------- | ------------------------------------------------------------- |
| `if x > 1: return 1`                                           | `if (x > 1) return 1;`                                     | `if (x > 1) return 1;`                                        |
| `elif x > 2:`                                                  | `else if (x > 2)`                                          | `else if (x > 2)`                                             |
| `else:`                                                        | `else`                                                     | `else`                                                        |
| `string result = (x == 1) ? "1" : (x == 2) ? "2" : "Invalid";` | `result = "1" if x == 1 else "2" if x == 2 else "Invalid"` | `let result = (x === 1) ? "1" : (x === 2) ? "2" : "Invalid";` |

* **C++/JavaScript**: Uses **curly braces `{}`** for multi-line blocks.
* **Python**: Parenthesis `()` is Optional (`if x > 1:` works fine).
* **Python**: No native `switch` statement (use `if-elif-else`).

**Switch**

* **Python use `match-case` in 3.10+**

```python
x = 2  
match x:  
    case 1:  
        print("One")  
    case 2:  
        print("Two")   
    case _:  
        print("Invalid")  # Default case  
# Output: Two  
```

* **C++/JavaScript**: Supports `switch` for multi-branch conditions

```javascript
// Javascript                // C++

let x = 2;                   // int x = 2
switch (x) {  
    case 1:  
        console.log("1");  // cout << "1" << endl;
        break;  
    case 2:  
        console.log("2");  // cout << "2" << endl;
        break;  
    case 3:  
        console.log("3"); // cout << "3" << endl;
        break;  
    default:  
        console.log("inval");  // cout << "inval" << endl;
}
// Output: Two  
```

***

**Data Structures**

| **C++**                                                             | **Python**                          | **JavaScript**                              |
| ------------------------------------------------------------------- | ----------------------------------- | ------------------------------------------- |
| `std::vector<int> v = {1, 2, 3};`                                   | `myList = [1, 2, 3]`                | `let myList = [1, 2, 3];`                   |
| `int arr[] = {1, 2, 3};`                                            | `myArray = [1, 2, 3]`               | `const myArray = [1, 2, 3];`                |
| `std::map<string, string> my_map = { {"k1", "v1"}, {"k2", "v2"} };` | `myDict = {'k1': 'v1', 'k2': 'v2'}` | `let myObj = { 'k1': 'v1', 'k2': 'v2' };`   |
| `const int arr[] = {1, 2, 3};`                                      | `myTuple = (1, 2, 3)`               | `const myTuple = Object.freeze([1, 2, 3]);` |

* **C++:** Use `std::vector` for dynamic arrays (preferred for modern C++). Use `int arr[]` for fixed-size arrays.
* **Python & JavaScript** : Lists or Array Use same Syntax (`[]`) and are dynamic and mutable.
* **Javascript and C++**: No native tuples like Python, but `const`(for both) and `Object.freeze()`(for JS) provides immutability. ⭐
* **C++**: `std::map` is an ordered associative container (like a dictionary) and but `std::unordered_map` is unordered
* **JavaScript**: Objects (`{}`) are similar to python dictionaries but unordered by default. Use `Map` for better handling of key-value pairs.

***

**Comments**

| **C++**            | **JavaScript**     | **Python**           |
| ------------------ | ------------------ | -------------------- |
| `// Single-line`   | `// Single-line`   | `# Single-line`      |
| `/* Multi-line */` | `/* Multi-line */` | `""" Multi-line """` |

* **Javascript** and **C++** : Same syntax for comments

***

**Boolean and Falsy Values Comparison**

| **C++**                | **JavaScript**       | **Python**              |
| ---------------------- | -------------------- | ----------------------- |
|                        |                      | **Boolean Values**      |
| `true`, `false`        | `true`, `false`      | `True`, `False`         |
|                        |                      | **Falsy Values**        |
| `0`                    | `0`                  | `0`                     |
| `NULL` (or `nullptr`)  | `null`               | `None`                  |
| `false`                | `false`              | `False`                 |
| `""` (Empty String)    | `""` (Empty String)  | `""` (Empty String)     |
| `{}` (Empty Container) | `[]` (Empty Array)   | `[]` (Empty List)       |
| N/A                    | `{}` (Empty Object)  | `{}` (Empty Dictionary) |
| N/A                    | `undefined`          | N/A                     |
| N/A                    | `NaN` (Not-a-Number) | N/A                     |

* **Falsy values** evaluate to `False` in condition checks.
* **C++** doesn't have as many implicit falsy values—only `0`, `NULL`, and `false` are considered false.
* **JavaScript** has additional falsy values like `undefined` and `NaN`.

***

## Similarities and Differences By GPT

🟢 **Similarities in functionality**

| Feature                | C++                           | Python                | JavaScript                         |
| ---------------------- | ----------------------------- | --------------------- | ---------------------------------- |
| **Control Structures** | `if`, `for`, `while`          | `if`, `for`, `while`  | `if`, `for`, `while`               |
| **Object-Oriented**    | Yes (with classes)            | Yes (with classes)    | Yes (via prototypes & classes)     |
| **Modules**            | `#include` (Headers)          | `import`              | `import/export` (ES6)              |
| **Functions**          | Yes (with overloading) ⭐      | Yes (first-class)     | Yes (first-class)                  |
| **Loops & Iteration**  | `for`, `while`                | `for`, `while`        | `for`, `while`, `forEach` ⭐        |
| **Error Handling**     | `try-catch`                   | `try-except` ⭐        | `try-catch` (async error handling) |
| **Data Structures**    | Arrays, Vectors               | Lists, Dicts ⭐        | Arrays, Objects                    |
| **Boolean Values**     | `true`, `false`               | `True`, `False` ⭐     | `true`, `false`                    |
| **Lambda Functions**   | Yes (`[=](int x){return x;}`) | Yes (`lambda x: x+1`) | Yes (`(x) => x + 1`)               |

* 🔴 **Differences in Functionality**

| Feature               | C++                            | Python                         | JavaScript                           |
| --------------------- | ------------------------------ | ------------------------------ | ------------------------------------ |
| **Compilation**       | Compiled (to machine code) ⭐   | Interpreted (Bytecode)         | Interpreted (JIT)                    |
| **Typing System**     | Static (compile-time) ⭐        | Dynamic (runtime)              | Dynamic (runtime)                    |
| **Variables**         | Strongly typed ⭐               | Dynamically typed              | Dynamically typed                    |
| **Memory Management** | Manual (with `new`/`delete`) ⭐ | Automatic (Garbage collection) | Automatic (Garbage collection)       |
| **Performance**       | Fast (close to hardware) ⭐     | Slower than C++                | Slower than C++ (Browser-optimized)  |
| **Pointers**          | Yes (direct memory access) ⭐   | No                             | No                                   |
| **Syntax Style**      | Curly braces `{}`              | Indentation (whitespace) ⭐     | Curly braces `{}`                    |
| **Main Entry Point**  | `int main()`                   | `if __name__ == "__main__"`    | No strict entry point ⭐              |
| **Use Case**          | System-level, performance apps | Data Science, Automation       | Web development (Frontend + Backend) |
| **Inheritance**       | Multiple & Virtual Inheritance | Single & Multiple Inheritance  | Prototype-based Inheritance          |
| **Concurrency**       | Threads (std::thread)          | GIL (Global Interpreter Lock)  | Asynchronous (Event loop, Promises)  |
