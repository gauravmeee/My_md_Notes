
# [# Texas Instruments Interview Experience for Embedded Software Intern (On-Campus)](https://www.geeksforgeeks.org/texas-instruments-interview-experience-for-embedded-software-intern-on-campus/)

**Test Format:**
- An online MCQ test with Aptitude section and Technical section
1. Mandatory Section with 20 questions to be attempted in 30 Minutes.
2. Technical Section: Number of questions and test duration varies with the domain(s) opted by candidates.

- Marking scheme: +1 mark for the correct answer, -0.25 marks for incorrect answer and 0 marks for un-attempted questions.

**Selection Process:**
1. Complete the registration process (post successful registration you will receive a confirmation mail).
2. Take the online test at the scheduled date and time
3. Candidates clearing the test will be shortlisted for the interviews
4. Candidates clearing the TI interviews will be made an offer
Here's a structured approach to preparing for your Texas internship test and interview:

### **Interview

- explain projects
- language C or C++?

- Reverse the digits of an integer
- How to Represent a hexadecimal in C
- Reverse a hexadecimal without using char data type
- Debug - Conditional statements and Loops
- Array vs Structure
- How to Declare a Structure
- Create a Linked list using the structure and reverse it
- What is a Volatile keyword In C
- Use of Switch Statement and how to use it
- What is an FSM and to Code an FSM with 3 States
- What is an Embedded System

<hr>

GPT Answers
#### **1. Explain Projects**
- Be ready to discuss your projects in detail. Focus on the problem statement, technologies used, challenges faced, and the solutions you implemented.

#### **2. Language: C or C++**
- Be prepared to answer questions in C or C++ based on the language you are most comfortable with.

#### Technical Questions

1. **Reverse the Digits of an Integer**
   - **C++ Example Code:**
     ```cpp
     #include <iostream>
     using namespace std;

     int reverseDigits(int num) {
         int reversed = 0;
         while (num > 0) {
             reversed = reversed * 10 + num % 10;
             num /= 10;
         }
         return reversed;
     }

     int main() {
         int number = 12345;
         cout << "Reversed Number: " << reverseDigits(number) << endl;
         return 0;
     }
     ```

2. **How to Represent a Hexadecimal in C**
   - Use the prefix `0x` for hexadecimal numbers.
     ```c
     int hexValue = 0x1A3F;
     ```

3. **Reverse a Hexadecimal without Using `char` Data Type**
   - Convert hexadecimal to decimal, reverse the digits, and convert back to hexadecimal.
     ```cpp
     #include <iostream>
     #include <sstream>
     using namespace std;

     string reverseHex(string hex) {
         stringstream ss;
         int num;
         ss << hex << std::hex << num;
         string reversedHex;
         while (num > 0) {
             reversedHex += (num % 16 < 10 ? '0' + num % 16 : 'A' + num % 16 - 10);
             num /= 16;
         }
         reverse(reversedHex.begin(), reversedHex.end());
         return reversedHex;
     }

     int main() {
         string hex = "1A3F";
         cout << "Reversed Hex: " << reverseHex(hex) << endl;
         return 0;
     }
     ```

4. **Debug: Conditional Statements and Loops**
   - Be familiar with syntax and logic errors in `if`, `else`, `for`, `while`, and `do-while` loops.

5. **Array vs Structure**
   - **Array:** Collection of elements of the same type.
   - **Structure:** Collection of elements of different types, used to group related variables.

6. **How to Declare a Structure**
   - **C Example:**
     ```c
     struct Person {
         char name[50];
         int age;
     };
     ```

7. **Create a Linked List Using the Structure and Reverse It**
   - **C++ Example Code:**
     ```cpp
     #include <iostream>
     using namespace std;

     struct Node {
         int data;
         Node* next;
     };

     Node* reverseList(Node* head) {
         Node* prev = nullptr;
         Node* current = head;
         Node* next = nullptr;
         while (current != nullptr) {
             next = current->next;
             current->next = prev;
             prev = current;
             current = next;
         }
         return prev;
     }

     int main() {
         Node* head = new Node{1, nullptr};
         head->next = new Node{2, nullptr};
         head->next->next = new Node{3, nullptr};

         head = reverseList(head);

         Node* temp = head;
         while (temp != nullptr) {
             cout << temp->data << " ";
             temp = temp->next;
         }
         return 0;
     }
     ```

8. **What is a `volatile` Keyword in C**
   - It indicates that the value of a variable may change at any time without any action being taken by the code the compiler finds nearby. It is often used with hardware registers.

9. **Use of `Switch` Statement and How to Use It**
   - It allows multi-way branching based on the value of an expression.
     ```c
     int x = 2;
     switch (x) {
         case 1:
             printf("One");
             break;
         case 2:
             printf("Two");
             break;
         default:
             printf("Default");
     }
     ```

10. **What is an FSM and to Code an FSM with 3 States**
    - **Finite State Machine (FSM):** A computational model with a finite number of states.
      ```cpp
      #include <iostream>
      using namespace std;

      enum State {START, PROCESSING, END};

      void fsm() {
          State currentState = START;
          while (true) {
              switch (currentState) {
                  case START:
                      cout << "Starting..." << endl;
                      currentState = PROCESSING;
                      break;
                  case PROCESSING:
                      cout << "Processing..." << endl;
                      currentState = END;
                      break;
                  case END:
                      cout << "Ending..." << endl;
                      return;
              }
          }
      }

      int main() {
          fsm();
          return 0;
      }
      ```

11. **What is an Embedded System**
    - A computer system with a dedicated function within a larger mechanical or electrical system. Examples include microcontrollers in appliances, automotive control systems, and industrial machines.

---

# [Embedded Software Engineer Interview](https://www.glassdoor.co.in/Interview/Texas-Instruments-Interview-RVW89447741.htm)

- Bitwise XOR questions and shifting bits questions
- Given 3 code snippets, which is best wrt the given architeture
- Just go through the bit masking questions and and also embedded systems topics if you are from CSE background
- In online test the questions were based on stack queue and registers.
- they mainly ask on resume projects they ask very detail and how embedded programming works and asked to take an example that how c++ works and learn everything mentioned in resume and they ask about area of and why .
- what is embedded and how it works . take a real life example to describe how a programming works
- What connection protocol/technique did you use to connect a development board with an external motor to drive a wheel.
- Implement Stack in C language.
- Started off with an introduction. Then the interviewer asked about my projects. Moving on he asked basics of bits manipulation i.e., bits bytes, hexadecimal number representation. At last, he asked to implement Stack in C.
- C code to implement Sorting Algorithm

---

## What Interviewers Look for in an Embedded Software Engineer

If you're an experienced embedded software engineer, you know that interviews can be nerve-wracking. You want to make sure that you [impress your interviewer and](https://www.interviewkickstart.com/blog/job-interview-tips-to-get-hired) demonstrate your skill set. But what exactly are they looking for?

