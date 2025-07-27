
# [5.1 Memory Management and Degree of Multiprogramming | Operating System](https://www.youtube.com/watch?v=eESIFJz7mJw&ab_channel=GateSmashers)


**Memory Management:** it is a kind of functionality to manage all the memory resources in a more and more efficient manner

```                .   .
                 .  CPU  .
                   .   .
    +--------/-------|--------\---------------------+
    |       /        |         \                    |  
    | Register (kb)   cache    RAM (Primary Memory) |
    |                                     |         |
    +-------------------------------------|---------+    
                                          ↓  
                               Secondary Memory [ | | | | ]

Memory Management Mainly concerned with (Main Memory) i.e. Primary Memory						
```
##### Primary and Secondary Memory

- **Primary Memory (RAM)**: Random Access Memory is used to store currently running processes because it allows **fast access** to data, which is crucial for the CPU to perform efficiently.
- **Secondary Memory**: Since **primary memory is expensive and limited**, we use secondary memory (e.g., hard drives, SSDs) to store files, programs, and data that are not currently in use. Secondary memory is **cheaper but slower** compared to RAM.
  
   **Why not use secondary memory instead of RAM?**
   - Secondary memory is too slow to directly interact with the CPU.
   - Hence, both **RAM** and **secondary memory** are required: RAM stores **actively running processes** for fast access, while secondary memory holds **idle programs and files** until they are needed.

#### Process Execution:
- Whenever we execute a program, it must first be **loaded from secondary memory into primary memory (RAM)**. This is because the CPU can only execute instructions from RAM, not directly from secondary memory. 

##### Why Not Register or Cache?
- Registers and cache memory are even smaller and faster than RAM, but they are limited in size. They are used for specific purposes:
- **Registers** ==store immediate data and instructions== that the CPU is actively processing.
- **Cache** is used to ==store frequently accessed data== for quicker access, but it is still much smaller than RAM.
- Thus, RAM is essential to bridge the gap between the larger but slower secondary memory and the smaller, faster cache and registers.

##### Multiprogramming and CPU Utilization

- To improve system performance, we use **multiprogramming**, which means having **multiple programs loaded into RAM at the same time**. The goal is to maximize **CPU utilization** by ensuring that the CPU always has a process ready to execute.

- **Degree of multiprogramming**:  it refers to the number of processes that can be loaded into RAM at any given time. This is limited by the **size of the RAM**:

```
              RAM (Process)
              ⬋  ⬊
            CPU   I/O

At a time Process are either executed by PC or Does Input/Output Operation
```
- According to multiple programming, When we bring a process P1 & if it wants to have some i/p then CPU shouldn't be idle( i.e. it should process some other processes)

```
Let K^n = Probability of a All `n` Process, that it will do I/O Operation (i.e CPU will be Idle)

Let K = 70%

RAM        Process                  K-> Process doing i/o operation (70%)
[]           []      4/4=1          (1-K) -> CPU Utilisation (30%) 
4MB          4MB

RAM        Process                  K^2-> both process doing i/o operation 
[]           []      8/4=2          (1-K^2) -> CPU Utilisation (76%) 
8MB          4MB

RAM        Process                  K^4-> both process doing i/o operation 
[]           []      16/4=4         (1-K^4) -> CPU Utilisation (93%) 
16MB         4MB

```

- The larger the RAM, the more processes can be loaded into it simultaneously.
- More processes in RAM ↑ = higher degree of multiprogramming ↑ = better CPU utilization ↑

- **Challenges on increase multiprogramming**:
	1. **Frequent allocation and deallocation of memory** as processes enter and leave RAM.
	2. The CPU must ensure that each process uses only its allocated memory space to **prevent interference** between processes, ensuring **security and stability**.

# [5.2 Contiguous and non-Contiguous ](https://www.youtube.com/watch?v=FrTttJLN7Kw&t=45s&ab_channel=GateSmashers)


