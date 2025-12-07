
# Web Development

|     | Topics                 | Subtopics                                      |
| --- | ---------------------- | ---------------------------------------------- |
| 1   | Frontend               | HTML, CSS, JS                                  |
| 2   | HTTP Methods & Storage | GET, POST, PUT, DELETE, Local, Session, Cookie |
| 3   | Server-side            | NodeJS, Java, Python, C#                       |
| 4   | CRUD Operations        | Database interaction                           |
| 5   | REST APIs              | Authentication, Rate limiting                  |

### **1. HTML, CSS, JS**


##### **HTML**

**Definition:** ==HyperText Markup Language== used to ==structure web pages==.  

**Structure:**
```html
<!DOCTYPE html>
<html>
<head>
  <title>Page Title</title>
</head>
<body>
  <h1>Main Heading</h1>
  <p>Paragraph text.</p>
</body>
</html>
```

**Key Elements:**

- `<html>`: Root element
- `<head>`: ==Metadata, title, links, scripts==
- `<body>`: Visible content
- Headings: `<h1>`–`<h6>`
- Paragraph: `<p>`
- Links: `<a href="url">text</a>`
- Images: `<img src="path" alt="desc">`
- Lists: `<ul>`, `<ol>`, `<li>`
- Tables: `<table>`, `<tr>`, `<td>`, `<th>`
- ==Forms:== ==`<form>`==, ==`<input>`==, ==`<textarea>`==, ==`<select>`==, ==`<button>`==
- Semantic Tags: `<header>`, `<footer>`, `<article>`, `<section>`, `<nav>`, `<main>`
- ==**Attributes:**== Provide additional information — `id`, `class`, `style`, ==`src`==, ==`href`==, etc.

##### **CSS**

**Definition:** ==Cascading Style Sheets== used for presentation and layout. 

**Syntax:**
```css
selector {
  property: value;
}
```

==**Selectors:**== element (==`p`==), class (==`.class`==), id (==`#id`==), attribute (`[type="text"]`), pseudo-class (`a:hover`)  

**Types of CSS:**

1. Inline: `<h1 style="color:red;">`
2. Internal: `<style>` in `<head>`
3. External: `<link rel="stylesheet" href="style.css">`

- **Box Model:** ==content → padding → border → margin==  
- **Positioning:** static, relative, absolute, fixed, sticky  
- **Display:** block, inline, inline-block, none, flex, grid  
- **Media Queries:** responsive design

```css
@media (max-width:600px) {
  body { font-size:14px; }
}
```

- **Units:** px, %, em, rem, vh, vw  
- **Colors:** names, hex, rgb(), rgba()

##### **JavaScript**

**Definition:** Client-side scripting language for interactivity and logic.  

**Embedding:**
```html
<script src="script.js"></script>
```

**Basics:**
```javascript
let x = 10;
const y = 20;
function add(a,b){ return a+b; }
console.log(add(x,y));
```

- **Data Types:** string, number, boolean, object, array, null, undefined  
- **Operators:** `+ - * / %`, `==`, `===`, `!=`, `!==`, `&&`, `||`, `!`  
- **Control Structures:** `if`, `else`, `switch`, `for`, `while`, `do-while`  
- **Functions:** normal, arrow `()=>{}`  

**Objects & Arrays:**
```javascript
let obj = {name:"Gaurav", age:22};
let arr = [1,2,3];
```

**DOM Manipulation:**
```javascript
document.getElementById("id").innerHTML = "Text";
document.querySelector(".class").style.color = "red";
```

**Events:** `onclick`, `onchange`, `onload`
```html
<button onclick="greet()">Click</button>
<script>
function greet(){ alert("Hello"); }
</script>
```

- **ES6 Features:** ==let/const==, ==arrow functions==, ==template literals==, destructuring, modules, ==promises==  

**Example:**
```javascript
fetch("data.json")
  .then(res => res.json())
  .then(data => console.log(data));
```

**Integration Flow:**  
- HTML → Structure  
- CSS → Styling/Layout  
- JavaScript → Interactivity/Logic


### **2. HTTP Methods, Request/Response Headers, Storage Mechanisms – Local, Cookie, Session**


##### **HTTP Methods**

**Definition:** HTTP (Hypertext Transfer Protocol) defines methods for communication between client and server.

==**Common Methods:**==
- **GET:** Retrieve data from the server (no body).
- **POST:** Send data to the server (form submission, API calls).
- **PUT:** ==Update/replace== existing resource.
- **PATCH:** ==Partially update== resource.
- **DELETE:** Remove resource.
- **HEAD:** Same as GET but ==returns headers only==.
- **OPTIONS:** Describe communication options for a resource.


**Example (JavaScript fetch):**
```javascript
fetch('/api/data', { method: 'GET' })
  .then(res => res.json())
  .then(data => console.log(data));
```

##### **2. HTTP Request/Response Headers**

**HTTP Request Headers:** ==Metadata sen==t by the client ==to describe request details==.  

