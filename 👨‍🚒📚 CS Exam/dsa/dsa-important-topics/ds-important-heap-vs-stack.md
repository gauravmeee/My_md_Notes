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

# Data Structure: Heap vs Stack

| Feature              | Stack Memory                    | Heap Memory                          |
| -------------------- | ------------------------------- | ------------------------------------ |
| **Allocation**       | Automatic (managed by compiler) | Manual (managed by programmer)       |
| **Lifetime**         | Limited to function scope       | Until explicitly deallocated         |
| **Speed**            | Fast access (LIFO structure)    | Slower access                        |
| **Size Limitations** | Smaller, fixed size             | Larger, variable size                |
| **Use Case**         | Local variables                 | Dynamic data structures, larger data |

### Heap

The **heap** is a <mark>region of a computer's memory</mark> that is used for **dynamic memory allocation.**

**Key Characteristics of the Heap:**

1. **Dynamic Memory Allocation**:
   * Memory in the heap is allocated and deallocated at runtime. This allows for more <mark>flexible memory usage</mark> compared to stack memory, which is fixed in size.
2. **Size**:
   * The heap can <mark>grow and shrink as needed</mark>, depending on the memory requirements of the application. It is generally <mark>larger than the stack</mark>.
3. **Lifetime**:
   * Objects created in the heap <mark>exist until they are explicitly deallocated</mark> by the programmer (e.g., using `delete` in C++ or garbage collection in languages like Java or Python).
4. **Access Speed**:
   * Accessing heap memory is generally <mark>slower than accessing stack</mark> memory due to the <mark>overhead of dynamic allocation</mark> and deallocation.
5. **Fragmentation**:
   * The heap can <mark>become fragmented over time</mark> as memory blocks are allocated and freed. This fragmentation can lead to inefficient use of memory.

**Usage:**

* The heap is typically used for:
  * Allocating large data structures whose size may not be known at compile time (e.g., arrays, linked lists, trees).
  * Creating objects whose lifetime needs to extend beyond the scope of a single function.

**Heap Memory Allocation in C++ Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Allocating an integer on the heap
    int* ptr = new int;      // dynamically allocate memory
    *ptr = 42;               // assign a value

    cout << "Value: " << *ptr << endl;  // Output: Value: 42

    delete ptr;              // deallocate memory
    return 0;
}
```

***

### Stack

The **stack** is a specific <mark>region of memory</mark> used for **managing function calls** and **local variables** in a program. Here are the key characteristics and details:

**Key Characteristics of the Stack:**

1. **Structure**:
   * The stack operates on a **Last In, First Out (LIFO)** basis. This means that the last item added to the stack is the first one to be removed.
2. **Automatic Memory Management**:
   * Memory <mark>allocation and deallocation for stack variables are handled automatically</mark>. When a function is called, its local variables are pushed onto the stack, and when the function exits, these variables are popped off the stack.
3. **Size**:
   * The stack typically has a <mark>fixed size</mark>, which is <mark>determined when a program starts</mark>. Exceeding this size <mark>can lead to a **stack overflow**</mark>.
4. **Lifetime**:
   * Variables on the stack <mark>exist only within the scope of the functio</mark>n in which they are declared. Once the function exits, these variables are destroyed.
5. **Access Speed**:
   * Accessing stack memory is generally <mark>faster than accessing heap</mark> memory due to its contiguous allocation and straightforward management.
6. **Limited Lifetime**:
   * The lifetime of stack variables is limited to the block in which they are defined. They cannot be returned from a function as they will no longer exist when the function returns.

**Usage:**

* The stack is commonly used for:
  * Storing local variables and function parameters.
  * Managing function call return addresses.
  * Supporting nested function calls and recursion.

**Stack memory allocation Example in C++:**

```cpp
#include <iostream>
using namespace std;

int a = 4; // Allocated to stack
void function() {
    int localVariable = 10; // Allocated on the stack
    cout << "Local Variable: " << localVariable << endl;
}

int main() {
    function(); // Calls the function where localVariable is allocated ⭐
    // localVariable is no longer accessible here
    return 0;
}
```

> ✅ 22-04-2025 Revised Upto here
