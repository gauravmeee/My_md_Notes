

## Q. report the first name, last name, city, and state of each person in the `Person` table. If the address of a `personId` is not present in the `Address` table, report `null` instead.


**Input**
```
Person
+----------+----------+-----------+
| personId | lastName | firstName |
+----------+----------+-----------+
Address
+-----------+----------+---------------+------------+
| addressId | personId | city          | state      |
+-----------+----------+---------------+------------+
```

**Output**
```
+-----------+----------+---------------+----------+
| firstName | lastName | city          | state    |
+-----------+----------+---------------+----------+
```

#### Solution.

```mysql
Select p.firstName, p.lastName, a.city, a.state
    FROM Person p
    LEFT JOIN Address a ON p.personId=a.personId;
-- ✅
```
OR

```Mysql
Select p.firstName, p.lastName, a.city, a.state
	FROM Person p
	NATURAL LEFT JOIN Address a;
-- ✅
```

if `FULL OUTER JOIN` ❌ Extra Right Table  `Address` data, for which  `Person` not exist in  Left Table
if `RIGHT JOIN` ❌ Missed Left table `Person` data, for which `Address` not exist in Right Table
IF `LEFT JOIN` ✅

## Write a solution to find the second highest **distinct** salary from the `Employee` table. If there is no second highest salary, return `null (return None in Pandas)`.

The result format is in the following example.

**Example 1:**

**Input:** 
```
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
```

**Output:** 
```
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
```

**Solution:**

Order by (sort) salaries in descending order,  and skips the first  (`OFFSET 1`), then Fetch the Top value (`LIMIT 1`) i.e. 2nd Largest
```Mysql
Select salary as SecondHighestSalary  from Employee
Order by Salary DESC
LIMIT 1 OFFSET 1 # Offset N-1 = 2nd -1 = 1

-- ❌ If Second Highest Salary Not Exist, It doesnot Return `NULL`
-- ⬇️ 
 ```

If `N` exceeds the number of rows, the subquery returns `NULL`.
``` MySQL
Select (Select salary  from Employee
Order by Salary DESC
LIMIT 1 OFFSET 1) as SecondHighestSalary

-- ❌ It Doesn't considering Distinct value. for exam it return 100 for It salary = (100, 100, 50 , 10) not 50 
-- ⬇️
```

use the `DISTINCT` keyword 
```Mysql
Select (Select Distinct salary  from Employee
Order by Salary DESC
LIMIT 1 OFFSET 1) as SecondHighestSalary
-- ✅
```