```
                      Memory manage ment Techniques
                     ⬋                              ⬊
           Contiguous                              Non-Contiguous
(Contnuous memory address allocation)       (Non Coninuous memory Allocation)
      ⬋                 ⬊                         
   Fixed Partition    Variable Partion            ↳ Paging
    (static)            (Dynamic)                 ↳ Multilevel Paging
 make fixed slots       Provide at run time       ↳ Inverted Paging
                                                  ↳ Segmentation
                                                  ↳ Segmented Paging               
```

- **Ready State Process ∝ CPU Utilization Efficiency**

# [5.3 Fixed Size Partitioning](https://www.youtube.com/watch?v=bK-VhQA512c&ab_channel=GateSmashers)
> Internal Fragmentation

Whenever the process are coming into RAM, how we are allocating it the space

```
 OS 10 MB
┌--------┐          ┌--------┐ 
|        |          |///P1///| <- P1 (5 MB), 1 MB Wasted (internal fragment.)
|        | 6MB      |////////|
|        |          |        |
├--------┤          ├--------┤  
|        |          |        |
|        | 4MB      |        |
├--------┤          ├--------┤
|        |          |        |
|        | 8MB      |        |
|        |          |        |
|        |          |        |
├--------┤          ├--------┤ 
|        | 2MB      |        |
└--------┘          └--------┘
```
**Points to remember**
1) No. of Partitions are fixed (always same)
2) No. of size of partition may or may not be same.
3) Size of each partition may or may not be same
4) Contiguous allocation so spanning is not allowed (This means that the process must fit into a single, uninterrupted section of memory)

-> We can put process in any partition taking into consideration its size should be less then the partition size


**Internal Fragmentation:** When we allocate memory to a process in **fixed-sized partitions**, sometimes the process may **not fully utilize the allocated partition**. The leftover space within the partition is wasted, and this is referred to as **internal fragmentation**.
- **Example**: If we allocate 4 KB of memory to a process that only requires 3 KB, the remaining 1 KB inside that partition is wasted. This wasted memory cannot be used for any other process.

**External Fragmentation:** In contrast, **external fragmentation** occurs when there is enough total free memory available to accommodate a process, but the memory is scattered in **small, non-contiguous fragments** across different areas. the process **cannot be accommodated** because we require a **contiguous block of memory** to allocate a process in **contiguous allocation** schemes.
- **Example**: Suppose you have three free blocks of memory (2 KB, 1 KB, and 3 KB) available in RAM. A process requires 4 KB to run, but even though the total free memory is 6 KB (2 KB + 1 KB + 3 KB), the process cannot be loaded because there is no single block large enough to hold 4 KB at once.

#### Limitations:

1. **Internal Fragmentation**
2. **Limit in Process Size** (If the process size exceeds the largest available partition)
3. **Limited Degree of Multiprogramming**: (The fixed number of partitions limits how many processes can be loaded into memory at once)
4. **External Fragmentation**

# [5.4 Variable Size Partitioning](https://www.youtube.com/watch?v=JdPmsrYqRDY&ab_channel=GateSmashers)

Ram is empty. At runtime process are allocated to the RAM at runtime

```

Variable Size Partioning

   OS              OS
┌--------┐       ┌--------┐     
|///P1///| 2MB   |///P1///| 2MB      
├--------┤       ├--------┤   
|        |       |////////|
|        |       |///P2///| 6MB
|        |       |////////|
|        |       ├--------┤ 
|        |       |////////|   
|   .    |       |///P3///| 8MB
|   .    |       |////////| 
|   .    |       |////////|
└--------┘       └--------┘
P1 allocated      P1->P2->P3 Allocated
```

```
┌--------┐     
|        | 2MB      
├--------┤   
|////////|            <- P4 (9 MB) ❌ Cannot Be Allocated Due to
|///P2///| 6MB                        (External Fragmentation)
|////////|
├--------┤ 
|        |   
|        | 8MB
|        | 
|        |
└--------┘
P1 allocated   
```

**Note:**
1) No internal Fragmentation
2) No limitation on number of Processes
3) There is no Limitation on the process size
> Fixed size memory allocation three limitation solved ✅

