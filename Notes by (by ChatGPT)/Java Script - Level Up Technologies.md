<hr>

`24/6/2024 Monday` 
# Overview of OOP's 

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects," which can contain data and code: data in the form of fields (often known as attributes or properties), and code in the form of procedures (often known as methods).

#### Key Concepts of OOP:

1. **Classes and Objects**
2. **Inheritance**
3. **Encapsulation**
4. **Polymorphism**
5. **Abstraction**

#### 1. Classes and Objects

- **Class**: A blueprint for creating objects. It defines a type of object according to the methods and properties that characterize the object.
- **Object**: An instance of a class. It is a collection of data (properties) and methods (functions).

```javascript
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
  }
}

const person1 = new Person('Alice', 30);
person1.greet(); // Hello, my name is Alice and I am 30 years old.
```

#### 2. Inheritance

- Inheritance is a mechanism where one class can inherit the properties and methods of another class.
- The class that inherits is called the **subclass** or **derived class**, and the class being inherited from is called the **superclass** or **base class**.

```javascript
class Animal {
  constructor(name) {
    this.name = name;
  }

  speak() {
    console.log(`${this.name} makes a noise.`);
  }
}

class Dog extends Animal {
  speak() {
    console.log(`${this.name} barks.`);
  }
}

const dog = new Dog('Rex');
dog.speak(); // Rex barks.
```

#### 3. Encapsulation

- Encapsulation is the bundling of data and methods that operate on the data within one unit, e.g., a class in JavaScript.
- It restricts direct access to some of the object’s components, which is a means of preventing accidental interference and misuse of the data.

```javascript
class Car {
  constructor(model, year) {
    this.model = model;
    this.year = year;
    let mileage = 0; // private variable

    this.drive = function(distance) {
      mileage += distance;
      console.log(`Driven ${distance} miles. Total mileage: ${mileage}`);
    };
  }
}

const myCar = new Car('Toyota', 2021);
myCar.drive(50); // Driven 50 miles. Total mileage: 50
console.log(myCar.mileage); // undefined (private variable)
```

#### 4. Polymorphism

- Polymorphism means "many forms," and it allows methods to do different things based on the object it is acting upon.
- It is typically implemented through method overriding.

```javascript
class Bird {
  fly() {
    console.log('The bird is flying.');
  }
}

class Eagle extends Bird {
  fly() {
    console.log('The eagle is soaring.');
  }
}

const bird = new Bird();
const eagle = new Eagle();

bird.fly();  // The bird is flying.
eagle.fly(); // The eagle is soaring.
```

#### 5. Abstraction

- Abstraction is the concept of hiding the complex implementation details and showing only the essential features of the object.
- It is achieved through abstract classes and interfaces (in languages like TypeScript) but can be simulated in JavaScript using simpler constructs.

```javascript
class Human {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  getDetails() {
    return `${this.name}, ${this.age} years old`;
  }
}

const human1 = new Human('John', 25);
console.log(human1.getDetails()); // John, 25 years old
```

### Advantages of OOP:

1. **Modularity**: The source code for a class can be written and maintained independently of the source code for other classes.
2. **Reusability**: Classes can be reused in other programs.
3. **Scalability**: With OOP, it's easier to manage large applications.
4. **Maintainability**: The modularity of OOP makes it easier to maintain and update code.

By understanding and using these OOP principles, JavaScript developers can create more structured, modular, and scalable code.

<hr>

`25/6/2024 Tuesday`
# Overview of Javascript

JavaScript is a versatile, high-level, interpreted programming language primarily used to create interactive effects within web browsers. It is one of the core technologies of the World Wide Web, alongside HTML and CSS.

#### Key Features of JavaScript:

1. **Dynamically Typed**
   - Variables do not require explicit declarations. Types are inferred at runtime.

```javascript
let message = "Hello, World!";
message = 42; // Dynamically changes type
```

2. **Interpreted Language**
   - JavaScript code is executed line by line by the browser’s JavaScript engine or a Node.js runtime.

3. **First-Class Functions**
   - Functions are treated as first-class citizens, meaning they can be assigned to variables, passed as arguments, and returned from other functions.

```javascript
const greet = function(name) {
  return `Hello, ${name}!`;
};
```

4. **Event-Driven**
   - JavaScript is heavily used for event handling, such as user interactions (clicks, mouse movements).

```javascript
document.getElementById("myButton").addEventListener("click", function() {
  alert("Button clicked!");
});
```

5. **Asynchronous and Single-Threaded**
   - JavaScript uses asynchronous programming with callbacks, promises, and async/await to handle operations like HTTP requests and timers without blocking the main thread.

```javascript
async function fetchData() {
  try {
    let response = await fetch('https://api.example.com/data');
    let data = await response.json();
    console.log(data);
  } catch (error) {
    console.error('Error:', error);
  }
}
```

6. **Object-Oriented**
   - Supports object-oriented programming with prototypes and ES6 classes.

```javascript
class Animal {
  constructor(name) {
    this.name = name;
  }
  
  speak() {
    console.log(`${this.name} makes a noise.`);
  }
}

const dog = new Animal('Dog');
dog.speak();
```

7. **Closures**
   - Functions have access to the scope in which they were defined, even after that scope has finished executing.

```javascript
function createCounter() {
  let count = 0;
  return function() {
    count++;
    return count;
  };
}

const counter = createCounter();
console.log(counter()); // 1
console.log(counter()); // 2
```

#### Key JavaScript Concepts:

1. **Variables and Data Types**
   - `var`, `let`, `const` for variable declarations.
   - Data types: `String`, `Number`, `Boolean`, `Object`, `Array`, `Null`, `Undefined`, `Symbol`.

```javascript
let age = 25;
const name = "Alice";
```

2. **Functions**
   - Functions can be declared with the `function` keyword or using arrow syntax (`=>`).

```javascript
function sum(a, b) {
  return a + b;
}

const multiply = (a, b) => a * b;
```

3. **Objects and Arrays**
   - Objects are collections of key-value pairs.
   - Arrays are ordered lists of values.

```javascript
const person = {
  name: "Alice",
  age: 25
};

const numbers = [1, 2, 3, 4];
```

4. **DOM Manipulation**
   - JavaScript can interact with the HTML DOM to manipulate web page content and structure.

```javascript
document.getElementById("myElement").innerText = "Hello, JavaScript!";
```

5. **Event Handling**
   - JavaScript can respond to user events like clicks, key presses, and mouse movements.

```javascript
document.querySelector("button").addEventListener("click", function() {
  alert("Button clicked!");
});
```

6. **Promises and Async/Await**
   - Handle asynchronous operations more effectively.

```javascript
fetch('https://api.example.com/data')
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));

async function getData() {
  try {
    let response = await fetch('https://api.example.com/data');
    let data = await response.json();
    console.log(data);
  } catch (error) {
    console.error('Error:', error);
  }
}
```

7. **ES6+ Features**
   - Includes new syntax and features like destructuring, template literals, spread/rest operators, and classes.

```javascript
const { name, age } = person;
const greeting = `Hello, ${name}! You are ${age} years old.`;
```

### Conclusion

JavaScript is a powerful and essential language for web development, enabling developers to create dynamic, interactive, and responsive web applications. Its continuous evolution, along with a rich ecosystem of frameworks and libraries, makes it a key technology for modern software development.

<hr>

`26/6/2024 Wednesday`
# Data Type and Variables in JS

#### Data Types

JavaScript has several fundamental data types:

1. **Number**
   - Represents both integer and floating-point numbers.
   - Includes special values: `Infinity`, `-Infinity`, and `NaN` (Not-a-Number).

```javascript
let age = 30;            // Integer
let temperature = 36.6;  // Floating-point
let infinityValue = Infinity;
let notANumber = NaN;
```

