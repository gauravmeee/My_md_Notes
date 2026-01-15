
# Introduction


A **Data Warehouse (DW)** is a centralized repository that stores large volumes of historical and current data from multiple sources, optimized for **analysis and reporting**, not transaction processing.

**Characteristics**
- **Subject-oriented**: ==Organized around key subject==s like customers, products, or transactions.
- **Integrated**: Data from ==multiple sources== is cleaned and standardized.
- **Non-volatile**: Once entered, data is stable and ==not frequently updated.==
- **Time-variant**: Stores historical data for ==trend analysis over time==.

**Architecture**
1. **Data Sources**: Operational databases, external sources, flat files.
2. **ETL Layer**: ==Extract, Transform, Load process== to clean, format, and move data.
3. **Data Warehouse Storage**: Central repository storing integrated data.
4. **==OLAP== Servers**: Provide multidimensional analysis.
5. **==Front-end== Tools**: Reporting, dashboards, and analytics.

**Types**
- **Enterprise Data Warehouse (EDW)**: Centralized, organization-wide.
- **Operational Data Store (ODS)**: Short-term, near-real-time storage.
- **Data Mart**: Subset of DW for specific department or function.
    
##### **OLAP (Online Analytical Processing)**

- **MOLAP**: ==Multidimensional storage==, fast query, pre-aggregated data.
- **ROLAP**: ==Relational storage==, queries executed on relational DB.
- **HOLAP**: ==Hybrid== of MOLAP and ROLAP.
    
**Benefits**
- Better decision-making through historical insights.
- High query performance for analysis.
- Consistent and accurate data.
    
**Challenges**
- High implementation and maintenance cost.
- Complexity in ETL and data integration.
- Requires careful design to handle large-scale queries efficiently.


## ETL, Data Cleaning, Data Cube, Data Model


##### **ETL (Extract, Transform, Load)**

- **Extract**: Collect data from multiple heterogeneous sources.
- **Transform**: Clean, standardize, aggregate, and convert data into suitable format.
- **Load**: Store the processed data into the data warehouse for analysis.
##### **Data Cleaning**
- **Purpose**: Remove errors, inconsistencies, duplicates, and missing values.
- **Techniques**:
    - Handling missing data (imputation, deletion)
    - Removing duplicates
    - Standardizing formats (dates, units)
    - Correcting inconsistent or incorrect values

##### **Data Cube**
- **Definition**: Multidimensional representation of data for fast OLAP queries.
- **Dimensions**: Attributes like time, product, location.
- **Measures**: Numeric data analyzed (e.g., sales, revenue).
- **Operations**:
    - **Roll-up**: Aggregate data along a dimension.
    - **Drill-down**: Break aggregated data into finer details.
    - **Slice**: Select a specific dimension value.
    - **Dice**: Select a sub-cube with multiple dimensions.
    - **Pivot**: Rotate dimensions for different perspective.

##### **Data Model**
- **Definition**: Logical structure of ==how data is stored, related, and accessed.==
- **Types**:
    - ==**Star Schema**:== Fact table in center, connected to dimension tables.
    - ==**Snowflake Schema**:== Dimension tables normalized into multiple related tables.
    - ==**Fact Constellation**==: Multiple fact tables sharing dimension tables.

