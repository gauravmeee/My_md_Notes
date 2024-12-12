
---
#### Types of Joins

**Inner Join** = Intersection
- `INNER JOIN`
- or just `JOIN`

**Left Outer Join** = Inner Join + Left 
- `LEFT OUTER JOIN`
- or just `LEFT JOIN` 

**Right Outer Join** = Inner Join + Right
- `RIGHT OUTER JOIN`
- or just `RIGHT JOIN` 

**Outer Join** = Inner Join + Left + Right = Union
- `FULL OUTER JOIN`
- or just `FULL JOIN`
- or just `OUTER JOIN`

---
#### Natural Join

- A `NATURAL JOIN` automatically joins tables based on *columns with the same name* and compatible data types in both tables.
- It eliminates the need to write `ON tableA.column = tableB.column`. i.e. it matches columns with the same name

**Natural + Inner Join** :`NATURAL JOIN`. 
**Natural + Left Jon** : `NATURAL LEFT JOIN`. 
**Natural + Right Jon** : NATURAL RIGHT JOIN`. 
**Natural + Full Outer Join** : `NATURAL FULL JOIN` or  `NATURAL FULL OUTER JOIN`. 

**Note**: 
- `NATURAL JOIN` Not supported by Many browsers such as `SQL Server`, `Oracle`, `SQLite`
- `NATURAL JOIN` can be risky if the table structures change over time. If new columns are added with the same name as existing columns, those columns will automatically be included in the join condition, which may lead to unexpected results. This is why many developers prefer to use explicit join conditions with `INNER JOIN`, `LEFT JOIN`, etc., to have full control over which columns are used for joining.

---
#### Comments in SQL

- Single-line comments  -> `--` and  `#` (only for MySQL))
- Multi-line comments -> `/* ... */`)

---
#### Order of Keyword

In SQL the order of keywords matters
-  `NATURAL LEFT JOIN`. ✅ 
- `LEFT NATURAL JOIN`. ❌ Syntax Error

---
#### Largest Value

##### 1. Using Subqueries

**Largest**
```Mysql
SELECT MAX(column_name) AS largest_value 
FROM table_name;
```

**Second Largest**
```Mysql
SELECT MAX(salary) AS second_largest_salary 
FROM employees 
WHERE salary < (
	SELECT MAX(salary) 
	FROM employees);
```


**Nth Largest**
```MySQL
SELECT MAX(column_name) AS nth_largest
FROM table_name
WHERE column_name < (
    SELECT MAX(column_name)
    FROM table_name
    WHERE column_name < (
        SELECT MAX(column_name)
        FROM table_name
        -- Repeat this pattern N-1 times
    )
);
```

##### Using `LIMIT` and `OFFSET`

1.  Sort the values in descending order (`ORDER BY column_name DESC`).
2. Skip the first `(N-1)` values (`OFFSET N-1`) and fetch one row (`LIMIT 1`).

```Mysql
SELECT column_name
FROM table_name
ORDER BY column_name DESC
LIMIT 1 OFFSET N-1;
```

---
#### Print the top 5 rows in SQL

1. **For MySQL & PostgreSQL:**
```sql
SELECT * FROM table_name
LIMIT 5;
```

2. **For SQL Server:**
```sql
SELECT TOP 5 * 
FROM table_name;
```

4. **For Oracle:**
```sql
SELECT * 
FROM table_name
WHERE ROWNUM <= 5;
```