2. **String**
   - Represents textual data.
   - Can be enclosed in single quotes (`'`), double quotes (`"`), or backticks (`` ` ``) for template literals.

```javascript
let name = "Alice";
let greeting = 'Hello, World!';
let message = `Hello, ${name}!`;  // Template literal
```

3. **Boolean**
   - Represents logical entities: `true` and `false`.

```javascript
let isStudent = true;
let hasGraduated = false;
```

4. **Undefined**
   - A variable that has been declared but not assigned a value.

```javascript
let myVar;
console.log(myVar);  // undefined
```

5. **Null**
   - Represents the intentional absence of any object value.

```javascript
let emptyValue = null;
```

6. **Symbol**
   - A unique and immutable data type, often used to identify object properties uniquely.

```javascript
let sym = Symbol('description');
```

7. **Object**
   - A collection of properties, each with a key (string or Symbol) and a value (any type).

```javascript
let person = {
  name: "Alice",
  age: 25,
  isStudent: true
};
```

8. **BigInt**
   - Represents whole numbers larger than the `Number` type can safely store.

```javascript
let bigNumber = BigInt(9007199254740991);
```

#### Variables

JavaScript uses three keywords to declare variables: `var`, `let`, and `const`.

1. **var**
   - Function-scoped or globally-scoped.
   - Can be re-declared and updated.

```javascript
var x = 10;
var x = 20;  // Allowed
x = 30;     // Allowed
```

2. **let**
   - Block-scoped.
   - Can be updated but not re-declared within the same scope.

```javascript
let y = 10;
// let y = 20;  // Error: Identifier 'y' has already been declared
y = 20;      // Allowed
```

3. **const**
   - Block-scoped.
   - Cannot be updated or re-declared.
   - Must be initialized at the time of declaration.

```javascript
const z = 10;
// z = 20;    // Error: Assignment to constant variable
```

#### Variable Scope

1. **Global Scope**
   - Variables declared outside of any function have global scope.

```javascript
var globalVar = "I am global";
```

2. **Function Scope**
   - Variables declared within a function are local to that function.

```javascript
function myFunction() {
  var localVar = "I am local";
  console.log(localVar);  // I am local
}
// console.log(localVar);  // Error: localVar is not defined
```

3. **Block Scope**
   - Variables declared with `let` or `const` within a block `{}` are local to that block.

```javascript
if (true) {
  let blockVar = "I am block scoped";
  console.log(blockVar);  // I am block scoped
}
// console.log(blockVar);  // Error: blockVar is not defined
```

#### Hoisting

- JavaScript hoists variable declarations (not initializations) to the top of their scope.

```javascript
console.log(hoistedVar);  // undefined
var hoistedVar = "I am hoisted";

// console.log(notHoisted);  // Error: Cannot access 'notHoisted' before initialization
let notHoisted = "I am not hoisted";
```

#### Best Practices

1. **Use `const` by default**: For variables that should not change.
2. **Use `let` for variables that will change**: Ensures block scope and avoids issues with hoisting.
3. **Avoid `var`**: To prevent scope-related bugs and unintended re-declarations.

By understanding and effectively utilizing JavaScript's data types and variable declarations, developers can write more predictable, maintainable, and error-free code.

<hr>

`27/6/2024 Thursday`
# Operators in Javascript

JavaScript provides a rich set of operators to perform operations on variables and values. These operators can be broadly categorized into several types:

#### 1. Arithmetic Operators

Used to perform basic arithmetic operations.

```javascript
let a = 10;
let b = 5;

console.log(a + b);  // Addition: 15
console.log(a - b);  // Subtraction: 5
console.log(a * b);  // Multiplication: 50
console.log(a / b);  // Division: 2
console.log(a % b);  // Modulus: 0 (remainder)
console.log(a ** b); // Exponentiation: 100000
```

#### 2. Assignment Operators

Used to assign values to variables. Includes shorthand assignment operators.

```javascript
let x = 10;
x += 5;  // Equivalent to x = x + 5
console.log(x); // 15

x -= 3;  // Equivalent to x = x - 3
console.log(x); // 12

x *= 2;  // Equivalent to x = x * 2
console.log(x); // 24

x /= 4;  // Equivalent to x = x / 4
console.log(x); // 6

x %= 3;  // Equivalent to x = x % 3
console.log(x); // 0
```

#### 3. Comparison Operators

Used to compare two values, returning a boolean result.

```javascript
let m = 10;
let n = 5;

console.log(m == n);  // Equality: false
console.log(m != n);  // Inequality: true
console.log(m === 10); // Strict equality: true
console.log(m !== '10'); // Strict inequality: true
console.log(m > n);  // Greater than: true
console.log(m < n);  // Less than: false
console.log(m >= n); // Greater than or equal to: true
console.log(m <= n); // Less than or equal to: false
```

#### 4. Logical Operators

Used to combine multiple Boolean expressions.

```javascript
let p = true;
let q = false;

console.log(p && q);  // Logical AND: false
console.log(p || q);  // Logical OR: true
console.log(!p);      // Logical NOT: false
```

#### 5. Unary Operators

Operate on a single operand.

```javascript
let num = 10;

console.log(-num);    // Unary negation: -10
console.log(++num);   // Unary increment: 11
console.log(--num);   // Unary decrement: 10
console.log(!true);   // Logical NOT: false
```

#### 6. Ternary Operator

A shorthand for `if-else` statements.

```javascript
let age = 18;
let beverage = (age >= 18) ? 'Alcohol' : 'Juice';
console.log(beverage); // Alcohol
```

#### 7. String Operators

Used for string concatenation.

```javascript
let firstName = "John";
let lastName = "Doe";

console.log(firstName + ' ' + lastName); // Concatenation: "John Doe"
```

#### 8. Conditional (Ternary) Operator

A concise way to perform `if-else` logic.

```javascript
let age = 20;
let drink = (age >= 18) ? "Alcohol" : "Juice";
console.log(drink); // Alcohol
```

#### 9. Bitwise Operators

Operate on bits and perform bit-level operations.

```javascript
let x = 5;  // 0101 in binary
let y = 3;  // 0011 in binary

console.log(x & y); // Bitwise AND: 1 (0001)
console.log(x | y); // Bitwise OR: 7 (0111)
console.log(x ^ y); // Bitwise XOR: 6 (0110)
console.log(~x);    // Bitwise NOT: -6 (inverts bits)
console.log(x << 1); // Left shift: 10 (1010)
console.log(x >> 1); // Right shift: 2 (0010)
```

#### 10. Type Operators

Used to check the type of a variable.

```javascript
let num = 42;
console.log(typeof num);     // "number"
console.log(typeof "Hello"); // "string"
console.log(typeof true);    // "boolean"
console.log(Array.isArray([])); // true
```

#### 11. Spread and Rest Operators

- **Spread Operator (`...`)**: Expands elements of an iterable.
- **Rest Operator (`...`)**: Collects multiple elements into an array.

```javascript
// Spread Operator
let arr1 = [1, 2, 3];
let arr2 = [...arr1, 4, 5];
console.log(arr2); // [1, 2, 3, 4, 5]

// Rest Operator
function sum(...numbers) {
  return numbers.reduce((total, num) => total + num, 0);
}
console.log(sum(1, 2, 3, 4)); // 10
```

### Summary

JavaScript’s operators are powerful tools for performing various operations on values and variables. Understanding how to use them effectively is crucial for writing clean, concise, and efficient code.

<hr>

`28/6/2024 Friday`
# Functions and Objects in JavaScript 

JavaScript functions and objects are fundamental building blocks of the language. Here’s an in-depth look at each:

### Functions

Functions are reusable blocks of code designed to perform specific tasks. They can take inputs (parameters) and return outputs.

#### 1. Function Declaration

A traditional way to define a function.

```javascript
function greet(name) {
  return `Hello, ${name}!`;
}

console.log(greet("Alice")); // Hello, Alice!
```

#### 2. Function Expression

A function defined within a variable. Can be anonymous.

```javascript
const square = function(x) {
  return x * x;
};

console.log(square(4)); // 16
```

#### 3. Arrow Functions

Introduced in ES6, arrow functions provide a concise syntax.

```javascript
const add = (a, b) => a + b;
console.log(add(3, 4)); // 7
```

#### 4. Immediately Invoked Function Expression (IIFE)

A function that runs as soon as it is defined.

```javascript
(function() {
  console.log("This function runs immediately!");
})();
```

#### 5. Function Parameters and Arguments

- **Parameters** are the named variables listed in the function definition.
- **Arguments** are the actual values passed to the function.

```javascript
function multiply(a, b) {
  return a * b;
}

console.log(multiply(2, 3)); // 6
```

#### 6. Default Parameters

Parameters with default values.

```javascript
function greet(name = "Guest") {
  return `Hello, ${name}!`;
}

console.log(greet()); // Hello, Guest!
console.log(greet("Bob")); // Hello, Bob!
```

#### 7. Rest Parameters

Collect multiple function arguments into an array.

```javascript
function sum(...numbers) {
  return numbers.reduce((total, num) => total + num, 0);
}

console.log(sum(1, 2, 3, 4)); // 10
```

#### 8. Scope and Closures

- **Scope** defines the visibility of variables.
- **Closures** allow functions to retain access to their lexical scope, even when called outside that scope.

```javascript
function createCounter() {
  let count = 0;
  return function() {
    count++;
    return count;
  };
}

const counter = createCounter();
console.log(counter()); // 1
console.log(counter()); // 2
```

### Objects

Objects are collections of key-value pairs. They are used to store and manage data.

#### 1. Creating Objects

- Using object literals.

```javascript
const person = {
  name: "Alice",
  age: 25,
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};

console.log(person.name); // Alice
person.greet(); // Hello, my name is Alice
```

#### 2. Constructor Function

A blueprint for creating objects.

```javascript
function Person(name, age) {
  this.name = name;
  this.age = age;
  this.greet = function() {
    console.log(`Hello, my name is ${this.name}`);
  };
}

const person1 = new Person("Bob", 30);
person1.greet(); // Hello, my name is Bob
```

#### 3. ES6 Class Syntax

A syntactic sugar over constructor functions.

```javascript
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
}

