---
description: From Interview Bits Blog 📋
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

# OOPS Important Questions (Interview Bits)

### [OOPSs MCQ InterviewBits](https://www.interviewbit.com/oops-mcq/)

#### Overview of OOPS

OOPS is Object-Oriented Programming.  It is an approach to developing software programming. It was introduced to overcome flaws in the procedural approach to programming such as reusability and maintainability. Object-oriented programming or OOPS is a methodology of designing an application using classes and objects.

The fundamental idea behind object-oriented language is to combine into a single unit with both data and functions.

The data and functions that operate on that data such as a unit are called an object.

A class is a blueprint from which objects are created. A class describes the state or behavior of an object. A class can have attributes and methods:

* Attributes: An Attribute is a public variable inside the class/object. For example, Length is an attribute of int data type. In other words, **class attributes** are the variable within a class.  You can access attributes by creating an object of a class and by using dot syntax(.).
* Methods: A method is a group/block of code that takes input from the user, process it, and provides the output. The method runs only when it is called.

**Object:**  An object is an instance of a class. It contains an address and takes up memory space. Objects have states and behavior defined as per their template definition.

1. **Instance member variable:** Attributes, data members, field, properties.
2. **Instance member functions:** Methods, procedures, actions, operations, services.

**Message Passing**

* Message passing in OOP-> the process of **communication between objects** in a program. It allows objects to interact with each other by invoking methods or functions.

```cpp
Car myCar;
// `myCar` object receives the message `start()`
myCar.start();
```

### Features of OOPS

There are primarily four pillars of OOPS:

* Data abstraction :
  * Data hiding: It hides implementation details while just presenting the features to the outside world
  * Reduces code complexity
  * Hides details and exposes the essential parts.
* Inheritance: Reusability
  * Mechanism of deriving a new class from an existing class.
  * Types:
    * Single level
    * Multi-level
    * Multiple
    * Hierarchical
    * Hybrid
* Polymorphism: Object to take many forms
  * Types:
    * Compile-time polymorphism
    * Run time polymorphism
* Encapsulation :
  * Hiding the data for purpose of protection.
  * Writing data and functions into a single unit.

**Important MCQ ⭐**

***

* Object -> an instance of the class
* Memory Allocated for the Object -> RAM

***

⭐

```
"when a variable comes into existence in memory" is determined on what basis

- Data Type
- Storage Class ✅
- Scope
```

**Data Type:**

* When a variable is declared, the compiler determines the kind of value it can hold and the amount of memory allocated for it based on its data type `int, float, char`

**Storage Class:**

