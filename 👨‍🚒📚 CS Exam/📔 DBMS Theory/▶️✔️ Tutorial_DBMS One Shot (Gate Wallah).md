---
layout:
  width: default
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: true
  metadata:
    visible: true
  tags:
    visible: true
---

# ▶️✔️ Tutorial\_DBMS One Shot (Gate Wallah)

## [Database Management System One Shot | CS & IT Engineering | DA | Maha Revision | Target GATE 2025](https://youtu.be/k6rDS0qQiO0)

**Topics**

1. Relational Model and Normal Forms
2. Query Languages
3. Transaction and Concurrency Control
4. Indexing
5. ER Model

#### Relational Model

**Relation** -> Organizing in the form of table (Row and Column)

```
Sid | Sname | Marks
----|-------|------
S1  | Ram   | 35
S2  | Nikhil| 56
S3  | Vishal|0
S4  | Ram   | 72
```

**Attributes/Fields** -> Column : `Sid`, `Sname`, `Marks` **Tuple/Record** -> Row : `S1 Ram 35`, `S2 Nikhil 56`

**Degree** -> No. of attributes in Relation(above ex : 3) **Cardinality** -> No. of Records in Relation(above ex: 4)

**Relation Schema:** `Student(Sid, Sname, Marks`. Tuple Value :

* `(S1 Ram 35)`
* `(S4 Ram 72)`
* `(Nikhil S2 56)` ❌ Order is important

**Relational Instance:**

```
{ (S1, Ram, 35), (S2, Nikhil, 56), (S3, Vishal, 0), (S4, Ram, 72), (S5, Mohan, 56) }
```

* Order of tuples doesn't matter in Relation Instance as it is a set.

***

#### Functional Dependency (FD)

Relation `R(A,B,C,D,E,F)`

**Functional Instance** -> Relationship that holds b/w attribute sets of Relation.

Let X & Y are any two attribute set over R.

**then** -> `X->Y` is called functional dependency.

Note:

* It may or May not hold in a given relation
* `X->Y` does not hold if there exists two tuples `t1, t2 ϵ R` such that `t1.x=t2.x` but `t1.y ≠ t2.y`
* Based on relation instance, ==we can not conclude which F.D will hold==, ==we can only conclude which F.D will not hold==.

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

* X : Determiner & Y: Dependent
* i.e. if we know value of X in the relation then we can identify value of Y

**Types of FD's:**

**1. Trivial FD:**

* If `Y ⊆ X` then `X->Y` is trivial
* Every trivial F.D always holds true in the relation.
* Ex: `AB->B`

**2. Non-Trivial FD:**

