---
title: Probability Advance
---

#### Conditional Probability, Law of Total Probability

Probability of event **A given that B has occurred**.

$$\boxed{P(A \mid B) = \frac{P(A \cap B)}{P(B)}, \quad (P(B) > 0)}$$

**Meaning (Intuition)**

- Sample space **shrinks to B**
- We ask: _within B, how often does A occur?_

**Rearranged Forms (Very Useful ⭐)**

- $P(A \cap B) = P(A \mid B).P(B)$
- $P(A \cap B) = P(B \mid A) . P(A)$

If A and B are **independent**:

$$\boxed{P(A \mid B) = P(A)}$$

**Law of Total Probability ⭐⭐**

#### 🔹 Statement

If $A\_1, A\_2, \dots, A\_n$ are **mutually exclusive and exhaustive events**, then for any event B:

$$
P(B) = \sum_{i=1}^{n} P(B \mid A_i)P(A_i)
}$$


**Why this works (Reason)**

- Event B can occur **only through one of the ($A_i$)**
- Break B into disjoint parts:  $B = (B \cap A_1) \cup (B \cap A_2) \cup \dots$

**Diagram View (Mental)**
```
A1 ─┐
A2 ─┼──► B
A3 ─┘
```


##### **Quick Comparison Table**

| Concept                 | Formula                                              | Purpose             |
| ----------------------- | ---------------------------------------------------- | ------------------- |
| Conditional Probability | $P(A\mid B)$                                         | Probability after B |
| Joint Probability       | $P(A\cap B)$)                                        | Both occur          |
| Total Probability       | $\sum P(B\mid A_i)P(A_i)$                            | Find $P(B)$         |
| Bayes’ Theorem          | $\frac{P(B\mid A_i)P(A_i)}{\sum P(B\mid A_k)P(A_k)}$ | Reverse condition   |

**Exam Memory Tricks 🧠**

- **Conditional** → _Restrict sample space_
- **Total probability** → _Weighted sum_
- **Bayes** → _Reverse the condition_
- **Independent?** → conditioning doesn’t change probability

**When to Use What?**

- Given **“given that”** → Conditional probability
- Given **multiple sources/causes** → Total probability
- Asked **cause after effect** → Bayes’ theorem



## **Bayes’ Theorem**


Bayes’ theorem gives the **probability of a cause given an observed event**.

##### **General Form (Multiple Causes)** ⭐

If  $A_1, A_2, \dots, A_n$ are **mutually exclusive and exhaustive events**, then:

$$\boxed{
P(A_i \mid B) =
\frac{P(B \mid A_i)P(A_i)}
{\sum_{k=1}^{n} P(B \mid A_k)P(A_k)}
}  $$


##### **Standard Two-Event Case**

For events AAA and its complement $A'$:

$${ P(B) = P(B \mid A)P(A) + P(B \mid A')P(A') }$$

$$\boxed{
P(A \mid B) =
\frac{P(B \mid A)P(A)}
{P(B \mid A)P(A) + P(B \mid A')P(A')}
}  $$


##### **Why Bayes’ Theorem Works (Intuition)**

Using **Conditional Probability**
	$$P(A \mid B) = \frac{P(A \cap B)}{P(B)}, \quad (P(B) > 0)$$
- But by definition of conditional probability,
		$$P(A \cap B) = P(B \mid A)P(A)$$

- Substitute into the first equation:

$$\boxed{P(A_i \mid B) = \frac{P(B \mid A_i)P(A_i)}{P(B)}}$$

**Using Law of Total Probability**
$$

P(B) = \sum\_{i=1}^{n} P(B \mid A_i)P(A_i)

$$
- Substitute this value of $P(B)$ into Bayes’ formula:

$$\boxed{
P(A_i \mid B) =
\frac{P(B \mid A_i)P(A_i)}
{\sum_{k=1}^{n} P(B \mid A_k)P(A_k)}
}  $$


**Meaning of Each Term**

| Term            | Meaning                                   |
| --------------- | ----------------------------------------- |
| $P(A_i)$        | ==Prior probability== (before seeing $B$) |
| $P(B \mid A_i)$ | ==Likelihood==                            |
| $P(B)$          | Total probability of (B)                  |
| $P(A_i \mid B)$ | ==Posterior probability==                 |

**Posterior ∝ Likelihood × Prior**

**Common GATE Traps**

1. Confusing  $(P(A \mid B))$ with $(P(B \mid A))$
2. Forgetting denominator (total probability)
3. Not checking **mutually exclusive & exhaustive**
4. Using Bayes when **simple conditional probability** is enough
$$
