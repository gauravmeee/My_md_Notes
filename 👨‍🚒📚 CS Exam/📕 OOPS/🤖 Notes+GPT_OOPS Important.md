# 🤖 Notes+GPT\_OOPS Important

**Access Specifier**

* We can directly access public function and data of a class using `object dot notation`
* We can't access private data directly, for this we should use a member function.
* when declaring a function/constructor inside a class , you have the option to **omit parameter names** and only specify their data types

**Nesting of Member Function**

* Through nested/call of private member function into public member function, we can use it to access.

**Object Memory Allocation**

* Data members of each instance or object of class take separate memory storage, while member function memory is common for all objects of a class.

You can declare objects along with the class declaration like this:

```cpp
Class Employee{
	//class definition
} harry, rohan, lavish;
```

**Static Member**

* **Static members** are shared among all instances of a class, meaning they belong to the class itself, not to any particular object. Delclared inside using `static` keyword
* **Static functions** also belong to class itself and limited to accessing **only static members** of the class, provide class level access and restrict operations on object-specific data.
* we can access static member on class level using`ClassName::static_member` along with `object.static_member`

**Array Of objects**

It is hectic to create many object that have similar work, than we can create Array of Objects `ClassName arr[3]`

**Passing objects as Arguments**

We could use objects as a arguments using individual `Funct(obj1, obj2)` or member `Obj3.member_func(obj1,obj2)`

**Friend Function**

function that is not a member of a class but has access to its private and protected members. **friend functions** are declared **inside the class** (with `friend` keyword before datatype )but **defined outside**

**Inheritence**

* Visibility mode public -base class public member would public member of derived class
* private(default) -base class public member will be private of derived
* private of base not inherited directly
*
  * **Private**: Accessible only within the class itself, **not** in derived classes.
* **Protected**: Accessible within the class and its **derived classes**, but **not** outside the class.

***

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects," which contain data and methods. OOP principles are key for creating structured and reusable code. The four main principles of OOP are:

#### 1. **Encapsulation**

Encapsulation is the bundling of data (variables) and methods (functions) that operate on the data into a single unit or class. It restricts direct access to some of the object's components, which is a means of preventing accidental interference and misuse of the data.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public:
    void setDimensions(int l, int b) {
        length = l;
        breadth = b;
    }

    int getArea() {
        return length * breadth;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(5, 10);
    cout << "Area: " << rect.getArea() << endl;
    return 0;
}
```

In this example, the `length` and `breadth` variables are private and cannot be accessed directly from outside the class. Instead, they are manipulated through public methods (`setDimensions` and `getArea`).

#### 2. **Inheritance**

Inheritance is a mechanism where a new class (derived class) is created from an existing class (base class). The derived class inherits the attributes and behaviors (methods) of the base class, which promotes code reusability.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited from Animal class
    myDog.bark(); // Defined in Dog class
    return 0;
}
```

In this example, `Dog` inherits the `eat` method from `Animal` and also defines its own method `bark`.

#### 3. **Polymorphism**

Polymorphism means "many forms," and it allows objects to be treated as instances of their parent class. There are two types of polymorphism: compile-time (method overloading and operator overloading) and run-time (method overriding).

**Example (Run-time Polymorphism):**

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->sound(); // Outputs: Woof!
    a2->sound(); // Outputs: Meow!

    delete a1;
    delete a2;
    return 0;
}
```

Here, the `sound` method is overridden in the `Dog` and `Cat` classes, allowing the same method name to behave differently based on the object type.

#### 4. **Abstraction**

Abstraction involves hiding complex implementation details and showing only the essential features of an object. It can be achieved using abstract classes (classes that cannot be instantiated) or interfaces.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->draw(); // Outputs: Drawing Circle
    s2->draw(); // Outputs: Drawing Rectangle

    delete s1;
    delete s2;
    return 0;
}
```

In this example, `Shape` is an abstract class with a pure virtual function `draw`. The `Circle` and `Rectangle` classes implement this function, allowing us to use the `draw` method in a more general way.

#### Summary

* **Encapsulation:** Protects object data through access restrictions.
* **Inheritance:** Allows one class to inherit properties and methods from another.
* **Polymorphism:** Enables methods to do different things based on the object.
* **Abstraction:** Simplifies complex systems by showing only the necessary parts.

These principles work together to create flexible, modular, and reusable code, which is the essence of object-oriented programming.

***

#### Free Function vs Member Function

* **Class Member Functions:**
  * The order of function declarations within a class does not matter.
  * As long as a function is declared somewhere in the class definition, it can be called from anywhere within the class.
  * This flexibility is due to the class definition acting as a forward declaration for all its member functions.
* **Free Functions:**
  * Free functions must be declared before they are called.
  * If a free function is called before its declaration, the compiler will not recognize it, resulting in a compilation error.

Note: Function inside a Class -> Method.

#### Struct vs Class

| Feature               | struct                            | class                                    |
| --------------------- | --------------------------------- | ---------------------------------------- |
| Default member access | public                            | private                                  |
| Default inheritance   | public                            | private                                  |
| Use cases             | POD types, simple data structures | Encapsulation, inheritance, polymorphism |
| Encapsulation         | Less emphasis                     | More emphasis                            |

#### Methods to Access Object Members

| Syntax      | Description                                                    |
| ----------- | -------------------------------------------------------------- |
| `node.val`  | Direct member access using a dot operator for objects.         |
| `node->val` | Member access using an arrow operator for pointers to objects. |

#### Derived Private vs Protected vs Public member

| Access Specifier | Access Level | Accessible from within the same class | Accessible from derived classes | Accessible from outside the class |
| ---------------- | ------------ | ------------------------------------- | ------------------------------- | --------------------------------- |
| `private`        | Restricted   | Yes                                   | No                              | No                                |
| `protected`      | Limited      | Yes                                   | Yes                             | No                                |
| `public`         | Unrestricted | Yes                                   | Yes                             | Yes                               |