[Embedded software engineer interview](https://www.interviewkickstart.com/companies/embedded-systems-engineer-interview-process) questions will depend on what the interviewer is looking for based on the role and company requirements. Interviewers will primarily try to uncover if you have the required skills to function as an [embedded software engineer](https://www.interviewkickstart.com/courses/embedded-software-engineering-interview-masterclass). Additionally, they will assess your skill level and whether you are a good cultural fit for the company.

### **Role of an Embedded Software Engineer**

An embedded software engineer develops code optimized for an embedded system to manage a hardware device. For example, [embedded software engineers are responsible](https://www.interviewkickstart.com/blog/embedded-systems-engineer-roles) for the development and maintenance of software that is embedded in devices such as pacemakers, cars, and thermostats.

[Embedded software is developed](https://www.interviewkickstart.com/blog/how-to-build-your-career-in-embedded-software-engineering) and used for a particular hardware system or platform, keeping end-user needs in mind. Because this software controls critical functions, embedded software engineers must have a strong understanding of both hardware and software design principles. They must also be able to write code that is both efficient and reliable. The role of an [embedded software engineer](https://www.interviewkickstart.com/blog/how-to-build-your-career-in-embedded-software-engineering) is challenging but also very rewarding.

_Learn more about the_ [_roles and responsibilities of an Embedded systems engineer_](https://www.interviewkickstart.com/blog/embedded-systems-engineer-roles) _here._

### **Skill Needed to Become an Embedded Software Engineer**

Embedded software engineer interview questions will be largely based on embedded software engineering skills. Here are some key skills requirements:

- Programming language expertise: C, C++, C#, Python
- Assembly Programming Language
- Real-time Operating Systems (RTOS)
- System-level designing and software development
-  Communication Protocols: SPI (Serial Peripheral Interface), 12C, GPIO (General Purpose Input Output), USB, Controller Area Network (CAN)
More:
- MATLAB
- ARM
- Software and Hardware programming at a low level
- Tensorflow, Linux, RISC-V, Zephyr; other open source technologies
- System of Chip (SoC) level software optimization - how to optimize memory, performance, and power
- Microcontrollers, latest MCUs, and Microprocessors
- Device Drivers
- Debugging
- Interrupt-driven design
- IoT technologies
- Data Structures

Embedded software engineer interview questions will be devised to discover your expertise in one or more key skills. Interviewers will also look for knowledge of both hardware and software design and embedded systems. You can take an in-depth look into the [skills required to become an Embedded systems engineer](https://www.interviewkickstart.com/companies/how-to-become-a-embedded-systems-engineer).

Embedded systems are being adopted at an increasing rate in various industries. As such, [embedded software technologies](https://www.interviewkickstart.com/blog/how-to-build-your-career-in-embedded-software-engineering) are ever-evolving. Ensure you stay updated on the latest skills and developments in this field to gain a competitive edge.

_Take a look at some_ [_Embedded Software Engineer Interview Prep Tips_](https://www.interviewkickstart.com/companies/embedded-systems-engineer-interview-prep) _here._

## Technical Embedded Software Engineer Interview Questions and Answers

Technical interview questions for embedded software engineers will vary depending on the role and the interviewer. Some common questions are as follows:

#### **Q1.** [**What is an embedded system**](https://www.interviewkickstart.com/blog/how-to-build-your-career-in-embedded-software-engineering)**?**

An embedded system is a computer system with hardware and software components designed to serve a dedicated function. For example, a smoke detector (fire alarm) can be considered an embedded system. It is made of hardware (sensors, speaker, etc.) and software that starts the alarm when the smoke is detected via sensors.

An embedded system could be designed to work as an independent system or as part of a large system. The smoke detector could be an example of an independent system. We can find several embedded systems in consumer electronics, automobiles, smart watches, household appliances, industrial equipment, and medical equipment.

Let’s understand the basic structure of an embedded system using a fire alarm:

- **Sensor**: The sensors (heat, smoke, or carbon monoxide sensors) measure and convert the physical quantity to an electrical signal.
- **A-D Converter**: To convert the analog signal sent by the sensor into a digital signal.
- **Processor & ASICs:** Processor and other ASICs run the instructions programmed to the fire alarm and process the sensor data by checking the values with the reference/threshold value to produce a suitable output (or no output).
- **D-A Converter**: To change the digital data fed by the processor to an analog signal. The actuators often require analog signals.
- **Actuator**: As directed by the output data from the processor, the actuator produces a physical signal, such as setting off the alarm, blinking LEDs, etc.  
      
    

![The basic structure of an embedded system using a fire alarm](https://cdn.prod.website-files.com/5d0dc87aac109e1ffdbe379c/651141c2248d9d9697303b9d_DbBLOxTwqf7UOq-WTv7gmmfPZrm5rAvwl-ZvBz6QQOZs5ZzCBNv8k2fQpo5POobSDqz9qb47_uAjyMuV5lgQP-QWRQ7sFISXjq1E50pPlVo_l_kvoddQSLGUym1QThE__KSGWC2R3Yyb7L3Whhhz80XyNqou7ekb.png)

#### **Q2. What is a spinlock?**

Spinlock is a synchronization mechanism used to access shared resources orderly by locking resources for a short amount. At the same time, other consumers wait in a spin (loop) until the shared resource is released/unlocked. For example, two threads named Thread-A and Thread-B would like to access a common resource named Resource-X.  

Let's say Thread-A requests spinlock to access a Resource-X:

If Thread-B is using Resource-X, Thread-A will be waiting in a loop until Thread-B releases/unlocks Resource-X.

If any thread does not use Resource-X, Thread-A will be allowed to acquire the spinlock, and all other threads will wait until Thread-A releases the lock.

A spinlock is a lock that causes a thread trying to acquire it to simply wait in a loop ("spin") while repeatedly checking whether the lock is available.

Because the thread is not performing any task despite being active, the use of this lock puts the thread in a busy waiting state. Spinlock held until explicitly released. However, in some implementations, spinlocks may be automatically released if the thread being waited on “goes to sleep” or blocks. Spinlock is useful in a multiprocessor system.

#### **Q3. What do we mean by virtual memory?**

Virtual memory is a memory addressing scheme that offers the illusion of having one large continuous addressing space for an application. Physically, the main memory can be smaller than the virtual memory address. Some virtual memory addresses physically correspond to the main memory, and other addresses physically correspond to the secondary memory.

There will be address translator implementation for the application to utilize one large contiguous address space. The address translation introduces an uncertain delay in the memory response. As a result, many embedded system microcontrollers do not implement virtual memory.

Virtual memory allows users to load multiple bigger-size processors than in the main memory. Now the operating system does not load complete processes into the memory; rather, it loads the different relevant parts of multiple processors into the main memory. Thus effectively using the memory and also increasing the CPU utilization between processes. The size of the virtual memory is determined by the addressing scheme of the given CPU instruction architecture and not by the size of the main memory.

![](https://cdn.prod.website-files.com/5d0dc87aac109e1ffdbe379c/636b496551a00d4a685ea0d5_Virtual_Memory.jpg)

Virtual memory is implemented using both software as well as hardware. It maps memory addresses that a program uses, known as virtual addresses, to physical addresses in the computer's memory. All of a process's memory references are virtual or logical addresses. These logical addresses are then dynamically translated to physical addresses during run time.

#### **Q4. What is your approach for debugging any issue in an embedded system?**

Debugging techniques are very specific to the issue and the system. However, the following is a generic step-by-step approach that can be applied to most embedded systems.

**1. Understand the system**

Understanding the system is always a good idea as it helps a lot in narrowing down the issue. You can start by asking a few basic questions, such as:

- What is the input to the system?
- What is the hardware underneath?
- What is the expected behavior from the system?
- What are the different states of the system (at a very high level)?  
      
    

![Debugging any issue in an embedded system](https://cdn.prod.website-files.com/5d0dc87aac109e1ffdbe379c/651141eca2dc726c97960d17_zrOnnSujgYg-j0HuoZSohEXsS38NXlRSriKPveVrCgOWlbpwSoueZZtHPWkWttVFg0N_61gaYrq3HwUPJMBgaoM2Jez87-8eqv01YHI-NJHm6Ozu_tBUI4M_vWJ7OKYFxkBs_nfvAAV9orj1G2OKOqI9ZmrCuLok.png)

Questions such as these can save a lot of time at various stages during debugging.

**2. Reproduce the issue**

Once you have a basic understanding of the system, you should try reproducing the issue. Hopefully, it is an issue that can be easily reproduced. If you can do these first two steps properly, finding the issue or debugging it becomes much easier.

**3. Add instrumentation/logging**

Once you can reduce the issue, the next step is to see if it's easy or hard to reproduce the issue. If it's an easy-to-reproduce issue, then you don't worry too much about what are certain scenarios during which you can reproduce the issue. But if it is hard to reproduce the issue, then sometimes just seeing when the issue reproduces usually gives you a clue.

In either of these cases, it is essential to add logging, some debug information, or add instrumentation (Oscilloscope, Signal Generator, Multimeter, etc.), depending on your system.

Now, tracking through the sequences of steps becomes much easier until the issue is reproduced.

In some systems, it's possible that you don't even have access to the signals. In such scenarios, you can try to look through the crash logs. You can then analyze the signals from the instruments or logs for a better understanding of the issue.

**4. Isolate the bug/system**

After finding where the issue is coming from, you can try to isolate the system (sub-system). You can then use divide-and-conquer techniques such as binary search to figure out the point where the bug is getting introduced.

**5. Apply quick fixes**

With all the information you gathered, try to form some hypotheses:

- This is the bug
- This is the module (sub-system) or line of code the bug is coming from
- Under these conditions; I can reproduce the issue (these conditions are causing the issue)

So now you can try applying quick fixes to counter the bug and iteratively see if the issue is reproducing again with the conditions identified earlier. If everything is working correctly, you can commit the changes and consider the bug fixed.

#### **Q5. Describe the role of the watchdog timer.**

Many microcontrollers have the watchdog timer feature (usually implemented with specific dedicated hardware). It can be used to check if the software running on the microcontroller is hung. Microcontrollers are designed to be stable and durable.

However, there are still many issues that can affect the stability of the hardware. An unhandled combination of software-side events may also occur. Both can cause microcontrollers to get "stuck or hang" either electrically or in an infinite loop in software.

A watchdog timer is a subsystem that must explicitly notify software that everything is running as expected at a certain time. If the watchdog is not receiving the expected notification, it will take some action, such as resetting the microcontroller or even the entire device. This is usually done periodically, and the watchdog timer will take action if it does not receive a notification after a configurable amount of time since the last notification.

#### **Q6. What is a livelock, and how is it different from a deadlock?**

First, let’s understand what a deadlock is. In a deadlock, you have two or more concurrent processes waiting for a resource, and one of the processes may be holding the resource. Assuming it's a unitary resource, one process is holding one resource, and the other is holding another resource, so they are both waiting for the other to release the resources while not letting the resources go from themself.

So, basically, in a deadlock, we have a ‘**hold and wait’** type of situation between the two processes. Both processes are doing this; therefore, they are in an embrace in which neither will let go so that the wait will be forever - this is what we define as a deadlock situation.

A live lock is the opposite of that. Instead of waiting, the processes try to get a resource, but the process is courteous, so it differs from taking the resource. These processes are not waiting and are running parallel. It means you check if any other process is active, and you assume it will also ask for the same resource, so you differ and back off from using (getting hold of) the resources. So when two processes differ from using the resources out of courtesy that the other process may need, it puts them in a livelock situation.

The loop here is that both processes keep checking for other activity and backing off. Now because they are concurrent, this thing can go on for a long time. None of the threads makes any progress which means they are locked.

To summarize, a deadlock is you're holding and waiting for the resources. But in a livelock, you differ forever from the resource, assuming some other active process will need it.

We can imagine a real-life example of livelock is when two people meet in a narrow hallway, and each of them tries to be polite by moving aside to let the other person pass. Still, they end up swaying from side to side without actually passing the hallway as they repeatedly move the same way at the same time.

To learn more about livelocks, check out our tutorial:

#### **Q7. What are the causes of the interrupt legacy?**

The first delay is usually caused by hardware: the interrupt request signal must be synchronous with the CPU clock. Depending on the synchronization logic, up to 3 CPU cycles may elapse before an interrupt request reaches the CPU core.

The CPU usually completes the current instruction, which may take several cycles. On most systems, the time-consuming instructions to get executed are divide, push-multiple, or memory-copy. In addition to the cycles required by the CPU, additional cycles are often required for memory accesses. On an ARM7 system, the **_STMDB SP!,{R0-R11, LR}_** instruction is typically a worst-case instruction consisting of 13 32-bit registers and takes 15 clock cycles.

The memory system might require additional cycles for wait states.

Upon completion of the current instruction, the CPU performs a mode switch or pushes registers on the stack. Modern processors such as ARM generally perform mode switching, which takes fewer CPU cycles than saving registers.

**Pipeline fill:** Most modern CPUs are pipelined. Instruction execution occurs at different stages of the pipeline. The instruction is executed when it reaches its final stage of the pipeline. Since the mode switch has flushed the pipeline, several more cycles are required to refill the pipeline.

#### **Q8. What are static memory allocation and dynamic memory allocation?**

**Memory Allocation:** Memory allocation is the process by which physical or virtual memory space is allocated to computer programs and services. It is done either before or during program execution. There are two types of memory allocation:

- **Static Memory Allocation:** Static allocation means that the object is declared with a static storage class or has an external or internal reference. It is initialized only once before the program starts, and its lifetime is for the duration of the program's execution. An example of static memory allocation is a global and static variable.
- **Dynamic Memory Allocation:** In C, many library functions, such as malloc, calloc or realloc, etc., are used for dynamic memory allocation. One problem with dynamically allocated memory is that the compiler doesn't destroy it itself; the user is responsible for freeing the allocated memory.

These memory management functions return a pointer to the allocated memory block, and the returned pointer points to the starting address of the allocated memory block. If no space is available, a null pointer is returned.

Here are some sample technical embedded software engineer questions that you can practice:

1. Explain inline functions
2. Explain buses in communication
3. Explain the troubleshooting process for embedded targets
4. Differentiate between component-based design and object-oriented design
5. Differentiate between mutexes and semaphores
6. Name some code testing tools
7. Name some of the latest technologies
8. How would you reduce interrupt latency?
9. What are model transformations?
10. Why would you need DMAC in ES?
11. Would you debug ISR using breakpoints?
12. Why do segmentation fault errors occur?
13. Write a program using the power-save super loop.
14. [Which software configuration tools are](https://www.interviewkickstart.com/blog/software-engineering-tools) you aware of?

### **C, C++, Embedded C Software Engineer Interview Questions**

In your embedded software engineer interview, you can be asked specific questions on C, C++, and Embedded C, such as:

#### **Q1. What are the type qualifiers in C Programming?**

It is a keyword applied to a data type, resulting in a qualified type. For example, **_const int_** is a qualified type representing a **constant integer**, whereas **const** is a type qualifier to specify that the value will not be changed. The following code declares a constant integer x and sets its value to 10. Now, if we attempt to change x’s value, the compiler will throw an error.  

Similarly, a **_volatile int_** is a qualified type representing a **volatile integer,** meaning its value can change by any external device or hardware. The following code declares a volatile integer y and set’s its initial value to 0, which can be modified.

As of 2014 and C11, there are the following four type-qualifiers in standard C:

- **_const_** (C89): The const keyword is compiler-enforced and says that the program cannot change the object’s value, making the object a nonmodifiable type.
- **_volatile_** (C89): A variable with a volatile-qualified type may be modified in ways the implementation is unaware of, or it may have other unanticipated side effects. The volatile keyword indicates that a value may change between different accesses, even if it does not appear to be modified.
- **_restrict_** (C99): This type of qualifier can be used in pointer declarations. By adding this type of qualifier, a programmer hints to the compiler that for the lifetime of the pointer, no other pointer will be used to access the object to which it points.
- **__Atomic_** (C11):  The latter has a private name to avoid clashing with user-defined names. **__Atomic_** is used to avoid the race condition if more than one thread attempts to update a variable simultaneously.

#### **Q2. What is the difference between a null pointer and a void pointer?**

A null pointer is essentially a null value assigned to a pointer of any data type, while a null pointer is a data type that remains void until it is assigned a data type address.

The data type of a pointer is stored in the memory location to which the pointer points. If you are unsure of the type of data stored in a particular memory location, you must create a void pointer.

A null pointer does not contain a reference to any variable/value; it is NULL, making it a null pointer.

**a void pointer is always of type void ***

These pointers are mainly used for dynamic memory allocation using the malloc(), calloc(), and realloc() functions. Here, the reserved memory block is a pointer to an empty pointer, and when the pointer value is returned, it must be explicitly cast to the specific type required.

#### **Q3. Explain the use of ‘volatile’ in Embedded C.**

A volatile keyword is a type qualifier in C applied to a variable when declared. It tells the compiler the variable may be modified in ways unknown to the implementation or have other unknown side effects. As a result, the compiler cannot make any assumptions about the variable's value. The optimizer must reload the variable every time it reads the value rather than keeping a copy in a register.

Let's take a look at the syntax:

To declare a variable as volatile, you must put the volatile keyword before or after the data type while defining the variable. Look at the following two variable declarations for a volatile unsigned 8-bit integer variable:

Now, it turns out that pointers to volatile variables are pretty common,

You can also declare a pointer to a volatile variable. The following declarations declare **_v_pot_** to be a pointer to a volatile unsigned 8-bit integer:

However, using a volatile pointer to non-volatile data is very rare; the following is the syntax for reference:

If you really must have a volatile pointer to a volatile variable, the following is the syntax for your reference:

#### **Q4. Why do we need infinite loops in embedded programming, and how do we code an infinite loop in Embedded C?**

As the name suggests, infinite loops repeat indefinitely and never terminate as long as the program is alive. In most other types of programming, infinite loops are created by mistake and don’t have many use cases. However, this is not the case with embedded programming.

Embedded systems are intended to run forever and serve a given task repeatedly. If the embedded system suddenly exits, it means it no longer serves the task it is designed for. If the embedded system completes a given task, it should go into a sleep mood instead of exiting altogether because the next time the task is needed, it should be able to wake up and resume the task.

This infinite loop contains the main instruction the embedded system should execute. You can take the Arduino program template, for example:

Now, let’s see how we create infinite loops in Embedded C.

The following is the definition of the infinite **_for_** loop. Here we don’t mention any of the parameters for initialization, condition, or increment/decrement for the loop.

Now, we'll look at how to use a while loop to create an infinite loop. The infinite while loop is defined as shown below. Here we hard code the **_while_** condition to **_true_**.

The **_do-while_** loop can also be used to create the infinite loop. The following is the syntax to create the infinite _do-while_ loop. Here again, we hard code the **_while_** condition to **_true_**.

#### **Q5. What do sizeof(int) return on 32-bit and 64-bit machines?**

According to the C-spec, an integer only needs to be able to represent this (-32767,32767) range of numbers. Essentially the C-spec only says that an integer has to be 16 bits or larger. But in practice, **_sizeof(int)_** will return you **4 bytes** on both 32-bit and 64-bit machines.

In other words, The C standard only specifies a minimum range for integer types guaranteed to be supported. An **_int_** is guaranteed to be able to hold (-32767,32767), which requires 16 bits (2 bytes). However, implementations can go beyond that minimum, as we see that many modern compilers make **_int_** 32-bit, i.e., **4 bytes.**

However, a **_long int_** might have a different size on a 32-bit or 64-bit machine. It is also possible that a **_long int_** might be different on Windows versus Linux machines. But on the other hand, **_long long int_** is consistently 64 bits but could be implemented as more.

To learn more about it, watch our tutorial:

These are some sample C, C++, and Embedded C software engineer questions that you can practice:

1. How many storage classes are there in C?
2. How do you write Function Itoa()

---

# [Technical - C](https://placement.freshersworld.com/texas-instruments-placement-papers/technical-c/33135194)

1. Can we declare a static function as virtual?  
    Ans: No. The virtual function mechanism is used on the specific object that determines which virtual function to call. Since the static functions are not any way related to objects, they cannot be declared as virtual.
    
2. Can user-defined object be declared as static data member of another class?  
    Ans: Yes. The following code shows how to initialize a user-defined object.  
    #include  
    class test  
    {  
    int i ;  
    public :  
    test ( int ii = 0 )  
    {  
    i = ii ;  
    }  
    };  
    class sample  
    {  
    static test s ;  
    };  
    test sample::s ( 26 ) ;  
    Here we have initialized the object s by calling the one-argument constructor. We can use the same convention to initialize the object by calling multiple-argument constructor.
    
3. What is forward referencing and when should it be used?  
    Ans: Consider the following program:  
    class test  
    {  
    public :  
    friend void fun ( sample, test ) ;  
    };  
    class sample  
    {  
    public :  
    friend void fun ( sample, test ) ;  
    };  
    void fun ( sample s, test t )  
    {  
    // code  
    }  
    void main( )  
    {  
    sample s ;  
    test t ;  
    fun ( s, t ) ;  
    }  
    This program would not compile. It gives an error that sample is undeclared identifier in the statement friend void fun ( sample, test ) ; of the class test. This is so because the class sample is defined below the class test and we are using it before its definition. To overcome this error we need to give forward reference of the class sample before the definition of class test. The following statement is the forward reference of class sample. Forward referencing is generally required when we make a class or a function as a friend.
    
4. The istream_withassign class has been derived from the istream class and overloaded assignment operator has been added to it. The _withassign classes are much like their base classes except that they include overloaded assignment operators. Using these operators the objects of the _withassign classes can be copied. The istream, ostream, and iostream classes are made uncopyable by making their overloaded copy constructor and assignment operators private.
    
5. How do I write my own zero-argument manipulator that should work same as hex?  
    Ans: This is shown in following program.  
    #include  
    ostream& myhex ( ostream &o )  
    {  
    o.setf ( ios::hex) ;  
    return o ;  
    }  
    void main( )  
    {  
    cout << endl << myhex << 2000 ;  
    }
    
6. We all know that a const variable needs to be initialized at the time of declaration. Then how come the program given below runs properly even when we have not initialized p?  
    #include  
    void main( )  
    {  
    const char *p ;  
    p = "A const pointer" ;  
    cout << p ;  
    }  
    Ans: The output of the above program is 'A const pointer'. This is because in this program p is declared as 'const char*' which means that value stored at p will be constant and not p and so the program works properly
    
7. How do I refer to a name of class or function that is defined within a namespace?  
    Ans: There are two ways in which we can refer to a name of class or function that is defined within a namespace: Using scope resolution operator through the using keyword. This is shown in following example:  
    namespace name1  
    {  
    class sample1  
    {  
    // code  
    };  
    }  
    namespace name2  
    {  
    class sample2  
    {  
    // code  
    };  
    }  
    using namespace name2 ;  
    void main( )  
    {  
    name1::sample1 s1 ;  
    sample2 s2 ;  
    }  
    Here, class sample1 is referred using the scope resolution operator. On the other hand we can directly refer to class sample2 because of the statement using namespace name2 ; the using keyword declares all the names in the namespace to be in the current scope. So we can use the names without any qualifiers.
    
8. While overloading a binary operator can we provide default values?  
    Ans: No!. This is because even if we provide the default arguments to the parameters of the overloaded operator function we would end up using the binary operator incorrectly. This is explained in the following example:  
    sample operator + ( sample a, sample b = sample (2, 3.5f ) )  
    {  
    }  
    void main( )  
    {  
    sample s1, s2, s3 ;  
    s3 = s1 + ; // error  
    }
    
9. How do I carry out conversion of one object of user-defined type to another?  
    Ans: To perform conversion from one user-defined type to another we need to provide conversion function. Following program demonstrates how to provide such conversion function.  
    class circle  
    {  
    private :  
    int radius ;  
    public:  
    circle ( int r = 0 )  
    {  
    radius = r ;  
    }  
    };  
    class rectangle  
    {  
    private :  
    int length, breadth ;  
    public :  
    rectangle( int l, int b )  
    {  
    length = l ;  
    breadth = b ;  
    }  
    operator circle( )  
    {  
    return circle ( length ) ;  
    }  
    };  
    void main( )  
    {  
    rectangle r ( 20, 10 ) ;  
    circle c;  
    c = r ;  
    }  
    Here, when the statement c = r ; is executed the compiler searches for an overloaded assignment operator in the class circle which accepts the object of type rectangle. Since there is no such overloaded assignment operator, the conversion operator function that converts the rectangle object to the circle object is searched in the rectangle class. We have provided such a conversion function in the rectangle class. This conversion operator function returns a circle object. By default conversion operators have the name and return type same as the object type to which it converts to. Here the type of the object is circle and hence the name of the operator function as well as the return type is circle.
    
10. How do I write code that allows to create only one instance of a class?  
    Ans: This is shown in following code snippet.  
    #include  
    class sample  
    {  
    static sample *ptr ;  
    private:  
    sample( )  
    {  
    }  
    public:  
    static sample* create( )  
    {  
    if ( ptr == NULL )  
    ptr = new sample ;  
    return ptr ;  
    }  
    };  
    sample *sample::ptr = NULL ;  
    void main( )  
    {  
    sample *a = sample::create( ) ;  
    sample *b = sample::create( ) ;  
    }  
    Here, the class sample contains a static data member ptr, which is a pointer to the object of same class. The constructor is private which avoids us from creating objects outside the class. A static member function called create( ) is used to create an object of the class. In this function the condition is checked whether or not ptr is NULL, if it is then an object is created dynamically and its address collected in ptr is returned. If ptr is not NULL, then the same address is returned. Thus, in main( ) on execution of the first statement one object of sample gets created whereas on execution of second statement, b holds the address of the first object. Thus, whatever number of times you call create( ) function, only one object of sample class will be available.
    
11. How do I write code to add functions, which would work as get and put properties of a class?  
    Ans: This is shown in following code.  
    #include  
    class sample  
    {  
    int data ;  
    public:  
    __declspec ( property ( put = fun1, get = fun2 ) )  
    int x ;  
    void fun1 ( int i )  
    {  
    if ( i < 0 )  
    data = 0 ;  
    else  
    data = i ;  
    }  
    int fun2( )  
    {  
    return data ;  
    }  
    };  
    void main( )  
    {  
    sample a ;  
    a.x = -99 ;  
    cout << a.x ;  
    }  
    Here, the function fun1( ) of class sample is used to set the given integer value into data, whereas fun2( ) returns the current value of data. To set these functions as properties of a class we have given the statement as shown below:  
    __declspec ( property ( put = fun1, get = fun2 )) int x ;  
    As a result, the statement a.x = -99 ; would cause fun1( ) to get called to set the value in data. On the other hand, the last statement would cause fun2( ) to get called to return the value of data.
    
12. How do I write code to make an object work like a 2-D array?  
    Ans: Take a look at the following program.  
    #include  
    class emp  
    {  
    public :  
    int a[3][3] ;  
    emp( )  
    {  
    int c = 1 ;  
    for ( int i = 0 ; i <= 2 ; i++ )  
    {  
    for ( int j = 0 ; j <= 2 ; j++ )  
    {  
    a[i][j] = c ;  
    c++ ;  
    }  
    }  
    }  
    int* operator[] ( int i )  
    {  
    return a[i] ;  
    }  
    };  
    void main( )  
    {  
    emp e ;  
    cout << e[0][1] ;  
    }  
    The class emp has an overloaded operator [ ] function. It takes one argument an integer representing an array index and returns an int pointer. The statement cout << e[0][1] ; would get converted into a call to the overloaded [ ] function as e.operator[ ] ( 0 ). 0 would get collected in i. The function would return a[i] that represents the base address of the zeroeth row. Next the statement would get expanded as base address of zeroeth row[1] that can be further expanded as *( base address + 1 ). This gives us a value in zeroth row and first column.
    
13. What are formatting flags in ios class?  
    Ans: The ios class contains formatting flags that help users to format the stream data. Formatting flags are a set of enum definitions. There are two types of formatting flags:  
    On/Off flags  
    Flags that work in-group  
    The On/Off flags are turned on using the setf( ) function and are turned off using the unsetf( ) function. To set the On/Off flags, the one argument setf( ) function is used. The flags working in groups are set through the two-argument setf( ) function. For example, to left justify a string we can set the flag as,  
    cout.setf ( ios::left ) ;  
    cout << "KICIT Nagpur" ;  
    To remove the left justification for subsequent output we can say,  
    cout.unsetf ( ios::left ) ;  
    The flags that can be set/unset include skipws, showbase, showpoint, uppercase, showpos, unitbuf and stdio. The flags that work in a group can have only one of these flags set at a time.
    
14. What is the purpose of ios::basefield in the following statement?  
    cout.setf ( ios::hex, ios::basefield ) ;  
    Ans: This is an example of formatting flags that work in a group. There is a flag for each numbering system (base) like decimal, octal and hexadecimal. Collectively, these flags are referred to as basefield and are specified by ios::basefield flag. We can have only one of these flags on at a time. If we set the hex flag as setf ( ios::hex ) then we will set the hex bit but we won't clear the dec bit resulting in undefined behavior. The solution is to call setf( ) as setf ( ios::hex, ios::basefield ). This call first clears all the bits and then sets the hex bit.
    
15. Can we get the value of ios format flags?  
    Ans: Yes! The ios::flags( ) member function gives the value format flags. This function takes no arguments and returns a long ( typedefed to fmtflags) that contains the current format flags.
    
16. Is there any function that can skip certain number of characters present in the input stream?  
    Ans: Yes! This can be done using cin::ignore( ) function. The prototype of this function is as shown below:  
    istream& ignore ( int n = 1, int d =EOF ) ;  
    Sometimes it happens that some extra characters are left in the input stream while taking the input such as, the ?\n? (Enter) character. This extra character is then passed to the next input and may pose problem.  
    To get rid of such extra characters the cin::ignore( ) function is used. This is equivalent to fflush ( stdin ) used in C language. This function ignores the first n characters (if present) in the input stream, stops if delimiter d is encountered.
    
17. Write a program that implements a date class containing day, month and year as data members. Implement assignment operator and copy constructor in this class.  
    Ans: This is shown in following program:  
    #include  
    class date  
    {  
    private :  
    int day ;  
    int month ;  
    int year ;  
    public :  
    date ( int d = 0, int m = 0, int y = 0 )  
    {  
    day = d ;  
    month = m ;  
    year = y ;  
    }  
    // copy constructor  
    date ( date &d )  
    {  
    day = d.day ;  
    month = d.month ;  
    year = d.year ;  
    }  
    // an overloaded assignment operator  
    date operator = ( date d )  
    {  
    day = d.day ;  
    month = d.month ;  
    year = d.year ;  
    return d ;  
    }  
    void display( )  
    {  
    cout << day << "/" << month << "/" << year ;  
    }  
    };  
      
    void main( )  
    {  
    date d1 ( 25, 9, 1979 ) ;  
    date d2 = d1 ;  
    date d3 ;  
    d3 = d2 ;  
    d3.display( ) ;  
    }
    
18. When should I use unitbuf flag?  
    Ans: The unit buffering (unitbuf) flag should be turned on when we want to ensure that each character is output as soon as it is inserted into an output stream. The same can be done using unbuffered output but unit buffering provides a better performance than the unbuffered output.
    
19. What are manipulators?  
    Ans: Manipulators are the instructions to the output stream to modify the output in various ways. The manipulators provide a clean and easy way for formatted output in comparison to the formatting flags of the ios class. When manipulators are used, the formatting instructions are inserted directly into the stream. Manipulators are of two types, those that take an argument and those that don?t.
    
20. What is the difference between the manipulator and setf( ) function?  
    Ans: The difference between the manipulator and setf( ) function are as follows:  
    The setf( ) function is used to set the flags of the ios but manipulators directly insert the formatting instructions into the stream. We can create user-defined manipulators but setf( ) function uses data members of ios class only. The flags put on through the setf( ) function can be put off through unsetf( ) function. Such flexibility is not available with manipulators.
    
21. How do I get the current position of the file pointer?  
    Ans: We can get the current position of the file pointer by using the tellp( ) member function of ostream class or tellg( ) member function of istream class. These functions return (in bytes) positions of put pointer and get pointer respectively.
    
22. What are put and get pointers?  
    Ans: These are the long integers associated with the streams. The value present in the put pointer specifies the byte number in the file from where next write would take place in the file. The get pointer specifies the byte number in the file from where the next reading should take place.
    
23. What do the nocreate and noreplace flag ensure when they are used for opening a file?  
    Ans: nocreate and noreplace are file-opening modes. A bit in the ios class defines these modes. The flag nocreate ensures that the file must exist before opening it. On the other hand the flag noreplace ensures that while opening a file for output it does not get overwritten with new one unless ate or app is set. When the app flag is set then whatever we write gets appended to the existing file. When ate flag is set we can start reading or writing at the end of existing file.
    
24. What is the limitation of cin while taking input for character array?  
    Ans: To understand this consider following statements,  
    char str[5] ;  
    cin >> str ;  
    While entering the value for str if we enter more than 5 characters then there is no provision in cin to check the array bounds. If the array overflows, it may be dangerous. This can be avoided by using get( ) function. For example, consider following statement,  
    cin.get ( str, 5 ) ;  
    On executing this statement if we enter more than 5 characters, then get( ) takes only first five characters and ignores rest of the characters. Some more variations of get( ) are available, such as shown below:  
    get ( ch ) ? Extracts one character only  
    get ( str, n ) ? Extracts up to n characters into str  
    get ( str, DELIM ) ? Extracts characters into array str until specified delimiter (such as '\n'). Leaves delimiting character in stream.  
    get ( str, n, DELIM ) ? Extracts characters into array str until n characters or DELIM character, leaving delimiting character in stream.
    
25. What is the purpose of istream class?  
    Ans: The istream class performs activities specific to input. It is derived from the ios class. The most commonly used member function of this class is the overloaded >> operator which can extract values of all basic types. We can extract even a string using this operator.
    
26. Would the following code work?  
    #include  
    void main( )  
    {  
    ostream o ;  
    o << "Dream. Then make it happen!" ;  
    }  
    Ans: No! This is because we cannot create an object of the ostream class since its constructor and copy constructor are declared private.
    
27. Can we use this pointer inside static member function?  
    Ans: No! The this pointer cannot be used inside a static member function. This is because a static member function is never called through an object.
    
28. What is strstream?  
    Ans: strstream is a type of input/output stream that works with the memory. It allows using section of the memory as a stream object. These streams provide the classes that can be used for storing the stream of bytes into memory. For example, we can store integers, floats and strings as a stream of bytes. There are several classes that implement this in-memory formatting. The class ostrstream derived from ostream is used when output is to be sent to memory, the class istrstream derived from istream is used when input is taken from memory and strstream class derived from iostream is used for memory objects that do both input and output.  Ans: When we want to retrieve the streams of bytes from memory we can use istrestream. The following example shows the use of istrstream class.  
    #include  
    void main( )  
    {  
    int age ;  
    float salary ;  
    char name[50] ;  
    char str[] = "22 12004.50 K. Vishwanatth" ;  
    istrstream s ( str ) ;  
    s >> age >> salary >> name ;  
    cout << age << endl << salary << endl << name ;  
    cout << endl << s.rdbuf( ) ;  
    }  
    Here, s is the object of the class istrstream. When we are creating the object s, the constructor of istrstream gets called that receives a pointer to the zero terminated character array str. The statement s >> age >> salary >> name ; extracts the age, salary and the name from the istrstream object s. However, while extracting the name, only the first word of name gets extracted. The balance is extracted using rdbuf( ).
    
29. When the constructor of a base class calls a virtual function, why doesn't the override function of the derived class gets called?  
    Ans: While building an object of a derived class first the constructor of the base class and then the constructor of the derived class gets called. The object is said an immature object at the stage when the constructor of base class is called. This object will be called a matured object after the execution of the constructor of the derived class. Thus, if we call a virtual function when an object is still immature, obviously, the virtual function of the base class would get called. This is illustrated in the following example.  
    #include  
    class base  
    {  
    protected :  
    int i ;  
    public :  
    base ( int ii = 0 )  
    {  
    i = ii ;  
    show( ) ;  
    }  
    virtual void show( )  
    {  
    cout << "base's show( )" << endl ;  
    }  
    };  
    class derived : public base  
    {  
    private :  
    int j ;  
    public :  
    derived ( int ii, int jj = 0 ) : base ( ii )  
    {  
    j = jj ;  
    show( ) ;  
    }  
    void show( )  
    {  
    cout << "derived's show( )" << endl ;  
    }  
    };  
      
    void main( )  
    {  
    derived dobj ( 20, 5 ) ;  
    }  
    The output of this program would be:  
    base's show( )  
    derived's show( )
    
30. Can I have a reference as a data member of a class? If yes, then how do I initialise it?  
    Ans: Yes, we can have a reference as a data member of a class. A reference as a data member of a class is initialised in the initialisation list of the constructor. This is shown in following program.  
    #include  
    class sample  
    {  
    private :  
    int& i ;  
    public :  
    sample ( int& ii ) : i ( ii )  
    {  
    }  
    void show( )  
    {  
    cout << i << endl ;  
    }  
    };  
    void main( )  
    {  
    int j = 10 ;  
    sample s ( j ) ;  
    s.show( ) ;  
    }  
    Here, i refers to a variable j allocated on the stack. A point to note here is that we cannot bind a reference to an object passed to the constructor as a value. If we do so, then the reference i would refer to the function parameter (i.e. parameter ii in the constructor),which would disappear as soon as the function returns, thereby creating a situation of dangling reference.
    
31. Why does the following code fail?  
    #include  
    class sample  
    {  
    private :  
    char *str ;  
    public :  
    sample ( char *s )  
    {  
    strcpy ( str, s ) ;  
    }  
    ~sample( )  
    {  
    delete str ;  
    }  
    };  
    void main( )  
    {  
    sample s1 ( "abc" ) ;  
    }  
    Ans: Here, through the destructor we are trying to deal locate memory, which has been allocated statically. To remove an exception, add following statement to the constructor.  
    sample ( char *s )  
    {  
    str = new char[strlen(s) + 1] ;  
    strcpy ( str, s ) ;  
    }  
    Here, first we have allocated memory of required size, which then would get deal located through the destructor.
    
32. assert( ) macro...  
    We can use a macro called assert( ) to test for conditions that should not occur in a code. This macro expands to an if statement. If test evaluates to 0, assert prints an error message and calls abort to abort the program.  
    #include  
    #include  
    void main( )  
    {  
    int i ;  
    cout << "\nEnter an integer: " ;  
    cin >> i ;  
    assert ( i >= 0 ) ;  
    cout << i << endl ;  
    }
    
33. Why it is unsafe to deal locate the memory using free( ) if it has been allocated using new?  
    Ans: This can be explained with the following example:  
    #include  
    class sample  
    {  
    int *p ;  
    public :  
    sample( )  
    {  
    p = new int ;  
    }  
    ~sample( )  
    {  
    delete p ;  
    }  
    };  
    void main( )  
    {  
    sample *s1 = new sample ;  
    free ( s1 ) ;  
    sample *s2 = ( sample * ) malloc ( sizeof ( sample  
    ) ) ;  
    delete s2 ;  
    }  
    The new operator allocates memory and calls the constructor. In the constructor we have allocated memory on heap, which is pointed to by p. If we release the object using the free( ) function the object would die but the memory allocated in the constructor would leak. This is because free( ) being a C library function does not call the destructor where we have deal located the memory.  
      
    As against this, if we allocate memory by calling malloc( ) the constructor would not get called. Hence p holds a garbage address. Now if the memory is deal located using delete, the destructor would get called where we have tried to release the memory pointed to by p. Since p contains garbage this may result in a runtime error.
    
34. Can we distribute function templates and class templates in object libraries?  
      
    Ans: No! We can compile a function template or a class template into object code (.obj file). The code that contains a call to the function template or the code that creates an object from a class template can get compiled. This is because the compiler merely checks whether the call matches the declaration (in case of function template) and whether the object definition matches class declaration (in case of class template). Since the function template and the class template definitions are not found, the compiler leaves it to the linker to restore this. However, during linking, linker doesn't find the matching definitions for the function call or a matching definition for object creation. In short the expanded versions of templates are not found in  
    the object library. Hence the linker reports error.
    
35. What is the difference between an inspector and a mutator ?  
    Ans: An inspector is a member function that returns information about an object's state (information stored in object's data members) without changing the object's state. A mutator is a member function that changes the state of an object. In the class Stack given below we have defined a mutator and an inspector.  
      
    class Stack  
    {  
    public :  
    int pop( ) ;  
    int getcount( ) ;  
    }  
    In the above example, the function pop( ) removes top element of stack thereby changing the state of an ob

---

# [Texas Technical Questions](https://placement.freshersworld.com/texas-instruments-placement-papers/technical-database/33135241)


> **Texas Instruments**  
> 
>  Interview Procedure  
>   
> The test is followed by a Technical and a HR interview. The technical interview is highly specialized and covers almost all subjects you have done in your curriculum. Some puzzles may also be asked in the interview. Special emphasis is laid on C and Data Structures.  
>   
> Written Test paper there was 20 questions as follows in 60 minutes second part consists of 36 queue. in 30 minutes all questions are diagramatical.(figurs)..  
>   
> Texas

1. if a 5-stage pipe-line is flushed and then we have to execute 5 and 12 instructions respectively then no. of cycles will be  
    a. 5 and 12  
    b. 6 and 13  
    c. 9 and 16  
    d.none
    
2. k-map  
    ab  
    ----------  
    c 1 x 0 0  
    1 x 0 x  
    solve it  
      
    a. A.B  
    B. ~A  
    C. ~B  
    D. A+B
    
3. CHAR A[10][15] AND INT B[10][15] IS DEFINED WHAT'S THE ADDRESS OF A[3][4] AND B[3][4] IF ADDRESS OD A IS OX1000 AND B IS 0X2000  
      
    A. 0X1030 AND 0X20C3  
    B. OX1031 AND OX20C4  
    AND SOME OTHERS..
    
4. int f(int *a)  
    {  
    int b=5;  
    a=&b;  
    }  
      
    main()  
    {  
    int i;  
    printf("\n %d",i);  
    f(&i);  
    printf("\n %d",i);  
    }  
      
    what's the output .  
      
    1.10,5  
    2,10,10  
    c.5,5  
    d. none
    
5. main()  
    {  
    int i;  
    fork();  
    fork();  
    fork();  
    printf("----");  
    }  
      
    how many times the printf will be executed .  
    a.3  
    b. 6  
    c.5  
    d. 8
    
6. void f(int i)  
    {  
    int j;  
    for (j=0;j<16;j++)  
    {  
    if (i & (0x8000>>j))  
    printf("1");  
    else  
    printf("0");  
    }  
    }  
    what's the purpose of the program  
      
    a. its output is hex representation of i  
    b. bcd  
    c. binary  
    d. decimal
    
7. #define f(a,b) a+b  
    #define g(a,b) a*b  
      
    main()  
    {  
      
    int m;  
    m=2*f(3,g(4,5));  
    printf("\n m is %d",m);  
    }  
      
    what's the value of m  
    a.70  
    b.50  
    c.26  
    d. 69
    
8. main()  
    {  
    char a[10];  
    strcpy(a,"\0");  
    if (a==NULL)  
    printf("\a is null");  
    else  
    printf("\n a is not null");}  
      
    what happens with it .  
    a. compile time error.  
    b. run-time error.  
    c. a is null  
    d. a is not null.
    
9. char a[5]="hello"  
      
    a. in array we can't do the operation .  
    b. size of a is too large  
    c. size of a is too small  
    d. nothing wrong with it .
    
10. local variables can be store by compiler  
    a. in register or heap  
    b. in register or stack  
    c .in stack or heap .  
    d. global memory.
    
11. average and worst time complexity in a sorted binary tree is
    
12. a tree is given and ask to find its meaning (parse-tree)  
    (expression tree)  
    ans. ((a+b)-(c*d)) ( not confirmed)
    
13. convert 40.xxxx into binary .
    
14. global variable conflicts due to multiple file occurance  
    is resolved during  
    a. compile-time  
    b. run-time  
    c. link-time  
    d. load-time
    
15. two program is given of factorial. one with recursion and one without recursion .question was which program won't run for very big no. input because  
    of stack overfow .  
    a. i only (ans.)  
    b. ii only  
    c. i& ii both .  
    c. none
    
16. struct a  
    {  
    int a;  
    char b;  
    int c;  
    }  
    union b  
    {  
    char a;  
    int b;  
    int c;  
    };  
    which is correct .  
    a. size of a is always diff. form size of b.(ans.)  
    b. size of a is always same form size of b.  
    c. we can't say anything because of not-homogeneous (not in ordered)  
    d. size of a can be same if ...

---
# [Texas Technical 2 - C ](https://placement.freshersworld.com/texas-instruments-placement-papers/technical-c/33135193)

Texas Technical - C 

given an expression tree and asked us to write the in fix of that expression
four choices : 2

global variables in different files are
a:at compiletime
b) loading time
c) linking time
d)execution time

size of(int)
a) always 2 bytes
b) depends on compiler that is being used
c) always 32 bits
d) can't tell

which one will over flow given two programs
2 prog 1: prog2:
main() main()
{ {
int fact; int fact=0
long int x; for(i=1;i<=n;i++)
fact=factoral(x); fact=fact*i;
}}
int factorial(long int x)
{
if(x>1) return(x*factorial(x-1);
}
a) program 1;
b) program 2;
c) both 1 &2
d) none
}

