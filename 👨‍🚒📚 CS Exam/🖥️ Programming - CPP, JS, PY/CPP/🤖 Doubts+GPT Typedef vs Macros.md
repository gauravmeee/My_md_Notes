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

# Typedef vs Macros

**1. Purpose**

* **typedef**: Used to create an ==alias (alternative name) for a data type==.
* **macro (#define)**: Used to ==define constants or code substitutions== (including type names).

**2. Syntax**

* **typedef**

```cpp
typedef existing_type new_name;
```

* **macro**

```cpp
# define new_name existing_type
```

**3. Examples**

* **typedef**

```cpp
// Using typedef
typedef unsigned int uint;
uint x = 10;   // same as unsigned int x
```

* **macro**

```cpp
// Using macro
#define uint unsigned int
uint y = 20;   // same as unsigned int y
```

**4. Scope**

* **typedef**: Respects C++ scope rules (==limited to the scope where declared==).
* **macro**: ==Global==, once defined applies everywhere until `#undef`.

**5. Type Safety**

* **typedef**: Compiler is aware of the alias, provides better type checking

```cpp
typedef char* string_t;
string_t a, b;   // both a and b are char*
```

* **macro**: Preprocessor substitution, no type awareness.

```cpp
#define string_m char*
string_m c, d;   // only c is char*, d is just char
```

**6. Debugging / Error Messages**

* **typedef**: Error messages show the alias properly.
* **macro**: Compiler shows substituted type, making debugging harder.

**7. Complex Types (struct, pointer, function pointer)**

* **typedef**

```cpp
// typedef example
typedef int* int_ptr;
int_ptr p1, p2;   // both are int*

// typedef struct
typedef struct {
    int x, y;
} Point;

Point p = {1, 2};
```

* **macro**

```cpp
// macro example
#define int_ptr2 int*
int_ptr2 q1, q2;  // q1 is int*, q2 is int (wrong expectation) ⭐
```

**8. Functions & Templates**

* **typedef**: Can be used for function pointers and complex template types. ⭐

```cpp
typedef int (*funcPtr)(int, int);
funcPtr add;  // function pointer
```

* **macro**: Cannot handle templates well (preprocessor only does text replacement).

```
#define funcPtr2 int (*)(int, int)  // messy and error-prone
```

**9. Best Practice**

* Prefer **typedef** (or `using` in modern C++) over macros for defining types.
* Use **macros** only for constants (before `const`, `constexpr`, `enum class` existed).
