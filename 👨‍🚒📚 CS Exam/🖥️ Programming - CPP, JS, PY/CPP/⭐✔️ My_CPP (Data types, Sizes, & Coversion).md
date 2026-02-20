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

# ⭐✔️ My\_CPP (Data types, Sizes, & Coversion)

#### Range of Number in C++

**32-bit Data Types**

| Data Type        | Power of 2   | Actual Range                    | Power Range          | Power of 10    |
| ---------------- | ------------ | ------------------------------- | -------------------- | -------------- |
| `int`            | ±2³¹         | −2,147,483,648 to 2,147,483,647 | ±2 billion           | ±2 × 10⁹       |
| `unsigned int`   | 0 to ==2³²== | 0 to 4,294,967,295              | 0 to ==4 billion==   | 0 to 4 × 10⁹   |
| `short`          | ±2¹⁵         | −32,768 to 32,767               | ±32 thousand         | ±3.2 × 10⁴     |
| `unsigned short` | 0 to ==2¹⁶== | 0 to 65,535                     | 0 to ==65 thousand== | 0 to 6.5 × 10⁴ |

**64-bit Data Types**

| Data Type            | Power of 2   | Actual Range                                            | Power Range             | Power of 10    |
| -------------------- | ------------ | ------------------------------------------------------- | ----------------------- | -------------- |
| `long long`          | ±2⁶³         | −9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | ±9 quintillion          | ±9 × 10¹⁸      |
| `unsigned long long` | 0 to ==2⁶⁴== | 0 to 18,446,744,073,709,551,615                         | 0 to ==18 quintillion== | 0 to 18 × 10¹⁸ |

**Platform-Independent Data Types (32/64 bit)**

| Data Type                                                                             | Behavior                                                                | Power of 2                        | Actual Range       | Power Range                                        | Power of 10                         |
| ------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- | --------------------------------- | ------------------ | -------------------------------------------------- | ----------------------------------- |
| <p><code>long</code> (32-bit)<br><br><code>long</code> (64-bit)</p>                   | <p><code>int</code><br><br><code>long long</code></p>                   | <p>±2³¹<br><br>±2⁶³</p>           | Platform-dependent | <p>±2 billion<br><br>±9 quintillion</p>            | <p>±2 × 10⁹<br><br>±9 × 10¹⁸</p>    |
| <p><code>unsigned long</code> (32-bit)<br><br><code>unsigned long</code> (64-bit)</p> | <p><code>unsigned int</code><br><br><code>unsigned long long</code></p> | <p>==0–2³²==<br><br>==0–2⁶⁴==</p> | Platform-dependent | <p>0–==4 billion==<br><br>0–==18 quintillion==</p> | <p>0–4 × 10⁹<br><br>0–18 × 10¹⁸</p> |
| <p><code>size_t</code> (32-bit)<br><br><code>size_t</code> (64-bit)</p>               | <p><code>unsigned int</code><br><br><code>unsigned long long</code></p> | <p>==0–2³²==<br><br>==0–2⁶⁴==</p> | Platform-dependent | <p>0–4 billion<br><br>0–==18 quintillion==</p>     | <p>0–4 × 10⁹<br><br>0–18 × 10¹⁸</p> |

**Notes on `size_t` and Unsigned Types**

* **`size_t`** is always **unsigned**.
* On most platforms, `unsigned long` and `size_t` are **the same size**.
* `size_t` is preferred for **array indices, container sizes, and memory sizes**.
* Using `size_t` ensures **portability and correctness** across platforms.
* `unsigned long` is a general-purpose unsigned integer; size may vary depending on platform.

**Platform-Independent Datatypes**

* **32-bit**
  * `int / unsigned int` ≡ `long / unsigned long`
  * `size_t` (32-bit) ≡ `unsigned int` ≡ `unsigned long`
* **64-bit**
  * `unsigned long long` ≡ `size_t` (64-bit) ≡ `unsigned long` (64-bit)
  * `long long / unsigned long long` ≡ `long / unsigned long` (64-bit)

**Summary by Size**

| Bit Size         | Typical Types                                             |
| ---------------- | --------------------------------------------------------- |
| 15-bit           | `short` / `unsigned short`                                |
| 32-bit           | `int` / `unsigned int`                                    |
| 32-bit or 64-bit | `size_t`, `long` / `unsigned long` (platform-independent) |
| 64-bit           | `long long` / `unsigned long long`                        |

