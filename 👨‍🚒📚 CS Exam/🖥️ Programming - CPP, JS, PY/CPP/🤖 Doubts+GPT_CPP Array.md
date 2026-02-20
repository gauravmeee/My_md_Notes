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

# Arrays

***

**Passing Arrays in Functions**

```cpp
// Function Definition : 
void func(int arr[5])  // ❌ size is ignored; treated as int*
void func(int arr[])  ✅
void func(int* arr) ✅
```

```cpp
// Function Call :
func(arr[]);  // ❌ Syntax Error
func(arr);  // ✅
```

***

**Can't declare array without size or initializer list**

```cpp
`int arr[]; // ❌ This will cause a compilation error.` 
```

compiler doesn't know the size of the array, You must either specify the size of the array explicitly or provide an initializer list.

***

Default Value of Elements when initialize size

```cpp
int arr[5]; // elments value are undefined
int arr[5]={}; // all element initialisez `0`
int arr[5]={1}; // first elmenent initialize `1`, rest `0`
int arr[5]={1, 2}; // arr[0] = 1, arr[1] = 2, and the rest are 0.
```

***

**Initializing Size of array should be constant**

* `int arr[a];` ❌ : if `int a=5` -> variable
* `int arr[b];` ✅ : if `const int b=5` -> constant

Note: In C++, the code `int arr[n];` ==is valid in some compilers== (like`gcc`) due to Variable Length Array (VLA) support, but it is not part of the C++ standard, which requires array sizes to be known at compile time. A better and standard-compliant approach is to use `std::vector` for dynamic arrays, as it provides safer memory management and flexibility when the array size is determined at runtime.

***

**Assignment of array should include `[]`**

* `int arr = { 1, 2, 3};` invalid in C++ ❌ : without `[]` compiler will think `arr` as Scaler Object
* `int arr[] = { 1, 2, 3};` ✅

***

**Assigning all elements to -1 (without iteration)**

```cpp
#include <algorithm>
int n = 5; // Example size 
int arr[n]; // in some compiler it is valid to use variable size but not safe
std::fill(arr, arr + n, -1); 🆕
```

***

**Method to find Size of array**

* `int n = arr.size();` not valid ❌ `size()` is part of C++ Standard Library such as std::vector, std::array
* `int n = sizeof(arr) / sizeof(arr[0]);` ✅

***

**Array should contain initialization object should be inside `{}` list initializer:**

* `int arr[] = [3, 1, 2]` ❌
* `int arr[] = {3, 1, 2}` ✅

***

**String can be Stored in Array :**

* `char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};` '\0' is the null terminator
* `char str2[] = "Hello";` str2=str1 -> are string
* `sizeof(str1)/sizeof(str1[0])` = `sizeof(str2)/sizeof(str2[0])` = **6**

***

**Sort an array**

```cpp
#include <algorithm>
int arr[] = {5, 2, 9, 1, 5, 6}; 
int n = sizeof(arr)/sizeof(arr[0]); 
sort(arr, arr + n); ⭐
```

***

**In build Swap Func**.

```cpp
#include <algorithm>
    std::swap(arr[1], arr[3]);
```

***

\*\*Passed array as Pointer and Reference in Function ? \*\* ⭐⭐

C++ requires the size of the array to be known at compile time when using array references.

**Pass as reference** If know the size at compile time

```cpp
void modifyArray(int (&arr)[5]){...}
```

In C++, if you don't know the size of the array at compile time, you cannot pass the array as a reference with a fixed size directly. but you can use Pointer. **Pass as pointer** if size not known at compile time (for similar functionality)

```cpp
void modifyArray(int* arr, int size){...}
// We can't find size of pointer so need to pass run-time/compile-time size as additional parameter
```

\#Revision Done Upto it (10 Nov 2024)✅
