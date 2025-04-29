
# **String Formatting in Python**

Python provides multiple ways to format strings efficiently. Below are different string formatting techniques with examples.

---

## **1. f-strings (Formatted String Literals) – Best & Fastest**

Introduced in Python 3.6, **f-strings** allow embedding expressions inside `{}` directly within a string.

```python
name = "Gaurav"
age = 22
print(f"My name is {name} and I am {age} years old.")
```

**Output:**

```
My name is Gaurav and I am 22 years old.
```

✅ **Supports expressions inside `{}`**  
✅ **Fastest method**  
✅ **Readable & concise**

### **(a) Evaluating Expressions inside f-strings**

```python
num1, num2 = 10, 5
print(f"Sum: {num1 + num2}")  # Sum: 15
```

### **(b) Using Functions inside f-strings**

```python
def square(x):
    return x * x

print(f"Square of 4 is {square(4)}")  # Square of 4 is 16
```

### **(c) Formatting Numbers using f-strings**

```python
pi = 3.1415926535
print(f"Pi rounded: {pi:.2f}")  # Pi rounded: 3.14
print(f"Formatted number: {1000000:,}")  # 1,000,000
```

---

## **2. `.format()` Method – Versatile but Verbose**

The `.format()` method allows positional and named placeholders.

```python
name = "Gaurav"
age = 22
print("My name is {} and I am {} years old.".format(name, age))
```

### **(a) Positional & Named Placeholders**

```python
print("Hello, {0}. You are {1} years old.".format("Gaurav", 22))
print("Hello, {name}. You are {age} years old.".format(name="Gaurav", age=22))
```

### **(b) Number Formatting in `.format()`**

```python
pi = 3.1415926535
print("Pi: {:.2f}".format(pi))  # Pi: 3.14
```

---

## **3. `%` Formatting (Old Style, Similar to C)**

Older method, less readable but works in all Python versions.

```python
name = "Gaurav"
age = 22
print("My name is %s and I am %d years old." % (name, age))
```

### **(a) Formatting Numbers with `%`**

```python
pi = 3.1415926535
print("Pi: %.2f" % pi)  # Pi: 3.14
```

---

## **4. Raw Strings (`r""`) – Avoiding Escape Sequences**

Raw strings treat backslashes (`\`) as literal characters.

```python
# Without raw string
print("C:\new\folder")  # Incorrect: \n is treated as a newline

# Using raw string
print(r"C:\new\folder")  # Correct output
```

---

## **5. Multi-line Strings (`''' or """`)**

Used for large text blocks.

```python
text = """This is 
a multi-line 
string."""
print(text)
```

---

## **6. Escape Characters**

```python
print("Newline:\nNext line")  # \n - Newline
print("Tab:\tSpace")  # \t - Tab space
print("Backslash: \\")  # \\ - Backslash
print("Quotes: \"Double\" 'Single'")  # \" and \' for quotes
```

---

## **7. Aligning and Padding Text**

```python
name = "Gaurav"
print(f"Left:  |{name:<10}|")  # Left align
print(f"Right: |{name:>10}|")  # Right align
print(f"Center:|{name:^10}|")  # Center align
```

---

## **8. Formatting Dates & Times in Strings**

```python
from datetime import datetime
now = datetime.now()
print(f"Today: {now:%Y-%m-%d}, Time: {now:%H:%M:%S}")
```

---

## **Conclusion**

|Method|Python Version|Features|Speed|
|---|---|---|---|
|**f-strings**|3.6+|Fastest, cleanest, supports expressions|⭐⭐⭐⭐⭐|
|`.format()`|2.7+|Flexible but verbose|⭐⭐⭐|
|`%` formatting|All|C-style, outdated|⭐⭐|

✅ **Use f-strings (`f"..."`) whenever possible!** 🚀