* **Key Idea:** Use `size_t` or `long / long long` for **portable code**, especially when handling object sizes, memory, or array indices.

***

#### Datatypes in C++

| Data Type            | Size (bytes) | Range                                                                                                    | Power of 2                   |
| -------------------- | ------------ | -------------------------------------------------------------------------------------------------------- | ---------------------------- |
| `char`               | ==1==        | -128 to 127                                                                                              | ±2⁷                          |
| `unsigned char`      | 1            | 0 to 255                                                                                                 | 0–2⁸                         |
| `short`              | ==2==        | -32,768 to 32,767                                                                                        | ±2¹⁵                         |
| `unsigned short`     | 2            | 0 to 65,535                                                                                              | 0–2¹⁶                        |
| `int`                | ==4==        | -2,147,483,648 to 2,147,483,647                                                                          | ±2³¹                         |
| `unsigned int`       | 4            | 0 to 4,294,967,295                                                                                       | 0–2³²                        |
| `long`               | 4 or 8       | -2,147,483,648 to 2,147,483,647 (32-bit)-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (64-bit) | ±2³¹ (32-bit)±2⁶³ (64-bit)   |
| `unsigned long`      | 4 or 8       | 0 to 2³² (32-bit)0 to 18,446,744,073,709,551,615 (64-bit)                                                | 0–2³² (32-bit)0–2⁶⁴ (64-bit) |
| `long long`          | ==8==        | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807                                                  | ±2⁶³                         |
| `unsigned long long` | 8            | 0 to 18,446,744,073,709,551,615                                                                          | 0–2⁶⁴                        |
| `wchar_t`            | 2 or 4       | Depends on platform (UTF-16/UTF-32)                                                                      | Varies                       |
| `bool`               | 1            | false (0) or true (1)                                                                                    | N/A                          |
| `float`              | 4            | ±3.4 × 10³⁸ (approx)                                                                                     | N/A                          |
| `double`             | 8            | ±1.7 × 10³⁰⁸ (approx)                                                                                    | N/A                          |
| `long double`        | 8, 10, or 16 | Platform-dependent (typically 15–18 decimal digits)                                                      | Varies                       |
| `float128`           | 16           | ±1.1897 × 10⁴⁹³² (approx)                                                                                | ±2¹²⁷                        |
| `std::string`        | Varies       | Depends on string content                                                                                | N/A                          |
| `std::vector<T>`     | Varies       | Depends on number of elements                                                                            | N/A                          |

**Notes**

* **Size**: Can vary depending on platform and compiler.
* **Range**: Floating-point ranges are approximate; precision may vary.
* **`wchar_t`**: 2 bytes (UTF-16) or 4 bytes (UTF-32) depending on platform.
* **`float128`**: Non-standard, available in some compilers for higher precision.
* **`long` / `unsigned long`**: 32-bit or 64-bit depending on platform.
* **Use `size_t`** for array indices, container sizes, or memory sizes to ensure portability.

**NULL & nullptr**

* **`NULL`**
  * An integer constant, ==typically defined as `0`==.
  * Can lead to **type ambiguity** in function overloading or pointer assignments.
* **`nullptr`** (C++11)
  * A keyword representing a **null pointer** of type `std::nullptr_t`.
  * Provides **type safety** and avoids ambiguity.

**Example:**

```cpp
int* p1 = NULL;    // allowed, but can be ambiguous
int* p2 = nullptr; // type-safe, preferred in modern C++
```

***

#### Data Type Conversions

**1. Implicit Type Conversion (Automatic Conversion / Type Promotion)**

**Occurs Automatically When:**

* Expressions involve different data types
* Assigning a value to a variable of a different type
* Passing arguments to functions or returning values

**Common Type Promotion Sequence:** ⭐

```
bool → char → short → int → unsigned int → long → unsigned long → float → double → long double
```

**Integer Promotions:**

* Types smaller than `int` (`char`, `bool`, `short`) are **promoted to `int`** if `int` can represent all their values.
* Ensures consistent arithmetic operations on smaller integer types.

**Example:**

```cpp
char c = 100;
int x = c + 50;  // char promoted to int before addition ⭐
```

**2. Explicit Type Conversion (Manual Conversion)**

**C style cast** ⭐

```cpp
int x = (int)3.14; // (type)expression
```

**C++ style cast** (safer) ⭐

```cpp
int x = static_cast<int>(3.14); // static_cast<type>(expression)
```

**C++ Cast Operators:**