==**Common Headers:**==
- `Host`: Target domain
- `User-Agent`: Browser/client info
- `Accept`: Data format client expects
- `Authorization`: Credentials (token, basic auth)
- `Content-Type`: Type of data sent (`application/json`, `text/html`)
- `Cookie`: Sends cookies with request
    
**Example:**
```
GET /index.html HTTP/1.1
Host: example.com
User-Agent: Chrome/118.0
Accept: text/html
```

**HTTP Response Headers:** ==Metadata returned== by server ==about the response==.  

==**Common Headers:**==
- `Content-Type`: Type of returned data (`text/html`, `application/json`)
- `Content-Length`: Size of response body
- `Set-Cookie`: Sends cookies to client
- `Cache-Control`: Defines caching policy
- `Access-Control-Allow-Origin`: CORS header
- `Server`: Server software info
- `Date`: Response timestamp

**Example:**
```
HTTP/1.1 200 OK
Content-Type: application/json
Cache-Control: no-cache
```

##### **Storage Mechanisms - Local, Cookie, Session**

**1. Cookies** ⭐
- ==Small data stored by browser==, sent with each HTTP request.
- Max size ==~4KB per cookie==.
- ==Used for authentication==, ==session tracking==.
```javascript
document.cookie = "user=Gaurav; expires=Fri, 10 Nov 2025 12:00:00 UTC; path=/";
```

**2. Local Storage** ⭐
- ==Stores data persistently in browser== (until manually cleared).
- ==Key-value pairs==, ~5–10MB limit, synchronous API.
```javascript
localStorage.setItem("username","Gaurav");
console.log(localStorage.getItem("username"));
```

**3. Session Storage**
- Similar to Local Storage but ==cleared when tab/window closes==.
- Scope ==limited to a single session==.
```javascript
sessionStorage.setItem("theme","dark");
console.log(sessionStorage.getItem("theme"));
```

**Comparison:**

| Feature                 | Cookie              | Local Storage | Session Storage |
| ----------------------- | ------------------- | ------------- | --------------- |
| Size                    | ~4KB                | ~5–10MB       | ~5MB            |
| Expiry                  | Configurable        | Persistent    | Until tab close |
| Sent with HTTP Requests | ==Yes==             | No            | No              |
| Accessibility           | ==Server + Client== | Client only   | Client only     |


### **3. Server-Side Programming - NodeJS / Java / Python / C#**

**Definition:** ==Logic executed on the server== to handle client requests, process data, interact with databases, and send responses.

##### **Node.js**

**Definition:** ==JavaScript runtime== built on ==Chrome’s V8 engine== for ==server-side applications==.  

- **Key Features:** Event-driven, non-blocking I/O, single-threaded, cross-platform.

**Setup:**
```bash
npm init -y
npm install express
```

**Example (Express Server):**
```javascript
const express = require('express');
const app = express();
app.get('/', (req,res)=>res.send('Hello World'));
app.listen(3000, ()=>console.log('Server running on port 3000'));
```

- ==**Modules:**== ==`fs`==, ==`http`==, ==`url`==, ==`path`==, ==`os`==  
- **Package Manager:** `npm`  
- **Uses:** ==REST APIs==, ==microservices==, ==real-time apps==

##### **Java (Servlets)**

**Definition:** ==Platform-independent OOP language== used for web backends via ==Servlets/JSP/Spring==.  

**Servlet Example:**
```java
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class HelloServlet extends HttpServlet {
  protected void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
    res.setContentType("text/html");
    PrintWriter out = res.getWriter();
    out.println("<h1>Hello World</h1>");
  }
}
```

**Frameworks:** ==Spring Boot==, ==Java EE==, ==Hibernate==  
**Uses:** Enterprise apps, REST APIs, banking systems

##### **Python (Flask/Django)**

**Definition:** ==High-level language== used for ==scalable, quick-to-develop web apps==.  

**Flask Example:**
```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def home():
    return "Hello World"

if __name__ == '__main__':
    app.run(debug=True)
```

**Django Example:**
```python
from django.http import HttpResponse
def index(request):
    return HttpResponse("Hello Django")
```

- **Uses:** APIs, data-driven web apps, ML-backed systems

##### **C# (.NET)**

**Definition:** ==Object-oriented language== used with ==ASP.NET== for ==dynamic web apps==. 

**Example (ASP.NET Core):**
```csharp
using Microsoft.AspNetCore.Mvc;

[ApiController]
[Route("[controller]")]
public class HelloController : ControllerBase {
  [HttpGet]
  public string Get() => "Hello World";
}
```

- **Frameworks:** ==ASP.NET==, ==.NET Core==  
- **Uses:** ==Enterprise portals==, ==Windows-integrated systems==, REST services



##### **Common Server Tasks**

- Handling HTTP requests/responses
- CRUD operations on databases
- Authentication & session management
- Input validation & security (XSS, SQL Injection)
- Logging & error handling
- API routing & middleware

**Flow:**  
- ```
  [Client] → HTTP Request → [Server] → Process Logic/DB → HTTP Response → [Client]
  ```

### **4. CRUD Operations**

**Definition:** CRUD stands for ==Create, Read, Update, Delete== — the four ==fundamental operations for persistent data management== in databases or APIs.

