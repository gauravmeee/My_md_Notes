Here's the same content restructured for cleaner flow — the diagram above captures the full hierarchy at a glance, so everything below builds on it without repeating it.

---

# Decidable, Semi-Decidable, and Undecidable Problems

## 1. The Core Question

A **decision problem** asks something with a YES/NO answer — "does this DFA accept string w?", "will this TM halt?" The central question in computability theory is: _can a Turing Machine (TM) reliably answer it?_

---

## 2. Decidable (Recursive) Languages

A problem is **decidable** if a TM always halts and gives the correct answer, for every possible input.

| Input        | TM behavior   |
| ------------ | ------------- |
| YES instance | Halt + Accept |
| NO instance  | Halt + Reject |

The key word is _always_. No loops, no maybes.

**Examples:** DFA membership, DFA equivalence, DFA emptiness, CFG membership, FA equivalence.

**Tip:** If the question involves DFAs, PDAs, or CFGs — decidable. If it involves TMs — probably not.

---

## 3. Semi-Decidable (RE / Recursively Enumerable)

A problem is **semi-decidable** if a TM can confirm YES instances but may loop forever on NO instances.

|Input|TM behavior|
|---|---|
|YES instance|Halt + Accept|
|NO instance|Reject _or_ loop forever|

This is "semi" because only _half_ the problem is solved reliably.

**The halting problem** is the canonical example. Simulate M on w:

- If M halts → we see it, output YES.
- If M never halts → simulation runs forever, we never know.

Any question of the form _"does TM M ever do X?"_ has this same shape.

**Alternative names:** Semi-decidable = Partially decidable = Recursively Enumerable (RE) = Turing Recognizable. All the same thing.

**Examples:** Halting problem, TM acceptance (Lᵤ), TM state reachability, Post Correspondence Problem (PCP).

---

## 4. Non-RE Languages

The hardest class. No reliable recognition in either direction.

| Input        | TM behavior      |
| ------------ | ---------------- |
| YES instance | May loop forever |
| NO instance  | May loop forever |

These are typically the **complements** of RE-but-undecidable languages. For example, the complement of HALT — "TM M does _not_ halt on w" — is Non-RE because you can never confirm a NO (infinite non-halting) case.

---

## 5. Relationships and Complement Rules

```
Decidable ⊂ RE ⊂ All Languages
```

Two complement rules follow from this: ⭐

|If...|Then...|
|---|---|
|L and L' are both RE|L is decidable|
|L is RE, L' is not RE|L is undecidable|

The intuition: if you can recognize both YES and NO cases (L and its complement), you can always halt and decide. If only one side is recognizable, you're stuck with semi-decidability at best.

---

## 6. Rice's Theorem

> Every non-trivial property of the _language_ recognized by a TM is undecidable.

"Non-trivial" means not true for all TMs or false for all TMs. So questions like "is the TM's language empty?", "finite?", "equal to Σ*?" — all undecidable.

Rice's theorem is the fastest way to identify undecidable problems on exams.

---

## 7. Quick Classification Guide

**Step 1 — Does it involve only DFAs/PDAs/CFGs?** → Decidable.

**Step 2 — Does it ask "does TM M ever…" or "will TM M halt…"?** → Semi-decidable (simulate and wait for YES).

**Step 3 — Is it a non-trivial property of a TM's language?** → Undecidable by Rice's theorem.

**Step 4 — Is it the complement of a known RE-but-undecidable problem?** → Non-RE.

---

## 8. Summary Table

|Class|YES case|NO case|Always halts?|
|---|---|---|---|
|Decidable|Halt|Halt|Yes|
|Semi-decidable (RE)|Halt|May loop|No|
|Non-RE|May loop|May loop|No|
