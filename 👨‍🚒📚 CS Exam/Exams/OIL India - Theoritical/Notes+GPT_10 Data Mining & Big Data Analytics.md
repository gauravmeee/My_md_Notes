
# Data Mining and Big Data Analytics

| Topics                     | Subtopics                        |
| -------------------------- | -------------------------------- |
| Data Cleaning & Processing | Preprocessing and transformation |
| Association & Correlation  | Apriori, FP-Growth               |
| Clustering                 | K-Means, Hierarchical            |
| Classification             | Decision trees, SVM              |
| Big Data                   | Concepts and applications        |
| Big Data Tools             | Hadoop, Spark, MapReduce         |
# Data Cleaning and Processing

## Data Cleaning

Process of detecting, correcting, and removing errors, inconsistencies, and inaccuracies in data to improve quality for analysis.

### Common Issues

- **Missing values** – caused by data entry errors or incomplete collection
    
- **Noise** – random error or variance in a dataset
    
- **Inconsistencies** – conflicting data (e.g., different formats, duplicates)
    
- **Outliers** – extreme values that deviate from others
    

### Handling Missing Data

- **Ignore the record** (if few and random)
    
- **Fill manually** (if possible)
    
- **Global constant** (e.g., “Unknown”)
    
- **Attribute mean/median/mode**
    
- **Attribute mean for class** (conditional mean)
    
- **Predictive models** (e.g., regression, k-NN, ML-based imputation)
    

### Noise Handling

- **Binning** – sort values and smooth via bin means/medians
    
- **Regression** – fit curve and smooth data
    
- **Clustering** – detect and remove outliers
    

### Inconsistency Resolution

- **Standardization** – uniform formats (e.g., date, units)
    
- **Deduplication** – remove duplicate records
    
- **Cross-validation** – use external references for correction
    

---

## Data Processing

Transforming raw data into a suitable format for mining or analysis.

### Steps

1. **Data Integration** – combining data from multiple sources
    
    - Handle schema conflicts, redundancy, entity identification
        
2. **Data Transformation** – convert data into suitable forms
    
    - **Normalization:** scale values (min-max, z-score, decimal scaling)
        
    - **Aggregation:** combine data (e.g., sum, avg)
        
    - **Generalization:** replace detailed data with higher-level concepts
        
    - **Feature construction:** create new attributes from existing ones
        
3. **Data Reduction** – reduce data volume but retain integrity
    
    - **Dimensionality reduction (PCA, LDA)**
        
    - **Numerosity reduction (sampling, clustering)**
        
    - **Data compression**
        
4. **Discretization** – convert continuous data into categorical intervals
    
    - **Equal-width** or **Equal-frequency binning**
        

### Objective

Improve **data quality**, **consistency**, and **efficiency** of mining algorithms.


---
----

# Association and Correlation Analysis

## Association Analysis

Process of discovering interesting relationships or patterns (associations) among items in large datasets.  
Used mainly in **market basket analysis** (e.g., {Milk → Bread}).

### Basic Concepts

- **Itemset:** Set of items (e.g., {Milk, Bread})
    
- **Support (s):** Frequency of itemset occurrence  
    `Support(A→B) = P(A ∪ B)`
    
- **Confidence (c):** Strength of implication  
    `Confidence(A→B) = P(B | A)`
    
- **Lift:** Measure of independence between A and B  
    `Lift(A→B) = P(A∪B) / (P(A) × P(B))`
    
    - **Lift > 1:** Positive correlation (A and B occur together more often)
        
    - **Lift = 1:** Independent
        
    - **Lift < 1:** Negative correlation
        

### Steps in Association Rule Mining

1. **Find Frequent Itemsets** (using support threshold)
    
2. **Generate Association Rules** (using confidence threshold)
    
3. **Prune Rules** based on interestingness measures (lift, conviction, leverage)
    

### Algorithms

- **Apriori Algorithm:** Uses iterative candidate generation and pruning
    
- **FP-Growth:** Builds a compact tree (FP-tree) to avoid candidate generation
    
- **Eclat:** Uses depth-first search with transaction ID sets
    

---

## Correlation Analysis

Determines how strongly pairs of attributes are related.

### Measures

- **Pearson Correlation Coefficient (r):**  
    `r = cov(X,Y) / (σX × σY)`
    
    - r = 1 → Perfect positive
        
    - r = -1 → Perfect negative
        
    - r = 0 → No linear correlation
        
- **Spearman Rank Correlation:** Non-parametric, uses ranks instead of values
    
- **Chi-Square Test:** Tests independence between categorical variables
    

