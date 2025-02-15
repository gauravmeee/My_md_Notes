
# [Database Management System One Shot | CS & IT Engineering | DA | Maha Revision | Target GATE 2025](https://youtu.be/k6rDS0qQiO0)


**Topics**
1. Relational Model and Normal Forms
2. Query Languages
3. Transaction and Concurrency Control
4. Indexing 
5. ER Model

## Relational Model

**Relation** -> Organizing in the form of table (Row and Column) 
```
Sid | Sname | Marks
----|-------|------
S1  | Ram   | 35
S2  | Nikhil| 56
S3  | Vishal|0
S4  | Ram   | 72
```

**Attributes/Fields** -> Column : `Sid`, `Sname`, `Marks`
**Tuple/Record** -> Row : `S1 Ram 35`, `S2 Nikhil 56`

**Degree** -> No. of attributes in Relation(above ex : 3)
**Cardinality** -> No. of Records in Relation(above ex: 4)


**Relation Schema:** `Student(Sid, Sname, Marks`.  Tuple Value :
- `(S1 Ram 35)`
- `(S4 Ram 72)`
-  `(Nikhil S2 56)` ❌ Order is important

**Relational Instance:**
```
{ (S1, Ram, 35), (S2, Nikhil, 56), (S3, Vishal, 0), (S4, Ram, 72), (S5, Mohan, 56) }
```
- Order of tuples doesn't matter in Relation Instance as it is a set.

### Functional Dependency (FD)

Relation `R(A,B,C,D,E,F)`

**Functional Instance** ->Relationship that holds b/w attribute sets  of Relation.

Let X & Y are any two attribute set over R.

**then** -> `X->Y` is called functional dependency.

Note:
- It may or May not hold in a given relation
- `X->Y` does not hold if there exists two tuples `t1, t2 ϵ R` such that `t1.x=t2.x` but `t1.y ≠ t2.y`
- Based on relation instance, we can not conclude which F.D will hold, we can only conclude which F.D will not hold.

**Let Consider the Relation:**
```
ABC

A | B | C
--|---|--
1 | 2 | 3
1 | 3 | 5
2 | 7 | 3
3 | 8 | 5
1 | 3 | 6
```

`X->Y` Means, X can determine Y
- X : Determiner & Y: Dependent
- i.e. if we know value of X in the relation then we can identify value of Y

**Types of FD's:**

**1. Trivial FD:**
- If `Y ⊆ X` then `X->Y` is trivial
- Every trivial F.D always holds true in the relation.
- Ex: `AB->B

**2. Non-Trivial FD:**
- If X and Y are two Non empty sets such that `X∩Y=∅`, then `X->Y` is called a non-trivial`
- May or May not hold true for a relation
- ex `A->B`

**3. Semi-Trivial FD:** (Not Standard)
- If X and Y are two Non empty sets such that `Y⫋X` and `X∩Y=∅`, then `X->Y` is called a semi-trivial
- ex: `AB->BC` (`AB -> C` Non trivial + `AB->B` Trivial)

No. of Non-Trivial FD `X->Y` Possible For above relation?
```
Cardinality of X (`|X|`? either 1 or 2

If One Attribute in LHS, |X|=1
- |Y|=1 -> ³C₁ * ²C₁ = 3*2 = 6
- |Y|=2` -> ³C1 * ²C₂ = 3*1 = 3

If Two Attribute in LHS, |X|=2
- |Y|=2` ³C₂ * ¹C₁ = 3*1 = 3

Example :

If |X|=1
	|Y| = 1 : A->B, A->C, B->A, B->C, C->A, C->B
	|Y| = 2 : A->BC, B->AC, C->AB

If |X| = 2
	|Y|=1 : AB->C, AC->B, BC->A

So Total 6 + 3 + 3 = 12 Non Trivial F.D Exists for Given Relation
```

Give Which F.D not exists for the Relation
```
A | B | C
--|---|--
1 | 2 | 3
1 | 3 | 5
2 | 7 | 3
3 | 8 | 5
1 | 3 | 6
```

