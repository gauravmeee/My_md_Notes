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

# 🤖 Notes+GPT\_Python Stack and Queue

Stacks and queues are fundamental data structures used in programming. Here's how you can use them in Python:

#### Stack

A stack is a collection that follows the Last In, First Out (LIFO) principle. You can use a list or the `collections.deque` class to implement a stack.

**Using a List**

```python
# Stack implementation using a list
stack = []

# Push elements onto the stack
stack.append(1)
stack.append(2)
stack.append(3)

# Pop elements from the stack
print(stack.pop())  # Output: 3
print(stack.pop())  # Output: 2
print(stack.pop())  # Output: 1
```

**Using `collections.deque`**

deque: double-ended queue;

```python
from collections import deque

# Stack implementation using deque
stack = deque()

# Push elements onto the stack
stack.append(1)
stack.append(2)
stack.append(3)

# Pop elements from the stack
print(stack.pop())  # Output: 3
print(stack.pop())  # Output: 2
print(stack.pop())  # Output: 1
```

#### Queue

A queue is a collection that follows the First In, First Out (FIFO) principle. You can also use a list or the `collections.deque` class to implement a queue.

**Using a List**

```python
# Queue implementation using a list
queue = []

# Enqueue elements
queue.append(1)
queue.append(2)
queue.append(3)

# Dequeue elements
print(queue.pop(0))  # Output: 1
print(queue.pop(0))  # Output: 2
print(queue.pop(0))  # Output: 3
```

**Using `collections.deque`**

```python
from collections import deque

# Queue implementation using deque
queue = deque()

# Enqueue elements
queue.append(1)
queue.append(2)
queue.append(3)

# Dequeue elements
print(queue.popleft())  # Output: 1
print(queue.popleft())  # Output: 2
print(queue.popleft())  # Output: 3
```

***

1. **Time Complexity**:
   * **Lists**:
     * **Append**: O(1)
     * **Pop from end**: O(1)
     * **Pop from front**: O(n) (inefficient for queues)
   * **Deque**:
     * **Append**: O(1) (both ends)
     * **Pop**: O(1) (both ends, efficient for queues)
2. **Functionality**:
   * **Deque** allows efficient operations from both ends, making it versatile for implementing various data structures.
   * **Thread-Safety**: Deque operations are designed to be thread-safe.

#### Use Cases

* **Stacks**: Both lists and deques can be used effectively.
* **Queues**: Deque is preferred for better performance in enqueue and dequeue operations.

#### Conclusion

Use **lists** for stack implementations and **deque** for queues or when needing efficiency in adding/removing elements from both ends.
