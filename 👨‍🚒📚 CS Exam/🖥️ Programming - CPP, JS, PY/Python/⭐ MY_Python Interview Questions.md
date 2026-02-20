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

# ⭐ MY\_Python Interview Questions

## [Python Interview Questions and Answers](https://www.geeksforgeeks.org/python-interview-questions/)

Python is the most used language in top companies such as Intel, IBM, NASA, Pixar, Netflix, Facebook, JP Morgan Chase, Spotify and many more because of its robust performance and powerful libraries. To get into these companies and organizations as a Python developer, we need to master some important **Python Interview Questions** to crack their Python Online Assessment Round and Python Interview Round. We have prepared a list of the **Top 50 Python Interview Questions** along with their answers to ace interviews.

**Table of Content**

1. Basic Python Interview Questions (Q. 1 to 23)
2. Intermediate Python Interview Questions (Q. 24 - 41)
3. Advanced Python Interview Questions ( Q. 42 - 54)

#### 1. Basic Python Interview Questions ✅

\####### **1. Is Python a compiled language or an interpreted language?**\* Python can be considered both compiled and interpreted, but in different stages of its execution process.

1. **Compilation**:
   * When you write Python code and run it, the Python interpreter first compiles your source code (`.py` files) into an intermediate form called bytecode (`.pyc` files).
   * **bytecode** -> lower-level representation of your code, but it is still not directly machine code. (It’s something that the Python Virtual Machine (PVM) can understand and execute.)
2. **Interpretation**:
   * After Python code is compiled into **bytecode**, it is executed by the Python Virtual Machine (PVM), which is an interpreter.
   * The **PVM** reads the bytecode and executes it line-by-line at runtime, which is why Python is considered an interpreted language in practice.

```
                   Compilation                 Interpretation
python code(.py) -------------> bytecode(.pyc) --------------> Machine Level Code
      ⬆                               ⬆ 
 Compiled by                        Interpret by
 Python Interpreter                Python Virtual Machine
```

Note: Some implementations, like `PyPy`, use Just-In-Time (JIT) compilation, where Python code is compiled into machine code at runtime for faster execution, blurring the lines between interpretation and compilation.

\####### **2. What is a dynamically typed language?** Programming Languages can be divided into the following two types.

1. **Statically typed languages:**
   * Data type of a variable is known at the compile time
   * Programmer has to specify the data type of a variable at the time of its declaration.&#x20;
   * Examples are C, C++, Java and C#
2. **Dynamically typed languages:**
   * Do not require any pre-defined data type for any variable
   * Interpreted at runtime by the machine itself. In these languages, interpreters assign the data type to a variable at runtime depending on its value.
   * Examples are Python and JavaScript Note: **Statically typed** languages are typically **faster** ⭐ than dynamically typed Languages and Dynamically typed languages are typically easy to code. Python is a Dynamically Typed language.

\####### **3. Is Indentation Required in Python?**

* Yes, indentation is required in Python.
* A Python interpreter can be informed that a group of statements belongs to a **specific block** of code by using Python indentation.
* Indentations **make the code easy to read** for developers in all programming languages but in Python, it is very important to indent the code in a specific order.

\####### **4. What are Built-in data types in Python?** The following are the standard or built-in **Datatypes** in Python:

1. **Numeric:**&#x20;
   * Represents the data that has a numeric value.
   * A numeric value can be an integer, a floating number, a Boolean, or even a complex number.
2. **Sequence Type:**
   * Ordered collection of similar or different data types.
   * There are several sequence types in Python: **String, Tuple, List, Range**
3. **Mapping Types:**&#x20;
   * In Python, **Hashable** data can be **mapped to random objects** using a mapping object. There is currently only one common mapping type, the dictionary and mapping objects are mutable.
   * **Python Dictionary**
4. **Set Types:**
   * Unordered collection of data types that is **Iterable**, mutable and has no duplicate elements.
   * The order of elements in a set is undefined though it may consist of various elements.

\####### **5. What is the difference between a Mutable datatype and an Immutable data type?**

* **Mutable data types** -> can be edited i.e., they can change at runtime. **ex:**  List, Dictionary, etc.
* **Immutable data types** -> can not be edited i.e., they can not change at runtime. **ex:** String, Tuple, etc. ⭐

\####### **6. What is a Variable Scope in Python?** The location where we can find a variable and also access it if required is called the **Scope of a variable**

* **Python Local variable ->** Initialized within a function + are unique to that function + cannot be accessed outside of the function.
* **Python Global variables->** Defined and declared outside any function + are not specified to any function.
* **Module-level scope->** Refers to the global objects of the current module accessible in the program.
* **Outermost scope:** Refers to any built-in names that the program can call. The name referenced is located last among the objects in this scope.

\####### **7. How do you floor and Ceil a number in Python?**

* **floor** -> by `math.floor(x)` = function, returns the largest integer less than or equal to the given number
* **ceil ->** by `math.ceil(x)` = `4`function, returns the smallest integer greater than or equal to the given number

```python
import math
math.floor(3.7) # 3
math.ceil(3.7) # 4
```

\####### **8. What is the difference between `/` and `//` in Python?**\*

* `/` -> **Precise division** (result is a floating point number)
* `//` -> **Floor division** (result is an integer)

```python
5/2 # 2.5
5//2 # 2
```

\####### 9. Difference between for loop and while loop in Python\*\*

* **For loop** -> Generally used to iterate through the elements of various collection types such as (List, Tuple, Set, Dictionary). Developers use a “for” loop where they have both the conditions start and the end.
* **While loop** -> It is the actual looping feature that is used in any other programming language. Note: Programmers use a Python **while loop** where they just have the **end conditions.** ⭐

\####### **10. Can we Pass a function as an argument in Python?** Yes, **Several arguments can be passed to a function**, including **objects, variables** (of the same or distinct data types) and functions.

* **Function can be passed** as parameters to other functions because they are **objects** ⭐.
* **Higher-order functions** -> functions that can take other functions as arguments.

\####### **11. What is a pass in Python?** ❓

* **`Pass`** statement -> It is `null` **operation** or a **placeholder** in Python .
* It is used when a statement is syntactically required but we don’t want to execute any code. It does nothing but allows us to maintain the structure of our program.
* **Example:** **Pass keyword** used in function when we define a function but don’t want to implement its logic immediately. It allows the function to be syntactically valid, even though it doesn’t perform any actions yet.

```python
def fun():
    pass  # Placeholder, no functionality yet

# Call the function
fun()
```

