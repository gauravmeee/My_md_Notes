
### **Higher-Order Function (HOF)

- A **HOF** is a function that **takes a function as argument** or **returns a function**.
- `forEach`, `map`, `filter`, `reduce` are **all HOFs** because they take a callback function.
    
- Types of HOF usage in JS:
    1. **Callback as argument:** `arr.map(fn)`
    2. **Returning a function:**
    
- Common HOFs in JS: `map`, `filter`, `reduce`, `forEach`, `sort`, `setTimeout`, etc.

### **Types of Higher-Order Functions

A **higher-order method** in JavaScript is a function that either:
1. **Takes another function as an argument**, or
2. **Returns a function** as its result.

**1. Callback as argument** – HOF **takes a function as input**.
```js
const numbers = [1, 2, 3];
const squares = numbers.map(num => num * num); // map takes a callback
console.log(squares); // [1, 4, 9]
```

**2. Returning a function** – HOF **returns another function**.
```js
function multiplier(factor) {
  return function(num) {
    return num * factor;
  }
}
const double = multiplier(2); // multiplier returns a function
console.log(double(5)); // 10
```
- **Key:** First uses a function as argument, second produces a function as output.


---

### **Common HOF in JS**


- **`map()`** – Transforms each item → **Returns a new array**
- **`forEach()`** – Executes a function for each item → **Returns `undefined`**
- **`filter()`** – Filters items by a condition → **Returns a new array**
- **`reduce()`** – Reduces array to a single value → **Returns a single value**
- **`find()`** – Finds the first matching item → **Returns the first match**
- **`findIndex()`** – Finds the index of the first match → **Returns the index**
- **`some()`** – Checks if **any** item meets a condition → **Returns `true` or `false`**
- **`every()`** – Checks if **all** items meet a condition → **Returns `true` or `false`**
- **`sort()`** – Sorts array in place → **Returns the sorted array (mutates original)**
- **`flatMap()`** – Maps and flattens in one step → **Returns a new flattened array**


---

### **Callback Function – Two Forms (General for Array Methods):**

1. **Single parameter (value only):**
```js
arrayMethod(arr => {
  // value = current element
});
```

2. **Multiple parameters (value, index, array):**
```js
arrayMethod((value, index, array) => {
  // value = current element
  // index = position of element
  // array = original array
});
```

**Notes:**
- **First parameter** = current element (mandatory).
- **Second parameter** = index of element (optional).
- **Third parameter** = original array (optional).
- Works for `forEach`, `map`, `filter`.
- **`reduce`** adds an extra first parameter for the accumulator:
```js
arr.reduce((accumulator, value, index, array) => { ... }, initialValue);
```

---
### **Higher-Order Methods in JavaScript:**

**higher-order function** -> a function that Takes another function as an argument (callback) and Returns a function (optional).
##### 1. **Array Methods (e.g., `forEach`, `map`, `filter`, `reduce`)**

###### **A. `forEach`:** Executes a callback for each element but **does ==not return a new array**==.

```js
// Single Parameter Forms (value)
const numbers = [1, 2, 3];
numbers.forEach(num => console.log(num)); // 1 2 3
```

```js
// Multi-Parameter Forms (value, index, array)
const numbers = [1, 2, 3];
numbers.forEach((value, index, array) => {
  console.log(`Index: ${index}, Value: ${value}, Array: ${array}`);
});
```

###### **B. `map`:** Takes a callback function and applies it to each element of the array.

```javascript
// Single Parameter Forms (value)
const numbers = [1, 2, 3];
const squares = numbers.map(num => num * num); // [1, 4, 9]
```

```js
// Multi-Parameter Forms (value, index, array)
const numbers = [1, 2, 3];
const squares = numbers.map((value, index, array) => {
  console.log(`Index: ${index}, Value: ${value}`);
  return value * value;
}); // [1, 4, 9]
```
###### **C. `filter`:** Takes a callback function and returns elements that satisfy the condition.

