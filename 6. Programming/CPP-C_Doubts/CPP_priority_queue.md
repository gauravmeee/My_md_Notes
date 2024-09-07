
In C++, the Standard Library provides in-built support for heaps through the `priority_queue` container. By default, a `priority_queue` is a max-heap, but it can be adapted to a min-heap as well. Here’s a brief overview of both:

### Max-Heap
In a max-heap, the maximum element is at the top, and each parent node is greater than or equal to its children.

**Default Behavior:**
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    
    std::cout << "Max-Heap top: " << maxHeap.top() << std::endl; // Outputs: 20

    return 0;
}
```

---
### Min-Heap
To create a min-heap, you can use `std::priority_queue` with a custom comparator. The custom comparator should ensure that the smallest element is at the top.

**Using a Custom Comparator:**
```cpp
#include <iostream>
#include <queue>
#include <vector>

struct Compare {
    bool operator()(int a, int b) {
        return a > b; // For min-heap
    }
};

int main() {
    std::priority_queue<int, std::vector<int>, Compare> minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    
    std::cout << "Min-Heap top: " << minHeap.top() << std::endl; // Outputs: 5

    return 0;
}
```
 
 or

using inbuilt comperator
```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // used for greater<int> 

int main() {
    std::priority_queue<int, std::vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    
    std::cout << "Min-Heap top: " << minHeap.top() << std::endl; // Outputs: 5

    return 0;
}

