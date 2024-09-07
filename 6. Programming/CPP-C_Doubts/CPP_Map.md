
# Map `<map>` &  Unordered Map `<unordered_map>`

**Map Initialization Default Value**
```cpp
//Default Initialization
`std::map<int, int> m; // Empty map.`
    
//**Default Value on Access**:
`std::map<int, int> m; int value = m[10]; // Creates m[10] with default value 0 for int.`
```
---
You cannot Directly sort a `Map` based  on  by its values (Second value)
However, you can achieve the desired result by transferring the contents to a std::vector of pairs and then sorting the vector based on the values.
```cpp
std::sort(vec.begin(), vec.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) { return a.second < b.second; });
```

The `unordered_map<int, int>`automatically initializes missing keys with `0`, which is convenient for counting frequencies.

---


# Map and Unordered Map (By Chat GPT)

In C++, `std::map` and `std::unordered_map` are two associative containers used to store key-value pairs, but they differ in how they store and access elements.

### `std::map` (Ordered Map)
- **Ordered**: The elements are stored in a sorted order based on the keys. By default, the keys are sorted in ascending order.
- **Underlying Data Structure**: Typically implemented as a self-balancing binary search tree (like a Red-Black Tree).
- **Access Time**: The time complexity for insertion, deletion, and access is \(O(\log n)\).
- **Use Case**: Use `std::map` when you need the elements to be in a specific order or need to traverse the elements in sorted order.

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> orderedMap;

    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[2] = "Two";

    // Elements are automatically sorted by key
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

### `std::unordered_map`
- **Unordered**: The elements are stored in no particular order. The order may change as elements are added or removed.
- **Underlying Data Structure**: Implemented as a hash table.
- **Access Time**: The average time complexity for insertion, deletion, and access is \(O(1)\), but in the worst case, it can degrade to \(O(n)\) if there are many hash collisions.
- **Use Case**: Use `std::unordered_map` when you need fast access to elements and do not care about the order.

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> unorderedMap;

    unorderedMap[3] = "Three";
    unorderedMap[1] = "One";
    unorderedMap[2] = "Two";

    // Elements are not in any specific order
    for (const auto& pair : unorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

*Note:*
- **Order**: `std::map` keeps elements sorted by keys, while `std::unordered_map` does not.

- **Performance**: `std::unordered_map` generally provides faster access times compared to `std::map` due to its \(O(1)\) average time complexity.

- **Memory Usage**: `std::unordered_map` typically uses more memory due to the need for hash tables.

**Use case**:
  - Use `std::map` when you need to maintain a sorted order of elements or when you need to frequently traverse the elements in order.
  - Use `std::unordered_map` when you need faster lookups and don't care about the order of elements.
