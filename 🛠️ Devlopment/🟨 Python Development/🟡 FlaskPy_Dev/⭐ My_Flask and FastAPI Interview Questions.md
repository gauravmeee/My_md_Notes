

# FLASK
#### **Q. What is Flask, Explain Flask Syntax**

What is flask

###### ChatGPT said:

Flask is a **lightweight** and **flexible** Python ==web framework== used to build web applications and APIs. It f==ollows the **WSGI** standard== and is designed to be simple yet powerful, providing essential features like routing, request handling, and templating without unnecessary overhead.

**Key Features:**  
- **Minimalist & Modular** – Only includes core features, with extensions for more functionality.  
 - **Easy Routing** – Uses decorators (`@app.route`) to define routes.  
- ==**Jinja2 Templating**== – Supports dynamic HTML rendering.  
- **Built-in Development Server** – Simplifies testing and debugging.  
-  **REST API Support** – Ideal for building APIs with JSON responses.

**Syntax:** **Main script (`app.py`):**
```python
from flask import Flask

app = Flask(__name__) #⭐

@app.route("/")
def home():
    return "Hello, World!"

if __name__ == "__main__":
    app.run(debug=True)  # Runs Flask app in debug mode
```

- When you **run `app.py`**, it starts the Flask web server.
- If you **import `app` in another script**, the Flask server won't start automatically.
**Methods**
```python
@app.route('/data', methods=['GET'])
@app.route('/data', methods=['GET', 'POST'])

```

#### Q. How to handle different Route Methods in Flask.

In Flask, you handle **GET, POST, PUT, DELETE** requests using the `methods` parameter in `@app.route()` or with `request.method`.

**Example: 

**Handling GET & POST in Flask**
```python
from flask import Flask, request

app = Flask(__name__) 
@app.route('/data', methods=['GET', 'POST'])
def handle_data():
    if request.method == 'GET':
        return "Received a GET request"
    elif request.method == 'POST':
        data = request.json  # For JSON data
        return f"Received POST with data: {data}"

if __name__ == '__main__':
    app.run(debug=True)

```

**Handling PUT & DELETE**
```python
@app.route('/update', methods=['PUT'])
def update_data():
    return "Received a PUT request"

@app.route('/delete', methods=['DELETE'])
def delete_data():
    return "Received a DELETE request"
```

#### **Q. What is Difference between PATCH and PUT**

- **PATCH** is used to **partially update** a resource, unlike **PUT**, which replaces the entire resource.
#### **Q. What is ASGI and WSGI**
- ==**WSGI (Web Server Gateway Interface)**== is a ==synchronous== interface between web servers and Python web applications, ==handling one request at a time==, making it suitable for traditional web apps like ==Flask and Django==.

- ==**ASGI (Asynchronous Server Gateway Interface)**== is an ==asynchronous== interface that ==supports concurrency==, allowing multiple requests to be handled simultaneously, making it ideal for real-time applications, WebSockets, and high-performance APIs like FastAPI.
#### **Q. What mean by `if __name__ == "__main__":` in Python**

**Understanding the Code**
```python
if __name__ == "__main__":
    app.run(debug=True)  # Run in debug mode (auto-restarts on code changes)
```

1. **`__name__ == "__main__"`**
    - In Python, `__name__` is a special variable that holds the module's name.
    - When a Python file is executed directly, `__name__` is set to `"__main__"`. ⭐
    - If the file is **imported as a module**, `__name__` will be set to the module name instead. ⭐
        
2. **`app.run(debug=True)`**
    - This starts a **Flask web server** with the `debug=True` mode enabled.
    - **Debug mode features:**
        
        - **Auto-reload**: Restarts the server when code changes.
        - **Debugging tools**: Shows detailed error messages in the browser.

---

# FAST API

#### **Q. What is FastAPI, and why is it used?**
 
FastAPI is a modern, high-performance web framework for building APIs with Python. It is based on Starlette and Pydantic, providing automatic validation, async support, and automatic OpenAPI & Swagger documentation. It is used because:
- **Speed**: Faster than Flask and Django due to ASGI and async support.
- **Auto Documentation**:==Generates Swagger and Redoc automatically.==
- **Type Safety**: Uses Python type hints for request validation.
- **Dependency Injection**: Supports built-in dependency management.
    
