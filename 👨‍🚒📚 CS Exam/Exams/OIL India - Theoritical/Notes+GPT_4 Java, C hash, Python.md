
# JAVA / C# / Python Programming

|     | Topics                | Subtopics                                |
| --- | --------------------- | ---------------------------------------- |
| 1   | OOP Principles        | Encapsulation, Inheritance, Polymorphism |
| 2   | Language Basics       | Syntax, data types, control flow         |
| 3   | User Interfaces       | GUI programming                          |
| 4   | Threads               | Creation and synchronization             |
| 5   | Database Connectivity | JDBC, ADO.NET, Python DB APIs            |

# 1. Principles of Object-Oriented Programming

## 1. Object-Oriented Programming (OOP)

OOP is a programming paradigm based on the concept of **objects** which contain **data (attributes)** and **methods (functions)**. It focuses on modularity, reusability, and abstraction.

## 2. Core Principles of OOP

### a) Encapsulation

- Bundling of data and methods operating on that data into a single unit (class).
    
- Restricts direct access to internal data; access controlled via getters/setters.  
    **Example (Java):**
    

```java
class Student {
    private int rollNo;
    public void setRollNo(int r){ rollNo = r; }
    public int getRollNo(){ return rollNo; }
}
```

### b) Inheritance

- Mechanism to derive new classes (subclasses) from existing ones (superclasses).
    
