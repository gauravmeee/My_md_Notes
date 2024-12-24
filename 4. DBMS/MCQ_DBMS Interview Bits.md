
## [DBMS Interview Questions](https://www.interviewbit.com/dbms-interview-questions/)

### 1. Basic

What is DBMS?
- DBMS stands for **Database Management System**, is a set of applications or programs that enable users to `create` and `maintain` a database

What is DBMS's Utility?
- provides a tool or an interface -> for performing various operations such as `inserting`, `deleting`, `updating`, etc. into a database
- It enables -> storage of data more `compactly` and `securely` (compared to a file-based system).
- Overcome problems like -> data `inconsistency`, `data redundancy`, etc. in a database (makes it more convenient and organized to use it).

Example of Popular DBMS systems
- `file systmes`, `XML`, `Windows Registry`

```

  students Records
    ↑
┌───|─────────────┐
│ [...]           │ ===================> DBMS ======> Programs
│      [...]      │                 (MySql,Oracle)    (Website Code)
│   [...] [...] --→ Employe Records
└─────────────────┘
```

What is RDBMS?
- RDBMS stands for **Relational Database Management System** (introduced in the 1970s) to `access` and `store` data more **efficiently** than DBMS. 
- Stores data -> In form of `Tables` (as compared to DBMS which stores data as files).
- Storing data as rows and columns makes it `easier to locate specific values` in the database and `makes it more efficient` as compared to DBMS.

Example of Popular  RDBMS
- MySQL, Oracle DB

What is a Database?
- **Database** -> `organized`, `consistent`, and `logical` collection of data (that can easily be updated, accessed, and managed).
- Database mostly contains sets of tables or objects (anything created using create command is a database object) which consist of records and fields. 
- **Record** -> a `tuple` or a `row` represents a single entry in a table. 
- **Field** -> an `Attribute` or a `column` represents the basic units of data storage (which contain information about a particular aspect of the table).

What is Cardinality and Degree?
- **Cardinality** -> no. of tuples
- **Degree** -> no. of Attributes

What DBMS do on a Database Relation?
- DBMS extracts or perform operation on data from a database in the form of queries given by the user.

Advantages of DBMS ⭐
```
                      API (App)
                     /
Database ------ DBMS --⭢ API (User)
                     \
                      API (App)


- Data Sharing: Data from a single database can be simultaneously shared by multiple users.

- Integrity constraints: Allows storing of data in an organized and refined manner.

- Controlling redundancy: by providing a
mechanism that integrates all the data in a single database.

- Data Independence: Allows changing the data structure without altering the composition of any of the executing application programs.⭐
refers to the ability to modify the database schema at one level without affecting the schema at the next higher level. This concept is crucial for separating data storage concerns from data manipulation concerns, ensuring flexibility and maintainability.

- Backup and Recovery: Can be configured to automatically create the backup and and restore whenever required

- Data Security: Provides the necessary tools to make the storage and transfer of data more reliable and secure (Authentication and Encryption)
```

Types of Language in DBMS
```
- DDL: define the database. [CREATE, ALTER, DROP, TRUNCATE, RENAME, etc.]

- DML: Manipulate the data present in the database. [SELECT, UPDATE, INSERT, DELETE, etc.]

- DCL: Deal with the user permissions and controls of the database system. [GRANT and REVOKE]

- TCL: Deal with the transaction of the database. [COMMIT, ROLLBACK, and SAVEPOINT]
```

Git Hub is a Database?
- No, GitHub is not technically a database
- It is a platform that uses a Git database internally to `store code` and `track changes` within repositories
- its Primary function is to `host and manage code` projects

Are `NULL` values in DB same as that of `space` of `zero`?
- No, A NULL value is very different from that of zero and blank space 
- It represents a value that is assigned, unknown, unavailable, or not applicable as compared to blank space (represents a character) and zero (represents a number).
- Example: `NULL` value in `number_of_courses` taken by a student represents that its value is unknown whereas `0` in it means that the student hasn't taken any courses.