* The **storage class** determines **Lifetime** (How long the variable exists in memory), **Visibility** (Where the variable can be accessed in the program), **Storage location** (Where the variable is stored (e.g., RAM or registers).

1. `auto int x = 10` - Exists throughout the program's execution but retains block-level scope.
2. `static int x = 10` - Exists throughout the program's execution but retains block-level scope.
3. `extern int x = 10` - Declared outside all blocks and can be accessed across files.
4. `register int x = 10` - Suggests the variable be stored in CPU registers for faster access.

**Scope:**

* The **scope** of a variable determines the portion of the program where it is valid and accessible

1. Local Scope - Exists only inside a function.
2. Global Scope - Declared outside all functions and accessible throughout the program.
3. Block Scope - Declared within a specific block `{ }` and destroyed when the block ends. `if`, `while`, `for`
4. File Scope - Variables declared as `static` outside functions are accessible only within that file.

***

⭐

1. `static int counter=0` - **Inside functions** ( Retains the value of the variable between function calls), **Inside classes** (Shared among all objects of the class (class-wide variable or function), **Global scope**( Restricts the visibility of the variable/function to the file)
2. `const int x = 10` - variables must be initialized at the time of declaration and Specifies that a variable’s value **cannot be modified** after initialization
3. `static const int x=10` - Shared + Immutable

***

Constructor - `class_name()` Destructor - `~class_name()` tilde \~

***

Access Data members of Class - `.` & `->` are used, as required.

***

No. of Access Specifier in OOPS in C++ -> `3` (Private, public, protected) Total type of Constructor in C++ -> `3` (Default, Parameterized, copy) Total type of Polymorphism in C++ -> `2` (Runtime , Compile time) Total instance of abstract class that can be created -> `0` (instance of abstract class cannot be created)

***

⭐

```
Virtual Function should be
- Public ✅
- Private 
- Protected 
```

```
Virtual Function should be defined in 
- Base Class ✅
- Derived Class 
```

***

```
What is Cout?
- Operator
- Object ✅
- Function
- Macro
```

***

```
What are the "total catch blocks that can be used using a single Try block"?
- 1
- 2
- According to needs ✅
- Maximum 256
```

1. `Try { }` - used to enclose code that might throw an **exception** and allows you to test a block of code for errors during runtime.
2. `catch (ExceptionType e){ }` - used to handle exceptions thrown by the `try` block. multiple `catch` blocks can be used to handle different types of exceptions.

* **How They Work Together** ⭐
  * Code in the `try` block executes until an exception is thrown.
  * When an exception occurs, the program control is transferred to the matching `catch` block.
  * If no exception is thrown, the `catch` block is skipped.

```cpp
try { // Code }
catch (int e) { /* Handles int exceptions */ }
catch (double e) { /* Handles double exceptions */ }
catch (...) { /* Handles all other exceptions */ }
```

***

Scope Resolution Operator -> `::` number of parameters that a default constructor requires -> `0` How is object created at run-time -> using `new` keyword

***

⭐

```
What type of inheritance does single-level inheritance support?
- Compile-time
- Runtime inheritance ✅
- Multiple inheritances
- Language independent
```

* The runtime inheritance is done when object of a class is created to call a method. At runtime the function is searched if it is in class of object. If not, it will search in its parent classes and hierarchy for that method.

***

⭐

```
What is the implicit return type of constructor?
- No return type
- A class object in which it is defined. ✅
- void
```

***

⭐

```
Identify the pure object-oriented programming language among the following.
- C++
- SmallTalk ✅
- Java
- Python
```

Father of OOPS -> `Alan Kay`

**Alan Kay**, Influenced by the work at MIT and the Simula language, in November 1966 Alan Kay began working on ideas that would eventually be incorporated into the `Smalltalk` programming language. Kay used the term "object-oriented programming" in conversation as early as 1967

***

Virtual Function mainly used to achieve -> Runtime Polymorphism

```
Why is reusability a desirable feature

- Reduces compilation time 
- Decreases testing time ✅
- Lowers maintenance cost
```

***

```
Choose whether True or False: The constructor function can be constant.
- True
- False ✅
- Depends on implementation
```

***

Another name of Generic Class -> Template Class

A **generic class** ->a class that can operate on **any data type**. It uses **templates** to define its structure and functionality, allowing the same class to work with different types without rewriting the code for each type.

* Generic programming promotes Type flexibility, reusability and type safety.
* **C++ Standard Template Library (STL)**: Containers like `vector`, `stack`, `queue`, etc., are implemented as generic classes.

**Template** ->a generic programming feature that allows creating classes or functions that can work with any data type. It enhances **code reusability** and **type independence**.

```cpp
vector<int> numbers; // Vector of integers 
vector<string> words; // Vector of strings
```

```cpp
// Template for Vector Class
template <typename T> // T = int, string
class Vector {
private:
    T* arr;    // Dynamic array to store element of type T : int* arr, string* arr
    int size;     // Track Current no. of element in Vector 
    int capacity; // Tracks the maximum number of elements the vector can hold before resizing

public:
    // Constructor
    Vector() {
        size = 0;
        capacity = 1;
        arr = new T[capacity]; // new int[1] , new string[1]
    }
};
```

***

By default, fields in a structure of a C Program is -> `public` By default, members in a Class of a C++ Program is -> `private`

***

```
Choose the option below which can show polymorphism.

Overloading ||
Overloading << ✅
Overloading &&
Overloading +=
```

Reason: **Polymorphism** is about **different behaviors** depending on the type of object at runtime. Logical operators (`||`, `&&`) and assignment operators (`+=`) don't allow this kind of flexible behavior as they are either predefined for fundamental operations or focused on state modification rather than defining actions for different object types.

The following operators **cannot be overloaded** in C++: **`::`** (Scope resolution operator) ,**`.`** (Member access operator), **`.*`** (Pointer to member operator), **`sizeof`** , **`typeid`**, **`const_cast`**, **`dynamic_cast`**, **`reinterpret_cast`**

***

```
Choose the option below which describes the overloading of functions or Operator.
- Ad-hoc polymorphism ✅
- Virtual polymorphism
- Pseudo polymorphism
- Transient polymorphism
```

Another name of Overloading -> Ad-hoc Polymorphism

**Ad-hoc polymorphism** refers to the ability of a function or operator to behave differently based on the **specific types of its arguments**.

The term **"ad-hoc"** means "for this purpose" or "specific to this case." In ad-hoc polymorphism, the polymorphic behavior is not generalized across different types; it is **specific to the function or operator** being overloaded and depends on the **exact types** used in a particular context.

***

```
Choose the option below which is **not** a member of the class.
- Friend function ✅
- Static function
- Virtual function
- Const function
```

***

Which feature is shown by function overloading -> polymorphism Which is used to implement late binding -> Virtual Function

***

```
which is used to free the memory allocated for an object in C++.
- Free()
- unallocate()
- delete ✅
- collect
```

⭐

```
Dynamic memory allocation can be done using?
- calloc()✅
- malloc()✅
- create()
```

* `malloc(size)` allocates a block of memory of the specified `size` but **does not initialize** it. The contents of the allocated memory are **uninitialized** and may contain garbage values.
* `calloc(n, size)` allocates memory for `n` elements, each of size `size`, and **initializes all the memory to zero**.

***

⭐

```
which overloads using the friend function.

- ()
- ->
- *
- =
```

**friend functions** can be used to overload operators, especially when you want to define the behavior of an operator for custom classes, where the class is neither the left-hand nor right-hand operand of the operation. This is particularly useful for **binary operators** like `+`, `-`, `*`, and others when you need access to the private members of the class.

ex:

```cpp
class Complex {

    friend Complex operator+(const Complex& c1, const Complex& c2);
...
};

// Friend function definition to overload '+' operator
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
```

***

⭐

```
Object can be passed as a function.
- True
- False ✅
- Depends on implementation
```

**Object can't be passed as function as it is an instance of some class, it's not a function**. Object can be passed by reference, value or copy. There is no term defined as pass as function for objects.

***

Encapsulation -> Binding Abstraction -> Hiding Inheritance -> Reusability Polymorphism -> Multiple form

***

```
abstract data type among the following.
- double
- int
- class ✅
- string
```

***

**Message Passing** ->the feature in OOP, that allows one object to interact with another by sending messages, typically through method calls. This enables objects to communicate and invoke behaviors on each other.

***

```
Identify the feature which can be implemented using encapsulation.
- Abstraction ✅
- Encapsulation
- Polymorphism
- Inheritance
```

* **Abstraction** is the concept of hiding the internal details and showing only the essential features of an object. Encapsulation helps achieve abstraction by restricting access to the internal workings of an object and providing controlled access via methods (getters and setters).
* Why not Encapsulation -> This is the concept being implemented, so it is not the feature we are looking for.

***

Identify the feature, which is used to reduce the use of nested classes -> Inheritance

***

⭐

```
50. Identify the option below which cannot be used with the term "virtual".
- constructor ✅
- destructor
- class
- Member function
```

* A **constructor** is used to initialize an object of a specific class, so there is no need for a constructor of another class. C++ is a statically typed language, so the compiler needs to know the exact type at compile time to allocate memory and initialize the object. If a constructor is made virtual, the compiler will flag an error.&#x20;
* Why not Destructor -> A virtual destructor ensures that the order of destruction of each class in a hierarchy is carried out correctly. This helps to avoid memory leaks.  A common guideline is that a destructor for a base class must be either public and virtual or protected and nonvirtual.

***

⭐

```
Identify the option below which is not a property of the object.
- Names ✅
- Attributes
- Identity
- Properties
```

Names are not a property of an object. The other options, attributes, identity, and properties, are all properties of an object:&#x20;

* **Attributes**: These are the data members or properties of an object that store its state or characteristics.
* **Identity**: Every object has a unique identity in memory, which distinguishes it from other objects, even if they have the same attributes.
* **Properties**: Often used interchangeably with attributes, describing the characteristics of an object.
