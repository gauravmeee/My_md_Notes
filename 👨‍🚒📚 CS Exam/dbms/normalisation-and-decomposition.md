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

# Normalisation and Decomposition

**Normalization (Normal Forms Comparison)**

* **Unnormalized Form**: Repeating groups, high redundancy, all anomalies present
* **1NF**: Atomic attributes only, redundancy still exists
* **2NF**: No partial dependency, reduced redundancy
* **3NF**: No transitive dependency, dependency preserving, acceptable anomalies only
* **BCNF**: Stronger than 3NF, removes all FD-based anomalies
* **4NF**: Removes multivalued dependencies
* **5NF**: Removes join dependencies, fully decomposed schema Corrected table (DBMS-accurate):

| Normal Form  | Lossless / Lossy | Dependency Preserving | Anomalies Present                                      |
| ------------ | ---------------- | --------------------- | ------------------------------------------------------ |
| Unnormalized | <mark>Lossy</mark>        | No                    | Insertion, Deletion, Update                            |
| 1NF          | <mark>Lossy</mark>        | No                    | Insertion, Deletion, Update                            |
| 2NF          | <mark>Lossy</mark>        | No                    | Insertion, Deletion, Update (<mark>reduced</mark>)              |
| 3NF          | Lossless         | <mark>Yes</mark>               | <mark>No Major anomalies</mark>                                 |
| BCNF         | Lossless         | No (not guaranteed)   | **No Anomalies** (No functional dependency anomalies)  |
| 4NF          | Lossless         | No                    | **No Anomalies** (No multivalued dependency anomalies) |
| 5NF          | Lossless         | No                    | **No Anomalies** (No join dependency anomalies)        |

> 3NF **can still have anomalies**, but they are **theoretically acceptable**; only BCNF and above remove FD-based anomalies completely.

**important points**:

* <mark>**Lossless decomposition**</mark> is <mark>**guaranteed from 3NF onward**</mark> , not strictly by 1NF/2NF
* <mark>**Dependency preservation**</mark> is **guaranteed <mark>only in 3NF**</mark> , not in BCNF, 4NF, 5NF
* **3NF is always achievable** without losing dependencies
* **BCNF may require sacrificing dependency preservation**
* **4NF deals with multivalued dependencies (MVDs)**
* **5NF deals with join dependencies (JD)**
* Higher normal forms **reduce redundancy but increase number of relations**
* Practical databases usually stop at **3NF or BCNF**

### Normalisation

* Systematic process of organizing relations to **reduce redundancy**, **avoid anomalies**, and **ensure data integrity**
* Uses **Functional Dependencies (FDs)** as the theoretical base
* Performed step-by-step through **Normal Forms (NF)**

**Why Normalisation**

* Removes duplicated data
* Prevents anomalies
* Makes database logically sound for updates

**Data Anomalies**

* **Insertion Anomaly**: Cannot insert data without other data\
  Example: Cannot add a new course unless a student enrolls
* **Deletion Anomaly**: Deleting data causes loss of useful info\
  Example: Deleting last student removes course info
* **Update Anomaly**: Same data updated in multiple places\
  Example: Teacher name repeated in many rows

**1. 1NF (First Normal Form)**

**Rule**

* Attributes must have <mark>**atomic (indivisible)</mark> values**
* No repeating groups or multi-valued attributes

**Violation Example**

```
STUDENT(SID, Name, Phone)
1, Rahul, {9876, 9123}
```

**Fix**

```
STUDENT(SID, Name, Phone)
1, Rahul, 9876
1, Rahul, 9123
```

**Key Idea**

* One cell → one value

**2. 2NF (Second Normal Form)**

**Rule**

* Must be in 1NF
* <mark>No **partial dependency**</mark> 
* **Non-prime attribute** must depend on **whole candidate key**

**Partial Dependency**

* Attribute depends on part of a composite key

> **Candidate key** → A <mark>**minimal set of attributes**</mark> that <mark>uniquely identifies</mark> a tuple\
> **Composite key** → A **candidate key consisting of more than one attribute**

> **Key Attribute** (prime attribute) → If an attribute <mark>appears in any candidate key</mark> **Non-key attribute** (non-prime attribute) → If it <mark>does not appear in any candidate key</mark> 

**Violation Example**

```
ENROLL(SID, CID, SName, CName)
Key = (SID, CID)
FDs:
	SID → SName
	CID → CName
```

**Problem**

* `SName` depends only on `SID`
* `CName` depends only on `CID`

**Decomposition**

```
STUDENT(SID, SName)
COURSE(CID, CName)
ENROLL(SID, CID)
```