* If X and Y are two Non empty sets such that `X∩Y=∅`, then `X->Y` is called a non-trivial\`
* May or May not hold true for a relation
* ex `A->B`

**3. Semi-Trivial FD:** (Not Standard)

* If X and Y are two Non empty sets such that `Y⫋X` and `X∩Y=∅`, then `X->Y` is called a ==semi-trivial==
* ex: `AB->BC` (==`AB -> C` Non trivial== + ==`AB->B` Trivial==)

No. of Non-Trivial FD `X->Y` Possible For above relation?

```
Cardinality of X (|X|? either 1 or 2

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

**Note:** Functional Dependency are property of Attributes in A Relation. You can Conclude that `Sid->Sname`, `Sid->Smarks` but Not `Sname->Sid` or `Sname.Smarks->Sid`. Two different person with same name and Marks can exists

**`⫋`**

* The symbol **⫋** means **subset (⊆)**.
* The **normal subset symbol (⊆)** means _“subset or equal to”_. Example: `{A} ⊆ {A, B}` and also `{A, B} ⊆ {A, B}`.
* The **proper subset symbol (⊂)** means _“strict subset”_, i.e., Y is a subset but not equal. Example: `{A} ⊂ {A, B}`, but `{A, B} ⊄ {A, B}`.
* The symbol you wrote **⫋** is just another typographical style sometimes used for **subset (⊆)** in relational algebra or FD notes. It does not imply anything extra beyond “Y is contained in X”.

**Properties of FD**

1. **Reflexivity:** If `Y ⫋ X` then `X->Y` is called reflexive FD (always hold in a relation)
2. \==**Augmentation**== : If ==`X->Y` holds in relation, then `XZ->YZ`== will also hold in relation
3. **Transitivity** : If `X->Y` & `Y->Z` holds in Relation, then `X->Z` will also holds

* These three Properties are Called **Armstrong's Axioms**, and we Can prove and derive All other properties from these

1. **Splitting (Decomposition)** : If ==`X->YZ` holds in Relation, then `X->Y` and `X->Z`== holds in Relation.
2. **Composition :** If ==`X->Y` and `P->Q` holds in the Relation then `XP->YQ` holds== in Relation
3. **Union:** If ==`X->Y` & `X->Z` holds in the Relation then `X->YZ` will also hold in Relation==. (It is a corollary of Composition i.e. if P=X in Composition)
4. **Pseudo Transitivity :** If X->Y and YW->Z, then XW->Z will hold in Relation.

**Important Rule of Relation Model**

Doctor Cord have given 13 Rules (0 to 12) called `Cord twelve rules`

1. Each ==Tuple of the relation must be distinct==, i.e. duplicate tuples are not allowed in the relation
2. For tuple Uniqueness ==every relation must have a key==

**ER Model Notations:** ⭐

```
[] : Rectangle -> Entity
[[]] : Double Rectangle -> Weak Entity
() : Oval -> Attributes
(_) -> : Underline Oval -> Key Attribute PK, CK, AK (underlined)
<> : Diamond ->  Relation
<<>> : Double Diamond -> Identifying Relationship

(optional)
(()) : Double Oval -> Multivalued Attribute
(…) : Dashed Oval -> Derived Attribute
```

```

   [EMP]                                [[Dependent]]
  /     \       << Take cares of>>        /     \ 
(Eid) (Ename)                          (Dname)  (Dage)
      ↓                                       ↓
Strong Entity                            Weak Entity
 
Strong Entity Set  -> It contains sufficient attributes such that key can be defined

Weak Entity Set -> Id doesnot contain sufficient attributes for a key

Emp:                                       Dependent:
Eid | Ename                             Eid | Dname |  Dage
----|------                             ----| ------|------
E1  |  Ram      <<take care of >>       E1  | Riya  | 05
E2  |  Shyam                            E2  | Rony  | 03
E3  |  Ohm                              E3  | Riya  | 05
  ↓                                            ↓
 Key:Eid                                Key:{Eid, DName}

Note: Any Employee (Eid) will not give his/her two children Same name, so {Eid, DName} is a key. but {Eid, Dage} can't be key, because an Employee can have two children with same age.
```

**Closure of an attribute Set:\*\***

Closure of an attribute set X i.e. X⁺ is a set of all attributes that can be determined by X

Let R(A B C D) With FD set `F={A->BC, B->C, AD->B, C->D}`

```
- (A⁺) = (AB⁺) = (AC⁺) = (AD⁺) = (ABC⁺) = (ACD⁺) = (ABCD⁺) = {A, B, C, D,} -> All
- (B⁺) = (BC⁺) = (BD⁺) = {B, C, D}
- (C⁺) = (CD⁺) = {C, D}
- (D⁺) = {D}

A⁺, AB⁺, AC⁺, AD⁺, ABC⁺, ABD⁺, ACD⁺, ABCD⁺ All of them represent the key of the relation
```

\==**Key**== -> A ==set of attributes that can be used to identify each tuple uniquely== or A set of attributes that can determine all attributes of the Relation.

\==**Super Key(SK)**== -> Let R be a relation on X be some set of attribute from relation R, if (X)⁺ contains all attributes of relation R then X is a Super key of relation R

* \==Need not be minimal==
* Ex: `A, AB, AC, AD, ABC, ABD, ACD or ABCD`

\==**Candidate Key(CK)**== -> A ==minimal set of attribute== that can ==determine all attribute== of relation is candidate key.

* or Let R be the relation, and X be some super key of relation R, If No proper subset of X is a super Key, then X is a minimal Super Key i.e. X is candidate key
* Ex: `A`

**Points to remember:**

* Every CK is a SK, but Every SK need not be CK
* A relation must have at least one CK
* A SK with a single attribute is always a CK
* if CK is formed of a single attribute, then simple CK
* if CK is formed of two or more attribute, then Composite CK
* \==Attribute that belongs to any CK are called **prime Attributes**==
* Attributes that does not belongs to any of the CK are called non-prime attributes

**Note:**

* Minimal Set of attributes -> set of attributes from which no attribute can be removed without destroying its property of being a key

```
- Any Super Set of Candidate Key is a Super Key
- Super Key = All attributes of at least one C.K + 0 or More of the remaining attributes
```

**QuesFind total no. of S.Ks of Relation R**

```
Let R (A B C D E F G) be a Relation and 
(AC) & (BC), and (CD) are the only three C.Ks of the Relation. 
```

**Solution**: No. of Sets Including **AC** = No. of Subsets of {B, D, E, F, G} -> 2<sup>5</sup> No. of Sets Including **BC** = No. of Subset of {A, D, E, F, G} -> 2<sup>5</sup> No. of Sets Including **CD** = No. of Subsets of { A, B, E, F, G} -> 2<sup>5</sup>

No. of Sets including **AC & BC** Both = No. of Subsets of {D, E, F, G} -> 2<sup>4</sup> No. of Sets including **AC & CD** Both = No. of Subsets of {B, E, F, G} -> 2<sup>4</sup> No. of Sets including **BC & CD** Both = No. of Subsets of {A, E, F, G} -> 2<sup>4</sup>

No. of Sets including **AC & BC & CD** = No. of Subsets of {E, F, G} -> 2<sup>3</sup>

**Total no. of S.Ks of Relation R** = **AC** ∪ **BC** ∪ **CD** = 3x2<sup>5</sup> - 3x2<sup>4</sup> + 2<sup>3</sup>

\=> 96 - 48 + 8 =56

**Ques Find total no. of Super Keys**

```
R (P Q R S T U V)
and C.K = (PQ), (RS) & (TU)
```

**Solution:** No. of Sets Including **PQ** = No. of Subsets of {R, S, T, U, V} -> 2<sup>5</sup> No. of Sets Including **RS** = No. of Subset of {P, Q, T, U, V} -> 2<sup>5</sup> No. of Sets Including **TU** = No. of Subsets of {P, Q, R, S, V} -> 2<sup>5</sup>

No. of Sets including **PQ & RS** Both = No. of Subsets of {T, U, V} -> 2<sup>3</sup> No. of Sets including **RS & TU** Both = No. of Subsets of {P, Q, V} -> 2<sup>3</sup> No. of Sets including **TU & PQ** Both = No. of Subsets of {R, S, V} -> 2<sup>3</sup>

No. of Sets including **PQ & RS & TU** = No. of Subsets of {V} -> 2<sup>1</sup>

**Total no. of S.Ks of Relation R** = **AC** ∪ **BC** ∪ **CD** = 3x2<sup>5</sup> - 3x2<sup>3</sup> + 2<sup>1</sup>

\=> 96-24+2 = 74

**Ques: Find All CKs of Relation R**

```
R (A B C D E)
F = { AB->C
	  B->E
	  C -> D }
```

**Solution:**

Essential Attributes = {A, B} All essential attributes must be present in Every key of Relation.

(AB)<sup>+</sup> = {A, B, C, E, D} ∴ AB is S.K (A)<sup>+</sup> = {A} Not a S.K (B)<sup>+</sup> = {B, E} Not a S.K -> **No. Proper subset of AB** (i.e. A<sup>+</sup> and B<sup>+</sup> ) is SK ∴ AB is C.K

-> **Candidate Key** -> AB -> **Prime Attributes** -> {A, B} -> **Non Prime Attribute** -> {C, D, E}

Note:

* If there exists a non trivial FD X->Y in the FD set of the relation such that `Y` is a prime attribute then relation will have at least two C.K
* We can obtain few more super keys by replacing prime attribute (y) in the corresponding candidate key by `X` i.e. LHS of FD X->Y (Prime Attribute)

**Ques: Find All CKs of Relation R**

```
R (A B C D E)
F = { AB->CD
	  C->E
	  BD -> A }
```

**Solution:**

Essential Attributes = {A, B} All essential attributes must be present in Every key of Relation.

(AB)<sup>+</sup> = {A, B, C, D, E} ∴ AB is S.K (A)<sup>+</sup> = {A} Not a S.K (B)<sup>+</sup> = {B, E} Not a S.K -> **No. Proper subset of AB** (i.e. A<sup>+</sup> and B<sup>+</sup> ) is SK ∴ AB is C.K

(BD)<sup>+</sup> = {A, B, C, D, E} ∴ AB is S.K (B)<sup>+</sup> = {B} Not a S.K (D)<sup>+</sup> = {D} Not a S.K -> **No. Proper subset of BD** (i.e. B<sup>+</sup> and D<sup>+</sup> ) is SK ∴ BD is C.K

-> **Candidate Key** -> AB, BD -> **Prime Attributes** -> {A, B, D} -> **Non Prime Attribute** -> {C, E}

**Membership Test:**

* Consider F is a given FD set, and X->Y be some FD.
* If (X)⁺ w.r.t FD set F contains `Y` then we say that X->Y is a member of FD set F

```
ig Y (X)+ w.r.t F
then X-> Y is not a member of F
```

Following are same,

1. X->Y is a member of F
2. F implies X->Y
3. X->Y is implied by F

Note: Set of all FDs implied by F is called closure of FD set F i.e. F+

**Ques: Find F+**

```
R (A B C D)
F = { AB->C
	  C->D}
```

**Solution:**

(A)<sup>+</sup> = {A} (B)<sup>+</sup> = {B} (C)<sup>+</sup> = {C, D} (D)<sup>+</sup> = {D}

(AB)<sup>+</sup> = {A, B, C, D} (AC)<sup>+</sup> = {A, C, D} (AD)<sup>+</sup> = {A, D} (BC)<sup>+</sup> = {B, C, D} (BD)<sup>+</sup> = {B, D} (CD)<sup>+</sup> = {C, D}

(ABC)<sup>+</sup> = {A, B, C, D} (ABD)<sup>+</sup> = {A, B, C, D} (ACD)<sup>+</sup> = {A, C, D} (BCD)<sup>+</sup> = {B, C, D} (ABCD)<sup>+</sup> = {A, B, C, D} Trivial FD -> (Optional)

```
F+ = {
	C->D
	AB->CD  Simplified -> (AB-> C + AB->D)
	AC->D,
	BC->D,
	ABC->D,
	ABD->C,
	ACD->B,
}

7 Simplified Non-Trivial FDs in F+
```

**Relation b/w two FDs sets**

Let F1 & F2 are any two FD sets

1. If all FDs of FD set F1 are member of F2, then F1⊆F2
   * or If F2 Covers F1
   * or All FDs of F1 are implied by F2
2. If all FDs of FD set F2 are member of F1 then F2 ⊆ F1
   * or If F1 covers F2
   * or All FDs of F2 are implied by F1

**1.** If F1 ⊆ F2 but F2 ⊈ F1 then F1 ⊂ F2 **2.** If F2 ⊆ F1 but F1 ⊈ F2 then F2 ⊂ F1 **3.** If F1 ⊆ F2 and F2 ⊆ F1 then F1 = F2

**Ques. Find Relation between F1 and F2**

```
F1 = {AB->C, BC->D, D->AE}
F2 = {AB->CD, BC->DA, D->E}
```

**Solution:**

Check if F1 Covers F2

* **FDs of F2**
* AB->CD -> yes ∵ ( F1: AB->C & BC->D)
* BC->DA -> yes ∵ ( F1: BC->D & D->AE)
* D->E -> yes ∵ ( F1: D-> AE)

Check if F2 Covers F1

* **FDs of F1**
* AB->C -> yes ∵ ( F1: AB->CD)
* BC->D -> yes ∵ ( F1: BC->DA)
* D->AE -> No ∵ D+ w.r.t F2 = {D, E}, and A ∉ {D,E}

∴ F2 ⊂ F1

**Minimal Cover**

**Minimal/Canonical Cover:-** Let F be any FD set, and FD set Fm such that

1. Fm = F { i.e. F⊆ Fm & Fm ⊆ F}
2. Fm does not contain any extraneous attribute in the LHS and Fm does not contain any Redundant FD then, Fm is called minimal Cover of F

**Steps to Identify Minimal Cover:-**

* Step 1. Simplify all FDs such that R.H.S contains exactly one attribute
* Step 2. Find and remove extraneous attributes from the L.H.S { if any }
* Step 3. Find and eliminate all redundant FDs
* Step 4. Finally Union all remaining FDs (if require)

**Extraneous Attribute:** If `α -> β` and `A ∈ α` if (α - A)+ determines A, then `A` is Extraneous **Redundant Attribute:** if `(α)+` w.r.t `(F-α ->β)` Contains `β` then `α ->β`

**Ques find the minimal Cover of FD set F**

```
F = { A -> BC
	  CD -> E
	  E -> C
	  D -> AEH
	  ABH -> BD
	  DH -> BC }
```

**Solution:**

* Step 1
  * A->B (Simplified A->BC)
  * A->C (Simplified A->BC)
  * CD->E
  * E->C
  * D->A (Simplified D->AEH)
  * D->E (Simplified D->AEH)
  * D->H (Simplified D->AEH)
  * ABH->B (Simplified ABH->BD)
  * ABH->D (Simplified ABH->BD)
  * DH->B (Simplified DH->BC)
  * DH->C (Simplified DH->BC)
* Step 2
  * A->B
  * A->C
  * D->E (Simplified from CD->E by removing extraneous attribute C) ∵ E ∈ (D)+ = {D,A,E,H,C}
  * E->C
  * D->A
  * D->E
  * D->H
  * AH->D (Simplified from ABH->D by removing extraneous attribute B) ∵ B ∈ (A)+ = {A,B}
  * D->B (Simplified from DH->B by removing extraneous attribute H) ∵ B ∈ (D)+ = {D,A,B,C,E,H}
  * D->C (Simplified from DH->C by removing extraneous attribute H) ∵ C ∈ (D)+ = {D,A,B,C,E,H}
* Step 3
  * A->B
  * A->C
  * ~~D->E~~ Remove (Redundant FDs) ∵ D->E exist two time
  * E->C
  * D->A
  * D->E
  * D->H
  * AH->D
  * ~~D->B~~ Remove (Redundant FDs) ∵ D -> A->B
  * ~~D->C~~ Remove (Redundant FDs) ∵ D -> A->C
* Step 4
  * A->BC (A->B ∪ A->C)
  * E->C
  * D->AEH (D->A ∪ D->E ∪ D->H)
  * AH -> D
* This is Minimal Cover of F

**Ques find the minimal Cover of FD set F**

```
F = { A -> B, B->AC, C->AB }
```

* Step 1
  * A->B
  * B->A
  * B->C
  * C->A
  * C->B
* Step 2
  * All correct
* Step 3 (Order 1 )
  * A->B
  * B->A
  * B->C
  * ~~C->A~~ Remove (Redundant FDs) ∵ B -> C->A
  * C->B
* Minimal Cover 2
* Step 3 (Order 2)
  * A->B
  * B->A
  * B->C
  * ~~C->A~~ Redundant because (C->B & B->A)
  * C->B
* Minimal Cover 12
* Step 4 (Not Required)
* Minimal Cover for given FD set need not be unique

**Ques R (A B C D)**

```
F = { AB->CD, D->A, C->B}
```

Find C.Ks of sub-relation **R1(BCD)** of relation R

**Solution:**

(B)+ = {B} (C)+ = {C,B} (D)+ = {D, A} (BC)+ = {B, C} (BD)+ = {B, D, A, C} (CD)+ = {C, D, B, A}

Remove Trivial Relation & A's Relation

~~(B)+ = {B}~~ Trivial (C)+ = {B} ∵ (C->C Trivial) (D)+ = {D, A} (A is not in R1) ~~(BC)+ = {B, C}~~ Trivial (BD)+ = {C} ∵ (BD -> BD Trivial) & (A is not in R1) (CD)+ = {B} ∵ (CD->CD Trivial) & (A is not in R1)

FD set of sub relation R1 { C-> B, BD->C, CD->B} ∴ CK = (BD), (CD)

***

[3:32:00](https://youtu.be/k6rDS0qQiO0?t=12754) ✅

### Schema Refinement or Normalization

**Normalization** - It is the process of eliminating/reducing the redundancies present in the relation

```
Sid -> Sname    ⬅   Student             Course  ➡  Cid  -> Cname  
Sname -/> Sid			       Enroll               Cname -/> Cid
					_Sid_| Sname | _Cid_ | Cname
					-----|-------|-------|------
				 	S1   |  A    |   C1  |  OS
				 	S1   |  A    | ┌ C2  |  DBMS
					S2   |  A    | | C2  |  DBMS
				 	S3   |  B    | └ C2  |  DBMS
				 	S3   |  B    |   C3  |  CN

Only two FDs exist in the Enroll Table :
Sid -> Sname
Cid -> Cname

∴ C.K = (Sid, Cid)
```

Note: A Relation will have at least one C.K

**Primary Key (PK)** -> ==One of the C.K is chosen as P.K==

* P.K attributes are ==not allowed to take NULL== values.
* A relation can have ==at most one P.K==.

**Attribute Key (AK)** -> ==C.K except PK are called alternate key==

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

* Entering a New Course with `Cid:C4` and `Cname:AI` in Enroll Table -> `Enroll(Null, Null, C4, AI)`
* ❌ Not Possible. Primary Key `Sid` Can't be NULL

**Deletion Anomaly:**

* Delete Info of Student `S3` i.e. Deleting `Sid and Sname` from `Enroll(S3, B, C2, DBMS)` & `Enroll(S3, B, C3, CN)` to `Enroll(Null, Null, B, C2)` and `Enroll(Null, Null, C3, CN)` Respectively
* ❌ Not Possible. Primary Key `Sid` Can't be NULL
* We have to delete Complete Tuple
* Because of deletion of tuples we lost the info of course `C3 CN`

**Updation Anomaly**

* Updation is required in all duplicate Copies, i.e. Time Consuming.

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

**Ques Let R (A B C D)**

```
F = {A->B, B->C, C->D, D-A}
```

Let R is decomposed into three sub-relations R1(AB), R2(BC), R3(CD) Check whether decomposition is dependency preserving or not

**Solution:**

**R1 (AB)**

* F1 = { A->B , B->C }

**R2 (BC)**

* F2 = {B->C, C->B}

**R3 (CD)**

* F3 = {C -> D, D->C}

F1 ∪ F2 ∪ F3 = { A->B, B->C, C->D, B->A, C->B, D->C} We Already know F1 ∪ F2 ∪ F3 ⊆ F

We need to check if F⊆ F1∪F2∪F3 or not

* i.e. if F1 ∪ F2 ∪ F3 covers F\
  FDs of F = { A->B ( Present in union ) B->C, ( Present in union ) C->D, ( Present in union ) D->A} (Present in union as D->C & C->B & B->A) So F ⊆ F1 ∪ F2 ∪ F3

F1 ∪ F2 ∪ F3 ⊆ F and F ⊆ F1 ∪ F2 ∪ F3 -> Dependency Preserving

\[Break from 4:16-4:52]

***

#### Normal Forms ⭐

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

✓ : FD types Allowed
X : FD types Not Allowed
```

**1. 1NF -> No Multivalued Attributes**

> **Condition:** A relation is in **1NF** if all attributes contain **atomic values** (no multivalued or composite attributes).

* Each column contains only ==**one value** per row.==
* If No valued attributes, then Relation is at least in 1NF
* If Multivalued exist, then not in 1NF
* In `X->Y` if X is a super key, then there is ==no redundancy because of this FD==
* In `X->Y` if X is not SK, then it will cause redundancy in the relation

**Example:**

```
      Student
_Sid_| Sname | Mob_no
-----|-------|---------- 
S1   |  A    |  {M1, M2}
S2   |  B    |  {M2, M3}
S3   |  B    |   M2

- Mob_no → Multiple Value

❌ Not in 1NF due Multivalued attributes
```

```
          ⬇ Convert into single Valued

      Student
_Sid_| Sname | Mob_no
-----|-------|-------- 
S1   |  A    |  M1
S1   |  A    |  M2 
S2   |  B    |  M2
S2   |  B    |  M3
S3   |  B    |  M2  

✅ No multivalued attributes → Relation is in 1NF.
```

**2. 2NF -> 1NF + No Partial Dependency**

> **Condition:** A relation is in **2NF** if it is in **1NF** and ==**no non-prime attribute** is partially dependent on the candidate key (C.K).==

* A relation R is in 2NF only if
  1. R is in 1NF
  2. No non-prime attribute should partially dependent on `C.K`
* If type 1 FD i.e. ==`PSCK->NPA` exists in the relation R then partial dependency exists in the relation==, and hence relation R will not be in `2NF`
* In Detail : If `α → β` is a functional dependency and there exists some set of attribute `x ϵ α` such that `(α-x)->β` holds in the relation then `α → β` is called partial dependency, and if there exists no such set of attribute ==`x` then `α → β` is called full functional dependency==

**Example:**

```
    StudentCourse  
_Sid_ | _Cid_ | Sname  | Cname  
------|-------|--------|--------   
S1    | C1    | A      | Math  
S1    | C2    | A      | Science  
S2    | C1    | B      | Math  
S2    | C3    | B      | Physics 

- C.K = {Sid, Cid}
- Sid → Sname (Partial dependency)
- Cid → Cname (Partial dependency)   

❌ Not in 2NF due to partial dependencies. 
```

```
	 Decompose into Two Relation Student & Course
           ⬇ to Remove Partial Dependency


         Student          Course           
     _Sid_ | Sname        _Cid_ | Cname     
     ------|-------       ------|--------     
     S1    | A            C1    | Math        
     S2    | B            C2    | Science     
                          C3    | Physics    
        ╲               ╱
			Enrollment  
			_Sid_ | _Cid_  
			------|--------  
			S1    | C1  
			S1    | C2  
			S2    | C1  
			S2    | C3

✅ No partial dependency → Relation is in 2NF
```

**3. 3NF -> 2NF + No transitive dependency**

> **Condition:** A relation is in **3NF** if it is in **2NF** and ==**no transitive dependency** exists==.

* A relation R is in 3NF only if
  1. R is in 1NF
  2. Every non-trivial functional dependency `X->Y` must be with X as a super key of relation R or Y must be a prime attribute
  3. Type 1 , Type 2 and Type 3 FDs are not allowed in 3NF

**Example:**

```
              Employee  
_Eid_ | Ename   | Dept_id   | Dept_name  
------|---------|-----------|------------  
E1    | Alice   | D1        | HR  
E2    | Bob     | D2        | IT  
E3    | Charlie | D1        | HR 

- C.K = Eid
- Eid → Dept_id → Dept_name (Transitive dependency)

❌ Not in 3NF due to transitive dependency.
```

```
Decompose into Two Relation Employee & Department
           ⬇ to Transitive Dependency
           
    Employee                      Department
_Eid_ | Ename   | Dept_id     _Dept_id_ | Dept_name   
------|---------|--------      ---------|---------- 
E1    | Alice   | D1            D1      | HR 
E2    | Bob     | D2            D2      | IT  
E3    | Charlie | D1  

✅ No transitive dependency → Relation is in 3NF
```

**4. BCNF -> 3NF + every non-trivial functional dependency has super key on LHS**

> **Condition:** A relation is in **BCNF** if it is in **3NF** and ==**every non-trivial functional dependency**== has a ==super key on the LHS.==

* A relation R is in BCNF only if
  1. R is in 1NF
  2. Every Non-trivial FD `X->Y` must be with X as a super key
  3. None of the Five types FDs are allowed in BCNF.

**Example:**

```
         dept_advisor
| s_ID | i_ID | dept_name |
|------|------|-----------|
| S1   | I1   | CS        |
| S2   | I1   | CS        |
| S3   | I2   | Math      |
| S4   | I3   | Math      |



- C.K = {s_ID, dept_name} & {s_ID, i_ID} 
- i_ID → dept_name (i_ID Not a Super Key)
- s_ID, dept_name → i_ID

❌ Not in 3NF, The relation is not in BCNF because the dependency i_ID → dept_name violates BCNF. Here, i_ID is not a super key of the relation, as the candidate keys are {s_ID, dept_name} and {s_ID, i_ID}.
```

```
Decompose into Two Relation Employee & Department
           ⬇ to Transitive Dependency
           
    instructor            std_advisor   
| i_ID | dept_name |      | s_ID | i_ID |
|------|-----------|      |------|------|
| I1   | CS        |      |  S1  |  I1  |
| I2   | Math      |      |  S2  |  I1  |
| I3   | Math      |      |  S3  |  I2  |
                          |  S4  |  I3  |

✅ Every non-trivial functional dependency has a super key on the left-hand side -> Relation is in BCNF 
```

#### Question Practice

**Ques. Find the Normal form of the Relation ⭐**

```
R(A B C D E F)

F = { AB -> CD
	  D -> A
	  C -> E
	  B -> F }
```

**Solution:**

```
Step 1: Find candidate key
- C.K (AB), (DB)
```

**Note:** We can't store multiple value in a single entry -> so By default Normal form of a relation is 1NF -> So a table which is not in 1NF is not a Valid Relation -> So we can't find C.K for it. and vice versal

```
we have find c.K for our relation `R`, so it is in 1NF atleast

Step 2: Find Types of FD

- AB -> CD (LHS(AB) is SK) : Satisfy BCNF -> BCNF
- D -> A (PSCK -> PSCK) : Type 4 FD -> 3NF
- C -> E (NPA -> NPA) : Type 3 FD -> 2NF
- B -> F (PSCK -> PSCK) : Type 1 FD -> 1NF

Type 4 FD -> Allowed in 3NF, but not in BCNF
Type 3 FD -> Allowed in 2NF, but not in 3NF
Type 1 FD -> Allowed in 1 NF, but not in 2NF
```

* PSCK -> Proper subset of a Candidate key
* NPA -> Non Prime Attribute
* SK -> Super key **Normal Form ->** Least of the highest Normal form satisfy by all the FDs, Here 1NF

```
Ans : 1NF
```

**Ques. Find the Normal form of the Relation ⭐**

```
R (AB -> CD)

F = {AB -> C
	 BC -> D}
```

**Solution:**

```
AB -> C (LHS(AB)-> SK) : BCNF
BC -> D (PSCK(B) + NPA(D)) : Type 2 FD -> 2NF

Normal Form of the RElation: 2NF
```

***

## Query Languages

**1. Relational Algebra**

* Procedural Query Language
* Relation Algebra query will always produce distinct Tuples

**2. SQL**

* Non-Procedural Language
* Duplicate tuples may be present in the output

***

## Relational Algebra (RA) ⭐

* **Query Condition** evaluates tuple by tuple on the database table, taken only one tuple at a time.
* There is no aggregate function in Relational Algebra like SQL and so the Relational Algebra is Procedural Language
* If we wants to compare two or more tuples of the same table or different tables then we need to join those tuples into single tuple.

**Two Types of RA Operations**

```
                 R.A Operations
                /               \
Basic R.A Operation             Derived R.A. Operation
```

**1. Basic R.A. Operations**

1. Projection (Π)
2. Selection (σ)
3. Cross Product (×)
4. Union (∪)
5. Set difference (−)
6. Rename (ρ)

**2. Derived R.A. Operations**

1. Intersection (∩)
2. Join (⨝)
3. Division (÷)⭐

**Order of Execution of Relational Algebra** -> Inner Query to Outer Query (or Read from Right to Left) ⭐

**Example Table**

```
| Sid  | Cid  | Branch |
|------|------|--------|
| S1   | C1   | CS     |
| S2   | C2   | IT     |
| S3   | C1   | IT     |
```

**1. ==Projection (Π)==**

**Projection** -> Used to Produce output from ==specified Column==

1. Produce All 3 Attribute in Output -> Π<sub>Sid,Cid,Branch</sub>(Student)

```
| Sid  | Cid  | Branch |
|------|------|--------|
| S1   | C1   | CS     |
| S2   | C2   | IT     |
| S3   | C1   | IT     |

Note: If Selection (σ) Condition operation is not Specified, Then All tuples would be Selected
```

2. Produce All Attribute in Output -> (Student)

```
| Sid  | Cid  | Branch |
|------|------|--------|
| S1   | C1   | CS     |
| S2   | C2   | IT     |
| S3   | C1   | IT     |

Note: If Projection (Π) is not Present then also All Attributes of Internal Schema will be present in output
```

4. If we only need `Cid` Attribute -> Π<sub>Cid</sub>(Student)

```
Output  
| Cid  |
|------|
| C1   |
| C2   |

Note: It will contain Distinct Tuples
```

3. Produce `Cid` & `Branch` -> Π<sub>Cid, Branch</sub>(Student)

```
| Cid  | Branch |
|------|--------|
| C1   | CS     |
| C2   | IT     |
| C1   | IT     |
```

**2. ==Selection (σ)==**

**Selection** -> Used to ==select tuples== based on Specified Condition

1. Select the tuples from Student table Where `Cid = C1` -> σ <sub>(Cid = 'C1')</sub>

```
| Sid  | Cid  | Branch |
|------|------|--------|
| S1   | C1   | CS     |
| S3   | C1   | IT     |

Note: No Projection, So include all attributes in output
```

2. Select the `Sid` From Student Table where `Cid=C1` -> Π<sub>Sid</sub>(σ <sub>(Cid = 'C1')</sub>(Student))

```
| Sid  |
|------|
| S1   |
| S3   |

Note: Order of Execution is : Selection -> Projection First Select Whole Table -> Then Select only Required Tuples -> Then Project only Required Attributes ⭐
```

3. Select the `Sid` From Student Table where `Cid=C1` and `Branch=IT` -> Π<sub>Sid</sub>(σ <sub>(Cid = 'C1' ∧ Branch='IT')</sub>(Student))

```
| Sid  |
|------|
| S3   |
```

4. Select the `Sid` From Student Table where `Cid=C1` or `Branch=IT` -> Π<sub>Sid</sub>(σ <sub>(Cid = 'C1' ∨ Branch='IT')</sub>(Student))

```
| Sid  |
|------|
| S1   |
| S2   |
| S3   |
```

Note: Selection and Projection are unary operation i.e. applied on Single Relation.

**3. ==Cross Product (×)==**

* It is a binary Operation
* Let `R` & `S` are two relation. then `RxS` will result all attributes of `R` followed by all attributes of `S`, with each tuple of `R` joined with each tuple of `S`

Here are the tables in markdown code blocks:

```markdown
Table R (Student)
| Sid  | Sname |
|------|-------| 
| S1   | A     | 
| S2   | A     |  m tuples
| S3   | B     | 


Table S (Enroll)
| Sid  | Cid  | Marks |
|------|------|-------|
| S1   | C1   | 35    |  n tuples
| S1   | C2   | 49    |
| S3   | C1   | 40    | 
```

Then Cross Product of `RxS` :

```
Table R × S (Natural Join or Cartesian Product)

       R        +          S
 ┌────────────┐   ┌──────────────────┐ 

| RSid | RSname | SSid | SCid | SMarks |
|------|--------|------|------|--------|
| S1   | A      | S1   | C1   | 35     |
| S1   | A      | S1   | C2   | 49     |
| S1   | A      | S3   | C1   | 40     |
| S2   | A      | S1   | C1   | 35     |
| S2   | A      | S1   | C2   | 49     | m x n tuples
| S2   | A      | S3   | C1   | 40     |
| S3   | B      | S1   | C1   | 35     |
| S3   | B      | S1   | C2   | 49     |
| S3   | B      | S3   | C1   | 40     |

- also known as cross join/cartesian join
```

* If we wants to compare two or more tuples of the same table or different tables then we need to join those tuples into single tuple. ⭐

Now we can find the Result for the queries like

* Retrieve all those students Names who has enrolled for `C1` course -> Π<sub>Sname</sub>(σ <sub>(S.cid = 'C1' ∧ S.sid=R.sid)</sub>(RxS))

```
 [S]        [S]         [R]         [R]
 Cid -----> Sid  =====> Sid -----> Sname
  ⬇          ⬇           ⬇           ⬇
 C1        S1, S3      S1, S3      A, B
```

* We could Get the `Sid` of those students from `S` table only, but to get the corresponding Names, We required `R` table.

**4. ==Rename (ρ)==**

* We Can Rename
  1. Table Name
  2. Attribute Name
  3. Both Table name and Attribute Name

**Table:** `Student (Sid, Sname)`

**1. Rename Table**

* ρ<sub>Stu</sub>(Student) : Student will be renamed into `Stu` => `Stu(Sid,Sname)`

**2. Rename Attributes**

* ρ<sub>(id,name)</sub>(Student) : Attributes will be renamed into `id, name` => `Student(id,name)`

**3. Rename Both Attribute and Table**

* ρ<sub>Stu(id,name)</sub>(Student) : Student will be renamed into `Stu` and Attributes will be renamed into `id, name` => `Stu(id, name)`

Note:

* But the Changes are temporary and exist only during Query Executions, In Database, The Table and Attributes names are not Changed.
* **renaming in Relational Algebra** is similar to using an **alias in SQL** because both are **temporary and only exist during query execution**. `SELECT Sname AS Ename FROM R`
* The original database schema remains intact unless explicitly updated via `ALTER`, `UPDATE`, or `DROP`.

**Set Operations**

1. Union
2. Set Difference
3. Intersection (Derived)

* These are the set operations.
* We can perform set operation on two relations if and only if relation are **Union Compatible**
* Two relation R & S are called union compatible if and only if:
  1. **Same Degree ->** No. of Attribute in R = No. of Attribute in S
  2. Domain of the corresponding attributes of R & S must be same i.e. (Domain of ith Attribute of R = Domain of ith Attribute of R)

Note: Relation Names need not be same.

**Example of Union Compatibility**

```
1. 
         R                   S
    Sid | Cid          Sid | Cid | Fee
    ----|------        ----|-----|-----
     .. | ..           ... | ... | ...

R & S are not union compatible ❌ because Degree(R)=2 Degree(S)=3 are not equal

2.
              Char                Int
         R    ⬋              S   ⬋
    Sid | Sname        Sid | Marks
    ----|------        ----|-------
     .. | ..           ... | ... 

R & S are not union compatible ❌ because 2nd Domain (Char) of R is not Same to 2nd Domain (Int) of S

3.
              Char                Char
         R    ⬋              S   ⬋
    Sid | Sname        Sid | Ename
    ----|------        ----|-------
     .. | ..           ... | ... 

R & S are union compatible ✅
```

Note: If relations are union compatible, then we can perform set operation and the resulting relation will take the names of its attributes from Left hand side Relation.

![](https://i.sstatic.net/uH6cL.png)

**Union (∪)**

* **R∪S**

```
   R ∪ S
| Sid  | Sname |
|------|-------|
| 1    | A     |
| 2    | B     |
| 4    | A     |
| 7    | C     |
| 9    | A     |

```

**Difference (-)**

* **R-S**

```
    S - R 
| Eid  | Ename |
|------|-------|
| 4    | C     |
| 9    | A     |
```

**Intersection (∩)**

* Derived Intersection Using Set Differences.
* **R∩S** = R - (R-S)

```
     S ∩ R
| Eid  | Ename |
|------|-------|
| 2    | B     |
| 7    | C     |

```

**Join (⨝)**

* Using **Join** Operation we can join the tuples of the relation based on specified condition.

**There are two types of Join**

```
 1.Inner Join               2. Outer Join
  
- a. Theta Join (⨝θ)         d. Left outer Join (⟕)
- b. Equijoin                 e. Right outer join (⟖)
- c. Natural Join (⨝)        f. Full outer join (⟗)
```

Note: Cross join is also a type of join, But in Cross Join, No condition is specified. Therefore each tuple of 1st Relation is joined with each tuple of 2nd Relation

**Example Table:**

```
  Table R                   Table S
| A  | B  |            | B  | C  | D  |
|----|----|            |----|----|----|
| 2  | 4  |            | 1  | 3  | 9  |
| 3  | 6  |            | 3  | 4  | 8  |
                       | 6  | 2  | 8  |
```

1. **Inner Join**

A. **Theta Join (⨝**<sub>**θ**</sub>**)**:

* In Theta Join we can Define Any Condition
* R ⨝<sub>R.A≤S.B</sub> S
* It is Same as Selection σ <sub>R.A≤S.B</sub>(RxS)

```
R ⨝θ S
| R.A | R.B | S.B | S.C | S.D |
|-----|-----|-----|-----|-----|
| 2   | 4   | 3   | 4   | 8   |
| 2   | 4   | 6   | 2   | 8   |
| 3   | 6   | 3   | 4   | 8   |
| 3   | 6   | 6   | 2   | 8   |
```

B. **Equijoin**:

* It is the special case of theta join where join condition is equality condition (Need not be on common attributes)
* Equality condition need to be explicitly specify
* R ⨝<sub>R.A=S.C</sub> S
* It is Same as Selection σ <sub>R.A=S.C</sub>(RxS)

```
R Equijoin S
| R.A | R.B | S.B | S.C | S.D |
|-----|-----|-----|-----|-----|
| 2   | 4   | 6   | 2   | 8   |
| 3   | 6   | 1   | 3   | 8   |
```

Note: In Equijoin if equality Condition is Applied on Common Attribute `B`, i.e. (`R.B=S.B`). Then it will behave as Natural Join. But it will not be Natural Join, Because, In Natural Join, we not write condition Explicitly. ⭐

C. **Natural Join (⨝)**:

* In Natural Join we don't need to specify any condition, and by default condition is equality condition on all common attributes
* In Natural Join duplicate attributes will not be present. And so Derivation of Relation Algebra, Projection is Also Specified. ⭐
* R⨝S -> No condition specified -> Natural Join
* It is Same as Selection Π<sub>A,B,C,D</sub>(σ <sub>R.B = S.B</sub>(RxS))

```
R ⨝ S
 A | B | C | D 
---|---|---|---
 3 | 6 | 2 | 8

- Duplicate Tuple i.e R.B and S.B are Terminated and replaced by single B
```

**Important**

* **What will be Natural Join, if the Two relation have more than two common attributes?**
  * **R(ABC) & S(BCD)** -> B & C common Attributes
  * Equality Condition will be applied on all Common attributes
  * **Natural Join** ->Π<sub>A,B,C,D</sub>(σ <sub>R.B = S.B ∧ R.C=S.C</sub>(RxS))
* **What will be Natural Join, if the Two relation Does not have any common attribute?**
  * **R(ABC) & S(DE)** ->No common Attributes
  * No Attribute -> No Selection Condition -> All tuples of `RxS` will be selected
  * **Natural Join** ->Π<sub>A,B,C,D,E</sub>(RxS)

Note: If there are No common Attribute, then Natural Join is same as **Cross Product**.

2. **Outer Join ->** In outer join tuples that does not satisfy the join condition may also be present

A. **Left Outer Join (⟕):**

* All the tuples of R⨝S, along with all the tuples of **left hand** side relation that failed the join condition.

```
R ⟕ S
| A   | B   | C     | D     |
|-----|-----|-------|-------|
| 3   | 6   | 2     | 8     |
| 2   | 4   | NULL  | NULL  |
```

B. **Right Outer Join(⟖):**

* All the tuples of R⨝S, along with all the tuples of **right hand** side relation that failed the join condition.

```
R ⟖ S
| A     | B     | C     | D     |
|-------|-------|-------|-------|
| 3     | 6     | 2     | 8     |
| NULL  | 1     | 3     | 9     |
| NULL  | 3     | 4     | 8     |
```

C. **Full Outer Join(⟗):**

* All the tuples of R⨝S, along with all the tuples of **both left and right hand** side relation that failed the join condition.

```
R ⟗ S
| A     | B     | C     | D     |
|-------|-------|-------|-------|
| 3     | 6     | 2     | 8     |
| 2     | 4     | Null  | Null  |
| NULL  | 1     | 3     | 9     |
| NULL  | 3     | 4     | 8     |
```

**Important:** Full Outer Join is the Super set of Left and Right Outer Join ⭐

***

[5:51:00](https://youtu.be/k6rDS0qQiO0?t=28262) ✅

### Lossless Natural Join

**Lossless Natural Join** R decomposed into R1 and R2, this decomposition is lossless join decomposition if and only if

1. Attribute of R1 ∪ Attribute of R2 = Attribute of R

```
R1(ABC) ∪ R2(CDE) = R(ABCDE) ✅ lossless  
R1(ABC) ∪ R2(CDE) = R(ABCDEF) ❌ not lossless
```

2. Attribute of R1 ∩ Attribute of R2 ≠ ∅

```
R1(ABC) ∩ R2(CDE) = R(C) ✅ lossless
R1(ABC) ∩ R2(DE) = ∅ ❌ not lossless  
```

3. Attribute of R1 ∩ Attribute of R2 is a candidate key of at least one of R1 or R2

```
Attr(R1) ∩ Attr(R2) ⊇ some candidate key of R1 or R2 ✅ lossless
or
Common attribute must be S.K of at least one R1 & R2 ✅ lossless
```

**Note:** When no common attribute between R1 and R2, natural join behaves like **cross product** and cross product is always ❌ **not lossless** ⭐

**Table 1**

```
R
| A     | B     | C     | 
|-------|-------|-------|
| 1     | 1     | 2     |
| 2     | 1     | 3     |
| 3     | 2     | 4     |
```

**1.1 Common Attribute A:** Let R decomposed into R1(AB) and R2 (BC).

```
Decomposition:

R1                      R2
| A     | B     |     | B     | C     | 
|-------|-------|     |-------|-------|
| 1     | 1     |     | 1     | 2     |
| 2     | 1     |     | 1     | 3     |
| 3     | 2     |     | 2     | 4     |
```

```
Composition:

     R1 ⨝ R2 
| A     | B     | C     | 
|-------|-------|-------|
| 1     | 1     | 2     | ✅
| 1     | 1     | 3     | ➡ Extra (spurious tuples)
| 2     | 1     | 2     | ➡ Extra (spurious tuples)
| 2     | 1     | 3     | ✅
| 3     | 2     | 4     | ✅

R1⨝R2 ⊃ R
   ⬇
Lossy Join
```

* (Common attribute = B) + (Values are not unique in any relation) -> Lossy

**1.2 Common Attribute A:** Let R decomposed into R1(AB) and R2 (BC).

```
Decomposition :

R1                      R2
| A     | B     |     | A     | C     | 
|-------|-------|     |-------|-------|
| 1     | 1     |     | 1     | 2     |
| 2     | 1     |     | 2     | 3     |
| 3     | 2     |     | 3     | 4     |
```

```
Composition :
      
      R1 ⨝ R2
R
| A     | B     | C     | 
|-------|-------|-------|
| 1     | 1     | 2     |
| 2     | 1     | 3     |
| 3     | 2     | 4     |

R1⨝R2 = R
   ⬇
Lossless Join decomposition
```

* (Common attribute = A) + (Values of A are unique in both relation) -> Lossless

What If Tables value is Changed and Decomposition with Common attribute B??

**Table 2**

```
R
| A     | B     | C     | 
|-------|-------|-------|
| 1     | 1     | 2     |
| 2     | 1     | 3    <- changed value
| 3     | 2     | 4     |
```

**2.1 Common Attribute B:** Let R decomposed into R1(AB) and R2 (BC).

```
Decomposition :

R1                      R2
| A     | B     |     | B     | C     | 
|-------|-------|     |-------|-------|
| 1     | 1     |     | 1     | 2     |
| 2     | 1     |     | 2     | 4     |
| 3     | 2     | 
```

```
Composition :
      
      R1 ⨝ R2
R
| A     | B     | C     | 
|-------|-------|-------|
| 1     | 1     | 2     |
| 2     | 1     | 3     |
| 3     | 2     | 4     |

R1⨝R2 = R
   ⬇
Lossless Join decomposition
```

* (Common attribute = B) + (Values of B are not unique in R1 but Unique in R2 relation) -> Lossless

Value of **Common Attribute** is Unique in at least one relation -> Lossless Join ⭐

**Important Note about Natural Join**

1. Natural Join is Commutative. R1⨝R2 = R2⨝R1 (tuple wise)
2. Natural Join is associative R1⨝(R2⨝R3) = (R1⨝R2)⨝R3

**Question Practices**

[8:49:00](https://youtu.be/k6rDS0qQiO0) ✅

**Ques: Check whether the decomposition of the relation is lossy or lossless**

```
R (A B C D E F)

F = { AB -> C, BC->A, AC->B, B->D, AD->E, E->F}

D = {R1(ABC), R2(ABDE), R3(EF)}
```

If there is any way that can join so,

**Solution:**

```
Step 1 : R1 ⨝ R2  
- A ∩ B => AB
- (AB)+ = {A, B, C, D, D, E, F} -> S.K of both -> we can join
- R1 ⨝ R2 = (ABCDE)

Step 2 : ABCDE ⨝ R3
- ABCDE ∩ R3
- (E)+ = {E,F} -> S.K of R3 -> We can join
- (R1 ⨝ R2) ⨝ R3 = (ABCDEF) : 

✅ Lossless Join
```

Joining in Incorrect Way (Lossy):

```
(R1 ⨝ R2) ⨝ R3 way

R1      R2
  ⬊ ∩ ⬋
    = ∅       R3
      ⬊  ∩  ⬋
         = ∅

❌ Lossy Join
```

\*\*Note: \*\* Since **natural join is commutative and associative**, **some join order** leads to a **lossless join**.

**If there exists any order in which relation can be joined such that join is lossless at every point of join, then overall decomposition is Lossless Join decomposition**

***

[9:06:00](https://youtu.be/k6rDS0qQiO0?t=32797) ✅

**Division**

**Example 1: Retrieve Sid of Students who enrolled for all courses**

```
  Enroll
| Sid| Cid| Fee |
|----|----|-----|
| S1 | C1 | 500 |
| S1 | C2 | 700 |
| S2 | C2 | 500 |
| S3 | C2 | 700 |
| S1 | C3 | 400 |
| S3 | C3 | 300 |

 Course
| Cid| Name|
|----|-----|
| C1 | OS  |
| C2 | DBMS|
| C3 | OS  |
```

We are looking for `Sid`s in the `Enroll` table that are associated with all `Cids of Course table`

```
Important Attributes
In Enroll -> Sid & Cid
In Course -> Cid
```

Ans: **Π**<sub>**Sid,Cid**</sub>**(Enroll) ÷ Π**<sub>**Cid**</sub>**(Course)**

**Derivation:** ⭐

Step 1:

```
	ΠSid(Enroll)   X    ΠCid(Course)
	   ↓                            ↓ 
	  Sid          ⬇           Cid
	  ----                     ----
	  S1        Sid|Cid        C1
	  S2       ----|----       C2
	  S3        S1 | C1        C3				
    		    S1 | C2
			    S1 | C3
			    S2 | C1
			    S2 | C2
				S2 | C3
				S3 | C1
				S3 | C2
				S3 | C3
				   ↑ 
			Universal Relation

```

Step 2:

```
(ΠSid(Enroll) X ΠCid(Course)) -  ΠSid,Cid(Enroll)
                                
      Sid|Cid             ⬋        Sid|Cid
     ----|----                    ----|----
      S1 | C1        Sid|Cid       S1 | C1
      S1 | C2       ----|----      S1 | C2
      S1 | C3        S2 | C1       S2 | C2
      S2 | C1        S2 | C3       S3 | C2
      S2 | C2        S3 | C1       S1 | C3
	  S2 | C3                      S3 | C3
	  S3 | C1          ↑              ↑    
	  S3 | C2    It contains Sid    Sid Enrolled
	  S3 | C3	 of the students      for the Cid
	             who did not enroll
	             for some course
	             along with Cids

```

Step 3:

```
ΠSid[ΠSid(Enroll) X ΠCid(Course)) -  ΠSid,Cid(Enroll)]
↓
Sid
---
S1        ← Sid of Students who did not enroll for at least one course
S3


```

Step 4:

```
ΠSid(Enroll) - ΠSid[ΠSid(Enroll) X ΠCid(Course)) -  ΠSid,Cid(Enroll)]
   ↓         ⬊
  Sid        Sid
  ---        ----
   S1         S1 ← Sid of Students enrolled for all the courses ✅
   S2
   S3
	↑
	Sid of Students who
	enrolled for some courses
