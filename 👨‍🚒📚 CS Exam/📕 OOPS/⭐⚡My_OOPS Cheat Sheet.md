---
description: Made By Me 💚
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

# OOPS Cheat Sheet

**POP**

* major emphasis is on `PROCEDURE` (functions) and not on the data
* Program is divide into functions
* Top-Down Approach
* Ex: `C`, `Cobol`, `Fortan`, `Pascal`

**OOP**

* Major emphasis is on `DATA` rather than `PROCEDURE`
* Program is divide into objects
* Bottom-Up Approach
* Ex: `C++`, `Java`, `Python`, `.NET`

_OOPS Follow DRY!_

**4-Principle of OOP**

* **Encapsulation**:
  * Binding data and functions into a single unit (via Classes, objects).
  * Hiding the data for purpose of protection (via Access Specifier)
* **Inheritance**:
  * deriving a new class from an existing class.
* **Abstraction**:
  * Hides Implementation details and just exposes the features. (via virtual functions, abstract classes).
  * Reduces code complexity
* **Polymorphism**:
  * Object to take many forms (via overloading and overriding).

**Concepts:**

* **Class:** A class is a template to create objects
* **Object:** An Instance of Class
* **Message Passing:** object interact with one another by sending messages, typically through method calls.
* **Dynamic Binding** - code which will execute is not known until the programs run

***

#### Classes

Create Class

```cpp
class MyClass{    
    private:
        int pvtData;
        void pvtFunc(){...}; // Declared and Defined
    public:
        int pubData;
        void pubFun(){...};   // only Declared
};
```

Create Object

```cpp
MyClass obj;
```

Only public member can be Accessed Directly

```cpp
obj.pvtData;  // OR obj.pvtFunc() ❌ Private
obj.pubData; // OR obj.pubFun() ✅ public
 // 
```

Define Function outside Class

```cpp
class MyClass{   
	// Declared (parameter name omitted ⭐)
	void myFunc(int, float); 
};
// Defined
void MyClass::myFunc(int a, float b){...}; 
```

Parameter name can be **omitted** in declaration for any function : member function, friend function, independent function etc.

```cpp
// Function declaration (parameter names omitted)
int add(int, int); 

// Function definition (parameter names required)
int add(int a, int b) {
    return a + b; 
}
```

Declare objects along with the class declaration like this:

```cpp
Class Employee{
	//class definition
} harry, rohan, lavish;
```

#### Nesting of Member Function

```cpp
class MyClass {
	// Class By default -> Private
    void pvtFunc(){...};

    public:
	    void pubFunc(void); 
};

void MyClass::pubFunc(void) {
    pvtFunc(); // pvtFunc() nested inside pubFunc()
}
```

* In **C++**:\
  ✅ `func()` and `func(void)` → **both mean no parameters**
* In **C**:\
  ✅ `func(void)` → no parameters\
  ⚠️ `func()` → **unspecified parameters** (can take any arguments)

#### Access Specifier

* `private`(Default) : Can only be Accessed within Same Class, and by Friend function.
* `protected` : private + can also be accessed in Derived Class ⭐
* `public` : protected + can also accessed outside the Class

Accessing Nested Private/Public Member using Public Function

```cpp
MyClass obj;

obj.pubFunc() // Accessing private function through another function
```

#### Static

* `static variable`
  * class-level variable shared by all instances.
  * Declared using the `static` keyword.
  * Can be ==accessed by both `static` and `non-static` functions.==
  * Can be accessed **without creating an object** of the class. ⭐
  * `static variable` inside a class **must** be ==defined outside the class== **unless** it is a `constexpr` or `const static` integral type, which can be initialized inside the class.
  * If **not explicitly initialized**, it is ==**automatically initialized to 0**==.
* **`static function`**
  * \==Can access **only `static` members**== (variables/functions) of the class.
  * Since it has ==no `this` pointer==, it ==can’t access non-static variables/functions.==
  * Useful for operations not tied to a specific object.
  * Can be called **without creating an instance**. ⭐
  * **Static functions** ==cannot be virtual== because they don’t belong to a specific object instance.

```cpp
class MyClass{
	static int pvtData;
	static void pvtFunc(){...};
	public:
		static int pubData;
		static void pubFunc(int pvtData){...};
		void pubFunc2(){...};
};
```

```cpp
class MyClass{
	private:
		static int pvtData;
	public:
		static int print()
}


```

```cpp
MyClass::pvtData;  // ❌ Cannot access private static or non-static data members
MyClass::pvtFunc(); // ❌ Cannot call private static or non-static functions

MyClass::pubData(); // =0 ✅ Accessing Static data without creating instance
MyClass::pubFunc(); // ✅ Accessing Private static member using public static Function (without creating Instance);

MyClass::pubFunc2(): // ❌ Non-static member cannot be called without creating an object
```

