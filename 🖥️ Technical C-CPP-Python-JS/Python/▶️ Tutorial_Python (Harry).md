
# [Functions in Python | Python Tutorial - Day #20](https://youtu.be/dyvxxJSGUsE)
# [Function Arguments in Python | Python Tutorial - Day #21](https://youtu.be/0d6b6fFuCkE)


# [# Python Comprehensions | Python Tutorials For Absolute Beginners In Hindi #73](https://youtu.be/D2h_qI6Tx4M)

# Dictionary Comprehensions
---
# [Exception Handling in Python | Python Tutorial - Day #36](https://youtu.be/4LKo6dlku7M)

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


---

# [Lambda functions in Python | Python Tutorial - Day #52](https://youtu.be/UfFWf-PXUqE)

---

# [Map, Filter and Reduce in Python | Python Tutorial - Day #53](https://www.youtube.com/watch?v=OErhjT4f5Cs)

---

# [`is` vs  `==` in Python | Python Tutorial - Day #54](https://youtu.be/TOemdfX_0xc)

---

# [Introduction to OOPs in Python | Python Tutorial - Day #56](https://youtu.be/HQnoYzxOHMw)

---

# [Classes and Objects in Python | Python Tutorial - Day #57](https://youtu.be/a7baAGCBA9U)

---

# [Constructors in Python | Python Tutorial - Day #58](https://youtu.be/12HRkYld22c)

---

# [Decorators in Python | Python Tutorial - Day #59](https://youtu.be/PTBZ674EsvI)

# [Inheritance in Python | Python Tutorial - Day #61](https://www.youtube.com/@CodeWithHarry)

# [Access Modifiers in Python | Python Tutorial - Day #62](https://youtu.be/43FK20rWvKQ)

---

# [Abstraction & Encapsulation | Python Tutorials For Absolute Beginners In Hindi #59](https://youtu.be/wySW_E4XsvE)

---

# [Polymorphism In Python | Python Tutorials For Absolute Beginners In Hindi #64](https://youtu.be/xnb-9TI-BjQ?list=PLPLmXWcXdkUMJdtK66pOgo20n3unMtDnm)

# [Method Overriding in Python | Python Tutorial - Day #74](https://youtu.be/46_yfYC36JY)