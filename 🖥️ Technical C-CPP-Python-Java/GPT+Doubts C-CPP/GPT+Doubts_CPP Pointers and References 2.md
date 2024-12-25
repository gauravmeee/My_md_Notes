
## Reference

Reference is a type of variable that acts as an alias or another name for existing variable.

**Definition**
```cpp
int orgVar = 42;
int &refVar = orgVar
```

**Modification (Through reference)**
```cpp
refVar = 55; // change the value of `orgVar`
```

**Reinitialization** (Not Allowed ❌)
```cpp
int orgVar2 = 45;
int &refVar = orgVar2; // refVar is arleady referencing to orgVar
```

*Note:* In C++, once a reference (`refVar`) is bound to a variable (`orgVar`), it cannot be changed to refer to another variable (`orgVar2`). Use a pointer instead of a reference, If you need to change what a reference points to.


**Function Parameter ( to avoid the overhead copying large objects)**
```cpp
void modifyValue(int &ref){
	ref = 10;
}

int org;
modify(org) // change the value of org to 10;
```

**Return Values** (Function can return Reference) ❓
```cpp
int b = 2;

int& getElement() {
    return b; // return a reference to `b`
}

getElement() = 10; // Modify `b` through the returned reference

// flow:
// int b = 2;
// getElement() returns a reference to b;
// b = 10;
```

The code correctly demonstrates that `getElement()` returns a reference to `b`, and the assignment `getElement() = 10;` modifies `b` to `10`.

**Null Reference** (Not Allowed ❌)
```cpp
int *ptr = nullptr;
int &ref = *ptr;  // Error: dereferencing a null pointer
```


**Used Iteration**
```cpp
vector<int> numbers={1, 2, 3};
for(int &num: numbers){
 num+=1; // modify vector (without reference, only local copy modified)
}
```

*Note:*  `&num` Avoids copying each element of the vector. Instead, `num` is a reference to each element, which is more efficient, especially for larger or complex data types.

---
### Pointers

- Pointer are variable that store memory addresses.
- used to manage memory dynamically and to work with the memory directly

**Declaration**
```cpp
int *ptr;
```

**Initialization**
```cpp
int x = 10;

int *ptr = &x; // ptr now holds the address of variable x
//or
int *ptr;
ptr = &x;
```

**Dereferencing**
```cpp
int y = *ptr; // y now holds the value stored at address 
```

**Null Pointer**
```cpp
int *nullPtr = nullptr; // modern c++ way of setting a pointer to null
```

**Memory address pointed to by `ptr`**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *arrPtr = arr; // point to the first element: arr -> address of arr[0];
int thirdElement = *(arrPtr+2) // arr[2]
```

**Dynamic Memory Allocation**
```cpp
int *dynamicPtr = new int; // dynamically alloted integer
*dynamicPtr = 42;  // assign value
dlete dynamiPtr; // free allocated memory
```
*Note :* instead of assigning address to pointer , it assign value

**Pointer in function** (pass & modify data by reference)
```cpp
void modifyValue (int* ptr){
	(*ptr)++; // increment the value pointed by ptr;
}
```