`Default` value is `0` for all static variable (unlike local variable)

#### Object Memory Allocation

The memory of a class in C++ is primarily determined by its **instance variables** (data members).

* `Variable` in class get their `own memories`
* Member `function` and `static variables` in class have `common memory` allocation for different objects

```
__________________________________
| Object 1 | Object 2 | Object 3 |
|    i     |   i      |    i     |
|    a     |   a      |    a     |
|--------------------------------|
|  f1()   f2()    f3()           |
|  static data                   |
|________________________________|
```

#### Passing Objects as a Function Argument

```cpp
class MyClass{
	int a;
	int b;
	public:
		void addClass(MyClass obj1, MyClass obj2){ 
			a = obj1.a + obj2.a;
			b = obj1.b + obj2.b;
		}
}
```

* Defining Function inside Class so that member functions can directly access private/protected data.

```cpp
// pass by value
void myFunc(MyClass obj) { // copy of the object is passed
}

// pass by reference
void myFunc(MyClass &obj) { // reference to the object is passed 
}

// pass by by pointer
void myFunc(MyClass *obj) { // object address is passed
}
```

* use `pass by value` if not want to affect the original object. but it creates overhead if the object is large.
* Use the `pointer` or `reference` to access or modify the original object.

***

#### Friend Functions

**Friend function** - > function that is ==not a member of a class but has access to its private and protected members.==

* Declared inside class using `friend` keyword.
* Take `object` as an argument. (to access its private member)
* Can be also declared inside of `private` section of the class ⭐
* It can be ==**invoked without the help of object**==
* Writing `friend int friendFunc(int pvtData);` or `friend int friendFunc(int pubData);` does not give the function access to the class's `pvtData` or `pubData` directly.

```cpp
class MyClass{
	int pvtData;
	public:
		// friendFunc() is Friend of the Class
		friend int friendFunc(MyClass, MyClass);
};

// friend function definition
int friendFunc(MyClass obj1, MyClass obj2){obj1.pvtData + obj2.pvtData} // accessing `pvtData` of objects
```

**Friend Class**

Instead of making individual functions friends, **==you can declare the entire class as a friend==** of another class.

```cpp
class MyClass1 // forward declaration

class MyClass2{ 
	int funcA(MyClass1 obj2){...};
	int funcB(MyClass1 obj2){...};
};

class MyClass1{
	int a, int b;
	friend class MyClass2 // Both member function of MyClass2 are friend
}
```

**Member Friend Function**

