

# [Python Comprehensions | Python Tutorials For Absolute Beginners In Hindi (Old Harry #73)](https://youtu.be/D2h_qI6Tx4M)

### **Comprehensions in Python**

Comprehensions provide a **concise way to create lists, dictionaries, and sets** in Python. They make code **more readable and efficient** by **replacing loops** with a single-line expression.

**Advantages of Comprehensions:**
- More readable and concise than loops.  
- Faster execution compared to standard loops.  
- Reduces the need for multiple lines of code.

**Type of List Comprehensions: ** ⭐
1. List Comprehensions -> Using `[]`
2. Dictionary Comprehensions -> Using`{}` with key : value pair
3. Set Comprehensions -> Using `{}`
4. Generator Comprehensions -> Using `()`

**Example:** Write a Code to List Numbers divisible by 3 from 1 to 100
```python
ls = []
for i in range(100):
	if i%3==0:
		ls.append(i)

print(ls) # [3, 6, 9, 12, 15, ....]
```

We can Create same list more efficiently using List Comprehensions
#### **1. List Comprehension**

Used to create lists using a compact syntax.
```python
[expression for item in iterable if condition]
```

1. **Example:** Write a Code to List Numbers divisible by 3 from 1 to 100
```python
ls = [i for i in range(100) if i%3==0]
print(ls) # [3, 6, 9, 12, 15, ....99]

print(type(ls)) # <class 'list'>
```
#### **2. Dictionary Comprehension**

Used to create dictionaries in a single line.
```python
{key_expression: value_expression for item in iterable if condition}
```

1. **Example:** Create dictionary with **key : value** pairs like `0:item0`, `1: item1` and up to 100
```python
dict1 = {i: f"item{i}" for i in range (1,100)}

print(dict1) # [1: item1, 2:item2, 3: item3, ...., 99:item99]

print(type(dict1)) # <class 'dict'>
```

2. **Example:** Create the same **key : value**  1000 which are divisible by 100
```python
dict1 = {i: f"item{i}" for i in range (1,100) if i%100=0}

print(dict1) # [100: item100, 200:item200, 300: item300, ...., 900:item900]
```

3. **Example:** Create the same **key : value** from existing Dictionary by swapping there **Key** and **value** ⭐
```python
dict2 = {value: key for key,value in dict1.items()}

print(dict2) # [item100:100, item200:200, item300:300, ...., item900:900]
```

#### **3. Set Comprehension**

Used to create sets with unique elements.
```python
{expression for item in iterable if condition}
```

1. **Example:** Create Set from a list i.e. Remove duplicate Tuples
```python
dresses = {dress for dress in ["dress1", "dress2", "dress1"]}

print(dresses) # {'dress1', 'dress2'}

print(type(dresses)) # <class 'set'>
```
- Make sure using `{}` not `[]` to create set

---
### **4. Generator Comprehension**

- A **generator** is an iterator that generates values **lazily**, meaning it does not store all values in memory but generates them **on demand**.
- A generator comprehension is similar to list comprehension but uses **parentheses `()` instead of square brackets `[]`**.

**Key Points:**
- **Generators are special iterators** that can be iterated **only once**.
- **Values are generated lazily**, saving memory.

```python
(expression for item in iterable if condition)
```

1. **Example**
```python
evens = (i for i in range(100) if i%2==0)

print(evens) # generator object <genexpr> at 0x03785330>

print(evens) # 0

print(type(even)) # <class 'generator'>
```

- Use `next(generator)` or `generator.__next__()` to get the next value.
- **Once exhausted, a generator cannot be restarted**, you need to create a new one.
```python
print(evens.__next__()) # 2
print(evens.__next__()) # 4
print(evens.__next__()) # 6
print(evens.__next__()) # 8
```


---
# [Exception Handling in Python | Python Tutorial - Day #36](https://youtu.be/4LKo6dlku7M)

