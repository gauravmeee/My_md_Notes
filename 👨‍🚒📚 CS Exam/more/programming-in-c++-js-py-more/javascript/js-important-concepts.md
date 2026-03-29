---
description: Made By Me 💚
icon: dot
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

# JS Important Concepts

## `let` vs `var` Key Differences

| Feature       | `var`                             | `let`                                              |
| ------------- | --------------------------------- | -------------------------------------------------- |
| Scope         | Function-scoped                   | Block-scoped (`{}`)                                |
| Redeclaration | Allowed                           | Not allowed in same block                          |
| Hoisting      | Hoisted (value `undefined`)       | Hoisted (but in TDZ, can't use before declaration) |
| Global Object | `var` attaches to `window` object | `let` does **not** attach to `window`              |

**1. Scope**

* `var` → Function-scoped: It is accessible anywhere inside the function it is declared in.
* `let` → Block-scoped: It is accessible only within the block (`{ }`) in which it is declared.

```js
function test() {
  if (true) {
    var x = 10;
    let y = 20;
  }
  console.log(x); // 10 → var is accessible
  console.log(y); // Error → let is block-scoped
}
```

**2. Redeclaration**

* `var` → Can be redeclared in the same scope without error.
* `let` → Cannot be redeclared in the same block.

```js
var a = 1;
var a = 2; // No error

let b = 1;
let b = 2; // Error: Identifier 'b' has already been declared
```

**3. Hoisting**

* Both `var` and `let` are hoisted to the top of their scope.
* But `var` is initialized as `undefined`, while `let` stays uninitialized and is in a **Temporal Dead Zone (TDZ)** until its declaration line.

```js
console.log(a); // undefined
var a = 5;

console.log(b); // Error: Cannot access 'b' before initialization
let b = 10;
```

**4. Global Object (in browsers)**

* `var` declared in the global scope becomes a property of `window`.
* `let` does **not** attach to `window`.

```js
var x = 100;
let y = 200;

console.log(window.x); // 100
console.log(window.y); // undefined
```

***

#### Function Scoped vs Block Scoped

**Function Scoped (`var`)**

* Scope is limited to the function where it is declared.
* Not limited inside blocks like `if`, `for`, etc.

```js
function test() {
  if (true) {
    var x = 10;
  }
  console.log(x); // 10
}
```

**Block Scoped (`let`, `const`)**

* Scope is limited to the block `{}` where declared.

```js
function test() {
  if (true) {
    let x = 10;
  }
  console.log(x); // ReferenceError
}
```

**Note:**

* **block can be inside a function**, but **function cannot be reliably inside a block** (in all cases).

**Block inside Function — allowed**

```js
function test() {
  if (true) {
    let x = 10; // block scoped
  }
}
```

**Function inside Block — not recommended**

```js
if (true) {
  function sayHi() {
    console.log("Hi");
  }
}
sayHi(); // ❌ May throw error in strict mode or some environments
```

**Safer Way (Use Function Expression)**

```js
if (true) {
  var sayHi = function() {
    console.log("Hi");
  }
}
sayHi(); // ✅ Works
```

***

#### `==` vs `===` in JavaScript

**`==` (Loose Equality / Abstract Equality)**

* **Compares values only** after **type coercion** (i.e., converts one or both operands to a common type before comparison).
* Can lead to unexpected results due to implicit type conversion.

```js
5 == '5'      // true → type coercion ('5' is converted to 5)
false == 0    // true → false is converted to 0
null == undefined // true → both considered equivalent
```

**`===` (Strict Equality)**

* **Compares both value and type** without type coercion.
* Only returns `true` if both the value and type are exactly the same.

```js
5 === '5'     // false → different types (number vs string)
false === 0   // false → different types (boolean vs number)
null === undefined // false → different types
```

**Note:** `is` in Python and `===` in Javascript are not same

* `is` in Python checks if two variables refer to the **same object in memory** (reference comparison),
* while `===` in JavaScript checks if both the **value and data type** are the same.

***

## Different types of Functions in Java Script

#### Types of Functions in JavaScript:

* **Function Declaration**: = Named

```javascript
function funcName() ... 
function funName() {...}

// Hoisted , Named Function,   Uses `function` keyword
```

* **Anonymous Function:** = No Named + No Expression X

```
function() {...} -> ❌ Not valid unless assigned to a variable
```

**Anonymous Function Expression**: = Expression

```js
const funVar = function() ... ✅
const funVar = function() { ...};✅

// Not Hoisted,  Anonymous Function, Assigned to a variable
```

* **Named Function Expression**: Named + Expression

```javascript
const funVar = function funcName() ...
const funVar = function funcName() { ...};

// Not Hoisted,  Named Function(Only accessible inside function scope
```

* **Arrow Function** : Arrow

```javascript
// Anonymous Arrow Function
() => ...
() => {...} 
// , Lexical `this` Binding
```

* **Arrow Function Expression** : Arrow + Expression

```javascript
// Assigned Arrow Function
const greet = () =>  ...
const greet = () => { ...} 
// Not Hoisted, Lexical `this` Binding
```

Note: **arrow functions**, the `return` keyword is **not needed** if the function consists of a **single expression** without curly braces `{}`. The result is **automatically returned**.

```js
const add = (a, b) => a + b; console.log(add(2, 3));
```

**Key Notes**

* **Hoisted :** you can use functions or variables before they are declared in your code, without causing an error.
* **Anonymous Function Expressions**: Have no name, so they rely on the variable they're assigned to.
* **Named Function Expressions**: Have a name, but it's only accessible within the function body itself.
* `this` Binding in Arrow Function. Unlike traditional functions where `this` refers to the object that called the function, Arrow functions not have their own `this` context. Instead, and `this` inside an arrow function refers to the `this` value of the enclosing lexical context (i.e., the scope in which the arrow function was defined).

***

#### Function Execution Behavior in JavaScript

**Functions Runs Immediately**

| **Type**                                           | **Code**                  | **Behavior**                                                                  |
| -------------------------------------------------- | ------------------------- | ----------------------------------------------------------------------------- |
| **Direct Function Call**                           | `handleClick();`          | **Runs immediately when encountered** : Executes instantly when script runs   |
| **Function Call in JSX/Event Listeners**           | `onClick={handleClick()}` | **Executes immediately if `()` used** : Executes as soon as component renders |
| **Immediately Invoked Function Expression (IIFE)** | `(function() {...})();`   | **Self-executing function** : Executes as soon as it's defined                |

**Functions Run Later (On an event)**

| **Type**                                           | **Code**                              | **Behavior**                                                                                  |
| -------------------------------------------------- | ------------------------------------- | --------------------------------------------------------------------------------------------- |
| **Function Reference (Event Handlers & JSX)**      | `onClick={handleClick}`               | **Executed later (on event)** : Passed as reference, executes on event                        |
| **Function with Arguments in JSX/Event Listeners** | `onClick={() => handleClick("John")}` | **Wrapped inside an arrow function to delay execution** : Function executed only when clicked |

**Note:**

* **IIFE (`(function() {...})();`)** i.e. wrapping function in `()` runs immediately without an explicit call.\*\*
* **Use `funcName()` when you need immediate execution.**
* **Use `funcName` (without `()`) when passing as a reference for later execution.**
* **Use `() => funcName(arg)` when you need to pass arguments but execute later.**
* **React JSX follows JavaScript function execution rules.**

***

#### Call back Functions

**Callback Function?** -> A **callback function** is a function passed as an argument to another function and executed later, usually after an operation completes or an event occurs.

```javascript
function greet(name, callback) {
  console.log(`Hello, ${name}!`);
  callback(); // Call the callback function
}
```

**Asynchronous Callback (setTimeout Example)**

```javascript
function fetchData(callback) {
  setTimeout(() => {
    const data = "Data fetched successfully";
    callback(data);
  }, 2000); // Simulates an API call delay
}
// `processData` is executed **after** `fetchData` completes.
```

**Event Listener Callback**

```javascript
document.getElementById("myButton").addEventListener("click", function() {
  alert("Button clicked!");
});
// The **anonymous function** is executed **when the event occurs**.
```

**Key Takeaways**

* **Callbacks allow functions to run after another function completes.**
* **Used heavily in event handling & asynchronous operations.**
* **Synchronous callbacks run immediately, while asynchronous ones wait for execution.**
* **Avoid callback hell by using Promises or async/await.**

***