variables of fuction call are allocated in
a) registers and stack
b) registers and heap
c) stack and heap
d)

avg and worst case time of sorted binary tree

data structure used for proority queue
a) linked list b) double linkedd list c)array d) tree

main(){
char str[5]="hello";
if(str==NULL) printf("string null");
else printf("string not null");
}
what is out put of the program?
a) string is null b) string is not null c) error in program d) it executes but print nothing

There are 0ne 5 pipe line and another 12 pipe line sates are there and flushed time taken to execute five instructions a) 10,17
b) 9,16
c)25,144
d)

for hashing which is best on terms of buckets
a)100 b)50 c)21 d)32 ans 32

void f(int value){
for (i=0;i<16;i++){
if(value &0x8000>>1) printf("1")
else printf("0");
}
}
what is printed?
a) bineray value of argument b)bcd value c) hex value d) octal value

void f(int *p){
static val=100;
val=&p;
}
main(){
int a=10;
printf("%d ",a);
f(&a);
printf("%d ",a);
}
what will be out put?
a)10,10

struck a{
int x;
float y;
char c[10];
}
union b{
int x;
float y;
char c[10];
}
which is true?
a) size of(a)!=sizeof(b);
b)
c)
d)

# define f(a,b) a+b
#defiune g(c,d) c*d
find valueof f(4,g(5,6))
a)26 b)51 c) d)