```javascript
// Single Parameter Forms (value)
const numbers = [1, 2, 3, 4];
const evens = numbers.filter(num => num % 2 === 0); // [2, 4]
```

```js
// Multi-Parameter Forms (value, index, array)
const numbers = [1, 2, 3, 4];
const evens = numbers.filter((value, index, array) => {
  console.log(`Index: ${index}, Value: ${value}`);
  return value % 2 === 0;
}); // [2, 4]
```

###### **D. `reduce`:** Takes a callback function and an accumulator to reduce the array to a single value.

```javascript
// Single Parameter Forms (accumulator, value)
const numbers = [1, 2, 3, 4];
const sum = numbers.reduce((acc, num) => acc + num, 0); // 10
```

```js
// Multi-Parameter Forms (accumulator, value, index, array)
const numbers = [1, 2, 3, 4];
const sum = numbers.reduce((acc, value, index, array) => {
  console.log(`Index: ${index}, Value: ${value}, Acc: ${acc}`);
  return acc + value;
}, 0); // 10

```
#### 2. **Custom Higher-Order Functions**

You can define your own higher-order function:
```javascript
function withLogging(func) {
  return function (...args) {
    console.log('Calling function with arguments:', args);
    return func(...args);
  };
}

const multiply = (a, b) => a * b;
const loggedMultiply = withLogging(multiply);

console.log(loggedMultiply(2, 3)); // Logs arguments and returns 6
```

##### Key Benefits:

- Promotes cleaner and more modular code.
- Enhances reusability and abstraction.
- Simplifies working with data transformations and iterations.

---

### **Understanding Callback Parameters in Array Methods (JavaScript)**

When we use array methods like `forEach`, `map`, `filter`, etc., we pass a callback function to them. This callback can receive up to **three arguments**:

```js
callback(currentValue, index, array)
```

Let’s understand each:

**1. `currentValue`**
- This is the current element of the array being processed.
- It is **mandatory** in the callback.
    

**2. `index` _(optional)_**
- This is the index (position) of the current element in the array.
- Use it when you need to know **where you are** in the array.
    

 **3. `array` _(optional)_**
- This is the **original array** on which the method was called.
- Useful when you want to compare values or need access to the entire array inside the callback.
    

**Is `array` Redundant?**

- No, it's not redundant.
- JavaScript **gives it as an option** so that you can use it **when needed**, without having to refer to the outer array manually. It avoids writing extra code to bring the array into the callback’s scope.

- Example:
```js
const arr = [1, 2, 3];

arr.forEach((value, index, array) => {
  console.log(array); // gives [1, 2, 3] every time
});
```
Even if you're not using it, JavaScript still makes it available. But **you’re free to ignore it** if you don’t need it.


**Applies To These Methods:**
- All standard array methods that process elements one by one:
- `forEach`,  `map`,  `filter`,  `find`,  `findIndex`, `some`, `every`, `flatMap`
    

> Note: `reduce` and `reduceRight` have different callback parameters (accumulator, currentValue, index, array).


**When to Use Which Parameter**
- Use only what you need.
- If you don’t use `index` or `array`, you can omit them in your callback.
    

Examples:
```js
// Only need value
arr.map(value => value * 2);

// Need value and index
arr.map((value, index) => index + value);

// Need all three
arr.map((value, index, array) => {
  return array.length - index;
});
```


---



If you want, I can make a **short cheat sheet of array HOFs with arguments and return types** for quick notes.


### **`forEach` Two Ways**

1. **Simple callback (only value needed):**
    

```js
const numbers = [1, 2, 3];
numbers.forEach(num => console.log(num)); // 1 2 3
```

- Callback takes **only the current element**.
    

2. **Full callback (value, index, array):**
    

```js
const arr = [1, 2, 3];
arr.forEach((value, index, array) => {
  console.log(`Index: ${index}, Value: ${value}`);
});
```

- Callback can take up to **3 arguments**:
    
    - `value` → current element
        
    - `index` → element index
        
    - `array` → the whole array
        

---

