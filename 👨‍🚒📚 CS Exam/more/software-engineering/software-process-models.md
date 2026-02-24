---
description: Software-process-models
icon: list-check
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

# Software-process-models

**Software Process Models** – A software process model is a **structured framework** that defines the **sequence of activities** involved in software development, from requirement analysis to maintenance.

**Why Process Models are Needed**

- Provide disciplined development approach
- Improve project planning and control
- Reduce risk and cost
- Ensure quality and timely delivery

**Major Activities in Any Process Model** ⭐

1. Requirement Analysis
2. System Design
3. Implementation (Coding)
4. Testing
5. Deployment
6. Maintenance

GFG [Software Developments Life Cycle Models (SLDC)](https://www.geeksforgeeks.org/software-engineering/top-8-software-development-models-used-in-industry/)

**Types of Software Process Models ⭐**

**1. Waterfall Model** ⭐

```
Requirement
     ↓
Design
     ↓
Implementation
     ↓
Testing
     ↓
Deployment
     ↓
Maintenance
```

- \==linear and sequential== model
- Each phase must be completed before next starts
- **Phases** : Requirement → Design → Implementation → Testing → Deployment → Maintenance
- **Advantages**
  - Simple and easy to manage
  - Clear documentation
- Disadvantages
  - No flexibility
  - Late testing
  - Not suitable for changing requirements

**2. ==Iterative Waterfall ==Model** ⭐

```
Requirement ↰
     ↓      |
  Design    |
     ↓      |
Implementation
     ↓
 Testing
     ↓
 Deployment
```

- Enhanced waterfall with ==**feedback paths**==
- Allows returning to previous phase
- **Advantages :**
  - \==Error correction== possible
  - Better than classical waterfall
- **Disadvantages :**
  - Still rigid
  - Late delivery of working software

**3. Incremental Model**

```
Req → Design → Code → Test → Release (Inc 1)
Req → Design → Code → Test → Release (Inc 2)
Req → Design → Code → Test → Release (Inc 3)
```

- Software ==developed in **small increments**==
- Each increment adds functionality
- **Advantages**
  - Early delivery
  - Reduced risk
  - Customer feedback possible
- **Disadvantages**
  - Requires good planning
  - Integration issues

**4. Spiral Model**

```
                 Planning
                    ↑
      Evaluation ←           → Risk Analysis
                    ↓
                Engineering
                    ↑
            (Next Spiral Loop)
```

- Risk-driven model
- Combines waterfall and prototyping
- **Each Loop:** Planning → Risk Analysis → Engineering → Evaluation
- **Advantages**
  - Strong risk management
  - Suitable for large systems
- Disadvantages
  - Complex
  - High cost

**5. V-Model**

```
Requirement        Acceptance Testing
     ↓                     ↑
System Design     System Testing
     ↓                     ↑
Architecture      Integration Testing
     ↓                     ↑
Module Design     Unit Testing
     ↓
Coding
```

- Verification and Validation focused
- Each development phase has corresponding test phase
- Advantages
  - Early test planning
  - High reliability
- Disadvantages
  - Inflexible
  - No early prototype

**6. Prototyping Model**

```
Requirement
     ↓
Quick Design
     ↓
Prototype
     ↓
User Evaluation
     ↓
Refined Requirement
     ↓
Final System
```

- Prototype built to understand requirements
- Types
  - Throwaway Prototype
  - Evolutionary Prototype
- Advantages
  - Clarifies requirements
  - User involvement
- Disadvantages
  - Poor documentation risk
  - Prototype mistaken as final product

**7. Agile Model**

```
Plan → Design → Develop → Test → Deploy
  ↑                                ↓
  ←────────── Feedback ────────────
```

- Iterative and incremental
- Focus on customer collaboration
- Principles
  - Working software over documentation
  - Responding to change
- Advantages
  - High adaptability
  - Continuous feedback
- Disadvantages
  - Less documentation
  - Needs experienced team

**8. RAD (Rapid Application Development)**

```
Requirements Planning
        ↓
User Design ↔ Prototyping
        ↓
Construction
        ↓
Cutover (Deployment)
```

- Fast development using reusable components
- Advantages
  - Short development time
  - High productivity
- Disadvantages
  - Not suitable for large systems
  - Requires skilled developers

**9. Big Bang Model**

```
Requirements + Design + Code + Test
               ↓
            Product

```

- No planning
- All resources applied at once
- Advantages
  - Simple
  - Suitable for small projects
- Disadvantages
  - High risk
  - Not scalable

**Comparison (Exam)**

- Waterfall: rigid, document-heavy
- Iterative Waterfall: feedback paths
- Spiral: risk-driven
- Agile: change-driven
- V-Model: testing-centric

#### **One-Line Exam Definitions**

- Waterfall: Linear sequential model
- Spiral: Risk-based iterative model
- Agile: Flexible, customer-driven model
- Incremental: Functionality delivered in parts
