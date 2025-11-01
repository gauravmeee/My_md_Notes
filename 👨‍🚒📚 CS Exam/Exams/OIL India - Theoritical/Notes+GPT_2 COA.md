# Computer Organization and Architecture

|     | Topics                   | Subtopics                              |
| --- | ------------------------ | -------------------------------------- |
| 1   | Functional Blocks        | CPU, ALU, Memory, I/O                  |
| 2   | x86 Architecture         | Instruction set, RISC, CISC            |
| 3   | Pipelining               | Stages and hazards                     |
| 4   | Memory Organization      | Cache, Main, Secondary memory          |
| 5   | Intel & AMD Processors   | Basics and comparison                  |
| 6   | Architectural Techniques | Instruction/Thread/Process parallelism |
| 7   | Peripheral Devices       | I/O interfacing and DMA                |
| 8   | Memory Hierarchies       | Levels and access time                 |
# 1. Functional Blocks of a Computer

## 1. Input Unit

- Accepts data and instructions from the user.
    
- Converts them into a machine-readable form.  
    **Examples:** Keyboard, Mouse, Scanner.
    

## 2. Memory Unit

- Stores data, instructions, and intermediate results.
    
- Two main types:
    
    - **Primary Memory:** RAM, ROM, Cache (fast but limited).
        
    - **Secondary Memory:** Hard Disk, SSD (large but slower).
        

## 3. Arithmetic and Logic Unit (ALU)

- Performs all arithmetic operations (addition, subtraction, etc.).
    
- Performs logical operations (AND, OR, NOT, comparisons).
    
- Works under control of Control Unit.
    

## 4. Control Unit (CU)

- Directs operations of all units by interpreting instructions.
    
- Fetches, decodes, and executes instructions.
    
- Coordinates data movement between memory and ALU.
    

## 5. Output Unit

- Converts machine results into human-readable form.  
    **Examples:** Monitor, Printer, Plotter.
    

## 6. System Interconnection (Bus System)

- Communication pathway connecting components.
    
- Types of Buses:
    
    - **Data Bus:** Transfers data.
        
    - **Address Bus:** Transfers memory addresses.
        
    - **Control Bus:** Transfers control signals.
        

## 7. Central Processing Unit (CPU)

- Combination of **ALU + CU + Registers**.
    
- Executes instructions, controls system operation.
    
- Often termed as the “brain of the computer”.
    

**Overall Block Structure:**  
Input Unit → Memory Unit → CPU (ALU + CU) → Output Unit  
Connected via Bus System

---
---

# 2. Introduction to x86 Architecture and Instruction Set, RISC, CISC

## 1. x86 Architecture

- Family of instruction set architectures (ISA) developed by **Intel** (starting with 8086 processor).
    
- **Type:** CISC (Complex Instruction Set Computer).
    
- **Word Size:** Initially 16-bit (8086), later extended to 32-bit (IA-32) and 64-bit (x86-64).
    
- **Registers:**
    
    - **General Purpose:** AX, BX, CX, DX (and their 32/64-bit versions: EAX, EBX, etc.).
        
    - **Segment Registers:** CS, DS, SS, ES, FS, GS.
        
    - **Index/Pointer Registers:** SI, DI, BP, SP, IP.
        
    - **Flags Register:** Status and control flags (ZF, CF, SF, etc.).
        
- **Memory Model:** Segmented memory addressing.
    
- **Instruction Format:** Variable-length (1–15 bytes).
    
- **Compatibility:** Backward compatible with earlier versions.
    
- **Applications:** Desktops, servers, embedded systems.
    

## 2. Instruction Set

- **Instruction:** Binary code telling CPU to perform an operation.
    
- **Types of Instructions:**
    
    - **Data Transfer:** MOV, PUSH, POP, XCHG
        
    - **Arithmetic:** ADD, SUB, MUL, DIV
        
    - **Logical:** AND, OR, XOR, NOT
        
    - **Control Transfer:** JMP, CALL, RET, JZ, JNZ
        
    - **String Operations:** MOVS, CMPS, SCAS, LODS, STOS
        
    - **Input/Output:** IN, OUT
        
- **Instruction Cycle:** Fetch → Decode → Execute → Store.
    

## 3. RISC (Reduced Instruction Set Computer)

- Uses small, simple, and fast instructions (one instruction per cycle).
    
