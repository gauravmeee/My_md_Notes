
Express is a Fast, unopinionated, minimalist web framework for Node.js
it is a backend framework like Flask , Django

Open your `project` Directory in `Terminal` and initialize the project.
```shell
npm init
//npm init -y
```

A `package.json` will be Created.
Now Create `Index.js` , that would be entry point.

```
project
├── index.js
└── package.json
```

Install express
```shell
npm install express --save
```

The `--save` flag in `npm install express --save` was used to add the installed package (`express` in this case) to the `dependencies` section of your `package.json` file. 

To install all the modules if `node_modules` folder got deleted, just use `npm i`
As of npm version 5 this flag is no longer necessary.

Uninstall express
```shell
npm uninstall express
```


### Why `Express` is important, Why we can't simply made `HTTP` server in `Nodejs` ??

You can learn How to build an HTTP Server in NodeJS from this Very Good Learning Page [NodeJS Learn](https://nodejs.org/en/learn/getting-started/introduction-to-nodejs)  and also check the [Node JS Documentation](https://nodejs.org/docs/latest/api/)

### Open `index.js` and Start Coding:

 Build A Basic HTTP Server in NodeJS 
```js
const { createServer } = require('node:http');

const hostname = '127.0.0.1';
const port = 3000;

const server = createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});

```

In Express We Can Do the Similar thing
```javascript
const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
```

## [Express Documentation](https://expressjs.com/en/starter/hello-world.html)
## Express is used so that, We no more need to use `if else` for Creating different different endpoints. for example `\about`, \contacts`

- **Route**: A pattern for matching URLs.
- **Endpoint**: A specific URL pattern combined with an HTTP method.

## Routes Handler

`localhost:3000` will show 'Hello World!' as Response at the Page
```javascript
app.get('/', (req, res) => {
  res.send('Hello World!')
})
```

`localhost:3000/about` will show 'Introduction' as Response at the Page
```js
app.get('/about', (req, res) => {
  res.send('Introduction')
})
```

`localhost:3000/contacts` will show 'List of Contacts' as Response at the Page
```js
app.get('/contacts', (req, res) => {
  res.send('List of Contacts')
})
```

**Note:**  In Express, Inspect Network, You will se it will automatically send `Status Code` like `404`. Without Express, we have to write custom codes for `Status Codes` manually
Express is a Framework to save your time : ) 

- Install `postman` App to Fetch, post HTTP Requests.
Alternatively you can install `Thunder Client` VS Code Extension if you don't want to switch into different application

- Install `nodemon` It will help the server to restart Automatically when you Save any changes

## Lets Start

Import Modules
```js
const express = require('express')
const path = require ('path')
const app = express()
const port = 3000
```
Send Response 
```js
// Route Handler
app.get('/', (req, res) => {
  res.send('Hello World!')
})
```
Render HTML
```js
// Route Handler
app.get('/about', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html' ))
})
```
Custom Status Code
```js
// Route Handler
app.get('/contacts', (req, res) => {
  res.send('List of Contacts')
  res.status(500) // 500: internal error
})
```
Run Server
```js
app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})
```

## More 

Send JSON
```js
app.get('/about', (req, res) => {
  res.json({"gaurav" : 169})
})
```
Note:- You can install chrome extension `JSON Formatter` if you want to see, the JSON sent in a formatted way. (Useful for big JSON files)

Use `html files` inside Public Folder
```
project
├── node_modules
├── index.js
└── public
       └── index.html
```

```js
const path = require('path')
// All other Imports

// Middleware
App.use(express.static(path.join(__dirname, "public")))
```
Note:- Now it will start Serving `Public` Folder as `Static` Folder
**`Express Middleware` are Functions that will keep Access of  Request and Response Objects, and can change it.**
## Middleware

Example to Create your own Middleware 
```js
// Create Middleware
const gauravMiddleware = (req, res) =>{
	console.log(req)
}
// use Middleware
app.use(gauravMiddleware)
```
Note:- In general, there is not need to create Middleware, we only use them)

**Middleware** :- In Express.js, middleware refers to functions that have access to the request object (`req`), the response object (`res`), and the next middleware function in the application's request-response cycle. 
These functions can perform various operations such as executing code, modifying the request and response objects, ending the request-response cycle, and calling the next middleware function in the stack.

If we have more than one middleware, we use `next()` function, so that next middleware run after current running middleware
```js
// Create Middleware
const gauravMiddleware = (req, res, next) =>{
	console.log(req)
	next() // pass control to the next middleware function in the stack.
}
// use Middleware
app.use(gauravMiddleware)
```

 
## Parameters in Routes/Endpoints

```js
// name parameter
app.get('/hello/:name', (req, res) => {
	res.send('Hello World! ' + req.params.name)
})

// url -> localhost:3000/hello:Gaurav
// response -> Hello World! Gaurav
```

We can fetch blogposts from website, fetch key value pair from your database. You get this by sending the `Parameters`


static vs template vs public folder
The `static` / (`public`folder in some frameworks, like Express.js (Node.js) ) folder is used to serve static assets/files to the client, which are files that do not change in response to user input and are sent directly from the server to the client. These files can include: Images, Stylesheets, JavaScript, Font

The `template` folder (or `templates` in Flask) is used to store HTML template files that your web application renders. These templates are often dynamically generated with server-side data. For example:

## Express Production app Structure ( Example blog app)
# 35:00 / 1:20:50