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
   - A column (or a set of columns) in one table that ==references the primary key in another table.== This enforces referential integrity.
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