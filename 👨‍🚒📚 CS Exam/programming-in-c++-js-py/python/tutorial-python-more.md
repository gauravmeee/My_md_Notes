# [Shallow Copy Vs Deep Copy in Python(Krish Naik)](https://www.youtube.com/watch?v=SgUwPDT9tEs&pp=ygUcc2hhbGxvdyBhbmQgZGVlcCBjb3B5IHB5dGhvbtIHCQl-CQGHKiGM7w%3D%3D "Shallow Copy Vs Deep Copy in Python")


**Three Operation in Focus**
- `=`
- `copy()`
- `deepcopy()`

### 1.  `=` (Assignment ) - Same Reference

```python
lst1 = [1, 2, 3, 4]
lst2 = lst1        # Not a copy, just another reference

lst2[1] = 1000     # Change through lst2
print(lst1)        # [1, 1000, 3, 4] — also changed
```
- `lst2 = lst1` means **both point to the same object**.
- Any change through `lst2` affects `lst1`.


### 2. `copy()` - Shallow Copy

```python
lst1 = [1, 2, 3, 4]
lst2 = lst1.copy()   # Creates a new list

lst2[1] = 1000
print(lst1)          # [1, 2, 3, 4] — unchanged
```
- `copy()` creates a new list with **same elements** (primitives).
- So, changing one does **not affect** the other.

#### Shallow Copy with Nested Lists

```python
lst1 = [[1, 2, 3, 4], [5, 6, 7, 8]]
lst2 = lst1.copy()
```

**Case 1: Replace whole nested list**
```python
lst2[1] = [100, 200, 300, 400]
print(lst1)  # [[1, 2, 3, 4], [5, 6, 7, 8]] — unchanged
```
- Replacing whole inner list creates a new object → doesn't affect original.

**Case 2: Append new nested list ⭐
```python
lst1.append([2, 3, 4, 5])

print(lst1) # [[1, 2, 3, 4], [5, 6, 7, 8], [2, 3, 4, 5]]
print(lst2) # [[1, 2, 3, 4], [5, 6, 7, 8]]  — unchanged
```
- Adding new outer element → doesn't affect original.

**Case 3: Modify inner element**
```python
lst2[1][0] = 100
print(lst1)  # [[1, 2, 3, 4], [100, 6, 7, 8]] — changed!
```
- Because `.copy()` only copies the **outer list**, not the inner ones.
- Both `lst1[1]` and `lst2[1]` still refer to **same inner list**.


### 3. `deepcopy()` - Deep Copy

```python
import copy
```

```python
lst1 = [1, 2, 3, 4]
lst2 = copy.deepcopy(lst1)

lst2[1] = 100
print(lst1) # [1, 2, 3, 4] - unchanged
```
- In Non-Nested Object -> Shallow Copy = Deep Copy
#### Deep Copy with Nested Lists
```python
lst1 = [[1, 2, 3], [3, 4, 5], [5, 6, 7]]
lst2 = copy.deepcopy(lst1)

lst2[1][0] = 100
print(lst1) = # [[1, 2, 3], [3, 4, 5], [5, 6, 7]] - unchanged
```

- `deepcopy()` creates **new copies of all inner objects** (lists inside list).
-  So changes in `lst2` won't affect `lst1`, even in nested levels.
-  This is different from `.copy()` which only copies the outer list and **shares** inner ones.