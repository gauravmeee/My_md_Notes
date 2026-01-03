# Software Engineering

| Topics                | Subtopics               |
| --------------------- | ----------------------- |
| Development Process   | SDLC models             |
| Requirement Gathering | SRS, analysis           |
| System Design         | Principles and patterns |
| Testing & Quality     | Unit, integration, QA   |
| Project Management    | Estimation, scheduling  |
# Introduction to Analytics Engines like Spark, Hadoop MapReduce etc.

## Definition

Analytics engines are distributed computing frameworks designed to **store, process, and analyze massive datasets** efficiently across clusters of machines.  
They provide the backbone for **Big Data analytics** by enabling scalable, parallel, and fault-tolerant computation.

---

## 1. Hadoop MapReduce

### Overview

A programming model and processing engine for large-scale data analysis in the **Hadoop ecosystem**.  
Processes data in **batch mode** using the **Map** and **Reduce** functions over distributed nodes.

### Architecture

- **HDFS (Hadoop Distributed File System):** Storage layer that splits data into blocks and distributes them across nodes.
    
- **YARN (Yet Another Resource Negotiator):** Resource management and job scheduling layer.
    
- **MapReduce Engine:** Computation layer for parallel data processing.
    

### Working

1. **Map Phase:** Input data is split and processed into key-value pairs.
    
2. **Shuffle and Sort:** Intermediate data grouped by keys.
    
3. **Reduce Phase:** Aggregates or summarizes values with the same key.
    

### Pros

- Scalable, reliable, fault-tolerant
    
- Handles huge datasets on commodity hardware
    

### Cons

- High latency (batch-only)
    
- Inefficient for iterative or real-time tasks
    

---

## 2. Apache Spark

### Overview

Fast, in-memory, distributed data processing engine for **batch and stream analytics**.  
Provides APIs in **Scala, Python, Java, R**.

### Core Components

1. **Spark Core:** Task scheduling, memory management, fault recovery
    
2. **Spark SQL:** Querying structured data using SQL/DataFrames
    
3. **Spark Streaming:** Real-time stream processing
    
4. **MLlib:** Machine learning library for scalable algorithms
    
5. **GraphX:** Graph computation and analytics
    

### Advantages over MapReduce

- In-memory computation (much faster)
    
- Supports iterative algorithms and streaming
    
- Unified engine for batch, streaming, and ML workloads
    

### Execution Model

- Data represented as **RDDs (Resilient Distributed Datasets)**
    
- Supports lazy evaluation and fault tolerance through lineage
    

---

## 3. Other Analytics Engines

### **Apache Flink**

- Stream-first engine for real-time, low-latency analytics
    
- Handles both batch and event-driven processing
    

### **Apache Storm**

- Real-time stream processing system
    
- Suitable for continuous event analytics and monitoring
    

### **Presto / Trino**

- Distributed SQL query engine for interactive analytics on large datasets
    

### **Apache Hive**

- SQL-like querying over Hadoop, converts queries to MapReduce or Spark jobs
    

---

## Comparison

|Feature|Hadoop MapReduce|Apache Spark|Apache Flink|
|---|---|---|---|
|Processing Type|Batch|Batch + Stream|Stream-first|
|Speed|Slow (disk-based)|Fast (in-memory)|Real-time|
|Ease of Use|Complex|Simple APIs|Moderate|
|ML Support|External (Mahout)|Built-in (MLlib)|Limited|

---

### Objective

Enable **large-scale, parallel, and fault-tolerant analytics** on massive datasets by providing scalable computation frameworks that power modern Big Data ecosystems.


---
---


# Software Requirement Gathering

**Definition:**  
Process of collecting and defining what the software must do and the constraints under which it must operate.

**Objectives:**

- Understand user needs and expectations
    
- Define functional and non-functional requirements clearly
    
- Avoid ambiguity, inconsistency, and incompleteness
    

**Types of Requirements:**

1. **Functional Requirements:** Describe what the system should do (features, operations, inputs/outputs).
    
2. **Non-Functional Requirements:** Define system attributes like performance, reliability, scalability, and security.
    
3. **Domain Requirements:** Specific to the industry or environment in which software will operate.
    

**Requirement Gathering Techniques:**

1. **Interviews:** One-to-one discussions with stakeholders.
    
2. **Questionnaires/Surveys:** Useful for large user groups.
    
3. **Brainstorming:** Collective idea generation from stakeholders and experts.
    
4. **Workshops:** Interactive sessions to resolve conflicts and finalize priorities.
    
5. **Observation:** Studying users’ actual work environment.
    
6. **Document Analysis:** Reviewing existing system documents and reports.
    
7. **Prototyping:** Building a working model to clarify unclear requirements.
    

**Outputs of Requirement Gathering:**

- **SRS (Software Requirement Specification):** Formal document containing all requirements.
    
- **Use Cases / User Stories:** Describe user interactions with the system.
    
- **Requirement Traceability Matrix (RTM):** Maps each requirement to its corresponding design and test cases.
    

**Key Qualities of Good Requirements:**