What is meant by  ACID properties in DBMS
```
DATABASE TRANSACTIONS
A | Atomic - All changes to the data must be performed successfully or not at all

C | Consistent - Data must be in a consistent state before and after the transaction

I | Isolation - No other process can change the data while the transaction is running

D | Durable : The changes made by a transaction must persist
```

**Atomicity :** This property reflects the concept of :
- either executing the whole query or executing nothing at all
- which implies that if an update occurs in a database then that update should either be reflected in the whole database or should not be reflected at all.
![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/266/original/atomicity-1.png?1617187688)
![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/267/original/atomicity-2.png?1617187786)

**Consistency:** This property ensures that 
- The data remains consistent before and after a transaction in a database.
![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/219/original/acid-consistency.png?1616074548)

**Isolation:** This property ensures that 
- Each transaction is occurring independently of the others.
- This implies that the state of an ongoing transaction doesn't affect the state of another ongoing transaction.
![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/220/original/acid-isolation.png?1616074608)

**Durability:** This property ensures that 
- The data is not lost in cases of a system failure or restart and is present in the same state as it was before the system failure or restart.

---
### 2. Intermediated

What is meant by Entity-Relationship(E-R) model?
- An entity-relationship model is a diagrammatic approach to a database design -> where real-world objects are represented as entities and relationships between them are mentioned.

Explain the terms Entity, Entity Type, Entity Set? ❓
- **Entity** -> a real-world object having attributes that represent characteristics of that particular object. ex: 
	->`student, employee, teacher`

- **Entity type** -> a collection of entities that have the same attributes.
	->`student_id, student_name` for student entity
	-> One or more related tables in a database represent an entity type. Entity type or attributes can be understood as a characteristic which uniquely identifies the entity.

- **Entity Set** -> set of all the entities present in a specific entity type in a database.
	->`set of all the students, employees, teachers` as entity set.

What is meant by Normalization and denormalization?
- **Normalization** -> a process of `reducing redundancy` by organizing the data into multiple tables.
	-> Normalization leads to `better usage of disk spaces` and makes it `easier to maintain the integrity` of the database.

- **Denormalization** -> combines the tables which have been normalized into a single table so that data `retrieval becomes faster`. 
	-> It is the reverse process of normalization
	-> `JOIN` operation allows us to create a denormalized form of the data by reversing the normalization.


What is a lock. 
- A database lock is a mechanism to protect a shared piece of data from getting updated by two or more database users at the same time. When a single database user or session has acquired a lock then no other database user or session can modify that data until the lock is released.

Shared lock and Exclusive lock during a transaction in a database.
- **Shared Lock** -> required for reading a data item and many transactions may hold a lock on the same data item in a shared lock. Multiple transactions are allowed to read the data items in a shared lock.
- **Exclusive Lock** -> lock on any transaction that is about to perform a write operation. This type of lock doesn't allow more than one transaction and hence prevents any inconsistency in the database.

| **Feature**      | **Exclusive Lock (X)**       | **Shared Lock (S)**         |
| ---------------- | ---------------------------- | --------------------------- |
| Purpose          | Write Operations             | Read Operations             |
| Concurrent Acess | No Other Transaction allowed | Multiple reads allowed      |
| Compatibility    | Block all other locks        | Blocks only exclusive locks |
| Use Cae          | Updating/deleting data       | Viewing/reading data        |

Difference between `DELETE` and `TRUNCATE`
- `DELETE` -> delete rows from a table based on the condition (provided by `WHERE` clause)
	-> Can be rolled back
	-> Maintains a `log to lock the row` of the table before each deletion and hence it's `slow`.
	-> `DML` command.
- `TRUNCATE` -> Removes complete data from a table in a database
	-> Can't be rolled back (in some databases)
	-> Doesn't maintain a `log` and deletes the whole table at once and hence it's `fast`
	-> `DDL` command.

