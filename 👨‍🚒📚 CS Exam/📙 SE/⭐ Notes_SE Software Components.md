


**Software Component** - A software component is a ==**self-contained, modular unit** of a software system== that performs a specific function and interacts with other components through **well-defined interfaces**. Components are designed for **reuse, replaceability, and independent development**.

i.e. Software components are modular units of a system that encapsulate functionality, interact through interfaces, and promote reuse, maintainability, and scalability.


**Why Components are Needed**
- Large software systems are complex
- Components ==divide complexity== into manageable units
- Enable parallel development
- ==Improve maintainability and scalability==
- Support reuse across projects

##### **Types of Software Components** ⭐

**1. Control Component** ⭐

- Responsible for **control flow of the system**
- Decides ==_what_ operation to execute and _when_==
- Does **not** contain business logic
- Acts as a mediator between user interface and domain logic
    
- Responsibilities
	- Request handling
	- Decision making
	- Workflow coordination
	- Exception handling
    
- Example
	- ==MVC Controller== ( Model–View–Controller )
	- Request Dispatcher in web applications
    

**2. Problem Domain Component** ⭐

- Represents the **core business logic**
- Models real-world entities and rules
- Independent of UI and infrastructure
- Most critical for correctness of the system

- Responsibilities
	- Data validation
	- Business rules enforcement
	- Core computations and processing

- Example
	- Banking transaction logic
	- Payroll calculation
	- Inventory management rules
    
**3. Infrastructure Component** ⭐

- Provides **technical services** required by other components
- Contains no business logic
- Supports system execution environment

- Responsibilities
	- Database connectivity
	- File handling
	- Logging
	- Security
	- Network communication

- Example
	- JDBC / ORM layers
	- Logging frameworks
	- Authentication modules
    
##### **Interaction Between Components**

- Control Component calls Problem Domain Component
- Problem Domain Component uses Infrastructure Component
- Infrastructure Component never controls application logic

**Flow:**  
Control → Problem Domain → Infrastructure


##### **Key Characteristics of Good Components**

**1. ==High Cohesion**==
- Component performs a **single well-defined task**    
- Improves clarity and maintainability

**2. ==Low Coupling**==
- Minimal dependency between components
- Changes in one component have minimal impact on others
    
**3. Interface-Based Design**
- Interaction through interfaces, not implementations
- Supports replaceability
    
**4. Reusability**
- Component can be reused in multiple systems

**5. Replaceability**
- Component can be replaced without affecting the system
    

---

##### **Advantages**

- Easier debugging and testing
- Faster development
- Better scalability
- Improved system reliability
- Supports component-based software engineering (CBSE)
    

##### **Key Points (For Exams)**

- Control component ≠ Business logic
- Domain component = heart of the system
- Infrastructure component = technical support
- Separation of concerns is the core principle
- Commonly asked in **Software Engineering theory questions**
    