- Complete, Consistent, Unambiguous, Verifiable, and Feasible


---
---

# System Design Principles

**Definition:**  
System design defines the architecture, components, interfaces, and data for a system to satisfy specified requirements. Design principles ensure software is scalable, maintainable, and efficient.

**Major Design Principles:**

1. **Modularity:**  
    System is divided into smaller independent modules for easier development and maintenance.
    
2. **Abstraction:**  
    Hides implementation details; focuses on what a module does, not how.
    
3. **Encapsulation:**  
    Bundles data and related operations; protects data from unauthorized access.
    
4. **Separation of Concerns:**  
    Each module handles a specific functionality or responsibility.
    
5. **Cohesion:**  
    Measures how strongly related the functions within a module are.
    
    - _High Cohesion_ is desirable.
        
6. **Coupling:**  
    Measures interdependence among modules.
    
    - _Low Coupling_ is desirable.
        
7. **Information Hiding:**  
    Internal details of modules are hidden; only necessary interfaces are exposed.
    
8. **Reusability:**  
    Design components to be reusable across different systems.
    
9. **Scalability:**  
    System should handle increased workload or data without performance degradation.
    
10. **Flexibility & Maintainability:**  
    Design should allow easy updates, enhancements, and error corrections.
    
11. **Fault Tolerance:**  
    System should continue to operate correctly even in presence of faults.
    

**Design Levels:**

- **High-Level Design (HLD):** Defines system architecture, modules, and their relationships.
    
- **Low-Level Design (LLD):** Specifies logic of individual components, algorithms, and data structures.

---
---


# Software Testing and Quality Management

**Definition:**  
Software Testing is the process of evaluating software to ensure it meets specified requirements and is defect-free.  
Quality Management ensures that software development and maintenance processes produce high-quality products.

**Objectives:**

- Detect defects early
    
- Ensure software reliability, performance, and correctness
    
- Validate that system meets user expectations
    

**Levels of Testing:**

1. **Unit Testing:** Tests individual components or modules.
    
2. **Integration Testing:** Tests interactions between integrated modules.
    
3. **System Testing:** Tests the complete system as a whole.
    
4. **Acceptance Testing:** Conducted by users to verify the system meets business needs.
    

**Types of Testing:**

- **Functional Testing:** Verifies functionalities as per requirements.
    
- **Non-Functional Testing:** Checks performance, usability, reliability, security, etc.
    
- **Regression Testing:** Ensures new changes don’t affect existing functionality.
    
- **Smoke Testing:** Initial quick testing to check basic stability.
    
- **Alpha & Beta Testing:** Pre-release testing by internal users and real users respectively.
    

**Software Quality Management (SQM):**  
Ensures that software processes and products conform to defined quality standards.

**Components of SQM:**

1. **Quality Assurance (QA):** Process-oriented; ensures standards and procedures are followed.
    
2. **Quality Control (QC):** Product-oriented; identifies defects in the final product.
    
3. **Quality Planning:** Defines quality goals, metrics, and required activities.
    

**Quality Standards and Models:**

- **ISO 9001:** Focuses on quality management systems.
    
- **CMMI (Capability Maturity Model Integration):** Measures process maturity levels.
    
- **Six Sigma:** Reduces defects through statistical analysis.
    

**Key Metrics:**

- Defect density
    
- Mean Time to Failure (MTTF)
    
- Test coverage
    
- Customer satisfaction index

---
---


# Software Project Management

**Definition:**  
Application of knowledge, skills, tools, and techniques to plan, execute, and control software projects to meet requirements within time, cost, and quality constraints.

**Objectives:**

- Deliver software on schedule and within budget
    
- Ensure desired quality and performance
    
- Manage risks, resources, and communication effectively
    

**Main Activities:**

1. **Project Planning:**
    
    - Define scope, objectives, and deliverables
        
    - Estimate effort, cost, and schedule
        
    - Identify risks and prepare mitigation plans
        
2. **Project Scheduling:**
    
    - Create work breakdown structure (WBS)
        
    - Use tools like Gantt Charts, PERT, and CPM for task sequencing and time estimation
        
3. **Resource Management:**
    
    - Allocate human, financial, and technical resources efficiently
        
4. **Risk Management:**
    
    - Identify, analyze, and control potential project risks
        
5. **Project Execution and Monitoring:**
    
    - Track progress using metrics like effort variance, cost variance, and schedule variance
        
    - Apply Earned Value Analysis (EVA)
        
6. **Project Closure:**
    
    - Final deliverables, documentation, evaluation, and lessons learned
        

**Project Estimation Techniques:**

- **Algorithmic Models:** COCOMO (Constructive Cost Model)
    
- **Expert Judgment:** Based on experience
    
- **Delphi Technique:** Consensus-based estimation among experts
    
- **Function Point Analysis (FPA):** Based on system functionality
    

**Project Management Tools:**  
MS Project, JIRA, Trello, Asana

**Software Project Manager Responsibilities:**

- Planning and scheduling
    
- Team coordination
    
- Progress tracking and reporting
    
- Ensuring quality and stakeholder satisfaction