const person1 = new Person("Charlie", 40);
person1.greet(); // Hello, my name is Charlie
```

#### 4. Object Methods

Functions stored as properties of an object.

```javascript
const person = {
  name: "Alice",
  age: 25,
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};

person.greet(); // Hello, my name is Alice
```

#### 5. Object Properties

Properties can be added or modified dynamically.

```javascript
const person = {
  name: "Alice",
  age: 25
};

person.email = "alice@example.com";
console.log(person); // { name: 'Alice', age: 25, email: 'alice@example.com' }
```

#### 6. Object Destructuring

Extract values from objects into variables.

```javascript
const { name, age } = person;
console.log(name, age); // Alice 25
```

#### 7. Spread Operator with Objects

Create copies or merge objects.

```javascript
const person = { name: "Alice", age: 25 };
const personCopy = { ...person };

console.log(personCopy); // { name: 'Alice', age: 25 }
```

#### 8. Object Methods and `this`

In ES6 classes, `this` refers to the current instance.

```javascript
class Person {
  constructor(name) {
    this.name = name;
  }

  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
}

const person1 = new Person("Alice");
person1.greet(); // Hello, my name is Alice
```

### Conclusion

Functions and objects are essential to JavaScript. Functions help encapsulate behavior, while objects help structure and manage data. Understanding these concepts allows for more effective and efficient code development.

<hr>

`1/7/2024 Monday`
# Events and Strings Method in JavaScript


JavaScript's event handling and string manipulation are crucial for building interactive and dynamic web applications. Let's delve into these topics:

## Events in JavaScript

Events are actions or occurrences that happen in the system you’re programming, which the system tells you about so your code can respond to them. Common events include user interactions such as clicks, key presses, mouse movements, and more.

### 1. Event Handling Basics

JavaScript handles events using event listeners. An event listener is a procedure that waits for an event to occur and then executes a callback function.

```javascript
document.getElementById("myButton").addEventListener("click", function() {
  alert("Button clicked!");
});
```

### 2. Common Event Types

- **Click**: Triggered when an element is clicked.
- **Mouseover**: Triggered when the mouse pointer enters an element.
- **Mouseout**: Triggered when the mouse pointer leaves an element.
- **Keydown**: Triggered when a key is pressed down.
- **Keyup**: Triggered when a key is released.
- **Submit**: Triggered when a form is submitted.

### 3. Example: Handling Click and Key Events

```html
<button id="myButton">Click Me!</button>
<input type="text" id="myInput" placeholder="Type something...">

<script>
  // Click event
  document.getElementById("myButton").addEventListener("click", function() {
    alert("Button was clicked!");
  });

  // Keyup event
  document.getElementById("myInput").addEventListener("keyup", function(event) {
    console.log(`Key ${event.key} was pressed`);
  });
</script>
```

### 4. Event Object

The event object contains information about the event that occurred. It can be accessed within the event handler.

```javascript
document.getElementById("myButton").addEventListener("click", function(event) {
  console.log("Event type:", event.type);
  console.log("Clicked element:", event.target);
});
```

### 5. Event Delegation

A technique to manage events efficiently by using a single event listener to manage events for multiple child elements.

```html
<ul id="myList">
  <li>Item 1</li>
  <li>Item 2</li>
  <li>Item 3</li>
</ul>

<script>
  document.getElementById("myList").addEventListener("click", function(event) {
    if (event.target.tagName === "LI") {
      alert("You clicked on " + event.target.textContent);
    }
  });
</script>
```

## String Methods in JavaScript

Strings in JavaScript are sequences of characters. JavaScript provides numerous methods to manipulate and work with strings.

### 1. Basic String Methods

- **Length Property**: Returns the length of the string.

```javascript
let str = "Hello, World!";
console.log(str.length); // 13
```

- **Accessing Characters**: Use bracket notation or `charAt()` method.

```javascript
console.log(str[0]);       // H
console.log(str.charAt(0)); // H
```

### 2. Common String Methods

- **Concatenation**: Combine strings.

```javascript
let str1 = "Hello";
let str2 = "World";
let greeting = str1 + ", " + str2 + "!";
console.log(greeting); // Hello, World!
```

- **toUpperCase() and toLowerCase()**: Convert case.

```javascript
console.log(str.toUpperCase()); // HELLO, WORLD!
console.log(str.toLowerCase()); // hello, world!
```

- **trim()**: Remove whitespace from both ends.

```javascript
let strWithSpaces = "  Hello, World!  ";
console.log(strWithSpaces.trim()); // "Hello, World!"
```

- **substring() and slice()**: Extract parts of a string.

```javascript
console.log(str.substring(0, 5)); // Hello
console.log(str.slice(7));        // World!
```

- **split()**: Split a string into an array of substrings.

```javascript
let sentence = "This is a test.";
let words = sentence.split(" ");
console.log(words); // ["This", "is", "a", "test."]
```

- **replace()**: Replace a substring with another.

```javascript
let text = "Hello, World!";
let newText = text.replace("World", "JavaScript");
console.log(newText); // Hello, JavaScript!
```

- **includes()**: Check if a string contains a substring.

```javascript
console.log(str.includes("World")); // true
console.log(str.includes("Java"));  // false
```

- **indexOf() and lastIndexOf()**: Find the position of a substring.

```javascript
console.log(str.indexOf("World"));     // 7
console.log(str.lastIndexOf("o"));     // 8
```

### 3. Template Literals

Introduced in ES6, template literals allow for multi-line strings and embedded expressions.

```javascript
let name = "Alice";
let age = 25;
let message = `Hello, my name is ${name} and I am ${age} years old.`;
console.log(message); // Hello, my name is Alice and I am 25 years old.
```

### 4. String Iteration

Use `for...of` to iterate over characters in a string.

```javascript
for (let char of str) {
  console.log(char);
}
```

### 5. String Conversion Methods

- **toString()**: Convert other data types to strings.

```javascript
let num = 123;
console.log(num.toString()); // "123"
```

### Conclusion

Understanding events and string methods in JavaScript is essential for building interactive web applications and manipulating text data effectively. Whether you're handling user interactions or performing complex string manipulations, these concepts are fundamental to JavaScript development.

<hr>

`4/7/2024 Thursday`
# Conditional statements and switch case in JavaScript

### **Conditional Statements in JavaScript**

Conditional statements allow you to execute different code blocks based on different conditions. In JavaScript, the most common conditional statements are `if`, `else if`, `else`, and `switch`.

#### **1. `if` Statement**

The `if` statement evaluates a condition (an expression that returns `true` or `false`). If the condition is `true`, the block of code inside the `if` statement is executed.

**Syntax:**

```javascript
if (condition) {
    // Code to execute if the condition is true
}
```

**Example:**

```javascript
let number = 10;

