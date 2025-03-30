
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
-  *Example :* `C++, Java, Python, .NET`

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
OOPS Follow DRY!
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
- Using classes solves this problem by modelling programs as real world scenario.

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

# Access Specifiers

***Class Syntax :***
```cpp
class myClass{
accessSpecifier: // private, public or protected
	myData;  // variable
	myFunc(){. . .}; // method to access the data members
}; // end
```


***Class Example*** :
```cpp
#include <iostream>
using namespace std;
```

```cpp 
class Employee{    
    private:   // private data
        int a, b, c;
    public:   // public data
        int d, e;
        // setdata() function declaration
        void setdata(int a1, int b1, int c1);  

		// getData() function declaration + definiton
        void getData(){  
            cout<<"The value of a, b, c, d"<<a<<b<<c<<d<<endl;
        }
};
```

```cpp
// Define function outside Class
// dataType className :: functionName () {...}
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
- also, Declare `count` inside Class, Define `myClass::count =0` outside Class (`::` Scope Resolution Operator)
- Create Object Instance `myClass myObject`
- Access data members `myObject.myData` (only public )
- Access function members `myObject.myFunc()` ( only public )
- Class Definition end with a semicolon `;`


| Specifier     | Same Class | Derived Class | Outside Class |
| ------------- | ---------- | ------------- | ------------- |
| **Private**   | Yes        | No            | No            |
| **Protected** | Yes        | Yes           | No            |
| **Public**    | Yes        | Yes           | Yes           |

# [#22 OOPs Recap & Nesting of Member Functions in C++ | C++ Tutorials for Beginners](https://youtu.be/d363dW0AeS8?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

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
void binary::chk_bin(void){ // chck_bin declaration
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
	chk_bin(); // function Chk_bin()  Nested inside compliment()
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
	// b.chk_bin() ❌ Error: Can't Access private function directly
	b.display(); // print(string s)
	
	b.compliment(); // ✅ Accessing private function (chk_bin()) through another function.
	b.display();
	return 0;
}
```

***Key Learning :
- Private Data Member Can't be Access Directly 
	- It Can be accessed using member Function ( note:- it should be present in function declaration)
- Private Member  function Can't be Access Directly
	- It can be accessed using another member Function (it should be nested in other function)
	- when declaring a function/constructor inside a class , you have the option to **omit parameter names** and only specify their data types. However, in the **definition** of the function you need to include both the data types and the parameter names.

# [#23 # C++ Objects Memory Allocation & using Arrays in Classes | C++ Tutorials for Beginners](https://youtu.be/qq05D2yFIHA?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

# Object Memory allocation 

- `Variable` in class get their `own memories`
- member `function` in class have `common memories` for different objects (unlike Data Members)

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
	public:
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
**OOPs - Classes & Objects: **
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

# [#24 Static Data Members & Methods in C++ OOPS | C++ Tutorials for Beginners](https://youtu.be/QcLI2zGVYFo?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

# Static Members

- A `Static Variable` have Common memory allocation for all objects in the class.
- A `static function` can have access to only other static member functions/variable declared in the same class

why need?
If you have a piece of data that should be shared across all instances of a class, you can declare it as a static variable. All objects of that class will share the same copy of this variable.

```cpp
class Employee{
	int id;
	// static int count = 1000; ❌ error
	static int count; // common memory allocation for all objects
	public:
		void setData(void){ cin>>id, count++ }
		void getData(void){ cout<<id;}
		// static void getCount(void){ cout<<id;} ❌ error: `id` is not static
		static void getCount(void){ cout<<count;} ✅ // `count` is static
};
```

Unlike non-static member function, **Static Function** of a class can be called without creating an instance (or object) of that class.
```cpp
// int Employee::count = 100; ✅
int Employee::count; // Default value is zero `count=0`
```

```cpp
int main(){
	Employee harry, rohan , lavish; // all three object share common count varibale
	
	harry.setData(); // count++, count=1
	harry.getData(); 
	
	rohan.setData(); // count++, count=2
	rohan.getData(); 
	
	lavish.setData(); // count++, count=3
	lavish.getData(); 

	// static functin can be called without mentioning object name by class.
	Employee::getCount(); // count = 3
}
```

***Key Learnings :***
- A Static function can't access non-static function/variable
- Declare `count` inside Class, Define `Employee::count` outside Class
- Default value is `zero` for all static variable
- A Static function can be called without mentioning object name by class `Employee::getcoutn()`

# [#25 Array of Objects & Passing Objects as Function Arguments in C++ | C++ Tutorials for Beginners](https://youtu.be/aKnc1A5NOKo?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

# Array of Objects 

It is hectic to create many object that have similar work, than we can create Array of Objects

```cpp
class Employee{
	int id;
	int salary;

	public:
		void setId (void){
			salary = 122;
			cin>>id;
		}
		void getId(void){
			cout<<id<<" "salary;
		}
};
```

```cpp
int main(){
	Employee arr[3]; // Employe arr[0], arr[1], arr[2]
	for(int i=0; i<3; i++){
		arr[i].setId(); 
		arr[i].getId();
		}
	return 0;
}
```

```
┌--------┬--------┬--------┐
| arr[0] | arr[1] | arr[2] |
└--------┴--------┴--------┘
```

```
// We could use above code in place of this Hard coding like this.

harry.setId;
harry.getId;

gaurav.setId;
gaurav.getId;

lovish.setId;
lovish.getId;
```

# Passing objects as Function Argument

```cpp
class Complex{
	int a;
	int b;
	public:
		void setData(int v1, int v2){
			a=v1;
			b=v2;
		}

		void setDataBySum(Complex o1, Complex o2){ // arguments are objects.
			a = o1.a + o2.a;
			b = o1.b + o2.b;
		}

		void printNumber(){
			cout<<"your Complex no."<<a<<"+"<<b<<"i"<<endl
		}
};
```

```cpp
int main(){
	Complex c1, c2, c3;
	
	c1.setData(1, 2);
	c1.printNumber(); // 1 +i2

	c2.setData(3,4);
	c2.printNumber(); // 3 + i4

	c3.setDataBySum(c1, c2);
	c3.printNumbers(); // 4 + i6

	return 0;
}
```

# [#26 Friend Functions in C++ | C++ Tutorials for Beginners](https://youtu.be/HK6gnkQIgqI?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

# Friend functions in C++

A friend function in C++ is a function that is not a member of a class but has access to its private and protected members. It is declared using the `friend` keyword within the class.

```cpp
class Complex{
	int a, b;
	public:
		void setNumber(int n1, int n2){
			a= n1;
			b = n2;
		}

	friend Complex SumComplex(Complex o1, Complex o2);
	// it give permission to non-member function i.e.  sumcomplex function is allowed to do anything with my private members.

	void printNumber(){
		cout<<"your number is "<<a<<"+"<<b<<"i"<<endl;
		}
};
```