### Difference Between Association and Correlation

|Aspect|Association|Correlation|
|---|---|---|
|Purpose|Find co-occurrence patterns|Measure strength & direction of linear relationship|
|Data Type|Categorical/transactional|Numerical (or ranked)|
|Output|Rules (A→B)|Coefficient (r)|
|Dependency|Asymmetric (A→B)|Symmetric (X↔Y)|

### Objective

- Association: Discover hidden relationships between items.
    
- Correlation: Quantify strength and direction of relationships between variables.

---
---

# Clustering Algorithms and Cluster Analysis

## Cluster Analysis

Unsupervised learning technique used to group similar data objects into clusters such that:

- **Intra-cluster similarity** is high
    
- **Inter-cluster similarity** is low
    

### Applications

Market segmentation, image analysis, anomaly detection, document classification, etc.

---

## Types of Clustering

1. **Partitioning Methods** – divide data into k clusters
    
    - Example: _k-Means, k-Medoids_
        
2. **Hierarchical Methods** – build a hierarchy of clusters
    
    - Example: _Agglomerative, Divisive_
        
3. **Density-Based Methods** – clusters are dense regions separated by sparse areas
    
    - Example: _DBSCAN, OPTICS_
        
4. **Grid-Based Methods** – quantize data space into finite cells
    
    - Example: _STING, CLIQUE_
        
5. **Model-Based Methods** – assume data is generated from a model
    
    - Example: _EM Algorithm, Gaussian Mixture Models (GMM)_
        

---

## Major Clustering Algorithms

### 1. k-Means Clustering

**Idea:** Partition data into _k_ clusters by minimizing within-cluster variance.  
**Steps:**

1. Choose _k_ initial centroids
    
2. Assign each point to nearest centroid
    
3. Recompute centroids as mean of assigned points
    
4. Repeat until centroids stabilize  
    **Pros:** Simple, fast  
    **Cons:** Sensitive to initial points, assumes spherical clusters, needs _k_
    

---

### 2. k-Medoids (PAM)

Similar to k-Means but uses actual data points (medoids) instead of means, reducing sensitivity to outliers.  
**Pros:** Robust to noise/outliers  
**Cons:** Higher computational cost

---

### 3. Hierarchical Clustering

Builds hierarchy of clusters without preset _k_.

- **Agglomerative (bottom-up):** Start with singletons → merge closest clusters
    
- **Divisive (top-down):** Start with one cluster → split recursively  
    **Linkage Methods:**
    
- Single (min distance)
    
- Complete (max distance)
    
- Average (mean distance)  
    **Produces:** Dendrogram (tree structure)
    

---

### 4. DBSCAN (Density-Based Spatial Clustering of Applications with Noise)

**Idea:** Clusters = dense regions separated by low-density areas  
**Parameters:**

- ε (epsilon): radius of neighborhood
    
- MinPts: minimum points to form dense region  
    **Pros:** Detects arbitrary-shaped clusters, handles noise  
    **Cons:** Sensitive to ε and MinPts selection
    

---

### 5. Gaussian Mixture Model (GMM)

**Idea:** Assumes data generated from mixture of Gaussian distributions  
**Uses:** Expectation-Maximization (EM) algorithm to estimate parameters  
**Pros:** Soft clustering (probabilistic)  
**Cons:** Requires assumption of Gaussian shape

---

## Cluster Evaluation

- **Internal Metrics:** Measure compactness/separation
    
    - _Silhouette Coefficient, Davies–Bouldin Index_
        
- **External Metrics:** Compare with known labels
    
    - _Rand Index, Purity, F-measure_
        

---

### Objective

Identify natural groupings in data for pattern discovery, data summarization, and insight extraction.


---
---

# Classification

## Definition

Supervised learning technique that assigns data items into predefined categories (classes) based on input features.  
Used for **predictive modeling** (e.g., spam detection, disease diagnosis).

---

## Basic Process

1. **Data Preparation:** Clean, transform, and split data into training and testing sets
    
2. **Model Training:** Learn mapping function from input features → class label
    
3. **Model Testing:** Evaluate on unseen data
    
4. **Prediction:** Assign class labels to new instances
    

---

## Key Concepts

- **Training Set:** Data used to build the model
    
- **Testing Set:** Data used to validate the model
    
- **Confusion Matrix:** Shows actual vs predicted classes
    
- **Accuracy:** `(TP + TN) / (TP + TN + FP + FN)`
    
- **Precision, Recall, F1-score:** Performance metrics for imbalanced datasets
    

