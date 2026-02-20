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

# ▶️ Tutorial\_Python OOPS (Harry)

## [Introduction to OOPs in Python | Python Tutorial - Day #56](https://youtu.be/HQnoYzxOHMw)

Introduction to Object-Oriented Programming in Python: In programming languages, mainly there are two approaches that are used to write program or code.

* 1\). Procedural Programming
* 2\). Object-Oriented Programming

The procedure we are following till now is the “Procedural Programming” approach. So, in this session, we will learn about Object Oriented Programming (OOP). The basic idea of object-oriented programming (OOP) in Python is to use classes and objects to represent real-world concepts and entities.

A **class** is a blueprint or template for creating objects. It defines the properties and methods that an object of that class will have. Properties are the data or state of an object, and methods are the actions or behaviors that an object can perform.

An **object** is an instance of a class, and it contains its own data and methods. For example, you could create a class called "Person" that has properties such as name and age, and methods such as speak() and walk(). Each instance of the Person class would be a unique object with its own name and age, but they would all have the same methods to speak and walk.

* **Encapsulation** is the practice of restricting direct access to an object's data and allowing modifications only through methods. This protects data integrity and prevents unintended modifications. Example: using **private variables (`_variable` or `__variable`)** and **getters/setters**.
* **Abstraction** is the concept of hiding complex implementation details and exposing only the necessary functionalities. This helps in reducing complexity and increasing code usability. Example: using **abstract classes and methods** with the `ABC` module in Python.
* **Inheritance** allows new classes to be created that inherit the properties and methods of an existing class. This allows for code reuse and makes it easy to create new classes that have similar functionality to existing classes.
* **Polymorphism** is also supported in Python, which means that objects of different classes can be treated as if they were objects of a common class. This allows for greater flexibility in code and makes it easier to write code that can work with multiple types of objects.

In summary, OOP in Python allows developers to model real-world concepts and entities using classes and objects, encapsulate data, reuse code through inheritance, and write more flexible code through polymorphism.

***

## [Classes and Objects in Python | Python Tutorial - Day #57](https://youtu.be/a7baAGCBA9U)

### Python Class and Objects

A class is a blueprint or a template for creating objects, providing initial values for state (member variables or attributes), and implementations of behavior (member functions or methods). The user-defined objects are created using the class keyword.

**Creating a Class:**

Let us now create a class using the class keyword.

**Example:**

```python
class Details:
    name = "Rohan"
    age = 20
```

**Creating an Object:**

Object is the instance of the class used to access the properties of the class Now lets create an object of the class.

**Example:**

```python
obj1 = Details()
```

Now we can print values:

**Example:**

```python
class Details:
    name = "Rohan"
    age = 20

obj1 = Details()
print(obj1.name)
print(obj1.age)
```

**Output:**

```
Rohan
20
```

### Instance Method & self parameter

The self parameter is a reference to the current instance of the class, and is used to access variables that belongs to the class.

* It must be provided as the **extra parameter** inside the method definition. ⭐

**Example:**

```python
class Details:
    name = "Rohan"
    age = 20

    def desc(self):
        print("My name is", self.name, "and I'm", self.age, "years old.")

obj1 = Details()
obj1.desc()
```

**Output:**

```
My name is Rohan and I'm 20 years old.
```

**Creating Attributes and Methods Dynamically (i.e. after object is created)**

**1. To Class**

```python
class Details:
    pass  # Empty class

# Assigning variable to class
Details.name = "gaurav"

# Assigning function to class
def greet(self):
    print("hi")

Details.greet = greet
```

**2. To Object**

```python
class Details:
    pass

obj1 = Details()

# Assigning variable to object
obj1.name = "gaurav"

# Assigning function to object
import types
def greet(self):
    print("hi")

obj1.greet = types.MethodType(greet, obj1)
```

* Use `types.MethodType` to bind the function properly to the object.

***

## [Constructors in Python | Python Tutorial - Day #58](https://youtu.be/12HRkYld22c)

