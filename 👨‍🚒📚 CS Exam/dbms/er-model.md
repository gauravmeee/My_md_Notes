---
description: Made By Me 💚
icon: dot
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

# ER Model

#### ER Model Symbols

```mathematica
Entity                → Rectangle 
Relationship          → Diamond
Attribute             → Oval
Key Attribute         → Underlined Oval

Weak Entity           → Double Rectangle
Identifying Relation  → Double Diamond
Partial Key           → Dashed Underline

Total Participation   → Double Line
Partial Participation → Single Line

Multivalued Attribute → Double Oval
Derived Attribute     → Dashed Oval
Composite Attribute   → Oval with sub-ovals

Cardinality           → 1:1, 1:N, M:N (on relationship lines)
```

More:

```
ISA (is-a)            → Triangle
Specialization        → Top-down ISA
Generalization        → Bottom-up ISA
Disjoint              → ‘d’ near ISA
Overlapping           → ‘o’ near ISA
```

**Exam Tip:** If you see **double boundary / double line**, think **dependency or total participation**.

#### Strong Entity vs Weak Entity

**Strong Entity Set**

* **Definition:** Can be **uniquely identified by its own attributes**.
* **Key:** Has a **primary key**.
* **Existence:** **Independent** of other entities.
* **ER Representation:**
  * Strong entity → **Single rectangle**
  * Key attribute → **Underlined**
* **Participation:** Can be **partial or total**.

**Example:**

* **Entity:** `Department`
* **Primary Key:** `Dept_ID`
* `Department` exists independently of other entities.
* Participation in relationships may be partial or total.

***

**Weak Entity Set**

* **Definition:** **Cannot be uniquely identified** by its own attributes; depends on a **strong entity**.
* **Key:** Has a **partial key** (discriminator).
* **Existence:** **Dependent** on strong entity.
* **ER Representation:**
  * Weak entity → **Double rectangle**
  * Identifying relationship → **Double diamond**
  * Partial key → **Dashed underline**
* **Participation:** **Total participation** is mandatory.

**Example:**

* **Entities:** `Department` (strong), `Employee` (weak)
* **Relationship:** `WorksIn` (identifying)
* `Employee` identified by `(Dept_ID + Emp_No)`
* Every `Employee` must be linked to a `Department`.

**Key Difference (Exam Ready)**

| Feature        | Strong Entity     | Weak Entity                    |
| -------------- | ----------------- | ------------------------------ |
| Primary Key    | Present           | Not present                    |
| Partial Key    | Not required      | Required                       |
| Existence      | Independent       | Dependent                      |
| Identification | By own attributes | By strong entity + partial key |
| Participation  | Partial / Total   | Always Total                   |
| ER Symbol      | Single rectangle  | Double rectangle               |

**GATE Tip:**\
If **total participation + no primary key**, it is a **weak entity**.

***

#### Types of Entity (ER Model)

**1. Strong Entity**

* Has its **own primary key**.
* Exists **independently**.

```mathematica
+-----------+
| Student   |
+-----------+
| Roll_No  |
| Name     |
+-----------+
```

**2. Weak Entity**

* **No primary key** of its own.
* Depends on a **strong entity**.
* Has **partial key**.

```mathematica
+-----------+      ⟪⟪ WorksIn ⟫⟫      ||-----------||
| Department|========================|| Employee  ||
+-----------+                         ||-----------||
| Dept_ID   |                         || Emp_No    ||
+-----------+                         ||-----------||
```

**3. Associative (Intersection) Entity**

* Created from **M:N relationship**.
* Has attributes of relationship.

```mathematica
+-----------+      Enrolls      +-----------+
| Student   |------------------| Course    |
+-----------+                  +-----------+

            ↓

+------------------+
| Enrollment       |
+------------------+
| Roll_No, CID     |
| Grade            |
+------------------+
```

**4. Regular Entity**

* Same as **strong entity**.
* Simple, independent entity.

```mathematica
+-----------+
| Book      |
+-----------+
| Book_ID   |
| Title     |
+-----------+
```

**5. Subtype / Supertype Entity**

* **Inheritance (IS-A)** relationship.
* Subtype inherits attributes.

```mathematica
        Employee
           |
        ---------
        |       |
     Teacher   Clerk
```

**6. Recursive Entity**

* Entity related to **itself**.

```mathematica
Employee ── Manages ── Employee
```

**7. Dependent Entity**

* Existence depends on another entity.
* Often same as **weak entity**.