```
- All Trivial FD will hold ✅

- Rest Non-Trivial FD are

A->B ❌ ex: A(1) -> B(2 or 3)
A->C ❌
B->A  May or May not Hold
B->C ❌ ex: B(3) -> B(5 or 6)
C->A ❌ ex: C(3) -> A(1 or 2)
C->B ❌ ex: C(5) -> B(3 or 8)

A->BC ❌ ex: A(1) -> BC(23, 35 or 36)
B->AC ❌ ex: B(3) -> AC(15, 16)
C->AB ❌ ex: C(5) -> AB(13, 38)

AB->C ❌ ex: AB(13) -> C (5 or 6)
AC->B May or May not Hold
BC->A May or May not Hold
```

Note: Functional Dependency are property of Attributes in A Relation. You can Conclude that `Sid->Sname`, `Sid->Smarks` but Not `Sname->Sid` or `Sname.Smarks->Sid`. Two different person with same name and Marks can exists

**Properties of FD**
1. **Reflexivity:** If `Y ⫋ X` then `X->Y` is called reflexive FD (always hold in a relation)
2. **Augmentation** : If `X->Y` holds in relation, then `XZ->YZ` will also hold in relation
3. **Transitivity** : If `X->Y` & `Y->Z` holds in Relation, then `X->Z` will also holds
- These three Properties are Called **Armstrong's Axioms**, and we Can prove and derive All other properties from these
4. **Splitting (Decomposition)** : If X->YZ holds in Relation, then X->Y and X->Z holds in Relation.
5. **Composition :** If  X->Y and P->Q holds in the Relation then XP->YQ holds in Relation
6. **Union:** If X->Y & X->Z holds in the Relation then X->YZ will also hold in Relation. (It is a corollary of Composition i.e. if P=X in Composition)
7. **Pseudo Transitivity :** If X->Y and YW->Z, then XW->Z will hold in Relation.


**Important Rule of Relation Model**

Doctor Cord have given 13 Rules (0 to 12) called `Cord twelve rules`
1. Each Tuple of the relation must be distinct, i.e. duplicate tuples are not allowed in the relation
2. For tuple Uniqueness every relation must have a key

**Key:-** A set of attributes that can be used to identify each tuple uniquely or A set of attributes that can determine all attributes of the Relation.

```
ER Model
[] -> Entity
[[]] -> Weak Entity
() -> Attributes
(_) -> Key Attribute PK, CK, AK (underlined)
<> -> Relation
<<>> -> Identifying Relationship
```

```

   [EMP]                                [[Dependent]]
  /     \       << Take cares of>>        /     \ 
(Eid) (Ename)                          (Dname)  (Dage)
      ↓                                       ↓
Strong Entity                            Weak Entity
 
Strong Entity Set  -> It contains sufficient attributes such that key can be defined

Weak Entity SEt -> Id doesnot contain sufficient attributes for a key

Emp:              Dependent:                Dependent:
Emp | Ename       Dname |  Dage             Emp | Dname |  Dage
----|------       ------|------             ----| ------|------
E1  |             Riya  | 05         =>     E1  | Riya  | 05
E2  |             Rony  | 03                E2  | Rony  | 03
E3  |             Riya  | 01                E3  | Riya  | 05
  ↓                  ↓                          ↓
 Key:Eid           Key?? X -> Relation X    Key:{Eid, Name}

Note: Any Employee (Eid) will not give his/her two children Same name, so {Eid, DName} is a key. but {Eid, Dage} can't be key, because an Employee can have two children with same age.

```

**Closure of an attribute Set:****

Closure of an attribute set X i.e. X⁺ is a set of all attributes that can be determined by X

Let R(A B C D) With FD set F={A->BC, B->C, AD->B, C->D}
```
- (A⁺) = (AB⁺) = (AC⁺) = (AD⁺) = (ABC⁺) = (ACD⁺) = (ABCD⁺) = {A, B, C, D,} -> All
- (B⁺) = (BC⁺) = (BD⁺) = {B, C, D}
- (C⁺) = (CD⁺) = {C, D}
- (D⁺) = {D}

A⁺, AB⁺, AC⁺, AD⁺, ABC⁺, ABD⁺, ACD⁺, ABCD⁺ All of them represent the key of the relation
```

**Super Key(SK)** -> Let R be a relation on X be some set of attribute from relation R, if (X)⁺ contains all attributes of relation R then X is a Super key of relation R
- Need not be minimal
- Ex: `A, AB, AC, AD, ABC, ABD, ACD or ABCD`

**Candidate Key(CK)** -> A minimal set of attribute that can determine all attribute of relation is candidate key.
	or
