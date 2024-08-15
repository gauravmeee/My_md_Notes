# C++ Doubts 🤷
## Int
`int n;`

if n in global scope `n=0`
otherwise `undetermined`

`int a, b;` ✅

`int a=b=0` ❌

# String

"a" == 'a' ❌  
"a"[0] == 'a' ✅
"a" = 'a\0' ❌ A character literal can not represent more than one character

"a" -> This is a string literal of type const char* (C-style string includes 'a' and '\0')
'a' -> This is a character literal
'\0' -> null terminator

**String Reverse**
built-in reverse function from the `<algorithm>` library.
- `reverse(str.begin(), str.end());`

constructs a new string using reverse iterators (rbegin and rend)
- `string reversed_str(str.rbegin(), str.rend());`

`
# Stack / Queue
**Queue**: `push()` `pop()` `empty()` `front()` 
**Stack**: `push()` `pop()` `empty()`

`queue<int> myQue = {1, 2, 3};` ❌
`queue<int> myQue({1, 2, 3});` ✅ : using constructor
`queue<int> myQue` `from(i=1;i<=3;i++) myQue.push(i)` ✅ : push in looop

`myQue.size()` ✅

 `myQue[0]` ❌ : doesn't support direct access
 `myQue.front()` ✅ : only first element access is allowed




# nullptr vs NULL

`NULL`
 is an integer constant typically defined as `0`, which can lead to type ambiguity.

`nullptr` is a keyword introduced in C++11 that represents a null pointer of type std::nullptr_t, providing type safety.


# Functions

in `non-void function`, it is necessary to `return` some value;

`non-void` we use `return` to stop the function

<hr>

**Class Function**
Let permute() is a function of Solution Class.

❌ direct class function can't be called
```cpp
int main(){
    permute();
}
```

✅ create class instance and call the function
```cpp
    Solution sol; 
    sol.permute()
```
<hr>

datatype -> declaration + initialisation

function -> declaration + definiton

# Loop / Iteration
`while (int i<n) valid?` ❌ In C++, you cannot declare a variable inside the condition of a while loop.\
 The variable must be declared and initialized before the loop.
 <hr>
for loop in increment `+2`
`for (int i=0; i<n; i+=2`


# Libraries 
## `<algorithm>`
✅ vec.begin() & vec.end()\
`std::sort(vec.begin(), vec.end()); ` 

✅ begin(vec) & end(vec)\
`std::sort(std::begin(vec),std::end(vec));`

<hr> 

std::max_element()\

note: `std::max_element()` returns an iterator, not an integer.

`int maxx = max_element(arr.begin(), arr.end())`❌

`Auto max_itr = max_element(arr.begin(), arr.end())`\
`int maxx = *max_itr`✅

`int maxx = *max_element(arr.begin(), arr.end())`✅
<hr>
## `<utility>`

`swap()` function can be used to swap the values of two variables of any type.
`swap(x,y)`

<hr>
# \#include Header 
`<iostream>`
`<bits/stdc++.h>`
`<vector>`
`<map>`
`<unordered_map>`
`<string>`

`<algorithm>`-> sort, reverse

**std: :library**    
- Input a string
`cin>>` can take String as input directly from terminal . (stops reading at whitespace).
```cpp
string s;
cin>>s;
```
- input a line `getline(cin, a)` of strings
```cpp
string a, b;
getline(cin, a);
```

---

# Common Errors

**1. int& sum=0;**
> error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'

References in C++ must be bound to a valid object or variable, not a temporary value like an integer literal (0).

**2. UndefinedBehaviorSanitizer: undefined-behavior**

> runtime error: signed integer overflow: 1073741824 + 1073741824 cannot be represented in type 'int' (solution.cpp)

This happens when you're trying to store a value in an int type that exceeds its maximum allowable value (for a 32-bit int, this maximum is typically 2,147,483,647).

solution: change `int` to `long long`
