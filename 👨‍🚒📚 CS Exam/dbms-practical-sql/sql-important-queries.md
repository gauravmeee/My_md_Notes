---
description: Made by Me 💚
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# SQL Important Queries

#### Print the top 5 rows

1. **For MySQL & PostgreSQL:** ⭐

```sql
SELECT * FROM table_name
LIMIT 5;
```

2. **For SQL Server:** ⭐

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

* **`ROWNUM`** is a **pseudocolumn** in **Oracle SQL** used to assign a unique number to each row returned by a query, starting from **1**.

#### Print Largest and Second Largest Value

**Largest**

```mysql
SELECT MAX(column_name) AS largest_value 
FROM table_name;
```

**Second Largest** ⭐

```mysql
-- Using Subqueries
SELECT MAX(salary) AS second_largest_salary 
FROM employees 
WHERE salary < (
	SELECT MAX(salary) 
	FROM employees
	);
```

or

```mysql
-- Using Offset
SELECT column_name
FROM table_name
ORDER BY column_name DESC
LIMIT 1 OFFSET 1;
```

**Advance: Print Nth Largest Value**

**1. Using Subqueries** ⭐

```mysql
-- Get the N-th largest value using nested MAX queries
SELECT MAX(column_name) AS nth_largest
FROM table_name
WHERE column_name < (
    -- Get the (N-1)th largest by excluding higher values
    SELECT MAX(column_name)
    FROM table_name
    WHERE column_name < (
        -- Repeat nesting (N-2) times for N-th largest
        SELECT MAX(column_name)
        FROM table_name
        -- Repeat this pattern N-1 times
    )
);
```

**2. Using `OFFSET`**

```mysql
-- Select the N-th highest value from a column in MySQL
SELECT column_name
FROM table_name
-- Sort values in descending order (highest first)
ORDER BY column_name DESC
-- Skip first (N-1) rows and fetch 1 row (i.e., the N-th highest)
LIMIT 1 OFFSET N-1;
```

**3. Using `TOP`** ⭐

```mysql
-- Select the N-th highest value from a column in SQL Server
SELECT TOP 1 column_name
FROM (
    -- Step 1: Select top N values in descending order (highest first)
    SELECT TOP N column_name
    FROM table_name
    ORDER BY column_name DESC
) AS temp
-- Step 2: From the top N, pick the smallest (i.e., N-th highest overall)
ORDER BY column_name ASC;
```

***

#### Print All (`*`) columns for the row with the maximum value in a specific column ⭐

```mysql
-- Select all columns from the row(s) with the maximum value in column_name
SELECT * 
FROM table_name
WHERE column_name = (
    -- Get the maximum value from the column
    SELECT MAX(column_name) 
    FROM table_name
);
```

✅ Done Revision on 17th June 2025

***

#### Customers with >5 Orders

```sql
SELECT customer_id FROM orders GROUP BY customer_id HAVING COUNT(*) > 5;
```

#### Avg Salary per Dept

```sql
SELECT department, AVG(salary) AS avg_salary FROM employees GROUP BY department;
```

#### Reverse String Without REVERSE()

```sql
SELECT STRING_AGG(SUBSTRING(str, n, 1), '')
FROM (
  SELECT s.str, g.n
  FROM mytable s
  JOIN generate_series(LENGTH(s.str), 1, -1) AS g(n)
) t
GROUP BY str;
```

#### Names Start with 'A' and End with 'n'

```sql
SELECT name FROM employees WHERE name LIKE 'A%n';
```

#### Orders in Last 7 Days

```sql
SELECT * FROM orders WHERE order_date >= CURRENT_DATE - INTERVAL '7 day';
```

***
