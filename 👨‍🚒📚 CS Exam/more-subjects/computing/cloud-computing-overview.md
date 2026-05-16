---
title: Cloud Computing Overview
---

### 1. Introduction to Cloud Computing

**Definition:**  

Cloud Computing is a model for enabling on-demand network access to a shared pool of configurable computing resources (servers, storage, applications, and services) that can be rapidly provisioned and released with minimal management effort or service provider interaction.

**Key Characteristics:**
1. **On-demand self-service:** Users can access computing resources automatically without human intervention.
2. **Broad network access:** Services are accessible over the network via standard mechanisms (e.g., browsers, APIs).
3. **Resource pooling:** Resources are shared among multiple users using multi-tenancy.
4. **Rapid elasticity:** Resources can be scaled up or down quickly according to demand.
5. **Measured service:** Resource usage is monitored, controlled, and billed based on consumption.

**Service Models:**
1. **Infrastructure as a Service (IaaS):** Provides virtualized hardware resources (e.g., AWS EC2, Google Compute Engine).
2. **Platform as a Service (PaaS):** Provides runtime environments and development tools (e.g., Google App Engine, Microsoft Azure).
3. **Software as a Service (SaaS):** Delivers applications over the internet (e.g., Gmail, Salesforce).

**Deployment Models:**
1. **Public Cloud:** Services offered over the internet to the general public (e.g., AWS, Azure).
2. **Private Cloud:** Exclusive cloud infrastructure for a single organization.
3. **Hybrid Cloud:** Combination of public and private clouds for flexibility.
4. **Community Cloud:** Shared by several organizations with common concerns.

**Advantages:**
- Cost-efficient (pay-per-use)
- Scalability and flexibility
- High availability and reliability
- Reduced maintenance effort
- Global accessibility
    

**Disadvantages:**
- Security and privacy concerns
- Dependency on internet connectivity
- Vendor lock-in
- Limited control over infrastructure
    

**Applications:**
- Data storage and backup
- Web hosting and content delivery
- Big data analytics
- Machine learning and AI services
- Software development and testing environments

---

## 2. Architecture & Virtualization

### 2.1 Cloud Architecture

**Definition:**  

Cloud architecture refers to the components and subcomponents required for cloud computing. These components typically consist of a **front-end platform (client side)**, **back-end platform (cloud side)**, a **cloud-based delivery model**, and a **network**.

##### **Core Components of Cloud Architecture**

**1. Front-End (Client Infrastructure)**
- User devices (laptops, smartphones, thin clients)
- Web browsers or cloud applications
- Client-side interfaces and APIs

**2. Back-End (Cloud Infrastructure)**
- Servers (compute resources)
- Storage systems
- Virtual machines
- Databases
- Application services
- Management & security mechanisms

**3. Cloud Delivery Models**
- IaaS
- PaaS
- SaaS

**4. Network**
- Internet connectivity
- VPN
- Load balancers
- Firewalls


##### **Layered Cloud Architecture**

Cloud systems are generally divided into layers:

1. **Physical Layer**
    - Data centers
    - Physical servers
    - Networking hardware
2. **Virtualization Layer**
    - Hypervisors
    - Virtual machine
    - Containers
3. **Service Layer**
    - IaaS, PaaS, SaaS
4. **Application Layer**
    - End-user applications


**Types of Cloud Architecture**

1. **Monolithic Architecture**
    - Single unified application
    - All components tightly coupled
2. **Service-Oriented Architecture (SOA)**
    - Services communicate via APIs
    - Reusable service components
3. **Microservices Architecture**
    - Small, independent services
    - Independently deployable


**Advantages of Cloud Architecture**
- High scalability
- Fault tolerance
- Resource optimization
- Flexibility in deployment
- Cost efficiency

**Challenges**
- Security management
- Network latency
- Complex architecture design
- Compliance requirements

---

## 2.2 Virtualization

**Definition:**  
Virtualization is the technology that enables the creation of virtual versions of physical resources such as servers, storage devices, networks, and operating systems.

It is the **foundation of cloud computing**.

**How Virtualization Works**: A software layer called a **hypervisor** (Virtual Machine Monitor - VMM) sits between the hardware and the operating systems.
It:
- Allocates CPU, memory, and storage
- Creates multiple Virtual Machines (VMs)
- Isolates workloads

##### **Types of Virtualization**

**1. Server Virtualization**
- Multiple VMs on a single physical server
- Improves hardware utilization

**2. Storage Virtualization**
- Combines physical storage from multiple devices into a single logical unit

**3. Network Virtualization**
- Creates virtual networks (VLANs, virtual switches)

**4. Desktop Virtualization**
- Virtual desktops delivered remotely (VDI)

**5. Application Virtualization**
- Applications run in isolated environments

##### **Types of Hypervisors**

**Type 1 (Bare-Metal Hypervisor)**
- Installed directly on hardware
- High performance
- Examples: VMware ESXi, Microsoft Hyper-V

**Type 2 (Hosted Hypervisor)**
- Runs on top of an operating system
- Examples: VirtualBox, VMware Workstation

##### **Virtual Machines (VMs)**

A Virtual Machine consists of:

- Virtual CPU (vCPU)
- Virtual RAM
- Virtual Disk
- Guest Operating System

Each VM operates independently.

##### **Virtualization vs Containerization**

|Aspect|Virtualization|Containerization|
|---|---|---|
|OS|Each VM has its own OS|Share host OS|
|Resource Usage|Higher|Lightweight|
|Startup Time|Slower|Faster|
|Isolation|Strong|Process-level|

