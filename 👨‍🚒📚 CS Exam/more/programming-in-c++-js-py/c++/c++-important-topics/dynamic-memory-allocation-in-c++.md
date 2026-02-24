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

# Dynamic Memory Allocation in C++

#### Dynamic Memory Allocation in C++ (Pointers) ⭐

* **Dynamic Memory Allocation** -> allows allocating memory at **runtime** from the **heap** using pointers.
* This provides flexibility when the size of data is not known at compile time.

**Allocating Memory to a Variable (`new`)**

```cpp
int *ptr = new int;  // Allocates memory for a single integer on heap
*ptr = 10;   // Assigns value to the allocated memory
delete ptr;    // Frees the allocated memory
```

* `new` returns the address of the allocated memory.
* `delete` must be used to free the memory to avoid leaks.

**Allocating Memory for Arrays (`new[]`) ⭐**

```cpp
int *arr = new int[10];  // Allocates memory for array of 10 integers ⭐
*(arr+2) = 10 // // Assigns 10 to the 3rd element
delete[] arr;   // Frees the memory allocated for array  ⭐
```

* Use `new[]` for array allocation i.e. to allocate continuous block of memory.
* Always use `delete[]` for deallocating arrays, not `delete`.
* You can also use `arr[i]` to assign and access elements. It is equivalent to `*(arr + i)`

**Common Mistakes (Pointer) :**

1. **Uninitialized Pointers:** Pointers that are declared but not initialized ==can point to any random memory location==, leading to ==undefined behavior==.
2. \==**Dangling Pointers:**== Pointers that continue to point to memory that has been freed. Always ==set pointers to `nullptr` after deleting the memory==. ⭐
3. \==**Memory Leaks:**== Occur when dynamically ==allocated memory is not freed==. This can be avoided by always using `delete` or `delete[]` for every `new` or `new[]`. ⭐
4. **Pointer Arithmetic Errors:** Ensure pointer arithmetic is done within bounds of allocated memory to avoid accessing invalid memory locations.

***

#### NULL POINTER

A ==**null pointer**== in C++ is a ==pointer that is not pointing to any valid memory location==. It essentially represents an absence of an object or an uninitialized pointer. Here’s a breakdown of what null pointers are and how they are used:

**Definition:**

* **Null Pointer** : A ==pointer variable that is assigned a special value== (often `nullptr` in modern C++) to indicate that it is not currently pointing to any valid memory address.

**Representation** ⭐

```cpp
// `nullptr`: Introduced in C++11, it is the preferred way to represent a null pointer.
int* ptr = nullptr; // ptr is a null pointer ⭐

// `NULL`: A macro defined in `<cstddef>`, which was commonly used before C++11.
int* ptr = NULL; // ptr is a null pointer ⭐

// `0`: In earlier C++ versions, `0` could also be used as a null pointer constant, though this practice is less clear and not recommended in modern C++.
int* ptr = 0; // ptr is a null pointer
```

**Why Use Null Pointers?**

* It indicates that the pointer is currently not pointing to any valid object, which can help ==avoid accidental dereferencing of uninitialized pointers==.
* Null pointers can serve as sentinel values in functions to indicate that a function has failed to return a valid result. For example, a function that searches for an item in an array can return a null pointer if the item is not found.
* In dynamic memory management, null pointers can help manage allocated resources, indicating that a pointer is available for allocation.

**Risks of Using Null Pointers?**

* Dereferencing a null pointer (attempting to access or modify the value it points to) results in undefined behavior, which can lead to runtime errors such as segmentation faults. Here's an example:

**Note:** It is safe to Always check if a pointer is null before dereferencing it. ⭐

```cpp
int* ptr = nullptr; // ptr is a null pointer
cout << *ptr; // ❌ This will lead to a runtime error


// Safe Practice 
 if (ptr != nullptr) {
      cout << *ptr; // Safe to dereference
  } else {
      cout << "Pointer is null";
  }
```

**Use Smart Pointers?**

* In modern C++, consider using smart pointers (`std::unique_ptr` and `std::shared_ptr`) from the `<memory>` header. Smart pointers help manage memory more safely and automatically handle null pointers.