- Our program **halts** when an **unhandled error occurs**.
- We use **exception handling** to prevent the program from crashing, allowing it to continue running by handling the error and executing an alternative action.

### Exception Handling

Exception handling is the process of responding to unwanted or unexpected events when a computer program runs. Exception handling deals with these events to avoid the program or system crashing, and without this process, exceptions would disrupt the normal operation of a program.

### Exceptions in Python

Python has many built-in exceptions that are raised when your program encounters an error (something in the program goes wrong).

When these exceptions occur, the Python interpreter stops the current process and passes it to the calling process until it is handled. If not handled, the program will crash.

### Python try...except

try….. except blocks are used in python to handle errors and exceptions. The code in try block runs when there is no error. If the try block catches the error, then the except block is executed.

**Syntax:**
```python
try:
     #statements which could generate 
     #exception
except:
     #Soloution of generated exception
```

### Learn from Example:

**1. Program to Print Multiplication Table of a number**
```Python
# Print table of a Number a
a = input("Enter the number:")
print(f"Multiplication table of {a} is:")

for i in range(1, 11):
	print(f"{int(a)}X{i}={int(a*i)}")
```
Output (Input is valid `integer` ) -> Correct Table
```
Enter the number : 8
8 x 1 = 8
8 x 2 = 16
8 x 3 = 24
8 x 4 = 32
8 x 5 = 40
8 x 6 = 48
8 x 7 = 56
8 x 8 = 64
8 x 9 = 72
8 x 10 = 80
```
Output (If Input not a valid `Int`) -> ❌ Error
```cd
Enter the number : Gaurav

Traceback (most recent call last):
	File "main.py", line 5, in <module>
	print("f{int(a)}X{i} = {int(a)*i}")
ValueError: Invalid litereal for int() with base 10: 'Gaurav'
```

**2. Program to Print Multiplication Table of a no. `a` + ( Handle Any Exception by Printing the Error )
```Python
a = input("Enter the number:")
print(f"Multiplication table of {a} is:")

# Try... Except
try:
	for i in range(1, 11):
		print(f"{int(a)}X{i}={int(a*i)}")

# Handle Any tipe of Error/Exception by printing error
except Exception as e:
	print(e)
```
Output (If Input not a valid `Int`) -> Handled Error ✅
```
Enter the number : Gaurav
Invalid literal for int() with base 10: 'harry'
```

**3. Program to Print Multiplication Table of a no. `a` + ( Handle Any Exception by Printing Custom Message )
```Python
a = input("Enter the number:")
print(f"Multiplication table of {a} is:")

# Try... Except
try:
	for i in range(1, 11):
		print(f"{int(a)}X{i}={int(a*i)}")

# Handle Any type of Error/Exception by print a message 
except:
	print("Invalid Input")
```
Output (If Input not a valid `Int`) -> Handled Error ✅
```
Enter the number : Gaurav
Invalid Input
```

**4. Program to Print Value of element in list at Given Index `a` + ( Handle `ValueError` and `TypeError` Exception by Printing Custom Message )
```Python
# Try... Except
try:
	num = int(input("Enter an Integer:"))
	a = [6, 3]
	print(a[num])

# Handle ValueError by print a message 
except ValueError:
	print("Number Error is not an Integer")

# Handle IndexError by print a message 
except ValueError:
	print("Number Error is not an Integer")
```

Output (If Input Index not a valid) -> Handled Error ✅
```
Enter an Integer : 1.5
Number entered is not an integer
```

Output (If Input Index is not a valid) -> Handled Error ✅
```
Enter an Integer : 15
Index Error
```

---
# [# Finally keyword in Python | Python Tutorial - Day #37](https://youtu.be/r_iuC-IDpPM)

# Finally Clause

The finally code block is also a part of exception handling. When we handle exception using the try and except block, we can include a finally block at the end. The finally block is always executed, so it is generally used for doing the concluding tasks like closing file resources or closing database connection or may be ending the program execution with a delightful message.

