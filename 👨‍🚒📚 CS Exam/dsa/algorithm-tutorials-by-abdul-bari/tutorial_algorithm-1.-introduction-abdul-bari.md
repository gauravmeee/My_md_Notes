---
description: From Abdul Bari's Tutorials ▶️
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

# L1: Introduction

## [1. Introduction to Algorithms](https://www.youtube.com/watch?v=0IAPZzGSbME\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=1\&pp=iAQB)

**What is an Algorithm?**

* An algorithm is defined as a **step-by-step procedure for solving a computational problem**.

**Algorithm vs. Program: Key Differences**

| Feature                    | Algorithm                                                                                                                                                                                                                                                                                                                                                                                                                                   | Program                                                                                                                                                                      |
| -------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Development Phase**      | Written during the ==**design phase**== of the software development lifecycle. It involves planning and understanding what needs to be developed before actual construction.                                                                                                                                                                                                                                                                | Written during the ==**implementation phase**==. This is the actual development based on the design.                                                                         |
| **Purpose**                | Serves as a ==**design or blueprint== for the program**. It familiarises you with how your program is going to work. It helps avoid developing "useless" programs by ensuring a thorough design first.                                                                                                                                                                                                                                      | The ==**executable code**== that performs the defined task. It is run to check its functionality.                                                                            |
| **Language Used**          | Can be written in ==**simple English-like statements**== that are easy to understand, without proper syntax. It can also use **mathematical notations**. The language used must be understandable by the team, especially the programmers who will implement it. The speaker intends to use **C language syntax for writing algorithms** because it is widely known and understood, even at a school level, ensuring clarity for everybody. | Written using **specific programming languages** such as ==C, C++, Java, or Python.==                                                                                        |
| **Machine Dependence**     | **Hardware and operating system independent**. It does not depend on the machine's configuration or the OS (e.g., Linux or Windows).                                                                                                                                                                                                                                                                                                        | **Dependent on hardware and operating system**. You must select specific hardware and an operating system for the program to run, which affects the development environment. |
| **Who Writes It**          | Often written by individuals with **domain knowledge** about the problem and its solution. For example, an accountant for accounting software or a doctor for hospital applications. Programmers who also have domain knowledge can act as designers.                                                                                                                                                                                       | Primarily written by **programmers**, often university graduates familiar with programming languages like C.                                                                 |
| **Post-Creation Activity** | Algorithms are ==**analysed to determine their correctness and efficiency**== in terms of time and space.                                                                                                                                                                                                                                                                                                                                   | Programs are ==**tested by running them**== to check their functionality.                                                                                                    |

***

### [1.1 Priori Analysis and Posteriori Testing](https://www.youtube.com/watch?v=-JTq1BFBwmo\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=2\&pp=iAQB)

Two key terms used for evaluating algorithms and programs: **==Priori Analysis**== and ==**Posteriori Testing**.==

**Priori Analysis vs Posteriori Testing**

| Feature              | **Priori Analysis**                         | **Posteriori Testing**                            |
| -------------------- | ------------------------------------------- | ------------------------------------------------- |
| **Definition**       | ==Analysis of an algorithm==                | ==Testing of a program by executing it==          |
| **Done After**       | Algorithm is written (Design Phase)         | Program is written (Implementation Phase)         |
| **What is Measured** | ==Time== and ==space== functions            | Actual execution time and memory usage            |
| **Result Type**      | Functions (e.g., O(n), O(log n))            | ==Exact measured== values (e.g., 1.2 sec, 100 MB) |
| **Independence**     | Language & hardware ==independent==         | Language, OS & hardware ==dependent==             |
| **Purpose**          | ==Theoretical understanding== of efficiency | ==Practical evaluation== of performance           |

***

### [1.2 Characteristics of Algorithm](https://youtu.be/FbYzBWdhMb0?list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O)

Characteristics that every algorithm must possess to be considered valid and effective.

**1. Input**

* **Requirement**: An algorithm **must take some input**.
* **Quantity**: Algorithms can take ==**zero or more inputs**.==
  * _Explanation_: While most algorithms process some data, some might perform a task that doesn't explicitly require external input, for example, generating a sequence of numbers based on an internal rule.

**2. Output**

* **Requirement**: An algorithm ==**must generate at least one output**.==
* **Purpose**: If an algorithm doesn't produce a result, there's **no use in writing it**.
  * _Analogy_: This is likened to a C language function that, even if it has a `void` return type, still "does something" and produces a result of some kind.
  * _Explanation_: The objective of any procedure, including an algorithm, is to yield some result. For example, a chemistry experiment must obtain a solution, or a recipe must produce a dish.

**3. Definiteness**

* **Requirement**: **Every statement** in an ==algorithm **should be unambiguous**== and have a ==**single, exact meaning**.==
* **Clarity**: You **cannot write any statement that cannot be understood or solved**.
  * _Example_: You cannot use an "unknown value" like "root minus 1" (an imaginary number) as a real number in an algorithm.
  * _Explanation_: All steps performed within an algorithm must be **known steps**, with nothing left to "magical" interpretation.

**4. Finiteness**

* **Requirement**: An algorithm ==**must terminate at some point**.==
* **Limited Steps**: It must have a **finite set of statements**. Whether it has 10 statements or 10,000 statements, it **must eventually stop** and return a result.
  * _Contrast with Programs_: This characteristic distinguishes algorithms from certain programs (like database or web servers) that are designed to run continuously unless manually stopped.
  * _Analogy_: Similar to a function, an algorithm should have a limited set of steps and then stop and return the result.
  * _Explanation_: Just as cooking a dish or performing a chemical experiment stops once the objective is achieved, an algorithm must also have a definite end point.

**5. Effectiveness**

* **Requirement**: An algorithm ==**should not include unnecessary statements**.==
* **Purposeful Steps**: **Whatever statement you write, the objective is that it should do something** towards the purpose of the procedure.
  * _Explanation_: Every step taken should be productive and contribute to the intended outcome. For instance, in a recipe, you wouldn't boil a vegetable and then not use it in the dish. This ensures that the procedure is efficient and goal-oriented.

***

### [1.3 How Write and Analyze Algorithm](https://youtu.be/xGYsEqe9Vl0?list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O)

Practical aspects of creating and evaluating algorithms, covering how they are written and, crucially, the criteria and methods used for their analysis.

**How to Write an Algorithm**

