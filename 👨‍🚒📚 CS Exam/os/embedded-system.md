---
description: Made By Me 💚
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

# Embedded System

## Embedded System Concepts

> Made For Texas Instruments

* **Real-Time Operating Systems (RTOS):** Learn how to work with RTOS, task scheduling, and inter-task communication.
* **Memory Management:** Understand stack, heap, and memory allocation in embedded systems.
* **Interrupt Handling:** Techniques for managing interrupts and prioritizing tasks.

#### Real-Time Operating Systems (RTOS)

**1. RTOS Basics**

**Definition:** A Real-Time Operating System (RTOS) is designed to handle real-time applications that require deterministic responses to events. Unlike general-purpose operating systems (GPOS), an RTOS provides predictability and ensures that critical tasks are completed within specified time constraints.

**Key Characteristics:**

* **Deterministic Behavior:** Guarantees a maximum time for each operation.
* **Task Priority:** Supports multiple levels of task priorities to ensure critical tasks are executed first.
* **Minimal Latency:** Offers low interrupt latency and fast context switching.
* **Concurrency:** Manages multiple tasks simultaneously, ensuring they meet their deadlines.

**Differences from GPOS:**

* **Scheduling:** RTOS uses priority-based preemptive scheduling, whereas GPOS often uses time-sharing scheduling.
* **Response Time:** RTOS guarantees predictable response times; GPOS does not.
* **Resource Management:** RTOS optimizes for real-time constraints; GPOS optimizes for throughput and fairness.

**2. Task Scheduling**

**Scheduling Mechanisms:**

* **Priority-Based Scheduling:** Tasks are assigned priorities, and the RTOS scheduler always picks the highest-priority task that is ready to run.
* **Preemptive Scheduling:** Higher-priority tasks preempt (interrupt) lower-priority tasks, ensuring critical tasks run as soon as they are ready.
* **Round-Robin Scheduling:** Used for tasks with the same priority, where each task is given a fixed time slice to execute.

**Types of Tasks:**

* **Periodic Tasks:** Execute at regular intervals.
* **Aperiodic Tasks:** Execute in response to external events or conditions.
* **Sporadic Tasks:** Execute irregularly but with a minimum inter-arrival time.

**Key Concepts:**

* **Context Switching:** The process of saving the state of a currently running task and loading the state of the next task to be executed.
* **Task States:** Common states include running, ready, blocked, and suspended.

**3. Inter-task Communication**

**Mechanisms:**

* **Semaphores:** Used to synchronize tasks or manage resource access. They can be binary (0 or 1) or counting (allowing multiple resources).
  * **Binary Semaphore:** Ensures mutual exclusion by allowing only one task to access a resource at a time.
  * **Counting Semaphore:** Manages a finite number of resources by counting available instances.
* **Mutexes (Mutual Exclusion):** Similar to binary semaphores but with priority inheritance to prevent priority inversion. Ensures only one task accesses a critical section at a time.
* **Message Queues:** Allow tasks to communicate by sending and receiving messages. Useful for passing data between tasks.
* **Events:** Enable tasks to wait for specific events or conditions. An event flag can be set by one task and waited on by another.

**Synchronization Issues:**

* **Deadlock:** Occurs when tasks wait indefinitely for resources held by each other.
* **Priority Inversion:** A lower-priority task holds a resource needed by a higher-priority task, causing the latter to wait.

**4. Timers and Interrupts**

**Timers:**

* **Software Timers:** Managed by the RTOS to create time delays or execute periodic tasks.
  * **One-Shot Timer:** Executes a task once after a specified delay.
  * **Periodic Timer:** Repeatedly executes a task at specified intervals.
* **Hardware Timers:** Utilize hardware timer peripherals to trigger interrupts or measure time intervals.

**Interrupts:**

* **Interrupt Handling:** RTOS manages interrupts to handle external events with minimal latency.
  * **Interrupt Service Routine (ISR):** A function that executes in response to an interrupt.
  * **Interrupt Priorities:** Higher-priority interrupts can preempt lower-priority ones, ensuring critical tasks are serviced promptly.