find avg access time of cache
a)tc*h+(1-h)*tm b)tcH+tmH
c) d) tc is time to access cache tm is time to access when miss occure

main()
{
char a[10]="hello";
strcpy(a,'\0');
printf("%s",a);
}
out put of the program?
a) string is null b) string is not null c) program error d)

simplyfy k map
1 x x 0
1 x 0 1

int f(int a)
{
a=+b;
//some stuff
}
main()
{
x=fn(a);
y=&fn;
what are x & y types
a) x is int y is pointer to afunction which takes integer value

char a[5][15];
int b[5][15];
address of a 0x1000 and b is 0x2000 find address of a[3][4] and b[3][4]
assume char is 8 bits and int is 32 bits
a) b) c) d)
there are 20 questions all in techinical paper and 36 questions in appititude test in appititude thay have given all diagrams and asked to find what comes next thay are quite easy and i hope if u practice r.s aggraval u can do it easily for tecnical thay have given 1 hr for 20 questions and for not technical thay have given only 40 min and 36 questions
this is the paper i have right now for TI aptitude test consist of all pictorial questions. ie in each question he will give 8 diagrams and ask to find th 9'th diagram in that sequence.You go through RS Agarwal. These aptitude questins are
very easy. Just pratice them. In RS Agarwal gothrough SERIES chapter. It is suffient. There are 35 aptitude
questions. First 25 are very easy. Do these questions in just 15 or 20 minutes. Because last questions are
very touch.

