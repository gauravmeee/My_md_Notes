
# [Low Level Design Interview Questions](https://www.interviewbit.com/low-level-design-interview-questions/)

### Introduction

- Generally, we develop software to solve a particular business problem.
- Developing any software follows a procedure as :
	- identifying the business problem, 
	- collecting the functional requirements for the identified problem, 
	- designing the overall architecture of the software/system by defining the building blocks called **components**, 
	- designing the individual components, actually writing the code, testing the software, deploy/release the software and maintain the software.

![](https://d3n0h9tb65y8q.cloudfront.net/public_assets/assets/000/003/064/original/sdlc.png?1649415376)

**Before writing the actual code, we do 2 crucial steps. :**
- One is defining the high-level components typically called **High-Level Design (HLD)** and 
- Another is designing each component in detail typically called **Low-Level Design (LLD).**

**What is High-Level Design (HLD)?**
- In HLD, the **focus is more on designing the high-level architecture** of the system, 
	- defining the high-level components with their interactions, 
	- and also the database design. 
- HLD converts the business requirements to a high-level solution.

**What is Low-Level Design (LLD)?**
- In LLD, the **focus is more on designing each component in detail** such as:
	- what classes are needed, 
	- what abstractions to use, 
	- how object creation should happen, 
	- how data flows between different objects, etc. 
- LLD converts the high-level design into detailed design (ready to code) components.

### Low Level Design Interview Questions: Freshers & Experienced

##### 1. Why LLD is Important?
- As a software developer in any company, the objective is to build software for the business of the company. 
- Building software is a complex task. 
- Change is the only constant thing in the world. 
- As the software progresses over the years, it needs to incorporate a lot of changes as the requirements keep on changing. 
- We can choose to build software in many ways but we need to build it in such a way that the software is **maintainable and extensible** ⭐ over the years easily
So:
- **Low-Level Design** is a must for building a piece of software. As LLD focuses on :
	- how to build software from a set of requirements, 
	- how different components interact with each other, 
	- what responsibilities each component has etc, 
- it is a vital exercise to be done before actually writing the code.
- Writing code is the easiest part of building software if we have the designs already in place. 
- Maintaining and Extending software will be easy if designs are well thought of.

**Effort :**
![](https://d3n0h9tb65y8q.cloudfront.net/public_assets/assets/000/003/065/original/Why_LLD_is_Important.png?1649415430)
- Maintenance takes almost 70% of the effort in the software development life cycle. 
- So the software should be easily maintainable and extensible. 
- **LLD plays an important role in the design of software and hence directly contributes to the maintainability and extensibility of software.** ⭐

##### 2. How to prepare for Low-Level Design Interviews?

**Here is the list of things that a software developer needs to learn for LLD Interviews:**

1. **Object-Oriented Language:**
2. **Object-Oriented Principles:**
	- **YAGNI:** **I**t is a practice in software development that states that features should only be added when required and thus help trim away excess and inefficiency development to facilitate the desired increased frequency of releases)
	- **DRY :** It is a principle that states that don't repeat the code again and again. 
		-> ( If there is a code that is duplicated then whenever a change needs to be made, the change has to be done in both places. )
	- **SOLID :** These are a set of 5 principles. **S**ingle Responsibility, **O**pen-Closed, **L**iskov Substitution, **I**nterface Segregation, and **D**ependency Inversion

3. **UML Diagram :** Unified Modeling Language and is a standard for modelling, visualizing, and documenting the artefacts of software systems. It is a tool to visually depict different types of diagrams that can be useful for building the software.
	- **Structural Diagrams:** They represent the static view of the system. 
		-> ( Class Diagram, Composite Structure Diagram, Object Diagram, Component Diagram, Deployment Diagram, Profile Diagram, and Package Diagram )
- 
	- **Behavioural Diagram:** They represent the dynamic view of the system. 
		-> ( Activity Diagram, State Machine Diagram, Use Case Diagram, Interaction Overview Diagram, Timing Diagram, Sequence Diagram, and Communication Diagram ) 

	
3. **Design Patterns :**  Design Patterns are typical solutions to common problems in software design. "Don't reinvent the wheel" is a well-known phrase in software engineering. 
	-> ( If a problem is already solved, don't solve the same problem to get the same solution. Instead, use the solution to the problem. Similarly, there are a lot of common problems in software design that are solved and are given as a toolkit called Design Patterns. )

4. **Practice LLD Questions**
##### 3. How to Solve Low-Level Design problems in Interviews?

Solving an LLD problem can be divided into mainly 3 stages:

1. **Clarify & Gather Requirements:**
2. **Class Diagram & Use Case Diagram & Schema Diagram (If required):**
3. **3. Code:**

##### 4. How to design Snake and Ladder?

Some frequently asked low-level design examples to practice are:

- Design `Parking Lot`
- Design `Splitwise`
- Design `Tik Tok Toe` Game
- Design `Car Rental` System
- Design `Bookmyshow`
- Design `Pub Sub` System
- Design `Coffee Vending` Machine

### Low Level Design MCQ Questions

**1. In a Low-Level Design interview, which of the following options would be the correct sequence to follow?**
```
Step 1: Clarifying any doubts with regards to the question asked.
Step 2: Specifying the core requirements to be included.
Step 3: Create a class diagram & use a case diagram.
Statement Ill: 
Step 4: Implement the code using Object Oriented Principles & Design Patterns.
```

**2. What does SOLID principles mean?**
```
S - Single Responsibility Principle : 
	A class should have only one reason to change.
    
O – Open/Closed Principle: 
    Software entities should be open for extension, but closed for modification.
    
L – Liskov Substitution Principle  
    Subtypes must be substitutable for their base types.
    
I – Interface Segregation Principle 
    No client should be forced to depend on methods it does not use.
    
D – Dependency Inversion Principle 
    High-level modules should not depend on low-level modules; both should depend on abstractions.

```

**3. What does DRY stand for?**
```
Don't Repeat Yourself ✅
```

**4. What does the MVC pattern stands for?**
```
Model View Controller ✅
```

**5. Which design pattern ensures that only one object of a particular class gets created?**
```
Singleton Design Pattern 
```

**5. What does UML stands for**
```
Unified Modeling Language 
```

**6. Which of the below is not a UML diagram?**
```
Development Diagram 
```

**7. Which of the below is not an Object Oriented Principle?**
```
Depend on concrete classes 
```

**8. Which of the following describes the Strategy pattern correctly?**
```
A class behaviour or its algorithm can be changed at run time. 
```

**9. Which of the following is not a category of Design Pattern?**
```
Communication Design Patterns
```

**10. Which principle says that "a class should have a single reason to change"?**
```
Single Responsibility Principle
```