##### **Create**

**Purpose:** Insert new data into database.  

**SQL Example:**
```sql
INSERT INTO users (id, name, email) VALUES (1, 'Gaurav', 'gaurav@example.com');
```

**Node.js (Express + MongoDB Example):**
```javascript
app.post('/users', async (req, res) => {
  const user = new User(req.body);
  await user.save();
  res.send('User Created');
});
```

##### **Read**

**Purpose:** Retrieve or fetch existing data.  

**SQL Example:**
```sql
SELECT * FROM users WHERE id = 1;
```

**Node.js Example:**
```javascript
app.get('/users/:id', async (req, res) => {
  const user = await User.findById(req.params.id);
  res.json(user);
});
```

##### **Update**

**Purpose:** Modify existing data.

**SQL Example:**
```sql
UPDATE users SET name = 'Gaurav Meena' WHERE id = 1;
```

**Node.js Example:**
```javascript
app.put('/users/:id', async (req, res) => {
  await User.findByIdAndUpdate(req.params.id, req.body);
  res.send('User Updated');
});
```

##### **Delete**

**Purpose:** Remove data from database.  

**SQL Example:**
```sql
DELETE FROM users WHERE id = 1;
```

**Node.js Example:**
```javascript
app.delete('/users/:id', async (req, res) => {
  await User.findByIdAndDelete(req.params.id);
  res.send('User Deleted');
});
```


**REST API Mapping**

|CRUD|HTTP Method|Example Endpoint|
|---|---|---|
|Create|POST|/users|
|Read|GET|/users/:id|
|Update|PUT/PATCH|/users/:id|
|Delete|DELETE|/users/:id|

**Key Points**
- CRUD ==ensures full== ==data lifecycle== ==management==.
- Used in ==DB systems (SQL/NoSQL)== and ==REST APIs==.
- ==Validation==, ==authentication==, and ==error handling== must accompany CRUD operations for security and data integrity.

### **5. REST APIs, Rate Limiting, Authorization and Authentication**

##### **REST APIs** ⭐

**Definition:** ==Representational State Transfer== — ==architectural style for designing== ==stateless web services==.  
**Principles:**

- **Stateless:** ==Each request independent==, no server session.
- **Uniform Interface:** Consistent resource access via URIs.
- **Client-Server:** Separation of UI and data logic.
- **Cacheable:** Responses can be cached for performance.
- **Layered System:** Multiple layers (proxy, load balancer).

*Note:* 
- **stateless** means that the server does **not store any information about the client’s session** between requests, so it makes the system more **scalable, reliable, and simple**.
- Every URL is a URI that locates a resource, but not every URI is a URL since some only identify without specifying location.


**REST API Example (Node.js + Express):**
```javascript
app.get('/api/users', (req,res)=>res.json(users));
app.post('/api/users', (req,res)=>res.send('User Added'));
```

**Typical Response:** 
```json
{
  "status": "success",
  "data": { "id": 1, "name": "Gaurav" }
}
```

**HTTP Method Mapping:**  
GET → Read, POST → Create, PUT/PATCH → Update, DELETE → Remove

##### **Rate Limiting**

**Definition:** Technique to ==restrict number of API requests== a client can make in a given time.  

**Purpose:** Prevent abuse, ensure fair usage, protect servers.  
**Common Strategies:**

- **Fixed Window:** ==Limit per time window== (e.g., 100 requests/min).
- **Sliding Window:** ==Adjusts window based on request time==.
- **Token Bucket / Leaky Bucket:** Allows bursts up to defined capacity.  
    
**Node.js Example (Express Middleware):**
```javascript
const rateLimit = require('express-rate-limit');
const limiter = rateLimit({ windowMs: 1*60*1000, max: 100 });
app.use(limiter);
```

#### **Authentication**

**Definition:** Process of ==verifying user identity==.  
**Types:**

1. **Basic Auth:** Username + Password in header (base64 encoded).
2. **Token-based Auth (JWT):** Client gets signed token after login.
3. **OAuth 2.0:** Delegated authorization (e.g., Google Login).
4. **API Keys:** Static unique keys for app-level access.
    

**JWT Example:**
```javascript
const jwt = require('jsonwebtoken');
const token = jwt.sign({id:1, name:'Gaurav'}, 'secretKey', {expiresIn:'1h'});
jwt.verify(token, 'secretKey', (err, data)=>console.log(data));
```

##### **Authorization**

**Definition:** Determines ==what authenticated users can access== or perform.  

**Flow:**
1. User authenticates → gets token.
2. Token is checked → user role/permissions verified.
3. Access granted or denied.


**Example:**
```javascript
function verifyAdmin(req,res,next){
  if(req.user.role !== 'admin') return res.status(403).send('Access Denied');
  next();
}
```

##### **Conclusion**

| Concept        | Purpose                | Example             |
| -------------- | ---------------------- | ------------------- |
| Authentication | ==Confirms identity==  | Login with password |
| Authorization  | ==Grants permissions== | Admin-only access   |


**Summary Flow:**  
Client → Authenticates → Receives Token → Sends Request → Server Verifies Token & Authorizes → Response