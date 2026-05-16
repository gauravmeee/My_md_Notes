---
title: SQL View
---

A **View** in SQL is essentially a **virtual table**. It does not store data physically; instead, it stores a pre-defined `SELECT` query that pulls data from one or more "base tables" every time the view is accessed.


## 1. Core Concept & Syntax

Think of a view as a "saved filter." When you query a view, the database engine executes the underlying query behind the scenes.

- **Creating a View:**
    
    SQL
    
    ```
    CREATE VIEW view_name AS
    SELECT column1, column2
    FROM table_name
    WHERE condition;
    ```
    
- **Querying a View:**
    
    SQL
    
    ```
    SELECT * FROM view_name;
    ```
    

## 2. Key Advantages of Views

Views are used for more than just convenience; they are critical for database architecture:

- **Security (Data Hiding):** You can restrict a user's access to a view that only shows specific columns (e.g., hiding a `Salary` column) while they remain blocked from the main table.
    
- **Simplification:** They hide complex joins and calculations. A 20-line `JOIN` query can be reduced to a simple `SELECT * FROM view_name`.
    
- **Consistency:** If the logic for calculating "Active Customers" changes, you only update the View definition in one place, rather than updating every application script.
    
- **Logical Data Independence:** You can change the structure of the underlying tables (like splitting one table into two) without breaking the applications that rely on the view.
    

## 3. Types of Views

| **Type**               | **Description**                                                                                                                  |
| ---------------------- | -------------------------------------------------------------------------------------------------------------------------------- |
| **Simple View**        | Created from a single table. No functions or grouping. You can often perform `INSERT/UPDATE` on these.                           |
| **Complex View**       | Created from multiple tables (Joins), contains aggregate functions (`SUM`, `AVG`), or `GROUP BY` clauses.                        |
| **Materialized View**  | Unlike standard views, these **physically store** the result of the query. Used in Data Warehousing to speed up massive queries. |


## 4. Operational Commands

How to manage views once they are created:

- **Update Definition:** Use `ALTER VIEW` (or `CREATE OR REPLACE VIEW` in some systems) to change the query logic without deleting the view object.
    
- **Rename:** Use `EXEC sp_rename` (SQL Server) or `RENAME TO` (PostgreSQL/Oracle).
- **Delete:** `DROP VIEW view_name;`
    
- **Refresh Metadata:** In SQL Server, if the underlying table changes, use `EXEC sp_refreshview 'view_name'`.
    

## 5. Limitations (Updatable Views)

You can sometimes `UPDATE` or `DELETE` rows through a view, but it must meet strict criteria:
1. The view must be based on a **single table**.
2. It cannot contain **Group By**, **Distinct**, or **Aggregate Functions**.
3. It cannot contain **Set operators** (like `UNION`).
    

---

### Comparison: View vs. Table

| **Feature**     | **View**                        | **Table**                           |
| --------------- | ------------------------------- | ----------------------------------- |
| **Storage**     | Only the query logic is stored. | Actual data rows are stored.        |
| **Space**       | Minimal (metadata only).        | Significant (depends on data size). |
| **Performance** | Slower (runs query every time). | Faster (direct data access).        |
| **Dependency**  | Depends on base tables.         | Independent.                        |
