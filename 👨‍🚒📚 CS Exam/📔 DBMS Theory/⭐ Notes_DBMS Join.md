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

