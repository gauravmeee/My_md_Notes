

---
### Variable and Comments

**JavaScript Variables**
```js
var     // function-scoped, can be redeclared and updated
let     // block-scoped, can be updated but not redeclared
const   // block-scoped, can't be updated or redeclared
```

**Comments**
```js
// Single line comment

/* Multi-line
   comment */
```

---
### Data Types

**Primitive Data Types**
```js
var num1 = 455              // Number
var str1 = "A String"       // String
var bool1 = true            // Boolean
var undef = undefined       // Undefined
var nul = null              // Null
var sym = Symbol('id')      // Symbol (unique)
```

**Reference Datatype**
```js
// Array
var arr = [1, 2, "doe", 4, 5];
console.log(arr);      // [1, 2, "doe", 4, 5]
console.log(arr[0]);   // 1

// Object
var marks = {
  ravi: 34,
  shubham: 78,
  harry: 99.977
};
console.log(marks);    // {ravi: 34, shubham: 78, harry: 99.977}
console.log(marks.shubham)  // 78
```

---
### Operators in JS

```js
// Assignment Operators
=   +=   -=   *=   /=

// Arithmetic Operators
+   -   *   /   %

// Comparison Operators
==   !=   ===   !==   <   >   <=   >=

// Logical Operators
&&   ||   !

// Bitwise Operators
&   |   ^   ~   <<   >>   >>>
```

---
### Function

**Anonymous Function**
```javascript
// Anonymous Function Expression
const funcVar = function() { };

// Immediately Invoked Function Expression (IIFE)
(function() {})();

// Callback Example
setTimeout(function() {}, time);

// Event Handler Example
document.getElementById("elementId").addEventListener("event", function() {});
```

**Named Function (Assigning to variable is optional)**
```javascript
// Named Function Declaration
function funcName() { }

// Named Function Expression
const funcVar = function funcName() { };

// Named Function Expression with Immediate Invocation
(function funcName() {})();
```

**Arrow Function**
```javascript
// Arrow Function
const funcName = () => { };

// Immediately Invoked Arrow Function (IIFE)
(() => {})();
```

**Condition in Javascript**
```js
if(x<18){
	// logic
}
else if(x>31){
	// logic
}
else{
	// logic
}
```

---
### Loops 

**For Loop**
```js
for(var i=0; arr.length; i++){
 // logic
}
// Iterate from a lower bound value to upper bound value
```

**While Loop**
```js
//while loop
while(j<arr.length){
    // logic
    j++;
} 
// Iterate until a given condition is true
```

**For Each Loop**  ⭐
```js
arr.forEach(functions(element){
    // logic
})
// Ierate over elements of sequence - array, string etc.
```

**do-while** ⭐
```js
do{
    // Logic ;
    j++;
}while (j < arr.length);
// Run a loop at least one time.
```

**Break and Continue**
```js
for( var i = 0; i<10; i++){

	// continue
    if(i==4){
		continue; // skip current iteration
    }
	// break
	if(i==6){
        break; // exit the loop
    }
    // logic
}
// continue: skip loop's execution for a condition
// break: terminate loop based on condition
```

---

### Methods in Javascript ⭐


**Methods on array** 
```js
let myArray = ["Fan", "Camera", 34, null, true ]

// Length of Array
myArr.length

// Remove last elment from array
myArr.pop() // ["Fan", "Camera", 34, null]

// Push an element to an Index
myArr.push("harry") 

// Remove first element from array ⭐
myArr.shift()

// Add element to Starting ⭐
myArr.unshift("Harry")

// Print array
console.log(myArr) // ["Harry", "Camera", 34, null, "harry"]

// Print length of new array ⭐
console.log(myArr.unshift("Gurav")) // 6

// Convert array to string ⭐
myArr.toString() // "Harry,Fan,Camer,34,,true"

// Sort Array (in Dictionary Order) ⭐
let d = [1,4,6,43,23,32324]
d.sort() // [1, 23, 32324, 4, 43, 6]
```


**String Methods in JS**
```js
let myLovelyString = "Gaurav is a good boy, Gaurav";

// Length of string
myLovelyString.length // 20

// Starting index of substring
myLovelyString.indexOf("Gaurav") //0 (first matched index)

// Starting index of substring
myLovelyString.lastIndexOf("Gaurav") //23 (last matched index)

// Slicing in string (startIndex, size)
myLovelyString.slice(0,3) // "Gau

// Replace first substring occurence in string
myLovelyString.replace("Gaurav","Meena") //"Meena is a good boy, Gaurav"
```

Date-Time Method in JS
```js
// Create a new Date object representing the current date and time
let myDate = new Date(); // e.g., Mon July 01 2024 22:47:00 GMT+0530 (IST)

// Get the time in milliseconds since Jan 1, 1970 (Unix Epoch)
myDate.getTime()

// Get the 4-digit year (e.g., 2024)
myDate.getFullYear()

// Get the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
myDate.getDay()

// Get the current minute (0 to 59)
myDate.getMinutes()

// Get the current hour (0 to 23)
myDate.getHours()
```

---

### Document Object Model (DOM) Manipulation

**Types of Messages**
```js
alert("Hello")                  // Shows an alert popup
console.log("Hello")            // Prints in the console
console.error("Hello")          // Logs error in the console
```

**Element Selection**
```js
document.querySelector(".button1")          // Selects first element with class "button1"
document.getElementById("navbar1")          // Selects element with id "navbar1"
document.getElementsByTagName("h1")         // Selects all <h1> elements (HTMLCollection)
```

**Click Implementation**
```js
document.querySelector(".button1").click()  // Clicks on element with class "button1"
```

**Select from Array of Elements**
```js
document.getElementsByTagName("h1")[0]      // Selects first <h1> element
```

**Apply CSS Style**
```js
document.getElementsByTagName("h1")[0].style.fontSize = "99px"  // Changes font size of first <h1>
```


**Embedded Script**
```html
<script> console.log("Hello World"); </script>
```

**External Script**
```html
<script src="index.js"></script>
```