- **Features:**
    
    - Fixed instruction length
        
    - Load/Store architecture (only load/store access memory)
        
    - Large number of registers
        
    - Simple addressing modes
        
    - Pipeline-friendly design
        
- **Examples:** ARM, MIPS, SPARC, RISC-V.
    
- **Advantages:** High speed, low power consumption, easier pipelining.
    
- **Disadvantages:** More instructions required for complex tasks.
    

## 4. CISC (Complex Instruction Set Computer)

- Large, complex instruction set with multi-cycle operations.
    
- **Features:**
    
    - Variable instruction length
        
    - Many addressing modes
        
    - Microprogrammed control unit
        
    - Direct memory operations within instructions
        
- **Examples:** x86, VAX, Intel 8086, Motorola 68000.
    
- **Advantages:** Compact code, easier for compiler and programmer.
    
- **Disadvantages:** Slower execution, harder to pipeline.
    

## 5. Comparison Between RISC and CISC

|Feature|RISC|CISC|
|---|---|---|
|Instruction Length|Fixed|Variable|
|Execution Speed|Faster|Slower|
|Control Unit|Hardwired|Microprogrammed|
|Memory Access|Load/Store only|Multiple instructions access memory|
|Pipelining|Easy|Difficult|
|Code Size|Larger|Smaller|
|Example|ARM, MIPS|x86, 8086|

---
---

# 3. Pipelining

## 1. Definition

Pipelining is a technique in which **multiple instructions are overlapped in execution** by dividing the CPU into several stages. Each stage performs a part of the instruction cycle, improving overall throughput.

## 2. Basic Concept

Each instruction passes through stages similar to an assembly line.  
When one instruction completes one stage, the next instruction enters that stage.

## 3. Basic Pipeline Stages

1. **IF (Instruction Fetch):** Fetch instruction from memory.
    
2. **ID (Instruction Decode):** Decode instruction and fetch operands.
    
3. **EX (Execute):** Perform operation in ALU.
    
4. **MEM (Memory Access):** Access memory if needed.
    
5. **WB (Write Back):** Write result to register.
    

## 4. Pipeline Performance

- **Speedup (S) = n / (1 + (k - 1)/m)**  
    Where:  
    n = number of stages, k = pipeline stalls, m = number of instructions.
    
- **Ideal Speedup:** ≈ number of pipeline stages.
    
- **Throughput:** Number of instructions completed per unit time increases.
    
- **Latency:** Time to complete one instruction remains almost same.
    

## 5. Types of Pipelining

- **Instruction Pipeline:** Overlaps different stages of instruction execution.
    
- **Arithmetic Pipeline:** Used for arithmetic operations like floating-point addition, multiplication.
    
- **Processor Pipeline:** Combination of both instruction and arithmetic pipelines.
    

## 6. Pipeline Hazards

1. **Structural Hazard:** Hardware resource conflict (e.g., one memory used for both instruction and data).
    
2. **Data Hazard:** Dependency between instructions.
    
    - Read After Write (RAW)
        
    - Write After Read (WAR)
        
    - Write After Write (WAW)
        
3. **Control Hazard:** Occurs due to branch or jump instructions.
    

## 7. Techniques to Handle Hazards

- **Stalling (Pipeline Bubble)**
    
- **Forwarding (Data Bypassing)**
    
- **Branch Prediction**
    
- **Speculative Execution**
    

## 8. Advantages

- Increased instruction throughput.
    
- Efficient CPU utilization.
    
- Reduced average instruction execution time.
    

## 9. Disadvantages

- Complex control logic.
    
- Performance loss due to hazards.
    
- Not suitable for programs with many branches or dependencies.

---
---

# 4. Memory Organization

## 1. Definition

Memory organization defines the **structure, hierarchy, and addressing** of data storage within a computer system to ensure fast and efficient access.

## 2. Memory Hierarchy

Organized based on **speed, cost, and size**:  
**Registers → Cache → Main Memory (RAM) → Secondary Storage (Disk)**

|Level|Example|Speed|Cost/Bit|Capacity|
|---|---|---|---|---|
|L1 Cache|Inside CPU|Fastest|Highest|Smallest|
|L2/L3 Cache|Near CPU|Very Fast|High|Small|
|Main Memory|RAM|Medium|Moderate|Medium|
|Secondary|SSD, HDD|Slow|Low|Large|

