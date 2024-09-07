# Arrays


**Can't declare array without size or initializer list**
```cpp
`int arr[]; // This will cause a compilation error.`
```
compiler doesn't know the size of the array, You must either specify the size of the array explicitly or provide an initializer list.

---
Default Value of Elements when initialize size 

```cpp
int arr[5]; // elments value are undefined
int arr[5]={}; // all element initialisez `0`
int arr[5]={1}; // first elmenent initialize `1`, rest `0`
```

---

**Initializing Size of array should be constant**
- `int arr[a];` ❌ : if `int a=5` ->
- `int arr[b];` ✅ : if `const int b=5` -> constant  
---
**Default value on Array Declaration
```cpp
// Uninitialization 
int arr[5]; // Uninitialized array, contains garbage values.

// zero initialization
int arr[5] = {0}; // All elements are initialized to 0.

// partial initialization
int arr[5] = {1, 2}; // arr[0] = 1, arr[1] = 2, and the rest are 0.
```

<hr>

**Assignment of array should include `[]`**
- `int arr = { 1, 2, 3};` invalid in C++ ❌ : without `[]` compiler will think `arr` as Scaler Object
- `int arr[] = { 1, 2, 3};` ✅
---
**Assigning all elements to -1 (without iteration)**
```cpp
#include <algorithm>
int n = 5; // Example size
int arr[n];
std::fill(arr, arr + n, -1);
```
<hr>

**Method to find Size of array**
- `int n = arr.size();` not valid ❌ `size()` is part of C++ Standard Library such as std::vector, std::array
- `int n = sizeof(arr) / sizeof(arr[0]);` ✅
<hr>

**Array should contain initialization object should be inside `{}` list initializer **
- `int arr[] = [3, 1, 2]` ❌
- `int arr[] = {3, 1, 2}` ✅
<hr>

**String can be Stored in Array :**
- `char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};` 
'\0' is the null terminator
- `char str2[] = "Hello";`  str2=str1 -> are string
---

**Sort an array**
```cpp
#include <algorithm>
int arr[] = {5, 2, 9, 1, 5, 6}; 
int n = sizeof(arr)/sizeof(arr[0]); 
sort(arr, arr + n);
```

---
**In build Swap Func**
```cpp
#include <algorithm>
    std::swap(arr[1], arr[3]);
```
---
**Passed array as Reference in Function ?**

In C++, if you don't know the size of the array at compile time, you cannot pass the array as a reference with a fixed size directly because C++ requires the size of the array to be known at compile time when using array references.

If know the size at compile time
```cpp
void modifyArray(int (&arr)[5]){...}
```

pass as pointer if size not known at compile time (for similar functionality)
```cpp
void modifyArray(int* arr, int size){...}
// We can't find size of pointer so need to pass run-time/compile-time size as additional parameter
```