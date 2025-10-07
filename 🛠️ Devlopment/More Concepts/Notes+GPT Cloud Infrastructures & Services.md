

# **Cloud Infrastructure Overview**


##### 1. **AWS (Amazon Web Services)**

**Key Services**
- **Compute:** EC2 (VMs), Lambda (serverless), ECS/EKS (containers)
- **Storage:** S3 (object), EBS (block), EFS (file)
- **Database:** RDS (managed SQL), DynamoDB (NoSQL), Redshift (data warehouse)
- **Networking:** VPC, Route53, CloudFront (CDN), ELB (load balancer)
- **Security:** IAM, KMS, Shield (DDoS protection)
    

**Features**
- Largest market share, highly scalable and global.
- Pay-as-you-go pricing.
- Strong ecosystem & developer support.

##### **2. Microsoft Azure**

**Key Services**

- **Compute:** Virtual Machines, Azure Functions (serverless), AKS (Kubernetes)
- **Storage:** Blob Storage (object), Disk Storage (block), File Storage
- **Database:** SQL Database, Cosmos DB (multi-model NoSQL), Synapse Analytics
- **Networking:** Virtual Network, Azure Front Door (CDN), Load Balancer
- **Security:** Azure AD, Key Vault, Security Center
###### Features
- Strong integration with Microsoft products (Windows Server, Office 365).
- Hybrid cloud-friendly.
- Enterprise-oriented with compliance support.
    
### **3. Google Cloud Platform (GCP)**

**Key Services**
- **Compute:** Compute Engine (VMs), Cloud Functions, GKE (Kubernetes)
- **Storage:** Cloud Storage (object), Persistent Disk (block), Filestore
- **Database:** Cloud SQL, Firestore, BigQuery (data warehouse)
- **Networking:** VPC, Cloud Load Balancing, Cloud CDN
- **Security:** Cloud IAM, KMS, Security Command Center
    

**Features**
- Strong in **AI/ML services** and data analytics.
- Global low-latency network.
- Pay-per-use billing.


##### **4. Oracle Cloud Infrastructure (OCI)**

**Key Services**

- **Compute:** VMs, Bare Metal Servers, Autoscaling
- **Storage:** Block, Object, File Storage
- **Database:** Autonomous Database (OLTP/OLAP), NoSQL
- **Networking:** VCN, Subnets, Load Balancer, Gateways
- **Security:** IAM, Key Management, Encryption

**Features**
- Enterprise-focused, high performance and reliability.
- Hybrid cloud capabilities.
- Strong for Oracle software (ERP, database workloads).

##### **5. Comparison Table**

|Feature|AWS|Azure|GCP|OCI|
|---|---|---|---|---|
|**Compute**|EC2, Lambda|VM, Azure Functions|Compute Engine, GKE|VM, Bare Metal|
|**Storage**|S3, EBS, EFS|Blob, Disk, File|Cloud Storage, Persistent Disk|Object, Block, File|
|**Database**|RDS, DynamoDB, Redshift|SQL DB, Cosmos DB, Synapse|Cloud SQL, Firestore, BigQuery|Autonomous DB, NoSQL|
|**Networking**|VPC, ELB, CloudFront|VNet, Load Balancer, Front Door|VPC, Load Balancing, CDN|VCN, Load Balancer, Gateways|
|**Security**|IAM, KMS|Azure AD, Key Vault|IAM, KMS|IAM, Key Management|
|**Strength**|Market leader, scalable, global|Enterprise integration, hybrid cloud|AI/ML, data analytics|Oracle enterprise apps, high performance|


##### **6. Key Concepts Across Cloud Providers**

- **IaaS:** Virtual machines, storage, networking
- **PaaS:** Managed platforms (databases, AI services)
- **SaaS:** Software delivered via cloud (Office365, Salesforce)
- **Serverless:** Event-driven functions (AWS Lambda, Azure Functions)
- **Hybrid Cloud:** Combine on-prem and cloud infrastructure
- **Security:** Identity, encryption, network security, compliance



---

# Cloud Service Providers Free Tier Overview


Comparing the free tier offers of the major cloud providers like AWS, Azure, GCP, Oracle Cloud etc.

