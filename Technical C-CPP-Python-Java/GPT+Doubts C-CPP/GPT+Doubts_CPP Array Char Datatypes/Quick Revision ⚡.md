##### `#include <Algorithms>`:

1. **Sort**  
   `Sort(startPointer, startPointer + n)`  
   Sorts the range from `startPointer` to `startPointer + n`.
   ✅ `vector`, `array`, `string` (since they support random access iterators).
   ❌ `map`, `set`, `list` (they do not support random access iterators).
   
1. **Fill**  
   `Fill(startPointer, startPointer + n - 1)`  
   Fills the range from `startPointer` to `startPointer + n - 1`.
   ✅ `vector`, `array`, `string` (since they support random access iterators),  `list`, `deque`, `set` (any container that supports forward iterators).
   ❌
   
1. **Swap**  
   `Swap(value1, value2)`  
   Swaps the values of `value1` and `value2`.
   ✅ `vector`, `array`, `string`, `map`, `set`, etc. (**any two objects** of the same type, including )
   ❌
##### Size of Data Types:
- **Char**: 1 byte  
- **Short**: 2 bytes  
- **Int**: 4 bytes  
- **Long**: 8 bytes  

> *Note*: The size is the same regardless of whether the datatype is signed or unsigned.

##### Maximum Values of Data Types:

- **Short**:  
  - Signed: 32 × 10³ = (2¹⁵)  
  - Unsigned: 65 × 10³ = (2¹⁶)

- **Int**:  
  - Signed: 2 × 10⁹ = (2³¹)  
  - Unsigned: 4 × 10⁹ = (2³²)

- **Long Long**:  
  - Signed: 9 × 10¹⁸ = (2⁶³)  
  - Unsigned: 18 × 10¹⁸ = (2⁶⁴)

- **Long**  
  - On a 32-bit system, behave like `int`/`unsigned int` and On a 64-bit system, behave like `long long`/`unsigned long long`.  
- **Size_t**:  
  - On both 32-bit and 64-bit, behaves like `unsigned long` on 32-bit and 64-bit.

---

1. Sort vector in descending order
2. Sort `Vector<pair>` based on second value

pair.first, pair.second  ??
pair[0], = pair[1] doesnot support index

In C++, when using `using namespace std;`, conflicts can arise if variable names clash with standard library types, such as `map`, which conflicts with `std::map`. However, this is not an issue for variable names like `pair` in loop contexts, where `pair` refers to a loop variable and not the `std::pair` type.

comparisons in `std::map` and `std::pair` are lexicographical. For a `std::map`, the comparison of keys is done based on the `first` element first, and if they are equal, the `second` elements are compared.

---

make_pair 
`pair<int, char> p1 = make_pair(1, 'A');`
same as `P1(1, 'A')` or `P1={1, 'A'}


