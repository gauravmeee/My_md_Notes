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

# Macro in C

A **macro** in programming refers to a fragment of code that has been given a name.

It is valid but not recommended to override inbuilt functions due to name collision, and you can't access the default function let . `for` within the program

```
#define for(n) for(int i=0; i<n; i++) ✅
```

Preferred to use different name for macro

```
#define for_up(n) for(int i=0; i<n; i++) ✅
#define for_down(n) for(int i=n-1; i>=0; i--) ✅
```