```cpp
// friend function definition
Complex Sumcomplex(Complex o1, Complex o2){
	Complex o3;
	o3.setNumbers((o1.a + o2.a), (o1.b + o2.b));
	return o3;
}
```

```cpp
int main(){
	Complex c1, c2, sum;
	c1.setNumber(1,4);
	c1.printNumber(); // 1 + 4i
	
	c1.setNumber(5,8);
	c1.printNumber();  // 5+ 8i

	sum = sumComplex(c1, c2);
	sum.printNumber(); // 6 + 12i
	return 0;
}
```

**Properties of Friend Functions :**

1. Not in the scope of Class
2. Since it is not in the scope of the class, it cannot be called from the object of that class. `c1.sumComplex() = Invalid ❌`
3. Can be invoked without the help of any object
4. Usually contains the objects as argument ( so that we can access its private data). Without object as argument it is a normal funciton
5. `friend <type> <functionName>();` Can be declared inside of private section of the class. (there will not be any difference)
6. It cannot access the member directly by their names and need `object_name.member_name` to access any member

# [#27 Friend Classes & Member Friend Functions in C++ | C++ Tutorials for Beginners](https://youtu.be/Tk-4KUoatg8?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
class Complex // forward declaration of Complex class

class Calculator{
	public:
		int add (int a, int b){
			return(a+b);
		}

		// forward declaration of sumRealComplex() and sumComplex() Function
		int sumRealComplex(Complex,Complex); // we cannot write (complex o1, complex o2); because we didn't write its type during forward declaration
		int sumCompComplex(Complex, Complex)
};
```

```cpp
// Definiton of Complex Class (forward delcared above)
Class Complex{
	int a , b;
	// individually declaring functions as friend
	friend int Calculator :: SumRealComplex (Complex, Complex);
	friend int Calculator :: SumCompComplex (Complex, Complex);
	
	// Alter: Declaring the entire calculator class as friend.
	frienc class Calculator: // friend class

	public:
		void setNumber(int n1, int n2){
			a = n1;
			b = n2;
		}
		void printNumber(){
			cout<<"Your Number is " << a<<"+"<<b<<"i"<<endl;
		};

		// definitions of Calculator class member-functions (Above forward delcared) 
		int Calculator::sumRealComplex(Complex o1, Complex o2){
			return(o1.a + o2.a);
		}
		int Calculator::sumCompComplex(Complex o1, Complex o2){
			return(o1.b + o2.b);	
		}
	
}
```

```cpp
int main(){
Complex o1, o2;
o1.setNumber(1,4);
o2.setNumber(5,7);
Calculator calc;
int res = calc.sumRealComplex(o1,o2);
cout<<"The sum of real part of o1 & o2 is" << res <<endl;
int resC = calc.sumComplex(o1, o2);
cout << "The sum of complex part of o1 and o2 is"<< resC << endl;
return 0;
}
```

Forward Declaration
- it refers to the beforehand declaration of the syntax or signature or an identifier, variable, function, class, etc. prior to its usage ( Done later int the program)
- In C++, forward declarations are usually used for classes, in this, the class pre-defined before its use so that it can be called and used by other classes that are defined before this

# [28 More on C++ Friend Functions (Examples & Explanation) | C++ Tutorials for Beginners](https://youtu.be/GTJTsMR_fro?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)


# [#29 Constructors In C++ | C++ Tutorials for Beginners](https://youtu.be/EEJUPXFKe8Q?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)



**Constructor:**
- Constructor is a special member function with the same name as of the class.
- It si used to initialized the objects of its class
- It is automatically invoked whenever an object is created

```cpp
class Complex{
	int a, b;
	public:
		Complex(void); // constructor forward declaration
		void printNumber(){
			cout<<"Your number is " <<a<<"+"<<b<<"i"<<endl;
		}
};
```

```cpp
// Definiton of Default Cosntructor
Complex::Complex(void){
	a = 10;
	b = 20;
}
```

```cpp
int main(){
	Complex c1, c2, c3; // complex constructor automatically called on declaring object.
	c1.printNumber(); // Your number is 10 + 20i
	c2.printNumber(); // Your number is 10 + 20i
	c3.printNumber(); // Your number is 10 + 20i
	return 0;
}
```

**Characteristics of Constructors:**
- It should be declared in the public section of the class
- They are automatically invoked whenever the object is created 
- They cannot return values and do not have return type
- we cannot to their address
- It can have default arguments like normal functions.
- A default construct is constructor that takes no parameter

# [#30 Parameterized and Default Constructors In C++ | C++ Tutorials for Beginners](https://youtu.be/CYXIlh5DURI?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
Class Complex{
	int a, b;
	public:
		Complex(int,int); // Declaring parametrized constructor
		void printNumber(){
			cout<<"your Number is" << a<<"+"<<b<<"i"<<endl;
		}		
};
```

```cpp
// Definition of Parameterized constructor
Complex:: Complex(int x, int y){
 a=x;
 b=y;
}
```

```cpp
int main(){
	//implicit call
	Complex a(4,6); // constructor called on declaring object with argument
	a.printNumber(); // 4 + 6i

	//Explicit call
	Complex b = Complex(5,7); // Alternative way to call constructor
	b.printNumber(); // 5 + 7i
	return 0;
}
```

*Note:* It is necessary to initialize while creating object in constructor. Declaring in one line and Defining in other show error.

>Try it! :  From the class below Create a function (Hint: Make it a friend function) which takes 2 point objects and computes the distance b/w those 2 points.

```cpp
Class Point{
 int x, y;
 public:
	 // declared and defined
	 Point(int a, int b){
		 x = a;
		 y = b;
	}
};
```