if (number > 5) {
    console.log("Number is greater than 5");
}
```

#### **2. `if...else` Statement**

The `if...else` statement executes one block of code if the condition is `true`, and another block of code if the condition is `false`.

**Syntax:**

```javascript
if (condition) {
    // Code to execute if the condition is true
} else {
    // Code to execute if the condition is false
}
```

**Example:**

```javascript
let number = 3;

if (number > 5) {
    console.log("Number is greater than 5");
} else {
    console.log("Number is 5 or less");
}
```

#### **3. `if...else if...else` Statement**

This allows you to check multiple conditions. If the first condition is `false`, the next condition is evaluated, and so on.

**Syntax:**

```javascript
if (condition1) {
    // Code to execute if condition1 is true
} else if (condition2) {
    // Code to execute if condition2 is true
} else {
    // Code to execute if none of the conditions are true
}
```

**Example:**

```javascript
let number = 7;

if (number > 10) {
    console.log("Number is greater than 10");
} else if (number > 5) {
    console.log("Number is greater than 5 but less than or equal to 10");
} else {
    console.log("Number is 5 or less");
}
```

### **Switch Statement**

The `switch` statement is used to perform different actions based on different conditions. It is often used as an alternative to `if...else if...else` when there are multiple possible conditions.

**Syntax:**

```javascript
switch (expression) {
    case value1:
        // Code to execute if expression equals value1
        break;
    case value2:
        // Code to execute if expression equals value2
        break;
    // More cases...
    default:
        // Code to execute if none of the cases match
}
```

**Example:**

```javascript
let fruit = "apple";

switch (fruit) {
    case "apple":
        console.log("It's an apple");
        break;
    case "banana":
        console.log("It's a banana");
        break;
    case "orange":
        console.log("It's an orange");
        break;
    default:
        console.log("Unknown fruit");
}
```

#### **Key Points**

- **`if` Statement**: Used for simple condition checks.
- **`if...else` Statement**: Handles a binary choice.
- **`if...else if...else` Statement**: Handles multiple conditions.
- **`switch` Statement**: Best for handling multiple discrete values.

#### **Using `switch` with `break` and `default`**

- **`break`**: Prevents the execution of subsequent cases once a match is found.
- **`default`**: Specifies the code to run if no cases match the expression.

### **Summary**

- Use `if` statements for basic condition checking.
- Use `if...else` for binary choices.
- Use `if...else if...else` for multiple conditions.
- Use `switch` for multiple discrete values.

These conditional constructs are fundamental for controlling the flow of your JavaScript programs.

<hr>

`5/7/2024 Friday`
# Arrays Methods, Dates, Math, Random and Booleans

JavaScript provides a rich set of features for manipulating arrays, working with dates and times, performing mathematical operations, generating random values, and handling Boolean logic. Let's explore these topics in detail.

## Array Methods

JavaScript arrays come with a variety of built-in methods that simplify array manipulation. Here are some commonly used array methods:

### 1. **Creating and Initializing Arrays**

```javascript
let fruits = ["Apple", "Banana", "Cherry"];
let numbers = new Array(1, 2, 3, 4, 5);
```

### 2. **Array Methods**

- **push()**: Adds one or more elements to the end of an array.

```javascript
let fruits = ["Apple", "Banana"];
fruits.push("Cherry");
console.log(fruits); // ["Apple", "Banana", "Cherry"]
```

- **pop()**: Removes the last element from an array and returns it.

```javascript
let fruits = ["Apple", "Banana", "Cherry"];
let lastFruit = fruits.pop();
console.log(lastFruit); // "Cherry"
console.log(fruits);    // ["Apple", "Banana"]
```

- **shift()**: Removes the first element from an array and returns it.

```javascript
let fruits = ["Apple", "Banana", "Cherry"];
let firstFruit = fruits.shift();
console.log(firstFruit); // "Apple"
console.log(fruits);     // ["Banana", "Cherry"]
```

- **unshift()**: Adds one or more elements to the beginning of an array.

```javascript
let fruits = ["Banana", "Cherry"];
fruits.unshift("Apple");
console.log(fruits); // ["Apple", "Banana", "Cherry"]
```

- **concat()**: Merges two or more arrays.

```javascript
let arr1 = [1, 2, 3];
let arr2 = [4, 5, 6];
let combined = arr1.concat(arr2);
console.log(combined); // [1, 2, 3, 4, 5, 6]
```

- **slice()**: Returns a shallow copy of a portion of an array.

```javascript
let fruits = ["Apple", "Banana", "Cherry", "Date"];
let citrus = fruits.slice(1, 3);
console.log(citrus); // ["Banana", "Cherry"]
```

- **splice()**: Adds or removes elements from an array.

```javascript
let fruits = ["Apple", "Banana", "Cherry"];
fruits.splice(1, 1, "Blueberry");
console.log(fruits); // ["Apple", "Blueberry", "Cherry"]
```

- **forEach()**: Executes a function on each element of an array.

```javascript
let numbers = [1, 2, 3];
numbers.forEach((number) => {
  console.log(number);
});
// Output:
// 1
// 2
// 3
```

- **map()**: Creates a new array with the results of calling a function on every element.

```javascript
let numbers = [1, 2, 3];
let squares = numbers.map(x => x * x);
console.log(squares); // [1, 4, 9]
```

- **filter()**: Creates a new array with elements that pass a test.

```javascript
let numbers = [1, 2, 3, 4, 5];
let evens = numbers.filter(x => x % 2 === 0);
console.log(evens); // [2, 4]
```

- **reduce()**: Executes a reducer function on each element of the array, resulting in a single value.

```javascript
let numbers = [1, 2, 3, 4];
let sum = numbers.reduce((acc, current) => acc + current, 0);
console.log(sum); // 10
```

- **find()**: Returns the first element that passes a test.

```javascript
let numbers = [1, 2, 3, 4, 5];
let found = numbers.find(x => x > 3);
console.log(found); // 4
```

- **findIndex()**: Returns the index of the first element that passes a test.

```javascript
let numbers = [1, 2, 3, 4, 5];
let index = numbers.findIndex(x => x > 3);
console.log(index); // 3
```

- **includes()**: Checks if an array contains a specified element.

```javascript
let fruits = ["Apple", "Banana", "Cherry"];
console.log(fruits.includes("Banana")); // true
console.log(fruits.includes("Mango"));  // false
```

## Dates in JavaScript

JavaScript's `Date` object is used to work with dates and times.

### 1. Creating Date Objects

```javascript
let now = new Date();
console.log(now); // Current date and time

