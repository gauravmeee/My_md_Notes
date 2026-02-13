# ▶️ Tutorial\_DBMS Joins ( Smashers 38 - 43 )

## [Lec-38: Introduction to Joins and its types | Need of Joins with example | DBMS](https://youtu.be/zYH-e6tUYbw)

* Joins are covered in Relational Algebra and Also in SQL
* Concept in both are same, just difference of syntax.

**Joins**

* Result from combinations of tables
* Join = Cross product + Select Statement (Condition)
* Condition for Joins : The two table should have common attribute (here \`E\_No')

In any Join Step 1: Cross Product Step 2: Condition

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

Ex: Display Employee Name whose working in HR?? Require two table -> so required join

Types of Joins

1. Cross Join
2. Natural Join
3. Conditional
4. Equi Join
5. Self Join
6. Outer Join -> left, right, full Inner Join??

## [Lec-39: Natural Join operation with Example | Database Management System](https://youtu.be/jRxEjmjIIFs)

**Natural Join**

A **Natural Join** in SQL is a type of join that automatically matches columns with the same names and compatible data types from two tables. It removes duplicate columns from the result, which means if the tables share columns with the same name, the result will include only one of those columns.

Syntax:

```mysql
Select E_Name
From Emp 
Natural Join Dept;
```

Working:

* `Join` = `Cross Product` + `Condition`
* `Natural Join` = `Cross Product` + `(Common Attribute should be same)`

**Q. Find the Employee Names who is working in a department**

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

Note: this special syntax only work if the name of the attribute are same. `E_No and E_No`, Else it Will become Equi Join

## [Lec-40: Self Join operation with Example | Database Management System](https://youtu.be/6DQpvfdj6EE)

**Self Join**

A **Self Join** is a type of join in SQL where a table is joined with itself. It is used when there is a need to compare rows within the same table. Essentially, the table is treated as if it were two separate tables, allowing for comparisons between different rows in that same table.

Since SQL doesn't allow (give error) tables to be directly self-referenced in a query, **aliases** are typically used to represent the same table under different names.

```mysql
SELECT DISTINCT S1.S_id
FROM Study S1
JOIN Study S2
ON S1.S_id = S2.S_id /* Equi Join */
WHERE S1.C_id <> S2.C_id;
```

**Q. Find Student id who is enrolled in at least two Courses**

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

## [Lec-41: Equi Join operation with Example | Database Management System](https://youtu.be/lUiPjkOQG9w)

**Equi Join**

An **Equi Join** is a type of join in SQL where two tables are combined based on an equality condition between specified columns of both tables. In an **Equi Join**, you explicitly specify the columns that should be compared for equality using the `ON` clause.

Syntax:

```sql
SELECT E_name
FROM Emp 
JOIN Dept
ON Emp.Address = Dept.Locat; /* Equi Join */
```

**Q. Find the Emp name who worked in a department having location same as their address?**

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

Step 3: Natural Join + Condition Note: Natural Join is Always Necessary for Correct Join

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

## [Lec-42: Left Outer Join operation with Example | Database Management System](https://youtu.be/unxn0KnzBzk)

**Left Outer Join**

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

## [Lec-43: Right Outer Join operation with Example | Database Management System](https://youtu.be/t7J__TGqoQs)

**Right Outer Join**

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