```

* **Π**<sub>**Sid, Cid**</sub>**(Enroll) ÷ Π**<sub>**Cid**</sub>**(Course)** = Π<sub>Sid</sub>(Enroll) - Π<sub>Sid</sub>(Π<sub>Sid</sub>(Enroll) × Π<sub>Cid</sub>(Course) - Π<sub>Sid, Cid</sub>(Enroll))

**Example 2: Retrieve the values of A & B from relation R that are associated with all values of C in relation S**

```
R(ABC)  S(C,D)
```

**Ans:** R ÷ Π<sub>C</sub>(S) or Π<sub>ABC</sub>(R) ÷ Π<sub>C</sub>(S)

***

[9:33:00](https://youtu.be/k6rDS0qQiO0?t=34365) to \[10:07:00] Remaining

**Consider the Following Relation :-** Supplier (Sid, Sname, Rating) Parts(Pid, Pname, Color) Catalog (Sid, Pid, Cost)

Let there are `Sid - S1, S2, S3, S4....` & `Pid - P1, P2, P3, P4`

Let S4 Never Supply a Part

```
Catalog 
(Sid, Pid, Cost)
S4   NULL NULL ❌
```

Let P4 is never supplied

```
Catalog 
(Sid, Pid, Cost)
NULL  P4  NULL ❌
```

Note: `Sid` & `Pid` Can't be NULL. So Information such as `A supplier that not supply and parts`, or `Parts that never supplied by any supplier`. would never be stored in Catalog Table

**Ques. Retrieve `Sid` of supplies who have not supplied some Red Color Parts**

```
Catalog    Parts