**Principle of Locality:**

- **Temporal Locality:** Recently used data likely to be reused.
    
- **Spatial Locality:** Data near recently used data likely to be used soon.
    

## 3. Types of Memory

### a) Primary Memory

- Directly accessible by CPU.
    
- **Volatile.**
    
- **Examples:** RAM (SRAM, DRAM), ROM (PROM, EPROM, EEPROM).
    

### b) Secondary Memory

- Non-volatile, used for long-term storage.
    
- **Examples:** Hard Disk, SSD.
    

### c) Cache Memory

- Small, high-speed memory between CPU and RAM.
    
- Stores frequently used data.
    
- **Levels:** L1, L2, L3 (based on proximity to CPU).
    

### d) Virtual Memory

- Technique to use part of secondary storage as an extension of RAM.
    
- Managed by OS using **paging or segmentation**.
    

## 4. Memory Addressing

- **Byte Addressable Memory:** Each byte has a unique address.
    
- **Word Addressable Memory:** Each word (n bytes) has a unique address.
    
- **Little Endian:** LSB stored first.
    
- **Big Endian:** MSB stored first.
    

## 5. Memory Interleaving

- Technique to improve memory access speed by dividing memory into modules accessed in parallel.
    
- **Types:**
    
    - **Low-order interleaving:** Sequential addresses go to different modules.
        
    - **High-order interleaving:** Consecutive blocks go to the same module.
        

## 6. Memory Mapping

- Maps CPU addresses to physical memory locations.
    
- **Types:**
    
    - **Direct Mapping**
        
    - **Associative Mapping**
        
    - **Set-Associative Mapping** (used in caches)
        

## 7. Memory Performance Parameters

- **Access Time:** Time to read/write data.
    
- **Cycle Time:** Time between two successive memory operations.
    
- **Bandwidth:** Amount of data transferred per unit time.
    
- **Hit Ratio:** (Cache hits) / (Total memory accesses).
    

## 8. Summary

Efficient memory organization ensures **fast access, high throughput, and cost-effectiveness** through hierarchical design, interleaving, and intelligent mapping techniques.


---
---

# 5. Basics of Intel and AMD Processors

## 1. Overview

**Intel** and **AMD (Advanced Micro Devices)** are leading manufacturers of **x86 and x86-64 architecture CPUs**.  
Both use similar instruction sets but differ in **microarchitecture, design philosophy, and performance optimization.**

## 2. Intel Processors

- **Architecture:** x86 / x86-64 (CISC-based).
    
- **Notable Series:** Pentium, Core (i3, i5, i7, i9), Xeon.
    
- **Microarchitecture Examples:** Nehalem, Sandy Bridge, Haswell, Skylake, Alder Lake, Raptor Lake.
    
- **Features:**
    
    - **Hyper-Threading:** Executes two threads per core.
        
    - **Turbo Boost:** Dynamic clock speed increase under load.
        
    - **Integrated Graphics:** Intel UHD/Iris GPUs.
        
    - **Large Cache Hierarchy:** Optimized for single-threaded tasks.
        
    - **Manufacturing Process:** Uses Intel’s own fabs (7nm, Intel 4, etc.).
        
- **Strengths:** High single-core performance, power efficiency, strong in professional workloads.
    

## 3. AMD Processors

- **Architecture:** x86 / x86-64 (CISC-based).
    
- **Notable Series:** Athlon, FX, Ryzen (3, 5, 7, 9), Threadripper, EPYC.
    
- **Microarchitecture Examples:** Zen, Zen+, Zen 2, Zen 3, Zen 4, Zen 5.
    
- **Features:**
    
    - **Simultaneous Multithreading (SMT):** Two threads per core (like Intel HT).
        
    - **Infinity Fabric:** High-speed interconnect between cores and chiplets.
        
    - **Chiplet Design:** Modular approach enabling more cores at lower cost.
        
    - **Unlocked CPUs:** Easier overclocking (Ryzen series).
        
    - **Integrated Graphics:** Ryzen G-series APUs.
        
- **Strengths:** Better multi-core performance, cost efficiency, scalability.
    

## 4. Key Differences

