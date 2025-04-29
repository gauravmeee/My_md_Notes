
### Print the top 5 rows

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

### Print  Largest and Second Largest Value

**Largest**
```Mysql
SELECT MAX(column_name) AS largest_value 
FROM table_name;
```

**Second Largest** ⭐
```Mysql
SELECT MAX(salary) AS second_largest_salary 
FROM employees 
WHERE salary < (
	SELECT MAX(salary) 
	FROM employees);
```

---
### Print Nth Largest Value

##### 1. Using Subqueries
```MySQL
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

##### 2. Using  `OFFSET`
```Mysql
-- Select the N-th highest value from a column in MySQL
SELECT column_name
FROM table_name
-- Sort values in descending order (highest first)
ORDER BY column_name DESC
-- Skip first (N-1) rows and fetch 1 row (i.e., the N-th highest)
LIMIT 1 OFFSET N-1;
```

##### 3. Using `LIMIT`
```Mysql
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


---

### Print all `*` columns for the row with the maximum value in a specific column ⭐

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