- Promotes code reusability and hierarchical classification.  
    **Example (C#):**
    

```csharp
class Animal {
    public void eat() { Console.WriteLine("Eating"); }
}
class Dog : Animal {
    public void bark() { Console.WriteLine("Barking"); }
}
```

### c) Polymorphism

- Ability of different classes to respond differently to the same function call.
    
- **Compile-time polymorphism:** method overloading.
    
- **Runtime polymorphism:** method overriding via inheritance.  
    **Example (Python):**
    

```python
class Shape:
    def area(self): pass
class Circle(Shape):
    def area(self): return "Area of Circle"
```

### d) Abstraction

- Hiding implementation details and showing only essential features.
    
- Achieved using abstract classes and interfaces.  
    **Example (Java):**
    

```java
abstract class Shape {
    abstract void draw();
}
class Circle extends Shape {
    void draw(){ System.out.println("Drawing Circle"); }
}
```

## 3. Advantages of OOP

- Modularity and maintainability
    
- Code reusability via inheritance
    
- Flexibility and scalability
    
- Enhanced data security via encapsulation
    

## 4. Key Concepts

- **Class:** Blueprint for objects.
    
- **Object:** Instance of a class.
    
- **Constructor:** Initializes object state.
    
- **Message Passing:** Communication between objects via methods.


---
---

# 2. Basics of Java / C# / Python Language

## 1. Introduction

- **Java**: Object-oriented, platform-independent (JVM-based).
    
- **C#**: Object-oriented, component-based, runs on .NET Framework / .NET Core.
    
- **Python**: Interpreted, dynamically typed, easy syntax, supports multiple paradigms.
    

## 2. Program Structure

**Java**

```java
class Main {
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
```

**C#**

```csharp
using System;
class Program {
    static void Main() {
        Console.WriteLine("Hello World");
    }
}
```

**Python**

```python
print("Hello World")
```

## 3. Data Types

|Type Category|Java|C#|Python|
|---|---|---|---|
|Integer|int, long|int, long|int|
|Floating|float, double|float, double|float|
|Character|char|char|str (single char)|
|Boolean|boolean|bool|bool|
|String|String|string|str|

## 4. Variables & Constants

- **Declaration**
    
    - Java: `int x = 10;`
        
    - C#: `int x = 10;`
        
    - Python: `x = 10`
        
- **Constants**
    
    - Java: `final int X = 10;`
        
    - C#: `const int X = 10;`
        
    - Python: conventionally uppercase: `X = 10`
        

## 5. Operators

- **Arithmetic:** `+ - * / %`
    
- **Relational:** `== != > < >= <=`
    
- **Logical:** `&& || !` (Java/C#), `and or not` (Python)
    
- **Assignment:** `= += -= *= /=`
    
- **Increment/Decrement:** `++ --` (Java/C# only)
    

## 6. Control Statements

**If-Else**

```java
if(x > 0) System.out.println("Positive");
else System.out.println("Negative");
```

```csharp
if(x > 0) Console.WriteLine("Positive");
else Console.WriteLine("Negative");
```

```python
if x > 0:
    print("Positive")
else:
    print("Negative")
```

**Looping**

```java
for(int i=0;i<5;i++) System.out.println(i);
```

```csharp
for(int i=0;i<5;i++) Console.WriteLine(i);
```

```python
for i in range(5):
    print(i)
```

## 7. Functions / Methods

- **Java**
    

```java
int add(int a, int b){ return a + b; }
```

- **C#**
    

```csharp
int Add(int a, int b){ return a + b; }
```

- **Python**
    

```python
def add(a, b):
    return a + b
```

## 8. Input / Output

- **Java:** `Scanner sc = new Scanner(System.in); int x = sc.nextInt();`
    
- **C#:** `int x = Convert.ToInt32(Console.ReadLine());`
    
- **Python:** `x = int(input())`
    

## 9. Comments

- **Single-line:** `//` (Java/C#), `#` (Python)
    
- **Multi-line:** `/*...*/` (Java/C#), `'''...'''` or `"""..."""` (Python)
    

## 10. Exception Handling

**Java**

```java
try { int a=5/0; } catch(Exception e){ System.out.println(e); }
```

**C#**

```csharp
try { int a=5/0; } catch(Exception e){ Console.WriteLine(e.Message); }
```

**Python**

```python
try: a=5/0
except Exception as e: print(e)
```


---
---

# 3. Working with User Interfaces

## 1. Introduction

User Interface (UI) enables interaction between user and application. In Java, C#, and Python, UI can be **Graphical (GUI)** or **Web-based**.

---

## 2. Java – Swing & JavaFX

### a) Swing

- Part of `javax.swing` package.
    
- Lightweight, platform-independent GUI toolkit.
    
- Components: `JFrame`, `JButton`, `JLabel`, `JTextField`.  
    **Example**
    

```java
import javax.swing.*;
class MyFrame {
    public static void main(String[] args){
        JFrame f = new JFrame("Demo");
        JButton b = new JButton("Click");
        b.setBounds(100,100,80,30);
        f.add(b);
        f.setSize(300,200);
        f.setLayout(null);
        f.setVisible(true);
    }
}
```

### b) JavaFX

- Modern GUI framework replacing Swing.
    
- Uses FXML and CSS for UI design.  
    **Example**
    

```java
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
public class Main extends Application {
    public void start(Stage stage){
        Button b = new Button("Click");
        Scene scene = new Scene(b, 200, 100);
        stage.setScene(scene);
        stage.show();
    }
}
```

---

## 3. C# – Windows Forms & WPF

### a) Windows Forms

- Found in `System.Windows.Forms` namespace.
    
- Event-driven, drag-and-drop support in Visual Studio.  
    **Example**
    

```csharp
using System;
using System.Windows.Forms;
class MyForm : Form {
    Button b;
    public MyForm(){
        b = new Button();
        b.Text = "Click";
        b.Click += (s,e)=> MessageBox.Show("Hello");
        Controls.Add(b);
    }
    [STAThread]
    static void Main(){ Application.Run(new MyForm()); }
}
```

### b) WPF (Windows Presentation Foundation)

- Uses XAML for UI, supports data binding and animation.  
    **Example**
    

```xml
<Window xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
  <Button Content="Click Me" Width="100" Height="40"/>
</Window>
```

---

## 4. Python – Tkinter & PyQt

### a) Tkinter

- Built-in Python GUI library.
    
- Uses widgets like `Button`, `Label`, `Entry`, `Frame`.  
    **Example**
    

```python
import tkinter as tk
win = tk.Tk()
btn = tk.Button(win, text="Click", command=lambda: print("Hello"))
btn.pack()
win.mainloop()
```

### b) PyQt / PySide

- Advanced GUI library with Qt framework.
    
- Supports UI Designer tool.  
    **Example**
    

```python
from PyQt5.QtWidgets import QApplication, QPushButton
app = QApplication([])
btn = QPushButton('Click')
btn.show()
app.exec_()
```

---

## 5. Common Concepts

- **Event Handling:** Actions triggered by user inputs (click, keypress).
    
- **Layout Managers:** Arrange UI components (e.g., `FlowLayout`, `GridLayout`, `pack()` etc.).
    
- **MVC Pattern:** Separates logic (Model), interface (View), and control (Controller).
    
- **Threading in UI:** Long-running tasks should run on separate threads to keep UI responsive.
    

---
---


# 4. Introduction to Threads in Java

## 1. Definition

A **thread** is the smallest unit of a process that can run independently.  
Multithreading allows concurrent execution of two or more threads to maximize CPU utilization.

---

## 2. Thread Creation Methods

### a) Extending `Thread` class

```java
class MyThread extends Thread {
    public void run(){
        for(int i=0;i<5;i++) System.out.println("Child Thread");
    }
    public static void main(String[] args){
        MyThread t = new MyThread();
        t.start(); // starts new thread
        for(int i=0;i<5;i++) System.out.println("Main Thread");
    }
}
```

### b) Implementing `Runnable` interface

```java
class MyRunnable implements Runnable {
    public void run(){
        for(int i=0;i<5;i++) System.out.println("Child Thread");
    }
    public static void main(String[] args){
        Thread t = new Thread(new MyRunnable());
        t.start();
        for(int i=0;i<5;i++) System.out.println("Main Thread");
    }
}
```

---

## 3. Thread Life Cycle

1. **New** – Thread created but not started (`new Thread()`).
    
2. **Runnable** – Ready to run after `start()`.
    
3. **Running** – Scheduler picks the thread to execute `run()`.
    
4. **Blocked/Waiting** – Waiting for resource or synchronization.
    
5. **Terminated** – After execution completes.
    

---

## 4. Thread Methods

|Method|Description|
|---|---|
|`start()`|Starts execution of thread (calls `run()` internally)|
|`run()`|Defines thread’s task|
|`sleep(ms)`|Pauses thread for specified time|
|`join()`|Waits for thread to finish|
|`isAlive()`|Checks if thread is active|
|`setPriority(int p)`|Sets priority (1–10)|
|`getName()` / `setName()`|Gets or sets thread name|

---

## 5. Thread Priority

- Range: `1 (MIN_PRIORITY)` to `10 (MAX_PRIORITY)`
    
- Default: `5 (NORM_PRIORITY)`
    
- Used by scheduler for execution order, but not guaranteed.
    

---

## 6. Synchronization

- Prevents multiple threads from accessing shared resources simultaneously.  
    **Example**
    

```java
class Counter {
    int count = 0;
    synchronized void increment(){ count++; }
}
```

- `synchronized` ensures thread-safe access.
    

---

## 7. Inter-thread Communication

- Methods: `wait()`, `notify()`, `notifyAll()` (used within synchronized blocks).
    
- Used for coordination between threads.
    

---

## 8. Daemon Threads

- Background threads that terminate when all user threads finish.
    

```java
Thread t = new Thread(...);
t.setDaemon(true);
t.start();
```

---

## 9. Advantages of Multithreading

- Better CPU utilization
    
- Faster program execution
    
- Responsive UI
    
- Simultaneous background processing
    


---
---

# 5. Database Connectivity using Java / C# / Python

## 1. Introduction

Database connectivity enables interaction between programs and databases (MySQL, SQL Server, Oracle, etc.) through APIs or libraries for CRUD operations (Create, Read, Update, Delete).

---

## 2. Java – JDBC (Java Database Connectivity)

### a) Steps

1. **Import package** – `import java.sql.*;`
    
2. **Load driver** – `Class.forName("com.mysql.cj.jdbc.Driver");`
    
3. **Establish connection**
    
    ```java
    Connection con = DriverManager.getConnection(
        "jdbc:mysql://localhost:3306/testdb","root","password");
    ```
    
4. **Create statement**
    
    ```java
    Statement st = con.createStatement();
    ```
    
5. **Execute query**
    
    ```java
    ResultSet rs = st.executeQuery("SELECT * FROM student");
    ```
    
6. **Process results**
    
    ```java
    while(rs.next())
        System.out.println(rs.getInt(1)+" "+rs.getString(2));
    ```
    
7. **Close connection**
    
    ```java
    con.close();
    ```
    

### b) PreparedStatement Example

```java
PreparedStatement ps = con.prepareStatement("INSERT INTO student VALUES(?,?)");
ps.setInt(1,101);
ps.setString(2,"Gaurav");
ps.executeUpdate();
```

---

## 3. C# – ADO.NET

### a) Steps

1. **Import namespace** – `using System.Data.SqlClient;`
    
2. **Establish connection**
    
    ```csharp
    SqlConnection con = new SqlConnection(
        "Data Source=SERVER;Initial Catalog=TestDB;Integrated Security=True");
    con.Open();
    ```
    
3. **Execute command**
    
    ```csharp
    SqlCommand cmd = new SqlCommand("SELECT * FROM student", con);
    SqlDataReader dr = cmd.ExecuteReader();
    while(dr.Read())
        Console.WriteLine(dr[0] + " " + dr[1]);
    ```
    
4. **Close connection**
    
    ```csharp
    con.Close();
    ```
    

### b) Using Parameters

```csharp
SqlCommand cmd = new SqlCommand("INSERT INTO student VALUES(@id,@name)", con);
cmd.Parameters.AddWithValue("@id", 101);
cmd.Parameters.AddWithValue("@name", "Gaurav");
cmd.ExecuteNonQuery();
```

---

## 4. Python – DB API (Using MySQL Connector / SQLite3)

### a) MySQL Connector Example

```python
import mysql.connector
con = mysql.connector.connect(host="localhost", user="root", password="1234", database="testdb")
cur = con.cursor()
cur.execute("SELECT * FROM student")
for row in cur:
    print(row)
con.close()
```

### b) Parameterized Query

```python
cur.execute("INSERT INTO student VALUES(%s, %s)", (101, "Gaurav"))
con.commit()
```

### c) SQLite Example

```python
import sqlite3
con = sqlite3.connect("test.db")
cur = con.cursor()
cur.execute("CREATE TABLE IF NOT EXISTS student(id INT, name TEXT)")
cur.execute("INSERT INTO student VALUES(1, 'Gaurav')")
con.commit()
for row in cur.execute("SELECT * FROM student"):
    print(row)
con.close()
```

---

## 5. Common Concepts

- **Connection Object:** Represents DB connection.
    
- **Statement / Cursor / Command:** Executes SQL queries.
    
- **ResultSet / Reader:** Holds query results.
    
- **Prepared/Parameterized Statements:** Prevent SQL injection.
    
- **Transaction Control:** `commit()`, `rollback()` for consistency.
    
