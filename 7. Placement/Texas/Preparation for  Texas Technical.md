# [TEXAS Instruments Placement Question Paper 4](https://entrance-exam.net/texas-instruments-placement-papers/)

### 1. If a 5-stage pipeline is flushed and then we have to execute 5 and 12 instructions respectively, then the number of cycles will be
a. 5 and 12  
b. 6 and 13  
c. 9 and 16  
d. none  

**Explanation:**  
In a 5-stage pipeline, the first instruction takes 5 cycles to complete. Each subsequent instruction completes in 1 additional cycle after the first instruction. Therefore:
- For 5 instructions: 
  - Cycles = 5 (initial cycles) + (5-1) (additional cycles) = 9 cycles
- For 12 instructions: 
  - Cycles = 5 (initial cycles) + (12-1) (additional cycles) = 16 cycles

**Answer:** c. 9 and 16

---
### 2. K-map ⭐⭐⭐ (study k map)
```
ab
----------
c 1 x 0 0
1 x 0 x
```
a. A.B  
b. ~A  
c. ~B  
d. A+B  

**Explanation:**  
Analyzing the K-map:
```
c \ ab | 00 | 01 | 11 | 10 |
---------------------------
  0    |  1 |  x |  0 |  0 |
  1    |  1 |  x |  0 |  x |
```
The K-map indicates that `~A` simplifies the expression.

**Answer:** b. ~A

---
### 3. `CHAR A[10][15]` AND `INT B[10][15]` IS DEFINED. WHAT'S THE ADDRESS OF `A[3][4]` AND `B[3][4]` IF THE ADDRESS OF A IS 0x1000 AND B IS 0x2000? ⭐
a. 0x1030 and 0x20C3  
b. 0x1031 and 0x20C4  

**Explanation:**  
- Address of `A[3][4]`:  
  `A` is a 2D character array. Each character occupies 1 byte. The base address is 0x1000.
  - `A[i][j]` address = `base + (i * number_of_columns + j) * size_of_element`
  - Address of `A[3][4]` = 0x1000 + (3 * 15 + 4) * 1 = 0x1000 + 49 = 0x1031

- Address of `B[3][4]`:  
  `B` is a 2D integer array. Each integer occupies 4 bytes. The base address is 0x2000.
  - `B[i][j]` address = `base + (i * number_of_columns + j) * size_of_element`
  - Address of `B[3][4]` = 0x2000 + (3 * 15 + 4) * 4 = 0x2000 + 196 = 0x20C4

**Answer:** b. 0x1031 and 0x20C4

---
### 4. What will be the output of the following code? ❓
```cpp
int f(int *a)
{ 
    int b=5;
    a=&b;
}

main()
{ 
    int i;
    printf("\n %d", i);
    f(&i);
    printf("\n %d", i);
}
```
a. 10, 5  
b. 10, 10  
c. 5, 5  
d. none  

**Explanation:**  
- The first `printf` statement will print the value of `i`, which is uninitialized, leading to an unpredictable value.
- In the function `f`, the pointer `a` is assigned the address of the local variable `b`. However, this change does not affect the actual variable `i` in `main`.
- The second `printf` statement will print the value of `i`, which remains uninitialized.

Therefore, the output is unpredictable (compiler-dependent).

**Answer:** d. none

---
### 5. main() ⭐(fork())
```cpp
main()
{ 
    int i;
    fork();
    fork();
    fork();
    printf("----");
}
```
How many times will the `printf` be executed?
a. 3  
b. 6  
c. 5  
d. 8  

**Explanation:**  
Each `fork()` call creates a new process. After the first `fork()`, there are 2 processes. Each of those calls another `fork()`, resulting in 4 processes. Each of those calls another `fork()`, resulting in 8 processes. Each process executes the `printf` statement.