## Constructors

A **constructor** is a special method in a class used to create and initialize an object of a class. There are different types of constructors. Constructor is invoked automatically when an object of a class is created.

* **constructor** -> A unique function that gets called automatically when an object is created of a class.
* The main purpose of a constructor is to initialize or assign values to the data members of that class. It cannot return any value other than None.

**Syntax of Python Constructor**

```python
def __init__(self):
	# initializations
```

`__init__` is one of the reserved functions in Python. In Object Oriented Programming, it is known as a constructor.

**Types of Constructors in Python**

1. Parameterized Constructor
2. Default Constructor

**1. Parameterized Constructor in Python**

When the constructor accepts **arguments** along with **`self`**, it is known as parameterized constructor.

These arguments can be used inside the class to assign the values to the data members.

**Example:**

```python
class Details:
    def __init__(self, animal, group):
        self.animal = animal
        self.group = group

obj1 = Details("Crab", "Crustaceans")
print(obj1.animal, "belongs to the", obj1.group, "group.")
```

**Output:**

```
Crab belongs to the Crustaceans group
```

**2. Default Constructor in Python**

When the constructor doesn't accept any arguments from the object and has **only one argument**, `self`, in the constructor, it is known as a Default constructor.

**Example:**

```python
class Details:
  def __init__(self):
    print("animal Crab belongs to Crustaceans group")
obj1=Details()
```

**Output:**

```
animal Crab belongs to Crustaceans group
```

Note: - `self` refers to the **current object**, and is required to write in argument during member function definition, Even if you don’t use `self` inside the method. Because it Required in **instance methods** and Python automatically passes the object when you call `obj.method()`. It must be present to match the call.

```python
def hello(): # Not write 'self' in argument -> Give error ❌ during Call 
    print("Hello")

obj.hello()  # Internally -> Person.hello(obj)
```

Output:

```
❌ TypeError: hello() takes 0 positional arguments but 1 was given
```

***

## [Decorators in Python | Python Tutorial - Day #59](https://youtu.be/PTBZ674EsvI)

#### Decorators in Python

**Decorators** -> A function that takes another function as an argument, modifies it, and returns the modified function.

**Learning From Example**

**Example:** defining a function `greet()` for Adding Greetings Before and After a Function

```python
def greet(fx):  # Takes a function as an argument
    def mfx():  # Modified function
        print("Good Morning")
        fx()  # Call the original function
        print("Tata!")
    return mfx  # Return the modified function
```

**1. Using `greet()`** on a Defined Function

```python
def hello():
	print("Hello world")

greet(hello)() # Call with greet()
```

```sh
Good Morning
Hello World # Main Logic
Tata!
```

**2. Using `greet()`** as a **decorator** ⭐ by adding `@greet` before the function definition

```python
@greet
def hello(): # greet() already attach to it
	print("Hello world")

hello() # greet() applied automatically whenever it is called
```

```sh
Good Morning
Hello World # Main Logic
Tata!
```

Note:

* **Decorators are not hoisted** like regular Python functions, its mean the decorator **must be defined before** it is used.
* The `@decorator` syntax is a cleaner way to apply a decorator instead of manually calling it.

#### `*args` and `**kwargs` in Python

In Python, `*args` and `**kwargs` allow a function to accept any number of positional and keyword arguments.

A simple decorator **works normally** if the function it decorates does **not** take arguments -> **Works fine** ✅

```
greet(hello)() # Call with greet()
```

**Using `greet()`** as a **decorator** `@greet` during function definition (Even if functions take argument) -> **Works fine** ✅

```python
@greet
def add(a, b):
	print(a+b)

add()
```

```
good Morning
3
Tata!
```

But using **`greet()`** on a Defined Function that requires arguments -> Error ❌

```python
def add(a,b):
	print(a+b)

greet(add)(1, 2)
```

```
TypeError: mfx() takes 0 positional argument but 2 were given
```