```cpp
int main(){
 Point p(1,1);
 p.displayPoint();
 Point q(4,6);
 q.displayPoint();
 return 0;
}
```
# [#31 Constructor Overloading In C++ | C++ Tutorials for Beginners](https://youtu.be/7BmtA-7r1Fg?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
Class Complex{
	int a, b;
	public:
		Complex(int x, int y){
			a =x;
			b =y;
		}
	
	void printNumber(){
		cout<<"Your number is" <<a<<"+"<<b<<"i"<<endl;
	}

	Complex(int x){
		a = x;
		b =0;
	}

	Complex(){
		a=0;
		b=0;
	}
};
```

```cpp
int main(){
	Complex c1(4,6);
	c1.printNumber(); // 4 + 6i

	Complex c2(5);
	c2.printNumber(); // 5 + 0i

	Complex c3;
	c3.printNumber(); // 0 + 0i

	return 0;
}
```

# [#32 Constructors With Default Arguments In C++ | C++ Tutorials for Beginners](https://youtu.be/Ok-5YqcGl6c?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)


```cpp
Class Simple{
		int a,b,c;
	
	public:
		// default argument
		Simple(int x=3, int y=9, int z=12){
			a=x;
			b=y;
			c=z;
		}
		void printData();
};
```

```cpp
void Simple :: printData(){
	cout<<"The value of a, b and c are" << a<<", "<<b<<", "<<c<<endl;
}
```


```cpp
int main(){
	Simple s1; // Note we will not use s1()
	s1.printNumber(); // 3, 6, 9

	Simple s1(2);
	s1.printNumber(); // 2, 6, 9

	Simple s1(2, 4); // 2, 4, 9
	s1.printNumber();

	Simple s1(2, 4, 8); // 2, 4, 8
	s1.printNumber();

	return 0;
}
```

*Note:* 
If we want to use constructor without argument we need to use `Simple s1` not `Simple s()`.
it's not possible to create an object like `Simple s1;` and then explicitly call the constructor on the already created object in C++

# [#33 Dynamic Initialization of Objects Using Constructors | C++ Tutorials for Beginners](https://youtu.be/c_9oCs-9fvg?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
class BankDeposit{
	int principal;
	int years;
	float interestRate;
	float returnValue;

	public:
		BankDeposit(){} // this will do nothing but required. without it there will be 'ERROR'
		BankDeposit(int p, int y, float r); // float r
		BankDeposit(int p, int y, int r); // int r
		void show();
};
```

```cpp
// float r
BankDeposit :: BankDeposit(int p, int y, float r){
	principal =p;
	years =y;
	interestRate = r;
	returnValue = principal;
	for(int i=0; i<y; i++){
		returnValue = returnValue *(1+interestRate);
	}
}

// int r
BankDeposit :: BankDeposit(int p, int y, int r){
	principal =p;
	years = y;
	interestRate = float(r)/100;
	returnValue = principal;
	for(int i=0; i<y; i++){
		returnValue = returnValue *(1+interestRate);
	}
}
```

```cpp
int main(){
	BankDeposit bd1, bd2, bd3;
	
	int p = 100;
	int y = 1;
	float r = 0.03;
	int R = 3;
	
	
	// bd1.BankDeposit(p, y, r); ❌ // This is not allowed.

	bd1 = BankDeposit(p, y, r); // ✅ Create a temporary object 'BankDeposit(p, y, r); and assigned to bd1 is allowed
	
	bd1.show(); // 103
	
	bd2 = BankDeposit(p, y, R);
	bd2.show(); // 103

	bd3.show() // output garbage value 
	
	return 0;
}
```

*Note:*
- When other Constructors are Defined ( in Dynamic initialization) , The default constructor  or Blank Constructor (`BankDeposit() {}`) is also required to allow object creation without initial parameters. without it there will be compile error.
- Here, `bd1` and `bd2` is first created using the default constructor and then assigned a value using the parameterized constructor.
- Here, `bd3` created using the default constructor and then assigned garbage values.

# [Copy Constructor in C++ | C++ Tutorials for Beginners](https://youtu.be/jhZjyaNO4Wo?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
class Number{
	int a;
	public:
		Number(){a=0}
		Number(int num){ a = num; }
		
		// this is copy constructor
		Number(Number& obj){ 
			a=obj.a; 
			cout<<"Copy constructor called"<<endl
		}
		
		void display(){
			Cout<<"The no. for this object is" <<a<<endl;
		}
};
```

```cpp
int main(){
	Number x, y, z(45), y1, z1;
	
	x.display(); // 0
	y.display(); // 0
	z.display(); /// 45

	// Number z1(z); ❌ Error : object is declared already
	
	Number z2(z); ✅
	z2.display(); // 45

	Number y2(y);
	y2.display(); // 0
}
```

*Note:*
**Default Copy Constructor :**

if the user define copy constructor is not declared & define, there will be no error in using
`Number z2(z)` Because there is an inbuilt  `Default Copy Constructor` that  automatically invoked using `Number z2(z)`
- But user define copy constructor overload it method, like we use to print the line "Copy Constructor is Called"

# [#35 Destructor in C++ in Hindi | C++ Tutorials for Beginners](https://youtu.be/rm4tGxWBkqs?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
int count =0;
class num{
	public:

		// Constructor
		num(){
			count++;
			cout<<"This is the time when constructor is called for object number: "<<count<<endl;
		}

		// Distructor (Name should be same as Class)
		~num(){
			cout<<"This is the time when distructor is called for object  number: "<<count<<endl;
		}
};
```

```cpp
int main(){
	cout<<"We are inside our main function"<<endl;
	 
	cout<<"Creating first object n1"<<endl;
	num n1; // constructor called for n1
	
	{ 
		cout<<"Entering this block"<<endl;
		
		cout<<"Creating two more objects"<<ednl;
		num n2, n3; // constructor called for n2, n3

		cout<<"Existing this block"<<endl; 
	} // n2, n3 scope end: destructor Automatically called for n2 and n,3

	cout<<"Back to main"<<endl;

	returna 0;
} // n1 scope end: destructor Automatically called for n1
```

Output
```
Creating frist object n1
This is the time when constructor is called for object number 1

Entering this block

Creating two more object

This is the time when constructor is called for object number 2
This is the time when constructor is called for object number 3

Exiting this block

This is the time when distructor is called for object number 3
This is the time when distructor is called for object number 2

Back to main

This is the time when my distructor is called for object number 1
```

**What is Destructor :**
- It is an instance member function which is invoked automatically whenever an object is going to be destroyed. Meaning, a destructor is the last function that is going to be called before an object is destroyed.
- Destructor is also a special member function like `constructor`. Destructor destroys the class objects created by constructor.
- Destructor has the same name as their class name preceded by a `tilde(~)` symbol
- It is not possible to define more than one destructor.
- The destructor is only one way to destroy the object create by constructor. Hence destructor can-not be overloaded.
- Destructor neither requires any argument nor returns any value.
- It is automatically called when object goes out of scope.
- Destructor release memory space occupied by the objects created by constructor 
- In destructor, objects are destroyed in the reverse of an object creation.

*Note:* If object is created by using `new` or the constructor uses `new` to allocate memory, which resides int the heap memory or the free store, the destructor should use `delete` to free the memory

---

# [#36 Inheritance & Its Different Types with Examples in C++ | C++ Tutorials for Beginners](https://youtu.be/RO1ZYW9NAzg?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

<ins>Overview: </ins>
- Reusability is a vary important feature of OOPS
- In C++ we can reuse a class and add additional features to it.
- Reusing classes saves time and memory
- Reusing already tested and debugged classes will save a lot of effort of developing and debugging the same things again

OOPs - Inheritance -> DRY

```
// Base Class         // Derive Classes

Class Employee{       
	name;               Manager,
	age;        ->      Clerk,
	dob;                Programmer
}
```

<ins>What is Inheritance in C++</ins>
- The concept of Reusability in C++ is supported using Inheritance
- We can reuse the properties of an existing class by inheriting from it.
- the existing class is called as the `Base Class`
- The new class which is inherited called as the `Derived Class`.
- Reusing classes saves time and money
- There are different types of inheritance in C++

