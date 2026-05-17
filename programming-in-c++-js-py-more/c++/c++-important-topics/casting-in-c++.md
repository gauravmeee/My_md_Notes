---
title: Casting in C++
---

Good question. Let’s break it clearly:

#### `int*`

* Declares a **pointer to int**.
*   Example:

    ```c
    int* p;  // p can point to an integer
    ```

#### `(int*)`

* This is a **type cast** operator.
* It tells the compiler: "Treat this value as a pointer to int".
*   Example with `malloc`:

    ```c
    int* p = (int*) malloc(sizeof(int));
    ```

Here, `malloc` returns a `void*` (generic pointer). In **C**:

* `void*` can be assigned to any pointer type **without cast**.
*   So this works fine too:

    ```c
    int* p = malloc(sizeof(int));
    ```

In **C++**:

* Implicit conversion from `void*` to other pointers is **not allowed**.
* That’s why we must use `(int*)malloc(...)` in C++.

#### Summary

* In **C**: Cast is optional → `int* p = malloc(sizeof(int));` (preferred).
* In **C++**: Cast is required → `int* p = (int*)malloc(sizeof(int));`
* Modern C++ avoids `malloc` and uses `new`/`delete`.

Do you want me to also show the **difference between malloc+free vs new+delete** in C++?


---

## **safe conversions between integers and characters in C++**, 


##### **1. Core Idea**

- `char` is just a **1-byte integer**
- Characters like `'0'`, `'1'` are stored using **ASCII values**

|Character|ASCII Value|
|---|---|
|`'0'`|48|
|`'1'`|49|

##### **2. Safe Conversions**

**Integer → Character (digit)**
```cpp
char c = digit + '0';
```
✔ Works when `digit` is between `0–9`

Example:
```cpp
int x = 1;
char c = x + '0'; // '1'
```


**Character → Integer**
```cpp
int digit = c - '0';
```

Example:
```cpp
char c = '1';
int x = c - '0'; // 1
```

---

##### **3. Unsafe Conversion (Common Mistake)**

```cpp
char c = char(1);
```

❌ Problem:
- Stores **raw value 1**
- Equivalent to `'\x01'` (non-printable)

✔ Not the same as
```cpp
char c = '1'; // value = 49
```

**Why `+ '0'` is needed**

```cpp
char(bit + '0')
```

Because:
- `bit = 0 → 0 + 48 = '0'`
- `bit = 1 → 1 + 48 = '1'`
    

**Binary Operations Case**

```cpp
ans = char(abit ^ bbit ^ carry) + ans; // ❌
```
- Produces `'\x00'` or `'\x01'`
- Not printable

```cpp
ans = char((abit ^ bbit ^ carry) + '0') + ans;  // ✅
```
- Produces `'0'` or `'1'`
    


##### **Summary Rules**

Always use:
```cpp
int → char  :  + '0'
char → int  :  - '0'
```

❌ Never assume:
```cpp
char(1) == '1'  // WRONG 
```

✔ Instead:
```cpp
char(1) == '\x01'
```


`'0'` is the **base**
- Digits are **offsets from '0'**
```
'0' + 0 → '0'
'0' + 1 → '1'
'0' + 2 → '2'
```
