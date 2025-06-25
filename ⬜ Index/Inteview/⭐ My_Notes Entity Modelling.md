
# [Top 24 Data Modeling Interview Question and Answers for 2025(Simplilearn)](https://www.simplilearn.com/data-modeling-interview-question-and-answers-article)

### What is Data Model ?

- A data model **organizes different data elements and standardizes how they relate to one another** and real-world entity properties.
	- So logically then, data modeling is the process of creating those data models.
- Data models are composed of **entities** ( entities are the objects and concepts whose data we want to track ) 
	- They, in turn, become tables found in a database. Customers, products, manufacturers, and sellers are potential entities.

- Each entity has attributes —details that the users want to track. For instance, a customer’s name is an attribute.

### Basic Data Modeling Interview Questions

##### 1. What Are the Three Types of Data Models?

The three types of data models:
- **Physical data model** - This is where the framework or schema describes how data is physically stored in the database.
- **Logical data models** - They straddle between physical and theoretical data models, allowing the logical representation of data to exist apart from the physical storage.
- **Conceptual data model** - This model focuses on the high-level, user’s view of the data in question

##### 2.  What is a Table?

- A table consists of data stored in rows and columns. 
- Columns, also known as fields, show data in vertical alignment. 
- Rows also called a record or tuple, represent data’s horizontal alignment.

##### 3. What is Normalization?

- Database normalization is the process of designing the database in such a way that it reduces data redundancy without sacrificing integrity.

##### 4. What Does a Data Modeler Use Normalization For?

The purposes of normalization are:
- Remove useless or redundant data
- Reduce data complexity
- Ensure relationships between the tables in addition to the data residing in the tables
- Ensure data dependencies and that the data is stored logically.

##### 5. So, What is Denormalization, and What is its Purpose?

- Denormalization is a technique where redundant data is added to an already normalized database. 
- The procedure enhances read performance by sacrificing write performance.

##### 6. What Does ERD Stand for, and What is it?

- ERD stands for **Entity Relationship Diagram** 
- It is a logical entity representation, defining the relationships between the entities. Entities reside in boxes, and arrows symbolize relationships.

##### 7. What’s the Definition of a Surrogate Key?

- A surrogate key, also known as a [primary key](https://www.simplilearn.com/tutorials/sql-tutorial/primary-key-in-sql "primary key"), enforces numerical attributes. 
- This surrogate key replaces natural keys.  ⭐
- Instead of having primary or composite primary keys, data modelers create the surrogate key, which is a valuable tool for identifying records, building SQL Queries and enhancing performance.

##### 8. What Are the Critical Relationship Types Found in a Data Model? Describe Them.

The main relationship types are: ⭐

- **Identifying.** A relationship line normally connects parent and child tables. But if a child table’s reference column is part of the table’s primary key, the tables are connected by a thick line, signifying an identifying relationship.
- **Non-identifying.** If a child table’s reference column is NOT a part of the table’s primary key, the tables are connected by a dotted line, signifying a no-identifying relationship.
- **Self-recursive.** A recursive relationship is a standalone column in a table connected to the primary key in the same table.

##### 9. What is an Enterprise Data Model?
- This is a data model that consists of all the entries required by an enterprise.
## Intermediate Data Modeling Interview Questions

## Advanced-Data Modeling Interview Questions

---

# [ER Model in DBMS](https://www.interviewbit.com/blog/er-model-in-dbms/)


##### Introduction

ER Model stands for **Entity-Relationship Model**, also known as a high-level data model 

**ER Model**  -> shows the relationship among the entity sets. 
- ER Model is used to **define the entities and the relationships between them**. ⭐
- It helps developers to design the conceptual design or you can say the logical design of the system from a data perspective. 
- It describes the structure of a database with the help of a diagram, which is known as the Entity-Relationship Diagram (ER Diagram).

##### What is an ER Diagram?

- ER diagrams are used to sketch out the design of a database. 
- By defining the **entities, their attributes, and showing the relationships** between them
- An ER diagram illustrates the logical structure of databases.

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/ER-Diagram-1024x525.png)


##### 1. Entity `[Rectangle]`

**Entity :**  -> Any object that physically exists and is logically constructed in the real world is called as an Entity. 
- It is a real-world object that can be easily identifiable. An entity is represented as a rectangle in an ER diagram.
- All the entities have some attributes or properties that give them their identity.
- Example- In an organization, employees, managers, and projects assigned can be considered entities. 


**Strong Entity** -> Strong entities are those entity types that have a key attribute.
- The primary key helps in identifying each entity uniquely.
- this can not accept null values so it can not be a unique key

**Weak Entity** -> Weak entity type doesn’t have a key attribute.
- Weak entity types can’t be identified on their own
- It depends upon some other strong entity for its distinct identity.
- The relationship between a weak entity type strong entity type is shown with a double outlined diamond `<<Diamond>>` instead of a single outlined diamond `<diamond>`.