**Syntax:**
```python
try:
   #statements which could generate 
   #exception
except:
   #solution of generated exception
finally:
    #block of code which is going to 
    #execute in any situation
```

The finally block is executed irrespective of the outcome of try……except…..else blocks  
One of the important use cases of finally block is in a function which returns a value.

### Learn from Example:

```python
try:
	l = [1, 5, 6, 7]
	i = int(input("Enter the index: "))
	print(l[i])
except:
	print("Some error occured")

finally:
	print("I am always executed")
```
Output: If valid Input given : Try -> Finally
```
Enter the index : 1
5
I am always executed
```
Output: If Invalid input given: Except -> Finally
```
Enter the index : Gaurav
5
I am always executed
```

**Important Interview Question ⭐**

**Ques:** Why do we need `finally`? We can write the statement outside `try-except`, and it will always execute anyway.

✅ **Answer:** The `finally` block plays an important role **inside functions**. Even if `try` or `except` contains a `return` statement, the code inside the `finally` block will still execute before the function exits.
Whereas, a normal statement outside `try-except` **won't execute** if a `return` occurs inside the function, but `finally` ensures execution in such cases.

**Example: **

```python
# Function definition
def func():
	try:
		l = [1, 5, 6, 7]
		i = int(input("Enter the index: "))
		print(l[i])
	except:
		print("Some error occured")
	
	finally:
		print("I am always executed")
	
	print("This is a Normal Statement")

# Call and print function value print(func1())
x = func1()
print(x)
```
Output: If valid Input given : Try -> Finally
```
Enter the index : 1
5
I am always executed
```
Output: If Invalid input given: Except -> Finally
```
Enter the index : Gaurav
5
I am always executed
```
Note : the statement `print("Tis is a Normal Statement")` is not executed after return

Your note is mostly correct, but I’ve refined the wording for clarity and correctness. Here’s the improved version:

##### **Real-World Use Case of `finally`**

1. If you have a **database connection** and an error occurs, you may need to **close** or **rollback** the connection to prevent issues.
2. If you are **working with files**, you should always **close the file** after reading/writing, regardless of whether an error occurs.

Writing these cleanup statements inside the `finally` block ensures they **execute no matter what**, even if the function returns early due to an error.
    
**Example 1: Closing a File Properly**
```python
try:
    f = open("data.txt", "r")
    content = f.read()
    print(content)
except FileNotFoundError:
    print("File not found!")
finally:
    f.close()  # Ensures the file is always closed
    print("File closed successfully.")
```

**Example 2: Closing a Database Connection**
```python
import sqlite3

try:
    conn = sqlite3.connect("example.db")
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM users")
    data = cursor.fetchall()
    print(data)
except Exception as e:
    print("Database error:", e)
finally:
    conn.close()  # Ensures the connection is closed
    print("Database connection closed.")
```

✅ **Conclusion:** The `finally` block is crucial for **resource cleanup**, ensuring that files, database connections, or other system resources are properly closed or released, **regardless of errors or returns in the code.**

---
# [File IO in Python | Python Tutorial - Day #49](https://youtu.be/eDBPlcWYses)

Python provides several ways to manipulate files. Today, we will discuss how to handle files in Python.

#### **Opening a File** `open()`

Before performing any operations on a file, you must **open** it using the `open()` function.

**Syntax:**
```python
f = open('filename', 'mode')
```
- `filename`: Name of the file (with extension).
- `mode`: Specifies how the file will be opened.
    

 **Default Mode:**
```python
f = open('myfile.txt')   # Opens in read mode by default ('r')
```
- Returns a **file object** (`_io.TextIOWrapper`) representing the file stream.

```python
print(f)  
# Output: <_io.TextIOWrapper name='myfile.txt' mode='r' encoding='UTF-8'>
```
- If the file **does not exist** in `r` mode → `FileNotFoundError` ❌

#### **Closing a File** `close()`

- Always **close** a file after use to free up system resources.    
- Use the `close()` method:

```python
f = open('myfile.txt', 'r')
# Perform operations
f.close()
```

