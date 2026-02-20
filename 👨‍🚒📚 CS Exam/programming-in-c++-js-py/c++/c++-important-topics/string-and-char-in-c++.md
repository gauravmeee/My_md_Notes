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

# String & Char in C++

**String and Character**

String

* `"a"` -> This is a string literal of type const char\* (C-style string includes 'a' and '\0')
* Type: `const char*`
* Represents -> `{'a', '\0'}` in memory

Null Terminator

* `'\0'` → null terminator
* Type: `char`
* ASCII value 0 -> Marks end of C-style string

Char

* `'a'` → This is a character literal
* Type: `char`
* Represents ASCII value of `'a' = 97`

#### CASTING

| From → To     | Conversion       |
| ------------- | ---------------- |
| string → int  | `stoi(s)`        |
| char → int    | `ch - '0'`       |
| int → string  | `to_string(num)` |
| int → char    | `num + '0'`      |
| string → char | `s[0]`           |
| char → string | `s(1, ch)`       |

***

**Comparing String and Character**

```cpp
// char == String
if(s[i] == " ") ; // ❌ Invalid : Compile error

// char == Char
if(s[i] == ' ') ; // ✅ Valid

// Note: comparing a character (`s[i]`) with a string (`" "`), and in C or C++, a string literal (like `" "`) is treated as a `const char *` (a pointer to characters), while `s[i]` is a single `char`. These two types are not directly comparable.
```

```cpp
"a" == 'a'  // ❌ Invalid : Comparing pointer with char
// "a" is a string literal (const char*) → address of first character
// 'a' is a char → ASCII value 97
```

```cpp
"a"[0] == 'a' //✅ Valid & True
// "a"[0] is the first character of string literal → 'a'
```

```cpp
"a" = 'a\0' // ❌ Inalid :  A character literal can not represent more than one character
// 'a\0' is an invalid char literal (char can only hold one character)
// Also, "a" is a string literal → cannot be assigned to (it's const char*) → ❌
```

Fix -> Casting ✅

1. **`char` -> `string`** Casting

```cpp
char ch = 'a';
string s(1, ch); // ✅ creates string "a"
// Equivalent: string s = string(1, ch);
```

* `string(size_t n, char c)` constructor creates a string of `n` copies of character `c`.

2. **`string` -> `char`** Casting

```cpp
string s = "a";
char ch = s[0]; // ✅ extracts first character

s[1] == '\0' ? // ❌ Not guaranteed in std::string
```

* `std::string` is not null-terminated like C-style strings.
* Accessing `s[1]` is **undefined behavior** if `s.size() == 1`.

**Notes:**

* `string s(1, ch)` creates a string of length 1 with char `ch`
* `s[0]` gives the first character of the string
* Ensure `s.length() >= 1` before accessing `s[0]` to avoid error

***

**Comparing Number and String**

```cpp
string s = "5";
if (s == 5) // ❌ Error: invalid comparison
```

Fix -> Casting ✅

1. **`string` -> `num`**

```cpp
int num = stoi(s); // stoi → string to int
if (num == 5) // ✅ valid
```

* Throw **`std::invalid_argument`** – if the string is not a number at all
* Throw **`std::out_of_range`** – if the number is too large for `int`

2. **`num` -> `string`**

```cpp
int x = 5;
string s = to_string(x);
```

**Comparing Number and Character**

```cpp
char ch = '5';
if (ch == 5) // ✅ valid but, ❌ Not logical 
// compares ASCII: '5' = 53 ≠ 5
```

**Fix -> Casting ✅**

1. **`char` -> `int`**

```cpp
int num = ch - '0'; // '5' - '0' = 5
```

2. **`int` -> `char`**

```cpp
char ch = x + '0'; // 5 + '0' = '5'
```

***

**Notes on `stringstream` in C++**

```cpp
#include <sstream>
```

**Purpose** - `stringstream` is used for parsing and manipulating strings like a stream (similar to `cin`, `cout`).

**Declaration:**

```cpp
stringstream ss;
```

**Initialize with string:**

```cpp
string str = "hello world";
stringstream ss(str);
```

**Extract words from string:**

```cpp
string word;
while (ss >> word) {
    // each word in 'word'
}
```

**Convert string to int / double:** ⭐

```cpp
string s = "123";
stringstream ss(s);
int x;
ss >> x; // x = 123

s >> x;        // ❌ Error: 's' is a string, not a stream
```

**Convert int to string:**

```cpp
int x = 456;
stringstream ss;
ss << x;
string s = ss.str(); // s = "456"

s << x;               // ❌ Error: 's' is a string, not a stream
```

**Functions:**

* `ss.str()` → returns full string content.
* `ss.clear()` → clears error flags (for reuse).
* `ss.str("")` → resets/clears the buffer.

**Common Use Cases:**

* Tokenizing strings
* Type conversion (string ↔ number)
* Parsing CSV or space-separated data

**Example:**

```cpp
string s = "10 20 30";
stringstream ss(s);
int num;
while (ss >> num) {
    cout << num << " ";
}
// Output: 10 20 30
```

***

**String Reverse**

built-in reverse function from the `<algorithm>` library.

* `reverse(str.begin(), str.end());`

constructs a new string using reverse iterators (rbegin and rend)

* `string reversed_str(str.rbegin(), str.rend());`

***

**Concatenate character with string**

```cpp
std::string str = "Hello";

str += '!';
# or
str.push_back('!');

# Both methods will result in the string `"Hello!"`.
```

***

**Seperate words**

```cpp
std::string str = "Hello World"; 
size_t spacePos = str.find(' '); // Finds the position of the space 
std::string hello = str.substr(0, spacePos); // Extracts "Hello" 
std::string world = str.substr(spacePos + 1); // Extracts "World"
```

***

**Reverse Word using `#include <sstream>` ❓**

Store each words of `string s` in vector;

```cpp
// Split the string into words
istringstream iss(s);
while (iss >> str){ //input word
	vec.push_back(str); 
}
```

Concatenate words from vector to `string str` in revers Order

```cpp
// Reverse the order of words ostringstream oss;
for (int i = vec.size() - 1; i >= 0; --i){
	oss << vec[i];
	if (i > 0){
		oss << " ";
	} 
}
```

* **`istringstream`**: Used to split the input string `s` into words. It allows you to extract words one by one using the `>>` operator.
* Used to read data from a string, similar to how `ifstream` is used to read from a file. You can use it to extract formatted data from a string.
* **`ostringstream`**: Used to build the final result string with the words in reversed order. It provides efficient string concatenation and formatting.
* Used to write data to a string, similar to how `ofstream` is used to write to a file. You can use it to format and assemble a string from various data types.

***

#### `substr()`

* **Purpose**: Extracts a substring from a string.
* **Syntax**: `string substr(size_t pos, size_t len)`
  * `pos`: Starting index.
  * `len`: Number of characters to extract.
*   **Example**:

    ```cpp
    string s = "Hello World";
    string sub = s.substr(6, 5);  // "World"
    ```
* If `len` exceeds the string length, it extracts until the end.

***

#### `at()`

* Returns character at given `index`
* Performs **bounds checking**
* Throws `std::out_of_range` if index is invalid

**Example:**

```cpp
string s = "Gaurav";
char ch = s.at(2); // 'u'
```

**Difference `s[index]` vs `s.at(index)` ?**

* `s[index]` is faster but **no bounds checking**
* `s.at(index)` is safer for error handling

***
