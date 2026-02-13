# ⭐ Notes\_DBMS Keys

Attribute - field - column Tuple - Data - Row

## Keys

In Database Management Systems (DBMS), **keys** are crucial for identifying unique rows in tables and establishing relationships between different tables. Here are the different types of keys and their significance, along with some **common interview questions** about keys in DBMS:

#### Types of Keys in DBMS:

1. **Primary Key**:
   * A column (or combination of columns) that uniquely identifies each row in a table.
   * It cannot have NULL values.
   * Example: In a table of students, `student_id` can be the primary key.
2. **Candidate Key**:
   * A set of columns that can uniquely identify any row in a table. A table can have multiple candidate keys, but only one is selected as the primary key.
   * Example: Both `student_id` and `email` might be candidate keys for a student table.
3. **Super Key**:
   * Any set of attributes that can uniquely identify a row in a table.
   * Example: `{student_id}` or `{student_id, email}` are super keys, as both can uniquely identify a record.
4. **Foreign Key**:
   * A column (or a set of columns) in one table that ==references the primary key in another table.== This enforces referential integrity.
   * Example: In a `course_enrollments` table, `student_id` might be a foreign key referencing the `students` table.
5. **Composite Key**:
   * A key made up of two or more columns that, together, uniquely identify a row.
   * Example: In an `order_details` table, a combination of `order_id` and `product_id` could be a composite key.
6. **Alternate Key**:
   * A candidate key that is not selected as the primary key.
   * Example: If `email` is a candidate key but `student_id` is chosen as the primary key, then `email` becomes an alternate key.
7. **Unique Key**:
   * A column (or a set of columns) that ensures all values are unique across rows. Unlike a primary key, it allows NULL values.
   * Example: A `username` column in a `users` table might be a unique key.
8. **Surrogate Key**:
   * An artificial key introduced when no natural key exists, typically an auto-incrementing number.
   * Example: `id` column generated automatically in databases.

***

#### **Common Interview Questions on Keys in DBMS**:

1. **What is a Primary Key, and how is it different from a Unique Key?**
   * **Answer**: A primary key uniquely identifies a row and cannot be NULL, while a unique key also ensures uniqueness but can have NULL values.
2. **Can a table have more than one Primary Key?**
   * **Answer**: No, a table can only have one primary key. However, it can have multiple candidate keys.
3. **What is the difference between a Primary Key and a Foreign Key?**
   * **Answer**: A primary key uniquely identifies records in its table, while a foreign key is used to refer to the primary key of another table, maintaining referential integrity between tables.
4. **What are Candidate Keys, and how are they different from Super Keys?**
   * **Answer**: A candidate key is the minimal set of attributes that can uniquely identify a row. A super key is any combination of attributes that can uniquely identify a row. Every candidate key is a super key, but not every super key is a candidate key.
5. **What is a Composite Key, and when would you use it?**
   * **Answer**: A composite key consists of two or more columns that together uniquely identify a record. It's used when no single column can uniquely identify a record.
6. **What are Alternate Keys?**
   * **Answer**: Alternate keys are candidate keys that are not chosen as the primary key.
7. **Can a Foreign Key accept NULL values?**
   * **Answer**: Yes, a foreign key can accept NULL values unless constraints are applied to disallow them.
8. **What is a Surrogate Key, and why is it used?**
   * **Answer**: A surrogate key is an artificial key (e.g., an auto-incremented number) used when there is no natural key, or when using a natural key would be inefficient or problematic.
9. **What is the difference between a Composite Key and a Candidate Key?**
   * **Answer**: A composite key is a key made up of more than one column, whereas a candidate key is any key (composite or not) that can uniquely identify a row.
10. **What are the advantages of using a Foreign Key in a database?**
    * **Answer**: Foreign keys enforce referential integrity, ensuring that relationships between tables remain consistent. It prevents invalid data from being entered and maintains the linkage between related tables.

***

#### Referential Integrity Constraints (Notes)

* **Referential Integrity (RI)** ensures that a **foreign key (FK)** in one relation **must match an existing primary key (PK)** value in another relation.
* It maintains **consistency among related tables**.

**Key Rule**

* If relation **R2** has a **Foreign Key (FK)** referring to the **Primary Key (PK)** of relation **R1**:
* Every FK value in **R2** must either be:
  * **NULL**, or
  * **Exist as a PK** value in **R1**.

**Possible Operations and Violations** ⭐

| **Operation**           | **Effect on Referential Integrity** | **Reason**                                                                               |
| ----------------------- | ----------------------------------- | ---------------------------------------------------------------------------------------- |
| **I. INSERT into R1**   | ✅ **No violation**                  | Adding new PK values in parent table (R1) does not break RI.                             |
| **II. INSERT into R2**  | ❌ **May violate**                   | If the FK value inserted in R2 does **not exist in R1**, RI is violated.                 |
| **III. DELETE from R1** | ❌ **May violate**                   | If a PK value is deleted from R1 while it is still **referenced in R2**, RI is violated. |
| **IV. DELETE from R2**  | ✅ **No violation**                  | Removing child rows (R2) doesn’t affect references.                                      |

**May cause violation:**

* **II. INSERT into R2**
* **III. DELETE from R1**

**Handling Violations (Actions)**

* To maintain referential integrity, DBMS can take predefined actions on **DELETE/UPDATE** in parent table (**R1**):
  * **CASCADE:** Automatically delete or update matching rows in child (R2).
  * **SET NULL:** Set FK values in child to NULL.
  * **SET DEFAULT:** Set FK to a default valid value.
  * **NO ACTION / RESTRICT:** Reject the operation.

**Summary**

* Referential integrity ensures **consistency between related tables**.
* **Violations occur** when:
  * Inserting invalid FK in child (R2).
  * Deleting referenced PK in parent (R1).

***

**Prime Attribute (Key Attribute) vs Primary Key**

* **Prime Attribute**
  * Attribute that is part of **any candidate key**.
  * May appear in **multiple candidate keys**.
  * Used mainly in **normalization (2NF, 3NF)**.
  * Example:
    * Candidate keys: `{A, B}`, `{A, C}`
    * **Prime attributes:** `A, B, C`
* **Primary Key**
  * **One selected candidate key** used to uniquely identify records.
  * Must be **unique** and **NOT NULL**.
  * Exactly **one primary key** per table.
  * Can be **composite**.

***

#### Clear Comparison (Exam-Ready)

| Feature               | Prime Attribute | Key Attribute | Primary Key          |
| --------------------- | --------------- | ------------- | -------------------- |
| Part of candidate key | Yes             | Yes           | Yes                  |
| All candidate keys    | Yes             | Usually yes   | No (only chosen one) |
| Uniqueness guarantee  | Indirect        | Indirect      | Direct               |
| NULL allowed          | Depends         | Depends       | Not allowed          |
| Used in normalization | Yes ⭐           | No            | No                   |

***

#### One-Line Rule (No Confusion)

```
Candidate Key → attributes are Prime
Chosen Candidate Key → Primary Key
```

**Best Opinion:**\
In exams, treat **prime attribute = attribute of any candidate key**.\
Ignore the term **key attribute** unless explicitly defined—it often causes confusion.
