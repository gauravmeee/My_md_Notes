**Queue**: `push()` `pop()` `empty()` `front()` 
**Stack**: `push()` `pop()` `empty()`

`queue<int> myQue = {1, 2, 3};` ❌
`queue<int> myQue({1, 2, 3});` ✅ : using constructor
`queue<int> myQue` `from(i=1;i<=3;i++) myQue.push(i)` ✅ : push in loop

`myQue.size()` ✅

 `myQue[0]` ❌ : doesn't support direct access
 `myQue.front()` ✅ : only first element access is allowed

---
# Stack `#include <stack>`

#### Last In, First Out (LIFO)

**Basic Operations:**
Push, Pop, Top, Empty, Size

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

---
# Queue `#include <queue>`

#### First In, First Out (FIFO) principle.

**Basic Operations:**
Push, Pop, Front, Back, Empty, Size


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

### Additional Notes

- Both `std::stack` and `std::queue` are container adapters that use other underlying containers (like `std::deque` or `std::list`) to store elements.
- By default, `std::stack` uses `std::deque`, and `std::queue` also uses `std::deque`. You can change the underlying container if needed.

Feel free to ask if you have any specific questions or need more details!