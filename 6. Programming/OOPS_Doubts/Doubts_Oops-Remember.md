
- **Class Member Functions:**
    
    - The order of function declarations within a class does not matter.
    - As long as a function is declared somewhere in the class definition, it can be called from anywhere within the class.
    - This flexibility is due to the class definition acting as a forward declaration for all its member functions.
- **Free Functions:**
    
    - Free functions must be declared before they are called.
    - If a free function is called before its declaration, the compiler will not recognize it, resulting in a compilation error.
    - 
### Struct vs Class

| Feature               | struct                         | class                               |
|-----------------------|--------------------------------|-------------------------------------|
| Default member access | public                         | private                             |
| Default inheritance   | public                         | private                             |
| Use cases             | POD types, simple data structures | Encapsulation, inheritance, polymorphism |
| Encapsulation         | Less emphasis                  | More emphasis                       |

### Methods to Access Object Members

| Syntax   | Description                           |
|----------|---------------------------------------|
| `node.val` | Direct member access using a dot operator for objects. |
| `node->val` | Member access using an arrow operator for pointers to objects. |

Function inside a Class -> Method.


Here's a table that highlights the differences between `private`, `public`, and `protected` access specifiers in C++:

- Private, Protected vs Public

| Access Specifier | Access Level | Accessible from within the same class | Accessible from derived classes | Accessible from outside the class |
| ---------------- | ------------ | ------------------------------------- | ------------------------------- | --------------------------------- |
| `private`        | Restricted   | Yes                                   | No                              | No                                |
| `protected`      | Limited      | Yes                                   | Yes                             | No                                |
| `public`         | Unrestricted | Yes                                   | Yes                             | Yes                               |