**Context Switching in Interrupts:**

* When an interrupt occurs, the RTOS saves the state of the current task, executes the ISR, and then restores the task state, possibly switching to a higher-priority task if needed.

**Key Points:**

* **Latency:** Time taken to respond to an interrupt.
* **Jitter:** Variation in response time, which should be minimized in real-time systems.

#### Memory Management in Embedded Systems

**1. Stack**

**Definition:** The stack is a region of memory that stores temporary data for function calls, such as local variables, return addresses, and function parameters. It operates on a Last-In-First-Out (LIFO) basis.

**Key Characteristics:**

* **Automatic Memory Allocation:** Memory for local variables is automatically allocated and deallocated.
* **Fixed Size:** The stack size is usually determined at compile time and is limited.
* **Fast Access:** Access to stack memory is very fast due to its contiguous allocation.
* **Function Call Management:** Manages the flow of function calls, return addresses, and local variables.

**Operations:**

* **Push:** Adds data to the top of the stack.
* **Pop:** Removes data from the top of the stack.

**Stack Overflow:** Occurs when the stack exceeds its allocated size, potentially causing program crashes or unpredictable behavior.

**2. Heap**

**Definition:** The heap is a region of memory used for dynamic memory allocation, where variables are allocated and freed manually at runtime.

**Key Characteristics:**

* **Dynamic Memory Allocation:** Memory can be allocated and deallocated as needed.
* **Variable Size:** Unlike the stack, the heap can grow and shrink based on the application's memory requirements.
* **Fragmentation:** Memory fragmentation can occur over time, leading to inefficient use of memory.
* **Slower Access:** Access to heap memory is slower compared to the stack due to the non-contiguous allocation.

**Operations:**

* **malloc/new:** Allocates a specified amount of memory from the heap.
* **free/delete:** Deallocates previously allocated memory, returning it to the heap.

**Heap Overflow:** Occurs when the heap runs out of available memory, leading to allocation failures.

**3. Memory Allocation in Embedded Systems**

**Static Allocation:**

* **Definition:** Memory allocation done at compile time.
* **Usage:** Used for global variables, static variables, and constants.
* **Pros:** Predictable and fast access.
* **Cons:** Inflexible, as the memory size is fixed at compile time.

**Dynamic Allocation:**

* **Definition:** Memory allocation done at runtime using the heap.
* **Usage:** Used for data structures with variable sizes, such as linked lists, trees, and large buffers.
* **Pros:** Flexible, allows efficient use of memory.
* **Cons:** Can lead to fragmentation, slower access, and requires careful management to avoid memory leaks.

**Memory Management Strategies:**

* **First-Fit:** Allocates the first available block of sufficient size.
* **Best-Fit:** Allocates the smallest block that fits the requested size.
* **Worst-Fit:** Allocates the largest available block to reduce fragmentation.

**Memory Management Techniques:**

* **Garbage Collection:** Automatically reclaims memory that is no longer in use. Rarely used in real-time embedded systems due to unpredictability.
* **Manual Management:** Programmers explicitly allocate and free memory. Common in embedded systems for precise control over memory usage.

**Common Issues:**

* **Memory Leaks:** Occur when allocated memory is not freed, leading to exhaustion of available memory.
* **Fragmentation:** Over time, memory may become fragmented, making it difficult to find contiguous blocks of memory.
* **Buffer Overflows:** Occur when writing more data to a buffer than it can hold, potentially leading to data corruption or security vulnerabilities.

**Best Practices for Memory Management in Embedded Systems**

* **Limit Dynamic Allocation:** Prefer static allocation where possible to avoid fragmentation and memory leaks.
* **Monitor Memory Usage:** Use tools and techniques to monitor and analyze memory usage during development and testing.
* **Handle Errors Gracefully:** Check the return values of memory allocation functions and handle errors appropriately.
* **Optimize Stack Usage:** Be mindful of stack size limitations and avoid deep recursion or large local variables.

#### Interrupt Handling in Embedded Systems

**1. Definition and Purpose**