|Feature|Intel|AMD|
|---|---|---|
|Instruction Set|x86 / x86-64|x86 / x86-64|
|Design|Monolithic (mostly)|Chiplet-based|
|Multithreading|Hyper-Threading|SMT|
|Overclocking|Limited|Widely supported|
|Performance|Strong single-core|Strong multi-core|
|Manufacturing|In-house fabs|Outsourced (TSMC)|
|Price/Value|Higher|More value per core|

## 5. Common Features

- 64-bit processing support.
    
- Integrated memory controllers.
    
- Multi-level caches (L1, L2, L3).
    
- Support for virtualization (Intel VT-x, AMD-V).
    
- Advanced power management and security features (Intel SGX, AMD PSP).
    

## 6. Summary

Both Intel and AMD build CPUs on the same **x86-64 ISA** but optimize differently:

- **Intel** focuses on **efficiency, power, and single-threaded speed**.
    
- **AMD** focuses on **core scalability, cost, and parallel performance**.  
    Modern systems often choose based on **workload type, performance per watt, and price-to-performance ratio.**


---
---

# 6. Organization and Architectural Techniques

## 1. Definition

Computer **architecture** defines the functional behavior and instruction set of a system, while **organization** deals with physical implementation — how hardware executes those instructions efficiently.  
Architectural and organizational techniques improve **speed, efficiency, and parallelism**.

## 2. Architectural Techniques

Focus on **designing the instruction set and control structure** to enhance performance.

### a) Instruction-Level Parallelism (ILP)

- Multiple instructions executed simultaneously.
    
- Achieved using:
    
    - **Pipelining**
        
    - **Superscalar Execution** (multiple pipelines)
        
    - **Out-of-Order Execution** (reorder instructions for efficiency)
        
    - **Speculative Execution** (predict and execute ahead)
        

### b) Memory Hierarchy Design

- Uses **cache, main memory, and virtual memory** to minimize access latency.
    
- **Cache optimization** through mapping and replacement policies.
    
- **Prefetching** improves access speed by loading probable data in advance.
    

### c) Instruction Set Design

- **RISC vs CISC** balance between simplicity and functionality.
    
- Efficient **addressing modes** and **instruction formats** reduce fetch/decode time.
    
- **Orthogonal ISA design:** Allows flexible combinations of operations and operands.
    

### d) Parallel Architectures

- **SISD:** Single Instruction, Single Data (uniprocessor).
    
- **SIMD:** Single Instruction, Multiple Data (vector processors).
    
- **MISD:** Multiple Instruction, Single Data (rare).
    
- **MIMD:** Multiple Instruction, Multiple Data (multi-core, multiprocessor systems).
    

## 3. Organizational Techniques

Focus on **hardware structures and data paths** for efficient execution.

### a) Pipelining

- Overlaps instruction execution stages to increase throughput.
    
- Reduces idle CPU cycles.
    

### b) Multiprocessing

- Multiple CPUs share memory and tasks.
    
- **Symmetric Multiprocessing (SMP):** All processors equal.
    
- **Asymmetric Multiprocessing (AMP):** One master, others slaves.
    

### c) Multicore Processors

- Multiple cores on a single chip executing parallel threads.
    
- Shared cache and inter-core communication (e.g., AMD Infinity Fabric).
    

### d) Cache Organization

- **Levels:** L1, L2, L3.
    
- **Mapping Techniques:** Direct, Associative, Set-Associative.
    
- **Write Policies:** Write-Through, Write-Back.
    

### e) Interleaved and Banked Memory

- Divide memory into independent banks accessed concurrently to increase bandwidth.
    

### f) I/O Organization

- **Programmed I/O:** CPU controls data transfer.
    
- **Interrupt-Driven I/O:** Device interrupts CPU when ready.
    
- **DMA (Direct Memory Access):** Transfers data directly between I/O device and memory without CPU involvement.
    

## 4. Performance Enhancement Metrics

- **CPI (Cycles Per Instruction)**
    
- **MIPS (Million Instructions Per Second)**
    
- **Throughput** and **Latency**
    
- **Amdahl’s Law:**  
    Speedup = 1 / [(1 - f) + (f / s)]  
    where _f_ = fraction enhanced, _s_ = speedup of enhanced part.
    

## 5. Summary

Architectural techniques improve **design-level efficiency** (instruction set, parallelism), while organizational techniques improve **hardware execution efficiency** (pipelining, caching, multiprocessing).  
Together, they define overall **computer performance and cost-effectiveness**.


