
**Message Passing**

Message passing in Object-Oriented Programming (OOP) refers to the process of **communication between objects** in a program. It allows objects to interact with each other by invoking methods or functions.

```cpp
int main() {
    Car myCar;
    myCar.start(); // Message passing: object `myCar` receives the message `start()`
    return 0;
}
```

**Benefits:** Promotes modular design, Supports abstraction and encapsulation, Enables scalability and flexibility.

---

```cpp
int main(){

    Employee harry; // private -> a, public -> b & fun()
   // harry.a = 1 -> ❌ private data 
    harry.b = 1; // -> ✅ public
    harry.fun(); // ✅ private data 'a' through function.
}
```

---

- Declare `data`/`func()`  inside Class, Define `myClass::count =0` /  `myClass::func(){. . .}`  outside Class

---

Virtual Base Class

A **virtual class** refers to the **base class** that is inherited using virtual inheritance. In your case, **class `A`** is the **virtual base class**, and classes `B`, `C`, and `D` are derived from it either directly or indirectly.

```
a-> virtual b
a-> virtual c

b ->d
c->d
```

---

when an object of a derived class is created, both the base class constructor and the derived class constructor are executed.

Priority of Order:
Virtual Base Class > Base Class > Derived Class

```cpp
Class Derived{
// Special Syntax
Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
        {
            derived1 = c;
            derived2 = d;
            cout<< "Derived class constructor called"<<endl;
        }
};
```

---
### Overridden vs Run-time Overloading:

|Aspect|**Overriding**|**Overloading**|
|---|---|---|
|**Concept**|Changing the implementation of an inherited method in a derived class.|Defining multiple methods with the same name but different parameters in the same class.|
|**Occurs**|Inheritance (derived class overrides a base class method).|Within the same class.|
|**Polymorphism Type**|Runtime Polymorphism (dynamic dispatch).|Compile-time Polymorphism (resolved at compile time).|
|**Method Signature**|The method signature (name + parameters) is the same in base and derived classes.|The method name is the same, but parameters (type, number) differ.|
|**Access Specifiers**|The base method should be virtual, and it may have access control like `public`, `protected`.|Overloaded methods have different parameter signatures but the same name, and access can vary.|
|**Example**|`void display() override` in derived class.|`void display(int x)`, `void display(double x)` in the same class.|

---
`override` keyword advantage: If you accidentally change the method signature in the derived class (e.g., change the parameters or return type), the base class method will no longer be overridden,
 `virtual` keyword advantage :when the display function is called by using the base class pointer -> **the display function of the derived class will run** 

---
No, **constructors cannot be virtual** in C++.

**Abstract base class** is a class that has at least one pure virtual function in its body.

. You can't Create Instance or Object of abstract class.  
	However If you **were** calling the pure virtual function through object would lead to **undefined behavior** because there would be no actual implementation for that function in the object.

2. call a pure virtual function directly from the abstract class, it will result in a compilation error `ClassName::virtualFunc()`❌