Sid Pid     Pid >> Color
S1  P1      P1   Red
S1  P2      P2   Green
S2  P2      P3   Red
S2  P3   
```

`Sid` is in Catalog and `Color` is in Parts Table. So we need to compare two tables So we need to join (Cross Product) the Table

**Ans:** -> Π<sub>Catalog.Sid</sub>( σ<sub>Catalog.Pid=Parts.Pid ∧ Parts.color='Red'</sub> (Catalog X Parts) ) or -> Π<sub>C.Sid</sub>( σ<sub>C.Color='Red'</sub>(σ<sub>C.Pid=P.Pid</sub> (Catalog(C) X Parts(P))) ) or -> Π<sub>Sid</sub>( σ<sub>C.Color='Red'</sub>(Catalog ⨝ Parts )) or -> Π<sub>Sid</sub>(Catalog ⨝ (σ<sub>C.Color='Red' )</sub>(Parts)) ---> Efficient Query

**Ques. Retrieve `Sid` of supplies who have supplied at least three parts**

```
  Catalog

Sid Pid Cost
S1  P1    
S1  P2    
S2  P2    
S1  P3
S3  P3
```

**Ans:** -> Π<sub>C1.sid</sub>( σ <sub>C1.Sid=C2.Sid ∧ C2.Sid=C3.Sid ∧ C1.Sid = C3.Sid ∧ C1.Pid!=C2.Pid ∧ C2.Pid!=C3.Pid ∧ C1.id!=C3.Pid</sub> (ρ<sub>C1</sub><sup>(Catalog)</sup> X ρ<sub>C2</sub><sup>(Catalog)</sup> X ρ<sub>C3</sub><sup>(Catalog)</sup>))

(C1.Sid = C3.Sid -> Optional)

-> Π<sub>C1.sid</sub>(σ <sub>C1.Sid=C2.Sid ∧ C2.Sid=C3.Sid ∧ C1.Pid!=C2.Pid ∧ C2.Pid!=C3.Pid ∧ C1.id!=C3.Pid</sub>(ρ<sub>C1</sub><sup>(Catalog)</sup> X ρ<sub>C2</sub><sup>(Catalog)</sup> X ρ<sub>C3</sub><sup>(Catalog)</sup>))

**Homework: Retrieve `Sids` of supplies who have supplied some parts at maximum cost**

***

[10:07:00](https://youtu.be/k6rDS0qQiO0?t=36464) ✅

### SQL

* SQL is Non Procedural
* SQL focus on syntax

```
                    Commands in SQL

