
What will be the value of output??
```cpp
void fun(int *ptr) {
    *ptr = 30;
}

int main() {
     int y = 20;
    fun(&y); // y = 30
    cout<<y++ + 10<<endl; // cout<< 30 + 10, y++
    return 0;
}
```
Ans: 40

Note: In `cout << y++ + 10 << endl;`
- First, **`y++`** is a **post-increment**. This means the current value of `y` (which is now `30`) will be used in the expression, and then `y` will be incremented to `31` after the expression is evaluated. The expression `y++ + 10` becomes `30 + 10`, which equals **`40`**.

---

Consider the following three C functions:

```cpp
[P1] int * g (void) { 
    int x= 10; 
    return (&x); 
} // ❌ Problem

[P2] int * g (void) { 
    int * px; 
    *px= 10; 
    return px; 
} // ❌ Problem

[P3] int *g (void) { 
    int *px; 
    px = (int *) malloc (sizeof(int)); 
    *px= 10; 
    return px;  
} // ✅ No Problem
```

- `[P1]` : Returning the address of `x` (`&x`) is dangerous because once the function returns, the memory allocated for `x` is no longer valid. Accessing this memory results in **undefined behavior**, as you're pointing to a location on the stack that has been deallocated.

- `[P2]` : Dereferencing an uninitialized pointer (`*px = 10;`) will cause a **segmentation fault** or other undefined behavior because `px` does not point to a valid memory location.
---


Which of the following are TRUE:
```
A. calloc() takes two arguments, but malloc takes only 1 argument.
B. malloc() and memset() can be used to get the same effect as calloc().
C. calloc() allocates the memory and also initializes the allocates memory to zero, while memory allocated using malloc() has random data.
D. Both malloc() and calloc() return 'void *' pointer.
E. All of the above ✅
```

`memset` is a standard C library function used to set a block of memory to a specified value. It's commonly used to initialize memory buffers or arrays with a specific value, typically zeros.

**Setting an array to zero**:
```c
int arr[10];
memset(arr, 0, 10 * sizeof(int));  // Sets all elements of the array to 0
```

**Setting a buffer to a specific value**:
```c
char buffer[20];
memset(buffer, 'A', 20);  // Sets all 20 bytes of the buffer to 'A'

```

- An **array** is a fixed-size, type-specific collection of elements stored in contiguous memory, used for direct data storage and manipulation. 
- A **buffer** is a temporary storage area, often used in I/O operations, and may handle raw bytes or mixed data types, with a size that can be dynamic. Arrays are used when the size and type of data are known upfront, while buffers are used for handling data temporarily during processing, especially for data transfers or streams.

Voide Pointer: 
- A **void pointer** is a generic pointer that can point to any data type.
- It cannot be dereferenced directly without casting to another pointer type.
- It is useful for writing flexible functions and for memory allocation functions.

---


What will be the output of following piece of code:

```cpp
int main()
{
    static int i=5; // one time initialize, skip the line next time
    if(--i) { 
        main();
        cout<<i<<" "; // 0 0 0 0 0 
    }
}
```
Ans : 0 0 0 0 

static variable:
- can not be re initialized
- initialized to 0, if not initialized explicitly
- remain in memory throughout the program

---

What will be the size of the object of the following class:
```cpp
 // Assume that integers take 4 bytes. 
 class Test 
 { 
      static int i; //4 byte,  Static member (not included in object size) 
      int j; // 4 yte, Non-static member (included in object size)
 }; 

 int Test::i; 

 int main() 
 { 
      cout << sizeof(Test); // 4 byte
      return 0; 
 } 
```
Ans : 4 byte

Static members are shared among all instances of the class and are not stored in each object.


---

For n=5, this code snippet print asterisks in 5 rows. How many asterisks will be there in third row of output:
```cpp
    int nsp=2;
    int nst=1;
    for(int i=1; i<=n; i++) { // 5 times 
        for(int j=1; j<=nsp; j++) {
            System.out.print(" ");
        }
        for(int j=1; j<=nst; j++) { // in 3rd time, nst=5 
            System.out.print("*"); // 3rd time *****
        }
        System.out.println();
        if(i<(n/2+1)) { // i<(5/2+1) i.e i<3
            nsp--; // 2 -> 1 -> 0 -> ....
            nst=nst+2; // 1 -> 3 -> 5 -> .....
        }else {
            nsp++;
            nst=nst-2;
        }
    }
```
Ans = 5

- **Iteration 1 (`i = 1`)**:  `nsp = 2`, `nst = 1` , Spaces: (2 spaces), Asterisks: `*` (1 asterisk), Output: `*`
- **Iteration 2 (`i = 2`)**:`nsp = 1`, `nst = 3` ,Spaces: (1 space), Asterisks: `***` (3 asterisks) Output: `***`
- **Iteration 3 (`i = 3`)**: `nsp = 0`, `nst = 5` Spaces: (0 spaces), Asterisks: `*****` (5 asterisks), Output: `*****`


---

### Summary of Differences:

|Expression|Syntax|Type Safety|Preferred Use Case|
|---|---|---|---|
|`int(a)`|Functional notation|Moderate|Converting between built-in types or classes with constructors.|
|`(int)a`|C-style cast|Low|Quick type conversion, but less safe.|
|`static_cast<int>(a)`|Static cast|High|Safe and explicit type conversion; prefer this in C++.|

---

What would be output of the following code

```cpp
class Room; // forward declaration

void Area(){ 
    int width, height;
    class Room{
        int width, height;
    public:
        void setValue(int w, int h){
            width=w;
            height=h;
        }
        void displayValues(){
            cout<<(float)width<<' '<<(float)height;
        }
    };
    Room objRoom1;
    objRoom1.setValue(12, 8);
    objRoom1.displayValues();
}

int main(){
    Area(); 
}
```
Ans: 12 8

a class can be declared (and defined) inside a function. This is known as a **local class**. Local classes are only visible within the scope of the function in which they are defined. Here are some key points about local classes:
- Only accessible within the function
- cannot have static member
- 