---

## Major Classification Algorithms

### 1. Decision Tree

**Idea:** Recursively splits data based on attribute values to maximize class purity.  
**Splitting Measures:** Information Gain, Gain Ratio, Gini Index  
**Pros:** Easy interpretation  
**Cons:** Prone to overfitting

---

### 2. Naïve Bayes

**Idea:** Applies Bayes’ theorem assuming independent features.  
`P(C|X) = [P(X|C) × P(C)] / P(X)`  
**Pros:** Fast, works well for text/data classification  
**Cons:** Independence assumption often unrealistic

---

### 3. k-Nearest Neighbors (k-NN)

**Idea:** Assigns class based on majority vote of k nearest neighbors.  
**Pros:** Simple, non-parametric  
**Cons:** Slow for large datasets, sensitive to noise

---

### 4. Support Vector Machine (SVM)

**Idea:** Finds optimal hyperplane that maximizes margin between classes.  
**Pros:** Effective in high-dimensional space  
**Cons:** Poor performance on noisy or overlapping data

---

### 5. Neural Networks

**Idea:** Multiple interconnected layers learn complex nonlinear decision boundaries.  
**Pros:** High accuracy for complex data (images, speech)  
**Cons:** Requires large data and computation

---

### 6. Random Forest

**Idea:** Ensemble of multiple decision trees; prediction via majority voting.  
**Pros:** Reduces overfitting, robust  
**Cons:** Less interpretable

---

## Model Evaluation Metrics

- **Accuracy** – overall correctness
    
- **Precision & Recall** – useful for class imbalance
    
- **F1-Score** – harmonic mean of precision and recall
    
- **ROC Curve & AUC** – trade-off between TPR and FPR
    

---

### Objective

Build a predictive model that accurately assigns unseen data to correct predefined categories.


---
---

# Introduction to Big Data

## Definition

Big Data refers to extremely large and complex datasets that traditional data processing tools cannot handle efficiently in terms of **storage, processing, and analysis**.  
It involves data generated from multiple sources like social media, sensors, IoT devices, logs, and transactions.

---

## Characteristics (5 V’s of Big Data)

1. **Volume** – Huge amount of data (terabytes to petabytes)
    
2. **Velocity** – Rapid rate of data generation and processing
    
3. **Variety** – Different data types: structured, semi-structured, unstructured
    
4. **Veracity** – Data uncertainty, inconsistency, and reliability issues
    
5. **Value** – Extracting meaningful insights and business value
    

---

## Types of Big Data

- **Structured:** Organized data in fixed schema (e.g., SQL tables)
    
- **Semi-Structured:** Partial organization (e.g., JSON, XML)
    
- **Unstructured:** No predefined format (e.g., text, images, videos)
    

---

## Sources of Big Data

- Social media platforms (Twitter, Facebook)
    
- IoT sensors and smart devices
    
- E-commerce and transaction systems
    
- Scientific research instruments
    
- Server logs, clickstreams, mobile apps
    

---

## Big Data Architecture Components

1. **Data Sources** – Origin of raw data
    
2. **Data Ingestion** – Collecting and importing data (e.g., Kafka, Flume)
    
3. **Storage Layer** – Distributed storage (e.g., HDFS, NoSQL databases)
    
4. **Processing Layer** – Batch/stream processing (e.g., Hadoop MapReduce, Spark)
    
5. **Analytics Layer** – Machine learning, data mining, visualization
    
6. **Visualization Layer** – Tools like Tableau, Power BI for insights
    

---

## Technologies for Big Data

- **Storage:** HDFS, HBase, Cassandra
    
- **Processing:** Hadoop, Spark, Flink
    
- **Querying:** Hive, Pig, Impala
    
- **Streaming:** Kafka, Storm
    
- **Machine Learning:** MLlib, Mahout
    

---

## Challenges

- Data quality and cleaning
    
- Scalability and performance
    
- Security and privacy
    
- Data integration and interoperability
    
- Real-time analytics requirements
    

---

### Objective

Efficiently store, process, and analyze massive, heterogeneous, and fast-changing datasets to derive actionable insights and informed decisions.


---
---

# Introduction to Big Data Applications

## Definition

Big Data Applications use large-scale data analytics techniques to extract meaningful insights, patterns, and predictions from massive datasets across various domains.

---

## Key Areas of Application

### 1. **Business and Marketing**

- Customer behavior analysis and segmentation
    
- Personalized recommendations (Amazon, Netflix)
    
- Dynamic pricing and targeted advertising
    
- Supply chain and inventory optimization
    

