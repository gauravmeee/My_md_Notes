
### Syntax Cheat Sheet

**Access Specifiers** (`private`, `protected`, `public`)
```cpp
class MyClass {

// private 
private:      // Only class members & friends can access (Default in Class)
    int a;

// protected
protected:    // Class + derived classes + friends can access (Default in Struct)
    int b;

// public
public:       // Accessible from anywhere
    int c;
};
```

**Modes of Inheritance**
```cpp
// public inheritance
class Derived : public Base { };   

// protected inheritance
class Derived : protected Base { }; 

// private inheritance
class Derived : private Base { };   
```

**Friend Keyword**
```cpp
class MyClass {
private:
    int secret;
public:
	// friend function
    friend void reveal(MyClass obj); // Function can access private data
};
```

**Static Keyword**
```cpp
class Test {
    // static variable (shared by all objects)
    static int count; // Declaration inside class

    // static function (can access only static members because No 'this' pointer)
    static void func(){...};
};

// Definition of static variable outside the class
int Test::count = 0;
```

**Const Keyword**
```cpp
// const function (does not modify member variables) 
void display() const {...};  // 'const' variable written after function ⭐

// const variable (value cannot change after initialization)
const int x = 10;  

// const object (can only call const member functions)
const MyClass obj;  
```

**Constructor & Destructor**
```cpp
class Test {
public:
    Test();        // Constructor
    ~Test();       // Destructor
};
```

**Virtual and Overridden Function**
```cpp
class Base {
public:
	// Virtual Function
    virtual void show() { cout << "Base"; }
};


class Derived : public Base {
public:
	// Overrides Base::show() (Func in base must be virtual)
    void show() override { cout << "Derived"; }  // 'override' variable  return after func name ⭐
};
```

**Pure Virtual Function (Abstract Class)**
```cpp
class Shape {
public:
    virtual void draw() = 0; // Must be overridden
};
```

---

### Const vs Static

Here’s a short **Static vs Const** comparison for C++:

| Feature             | `static`                                                                            | `const`                                                                  |
| ------------------- | ----------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| **Meaning**         | ==Variable/function belongs to the class==, not an object                           | ==Value cannot be changed== after initialization                         |
| **Scope**           | ==Shared by all objects== of the class                                              | ==Each object gets its own copy== (unless combined with `static`)        |
| **Initialization**  | For class members, ==must be defined outside class== (unless `constexpr` in C++17+) | ==Must be initialized at declaration== (for variables)                   |
| **Default Value**   | ==Zero-initialized== if not set                                                     | ==Must have an explicit value== at compile time (for const data members) |
| **Function Effect** | `static` function → no `this` pointer, can only access static members               | `const` function → cannot modify member variables                        |
| **Lifetime**        | ==Exists for the entire program== run                                               | ==Exists as long as its scope==/object exists                            |
| **Usage**           | Class-level data, counters, utility functions                                       | Read-only variables, protecting data from modification                   |

```cpp
class Demo {
    static int count;   // static var (shared)
    const int id;       // const var (unique to each object)
public:
    Demo(int x) : id(x) { count++; }
    static void showCount();   // static func
    void display() const;      // const func
};
```

---

### Function Signature

**Function Signature**  - In C++, the _function signature_ is the part of the function declaration that the compiler uses to uniquely identify a function.  
It **includes**:
1. Function name
2. Number of parameters
3. Types of parameters (including their order)
    
It **does not include**:
- Return type
- Parameter names
- `const` qualifier on the function itself (though it can affect overloading in member functions)
    
**Example:**
```cpp
void show(int, double);   // signature: show(int, double)
void show(double, int);   // different signature
```


**Significance in Polymorphism**

1. **Compile-time Polymorphism (Function Overloading)**
    - ==Overloading is possible only if function **signatures** differ.==
    - Changing only the return type does **not** change the signature, so it won’t overload.
    ```cpp
    int fun(int);    // OK
    void fun(int);   // ❌ Error: same signature as above
    ```
    
2. **Runtime Polymorphism (Virtual Functions)**
    - ==For overriding in inheritance, the **signature must match exactly**== (including const-ness)        
    - If the signature is different, it becomes **function hiding**, not overriding.
    ```cpp
    class Base {
        virtual void show(int);
    };
    class Derived : public Base {
        void show(int) override; // ✅ Same signature → overriding
    };
    ```
    
In short:
- **Overloading** → Different signatures.
- **Overriding** → Same signatures.
    
