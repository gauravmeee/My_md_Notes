
## Flask 

Server-side code
```python
@app.route('/')
def home():
    # Data to be sent to the template
    data = {
        'title': 'Home Page',
        'name': 'John Doe'
    }
    return render_template('index.html', **data)
```

Jinja2 (Python) Template (`templates/index.html`)
```html
<head>
    <title>{{ title }}</title>
</head>
<body>
    <h1>Hello, {{ name }} </h1>
</body>
```

---
## Express 

Server-Side Code:
```javascript
app.get('/', (req, res) => {
    // Data to be sent to the template
    const data = {
        title: 'Home Page',
        name: 'John Doe'
    };
    res.render('index', data);
});
```

EJS (Node.js) Template (`views/index.ejs`):
```html
<head>
    <title><%= title %></title>
</head>
<body>
    <h1>Hello, <%= name %> </h1>
</body>
```

Handlebars.js Template (`views/index.handlebars`):
```html
<head>
    <title>{{title}}</title>
</head>
<body>
    <h1>Hello, {{name}} </h1>
</body>
```
*Note:* Mustache template engine is also work as handle bar, but it is supported by Python, Ruby

Pug (Node.js) Template (`views/index.pug`):
```html
doctype html
html
  head
    title= title
  body
    h1 Hello, #{name}
```


- `Jinja2`  offer rich features and are suitable for full-featured web frameworks.
- `EJS` and `Pug` provide flexibility and are popular in the Node.js ecosystem.
- `Handlebars.js` and `Mustache` are lightweight and focus on simplicity.
- **Liquid** is designed for specific use cases like content management and static site generation.