DDL          DML          DCL          TCL         DQL
 ⬇            ⬇            ⬇            ⬇           ⬇
Create      Insert       Grant       Commit     Select
DROP        Delete       Revoke      Rollbak
Alter       Truncate* 
```

Note:

* Truncate is Considered under DDL in Most of the sources (but here considered under DML)
* **Predefined keywords** (e.g., `HAVING`, `GROUP BY`, `SELECT`, `MAX()`) are **case-insensitive**.
* **User-defined identifiers** (e.g., table names, column names) are **case-sensitive** in some

#### DDL

**CREATE**

```sql
CREATE newTableName
	( Attr1   dataType   constraint,
	  Attr2   dataType   constraint,
	    .        .            .   
	    .        .            .     );
```

**DROP** : It deletes complete table **ALTER** : It is used to **add** a new Column or **Drop** existing Column

Note: DDL is not asked in GATE Exam.

#### DML

**INSERT**

```sql
INSERT INTO tableName
	( values (..., ..., ...),
	  values (..., ..., ...),
	  values (..., ..., ...), );
```

**DELETE**

```sql
DELETE from tableName
	WHERE (condition)
```

**UPDATE**

```sql
UPDATE tableName
	Set marks=marks+5 -- Statement for Update
```

#### DQL

**Syntax of SQL query using basic SQL Clauses**

**1. SELECT** ≡ Π<sub>A₁,A₂,...Aₘ</sub> (Projection)

```sql
SELECT distinct A₁, A₂,...Aₘ --List of Attributes
```

* distinct (optional) : Without it SQL May produce duplicate tuples

**2. FROM** ≡ R₁ x R₂ x Rₘ

```sql
FROM R₁, R₂,...Rₘ -- Relation required for execution of query
```

**3. WHERE** ≡ σ<sub>(condition)</sub>

```sql
WHERE (Condtition) -- Where Condition will be applied on each tuple
```

**4. GROUP BY**

```sql
GROUP BY (Attributes) -- Used to group the result of where clause based on attribute
```

* Without Group by Clause, Result will be considered as Single Group

**5. HAVING**

```sql
HAVING (Condition) -- Having Condition will be applied on each group
```

* Work even Grouping (Group by) not done

Note:

* Group by & Having Does not have Equivalent Basic Relational Operation
* DQL is Important for Gate EXAM

**Basic Clauses of SQL (With Execute Order)**

```sql
1. From
2. Where -- optional (without it All tuple selected)
3. Group by -- optional (wihtout it All tuples are in single group)
4. Having -- optional + Can also work without group by
5. Select
```

**Aggregate Function**

**Five Function**

```mysql
1. Count()
2. Sum()
3. Avg()
4. Max()
5. Min()
```

**Examples Table 1**

```
            Student
