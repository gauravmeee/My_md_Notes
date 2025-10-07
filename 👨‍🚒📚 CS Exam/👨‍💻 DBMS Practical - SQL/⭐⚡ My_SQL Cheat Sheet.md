
### Types of  Language in SQL

**Data Definition Language (DDL):** Defines and manages the structure of database objects.
```mysql
 CREATE, ALTER, DROP, TRUNCATE
 USE, DESC/ DESCRIBE, SHOW
```

**Data Manipulation Language (DML):** Manipulates data within database tables.
```mysql
SELECT, INSERT, UPDATE, DELETE
```

**Data Control Language (DCL):** Controls access to data in the database.
```mysql
GRANT, REVOKE
```

**Transaction Control Language (TCL):** Manages transactions to ensure data integrity.
```mysql
COMMIT, ROLLBACK, SAVEPOINT, SET TRANSACTION
```

---
---
# DDL 

- *SHOW DATABASES*

##### `SHOW DATABASES`
```Mysql
SHOW DATABASES
```

---
### 1. DDL For Databases

- *CREATE, DROP, USE, SHOW TABLES*

##### `CREATE DATABASE`
```mysql
CREATE DATABASE DatabaseName;
-- or
CREATE DATABASE IF NOT EXISTS DatabaseName;
```

##### `DROP DATABASE`
```mysql
DROP DATABASE DatabaseName;
-- or
DROP DATABASE IF EXISTS DatabaseName
```
##### `USE`
```mysql
-- Selects the specified database for the current session
USE DatabaseName;
```

##### `SHOW TABLES`
```mysql
-- Lists all tables in the currently selected database
SHOW TABLES;
```

---
### 2. DDL For Tables

- *CREATE x3, ALTER x5, DROP, SHOW COLUMNS, DESC/DESCRIBE*

##### `CREATE TABLE`

```mysql
CREATE TABLE TableName(
ColumnName1 DataType [Size],
ColumnName2 DataType [Size],...
)
-- or
CREATE TABLE TableName(
ColumnName1 DataType [Size] Constraints,...)
```


`REFERENCES`  (defines a **foreign key constraint**) ⭐
```mysql
-- Links a column in one table to a `PRIMARY KEY` in another.
CREATE TABLE TableName (
  Column1 DataType,
  Column2 DataType,
  FOREIGN KEY (Column2) REFERENCES OtherTable(OtherColumn)
);
```
Or inline:
```mysql
CREATE TABLE TableName (
  Column1 DataType,
  Column2 DataType REFERENCES OtherTable(OtherColumn)
);
```

`AS` - `SELECT` 
```mysql
-- Create TAble from Existing Table
CREATE TABLE TableName AS
(SELECT ColumnName, ColumnName2 FROM TableName WHERE <Condition>)
```


**Full Use case Example** ⭐
```mysql
-- Table 1:  Use of -> Primary Keys, Size
CREATE TABLE Department (
  dept_id INT PRIMARY KEY,
  dept_name CHAR(30)
);

-- Table 2: Use of Primary Keys, Size, Foregin Key (References)
CREATE TABLE Student (
  student_id INT PRIMARY KEY,
  name CHAR(20),
  email VARCHAR(50),
  age INT,
  grade DECIMAL(4,2),
  dept_id INT,
  FOREIGN KEY (dept_id) REFERENCES Department(dept_id)
);

-- Table 3: Use of AS (Select)
CREATE TABLE TopStudents AS
SELECT student_id, name, grade
FROM Student
WHERE grade >= 90.00;
```

**NOTE**
- Ensures `Column2` in `Orders` must exist in `OtherTAble(OtherColumn)` ⭐
- `REFERENCES` requires the target column to be **uniquely identifiable** (**PRIMARY KEY** or **UNIQUE**)

**Benefit of linking to `PRIMARY KEY`:**
- Ensures **only valid values** (that exist in the referenced table) can be inserted.
- Maintains **referential integrity** (no broken or orphan records).
- Enables **relational mapping** (e.g., Orders → Customers).
- Supports **joins** across tables efficiently.
- Prevents **accidental deletion or updates** (with `ON DELETE` / `ON UPDATE` rules).
- This ensures **one-to-one or many-to-one** relationships can be enforced.