let specificDate = new Date('2024-07-27');
console.log(specificDate); // Specific date
```

### 2. Date Methods

- **getDate()**: Returns the day of the month.

```javascript
let date = new Date();
console.log(date.getDate()); // Current day of the month
```

- **getDay()**: Returns the day of the week (0 = Sunday, 6 = Saturday).

```javascript
let date = new Date();
console.log(date.getDay()); // Day of the week
```

- **getFullYear()**: Returns the four-digit year.

```javascript
let date = new Date();
console.log(date.getFullYear()); // Year
```

- **getHours()**, **getMinutes()**, **getSeconds()**: Return hours, minutes, and seconds.

```javascript
let date = new Date();
console.log(date.getHours());   // Hours
console.log(date.getMinutes()); // Minutes
console.log(date.getSeconds()); // Seconds
```

- **setDate()**, **setFullYear()**, **setHours()**: Set the date, year, and time.

```javascript
let date = new Date();
date.setFullYear(2025);
console.log(date.getFullYear()); // 2025
```

### 3. Formatting Dates

```javascript
let now = new Date();
console.log(now.toLocaleDateString()); // e.g., "7/27/2024"
console.log(now.toLocaleTimeString()); // e.g., "2:30:00 PM"
```

## Math Object

JavaScript's `Math` object provides a set of methods for mathematical constants and functions.

### 1. Common Math Methods

- **Math.PI**: The value of π (pi).

```javascript
console.log(Math.PI); // 3.14159
```

- **Math.abs()**: Returns the absolute value of a number.

```javascript
console.log(Math.abs(-5)); // 5
```

- **Math.round()**: Rounds a number to the nearest integer.

```javascript
console.log(Math.round(4.7)); // 5
console.log(Math.round(4.4)); // 4
```

- **Math.ceil()**: Rounds a number up to the nearest integer.

```javascript
console.log(Math.ceil(4.1)); // 5
```

- **Math.floor()**: Rounds a number down to the nearest integer.

```javascript
console.log(Math.floor(4.9)); // 4
```

- **Math.max() and Math.min()**: Return the maximum and minimum values.

```javascript
console.log(Math.max(1, 2, 3, 4)); // 4
console.log(Math.min(1, 2, 3, 4)); // 1
```

- **Math.random()**: Returns a random number between 0 (inclusive) and 1 (exclusive).

```javascript
console.log(Math.random()); // Random number between 0 and 1
```

- **Math.pow()**: Returns the base to the exponent power.

```javascript
console.log(Math.pow(2, 3)); // 8
```

- **Math.sqrt()**: Returns the square root of a number.

```javascript
console.log(Math.sqrt(16)); // 4
```

## Random Numbers

Generating random numbers is crucial for various applications, such as simulations and games.

### 1. Generating Random Numbers

- **Math.random()** generates a number between 0 and 1.

```javascript
let randomNumber = Math.random();
console.log(randomNumber);
```

- **Generating a random integer between min and max (inclusive)**:

```javascript
function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

console.log(getRandomInt(1, 100)); // Random integer between 1 and 100
```

## Booleans in JavaScript

Booleans represent a logical entity and can have two values: `true` and `false`.

### 1. Boolean Values and Operators

```javascript
let isJavaScriptFun = true;
let isFishTasty = false;

console.log(isJavaScriptFun); // true
console.log(isFishTasty);     // false
```

### 2. Logical Operators

- **AND (&&)**: Returns `true` if both operands are true.

```javascript
console.log(true && true);  // true
console.log(true && false); // false
```

- **OR (||)**

: Returns `true` if at least one operand is true.

```javascript
console.log(true || false); // true
console.log(false || false);// false
```

- **NOT (!)**: Inverts the boolean value.

```javascript
console.log(!true);  // false
console.log(!false); // true
```

### 3. Comparison Operators

Comparison operators return a Boolean value based on the comparison.

- **Equality (`==`)**: Checks for equality, type coercion may occur.

```javascript
console.log(5 == '5'); // true
```

- **Strict Equality (`===`)**: Checks for equality without type coercion.

```javascript
console.log(5 === '5'); // false
```

- **Inequality (`!=`)**: Checks for inequality, type coercion may occur.

```javascript
console.log(5 != '5'); // false
```

- **Strict Inequality (`!==`)**: Checks for inequality without type coercion.

```javascript
console.log(5 !== '5'); // true
```

- **Greater than (`>`)** and **Less than (`<`)**:

```javascript
console.log(10 > 5);  // true
console.log(5 < 10);  // true
```

- **Greater than or equal to (`>=`)** and **Less than or equal to (`<=`)**:

```javascript
console.log(10 >= 5); // true
console.log(5 <= 10); // true
```

### Conclusion

Understanding array methods, dates, math functions, random number generation, and Boolean logic is essential for effective JavaScript programming. These features enable you to manipulate data, handle dates and times, perform calculations, generate random values, and manage logical conditions efficiently.

<hr>

`11/7/2024 Thursday`
# Loops and Functions in JavaScript


JavaScript loops and functions are fundamental for controlling the flow of your program and for reusing code. Let's dive into these concepts.

## Loops in JavaScript

Loops allow you to execute a block of code multiple times. JavaScript provides several types of loops:

### 1. **For Loop**

The `for` loop repeats a block of code a known number of times.

```javascript
for (let i = 0; i < 5; i++) {
  console.log(`Iteration: ${i}`);
}
```

- **Initialization**: `let i = 0` (set up loop variable).
- **Condition**: `i < 5` (continue loop as long as the condition is true).
- **Increment/Decrement**: `i++` (increase `i` by 1 after each iteration).

### 2. **While Loop**

The `while` loop executes a block of code as long as a specified condition is true.

```javascript
let i = 0;
while (i < 5) {
  console.log(`Iteration: ${i}`);
  i++;
}
```

- **Condition**: `i < 5` (loop continues as long as the condition is true).

### 3. **Do...While Loop**

The `do...while` loop executes a block of code once, and then repeats the loop as long as a specified condition is true.

```javascript
let i = 0;
do {
  console.log(`Iteration: ${i}`);
  i++;
} while (i < 5);
```

- **Execution**: Executes the code block at least once before checking the condition.

### 4. **For...of Loop**

The `for...of` loop is used to iterate over iterable objects (e.g., arrays, strings).

```javascript
let fruits = ["Apple", "Banana", "Cherry"];
for (let fruit of fruits) {
  console.log(fruit);
}
```

### 5. **For...in Loop**

The `for...in` loop iterates over the properties of an object.

```javascript
let person = { name: "Alice", age: 25, city: "New York" };
for (let key in person) {
  console.log(`${key}: ${person[key]}`);
}
```

## Functions in JavaScript

Functions are blocks of code designed to perform a particular task. They can take parameters and return values.

### 1. **Function Declaration**

```javascript
function greet(name) {
  return `Hello, ${name}!`;
}

console.log(greet("Alice")); // "Hello, Alice!"
```

### 2. **Function Expression**

A function expression is a function defined within a variable.

```javascript
const greet = function(name) {
  return `Hello, ${name}!`;
};

console.log(greet("Bob")); // "Hello, Bob!"
```

### 3. **Arrow Function**

Introduced in ES6, arrow functions provide a concise syntax.

```javascript
const greet = (name) => `Hello, ${name}!`;

console.log(greet("Charlie")); // "Hello, Charlie!"
```

### 4. **Function with Default Parameters**

Default parameters allow you to set default values for function parameters.

```javascript
function greet(name = "Guest") {
  return `Hello, ${name}!`;
}