- Although **TRUNCATE** removes data, it is considered a **DDL command** because it focuses on altering the storage and structure of the table at a higher level, rather than manipulating individual rows like DML commands (`INSERT`, `UPDATE`, `DELETE`).


Difference between intension and extension in a database. ❓
- **Intension:** Intension or popularly known as database schema is used to define the description of the database and is specified during the design of the database and mostly remains unchanged.
- **Extension:** Extension on the other hand is the measure of the number of tuples present in the database at any given point in time. The extension of a database is also referred to as the snapshot of the database and its value keeps changing as and when the tuples are created, updated, or destroyed in a database.


ER-Model Diagram Shapes for Entity, Attribute, Relationship
- Entity - `[Rectangle]`
- Relationship - `<Diamond>`
- Attribute - `(Oval)`


ER-Model Diagram Shapes

|**Shape**|**Meaning**|
|---|---|
|**Rectangle**|**Entity**: Represents an object or thing in the system (e.g., `Employee`, `Product`).|
|**Oval**|**Attribute**: Represents properties or characteristics of an entity or relationship (e.g., `Name`, `Price`).|
|**Diamond**|**Relationship**: Represents the association between entities (e.g., `Manages`, `Belongs To`).|
|**Double Oval**|**Multivalued Attribute**: Represents attributes that can have multiple values (e.g., `Phone Numbers`).|
|**Dashed Oval**|**Derived Attribute**: Represents an attribute derived from other attributes (e.g., `Age` derived from `Date of Birth`).|
|**Double Rectangle**|**Weak Entity**: Represents entities that depend on another entity (e.g., `Dependent` depends on `Employee`).|
|**Double Diamond**|**Identifying Relationship**: Links a weak entity to its identifying entity.|
|**Line**|**Link**: Connects entities, attributes, and relationships.|
|**Dashed Line**|**Partial Key**: Represents a partial key attribute (used for weak entities).|

Explain Different types of relationships amongst tables in a tables in a DBMS
- **One to One Relationship** -> applied when a particular row in table X is linked to a singular row in table Y.  `[Person]---1---<has>---1---[Passport]`

- **One to Many Relationship** -> applied when a single row in table X is related to many rows in table Y.  `[Customer]---1---<has>---n---[Account]`

- **Many to Many Relationship**-> applied when multiple rows in table X can be linked to multiple rows in table Y. `[Customer]---m---<buys>---n---[Product]`

- **Self Referencing Relationship** -> applied when a particular row in table X is associated with the same table. ❓
```
[Customer]---<makes>---[Order]

[Order]---<Salutation>---[Salutation]

[ Salutation  ]   [ Salutation  ]   [  Salutation   ]
 --------------   ---------------    ----------------
| Customer_id ──┐ | Order_id    |   | Product_id    |
| Name        | └── Customer_id | ┌── Product_Name  |
| Age         |   | Product_id  ──┘ | Price         |
| Mobile_No   |   |             |   | Date          | 
```

Explain different levels of data abstraction in a DBMS.
- Data Abstraction -> The process of hiding irrelevant details from users is known as data abstraction.
- Data abstraction can be divided into 3 levels:

- **Internal or Physical Level**: 
	- it is the lowest level and is managed by DBMS. 
	- This level consists of -> data storage descriptions
	- The details of this level are typically hidden from -> system admins, developers, and users.
- **Conceptual or Logical level**:
	- it is the level on which -> developers and system admins work
	- It determines  -> what data is stored in the database and what is the relationship between the data points.
- **External or View level** ->
	- It is the level -> that describes only part of the database and hides the details of the table schema and its physical storage from the users.
	- The result of a query is an example of View level data abstraction. A view is a virtual table created by selecting fields from one or more tables present in the database.

```
External Level
[view 1]  [view 2]  [view 3]
    \     |     / -------------> External-Conceptual Mapping
      \   |    /
    Conecptual Level
          |   -----------------> Conceptual-Internal Mapping
          |
    Internal Level
          | 
          |
         🛢️(Database)       
```