| Sid  | Sname | Marks | Branch |
|------|-------|-------|--------|
| S1   | A     | 20    | EC     |
| S2   | A     | 40    | CS     |
| S3   | B     | NULL  | IT     |
| S4   | A     | 60    | CS     |
| S5   | C     | 40    | EC     |
| S6   | B     | 60    | IT     |
| NULL | NULL  | NULL  | NULL   |
```

**Count**

```sql
Count(*) -- It result the total no. of tuples. 
```

* `*` : Means **Everything**
* `Count(*)` : also count **Empty Tuples** (i.e. the tuple in which values are NULL)

```sql
Count(Attribute) -- Number of non-Null values in the column Specified
```

```sql
Count(distinct Attribute) -- Number of non-Null disticnct values in the column Specified
```

Note:

* NULL is a non-zero unknown value
* No two NULL are equal
* NULL values are discarded by aggregate function { Except for `Count(*)` }
* Algebraic operation with NULL results NULL e.g. NULL + 100 = NULL
* Count(), Sum() etc. Operation with Null and Non-NULL Value in A tuple Not Result in NULL. Aggregate function Discard NULL Values before Operation

Note: Column and Table Names are Case sensitive

**Count() Example**

```sql
Count(*) = 7
Count(Sid) = 6
Count(distinct Sid) = 6
Count(Marks) = 5
Count(distinct Marks) = 3
```

**Sum() Example**

```sql
Sum(Marks) = 220
Sum(distinct Marks) = 120
```

**Avg() Example**

```sql
Avg(Marks) = 44 -- Sum(Marks)/Count(Marks) == 220/5
Avg(distinct Marks) = 40 -- Sum(distinct Marks)/Count(disctinct Marks) = 120/3
```

**Max() & Min() Example**

```sql
Max (Marks) = 60
Max (distinct Marks) = 60  
Min (Marks) = 20
Min (distinct Marks) = 20 

