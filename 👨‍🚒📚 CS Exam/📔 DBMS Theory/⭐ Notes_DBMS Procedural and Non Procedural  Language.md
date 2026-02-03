
# Procedural Language (DBMS)

- User specifies ==_what data_ is required **and** _how to get it_== (sequence of steps)
- Query execution path is defined by user
- Define Steps, More control, ==less abstraction==
- 
**Examples:**
1. Relational Algebra
2. Tuple Relational Calculus (considered weakly procedural in exams)

**eg:- Relational Algebra** (RA)
```sql
π name (σ marks > 80 (STUDENT))
```
- First **==select** tuples==
- Then ==**project** attributes==

**eg:- Tuple Relational Calculus** (TRC)
```sql
{ t.name | STUDENT(t) ∧ t.marks > 80 }
```
- Specify desired attribute in result
- Give condition on tuples (no explicit operation order)

##### **1. Relational Algebra Operations** ⭐

**Primitive (Basic) Operations:**
- Selection (σ)
- Projection (π)
- Cartesian Product (×)
- Union (∪)
- Set Difference (−)
- Rename (ρ)

**Derived Operations:**
- Intersection (∩)
- Join (⨝)
- Division (÷)

**Unary Operations**

| Operation  | Symbol | Purpose                          | Example                |
| ---------- | ------ | -------------------------------- | ---------------------- |
| Selection  | σ      | Select rows satisfying condition | `σ_Age>20(Student)`    |
| Projection | π      | Select specific columns          | `π_Name, Age(Student)` |
| Rename     | ρ      | Rename relation or attributes    | `ρ_Stud(Student)`      |

**Binary Operations**

| Operation         | Symbol | Purpose                                  | Example                         |
| ----------------- | ------ | ---------------------------------------- | ------------------------------- |
| Union             | ∪      | Tuples in either relation                | `Student ∪ Alumni`              |
| Set Difference    | -      | Tuples in first, not in second           | `Student - Alumni`              |
| Intersection      | ∩      | Tuples common to both                    | `Student ∩ Scholarship`         |
| Cartesian Product | ×      | All combinations of tuples               | `Student × Course`              |
| Join              | ⨝      | Combine tuples based on condition        | `Student ⨝_ID=Enroll.ID Enroll` |
| Division          | ÷      | Tuples related to all in second relation | `StudentID ÷ CourseID`          |

- **Unary:** operate on one relation
- **Binary:** operate on two relations
- **Rename (ρ)** helps in queries and avoiding conflicts.


**Examples** :

1. **Find all students older than 20**
	`σ_Age>20 (Student)`

2. **Find all students enrolled in a 4-credit course**
	`σ_Credit=4 (Student ⨝ Student.CourseID = Course.ID Course)`

3. **Find all students with marks > 80**
	`σ_Marks>80 (Student)`

4. **Find names of students in “DBMS” course**
	`π_Name (σ_CourseName='DBMS' (Student ⨝ Student.CourseID = Course.ID Course))`

5. **Find students who have taken all courses offered**
	`π_StudentID (Enroll) ÷ π_CourseID (Course)`

##### **2. Tuple Relational Calculus (TRC)**

| Feature             | Description                                                  |
| ------------------- | ------------------------------------------------------------ |
| Definition          | Non-procedural query language using **tuples as variables**  |
| Tuple Variable      | Represents a tuple from a relation                           |
| Syntax              | `{t `\|` P(t)}`                                              |
| Predicate           | Condition on tuple `t` (comparisons, logical operators)      |
| Operators           | AND (`∧`), OR (`∨`), NOT (`¬`), `=`, `≠`, `<`, `>`, `≤`, `≥` |
| Quantifiers         | ==`∃` (exists)==, ==`∀` (for all)==                          |
| Characteristics     | Non-procedural; specifies **what** to retrieve, not **how**  |
| Difference from SQL | TRC is theoretical; SQL is practical                         |
**Examples** :

1. **Find all students older than 20**  
    `{ t | Student(t) ∧ t.Age > 20 }`
    
2. **Find all students enrolled in a 4-credit course**  
    `{ t | ∃c (Course(c) ∧ t.CourseID = c.ID ∧ c.Credit = 4) }`
    
3. **Find all students with marks > 80**  
    `{ t | Student(t) ∧ t.Marks > 80 }`
    
4. **Find names of students in “DBMS” course**  
    `{ t.Name | ∃c (Course(c) ∧ t.CourseID = c.ID ∧ c.CourseName = 'DBMS') }`
    