**Key Idea**

* Applies only when **composite key exists**

**3. 3NF (Third Normal Form)**

**Rule**

* Must be in 2NF
* <mark>No **transitive dependency**</mark> 
* For every FD `X → A`:
  * `X` is a super key OR
  * `A` is a prime attribute

**Transitive Dependency**

* Key → Non-key → Non-key

> **Candidate key** → A <mark>**minimal set of attributes**</mark> that <mark>uniquely identifies</mark> a tuple\
> **Super key** → A **set of attributes** that uniquely identifies a tuple, **may contain extra (non-minimal) attributes**

> **Key Attribute** (prime attribute) → If an attribute <mark>appears in any candidate key</mark> **Non-key attribute** (non-prime attribute) → If it <mark>does not appear in any candidate key</mark> 

**Violation Example**

```
EMP(EID, EName, DeptID, DeptName)
Key = EID
FDs:
	EID → DeptID
	DeptID → DeptName
```

**Problem**

* `DeptName` indirectly depends on `EID`

**Decomposition**

```
EMP(EID, EName, DeptID)
DEPT(DeptID, DeptName)
```

**Key Idea**

* Remove dependency between non-key attributes

**4. BCNF (Boyce-Codd Normal Form)**

**Rule**

* Stronger than 3NF
* For every FD `X → Y`, `X` must be a **super key** ⭐

> **Candidate key** → A <mark>**minimal set of attributes**</mark> that <mark>uniquely identifies</mark> a tuple\
> **Super key** → A **set of attributes** that uniquely identifies a tuple, **may contain extra (non-minimal) attributes**

**Violation Example (3NF but not BCNF)**

```
TEACH(SID, Course, Instructor)
FDs:
	Instructor → Course
	(SID, Course) → Instructor
```

**Problem**

* `Instructor` is not a super key

**Decomposition**

```
INST(Instructor, Course)
STUD(SID, Instructor)
```

**Key Idea**

* Eliminates all FD-based anomalies
* May lose dependency preservation

**5. 4NF (Fourth Normal Form)**

**Rule**

* Must be in BCNF
* No **non-trivial multivalued dependency**
* If `X →→ Y`, then `X` must be a super key

> **Trivial functional dependency** → X → Y where **Y ⊆ X**\
> **Non-trivial functional dependency** → X → Y where **Y ⊄ X**

**Violation Example**

```
STUDENT(SID, Skill, Hobby)
SID →→ Skill
SID →→ Hobby
```

**Problem**

* Independent multi-valued facts

**Decomposition**

```
STUDENT_SKILL(SID, Skill)
STUDENT_HOBBY(SID, Hobby)
```

**Key Idea**

* One fact per relation

**6. 5NF (Fifth Normal Form)**

**Rule**

* No **join dependency** except trivial
* Relation cannot be further decomposed losslessly

**Example Idea**

* Supplier–Part–Project relations where data is reconstructible only via joins

**Key Idea**

* Rare in practice
* Used in highly complex databases

**Anomalies Present Summary ⭐**

| Normal Form  | Anomalies Present                     |
| ------------ | ------------------------------------- |
| Unnormalized | Insertion, Deletion, Update           |
| 1NF          | Insertion, Deletion, Update           |
| 2NF          | Insertion, Deletion, Update (reduced) |
| <mark>3NF</mark>      | <mark>No major anomalies</mark>                |
| BCNF         | No anomalies                          |
| 4NF          | No anomalies                          |
| 5NF          | No anomalies                          |

**Best View (Exam-oriented)**

* <mark>Anomalies completely removed from **3NF onwards**</mark> 
* Decomposition into **3NF / BCNF / 4NF is always lossless**
* Lossy decompositions are **invalid in design**

**Important Definitions :**

* **Prime Attribute**: Part of some candidate key
* **Non-Prime Attribute**: Not part of any candidate key
* **Candidate Key**: Minimal super key
* **Super Key**: Attribute set uniquely identifying tuples

**Exam Focus (GATE / PSU)**

* 1NF → Atomicity
* 2NF → Partial dependency
* 3NF → Transitive dependency
* BCNF → LHS must be super key
* 3NF always possible with dependency preservation
* BCNF gives better redundancy removal but may lose dependencies

***

***

### Decomposition

* Process of splitting a relation into **two or more relations**
* Goal: remove redundancy, anomalies, and achieve higher normal form
* Based on **functional dependencies (FDs)** or **multivalued dependencies (MVDs)**

**Why Decomposition is Needed**