**Constraint vs size**
- `CHAR(5)` → allows **exactly 5 characters** (padded if shorter).
- `VARCHAR(5)` → allows **up to 5 characters**.
- `INT(5)` → **does not** restrict the number of digits.  (`INT`, `BIGINT` store **binary integers**, not character strings.)
- **Use `CHECK` for integer constraint**
```mysql
column2 INT,
CHECK (column2 BETWEEN 10000 AND 99999)  -- exactly 5-digit numbers
```
 

##### `ALTER TABLES`

`ADD`
```mysql
ALTER TABLE TableName
ADD ColumnName DataType (Size) <Constraint>
```

`MODIFY`
```mysql
ALTER TABLE TableName
MODIFY ColumnName DataType (Size)
```

`FIRST` / `AFTER`
```mysql
-- Places the modified column at the beginning of the ttable
ALTER TABLE TableName MODIFY ColumnName DataType(Size) FIRST;

-- Places the modified column immediately after the specified column.
ALTER TABLE TableName MODIFY ColumnName DataType(Size) AFTER ColumnName2;
```

`CHNAGE`
```mysql
-- Changing ColumnName
ALTER TABLE TableName CHANGE OldName NewName Datatype(Size)
```

`DROP`
```mysql
-- Removing Table Components
ALTER TABLE TableName 
DROP PRIMARY KEY,
DROP FOREIGN KEY,
DROP ColumnName,
```

##### `SHOW COLUMNS`
```mysql
-- to view column details of a table
SHOW COLUMNS FROM TableName;
```
##### `DESC` or `DESCRIBE`
```mysql
-- Shows the structure of the specified table (columns, data types, etc.)
DESC TableName;
-- or
DESCRIBE TableName;
```

##### `DROP TABLE`
```mysql
-- Drop Table Commands
DROP TABLE TableName;
-- or
DROP TABLE IF EXISTS TableName;
```

##### `TRUNCATE TABLE`
```mysql
-- Truncate Table Command (removes all rows, resets identity)
TRUNCATE TABLE TableName;
```
- Truncate Don't Delete Table itself, but its a `DDL` Command

**NOTE :**
- Faster than `DELETE` (which is in DML)
- Use **`TRUNCATE`** when you need to quickly clear all rows from a table but keep the table structure.
- Use **`DROP`** when you want to permanently delete a table, including its structure.

**Why Truncate is in DDL and not in DML ?**
1. **Resets structure (like AUTO_INCREMENT):**
    - Resets identity/auto-increment counters to start from initial value.
    - Example:
	```mysql
	TRUNCATE TABLE students; -- Next insert will start student_id from 1 again (if auto_increment)
	```
2. **No row-level logging & mostly non-rollbackable:**
    - Most DBMS don’t log individual row deletions.
    - Can’t `ROLLBACK` after `TRUNCATE` (unless in a transaction and supported).
3. **Deallocates entire data pages:**
    - Instead of deleting row-by-row (like `DELETE`), it frees up memory pages.
    - That’s why it’s **faster** and more **efficient**.

---
---
# DML

- *SELECT, INSERT, DELETE, UPDATE*
##### `SELECT`
```mysql
-- Show all columns
SELECT * FROM TableName;

-- Show specific columns
SELECT ColumnName1, ColumnName2, ColumnName3 FROM TableName;

-- This adds a fixed text column in the result for every row.
SELECT ColumnName, 'Text' FROM TableName;

/* ColumnName    |   'Text'
  ---------------|-----------
    Value 1      |    'Text'
    Value 2      |    'Text'
    Value 3      |    'Text'
*/
```

`DISTINCT`
```mysql
-- Select distinct rows
SELECT DISTINCT * FROM TableName;

-- Select distinct values in a specific column
SELECT DISTINCT ColumnName FROM TableName;
```

`ALL`
```mysql
-- select ALL (Include Non-Distinct) (ALL is implicit by default)

SELECT ALL * FROM TableName; -- Select all rows
SELECT ALL ColumnName FROM TableName; -- Select all values in a specific column

-- `ALL` as Comparison Operator
SELECT * FROM Employees
WHERE Salary > ALL (SELECT Salary FROM Employees);
-- This query selects employees whose salary is greater than all the salaries
```
Note:- `ALL` is **redundant** because it's the **default behavior**. It Select all **non-distinct** values (default).