#### Limitations
1) External fragmentation occurs. We can remove it using compaction (One process is copied and Pasted to other location, but it takes very much time)
2) Deallocation creates Hole. Allocation and Deallocation is difficult
3) Lots of Holes is Created

```
  OS
┌--------┐     
|///P1///| 2MB      
├--------┤   
|  Hole  |           
|        | 4MB                        
├--------┤ 
|///P3///| 8MB
├--------┤ 
|  Hole  | 4MB
├--------┤ 
|///P5///| 2 MB
└--------┘
```

In Which way we should put which new Process ? 
  ↓
# [5.5 First fit, Next Fit, Best Fit, Worst fit Memory Allocation](https://www.youtube.com/watch?v=N3rG_1CEQkQ&ab_channel=GateSmashers)

1. **First Fit** -> Allocated the first hole that is big enough
2. **Next Fit** -> Same as first fit (but start search always from last allocated hole i.e. pointer use)
3. **Best fit** -> Allocate the smallest hole that is big enough to accommodate the process
4. **Worst fit** -> Allocate the largest hole. (But what's its use??)


Examples .... skipped

# [5.6 Gate Question Solved on Fits](https://www.youtube.com/watch?v=W7wDlABjCQI&ab_channel=GateSmashers)

# [5.7 Gate 2007 Solved Questions on fits](https://www.youtube.com/watch?v=XOFTINaUZt8&ab_channel=GateSmashers)


# [5.8 Need of Paging | Memory Management | Operating System](https://www.youtube.com/watch?v=I2TbCGNv1xQ&ab_channel=GateSmashers)

In contiguous memory allocation, one Process cannot be divided and put in different locations that leads to External Fragmentations.
### Non Contiguous Memory Allocation.
In **non-contiguous memory allocation**, a process can be divided into smaller parts, and these parts can be placed in different locations in the main memory (RAM). This method contrasts with contiguous memory allocation, where a process must occupy a single continuous block of memory.

```

+-----+
|     | 2KB      Process is divided and put up in different memory location
+-----+         
|\\\\\|             P1 
+-----+         \  ┌---┐
|     | 2KB     __ ├---┤  
+-----+            ├---┤
|\\\\\|          / └---┘
+-----+             6 KB
|     | 2KB  
+-----+
 OS
```

**Problem**
Process is divided according to the hole sizes, but  The holes are dynamically created, whenever a process try to enter into RAM, the CPU need to analyze the no. of holes and there size and then divide the process according to it.
But dividing a process is time/Costly Method

**Solution** 
So a Processes is divided before its gets the Memory called **pages.**
We make and keep partition of Process  already in Secondary Memory that is page
We already divide Main memory in Partitions i.e. each slots called **Frames**

```
The Size of Page = Frame Size
```

Note: The pages of a process are stored in **different locations** (non-contiguous manner) but still can be accessed and executed sequentially due to a **page table** that keeps track of where each page resides in RAM.
#### Key Characteristics:
- A process is **divided into pages**, and these pages can be placed in different frames in RAM.
- **Main memory** is divided into fixed-size blocks called **frames**.
- Each process is divided into blocks of the same size called **pages**, which are stored in the secondary memory (disk).
- The size of a page is equal to the size of a frame

#### Advantages:
- No External Fragmentation
- The memory is used dynamically, and it can hold several processes at once, even if the processes are larger than any single contiguous block.

#### Disadvantages:
- The operating system must maintain a page table for each process, mapping the pages of the process to the frames in memory. This adds overhead and cost
-  There may be Internal Fragmentation i.e. some wasted space within frames.

#### Example:
  
**Initial Memory Layout (Empty)**:
```
Memory 6KB
┌---┐
├---┤
├---┤
├---┤
├---┤
├---┤
└---┘
Frame Size = 1KB
```

**Page Allocation Example**:
- Process P1 requires 2 pages (2KB).
- Process P2 requires 3 pages (3KB).
- Process P3 requires 3 pages (3KB), but initially, not enough space is available.

```
 P1          P2       P3
┌---┐      ┌---┐    ┌---┐   
├---┤      ├---┤    ├---┤
└---┘      ├---┤    ├---┤
Page=1KB   └---┘    └---┘
          Page=1KB   Page=1KB
```

**Memory Allocation Attempt (P3 Fails to Fit)**:
```
Memory 6KB
┌---┐
|P1 |
├---┤  P1
|P1 |  ↓
├---┤  P2
|P2 |  ↓
├---┤  P3 ❌ Not enough space
|P2 |
├---┤
|   |
├---┤
|   |
└---┘
Frame Size = 1KB
```

**After Releasing P1**:
- Once Process P1 finishes and its frames are freed, Process P3 can be allocated in the freed frames.

```
Memory 6KB
┌---┐                   ┌---┐
|   |                   |P3 | <- P3 Page 
├---┤                   ├---┤ 
|   |                   |P3 | <- P3 Page
├---┤                   ├---┤  
|P2 |                   |P2 |
├---┤            =>     ├---┤  
|P2 |                   |P2 |
├---┤                   ├---┤
|   |                   |P3 | <- P3 Page
├---┤                   ├---┤
|   |                   |   |
└---┘                   └---┘   
P1 Done    
```


# [5.9 What is Paging](https://www.youtube.com/watch?v=6c-mOFZwP_8&ab_channel=GateSmashers)

# [5.10 Question Explanation on Logical address and Physical address space](https://www.youtube.com/watch?v=30P73tWmU0s&ab_channel=GateSmashers)

# [5.11 Question Explanation on Paging](https://www.youtube.com/watch?v=L80DakYu4uw&ab_channel=GateSmashers)

# [5.12 Page Table Entries | Format of Page Table](https://www.youtube.com/watch?v=JyPMJnnkNmQ&ab_channel=GateSmashers)

# [5.13 2-Level Paging in Operating System | Multilevel Paging](https://www.youtube.com/watch?v=PiEq1CoP0ds&ab_channel=GateSmashers)

# [5.14 Inverted paging](https://www.youtube.com/watch?v=spApKfUa8BI&ab_channel=GateSmashers)

# [5.15 Paging Questions Imp Question for all competitive exams](https://www.youtube.com/watch?v=ucNJMcX-duE&ab_channel=GateSmashers)

# [5.16 What is Thrashing](https://www.youtube.com/watch?v=IyWaK8pbN6A&ab_channel=GateSmashers)

# [5.17 Segmentation Vs Paging | Segmentation Working](https://www.youtube.com/watch?v=dz9Tk6KCMlQ&ab_channel=GateSmashers)

# [5.18 Overlay  Memory Management](https://www.youtube.com/watch?v=Quj-Goz4VMA&ab_channel=GateSmashers)

# [5.19 Virtual Memory | Page fault | Significance of virtual memory ](https://www.youtube.com/watch?v=o2_iCzS9-ZQ&ab_channel=GateSmashers)

# [5.20: Translation Lookaside Buffer(TLB)](https://www.youtube.com/watch?v=Z2T2vnyZl0o&ab_channel=GateSmashers)

# [5.21 Numerical on Translation Lookaside Buffer (TLB)](https://www.youtube.com/watch?v=Z4vzWxCcDCY&ab_channel=GateSmashers)
# [5.22 Page Replacement Introduction | FIFO Page Replacement algorithm ](https://www.youtube.com/watch?v=8rcUs5RutX0&ab_channel=GateSmashers)

# [5.23 Belady's Anomaly in FIFO page Replacement with example](https://www.youtube.com/watch?v=pR1uhp--COc&ab_channel=GateSmashers)

# [5.24 Optimal Page Replacement algorithm](https://www.youtube.com/watch?v=q2BpMvPhhrY&ab_channel=GateSmashers)

# [5.25 Least Recently Used Page Replacement Algorithm](https://www.youtube.com/watch?v=dYIoWkCvd6A&ab_channel=GateSmashers)

# [5.26 Most recently used page replacement algorithm](https://www.youtube.com/watch?v=H3BU_Do_l-Q&ab_channel=GateSmashers)