\####### **12. What is a break, continue and pass in Python?**

* **Break** -> used to **terminate the loop** or statement in which it is present. After that, the control will pass to the statements that are present after the break statement, if available.
* **Continue ->**  Continue statement is opposite to that of the break statement, instead of terminating the loop, it **forces to execute the next iteration of the loop**.
* **Pass** -> **Performing no operation** or in other words, it is a placeholder in the compound statement, where there should be a blank left and nothing has to be written there.

\####### **13. How are arguments passed by value or by reference in Python?**

* **Python’s argument-passing model** -> It is neither “**Pass by Value**” nor “**Pass by Reference**” but it is “**Pass by Object Reference**”. ⭐ Note: Depending on the type of object you pass in the function, the function behaves differently. Immutable objects show “pass by value” whereas mutable objects show “pass by reference”.

You can check the difference between **pass-by-value** and **pass-by-reference** in the example below: ⭐

```python
def call_by_value(x):
    x = x * 2
    print("in function value updated to", x)
    return

def call_by_reference(list):
    list.append("D")
    print("in function list updated to", list)
    return

my_list = ["E"]
num = 6
print("number before=", num)
call_by_value(num)
print("after function num value=", num)
print("list before",my_list)
call_by_reference(my_list)
print("after function list is ",my_list)
```

**Output :**

```
number before= 6
in function value updated to 12
after function num value= 6
list before ['E']
in function list updated to ['E', 'D']
after function list is  ['E', 'D']  
```

\####### **14. What is a lambda function?**

* **lambda function**  -> It is an anonymous function that can have any number of parameters but, can have just one statement. ⭐ In the example, we defined a lambda function(**upper**) to convert a string to its upper case using upper(). ⭐

```python
s1 = 'GeeksforGeeks'

s2 = lambda func: func.upper()
print(s2(s1))
```

**Output :**

```
GEEKSFORGEEKS
```

\####### **15. How is a dictionary different from a list?**

* **list** -> ordered collection of items accessed by their index, while a
* **dictionary** -> unordered collection of key-value pairs accessed using unique keys.