-- No use of distinct in Max() and Min()
```

**WHERE**

**Example Table 2**

```
	            Student
	| Sid  | Sname | Marks | Branch |
	|------|-------|-------|--------|
	| S1   | A     | 20    | CS     |
	| S2   | C     | 40    | IT     |
	| S3   | B     | NULL  | EC     |
	| S4   | A     | 60    | IT     |
	| S5   | B     | 40    | CS     |
	| S6   | A     | 60    | EC     |
```

```mysql
SELECT *
	FROM Student
		WHERE (Marks > 40)
```

```
Output:

| Sid  | Sname | Marks | Branch |
|------|-------|-------|--------|
| S4   | A     | 60    | IT     |
| S6   | A     | 60    | EC     |
```

Result

* We Don't Know whether the tuple `S3 B NULL EC` will be selected or not. (Depends if NULL is Greater then 40 or not)
* `S4 A 60 IT` & `S6 A 60 EC` tuples are guaranteed to be present in O/P

````sql
SELECT Sid
	FROM Student
		Where Marks between 20 AND 40```
````

Output:

| Sid |
| --- |
| S1  |
| S2  |
| S5  |

````

Result
- Between means both 20 & 40 also included
-  We Don't Know whether the Sid `S3` will be selected or not. (Depends if NULL is <= 40 and >=20)
- `S1`, `S2` and `S5` Sid are guaranteed to be present in O/P