console.log(greet()); // "Hello, Guest!"
console.log(greet("David")); // "Hello, David!"
```

### 5. **Rest Parameters**

Rest parameters allow a function to accept an indefinite number of arguments as an array.

```javascript
function sum(...numbers) {
  return numbers.reduce((acc, num) => acc + num, 0);
}

console.log(sum(1, 2, 3, 4)); // 10
```

### 6. **Anonymous Functions**

Anonymous functions are functions without a name.

```javascript
const multiply = function(a, b) {
  return a * b;
};

console.log(multiply(2, 3)); // 6
```

### 7. **IIFE (Immediately Invoked Function Expression)**

An IIFE is a function that runs as soon as it is defined.

```javascript
(function() {
  console.log("IIFE Executed!");
})();
```

### 8. **Function Scope and Hoisting**

Functions are hoisted, meaning they can be called before they are defined.

```javascript
console.log(add(2, 3)); // 5

function add(a, b) {
  return a + b;
}
```

### 9. **Callback Functions**

Callback functions are functions passed into another function as arguments.

```javascript
function processUserInput(callback) {
  const name = prompt("Enter your name:");
  callback(name);
}

processUserInput(function(name) {
  console.log(`Hello, ${name}!`);
});
```

### 10. **Arrow Function and `this` Context**

Arrow functions do not have their own `this` context, inheriting `this` from the surrounding scope.

```javascript
const obj = {
  name: "Alice",
  greet: function() {
    setTimeout(() => {
      console.log(`Hello, ${this.name}`);
    }, 1000);
  }
};

obj.greet(); // "Hello, Alice"
```

## Combining Loops and Functions

Loops and functions are often used together to process arrays and perform repetitive tasks.

### Example: Using a Loop to Process an Array

```javascript
function processArray(arr) {
  for (let i = 0; i < arr.length; i++) {
    console.log(`Element ${i}: ${arr[i]}`);
  }
}

let numbers = [10, 20, 30, 40];
processArray(numbers);
```

### Example: Using a Function with Array Methods

```javascript
const numbers = [1, 2, 3, 4, 5];

const doubled = numbers.map(num => num * 2);
console.log(doubled); // [2, 4, 6, 8, 10]

const filtered = numbers.filter(num => num > 3);
console.log(filtered); // [4, 5]
```

### Conclusion

Understanding loops and functions is crucial for effective JavaScript programming. They help you control program flow, reuse code, and handle complex logic efficiently. Whether you are iterating over arrays or defining reusable functions, these concepts are foundational to JavaScript development.
<hr>

`12/7/2024 Friday`
# Error Handling in JavaScript


Error handling is an important aspect of programming that helps manage and respond to unexpected situations or errors in your code. JavaScript provides several mechanisms for error handling, including the `try...catch` statement, `throw` statements, and `finally` blocks. Here’s an overview of how error handling works in JavaScript:

## 1. **Using `try...catch`**

The `try...catch` statement allows you to test a block of code for errors and handle those errors gracefully.

### Basic Syntax

```javascript
try {
  // Code that may throw an error
  let result = riskyOperation();
} catch (error) {
  // Code to handle the error
  console.error("An error occurred:", error);
}
```

### Example

```javascript
try {
  let number = 10;
  let result = number / 0; // This will not throw an error, but results in Infinity
  console.log(result);
} catch (error) {
  console.error("An error occurred:", error);
}
```

## 2. **Using `throw`**

The `throw` statement allows you to create a custom error and throw it, which can then be caught by a `try...catch` block.

### Syntax

```javascript
throw new Error("Custom error message");
```

### Example

```javascript
function divide(a, b) {
  if (b === 0) {
    throw new Error("Division by zero is not allowed");
  }
  return a / b;
}

try {
  console.log(divide(10, 0));
} catch (error) {
  console.error("An error occurred:", error.message);
}
```

## 3. **Using `finally`**

The `finally` block, if present, will execute after the `try` and `catch` blocks, regardless of whether an error was thrown or not. It’s useful for cleanup code that should run no matter what.

### Syntax

```javascript
try {
  // Code that may throw an error
} catch (error) {
  // Code to handle the error
} finally {
  // Code that will run regardless of whether an error occurred or not
}
```

### Example

```javascript
try {
  let result = riskyOperation();
} catch (error) {
  console.error("An error occurred:", error);
} finally {
  console.log("This will always run.");
}
```

## 4. **Creating Custom Errors**

You can create custom error classes by extending the built-in `Error` class.

### Syntax

```javascript
class CustomError extends Error {
  constructor(message) {
    super(message);
    this.name = "CustomError";
  }
}
```

### Example

```javascript
class ValidationError extends Error {
  constructor(message) {
    super(message);
    this.name = "ValidationError";
  }
}

function validateInput(input) {
  if (input < 0) {
    throw new ValidationError("Input must be a positive number");
  }
  return input;
}

try {
  validateInput(-1);
} catch (error) {
  if (error instanceof ValidationError) {
    console.error("Validation error:", error.message);
  } else {
    console.error("Unexpected error:", error);
  }
}
```

## 5. **Error Handling in Asynchronous Code**

In asynchronous code, such as with Promises or async/await, error handling is slightly different.

### Promises

```javascript
fetch('https://api.example.com/data')
  .then(response => {
    if (!response.ok) {
      throw new Error('Network response was not ok');
    }
    return response.json();
  })
  .then(data => {
    console.log(data);
  })
  .catch(error => {
    console.error("An error occurred:", error);
  });
```

### Async/Await

```javascript
async function fetchData() {
  try {
    let response = await fetch('https://api.example.com/data');
    if (!response.ok) {
      throw new Error('Network response was not ok');
    }
    let data = await response.json();
    console.log(data);
  } catch (error) {
    console.error("An error occurred:", error);
  }
}

fetchData();
```

## 6. **Common Error Types**

- **`Error`**: The generic error type.
- **`TypeError`**: Thrown when an operation is performed on a value of the wrong type.
- **`ReferenceError`**: Thrown when a non-existent variable is referenced.
- **`SyntaxError`**: Thrown when there is a syntax mistake in the code.
- **`RangeError`**: Thrown when a value is not within the expected range.

### Example

```javascript
try {
  // Example of a TypeError
  null.f(); // This will throw a TypeError
} catch (error) {
  if (error instanceof TypeError) {
    console.error("TypeError:", error.message);
  } else {
    console.error("Unexpected error:", error);
  }
}
```

## Conclusion

Error handling in JavaScript helps you manage unexpected situations gracefully, providing better user experiences and debugging information. By using `try...catch`, `throw`, and `finally`, you can handle synchronous errors, while Promises and async/await help manage errors in asynchronous operations. Custom error classes and proper error types further enhance your ability to create robust and maintainable code.

<hr>

`15/7/2024 Monday`
# Map & Set and Map & Set Methods

JavaScript's `Map` and `Set` are data structures that provide efficient ways to store and manage unique values or key-value pairs. They offer functionalities that are different from traditional objects and arrays, making them useful for various scenarios.

## 1. **Maps**

A `Map` is a collection of key-value pairs where both keys and values can be of any data type. Unlike objects, keys in a `Map` can be any data type, and `Map` maintains the insertion order of keys.

### **Creating a Map**

```javascript
const myMap = new Map();
```

### **Adding Entries**

```javascript
myMap.set('name', 'Alice');
myMap.set(1, 'Number One');
myMap.set(true, 'Boolean True');
```

### **Accessing Entries**

```javascript
console.log(myMap.get('name')); // "Alice"
console.log(myMap.get(1)); // "Number One"
console.log(myMap.get(true)); // "Boolean True"
```

### **Checking for Existence**

```javascript
console.log(myMap.has('name')); // true
console.log(myMap.has('age')); // false
```

### **Deleting Entries**

```javascript
myMap.delete('name');
console.log(myMap.has('name')); // false
```

### **Clearing the Map**

```javascript
myMap.clear();
console.log(myMap.size); // 0
```

### **Iterating Over a Map**

```javascript
const myMap = new Map([
  ['name', 'Alice'],
  [1, 'Number One'],
  [true, 'Boolean True']
]);

