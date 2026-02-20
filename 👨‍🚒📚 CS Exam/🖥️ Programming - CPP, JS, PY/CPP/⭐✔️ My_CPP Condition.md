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

# ⭐✔️ My\_CPP Condition

#### **C++ Conditional Statements Notes (From Simple to Complex)**

#### 1. If - Else

**Basic `if`**

```cpp
if (x > 0) {
    // code
}
```

**`if-else`**

```cpp
if (x > 0) {
    // positive
} else {
    // zero or negative
}
```

**`if-else if-else` Ladder**

```cpp
if (x > 0) {
    // positive
} else if (x == 0) {
    // zero
} else {
    // negative
}
```

**Nested `if`**

```cpp
if (x > 0) {
    if (x % 2 == 0) {
        // positive even
    } else {
        // positive odd
    }
}
```

#### 2. Ternary Operator (`?:`) ⭐

```cpp
int res = (x > 0) ? x : -x;  // absolute value
```

#### 3. Switch-case (when value checking only) ⭐⭐

1. Integer constant

```cpp
switch(3) {
    case 1: cout << "One"; break;
    case 2: cout << "Two"; break;
    default: cout << "Other";
}
```

2. **Character constant**

```cpp
switch('z') {
    case 'a': cout << "Letter a"; break;
    case 'b': cout << "Letter b"; break;
    default: cout << "Other letter";
}
```

3. **Enum constant**

```cpp
enum Meal { breakfast, lunch }; // breakfast = 0, lunch = 1
switch(breakfast) {
    case breakfast: cout << "B"; break;
    case 1: cout << "L"; break;
    default: cout << "Invalid";
}
```

**Allowed in `case`**

* Integer constants → `case 1:`, `case 100:`
* Character constants → `case 'a':`, `case '\n':`
* `enum` constants → `case breakfast:` (from `enum Meal { breakfast, lunch, dinner };`)
* `constexpr` / `const` values known at **compile time**

**Not allowed** - Variables

```cpp
int x = 5;
switch(n) {
    case x:   // ❌ ERROR: x is a variable (runtime value)
        ...
}
```

#### 4. Use Case & Safe Coding Practices

**Logical Conditions**

```cpp
if (x > 0 && y > 0) {
    // both positive
}

if (x == 0 || y == 0) {
    // at least one is zero
}
```

**Use with `auto`, `const`, or references**

```cpp
for (const auto &x : vec) {
    if (x > 0) ...
}
```

**Short-circuiting ⭐**

```cpp
if (x != 0 && y / x > 1) {
    // safe, prevents division by zero
}
```

* Prevents unnecessary computation and runtime errors.
* Stops evaluating further conditions if the first one is false.
* Useful in DSA for safe operations like division, null-pointer checks, or bounds checking.

**Avoiding dangerous access (extreme cases)**

```cpp
if (!st.empty() && st.top() < x) {
    // Safe access to st.top()
}
```

* Ensures container is not empty before accessing its elements.
* Prevents runtime errors like segmentation faults or undefined behavior.
* Common in stacks, queues, vectors, and other containers in DSA.

**Guard Clauses**

```cpp
if (vec.empty()) return;

if (i < 0 || i >= vec.size()) return;
```

* Immediately exits the function when **invalid or edge-case conditions** are met.
* Keeps the main logic **clean and unindented**.
* Prevents runtime errors like out-of-bounds access.
* Useful in DSA for vectors, arrays, stacks, or recursive functions.

**Common Pitfalls**

*   **Using `=` instead of `==`**

    ```cpp
    if (x = 0) // ❌ assigns 0 to x, condition always false
    ```
*   **Accessing container without check**

    ```cpp
    vec[0] // ❌ unsafe if vec.size() == 0
    ```

**Note:** Always verify conditions and container size before operations.

**Summary Table:**

| Type          | Usage                            | Example                  |
| ------------- | -------------------------------- | ------------------------ |
| Simple `if`   | One condition                    | `if (x > 0)`             |
| `if-else`     | Two paths                        | `if (x) else`            |
| Ladder        | Multiple conditions              | `if-else if-else`        |
| Ternary       | Short inline condition           | `int x = a > b ? a : b;` |
| Nested `if`   | Condition inside another         | `if (x) { if (y) ... }`  |
| Logical ops   | Combine conditions               | `if (x && y)`            |
| Short-circuit | Prevent runtime errors           | `if (ptr && ptr->val)`   |
| Guard clause  | Early exit on invalid conditions | `if (!ok) return;`       |

Use conditionals carefully to avoid undefined behavior and keep logic readable.