**Answer:** d. 8
[fork() by Gate Smashers](https://youtu.be/ixq5cpdEO2Q)

---
### 6.  ⭐ (0x8000)
```cpp
void f(int i)
{ 
    int j;
    for (j=0;j<16;j++)
    { 
        if (i & (0x8000>>j))
            printf("1");
        else
            printf("0");
    }
}
```
What's the purpose of the program?
a. its output is hex representation of i  
b. bcd  
c. binary  
d. decimal  

**Explanation:**  

- **Bitwise Operation:**
    - The expression `0x8000 >> j` generates a bitmask for the `j`-th bit from the left in a 16-bit integer. Specifically:
        - `0x8000` is the hexadecimal representation of `1000000000000000` in binary (a 16-bit integer with the highest bit set).
        - Shifting `0x8000` to the right by `j` bits effectively positions the bitmask at the `j`-th bit from the left.
    
- **Bitwise AND Operation:**
    - `i & (0x8000 >> j)` checks if the `j`-th bit from the left in the integer `i` is set (i.e., it’s `1`).
    - If the result is non-zero, the `j`-th bit is `1`, otherwise, it’s `0`.

The function prints the binary representation of the integer `i`. It iterates over 16 bits (assuming `i` is a 16-bit integer) and prints `1` if the corresponding bit is set and `0` otherwise.

- `0x8000` is hexadecimal notation for the number `32768` in decimal.
- In binary, it represents a 16-bit number where only the most significant bit is set. .ie. `1000000000000000`

**Answer:** c. binary

---
### 7.  ⭐(#define)
```cpp
#define f(a,b) a+b
#define g(a,b) a*b
main()
{ 
    int m;
    m=2*f(3,g(4,5));
    printf("\n m is %d",m);
}
```
What's the value of `m`?
a. 70  
b. 50  
c. 26  
d. 69  

**Explanation:**  
The macro `f(a,b)` expands to `a + b`, and `g(a,b)` expands to `a * b`. Therefore, `f(3, g(4, 5))` expands to `3 + 4*5`. 
- `g(4, 5)` expands to `4 * 5` which is `20`.
- `f(3, 20)` expands to `3 + 20` which is `23`.
- `2 * 23` is `46`.

However, the macro expansion occurs without parentheses, so the actual expansion is ``2 * 3 + 4 * 5``, which is `6 + 20` = `26`.

*Note:* The expression `2 * f(3, g(4, 5))` expands to `2 * 3 + 4 * 5` (without proper parentheses around macro definitions
With Parentheses `#define f(a,b) (a+b), #define g(a,b) (a*b)`).  `2 *(3 + (4 * 5))`, which is 46.

**Answer:** c. 26

---
### 8. ⭐(strcpy())
```cpp
main()
{
    char a[10];
    strcpy(a, "\0");
    if (a == NULL)
        printf("\a is null");
    else
        printf("\n a is not null");
}
```
What happens with it?
a. compile time error.  
b. run-time error.  
c. a is null  
d. a is not null.  

**Explanation:**  
The `strcpy(a, "\0")` copies an empty string into `a`, which makes `a` an empty string but not a `NULL` pointer. The condition `if (a == NULL)` checks if `a` is a null pointer, which it is not; hence, `a is not null` will be printed.

**Answer:** d. a is not null.

---
### 9. ⭐ (`'\0'` null operator after string)
```cpp
char a[5] = "hello";
```
What's wrong with this declaration?
a. in array we can't do the operation.  
b. size of a is too large  
c. size of a is too small  
d. nothing wrong with it.  

**Explanation:**  
The string `"hello"` requires 6 characters (5 letters + 1 null terminator). The array `a` is only of size 5, which is insufficient to hold the string including the null terminator.

**Answer:** c. size of a is too small.

---
### 10. Local variables can be stored by the compiler:
a. in register or heap  
b. in register or stack  
c. in stack or heap  
d. global memory  

**Explanation:**  
Local variables are typically stored in the stack or sometimes in registers for optimization. The heap is used for dynamic memory allocation.

==**Answer:** b. in register or stack.

---
### 11. Average and worst time complexity in a sorted binary tree:
**Explanation:**  
- Average time complexity for operations like search, insertion, and deletion in a balanced sorted binary tree (e.g., AVL tree) is \(O(\log n)\).
- Worst time complexity occurs in an unbalanced binary tree, which can degrade to \(O(n)\) in the case of a degenerate tree (like a linked list).

---
### 12. A tree is given and asked to find its meaning (parse-tree) (expression tree):

---
### 13. Convert 40.xxxx into binary:
**Explanation:**  
The integer part `40` in binary is `101000`. For the fractional part `.xxxx`, it requires conversion of each binary fractional value (which is not given here).

---
### 14. Global variable conflicts due to multiple file occurrences are resolved during: ⭐
a. compile-time  
b. run-time  
c. link-time  
d. load-time  

**Explanation:**  
Conflicts in global variables across multiple files are resolved during the linking phase when the linker combines object files and resolves addresses.

==**Answer:** c. link-time.

---
### 15. Two programs are given for factorial, one with recursion and one without recursion. Which program won't run for a very big number input because of stack overflow?
a. i only  
b. ii only  
c. i & ii both.  
d. none  

**Explanation:**  
Recursive programs can cause stack overflow with large inputs due to deep recursive calls. Non-recursive programs, using iterative methods, are less likely to cause stack overflow.

**Answer:** a. i only.

---

### 16. Given the following structures:
```cpp
struct a
{ 
    int a;
    char b;
    int c;
}

union b
{ 
    char a;
    int b;
    int c;
};
```
Which is correct?
a. size of a is always different from the size of b.  
b. size of a is always the same as the size of b.  
c. we can't say anything because of not-homogeneous (not in ordered)  
d. size of a can be the same if  

**Explanation:**  
- The size of a struct is the sum of the sizes of its members plus any padding needed for alignment.
- The size of a union is determined by the size of its largest member. Hence, the size of the union `b` is the size of `int` (assuming `int` is larger than `char`).

**Answer:** a. size of a is always different from the size of b.

---

# [TEXAS Instruments Placement Question Paper 1](https://entrance-exam.net/texas-instruments-placement-papers/)
### 1. What will be the output of the following code? ⭐
```cpp
void main ()
{ 
    int i = 0, a[3];
    a[i] = i++;
    printf("%d", a[i]);
}
```
**Answer:** The output for the above code would be a garbage value.

**Explanation:**  
In the statement `a[i] = i++;`, the value of `i` is assigned to `a[0]` (since `i` is initially 0) and then `i` is incremented to 1. However, when `printf` is called, it prints `a[1]` because `i` is now 1. Since `a[1]` has not been initialized, it contains a garbage value.

---
### 2. Why doesn't the following code give the desired result? ❓
```cpp
int x = 3000, y = 2000;
long int z = x * y;
```
**Answer:** The multiplication results in an overflow.

**Explanation:**  
The multiplication is carried out between two `int`s, `x` and `y`, and the result exceeds the range of `int`. This causes an overflow, and the truncated result is assigned to the variable `z` of type `long int`. To get the correct result, you should cast one of the operands to `long int` to force long arithmetic:
```cpp
long int z = (long int) x * y;
```
Note that `(long int)(x * y)` would not give the desired effect because the multiplication would still occur between two `int`s before the result is cast to `long int`.

---
### 3. Why doesn't the following statement work? ⭐(strcat())
```cpp
char str[] = "Hello";
strcat(str, '!');
```
**Answer:** The `strcat` function concatenates strings,==not a single character.

**Explanation:**  
The function `strcat()` is designed to concatenate strings, which are collections of characters terminated by a null character (`\0`). A character is not a string. To concatenate a character to a string, you should convert the character to a string:
```cpp
strcat(str, "!");
```

---
### 4. How do I know how many elements an array can hold?

**Answer:** The amount of memory an array can consume depends on the data type of the array and the memory model in use.

**Explanation:**  
In a DOS environment, the amount of memory an array can consume depends on the current memory model (e.g., Tiny, Small, Large, Huge). ==In general, an array cannot consume more than 64 KB.== Consider the following program, which shows the maximum number of elements an array of type `int`, `float`, and `char` can have in the case of the Small memory model:
```cpp
main()
{
    int i[32767];
    float f[16383];
    char s[65535];
}
```
In this example:
- An `int` array can have 32767 elements.
- A `float` array can have 16383 elements.
- A `char` array can have 65535 elements.
The actual number of elements that an array can hold is determined by dividing the maximum memory size by the size of the array's data type.

---
### 5. How do I write code that reads data at a memory location specified by segment and offset? ⭐(peekb())

**Answer:** Use the ==`peekb()` function. This function returns a byte read from specific segment and offset== locations in memory. 

**Explanation:**  
The following program illustrates the use of the `peekb()` function. In this program, characters and their attributes are read from the VDU memory's first row. The information stored in a file is then further read and displayed using the `peekb()` function.
```cpp
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char far *scr = 0xB8000000;
    FILE *fp;
    int offset;
    char ch;

    if ((fp = fopen("scr.dat", "wb")) == NULL)
    {
        printf("\nUnable to open file");
        exit(1);
    }

    // Reads and writes to file
    for (offset = 0; offset < 160; offset++)
        fprintf(fp, "%c", peekb(scr, offset));
    fclose(fp);

    if ((fp = fopen("scr.dat", "rb")) == NULL)
    {
        printf("\nUnable to open file");
        exit(1);
    }

    // Reads and writes to file
    for (offset = 0; offset < 160; offset++)
    {
        fscanf(fp, "%c", &ch);
        printf("%c", ch);
    }
    fclose(fp);
}
```
In this code:
- `scr` is a far pointer pointing to the VDU memory location.
- `peekb()` reads a byte from the specified segment and offset.
- Data is written to and read from a file named `scr.dat`.

---
### 6. How do I compare character data stored at two different memory locations?

**Answer:** Use the `memcmp()` or `memicmp()` functions. The `memcmp()` function performs a case-sensitive comparison, whereas the `memicmp()` function ignores the case of characters.

**Explanation:**  
The following program illustrates the use of both functions.
```cpp
#include <stdio.h>
#include <string.h>

void main()
{
    char *arr1 = "Kicit";
    char *arr2 = "kicitNagpur";
    int c;

    c = memcmp(arr1, arr2, sizeof(arr1));
    if (c == 0)
        printf("\nStrings arr1 and arr2 compared using memcmp are identical");
    else
        printf("\nStrings arr1 and arr2 compared using memcmp are not identical");

    c = memicmp(arr1, arr2, sizeof(arr1));
    if (c == 0)
        printf("\nStrings arr1 and arr2 compared using memicmp are identical");
    else
        printf("\nStrings arr1 and arr2 compared using memicmp are not identical");
}
```
In this code:
- `memcmp()` compares the memory content of `arr1` and `arr2` considering case sensitivity.
- `memicmp()` compares the memory content of `arr1` and `arr2` ignoring case sensitivity.

---
### 7. Fixed-size objects vs Variable-size data objects

**Answer:** Use fixed-size data objects when the maximum size is clearly bounded and close to the average, and use variable-size data objects when a few of the data items are significantly bigger than the average size.

**Explanation:**
Fixed-size objects are more appropriate in many situations because they are easier and faster to manipulate and usually have less overhead compared to variable-size data objects. For example:
```cpp
char *num[10] = { "One", "Two", "Three", "Four",
"Five", "Six", "Seven", "Eight", "Nine", "Ten" };
```
In the above code, variable-size data objects are used, requiring 10 pointers and strings of variable sizes, consuming 90 bytes assuming each pointer is 4 bytes. However, using fixed-size data objects:
```cpp
char num[10][6] = { "One", "Two", "Three", "Four",
"Five", "Six", "Seven", "Eight", "Nine", "Ten" };
```
This approach only requires 60 bytes as it allocates 10 arrays of 6 characters each, making it more efficient in this case.

---
### 8. The Spawnl( ) function

**Answer:** The `spawnl()` function is used to start the execution of one program from within another program. It allows the creation of a child process which runs a specified program.

**Explanation:**
In DOS, a single-tasking operating system, only one program runs at a time. The `spawnl()` function enables a parent process to call a child process, pausing the parent process until the child process completes execution. The following program demonstrates the use of `spawnl()`:
```cpp
/* Mult.c */
int main ( int argc, char* argv[] )
{
    int a[3], i, ret ;
    if ( argc < 3 || argc > 3 )
    {
        printf ( "Too many or Too few arguments..." ) ;
        exit ( 0 ) ;
    }
    for ( i = 1 ; i < argc ; i++ )
        a[i] = atoi ( argv[i] ) ;
    ret = a[1] * a[2] ;
    return ret ;
}

/* Spawn.c */
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

main( )
{
    int val ;
    val = spawnl ( P_WAIT, "C:\\Mult.exe", "3", "10", "20", NULL ) ;
    printf ( "\nReturned value is: %d", val ) ;
}
```
In this example:
- `Mult.exe` calculates the product of the arguments passed to it.
- `Spawn.exe` invokes `Mult.exe` using `spawnl()`, passes the command-line arguments to it, and prints the returned value.
- The `spawnl()` function takes `P_WAIT` to indicate that the parent process should wait until the child process completes. Other possible modes include `P_NOWAIT` and `P_OVERLAY`, which allow the parent process to continue running or overlay the child process on the parent process in memory, respectively.
---
### 9. Are the following two statements identical?
```cpp
char str[6] = "Kicit" ;
char *str = "Kicit" ;
```
**Answer:** No.

**Explanation:**
Arrays are not pointers. An array is a single, pre-allocated chunk of contiguous elements (all of the same type), fixed in size and location. A pointer, on the other hand, is a reference to any data element (of a particular type) located anywhere. A pointer must be assigned to point to space allocated elsewhere, but it can be reassigned at any time. 

- The array declaration `char str[6] = "Kicit";` requests that space for 6 characters be set aside, to be known by the name `str`. In other words, there is a location named `str` at which six characters are stored.
- The pointer declaration `char *str = "Kicit";` requests a place that holds a pointer, to be known by the name `str`. This pointer can point almost anywhere to any char, to any contiguous array of chars, or nowhere.

---
### 10. Is the following code fragment correct?
```cpp
const int x = 10 ;
int arr[x] ;
```
**Answer:** No.

**Explanation:**
Here, the variable `x` is first declared as an `int` so memory is reserved for it. Then it is qualified by a `const` qualifier. Hence, a `const` qualified object is not a constant in the full sense. It is an object with read-only access, which means its value cannot be changed after initialization, but it is not treated as a constant expression by the compiler. In C++, you can use `const` in this way, but in C, this is not allowed because the size of an array must be a constant expression.

#### 10/108 Done ✅

---