Note: Make sure to always Close the File To ensure changes are saved, always close the file after writing.

**Alternatively, Using `with` Statement to automatically closes the file after the block execution.:**
```python
with open('myfile.txt', 'r') as f:
    content = f.read()    # Automatically closes after block execution
```

#### **File Opening Modes**

|**Mode**|**Description**|
|---|---|
|`r`|Read mode (default). Error if file doesn't exist.|
|`w`|Write mode. Creates file if it doesn't exist, overwrites if it does.|
|`a`|Append mode. Creates file if it doesn't exist, adds content at the end.|
|`x`|Create mode. Fails if the file already exists.|
|`t`|Text mode (default). Reads/writes text files.|
|`b`|Binary mode. Used for binary files (images, PDFs, etc.).|

**Text vs Binary mode**
```python
# Text mode (default)
open('myfile.txt', 'rt')   # Same as 'r'
# Binary mode
open('myfile.txt', 'rb')
```


#### **Reading from a File**

Once a file is opened, you can use various methods to **read** from it.

`myfile.txt` content:
```
My name is Gaurav!
```

**1. `read()` – Reads entire content**
```python
f = open('myfile.txt', 'r')
content = f.read()
print(content)
f.close()
```
Output:
```
My name is Gaurav!
```

**2. `readline()` – Reads one line at a time**
```python
f = open('myfile.txt', 'r')
line = f.readline()
print(line)
f.close()
```

**3. `readlines()` – Reads all lines into a list**
```python
f = open('myfile.txt', 'r')
lines = f.readlines()
print(lines)
f.close()
```
Output:
```python
['Line 1\n', 'Line 2\n', 'Line 3']
```

#### **Write Mode (`w`)**

- **Overwrites** existing content or creates a new file if it doesn't exist.
```python
f = open('myfile.txt', 'w')
f.write('Hello, world!')
f.close()
```

#### **Append Mode (`a`)**

- **Adds** content at the end of the file.
```python
f = open('myfile.txt', 'a')
f.write('\nAppended text!')
f.close()
```

### **Create Mode (`x`)**

- Creates a new file.
- Raises `FileExistsError` if the file already exists.
- It is Used for File Creation with Error Handling
```python
f = open('newfile.txt', 'x')
f.write('This is a new file!')
f.close()
```

**Alternately, To Create File with Error Handling You can Check Path if it exists**
```python
import os

if os.path.exists('myfile.txt'):
    f = open('myfile.txt', 'r')
    print(f.read())
    f.close()
else:
    print('File does not exist.')
```


---

# [read(), readlines() and other methods | Python Tutorial - Day #50](https://youtu.be/l1FsnQxET9U)

Multiline Operations

- `readline()` → When you want to read the file **line by line**.
- `readlines()` → When you want to read the entire file into a **list**.
- `writelines()` → When you want to write **multiple lines** at once.
#### **1. `readline()` → Reading line by line**

##### Use case Example 1:

`myfile.txt`
```
Hello world!
This world is Great!
And you are also great!
```

```python
f = open('myfile.txt', 'r')

while True:
	line = f.readline()
	print(line)
	if not line:
		print(line, type(line))
		break
```
Output:
``` 
Hello world!

This world is Great!

And you are also great!
```

Better Version
```python
f = open('myfile.txt', 'r')

while True:
    line = f.readline()
    if not line:   # Stop when EOF is reached
        break
    print(line, end='')   # end='' avoids double newlines

f.close()
```
Output:
```
Hello world!  
This world is Great!  
And you are also great!  
```
##### Use case Example 2:
Each line → Student's marks in **Math, English, SST**

`myfile.txt`
```
56,45,67 
12,34,63
13,64,23
```