for (const [key, value] of myMap) {
  console.log(`${key}: ${value}`);
}

// or using forEach
myMap.forEach((value, key) => {
  console.log(`${key}: ${value}`);
});
```

### **Map Properties and Methods**

- **`size`**: Returns the number of key-value pairs in the Map.
- **`set(key, value)`**: Adds or updates an entry.
- **`get(key)`**: Retrieves the value associated with the key.
- **`has(key)`**: Checks if a key exists.
- **`delete(key)`**: Removes an entry.
- **`clear()`**: Removes all entries.
- **`keys()`**: Returns an iterator of the keys.
- **`values()`**: Returns an iterator of the values.
- **`entries()`**: Returns an iterator of [key, value] pairs.
- **`forEach(callback)`**: Executes a callback function for each entry.

## 2. **Sets**

A `Set` is a collection of unique values. Unlike arrays, a `Set` automatically ensures that each value occurs only once, and it also maintains the insertion order.

### **Creating a Set**

```javascript
const mySet = new Set();
```

### **Adding Values**

```javascript
mySet.add('apple');
mySet.add('banana');
mySet.add('apple'); // This will not be added again
```

### **Accessing Values**

```javascript
console.log(mySet.has('apple')); // true
console.log(mySet.has('grape')); // false
```

### **Deleting Values**

```javascript
mySet.delete('banana');
console.log(mySet.has('banana')); // false
```

### **Clearing the Set**

```javascript
mySet.clear();
console.log(mySet.size); // 0
```

### **Iterating Over a Set**

```javascript
const mySet = new Set(['apple', 'banana', 'cherry']);

for (const value of mySet) {
  console.log(value);
}

// or using forEach
mySet.forEach(value => {
  console.log(value);
});
```

### **Set Properties and Methods**

- **`size`**: Returns the number of unique values in the Set.
- **`add(value)`**: Adds a value to the Set.
- **`has(value)`**: Checks if a value exists.
- **`delete(value)`**: Removes a value.
- **`clear()`**: Removes all values.
- **`values()`**: Returns an iterator of the values.
- **`keys()`**: Same as `values()`, returns an iterator of the values.
- **`entries()`**: Returns an iterator of [value, value] pairs (each pair is the same value).
- **`forEach(callback)`**: Executes a callback function for each value.

## **Comparison Between Map and Set**

- **Map**: 
  - Stores key-value pairs.
  - Keys and values can be of any data type.
  - Maintains the insertion order of keys.
  - Allows duplicate values but not duplicate keys.

- **Set**: 
  - Stores unique values.
  - Values must be unique.
  - Maintains the insertion order of values.
  - Does not store key-value pairs.

## **Conclusion**

Maps and Sets are powerful tools in JavaScript for handling collections of data. `Maps` are ideal when you need to work with key-value pairs and require the ability to access values via keys. `Sets` are useful when you need a collection of unique values and want to ensure no duplicates. Understanding these data structures and their methods will help you efficiently manage and manipulate data in your JavaScript applications.

<hr>

`16/7/2024 Tuesday`
# Regex precedence scope hoisting


Regular Expressions (Regex) are patterns used to match character combinations in strings. They are used for searching, replacing, and validating strings. Understanding regex syntax and its features is crucial for effective string manipulation in JavaScript.

## **Regex Syntax and Features**

### **1. Basic Syntax**

- **Literals**: Matches exact characters.
  ```javascript
  /abc/ // matches "abc"
  ```

- **Metacharacters**: Characters with special meanings.
  - `.`: Matches any character except newline.
    ```javascript
    /a.c/ // matches "abc", "a-c", "a5c", etc.
    ```

- **Character Classes**: Matches any one of a set of characters.
  - `[abc]`: Matches "a", "b", or "c".
    ```javascript
    /[abc]/ // matches "a", "b", or "c"
    ```

- **Ranges**: Specifies a range of characters.
  - `[a-z]`: Matches any lowercase letter.
    ```javascript
    /[a-z]/ // matches any lowercase letter
    ```

- **Negation**: Matches any character not in the set.
  - `[^abc]`: Matches any character except "a", "b", or "c".
    ```javascript
    /[^abc]/ // matches any character except "a", "b", or "c"
    ```

### **2. Quantifiers**

- **`*`**: Matches 0 or more times.
  ```javascript
  /a*/ // matches "", "a", "aa", etc.
  ```

- **`+`**: Matches 1 or more times.
  ```javascript
  /a+/ // matches "a", "aa", "aaa", etc.
  ```

- **`?`**: Matches 0 or 1 time.
  ```javascript
  /a?/ // matches "", "a"
  ```

- **`{n}`**: Matches exactly `n` times.
  ```javascript
  /a{3}/ // matches "aaa"
  ```

- **`{n,}`**: Matches `n` or more times.
  ```javascript
  /a{2,}/ // matches "aa", "aaa", "aaaa", etc.
  ```

- **`{n,m}`**: Matches between `n` and `m` times.
  ```javascript
  /a{2,4}/ // matches "aa", "aaa", "aaaa"
  ```

### **3. Anchors**

- **`^`**: Matches the beginning of a string.
  ```javascript
  /^abc/ // matches "abc" at the start of the string
  ```

- **`$`**: Matches the end of a string.
  ```javascript
  /abc$/ // matches "abc" at the end of the string
  ```

### **4. Special Characters**

- **`\d`**: Matches any digit (0-9).
  ```javascript
  /\d/ // matches any digit
  ```

- **`\D`**: Matches any non-digit.
  ```javascript
  /\D/ // matches any non-digit
  ```

- **`\w`**: Matches any word character (alphanumeric + underscore).
  ```javascript
  /\w/ // matches any alphanumeric character or underscore
  ```

- **`\W`**: Matches any non-word character.
  ```javascript
  /\W/ // matches any non-alphanumeric character
  ```

- **`\s`**: Matches any whitespace character (spaces, tabs, line breaks).
  ```javascript
  /\s/ // matches any whitespace character
  ```

- **`\S`**: Matches any non-whitespace character.
  ```javascript
  /\S/ // matches any non-whitespace character
  ```

### **5. Grouping and Capturing**

- **`(abc)`**: Groups characters together and captures the match.
  ```javascript
  /(abc)/ // matches "abc" and captures it
  ```

- **Non-capturing Group**: `(?:abc)`
  ```javascript
  /(?:abc)/ // matches "abc" but does not capture it
  ```

- **Capture Groups**: Can be referenced using `$1`, `$2`, etc., in the replacement string.

### **6. Lookahead and Lookbehind**

- **Positive Lookahead**: `(?=...)` asserts that what follows must match.
  ```javascript
  /a(?=b)/ // matches "a" only if followed by "b"
  ```

- **Negative Lookahead**: `(?!...)` asserts that what follows must not match.
  ```javascript
  /a(?!b)/ // matches "a" only if not followed by "b"
  ```

- **Positive Lookbehind**: `(?<=...)` asserts that what precedes must match.
  ```javascript
  /(?<=b)a/ // matches "a" only if preceded by "b"
  ```

- **Negative Lookbehind**: `(?<!...)` asserts that what precedes must not match.
  ```javascript
  /(?<!b)a/ // matches "a" only if not preceded by "b"
  ```

## **Precedence**

In regex, precedence determines how different parts of a regex are combined and interpreted. Here’s a general order of precedence:

1. **Grouping and Capturing**: `()`
2. **Quantifiers**: `*`, `+`, `?`, `{n}`, `{n,}`, `{n,m}`
3. **Character Classes**: `[abc]`, `[^abc]`
4. **Special Characters**: `\d`, `\D`, `\w`, `\W`, `\s`, `\S`
5. **Anchors**: `^`, `$`
6. **Lookahead and Lookbehind**: `(?=...)`, `(?!...)`, `(?<=...)`, `(?<!...)`
7. **Alternation**: `|` (OR)

### **Example of Precedence**

```javascript
let regex = /(\d+)\s+(\w+)(?=\s+(\w+))/;

