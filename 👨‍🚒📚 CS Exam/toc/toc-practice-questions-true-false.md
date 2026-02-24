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

# TOC Practice Questions True/False

### True / False

##### **Ques.** For every **Non-Deterministic Turing Machine (NTM)**, there exists an **equivalent Deterministic Turing Machine (DTM)**. -> True ✅

**Meaning of Equivalent** : Equivalent ⇒ both machines **recognize the same language** (and decide it, if the NTM is a decider).

**Key Idea**

- NTM may have **multiple possible moves** from a configuration
- DTM has **exactly one move**
- DTM simulates **all possible computation branches** of the NTM **systematically**

**How DTM Simulates NTM**

- View NTM computation as a **computation tree**
- Each path = one possible sequence of choices
- DTM performs **Breadth-First Search (BFS)** on this tree
- ==BFS is crucial to avoid getting stuck in an infinite branch==

**Simulation Steps**

- Start from initial configuration
- Enumerate all possible transitions
- Simulate 1 step of every branch
- Then 2 steps of every branch, and so on
- If **any branch accepts**, DTM accepts

**Why BFS, not DFS**

- ==DFS may follow an infinite non-accepting branch==
- BFS guarantees that if an accepting branch exists, it is eventually found

**Case 1: NTM is a Recognizer**

- If input ∈ L → at least one branch accepts → DTM eventually finds it
- If input ∉ L → no branch accepts → DTM may run forever
- Hence, DTM is also a **recognizer**

**Case 2: NTM is a Decider**

- All branches halt
- Computation tree is **finite**
- DTM explores entire tree and halts
- Hence, DTM is also a **decider**

**Conclusion**

- NTM and DTM have **same computational power**
- Nondeterminism does **not** increase language recognition power
- Difference is only in **time complexity**, not computability

**One-line exam answer**

> Every nondeterministic Turing machine can be simulated by a deterministic Turing machine by systematically exploring all computation branches using breadth-first search, hence recognizing the same language.

##### **Ques.** Regular languages are closed under infinite union** -> ❌ **FALSE\*\*

**Counterexample**

- Define: `Lₙ = {0ⁿ}` → regular (finite language)
- Consider:- `L = ⋃ₙ ≥ 1 Lₙ = {0ⁿ | n ≥ 1}`
- Now modify:
  - `Lₙ = {0ᵖ | p is prime and p ≤ n} `→ regular (finite)
  - `⋃ₙ Lₙ = {0ᵖ | p is prime}` → **not regular**

Thus, infinite union of regular languages **need not be regular**.
