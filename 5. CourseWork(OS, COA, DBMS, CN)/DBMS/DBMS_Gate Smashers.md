
Attribute - field - column 
Tuple - Data - Row

---
# Keys

In Database Management Systems (DBMS), **keys** are crucial for identifying unique rows in tables and establishing relationships between different tables. Here are the different types of keys and their significance, along with some **common interview questions** about keys in DBMS:

### **Types of Keys in DBMS:**

1. **Primary Key**:
   - A column (or combination of columns) that uniquely identifies each row in a table.
   - It cannot have NULL values.
   - Example: In a table of students, `student_id` can be the primary key.

2. **Candidate Key**:
   - A set of columns that can uniquely identify any row in a table. A table can have multiple candidate keys, but only one is selected as the primary key.
   - Example: Both `student_id` and `email` might be candidate keys for a student table.

3. **Super Key**:
   - Any set of attributes that can uniquely identify a row in a table.
   - Example: `{student_id}` or `{student_id, email}` are super keys, as both can uniquely identify a record.

4. **Foreign Key**:
   - A column (or a set of columns) in one table that references the primary key in another table. This enforces referential integrity.
   - Example: In a `course_enrollments` table, `student_id` might be a foreign key referencing the `students` table.

5. **Composite Key**:
   - A key made up of two or more columns that, together, uniquely identify a row.
   - Example: In an `order_details` table, a combination of `order_id` and `product_id` could be a composite key.

6. **Alternate Key**:
   - A candidate key that is not selected as the primary key.
   - Example: If `email` is a candidate key but `student_id` is chosen as the primary key, then `email` becomes an alternate key.

7. **Unique Key**:
   - A column (or a set of columns) that ensures all values are unique across rows. Unlike a primary key, it allows NULL values.
   - Example: A `username` column in a `users` table might be a unique key.

8. **Surrogate Key**:
   - An artificial key introduced when no natural key exists, typically an auto-incrementing number.
   - Example: `id` column generated automatically in databases.

---

### **Common Interview Questions on Keys in DBMS**:

1. **What is a Primary Key, and how is it different from a Unique Key?**
   - **Answer**: A primary key uniquely identifies a row and cannot be NULL, while a unique key also ensures uniqueness but can have NULL values.

2. **Can a table have more than one Primary Key?**
   - **Answer**: No, a table can only have one primary key. However, it can have multiple candidate keys.

3. **What is the difference between a Primary Key and a Foreign Key?**
   - **Answer**: A primary key uniquely identifies records in its table, while a foreign key is used to refer to the primary key of another table, maintaining referential integrity between tables.

4. **What are Candidate Keys, and how are they different from Super Keys?**
   - **Answer**: A candidate key is the minimal set of attributes that can uniquely identify a row. A super key is any combination of attributes that can uniquely identify a row. Every candidate key is a super key, but not every super key is a candidate key.

5. **What is a Composite Key, and when would you use it?**
   - **Answer**: A composite key consists of two or more columns that together uniquely identify a record. It's used when no single column can uniquely identify a record.

6. **What are Alternate Keys?**
   - **Answer**: Alternate keys are candidate keys that are not chosen as the primary key.

7. **Can a Foreign Key accept NULL values?**
   - **Answer**: Yes, a foreign key can accept NULL values unless constraints are applied to disallow them.

8. **What is a Surrogate Key, and why is it used?**
   - **Answer**: A surrogate key is an artificial key (e.g., an auto-incremented number) used when there is no natural key, or when using a natural key would be inefficient or problematic.

9. **What is the difference between a Composite Key and a Candidate Key?**
   - **Answer**: A composite key is a key made up of more than one column, whereas a candidate key is any key (composite or not) that can uniquely identify a row.

10. **What are the advantages of using a Foreign Key in a database?**
    - **Answer**: Foreign keys enforce referential integrity, ensuring that relationships between tables remain consistent. It prevents invalid data from being entered and maintains the linkage between related tables.