##### 2. Attribute `(Ellipse)`

**Attribute** -> a property or characteristic of an entity. 
- An entity may contain any number of attributes. 
- The attributes that can uniquely define an entity are considered as the primary key. 
- Attributes describe the instances in the database. ⭐
- Examples -  Employee has attributes like name, `age`, `roll`, `emp_id`, and many more. 
- To uniquely identify the employee, we use the primary key as an `emp_id(employee id)` as it is not repeated. 

**Types of Attribute:**
- Simple attribute
- Composite attribute
- Single-valued attribute
- Multi-valued attribute
- Derived attribute.
- Complex Attribute (Not Important)

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Attributes-of-an-entity-1024x683.png)


##### 3. Relationship `<Diamond>`

**Relationship** -> A relationship in a DBMS is primarily the way two or more data sets are linked. 
- Relationships allow the datasets to share and store data in separate tables. 
- They also help link disparate data with each other.

**Types of relationships:**
1. **One to One (`1:1`) :** a single row of the first table can only be related to one and only one record of a second table.
	- Example - each department has only one head of the department, and one HOD can take only one department.


2. **One to Many (`1:M`)** Any single row of the first table can be related to one or more rows of the second table, but the rows of the second table can 
	- Example : A department that has many employees, Each employee is assigned to one department.

3. **Many to Many** (`N:M`): Each record of the first table can relate to any records (or no records) in the second table. Similarly, each record of the second table can also relate to more than one record of the first table.
	- Example: There are many employees involved in each project, and every employee can involve in more than one project.

### Features of ER Model

**1. Specialization** ->  An entity set broken down sub-entities that are distinct in some way from other entities in the set. 
- It is a “Top-down approach” where a high-level entity is specialized into two or more level entities.

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Specialization-1024x571.png)

**2. Generalization** -> It is a process of extracting common properties from a set of entities and creating a generalized entity from it.
-  It is a “Bottom-up approach”. In which two or more entities can be combined to form a higher-level entity if they have some attributes in common.

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Generalization-1024x591.png)

**3. Inheritance** ->  An entity that is a member of a subclass inherits all the attributes of the entity as the member of the superclass, the entity also inherits all the relationships that the superclass participates in. - 
- Inheritance is an important feature of Generalization and Specialization. 
- It allows lower-level entities to inherit the attributes of higher-level entities.

**5. Aggregation –** In aggregation, the relation between two entities is treated as a single entity. 
- In aggregation, the relationship with its corresponding entities is aggregated into a higher-level entity.

- Example - phone numbers on your mobile phone. You can refer to them individually – your mother’s number, your best friend’s number, etc. But it’s easier to think of them collectively, as your phone number list.
- Each member of the aggregation still has the properties of the whole. In other words, each phone number in the list remains a phone number.

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Aggregation-1024x617.png)


### How To Create ER diagram in DBMS

**Steps to create an ER Diagram :**

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Steps-to-create-an-ER-Diagram-522x1024.png)


##### **Ques.**  In an Organization, an employee is assigned to projects. An employee must be assigned to at least one or more projects. Each project is managed by a single manager. To maintain instruction quality, a manager can control only one project.

**Step 1) Entity Identification:** We have three entities
- Employee
- Project
- Manager

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Entity-Identification-1024x244.png)

**Step 2) Relationship Identification:** We have the following two relationships
- The employee is assigned a project
- manager control a project

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Relationship-Identification-1024x200.png)

**Step 3) Cardinality Identification:** For them problem statement we know that,
- An employee can be assigned multiple projects
- A manager can manage only one course

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/Cardinality-Identification-1024x186.png)

**Step 4) Identify Attributes** – Initially, it’s important to identify the attributes without mapping them to a particular entity. Once you have a list of Attributes, you need to map them to the identified entities. Ensure an attribute is to be paired with exactly one entity. If you think an attribute should belong to more than one entity, use a modifier to make it unique.

Once the mapping is done, identify the primary Keys. If a unique key is not readily available, create one.

|Entity|Primary Key|Attribute|
|---|---|---|
|Employee|Employee_ID|EmployeeName|
|Manager|Manager_ID|ManagerName|
|Project|Project_ID|ProjectName|

For the sake of ease, we have considered just one attribute.

**Step 5) Create the ERD Diagram** – A more modern representation of Entity Relationship Diagram Example

![](https://www.interviewbit.com/blog/wp-content/uploads/2022/02/ERD-Diagram-1024x451.png)

### Why use ER Diagrams?

Here, are prime reasons for using the ER Diagram
- It helps you to define terms related to entity relationship modeling.
- It provides a preview of how all your tables should connect, what fields are going to be on each table
- It helps to describe entities, attributes, relationships.
- ER diagrams are translatable into relational tables which allows you to build databases quickly.
- ER diagrams can be used by database designers as a blueprint for implementing data in specific software applications.