```python
f = open('myfile.txt', 'r')

while True:
	i = i+1
	line = f.readline()
	if not line:
		break
	m1 = line.split(",")[0]
	m2 = line.split(",")[1]
	m3 = line.split(",")[2]
	# Inside `{}` in a string, we can use variable and write logic
	print(line)
	print(f"Marks of student{i}: {m1}")
	print(f"Marks of student{i}: {m2}")
	print(f"Marks of student{i}: {m3}")

f.close
```
Output:
```
56,45,67
Marks of student 1 in Maths is: 56
Marks of student 1 in English is: 45
Marks of student 1 in SST is: 67

12,34,63
Marks of student 2 in Maths is: 12
Marks of student 2 in English is: 34
Marks of student 2 in SST is: 63

13,64,23
Marks of student 3 in Maths is: 13
Marks of student 3 in English is: 64
Marks of student 3 in SST is: 23

```

#### **2. `readlines()` → Reading all lines into a list**

```python
f = open('myfile.txt', 'r')

lines = f.readlines()  # Reads all lines into a list
for line in lines:
    print(line.strip())  # Remove newline while printing

f.close()
```
Output:
```
56,45,67  
12,34,63  
13,64,23  
```
#### **3. `writelines()` → Writing multiple lines at once**

##### Use case Example 1