**Why?**

* The inner function `mfx()` inside `greet()` does **not** accept arguments, but `add(a, b)` requires two arguments.

Solution: Modify `greet()` to Accept Arguments

modify `mfx()` to accept **any number of arguments** using `*args` and `**kwargs`. -> **Corrected ✅**

```python
def greet(fx): 
    def mfx(*args, **kwargs):  # Modify to take All arguments
        print("Good Morning")
        fx(*args, **kwargs) # Pass the Arguments to Actual function
        print("Tata!")
    return mfx 
```

Now, it works with functions that take arguments:

```python
def add(a,b):
	print(a+b)

greet(add)(1, 2)
```

```
good Morning
3
Tata!
```

* `*args` -> Collects all **positional** arguments as a tuple (type: `tuple`)
* `**kwargs` -> Collects all **keyword** arguments as a dictionary (type: `dict`)
* **Real use cases:** Logging, authentication, performance tracking, etc.

**Theory Notes**

**Python decorators** are a powerful and versatile tool that **allow you to modify the behavior of functions** and methods. They are a way to extend the functionality of a function or method without modifying its source code.

**Decorator** -> a function that takes another function as an argument and returns a new function that modifies the behavior of the original function. The new function is often referred to as a "decorated" function. The basic syntax for using a decorator is the following:

```python
@decorator_function
def my_function():
    pass
```

The `@decorator_function` notation is just a shorthand for the following code:

```python
def my_function():
    pass
my_function = decorator_function(my_function)
```

Decorators are often used to add functionality to functions and methods, such as logging, memoization, and access control.

**Practical use case**

1. One common use of decorators is to add logging to a function. For example, you could use a decorator to log the arguments and return value of a function each time it is called:

```python
import logging

def log_function_call(func):
    def decorated(*args, **kwargs):
        logging.info(f"Calling {func.__name__} with args={args}, kwargs={kwargs}")
        result = func(*args, **kwargs)
        logging.info(f"{func.__name__} returned {result}")
        return result
    return decorated

@log_function_call
def my_function(a, b):
    return a + b
```

* In this example, the `log_function_call` decorator takes a function as an argument and returns a new function that logs the function call before and after the original function is called.

2. In Flask `route` decorator binds the URL `'/'` to this function

```python
@app.route('/')
def home():
    return 'Welcome to the Homepage'
```

* the above code is equivalent to

```python
def home():
    return 'Welcome to the Homepage'
app.add_url_rule('/home', view_func=home)
```

* Flask maps the URL path `/about` to the function `about()` using `add_url_rule()` under the hood.

**Conclusion**

Decorators are a powerful and flexible feature in Python that can be used to add functionality to functions and methods without modifying their source code. They are a great tool for separating concerns, reducing code duplication, and making your code more readable and maintainable.

In conclusion, python decorators are a way to extend the functionality of functions and methods, by modifying its behavior without modifying the source code. They are used for a variety of purposes, such as logging, memoization, access control, and more. They are a powerful tool that can be used to make your code more readable, maintainable, and extendable.

***

## [Getters and Setters in Python | Python Tutorial - Day #60](https://youtu.be/2gbCT8h9uyk)

***

## [Inheritance in Python | Python Tutorial - Day #61](https://youtu.be/-KsfUaQEY9Y)

## [Access Modifiers in Python | Python Tutorial - Day #62](https://youtu.be/43FK20rWvKQ)

***

## [Abstraction & Encapsulation | Python Tutorials For Absolute Beginners In Hindi #59](https://youtu.be/wySW_E4XsvE)

***

## [Polymorphism In Python | Python Tutorials For Absolute Beginners In Hindi #64](https://youtu.be/xnb-9TI-BjQ?list=PLPLmXWcXdkUMJdtK66pOgo20n3unMtDnm)

## [Method Overriding in Python | Python Tutorial - Day #74](https://youtu.be/46_yfYC36JY)

***
