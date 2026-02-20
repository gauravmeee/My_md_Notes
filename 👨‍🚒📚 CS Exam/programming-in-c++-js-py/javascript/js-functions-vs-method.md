# ⭐ JS Functions vs Method

#### Function Declaration

* In JavaScript you can declare functions in a few ways.
* The presence (or absence) of the `function` ==keyword changes how the function is defined==, scoped, and hoisted.

**1. Function Declaration (with `function`)**

```js
function add(a, b) {
  return a + b;
}
```

* **Hoisted**: you can call it before its definition.
* Creates a named function.

**2. Function Expression**

```js
const add = function(a, b) {
  return a + b;
};
```

* **Not hoisted** (the variable `add` is hoisted but uninitialized until runtime).
* Can be **anonymous** (like above) or **named**.

**3. Arrow Function Expression (ES6)**

```js
const add = (a, b) => a + b;
```

* Shorter syntax.
* Does **not** have its own `this`, `arguments`, or `super`.
* Useful for callbacks and React components.

**4. Method Definition (in objects / classes)**

```js
const obj = {
  add(a, b) {
    return a + b;
  }
};
```

```js
class MathOps {
  add(a, b) {
    return a + b;
  }
}
```

* Shorthand inside objects or classes.
* Still uses the `function` keyword internally, but omitted in syntax.

**Key Difference (your question focus)**

*   With `function`:

    ```js
    function fn() {}   // function declaration
    ```
*   Without `function`:

    ```js
    const fn = () => {};   // arrow function expression
    const fn = function() {}; // function expression
    ```

So:

* **Declaration (`function fn() {}`)** = hoisted, classic style.
* **Expression (`const fn = ...`)** = not hoisted, assigned to variable.

***

#### Problem : `add() { ... }` is **not valid** at top-level in JavaScript. It only works inside **classes** or **objects** as a method.

**Solution 1 — Function Declaration**

```js
function add(a, b) {
  return a + b;
}
```

* Hoisted → can be used before definition.
* Best for standalone functions.

**Solution 2 — Function Expression**

```js
const add = function(a, b) {
  return a + b;
};
```

* Not hoisted.
* Can be anonymous or named.
* Useful when assigning functions to variables.

**Solution 3 — Arrow Function Expression**

```js
const add = (a, b) => a + b;
```

* Short and modern syntax.
* Lexical `this` (does not bind its own `this`).
* Often used in callbacks and React.

**Extra — Method Shorthand (inside object/class)**

```js
class Calc {
  add(a, b) {
    return a + b;
  }
}

const obj = {
  add(a, b) {
    return a + b;
  }
};
```

* Valid only inside objects or classes.

***

#### Why Function cannot declare without `function` Keyword

* In JavaScript, that syntax (`add(a, b) { ... }`) is **only valid inside objects or classes**, not at top-level.

**Reason:**

* Top-level **functions** need the `function` keyword to tell JS it’s a standalone function.

```js
function add(a, b) { return a + b; } // valid
```

* `add(a, b) { ... }` is **method shorthand** syntax, and JS expects it to be inside an object or class:

```js
const obj = {
  add(a, b) { return a + b; } // valid
};
class Calc {
  add(a, b) { return a + b; } // valid
}
```

**Summary:** JS **needs the context (object/class)** to interpret that syntax as a method; otherwise, it won’t know what you mean without `function`.

***

#### Method Declaration Difference

**Function Declaration (top-level / standalone)**

```js
function add(a, b) {
  return a + b;
}
```

* Can be called anywhere after declaration (hoisted).
* Not tied to any object.

**Method (inside object or class)**

```js

const obj = {
  // Object method
  add(a, b) {
    return a + b;
  }
};


class Calculator {
  // Class method
  add(a, b) {
    return a + b;
  }
}
```

* Must be inside an object or class.
* Has access to `this` (object instance).
* Cannot exist at top-level like a standalone function using the same `method` syntax (`add() {}` is invalid outside).

**Summary:**

* Functions = standalone, global or local scope.
* Methods = part of object/class, can use `this`.
