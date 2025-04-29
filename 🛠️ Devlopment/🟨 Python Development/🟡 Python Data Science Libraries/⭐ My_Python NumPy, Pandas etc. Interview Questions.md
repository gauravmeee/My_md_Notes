
# [Pandas Interview Questions](https://www.interviewbit.com/pandas-interview-questions/)

# [MatplotLib Interview Questiosn](https://www.withoutbook.com/InterviewQuestionList.php?tech=282&dl=Top&s=Python%20Matplotlib%20interview%20questions%20and%20answers)

# [NumPy Interview Questions](https://www.interviewbit.com/numpy-interview-questions/)

# [Scikit Learn Interview Questions](https://github.com/Devinterview-io/scikit-learn-interview-questions)


---

# NumPy, Pandas, Scikit-learn, Matplotlib Question from [HCL Python Interview questions](https://www.credosystemz.com/hcl-python-interview-questions/) ✅

### **1. NumPy**

#### **7. Why you should use NumPy arrays instead of nested Python lists?**

NumPy is the fundamental package for **scientific computing** in Python. NumPy arrays facilitate advanced mathematical and other types of operations on large numbers of data.

**Advantages of using Numpy Arrays Over Python Lists:**
- ==**Faster Computation**==  – NumPy uses optimized C-based functions, making operations significantly faster.
- ==**Less Memory== Usage**  – Uses ==contiguous memory blocks==, reducing overhead compared to Python lists.
- ==**Vectorized Operations**==  – Supports element-wise operations without explicit loops (`+`, `*`, etc.).
- **Broadcasting**  – Allows operations on different-sized arrays without extra loops.
- **==Convenient Functions**==  – Built-in mathematical operations like `mean()`, `sum()`, `dot()`, etc.

Note: NumPy is 10-100x faster than lists for large data operations

### **2. Pandas**

#### **4. What is the main difference between a Pandas series and a single-column DataFrame in Python?**

**Series** is a type of list in pandas which can take integer values, string values, double values and more. Series can only contain single list with index, whereas dataframe can be made of more than one series or we can say that a dataframe is a collection of series that can be used to analyse the data.

**Difference Between Pandas Series and Single-Column DataFrame**

| Feature        | **Pandas Series**                                                    | **Single-Column DataFrame**                                           |
| -------------- | -------------------------------------------------------------------- | --------------------------------------------------------------------- |
| **Definition** | A **one-dimensional** labeled array.                                 | A **two-dimensional** labeled table with one column.                  |
| **Structure**  | Similar to a column in a DataFrame but independent.                  | A DataFrame with a single column.                                     |
| **Indexing**   | Has an index, just like a DataFrame.                                 | Also has an index, but includes column labels.                        |
| **Data Type**  | Stores homogeneous data (same type).                                 | Can store different types across columns (but here, only one column). |
| **Shape**      | `(n,)` → 1D (like a list).                                           | `(n,1)` → 2D (like a table).                                          |
| **Usage**      | Best for storing & performing operations on a single column of data. | Used when expecting tabular structure (e.g., database-like tables).   |

**Example: Series vs. Single-Column DataFrame**
```python
import pandas as pd

# Creating a Pandas Series
series = pd.Series([10, 20, 30, 40])
print(series)
print(type(series))  # <class 'pandas.core.series.Series'>

# Creating a Single-Column DataFrame
df = pd.DataFrame({'Column1': [10, 20, 30, 40]})
print(df)
print(type(df))  # <class 'pandas.core.frame.DataFrame'>
```
**Key Takeaways**
- **Use a Series when working with a single array of data** (like a column of numbers).  
- **Use a DataFrame when working with structured data** (even if it’s just one column, for better table-like operations).


#### **5. How can you handle duplicate values in a dataset for a variable in Python?** ⭐

`df.drop_duplicates([‘col1’])`

Here, you drop duplicates from column1. Alternatively, you can add `keep` and indicate whether you’d like to keep the first argument (`keep='first'`), the last argument (`keep='last'`) from the duplicates or drop all the duplicates altogether (`keep=False`).


**1. Identify Duplicates**

