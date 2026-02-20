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

# 🤖 Notes+GPT\_Python Special Syntax

#### ✅ **1. Keywords with `__` (Double Underscore) in Python**

These are **"Dunder" (Double Underscore) Methods & Variables**, mainly used for **special functions and attributes** in Python.

| **Dunder Name** | **Purpose**                            |
| --------------- | -------------------------------------- |
| `__init__`      | Constructor method in classes          |
| `__str__`       | String representation (`str(obj)`)     |
| `__repr__`      | Debug representation (`repr(obj)`)     |
| `__name__`      | Module name (`__name__ == "__main__"`) |
| `__call__`      | Make an object callable (`obj()`)      |
| `__len__`       | Length of an object (`len(obj)`)       |
| `__getitem__`   | Indexing support (`obj[key]`)          |
| `__setattr__`   | Control setting attributes             |
| `__del__`       | Destructor method                      |
| `__new__`       | Customize object creation              |

* **These are not "keywords", but rather special names recognized by Python.**

***

#### ✅ **2. Keywords with `@` in Python**

These are called **"Decorators"**, which modify functions or methods.

| **Decorator**   | **Purpose**                                     |
| --------------- | ----------------------------------------------- |
| `@decorator`    | Defines a decorator function                    |
| `@classmethod`  | Defines a class method                          |
| `@staticmethod` | Defines a static method                         |
| `@property`     | Defines a getter property                       |
| `@app.route()`  | Flask route decorator (e.g., `@app.route("/")`) |
| `@pytest.mark`  | Pytest test marker                              |

* **Decorators start with `@` and modify functions/classes.**

***

#### ✅ **Python String Prefixes & Format Strings**

| Prefix          | Meaning                                              | Example                                                      |
| --------------- | ---------------------------------------------------- | ------------------------------------------------------------ |
| `f""` or `f'''` | **Formatted String Literal** (f-strings)             | `name = "Gaurav"; print(f"Hello {name}")` → `"Hello Gaurav"` |
| `r""` or `r''`  | **Raw String** (ignores escape sequences)            | `print(r"C:\new\folder")` → `"C:\new\folder"`                |
| `b""` or `b''`  | **Byte String**                                      | `b"hello"` → `b'hello'`                                      |
| `u""`           | **Unicode String** (Python 2, redundant in Python 3) | `u"hello"` → `"hello"`                                       |
| `"""` or `'''`  | **Multiline String**                                 | `"""Hello\nWorld"""` → `"Hello\nWorld"`                      |
| `%` Formatting  | **Old String Formatting**                            | `"Hello %s" % "Gaurav"`                                      |
| `.format()`     | **String `format()` method**                         | `"Hello {}".format("Gaurav")`                                |

* `f""` → **Best for dynamic formatting** (faster & readable).
* `r""` → **Best for regex or Windows paths** (avoids `\n` issues).
* `b""` → **For byte data, encoding purposes**.
* `""" """` → **For docstrings & multi-line text**.