Forms of Inheritance in C++
1. Inheritance
2. Multiple Inheritance
3. Multilevel Inheritance
4. Hierarchical Inheritance
5. Hybrid Inheritance


### Single Inheritance
A derived class with only one Base class : `B = A + (more)`
```
	base
	[A]  
	 ⇩  derive
	[B]
	derives

or

  base
   [A]  
	⇧  is derived from
   [B]
   derives
```
```cpp
class B : public A { }
```

### Multiple Inheritance
A derived class with more than one base class : `C = A + B + (more)`
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

### Hierarchical Inheritance
Several Derived Classes from a single base class: `A = C + more` & `B = C + more`
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

### Multilevel Inheritance
Deriving a class from already derived class : `B = A + more` & `C = B + more`
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


### Hybrid Inheritance
- it is a combination of multiple inheritance and multilevel inheritance
- A class is derived from two class as in Multiple Inheritance
- However, one of the parent classes is not a base class.
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


# [#37 Inheritance Syntax & Visibility Mode in C++ | C++ Tutorials for Beginners](https://youtu.be/Dmrc82dL7E8?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)


| Base Class Member     | Public Inheritance | Protected Inheritance | Private Inheritance |
| --------------------- | ------------------ | --------------------- | ------------------- |
| **Private Members**   | Not Inherited      | Not Inherited         | Not Not Inherited   |
| **Protected Members** | **protected**      | **protected**         | **private**         |
| **Public Members**    | **public**         | **protected**         | **private**         |


Derived Class Syntax
```cpp
class derived_Class_Name : Visibility_Mode base_className{
	class members/methodes/etc...
}
```

*Note:* 
1. Visibility Mode -> Optional, Default mode is private
2. visibility mode : 
	- Public: Public members of the base class becomes public members of the derived class
	- Private: Public members of the base class becomes private members of the derived class.
	- Private members of class are never inherited

```cpp
class Employe{
	public:
		int d;
		float salary;
		
		Employee(int ImpId){
			id = impId;
			salary = 34.0;
		}

		Employee(){}
		// Calling Derived class constructor without Declaring Base Class will throw error.
};
```

Derive Programmer from Employee
```cpp
class Programmer : public Employee{
	public:
		Programmer(int ImpId){ // it will called Default constructor of base class Employee :: Employee()
			id=impId;
		}
		int language code = 9;
		void getData(){
			cout<<id<<endl;
		}
};
```

```cpp
int main(){
	Employee harry(1), rohan(2);
	cout<<harry.salary<<endl; // 34
	cout<<rohan.salary<<endl; // 34

	Programmer skillF(10); 
	cout<<skillF.langauageCode<<endl; // 9
	cout<<skillF.id<<endl; // 10
	skillF.getData(); // 10
	
	return 0;
}
```


---

---


# [#44 Virtual Base Class in C++ | C++ Tutorials for Beginners](https://youtu.be/kzMQpPX7TUY?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

The virtual base class is a concept used in multiple inheritances to prevent ambiguity between multiple instances. 

```
                a
            ⬋        ⬊
          b            c
            ⬊       ⬋
                d
```


1. Class “A” is a parent class of two classes “B” and “C”
2. And both “B” and “C” classes are the parent of class “D”

The main thing to note here is that the data members and member functions of class “A” will be inherited twice in class “D” because class “B” and “C” are the parent classes of class “D” and they both are being derived from class “A”.

So when the class “D” will try to access the data member or member function of class “A” it will cause ambiguity for the compiler and the compiler will throw an error. To solve this ambiguity we will make class “A” as a virtual base class. To make a virtual base class “virtual” keyword is used.

When one class is made virtual then only one copy of its data member and member function is passed to the classes inheriting it. So in our example when we will make class “A” a virtual class then only one copy of the data member and member function will be passed to the classes “B” and “C” which will be shared between all classes. This will help to solve the ambiguity.

The syntax of the virtual base class is shown in the code snippet below,
```cpp
#include <iostream> 
using namespace std; 
class A { 
public: 
    void say() 
    { 
        cout << "Hello world"<<endl; 
    } 
}; 
class B : public virtual A { 
};   
class C : public virtual A { 
};   
class D : public B, public C { 
}; 
```

Note:
A **virtual class** refers to the **base class** that is inherited using virtual inheritance. In your case, **class `A`** is the **virtual base class**, and classes `B`, `C`, and `D` are derived from it either directly or indirectly.

The **virtual** keyword in this context does not make `A` a "virtual class" globally. Instead, it only makes `A` a **virtual base class** **relative to** the inheritance relationship in `B` and `C`. Here's a clearer explanation:
# [#45 Code Example Demonstrating Virtual Base Class in C++ | C++ Tutorials for Beginners](https://youtu.be/eYV-TohBaa0?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```
              Student
            ⬋        ⬊
          Test       Sports
            ⬊       ⬋
              Result
```

```cpp
#include<iostream>
using namespace std;

class Student{
    protected:
        int roll_no; // Roll No.
    public:
        void set_number(int a){ // Set Roll No.
            roll_no = a;
        }
        void print_number(void){
            cout<<"Your roll no is "<< roll_no<<endl;
        }
};

class Test : public virtual Student{  // order of `access specifier` and 'virtual' keyword doesn't matter
    protected:
        float maths, physics;
        public:
            void set_marks(float m1, float m2){
                maths = m1;
                physics = m2;
            }

            void print_marks(void){
                cout << "You result is here: "<<endl
                     << "Maths: "<< maths<<endl 
                     << "Physics: "<< physics<<endl; // shorthand to print train of cout
            }
};

class Sports: virtual public Student{  // order of `access specifier` and 'virtual' keyword doesn't matter
    protected:
        float score;
    public:
        void set_score(float sc){
            score = sc;
        }

        void print_score(void){
            cout<<"Your PT score is "<<score<<endl;
        }

};

class Result : public Test, public Sports{
    private:
        float total;
    public:
        void display(void){
            total = maths + physics + score;
            print_number(); // roll no. come from two direction
            print_marks();
            print_score();
            cout<< "Your total score is: "<<total<<endl;
        }
};
```

```cpp
int main(){
    Result harry;
    harry.set_number(4200); // `set_number` is ambiguous
    harry.set_marks(78.9, 99.5);
    harry.set_score(9);
    harry.display();
    return 0;
}
```

Output if Use virtual Base Class
```
Your roll no. 4200
Your result is here:
Maths: 78.9
Phyiscs: 99.5
Your PT score is 9
Your total score is: 187.4
```

Output if Not used Virtual Base Class -> Compile-time error
```cmd
error: request for member 'set_number' is ambiguous
	harry.set_number(4200);
