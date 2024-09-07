Object-Oriented Programming (OOP) is a programming paradigm based on the concept of "objects," which contain data and methods. OOP principles are key for creating structured and reusable code. The four main principles of OOP are:

### 1. **Encapsulation**
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

### 2. **Inheritance**
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

### 3. **Polymorphism**
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

### 4. **Abstraction**
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

### Summary
- **Encapsulation:** Protects object data through access restrictions.
- **Inheritance:** Allows one class to inherit properties and methods from another.
- **Polymorphism:** Enables methods to do different things based on the object.
- **Abstraction:** Simplifies complex systems by showing only the necessary parts.

These principles work together to create flexible, modular, and reusable code, which is the essence of object-oriented programming.