Use `.duplicated()` to check for duplicate rows.
```python
import pandas as pd

# Sample Data
data = {'Name': ['Alice', 'Bob', 'Alice', 'Charlie', 'Bob'],
        'Age': [25, 30, 25, 35, 30]}
df = pd.DataFrame(data)

# Check for Duplicates
print(df.duplicated())  # Shows which rows are duplicates
```

**2. Remove Duplicate Rows**

- **Drop all duplicate rows** (keep only the first occurrence).
```python
df_unique = df.drop_duplicates() # default keep = 'first'
```

- **Drop duplicates from a specific column**
```python
df_unique_col = df.drop_duplicates(subset=['Name'])
```

- **Keep only the last occurrence**
```python
df_unique_last = df.drop_duplicates(keep='last')
```

- **Drop all occurrences of duplicates**
```python
df_no_duplicates = df.drop_duplicates(keep=False)
```

**3. Remove Duplicate Entries with Reset Index**
```python
df_cleaned = df.drop_duplicates().reset_index(drop=True)
```

#### **6. Can we create a DataFrame with multiple data types in Python? If yes, how can you do it?**

- **Yes**, a Pandas DataFrame can have multiple data types.
```python
import pandas as pd

data = {'Name': ['Alice', 'Bob', 'Charlie'],  # String
        'Age': [25, 30, 35],  # Integer
        'Salary': [50000.5, 60000.75, 70000.25],  # Float
        'Joining Date': pd.to_datetime(['2023-01-10', '2022-05-15', '2021-07-22'])}  # Datetime
```
- Pandas **DataFrame** is a **2-dimensional** labeled data structure with ==columns of potentially different types==. 
- It is generally the most commonly used pandas object. Pandas **DataFrame** can be created in multiple ways.

##### **Q13. What are Pandas?**

A fairly extensive collection of data structures for data-based operations can be found in the open-source Python package called Pandas. Because of their amazing features, pandas are a great fit for any data activity, be it academic research or the resolution of challenging business issues. Pandas are among the most vital tools to master since they can handle a wide range of file types.

##### **Q14. What is a Pandas Series?**

**Answer:** Panda’s one-dimensional data structure, Series, can hold nearly any kind of data. It’s like a column in Excel. It is utilised for single-dimensional data manipulations and supports several procedures.
Making a series out of data

**Code:**
```
import pandas as pds
data=["2",3,"four",5.0]
series=pds.Series(data)
print(series)
print(type(series))
```

### **3. MatplotLib**

    
#### **3. Which library would you prefer for plotting in Python language: Seaborn or Matplotlib?**

Seaborn and Matplotlib are two of Python’s most powerful visualization libraries. 
- Seaborn uses fewer syntax and has stunning default themes and 
- Matplotlib is more easily customizable through accessing the classes. By Asel Mendis, KDnuggets. Python offers a variety of packages for plotting data.

Both **Seaborn** and **Matplotlib** are powerful Python libraries for data visualization, but they serve different purposes.


**1. Matplotlib**    
- **Highly customizable**: Can create **any** type of visualization.
- **Best for**: Simple plots, detailed customizations, and when working closely with `NumPy` arrays.
**Example: Basic Line Plot in Matplotlib**
```python
import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [10, 20, 25, 30, 50]

plt.plot(x, y, marker='o', linestyle='--', color='r')
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Matplotlib Line Plot")
plt.show()
```

**2. Seaborn**
- **Built on Matplotlib**: Provides higher-level abstraction.
- **Beautiful default themes**: Better aesthetics out of the box.
- **Best for**: Statistical plots, visualizing distributions, and working with `Pandas` DataFrames.
**Example: Simple Seaborn Scatter Plot**
```python
import seaborn as sns
import pandas as pd

# Sample dataset
data = pd.DataFrame({'x': [1, 2, 3, 4, 5], 'y': [10, 20, 25, 30, 50]})

# Seaborn scatter plot
sns.scatterplot(x='x', y='y', data=data)
```

### **4. Scikiti-Learn**