```

# [#46 Constructors in Derived Class in C++ | C++ Tutorials for Beginners](https://youtu.be/gvOO4H7j_qI?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

# Constructor in Derived Class

- We Can use constructors in derived classes in C++ 
- If base class constructor does not have any arguments, there is no need of any constructor in derived class :
```
A (Constructor without argument) -> B
Object of Derived Class (B) will automatically called Constructor of Base Class (A)
```

Note:
- But if there are one or more arguments in the base class constructor, derived class need to pass arguments to the base class constructor
- If both base and derived classes have constructors, base class constructor is executed first.

#### Constructor in Multiple Inheritance
- In multiple inheritance, base classes are constructed in the order in which they appear in class declaration
```cpp
class A : public B, public C { } // order of B and C
```
 
- In multilevel inheritance, the constructors are executed in the order of inherit
```cpp
// order of inheritance of B and C
class B:  public A { }
class C:  public B { }
```

#### Special Syntax
- C++ supports an special syntax for passing arguments to multiple base classes
- The constructor of the derived class receives all the arguments at once and then will pass the calls to the respective base classes
- The body is called after all the constructors are finished executing.
```
A -> B -> C
```
```cpp
class A { public: A(int x, int y) {} }; 
class B { public: B(int z) {} }; 

// Derived Class From A and B
class C : public A, public B {
	// Derived class constructor 
	public: C(int x, int y, int z) : A(x, y), B(z) { 
	
	} 
};
```

#### Special Case of Virtual Base Class
- The constructors for virtual base classes are invoked before an nonvirtual base class
- If there are multiple virtual base class, they are invoked in the order declared.
- Any non-virtual base class are then constructed before the derived class constructor is executed.

```
Priority of Order:
Virtual Base Class > Base Class > Derived Class
```

# [#47 Solution to Exercise on Cpp Inheritance | C++ Tutorials for Beginners ](https://youtu.be/eGhDSjWGXQc)
> #42 Homework Exercise solution
# [#48 Code Example: Constructors in Derived Class in Cpp | C++ Tutorials for Beginners ]

Case 1 : Simple Inheritance A->B
```cpp
Class B: public A{
	//Constructor execution Order -> A() -> B()
};
```

Case 2 : Multiple Inheritance B->A, C->A
```cpp
Class A: public B, public C{
	//Constructor execution Order -> B() -> C() -> A()
};
```

Case 3 : Virtual Base Class:
```cpp
Class A: public B, virtual public C{
	//Constructor execution Order -> C() -> B() -> A()
};
```

Passing Values to Base Constructor through Derive Constructor Arguments
```cpp
// Base Class1
class Base1{
	int data1;
	public:
		Base1(int i){
			data1=i;
			cout<<"Base1 class constructor called"<<endl
		}
		void printDataBase1(void){
			cout<<"The value of data1 is"<<data1<<endl;
		}
};

// Base Class2
class Base2{
    int data2;
    public:
        Base2(int i){
            data2 = i;
            cout << "Base2 class constructor called" << endl;
        }
        void printDataBase2(void){
            cout << "The value of data2 is " << data2 << endl;
        }
};

// Multiple Base Class Inhertence
class Derived: public Base2, public Base1{
    int derived1, derived2;
    public:
	    // Pass `a` to Base1 and 'b' to Base2
	    // Special Syntex
        Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
        {
            derived1 = c;
            derived2 = d;
            cout<< "Derived class constructor called"<<endl;
        }
        void printDataDerived(void)
        {
            cout << "The value of derived1 is " << derived1 << endl;
            cout << "The value of derived2 is " << derived2 << endl;
        }
};
```

```cpp
int main(){
    Derived harry(1, 2, 3, 4); // 1 passed to Base1, 2 Passed to Base2
    harry.printDataBase1(); // 1
    harry.printDataBase2(); // 2
    harry.printDataDerived(); // 3 & 4
    return 0;
}
```

Output
```
Base1 class constructor called
Base2 class constructor called
Derived class constructor called
The value of data1 is 1
The value of data2 is 2
The value of derived1 is 3
The value of derived2 is 4
```
# [#49 Initialization list in Constructors in Cpp | C++ Tutorials for Beginners](https://youtu.be/-Re7K7mHtv4?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
/*
Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}
```

```cpp
class Test
{
    int a;
    int b;

public:
	// i is assigne to a, j is assigned to b
    Test(int i, int j) : a(i), b(j)
    {
        cout << "Constructor executed"<<endl;
    }
};
```

```cpp
int main()
{
    Test t(4, 6); // a=4, b=6
    return 0;
}
```

Modification of argument in body
```cpp
Test(int i, int j) : a(i), b(j) {
	i++; // not modified a afterward
	++j; // not modified b afterward
	}
// a = i (before increment)
// b = j (before increment)
```

b initializer using a value
```cpp
Test(int i, int j) : a(i), b(a+j)
// a = i
// b = a+j
```

a initializer using Value b : Garbage Value Error ❌
```cpp
Test(int i, int j) : b(j), a(i+b)
// a = -> i + garbage value
// b = j

// Order of declaration of Class member 'int a' and 'int b' should be in same order of initialise list.

//`b` is initialized **before** `a` because `b` is declared **after** `a`, leading to potential issues (like using uninitialized `a`).
```

# [#50 Revisiting Pointers: new and delete Keywords in CPP | C++ Tutorials for Beginners](https://youtu.be/2Y0b9nFA9s8?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
// stack memory allocation
int a = 4;

// pointer : *ptr=value(a), ptr=address(a)
int* ptr = &a;

//heap allocation : *(h)=40
int *h = new int(40);

delete h ✅// deallocate

// Dynamically alocating memory for an array of 3 integers
int *arr = new int[3];
arr[0] = 10; // *(arr) = 10
arr[1] = 20; // *(arr+1)=20
arr[2] = 30; // *(arr+2)=30

delete arr // ❌ Undefined behavior
delete arr[] ✅ // deallocate block of memory
```
- `new` and `delete` are keyword as well as operator
- `new` : allocate a variable dynamically
- `new[]`: allocate an array dynamically
- `delete`: deallocate memory allocated for a single object (if array, first element of it.)
- `delete[]`: deallocate block of memory allocated for an array

Note: it is essential to use the corresponding `delete` operator properly to avoid memory leaks.

# [#51 Pointers to Objects and Arrow Operator in CPP | C++ Tutorials for Beginners](https://youtu.be/ANpUQgyRPKk?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

```cpp
class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout<<"The real part is "<< real<<endl;
            cout<<"The imaginary part is "<< imaginary<<endl;
        }

        void setData(int a, int b){
            real = a;
            imaginary = b;
        }

};
```

Actual Object
```cpp
Complex a;

a.real;
a.getData();
```
Pointer to Object
```cpp
Complex *ptr = new Complex;
// *ptr:object ptr:address of object
(*ptr).real; // is exactly same as a.real
(*ptr).getData(); // is as good as a.getData()

