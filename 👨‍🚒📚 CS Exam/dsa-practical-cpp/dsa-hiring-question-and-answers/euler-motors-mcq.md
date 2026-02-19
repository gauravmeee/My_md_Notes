---
description: Made by Me 💚
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

# Euler Motor's MCQ

```
Which of the following describes the concept of "stack overflow"?

- When the stack pointer exceeds the stack bound ✅
- When too many elements are pushed onto a stack "stack overflow"? ✅
- When the program tries to use more memory than the stack has available ✅
```

```
Which of the following is a valid variable name in C++?

- 2variable
- _variable ✅
```

```
Which of the following is the correct syntax to declare a function in C++?

- void myFunction(int x, int y) { }
- int myFunction(int x, int y); ✅
```

```
Which operator is used for dynamic memory allocation in C++?

- new ✅
- malloc
- calloc
```

```
What is the time complexity of searching an element in a binary search tree?

- O(log n) ✅
```

```
What is the time complexity of finding an element in a hash table with a good hash function?

- 0(1) ✅
```

```
What is the time complexity of the merge sort algorithm?

- O(n log n) ✅
```

```
Which data structure is best suited for implementing LIFO (Last In First Out)
behavior?

- Stack ✅
```

```
Which data structure is typically used for implementing priority queues?

- Queue
- Linked List
- Heap ✅
```

```
What is the purpose of hashing in data structures?

- To map data to keys for efficient retrieval ✅
- To store elements in a tree structure
```

```
What is the main advantage of using a linked list over an array?

- Efficient insertion and deletion of elements ✅
```

```
Which data structure is used for implementing recursion?
- Stack ✅
```

```
The data structure required for Breadth First Traversal on a graph is?
- Queue ✅
```

```
What is the main difference between a depth-first search (DFS) and a breadth-first search (BFS) in a graph?

- DFS explores as far as possible along each branch before backtracking, while BFS explores all neighbors at the present depth before moving on to nodes at the next depth level. ✅
```

```
Which algorithm is used to find the shortest path in an unweighted graph?

- Dijkstra's algorithm
- Bellman-Ford algorithm
- Floyd-Warshall algorithm
- Breadth-First Search (BFS) ✅
```

**C++ Code Output**

```cpp
int arr[5] = {1, 2, 3, 4, 5}; 
cout << arr[5]; 
```

```
output
- Runtime Error : out of bound array access ✅
```

```cpp
Int arr[3];
cout arr[2];
```

```
output
- garbage value ✅
```

```cpp
int x = 10, y = 5;
cout << (x > y ? x : y);
```

```
output
- 10 ✅
- 5 
```

```cpp
int x = 5;
int &ref = x; 
ref++; 
cout << x;
```

```
output
- 6
```

```cpp
int x = 5;
int *Ptr = &x;
cout << Ptr;
```

```
output
- Address of x
```

```cpp
void printDigits(int n) {
    if (n == 0)
        return;
    printDigits(n / 10);
    cout << n % 10;
}
int main() {
    printDigits(123);
    return 0;
}
```

```
output
- 321
```