---
# [Lec-74: ACID Properties of a Transaction | Database Management System](https://youtu.be/-GS0OxFJsYQ)

ACID : Atomicity Consistency Isolation Durability

#### 1. Atomicity:
- Either All or None
- If any operation in a transaction fail before commit, we will roll back. Either All operation should be executed or only one.
- A failed Transaction cannot be resumed, it will be restart.

Ex: - Sending money to a bank account. if OTP failed, you need to restart from first step.


For a Transaction
```
 T1
----
R(A)
A=A-50
W(A)
R(B) x -> Roll back
R(C)
.
.
```

#### 2. Consistency

- Before transaction start and  after the transaction completed, sum of money should be same. 
- The sum of money of the receiver and sender bank account should be same.

#### 3. Isolation
- Converting Parallel Schedule to Serial Schedule (If we could, then the transaction would be consistent)
```
T1   ⇆   T2
```

#### Durability
- The changes Done through transaction should be permanent.
- Like we store data on Harddisk rather than Ram for Durability


# [Lec-38: Introduction to Joins and its types | Need of Joins with example | DBMS](https://youtu.be/zYH-e6tUYbw)

- Joins are covered in Relational Algebra and Also in SQL
- Concept in both are same, just difference of syntax.

#### Joins
- Result from combinations of tables
- Join = Cross product + Select Statement (Condition)
- Condition for Joins : The two table should have common attribute (here `E_No')

In any Join
Step 1: Cross Product
Step 2: Condition

```
  p.k                                 f.k
|E_No|E_name|Address|  |Dep_No|Name |E_No|
|----|------|-------|  |------|-----|----|
|1   |Ram   |Delhi  |  |D1    |HR   |1   |
|2   |Varun |Chda.  |  |D2    |IT   |2   |
|3   |Ravi  |Chad.  |  |D3    |MRKT |4   |
|4   |Amrit |Delhi  |  |D4    |FINAN|5   |
|5   |Nitin |Noida  | 

    Employee                Department
```
Ex: Display Employee Name whose working in HR??
	Require two table -> so required join

Types of Joins
1. Cross Join
2. Natural Join
3. Conditional 
4. Equi Join
5. Self Join
6. Outer Join -> left, right, full
Inner Join??

# [Lec-39: Natural Join operation with Example | Database Management System](https://youtu.be/jRxEjmjIIFs)

#### Natural Join

 A **Natural Join** in SQL is a type of join that automatically matches columns with the same names and compatible data types from two tables. It removes duplicate columns from the result, which means if the tables share columns with the same name, the result will include only one of those columns.

Syntax:
```mysql
Select E_Name
From Emp 
Natural Join Dept;
```

Working:

- `Join` = `Cross Product` + `Condition`
- `Natural Join` = `Cross Product` + `(Common Attribute should be same)`

#### Q. Find the Employee Names who is working in a department
```
  p.k                                 f.k
|E_No|E_name|Address|  |Dep_No|DName|E_No|
|----|------|-------|  |------|-----|----|
|1   |Ram   |Delhi  |  |D1    |HR   |1   |
|2   |Varun |Chda.  |  |D2    |IT   |2   |
|3   |Ravi  |Chad.  |  |D3    |MRKT |4   |
|4   |Amrit |Delhi  |
    Emp                      Dept
```

Step 1: `Select * From Emp, Dept;` 
```
Join -> Emp, Dept -> Cross Product -> Emp X Dept

|E_No|E_name|Address|Dep_No|DName|ENo|
|----|------|-------|------|-----|----|
|1   |Ram   |Delhi  |D1    |HR   |1   | <- ✅
|1   |Ram   |Delhi  |D2    |IT   |2   |
|1   |Ram   |Delhi  |D3    |MRKT |4   |
|2   |Varun |Chda.  |D1    |HR   |1   |
|2   |Varun |Chda.  |D2    |IT   |2   | <- ✅
|2   |Varun |Chda.  |D3    |MRKT |4   |
|3   |Ravi  |Chad.  |D1    |HR   |1   |
|3   |Ravi  |Chad.  |D2    |IT   |2   |
|3   |Ravi  |Chad.  |D3    |MRKT |4   |
|4   |Amrit |Delhi  |D1    |HR   |1   |
|4   |Amrit |Delhi  |D2    |IT   |2   |
|4   |Amrit |Delhi  |D3    |MRKT |4   | <- ✅

No. of Rows = 4 x 3 = 12
```

Step 2: `Select * From Emp, Dept Where Emp.E_No=Dept.E_No`; 
```
Natural Join -> Common Attribute same -> E_No=E_No

|E_No|E_name|Address|Dep_No|DName|E_No|
|----|------|-------|------|-----|----|
|1   |Ram   |Delhi  |D1    |HR   |1   | <- ✅
|2   |Varun |Chda.  |D2    |IT   |2   | <- ✅
|4   |Amrit |Delhi  |D3    |MRKT |4   | <- ✅

No. of Rows = min(4,3);
```

Step 3: 
```sql
Select E_Name From Emp, Dept Where Emp.E_no=Dept.E_no;
```

```
Columns need to be Select -> Employee Name -> E_Name

|E_name|
|------|
|Ram   |
|Varun |
|Amrit |
```

Note: 
this special syntax only work if the name of the attribute are same. `E_No and E_No`, Else it Will become Equi Join

---

# [Lec-40: Self Join operation with Example | Database Management System](https://youtu.be/6DQpvfdj6EE)
#### Self Join

A **Self Join** is a type of join in SQL where a table is joined with itself. It is used when there is a need to compare rows within the same table. Essentially, the table is treated as if it were two separate tables, allowing for comparisons between different rows in that same table.

Since SQL doesn't allow (give error) tables to be directly self-referenced in a query, **aliases** are typically used to represent the same table under different names.

```mysql
SELECT DISTINCT S1.S_id
FROM Study S1
JOIN Study S2
ON S1.S_id = S2.S_id /* Equi Join */
WHERE S1.C_id <> S2.C_id;
```
#### Q. Find Student id who is enrolled in at least two Courses

```
Study

|S_id|C_id|Since|
|----|----|-----|
|S1  |C1  |2016 |
|S2  |C2  |2017 |
|S1  |C2  |2017 |
```

Step 1: `Select * From Study as T1, Study as T2;`
```
Join -> Cross Product -> T1 X T2

|S_id|C_id|Since|S_id|C_id|Since|
|----|----|-----|----|----|-----|
|S1  |C1  |2016 |S1  |C1  |2016 |
|S2  |C2  |2017 |S1  |C1  |2016 |
|S1  |C2  |2017 |S1  |C1  |2016 | <- ✅
|S1  |C1  |2016 |S2  |C2  |2017 |
|S2  |C2  |2017 |S2  |C2  |2017 |
|S1  |C2  |2017 |S2  |C2  |2017 |
|S1  |C1  |2016 |S1  |C2  |2017 | <- ✅
|S2  |C2  |2017 |S1  |C2  |2017 |
|S1  |C2  |2017 |S1  |C2  |2017 |
```
Note: Alias name should be created, either it would give error using two same name table.

Step 2: `Select * From Study as T1, Study as T2;`
```
Self Join -> Same id, but different course -> S_id=S_id and C_id!=Cid

|S_id|C_id|Since|S_id|C_id|Since|
|----|----|-----|----|----|-----|
|S1  |C2  |2017 |S1  |C1  |2016 | <- ✅
|S1  |C1  |2016 |S1  |C2  |2017 | <- ✅
```

Step 3: 
```sql
Select T1.S_id From Study as T1, Study as T2 Where T1.s_id=T2.s_id and T1.c_id<>T2.c_id;
/* <> (not equal to )*/
```

```
|S_id|
|----|
|S1  |
```

# [Lec-41: Equi Join operation with Example | Database Management System](https://youtu.be/lUiPjkOQG9w)

#### Equi Join

An **Equi Join** is a type of join in SQL where two tables are combined based on an equality condition between specified columns of both tables. In an **Equi Join**, you explicitly specify the columns that should be compared for equality using the `ON` clause.

Syntax:
```sql
SELECT E_name
FROM Emp 
JOIN Dept
ON Emp.Address = Dept.Locat; /* Equi Join */
```

#### Q. Find the Emp name who worked in a department having location same as their address?
```
  p.k                                 f.k
|E_No|E_name|Address|  |Dep_No|Locat|ENo|
|----|------|-------|  |------|-----|---|
|1   |Ram   |Delhi  |  |D1    |Delhi|1  |
|2   |Varun |Chda.  |  |D2    |Pune |2  |
|3   |Ravi  |Chad.  |  |D3    |Patna|4  |
|4   |Amrit |Delhi  |
    Emp                      Dept
```

`Select * E_name from Emp, Dept;`
```
Join -> Emp, Dept -> Cross Product -> Emp X Dept

|E_No|E_name|Address|Dep_No|Locat|ENo|
|----|------|-------|------|-----|---|
|1   |Ram   |Delhi  |D1    |Delhi|1  | <- ✅
|1   |Ram   |Delhi  |D2    |Pune |2  |
|1   |Ram   |Delhi  |D3    |Patna|4  |
|2   |Varun |Chda.  |D1    |Delhi|1  |
|2   |Varun |Chda.  |D2    |Pune |2  | <- ✅
|2   |Varun |Chda.  |D3    |Patna|4  |
|3   |Ravi  |Chad.  |D1    |Delhi|1  |
|3   |Ravi  |Chad.  |D2    |Pune |2  |
|3   |Ravi  |Chad.  |D3    |Patna|4  |
|4   |Amrit |Delhi  |D1    |Delhi|1  |
|4   |Amrit |Delhi  |D2    |Pune |2  |
|4   |Amrit |Delhi  |D3    |Patna|4  | <- ✅
```

Step 3: Natural Join + Condition
Note: Natural Join is Always Necessary for Correct Join

`Select * E_name from Emp, Dept Where Emp.E_no=Dept.E_no;`
```
|E_No|E_name|Address|Dep_No|Locat|E_No|
|----|------|-------|------|-----|---|
|1   |Ram   |Delhi  |D1    |Delhi|1  | <- ✅
|2   |Varun |Chda.  |D2    |Pune |2  |
|4   |Amrit |Delhi  |D3    |Patna|4  |
```


```sql
Select E_name E_name from Emp, Dept  Where Emp.E_no=Dept.E_no and Emp.Address=Dept.Locat;
```

```
|E_name|
|------|
|Ram   |
```

---
# Joins

![](https://i.sstatic.net/UI25E.jpg)

**Inner Join** = Intersection
  - **Definition**: Retrieves matching records from both tables.  
  - **Equivalent to**: Intersection of two sets.

**Outer Join** = Inner Join + Left + Right = Union
  - **Definition**: Retrieves all records from one or both tables, including non-matching ones. 
  - **Equivalent to**: Union of **Inner Join**, **Left Outer Join**, and **Right Outer Join**.

**Left Outer Join** = Inner Join + Left 
  - **Definition**: Retrieves all records from the left table and matching records from the right table (with NULLs for non-matches).  
  - **Equivalent to**: Inner Join + Left records.

**Right Outer Join** = Inner Join + Right
  - **Definition**: Retrieves all records from the right table and matching records from the left table (with NULLs for non-matches).  
  - **Equivalent to**: Inner Join + Right records.

```mysql
/*In SQL You can the syntax can be interchanchably used*/

Left OUTER Join /* Outer is optional ->*/ Left Join
Right OUTER JOin /* Outer is optional ->*/ Right Join
Full Outer Join /*Full or Outer is Not optional*/

```

---
# [Lec-42: Left Outer Join operation with Example | Database Management System](https://youtu.be/unxn0KnzBzk)

#### Left Outer Join
It gives the matching rows and the rows which are in left table but not in right table.


```
|E_No|E_name|Dep_No|  |Dep_No|D_Name|Locat|
|----|------|------|  |------|------|-----|
|E1  |Varun |D1    |  |D1    |HR    |Delhi|
|E2  |Amrit |D2    |  |D2    |IT    |Hybd |
|E3  |Ravi  |D1    |  |D3    |Finan |Pune |
|E4  |Nitin |-     |
		Emp                 Dept
```

```mysql
Select *
From Emp Left Outer Join Dept /* Left Join*/
ON (Emp.Dep_no=Dept.Dep_no) /*Inner Join*/
```

Output
```
|E_No|E_name|Dep_No|D_Name|Locat|
|----|------|------|------|-----|
|E1  |Varun |D1    |HR    |Delhi|
|E2  |Amrit |D2    |IT    |Hybd |
|E3  |Ravi  |D1    |HR    |Delhi|
|E4  |Nitin |-     |-     | _   | -> Extra due to Left Join
```

# [Lec-43: Right Outer Join operation with Example | Database Management System](https://youtu.be/t7J__TGqoQs)

#### Right Outer Join
It Gives the matching frows and the rows which are in Right table but not in left table

```
|E_No|E_name|Dep_No|  |Dep_No|D_Name|Locat|
|----|------|------|  |------|------|-----|
|E1  |Varun |D1    |  |D1    |HR    |Delhi|
|E2  |Amrit |D2    |  |D2    |IT    |Hybd |
|E3  |Ravi  |D1    |  |D3    |Finan |Pune |
                      |D4    |Testn |Noida|
		Emp                 Dept
```

```mysql
Select *
From Emp Right Outer Join Dept /* Right Join*/
ON (Emp.Dep_no=Dept.Dep_no) /*Inner Join*/
```

Output
```
|E_No|E_name|Dep_No|D_Name|Locat|
|----|------|------|------|-----|
|E1  |Varun |D1    |HR    |Delhi|
|E2  |Amrit |D2    |IT    |Hybd |
|E3  |Ravi  |D1    |HR    |Delhi|
|-   |-     |D4    |Testn |Noida| -> Extra due to Right Join
```

---

# Natural Join vs Equi Join vs Inner Join

**Equi Join** is a specific case of **Inner Join** focused on equality conditions.
```sql
SELECT *
FROM TableA
JOIN TableB
ON TableA.id = TableB.id;
```

**Natural Join** simplifies the process by automatically matching columns with the same names, removing duplicates in the output.
```mysql
SELECT *
FROM TableA
NATURAL JOIN TableB;
```


**Inner Join** is the most general form, allowing various conditions to determine how tables are joined.
```mysql
SELECT *
FROM TableA
INNER JOIN TableB
ON TableA.id = TableB.id;
```

| **Aspect**            | **Equi Join**                                   | **Natural Join**                                       | **Inner Join**                                                             |
| --------------------- | ----------------------------------------------- | ------------------------------------------------------ | -------------------------------------------------------------------------- |
| **Definition**        | Joins tables based on equality conditions.      | Joins tables based on all columns with matching names. | Joins tables based on a specified condition (equality or otherwise).       |
| **Join Condition**    | Explicitly defined (e.g., `A.id = B.id`).       | Implicitly defined using matching column names.        | Explicitly defined or can be based on other conditions.                    |
| **Duplicate Columns** | Retains duplicate columns unless specified.     | Removes duplicate columns from the result.             | Retains all columns based on specified conditions, may contain duplicates. |
| **Use Case**          | Used for specific equality-based relationships. | Used for joining on all common columns automatically.  | Used for combining related data based on defined criteria.                 |
| **Result Set**        | Includes all matched records.                   | Includes all matched records, no duplicates.           | Includes all matched records based on the join condition.                  |


# [Lec-114: What is RAID? RAID 0, RAID 1, RAID 4, RAID 5, RAID 6, Nested RAID 10 Explained]

# RAID
- Redundant Array of Independent Disks
- Also, Redundant Array of Inexpensive Disks

Redundant - Copy of Data
Array - Multiple Disks
Independent - If one fail, other will not affected
Inexpensive - Cheap Storage (Cost : Registers > Cache > Ram > Disk)
Disks - To Store Data

Why Raid ??
1. Performance (Read/Write)
2. Security (Available 24x7)

### RAID 0
- Level 0
- Data Stripping
- Parallel Read and Write-> Performance Fast


```
Let Original Data A, B, C, D

break down the data and store in seperate disk

A->A1+A2
B->B1+B2
C->C1+C2
D->D1+D2
```

Divide each data into two parts and store parallelly
```
            RAID 0
            /     \
        A1          A2
        B1          B2
        C1          C2
        D1          D2
      (Disk 0)    (Disk 1)
```

### RAID 1

- Level 1
- Data Mirroring
- Data Secure and Reliable
- Cost Expensive? No (We are using Inexpensive Disks)

```
            RAID 1
           /     \
         A         A
         B         B
         C         C
         D         D
      (Disk 0)    (Disk 1)
```

### RAID 10 or RAID 01
- RAID + RAID 2
- Stripping & Mirroring
- Reliable and Fast Performance
- Very Useful In real life
- ex: Email Servers, Web Servers

```
                 RAID 1+0

                     RAID 0
                   /      \
             RAID 1           RAID 1      
           /   \              /    \
        A1      A1           A2     A2
        B1      B1           B2     B2
        C1      C1           C2     C2
        D1      D1           D2     D2
      (Disk 0)  (Disk 1)   (Disk 2)  (Disk 3)
```


### RAID 2
- Bit Level Breaking of Data
- Raid 2 is Obsolete

### RAID 3
- Slicing + Store The All data into Parity Disk
- Reliable and Secure : If a Disk Fail, Can be recover from Parity Disk
- Bottle Neck Problem: Every time write in disk, Parity Disk should also be update
- Parity Disk over Utilized Problem
- If any Parity Disk failed, Can't be recovered

```
               RAID 3
   /       /           \          \    
A1         A2         A3        Ap(1-3)
B1         B2         B3        Bp(1-3)
C1         C2         C3        Cp(1-3)
D1         D2         D3        Dp(1-3)
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3)
                                   ˄
                                  Parity Disk
```

#### RAID 4
- Not much changes from RAID 3
```
               RAID 4
   /        /          \        \    
A1         A2         A3        Ap
B1         B2         B3        Bp
C1         C2         C3        Cp
D1         D2         D3        Dp
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3)

```


#### RAID 5
- RAID 3 + Parity Distributed Among Disks
- All disks will be equally utilized
```
               RAID 5
   /        /          \        \    
A1         A2         A3        Ap
B1         B2         Bp        B3
C1         Cp         C3        C3
Dp         D2         D3        D3
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3)
```

#### RAID 6
- RAID 5 + 2 Parity Distribution
- If any one Parity disk failed, It could be recovered (but not 2)
```
                     RAID 6
   /        /          |       \         \   
A1         A2         A3        Ap       Aq
B1         B2         Bp        Bq       B3
C1         Cp         Cq        C2       C3
Dp         Dq         D1        D2       D3
Eq         E1         E2        E3       Ep
(Disk 0)  (Disk 1)  (Disk 2)   (Disk 3) (Disk 4)
```