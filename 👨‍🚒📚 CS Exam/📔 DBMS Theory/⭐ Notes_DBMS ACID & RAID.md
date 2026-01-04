
# ACID ⭐

ACID: set of ==properties that ensure reliable processing== of database transactions.
These properties are:

1. **Atomicity**: A transaction is an indivisible unit, meaning either all its operations are executed or none at all. If any part of the transaction fails, the entire transaction is rolled back, and the database remains unchanged.
	_Example_: Mobile recharge
    - Balance deducted from bank
    - Recharge applied to number
    - If recharge API fails, money is not deducted.

2. **Consistency**: A transaction must leave the database in a valid state. It ensures that the database transitions from one consistent state to another, maintaining the integrity of the data according to defined rules and constraints (like foreign keys, triggers).
	_Example_: E-commerce order
    - Product stock must not go negative
    - If 0 stock and someone tries to buy, order fails.

3. **Isolation**: Transactions are executed independently of each other, meaning changes made in one transaction are not visible to other concurrent transactions until the transaction is completed. This prevents unintended interference between concurrent transactions.
    _Example_: 2. Order Placement
    - User places an order, reducing inventory.
    - Another admin checks inventory at the same time — they still see the old stock until the order transaction is committed.

4. **Durability**: Once a transaction is committed, the changes it made to the database are permanent. Even if there is a system crash or failure, the committed changes remain intact, thanks to backup and recovery mechanisms.
    _Example_: After online payment, order ID is generated
    - Even if server crashes, the order details are saved and retrievable from database.

Together, these properties ensure the reliability and correctness of database operations in multi-transactional environments.

---

# RAID

- **RAID** - **Redundant Array of Inexpensive Disks** (or **Independent Disks**).
- **RAID** : is a ==data storage virtualization technology== that combines multiple physical disk drives into one or more logical units to improve performance, increase storage capacity, and enhance data redundancy. 
- RAID is commonly used in databases to ensure high **availability** and **reliability** of data.
- RAID has different levels, each offering a balance of performance, redundancy, and storage capacity. Here are some key RAID levels:

##### **RAID 0 (Striping)**: ⭐
- **Purpose**: Improves performance by spreading data across multiple disks.
- **How it works**: Data is split into blocks and written across multiple disks. This parallelism enhances read and write speeds.
- **Pros**: High performance for read/write operations.
- **Cons**: No redundancy; if one disk fails, all data is lost.

##### **RAID 1 (Mirroring)**: ⭐
- **Purpose**: Provides data redundancy by duplicating the same data on two or more disks.
- **How it works**: Every piece of data is written to two or more disks simultaneously. If one disk fails, the other contains an identical copy.
- **Pros**: High data redundancy and reliability.
- **Cons**: Storage efficiency is low, as 50% of disk space is used for duplication.

##### **RAID 10 (Combining RAID 1 + RAID 0)**: ⭐
- **Purpose**: Offers both redundancy and high performance.
- **How it works**: Combines RAID 1 (mirroring) and RAID 0 (striping). Data is mirrored across pairs of disks (RAID 1) and striped across multiple mirrored sets (RAID 0).
- **Pros**: High performance and redundancy(Reliability).
- **Cons**: Requires more disks; storage efficiency is only 50%.
##### **RAID 2 (Bit-Level Striping with Hamming Code Parity)**
##### **RAID 3 (Byte-Level Striping with Dedicated Parity Disk)**
##### **RAID 4 (Block-Level Striping with Dedicated Parity Disk)**
##### **RAID 5 (Striping with Parity)**:
- **Purpose**: Balances performance and redundancy.
- **How it works**: Data is striped across multiple disks, but in addition, parity information is distributed across all disks. The parity data allows the system to reconstruct lost data if one disk fails.
- **Pros**: Good read performance, redundancy, and efficient use of disk space.
- **Cons**: Slower write performance due to parity calculation; recovery from disk failure takes time.

##### **RAID 6 (Striping with Double Parity)**:
- **Purpose**: Provides additional fault tolerance compared to RAID 5.
- **How it works**: Similar to RAID 5 but with two sets of parity data, allowing for recovery from the failure of two disks.
- **Pros**: Increased fault tolerance (can withstand two disk failures).
- **Cons**: Slower write performance due to double parity calculation; more overhead than RAID 5.


#### Benefits of RAID in DBMS:
- **Data Redundancy**: Ensures data remains available even if a disk fails.
- **Improved Performance**: Striping (RAID 0, 5, 10) enhances I/O performance, critical for database systems with large amounts of data.
- **Fault Tolerance**: Mirroring and parity-based RAID levels provide resilience against hardware failure, reducing downtime.

#### Conclusion:
- RAID is crucial in DBMS environments to safeguard against data loss, improve performance, and ensure high availability, especially for critical systems that handle large datasets and require constant uptime.