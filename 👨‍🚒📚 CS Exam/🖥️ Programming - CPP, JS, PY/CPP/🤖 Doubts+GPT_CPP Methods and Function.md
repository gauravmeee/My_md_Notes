
- Methods and Functions are Not Same
- **All methods are functions**, but **not all functions are methods**.
- Methods can access object-specific data through `this`. Functions cannot.

**Function**: 
- Function is a standalone block of code that performs a task.
- It Lives in global or namespace scope. It doesn’t have access to class members unless passed explicitly. Called normally:
```cpp
int add(int a, int b) { return a + b; }
```


- **Method (Member Function)**
- Method is a function that is part of a class and can access its data members.
- It Lives inside a class. Each object has its own context (`this` pointer) pointing to the object’s data. Called via object:
```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
};
```