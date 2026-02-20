---
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

# Pseudocode written in Pascal / Algorithm notation (used in GATE, DAA, proofs).

**`begin ... end`**

Block boundary (same as `{ ... }` in C)

```pascal
begin
   statement1;
   statement2;
end
```

Equivalent C:

```c
{
   statement1;
   statement2;
}
```

#### **`:=`**

Assignment operator (means “store into”)

```pascal
x := 5;
```

Equivalent C:

```c
x = 5;
```

**`Const`**

Declares constants (fixed values)

```pascal
Const dividend = 81;
```

Means value won’t change.

#### **`Var`**

Declares variables

```pascal
Var remainder, quotient : integer;
```

Equivalent C:

```c
int remainder, quotient;
```

#### **`While ... do`**

While loop syntax

```pascal
While (condition) do
begin
   ...
end;
```

Equivalent C:

```c
while(condition){
   ...
}
```

#### **`(* ... *)`**

Comment / Assertion marker (used in proofs)

```pascal
(* loop invariant here *)
```

Not executable, only for explanation.