**Definition:** Interrupts are signals that inform the processor of an event that needs immediate attention. They temporarily halt the current execution flow, saving the context, and executing a function called an Interrupt Service Routine (ISR) to handle the event.

**Purpose:** Interrupts allow the processor to respond quickly to critical events, such as hardware signals or timers, without polling for these events continuously.

**2. Types of Interrupts**

**Hardware Interrupts:** Generated by hardware devices (e.g., timers, I/O devices) to signal that they need attention. They are asynchronous and can occur at any time.

**Software Interrupts:** Generated by software instructions to request system services or trigger certain events within the software.

**Maskable Interrupts:** Can be enabled or disabled (masked) by the processor to control whether they should be handled or ignored temporarily.

**Non-Maskable Interrupts (NMI):** Cannot be disabled and must be handled immediately. Used for critical events like power failures or memory errors.

**3. Interrupt Service Routine (ISR)**

**Definition:** An ISR is a special function executed in response to an interrupt. It performs the necessary processing for the event and then returns control to the interrupted code.

**Characteristics:**

* **Short and Fast:** ISRs should be quick to minimize latency and avoid blocking other interrupts.
* **Non-blocking:** ISRs should not block or wait for events that might take time, as this can delay the handling of other interrupts.
* **Minimal State Change:** ISRs should alter as little of the system state as possible to avoid side effects.

**ISR Execution Steps:**

1. **Interrupt Occurs:** An event triggers an interrupt signal.
2. **Context Saving:** The current execution state (registers, program counter) is saved.
3. **ISR Execution:** The processor jumps to the ISR address and executes the ISR.
4. **Context Restoration:** The saved context is restored after the ISR execution.
5. **Resume Execution:** The processor resumes execution from the point where it was interrupted.

**4. Interrupt Latency and Response Time**

**Interrupt Latency:** The time taken from when an interrupt is generated to when the ISR starts executing. It includes the time for interrupt recognition, context saving, and jumping to the ISR.

**Response Time:** The total time taken from the interrupt generation to the completion of the ISR. It includes interrupt latency and the execution time of the ISR.

**Factors Affecting Latency and Response:**

* **ISR Length:** Longer ISRs increase response time.
* **Interrupt Nesting:** Handling multiple interrupts can increase latency.
* **Interrupt Priorities:** High-priority interrupts can preempt lower-priority ones, affecting latency.
* **Processor Speed:** Faster processors have lower latency.

**5. Interrupt Priorities and Nesting**

**Interrupt Priorities:**

* **Priority Levels:** Assigning priorities ensures critical interrupts are handled first.
* **Priority Inversion:** A higher-priority interrupt may be delayed by a lower-priority one, mitigated using techniques like priority inheritance.

**Interrupt Nesting:**

* **Nested ISRs:** Higher-priority interrupts can interrupt lower-priority ISRs.
* **Stack Usage:** Each nested interrupt uses stack space, increasing the need for careful stack management to avoid overflow.

**6. Interrupt Vector Table**

**Definition:** A table that holds the addresses of ISRs. Each entry corresponds to a specific interrupt and points to the ISR that handles that interrupt.

**Usage:**

* **Fixed Vector Table:** The table is located at a fixed memory address.
* **Relocatable Vector Table:** The table can be placed at different memory locations, offering flexibility in memory usage.

**7. Common Pitfalls and Best Practices**

**Common Pitfalls:**

* **ISR Length:** Long ISRs can delay the handling of other interrupts.
* **Blocking Operations:** ISRs should avoid blocking calls, such as waiting for I/O.
* **Shared Resources:** Improper handling of shared resources can lead to race conditions.

**Best Practices:**

* **Keep ISRs Short:** Perform minimal processing in ISRs, deferring lengthy operations to non-interrupt context.
* **Use Flags or Queues:** Communicate between ISRs and the main code using flags or queues to avoid blocking.
* **Proper Context Saving:** Ensure all necessary context is saved and restored correctly.
* **Prioritize Critical Tasks:** Assign appropriate priorities to interrupts based on their criticality.
* **Test and Debug:** Thoroughly test ISRs to ensure they handle interrupts correctly and efficiently.