---
---

# 7. Memory Hierarchies

## 1. Definition

Memory hierarchy is an arrangement of storage devices based on **speed, cost, and capacity**, designed to balance fast access and large storage by using multiple memory levels.

## 2. Need for Hierarchy

- CPU speed >> Memory speed → causes **memory bottleneck**.
    
- Hierarchy ensures frequently used data is kept in faster memory (cache/registers) and less-used data in slower, larger storage.
    
- Exploits **locality of reference** (temporal and spatial locality).
    

## 3. Structure of Memory Hierarchy

**Registers → Cache → Main Memory (RAM) → Secondary Memory (SSD/HDD) → Tertiary Storage (Optical, Magnetic tapes)**

|Level|Type|Access Time|Cost/Bit|Capacity|
|---|---|---|---|---|
|L0|Registers|1 ns|Highest|Few Bytes|
|L1|Cache|2–4 ns|Very High|KBs–MBs|
|L2/L3|Cache|5–15 ns|High|MBs|
|L4|Main Memory|50–100 ns|Moderate|GBs|
|L5|Secondary Storage|ms|Low|TBs|
|L6|Tertiary Storage|s|Very Low|PBs|

## 4. Principle of Locality

- **Temporal Locality:** Recently accessed data likely reused soon.
    
- **Spatial Locality:** Data near recently accessed address likely accessed soon.  
    These principles justify caching and prefetching mechanisms.
    

## 5. Cache Memory Role

- Acts as **intermediate high-speed buffer** between CPU and main memory.
    
- Stores copies of frequently accessed instructions/data.
    
- Improves average access time:  
    **Tavg = (Hit Ratio × Cache Time) + (Miss Ratio × Main Memory Time)**
    

## 6. Memory Mapping Techniques

1. **Direct Mapping:** Each block mapped to one cache line (simple, low-cost).
    
2. **Associative Mapping:** Block can go to any line (flexible, expensive).
    
3. **Set-Associative Mapping:** Compromise; block maps to a set of lines.
    

## 7. Replacement Policies

When cache is full, decide which block to replace:

- **LRU (Least Recently Used)**
    
- **FIFO (First In First Out)**
    
- **Random Replacement**
    

## 8. Write Policies

- **Write-Through:** Write to both cache and main memory simultaneously.
    
- **Write-Back:** Write only to cache; main memory updated later on eviction.
    

## 9. Virtual Memory in Hierarchy

- Extends main memory using secondary storage (disk).
    
- Managed by OS via **paging** or **segmentation**.
    
- Provides illusion of large memory space to processes.
    

## 10. Summary

Memory hierarchy provides a **trade-off between speed and cost**, ensuring:

- Fast access for active data,
    
- Large capacity for infrequent data,
    
- Efficient CPU utilization and system performance.

---
---


# 8. Peripheral Devices

## 1. Definition

Peripheral devices are **external or auxiliary hardware components** connected to a computer to perform input, output, or storage operations. They communicate with the CPU through **I/O interfaces and buses**.

## 2. Types of Peripheral Devices

### a) Input Devices

Used to provide data and instructions to the computer.  
**Examples:**

- Keyboard (text input)
    
- Mouse (pointing input)
    
- Scanner (optical input)
    
- Microphone (audio input)
    
- Camera (image/video input)
    

### b) Output Devices

Used to present processed data in a human-readable form.  
**Examples:**

- Monitor / Display (visual output)
    
- Printer (hard copy output)
    
- Speakers (audio output)
    
- Plotter (graphical output)
    

### c) Storage Devices

Used for **data storage and retrieval** beyond primary memory.  
**Examples:**

- Hard Disk Drives (HDD)
    
- Solid State Drives (SSD)
    
- Optical Drives (CD/DVD/Blu-ray)
    
- USB Flash Drives
    
- External Backup Drives
    

### d) Communication Devices

Used for **data exchange** between systems or networks.  
**Examples:**

- Network Interface Card (NIC)
    
- Modem
    
- Wi-Fi Adapter
    
- Bluetooth Dongle
    

## 3. Classification by Connection

- **Internal Peripherals:** Installed inside the system unit (e.g., internal HDD, GPU).
    
- **External Peripherals:** Connected via ports or wireless interfaces (e.g., USB keyboard, printer).
    

## 4. Interfaces and Ports

