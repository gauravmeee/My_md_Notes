
# Cloud Computing

|     | Topics                        | Subtopics                  |
| --- | ----------------------------- | -------------------------- |
| 1   | Introduction                  | Characteristics and models |
| 2   | Architecture & Virtualization | IaaS, PaaS, SaaS           |
| 3   | Serverless & Microservices    | Concepts and use cases     |
| 4   | Cloud Providers               | AWS, Azure, GCP basics     |


### **1. Introduction to Cloud Computing**

**Definition:** Cloud Computing is a ==model for enabling on-demand network access== to a ==shared pool of configurable computing resources== (servers, storage, applications, and services) that can be rapidly provisioned and released with minimal management effort or service provider interaction.

**Key Characteristics:**
1. **On-demand self-service:** Users can ==access computing resources automatically== without human intervention.
2. **Broad network access:** ==Services are accessible over the network== via standard mechanisms (e.g., browsers, APIs).
3. **Resource pooling:** ==Resources are shared among multiple users using multi-tenancy==.
4. **Rapid elasticity:** Resources can be scaled up or down quickly according to demand.
5. **Measured service:** Resource usage is monitored, controlled, and billed based on consumption.


**Service Models:** ⭐
1. ==**Infrastructure as a Service (IaaS)==:** Provides virtualized hardware resources (e.g., AWS EC2, Google Compute Engine).
2. ==**Platform as a Service (PaaS)==:** Provides runtime environments and development tools (e.g., Google App Engine, Microsoft Azure).
3. ==**Software as a Service (SaaS)==:** Delivers applications over the internet (e.g., Gmail, Salesforce).
    

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

### **2. Cloud Architecture and Virtualization**

##### **Cloud Architecture**

**Cloud Architecture:** Cloud architecture ==defines the structure and components required== to ==deliver cloud services efficiently and securely==. It integrates ==computing, storage, networking, and management== layers.

**Main Components:**

1. **Front-end:**
    - ==Interface for users== (web portals, APIs, mobile apps)
    - Manages user interaction and access to cloud services
        
2. **Back-end:**
    - Core infrastructure including ==servers, storage, databases, and virtualization software==
    - Manages resource allocation, security, and system management
        
3. **Cloud Service Layer:**
    - Implements service models (==IaaS, PaaS, SaaS==)
    - Provides abstraction and automation of resources
        
4. **Management Layer:**
    - Handles resource provisioning, monitoring, billing, and SLA management
        
5. **Security Layer:**
    - Ensures data confidentiality, authentication, authorization, and compliance
        

**Cloud Delivery Components:**
- **Compute:** Virtual machines or containers providing processing power
- **Storage:** Object, block, or file-based scalable storage systems
- **Network:** Virtual networks enabling secure communication among resources
    
##### **Virtualization**

**Virtualization:** Virtualization is the ==creation of a virtual version of== ==hardware, storage, or network resources==, enabling ==multiple OSs or applications to run on the same physical system==.

**Types of Virtualization:**
1. **Hardware Virtualization:** Uses a ==hypervisor to divide physical resources== (e.g., VMware, KVM).
2. **Storage Virtualization:** Combines multiple storage devices into a single logical unit.
3. **Network Virtualization:** Creates virtual networks (e.g., VLAN, SDN).
4. **Desktop Virtualization:** Provides virtual desktops to users (e.g., VDI).
5. **Application Virtualization:** Runs applications in isolated environments.
    
==**Hypervisors:**==
- **Type 1 (==Bare-metal==):** Runs directly on hardware (e.g., VMware ESXi, Microsoft Hyper-V).
- **Type 2 (==Hosted==):** Runs on top of a host OS (e.g., Oracle VirtualBox, VMware Workstation).

**Benefits of Virtualization:**
- Efficient hardware utilization
- Scalability and flexibility
- Easy disaster recovery
- Reduced cost and energy consumption
    
**Relation between Cloud and Virtualization:**  Virtualization is the foundation of cloud computing; it abstracts physical resources to create scalable, on-demand virtual environments that enable cloud service delivery.

### **3. Serverless Computing and Microservices**

##### **Serverless Computing**

**Serverless Computing:**  Serverless computing is a ==cloud execution model where== ==the cloud provider manages== the ==infrastructure, automatically handles scaling, and charges only for actual resource usage==.

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

##### **Microservices Architecture**

**Microservices Architecture:**  Microservices architecture ==decomposes an application into== a ==collection of small, independent services== that communicate through APIs.

**Characteristics:**
- Each service performs a single business function
- Services communicate via REST, gRPC, or message queues
- Independently deployable and scalable
- Often containerized (e.g., Docker, Kubernetes)

**Advantages:**
- ==High scalability and flexibility==
- ==Easier maintenance and updates==
- Fault isolation (failure in one service doesn’t crash the whole system)
- Enables use of different technologies per service

**Challenges:**
- Complex inter-service communication
- Difficult debugging and tracing
- Requires advanced DevOps and monitoring tools
    


##### **Serverless vs Microservices:**

| Aspect      | Serverless                        | Microservices                     |
| ----------- | --------------------------------- | --------------------------------- |
| Deployment  | ==Functions triggered by events== | Independent services              |
| Management  | Fully managed by provider         | Managed by DevOps team            |
| Scalability | Automatic                         | Configured per service            |
| Use Case    | Short-lived, event-driven tasks   | Large-scale, modular applications |

**Integration:** ==Serverless functions can host or complement microservices== (e.g., using serverless for specific tasks like authentication or image processing within a microservices-based system).


### **4. Basics of Popular Cloud Providers: AWS, Azure, GCP**

##### **AWS**

**Amazon Web Services (AWS):**  AWS is Amazon’s cloud platform offering IaaS, PaaS, and SaaS solutions. It is the largest and most mature cloud provider.

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
    

##### **Azure**

**Microsoft Azure:** Azure is Microsoft’s integrated cloud platform providing a wide range of enterprise services.

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

##### **GCP**

**Google Cloud Platform (GCP):**   GCP is Google’s cloud offering, known for data analytics, AI, and Kubernetes innovations.

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

##### **Comparison Summary:**

| Feature      | AWS                           | Azure                      | GCP                          |
| ------------ | ----------------------------- | -------------------------- | ---------------------------- |
| Launch Year  | ==2006==                      | 2010                       | 2011                         |
| Strength     | Breadth of services           | Enterprise integration     | ==Data & AI==                |
| Market Share | ==Largest==                   | Second                     | Growing                      |
| Pricing      | ==Pay-as-you-go==             | Pay-as-you-go              | Sustained use discounts      |
| Best For     | ==Versatility & scalability== | Enterprise & hybrid setups | ==Data-driven applications== |