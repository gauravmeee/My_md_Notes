---
description: Software Testing
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

# Software Testing

### Introduction

- **Software Testing**: The process of ==executing a program== with the ==intent of finding errors==.
- Ensures software meets requirements, is defect-free, reliable, and fit for use.
- Conducted at different levels of SDLC.

### Objectives of Testing

- ==Detect defects== before delivery.
- Ensure requirements are met.
- ==Increase reliability and quality.==
- Validate functionality, performance, and security.
- Reduce maintenance cost.
- Build user confidence.

## Principles of Testing

1. Testing shows presence of defects, not absence.
2. ==Exhaustive testing is impossible==.
3. Testing should start early (shift-left).
4. Defects cluster in few modules.
5. Pesticide paradox: repeated tests lose effectiveness.
6. ==Testing is context dependent.==
7. ==Absence of errors fallacy: bug-free but useless software still fails.==

### Software Testing Life Cycle (STLC)

1. **Requirement Analysis** – Identify testable requirements.
2. **Test Planning** – Define scope, objectives, resources, risks.
3. **Test Case Development** – Write test cases, test scripts, test data.
4. **Environment Setup** – Hardware, software, network readiness.
5. **Test Execution** – Run test cases, log defects.
6. **Test Closure** – Deliver reports, metrics, lessons learned.

### Levels of Testing ⭐

1. **Unit Testing** ⭐
   - ==Tests individual components (functions, classes).==
   - Usually automated.
   - Done by developers.
2. **Integration Testing** ⭐
   - ==Tests interaction between integrated modules.==
   - Approaches:
     - Big-Bang Integration
     - Top-Down
     - Bottom-Up
     - Sandwich/Hybrid
3. **System Testing**
   - ==Tests complete system as a whole.==
   - Validates functional + non-functional requirements.
4. **Acceptance Testing**
   - ==Done by client/user.==
   - Confirms system meets business needs.
   - Types:
     - ==Alpha Testing== (internal users). ⭐
     - ==Beta Testing== (external users). ⭐

### Types of Testing

**Functional Testing**

- Validates software functions as per requirements.
- Examples: Unit testing, integration, system, UAT, regression, smoke, sanity.

**Non-Functional Testing**

- Checks performance, scalability, security, usability, reliability.
- Examples: Load testing, stress testing, volume testing, compatibility, recovery testing.

**Maintenance Testing**

- After deployment, when software is modified.
- Regression Testing – ensures old functionality works after changes.
- Re-testing – validates fixes of specific defects.

### Two Testing Approaches ⭐

1. **White Box Testing** ==(Structural)== ⭐
   - ==Internal logic tested.==
   - Techniques:
     - Statement Coverage
     - Branch Coverage
     - Path Coverage
     - Loop Testing
2. **Black Box Testing** ==(Functional)== ⭐
   - Ignores internal code, ==focuses on inputs/outputs.==
   - Techniques:
     - Equivalence Partitioning
     - ==Boundary Value Analysis==
     - ==Decision Table Testing==
     - State Transition Testing
3. **Grey Box Testing** ⭐
   - Combines white + black box.
   - Tester has partial knowledge of system.

### Test Documentation

- **Test Plan** – strategy, objectives, resources.
- **Test Case Specification** – input, expected output, actual output.
- **Test Data** – sample inputs for testing.
- **Test Execution Report** – results of test runs.
- **Defect Report** – bug ID, description, severity, status.
- **Test Summary Report** – overall testing status, coverage, pass/fail ratio.

### Automated vs Manual Testing

- **Manual Testing**: Executed by human testers, good for exploratory/ad-hoc testing.
- **Automated Testing**: Uses tools/scripts for regression, load, performance tests.
- **Tools**: Selenium, JUnit, TestNG, QTP, LoadRunner, JMeter.

### Defect Lifecycle (Bug Life Cycle)

1. New → Assigned → Open → Fixed → Retest → Verified → Closed.
2. If not fixed: can be Reopened, Deferred, or Rejected.

### Metrics in Testing

- **Defect Density** = Defects / Size of software.
- **Test Coverage** = (Executed tests / Total tests) × 100.
- **Defect Removal Efficiency (DRE)** = (Defects removed / Total defects) × 100.
- **MTTF (Mean Time to Failure)**.

### Standards for Testing

- **IEEE 829** – Test documentation.
- **ISO/IEC/IEEE 29119** – Software testing standards.
- **ISO/IEC 9126** – Software quality metrics.

### Challenges in Testing

- Limited time and resources.
- Changing requirements.
- Test environment issues.
- Maintaining automation scripts.
- Communication gaps with stakeholders.

### Best Practices

- Start testing early.
- Maintain traceability matrix (requirements ↔ test cases).
- Prioritize test cases by risk and criticality.
- Use automation for regression and performance tests.
- Regular reviews of test cases and plans.
- Continuous testing in DevOps/Agile.