- **Serial Port / USB (Universal Serial Bus)** – General-purpose serial communication.
    
- **Parallel Port** – Older high-speed data transfer interface.
    
- **HDMI / DisplayPort / VGA** – Video output connections.
    
- **SATA / NVMe** – Internal storage connection standards.
    
- **Ethernet Port** – Wired network communication.
    

## 5. I/O Communication Techniques

- **Programmed I/O:** CPU controls data transfer manually.
    
- **Interrupt-Driven I/O:** Device notifies CPU via interrupts when ready.
    
- **Direct Memory Access (DMA):** Data transferred directly between device and memory without CPU intervention.
    

## 6. Device Controllers and Drivers

- **Device Controller:** Hardware interface managing communication between CPU and device.
    
- **Device Driver:** Software component that allows OS to control hardware devices.
    

## 7. Summary

Peripheral devices expand system capabilities beyond the CPU and memory.  
They enable **interaction (input/output), storage, and communication**, forming the essential bridge between the user, hardware, and external world.


---
---

# 9. Instruction Level, Thread Level & Process Level Parallelism

## 1. Instruction Level Parallelism (ILP)

ILP refers to executing **multiple independent instructions simultaneously** within a single processor core.

### a) Types of ILP

- **Static ILP:** Determined by compiler at compile-time (e.g., loop unrolling).
    
- **Dynamic ILP:** Determined by hardware at runtime (e.g., out-of-order execution).
    

### b) Techniques for ILP

- **Pipelining:** Overlaps instruction stages.
    
- **Superscalar Execution:** Multiple instructions issued per clock cycle.
    
- **Speculative Execution:** Executes predicted branches ahead of time.
    
- **Branch Prediction:** Reduces control hazards by guessing branch outcomes.
    
- **Register Renaming:** Avoids data dependency conflicts.
    

### c) Limitations

- Data and control dependencies reduce parallelism.
    
- Diminishing returns due to limited independent instructions.
    

---

## 2. Thread Level Parallelism (TLP)

TLP focuses on **concurrent execution of multiple threads** within one or more processor cores.

### a) Definition

A thread is a lightweight sequence of instructions that can run independently but shares memory and resources with other threads.

### b) Techniques for TLP

- **Simultaneous Multithreading (SMT):** Multiple threads share one core’s execution units (e.g., Intel Hyper-Threading).
    
- **Multicore Processors:** Each core executes separate threads concurrently.
    
- **Chip Multiprocessing (CMP):** Multiple processing units on a single chip.
    

### c) Advantages

- Better CPU utilization.
    
- Hides memory latency by switching threads.
    
- Improves throughput for multi-threaded applications.
    

### d) Challenges

- Thread synchronization overhead.
    
- Shared resource contention.
    
- Requires multi-threaded software support.
    

---

## 3. Process Level Parallelism (PLP)

PLP involves executing **multiple independent processes** simultaneously across multiple cores or processors.

### a) Definition

Each process has its **own address space, memory, and resources**, unlike threads that share the same space.

### b) Techniques for PLP

- **Multiprocessing Systems:** Multiple CPUs executing separate processes.
    
- **Distributed Systems / Clusters:** Independent systems working on different tasks.
    
- **Parallel Execution in OS:** Scheduling multiple processes across processors.
    

### c) Advantages

- High reliability (one process crash doesn’t affect others).
    
- Efficient for large-scale parallel workloads.
    
- Suitable for independent or loosely coupled tasks.
    

### d) Challenges

- Inter-process communication (IPC) overhead.
    
- Load balancing across processors.
    

---

## 4. Comparison

|Feature|ILP|TLP|PLP|
|---|---|---|---|
|Unit of Parallelism|Instruction|Thread|Process|
|Hardware Requirement|Superscalar CPU|Multicore/SMT CPU|Multiprocessor/Cluster|
|Resource Sharing|Same core|Shared memory|Independent memory|
|Speedup Type|Fine-grained|Medium-grained|Coarse-grained|
|Example|Out-of-order execution|Multithreading|Multi-programming|

---

## 5. Summary

- **ILP** enhances performance **within** a single core.
    
- **TLP** boosts throughput by running multiple threads concurrently.
    
- **PLP** increases system-level parallelism using multiple processes or CPUs.  
    Together, they form the foundation of **modern parallel computing architectures**.