1. `static_cast<T>(expression)` : Converts between compatible types (e.g., int → float, base ↔ derived)
2. `const_cast<T>(expression)` : Used to add/remove `const` or `volatile` qualifier
3. `reinterpret_cast<T>(expression)` : Converts one pointer type to another (very low-level)
4. `dynamic_cast<T>(expression)` : Used for safe downcasting in inheritance (needs polymorphism)

**3. User-Defined Conversion**

**1. Conversion Constructor** ❓⭐

* Converts a value of one type to a class type.

```cpp
class A {
public:
    A(int x); // int → A
};
```

**2. Conversion Operator** ❓⭐

* Converts a class type to another type.

```cpp
class A {
public:
    operator int(); // A → int
};
```

**Usage:**

* \==Conversion constructors== ==allow implicit or explicit construction from another type==.
* \==Conversion operators== ==enable objects to be used where another type is expected==.

**4. Standard Conversion Sequences**

Common implicit conversions applied automatically by the compiler:

* **Lvalue-to-rvalue**: Converts a variable to its value.
* **Array-to-pointer**: Array decays to pointer to its first element.
* **Function-to-pointer**: Function name decays to pointer to function.
* **Integral promotions**: Small integers promoted to `int`.
* **Floating-point promotions**: `float` promoted to `double`.
* **Qualification conversions**: e.g., `T*` → `const T*`.

**5. Pointer Conversions**

* `Derived*` → `Base*` (implicit upcast)
* `void*` ↔ any pointer (requires cast for specific type)
* `nullptr` → any pointer type (implicit)

**Coversion Summary Table:**

| Conversion Type        | Requires Cast | Safe?     | Keyword(s)           |
| ---------------------- | ------------- | --------- | -------------------- |
| Implicit Promotion     | No            | Yes       | —                    |
| C-style Cast           | Yes           | Risky ❌   | `(type)`             |
| `static_cast`          | Yes           | Yes       | `static_cast<>`      |
| `const_cast`           | Yes           | Limited ❌ | `const_cast<>`       |
| `reinterpret_cast`     | Yes           | Unsafe ❌  | `reinterpret_cast<>` |
| `dynamic_cast`         | Yes           | Yes       | `dynamic_cast<>`     |
| Conversion Constructor | No (implicit) | Yes       | Constructor          |
| Conversion Operator    | No (implicit) | Yes       | `operator type()`    |

***

#### Type Conversion & Rounding in C++

**Double to Integer Conversion**

1. **Direct Assignment (Truncation)** Assigning a `double` to an `int` variable truncates the decimal part, effectively rounding toward zero.

```cpp
// implicit truncate
double num = 2.9;
int truncated = num;  // truncated = 2
```

2. **`static_cast<int>()` (Truncation)** Assigning a `double` to an `int` variable truncates the decimal part, effectively rounding toward zero.

```cpp
// explicitly truncate
double num = 3.7;
int result = static_cast<int>(num);  // result = 3

```

3. **`round()`** Rounds the `double` to the nearest integer. ( If exactly halfway, it ==rounds toward positive infinity==. ) ⭐

```cpp
double num = 2.5;
int rounded = round(num);  // rounded = 3
// round(2.5) -> 3
// round(-1.5) -> -1
```

4. **`floor()`** Rounds down to the nearest integer (==toward negative infinity==). ⭐

```cpp
double num = 2.9;
int floored = floor(num);  // floored = 2
// floor(2.9) -> 2
// floor(-1,1) -> -2
```

5. **`ceil()`** Rounds up to the nearest integer (==toward positive infinity==).

```cpp
double num = 2.1;
int ceiled = ceil(num);  // ceiled = 3
// ceil(2.1) -> 3 
// ceil(-1.7) gives -1
```

**Notes:**

* For all three functions `floor()`, `ceil()`, `round()` use `#include <cmath>`
* **`floor(x)`** → rounds **down** to nearest integer (≤ x)
* **`ceil(x)`** → rounds **up** to nearest integer (≥ x)
* **`round(x)`** → rounds to **nearest integer**, halves go **toward +∞** for positive, **toward 0** for negative.

**Integer Division in C++ ⭐**

*   `int / int` → result is **int**, fractional part truncated.

    ```cpp
    int a = 7, b = 2;
    int c = a / b; // c = 3
    ```
* To get a **floating-point result**, cast one operand:

```cpp
double d = static_cast<double>(a) / b; // d = 3.5
```
