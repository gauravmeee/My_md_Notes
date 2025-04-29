

# OOPS
```
⭐ Remember

curl -s https://flask-contest-api.onrender.com/ | python -m json.tool
curl -s  https://flask-jobs-api.onrender.com/ | python -m json.tool
https://gkmeena.netlify.app/




static var-> common memory allocation
static fun -> can't access non-static variable



Member Functions:
Member Function -> Can Access Private, Protected, Public members
Static member Function -> Can Access only Static Private, Public, Protected members

Non-Member Functions:
Friend Function -> Can Access Private, Protected, Public members
Normal Function -> Can Access only Public member
Static Function -> Can Access Static Public members

Class1{
friend <data type> Class2:Func(); // ignore `Class2:` if friend function is independent
}

<data type> Class2:Func(){ // Logic} ;


Constructor
Class1 Obj1() // Implicit Call
Class1 obj1 = Class() // explicit call

Constructor:
Cosntructor Can't be used like normal function
Class1 obj.Class1() ❌
Class1 obj = Class1();

Default -> No parameter, Automatically called
Parameterized -> Take arguments to initialize (should be pass argument during declaration otherwise error)
Copy Constructor -> Takes object References, Initializes an object from another object
A(const A &obj){
	dataMember1 = obj.dataMember1
	// More Data members
}

Default Copy Constructor -> there is an inbuilt  `Default Copy Constructor` that  automatically invoked using `A obj2(obj1)`
Distructor

Dynamic Initilization of objects using constructor
Class1 obj1; // Default/blank Constructor called
int a =2;
obj1 = Class1(a) // create temporary object `Class1(a)` and assign obj1 to it

Destructor:
~Class(){//} // Manually redifining default destructor logic
It is an instance member function which is invoked automatically whenever an object is going to be destroyed.

Inheritance
A -> B : class B : public A { }
A + B -> C (multiple or hybrid) : class C : public A, public B { }

Visiblity mode
Private Member never inherited
Protected  member -> protected, private
Public member -> Public, Protected, Private



Virtual Base Class ⭐
```

# OS
```

System Call -> A way for program to interact with the operating system.

Program -> set of instructions written in a programming language to perform a specific task.
Processes -> Program under execution.

Main Memory        Program P1
┌──┐             . ┌───────┐
|OS|        .      | Stack | -> Local Var, Function Param, return addr.
├──┤. . .          ├───↓───┤
|P1| ->            ├───↑───┤
├──┤.  .           | Heap  | -> Dynamic Memory Allocation
│  │       .       ├───────┤
└──┘           .   | Data  | -> Static and Global Variable
                   ├───────┤
                   | Code  | -> Program Instructions
                   └───────┘

Program Counter (PC)-> Store address of Next Instruction -> 
Program Code Part
┌────────┐
|  CPU   |  
│ ┌────┐ │
│ | PC | │
| └────┘ |
└────────┘

Process Block (PCB) -> When Process load into CPU Process content like (instructions, Variables) not goes into CPU, only PCB goes into CPU that stores Process ID, Process current state, Process Priority etc.

Main Memory                OS
                  . ┌──────────────────┐
┌──┐ .     .        | PCB P1 [.....]   |
|OS|---->           | PCB P2 [.....]   |
├──┤ .     .        | PCB P3 [.....]   |
|P1|              . └──────────────────┘
├──┤
└──┘


Paging: - Processes is divided in equal size of partitions called as `pages` and Physical memory is divided in same equal size of partitions called `frames`

Logical Address
┌─────┬─────┐
│  p  │  d  |     p:page no.  , d: offset
└─────┴─────┘                    |
                                 |
Physical Address                 | equal
┌─────┬─────┐                    ↓
│  f  │  d  |     f:frame no.  , d: offset
└─────┴─────┘

Page Table 1 entry
┌─────┬─────────────┐ 
│  f  │  extra bits |   
└─────┴─────────────┘

Logical Memory -> Logical memory (also called virtual address space) is the memory as seen by a process.

Virtual memory ->  memory management technique that gives an illusion of a large main memory by using a portion of the secondary storage (e.g., hard disk).


Translation lookaside buffer (TLB) -> Memory hardware that is used to reduce the time taken to access a user memory location or address translation

TLB[p] -> f
 p   f          
┌──┬──┐
├──┼──┤
├──┼──┤
├──┼──┤
├──┼──┤


Demand Paging: Bring Pages in memory when CPU demands

Page Fault : if the page demanding by CPU is not present in main memory

Page Replacement Policies
FIFO
LIFO
LFU and LRU
MFU xx
Optimal Policy
```

```
1. FCFS (First Come First Serve)
2. SSTF (Shortest Seek Time First)
3. Scan
4. C-Scan (Circular-Scan)
5. Look
6. C-Look (Circular-Look)
```
# DBMS
```

```

