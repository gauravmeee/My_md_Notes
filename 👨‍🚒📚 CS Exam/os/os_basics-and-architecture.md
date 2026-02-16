---
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

# OS Basics & Architecture

***

## Operating System

> Made from the PDF Notes

### Introduction

**What is an Operating System**

A program that acts as an intermediary between the user and the computer hardware.

**Goals of Operating System:**

* Execute user programs and make solving user problems easier
* Make the computer system convenient to use
* Use the computer hardware in an efficient manner

### Computer System Structure

**Four components of a Computer System:**

1. **Hardware** – Provides basic computing resources
2. \==**Operating System** – Controls and coordinates use of hardware among various applications and users
3. **Application Programs** – Define how system resources are used to solve user problems
4. **Users**

**What Operating Systems Do**

Depends on the point of view:

* Users want convenience, ease of use, and good performance
* Shared computers (mainframe/minicomputers) must serve multiple users effectively
* Workstations have dedicated resources but often share others via servers
* Handheld systems prioritize usability and battery life due to limited resources
* Embedded systems may have no user interface but require reliable OS for operation

**Operating System Definition**

* \==**OS as a Resource Allocator:**
  * Manages all hardware and software resources
  * Handles conflicting requests to ensure fair and efficient use
* \==**OS as a Control Program:**
  * Controls program execution
  * Prevents errors and improper operations

**No Universally Accepted Definition** **Approximations:**

* **Vendor's View:**\
  "Everything a vendor ships as an OS" – practical but varies

**Core Component:**

* \==**Kernel:**
  * Always running
  * Manages hardware, memory, CPU, and I/O operations **Other Components:**
* \==**System Programs:**
  * Support system operations
  * Ship with the OS
* \==**Application Programs:**
  * Solve specific user tasks
  * Run on top of system programs and kernel

**Computer Startup**

**Bootstrap Program:**

* Loaded at power-up or reboot
* Stored in ROM/EPROM (**firmware**)
* Initializes system and loads OS kernel

**Computer System Organization**

* One or more CPUs and device controllers share a common bus
* Shared memory is accessed by all
* CPUs and devices run concurrently and compete for memory access

**Computer-System Operation**

* \==I/O devices and CPU execute concurrently
* Each device controller manages a specific device
* Each has a local buffer
* CPU transfers data between main memory and local buffers
* I/O happens between device and controller buffer
* Devices signal completion via **interrupts**

**Common Functions of Interrupts**

* Interrupt control transfers to the **interrupt service routine** via an **interrupt vector**
* Interrupt vector stores addresses of service routines
* System saves address of the interrupted instruction
* \==A **trap**/**exception** is a software-generated interrupt (error/user request)
* OS is **interrupt-driven**

**Interrupt Handling**

* \==OS preserves CPU state (registers + program counter)
* Determines type of interrupt:
  * **Polling**
  * **Vectored** interrupt system
* Each interrupt type has a dedicated handler code
