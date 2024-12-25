

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

---

```cpp
class Complex{
	int img, real
	void getdata()
}
```

Pointers to object
```cpp
Complex *ptr = new Complex
// ptr -> pointer, *ptr -> actual object
ptr -> img // (*ptr).img  
ptr -> getdata() // = (*ptr).getdata()
```

Array of Object

```cpp
Complex *arrPtr = new Complex[4] // = Complex arr[4]
arrPtr->img // arrPtr[0].img
arrPtr+1->img // (arrPtr+1) -> img = *(arrPtr+1).img = arrPtr[1].img
// arrPtr+1 = (arrPtr+1) because precedence of `+` more than `->`
```

this -> point to object
```cpp
class A{
	int a;
	void setData(int a){ // if we want to use same variable for simplicity
		// Explicitly use this->a
		this->a = a; // LHS: data member,  RHS: local variable
		}
```

Return the object itself
```cpp
```cpp
class A{
		int a;
		A& setData(int a){
			this->a = a;
			return *this // *this = value of this, because this is a pointer 
		}
		void getData() cout<<a<<endl;		
};

```

```cpp
	A a;
	a.setData(4).getData(); // = 4 , call the function of object

```

---

Which Function in oops called

Non virtual function
If the function in the base class is **not declared as virtual**, the function to be called is resolved at **compile time** based on the type of the object or pointer/reference.

- If accessed through a **base class pointer/reference**, the **base class version** is called.
- If accessed directly through a **derived class object**, the **derived class version** is called.

Virtual Function
If the function in the base class is declared as **virtual**, the function to be called is resolved at **runtime** based on the type of the object being pointed to (dynamic polymorphism).

- If accessed through a **base class pointer/reference**, the **derived class version** is called (if overridden).
- If accessed directly through a **derived class object**, the **derived class version** is called.


`Base::function()` syntax, the base class version will always be invoked regardless of whether the function is virtual or not.

---
```
                         Polymorphism
                         /         \
                        /           \
                 Compile-time      Run-time
                 Polymorphism      Polymorphism
                 /       \               \
                /         \               \ 
          Function       Operator         Virtual
        Overloading    Overloading        Function
```

 Virtual Function: A function that is in the parent class but redefined in the child class is called a virtual function. “virtual” keyword is used to declare a virtual function.
 
The run time polymorphism is considered slow because function calls are decided at run time

---
Pointer to Derived Class

```cpp
class BaseClass
class DerivedClass : public BaseClass
```

```cpp
BaseClass *base_class_ptr; // Base Class Pointer
DerivedClass * derived_class_ptr; // Derived Class Pointer

BaseClass obj_base; // Derived Class Object
DerivedClass obj_derived; // Derived Class object
```


**Base Class Pointer to Derived Class Object (Upcasting)**:

```cpp
base_class_pointer = &obj_derived; // Base Class pointer pointing to Derived object

base_class_pointer->display(); // ✅ member function of base class (unless virtual)
base_class_pointer->var_base = 34; // ✅ member variable of base class
base_class_pointer->var_derived= 134; // ❌  A base class pointer cannot access derived class memberer
```


**1. Base Class Pointer to Base Class Object -> Same as Base Class Object**   ✅
    A Base class pointer to a Base class object behaves exactly like the Base class object. It can only access members of the Base class.
    
**2. Base Class Pointer to Derived Class Object -> Same as Base Class Object + Polymorphism (if virtual functions are used)**   🙀
    When a Base class pointer points to a Derived class object, it can invoke overridden functions in the Derived class via virtual functions (runtime polymorphism). Otherwise, it behaves like a Base class pointer without polymorphism.

**3. Derived Class Pointer to Derived Class Object -> Same as Derived Class Object**   ✅
    A Derived class pointer pointing to a Derived class object can fully access all members of the Derived class (including Base class members).

**4. Derived Class Pointer to Base Class Object -> Cannot Be Created**   ❌
    A Derived class pointer cannot point to a Base class object because the Base class does not have the additional members or methods of the Derived class. It would violate the memory layout and object integrity.

---