// Note: use '()' because, precedence of '.' is more than '*'
// Note: pointer can also store the address of an object
```

Access class member using arrow operator
```cpp
ptr->real; // (*ptr).real
ptr->getData(); //  (*ptr).getData()

// Note: The arrow operator (`->`) in C++ can be thought of as a combination of dereferencing a pointer and using the dot operator to access a member of a class or structure.
```

Array of Objects
```cpp
Complex *arrP = new Complex[4]; // Complex arr[]
arrP->real; // arr[0].real;
(arrP+1)->real;// *(arrP+1).real or arr[1].real;
arrP+1->real;// paranthesis '()' is optional as, precedence of `+` > `->`
```


# [#52 Array of Objects Using Pointers in C++ | C++ Tutorials for Beginners](https://youtu.be/OCmCyYxSi2I)

```cpp
class ShopItem
{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id = a;
            price = b;
        }
        void getData(void){
            cout<<"Code of this item is "<< id<<endl;
            cout<<"Price of this item is "<<price<<endl;
        }
};
```

⭐ Array of Object Use case Example 
```cpp
int main(){
    int size = 3;
    ShopItem *ptr = new ShopItem [size]; // dynamically allot block of ( size x memory required for 1 object) 
    ShopItem *ptrTemp = ptr;
    //    address  0  1  2
    //             ^
    //             |
    //           ptr/ptrTemp
    int i;
    float p;

	// setData();
    for (i = 0; i < size; i++)
    {
        cout<<"Enter Id and price of item "<< i+1<<endl;
        cin>>id>>price;
        // (*ptr).setData(id, price);
        ptr->setData(id, price);
        ptr++;  // pointer address increment
    }
    //    address  0  1  2
    //             ^        ^
    //             |        |
    //        ptrTemp      ptr

	ptr = ptrTemp;

    // getData()
    for (i = 0; i < size; i++)
    {
        cout<<"Item number: "<<i+1<<endl;
        ptr->getData();
        ptr++; // pointer address increment
    }
    
    
    return 0;
}
```

# [#53 this Pointer in C++ | C++ Tutorials for Beginners](https://youtu.be/cEOfK_L4gGA)

```cpp
class A{
	int a;
	public:
		void setData(int a){ // if we want to use same variable for simplicity
			a = a; // both in LHS and RHS , a will be local variable 
				   // priority of local variable > Data member
				   // no change to data member
		}

		void getData(){
			cout<<a<<endl;
		}
}

int main(){
	A a;
	a.setData(4); // here a -> object
	a.getData(); // garbage value
	return 0;
}
```
Note: In C++ Most priority is given to Local variables.


#### `this` keyword

This: `this` is a keyword which is a pointer which points to the object which invokes the member function
If you want to return an object, using  `this` is the only way.

Use `this` keyword to refer the object
```cpp
class A{
	int a;
	int b;
	public:
		void setData(int a){ // if we want to use same variable for simplicity
			// Explicitly use this->a
			this->a = a; // LHS: data member,  RHS: local variable

			// implicitly call this->b
			b = a; 

		}

		void getData(){
			cout<<a<<endl;
		}
}

int main(){
	A a;
	a.setData(4); // here a -> object
	a.getData(); // 4
	return 0;
}
```

Note: // C++ support easy syntax, if no local variable with same name as class variable is there, we could directly use class variable to return its value. otherwise we need to use `this->`

#### Returning object itself using this
```cpp
class A{
	int a;
	public:

		// Returning the object itself
		A& setData(int a){
			this->a = a;
			return *this // *this = value of this, because this is a pointer 
		}
		// cout<<this = address of object

		void getData(){
			cout<<a<<endl;
		}
};

