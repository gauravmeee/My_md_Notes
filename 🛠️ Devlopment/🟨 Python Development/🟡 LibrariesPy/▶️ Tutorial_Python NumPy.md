

**Reference:**
- [docs.Scipy.org - Numpy Function and Attributes](https://docs.scipy.org/doc/numpy-1.6.0/reference/generated/numpy.ndarray.html)
# [Numpy Tutorial in Hindi](https://youtu.be/Rbh1rieb3zc)


**Why use NumPy**
- NumPy provides efficient storage
- Its also provides better ways of handling data for processing
- It is fast
- It is easy to learn
- NumPy uses relatively less memory to store data.

**Jupyter Notebook**
- The Jupyter Notebook is an **open-source** web application that allows you to **create and share** documents that contain **live code, equations, visualizations** and narrative text.
- The Notebook has support for over 40 programming languages, including Python, R, Julia, and Scala.
- Notebooks can be shared with others using email, Dropbox, GitHub and the Jupyter Notebook Viewer.
- Your code can produce rich, interactive output: HTML, images, videos, LaTeX, and custom MIME types.

**Install NumPy :**
```sh
pip install numpy
```

**Install Jupyter :**
```sh
pip install jupyter
```

**Run Jupyter Notebook in Browser:** `http://localhost:8888`
```sh
jupyter notebook
```

**Import :**
```python
import numpy as np
```

**1D `numpy` Array**
```python
# 1d numpy array
myarr = np.array([3, 6, 37, 7])

# Size
listarray.size # 4

# (rows,)
myarr.shape # (4,)

# Access 
myarr[2] # 37

# modify
myarr[2] = 5
myarr[2] # 5
```

`numpy` Object
```python
myarr = np.array([3, 6, 37, 7])
my arr # array([3, 6, 37, 7], np.int64) <- 64 bit sys
```

Data types
```python
myarr = np.array([3.2, 6, 3.7, 7], np.int8)
myar.dtype # dtype('float32') <- On 32 bit sys

# datatype = int8
myarr = np.array([3, 6, 37, 7], np.int8)
myar.dtype # dtype('int8')

# Error 8 bit int Can't store large no. 37772
myarr = np.array([3, 6, 377772, 7], np.int8) ❌ # Error
```

**Basic NumPy Data Types:**
- `np.int_` → Integer (**bits:** 32 or 64, platform-dependent)
- `np.uint` → Unsigned Integer (**bits:** 32 or 64, platform-dependent)
- `np.float_` → Floating-point (**bits:** 64)
- `np.bool_` → Boolean (`True/False`)
- `np.str_` → String
- `np.complex_` → Complex number (**bits:** 128)
- `np.datetime64` → Date and time values
- `np.timedelta64` → Time difference

**Note:** The underscore (`_`) in NumPy types (e.g., `np.int_`, `np.float_`) **differentiates** them from native Python data types and indicates **platform-dependent precision**
    
**Bit-specific types:**
- `np.int8, np.int16, np.int32, np.int64` → Signed integers
- `np.uint8, np.uint16, np.uint32, np.uint64` → Unsigned integers
- `np.float16, np.float32, np.float64` → Floating-point numbers
- `np.complex64, np.complex128` → Complex numbers

**2D `numpy` Array**
```python
# 2d numpy array
myarr = np.array([[3, 6, 37, 7]])

# (rows, cols)
myarr.shape # (1, 4)

# Access 
myarr[0,1] # 6
```

**3D `numpy` Array**
```python
# 3D numpy array
myarr = np.array([[[1, 2, 3], 
                   [4, 5, 6]],
                  
                  [[7, 8, 9], 
                   [10, 11, 12]]])

# Shape (blocks, rows, cols)
print(myarr.shape)       # (2, 2, 3)

# Accessing elements
print(myarr[0, 1, 2])   # 6 
```

**Five ways to creating `numpy` array**

1. Conversion from other Python structures (e.g., lists, tuples)
2. Intrinsic `numpy` array creation objects (e.g., arange, ones, zeros, etc.)
3. Reading arrays from disk, either from standard or custom formats
4. Creating arrays from raw bytes through the use of strings or buffers
5. Use of special library functions (e.g., random)

**1. Array Creation : Conversion from other Python structures**
```python
# numpy array from List
listarray = np.array([[1,2,3], [5,8,5],[0,3,1]])

# numpy array of dictionary object dtype 
np.array({34, 23, 23}) # array({34, 23}, dtype=object)
# note: its not efficient for mathematical (used list, tuple instead)
```

**2. Array Creation : Intrinsic numpy array creation object**
```python
# 2.1 Zeros

# Create a 2x5 numpy array of '0's
zeros = np.zeros((2,3))
zeros # array([[0., 0., 0.], [0., 0., 0.]])
zeros.shape  # (2, 5)
zero.dtype # dtype('float64')
```

```python
# 2.2 A-range

#Create a numpy array of range(15) i.e 0 to 14
rng = np.arange(15)
rng # array([0, 1, 2, 3, 4, ... 14])
```

```python
# 2.3 L-space

# Create a numpy array of 12 linearly spaced number (1 to 5)
lspace = np.linspace(1, 5, 12)
lnspace # array([1., 1.36.., 1.72.., 2.09.., ..., 5.])
```

```python
# 2.4 Empty

# Create array of 1x1 with random numbers
emp = np.empty((1,2)) # Array([1.245e-306, 8.34e-308])
```

```python
# 2.4 Empty Like

# Create an Empty array using the size of some existed array
# lspace = np.linspace(1, 5, 12)
emp = np.empty_like(lspace)
```

```python
# 2.5 Identity

# Create an Identity Matrix of 3x3
emp = np.identity(3)  # Array([[1, 0, 0]
                      #        [0, 1, 0]
                      #        [0, 0, 1]])
```

```python
# 2.5 Reshape

# Create an numpy array by reshaping existing one
# rng = np.arange(6)
emp = np.reshape(2,3)  # Array([0,1,2],[3,4,5])
emp = np.reshape(2,2)  # ValueError: cannot reshape ❌ 

# Note: arrange(n) & reshape(x,y) n=x*y
```

```python
# 2.5 Ravel

# Create an numpy array by making existing array linear i.e. 1D
# zeros = np.zeros((2,3))
emp = np.reshape(2,3)  # Array([0, 0, 0, 0, 0, 0])
```


[numpy axis](https://youtu.be/Rbh1rieb3zc?t=2066)

```
Take care, what is attribute and what is function
   
ar.T -> Attribute
one.argmax() -> function
```


**NumPy Axis**

```
1D Array:

arr = np.array([1, 2, 3, 4, 5])

- Shape -> (5,0)
- Axis0 -> Row direction -> Horizontal


[ 1  2  3  4  5 ]
    -→ Axis0 (x-axis)
```

```
2D Array:

arr = np.array([[1, 2, 3],  
                [4, 5, 6],  
                [7, 1, 0]])

- Shape -> `(3, 3)` → 3 rows, 3 columns
- Axis0 -> Rows ↓ (vertical)
- Axis1 -> Columns → (horizontal)

	       -→ Axis1 (y-axis)  
       ↓  ┌         ┐  
   Axis0  │ 1  2  3 │ 
 (x-axis) │ 4  5  6 │ 
	      │ 7  1  0 │  
	      └─       ─┘

```

```
3D Array:

- **Shape:** `(2, 2, 3)` → 2 matrices, 2 rows, 3 columns
- Axis0 → Depth (matrices)
- Axis1 → Rows
- Axis2 → Columns

y-axis
  ↑    z-axis
  |   ╱
  | ╱
 -|--------→ x-axis
```

```python
# Arguments:

x = [[1, 2, 3], [4, 5, 6], [7, 1, 0]]

ar = np.array(x)

ar # array([[1, 2, 3],
   #        [4, 5, 6],
   #        [7, 1, 0]])


# Sum Along X-Axis
ar.sum(axis=0) # array([12, 8, 9])
# 1+4+7=12, 2+5+1=8, 3+6+0=9

# Sum along Y-Axis
ar.sum(axis=1) # array([6, 15, 8])
# 1+2+3=6, 4+5+6=15, 7+1+0=8

# Transpose Matrix
ar.T # array([[1, 4, 7],
     #        [2, 5, 1],
     #        [3, 6, 0]])

# Get No. of Dimension
ar.ndim # 2

# No. of Elements in Array
ar.size #9

# No. of bytes Array taking
ar.nbytes # 36

# Make A Linear iterator on Array
ar.flat # <numpy.flatiter at 0x988d490>

for item in ar.flat:
	print(item) # 1
	            # 2
	            # 4
	            # 4
	            # 5
	            # 6
	            # 7
	            # 1
	            # 0
```


**Note:** 
- Above we have see Example of NumPy **arguments** (no `()`) access properties/metadata
- Now we will see NumPy **functions** (`()`) perform operations/transformations.

```python
# 1D Functions():

one = np.array([1,3,4,634,2])

# Index(Argument) of Maximum/Minimum Element
one.armax() # 3
one.armin() # 0

# Indexes for the sorted Array
one.argsort() # array([0, 4, 1, 2, 3], dtype=int32)
```

```python
# 2D Functions():

two = np.array([[1, 2, 3],
                [4, 5, 6],
                [7, 1, 0]])


# Flat and find Index of Maximum/Minimum Element
two.argmax() # 6
two.argmin() # 8

# Row Index of Maximum Element Along Each Row (for each column)
two.argmax(axis=0) # array([2, 1, 1], dtype=int32)

# Column Index of Minimum Element Along Each Column (for each row)

two.argmin(axis=1) # array([0, 0, 2], dtype=int32)


two.argmin() # By default same as two.argmin(axis=1)

# Column Indexes for Each row sorted
two.argsort(axis=1) # array([[0, 1, 2],
					#        [0, 1, 2],
					#        [2, 1, 0]])

# Column Indexes for Each row sorted
two.argsort(axis=0) # array([[0, 2, 2],
                    #        [1, 0, 1], 
                    #        [2, 1, 0]])
```

 **Note:** By default, `np.argsort()` uses `axis=-1` (i.e., the last axis), which is equivalent to `axis=1` for **2D arrays  sorts along rows.

```python
ar = np.array([[1, 2, 3], 
			   [4, 5, 6],
			   [7, 1, 0]])

# Flatten the 2D array
ar.ravel() # array([1, 2, 3, 4, 5, 6, 7, 1, 0])

# Reshape dimension into 1 row x 9 col
ar.reshape(1,9) # array([1, 2, 3, 4, 5, 6, 7, 1, 0])

# Reshape dimension into 9 row x 1 col
ar.reshape((9,1)) # array([[1],
                  #        [2],
                  #        [3],
                  #        [4],
                  #        [5],
                  #        [6],
                  #        [7],
                  #        [1],
                  #        [0]])
```

**Mathematical and More Operation in NumPy**

```python
# Try Addition of each element of Array with each element of another array
[2, 5] + [4, 6] # [2, 5, 4, 6] ❌ Combine instead of Add

# Array have different behavior toward the mathematical operators.
```

```python
ar1 = np.array([[1, 2, 3], 
			    [4, 1, 6],
			    [2, 1, 0]])

ar2 = np.array([[1, 4, 1],
                [4, 5, 1]
                [3, 1, 0]])

# Matrix Addition
ar1 + ar2 # array([[2, 6, 4],
          #        [8, 6, 7]
          #        [5, 2, 0]])

ar1 + ar2 # array([[1, 8,  3],
          #        [16, 5, 6]
          #        [6, 1,  0]])

# Same Other operations ✔️

# Square Root of each element of array
np.sqrt(ar1)

# Sum of each Element in array
ar1.sum()

# sum of Max/min element in array
ar1.max()
ar1.min()
```

```python
# Find Elements which are greater than 5
np.where(ar1>5) 
# (ary([1,2], dtype=int32), array([2,0], dtype=int32))
#        ↳ 6                         ↳ 7

# its tuple of array
type(np.where(ar1>5)) #tuple

# non zeros in Array
np.count_nonzer(ar1)
# (array([0, 0, 0, 1, 1, 1, 2, 2], dtype=int32),
#  array([0, 1, 2, 0, 1, 2, 0, 1], dtype=int32))
# ex:           ↳ 0x2       ↳ 2x0

# Count no. of non zeros in Array
np.count_nonzer(ar1) # 8

# Recheck by making 0x2 zero
ar[0,2]=0;

np.count_nonzer(ar1)
# (array([0, 0, 1, 1, 1, 2, 2], dtype=int32),
#  array([0, 1, 0, 1, 2, 0, 1], dtype=int32))
# ex:                     ↳ 2x0

np.count_nonzer(ar1) # 7
```

Check if **NumPy** array really Takes Less Space
```python
import sys

# Python Array
py_ar = [0, 4, 55, 2] 

# Numpy Array
chck_ar = np.array(py_ar) 


# Check size of 1 Python Array 
sys.getsizeof(1)*len(py_ar) #  56

# Check size of 1 Numpy Array 
chck_ar.itemsize * chck_ar.size # 16

# Note: Numpy take too less size (16 bytes) compare to Python List array (56 bytes)

```