Let R be the relation, and X be some super key of relation R, If No proper subset of X is a super Key, then X is a minimal Super Key i.e. X is candidate key
- Ex: `A`

**Points to remember:**
- Every CK is a SK, but Every SK need not be CK
- A relation must have at least one CK
- A SK with a single attribute is always a CK
- if CK is formed of a single attribute, then simple CK
- if CK is formed of two or more attribute, then Composite CK
- Attribute that belongs to any CK are called **prime Attributes**
- Attributes that does not belongs to any of the CK are called non-prime attributes

Note:
- Minimal Set of attributes -> set of attributes from which no attribute can be removed without destroying its property of being a key



Questions
........

Note: 
- If there exists a non trivial FD X->Y in the FD set of the relation such that `Y` is a prime attribute then relation will have at least two C.K
- We can obtain few more super keys by replacing prime attribute (y) in the corresponding candidate key by `X` i.e. LHS of FD X->Y (Prime Attribute)

**Ques:** 
```
R (A B C D E)
F = { AB->CD
	  C->E
	  BD->A }

Find All CKs of Relation R
```


**Membership Test:**
- Consider F is a given FD set, and X->Y be some FD. If (X)⁺ w.r.t FD set F contains `Y` then we say that X->Y is a member of FD set F

.
.
.

**Primary Key (PK)** -> One of the C.K is chosen as P.K
- P.K attributes are not allowed to take NULL values.
- A relation can have at most one P.K.

**Attribute Key (AK)** -> C.K except PK are called alternate key

Note: PK and AK are also minimal as formed from CK


**Redundancy:**

```
       Student              Course
                  Enroll
		_Sid_| Sname | _Cid_ | Cname
		-----|-------|-------|------
	┌	S1   |  A ┐  |   C1  |  OS
	└	S1   |  A ┘  | ┌ C2  |  DBMS ┐
		S2   |  A    | | C2  |  DBMS | Redund.
	┌	S3   |  B ┐  | └ C2  |  DBMS ┘
	└	S3   |  B ┘  |   C3  |  CN

Only Two FD Exists :
	Sid -> Sname (Sname -x-> Sid)
	Cid -> Cname (Cname -x-> Cid)

Redundendancy
	In Student -> (S1, A)x2, (S3, B)x2
	In Course -> (C2, DBMS)x3
```

**Problem because Redundancy:**
1. Insertion Anomaly
2. Deletion Anomaly
3. Updation Anomaly 
4. More storage space (Not big problem)

**Insertion Anomaly:**
- Entering a New Course with `Cid:C4` and `Cname:AI` in Enroll Table -> `Enroll(Null, Null, C4, AI)` 
- ❌ Not Possible. Primary Key `Sid` Can't be NULL 


**Deletion Anomaly:**
- Delete Info of Student `S3` i.e. Deleting `Sid and Sname` from `Enroll(S3, B, C2, DBMS)` & `Enroll(S3, B, C3, CN)` to `Enroll(Null, Null, B, C2)` and `Enroll(Null, Null, C3, CN)` Respectively
- ❌ Not Possible. Primary Key `Sid` Can't be NULL 
- We have to delete Complete Tuple
- Because of deletion of tuples we lost the info of course `C3 CN`

**Updation Anomaly**
- Updation is required in all duplicate Copies, i.e. Time Consuming.


**Normalization->** Process of decomposing (Splitting) the relation into sub-relations such that redundancy is eliminated and anomalies like insertion, Deletion and Updation are overcome

**Let Enroll Relation be**
```
           Enroll
_Sid_| Sname | _Cid_| Cname
-----|-------|------|------
S1   |  A    |  C1  |  OS
S1   |  A    |  C2  |  DBMS 
S2   |  A    |  C2  |  DBMS  
S3   |  B    |  C2  |  DBMS 
S3   |  B    |  C3  |  OS
```

Let us **Decompose** the relation into following **sub-relation** - Student, Course, Enroll

```
    Student
_Sid_ | Sname
------|------
  S1  |  A
  S2  |  A
  S3  |  B

   Course
_Cid_ | Cname
------|-------
  C1  |  OS
  C2  | DBMS
  C3  | OS

  Enroll
_Sid_ | _Cid_
------|-------
   S1 |  C1
   S1 |  C2
   S2 |  C2
   S3 |  C2
   S3 |  C3


* After Decomposition there is no redundancy -> Thre is no anomaly after decomposition
1. No Problem in Insertion
2. No information Loss on Deleting a Course or Student
3. No Multiple Updation of Copies
```

