
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
// 
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
- Access data members `myObject.myData` ( Note if only public )
- Access function members `myObject.myFunc()`
- Class Definition end with a semicolon `;`

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

# [#23 # C++ Objects Memory Allocation & using Arrays in Classes | C++ Tutorials for Beginners](https://youtu.be/qq05D2yFIHA?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

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
Employee  arr[0], arr[1],  arr[2] =   haryr, gaurav, Lavish
┌--------┬--------┬--------┐
| arr[0] | arr[1] | arr[2] |
└--------┴--------┴--------┘

harry.setId;
harry.getId;

gaurav.setId;
gaurav.getId;

lovish.setId;
lovish.getId;
```

# [#26 Friend Functions in C++ | C++ Tutorials for Beginners](https://youtu.be/HK6gnkQIgqI?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)
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
			a = o1.a +o2.a;
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



### Multiple Inheritance
A derived class with more than one base class : `C = A + B + (more)`
```
   Base    Base
   [A]     [B]
     ⬂   ⬃
       [C]
     Derived
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

### Multilevel Inheritance
Deriving a class from already derived class : `B = A + more` & `C = B + more`
```
	base
	[A]  
	 ⇩ 
	[B]
	 ⇩ 
	[B]
	derives
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


# [#37 Inheritance Syntax & Visibility Mode in C++ | C++ Tutorials for Beginners](https://youtu.be/Dmrc82dL7E8?list=PLISTUNloqsz0z9JJJke7g7PxRLvy6How9)

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