**Star** :star: this repository if you found it useful and share with fellow developers!

1. [AWS](#1-aws)
2. [Azure](#2-azure)
3. [Google Cloud](#3-google-cloud)
4. [Oracle Cloud](#4-oracle-cloud)
5. [Alibaba Cloud](#5-alibaba-cloud)
6. [IBM Cloud](#6-ibm-cloud)
7. [DigitalOcean](#7-digitalocean)
8. [Hetzner Cloud](#8-hetzner-cloud)
9. [Render](#9-render)
10. [Netlify](#10-netlify)
11. [JFrog](#11-jfrog)
12. [Salesforce](#12-salesforce)
13. [OpenShift](#13-openshift)
14. [Linode](#14-linode)
15. [Container Hosting Service](#15-container-hosting-service)
16. [Cloudflare](#16-cloudflare)
17. [OVHcloud](#17-ovhcloud)
18. [Tencent Cloud](#18-tencent-cloud)
19. [Vercel](#19-vercel)
20. [Zeabur](#20-zeabur)

##### **1. AWS**
**Homepage: [AWS Free Tier](https://aws.amazon.com/free/)**
**Always Free**
- Amazon DynamoDB (NoSQL): 25 GB of storage
- AWS Lambda (FaaS): 1 Million free requests per month
- Amazon SNS: 1 Million publishes
##### **2. Azure**
**Homepage: [Azure Free Tier](https://azure.microsoft.com/en-us/free/)**
**Free for Limited-time**
- US$200 credit for 30 days
- Popular services free for 12 months
Always Free
- 54+ other services free always

##### **3. Google Cloud**
**Homepage: [Google Cloud Free Tier](https://cloud.google.com/free/docs/gcp-free-tier)**
**Always Free**
- Compute VM: 0.25 vCPU, 1 GB RAM (only on us-west1, us-central1 and us-east1)
  - 30 GB of standard persistent disk
  - 1 GB of network egress (except China and Australia) - in premium tier
  - 200 GB of network egress to any region in standard tier. (Comes with increased latency of around 20%.)
- BigQuery (SQL): 1 TB of querying per month and 10 GB of storage each month
- Cloud Storage: 5 GB-months of regional storage (US regions only) per month

##### **4. Oracle Cloud**
**Homepage: [Oracle Cloud Free Tier](https://www.oracle.com/cloud/free/)**
**Free for Limited-time 30 day free trial**
- US $300 credit for 30 days
- Up to eight instances across all available services
- Up to 5 TB of storage
**Always Free**
- Compute: (Note- [1 Oracle OCPU = 2 vCPUs](https://blogs.oracle.com/cloud-infrastructure/post/vcpu-and-ocpu-pricing-information))
  - 2 AMD-based VMs: 1/8 OCPU = 0.25 vCPU with 1 GB RAM each
  - 4 Arm-based VMs: 24 GB RAM total, 3,000 OCPU hours and 18,000 GB memory hours per month
- 2 Block Volumes Storage, 200 GB total
- 10 GB Object Storage - Standard
- 10 GB Object Storage - Infrequent Access
- 10 GB Archive Storage
- 10TB of network data egress/month per originating region
- Resource Manager (managed terraform)
- 5 OCI Bastions
- 2 Oracle Autonomous Databases incl. Oracle Application Express (APEX), Oracle SQL Developer etc., each with 20GB storage
- NoSQL Database with 25GB storage per table, up to 3 tables
- 4 Load Balancers: 1 Flexible (10Mbps) and 3 Network
- Monitoring and Notifications

##### **5. Alibaba Cloud**
Homepage: [Alibaba Cloud Free Trial](https://www.alibabacloud.com/campaign/free-trial)
**Free for Limited-time**
- Try Over 40 Products for Free Worth $450-$1300 USD. 
- Now up to 12 Months Usage for Elastic Compute Services.

##### **6. IBM Cloud**
**Homepage: [IBM Cloud Free Tier](https://www.ibm.com/uk-en/cloud/free)**
**Free for Limited-time**
- US$200 credit for 30 days

##### **7. DigitalOcean**
**Homepage: [DigitalOcean](https://www.digitalocean.com/)**
**Free for Limited-time**
- $100 credit for 60 days from [do.co/hf100](https://do.co/hf100)
##### **8. Hetzner Cloud**
**Homepage: [Hetzner Cloud](https://hetzner.cloud)**
**Free for Limited-time**
- sometimes they give away free credits

##### **9. Render**
**Homepage: [Render](https://render.com/)**
**Free for Limited-time**
- sometimes they give away free credits
**Always Free**
- static site hosting
- web service
- Redis
- PostgreSQL
- 0.1vCPU, 512MB of RAM, 100GB bandwidth, running time of 750 hours per month

##### **10. Netlify**
**Homepage: [Netlify](https://www.netlify.com/)**
**Free for Limited-time**
- sometimes they give away free credits
**Always Free**
- static site hosting

##### **11. JFrog**
**Homepage: [Jfrog Free Tier](https://jfrog.com/platform/free-trial/)**
**Free for Limited-time**
- Self-Hosted 30 day trial
**Always Free**
- 2GB Storage
- 10GB Transfer/month
- 2,000 CI/CD Minutes/month

##### **12. Salesforce**
**Homepage: [Salesforce Free Tier](https://www.salesforce.com/in/form/signup/freetrial-sales)**
**Free for Limited-time**
-  Your FREE 30-Days Trial Now!
**Always Free**
- When you download Listware for Salesforce, you are given 1,000 free credits which you can use during a free 30-day trial of the app.
 
##### **13. OpenShift**
**Homepage: [Interactive Learning Portal](https://learn.openshift.com/)**
**Try out Openshift 4 cluster for free**
**Openshift 4: [Try Openshift 4 cluster for free](https://www.openshift.com/try)**

##### **14. Linode**
**Homepage: [Linode](https://www.linode.com)**
**Free for Limited-time**
- US$100, 60-day free trial requires valid credit card. [free-credit-100](https://www.linode.com/lp/free-credit-100)

##### **15. Container Hosting Service**
**Homepage: [Container Hosting Service](https://container-hosting.anotherwebservice.com/)**
**Currently Free**
- Container Hosting Service [Try Open Source Container Hosting Service for free](https://container-hosting.anotherwebservice.com/)

##### **16. Cloudflare**
**Homepage: [Cloudflare](https://www.cloudflare.com/plans/)**
**Always free on basic plan:**
- NS server with DNS delegation
- 10GB R2 - S3 compatible object storage
- D1 - serverless SQL database
- CDN for delegated domains
- SSL offloading
- Web Application Firewall
- Workers & Pages - serverless functions

##### **17. OVHcloud**
**Homepage: [OVH](https://www.ovhcloud.com)**
**Free for Limited-time**
- [200€ or equivalent on all public cloud ressources for 30 days](https://www.ovhcloud.com/en-ie/public-cloud/)
**Always free**
- Mongo DB 512 MB (with replication): https://www.ovhcloud.com/en/public-cloud/mongodb/
##### **18. Tencent Cloud**
**Homepage: [Tencent Cloud](https://www.tencentcloud.com/campaign/freetier)**
Multiple alternative server locations for hosting in Asia: Shanghai, Nanjing, Guangzhou, Beijing, Chengdu, Chongqing, Hong Kong, Seoul, Tokyo, Singapore, Bangkok, Jakarta, Silicon Valley, Frankfurt, Mumbai, Virginia, São Paulo, Toronto
**Free for Limited-time**
- [$300 voucher, 30-day trial](https://www.tencentcloud.com/campaign/promotions)
**Always Free**
- Elastic Network Interface (ENI)
- Virtual Private Cloud (VOC)
- Auto Scaling (AS)
- VPN connections
##### **19. Vercel**
**Homepage: [Vercel](https://vercel.com/pricing)**
**Always free**
- Support for 35+ Frameworks
- Fast Globally (Edge Network)
- Automatic CI/CD (Git Integration)
- Functions (Serverless, Edge)
- Starter Database (KV, Postgres)
- Web Analytics
##### **20. Zeabur**
**Homepage: [Zeabur](https://zeabur.com/pricing)**
**Always free**
- Serverless functions and static sites
- 10GB outbound data transfer per month
**Always free for developer plan**
- 100GB outbound data transfer per month
- US$ 5 usage fee per month