* To eliminate **update / insertion / deletion anomalies**
* To satisfy **normal forms (3NF, BCNF, 4NF)**
* To improve **data consistency and integrity**

**Types of Decomposition**

1. <mark>Lossless vs Lossy</mark> 
2. <mark>Dependency Preserving vs Non-preserving</mark> 
3. 3NF Decomposition
4. BCNF Decomposition
5. 4NF Decomposition

**1. Lossless Decomposition**

* No information loss after decomposition
* Natural join of decomposed relations gives **exact original relation**

**Condition**

* Decomposition of `R` into `R1` and `R2` is lossless if\
  `(R1 ∩ R2) → R1` **OR** `(R1 ∩ R2) → R2`

**Example**

* `R(A, B, C)`
* FD: `A → B`
* Decompose into\
  `R1(A, B)`\
  `R2(A, C)`
* Intersection = `A`
* Since `A → B`, lossless

**Exam Point**

* Always test lossless first, dependency preservation later

**2. Lossy Decomposition**

* Information is lost after decomposition
* Natural join does **not** give original relation

**Example**

* `R(A, B, C)`
* Decompose into\
  `R1(A, B)`\
  `R2(B, C)`
* Intersection = `B`
* No FD `B → R1` or `B → R2`
* Lossy

**Exam View**

* Always **invalid** decomposition

**3. Dependency Preserving Decomposition**

* All FDs can be enforced on **individual relations**
* No need to join relations to check constraints

**Condition**

* `F = (F1 ∪ F2 ∪ … ∪ Fn)+`

**Example**

* `R(A, B, C)`
* FD: `A → B`, `B → C`
* Decompose into\
  `R1(A, B)`\
  `R2(B, C)`
* Dependencies preserved

**Importance**

* Preferred in real DB design
* Reduces computation cost

**4. Non-Dependency Preserving Decomposition**

* Some FDs cannot be checked without join

**Example**

* `R(A, B, C)`
* FD: `A → C`
* Decompose into\
  `R1(A, B)`\
  `R2(B, C)`
* `A → C` not preserved

**Trade-off**

* Often occurs in **BCNF decomposition**

**3NF Decomposition**

* Used when BCNF breaks dependency preservation
* Guarantees:
  * Lossless
  * Dependency preserving

**Algorithm (Core Idea)**

* Create relation for each FD
* Ensure candidate key exists in some relation

**Example**

* `R(A, B, C)`
* FD: `A → B`, `B → C`
* Not in 3NF due to transitive dependency
* Decompose into\
  `R1(A, B)`\
  `R2(B, C)`

**Exam Note**

* 3NF is **practical normal form**

**5. BCNF Decomposition**

* Stronger than 3NF
* For every FD `X → Y`, `X` must be a super key

**Properties**

* Always lossless
* May **not** preserve dependencies

**Example**

* `R(A, B, C)`
* FD: `A → B`, `C → B`
* Keys: `{A, C}`
* `C → B` violates BCNF
* Decompose into\
  `R1(C, B)`\
  `R2(A, C)`

**Key Insight**

* Removes maximum redundancy
* Dependency preservation may be sacrificed

**6. 4NF Decomposition**

* Deals with **multivalued dependencies**
* Rule: for `X →→ Y`, `X` must be a super key

**Example**

* `R(Student, Course, Hobby)`
* Student has independent courses and hobbies
* MVDs:\
  `Student →→ Course`\
  `Student →→ Hobby`
* Decompose into\
  `R1(Student, Course)`\
  `R2(Student, Hobby)`

**Result**

* Removes spurious tuples
* Always lossless

**Comparison Summary ⭐**

| Normal Form  | Lossless / Lossy | Dependency Preserving |
| ------------ | ---------------- | --------------------- |
| Unnormalized | Lossy            | No                    |
| 1NF          | Lossy            | No                    |
| 2NF          | Lossy            | No                    |
| <mark>3NF</mark>      | <mark>Lossless</mark>     | <mark>Yes</mark>               |
| BCNF         | Lossless         | No (not guaranteed)   |
| 4NF          | Lossless         | No                    |
| 5NF          | Lossless         | No                    |

* Lossless → <mark>mandatory</mark> 
* Dependency preserving → <mark>desirable</mark> 
* 3NF → <mark>preserves FD</mark> , slight redundancy allowed
* BCNF → <mark>no redundancy</mark> , FD may break
* 4NF → handles MVDs

**GATE / PSU Focus**

* Always check **lossless condition**
* Prefer **3NF over BCNF** if FD preservation asked
* BCNF questions often test **trade-off**
* 4NF questions usually include **independent attributes**