TECHNICAL TEST:
3 flipflops are connected so that after 0 to 5 count occured next number is zero. So what is the counter?
Ans: mod 6 counter

simplication of some boolean expression which is simple. Boolean Expression is A+A'B.
Ans:A+B

Given inorder sequence and preorder sequence and asked to find out postorder sequence.

Some question on value of a static variable.

Given an interger in binary form,find the number of ones in that number without counting each bit.(This questin is not multiple choice question. This question carries more marks. So please take care for this question.)

1-way set associative memory is called-----
a)direct b)something c)1-way set associative 4)something
Ans: c

Fastest IPC mechanism is
a)shared memory b)pipes c)named pipes d)semaphores
Ans:c 

Some page references are given. You are asked to implement it with Least Frequently Used algorithm.

Some diagram is given. Iam describinmg the diagram. A 2*1 MUX is given. The inputs are A,B. Output is C. C and A are tied together. What is the diagram.?
Ans:Latch.

This paper is for Electrical & Electronics students. There is separate test for computer Science Students. There are 20  questions.

 

1)Some circuit is given. Iam describing the circuit.A resistor R & a capacitor C are connected in parallel.
To this circuit another circuit which is having a capacitorof capacity 2C & an impedence Z, is connected in series.
You are asked to find out the value of Z? Note that 2C & Zare connected in series.
a)Z=2C
b)Z=2L
c)Z=L/2
d)Z=2R
Some circuit which consist of only resistors R is given. This is a repetative circuit. U have to find the effctive
resistance of the entire circuit.
A)Rin=R
B)Rin=(5+sqrt(3))/7
C)Rin=(19+sqrt(3))/8
D)None.