-  **1. Adding newlines when `/n` present in strings with `writelines()`**
```python
f = open('myfile.txt', 'w')
lines = ['line 1\n', 'line 2\n', 'line 2\n`]
f.writelines(lines) # Writes all lines at once
f.close
```

Note: Mind that the `writelines()` method does not add `'\n'` (newline characters) between the strings in the sequence.


- **2. Adding newlines when `/n` missing in strings with `writelines()`**
```python
f = open('myfile.txt', 'w')
lines = ['line 1', 'line 2', 'line 3']
# Add newline after each line before writing
f.writelines(line + '\n' for line in lines)
f.close()
```

- **3.  Adding newlines when `/n` missing in strings with `write()`**
```python
f = open('myfile.txt', 'w')
lines = ['line 1\n', 'line 2\n', 'line 2\n`]
for line in lines:
	f.write(lines)
f.close
```

- This is useful have list of strings to represent in new line each but don't have ending with `'\n'`

Output: `myfile.txt`
```
line 1
line 2
line 3
```

---

# [seek(), tell() and other functions | Python Tutorial - Day #51](https://youtu.be/PByYX-2l5Us)


In Python, the seek() and tell() functions are used to work with file objects and their positions within a file. These functions are part of the built-in io module, which provides a consistent interface for reading and writing to various file-like objects, such as files, pipes, and in-memory buffers.

### `seek()` function

The `seek()` function allows you to move the current position within a file to a specific point. The position is specified in bytes, and you can move either forward or backward from the current position. For example:

`file.txt`
```
Harry is a good boy
```

```python
with open('file.txt', 'r') as f:
    f.seek(10)       # Move to 10th byte
    data = f.read(5) # Read 5 bytes → ' good'
```

Step-by-step:
```
1. Initially at byte 0

2. f.seek(10)
   Moves cursor to byte 10
   Harry is a good boy
             ↑ (position 10)

3. f.read(5)
   Reads 5 bytes from position 10
   → ' good'

```
 
 Note: 
 - `print(type(f))` -> `<class '_io.TextIOWrapper'>` -> work on built-in IO Module
-  `1 byte` = `1 char`

### `tell()` function

The tell() function returns the current position within the file, in bytes. This can be useful for keeping track of your location within the file or for seeking to a specific position relative to the current position. For example:

`file.txt`
```
Harry is a good boy
```

```python
with open('file.txt', 'r') as f:
  # Read the first 10 bytes
  data = f.read(10)

  # Save the current position
  current_position = f.tell()

  # Seek to the saved position
  f.seek(current_position)
```

Step-by-step:
```
1. Start at byte 0

2. f.read(10)
   → Reads 'Harry is a'
   → Cursor moves to byte 10

3. f.tell()
   → Returns 10

4. f.seek(10)
   → Moves cursor to byte 10 (same position)

```
## truncate() function

When you open a file in Python using the open function, you can specify the mode in which you want to open the file. If you specify the mode as 'w' or 'a', the file is opened in write mode and you can write to the file. However, if you want to truncate the file to a specific size, you can use the truncate function.

Here is an example of how to use the truncate function:

```python
with open('sample.txt', 'w') as f:
  f.write('Hello World!')
  f.truncate(5) 

with open('sample.txt', 'r') as f:
  print(f.read())
```

Step-by-step:
```
1. File is initially blank

2. f.write('Hello World!')
   → File content: 'Hello World!'

3. f.truncate(5)
   → File is cut to first 5 bytes
   → Final content: 'Hello'
```

---

# [Lambda functions in Python | Python Tutorial - Day #52](https://youtu.be/UfFWf-PXUqE)

Lambda Functions in Python

**Normal Function**

```python
# Function to double the input
def double(x):
  return x * 2
```

**Lambda Functions in Python**

In Python, a lambda function is a **small anonymous function** ⭐ without a name. It is defined using the lambda keyword and has the following syntax:

```python
lambda arguments: expression
```

Lambda functions are often used in situations where a small function is required for a short period of time. They are commonly used as arguments to higher-order functions, such as map, filter, and reduce.

Here is an example of how to use a lambda function:
```python
# Lambda function to double the input
lambda x: x * 2
```


Lambda functions can have multiple arguments and can be assigned to variable, just like regular functions
```python
# Lambda function to calculate the product of two numbers
product = lambda x, y: x * y

print(product(2,5)) # 10
```

Lambda functions can also include multiple statements, but they are limited to a single expression. For example:

```python
# Lambda function to calculate the product of two numbers,
# with additional print statement
lambda x, y: print(f'{x} * {y} = {x * y}')
```

In the above example, the lambda function includes a print statement, but it is still limited to a single expression.

Lambda functions are **often used in conjunction** with higher-order functions, such as map, filter, and reduce which we will look into later.

**Function is passed as Function**

In Python, functions can be passed as arguments to other functions. This allows for flexible and reusable code.
```python
# Function that takes another function as input and applies it to a value
def appl(fx, value):
	return 6+ fx(value) # Calls the passed function and adds 6 to the result

# Calling the function with a lambda function that cubes a number
print(appl(lambda x:x*x*x,2)) # lambda function to cube a no.
```
---

# [Map, Filter and Reduce in Python | Python Tutorial - Day #53](https://www.youtube.com/watch?v=OErhjT4f5Cs)


- **map()**, **filter()**, and **reduce()** are **higher-order functions** in Python 
- A **higher-order function** is a function that either:
	1. **Takes another function as an argument**
	2. **Returns a function as a result**
    

This makes them powerful tools in **functional programming**.
### Map, Filter and Reduce

In Python, the map, filter, and reduce functions are built-in functions that allow you to apply a function to a sequence of elements and return a new sequence. These functions are known as higher-order functions, as they take other functions as arguments.

#### **map**

- The map function applies a function to each element in a sequence and returns a new sequence containing the transformed elements.

**Syntax:**
```python
map(function, iterable)
```

- The function argument is a function that is applied to each element in the iterable argument. The iterable argument can be a list, tuple, or any other iterable object.

**Example:**
```python
# List of numbers
numbers = [1, 2, 3, 4, 5]

# Double each number using the map function
doubled = map(lambda x: x * 2, numbers)

# Print the doubled numbers
print(list(doubled))
```

- In the above example, the lambda function lambda x: x * 2 is used to double each element in the numbers list. The map function applies the lambda function to each element in the list and returns a new list containing the doubled numbers.

#### **filter**

- The filter function filters a sequence of elements based on a given predicate (a function that returns a boolean value) and returns a new sequence containing only the elements that meet the predicate. The filter function has the following syntax:

**Syntax:**
```python
filter(predicate, iterable)
```

- The predicate argument is a function that returns a boolean value and is applied to each element in the iterable argument. The iterable argument can be a list, tuple, or any other iterable object.


**Example:**
```python
# List of numbers
numbers = [1, 2, 3, 4, 5]

# Get only the even numbers using the filter function
evens = filter(lambda x: x % 2 == 0, numbers)

# Print the even numbers
print(list(evens))
```

- In the above example, the lambda function lambda x: x % 2 == 0 is used to filter the numbers list and return only the even numbers. The filter function applies the lambda function to each element in the list and returns a new list containing only the even numbers.

#### **reduce**

- The reduce function is a higher-order function that applies a function to a sequence and returns a single value. 

- It is a part of the `functools` module in Python ⭐

**Syntax:**
```python
reduce(function, iterable)
```

- The function argument is a function that takes in two arguments and returns a single value. The iterable argument is a sequence of elements, such as a list or tuple.

- The reduce function applies the function to the first two elements in the iterable and then applies the function to the result and the next element, and so on. The reduce function returns the final result.

**Example:**
```python
from functools import reduce

# List of numbers
numbers = [1, 2, 3, 4, 5]

# Calculate the sum of the numbers using the reduce function
sum = reduce(lambda x, y: x + y, numbers)

# Print the sum
print(sum)
```

- In the above example, the reduce function applies the lambda function lambda x, y: x + y to the elements in the numbers list. The lambda function adds the two arguments x and y and returns the result. The reduce function applies the lambda function to the first two elements in the list (1 and 2), then applies the function to the result (3) and the next element (3), and so on. The final result is the sum of all the elements in the list, which is 15.

- It is important to note that the reduce function requires the functools module to be imported in order to use it.

---

# [`is` vs  `==` in Python | Python Tutorial - Day #54](https://youtu.be/TOemdfX_0xc)

**`==`** -> Compare Values of two objects
**`is`** -> Compare Exact location of two objects in Memory

It is obvious
```python
a = 4 # Int
b = "4" # String

print(a == b)  # False ❌ → Different types: int vs str
print(a is b)  # False ❌ → Different objects in memory
```

In Python, is and `==` are both comparison operators that can be used to check if two values are equal. However, there are some important differences between the two that you should be aware of.

The is operator compares the identity of two objects, while the `==` operator compares the values of the objects. This means that `is` will only return `True` if the objects being compared are the exact same object in memory, while `==` will return `True` if the objects have the same value.


```python
a = [1, 2, 3] # List
b = [1, 2, 3] # List

print(a == b)  # True ✔️ → Same content
print(a is b)  # False ❌ → Mutable -> Different list objects in memory
```

**Note:**  
- Mutable objects like `list`, `dict`, `set` **can change**. So Python creates a **new object** every time to avoid bugs.


In this case, a and b are two separate lists that have the same values, so == returns True. However, a and b are not the same object in memory, so is returns False.

One important thing to note is that, in Python, strings and integers are immutable, which means that once they are created, their value cannot be changed. This means that, for strings and integers, is and `==` will always return the same result:

```python
a = "hello" # String
b = "hello" # String

print(a == b)  # True ✔️ → Same content
print(a is b)  # True ✔️ → Python interns short strings → Same object
```

```python
a = 5 # Int
b = 5 # Int

print(a == b)  # True ✔️ → Same value
print(a is b)  # True ✔️ → Python caches small integers → Same object
```

**Note:** 
- Python **automatically reuses** memory for **immutable** objects like:  Small integers (`-5 to 256`), Short strings (especially literals), Booleans, None. 
- This is called **_interning_** or **_object caching_**.


```python
a = (1, 2) # Tuple
b = (1, 2) # Tuple

print(a == b)  # True ✔️ → Same value
print(a is b)  # True ✔️ → Python caches small integers → Same object
```

**Note:**
- Tuples are **immutable**, so they **can** be interned sometimes.
- But if they **contain mutable elements**, they won't be interned.

****

In these cases, a and b are both pointing to the same object in memory, so is and `==` both return True.

For mutable objects such as lists and dictionaries, is and `==` can behave differently. In general, you should use `==` when you want to compare the values of two objects, and use is when you want to check if two objects are the same object in memory.

I hope this helps clarify the difference between is and `==` in Python!

---

# [Regular Expressions in Python | Python Tutorial - Day #95](https://youtu.be/TCWOwavqFrw)

- **Definition**: Regular expressions (regex) are patterns used to match character combinations in strings.
    
- **Purpose**: They simplify complex string matching tasks by providing a built-in way to search for patterns without needing extensive custom logic.
    

 **Using Regular Expressions in Python**

**Importing the `re` module**:     
```python
import re
```
    
**Basic Matching**: You can use `re.search()` to find if a pattern exists in a string.    
```python
text = "Wikipedia is a free online encyclopedia."
pattern = "free"
match = re.search(pattern, text)
```
```
Output:
<re.Match object; span=(15, 19), match='free'>
```
    
**Complex Patterns**: Regex allows you to define complex patterns using **meta characters**.
- **Character Classes**: Use square brackets `[]` to specify a set of characters. For example, `[A-Z]` matches any uppercase letter.
- **Special Characters**: Use a backslash `\` to denote special characters. For example, `\n` matches a newline character.
- **Quantifiers**: Use `+`, `*`, or `?` to specify the number of occurrences. For example, `a+` matches one or more `a`s.

Note: For many tasks, you can write your own logic using **for loops** and custom conditions, but it is **time-consuming and inefficient**.  **Regex** offers a **concise and powerful way** to handle **complex pattern matching** efficiently.

**`re.finditer()` Returns Match Objects:** It returns **match objects** instead of the matched strings directly.
```python
text = "Cyclone and Dyclone are storms."
pattern = r"[A-Z]yclone"
matches = re.finditer(pattern, text)
for match in matches:
    print(match)
```
```
Output:
<re.Match object; span=(0, 7), match='Cyclone'>  
<re.Match object; span=(12, 19), match='Dyclone'>  

```

**Extracting Matched Text:** Use `.group()` to extract the **matched text** from each match object.
```python
text = "Cyclone and Dyclone are storms."
pattern = r"[A-Z]yclone"
matches = re.finditer(pattern, text)
for match in matches:
    print(match.group())
```

**Extracting Match Positions:** Use `.span()` to get the **start and end positions** of each match.
```python
text = "Cyclone and Dyclone are storms."
pattern = r"[A-Z]yclone"
matches = re.finditer(pattern, text)
for match in matches:
    print(match.span())
```
```
Output:
(0, 7)
(12, 19)
```
- **`type(match.span())`** -> Tuple 
- **`.span()`** → Returns a tuple of the **start and end positions** of each match, which you can use to slice the string.

**Extracting Matched Text Using `.span()` Indexes:**
```python
text = "Cyclone and Dyclone are storms."
pattern = r"[A-Z]yclone"
matches = re.finditer(pattern, text)
for match in matches:
    print(text[match.span()[0]:match.span()[1]])
```
```
Output:
Cyclone  
Dyclone  
```

**Raw Strings:** Prefixing with `r` treats the string as **raw**, preventing Python from interpreting backslashes as escape characters.
```python
pattern = r"\n"  # Matches a literal backslash followed by 'n'
```
```
Output:
Cyclone  
Dyclone  
```
- **Without `r`:** `\n` is interpreted as a newline.
- **With `r`:** `\n` is treated as two separate characters: `\` and `n`.

**Learn More**
- [Regex Python Documentation]()
-  [Meta Character in Regex - ibm.com](https://www.ibm.com/docs/en/datapower-gateway/10.6.x?topic=gateway-meta-characters-regular-expressions)
-  [Practice Regex Regexr.com](https://regexr.com/)
    

**Practice and Application**
- Regular expressions are used in many programming languages, including JavaScript.
- They simplify tasks like data validation and text processing.
- Practice is essential to master regex, as it can be complex for beginners.

---
