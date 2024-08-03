
## Procedure Oriented Programming (POP)
- large problems are divided into smaller problems known as functions
- program is written as sequence of procedure or function
- Each procedure contains a series of instructions for performing specific task.
- During the program execution each procedure (function) can be called by the other procedure
- To call procedure, we have to write function name only
- we concentrate on functions and gives very little attention to the data that are being used by functions.
- The major emphasis is on `PROCEDURE` and not on the data.
- In a multi-function program, many important data items are placed as `global` so that they may be accessed by all the function ( and each functions may have its own local data)
- Global data are more vulnerable to an accidental change by a function. In a large program it is very difficult to Identify what data is used by which function.
- *Example :* of POP languages `C, Cobol, Fortan, Pascal`
## Object Oriented Programming (OOP)
- OOP treats data as critical element in the program development and does not allow it to flow freely around the system.
- Major emphasis is on `DATA` rather than `PROCEDURE`
- it **ties data** more closely to the function that operate on it, and protects it from accidental modification from outside function
- Oop allow decomposition of a problem into a number of entities called `objects` and then builds data and function around these objects.
- The data of an object can be accessed only by the function associated with that object. (However the function of one object can access the function of other object)
-  *Example :* `C++, Java, Python, Dot net`

| OOP                                                 | POP                                                   |
| --------------------------------------------------- | ----------------------------------------------------- |
| Object Oriented                                     | Structural Oriented                                   |
| Program is divide into objects                      | Program is divide into functions                      |
| Bottom-Up Approach                                  | Top-Down Approach                                     |
| Inheritance property is used                        | Inheritance property is not allowd                    |
| It uses access specifier                            | It doesn't uses access specifier                      |
| Encapsulation is used to hide the data              | No data hiding                                        |
| Concept of Virtual Function                         | No virtual function                                   |
| Object functions are linked through message passing | Parts of program are linked through parameter passing |

### Feature of OOPS
1. Class
2. Object
3. Data Binding
4. Encapsulation 
5. Data Abstraction
6. Inheritance
7. Polymorphism
8. Message Passing

### 4-Principle of OOP
1. Encapsulation
2. Inheritance
3. Abstraction
4. Polymorphism

#  [#20 Object Oriented Programming in C++](https://www.youtube.com/watch?v=nGJTWaaFdjc&list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9&index=1&pp=iAQB)

### Why OOPS?
- C++ language was designed with the main intention of adding object-oriented features to c languages
- As the size of the program increases, readability, maintainability and bug-free nature of programs decreases
- This was the major problem with the languages like c which work upon functions or procedure (hence the name procedural programming languages)
- As a result, the possibility of not addressing the problem in an affective manner was high.
- Also, as data was almost neglected, data security was easily compromised.
- Using classes solves this problem by modelling programs as real world scenario

### Procedure Oriented Programming
- consists of writing a set of instructions for the computer to follow
- Main focus is on functions and not on flow of data
- functions can either use local or global data
- Data moves openly from function to function

### Object Oriented Programming
- works on the concepts of classes and objects
- A class is a template to create objects
- Treats data as a critical element (private/public concept)
- Decomposes the problem in objects and build data and functions around the objects

