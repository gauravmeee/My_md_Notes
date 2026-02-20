
**Queue**
- Operations: `push()`, `pop()`, `empty()`, `front()`, `back()`

**Stack**
- Operations: `push()`, `pop()`, `empty()`, `top()`

**Key Difference**:
- **Queue** → FIFO (First In First Out)
- **Stack** → LIFO (Last In First Out)


### **Queue & Stack Initialization**

**Queue Initialization & Access**
```cpp
    queue<int> myQue; // Initialize empty
    for(int i = 1; i <= 3; i++) myQue.push(i); // Push in loop
```
- ❌ `queue<int> myQue = {1, 2, 3};` ⭐ **not allowed**
- ✅ `queue<int> myQue({1, 2, 3});` ⭐ // using constructor
    

**Stack Initialization & Access**
```cpp
    stack<int> mySt; // Initialize empty
    for(int i = 1; i <= 3; i++) mySt.push(i); // Push in loop
```
- ❌ `stack<int> mySt = {1, 2, 3};` → **not allowed**
- ✅ `stack<int> mySt({1, 2, 3});` → works using constructor (rarely used)
    
##### **Queue vs Stack Operations**

**Queue** (FIFO)
- ✅ `myQue.size()` → number of elements
- ❌ `myQue[0]` → direct indexing **not allowed**
- ✅ `myQue.front()` → ==access first element==
- ✅ `myQue.back()` → ==access last element==
- ✅ `myQue.push(x)` → add element at back
- ✅ `myQue.pop()` → remove element from ==front==
    

**Stack** (LIFO)
- ✅ `mySt.size()` → number of elements
- ❌ `mySt[0]` → direct indexing **not allowed**
- ✅ `mySt.top()` → ==access top element==
- ✅ `mySt.push(x)` → ==add element at top==
- ✅ `mySt.pop()` → remove top ==element==

##### **Stack `#include <stack>`**
```cpp
std::stack<int> s;

// Push elements onto the stack
s.push(1);
s.push(2);
s.push(3);

// Display the top element
std::cout << "Top element: " << s.top() << std::endl;

// Pop the top element
s.pop();

// Display the new top element
std::cout << "New top element: " << s.top() << std::endl;

// Check if the stack is empty
if (s.empty()) {
	std::cout << "Stack is empty" << std::endl;
} else {
	std::cout << "Stack size: " << s.size() << std::endl;
}
```

##### **Queue `#include <queue>`**
```cpp
std::queue<int> q;

// Push elements into the queue
q.push(1);
q.push(2);
q.push(3);

// Display the front element
std::cout << "Front element: " << q.front() << std::endl;

// Pop the front element
q.pop();

// Display the new front element
std::cout << "New front element: " << q.front() << std::endl;

// Check if the queue is empty
if (q.empty()) {
	std::cout << "Queue is empty" << std::endl;
} else {
	std::cout << "Queue size: " << q.size() << std::endl;
}

```

**Additional Notes**
- Both `std::stack` and `std::queue` are ==container adapters that use other underlying containers== (like ==`std::deque`==  or  ==`std::list`==) to store elements.
-==By default==, ==`std::stack` uses `std::deque`==, and ==`std::queue` also uses `std::deque`==. You can change the underlying container if needed.