Note: Lists are ideal for storing **sequential data** (`[10, 20, 30]`, whereas dictionaries are better for storing associative data `{“a”: 10, “b”: 20, “c”: 30}`.

\####### 16. \*\*What is List Comprehension? \*\* ⭐

* **List comprehension** -> A way to create lists using a **concise syntax**. It allows us to generate a new list by applying an **expression** to each item in an existing **iterable** (such as a **list** or **range**). This helps us to write cleaner, more readable code compared to traditional looping techniques.

For example, if we have a list of integers and want to create a new list containing the square of each element, we can easily achieve this using list comprehension.

```python
a = [2,3,4,5]
res = [val ** 2 for val in a]
print(res)
```

**Output**:

```
[4, 9, 16, 25]
```

\####### **17. What are `*args` and `**kwargs`?** ⭐

1. **`*args`** -> The special syntax **`*args`** in function definitions is **used to pass a variable number of arguments to a function.** Python program to illustrate `*args` for a variable number of arguments:

```python
def myFun(*argv):
    for arg in argv:
        print(arg)

myFun('Hello', 'Welcome', 'to', 'GeeksforGeeks')
```

**Output:**

```
Hello
Welcome
to
GeeksforGeeks
```

**`**kwargs`** -> The special syntax `**kwargs` in function definitions is used to pass a variable length argument list.

```python
def fun(**kwargs):
    for k, val in kwargs.items():
        print("%s == %s" % (k, val))


# Driver code
fun(s1='Geeks', s2='for', s3='Geeks')
```

**Output :**

```
s1 == Geeks
s2 == for
s3 == Geeks
```

\####### 18. **What is the difference between a Set and Dictionary?**

* **Python Set** -> Unordered collection data type that is iterable, mutable and has **no duplicate elements**. Python’s set class represents the mathematical notion of a set.
* **Syntax**: Defined using curly braces `{}` or the `set()` function.

```python
my_set = {1, 2, 3}
```

* **Dictionary** -> Ordered collection of data values, used to store data values like a map, which, unlike other Data Types that hold only a single value as an element, Dictionary holds `key:value` pair. Key-value is provided in the dictionary to make it more optimized.
* **Syntax**: Defined using curly braces `{}` with key-value pairs.

```python
my_dict = {“a”: 1, “b”: 2, “c”: 3}
```

Note: Python Dictionary are Ordered since `Py 3.7` , and was Unordered `Py 3.6` & prior ⭐

\####### **19. How can you concatenate two lists in Python?** We can concatenate two lists in Python using the `+` operator or the **extend()** method.

1. **Using the + operator:** This creates a new list by joining two lists together.

```python
list1 = [1, 2, 3]
list2 = [4, 5, 6]
result = list1 + list2
print(result) 
```

**Output :**

```
[1, 2, 3, 4, 5, 6]
```

2. \*\*Using the extend() method: This adds all the elements of the second list to the first list in-place. ⭐

```python
list1 = [1, 2, 3]
list2 = [4, 5, 6]
list1.extend(list2)
print(list1) 
```

**Output:**

```
[1, 2, 3, 4, 5, 6]
```

**20. What is docstring in Python? ⭐**

**docstring** -> Python **documentation strings** provide a convenient way of associating documentation with Python modules, functions, classes and methods.

* **Declaring Docstrings:** The docstrings are declared using `'''triple single quotes'''` or `"""triple double quotes"""` just below the class, method, or function declaration. All functions should have a docstring.
* **Accessing Docstrings:** The docstrings can be accessed using the `__doc__` method of the object or using the help function.

\####### 21. **How is Exceptional handling done in Python?** There are 3 main keywords i.e. `try`, `except` and `finally` which are used to catch exceptions and handle the recovering mechanism accordingly.

* `Try` -> block of a code that is monitored for errors.
* `Except` -> block gets executed when an error occurs. ⭐
* `Finally` -> block is used to do the required cleanup activities of objects/variables.\`

Note: The beauty of the final block is to execute the code after trying for an error. This block gets executed irrespective of whether an error occurred or not. ⭐

Trying to divide a number by zero will cause an exception.

```python
n = 10
try:
    res = n / 0  # This will raise a ZeroDivisionError
    
except ZeroDivisionError:
    print("Can't be divided by zero!")

```

**Output:**

```
Can't be divided by zero!
```

\####### **22. What is the difference between Python Arrays and Lists?**

1. **Arrays ->** (when talking about the `array` module in Python) Array are specifically used to store a collection of numeric elements that are all of the same type. This makes them more efficient for storing large amounts of data and performing numerical computations where the type consistency is maintained.

* **Syntax:** Need to import the `array` module to use arrays.

```python
from array import array
arr = array('i', [1, 2, 3, 4])  # Array of integers
```

2. **List ->** are more flexible than arrays in that they can hold elements of different types (integers, strings, objects, etc.). They come built-in with Python and do not require importing any additional modules.

* Lists support a variety of operations that can modify the list.

```python
lst = [1, 'hello', 3.14, [1, 2, 3]]
```

\####### **23. What are Modules and Packages in Python?**

1. **Module** -> a single file that contains Python code (functions, variables, classes) which can be reused in other programs. You can think of it as a code library. For example: \*\*`math**` is a built-in module that provides math functions like sqrt(), pi, etc.

```python
import math 
print(math.sqrt(16))
```

2. **Package** -> is a collection of related modules stored in a directory. It helps in organizing and grouping modules together for easier management. For example: The **`numpy`** package contains multiple modules for numerical operations. To create a package, the directory must contain a special file named `**__init__.py`\*\*.

#### 2. Intermediate Python Interview Questions ✅

\####### **24. What is the difference between xrange and range functions?**

`range()` and `xrange()` are two functions that could be used to iterate a certain number of times in for loops in Python.&#x20;

* `**range()**` – This returns a range object, which is an immutable sequence type that generates the numbers on demand.&#x20;
* **`xrange()`** – This function ==returns the generator object== that can be used to display numbers only by looping. The only particular range is displayed on demand and hence called lazy evaluation.

**`range()` in Python 3:**

* Returns a **range object** (like a generator)
* Used to create sequences.
* `range(3)` -> List `[0, 1, 2]`
* Memory Usage -> High (stores list)

```python
for i in range(3):
    print(i)
# Output : 0 1 2 (Same)
```

**`xrange()` (Python 2 only):**

* Returns a **generator-like object**.
* `xrange(3)` -> Generator-like object
* **Not available in Python 3.**
* Memory Usage -> Low (generates on the fly)

```python
# Python 2 only
for i in xrange(3):
    print(i)
# Output : 0 1 2 (Same)
```

Note: In Python 3, there is no `xrange`, but the range function behaves like `xrange`.

**25. What is Dictionary Comprehension? Give an Example**

**Dictionary Comprehension** is a syntax construction to ease the creation of a dictionary based on the existing iterable.

```python
# Lists to represent keys and values
keys = ['a', 'b', 'c', 'd', 'e']
values = [1, 2, 3, 4, 5]

#  Dictionary Comprehension
myDict = {k: v for (k, v) in zip(keys, values)}
print("Using Dict Comprehension:", myDict)

#  Using dict() + zip()
myDict2 = dict(zip(keys, values))
print("Using dict(zip):", myDict2)
```

Output :

```
Using Dict Comprehension: {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}
Using dict(zip): {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}
```

**26. Is Tuple Comprehension possible in Python? If yes, how and if not why?**

\==**Tuple comprehensions** are not directly supported==, Python’s existing features like generator expressions and the `tuple()` function provide flexible alternatives for creating tuples from iterable data.

`(i for i in (1, 2, 3))`

Tuple comprehension is not possible in Python ==because it will end up in a generator==, not a tuple comprehension.

\####### **27. Differentiate between List and Tuple?**

Let’s analyze the [differences between List and Tuple](https://www.geeksforgeeks.org/python-difference-between-list-and-tuple/):

**List**

* Lists are ==Mutable datatype==.
* Lists consume more memory
* The list is ==better for performing operations==, such as insertion and deletion.
* The implication of iterations is Time-consuming

**Tuple**

* Tuples are ==Immutable== datatype.
* Tuple consumes ==less memor==y as compared to the list
* A Tuple data type is ==appropriate for accessing the elements==
* The implication of ==iterations is comparatively Faster==

**28. What is the difference between a shallow copy and a deep copy? ⭐**

Below is the tabular **Difference** between the **Shallow Copy** and **Deep Copy**:

| Shallow Copy                                                                                  | Deep Copy                                                                                        |
| --------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| Shallow Copy ==stores the references of objects== to the original memory address.             | Deep copy ==stores copies of the object’s value==.                                               |
| Shallow Copy reflects changes made to the new/copied object in the original object.           | Deep copy doesn’t reflect changes made to the new/copied object in the original object.          |
| Shallow Copy stores the copy of the original object and points the references to the objects. | Deep copy ==stores the copy of the original object and recursively copies the objects as well==. |
| A shallow copy is ==faster==.                                                                 | Deep copy is comparatively slower.                                                               |

**29. Which sorting technique is used by sort() and sorted() functions of python?**

Python uses the **Tim Sort** ⭐ algorithm for sorting. It’s a stable sorting whose worst case is ==O(N log N)==. It’s a hybrid sorting algorithm, ==derived from **merge sort** and **insertion sort**==, designed to perform well on many kinds of real-world data.

**30. What are Decorators?**

**Decorators** are a powerful and flexible way to ==modify or extend the behavior of functions== or methods, ==without changing their actual code==. **Decorator** is essentially -> A function that takes another function as an argument and returns a new function with enhanced functionality.

Decorators are often used in scenarios such as **logging, authentication and memorization**, allowing us to add additional functionality to existing functions or methods in a clean, reusable way.

**31. How do you debug a Python program? ❓**

**1. Using `pdb` (Python Debugger):**

* `pdb` is a built-in module that allows you to ==set breakpoints and step through the code line by line==. You can start the debugger by adding `import pdb;` and use `pdb.set_trace()` in your code where you want to begin debugging.

```python
import pdb

x = 5
pdb.set_trace()  # 🔍 Debugger starts here
print(x)

```

Output :

```
> main.py(4)<module>()
-> print(x)
(Pdb)
```

* You can now type commands like `n`, `c`, `p x`, etc.

**2. Using logging Module:**

* For more advanced debugging, the logging module provides a flexible way to ==log messages with different severity levels== (INFO, DEBUG, WARNING, ERROR, CRITICAL).

```python
import logging

logging.basicConfig(level=logging.DEBUG)
logging.debug("This is a debug message")
```

Output:

```
DEBUG:root:This is a debug message
```

**32. What are Iterators in Python?**

In Python, **iterators** are used to ==iterate a group of elements==, containers like a list. Iterators are collections of items and they can be a list, tuples, or a dictionary. Python iterator implements `__iter__()` and the `__next__()`⭐ method to iterate the stored elements. We generally use loops to iterate over the collections (list, tuple) in Python.

* `__iter__()` -> returns the iterator object itself
* `__next__()` -> returns the next value and raises `StopIteration` when done

```python
my_list = [1, 2, 3]
it = iter(my_list)
print(next(it))  # 1
```

Note:

* `iter(it)` → Internally calls `it.__iter__()`
* `next(it)` → Internally calls `it.__next__()`

**33. What are Generators in Python? ❓⭐**

In Python, the **generator** is a== way that specifies how to implement iterators. ==It is a normal function except that it yields expression in the function==. It does not implement `__iter__()` and `__next__()` method and reduces other overheads as well.

If a function contains at least a yield statement, it becomes a **generator**. The yield keyword pauses the current execution by saving its states and then resumes from the same when required.

```python
def gen():
    yield 1
    yield 2

g = gen()
print(next(g))  # 1
```

* `yield` saves function state, making it memory efficient.

**38. How is memory management done in Python? ⭐**

Python uses its **private heap space** to manage  the memory. Basically, **all the objects and data structures are stored in** the **private heap space**. Even the programmer can not access this private space as the interpreter takes care of this space.

Python also has an **inbuilt garbage collector**, which recycles all the unused memory and frees the memory and makes it available to the heap space.

**39. How to delete a file using Python?**

We can delete a file using Python by following approaches:

1. Python Delete File using `os.remove`
2. Delete file in Python using the `send2trash module`
3. Python Delete File using `os.rmdir`

**40. What is slicing in Python?**

**Python Slicing** is a `str`, `list`, `tuple` operation for extracting a part of the string, or some part of a list. With this operator, one can specify where to start the slicing, where to end and specify the step. List slicing returns a new list from the existing list.

```python
substring = s[start : end : step]
```

**41. What is a namespace in Python? ⭐**

A **namespace** in Python refers to a **container where names (variables, functions, objects)** are mapped to objects.

**namespace** -> a space where names are defined and stored and it helps ==avoid naming conflicts== by ==ensuring that names are unique within a given scope==.

```
╭------------------------------╮
|      Built-in namespace      |
|  ╭------------------------╮  |
|  |   Global namespace     |  |
|  |  ╭------------------╮  |  |
|  |  | Local namespace  |  |  |
|  |  ╰------------------╯  |  |
|  ╰------------------------╯  |
╰------------------------------╯

	Type of Namespaces
```

**Types of Namespaces**:

1. **Built-in Namespace**: Contains all the built-in functions and exceptions, like `print()`, `int()`, etc. These are available in every Python program.
2. **Enclosing (Global) Namespace**: Contains names from all the objects, functions and variables in the program at the top level.
3. **Local Namespace**: Refers to **names inside a function or method**. Each function call creates a new local namespace.

#### 3. Advanced Python Interview Questions & Answers&#x20;

**42. What is PIP?**

[PIP](https://www.geeksforgeeks.org/python-pip/) is an acronym for Python Installer Package which provides a seamless interface to install various Python modules. It is a command-line tool that can search for packages over the internet and install them without any user interaction.

**43. What is a zip function?**

Python [zip() function](https://www.geeksforgeeks.org/zip-in-python/) returns a zip object, which maps a similar index of multiple containers. It takes an iterable, converts it into an iterator and aggregates the elements based on iterables passed. It returns an iterator of tuples.

> **Syntax:**\
> **zip(\*iterables)**&#x20;

**44. What are Pickling and Unpickling?**

* **Pickling:** The pickle module converts any Python object into a byte stream (not a string representation). This byte stream can then be stored in a file, sent over a network, or saved for later use. The function used for pickling is pickle.dump().
* **Unpickling:** The process of retrieving the original Python object from the byte stream (saved during pickling) is called unpickling. The function used for unpickling is pickle.load().

**45. What is the difference between `@classmethod`, `@staticmethod` and instance methods in Python?**

1. Instance Method operates on an instance of the class and has access to instance attributes and takes self as the first parameter. Example:

> def method(self):

2. Class Method directly operates on the class itself and not on instance, it takes cls as the first parameter and defined with [@classmethod.](https://www.geeksforgeeks.org/classmethod-in-python/)

> **Example:** @classmethod def method(cls):

3. Static Method does not operate on an instance or the class and takes no self or cls as an argument and is defined with [@staticmethod.](https://www.geeksforgeeks.org/python-staticmethod/)

> **Example:** @staticmethod def method(): align it and dont bolod anything and not bullet points

**46. What is `__init__()` in Python and how does `self` play a role in it?**

[**init**() method](https://www.geeksforgeeks.org/__init__-in-python/) in Python is equivalent to constructors in OOP terminology. It is a reserved method in Python classes and is called automatically whenever a new object is instantiated. This method is used to initialize the object’s attributes with values. While **init**() initializes the object, it does not allocate memory. Memory allocation for a new object is handled by the **new**() method, which is called before **init**(). The `self` parameter in `__init__()` refers to the instance of the class being created as it allows access to the instance’s attributes and methods. _`_self_`_ must be explicitly declared as the first parameter in all instance methods, including `__init__()`.

`class MyClass: def __init__(self, value): self.value = value # Initialize object attribute def display(self): print(f"Value: {self.value}") obj = MyClass(10) obj.display()`

**Output**

Value: 10

**47. Write a code to display the current time?**

`import time currenttime= time.localtime(time.time()) print ("Current time is", currenttime)`

**48. What are Access Specifiers in Python?**

Python uses the ‘\_’ symbol to determine the access control for a specific data member or a member function of a class. A Class in Python has three types of [Python access modifiers](https://www.geeksforgeeks.org/access-modifiers-in-python-public-private-and-protected/):

* **Public Access Modifier:** The members of a class that are declared public are easily accessible from any part of the program. All data members and member functions of a class are public by default.&#x20;
* **Protected Access Modifier:** The members of a class that are declared protected are only accessible to a class derived from it. All data members of a class are declared protected by adding a single underscore ‘\_’ symbol before the data members of that class.&#x20;
* **Private Access Modifier:** The members of a class that are declared private are accessible within the class only, the private access modifier is the most secure access modifier. Data members of a class are declared private by adding a double underscore ‘\_\_’ symbol before the data member of that class.&#x20;

**49. What are unit tests in Python?**

[Unit Testing](https://www.geeksforgeeks.org/unit-testing-python-unittest/) is the first level of software testing where the smallest testable parts of the software are tested. This is used to validate that each unit of the software performs as designed. The unit test framework is Python’s xUnit style framework. The White Box Testing method is used for Unit testing.

**50. Python Global Interpreter Lock (GIL)?**

[Python Global Interpreter Lock](https://www.geeksforgeeks.org/what-is-the-python-global-interpreter-lock-gil/) (GIL) is a type of process lock that is used by Python whenever it deals with processes. Generally, Python only uses only one thread to execute the set of written statements. The performance of the single-threaded process and the multi-threaded process will be the same in Python and this is because of GIL in Python. We can not achieve multithreading in Python because we have a global interpreter lock that restricts the threads and works as a single thread.

**51. What are Function Annotations in Python?**

[Function Annotation](https://www.geeksforgeeks.org/function-annotations-python/) is a feature that allows you to add metadata to function parameters and return values. This way you can specify the input type of the function parameters and the return type of the value the function returns.

Function annotations are arbitrary Python expressions that are associated with various parts of functions. These expressions are evaluated at compile time and have no life in Python’s runtime environment. Python does not attach any meaning to these annotations. They take life when interpreted by third-party libraries, for example, mypy.

**52. What are Exception Groups in Python?**

The latest feature of Python 3.11, [Exception Groups](https://www.geeksforgeeks.org/exception-groups-in-python/). The ExceptionGroup can be handled using a new except\* syntax. The \* symbol indicates that multiple exceptions can be handled by each except\* clause.

ExceptionGroup is a collection/group of different kinds of Exception. Without creating Multiple Exceptions we can group together different Exceptions which we can later fetch one by one whenever necessary, the order in which the Exceptions are stored in the Exception Group doesn’t matter while calling them.

try: raise ExceptionGroup('Example ExceptionGroup', ( TypeError('Example TypeError'), ValueError('Example ValueError'), KeyError('Example KeyError'), AttributeError('Example AttributeError') )) except\* TypeError: ... except\* ValueError as e: ... except\* (KeyError, AttributeError) as e: ...

**53. What is Python Switch Statement?**

From version 3.10 upward, Python has implemented a [switch case](https://www.geeksforgeeks.org/switch-case-in-python-replacement/) feature called “structural pattern matching”. You can implement this feature with the match and case keywords. Note that the underscore symbol is what you use to define a default case for the switch statement in Python.

**Note**: Before Python 3.10 Python doesn’t support match Statements.

`match term: case pattern-1: action-1 case pattern-2: action-2 case pattern-3: action-3 case _: action-default`

**54. What is Walrus Operator?**

[Walrus Operator](https://www.geeksforgeeks.org/walrus-operator-in-python-3-8/) allows you to assign a value to a variable within an expression. This can be useful when you need to use a value multiple times in a loop, but don’t want to repeat the calculation.

Walrus Operator is represented by the `:=` syntax and can be used in a variety of contexts including while loops and if statements.

**Note:** Python versions before 3.8 doesn’t support Walrus Operator.

`numbers = [1, 2, 3, 4, 5] while (n := len(numbers)) > 0: print(numbers.pop())`

**Output**

5 4 3 2 1

***

***

## [Python Interview questions (Interviewbits)](https://www.interviewbit.com/python-interview-questions/)

***

***

## [HCL Python Interview questions](https://www.credosystemz.com/hcl-python-interview-questions/)

**1. How is Multithreading achieved in Python?**

* Multithreading in Python is achieved using the ==**`threading`**== module, which allows the execution of multiple threads (lightweight subprocesses) concurrently.
* However, due to Python’s **Global Interpreter Lock (GIL)**, threads do ==not achieve true parallel execution for CPU-bound tasks==. Instead, they are ==best suited for I/O-bound== operations such as network requests, file I/O, and database interactions.
* Python threads will NOT make your program faster if it already uses 100 % CPU time.

Example: Creating and Running Multiple Threads

```python
import threading
import time

def print_numbers():
    for i in range(5):
        time.sleep(1)
        print(f"Number: {i}")

# Creating two threads
t1 = threading.Thread(target=print_numbers)
t2 = threading.Thread(target=print_numbers)

# Starting threads
t1.start()
t2.start()

# Waiting for threads to finish
t1.join()
t2.join()

print("All threads completed.")

```

**Thread Synchronization** : Using a Lock to Prevent Race Conditions

```python
lock = threading.Lock()

def thread_safe_task():
    with lock:  # Ensures only one thread can access the resource at a time
        print("Thread-safe execution")

```

**Limitations of Python Multithreading**

* **Global Interpreter Lock (GIL)** prevents true parallel execution of CPU-bound tasks.
* **Context switching ==overhead** may reduce efficiency==.
* **Not suitable for parallel computation**; use `multiprocessing` for CPU-bound tasks.

**Best Use Cases for Multithreading in Python**

* Web scraping using multiple threads.
* Performing multiple I/O operations simultaneously.
* Running background tasks in GUI applications.

Note: ==For CPU-bound tasks, consider using the **`multiprocessing`** ==module instead, which creates separate processes rather than threads. ⭐

**8. What are the two major loop statements?**

There are **two major loop statements** in Python:

1.  **`for` loop**:

    * Used to ==iterate over a sequence== (like a list, tuple, dictionary, string, or range)
    * Commonly used when the number of iterations is known beforehand.

    ```python
    for i in range(5):
        print(i)  # Prints numbers from 0 to 4
    ```
2.  **`while` loop**:

    * Repeats as long as a condition is `True`.
    * Used when the number of iterations is not known in advance.

    ```python
    i = 0
    while i < 5:
        print(i)  # Prints numbers from 0 to 4
        i += 1
    ```

**9. What are the built-in types available in Python?**

Python provides a variety of **built-in types** for data manipulation:

1. **Numeric Types**:
   * **`int`**: Integer numbers (e.g., 5, -3).
   * **`float`**: Floating-point numbers (e.g., 3.14, -2.0).
   * **`complex`**: Complex numbers (e.g., 2 + 3j).
2. **Boolean Type**:
   * **`bool`**: Represents `True` or `False`.
3. **Sequence Types**:
   * **`str`**: String type , Immutable(e.g., `"Hello"`).
   * **`list`**: Ordered, mutable collection (e.g., `[1, 2, 3]`).
   * **`tuple`**: Ordered, immutable collection (e.g., `(1, 2, 3)`).
4. **Set Types**:
   * **`set`**: Unordered collection with unique elements (e.g., `{1, 2, 3}`).
   * **`frozenset`**: Immutable version of a set.
5. **Mapping Type**:
   * **`dict`**: Key-value pairs (e.g., `{"key": "value"}`).
6. **Binary Types**:
   * **`bytes`**: Immutable sequence of bytes (e.g., `b'hello'`).
   * **`bytearray`**: Mutable sequence of bytes.
   * **`memoryview`**: Memory view objects.

**10. How to Invoke the Python Interpreter for Interactive Use?**

To start the Python interpreter for interactive use, you can follow these steps:

**On Windows**:

1.  **Command Prompt**:

    * Open **Command Prompt** (type `cmd` in the search bar).
    * Type `py` or `python` and press **Enter**.
    * This starts the Python interpreter in interactive mode, allowing you to enter Python commands directly.

    ```bash
    C:\> python
    >>>  # Python interactive prompt
    ```
2. **IDLE**:
   * Open **IDLE** (Python's Integrated Development and Learning Environment).
   * Type `IDLE` in the search bar and select it from the app menu.
   * IDLE provides a GUI interface with an interactive Python shell for running Python code and editing files.

This allows you to directly execute Python code in a REPL (Read-Eval-Print Loop) environment.

**What is REPL?**

1. **Read**: Reads the user input (Python code).
2. **Evaluate**: Executes the inputted code.
3. **Print**: Displays the output of the execution.
4. **Loop**: Repeats the process, allowing continuous interaction.

```cpp
/*
**11. Which scientific libraries in SciPy have you worked with in your project?**

The SciPy library is one of the core packages that make up the SciPy stack. It provides many user-friendly and efficient numerical routines, such as routines for numerical integration, interpolation, optimization, linear algebra, and statistics.
*/
```

**14. Define slicing in Python?**

* Slicing is the extraction of a part of a **string, list, or tuple**.
* It enables users to ==access the specific range of elements== by mentioning their indices. Slicing is used to extract a portion of a **string, list, or tuple** using index ranges.

`sequence[start:stop:step]`

* **start** → Starting index (inclusive)
* **stop** → Ending index (exclusive)
* **step** → Skip count (optional)

```python
s = "Python"
print(s[1:4])   # "yth" (Indexes 1 to 3)
print(s[:3])    # "Pyt" (Start from index 0)
print(s[2:])    # "thon" (Till end)
print(s[::-1])  # "nohtyP" (Reversed)
```

Note: The search will start at index one (included) and ends at index six (not included).

**15. How can Python be an interpreted language? ⭐**

Python is called **interpreted** because it ==executes code **line by line** using an **interpreter**== instead of compiling the entire code at once.

**Key Differences:**

* **Interpreter** (Python) → Executes code **one-by-one**, making debugging easier.
* **Compiler** (C, C++) → Translates entire code before execution, making it faster.

**Example:**

* If there's an ==error in **line 50**, Python will execute **lines 1-49** successfully before stopping==, unlike compiled languages that show all errors at once.

This makes Python **more flexible and easier to debug**, but generally slower than compiled languages.

**16. Define package in Python? ⭐**

* A **package** is a ==**collection of modules** stored in a directory== containing a special `__init__.py` ⭐ file. It helps organize code and allows for easy reuse.
* It allows for easier portability with all the application dependencies in a single folder.

A package structure:

```sh
mypackage/
│── __init__.py  (Defines the package)
│── module1.py  
│── module2.py  
```

You can **import** modules using:

```python
from mypackage import module1
```

real-world examples using popular Python packages:

```python
#NumPy (Numerical Computing)
from numpy import random

# Pandas (Data Analysis)
from pandas import DataFrame

# Matplotlib (Data Visualization)
from sklearn.linear_model import LinearRegression ⭐

# Seaborn (Statistical Data Visualization)
from matplotlib import pyplot as plt
```

\`

Note: Packages make large projects **well-structured and scalable**.

**17. Which command is used to delete files in Python?**

To delete a file in Python, use the **`os`** or **`pathlib`** module:

**Using `os` module:** ⭐

```python
import os
os.remove("file.txt")  # Deletes 'file.txt'
```

**Using `pathlib` module (Python 3.4+):**

```python
from pathlib import Path
Path("file.txt").unlink()  # Deletes 'file.txt'
```

For **directories**, use:

* `os.rmdir("dir_name")` → Removes **empty** directory
* `shutil.rmtree("dir_name")` → Removes **non-empty** directory

**18. Define pickling and unpickling in Python? ⭐**

\==Pickling is **converting a Python object into a byte stream**==, while **unpickling** is the reverse—**converting the byte stream back into a Python object**. This is useful for saving and loading objects.

**Pickling (Saving an object)**

```python
import pickle
data = {"name": "Alice", "age": 25}
with open("data.pkl", "wb") as f:
    pickle.dump(data, f)  # Convert and save (not return anything)
```

Data saved in `data.pkl`

```
\x80\x04\x95\x11\x00\x00\x00\x00\x00\x00\x00}\x94(\x8c\x04name\x94\x8c\x05Alice\x94\x8c\x03age\x94K\x19u.
```

**Unpickling (Loading an object)**

```python
with open("data.pkl", "rb") as f:
    loaded_data = pickle.load(f)  # Load and convert back (# Returns the original dictionary)
```

* **Use Cases:** Storing **ML models**, **caching**, **saving game states**, etc.
* `pickle.dump` : pickle
* `pickle.load` : unpickle

**19. How does a function return values?**

* A function **returns values** using the `return` statement.
* Once `return` is executed, the function **ends** and passes the result to the caller.
* The statements after the return statements are not executed.

**Key Points:**

* Can return **single or multiple** values (`return x, y`).
* **Stops execution** after `return`.
* If no `return`, function returns **None** by default.

**20. What is a boolean in Python?**

* A **boolean** (`bool`) is one of the built-in data types provided by Python tp represents **True or False** values.
* It is used in conditions, comparisons, and logical operations.
* Python boolean type , which are defined by the True or False keywords.
* Generally, it is used to represent the truth values of the expressions.
* The output indicates the variable is a boolean data type.

**21. What is&#x20;**_**init**_**? ⭐**

* `__init__` is the ==**constructor** method== in Python classes.
* It is **automatically Executes** when an object is created to initialize attributes.
* It is used to **initialize** object attributes.

**Example:**

```python
class Person:
    def __init__(self, name, age):  # Constructor
        self.name = name
        self.age = age

p1 = Person("Alice", 25)  # Calls __init__
print(p1.name, p1.age)  # Output: Alice 25
```

**22. How to remove values from a Python array?**

**Different Methods to Remove value:** ⭐

1.  **`remove(value)`** → Removes the first occurrence of the given value.

    ```python
    arr = [1, 2, 3, 4, 2]
    arr.remove(2)  # Removes first 2
    print(arr)  # [1, 3, 4, 2]
    ```
2.  **`pop(index)`** → Removes and returns the item at the given index.

    ```python
    arr = [10, 20, 30, 40]
    arr.pop(2)  # Removes element at index 2 (30)
    print(arr)  # [10, 20, 40]
    ```
3.  **`del` statement** → Deletes an item or slice from a list.

    ```python
    arr = [5, 6, 7, 8]
    del arr[1]  # Removes element at index 1
    print(arr)  # [5, 7, 8]
    ```
4.  **List Comprehension** → Removes all occurrences of a value. ⭐

    ```python
    arr = [1, 2, 3, 2, 4]
    arr = [x for x in arr if x != 2]  # Removes all 2s
    print(arr)  # [1, 3, 4]
    ```

**23. Write a program in Python to produce Star triangle?**

**Python program to produce triangle pattern:**

```python
def triangle(n):
    k = n - 1  # Number of spaces before the first star

    for i in range(n):  # Outer loop for rows
        print(" " * k, end="")  # Print spaces
        print("* " * (i + 1))  # Print stars with spaces
        k -= 1  # Reduce spaces in each row

# Driver Code
n = 5
triangle(n)
```

```
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
```

***

***

## [Python Interview Questions and Answers (based on Experience)](https://www.credosystemz.com/python-interview-questions-answers/)

***

***

## [## **HCL Interview Questions for Freshers in Python**](https://entri.app/blog/hcl-python-interview-questions-for-freshers/) ✅

**Q1. Discuss what type of language is Python?**

* Python is an object-oriented, interpreted, interactive programming language. There are dynamic typing, classes, modules, exceptions, and very high-level dynamic data types.
* Python has dynamic typing and is an interpreted language. These languages are frequently called “scripting” languages because the code is not transformed into a binary format. When I say dynamically typed, I mean that types are discovered at runtime by the interpreter, negating the need for them to be declared while code.
* Python’s compact, learnable syntax prioritises readability, which reduces the cost of software maintenance.
* Python offers packages and modules that facilitate code reuse and programme modularity. You can download and share the Python interpreter and its extensive standard library in source or binary form for free on all major platforms.

**Q2. Define PEP 8?**

A document called PEP 8 (often referred to as PEP8 or PEP-8) describes best practices and guidelines for creating Python code. Guido van Rossum, Barry Warsaw, and Nick Coghlan wrote it in 2001. PEP 8’s primary objective is to improve the readability and consistency of Python code.

The term Python Enhancement Proposal (PEP) refers to the type of proposal that is available in a spreadsheet format. A document known as a Python Enhancement Proposal (PEP) describes new features that have been proposed for Python and provides community-facing details about aspects of the language including style and design.

**Q3. What do you meant by namespace in Python?**

A namespace in Python is a system that gives every item in the system a special name. One may think of a method or a variable as an object. A Python dictionary serves as the storage for Python’s unique namespace. As an example, let’s examine the directory-file system architecture of a computer. It should go without saying that different folders may contain files with the same name. On the other hand, if one wishes, they can be directed to the file by providing its absolute path.

**Q4. What is PYTHON PATH?**

With the use of the environment variable PYTHONPATH, users can expand the list of directories in Python’s sys.path directory. It is, in essence, an environment variable that is initialised prior to the Python interpreter starting.

**Q5. What are the Python modules?**

A single file containing definitions and commands for Python is called a module. You can define variables, classes, and functions in a module. Executable code can also be a part of a module. Code that is arranged into modules is simpler to use and comprehend. It also arranges the code logically.

**Q6. What are local variables and global variables in Python?**

Global variables are defined outside of any function and have a global scope, while local variables are declared inside a function and have a scope that is limited to that function alone. Stated differently, global variables are accessible across the programme and in every function, while local variables are only available within the function in which they were generated.

**Local Variables** : Variables defined inside a function that are exclusive to that function are referred to as local variables. It cannot be accessed outside of the function.

**Global Variables** : Global variables are those that are available throughout the programme, that is, both inside and outside of each function, and that are defined independently of any particular function.

**Q7. Define Flask and its benefits?**

An open-source web framework is called Flask.A collection of technologies, frameworks, and tools called Flask is used to create web applications. This online app is built on a web page, wiki, large web-based calendar programme, or a for-profit website. Since Flask is a micro-framework, it doesn’t rely much on external libraries.

**Benefits:** Flask is an excellent web application framework for a number of reasons. Such as

* Support for unit testing that is integrated
* Both a quick debugger and an integrated development server are included.
* Dispatching peaceful requests using a Unicode foundation
* It is okay to utilise cookies.
* WSGI 1.0 compliant jinja2 templating
* The flask also allows you total control over how your project develops.
* Function for parsing HTTP requests
* With a few additions, Flask is a simple and adaptable web framework that is easy to integrate.
* To connect, you can use your preferred device. ORM Basic’s primary API is logically laid out and well-designed.
* Incredibly flexible
* The flask is simple to utilise during the manufacturing process.

**Q8. Which is better Django or Flask?**

Django is more popular because it has plenty of functionality out of the box, making complicated applications easier to build. Django is best suited for larger projects with a lot of features. The features may be overkill for lesser applications.

If you’re new to web programming, Flask is a fantastic place to start. Many websites are built with Flask and receive a lot of traffic, although not as much as Django-based websites. If you want precise control, you should use flask, whereas a Django developer relies on a large community to produce unique websites.

**Q9. What is Django architecture**

Three components make up Django’s Model-View-Controller (MVC) architecture:

**1. Model** : The conceptual data structure that supports the entire programme is called the Model, and it is represented by a database (usually relational databases like MySql, Postgres).

**2. View** : The user interface, or View, is what you see when you use your browser to view a website. The files that represent them are HTML, CSS, and Javascript files.

**3. Controller** : Data must be sent from the model to the view by the Controller, which serves as a bridge between the two.

**Q10. What is Scope in Python?**

Consider scope to be the father of a family; everything has a scope. This is a block of code that, regardless of how many objects are declared, remains relevant, according to a formal definition. Here are a few instances of similar situations:

* **Local Scope:** A variable that is created inside a function and is only used inside that function is considered to be part of the function’s local scope.

```python
def harshit_fun():
b = 200
print (b)
harshit_func()
200
```

* **Global Scope:** A variable is said to be in the global scope when it is created within the main body of Python code. The best thing about global scope is that it may be accessed from any location in the Python code, whether it is local or global.

```python
b = 200
def harshit_func():
print (b)
harshit_func()
print (b)
```

* **Nested Function:** Also called a function inside a function, this is illustrated in the preceding example where the variable y is only accessible inside the function and not outside of it.

```python
def first_func():
b = 100
def nested_func1():
print(b)
nested_func1()
first_func()
```

* Module Level Scope: This basically describes the global objects that are now accessible within the programme for the module in question.
* The word “outermost scope” refers to all of the program’s built-in names that you can call.

**Q11. List the common built-in data types in Python?**

The most popular built-in datatypes are listed below:

* **Numbers:** Comprised of complex, floating-point, and integer numbers.
* **List:** As we’ve already covered a little bit about lists, a list is defined as an ordered, modifiable sequence of elements, the elements of which can be of multiple data kinds.

```python
list = [200, “Entri App”, 50]
```

**Tuples:** Similar to lists, this is also an ordered series of elements, however unlike lists, tuples are unchangeable once stated.

```tuple
tup_2 = (100, “ Entri App ”, 20) 
```

**String:** The string of characters stated inside single or double quotations is known as this.

```python
“Hi, Entri App is a Learning Platform”
‘Hi, Entri App is a Learning Platform’
```

**Sets:** In essence, sets are collections of distinct objects with a non-uniform order.

```python
set = {2,3,4}
```

**Dictionary:** Values are always kept in dictionaries as key-value pairs, where a key can be used to access each value.

```python
[10] harshit = {1:’sports’, 2:’video_games’, 3:’contents’} 
```

**Boolean:** True and False are the only two possible boolean values.

**Q12. What are global, protected, and private attributes in Python?**

Variables are another name for a class’s characteristics. In Python, there are three types of access modifiers for variables:

**a. Public:** Public variables can be accessed from anywhere, both within and outside of the classroom.

**b. private:** Variables designated as private can only be accessed by members of the current class.

**c. protected:** Only the variables included in the current package can access variables designated as protected.

Moreover, attributes are categorised as:

* Local attributes can only be accessed within the code-block or method in which they are defined.
* Global attributes can be accessed from anywhere and are defined outside of the code-block or procedure.

```python
class Mobile:
    a1 = "Android Mobiles" //Global attributes
    def price(self):
        a2 = "mobiles"   //Local attributes
        return m2
Android_a = Mobile()
print(Android_a.a1)
```

**Q15. What is classifier?**

A classifier is used to predict the class of any data point. Classifiers are special hypotheses that are used to assign class labels to any particular data point. A classifier often uses training data to understand the relation between input variables and the class. Classification is a method used in supervised learning in Machine Learning.

**Q16. How can one obtain a dictionary’s whole list of keys?**

The following is one method we can use to obtain a list of `keys: dict.keys()`

* Every key that is available in the dictionary is returned by this method.

```
dict = {1:x, 2:y, 3:z} dict.keys()
```

Output:

```
[1, 2, 3]
```

**Q17. How do you capitalise a string’s initial letter?**

To `capitalise` a string’s first character, use the `capitalise()` function.

* The original - string is returned if the first character is already `capitalised`.
* `string_name.capitalize()`

```python
a = “Entri App” 
print(a.capitalize())
```

**Q18. In Python, how may an element be inserted at a specific index?**

The `insert()` function is a built-in Python function.

* An element can be inserted using it at a specified index.
* `list_name.insert(index, element)`

```python
list = [ 0,1, 2, 3, 4, 5, 6, 7 ]
#insert 12 at 5th index
list.insert(5, 12)
```

Output:

```
[0,1,2,3,4,12,5,6,7]
```

**Q19. How can duplicate items be eliminated from a list?**

Duplicate elements in a list can be eliminated in a number of ways. However, the most popular one is to use the set() function to turn a list into a set, and the list() function to return the set to a list as needed.

```python
list1 = [1, 2, 2, 3, 4, 5, 6, 3]
list2 = list(set(list1)) 
print (“The list without duplicates : ” + str(list2))
```

**Q20. What is recursion?**

A function that calls itself once or more times within its body is called recursive. One crucial requirement for using a recursive function in a programme is that it must end; otherwise, an infinite loop issue might arise.

**Q21. Describe List Comprehension in Python.**

One list can be changed into another list using list comprehensions. The new list can contain elements conditionally, and each entry can be changed as necessary. It is made up of an expression surrounded in brackets that goes to a for clause.

```python
list = [a for a in range(100)]
print list
```

[**Experience**](https://entri.app/course/full-stack-developer-course/?utm_source=python-programming\&utm_medium=blog_referral\&utm_campaign=hcl-python-interview-questions-for-freshers)

***

***

## Interview Questions on GLASDOOR

Interview

Gave two coding questions from Leetcode, 2sum and longest substring without repeating characters iirc. Then asked some questions about my experience and resume like projects. Also talked about the role and duties that would be assigned

Tell us about a project you are currently working on. What are some challenges you overcame while working on it?

What is decoratord and implement it ⭐

Q. my\_list = \[\[35, 66, 31], \["python", 13, "is"], \[15, "fun", 14]] OUTPUT REQUIRED: To print the string from the list as : python is fun

Q. \[4,5,6,7,2,3,11,13] Sort the element in a such a way that have even should come first and odd numbers at last

&#x20;difference between mutable and immutable data structures

What is lamda equation there in python⭐

2 Use of **name** == "**main**": 3 What is unicode? Types of strings 4 What is property? How we can implement that?

1 Least Common Ancestor 2 BFS Traversal 3 Reducing a string so that no adjacent duplicates should be together For eg : "aaba" output will be "ba"

Second Round: 1 Initial discussions on above questions 2 DFS Traversal 3 String aabbccaaa to be printed like "a2b2c2a3" i.e. length to be appended of a variable 4 BFS Traversal : print elements level wise For eg: 2 1 4 3 5 Third Round: Create binary search tree , pass Linked link and using bst return sorted list . can be done using inorder traversal Questions were mostly from Data Structures and mainly from Trees

2 rounds: Technical - asked some theretical questions on python. Then gave 2 logical questions to solve. 1 find all possible permutations, combinations of a given list 2 reverse a given string without changing order non alpha-numeric characters HR - discussion about package
