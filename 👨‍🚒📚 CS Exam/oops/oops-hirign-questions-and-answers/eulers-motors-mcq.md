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

# Euler's Motor's MCQ



```
Which of the following best defines the concept of 'Polymorphism' in C++?

- The ability of a function or operator to behave in different ways depending on the
types of its arguments.✅
```

```
Which of the following is an example of dynamic polymorphism?

- Calling a method of a derived class through a base class reference at runtime. ✅
```

```
What is an abstract class in C++?

- A class that cannot be instantiated
- A class that must contain at least one pure virtual function ✅
```

```
Which of the following best describes a memory leak?⭐

- When memory is reused from the heap without being properly released, leading to
inefficient memory management.

- When memory is allocated dynamically but never deallocated, causing the program
to consume more memory over time. ✅
```

```
What is a dangling pointer?

- A pointer that points to a variable that has been deallocated ✅
```

```
What is the function of the `new` keyword in C++?
- To create a new variable
- To allocate memory on the heap
'new' keyword in C++? ✅
```

```
Which of the following best describes the term "heap" in memory management?

- A region of memory used for dynamic memory allocation ✅
```

```
Which operators cannot be overloaded in C++?

- :: ✅
- . ✅
- sizeof ✅
- .* ✅
- ?: ✅
```

**C++ Code Predict Output**

```cpp
class SyntaxWizard {
public:
    SyntaxWizard() {
        cout << "Constructor called\n";
    }
    
    ~SyntaxWizard() {
        cout << "Destructor called\n";
    }
};

int main() {
    SyntaxWizard obj;  // Constructor is called here
    return 0;  // Destructor is called here when obj goes out of scope
}
```

or

```cpp
int main() {
    syntaxwizard *obj = new syntaxwizard(); // Constructor will be called here
    delete obj; // Destructor will be called here
    return 0;
}
```

```
output
- Constructor called Destructor called ✅
```

```cpp
class MyClass {
public:
    static int count;
    MyClass() {
        count++;
    }
};

int MyClass::count = 0; // Initialize the static variable

int main() {
    MyClass obj1;  // Constructor is called, count is incremented
    MyClass obj2;  // Constructor is called, count is incremented
    cout << MyClass::count << endl;  // Output the static count
    return 0;
}
```

```
output
- 2 ✅
```

```cpp
class Base {
public:
    virtual void show() = 0; // Pure virtual function
};

int main() {
    cout << "Hello world!" << endl;
    Base obj; // Compilation error: cannot create object of abstract class
    cout << obj.show() << endl;
    return 0;
}
```

```
output
- Compilation Error: cannot declare variable 'obj' to be of abstract type 'Base' ✅
```

```cpp
class MyClass {
public:
    int num = 5;  // Data member with initial value

    // Default constructor to initialize 'num'
    MyClass() {
        this->num = 8;  // Assign a new value to 'num'
    }

    // Parameterized constructor to initialize 'num'
    MyClass(int num) {
        this->num = num;  // Assign the passed value to 'num'
    }

    // Method to display the value of 'num'
    void display(int data) {
        cout << "num = " << num << endl;  // Output the value of 'num'
    }
};

int main() {
    MyClass obj;  // Creating an object and initializing 'num' to 8 using the default constructor
    obj.display(10);  // Calling the display method, the 'data' parameter is not used
    return 0;
}
```

```
output
- num = 10
- num = 8 ✅
- num = 5
```

**Python Code Output:**

```
Predict the output of the following code snippet
```

```python
class MyClass:
    def __init__(self):  # Constructor method
        self.quantity = 2  # Initialize quantity
    
    def calc_price(self, quantity)->float:  # Method to calculate price
        self.quantity = quantity 
        return self.quantity * 10 

# Create an object of MyClass
obj = MyClass()
price = obj.calc_price(10)  # Calling calc_price method with 10 as argument
print(price, type(price))  # Print the result and its type of `self.quantity` which was 2 at starting, and print in integer until not return in float explicityly
```

```
output
- 20 <class 'int'>
```

Learnings ⭐

* `__init__`: The constructor method in Python that is used for initializing an object’s attributes.
* **`self`**: A reference to the current object, used to access its attributes and methods within the class.
* `def func() -> float` : The return to suggests that the method is expected to return a floating-point number. However, in the current code, the result of `self.quantity * 10` is an integer (`20`), until explictly return float

```
Predict the output of the following code snippet
```

```python
class Base:
    def display(self):
        print("Base", end=' ')

class Derived(Base):
    def display(self):
        print("Derived", end=' ')

obj1 = Base()
obj2 = Derived()

obj1.display()  # Calls Base class method
obj2.display()  # Calls Derived class method
Base.display(Derived)  # This line will cause an error
```

```
Base Derived
AttributeError: unbound method display() must be called with Base instance as first argument (got type Derived instead)
```