5. **Find students who have taken all courses offered**  
    `{ s | Student(s) ∧ ∀c (Course(c) → ∃e (Enroll(e) ∧ e.StudentID = s.ID ∧ e.CourseID = c.ID)) }`

---

# Non-Procedural Language (DBMS)

- User specifies ==_what data_ is required, not _how to retrieve_==
- DBMS decides execution plan
- Define Result Only, High-level, declarative, high abstraction

**Examples:**
1. SQL
2. Query By Example
3. Domain Relational Calculus (QBE)

**eg:- SQL**
```sql
SELECT name FROM STUDENT WHERE marks > 80;
```

**eg:- Query By Example (QBE)**
- Put condition `>80` under marks
- Put `P.` under name

**eg:- Domain Relational Calculus (DRC)**
```sql
{ <n> | ∃ r (STUDENT(n, r) ∧ r > 80) }
```
- Specify required domain variable in result
- Use logical condition on domains (no execution order)

##### **3. SQL (Structured Query Language)**

|Feature|Description|
|---|---|
|Definition|Declarative query language for relational databases|
|Nature|Non-procedural (user specifies **what**, not **how**)|
|Basis|Based on Relational Algebra & Relational Calculus|
|Core Clauses|`SELECT`, `FROM`, `WHERE`, `GROUP BY`, `HAVING`, `ORDER BY`|
|Joins|`INNER`, `LEFT`, `RIGHT`, `FULL`|
|Quantification|`EXISTS`, `NOT EXISTS`, `IN`, `ALL`, `ANY`|
|Characteristics|Practical, optimized by DBMS|
|Difference from TRC|SQL is executable; TRC is mathematical|

**Examples** :

1. **Find all students older than 20**
	`SELECT * FROM Student WHERE Age > 20;`

2. **Find all students enrolled in a 4-credit course**
	`SELECT DISTINCT s.* FROM Student s, Course c WHERE s.CourseID = c.ID AND c.Credit = 4;`

3. **Find all students with marks > 80**
	`SELECT * FROM Student WHERE Marks > 80;`

4. **Find names of students in “DBMS” course**
	`SELECT s.Name FROM Student s, Course c WHERE s.CourseID = c.ID AND c.CourseName = 'DBMS';`


##### **2. QBE (Query By Example)**

|Feature|Description|
|---|---|
|Definition|Visual, example-based query language|
|Nature|Non-procedural|
|Basis|Based on Domain Relational Calculus|
|Query Style|Conditions filled in table skeletons|
|Output Indication|`P.` (print)|
|Usage|Educational, conceptual (rare in real systems)|
|Difference from SQL|QBE is graphical; SQL is textual|

**Examples** :

1. **Find all students older than 20**
	- Put `>20` under `Age`
	- Put `P.` under required attributes

2. **Find all students enrolled in a 4-credit course**
	- Course table: put `4` under `Credit`
	- Match `CourseID`
	- Put `P.` under Student attributes

3. **Find all students with marks > 80**
	- Put `>80` under `Marks`
	- Put `P.` under Student attributes

4. **Find names of students in “DBMS” course**
	- Course table: put `DBMS` under `CourseName`
	- Match `CourseID`
	- Put `P.` under `Name`

5. **Find students who have taken all courses offered**
	- Use ALL rows of Course table
	- Match `StudentID` and `CourseID` via Enroll
	- Put `P.` under Student attributes


##### **3. Domain Relational Calculus (DRC)**

| Feature             | Description                                              |
| ------------------- | -------------------------------------------------------- |
| Definition          | Non-procedural query language using **domain variables** |
| Domain Variable     | Represents attribute values                              |
| Syntax              | `{ <x1, x2, …> \| P(x1, x2, …) }`                        |
| Predicate           | Conditions on domains using logic                        |
| Operators           | `∧`, `∨`, `¬`, `=`, `<`, `>`                             |
| Quantifiers         | ==`∃`, `∀`==                                             |
| Characteristics     | Mathematical, declarative                                |
| Difference from TRC | DRC uses domains; TRC uses tuples                        |

**Examples** :

1. **Find all students older than 20**
	`{ <n, a> | Student(n, a) ∧ a > 20 }`

2. **Find all students enrolled in a 4-credit course**
	`{ <s> | ∃c (Student(s, c) ∧ Course(c, 4)) }`

3. **Find all students with marks > 80**
	`{ <n> | ∃m (Student(n, m) ∧ m > 80) }`

4. **Find names of students in “DBMS” course**
	`{ <n> | ∃c (Student(n, c) ∧ Course(c, 'DBMS')) }`

5. **Find students who have taken all courses offered**
	`{ <s> | ∀c (Course(c) → ∃e (Enroll(s, c))) }`


---

