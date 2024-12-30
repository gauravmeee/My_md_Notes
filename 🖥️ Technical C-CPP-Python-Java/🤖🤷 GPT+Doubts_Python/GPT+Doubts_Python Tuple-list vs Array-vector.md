


- **Tuple**: Unlike List `List=[]` , tuple `tuple=()` are Immutable (cannot be changed once created) 
```python
myTuple = (1, 2, 3);
myTuple[0] = 100 ❌ TypeError
```

- List is slower than tuple due to mutability
- List take more memory due to its dynamic nature
- In tuple has no methods for modifying( like `.append()`, `.remove`, `.sort()`, etc.) content, but have accessing methods like `.count()`, `.index()`
- Both lists and tuples can store nested structures like
```python
nested_list = [[1, 2], [3, 4]] # list of list
nested_tuple = ((1, 2), (3, 4)) # tuple of tuples 
mixed = ([1, 2], (3, 4)) # tuple of lists
```

- Since tuples are immutable, they can be used as keys in dictionaries, while lists cannot be used as keys.
```python
# Using a tuple as a dictionary key
my_tdict = {(1, 2): "tuple_key"} 
my_ldict = {[1, 2]: "list_key"}  # ❌ TypeError
```


# C++ Vs Python

- **tuples** and **lists** in Python can store elements of different data types.
```python
# Python List
my_list = [1, 2, 3]

# Python Tuple
my_tuple = (1, 2, 3)

```

```cpp
// C++ Array
int arr[3] = {1, 2, 3};

// C++ Vector
std::vector<int> vec = {1, 2, 3};
```


Python `List` =  `Vector` C++
Python `Tuple` = `Array` C++


Array vs Tuple
- Tuple = Fixed Size and Immutable
- Array = Fixed Size but Mutable

- Tuple = Can store elements of different types.
- Array = Homogeneous, all elements must be of the same type.

Vector vs List
- Both  = dynamic resizing and mutable

- List = Can store elements of different types.
- Vector = Homogeneous, all elements must be of the same type.


Note: Tuple are mutable, thats not mean, that we can't reassign tuple.
When you **reassign a tuple variable** to new data in Python, the original tuple does not get modified; instead, a new tuple is created, and the variable points to this new tuple. The **previous data** (the original tuple) is **no longer referenced** by that variable, so it becomes eligible for **garbage collection** if no other variables or objects reference it.
