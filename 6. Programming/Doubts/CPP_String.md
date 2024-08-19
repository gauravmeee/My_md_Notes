
#### String vs Character
```
"a" == 'a' ❌  
"a"[0] == 'a' ✅
"a" = 'a\0' ❌ A character literal can not represent more than one character

"a" -> This is a string literal of type const char* (C-style string includes 'a' and '\0')
'a' -> This is a character literal
'\0' -> null terminator
```

---
#### String Reverse
built-in reverse function from the `<algorithm>` library.
- `reverse(str.begin(), str.end());`

constructs a new string using reverse iterators (rbegin and rend)
- `string reversed_str(str.rbegin(), str.rend());`

---

#### Concatenate character with string
```cpp
std::string str = "Hello";

str += '!';
# or
str.push_back('!');

# Both methods will result in the string `"Hello!"`.
```

---
#### Seperate words

```cpp
std::string str = "Hello World"; 
size_t spacePos = str.find(' '); // Finds the position of the space 
std::string hello = str.substr(0, spacePos); // Extracts "Hello" 
std::string world = str.substr(spacePos + 1); // Extracts "World"
```

---
#### Reverse Word using  `#include <sstream>` ❓

Store each words of `string s` in vector;
```cpp
// Split the string into words
istringstream iss(s);
while (iss >> str){ //input word
	vec.push_back(str); 
}
```

Concatenate words from vector to  `string str` in revers Order
```cpp
// Reverse the order of words ostringstream oss;
for (int i = vec.size() - 1; i >= 0; --i){
	oss << vec[i];
	if (i > 0){
		oss << " ";
	} 
}
```


- **`istringstream`**: Used to split the input string `s` into words. It allows you to extract words one by one using the `>>` operator.
- Used to read data from a string, similar to how `ifstream` is used to read from a file. You can use it to extract formatted data from a string.

- **`ostringstream`**: Used to build the final result string with the words in reversed order. It provides efficient string concatenation and formatting.
- Used to write data to a string, similar to how `ofstream` is used to write to a file.  You can use it to format and assemble a string from various data types.