int main(){
	A a;
	a.setData(4) // set a=4, and return the object itself 
	a.setData(4).getData(); // call the function of object
	return 0;
}
```


# [#54 Polymorphism in C++ | C++ Tutorials for Beginners](https://youtu.be/B-WWdC-H0zw)

“Poly” means several and “morphism” means form. So we can say that polymorphism is something that has several forms or we can say it as one name and multiple forms. There are two types of polymorphism:
- Compile-time polymorphism
- Run time polymorphism

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

1. **Compile Time Polymorphism**
In compile-time polymorphism, it is already known which function will run. Compile-time polymorphism is also called **early binding**, which means that you are already bound to the function call and you know that this function is going to run. There are two types of compile-time polymorphism:

- Function Overloading : This is a feature that lets us create more than one function and the functions have the same names but their parameters need to be different. If function overloading is done in the program and function calls are made the compiler already knows that which functions to execute.

- Operator Overloading: This is a feature that lets us define operators working for some specific tasks. For example, we can overload the operator “+” and define its functionality to add two strings. Operator loading is also an example of compile-time polymorphism because the compiler already knows at the compile time which operator has to perform the task.

2. **Run Time Polymorphism**
In the run-time polymorphism, the compiler doesn’t know already what will happen at run time. Run time polymorphism is also called **late binding**. The run time polymorphism is considered slow because function calls are decided at run time. Run time polymorphism can be achieved from the virtual function.

-  Virtual Function: A function that is in the parent class but redefined in the child class is called a virtual function. “virtual” keyword is used to declare a virtual function.

---
# [#55 Pointers to Derived Classes in C++ | C++ Tutorials for Beginners](https://youtu.be/0YQ_yhX46uk)

```cpp
// Base Class
class BaseClass{
    public:
        int var_base;
        void display(){
            cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

// Derived Class
class DerivedClass : public BaseClass{
    public:
            int var_derived;
            void display(){
                cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};
```

#### 1.  **Base Class Pointer to Derived Class Object (Upcasting)**:
```cpp
BaseClass *base_class_pointer; // Base Class Pointer
DerivedClass obj_derived; // Derived Class Object

base_class_pointer = &obj_derived; // Base Class pointer pointing to Derived class object

base_class_pointer->display(); // ✅ member function of base class 
base_class_pointer->var_base = 34; // ✅ member variable of base class
base_class_pointer->var_derived= 134; // ❌ Error
```
- A **base class pointer** can point to a **derived class object**, but can only access **base class members**.
- The **base class version** of an overridden function is called unless the function is **virtual** (due to **late binding**). 
- The base class pointer **cannot access derived class members** (e.g., variables specific to the derived class).


#### 2. **Derived Class Pointer to Derived Class Object**:
```cpp
DerivedClass * derived_class_pointer; // Derived Class Pointer
DerivedClass obj_derived; // Derived Class object

derived_class_pointer = &obj_derived; // Derived class pointer, pointing to derived class

derived_class_pointer->display(); // ✅ member function of Derived class 
derived_class_pointer->var_base = 34; // ✅ member variable of base class
derived_class_pointer->var_derived = 98; // ✅ member variable of Derived class
```
    
- A **derived class pointer** can access both **base** and **derived class members**.
- The **derived class version** of an overridden function is called.


#### 3. **Derived Class Pointer to Base Class Object (Downcasting)**: ❌

- A **derived class pointer cannot point to a base class object** directly, resulting in a **compilation error**.
- The base class lacks derived class-specific members, leading to **undefined behavior** if allowed.
- This restriction prevents unsafe memory access since the Derived class expects a larger object layout than what the Base class provides.

| Case                                     | Behavior                                                      |
| ---------------------------------------- | ------------------------------------------------------------- |
| **1. Base Pointer to Base Object**       | Same as Base Object ✅                                         |
| **2. Base Pointer to Derived Object**    | Acts like Base Object + Runtime Polymorphism (via virtual) 🙀 |
| **3. Derived Pointer to Derived Object** | Same as Derived Object ✅                                      |
| **4. Derived Pointer to Base Object**    | **Invalid** (Cannot be created) ❌                             |

---
# [#56 Virtual Functions in C++ | C++ Tutorials for Beginners](https://youtu.be/fB3JHNnlRfI)

#### Virtual Functions in C++

A member function in the base class which is declared using virtual keyword is called virtual functions. They can be redefined in the derived class.

Virtual allow derived classes to **override** methods from a base class so that the correct method is called, depending on the type of object, even when the call is made through a base class reference or pointer. 

Why Virtual Function ??
- **Base Class Interface**: If the function doesn’t exist in the base class, you can’t call it using a base class pointer or reference, losing polymorphism.
- **Fallback to Base Function**: If a derived class doesn’t override the virtual function, the base class implementation is used, avoiding errors. Without the base function, the absence of an override would cause a compile-time error.

```cpp
// Base Class
class BaseClass{
    public:
        int var_base;
        virtual void display(){
            cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

// Derived Class
class DerivedClass : public BaseClass{
    public:
            int var_derived;
            void display() override {
                cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};
```

**Base Class Pointer to Derived Class Object (Upcasting)**:
```cpp
BaseClass * base_class_pointer;
DerivedClass obj_derived;

base_class_pointer = &obj_derived; 

base_class_pointer->display(); // ✅ member function of base class 
base_class_pointer->var_base = 34; // ✅ member variable of base class
base_class_pointer->var_derived= 134; // ✅ member variable of Derived class
// base_class_pointer->var_derived= 134; // ❌ Error if not used virtual
```

---
### `Virtual` Keyword


**Without `Virtual`**:
 If we **don’t use the “virtual”** keyword with the “display” function of the base class then beside of the point that we have pointed our base call pointer to derived class object still the compiler would have called the “display” function of the base class because this is its default behavior
 
But we have **used the “virtual”** keyword with the “display” function of the base class to make is **virtual function** so when the display function is called by using the base class pointer **the display function of the derived class will run** because the base class pointer is pointing to the derived class object.

Note: It's Run-time polymorphism not means, that we can't guess which function will execute. actually here we can find out which function Base class or Derived Class will run.
But runt-time polymorphism means, In actual ,the binding of compiler i.e., association of the function address to object is happen at runtime 

*Example:*

**Derived Class Function :** 
```cpp
class Derived : public Base {
    void display() override { cout << "Derived class";}
};
```

**Base Class Function without `virtual` :**
```cpp
class Base {
    void display() { cout << "Base class";}
};
```
```cpp
Base* obj = new Derived();
obj->display();  // Calls Base::display() ✅
```

**Base Class function with `virtual` :**
```cpp
class Base {
    virtual void display() { cout << "Base class"; }
};
```
```cpp
Base* obj = new Derived();
obj->display();  // Calls Derived::display() 🙀
```

---
### `Override` Keyword

The `override` keyword in C++ is optional, and omitting it does not cause a runtime or compile-time error **as long as the function signature in the derived class correctly matches the one in the base class**. 

**Function Signature** -> Unique characteristics of a function that allow the compiler to identify it. 
- Function Name: The name of the function.
- Parameter Types: The number, types, and order of parameters.

**Without `Override`**:
If you do not use the `override` keyword in the derived class's `display()` method, the method will still be **overridden** if the base class function is virtual. However, there are some potential risks:

- If you accidentally change the method signature in the derived class (e.g., change the parameters or return type), the base class method will no longer be overridden, and you may not notice the issue. The compiler will not check if the method in the derived class is correctly overriding a base class method. It will treat the method as a new method in the derived class.


The `override` keyword in C++ ensures that the compiler checks whether a method in a derived class is **actually overriding** a virtual method in the base class. This helps prevent subtle bugs caused by mismatched function signatures.

*Example:* 

Base Class Function
```cpp
class Base {
	virtual void display(int x) {cout << "Base class";} 
};
```

Derived Class Function Without `overriden`
```cpp    
class Derived : public Base { 
	void display(double x) {cout << "Derived class";} // Mistyped parameter type
};
```
```cpp
Base* obj = new Derived();
obj->display(5);  // Calls Base::display (not overridden!) ✅
```

Derived Class Function With `overriden`
```cpp
class Derived : public Base {
	void display(double x) override {cout << "Derived class"}; // Mistyped parameter type
```
```cpp
Base* obj = new Derived();
obj->display(5);  // Error: 'display' in 'Derived' does not override any member function 🙀
```

---
# [#57 Virtual Functions Example + Creation Rules in C++ | C++ Tutorials for Beginners](https://youtu.be/-noYyWtdXSI?list=PLu0W_9lII9agpFUAlPFe_VNSlXW5uE0YL)

```cpp
class Tutorial{
	protected:
		string title;
		float rating;
	public:
		Tutorial(string t, float r){
			title = t;
			rating = r;
		}
		virtual void display(){
			cout<<"bogus code"<<endl;
		}
}
```

```cpp
class Tutorial_Video: public Tutorial{
	int videoLength;
	public:
		Tutorial_Video(string t, int r, int vl):Tutorial(t,r){
			videoLength = vl;
		}

		void display(){
			cout<<"This is an amazing video with title "<<title<<endl;
			cout<<"Ratings of this video is "<<rating<<" out of 5"<<endl;
			cout<<"Length of this video is "<<videoLength<<" minutes"<<endl;
		}

		
}
```

```cpp
class Tutorial_Notes: public Tutorial{
	int wordCount;
	public:
		Tutorial_Notes(string t, int r, int wc):Tutorial(t,r){
			wordCount = wc;
		}

		void display(){
			cout<<"This is amazing note with title "<<title<<endl;
		    cout<<"Ratings of this note is "<<rating<<" out of 5"<<endl;
		    cout<<"No of words in this Notes is "<<words<<" words"<<endl;
		}
}		    
```

```cpp
int main(){

    string t; 
    float r;
    
    float vl;
    int wc;
```

Constructor special syntax usage:
```cpp
    t = "Flask Tutorial Video";
    r = 4.89;
    
    vl = 4.56;
    Tutorial_Video flaskVideo(t, r, vl);
    // flaskVideo():Tutorial(): title =t, rating r
    // flaskVideo: videoLength = v
```

Constructor special syntax usage: 
```cpp
    t = "Flask Tutorial Note";
    r = 4.19;
    
    wc = 433;
    Tutorial_Notes flaskNote(t, r, wc);
    // flaskVideo():Tutorial(): title =t, rating r
    // flaskVideo: wordCount = wc
```

Virtual Function
```cpp
	
    Tutorial* flask[2];
    flask[0] = &flaskVideo; // Base Class pointer, pointing to Derived Class.
    flask[1] = &flaskNote; // Base Class pointer, pointing to Derived Class.

	// flask[x] = address of object (pointer)
	// *flask[x] = value of object
    flask[0]->display();
    flask[1]->display();
```

Current Output with Virtual Function : Derived Class Function Execute
```
This is amazing note with title Flask Tutorial Video
Ratings of this video is 4.89 out of 5
Length of this video is 4.56 words

This is amazing note with title Flask Tutorial Note
Ratings of this note is 4.19 out of 5
No of words in this Notes is 433 words
```

Output if not used Virtual Function : Base Class function Execute
```
bogus code
bogus code
```

---

### Relationship Between Late Binding, Overriding and Runtime Polymorphism ⭐

**late binding**, **overriding**, and **runtime polymorphism** indeed go **hand in hand**. They are tightly connected, and together they enable flexible and extensible object-oriented programming. Here's how they fit together

- **Late Binding** is the mechanism.
- **Overriding** is the act of redefining a function in the derived class.
- **Runtime Polymorphism** is the result of late binding and overriding combined.

|**Concept**|**Definition**|**Connection**|
|---|---|---|
|**Late Binding**|Function call resolved at runtime (via virtual function mechanism).|Enables runtime polymorphism.|
|**Overriding**|Redefining a base class virtual function in the derived class to provide specific behavior.|A requirement for runtime polymorphism.|
|**Runtime Polymorphism**|The behavior where the derived class function is executed when using a base class pointer/reference at runtime.|Achieved through late binding and overriding.|

---
# [# Abstract Base Class & Pure Virtual Functions in C++ | C++ Tutorials for Beginners](https://youtu.be/RBAWWutf0fY?list=PLu0W_9lII9agpFUAlPFe_VNSlXW5uE0YL)


#### Pure Virtual Functions
**Pure virtual function** is a function that doesn’t perform any operation and the function is declared by assigning the value `0` to it. Pure virtual functions are declared in abstract classes.
-> It make necessary for the Derived Class to override the virtual function and thus Abstraction class
#### Abstract Base Class
**Abstract base class** is a class that has at least one pure virtual function in its body. The classes which are inheriting the base class must need to override the virtual function of the abstract class **otherwise compiler will throw an error.**

```cpp
class Tutorial{
    protected:
        string title;
        float rating;
    public:
	    // Constructor of Abstract Base Class
        Tutorial(string t, float r){
            title =  t;
            rating = r;
        }

		// Pure Virtual Function (Abstract method)
        virtual void display()=0; // do-nothing-function (No implementation)
};
```

> **abstraction** allows focusing on what an object does, rather than how it achieves it.
### Advantages of Abstraction:

1. **Reduces Complexity**: Users only need to know the interface and not the implementation details.
2. **Improves Code Maintenance**: Implementation can change without affecting the users of the class.
3. **Enhances Security**: Hides sensitive information from the user.


Note:
1. You can't Create Instance or Object of abstract class.  
	However If you **were** calling the pure virtual function through object would lead to **undefined behavior** because there would be no actual implementation for that function in the object.

2. call a pure virtual function directly from the abstract class, it will result in a compilation error `ClassName::virtualFunc()`❌
	You can define a non-virtual function in an abstract class and call it directly using `ClassName::NonVirtualFunc()` ✅
	
1. If you declare a function as `display() = 0;` without the `virtual` keyword 
	It will not be considered a pure virtual function. Instead, this would lead to a compilation error ❌ , as it would not be valid to declare a function in this way in C++.
	
1. Declaring a function as `display() = 0;` outside of a class is not valid in C++.  ❌
	A pure virtual function declaration must occur within the context of a class. 


---
# Operator Overloading and Function Overloading

Function overloading and operator overloading are considered part of OOP as they enable polymorphism, enhance code readability, and allow user-defined types to interact naturally with operators and functions. While they can exist independently, their integration within classes and objects is fundamental to the principles of Object-Oriented Programming.

**Function overloading vs Operator Overloading**
- operator overloading **cannot be done independently** without using classes or structs because it's meant to define custom behavior for operators when applied to user-defined types (like classes or structs). It can't be used with fundamental types or independently of user-defined types.
- However, **function overloading** is different. Function overloading **can be done independently** of classes. You can overload functions with different parameter types or numbers, even if they don't belong to any class.
# [Operator Overloading in C++ Programming | C++ Programming for Beginners](https://youtu.be/BO2KagRMS3M)

Let take the example of `+` Operator

`+` Operator
```cpp
int x=5;
int y=4;
int z = x+y; // 5+4
cout<<z; // 9
```

Operator Overloading for User Defined Class.
```cpp
class Complex{
	int real, img;
	public:
		// Default constructor + Default Argument
		Complex(int r=0, int i=0){
			real = r;
			imag = i;
		}
		void print(){
			// 5 + 4i;
			cout<<real<<"+"<<imag<<"i"<<endl;
		}
	// Binary Operator Overloading: Addition (+)
	Complex operator +(Complex c){ // x.add(Complex c)
		Complex ans;
		ans.real = real + c.real; // real -> x.real
		ans.img = img + c.img; // img -> x.img
		return temp;
	}

	// Unary Operator overloading: Negotion (-)
	Complex operator -(){ // x.neg()
		Complex ans;
		ans.real = -real; // real -> x.real
		ans.img = -img; // img -> x.img
		return ans;
	}
};
	```

`+` Operator Overloading
```cpp
Complex c1(5, 4); // 5+ 4i
Complex c2(2, 5); // 2 + 5i
Complex c3 = c1 + c2 // c1.add(c2)
Complex c4 = c1 + c2 + c3 // (c1.add(c2)).add(c3)

c1.print(); // Output: 5+4i 
c2.print(); // Output: 2+5i 
c3.print(); // Output: 7+9i 
c4.print(); // Output: 14+18i
```


Operator overloading is only relevant in Object-Oriented Programming (OOP) because it allows custom behavior for operators with user-defined types like classes or structs. Without OOP, operators already have predefined behavior for fundamental types, so overloading them has no significance.

Operator overloading cannot be used for fundamental data types (like `int`, `float`, etc.) because their operator behavior is predefined by the language. If you attempt to overload operators for these types, the compiler will produce an error, as C++ doesn't allow changing their built-in behavior.