![OOP vs POP Diagram ](https://d8it4huxumps7.cloudfront.net/bites/wp-content/banners/2023/7/64c0c9e8d26d0_oop_vs_pop_.jpg)

### Basic Concepts in OOP
- **Classes -** Basic templates for creating objects
- **Objects** - Basic run time entities
- **Data Abstraction and Encapsulation** - Wrapping data and functions into single unit.
- **Inheritance** - Properties of one class can be inherited into others
- **Polymorphism** - Ability to take more than one forms ( same function for area of square and circle)
- **Dynamic Binding** - code which will execute is not known until the programs run
- **Message Passing** - Object message (information) call format

# [#21 Classes, Public and Private access modifiers in C++](https://youtu.be/tL8vnfFFzVQ?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)


***Class Example*** :
```cpp
#include <iostream>
using namespace std;
```

```cpp
// 
class Employee{
    private:
        int a, b, c;
    public:
        int d, e;
        void setdata(int a1, int b1, int c1);
        void getData(){
            cout<<"The value of a, b, c, d"<<a<<b<<c<<d<<endl;
        }
};
```

```cpp
// Define function outside Class
void Employee:: setData (int a1, int b1, int c1){
    a = a1, b = b1, c = c1;
}
```

```cpp
int main(){

    Employee harry;
   // harr.a = 69 -> error ❌ Can't access private data (a, b, c) directly 
    harry.d = 134; 
    harry.e = 89; 
    harry.setData(1,2,4); // ✅ accessing private data (a, b, c) through function. harry.a=1, harry.b=2, harry.c=4 
    harry.getData(); // 

    return 0;
}
```

***Key Learning :***
- Definition of Class `class <Class_Name> { . . .};`
- Access Specifier `public:` and `private:`
- Declare and Define `myFunc(){. . .}` inside Class Definition
- Declare `myFunc()` inside Class, Define   `myClass::myFunc(){. . .}` outside Class
- also, Declare `count` inside Class, Define `myClass::count =0` outside Class
- Create Object Instance `myClass myObject`
- Access data members `myObject.myData` ( Note if only public )
- Access function members `myObject.myFunc()`
- Class Definition end with a semicolon `;`

***Class Syntax :***
```cpp
class myClass{
accessSpecifier: // private, public or protected
	myData;  // variable
	myFunc(){. . .}; // method to access the data members
}; // end
```

# #22 Nesting of Member Functions

// Member functions declarations
```cpp
class binary{
	string s;
	void chk_bin(void);
	public :
		void read(void);
		void compliment(void);
		void display(void);
};
```

// Member Functions definition
```cpp
void binary::read(void){
	cout<<"Enter a binary no." <<endl;
	cin>>s;
}
```
```cpp
void binary::chk_bin(void){
	for(int i=0; i<s.length(); i++){
		if(s.at(i)!='0' && s.at(i)!='1'){
			cout<<"incorrect binary format"<<endl;
			exit(0);
		}
	}
}
```
```cpp
void binary::compliment(void){
	chk_bin(); // function `Chk_bin()`  Nested inside `compliment`
	for(int i=0; i<s.length(); i++){
		if(s.at(i)=='0') s.at(i)=`1`;
		else s.at(i)='0';
	}
}
```
```cpp
void binary::display(void){
	for(int i=0; i<s.length(); i++){
		cout<<s.at(i);
	}
	cout<<endl;
}
```

```cpp
int main(){
	binary b;
	b.read(); // Input(b.s)
	// b.chk_bin() -> error ❌, Can't Access private function directly
	b.display(); // print(string s)
	b.compliment(); // ✅ Accessing private function through another function. chkbin():check if binary -> ifs.at(i)=='0' -> s.at(i)=`1` vice versa.
	b.display();
	
	return 0;
}
```

***Key Learning :
- Private Data Member Can't be Access Directly 
	- It Can be accessed using member Function ( note:- it should be present in function declaration)
- Private Member  function Can't be Access Directly
	- It can be accessed using another member Function (it should be nested in other function)

# #23 Object memory Allocation and using array in class

- `Variable` in class get their `own memories`
- member `function` in class have `common memories` for different objects 

```
Class | Memory Diagram
__________________________________
| Object 1 | Object 2 | Object 3 |
|    i     |   i      |    i     |
|    a     |   a      |    a     |
|    b     |   b      |    b     |
|--------------------------------|
|  f1()   f2()    f3()           |
|________________________________|
```

```cpp
Class shop{
	int itemID[100]; // array
	int itemPrice[100]; // array
	int counter;
	publid:
		void initCounter(void){ counter = 0;}
		void setPrice(void);
		void displayPrice(void);
};
```

```cpp
void Shop::setPrice(void){
	cin>>ItemId[counter]>>ItemPrice[counter];
	counter++;
}

void shop::displayPrice(void){
	for(int i=0; i<counter; i++){
	cout<<itemId[i]<<itemPrice[i];
	}
}
```

```cpp
int main(){
	shop dukaan;
	dukaan.initCounter(); // dukaan.counter = 0;
	dukkan.setPrice();  // Input(ItempId[0], ItemPrice[0]), counter++
	dukaan.setPrice();  // Input(ItempId[1], ItemPrice[1]), counter++
	dukaan.setPrice();  // Input(ItempId[2], ItemPrice[2]), counter++
	dukaan.displayPrice(); // print(ItemId[0], ItemPrice[0])..... ItempId[2], ItemPrice[2])
	return 0;
}
```
***Key Learnings:***


# OOPs - Classes & Objects

- C++ initially called -> C with classes by Stroustroup
- Classes -> extension of structures (in C)
	- Structures had limitations
		- members are public
		- no methods
- Classes -> structure + more
- Classes -> Can have methods and Properties
- Classes -> can make few members as private and few as public
- Structures -> in C++ are typedefined

You can declare objects along with the class declaration like this:
```cpp
Class Employee{
	//class definition
} harry, rohan, lavish;
```

# #24 Static Data Members and Methods

- A `Static Variable` have Common memory allocation for all objects in the class.
- A `static function` can have access to only other static member functions/variable declared in the same class

```cpp
class Employee{
	int id;
	// static int count = 100; error ❌ 
	static int count; // common memory allocation for all objects
	public:
		void setData(void){ cin>>id, count++ }
		void getData(void){ cout<<id;}
		// static void getCount(void){ cout<<id;} error ❌ `id` is not static
		static void getCount(void){ cout<<count;} ✅ // `count` is static
};
```
```cpp
// int Employee::count = 100; ✅
int Employee::count; // Default value is zero `count=0`
```
```cpp
int main(){
	Employee harry, rohan , lavish;
	harry.setData(); // input(lavish.id), count=1
	harry.getData(); // print(count)
	rohan.setData(); // input(lavish.id), count=2
	rohan.getData(); // print(count)
	lavish.setData(); // input(lavish.id), count=3
	lavish.getData(); // print(count)

	Employee::getCount(); // count = 3
}
```

***Key Learnings :***
- A Static function can't access non-static function/variable
- Declare `count` inside Class, Define `Employee::count` outside Class
- Default value is `zero` for all static variable
- A Static function can be called without mentioning object name by class `Employee::getcoutn()`


Doubts:-
One line function can be declared without { }
why need static variable/functions
s.at(i)
exit(0)