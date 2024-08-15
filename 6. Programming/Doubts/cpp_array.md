# Arrays


**Can't declare array without size or initializer list**
```cpp
`int arr[]; // This will cause a compilation error.`
```
compiler doesn't know the size of the array, You must either specify the size of the array explicitly or provide an initializer list.

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
int arr[] = {5, 2, 9, 1, 5, 6}; 
int n = sizeof(arr)/sizeof(arr[0]); 
sort(arr, arr + n);
```