Important Interchangeable Terms
- `External = View` Level Schema
- `Conceptual = Logical`  Level Schema
- `Internal = Physical` Level  Schema
- `External/Conceptual Mapping = Logical Data Independence`
- `Conceptual/Internal Mapping = Physical Data Independence`

What is Data Warehousing? ⭐
- **Data warehousing** -> The process of collecting, extracting, transforming, and loading data from multiple sources and storing them in one database.
- A data warehouse can be considered as a central repository where data flows from transactional systems and other relational databases and is used for data analytics. 
- the data may be used for -> `Reporting, OLAP Analysis, Data Mining` etc.
- A data warehouse comprises a wide variety of an organization's historical data that supports the decision-making process in an organization.

---
### 3. Advanced


Explain the difference between a 2-tier and 3-tier architecture in a DBMS. ❓
- **2-tier :** the application `logic` is either buried inside the `User Interface on the client or within the database on the server (or both)`. With two-tier client/server architectures, the user system interface is usually located in the user’s desktop environment and the database management services are usually in a server that is a more powerful machine that services many clients.
- Example - Contact Management System created using MS-Access or Railway Reservation System, etc.
```
    Client 🖥️   Client 🖥️    Client 🖥️
             \      |       /
                \   |     /
                 Data Source 🛢️
```

- **3-tier:** contains another layer between the client and the server to provide GUI to the users and make the system much more secure and accessible. In this type of architecture, the application present on the client end interacts with an application on the server end which further communicates with the database system.
- Example - Designing registration form which contains a text box, label, button or a large website on the Internet, etc.
```
    Client 🖥️   Client 🖥️    Client 🖥️
             \      |       /
                \   |     /
            Application Server🗄️
                    |
                    |
                 Data Source 🛢️
```



Different types of keys in a database 
- There are mainly **7** types of keys in a database.
- **Candidate Key** -> A set of properties that can uniquely identify a `table`.
	-> One key amongst all candidate keys can be chosen as a primary key.
- **Primary Key** -> A set of attributes that are used to uniquely identify `every tuple` (and can't be null)
- **Alternate Key** -> All the candidate keys which are not chosen as primary keys are considered as alternate Keys
- **Super Key** -> A set of attributes that can uniquely identify a tuple.
	       -> It is a Superset of Primary and Candidate Key. ❓

- **Unique Key*** -> Similarly to the primary key except that it allow `NULL` values in the column unlike primary key.
	-> It is a primary keys with NULL values.
- **Foreign Key** -> An attribute that can only take the values present in one table common to the attribute present in another table. ❓
- **Composite Key** -> Combination of two or more columns that can uniquely identify each tuple in a table.

![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/282/original/db_keys.png?1617188783)

![](https://s3.ap-south-1.amazonaws.com/myinterviewtrainer-domestic/public_assets/assets/000/000/240/original/relationship_between_keys.png?1616078153)


Explain different types of Normalization forms in a DBMS.

| **Normal Form** | **Conditions**                                      | **Purpose**                        |
| --------------- | --------------------------------------------------- | ---------------------------------- |
| **1NF**         | Atomic values, unique column names, unique rows.    | Remove repeating groups.           |
| **2NF**         | 1NF + Full dependency on primary key.               | Remove partial dependency.         |
| **3NF**         | 2NF + No transitive dependency.                     | Remove indirect dependency.        |
| **BCNF**        | 3NF + every determinant is a candidate key.         | Handle anomalies in 3NF.           |
| **4NF**         | BCNF + No multi-valued dependencies.                | Remove redundancy from MVDs.       |
| **5NF**         | 4NF + No join dependency. (Lossless decomposition.) | Eliminate join-related redundancy. |
| **6NF**         | 5NF + deals with temporal or non-atomic data.       | Handle time-dependent data.        |

---

Most prac