Note: `Where (Attribute > X )` , then the NULL Attribute value will be compared too.


##### GROUP BY

##### **Ques.** Retrieve names of All branches along with Max marks in the branch

```sql
SELECT Branch, Max(Marks)
	From Student
````

❌ This Is Invalid Query

Note: ⭐ Very Very Important

* This is invalid Because `Branch` Attribute is Not Present in Group By Clause. (i.e. Output is Not Grouped by Branch Attribute). `Max()` will work on All attributes as a Single Group. So `Select Max()` Will result in one tuple output, While `Select Branch` Will result in All tuples output. So it is not possible
* In `Select` Clause ,if you specify some attribute (`Branch`) along with some aggregate function (`Max()`) then the Attribute (`Branch`) Should be Present in `Group by` Clause too. (Converse is not true i.e. If some attribute is present in `Group By` then it is not necessary to include in `Select` Clause)

```sql
SELECT Branch, Max(Marks)
	From Student
		Group by (Branch)
```

This is the correct Query ✅

```
Output:

| Branch | Max(Marks) |
|--------|------------|
| CS     | 40         |
| IT     | 60         |
| EC     | 60         |
```

* No having condition, so each group is selected

Note : ⭐

* If Branch Has `NULL`, then Corresponding to Each `NULL` there will be a separate group. (Because no two NULLs are equal)

**HAVING**

**Ques.: Retrieve Branch names with average marks more than 40**

```mysql
SELECT Branch
	FROM Student
		Group by (Branch)
			Having(Avg(Marks)>40)
```

```
Output:

| Branch |
|--------|
| IT     |
| EC     |
```

Note:

* CS Average Marks are 30 i.e. not more than 40, so this group is not selected.
* In Average Marks of EC Group NULL & 60 , NULL is Discarded and so Average is 60/1 = 60

**Nested Query / Sub-Query**

**Types of Nested/Sub Query**

* **Independent Query** -> When Inner query can be executed Independently
* **Correlated** -> Attribute cannot be executed Independently and Specify Relation by Outer Query

Important ⭐ : Correlated Subquery Question is Very Very Important for Gate exam

**Ques. Write Query to Retrieve Sids of Students who scored maximum marks, from the above student table**

```mysql
SELECT  Sid
	FROM Student
		WHERE (Marks = Max(Marks))
```

❌ This Is Invalid Query

**Solution:**

```
Output:

| Sid |
|-----|
| S4  |
| S5  |
```

Note: Aggregate Function (`Max()`) Can't be used Directly within the `Where` Condition

```mysql
-- ↓ Outer Query (Main Query)
SELECT  Sid
	FROM Student
		WHERE (Marks = SELECT Max(Marks) FROM Student)
		               -- ↑ Inner Query (Sub-query)
```

This is the correct Query ✅

**Order of Execution w.r.t independent Sub-query**

* Inner query will be Executed first -> Operation of Inner query will be used to execute outer query
* Let the Independent Subquery

```mysql
SELECT  Sid
	FROM Student
		WHERE (Marks = SELECT Max(Marks) FROM Student)
		            -- ↑ Independent Subquery
```

```
Step 1: Inner Query
(SELECT Max(Marks) FROM Student)

| Max(Marks) |
|------------|
|    60      |


Step 2: SELECT  Sid FROM Student Where Marks = 60

| Sid |
|-----|
| S4  |
| S5  |

✅
```

**Order of Execution w.r.t Correlated Sub-query** ⭐

* Inner query will be Executed first -> Operation of Inner query will be used to execute outer query
* Let the Correlated Subquery

```mysql
Select * 
  From R           -- ↓ Correlated Subquery
	Where operator(SELECT * 
				    from S 
					  Where (R.A = S.B))			  
```

```
Outer Query               Inner Query
(Select * From R)        (Select * From S)

  R                          S
| . | A |                 | . | B |
|---|---|                 |---|---|
|   |   |                 |   |   | 
|   |   |                 |   |   |


operator (SELECT .....)
   ↓
  this operator will produce True or False

If True -> Then where condition true
If False -> Then where condition false
```