`Expression`
```mysql
-- Evaluate a expression (MySQL, PostgreSQL, SQL Server, etc.)
SELECT 1 + 6; -- 
/*
| 1 + 6 |
|-------|
|   7   |
*/

-- Evaluate a expression (used in Oracle, Also work in MySQL)
SELECT 4 * 3 FROM DUAL;
/*
| 4 * 3 |
|-------|
|  12   |
*/

-- Scalar expression with a selected field
SELECT ColumnName * 100 FROM TableName;
```

**Note:**  `DUAL` is a special one-row, one-column table used in Oracle for expressions without needing actual data.  `DUAL` allows you to execute expressions like arithmetic, string manipulations, or system functions without requiring a real table.

`Top 100 fields` ⭐
```sql
-- In SQL Server, Sybase, MS Access --
SELECT TOP 100 * FROM TableName;

-- MySQL, MariaDB, PostgreSQL
`SELECT *  FROM TableName LIMIT 100;`
```


`AS`
```mysql
-- Using column aliases
SELECT ColumnName AS MyColumnName FROM TableName;
```

`IFNULL` ⭐
```mysql
-- Replaces NULL in ColumnName with 'ValueSubstitute'
SELECT IFNULL(ColumnName, 'ValueSubstitute') FROM TableName;
```

`WHERE`
```mysql
-- Filters rows based on specified conditions
SELECT ColumnName
FROM TableName
WHERE <Conditions>;
```


`BETWEEN`
```mysql
-- Filters rows where ColumnName is between x and y (inclusive)
... WHERE ColumnName BETWEEN x AND y
```

`IN`
```mysql
-- Filters rows where ColumnName matches any value in the list (x, y, z)
... WHERE ColumnName IN (x, y, z)
```

`LIKE`
```mysql
-- Filters rows where ColumnName starts with '13'
...WHERE ColumnName LIKE '13%'

-- Filters rows where ColumnName has exactly 3 characters
...WHERE ColumnName LIKE "___"
```

`IS NULL`
```mysql
-- Filters rows where ColumnName has a NULL value
...WHERE ColumnName IS NULL;
```
**Note:** `customerId = NULL` ❌ Syntax Error

**Full Use Case Example:** ⭐
```mysql
SELECT *
FROM Employees
WHERE (Bonus + Commission > 10000)
  AND (Department = 'Sales')
  AND (Name LIKE 'J___')          -- Name starts with J and has 4 letters
  AND (YearsExperience IS NOT NULL)
  AND NOT (JobTitle LIKE 'Intern%')    -- Exclude interns
  AND Department IN ('Sales', 'Marketing')   -- Department is either Sales or Marketing
  AND Age BETWEEN 30 AND 40;  -- Age between 30 and 40 (inclusive)
```

`<>` : not

`ORDER BY`
```mysql
-- Sorts the result set in ascending order by ColumnName (default)
SELECT * 
FROM TableName
ORDER By ColumName 
-- or
... ORDER BY ColumnName ASC;


-- Sorts the result set in descending order by ColumnName
... ORDER BY ColumnName DESC;
```

`GROUP BY`
```mysql
-- Groups rows based on unique values in ColumnName1 and calculates an aggregate function for each group
SELECT ColumnName1, AggregateFunction(ColumnName2)
FROM TableName
GROUP BY ColumnName1;


```

`HAVING`
```mysql
-- Filters groups created by the GROUP BY clause based on a condition applied to an aggregate function
SELECT ColumnName1, AggregateFunction(ColumnName2)
FROM TableName
GROUP BY ColumnName1
HAVING AggregateFunction(ColumnName2) < Condition;
```

**Where vs Having** Clause : ⭐

| Feature             | WHERE Clause                   | HAVING Clause               |
| ------------------- | ------------------------------ | --------------------------- |
| **Used On**         | Rows (Before grouping)         | Groups (After GROUP BY)     |
| **Aggregate Use**   | Cannot use aggregate functions | Can use aggregate functions |
| **Execution Order** | Evaluated before GROUP BY      | Evaluated after GROUP BY    |