* **Syntax and Language**:
  * Algorithms are written during the **design phase** of software development.
  * They can be written using ==**simple English-like statements**== that are easy to understand, without needing proper syntax.
  * \==**Mathematical notations** can also be used.==
  * While there's no fixed syntax, the goal is for the algorithm to be **understandable** by anyone involved in the project (e.g., designers, programmers).
  * Though language-independent, for practical purposes and ease of understanding, algorithms are often written using **C language syntax** because of its widespread familiarity.
  * **Minor details** related to programming languages, such as data types of parameters or variable declarations, are typically **not decided or bothered about** at the algorithm design time.
  * Alternatives to traditional code blocks (e.g., curly brackets) include `begin` and `end` keywords. Assignment symbols might also differ (e.g., Pascal's `:=`).

\*\*How to Analyze an Algorithm:

* Algorithm analysis is ==crucial for evaluating its efficiency==. The ==primary criteria for analysis are **time** and **space**.==

**1. Time Analysis**

* **Objective**: To determine **how much computational time** an algorithm takes. The goal is to devise ==**time-efficient (faster)**== procedures.
* **Result**: The analysis yields a **time function (F(n))**, not an exact time value (e.g., "three minutes"). This function expresses performance in terms of the input size 'n'. For very simple algorithms, the time function might be a constant value.
* **Assumption for Calculation**: **Every simple statement in an algorithm is ==assumed to take "one unit of time"**.==
  * A "simple statement" refers to direct, non-nested statements.
  * If a statement involves complex operations (e.g., `X = 5*A + 6*B`), it is still considered **one unit of time** for high-level analysis, without delving into its conversion to multiple machine code instructions.
  * If an algorithm calls another algorithm or procedure, that nested procedure also needs to be analyzed in detail. ==- **Frequency Count Method**:==
  * This method is used to determine the time complexity by ==calculating **how many times each statement executes**.==
  * **Example: Sum of Array Elements**
    * A simple statement like `sum = 0` executes once.
    * A `for` loop (e.g., `for(i=0; i<n; i++)`) involves:
      * Condition checking (e.g., `i<n`): `n+1` times.
      * Statements inside the loop (e.g., `sum = sum + arr[i]`): `n` times.
    * The time function for such an algorithm would be `F(n) = 2n + 1` (or `2n + 3` if all statements including initialization and final return are counted), which is considered **Order of N** (linear complexity).
  * **Example: Sum of Two N x N Matrices**
    * This typically involves nested loops. The outer loop executes `n+1` times, and for each iteration, the inner loop executes `n` times. Statements inside the innermost part execute `n` times.
    * The resulting time function will have a highest degree term of **n-squared** (e.g., `2n^2 + ...`), leading to an **Order of N-squared** (quadratic complexity).
  * **Example: Multiplication of Two N x N Matrices**
    * This involves three nested loops. The innermost statements execute `n*n*n` times, resulting in a time function with a highest degree term of **n-cubed** (e.g., `2n^3 + ...`). This leads to an **Order of N-cubed** (cubic complexity).

**2. Space Analysis**

* **Objective**: To determine **how much memory space** an algorithm will consume when run on a machine.
* **Assumption for Calculation**: ==**Each variable is assumed to take "one word"**== of space.
  * \=="Word" is used instead of "byte"== ==because the specific data type (e.g., integer, float, double) is not decided at the algorithm design phase.== ❓
* **Calculation**: Involves counting the parameters and local variables used by the algorithm.
* **Result**: The analysis yields a **space function (S(n))**.
  * For simple algorithms using a fixed number of variables, ==the space can be a **constant**== (e.g., 3 variables = 3 words = ==**Order of 1**==).
  * For algorithms that process arrays or matrices, the space complexity will depend on the size of these data structures. For example, an ==`N`-element array will require `N` words of space, leading to **Order of N** space== complexity. Similarly, an ==`N x N` matrix will require `N-squared` words, resulting in **Order of N-squared**== space complexity.

**3. Other Analysis Criteria**

* While time and space are the major criteria, other factors may be considered depending on the project or application's specific requirements:
* **Data Transfer / Network Consumption**: Important for internet-based, cloud-based, or network-intensive applications, assessing how much data is transferred.
* **Power Consumption**: Relevant for algorithms running on handheld devices like palm tops, laptops, and tablets.
* **CPU Register Consumption**: A concern when developing algorithms for device drivers or system-level programming, where CPU register usage can be critical.

***

### [1.4 Frequency Count Method](https://www.youtube.com/watch?v=1U3Uwct45IY\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=5\&pp=iAQB0gcJCccJAYcqIYzv)

Practical method for ==determining the time complexity of an algorithm==, known as the Frequency Count Method.

**Objective**:

* To find out the **time taken by an algorithm**. This is done by calculating **how many times each statement executes** within the algorithm.

**Methodology**:

1. **Assign Unit Time**: ==Every simple statement in the algorithm is assumed to take **one unit of time**.==
2. **Count Frequency**: For statements that repeat (e.g., inside loops), calculate their **frequency of execution**.
3. **Sum Frequencies**: Sum up the frequencies of all statements to derive the **time function F(n)**.

**Assumptions**:

* A "simple statement" is a direct, non-nested statement.
* Even if a statement involves multiple underlying machine operations (e.g., `X = 5*A + 6*B`), it is still considered **one unit of time** for this high-level analysis.
* If an algorithm calls another procedure, that nested procedure also needs detailed analysis.
* For **space analysis**, each variable is assumed to take **one "word"** of space (not bytes, as data types are not decided at the algorithm design phase).

**Examples and Analysis using Frequency Count**:

1. **Sum of All Elements in an Array (Order of N)**
   * `sum = 0;`: Executes **1 time**.
   * `for (i=0; i<n; i++)`:
     * Initialisation (`i=0`): **1 time**.
     * Condition check (`i<n`): **n + 1 times** (n times true, 1 time false).
     * Increment (`i++`): **n times**.
   * `sum = sum + arr[i];` (inside loop): Executes **n times**.
   * `return sum;`: Executes **1 time**.
   * **Time Function F(n)**:
     * Including initialisation and return: `1 + (n+1) + n + n + 1 = **3n + 3**`.
     * Commonly simplified in analysis (ignoring minor constant/lower-degree terms for simplicity): If considering only dominant terms for the loop, condition and body: `(n+1) + n = **2n+1**`.
   * **Time Complexity**: The highest degree of the polynomial is `n` (degree 1). So, the time complexity is **Order of N**.
   * **Space Complexity**:
     * Variables: `n` (for array size), `sum`, `i`. Total: `n + 1 + 1 + 1 = **n + 3 words**`.
     * Space Function S(n): `n + 3`.
     * **Space Complexity**: The highest degree is `n` (degree 1). So, the space complexity is **Order of N**.
2. **Sum of Two N x N Matrices (Order of N-squared)**
   * Involves **two nested loops**, each iterating `n` times.
   * Outer loop (`i`): Condition `n+1` times.
   * Inner loop (`j`): For each `i`, its condition runs `n+1` times. Since outer loop runs `n` times, total `n * (n+1)` times.
   * Statement inside innermost loop: Executes `n * n = n^2` times.
   * **Time Complexity**: The highest degree term will be `n^2`. The complexity is **Order of N-squared**.
   * **Space Complexity**:
     * Variables: `A` (N x N matrix), `B` (N x N matrix), `C` (N x N result matrix), `i`, `j`.
     * Space: `n^2` (for A) + `n^2` (for B) + `n^2` (for C) + `1` (for i) + `1` (for j) = `**3n^2 + 2 words**`.
     * **Space Complexity**: The highest degree is `n^2`. So, the space complexity is **Order of N-squared**.
3. **Multiplication of Two N x N Matrices (Order of N-cubed)**
   * Involves **three nested loops**, each iterating `n` times.
   * The innermost statement executes `n * n * n = n^3` times.
   * **Time Complexity**: The highest degree term will be `n^3`. The complexity is **Order of N-cubed**.
   * **Space Complexity**:
     * Variables: `A`, `B`, `C` (matrices), `i`, `j`, `k`.
     * Space: `3n^2 + 3 words`.
     * **Space Complexity**: The highest degree is `n^2`. So, the space complexity is **Order of N-squared**.

***

### 1.5 Time Complexity

#### [1.5.1 Time Complexity (1)](https://www.youtube.com/watch?v=1U3Uwct45IY\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=5\&pp=iAQB0gcJCccJAYcqIYzv)

Delves into the time complexity of various types of `for` loops.

**1. Linear Increment/Decrement Loops ==(Order of N)== $O(N)$**

* \==**Simple Increment**:==
  * `for (i=0; i<n; i++) { // statement }`
  * The statement inside the loop executes ==`n`== times. The condition `i<n` is checked `n+1` times.
  * **Complexity**: **Order of N**.
* **Simple Decrement**:
  * `for (i=n; i>0; i--) { // statement }`
  * Similar to incrementing, the loop executes ==`n` ==times.
  * **Complexity**: **Order of N**.
* \==**Increment by Constant Step**:==
  * `for (i=1; i<n; i+=2) { // statement }` (incrementing by 2)
  * The statement executes `n/2` times. The degree of ==`F(n) = n/2` is still `n`.==
  * **Complexity**: Even if incremented by a larger constant (e.g., `i+=20`), it's still **Order of N**. This is because constant coefficients are ignored in asymptotic notation.

**2. ==Standard Nested Loops== (Order of N-squared) ==`O(N^2)`==**

* `for (i=0; i<n; i++) { for (j=0; j<n; j++) { // statement } }`
* The outer loop executes `n` times, and for each iteration of the outer loop, the inner loop executes `n` times.
* The innermost statement executes ==`n * n = n^2` times.==
* **Complexity**: **Order of N-squared**.

**3. ==Nested Loops with Dependent Inner Loop== ==(Order of N-squared)== $O(N^2)$**

* `for (i=0; i<n; i++) { for (j=0; j<i; j++) { // statement } }`
* The number of times the inner statement executes depends on `i`:
  * When `i=0`, inner loop runs **0** times.
  * When `i=1`, inner loop runs **1** time (`j=0`).
  * When `i=2`, inner loop runs **2** times (`j=0, 1`).
  * ...
  * When `i=n-1`, inner loop runs **n-1** times.
* **Total executions**: `0 + 1 + 2 + ... + (n-1)` = ==`n * (n-1) / 2`.==
* **Time Function F(n)**: `n^2/2 - n/2`.
* **Complexity**: The highest degree is ==`n^2`==. So, it's **Order of N-squared**.

**4. Loops with Non-Linear Counter ==(Order of Root N)== $O(\sqrt N)$ ⭐⭐**

*   Consider a loop like:

    ```
    int P = 0;
    int I = 1;
    while (P < n) {
        P += I;
        I++;
    }
    ```
* The variable `P` accumulates values like `1`, `1+2=3`, `1+2+3=6`, `1+2+3+4=10`, etc. This is the sum of `I` up to a certain point.
* If the loop runs `k` times, `P` will be approximately `1 + 2 + ... + k = k * (k+1) / 2`.
* The loop stops when `P` becomes greater than or equal to `n`. So, `k * (k+1) / 2 >= n`.
* Roughly, `k^2 / 2 >= n`, which implies `k^2 >= 2n`, so ==`k >= sqrt(2n)`.==
* **Complexity**: ==The number of iterations `k` is proportional to **Root N (sqrt(n))**.==

#### [1.5.2 Time Complexity (2)](https://www.youtube.com/watch?v=9SgLBjXqwd4\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=7\&pp=iAQB)

Extends the analysis to loops where the counter variable is multiplied or divided.

**1. ==Multiplicative Increment== Loop ==(Order of Log N)== $O(\log\_2 N)$**

* `for (i=1; i<n; i*=2) { // statement }`
* The variable `i` takes values: `1, 2, 4, 8, ..., 2^k`.
* The loop terminates when `i` (which is `2^k`) becomes greater than or equal to `n`.
* So, `2^k >= n`. Taking `log2` on both sides, `k >= log2(n)`.
* **Number of iterations**: `k` is `log2(n)`.
* **Complexity**: **Order of Log N** (base 2).
  * **Note on Logarithm Base**: The base of the logarithm (e.g., base 2, base 3) does not change the overall order of complexity in asymptotic analysis. ==`log2(n)`== is asymptotically equivalent to `log3(n)`.
  * **Ceiling Function**: When `n` is not an exact power of the base, the number of executions will be `ceil(log_base(n))`. For example, `n=10`, `log2(10)` is approximately 3.32, but the loop executes 4 times (`1, 2, 4, 8` then `16` causes termination).

**2. ==Multiplicative Decrement== Loop ==(Order of Log N)== $O(\log\_2 N)$**

* `for (i=n; i>1; i/=2) { // statement }`
* The variable `i` takes values: `n, n/2, n/4, ..., n/2^k`.
* The loop terminates when `i` (which is `n/2^k`) becomes less than `1`.
* So, `n/2^k < 1`, which means `n < 2^k`, so `k > log2(n)`.
* **Number of iterations**: `k` is proportional to ==`log2(n)`.==
* **Complexity**: **Order of Log N** (base 2).

**3. ==Independent Loops== (Additive Complexity)**

* `for (i=0; i<n; i++) { ... }`
* `for (j=0; j<n; j++) { ... }`
* These loops are executed sequentially, not nested.
* Each loop has a complexity of **Order of N**.
* **Combined Complexity**: ==`N + N = 2N`.== In asymptotic analysis, constant coefficients are dropped, so the complexity is still **Order of N**.

**4. Complex Independent Loops (Log of Log N)**

* Consider two independent loops where one's output influences the other's range in a multiplicative way:
  * Outer loop: `for (I = 1; I <= N; I *= 2)` (This iterates `log N` times). Let `P` be a variable that takes values related to `I` or the number of iterations of this loop.
  * Inner loop: `for (J = 1; J <= P; J *= 2)` (This iterates `log P` times).
  * If `P` in the inner loop's condition is directly related to the _number of iterations_ of the outer loop (which is `log N`), then `P` can effectively be `log N`.
  * **Complexity**: The inner loop then executes `log(log N)` times. So, the overall time complexity is **Order of Log(Log N)**.

**5. ==Nested Loops== with ==One Multiplicative Counter== (Order of N Log N)**

* `for (i=0; i<n; i++) { for (j=1; j<n; j*=2) { // statement } }`
* Outer loop is a linear increment loop, running **Order of N** times.
* Inner loop is a multiplicative increment loop, running **Order of Log N** times for each iteration of the outer loop.
* **Combined Complexity**: ==`N * Log N`.== So, the complexity is **Order of N Log N**.

#### [1.5.3 Time Complexity of While and if (3)](https://www.youtube.com/watch?v=p1EnSvS3urU\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=8\&pp=iAQB)

Discusses how to analyze `while` loops and conditional (`if`) statements, and provides a broader context for loop analysis.

**1. While Loops vs. For Loops:**

* **C Language Flexibility**: In C, `while` loops and `for` loops are highly flexible and can often be interconverted without changing their time complexity.
* **Older Languages**: Historically, `for` loops in languages like Pascal had a more rigid structure (e.g., implicitly incrementing by 1), making `while` loops essential for more complex iteration patterns.
* **Analysis of While Loops**: Unlike simple `for` loops which might have a predictable `N` iterations, `while` loops require **thorough study of their termination condition and how variables change** to determine the number of iterations.

**Examples of While Loop Analysis**:

1. **Linear Increment (Order of N)**
   * `int I = 0; while (I < N) { I++; }`
   * This is a simple counter incrementing by 1. It executes `N` times.
   * **Complexity**: **Order of N**.
2. **Multiplicative Increment (Order of Log N)**
   * `int A = 1; while (A < B) { A *= 2; }`
   * Similar to the `i*=2` for loop example, `A` doubles each time until it reaches `B`.
   * **Complexity**: **Order of Log B** (or **Order of Log N** if `B` is the input size `N`).
3. **Multiplicative Decrement (Order of Log N)**
   * `int I = N; while (I > 1) { I /= 2; }`
   * Similar to the `i/=2` for loop example, `I` halves each time.
   * **Complexity**: **Order of Log N**.
4. **Non-Linear Summation (Order of Root N)**⭐
   * `int K = 1; int I = 1; while (K < N) { K += I; I++; }`
   * This is the same logic as the `P += I; I++;` example from 1.5.1. `K` accumulates sums `1, 1+2, 1+2+3, ...`.
   * The loop iterates `M` times where `K` is approximately `M * (M+1) / 2`.
   * The loop stops when `M^2` is roughly `N`, so `M` is roughly `sqrt(N)`.
   * **Complexity**: **Order of Root N**.
5. **Euclidean Algorithm for GCD (Worst Case: Order of N, Best Case: Order of 1)**
   * `while (M != N) { if (M > N) M -= N; else N -= M; }`
   * **Worst Case**: Occurs when one number is significantly larger than the other, and the smaller number is very small (e.g., `M=16, N=2`). In this scenario, the larger number is repeatedly decremented by the smaller one. If `N` is 1, it will take `M-1` subtractions.
     * **Complexity**: **Order of N** (where N is the larger of the two numbers).
   * **Best Case**: Occurs when `M` and `N` are already equal, or very close. The loop executes 0 or 1 time.
     * **Complexity**: **Order of 1** (constant time).

**2. Conditional Statements (`if-else`):**

* The presence of `if-else` can lead to **different execution times** depending on which branch is taken.
*   **Example**:

    ```
    if (N < 5) {
        // statement 1 (e.g., print N)
    } else {
        // loop for N times
    }
    ```

    * If `N < 5` (condition true): The program executes a single statement. **Time Complexity: Order of 1 (Best Case)**.
    * If `N >= 5` (condition false): The program executes a loop `N` times. **Time Complexity: Order of N (Worst Case)**.
* **Important Note**: An `if` statement doesn't inherently create "best/worst cases" unless it fundamentally alters the algorithm's iteration count or computation based on the input condition. If the `if` condition simply chooses between two fixed paths, it's analyzed based on the chosen path, not necessarily as a "case" in the performance sense

***

### [1.6 Classes of functions](https://www.youtube.com/watch?v=p1EnSvS3urU\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=8\&pp=iAQB)

**Types of time functions** or **time complexities** obtained from algorithm analysis. These are also referred to as "classes of functions" or "categories".

* **Constant (Order of 1)**:
  * **Description**: If an algorithm's time complexity is represented by a fixed numerical value (e.g., 2, 5, 5000), it belongs to the constant class.
  * **Meaning**: This means the execution time is **not dependent on the size of the input (n)**.
  * **Example**: `f(n) = 3`, `f(n) = 3000` are both considered `Order of 1`.
* **Logarithmic (Order of log n)**:
  * **Description**: When the time complexity is `log n` (regardless of the base, e.g., `log base 2` or `log base 3`), it's logarithmic.
  * **Meaning**: The growth rate is very slow, increasing slightly as `n` grows large.
  * **Examples**: Algorithms that repeatedly divide the input size in half (like binary search, as seen in earlier examples) often exhibit logarithmic time complexity.
* **Linear (Order of n)**:
  * **Description**: If the time function is a polynomial of degree 1 (e.g., `2n + 3`, `500n + 700`, `n/5000 + 6`), it's linear.
  * **Meaning**: The execution time grows **directly proportional to the input size `n`**.
  * **Example**: A simple loop iterating `n` times (e.g., linear search) is `Order of n`.
* **Quadratic (Order of n²)**:
  * **Description**: Algorithms with a time function that is a polynomial of degree 2 (e.g., `n²`) fall into this class.
  * **Meaning**: The execution time grows with the **square of the input size**.
  * **Example**: Matrix addition, which involves nested loops, can have `Order of n²` time complexity.
* **Cubic (Order of n³)**:
  * **Description**: Algorithms with a time function that is a polynomial of degree 3 (e.g., `n³`) belong here.
  * **Meaning**: The execution time grows with the **cube of the input size**.
  * **Example**: Matrix multiplication, involving three nested loops, often has `Order of n³` time complexity.
* **Exponential (Order of 2^n, 3^n, or n^n)**:
  * **Description**: Functions like `2^n`, `3^n`, or `n^n` represent exponential time complexity.
  * **Meaning**: This signifies a **very rapid growth** in execution time as the input size `n` increases. Algorithms with exponential complexity are generally considered inefficient for large inputs.

***

### [1.7 Compare Class of Functions](https://www.youtube.com/watch?v=5v-tKX2uRAk\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=10\&pp=iAQB)

**Comparing these classes of functions** based on their growth rate, arranging them in increasing order of "weight" or magnitude. This comparison is crucial for understanding which algorithms are more efficient, especially for large input sizes.

The **increasing order of growth** for common function classes is as follows:

* `Order of 1` (Constant)
* `Order of log n` (Logarithmic)
* `Order of root n` (Square Root)
* `Order of n` (Linear)
* `Order of n log n`
* `Order of n²` (Quadratic)
* `Order of n³` (Cubic)
* ... (and so on, `n^4`, `n^5`, up to `n^k` for any constant `k`)
* `Order of 2^n` (Exponential)
* `Order of 3^n` (Exponential)
* `Order of n^n` (Exponential)

**Key takeaways from the comparison**:

* **Slower Growth**: Functions like `log n`, `n`, `n log n`, and `n²` show a relatively slower growth compared to exponential functions.
* **Faster Growth (Exponential)**: `2^n` and `3^n` (and higher exponential powers like `n^n`) exhibit **extremely fast growth**. For large values of `n`, an exponential function will always be greater than any polynomial function, even `n^100`.
  * For example, when `n=8`:
    * `log n` is 3
    * `n` is 8
    * `n²` is 64
    * `2^n` is 256
  * The lecture shows that `2^n` can initially be smaller than some polynomial terms for very small `n` values, but **from a certain point onwards (for large values of n), `2^n` will always be greater and will grow at a much faster rate**.
* **Significance of Large 'n'**: When comparing functions for algorithm analysis, it is important to **imagine `n` as a very large number**, not just small values like 1 or 2 or 10. The asymptotic behaviour (how the function behaves as `n` approaches infinity) is what truly matters.
* **Graph Representation**: The growth rates can be visualized on a graph, where `2^n` would show a much steeper, almost vertical, increase compared to polynomial or logarithmic functions.
* **Importance of Order**: The arranged order of these function classes is **very important** as it helps in understanding the relative efficiency and scalability of different algorithms. An algorithm with `log n` complexity is generally much more efficient than one with `n²` or `2^n` complexity, especially for large inputs.

***

### 1.8 Asymptotic Notation

#### [1.8.1 Asymptotic Notations Big Oh - Omega - Theta (1)](https://www.youtube.com/watch?v=A03oI0znAoc\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=11\&pp=iAQB0gcJCccJAYcqIYzv)

**Asymptotic notations**, which are mathematical tools used to **represent the time complexity (or space complexity) of algorithms in a simplified, communicative form**. They show the "class" a function belongs to, helping us understand an algorithm's efficiency, especially for large inputs.

The three main asymptotic notations are:

* **Big O Notation (O): Upper Bound** (⭐ Used by us in Programming)
  * **Definition**: A function `f(n)` is `O(g(n))` if there exist positive constants `C` and `n0` such that **`f(n) ≤ C * g(n)` for all `n ≥ n0`**.
  * **Explanation**: `g(n)` serves as an ==**upper bound** for `f(n)`.== This means that for sufficiently large `n` (beyond `n0`), `f(n)` will always be less than or equal to `C` times `g(n)`.
  * **Example**: If `f(n) = 2n + 3`:
    * We can say `2n + 3 ≤ 5n` for `n ≥ 1` (here `C=5`, `g(n)=n`, `n0=1`).
    * Therefore, `f(n)` is **`O(n)`**.
    * The lecture stresses that technically, ==`O(n^2)` or `O(2^n)` would also be mathematically correct upper bounds for `2n + 3` (e.g., `2n + 3 ≤ 5n^2` is true== for large `n`). However, when using Big O, we should ==**always prefer to write the closest or tightest upper bound possible**== ⭐ for practical usefulness.
* **Big Omega Notation (Ω): Lower Bound**
  * **Definition**: A function `f(n)` is `Ω(g(n))` if there exist positive constants `C` and `n0` such that **`f(n) ≥ C * g(n)` for all `n ≥ n0`**.
  * **Explanation**: `g(n)` serves as a ==**lower bound** for `f(n)`==. For sufficiently large `n`, `f(n)` will always be greater than or equal to `C` times `g(n)`.
  * **Example**: If `f(n) = 2n + 3`:
    * We can say `2n + 3 ≥ 1n` for `n ≥ 0` (here `C=1`, `g(n)=n`, `n0=0`).
    * Therefore, `f(n)` is **`Ω(n)`**.
    * Similar to ==Big O, `Ω(log n)` would also be a valid== lower bound, ==but the **nearest function is the most useful**==. `Ω(n^2)` would be incorrect because `n^2` is not a lower bound for `2n+3`.
* **Theta Notation (Θ): Tight/Average Bound**
  * **Definition**: A function `f(n)` is `Θ(g(n))` if there exist positive constants `C1`, `C2`, and `n0` such that **`C1 * g(n) ≤ f(n) ≤ C2 * g(n)` for all `n ≥ n0`**.
  * **Explanation**: `g(n)` acts as both a ==**lower bound and an upper bound**==, effectively tightly bounding `f(n)`. This means `f(n)` grows at the same rate as `g(n)`.
  * **Example**: If `f(n) = 2n + 3`:
    * We can say `1n ≤ 2n + 3 ≤ 5n` for `n ≥ 1` (here `C1=1`, `C2=5`, `g(n)=n`, `n0=1`).
    * Therefore, `f(n)` is **`Θ(n)`**.
    * Unlike Big O and Big Omega, **Theta notation can only use `g(n)` that precisely matches the growth rate of `f(n)`**. For example, `Θ(n^2)` or `Θ(log n)` would be incorrect for `2n+3`.
    * **Theta notation is generally the most preferred and recommended** because it gives the most precise representation of an algorithm's asymptotic behaviour.
* **Important Clarification**: Asymptotic notations ==(Big O, Omega, Theta) are **not directly related to best-case, worst-case, or average-case analysis**== of an algorithm. ==They describe the growth rate of a _function_==, which could be the function representing the best, worst, or average case time, but the notations themselves don't imply the case.

| Notation | Name  | Use Case                                                                     |
| -------- | ----- | ---------------------------------------------------------------------------- |
| **O**    | Big-O | **Most used**: Describes **upper bound** (worst-case). Useful in guarantees. |
| Ω        | Omega | Describes **lower bound** (best-case). Rarely used in practice.              |
| Θ        | Theta | Describes **tight bound** (both best & worst same). Theoretically useful.    |

**Why Big-O is most used:** ⭐

* Focuses on **worst-case performance**, which is important in real-world scenarios.
* Helps in **guaranteeing performance limits**.
* Standard in **interviews, textbooks, industry**.

#### [1.8.2 Asymptotic Notations Big Oh - Omega - Theta (2)](https://www.youtube.com/watch?v=Nd0XDY-jVHs\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=12\&pp=iAQB)

Examples to solidify the understanding of asymptotic notations, especially focusing on cases where a tight bound (Theta) might not be easily definable.

* **Example 1: Polynomial Function**
  * `f(n) = 2n² + 3n + 4`
  * This function is `O(n²)`, `Ω(n²)`, and `Θ(n²)`, as `n²` is its dominant term and accurately bounds it from both sides.
* **Example 2: Combined Function**
  * `f(n) = n² log n + n`
  * This function is `O(n² log n)`, `Ω(n² log n)`, and `Θ(n² log n)`.
  * The term `n² log n` is dominant. It's noted that `n² log n` fits between `n²` and `n³` in the hierarchy of functions (i.e., `n² < n² log n < n³`).
* **Example 3: Factorial Function (`n!`)**
  * `n! = n * (n-1) * ... * 1`
  * **Upper Bound**: `n!` is `O(n^n)` because `n!` grows no faster than `n^n` (i.e., `1*2*...*n <= n*n*...*n`).
  * **Lower Bound**: `n!` is `Ω(1)` (or `Ω(2^n)` if you consider Stirling's approximation, but the video states `Ω(1)` by making terms `1*1*...*1`).
  * **Tight Bound (Theta)**: For `n!`, it's **not possible to find a `Θ(g(n))`** that fits it into a neat polynomial or standard exponential class. While it grows very fast, `n^n` is too loose, and simpler functions are too small. Thus, for `n!`, we typically express its bounds using `Big O` and `Big Omega` because a tight `Theta` notation cannot be easily defined or does not exist for common functions.
* **Example 4: Log of Factorial Function (`log(n!)`)**
  * `log(n!)` can be expanded using logarithm properties: `log(1*2*...*n) = log(1) + log(2) + ... + log(n)`.
  * **Upper Bound**: `log(n!)` is `O(n log n)`. This comes from approximating `log(n!)` as roughly `n log n - n`, so the dominant term is `n log n`.
  * **Lower Bound**: `log(n!)` is `Ω(1)` (or `Ω(n log n)` if using a tighter analysis, but video shows `Ω(1)` by setting lower bound of log to 0/1).
  * **Tight Bound (Theta)**: Similar to `n!`, a **tight `Theta` bound is not easily found** for `log(n!)` in common function classes.
* **Summary of Notation Usage**:
  * \==**Theta is always preferable** when it can be found because it gives the exact growth rate.==
  * \==**Big O and Big Omega are useful when a tight bound is difficult== or impossible to determine** (e.g., for `n!`) or when you only need to specify an upper or lower performance limit.
  * Even when using Big O or Big Omega, it is **best practice to provide the tightest possible bound** (e.g., for `2n+3`, `O(n)` is useful, `O(n^2)` is correct but less useful). The lecturer uses an analogy of quoting a mobile phone price: giving `£20,000` is useful, but `£2,000` (too low) or `£200,000` (too high) are correct but not meaningful.

***

### [1.9 Properties of Asymptotic Notations](https://www.youtube.com/watch?v=NI4OKSvGAgM\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=13\&pp=iAQB)

Several properties that asymptotic notations follow, which are derived from their mathematical definitions. These properties help in manipulating and understanding the relationship between functions.

* **General Property**:
  * If `f(n)` is `O(g(n))`, then `A * f(n)` is also `O(g(n))` for any positive constant `A`.
  * **Explanation**: Multiplying a function by a constant `A` does not change its asymptotic class or order of growth. This property holds true for **Big O, Big Omega, and Theta notations**.
  * **Example**: If `f(n) = 2n² + 5` is `O(n²)`, then `7 * f(n)` (which is `14n² + 35`) is also `O(n²)`.
* **Reflexive Property**:
  * A function `f(n)` is `O(f(n))`, `Ω(f(n))`, and `Θ(f(n))`.
  * **Explanation**: Any function is an upper bound, a lower bound, and a tight bound of itself. This is intuitive as `f(n)` is always `≤ 1*f(n)`, `≥ 1*f(n)`, and `between 1*f(n) and 1*f(n)`.
* **Transitive Property**:
  * If `f(n) = O(g(n))` and `g(n) = O(h(n))`, then `f(n) = O(h(n))`.
  * **Explanation**: If `f(n)` is bounded above by `g(n)`, and `g(n)` is bounded above by `h(n)`, then `f(n)` is also bounded above by `h(n)`. This property holds for **all three notations (Big O, Big Omega, and Theta)**.
  * **Example**: If `n` is `O(n²)`, and `n²` is `O(n³)`, then `n` is `O(n³)`.
* **Symmetric Property**:
  * If `f(n) = Θ(g(n))`, then `g(n) = Θ(f(n))`.
  * **Explanation**: If `f(n)` is tightly bounded by `g(n)`, it implies that `g(n)` is also tightly bounded by `f(n)`. This property is **only true for Theta notation**.
  * **Example**: If `n²` is `Θ(n²)`, then `n²` is `Θ(n²)`.
* **Transpose Symmetric Property**:
  * If `f(n) = O(g(n))`, then `g(n) = Ω(f(n))`.
  * **Explanation**: If `g(n)` is an upper bound for `f(n)`, then `f(n)` must be a lower bound for `g(n)`. This property is true for **Big O and Big Omega notations**.
  * **Example**: If `n` is `O(n²)`, then `n²` is `Ω(n)`.
* **Relationship between Notations**:
  * If `f(n) = O(g(n))` **AND** `f(n) = Ω(g(n))`, then `f(n) = Θ(g(n))`.
  * **Explanation**: If a function `f(n)` is bounded both from above and below by the same function `g(n)`, then `g(n)` is its tight bound. This formalizes why `Theta` is the most precise.
* **Properties for Operations on Functions**:
  * **Addition**: If `f(n) = O(g(n))` and `d(n) = O(e(n))`, then `f(n) + d(n) = O(max(g(n), e(n)))`.
    * **Explanation**: When adding two functions, the asymptotic complexity is determined by the function with the highest growth rate.
    * **Example**: If `f(n)` is `O(n)` and `d(n)` is `O(n²)`, then `f(n) + d(n)` (which is `n + n²`) is `O(max(n, n²))`, resulting in `O(n²)`.
  * **Multiplication**: If `f(n) = O(g(n))` and `d(n) = O(e(n))`, then `f(n) * d(n) = O(g(n) * e(n))`.
    * **Explanation**: When multiplying two functions, their asymptotic complexities also multiply.
    * **Example**: If `f(n)` is `O(n)` and `d(n)` is `O(n²)`, then `f(n) * d(n)` (which is `n * n²`) is `O(n * n²)`, resulting in `O(n³)`.

***

## 1.10 Comparison of Functions

#### [1.10.1 Comparison of Functions (1)](https://www.youtube.com/watch?v=mwN18xfwNhk\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=14\&pp=iAQB)

**Comparing mathematical functions**, which in the context of algorithms, often represent time or space complexities. The goal is to determine which function grows faster or which one is an upper/lower bound for the other.

Two primary methods for comparing functions are presented:

1. **Sampling Values (Plugging in `n` values)**:
   * For simple functions like `n²` and `n³`, you can substitute small values of `n` (e.g., 2, 3, 4) to observe their growth. For `n=2`, `n²=4` and `n³=8`. For `n=3`, `n²=9` and `n³=27`. This quickly shows that `n³` grows faster than `n²`.
   * This method is straightforward but may not be conclusive for all functions, especially complex ones, or for large `n` values where the initial behaviour might differ from the asymptotic one.
2. **Applying Logarithms**:
   * This method is particularly useful for **complex functions**.
   * By taking the logarithm of both functions, you can often simplify them and make their comparison easier.
   * **Key Logarithm Formulas (reiterated from lecture):**
     * `log(a * b) = log a + log b`
     * `log(a / b) = log a - log b`
     * `log(a^b) = b * log a` (power rule)
     * If `b = log_a n`, then `a^b = n`

* **Example 1: Compare `n² log n` and `(n log n)^10`**
  * Let `f(n) = n² log n` and `g(n) = (n log n)^10`.
  * Apply `log` to `f(n)`: `log(n² log n) = log(n²) + log(log n) = 2 log n + log(log n)`.
  * Apply `log` to `g(n)`: `log((n log n)^10) = 10 * log(n log n) = 10 * (log n + log(log n))`.
  * Comparing `2 log n + log(log n)` and `10 log n + 10 log(log n)`:
    * The dominant term on the left is `2 log n`.
    * The dominant term on the right is `10 log n`.
    * Clearly, `10 log n` is greater than `2 log n`. Therefore, `(n log n)^10` is greater than `n² log n`.
* **Example 2: Compare `3^√n` and `2^(√n log n)`**
  * Let `f(n) = 3^√n` and `g(n) = 2^(√n log n)`.
  * The term `2^(√n log n)` can be rewritten using the property `a^(b log_a c) = c^b`. Assuming `log` is base 2 here, `2^(√n log_2 n)` can be transformed to `n^√n`.
  * Now the comparison is between `3^√n` and `n^√n`.
  * If you take the `√n`-th root of both, you are comparing `3` and `n`.
  * For large `n`, `n` is much greater than `3`.
  * Therefore, `n^√n` (which is `2^(√n log n)`) is greater than `3^√n`.
  * **Important Note on Coefficients**: In asymptotic analysis, leading coefficients are generally ignored (e.g., `2n²` and `5n²` are both `O(n²)`). However, when a coefficient is in the **exponent** (like `2n` in `2^(2n)` which becomes `4^n`), it is significant and changes the growth rate.

#### [1.10.2 Comparison of Functions (2)](https://www.youtube.com/watch?v=WlBBTSL0ZRc\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=15\&pp=iAQB)

More examples of function comparison, particularly using the logarithm method.

* **Example 1: Compare `n^log n` and `2^√n`**
  * Let `f(n) = n^log n` and `g(n) = 2^√n`.
  * Apply `log` to `f(n)`: `log(n^log n) = (log n) * (log n) = (log n)²`.
  * Apply `log` to `g(n)`: `log(2^√n) = √n * log 2`. Assuming `log` is base 2, `log 2 = 1`, so it simplifies to `√n`.
  * Now compare `(log n)²` and `√n`.
  * If you are still unsure, you can apply `log` again (or consider the hierarchy of functions: `log n` grows slower than `n`). Since `(log n)²` is less than `n` for large `n`, and `√n` is `n^0.5`, `√n` will be greater than `(log n)²`.
  * Therefore, `2^√n` is greater than `n^log n`.
* **Example 2: Compare `2^n` and `4^n`**
  * This is straightforward. `4^n = (2^2)^n = 2^(2n)`.
  * Here, `2n` is greater than `n`. So, `4^n` is clearly greater than `2^n`.
  * The lecture warns **not to ignore coefficients in the exponent** because they significantly alter the growth rate (e.g., `2^n` vs `4^n` is a different class, not just a constant factor).
* **Example 3: Comparison of Piecewise Functions (`G1` vs `G2`)**
  * `G1(n)` is `n³` for `n < 100`, then `n²` for `100 ≤ n ≤ 10000`, then `n³` for `n > 10000`.
  * `G2(n)` is `n²` for `n < 10000`, then `n³` for `n > 10000`.
  * The key in asymptotic analysis is to consider behaviour for **large values of `n` (as `n` approaches infinity)**.
  * For `n` beyond `10000` (which is considered a "large" `n` in this context), `G2(n)` becomes `n³`, and `G1(n)` also becomes `n³`.
  * Therefore, for large `n`, `G2(n)` is effectively greater than `G1(n)` because `n³` dominates `n²`. **Asymptotically, `G2(n)` is greater than `G1(n)` from `n = 10000` onwards.**
* **True/False Statements on Asymptotic Notations:**
  * `(n+k)^n = Θ(n^n)`: **True**. Expanding `(n+k)^n` would result in terms where `n^n` is the dominant factor.
  * `2^(n+1) = Θ(2^n)`: **True**. `2^(n+1) = 2 * 2^n`. Since `2` is a constant coefficient, it doesn't change the asymptotic class.
  * `2^(2n) = O(2^n)`: **False**. `2^(2n) = (2^2)^n = 4^n`. `4^n` grows much faster than `2^n`, so `2^n` cannot be an upper bound (Big O) for `4^n`.
  * `√log n = O(log(log n))`: **False**. `√log n` is `(log n)^0.5`, while `log(log n)` grows much slower than any polynomial of `log n`. Thus, `log(log n)` cannot be an upper bound for `√log n`.
  * `n log n = O(n)`: **False**. `n log n` grows faster than `n`. So `n` cannot be an upper bound.
  * `n^log n = O(n)`: **False**. This means `n^log n` should be less than or equal to `C*n`. This is clearly not true as `log n` can be greater than 1 for `n > 2`.

***

### [1.11 Best Worst and Average Case Analysis](https://www.youtube.com/watch?v=lj3E24nnPjI\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=16\&pp=iAQB)

Different types of **performance analysis** for algorithms: best case, worst case, and average case. It's crucial to understand that these are **analysis types** and are **not directly related to asymptotic notations** (Big O, Omega, Theta). Any notation can be used to represent the complexity of any case (best, worst, or average).

1. **Linear Search Example:**
   * **Algorithm Description**: Linear search iterates through a list of `n` elements from left to right, comparing each element with the `key` until it's found or the list ends. A search can be successful or unsuccessful.
   * **Best Case**:
     * **Definition**: Occurs when the `key` element is found at the **first index** of the list.
     * **Time Analysis**: Requires only **one comparison**.
     * **Time Complexity**: **O(1)** (constant time).
   * **Worst Case**:
     * **Definition**: Occurs when the `key` element is found at the **last index** of the list, or when the `key` element is **not present** in the list at all.
     * **Time Analysis**: Requires checking **all `n` elements**.
     * **Time Complexity**: **O(n)** (linear time).
   * **Average Case**:
     * **Definition**: Defined as the **sum of times for all possible cases divided by the number of cases**.
     * **Time Analysis**: If the key is at the 1st index (1 comparison), 2nd index (2 comparisons), ..., `n`th index (`n` comparisons). Assuming equal probability for each position.
     * **Calculation**: `(1 + 2 + 3 + ... + n) / n = (n(n+1)/2) / n = (n+1)/2`.
     * **Time Complexity**: **O(n)** (linear time), as `(n+1)/2` is asymptotically linear.
     * **Note**: Average case analysis is often complex and rarely performed for every algorithm; worst-case analysis is frequently preferred as it gives an upper bound on performance.
2. **Binary Search Tree (BST) Example:**
   * **Algorithm Description**: A BST is a tree-based data structure where for every node, all smaller elements are in its left subtree, and all greater elements are in its right subtree. Searching involves traversing down the tree.
   * **Best Case**:
     * **Definition**: Occurs when the `key` element being searched for is the **root element** of the BST.
     * **Time Analysis**: Requires only **one comparison** (checking the root).
     * **Time Complexity**: **O(1)** (constant time).
   * **Worst Case**:
     * **Definition**: Occurs when the `key` element is found at a **leaf node**, requiring traversal down the longest path. The time taken depends on the **height (H)** of the binary search tree.
     * **Time Analysis**: The height of a BST can vary significantly based on its structure:
       * **Minimum Worst-Case Time**: Achieved in a **balanced BST** (e.g., a complete binary tree), where the height `H` is **logarithmic** (`log n`). Example time: `log 8 = 3` comparisons for 8 elements.
         * **Time Complexity**: **O(log n)**.
       * **Maximum Worst-Case Time**: Achieved in a **skewed BST** (e.g., a left-skewed or right-skewed tree), which resembles a linked list. Here, the height `H` can be **linear** (`n`).
         * **Time Complexity**: **O(n)**.
     * Therefore, the worst-case time for a BST search can range from `O(log n)` to `O(n)` depending on the tree's balance.

***

### [1.12 Disjoint Sets Data Structure - Weighted Union and Collapsing Find](https://www.youtube.com/watch?v=wU6udHRIkcc\&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O\&index=17\&pp=iAQB0gcJCccJAYcqIYzv)

**Disjoint Sets**, a ==data structure primarily used to manage a collection of non-overlapping (disjoint) sets==. They are particularly useful for **detecting cycles in undirected graphs**, a common application seen in algorithms like Kruskal's algorithm for finding Minimum Spanning Trees.

1. **What are Disjoint Sets?**
   * **Definition**: A collection of ==sets where no two sets have any common elements==. Their intersection is always an empty set.
   * **Representation**: Graphically, components of a non-connected graph can be represented as disjoint sets.
   * **Purpose**: While similar to mathematical sets, disjoint sets in algorithms are specifically tailored for efficient **Find** and **Union** operations, and for cycle detection.
2. **Core Operations**:
   * \==**Find(element)**: ==This operation determines which set a given element (or vertex) belongs to. It's essentially a "set membership" query.
   * \==**Union(set1, set2)**:== This operation merges two previously disjoint sets into a single set. In the context of graphs, if an edge (U, V) is added, and U belongs to Set1 and V belongs to Set2 (where Set1 and Set2 are different), then Union(Set1, Set2) is performed to combine them.

Example:

```
    (2)──────(3)
   ╱           ╲
(1)             (4)

(5)            (8)
   ╲           ╱
    (6)──────(7)

S1 = {1, 2, 3, 4}
S2 = {5, 6, 7, 8}
S1 ∩ S2 = ∅


        u                v
1. Find(4) -> S1  , Find(8) -> s2

- u & v belong to different sets.
- So, add edge (4,8) ✅
- Perform Union(S1, S2)  
- S3 = {1, 2, 3, 4, 5, 6, 7, 8}


2. Union(S1, S2) = S1 U S2 = { 1, 2, 3, 4, 5, 6, 7, 8}


    (2)──────(3)
   ╱           ╲
(1)             (4)
                 |
(5)            (8)
   ╲           ╱
    (6)──────(7)

S3 = {1, 2, 3, 4, 5, 6, 7, 8}

```

3. **Cycle Detection using Disjoint Sets**:
   * The ==primary purpose of Disjoint Sets== in graph algorithms is ==to detect cycles.==
   * **Mechanism**: If an edge (U, V) is considered for inclusion in a graph:
     * Perform `Find(U)` and `Find(V)` to identify the sets U and V belong to.
     * I==f `Find(U)` and `Find(V)` return **different sets**==, it means U and V are ==currently in different components==. In this case, perform `Union(Find(U), Find(V))` to merge their components, and include the edge.
     * \==If `Find(U)` and `Find(V)` return the **same set**==, it means U and V are already ==connected within the same component==. Adding the edge (U, V) would create a cycle. Therefore, this edge should not be included (e.g., in Kruskal's algorithm, this edge would be discarded).
   * The lecture demonstrates this step-by-step with an example graph, adding edges and performing unions to track components and detect cycles.

Example 1:

```
    (2)──────(3)
   ╱           ╲
(1)             (4)
                 |
(5)            (8)
   ╲           ╱
    (6)──────(7)

S3 = {1, 2, 3, 4, 5, 6, 7, 8}


- Find(1) -> S3  , Find(5) -> s3
- u & v belong to the same set.
- So, adding and extra edge (1,5) -> forms a cycle
- Find(1) == Find(5) -> Cycle Detected



Final Graph (Cycle formed):

    (2)──────(3)
   ╱           ╲
(1)             (4)
 |               |
(5)            (8)
   ╲           ╱
    (6)──────(7)
```

**Kruskal's algorithm** - is a greedy algorithm used to find a Minimum Spanning Tree (MST) or Minimum Spanning Forest (MSF) for a weighted, undirected graph. A Minimum Spanning Tree is a subset of the graph's edges that connects all the vertices with the minimum possible total edge weight, without forming any cycles.

Example 2 (Kruskal's Algorithm):

```
Complete notes


after diagram  |------------|
               |            |
               |            |
               |------------|
               |
               |
               |------------|
               |            |
               |            |
               |------------|
```

3. **Graphical Representation**:
   * Instead of abstract sets, disjoint sets are often represented as a **collection of trees (a forest)**.
   * \==Each tree represents a set,== and the ==**root of the tree is the representative** of that set==.
   * When performing `Union(Set1, Set2)`, the root of one tree is made a child of the root of the other tree, effectively merging the two trees into a single, larger tree.
4. **Array Representation**:
   * A single array, typically named `parent` (or `p`), is used to represent the disjoint sets.
   * `parent[i]` stores the index of the parent of element `i`.
   * If `parent[i]` is a **negative value (e.g., -1)**, it indicates that `i` is the **root (representative)** of its set. The negative value can also be used to store the **size or rank (weight)** of the set (e.g., -N means N elements in the set).
   * **`Find` Operation with Array**: To find the representative of an element, you traverse the `parent` array upwards until you reach a node whose parent value is negative (i.e., the root).
   * **`Union` Operation with Array**: To merge two sets (represented by their roots), the parent pointer of one root is set to point to the other root.
5. **Time-Efficient Operations**:
   * Naive `Find` (just following parent pointers) can be slow if trees become deep. Naive `Union` (just making one root child of another) can also lead to deep trees. To optimize, two techniques are used:
     * **Weighted Union (Union by Rank/Size)**:
       * When merging two sets (trees), the root of the **smaller tree (fewer elements/smaller rank)** is attached as a child to the root of the **larger tree (more elements/higher rank)**.
       * This strategy helps in keeping the trees flatter (reducing their height), which in turn reduces the time taken for `Find` operations.
     * **Collapsing Find (Path Compression)**:
       * During a `Find` operation, after the root of an element is identified, all nodes along the path from the initial element to the root are **re-linked directly to the root**.
       * This "compresses" the path, ensuring that subsequent `Find` operations for any of those nodes will be much faster (often nearly constant time, amortised).
       * The lecture provides an example of `Find(6)` where the path `6 -> 5 -> 1` is collapsed so that `6` directly points to `1`.
   * These two optimizations (Weighted Union and Collapsing Find) together make the Disjoint Set Union (DSU) data structure extremely efficient, achieving an amortised time complexity very close to constant time (specifically, inverse Ackermann function, which grows extraordinarily slowly).

***

***
