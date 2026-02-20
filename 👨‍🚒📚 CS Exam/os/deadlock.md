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

# Deadlock

#### **DeadLock vs LiveLock**

**Deadlock**

* Processes are **stuck waiting** for each other indefinitely.
* No process makes progress because each holds a resource the other needs.
* **State:** System is frozen.
* **Example:**
  * P1 holds R1, needs R2
  * P2 holds R2, needs R1 → both wait forever.

**Livelock**

* Processes are **not blocked** but keep changing state in response to each other, making **no effective progress**.
* System keeps “spinning” instead of freezing.
* **State:** Active but useless.
* **Example:**
  * Two processes repeatedly release and request the same resources to avoid deadlock, continually restarting.

**Summary Table**

| Feature       | Deadlock                         | Livelock                                         |
| ------------- | -------------------------------- | ------------------------------------------------ |
| Progress      | None (blocked)                   | None (active but futile)                         |
| Process State | Waiting                          | Running                                          |
| Cause         | Circular wait on resources       | Over-aggressive avoidance or mutual interference |
| Resolution    | Break one of deadlock conditions | Add randomness or backoff                        |

**Mnemonic:**\
Deadlock → “stuck still”\
Livelock → “stuck moving”

#### **Deadlock Prevention Schemes using Timestamp**

**1. Wait-Die Scheme**

**Rule:**

```
if T(requester) < T(holder)
    requester waits
else
    requester is killed (aborts)
```

**Meaning:**

* Older process waits for younger one
* Younger process is killed if it requests a resource held by an older process

**Properties:**

* Deadlock-free (no circular wait)
* May cause starvation (young process may repeatedly die)

**2. Wound-Wait Scheme**

**Rule:**

```
if T(requester) < T(holder)
    requester preempts (wounds) holder
else
    requester waits
```

**Meaning:**

* Older process preempts younger one
* Younger process waits for older one

**Properties:**

* Deadlock-free
* May cause starvation of younger processes

***

### 3. Reverse of Wait-Die (Given Scheme)

**Rule:**

```
if T(requester) < T(holder)
    kill requester
else
    wait
```

**Meaning:**

* Older process is killed
* Younger process waits

**Properties:**

* Not deadlock-free (possible waiting cycles)
* Not starvation-free (older process keeps getting killed)

***

### 4. Comparison Table

| Scheme          | Older Process Action | Younger Process Action | Deadlock-Free | Starvation-Free |
| --------------- | -------------------- | ---------------------- | ------------- | --------------- |
| Wait-Die        | Waits                | Dies                   | Yes           | No              |
| Wound-Wait      | Wounds               | Waits                  | Yes           | No              |
| Reverse (Given) | Dies                 | Waits                  | No            | No              |