---

### 2. **Finance and Banking**

- Fraud detection using real-time analytics
    
- Credit scoring and risk management
    
- Algorithmic and high-frequency trading
    
- Customer churn and sentiment analysis
    

---

### 3. **Healthcare**

- Predictive diagnosis and patient monitoring
    
- Drug discovery and genomics research
    
- Hospital resource optimization
    
- Disease outbreak prediction (epidemiology)
    

---

### 4. **Government and Public Sector**

- Smart cities and infrastructure management
    
- Crime prediction and surveillance analytics
    
- Policy planning and social welfare optimization
    
- Disaster management and response systems
    

---

### 5. **Telecommunication**

- Network traffic analysis and optimization
    
- Churn prediction and customer profiling
    
- Fault detection and predictive maintenance
    

---

### 6. **Energy and Utilities**

- Smart grid monitoring and load forecasting
    
- Predictive maintenance of power equipment
    
- Optimization of renewable energy generation
    

---

### 7. **Education**

- Adaptive learning and personalized content
    
- Student performance prediction and dropout analysis
    
- Academic research using large-scale data
    

---

### 8. **Transportation and Logistics**

- Route and traffic optimization (Google Maps, Uber)
    
- Fleet management and predictive maintenance
    
- Autonomous vehicle analytics
    

---

### 9. **Social Media and Web**

- Sentiment analysis and trend prediction
    
- User behavior modeling
    
- Influencer and community detection
    

---

## Benefits

- Enhanced decision-making
    
- Real-time insights and automation
    
- Cost reduction through optimization
    
- Innovation and competitive advantage
    

---

### Objective

Leverage massive and diverse datasets to enable **data-driven decision-making**, improve **efficiency**, and create **intelligent, predictive, and adaptive systems** across industries.


---
---

# Introduction to Big Data Applications using Machine Learning

## Definition

Integration of **Machine Learning (ML)** with **Big Data** enables automatic pattern discovery, prediction, and decision-making from massive and complex datasets that cannot be processed by traditional algorithms.

---

## Relationship Between Big Data and Machine Learning

- **Big Data** provides **large-scale, high-dimensional, and diverse datasets**.
    
- **Machine Learning** provides **algorithms** that learn from this data to predict or classify outcomes.
    
- Together they form the foundation of **AI-driven analytics and automation**.
    

---

## Key Components

1. **Data Collection and Storage:** Using Hadoop, Spark, HDFS, NoSQL
    
2. **Data Preprocessing:** Cleaning, feature selection, and dimensionality reduction
    
3. **Model Training:** Using ML algorithms (supervised, unsupervised, reinforcement)
    
4. **Model Evaluation:** Performance metrics and validation
    
5. **Deployment and Real-Time Prediction:** Integration with applications and streaming data
    

---

## Common Machine Learning Techniques in Big Data

- **Supervised Learning:** Classification, regression (e.g., fraud detection, sentiment analysis)
    
- **Unsupervised Learning:** Clustering, association (e.g., market segmentation, anomaly detection)
    
- **Reinforcement Learning:** Decision optimization in dynamic environments
    
- **Deep Learning:** Handling unstructured data like images, audio, text (CNNs, RNNs)
    

---

## Big Data Platforms Supporting ML

- **Apache Spark MLlib** – scalable machine learning library
    
- **Hadoop Mahout** – distributed ML algorithms
    
- **TensorFlow on Big Data** – large-scale deep learning
    
- **H2O.ai, Databricks, AWS Sagemaker** – integrated ML and Big Data environments
    

---

## Major Applications

### 1. **Predictive Analytics**

Forecasting demand, stock prices, or failures using regression and neural networks.

### 2. **Fraud Detection**

Analyzing transaction patterns using anomaly detection and classification models.

### 3. **Recommendation Systems**

Using collaborative filtering and deep learning to recommend products or media.

### 4. **Healthcare Analytics**

Disease prediction, medical image classification, and personalized treatment models.

### 5. **Real-Time Analytics**

Streaming ML for IoT data, social media trends, and financial markets using Spark Streaming or Flink.

### 6. **Natural Language Processing**

Text mining, sentiment analysis, and chatbot training on large textual datasets.

---

## Benefits

- Scalability and automation in data-driven decisions
    
- Real-time insights from streaming and batch data
    
- Improved accuracy with continuous learning models
    

---

### Objective

Combine **Big Data infrastructure** with **Machine Learning intelligence** to build **scalable, adaptive, and predictive systems** capable of transforming massive datasets into actionable knowledge.


---
---

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