**Non-Aggregate** vs **Aggregate** functions: ⭐

| **Aspect**                 | **Non-Aggregate Functions**      | **Aggregate Functions**                       |
| -------------------------- | -------------------------------- | --------------------------------------------- |
| **Definition**             | Work on individual rows          | Work on groups of rows                        |
| **Return Value**           | One result per row               | One result per group or table                 |
| **Usage**                  | In `SELECT`, `WHERE`, etc.       | In `SELECT`, `HAVING`, `GROUP BY`             |
| **Examples**               | `UPPER()`, `LOWER()`, `LENGTH()` | `SUM()`, `AVG()`, `COUNT()`, `MAX()`, `MIN()` |
| **Can be used in WHERE?**  | Yes                              | No                                            |
| **Can be used in HAVING?** | No                               | Yes                                           |

### Aggregate Functions

`ROUND()`
```mysql
-- Rounds the values in ColumnName
SELECT ROUND(ColumnName) AS MyColumnName FROM TableName;
```

`AVG()`
```mysql
-- Calculates the average of distinct values in ColumnName
SELECT AVG(DISTINCT ColumnName) FROM TableName;

-- Calculates the average of all values in ColumnName (default)
SELECT AVG(ALL ColumnName) FROM TAbleName;
```

`COUNT()`
```mysql
-- Counts all rows, including those with NULL values (* include null value)
SELECT COUNT(*)  FROM TableName;

-- Counts distinct non-NULL values in ColumnName
SELECT COUNT(DISTINCT ColumnName) FROM TableName;

-- Counts all non-NULL values in ColumnName (default)
SELECT COUNT(ALL ColumnName) FROM TableName; 
```

`MAX()`
```mysql
-- Finds the maximum of distinct values in ColumnName
SELECT MAX(DISTINCT ColumnName) FROM TableName;
```

`MIN()`
```mysql
-- Finds the minimum of distinct values in ColumnName
SELECT MIN(DISTINCT ColumnName) FROM TableName;
```

SUM()`
```mysql
-- Calculates the sum of distinct values in ColumnName
SELECT SUM(DISTINCT ColumnName) FROM TableName;
```


✅ Revision Done Upto here - 18 June 2025

##### `INSERT INTO`

`VALUES`
```mysql
INSERT INTO TableName ColumnName1 VALUES Value1 ;
-- or
INSERT INTO TableName (ColumnName1, ColumnName2) VALUES (Value1, Value2) ;
```

`SELECT`
```mysql
-- Inserts data into TableName by selecting rows from TableName2 
INSERT INTO TableName1 SELECT * FROM TableName2 WHERE <Conditions>;

-- Inserts specific columns into TableName1 by selecting them from TableName2
INSERT INTO TableName SELECT ColumnName FROM TableName WHERE <Conditions>;
```

##### `UPDATE`

`SET`
```mysql
-- Updates the value of ColumnName to Value2 for rows that meet the Condition
UPDATE TableName
SET ColumnName = Value2 WHERE <Condition>;

-- Increments the value of ColumnName by 900 for all rows in TableName
UPDATE TableName
SET ColumnName = ColumnName + 900;
```

##### `DELETE`

`FROM`
```mysql
-- Delete All Content
DELETE FROM TableName

-- Delete Specific Rows
DELETE FROM TableName WHERE <Predicate>
```

---

### Comments in SQL

SQL supports different types of joins: `INNER JOIN`, `LEFT JOIN`, `RIGHT JOIN`, `FULL JOIN`, `CROSS JOIN`.
## `--` or `/* ... */` 
```mysql
-- this is a single line

/* This is a 
Multiline Comment */
```
- In MySQL Single-line comments can be implemented with  `#` too , along with `--`

---

### SQL Clause order ⭐

- **`WHERE`** - Filters **rows** before any grouping happens.
- **`GROUP BY`** - Groups the filtered rows by specified column(s).
- **`HAVING`** - Filters **groups** (not individual rows) after aggregation.
- **`ORDER BY`** - Sorts the final result.