// Breaking down the regex:
1. **Grouping**: `(\d+)`, `(\w+)` are capturing groups.
2. **Quantifiers**: `\d+` (one or more digits), `\s+` (one or more whitespace characters).
3. **Lookahead**: `(?=\s+(\w+))` asserts that the next part must be one or more whitespace characters followed by a word.

### **Scope**

In the context of regex, scope typically refers to the range or extent of a pattern's application. The scope of a regex pattern is determined by the portion of the string it operates on, which is defined by:

- **Global Flag (`g`)**: Allows matching multiple occurrences within the string.
  ```javascript
  let regex = /a/g;
  let result = 'banana'.match(regex); // ["a", "a"]
  ```

- **Case Insensitivity (`i`)**: Makes the pattern matching case-insensitive.
  ```javascript
  let regex = /abc/i;
  console.log(regex.test('ABC')); // true
  ```

- **Multiline Flag (`m`)**: Allows `^` and `$` to match the start and end of each line.
  ```javascript
  let regex = /^abc/m;
  console.log(regex.test('abc\n123')); // true
  ```

- **Dotall Flag (`s`)**: Allows the `.` to match newline characters.
  ```javascript
  let regex = /a.b/s;
  console.log(regex.test('a\nb')); // true
  ```

## **Hoisting**

In JavaScript, hoisting refers to the behavior where variable and function declarations are moved to the top of their containing scope during compilation. However, regex patterns themselves are not affected by hoisting. The concept of hoisting is mainly relevant for variables and functions.

### **Example of Hoisting**

```javascript
console.log(foo); // undefined (variable declaration is hoisted)
var foo = 'bar';

console.log(myFunction()); // "Hello, World!" (function declaration is hoisted)

function myFunction() {
  return "Hello, World!";
}
```

### **Regex in Context of Hoisting**

When using regex literals, they are not subject to hoisting in the same way variables and functions are. Regex patterns are interpreted as part of the code execution and do not get hoisted.

```javascript
console.log(/abc/.test('abcdef')); // true (regex is executed as it appears)
```

## **Conclusion**

Regular expressions are a powerful tool for string manipulation in JavaScript, offering a rich syntax for pattern matching and text processing. Understanding regex syntax, precedence, and scope helps in constructing effective patterns and handling various string operations. While regex itself isn't subject to hoisting, the surrounding code's behavior should be well-understood for robust regex usage.


<hr>

`17/7/2024 Wednesday`
# Classes and Object in JavaScript


JavaScript uses a prototype-based inheritance model, but since ECMAScript 6 (ES6), it has also introduced a class syntax that offers a more traditional and familiar way of defining and working with objects. This class syntax is syntactic sugar over JavaScript's existing prototype-based inheritance.

## **1. Objects**

An object in JavaScript is a collection of key-value pairs where keys are strings (or Symbols) and values can be of any data type. Objects are the fundamental building blocks of JavaScript programs and can represent real-world entities and complex data structures.

### **Creating an Object**

#### **Using Object Literals**

```javascript
const person = {
  name: 'Alice',
  age: 30,
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};

console.log(person.name); // "Alice"
person.greet(); // "Hello, my name is Alice"
```

#### **Using the `new Object()` Syntax**

```javascript
const person = new Object();
person.name = 'Alice';
person.age = 30;
person.greet = function() {
  console.log(`Hello, my name is ${this.name}`);
};

console.log(person.name); // "Alice"
person.greet(); // "Hello, my name is Alice"
```

### **Adding and Modifying Properties**

```javascript
const person = {
  name: 'Alice',
  age: 30
};

person.name = 'Bob'; // Modify property
person.email = 'bob@example.com'; // Add new property

console.log(person); // { name: 'Bob', age: 30, email: 'bob@example.com' }
```

### **Deleting Properties**

```javascript
const person = {
  name: 'Alice',
  age: 30
};

delete person.age;
console.log(person); // { name: 'Alice' }
```

### **Object Methods**

Objects can have methods, which are functions that are properties of the object.

```javascript
const person = {
  name: 'Alice',
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};

person.greet(); // "Hello, my name is Alice"
```

## **2. Classes**

Classes in JavaScript are a syntactical sugar over the existing prototype-based inheritance and provide a more familiar way to work with objects and inheritance, especially for those coming from class-based languages.

### **Creating a Class**

```javascript
class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
}

const alice = new Person('Alice', 30);
console.log(alice.name); // "Alice"
alice.greet(); // "Hello, my name is Alice"
```

### **Class Inheritance**

Classes can extend other classes, allowing for inheritance and the creation of subclasses.

```javascript
class Animal {
  constructor(name) {
    this.name = name;
  }

  speak() {
    console.log(`${this.name} makes a noise.`);
  }
}

class Dog extends Animal {
  speak() {
    console.log(`${this.name} barks.`);
  }
}

const dog = new Dog('Rex');
dog.speak(); // "Rex barks."
```

### **Static Methods**

Static methods are called on the class itself, rather than on instances of the class.

```javascript
class MathUtils {
  static add(a, b) {
    return a + b;
  }
}

console.log(MathUtils.add(5, 3)); // 8
```

### **Getters and Setters**

Getters and setters allow you to define methods that are accessed like properties.

```javascript
class Person {
  constructor(name, age) {
    this._name = name;
    this._age = age;
  }

  get name() {
    return this._name;
  }

  set name(value) {
    this._name = value;
  }

  get age() {
    return this._age;
  }

  set age(value) {
    if (value < 0) {
      console.log('Age cannot be negative.');
    } else {
      this._age = value;
    }
  }
}

const alice = new Person('Alice', 30);
console.log(alice.name); // "Alice"
alice.age = -5; // "Age cannot be negative."
console.log(alice.age); // 30
```

### **Class Fields**

Class fields allow you to define properties directly inside a class, without needing a constructor.

```javascript
class Person {
  name = 'Unknown';
  age = 0;

  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
}

const alice = new Person();
alice.name = 'Alice';
alice.age = 30;
alice.greet(); // "Hello, my name is Alice"
```

## **3. Prototypes**

JavaScript uses prototypes for inheritance. Each object has a prototype object, and inheritance is handled through these prototypes.

### **Prototype Inheritance**

```javascript
function Person(name, age) {
  this.name = name;
  this.age = age;
}

Person.prototype.greet = function() {
  console.log(`Hello, my name is ${this.name}`);
};

const alice = new Person('Alice', 30);
alice.greet(); // "Hello, my name is Alice"
```

### **Object.create()**

You can create a new object with a specified prototype.

```javascript
const personPrototype = {
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};

const alice = Object.create(personPrototype);
alice.name = 'Alice';
alice.greet(); // "Hello, my name is Alice"
```

## **4. Summary**

- **Objects**: Collections of key-value pairs with properties and methods.
- **Classes**: ES6 syntax for creating objects and managing inheritance.
  - **Constructor**: Initializes instance properties.
  - **Methods**: Functions defined inside classes.
  - **Inheritance**: Using `extends` to create subclasses.
  - **Static Methods**: Called on the class itself.
  - **Getters and Setters**: Methods to access and modify properties.
- **Prototypes**: JavaScript’s original mechanism for inheritance, providing a way to define properties and methods shared by all instances.

Classes and objects provide a powerful way to work with and organize data in JavaScript, offering features that make object-oriented programming more accessible and familiar.