**Container Tools:**
- Docker
- Kubernetes

**Benefits of Virtualization**
- Better resource utilization
- Reduced hardware costs
- Isolation and security
- Faster deployment
- Disaster recovery support
    
 **Limitations**
- Performance overhead
- Complex management
- Licensing costs
- Resource contention

---

### 3. Serverless Computing and Microservices

##### **3.1 Serverless Computing:**  

Serverless computing is a cloud execution model where the cloud provider manages the infrastructure, automatically handles scaling, and charges only for actual resource usage.

**Key Features:**
- No server management (fully managed by provider)
- Event-driven execution
- Auto-scaling based on workload
- Pay-per-execution billing

**How it Works:**
- Developer writes and uploads functions (small code units).
- Functions are triggered by events (HTTP requests, file uploads, database updates).
- Cloud provider (e.g., AWS Lambda, Azure Functions, Google Cloud Functions) provisions resources dynamically.
    
**Advantages:**
- Simplified deployment
- Cost-efficient (no idle time billing)
- Automatic scalability
- Faster development and innovation

**Limitations:**
- Cold start latency
- Limited execution time and memory
- Vendor lock-in
- Debugging and monitoring complexity
    
##### **3.2 Microservices Architecture:**  

Microservices architecture decomposes an application into a collection of small, independent services that communicate through APIs.

**Characteristics:**
- Each service performs a single business function
- Services communicate via REST, gRPC, or message queues
- Independently deployable and scalable
- Often containerized (e.g., Docker, Kubernetes)

**Advantages:**
- High scalability and flexibility
- Easier maintenance and updates
- Fault isolation (failure in one service doesn’t crash the whole system)
- Enables use of different technologies per service

**Challenges:**
- Complex inter-service communication
- Difficult debugging and tracing
- Requires advanced DevOps and monitoring tools

##### **3.3 Serverless vs Microservices:**

|Aspect|Serverless|Microservices|
|---|---|---|
|Deployment|Functions triggered by events|Independent services|
|Management|Fully managed by provider|Managed by DevOps team|
|Scalability|Automatic|Configured per service|
|Use Case|Short-lived, event-driven tasks|Large-scale, modular applications|

**Integration:**  

Serverless functions can host or complement microservices (e.g., using serverless for specific tasks like authentication or image processing within a microservices-based system).

---

### 4.  Cloud Providers: AWS, Azure, GCP

##### **4.1 Amazon Web Services (AWS):**  

AWS is Amazon’s cloud platform offering IaaS, PaaS, and SaaS solutions. It is the largest and most mature cloud provider.

**Core Services:**

- **Compute:** EC2 (Virtual Servers), Lambda (Serverless), ECS/EKS (Containers)
- **Storage:** S3 (Object Storage), EBS (Block Storage), Glacier (Archival)
- **Database:** RDS (Relational), DynamoDB (NoSQL), Redshift (Data Warehouse)
- **Networking:** VPC, Route 53 (DNS), CloudFront (CDN)
- **AI/ML:** SageMaker, Rekognition, Lex
- **Management:** CloudWatch (Monitoring), CloudFormation (Infrastructure as Code)

**Key Features:**
- Global infrastructure (Regions, Availability Zones)
- Pay-as-you-go pricing model
- High reliability and scalability
    

##### **4.2 Microsoft Azure:**  

Azure is Microsoft’s integrated cloud platform providing a wide range of enterprise services.

**Core Services:**

- **Compute:** Virtual Machines, Azure Functions, AKS (Kubernetes)
- **Storage:** Blob Storage, Disk Storage, File Storage
- **Database:** SQL Database, Cosmos DB, PostgreSQL
- **Networking:** Virtual Network (VNet), Load Balancer, CDN
- **AI/ML:** Azure ML, Cognitive Services
- **DevOps Tools:** Azure DevOps, ARM Templates
    
**Key Features:**
- Strong integration with Microsoft ecosystem (Windows Server, Active Directory, Office 365)
- Hybrid cloud support (Azure Arc, Stack)
- Enterprise-grade security and compliance
    

##### **4.3 Google Cloud Platform (GCP):**  

GCP is Google’s cloud offering, known for data analytics, AI, and Kubernetes innovations.

**Core Services:**
- **Compute:** Compute Engine (VMs), Cloud Functions (Serverless), GKE (Kubernetes Engine)
- **Storage:** Cloud Storage (Object), Persistent Disk, Filestore
- **Database:** Cloud SQL, Firestore, Bigtable, BigQuery (Analytics)
- **Networking:** VPC, Cloud Load Balancing, Cloud CDN
- **AI/ML:** Vertex AI, TensorFlow, AutoML
- **Developer Tools:** Cloud Build, Deployment Manager

**Key Features:**

- Leadership in container orchestration (Kubernetes)
- Advanced data analytics and machine learning
- Global fiber network and security architecture
    

**Comparison Summary:**

| Feature      | AWS                       | Azure                      | GCP                      |
| ------------ | ------------------------- | -------------------------- | ------------------------ |
| Launch Year  | 2006                      | 2010                       | 2011                     |
| Strength     | Breadth of services       | Enterprise integration     | Data & AI                |
| Market Share | Largest                   | Second                     | Growing                  |
| Pricing      | Pay-as-you-go             | Pay-as-you-go              | Sustained use discounts  |
| Best For     | Versatility & scalability | Enterprise & hybrid setups | Data-driven applications |
