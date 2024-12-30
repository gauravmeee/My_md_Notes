
Flask Minimal App
```python
# app
from flask import Flask
app = Flask(_name_)

@app.route('/')
def hello_world():
    return 'Hello, World!'
```
```python
# Call or run the app.
if __name__ == "__main__":
    app.run(debug=True)
```

---

- `if __name__ == "__main__":` ensures that the code inside this block will only run when the script is executed directly, not when it's imported as a module into another script.

---

A decorator is applied to a function by writing it above the function definition, preceded by the `@` symbol. So, if you see something like this:

```python
@decorator_function
def my_function():     
	pass`
```


**Route Definition**: The `@app.route()` decorator is used to define a route in the Flask application. The argument passed to it is the URL pattern that Flask should listen to.

```python
@app.route('/home')
def home():
    return "Welcome to Home!"
```

---

### 15. **How would you handle file uploads in Flask?**

- Flask provides the `request.files` object to access uploaded files. You can handle file uploads as follows:

```python
file = request.files['file']
file.save(os.path.join('uploads', filename))
```

### 16. **Explain Flask's method for handling URL parameters.**

- Flask allows you to capture URL parameters using route variables, which can be accessed in the corresponding view function.

```python
@app.route('/user/<username>')
def show_user_profile(username):
    return f"User {username}"
```