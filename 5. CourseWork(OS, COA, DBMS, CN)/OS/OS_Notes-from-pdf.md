
# Operating System
---
# Introduction


## What is an Operating System
A program that acts as an intermediary between a user of a computer and the computer hardware Operating system goals: 
- Execute user programs and make solving user problems easier 
- Make the computer system convenient to use 
- Use the computer hardware in an efficient manner

Computer System Structure
four components of Computer System
1. **Hardware** – provides basic computing resources  
2.  ==**Operating system** - Controls and coordinates use of hardware among various applications and users 
3.  **Application programs** – define the ways in which the system resources are used to solve the computing problems of the users  
4.  **Users** 

## What Operating Systems Do

Depends on the point of view: 
● Users want convenience, ease of use and good performance (Don’t care about resource utilization)
● But shared computer such as mainframe or minicomputer must keep all users happy 
● Users of dedicate systems such as workstations have dedicated resources but frequently use shared resources from servers 
● Handheld computers are resource poor, optimized for usability and battery life 
● Some computers have little or no user interface, such as embedded computers in devices and automobiles

## Operating System Definition 

- ==**OS is a resource allocator** 
	- Manages all resources
	- Decides between conflicting requests for efficient and fair resource use 

- ==**OS is a control program** 
	- Controls execution of programs to prevent errors and improper use of the computer


*No Universally Accepted Definition

**Approximations:**

- **Vendor's Perspective:**
    - "Everything a vendor ships when you order an operating system" is a practical, though imprecise, definition.
    - This definition can vary significantly depending on the vendor.

**Core Component:**

- ==**Kernel:**
    - "The one program running at all times on the computer" is referred to as the kernel.
    - The kernel is the core part of the OS responsible for managing system resources and hardware communication.

**Other Components:**

- ==**System Programs:**
    - These are programs that ship with the operating system.
    - They provide various functionalities to support the operation of the computer system.
- ==**Application Programs:**
    - These are programs designed to perform specific user-oriented tasks.
    - They run on top of the system programs and kernel.

## Computer Startup

**bootstrap program** is loaded at power-up or reboot 
- Typically stored in ROM or EPROM, generally known as **firmware**
- Initializes all aspects of system
- Loads operating system kernel and starts execution

### Computer System Organization

- One or more CPUs, device controllers connect through common bus providing access to shared memory
- Concurrent execution of CPUs and devices competing for memory cycles

## Computer-System Operation

- ==I/O devices and the CPU can execute concurrently
- Each device controller is in charge of a particular device type
- Each device controller has a local buffer
- CPU moves data from/to main memory to/from local buffers
- I/O is from the device to local buffer of controller
- Device controller informs CPU that it has finished its operation by causing an interrupt

## Common Functions of Interrupts
- Interrupt transfers control to the interrupt service routine generally, through the interrupt vector, which contains the addresses of all the service routines
- Interrupt architecture must save the address of the interrupted instruction
- ==A **trap** or **exception** is a software-generated interrupt caused either by an error or a user request
- An operating system is interrupt driven

## Interrupt Handling
- ==The operating system preserves the state of the CPU by storing registers and the program counter
- Determines which type of interrupt has occurred:
	- **polling**
	- **vectored** interrupt system 
- Separate segments of code determine what action should be taken for each type of interrupt

## Interrupt Timeline