```sql
SELECT
FROM
--
WHERE
GROUP BY
HAVING
ORDER BY -- sorts the grouped result
```

**WHERE → GROUP BY → HAVING → ORDER BY**

---
### Data Types in SQL



##### 1. Numeric Data Types
- `INT` or `INTEGER` - Integer (whole number)
- `SMALLINT` - Smaller range integer  
- `BIGINT` - Large range integer 
- `DECIMAL(p,s)` - Exact fixed-point number
- `NUMERIC(p,s)`- Same as DECIMAL
- `FLOAT(p)` - Approximate floating-point number
- `REAL` - Approximate floating-point (lower prec)

##### 2. String/Text Data Types
- `CHAR(n)` - Fixed-length string
- `VARCHAR(n)` - Variable-length string
- `VARCHAR(n)` - Variable-length string
- `TEXT` - Large variable-length text

##### 3. Date & Time Data Types
- `DATE`- Date (YYYY-MM-DD)
- `TIME` -  Time (HH:MM:SS)
- `DATETIME` - Date and time
- `TIMESTAMP` - Auto-generated datetime
- `YEAR` - Year (2 or 4 digits)

##### 4. Boolean Type
- `BOOLEAN` - True or False (0/1)

##### 5. Binary Data Types
- `BINARY(n)` - Fixed-length binary data
- `VARBINARY(n)` - Variable-length binary data
- `BLOB` - Binary Large Object (images, files)


---
### JOIN in SQL

- SQL supports different types of joins: `INNER JOIN`, `LEFT JOIN`, `RIGHT JOIN`, `FULL JOIN`, `CROSS JOIN`.
- `JOIN` = `Cross`(Cartesian) Product + `Condition`

```
-- Table1
| ID | Name  |
|----|-------|
| 1  | Alice |
| 2  | Bob   |

-- Table2
| Code | Color  |
|------|--------|
| A    | Red    |
| B    | Blue   |

-- Cartesian Product (Cross Join) Result
| ID | Name  | Code | Color |
|----|-------|------|-------|
| 1  | Alice | A    | Red   |
| 1  | Alice | B    | Blue  |
| 2  | Bob   | A    | Red   |
| 2  | Bob   | B    | Blue  |
```

##### 1. INNER JOIN =  Intersection
- `INNER JOIN` or just `JOIN`
- **Definition**: Returns only the rows where there is a match in both tables.
- **Use Case**: When you only need data that exists in both tables.
```sql
SELECT p.firstName, p.lastName, a.city
FROM Person p
INNER JOIN Address a ON p.PersonId = a.PersonId;
```
##### 2. LEFT JOIN  =  Inner Join + Left 
- `LEFT OUTER JOIN` or just `LEFT JOIN` 
- **Definition**: Returns all rows from the left table and the matched rows from the right table. If there is no match, `NULL` is returned for columns from the right table.
- **Use Case**: When you need all data from the left table regardless of matches in the right table.
```sql
SELECT p.firstName, p.lastName, a.city
FROM Person p
LEFT JOIN Address a ON p.PersonId = a.PersonId;
```  
##### 3. RIGHT JOIN  = Inner Join + Right
- `RIGHT OUTER JOIN` or just `RIGHT JOIN` 
- **Definition**: Returns all rows from the right table and the matched rows from the left table. If there is no match, `NULL` is returned for columns from the left table.
- **Use Case**: When you need all data from the right table regardless of matches in the left table.
```sql
SELECT p.firstName, p.lastName, a.city
FROM Person p
RIGHT JOIN Address a ON p.PersonId = a.PersonId;
```

##### 4. OUTER JOIN = Inner Join + Left + Right = Union
- `FULL OUTER JOIN` or just `FULL JOIN` or `OUTER JOIN`
- **Definition**: Returns all rows from both tables. When there is no match, `NULL` is returned for columns from the table without a match.
- **Use Case**: When you need all records from both tables, whether or not they have matches.
```sql
SELECT p.firstName, p.lastName, a.city
FROM Person p
FULL OUTER JOIN Address a ON p.PersonId = a.PersonId;
```
##### 5. CROSS JOIN
- **Definition**: Returns the Cartesian product of the two tables, meaning every row from the first table is joined with every row from the second table.
- **Use Case**: Rarely used, but useful for generating combinations of rows from two tables.
```sql
SELECT p.firstName, a.city
FROM Person p
CROSS JOIN Address a;
```
- Natural Join without Using `CROSS JOIN` Keyword
```mysql
SELECT P.firstName, a.city
FROM Person p, Address a;
```
    