Friend Functions that are member of other class (not independent

```cpp
class MyClass1{
	int a ;
	friend int MyClass2 :: func(MyClass); // individually declaring member functions of another class  as friend
}

class MyClass2{ 
	int func(MyClass1 obj2){...};
};
```

**Forward declaration** -> this lets the compiler or interpreter know about the entity beforehand, such as `class`, `function`, `structs`, `enums`, `typedef`, `template`

#### Constructor

**Constructor:** -> Special member function with ==same name as of the class.==

* It is used to initialized the objects of its class
* It is ==automatically invoked== whenever an object is created
* It should be ==declared in the `public` section== of the class ⭐
* Cannot `return` values and do n==ot have `return` type== ⭐

```cpp
class MyClass{
	int a;
	public:
		MyClass(void){a=0;}; // Also a Default Constructor
};
	// MyClass obj -> Default Constructer called
```

**Default Constructor** -> No argument

```cpp
class MyClass{
	Public:
		MyClass(); // Default Constructor
};
// forward declared...

int main(){
	MyClass obj1; // Default Constructor called
	MyClass obj2(); // ❌ This is NOT object creation, it declares a function ⭐
}
```

**Parameterized Constructor** - One or more argument

```cpp
class MyClass{
	public:
		MyClass(int, int); // Parameterised Constructor
};
// forward declared...

int main(){
	MyClass obj1(4,5);
	MyClass obj2 ❌ // necessary to initialize while creating object in constructor.
}
```

**Constructor with Default Argument** -> If argument not passed, default value is used

```cpp
MyClass{
	public:
		MyClass(int a, int b){...};
		MyClass(int a=0, int b=0){...}; // Constructor with Default Argument
};

int main(){
	MyClass obj1; // Default Argument (a=0, b=0)
	MyClass obj2(); // ❌ Function Declaration
	MyClass obj3(5); // a=5, Default argument(b=0)
}
```

* **`MyClass obj2();`** This will **not create an object**, it declare a function which takes no argument and returns a `MyClass` object ⭐

Note

* `MyClass(int a, int b=0) { ... }` ✅
* `MyClass(int a = 0, int b) { ... }`// ❌ Invalid: Default arguments must be from **right to left**

**Constructor Overloading** -> Multiple constructor with different signature

```cpp
class MyClass {
public:
    MyClass() { ... }                          // 1. Default constructor
    MyClass(int a) { ... }                     // 2. One int param
    MyClass(int a, int b) { ... }              // 3. Two int params
    MyClass(int a, int b = 0) { ... }          // 4. Default b
    MyClass(int a = 0, int b = 0) { ... }      // 5. Default a and b
    MyClass(char) { ... }                      // 6. One char param
};

int main() {
    MyClass obj1;            // ✅ 5 is used (int a=0, int b=0) → matches default constructor
    MyClass obj1();          // ❌ Most Vexing Parse: interpreted as a function
    MyClass obj2(5);         // ❌ Ambiguous: matches 2, 4, and 5 → compile-time error
    MyClass obj3(5, 10);     // ✅ 3 is used (int, int)
    MyClass obj4 = MyClass(5);   // ❌ Same ambiguity as obj2
    MyClass obj5 = MyClass();    // ✅ 5 is used (a=0, b=0)
    MyClass obj6('a');       // ✅ 6 is used (char)
}
```

`MyClass obj1` -> If no argument passed, and both `default constructor` and `constructor with no argument` are there, `default constructor` is called. then use explicitly `Constructor with Default argument` by `MyClass obj3=MyClass()` without passing single data

**Dynamic Initialization of Objects using Constructor**

```cpp
class MyClass{
	public:
		MyClass(){...} 
		MyClass(int p, int y, int r){...}
		MyClass(int p, int y, float r){...}
};

int main(){
	MyClass bd1, bd2; // Default Constructor
	
	// Create a temporary object using Explicit Constructor Call 'MyClass(p,y,r); and assigned to bd1 and bd2.

	// overwrites the current state of bd1, bd2 with the state of the temporary object.
	bd1 = MyClass(1, 3, 5); // Reassigned
	bd2 = MyClass(1, 3, 1.5); // Reassigned
	bd2 = MyClass(1, 3, 3); // Reassigned
}
```

* \==Default Constructor is required to create object without passing initial parameter ==(otherwise error).
* Initially `bd1` & `bd2` created using the default constructor and assigned garbage values.
* `bd1` & `bd2` then ==reassigned a value using the parameterized constructor==.

**Copy Constructor**

```cpp
class MyClass{
	int a;
	public:
		MyClass(int num){a = num}
		MyClass(MyClass& obj){ // Default Constructor
			a=obj.a;
			cout<<"Copy constructor called";
		}
};

int main(){
	MyClass obj(45);
	MyClass obj2(obj) // obj2.a = 1
}
```

**Default Copy Constructor :** There is no error to use `MyClass obj2(obj)` even if copy constructor is not defined by user. ⭐ Because **it is inbuilt**. But user define copy constructor overload it.

**Destructor** -> an instance member function which is invoked automatically whenever an object is going to be destroyed

* Destructor neither requires any argument nor returns any value.
* Destructor has the same name as their class name preceded by a `tilde(~)` symbol
* It is not possible to define more than one destructor.
* In ==destructor, objects are destroyed in the reverse of an object creation.==

```cpp
Class MyClass{
	MyClas(){cout<<"constructor called";}
	~MyClass(){cout<<"distructor called";}
};

int main(){
	MyClass obj1; // "constructor called" (for obj1)
	{
		MyClass obj2; // "constructor called" (for obj2)
	} // "Destructor called" (for obj2, automatically due to scope end)
} // "Destructor called" (for obj1, automatically due to scope end)
```

* If object is created by using `new` or the constructor uses `new` to allocate memory, which resides int the heap memory or the free store, the destructor should use `delete` to free the memory

#### Inheritance

**Inheritance** -> Deriving a Class from another Class

* It allows a class to inherit properties and behaviors from another class.

**1. Simple** Inheritance -> A derived class with only one Base class : `B = A + (more)`

```
	base
	[A]  
	 ⇩  derive
	[B]
	derives
```

```cpp
class B : public A { }
```

**2. Multiple** Inheritance -> A derived class with more than one base class : `C = A + B + (more)`

```
   Base    Base
   [A]     [B]
     ⬂   ⬃
       [C]
     Derived
```

```cpp
class C : public A, public B { }
```

**3. Multilevel** Inheritance -> Deriving a class from already derived class : `B = A + more` & `C = B + more`

```
	base
	[A]  
	 ⇩ 
	[B]
	 ⇩ 
	[C]
	derives
```

```cpp
class B:  public A { }
class C:  public B { }
```

**4. Hierarchical** Inheritance -> Several Derived Classes from a single base class: `A = C + more` & `B = C + more`

```
	  Blase 
       [C]
     ⬃    ⬂
   [A]     [B]
Derived   Derived
```

```cpp
class A:  public C { }
class B:  public C { }
```

**5. Hybrid** Inheritance -> combination of two or more types of inheritance (e.g., single, multiple, multilevel, hierarchical)

```
	  Blase 
       [C]
     ⬃    ⬂
   [A]     [B]
     ⬂    ⬃
       [D]
     Derived
```

```cpp
class A:  public C { }
class B:  public C { }
class D : public A, public B { }
```

**Visibility Modes in Inheritance** -> how the members (attributes and methods) of the parent class are inherited in the child class.

* Default visibility -> mode is private

| **Base Class Member**  | **Private Members** | **Protected Members** | **Public Members** |
| ---------------------- | ------------------- | --------------------- | ------------------ |
| Private Mode (Default) | not ❌ Inherited     | private               | private            |
| Protected Mode         | not❌ Inherited      | protected             | protected          |
| Public Mode            | not ❌ Inherited     | protected             | public ⭐           |

```cpp
class DerivedClass : protected BaseClass{
	// protected Inheritance
}
```

**Virtual Base Class** -> Concept used in multiple inheritances to prevent ambiguity between multiple instances

* solve the **diamond problem** in multiple inheritance, ensuring that a single shared instance of a base class is inherited, even when multiple paths lead to it.
* `virtual` keyword is applied during inheritance, not when defining the base class.
* The order of `virtual` keyword and `visibility mode` keyword does not matter ⭐
* Without Virtual Base Class
* Ambiguity -> Compile-time error

```
                A 
             (int x)
            ⬋        ⬊
          B           C
   (x from 'A')     (x from 'A')
            ⬊       ⬋
                D
        (x from 'B' or 'C') ?? -> ambiguity ❌
                
```

* To solve this ambiguity we will make class `A` as a virtual base class.
* Now class `D` inherits a single instance of `A` through `B` and `C`, preventing ambiguity.

```cpp
class A {  // Class A Logic
};

class B : public virtual A {  // Virtual inheritance
};
class C : virtual public A {  // Virtual inheritance
};   
class D : public B, public C { // Single instance of A in D
}; 
```

**Constructor in Derived Class**

* if the **visibility mode** of the base class constructor is not `public`, then the constructor is **not inherited** in the derived class.

**Default constructor** of the base class -> automatically called when an object of the derived class is created.

```cpp
BaseClass{
	public:
		BaseClass(); // Default Constructor
}
class DerivedClass:public BaseClass{
	// No need to explicitly call the base class constructor
}
```

**Parameterized constructor** of the base class -> constructor **must explicitly call** in Derived class and pass argument to use it ⭐

```cpp
BaseClass{
	public:
		BaseClass(int x){...} // Parameterised Constructor
}
class DerivedClass:public BaseClass{
	public:
		DerivedClass(int x) : BaseClass(x) {...} ⭐
		// Explicitly call the base class constructor with an argument
}
```

**Constructor Execution Order**

1. **Case 1: Constructor in Simple Inheritance** -> If both base and derived classes have constructors, **==base class constructor is executed first==**.

* Constructor order for `B`'s Instance where Inheritance `A->B`

```cpp
class B: public A{
	//Constructor execution Order -> A() -> B()
};
```

2. **Case 2 : Constructor in Multiple Inheritance** -> base classes are constructed in the **==order in which they appear==** in class declaration.

* Constructor order for `C`'s Instance where Inheritance `A->C, B->C`

```cpp
class C: public A, public B{
	//Constructor execution Order -> A() -> B() -> C()
};
```

3. **Case 3 : Constructor in Multilevel Inheritance** -> the constructors are **==executed in the order of inherit==**

* Constructor order for `C`'s Instance where Inheritance `A->B->C` ⭐

```cpp
 // For Object `C` Constructor order : A() -> B() -> C() 
class B:  public A { }
class C:  public B { }
```

4. **Case 4 : Virtual Base Class** -> constructors for **==virtual base classes are invoked before an non-virtual base class==**. If there are multiple virtual base class, they are invoked in the order declared.

* Constructor order for `C`'s Instance multiple inheritance.

```cpp
class C: public A, virtual public B{
	//Constructor execution Order -> B() -> A() -> C()
};
```

Order of Constructor execution on Derived Class ⭐

```
Rule 1:
Virtual Base Class  -> Base Class ->  Derived Class

Rule 2:
Order of Declaration

Rule 1 > Rule 2
```

***

**Special Syntax for Passing Arguments to Multiple Base Classes through derived constructor**

* The constructor of the derived class receives all the arguments at once and then it will pass the calls to the respective base classes
* The body is called after all the constructors are finished executing. ⭐

`A->B->C`

```cpp
class A { public: A(int x, int y) {} }; 
class B { public: B(int z) {} }; 

// Derived Class From A and B
class C : public A, public B {
	public: 
		// Derived class constructor 
		C(int x, int y, int z) : A(x, y), B(z) {...}  ⭐
};
```

`A->C`, `B->C`

```cpp
class C : public A, public B{
	int x, y;
	public:
		C(int a, int b, int c, int d) : A(a), B(b) {...}
}
```

***

**Initialization list in Constructor**

```cpp
class MyClass
{
    int a;
    int b;

public:
	// i is assigned to a, j is assigned to b
    MyClass(int i, int j) : a(i), b(j)  ⭐
    {
        // data assigned a=i, b=j, without actually defining assignment in body
    }
};
```

**Order of Initialization:** The order of initialization in the initializer list follows the **declaration order** of class members, not the order in the list itself. ⭐

**Case 1: Modification of argument in the body**:

```cpp
MyClass(int i, int j) : a(i), b(j) {
	i++, ++j;
}
```

* Final values of `a=i` and `b=j` are captured by the initializer list.
* Modifications to `i` and `j` in the body do **not** affect the already-initialized `a` and `b`.

**Case 2: Using Post-incremented `i++` for `a` and Pre-incremented `++j` for `b`**

```cpp
MyClass(int i, int j) : a(i++), b(++j)
```

* Final value of `a=i` and `b=j+1`
* **Post-increment** means assigned then increment, **Pre-Increment** means increment then assigned

**Case 3: Using incremented `i` for `a` and a relation for `b`**:

```cpp
MyClass(int i, int j) : a(i), b(a+j)
```

* Final value of `a=i` and `b=a+j`
* `a` is initialized first with `i` and then `b` is initialized using the already-initialized value of `a` and `j`.

**Case 4: Order mismatch in declaration and initializer list:**

```cpp
MyClass(int i, int j) : b(j), a(i+b)
```

* Final value of `a=i+garabage value` and `b=j`
* Even though `b` is listed before `a` in the initializer list, `a` is declared before `b` in the class.

***

#### Pointers to Objects

```cpp
class MyClass{
	public:
		int a;
		int func();
}
```

Actual object

```cpp
MyClass obj;

// Accessing class member using dot operator
obj.a;
obj.func();
```

Pointer to Object

```cpp
MyClass *ptr = new MyClass;

// Access class member using dot operator
(*ptr).a; // same as obj.a
(*ptr).func() // same as obj.func()

// Access class member using arrow operator
ptr->a; // same as (*ptr).a
ptr->func() // same a (*ptr).func()
```

* It is important to use `()` because, precedence of `.` is more than `*` ⭐
* The arrow operator (`->`) in C++ can be thought of as a combination of dereferencing a pointer and using the dot operator to access a member of a class or structure

**Array of Objects**

```cpp
MyClass objArr[3]; // 3 elements -> 3 instance
// Accessing using dot operator
objArr[0].a
objArr[1].a
objArr[2].a
```

```
┌-----------┬-----------┬-----------┐
| objArr[0] | objArr[1] | 0bjArr[2] |
└-----------┴-----------┴-----------┘
```

* dynamically allot block of `size` x `memory`( required for 1 object )

```cpp
MyClass *ptrArr = new MyClass[3]; // Complex arr[]

// Accessing using dot operator
(*ptrArr).a; // same as objArr[0].a
(*(ptrArr+1)).a; // same as objArr[1].a

// Accessing using arrow operator
ptrArr->a; // same as (*ptrArr).a
(ptrArr+1)->a;// same as (*(ptrArr+1)).a
ptrArr+1->a;// paranthesis '()' is optional.
```

* paranthesis `()` is optional as, precedence of `+` is more than `->` ⭐

**`this` pointer** -> Refer to the object

* `this` is a keyword which is a pointer which points to the object which invokes the member function.
* If you want to return an object, using `this` is the only way.

```cpp
class MyClass{
	int a;
	int b;
	public:
		MyClass& rtrnObj(int a, int c){ 
			
			this->a = a; // explicit call `this->a`
			// data member = local variable
			
			b = c // Implicit call `this->b`
			// data member = local variable

			return *this // *this => value of this
			// this => pointer => address of object
		}
}

int main(){
	MyClass obj;
	MyClass obj2 = obj.rtrnObj(4,5); 
	// return a object with a=4, b=5
	MyClass obj3 = obj.rtrnObj(4,5).rtrnObj(6,7)
	// return a object with a=6, b=7
	return 0;
}
```

**Use case Example (pointer and array)**

```cpp
class ShopItem
{
    int id;
    float price;
    public:
        void setData(int a, float b){
            this->id = a;
            this->price = b;
        }
};
```

```cpp
int main(){
    int size = 3;
    ShopItem *ptr = new ShopItem [size];
```

```
address  0  1  2
		 ^
		 ptr  
```

```cpp
	int id;
    float price;
    for (i = 0; i < size; i++)
    {
        cout<<"Enter Id and price of item "<< i+1<<endl;
        cin>>id>>price;
        ptr->setData(id, price);
        ptr++;
    }
```

```
address  0  1  2
		       ^
		       ptr  
```

```
}
```

#### **Polymorphism**

“Poly” means several and “morphism” means form.

```
                         Polymorphism
                         /         \
                        /           \
                 Compile-time      Run-time
                 /       \               \
                /         \               \ 
          Function       Operator         Virtual
        Overloading    Overloading        Function
```

**Compile Time Polymorphism**

* **Compile time** -> The compiler determines which method or operator to invoke based on the function signature or operator context at compile time.
* **Early binding (`Static Binding`)** -> Resolved during compilation.
* **Achieved through `overloading` (Ad-hoc Polymorphism)** -> works within the same class and allows multiple functions (with the **same name** but **different parameter** lists)

**Run Time Polymorphism**

* **Run time** -> The method to invoke is determined during runtime based on the actual type of the object, even if it is accessed through a base class pointer or reference.
* **Late binding (`Dynamic Binding`)** -> Resolved during execution.
* **Achieved through `overriding`** -> works across base and derived classes and requires the use of virtual functions in the base class (with **same signature**)

Note: The run time polymorphism is considered slow because function calls are decided at run time

**Pointer to Derived Class**

```cpp
// Base Class
class BaseClass{
	public:
		var_base;
		void display(){...}; // non-virtual
}
// Derived Class
class DerivedClass : public BaseClass {
	public:
		int var_derived;
		void display(){...};
}
```

**Base Class Pointer to Derived Class Object (Upcasting)**:

```cpp
BaseClass *base_class_ptr; // Base Class Pointer
DerivedClass obj_derived; // Derived Class object

// Base Class pointer pointing to Derived object
base_class_pointer = &obj_derived; 

// Variable
base_class_pointer->var_base; // BaseClass::var_base
base_class_pointer->var_derived ; // DerivedClass::var_derived

// Function
base_class_pointer->display(); // BaseClass::Display()
```

1. **Base Class Pointer to Base Class Object** & **Derived Class Pointer to Derived Class Object** -> same as there object.
2. **Base Class Pointer to Derived Class Object**(upcasting) -> Same as Base Class Object + Polymorphism (if virtual functions are used) ✅

* it can invoke overridden functions in the Derived class via virtual functions

1. **Derived Class Pointer to Base Class Object**(downcasting) -> Cannot Point ( because the Base class does not have the additional members or methods of the Derived class). ❌⭐

**Virtual Function**

* **Virtual Function** -> A member function in the base class which is **declared using virtual keyword** is called virtual functions.
* \==Virtual allow derived classes to **override** methods from a base class== so that the correct method is called, depending on the type of object, even when the call is made through a base class reference or pointer.
* **Use of Virtual Function :**
  * if not exist in base class -> you can’t call it using a base class pointer.
  * If a derived class not override -> the base class implementation is used, avoiding errors.

```cpp
// Base Class
class BaseClass {
public:
    virtual void display() { /*...*/ } // virtual function
};

// Derived Class
class DerivedClass : public BaseClass {
public:
    void display() override { /*...*/ } // override keyword after function signature
};

```

```cpp
BaseClass * base_class_pointer;
DerivedClass obj_derived;

base_class_pointer = &obj_derived; 

// Due to Virtual Function
base_class_pointer->display(); // DerivedClass::Display()
```

`virtual` keyword make sure that when the **virtual** function is called by using the base class pointer the `overriden` function of the derived class will run ⭐

\==`override` keyword ensures that the compiler checks whether a method in a derived class is **actually overriding** a virtual method== even If you accidentally change the method signature in the derived class. `override` Ensure correct matching, Catch typos, Avoid silent bugs.

**virtual functions can be overridden without the `override` keyword**, but using `override` is **strongly recommended**.

Note:

* If function **not declared virtual**, it will be resolved at **compile time** based on the type of the object or pointer/reference.
* **constructors cannot be virtual** in C++.

**Without `override` Keyword ⭐**

```cpp
class Base {
public:
    virtual void show1() const {}
    virtual void show2() const {}
    virtual void show3() {}
};

class Derived : public Base {
public:
    void show1() const {}  // OK: matches exactly
    void show2() {}        // ⚠️ Silent Bug: missing const → not overriding
    void showi() {}        // ⚠️ Typo: not overriding, silently creates new function
};
```

**With `override` Keyword**

```cpp
class Base {
public:
    virtual void show1() const {}
    virtual void show2() const {}
    virtual void show3() {}
};

class Derived : public Base {
public:
    void show1() const override {}  //  OK: matches exactly
    void show2() override {}   // ✅ Error caught -> Compile Error: missing const
    void showi() override {}  // ✅ Error caught -> Compile Error: no function to override
};
```

**Function Signature Include:**

1. Function name
2. No. of Parameter + Its Types
3. `const` qualifier (if member function)

**Function Signature Don't Include:**

1. Return type
2. Parameter names
3. `static` keyword
4. `virtual` keyword

**Use of `const` Qualifier ⭐**

* `const` helps prevent accidental changes to data
* `const` after a function promise not to change object state and so it **cannot modify any member variables** of the object.
* `const` also allows calling the function on `const` objects:

```cpp
class Test {
    int x;
public:
    void show1() const { 
        x = 10; // const -> ❌ Error: can't modify member
    }
    void show2(){
	    x = 10; // ✅ Ok as show() is not const
    }
};

const Test t;
t.show1() // ✅ OK as show() is const
t.show2() // Not const → ❌ can't call on const object
```

***

**Pure Virtual Functions**

**Pure virtual function** -> function that doesn’t perform any operation

* it is declared by assigning the value `zero` to virtual function i.e. `virtual void func()=0`
* declaring a function as `display() = 0;` without the `virtual` keyword and outside of a class is not valid.
* It make necessary for the Derived Class to override the virtual function and thus Abstraction class

```cpp
MyClass{
	public:
		virtual void MyFunc()=0 // Pure virtual function.
};
```

**Abstract Base Class**

**Abstract base class** -> class that has ==at least one pure virtual function in its body==.

* The classes which are inheriting the base class must need to override the virtual function of the abstract class **otherwise compiler will throw an error.**
* You can't Create Instance or Object of abstract class.
* Virtual function can't be called directly from abstract class `MyClass::virtualFunc()` (compilation error)
* Non virtual function can be called directly from abstract class `MyClass::NonVirtualFunc()` .

***

The End ❌

***

***

#### Key Points

* In **C++**: `func()` and `func(void)` → both mean no parameters
* In **C**: `func()` → unknown arguments, `func(void)` → no argument

**`static` Members**

* Can be called without creating an object
* Default value: `0` (unlike local variables)
* Share **common memory** across all objects
* Can be declared in the `private` section of class

**Access Specifiers**

* `private`, `protected` → can't be accessed outside the class directly
* Accessible through **class functions**
* `protected` → accessible in derived class, treated as `private`
* `friend` function → can access both `private` and `protected`

**Constructors**

* Default Constructor: `MyClass obj;`
* Constructor with default arguments: `MyClass obj;`
* **Wrong:** `MyClass obj();` → interpreted as function declaration

**Constructor Overloading**

```cpp
class MyClass {
public:
	MyClass() { }                          // 1. ❌ Conflict with 5
	MyClass(int a) { }                     // 2. ❌ Conflict with 4
	MyClass(int a, int b) { }              // 3. ❌ Conflict with 5
	MyClass(int a, int b = 0) { }          // 4. ✅ obj4(5), obj4(5,10)
	MyClass(int a = 0, int b = 0) { }      // 5. ✅ obj5; obj5 = MyClass()
	MyClass(char) { }                      // 6. ✅ obj6('a')
};
```

**Copy Constructor & Destructor**

* Custom Copy Constructor: `MyClass(MyClass &obj) { a = obj.a; }`
* Custom Destructor: `~MyClass() { cout << "destructor called"; }`
* Both are provided by default
* Copy constructor auto-called on `MyClass obj2(obj1)`
* Destructor auto-called at object end of scope

**Inheritance**

```cpp
class A : public C { };  // A inherits from C
```

* Modes: `private` (default), `protected`, `public`
* `private` members → not inherited
* Inheritance Access Changes:

| Base \ Derived | private | protected | public    |
| -------------- | ------- | --------- | --------- |
| private        | ❌       | ❌         | ❌         |
| protected      | private | protected | protected |
| public         | private | protected | public    |

**Ambiguity in Inheritance (Without `virtual` base)**

```
        A
     (int x)
    /      \
   B        C
(x from A)(x from A)
    \      /
       D
(x?) → ❌ Ambiguity                
```

**Virtual Base Class (Solution)**

* To solve this ambiguity we will make class `A` as a virtual base class.
* `virtual` keyword is used during inheritance. not when defining the base class.
* Order of `virtual` & `visibility` doesn’t matter.

```cpp
class A {...};

class B : public virtual A {...}; // virtual inheritence
class C : virtual public A {...};  // virtual inheritence 
class D : public B, public C {...};  // Single instance of A in D
```

* Now class `D` inherits a single instance of `A` through `B` and `C`, preventing ambiguity.

**Constructor**

* constructor is **not inherited** in the derived class, if the visibility mode of the base class constructor is not `public`
* Parameterized constructor of the base class **must explicitly call** in Derived class and pass argument to use it ⭐

```cpp
class Derived:public Base{
	public:
		Derived(int x) : Base(x) {...}
		// Explicitly call the base class constructor with an argument
}
```

**Constructor Call Order**

* Rule 1: Virtual Base Class -> Base Class -> Derived Class
* Rule 2: Order of Declaration

\*\*Special Syntax : Passing Args to Multiple Base Classes

```cpp
// Derived Class From A and B
class C : public A, public B {
	// Derived class constructor pass the calls to respective base class coonstructor ⭐
	C(int x, int y, int z) : A(x, y), B(z) {...} };
```

**Initialization list in Constructor**

```cpp
// data assigned a=i, b=j, without actually defining assignment in body
class MyClass
{
    int a;
    int b;
	// i is assigned to a, j is assigned to b
	MyClass(int i, int j) : a(i), b(j) {...}};
```

**Order of Initialization should follow order of Declaration** of class members not the order in the list itself.

**Object Pointer & Array**

**Pointer to Object**

```cpp
// Object Pointer
MyClass *ptr = new MyClass;
// Access class member using arrow operator
ptr->a; // same as (*ptr).a
ptr->func() // same a (*ptr).func()

// Object Array
MyClass *ptrArr = new MyClass[3]; // Complex arr[]
// Accessing using arrow operator
ptrArr->a; // same as (*ptrArr).a and so objArr[0]
ptrArr+1->a; // same as (*(ptrArr+1)) and so objArr[1]
```

**Precedence**: `.` > `*` > `+` > `->`

**Polymorphism**

```
                           Polymorphism
                         /              \
                        /                 \
               Compile-time               Run-time
            (Static/Early Binding)    (Dynamic/Late Binding)
                /       \                  |
               /         \                 |
      Function        Operator         Function
     Overloading     Overloading       Overriding
   - Different       - Redefine       - Same signature
     signatures        operators        in base & derived
   - Resolved at     - At compile     - Uses virtual
     compile time       time            functions
```

**Base Class Pointer can point to Derived Class Object -> Upcasting**:

```cpp
Base *bp; // Base Class Pointer
Derived d; // Derived Class object

// Base Class pointer pointing to Derived object
bp = &d;
```

```cpp
// Variable
base_class_pointer->var_base; // BaseClass::var_base
base_class_pointer->var_derived ; // DerivedClass::var_derived

// Function
base_class_pointer->display_base(); // BaseClass::Display()
base_class_pointer->display_derived(); // BaseClass::Display()
```

```
             Base Class Pointer to Derived Class object
                 /                           \
                /                             \
       Base Class function called        Derived Class function called
                                        (if virtual functions are used) ✅
```

* it can invoke overridden functions in the Derived class via virtual functions
* Downcasting ❌ (unsafe without cast)

**Virtual Function**

* Virtual function is a member function in the base class declared using virtual 'keyword'.
* Virtual function allow derived classes to **override** methods from a base class so that the correct method is called, depending on the type of object, even when the call is made through a base class reference or pointer.

```cpp
// Base Class
class BaseClass{
	public: virtual void display(){...};} // virtual function

// Derived Class
class DerivedClass : public BaseClass {
	public: void display override (){...};} // override virtual function
```

`override` Ensure correct matching, Catch typos, Avoid silent bugs.

**Function Signature Include:**

1. Function name
2. Parameter types
3. `const` qualifier (if member function)

**Use of `const` Qualifier** ⭐

* `const` helps prevent accidental changes to data
* `const` after a function promise not to change object state and so it **cannot modify any member variables** of the object.
* `const` also allows calling the function on `const` objects:

**Pure Virtual Function**

* it is declared by assigning the value `zero` to virtual function i.e. `virtual void func()=0`
* It make necessary for the Derived Class to override the virtual function and thus Abstraction class

**Abstract base class**

* Abstract class - class that has at least one pure virtual function in its body.
* The classes which are inheriting the base class must need to override the virtual function of the abstract class **otherwise compiler will throw an error.**
* You can't Create Instance or Object of abstract class.
* Virtual function can't be called directly from abstract class `MyClass::virtualFunc()` (compilation error)