A Decomposition is said to be correct if and only if following two properties are ensure
1. Decomposition must be dependency preserving (i.e. No loss of FD)
2. Decomposition must be lossless join Decomposition (i.e. No loss of data)

```
                 Decomposition
           /                        \
Dependancy Preserving       Lossless Join 
Decomposition               Decomposition
    R(F)                        R(F)
 /      /        \         /      /    \
 R1(F1) R2(F2)... Rn(Fn) R1(F1) R2(F2)... Rn(Fn)

-> F1∪F2∪..∪Fn ⊆ F       -> R1⨝R2⨝...⨝R3 ⊇ R
`=` ->  Depend. Presv       `=` -> Losless join 
`⊂` -> Not depen. Pres.     `⊃` -> Lossy Join
```

Ques.......

**Normal Forms**
`1NF`, `2NF`, `2NF`, `BCNF`, `4NF`

```
2NF is also 1NF
3NF is also 2NF and So 1NF
BCNF is also 3NF and So 2NF & 1NF
4NF is also BCNF and so 3NF, 2NF and 1NF
┌─────────────────────────────────────────────┐
|  ┌────────────────────────────────────┐     |
|  |  ┌───────────────────────────┐     |     |
|  |  |  ┌──────────────────┐     |     |     |
|  |  |  |  ┌────────┐      |     |     |     |
|  |  |  |  │  4NF   │ BCNF | 3NF | 2NF | 1NF |
|  |  |  |  └────────┘      |     |     |     |
|  |  |  └──────────────────┘     |     |     |
|  |  └───────────────────────────┘     |     |
|  └────────────────────────────────────┘     |
└─────────────────────────────────────────────┘
```

```
1NF   ┐
2NF   | Upto BCNF We elminate the Redundancies
3NF   | Present in relation because of:
BCNF  ┘ Non-Trivial FD

4NF   ] In 4NF We elminate redundancy Present   
        because of Multivalued Dependancies (MVD)
```

**1. 1NF**
- If No valued attributes, then Relation is at least in 1NF 
- If Multivalued exist, then not in 1NF
```
      Student
_Sid_| Sname | Mob_no
-----|-------|----------     MVD Exists
S1   |  A    |  {M1, M2}
S2   |  B    |  {M2, M3}
S3   |  B    |   M2 
          
          ⬇ Convert into single Valued

      Student
_Sid_| Sname | Mob_no
-----|-------|-------- 
S1   |  A    |  M1
S1   |  A    |  M2           No MVD
S2   |  B    |  M2
S2   |  B    |  M3
S3   |  B    |  M2  
```

Note:
- In `X->Y` if X is a super key, then there is no redundancy because of this FD
- In `X->Y` if X is not SK, then it will cause redundancy in the relation

**Possible Non-Trivial FDs that may Cause Redundancy in the Relation:**
```
- If X is not a SK, then Y will not be SK.
- If X is not a SK, then Possible value of X Can be P.S.C.K and N.P.A

     X ------------------------> Y

Types of FD:

Type 1. PSCK ----------------------> NPA  
Type 2. (PSCK + NPA) --------------> NPA
Type 3. NPA -----------------------> NPA
Type 4. Proper subset -------------> Proper subset
        of one CK                    of another CK
Type 5. Proper subset -------------> Proper subset
        of one CK + NPA              of another CK

PSCK -> Proper subset of Candidate Key. i.e. Removing a attribute from this Candidate Key (Minimal Super Key).
NPA -> Non Prime Attribute
```

```
           |
(FD Types) ➡ 
  (NF)     |Type 1 |Type 2 |Type 3 |Type 4 |Type5
----⬇------|-------|-------|-------|-------|------
1NF        |   ✓   |   ✓   |   ✓   |   ✓   | ✓
2NF        |   X   |   ✓   |   ✓   |   ✓   | ✓
3NF        |   X   |   X   |   X   |   ✓   | ✓
BCNF       |   X   |   X   |   X   |   X   |  X  

✓ : Allowed
X : Not Allowed
```

.
.
.


---

# Query Languages

**1. Relational Algebra**
- Procedural Query Language
- Relation Algebra query will always produce distinct Tuples

**2. SQL** 
- Non-Procedural Language
- Duplicate tuples may be present in the output

---
# Relational Algebra