#### **2. How can you build a simple logistic regression model in Python?**
- **Logistic Regression** is a ==supervised learning algorithm== used for **binary classification** problems, where the output (target variable) has only two possible values (e.g., Yes/No, 0/1, True/False).
- Unlike **Linear Regression**, which predicts continuous values, **Logistic Regression** predicts probabilities and maps them to binary outcomes using the **sigmoid function**.
- Logistic Regression is a statistical method used for binary classification problems. In Python, you can implement logistic regression using libraries like `statsmodels` and `scikit-learn`. Below is an example using **`scikit-learn`**.
- A telecom company wants to predict whether a customer will **churn (leave the service)** or not based on their usage patterns and customer data.

**Step 1: Import Required Libraries**
```python
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report
```

**Step 2: Prepare the Data**
```python
# Sample dataset
data = {
    'Feature1': [2, 3, 5, 7, 9, 11, 12, 14, 16, 18],
    'Feature2': [1, 2, 2, 3, 4, 5, 6, 7, 8, 9],
    'Target':    [0, 0, 0, 0, 1, 1, 1, 1, 1, 1]
}

df = pd.DataFrame(data)

# Split data into features (X) and target (y)
X = df[['Feature1', 'Feature2']]
y = df['Target']

# Split into training and testing sets (80% train, 20% test)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
```

**Step 3: Create and Train the Model**
```python
# Initialize and train the logistic regression model
model = LogisticRegression()
model.fit(X_train, y_train)
```

**Step 4: Make Predictions**
```python
# Predict on test data
y_pred = model.predict(X_test)
```

**Step 5: Evaluate the Model**
```python
# Accuracy Score
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy:.2f}")

# Classification Report
print("Classification Report:\n", classification_report(y_test, y_pred))
```

**Key Features of `scikit-learn` Logistic Regression**
- **`fit(X, y)`** – Trains the model on the dataset.
- **`predict(X)`** – Predicts the class labels.
- **`score(X, y)`** – Returns the accuracy score.
- **`classification_report(y_true, y_pred)`** – Provides precision, recall, and F1-score.

#### **12. Which python library is used for Machine Learning?**

Scikit-learn was **built on top of two Python libraries** – **NumPy and SciPy** and has become the most popular Python machine learning library for developing machine learning algorithms. Scikit-learn have a wide range of supervised and unsupervised learning algorithms that works on a consistent interface in Python.

**Why Scikit-learn?**
- Built on **NumPy, SciPy, and Matplotlib**.
- Provides tools for **data preprocessing, feature selection, and model evaluation**.
- Supports both **supervised and unsupervised learning**.
- Has a **consistent and easy-to-use API**.

**Key Features:**
- **Supervised Learning**: Linear Regression, Logistic Regression, Decision Trees, Random Forest, SVM, etc.  
- **Unsupervised Learning**: Clustering (K-Means, DBSCAN), PCA, etc.  
- **Model Selection**: Train-test split, cross-validation.  
- **Feature Engineering**: Standardization, One-hot encoding, etc.
#### **13. How can you train and interpret a linear regression model in SciKit learn?**


 **Step 1: Import Required Libraries**
```python
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
```

**Step 2: Prepare Data**
```python
# Example dataset
X = np.array([1, 2, 3, 4, 5]).reshape(-1, 1)  # Features (Independent Variable)
y = np.array([2, 4, 5, 4, 5])  # Target Variable (Dependent Variable)
```

**Step 3: Split Data into Training and Testing Sets**
```python
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
```

**Step 4: Create and Train the Model**
```python
model = LinearRegression()
model.fit(X_train, y_train)
```

**Step 5: Get Model Parameters**
```python
print("Intercept:", model.intercept_)
print("Slope:", model.coef_[0])
```

**Step 6: Make Predictions**
```python
y_pred = model.predict(X_test)
```

**Step 7: Evaluate Model Performance**
```python
print("Mean Squared Error:", mean_squared_error(y_test, y_pred))
print("R² Score:", r2_score(y_test, y_pred))
```

**Step 8: Visualize the Regression Line**
```python
plt.scatter(X, y, color='blue', label='Actual Data')
plt.plot(X, model.predict(X), color='red', label='Regression Line')
plt.xlabel("X")
plt.ylabel("y")
plt.legend()
plt.show()
```