#### **Q. How does FastAPI handle asynchronous operations?**

FastAPI is ==built on **ASGI**== (Asynchronous Server Gateway Interface) and ==supports **async/await**== natively. To create an asynchronous route, use:
```python
from fastapi import FastAPI

app = FastAPI()

@app.get("/items/")
async def read_items():
    return {"message": "This is an async endpoint"}
```
This allows FastAPI to handle concurrent requests efficiently using event loops, making it **faster than Flask**, which is synchronous by default.

#### **Q. Why Use FastAPI Instead of Flask?**

While **Flask** is a great micro-framework for web applications, **FastAPI** offers several advantages, especially for modern API development.

**Key Differences:**

| Feature                 | Flask                                   | FastAPI                                |
| ----------------------- | --------------------------------------- | -------------------------------------- |
| **Speed**               | Slower (uses WSGI)                      | ==Much faster== (uses ASGI & async)    |
| **Async Support**       | Limited                                 | ==Built-in async/await==               |
| **Data Validation**     | Manual (via libraries like Marshmallow) | Automatic (Pydantic)                   |
| **Type Hints**          | Optional                                | Enforced for better code quality       |
| **Auto-Generated Docs** | No                                      | Yes (Swagger, ReDoc)                   |
| **Best for**            | Simple web apps & APIs                  | ==High-performance APIs==, ML services |

**When to Use FastAPI?**
- **High-performance APIs** (e.g., real-time services, chat apps)    
- **Async database operations** (e.g., MongoDB, PostgreSQL with async drivers)
- **Machine Learning APIs** (e.g., serving AI models)
- **Large-scale microservices** (e.g., distributed systems)

**Use Flask** for small projects.  
**Use FastAPI** when performance & scalability matter.

#### **Q.`if __name__ == "__main__": asyncio.run(main())` in Python**

This structure is used when running an **asynchronous** Python script.

**Code Example**
```python
import asyncio

async def main():
    print("Start")
    await asyncio.sleep(2)  # Simulates an async task (e.g., API call, DB query)
    print("End")

if __name__ == "__main__":
    asyncio.run(main())  # Runs the async function
```

1. **`async def main():`**
    - Defines an **asynchronous function** that contains `await` operations.
2. **`await asyncio.sleep(2)`**
    - Simulates an asynchronous task (e.g., waiting for a response, fetching data).
        
3. **`asyncio.run(main())`**
    - Runs the `main()` ==coroutine in an event loop==.    
    - Ensures proper handling of async tasks.
        
4. **`if __name__ == "__main__":`**
    - Ensures the script runs only when executed directly, not when imported.
        
**Expected Output**
```
Start
(Waits 2 seconds)
End
```
**Use Case**: Running asynchronous scripts, handling APIs, databases, or concurrent tasks.


#### **Q. How do you validate request data in FastAPI?**

FastAPI uses **Pydantic models** for request validation. Example:
```python
from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI() # ⭐

class User(BaseModel):
    name: str
    age: int
    email: str

@app.post("/user/")
def create_user(user: User):
    return {"message": f"User {user.name} created!"}
```
If an invalid request is sent, FastAPI **automatically returns a 422 Unprocessable Entity error** with validation details.

#### **Q. How do you handle dependencies in FastAPI?**

FastAPI provides **dependency injection** using the `Depends` function. Example:
```python
from fastapi import FastAPI, Depends

app = FastAPI()

def get_db():
    return {"db_status": "connected"}

@app.get("/items/")
def read_items(db=Depends(get_db)):
    return {"db_status": db["db_status"]}
```
This makes it easy to manage **database connections, authentication, and shared resources**.
#### **Q. How does FastAPI generate automatic API documentation?**

FastAPI **automatically** generates OpenAPI and Swagger documentation at:
- **Swagger UI**: `http://127.0.0.1:8000/docs`
- **ReDoc**: `http://127.0.0.1:8000/redoc`
    
The documentation is based on function signatures, type hints, and docstrings. Example:
```python
@app.get("/items/", summary="Get Items", description="Returns a list of items")
def get_items():
    return {"items": ["apple", "banana", "mango"]}
```
This makes FastAPI **self-documenting** and reduces manual API documentation efforts.