##### 6. SELF JOIN
- **Definition**: Joins a table to itself, which can be useful for comparing rows within the same table.
- **Use Case**: When you need to find relationships within a single table.
    ```sql
SELECT e1.EmployeeName, e2.EmployeeName
FROM Employee e1
JOIN Employee e2 ON e1.ManagerId = e2.EmployeeId;
    ```

##### 7. NATURAL JOIN
- **Definition**: Automatically joins tables based on columns with the same names and removes duplicate columns from the result.
- It eliminates the need to write `ON tableA.column = tableB.column`. i.e. it matches columns with the same name
- **Note**: Avoid if column names mismatch or ambiguity is possible.
```mysql
SELECT *  
FROM Employee  
NATURAL JOIN Department;
```
- Natural Join without Using `NATURAL JOIN` Keyword
```mysql
# Using Only
SELECT e.EmployeeName, d.DepartmentName  
FROM Employee e  
JOIN Department d ON e.DepartmentId = d.DepartmentId;

# Using `WHERE` Clause
SELECT *  
FROM Employee e, Department d  
WHERE e.DepartmentId = d.DepartmentId;
```

**Types of Natural Join**
- **Natural + Inner Join** :`NATURAL JOIN`. 
- **Natural + Left Jon** : `NATURAL LEFT JOIN`. 
- **Natural + Right Jon** : NATURAL RIGHT JOIN`. 
- **Natural + Full Outer Join** : `NATURAL FULL JOIN` or  `NATURAL FULL OUTER JOIN`. 

**Note**: 
- `NATURAL JOIN` Not supported by Many browsers such as `SQL Server`, `Oracle`, `SQLite`
- `NATURAL JOIN` can be risky if the table structures change over time. This is why many developers prefer to use explicit join conditions with `INNER JOIN`, `LEFT JOIN`, etc., to have full control over which 

**Order of Keyword**
-  `NATURAL LEFT JOIN`. ✅ 
- `LEFT NATURAL JOIN`. ❌ Syntax Error  


---
#### Alias Name

- **Table Alias**: Short name for table   `Employee AS e1`
- **Column Alias**: Rename output column  `e1.EmployeeName AS Employee`
```sql
SELECT e1.EmployeeName AS Employee, e2.EmployeeName AS Manager
FROM Employee AS e1
JOIN Employee AS e2 ON e1.ManagerId = e2.EmployeeId;
```

---

### Key Notes

##### SQL Rules :
```
- SQL keywords are not case-sensitive.
- Database, table, and column names are *usually not case-sensitive
- An SQL statement must end with a `;` 
- Use single quotes (') for string literals in SQL.
- Double quotes are usually reserved for identifiers (e.g., column names)
- SQL is not white-space sensitive
- Enclose subqueries in parentheses `()` or enclose queries that include more than one columns, condition, statements.
```

##### Parenthesis '()' uses :
```
- Function Call Max()
- Group Columns Together SELECT (Column1, Column2) FROM TableName;
- Definin Datype Size VARCHAR(100)
- Grouping WHERE Clauses ( Salary > 5000 AND Dept = 'IT') OR (Expression>5);
- Subqueries SELECT * FROM Employee WHERE DepartmentID IN (SELECT ID FROM Departmnets WHERE = 'HR');

# Parenthesis Error
Parentheses are not required around the column definition when adding a single column. ALTER TABLE Employees ADD|Modify Email VARCHAR(100);
```

##### Operators in SQL :
```
NULL Handeling : IS NULL, IS NOT NULL
Relational Operator : <, >, =, <, >, <=, >=, <>(not equal)
Logical Operator : OR(||), NOT(!), AND(&&)
Arithmetic Operators : +, -, *, /
Wildcards(used with like): `%` for sequence of character, `-` for a single character 
```

##### Constraints :
``` 
NOT NULL, UNIQUE, PRIMARY KEY, DEFAULT 'Value', CHECK (<Conditions>), REFERENCE  
```

##### SELECT Format :
```
NOTE: ALL can be used wherever DISTINCT is applicable (default is ALL).
SELECT (ALL/ DISTINCT) (*/ColumnName) FROM TableName;
```

**Double use of Same Keyword** `DESC`, `AS`, `ALL`
```mysql
-- Two uses of `DESC`
DESC table_name;           -- Describe table structure (DDL)
SELECT * FROM table_name ORDER BY column_name DESC;  -- Sort in descending order (DML)

-- Two uses of `AS`
SELECT column_name AS alias;  -- Column alias (Rename column in output)
CREATE TABLE new_table AS SELECT ...;   -- Create new table using result of a SELECT

-- Two uses of `ALL`
SELECT ALL column_name FROM table_name;  -- (Default) Include duplicates in SELECT
SELECT * FROM table_name WHERE salary > ALL (...); -- Comparison operator in subqueries

```

--- 

### Query Processing and Execution Order




**SQL Query Writing Order (Syntax Order):**

```sql
SELECT column1, column2, ...
FROM table_name
[JOIN other_table ON condition]
[WHERE condition]
[GROUP BY column]
[HAVING condition]
[ORDER BY column ASC|DESC]
[LIMIT number OFFSET number];
```
- Writing order is how you write the query.

**Order of Execution in SQL Query:**
```text
1. FROM            -- tables & joins
2. ON              -- join condition
3. JOIN            -- apply joins
4. WHERE           -- row filtering
5. GROUP BY        -- grouping rows
6. HAVING          -- group filtering
7. SELECT          -- select columns or expressions
8. DISTINCT        -- remove duplicates
9. ORDER BY        -- sort results
10. LIMIT / OFFSET -- restrict output
```
- - Execution order is how SQL engine processes it internally.

---

### Case Sensitivity 

> This is Just for Understanding Purposes and Not asked in SQL questions


Whether SQL is case-sensitive or not depends on the database system and the specific collation settings used.

**Collation**
- **Collation** in SQL refers to a set of rules that determine how data is sorted and compared in a database.
- It specifies how characters are compared, which affects operations like `ORDER BY`, `WHERE`, and `JOIN`. 
- Collation is crucial for managing data in different languages and for case-sensitivity.

**Components of Collation**
1. Character Set: ex `utf8` , `latin1`
2. Collation Name: `utf8_general_ci` or `utf8_bin`
3. Case Sensitivity:  `CS` for case-insensitivity, `CI` for case-insensitive (e.g. `a` & `A`)
4. Accent Sensitivity: `AS` for accent-sensitivity , `AI` for accent-insensitivity (e.g. `é` vs. `e`)

**Examples Collation**
- `utf8_general_ci` : `CI` & `AI`
- `utf8_bin` : `CS` & `AS`
- `SQL_Latin1_General_CP1_CI_AS` (SQL Server) : `CI` & `AS`


##### Case Sensitivity in SQL Database

1. **MySQL** : 
- Case sensitivity depends on the collation of the columns or the database
- By default, string comparisons in MySQL are **case-insensitive** (e.g., `utf8_general_ci` collation).
- However, column collation can be set to **case-sensitive** (e.g., `utf8_bin` collation).

2. **SQL Server** : 
- Case sensitivity is determined by the collation settings of the columns or database.
- `CI` in collation (e.g., `SQL_Latin1_General_CP1_CI_AS`) stands for **Case Insensitive**.
- `CS` in collation (e.g., `SQL_Latin1_General_CP1_CS_AS`) stands for **Case Sensitive**.

3. **Oracle**: 
- Comparisons are case-sensitive by default. To make them case-insensitive, you can use functions like `UPPER()` or `LOWER()`.

4. **PostgreSQL**: 
- By default, it is **case-sensitive** when comparing strings.


**Summary :**
MySQL - String comparison `CI` & Column Collation `CS`
SQL Server - Depends on Setting
Oracle - Comparisons are `CS`
PostgreSQL - String Comparison `CS`