Two wave forms are given. You are asked to write the cirsuit to get B(second wave form) from A(first wave form).

#define SUM(a,b) a+b
main()
{
a=2;
b=3;
x=SUM(a,b)*2;
printf("x=%d\n",x);
}
Ans:8.

number(int i)
{
number++;
printf("%d\n",number);
}
main()
{
static int i=0;
number(i);
}
Ans: I don't know.

Some circuit is given. I can't describe the circuit. There are
3 resistors,3 capacitors & one inverter.. The question is
What is the value of the frequency such that the circuit oscillates.
A)f=RC
B)f=sqrt(3)/(Pi*R*C)
C)f=1/(Pi*R*C)
D)something
Ans:I don't know the answer.

7)Question on flipflop. So gothrough all flipflops.

8)There are 5 questions on Nmos & Pmos circuits.

This Paper is for Computer Science Students. THis paper is very easy. You can definitely do it in one hour.
 The fastest memory is
(i) DRAM, (ii) ROM, (iii) SRAM, (iv) Main memory
Ans : SRAM

 Programing exceptions are
(i) Asynchronous, (ii) Synchronous, (iii) None
Ans : Asynchronous

 DSP which architecture is used
(i) MIMD, (ii) SIMD, (iii) Nueman, (iv) Harvard Architecture
Ans : Harvard Architecture

 C prog. for searching for an element in linked list

 main()
{
unsigned char i;
int sum;
for(i=0; i<300; i++)
sum+ = i;
printf("\nSum = %d\n", sum);
}
Ans : infinite loop

 void fn(int *p)
{
static int val = 100;
p = &val;
}
main()
{
int i=10;
printf("i=%d\n", i);
fn(&i);
printf("i=%d\n", i);
}
Ans : i=10 i=10

 int a[10[15];
char b[10[15];
(a) location g a[3][4], if base location g a[0][0] is ox1000
(b) location g b[3][4], if base location g b[0][0] is ox2000
int taken 32 bits and char taken 8 bits.
Ans : (a) ox10C4 (b) ox2031

 Implement OR gate function with 2*1 MUX
Ans : A ___________
--------|2*1 MUX |
B | |--------o/p
--------| |
| -----------
|_______|C
B=C

 Implement 4*1 MUX with 2*1 MUXES

 Swapping without using a temporary variables. (2 methods)
(i) x = x+y;
y = x-y;
x = x-y;
(ii) x = x^y;
y = x^y;
x = x^y;

Count no of 1's in a word without using bit by bit. (This question carries more marks. It is not a multiple choice
question.

Code 1 :
for(i=0; i<1000; i++)
for(j=0; j<100; j++)
x = y;
Code 2 :
for(i=0; i<100; i++)
for(j=0; j<1000; j++)
x = y;
Which code will execute faster
(i) Code 1 and Code 2 are of same speed,
(ii) Code 1,
(iii) Code 2,
(iv) None.
Ans : Code 2

main()
{
int a[10] = {1, 2, 3, ...., 10}, i, x=10, temp;
for(i=0; itemp = a[i];
a[i] = a[x-i-1];
a[x-i-1] = temp;
}
(i) All contents of array a are reversed
(ii) Only some portions are altered
(iii) Remains same
(iv) None
Ans : (iii)

An array is stored in row major order. The memory capacity is 30 MB. And in unix system demand paging is used. Which one will give more page faults?
#define V_L_I 10000
int i, j, array[V_L_I][V_L_I];
Code 1 :
array[i][j] = 1;
Code 1 :
for(j=0; jfor(i=0; iarray[i][j] = 1;
Ans : Code 2

 In C which parameter passing technique is used?
(i) call by value,
(ii) call by reference,
(iii) both
Ans : call by value

A circuit is given with 2 exclusive OR gates whose boolean expression will be y = '(AB) + AB (' indicates bar)

(17) main()
{
int i = 1;
fork();
fork();
printf("\ni = %d\n", i+1);
}
Ans : 4 printfs will occur and i = 2

 Compute the complexity of Binary search.
Ans : O(lg n) ( Answer in detail. This is not a multiple choice question. It carries more marks.)
Write expression for the tree graph :
Ans : ((a-b) + c*d)/x
# define MAX(a, b) a>b ? a:b
main()
{
int m, n;
m = 3 + MAX(2, 3);
n = 2 * MAX(3, 2);
printf("m = %d, n = %d\n", m, n)
}
Ans : m=2, n=3