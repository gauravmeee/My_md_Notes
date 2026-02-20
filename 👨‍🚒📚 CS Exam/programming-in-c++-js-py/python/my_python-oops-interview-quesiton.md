# ⭐ My\_Python OOPS Interview Quesiton

## [Python OOPS Interview question](https://www.geeksforgeeks.org/python-oops-interview-question/)

In [Python](https://www.geeksforgeeks.org/python-programming-language-tutorial/), **Object-Oriented Programming (OOP)** allows developers to structure their code in a more efficient, scalable, and maintainable way by using classes and objects. These objects can have attributes (data) and methods (functions) that represent both the state and behaviour of an entity. Python OOP provides a powerful approach to managing complex systems and applications.

Table of Content

* [Basic OOPS Interview Questions](https://www.geeksforgeeks.org/python-oops-interview-question/#basic-oops-interview-questions)
* [Intermediate Python OOPs Interview Questions](https://www.geeksforgeeks.org/python-oops-interview-question/#intermediate-python-oops-questions)
* [Advanced Python Interview OOPs Questions](https://www.geeksforgeeks.org/python-oops-interview-question/#advanced-python-oops-questions)

In this article, we will explore common **Object-Oriented Programming(OOP) interview questions** related to Python. Let’s explore some key OOP interview questions that will help you master Python’s OOP features.

### Basic OOPS Interview Questions

#### **1. What is Object-Oriented Programming (OOP)?**

[Object-Oriented Programming (OOP)](https://www.geeksforgeeks.org/python-oops-concepts/) is a fundamental paradigm in Python which is designed to model real-world entities through classes and objects. It offers features like **encapsulation, inheritance, polymorphism, and abstraction** enabling developers to write reusable, modular, and maintainable code.

#### 2. What are the key features of OOP?

The key features of oop are:

* [**Encapsulation**](https://www.geeksforgeeks.org/encapsulation-in-python/): Bundles data and methods within a class, hiding internal details from outside access.
* [**Abstraction**](https://www.geeksforgeeks.org/abstract-classes-in-python/): Hides complex implementation details and exposes only necessary functionality.
* [**Inheritance**](https://www.geeksforgeeks.org/inheritance-in-python/): Allows a new class to inherit properties and methods from an existing class.
* [**Polymorphism**](https://www.geeksforgeeks.org/polymorphism-in-python/): Enables a single interface to represent different behaviors.

#### 3. What is a class and an object in Python?

* [**Class**](https://www.geeksforgeeks.org/python-classes-and-objects/): A blueprint for creating objects, defining their properties and methods.
* [**Object**](https://www.geeksforgeeks.org/python-object/): An instance of a class.

**Example:**

`class Dog: def __init__(self, name, breed): self.name = name self.breed = breed def speak(self): print(f"{self.name} says Woof!") dog1 = Dog("Buddy", "Golden Retriever") dog1.speak()`

#### 4. What is the difference between a class and an instance?

* Class: Defines the structure and behavior ([attributes](https://www.geeksforgeeks.org/difference-between-attributes-and-properties-in-python/) and methods).
* Instance: A concrete occurrence of a class with actual data

#### 5. **What is the** **`**__init__**`** **method in Python?**

The [`__init__`](https://www.geeksforgeeks.org/__init__-in-python/) method is a constructor used to initialize an object’s attributes when it is created and it is also known as constructor. The **init** method is part of Python's object-oriented programming (OOP) mechanism and is used to set up the initial state of the object when it is instantiated.

**Example:**

`class Person: def __init__(self, name): self.name = name p = Person("Alice")`

#### 6. **What is** **`**self**`** **in Python classes?**

[`self`](https://www.geeksforgeeks.org/self-in-python-class/) is a reference to the current instance of the class. It is used to access attributes and methods of the class. When you define a method inside a class, the first parameter of the method is always self, which allows the method to refer to the object (or instance) on which the method was called.

#### 7. What is the difference between instance variables and class variables?

* **Instance variables**: Instance variables unique to each object.
* **Class variables**: Shared among all objects of a class.

**Example:**

`class Demo: class_var = "shared" # class variable def __init__(self, val): self.instance_var = val # instance variable`

#### 8. What is inheritance in Python?

[Inheritance](https://www.geeksforgeeks.org/inheritance-in-python/) allows a class to inherit attributes and methods from another class. Inheritance enables the child class to inherit the properties (attributes) and behaviors (methods) of the parent class, and it can also define its own additional attributes and methods or override existing ones.

**Example:**

`# Define the Parent class (base class) class Parent: pass # Define the Child class that inherits from Parent class class Child(Parent): pass`

#### 9. **What is method overloading in Python?**

[**Method overloading**](https://www.geeksforgeeks.org/python-method-overloading/) in Python refers to the ability to define multiple methods with the same name but with different **parameters** (different numbers or types of arguments).

**Example:**

`def greet(name="Guest"): # Print a greeting message, using the 'name' argument. print(f"Hello, {name}")`

#### 10. What is method overriding in Python?

[Method overriding](https://www.geeksforgeeks.org/method-overriding-in-python/) allows a subclass to provide a specific implementation of a method that is already defined in its superclass. This means that the subclass can "override" the behavior of the method inherited from the parent class, providing a different version that is more suitable for the subclass.

**Example:**

`class Parent: def show(self): print("Parent") class Child(Parent): def show(self): # Method overriding print("Child")`

### Intermediate Python OOPs Interview Questions

#### 11. What is polymorphism in Python?

[Polymorphism](https://www.geeksforgeeks.org/polymorphism-in-python/) allows objects to be treated as instances of their parent class, enabling different implementations for the same interface. It enables a single function, method, or operator to work with different types of objects in a way that is determined at runtime, allowing code to be more flexible and reusable.

**Example:**

`class Bird: # Method to make a sound for the Bird class def speak(self): print("Chirp") class Dog: # Method to make a sound for the Dog class def speak(self): print("Bark")`

#### 12. What is encapsulation, and how does Python achieve it?

Encapsulation is one of the fundamental principles of OOP. It allows the internal representation of an object to be hidden from the outside world and exposes only what is necessary through a controlled interface.

**Example:**

`class Example: def __init__(self): self.__private_var = 42`

#### 13. What is the `super()` function in Python?

[`super()`](https://www.geeksforgeeks.org/python-super/) allows access to methods of the parent class and it’s often used to call the parent class’s constructor.

**Example:**

`class A: def method(self): print("Method in class A") class B(A): def method(self): super().method() # Call method from class A print("Method in class B") class C(A): def method(self): super().method() # Call method from class A print("Method in class C")`

#### 14. What are abstract classes in Python?

[Abstract class](https://www.geeksforgeeks.org/abstract-classes-in-python/) is a class that serves as a blueprint for other classes. It defines a structure that derived classes must follow but does not provide full implementation, abstract classes cannot be instantiated directly which means they are meant to be subclassed.

**Example:**

`from abc import ABC, abstractmethod class Animal(ABC): @abstractmethod def sound(self): pass`

#### 15. What is the difference between `is` and `==`?

'is' checks if two objects are the same instance(identity) and '==' checks if the two objects have the same value(equality).

#### 16. What is multiple inheritance in Python?

[Multiple inheritance](https://www.geeksforgeeks.org/multiple-inheritance-in-python/) allows a subclass to inherit features from multiple parent classes, making it more versatile and capable of combining behaviors from different sources.

`class ChildClass(ParentClass1, ParentClass2, ...): # Class body`

#### 17. What is the diamond problem in multiple inheritance? How does Python handle it?

The **Diamond Problem** in [multiple inheritance](https://www.geeksforgeeks.org/multiple-inheritance-in-python/) is a classic issue that arises when a class inherits from two classes that both inherit from a common ancestor. The problem occurs because, in such a scenario, it's unclear which version of the inherited method should be invoked when the method is called on the subclass.

#### 18. What are class methods in Python?

Class methods are defined with the [`@classmethod` decorator](https://www.geeksforgeeks.org/classmethod-in-python/) and take '`cls'` (class reference) as their first argument.

`class Demo: @classmethod def info(cls): print("Class Method")`

#### 19. What is the difference between `staticmethod` and `classmethod`?

In Python, both [@staticmethod and @classmethod](https://www.geeksforgeeks.org/class-method-vs-static-method-python/) [`@staticmethod` and `@classmethod`](../../../%F0%9F%91%A8%E2%80%8D%F0%9F%9A%92%F0%9F%93%9A%20CS%20Exam/%F0%9F%96%A5%EF%B8%8F%20Programming%20-%20CPP,%20JS,%20PY/Python/https:/) are used to define methods that are not bound to the instance of the class (i.e., they can be called on the class itself).

| Aspect                             | ### `staticmethod`                                   | ### `classmethod`                                                   |
| ---------------------------------- | ---------------------------------------------------- | ------------------------------------------------------------------- |
| Binding                            | Not bound to either the instance or the class.       | Bound to the class, not the instance.                               |
| First Argument                     | Does not take self or cls as the first argument.     | Takes cls as the first argument (refers to the class).              |
| Access to Class/Instance Variables | Cannot access or modify instance or class variables. | Can access and modify class variables (but not instance variables). |
| Call                               | Can be called on the class or an instance.           | Can be called on the class or an instance.                          |

#### 20. What are magic methods in Python?

[Magic methods](https://www.geeksforgeeks.org/dunder-magic-methods-python/)(dunder methods) start and end with double underscores providing operator overloading and custom behaviors.

> **Examples:** `__str__`, `__len__ and` , **init** so on...

### Advanced Python Interview OOPs Questions

#### 21. How does Python handle garbage collection?

Python uses automatic garbage collection to manage memory by identifying and removing unused objects and It employs reference counting and a cyclic [garbage collector](https://www.geeksforgeeks.org/garbage-collection-python/).

#### 22. What is metaclass in Python?

A [metaclass](https://www.geeksforgeeks.org/python-metaclasses/) is a class of a class that defines how classes behave and classes are instances of metaclasses. Essentially, metaclasses define the "rules" for building classes, much like a class defines the rules for creating objects.

**Example:**

`class Meta(type): # This is an empty metaclass that inherits from 'type' pass class Demo(metaclass=Meta): # The 'metaclass=Meta' instructs Python to use the 'Meta' metaclass pass`

#### 23. How is data hiding implemented in Python?

[Data hiding](https://www.geeksforgeeks.org/data-hiding-in-python/) is implemented using private attributes (\_\_attribute) and even though it is not completely hidden, it is still difficult to access without name mangling.

#### 24.What is the purpose of **slots** in Python classes?

[**slots**](https://www.geeksforgeeks.org/python-use-of-__slots__/) attribute limits the attributes that can be added to an instance improving memory usage.

**Example:**

`class Example: __slots__ = ['name', 'age']`

#### 25. What is the Global Interpreter Lock (GIL) and its impact on Python OOP?

The [GIL](https://www.geeksforgeeks.org/what-is-the-python-global-interpreter-lock-gil/) ensures only one thread executes Python bytecode at a time affecting multithreaded programs. Its purpose is to prevent multiple native threads from executing Python bytecode at the same time, ensuring thread safety in Python's memory management system. .

#### 26.How do you achieve operator overloading in Python?

Operator overloading is achieved using magic methods like [**add**](https://www.geeksforgeeks.org/python-__add__-magic-method/) and **eq**.

**Example:**

`class Point: def __add__(self, other): return Point(self.x + other.x)`

#### 26. What is the difference between shallow copy and deep copy in Python?

In Python, [shallow copy and deep copy](https://www.geeksforgeeks.org/difference-between-shallow-and-deep-copy-of-a-class/) are used to create copies of objects. They differ in how they handle nested objects, such as lists within lists or objects containing other objects. A **shallow copy** creates a new object but does not copy the nested objects inside it and A deep copy creates a new object and recursively copies all objects within it, including nested objects.

#### 27. What is the difference between composition and inheritance?

[Composition and inheritance](https://www.geeksforgeeks.org/inheritance-and-composition-in-python/) are two fundamental object-oriented programming (OOP) techniques for creating relationships between classes. The main difference between inheritance and composition is that:

* **Inheritance:** "Is-a" relationship (e.g., a Car is-a Vehicle).
* **Composition:** "Has-a" relationship (e.g., a Car has-a Engine).

#### 28. How do you implement design patterns like Singleton in Python?

[Singleton](https://www.geeksforgeeks.org/singleton-method-python-design-patterns/) ensures only one instance of a class exists. it design pattern ensures that a class has only one instance and provides a global point of access to it.

**Example:**

`class Singleton: _instance = None def __new__(cls, *args, **kwargs): if not cls._instance: cls._instance = super().__new__(cls) return cls._instance`

#### 29. Explain Python’s MRO with an example.

Python's , determines the order in which classes are searched when calling a method or accessing an attribute. It is crucial in object-oriented programming, especially when dealing with multiple inheritance.

**Example:**

`class A: # Class A is a base class with no methods or attributes pass class B(A): # Class B inherits from A pass class C(A): # Class C also inherits from A pass class D(B, C): # Class D inherits from both B and C pass print(D.mro())`

#### 30. How would you identify the MRO of a class programmatically?

We can identify the Method Resolution Order (MRO) of a class programmatically in Python using the [mro()](https://www.geeksforgeeks.org/method-resolution-order-in-python-inheritance/) Method or by using the [**mro**](https://www.geeksforgeeks.org/multiple-inheritance-in-python/) attribute.

* **Using the** **`**mro()**`** **method**: This method returns a list of classes in the order they are checked for method resolution.
* **Using the** **`**__mro__**`** **attribute**: This attribute directly provides the MRO as a tuple of classes.

***

## OOPS Questions from [Python Interview Questions and Answers](https://www.geeksforgeeks.org/python-interview-questions/)

**34. Does Python supports multiple Inheritance?**

When a class is derived from more than one base class it is called multiple Inheritance. The derived class inherits all the features of the base case.

![multipleinh](https://media.geeksforgeeks.org/wp-content/uploads/20191222084630/multipleinh.png)

Multiple Inheritance

Python does support multiple [inheritances](https://www.geeksforgeeks.org/inheritance-in-python/), unlike Java.

**35. What is Polymorphism in Python?**

[Polymorphism](https://www.geeksforgeeks.org/polymorphism-in-python/) means the ability to take multiple forms. Polymorphism allows different classes to be treated as if they are instances of the same class through a common interface. This means that a method in a parent class can be overridden by a method with the same name in a child class, but the child class can provide its own specific implementation. This allows the same method to operate differently depending on the object that invokes it. Polymorphism is about overriding, not overloading; it enables methods to operate on objects of different classes, which can have their own attributes and methods, providing flexibility and reusability in the code.

**36. Define encapsulation in Python?**

[Encapsulation](https://www.geeksforgeeks.org/encapsulation-in-python/) is the process of hiding the internal state of an object and requiring all interactions to be performed through an object’s methods. This approach:

* Provides better control over data.
* Prevents accidental modification of data.
* Promotes modular programming.

Python achieves encapsulation through **public**, **protected** and **private** attributes.

![Encapsulation-in-Python](https://media.geeksforgeeks.org/wp-content/uploads/20230501154755/Encapsulation-in-Python.webp)

Encapsulation in Python

**37. How do you do data abstraction in Python?**

[Data Abstraction](https://www.geeksforgeeks.org/data-abstraction-in-python/) is providing only the required details and hides the implementation from the world. The focus is on exposing only the essential features and hiding the complex implementation behind an interface. It can be achieved in Python by using interfaces and abstract classes.
