---
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

# ⭐✔️ My\_CPP Pair

**Map can be Converted to pairs**

```
vector<vector<int>> vec{{1,2},{3,4},{5,6}}
unordered_map<int,int> mp{{1,2},{3,4},{5,6}}
```

`for(pair<int,int> v: vec){ }` ❌ Vector Can't be converted into pairs.\
`for(pair<int,itn> m: mp){ }` ✅ Map Can be converted into pairs.

`m.first` access first element of pair\
`m.second` access second element of pair

***

## Pair

In C++, a `pair` is a simple container defined in the `<utility>` header that holds two values, which may be of different types. The types of these values are specified as template parameters. Here's a quick guide on using `pair`:

**Create Pair** ⭐

```cpp
#include <utility>

// Using std::make_pair
std::pair<int, std::string> p1 = std::make_pair(1, "Hello");

// Direct initialization
std::pair<int, std::string> p2(2, "World");

```

**Access Elements**

```cpp
std::cout << "First element: " << p1.first << std::endl;
std::cout << "Second element: " << p1.second << std::endl;
```

**Modifying elements**

```cpp
p1.first = 10;
p1.second = "Changed";
```

**Comparing Pairs**

```cpp
std::pair<int, int> p3(10, 20);
std::pair<int, int> p4(10, 30);

if (p3 < p4) {
    std::cout << "p3 is less than p4" << std::endl;
}
```

\*Note: \*Comparisons are lexicographical, meaning they compare the `first` elements first, and if they are equal, they compare the `second` elements.

**You can use pairs as elements in STL containers like `std::vector`, `std::map`, etc.**

```cpp
#include <vector>

std::vector<std::pair<int, std::string>> vec;
vec.push_back(std::make_pair(1, "One"));
vec.push_back(std::make_pair(2, "Two"));
```

**A `pair` can hold two values of different types, which can be useful in various contexts.**

```cpp
std::pair<int, double> p5(10, 3.14);
std::pair<std::string, char> p6("Example", 'A');
```

***

you **cannot** directly access the elements of a `std::pair` in C++ using the syntax `p[0]` and `p[1]`. The `std::pair` class does not overload the `operator[]`, so trying to use indexing like this will result in a compilation error.

```cpp
pair<char,char> p  = { 'a', 'b'}; ✅
// or
pair<char,char> p('a', 'b'); ✅
```

```cpp
p.first; // ='a' ✅
p.second; // ='b' ✅

p[0]; // ='a'? ❌ Compilation error
p[1]; // ='b'? ❌ Compilation error
```
