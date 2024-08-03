
# [ Express JS Tutorial in Hindi 🔥✌](https://youtu.be/7H_QH9nipNs)


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

### Import
`require`: in Node.js, require() is a built-in function used to import modules, JSON, and local files into your application
```js
const express = require('express')
```

`import`: this is alternative way to import. This Model is useful if you're working with modern Javascript and want to take advantage of ES Module features.
```js
import express from 'express'
```
Note: When using import, ensure all files that use ES Modules have the `"type":"module"` setting or use the `.mjs` extension.
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

In JavaScript, the `${}` syntax is part of template literals (or template strings), which allow for easier and more readable string interpolation and multi-line strings.
*Note:* Template literals are enclosed by` backticks` (\`) instead of single or double quotes 
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

### Create the Files
 `public` or `Static` Directory  Contains static files that are served directly to the client.
 `template` Directory 


```
project
├── node_modules
├── index.js
├── routes
│      └── blogRoute.js
├── static
|       
├── templates
|       └── index.html
|       └── blogHome.html   
|       └── blogPage.html 
└── data
         └── blogData.js 
```

`static Middleware`:- Used to serve static files from a specified director
ex:- `app.use(express.static('public'));`

`Template Rendering`:-Used to dynamically generate HTML pages on the server side using template engines.

---

*Create index.js*
```js
//index.js
const express = require('express')
const path = require('path')
const app = express()
const port = 3000

app.use(express.static(path.join(__dirname, "static")))

app.use('/', require(path.join(__dirname, `routes/blogRoute.js` )))

app.listen(port, () => {
  console.log(`Blog app listening at http://localhost:${port}`)
})
```

1. The `app.use(express.static(path.join(__dirname, "static")))` line in an Express.js application sets up middleware to serve static files from a directory. Here’s a breakdown of what each part does:

3. **`require(path.join(__dirname, 'routes/blog.js'))`**: This loads the router module from the `routes/blog.js` file. The `path.join(__dirname, 'routes/blog.js')` constructs the absolute path to the `blog.js` file. `__dirname` is a global variable representing the directory name of the current module.

4. **`path.join(__dirname, 'routes/blog.js')`**: Joins the `__dirname` (current directory) with the `routes/blog.js` path, ensuring the path is correctly constructed based on the operating system.

5. We will separate our other routes from `index.js` into separate routes files, because it will become complex to write multiple routes into single, index.js. let the routes be `routes/blog.js`

*Create Index.html*
```html
...
<body>
This is my Home Page
</body>
...
```

*Create blogRoute.js*
```javascript
// blogRoute.js
const express = require('express')

// router function
const router = express.Router()
// routes
router.get('/', (req, res)=>{
	res.sendFile(path.join(__dirname, `templates/index.html`  ))
})

// Export router
module.exports = router
```

2. ***router.get() vs app.get()***
- Global Scope: `app.get()` is used to define a route handler for a specific HTTP GET request at the application level. (`const app = express()`)
- Router Scope: `router.get()` is used to define routes on a router object. Routers allow you to modularize your route definitions, making the application structure cleaner and more manageable. (`const router = express.Router()`)

*Create blogData.js:*
```js
// blogData.js
{
	blogs:[
		{
			title: "How to get started with Python",
			content: "This is content",
			slug: "python-learn"
		},
		{
			title: "How to get started with JS",
			content: "This is content"
		},,
			slug: "javascript-learn"
		{
			title: "How to get started with Django",
			content: "This is content"
		},,
			slug: "python-django-learn"
	]
}

// export the file
module.exports blogs;
```

*Update blogRouter.js:*
```js
const express = require('express')
const router = express.Router()

// inport built in `path` module
const path = require('path')

// import blogData.js file
const blogs = rquire('../data/blogs')

router.get('/', (req, res)=>{
	res.sendFile(path.join(__dirname, `templates/index.html`))
})

router.get('/blog', (req, res)=>{
	// print each blog title in console
	blogs.forEach(elem =>{
		console.log(elem.title)
	});
	// route '/blog' to 'blogHome.html'
	 res.sendFile(path.join(__dirname, `templates/blogHome.html` ))
})

module.exports = router
```

*Create blogHome.html*
```html
<body>
This is my blog Homepage
</body>
```

Create blogPage
```html
<body>
Python Blog
</body>
```

Update blogRoute.js
```js
// blogRoute.js
const express = require('express')
const router = express.Router()
const path = require('path')
const blogs = rquire('../data/blogs')

router.get('/', (req, res)=>{
	res.sendFile(path.join(__dirname, `../templates/index.html` ))
})

router.get('/blog', (req, res)=>{
	blogs.forEach(elem =>{
		console.log(elem.title)
	});
	 res.sendFile(path.join(__dirname, `../templates/blogHome.html` ))
})

// Individual post routing through Parameter
router.get('/blogpost/:slug', (req, res)=>{
	// JS function to Filter the blogs array to find the blog with the matching slug
	myBlog = blogs.filter((elem)=>{
		return elem.slug == req.params.slug
	})
	 res.sendFile(path.join(__dirname, `../templates/blogPage.html` ))
});

module.exports = router```

There our basic routing is done, we can Create design and add contents etc.
## We can also use mongoose to connect to the MongoDB Database : )


### Handlebars

[Handlebars official guide](https://handlebarsjs.com/guide/)
`Handlebars.js` is a templating engine for Node.js that can be used with Express to render web pages from server-side data to the client side. Handlebars expressions are the basic unit of a Handlebars template, and are enclosed by double curly braces, `{{}}`. For example, the following template uses a variable, firstname, enclosed by double curly braces:
```handlebars
template: <p>{{firstname}} {{lastname}}</p>
```

*Note:* `Handlebar` is like `Jinja2` python template engine.

- **HBS**
`HBS (Express-HBS)`: A specialized package for using Handlebars within the Express framework, making integration with Express easier and more streamlined.

### Express-Handlebars

[express-handlebars documentation](https://www.npmjs.com/package/express-handlebars)
`Express-Handlebars**` A specialized wrapper for using Handlebars with Express.js, offering better integration and configuration options.

Install express-handlebar:
```sh
npm install express-handlebars
```

**Directory Structure:**

```
.
├── app.js
└── views
    ├── home.handlebars
    └── layouts
        └── main.handlebars

2 directories, 3 files
```

**app.js:**

Creates a super simple Express app which shows the basic way to register a Handlebars view engine using this package.

```js
// import express and express-handlebars
import express from 'express';
import { engine } from 'express-handlebars';

const app = express();

app.engine('handlebars', engine());
app.set('view engine', 'handlebars');
app.set('views', './views');

app.get('/', (req, res) => {
    res.render('home');
});

app.listen(3000);
```

**views/layouts/main.handlebars:**
The main layout is the HTML page wrapper which can be reused for the different views of the app. `{{{body}}}` is used as a placeholder for where the main content should be rendered
```handlebars
...
<body>
	{{{body}}}
</body>
...
```


**views/home.handlebars:**
The content for the app's home view which will be rendered into the layout's `{{{body}}}`.
```handlebars
<h1>Example App: Home</h1>
```

*Note:* There will be a `main.handlebars` in `/views/layouts` directory, that will contain html syntax, and will be reused for different pages like `home.handlebars`, `blogs.handlebars` in `/view` directory.
Including common Content on `main.handlebars`, This prevent us from making, header, footer and other components copy paste for different pages.

# Now Continue our Express Application with Handlebars

*Update index.js*
```js
//index.js
const express = require('express')
// import handlebars
var exphbs = require('express-handlebars')

const path = require('path')
const app = express()
const port = 3000

// Registers Handlebars as the template engine for Express.
app.engine('handlebars', engine());
// Sets Handlebars as the default view engine for rendering templates.
app.set('view engine', 'handlebars');


app.use(express.static(path.join(__dirname, "static")))

app.use('/', require(path.join(__dirname, `routes/blogRoute.js` )))

app.listen(port, () => {
  console.log(`Blog app listening at http://localhost:${port}`)
})
```

Update blogRoute.js
```js
// blogRoute.js
const express = require('express')
const router = express.Router()
const path = require('path')
const blogs = rquire('../data/blogs')

router.get('/', (req, res)=>{
	// handle bar syntax to render `home.handlebars`
	res.render('home');
})

router.get('/blog', (req, res)=>{
	// handle bar syntax to render `blogHome.handlebars`
	res.render('blogHome', {
	// <key used in the Handlebars template> : <variable from your Express application containing the data>
	blogs: blogs
	});
})


router.get('/blogpost/:slug', (req, res)=>{
	myBlog = blogs.filter((elem)=>{
		return elem.slug == req.params.slug
	})
	// 
	res.render('blogPage', {
		title: myBlog[0].title,
		content: myBlog[0].content})
		// myBlog is array so used myBlog[0] to send only one blogPost.
});

module.exports = router```

Create main.handlebars,
```handlebars
...
<body>
	</nav>
	...
	<a href="/blog"> Blog </a>
	...
	</nav>
	{{{body}}}
</body>
...
```
We added links to route to `/blog`

Create home.handlebars
```html
this is home.handlebars.
```


Create blogHome.handlebars
```handlebars
{{#each blogs}}
	<div class="blog">
		<a href="/blogpost/{{this.slug}}"></a>
		<h2> {{this.title}}</h2>
	</div>
	{{/each}}
```
- blogs is the data of the blogHome.handlebars
- this.title -> blog.title -> title of each blog (Displayed as Heading lists)
- this.slug -> blog.slug -> kind of identifier of each post ( use to make specific link for each post )

*Note:* the variables in .handlebars, like blog , this etc are javascript variable comes from the express app

*Note:* **Helpers** in Handlebars are custom functions that you can use within your templates to perform operations or transformations on data. They help keep templates clean by moving logic into reusable functions. (e.g., `{{#if}}`, `{{#each}}`).

Create blogPage.handlebars (Page for Each Posts)
```handlebars
<h2>{{title}}</h2>
<p>
	{{content}}
</p>
```

This was the Basic Structure of the blog post

Final blog App, File Directory Structures
```
project
├── index.js
├── routes
│      └── blogRoute.js
└── views
    ├── home.handlebars
    ├── bloghome.handlebars
    ├── blogPage.handlebars
    └── layouts
        └── main.handlebars
```
## Additionally , We can use mongoose to connect to the MongoDB Database : )

Remaining video is on hosting
# Host on DigitalOcean

**DigitalOcean** is a cloud computing service provider that offers scalable virtual servers known as **Droplets**. Droplets are customizable virtual private servers (VPS) used for hosting applications, websites, and databases. DigitalOcean provides a user-friendly platform with features like pre-configured server images, managed databases, and scalable resources.

### Hosting Express/Nodejs

1. **Create a Droplet**:
   - Sign up for DigitalOcean and create a Droplet with your desired specifications (e.g., OS, size).

2. **Set Up Your Server**:
   - SSH into your Droplet using the credentials provided.
   - Update the server and install Node.js and npm.
   - Transfer your Express app code to the server (e.g., using `scp`, Git, or FTP).

3. **Install Dependencies**:
   - Navigate to your app directory and run `npm install` to install dependencies.

4. **Run Your Express App**:
   - Start your app using `node app.js` or a process manager like PM2 (`pm2 start app.js`).

5. **Configure a Reverse Proxy** (optional but recommended):
   - Install and configure Nginx to act as a reverse proxy for better performance and security.

6. **Set Up a Domain and SSL** (optional):
   - Point your domain to your Droplet’s IP and set up SSL for secure connections (e.g., using Certbot).

### Benefits of Hosting on DigitalOcean

- **Scalability**: Easily resize resources or add more Droplets as your needs grow.
- **Cost-Effective**: Affordable pricing with predictable monthly costs.
- **Customizable**: Flexible configuration options for your server environment.
- **Performance**: High-performance SSD-based storage and data center options.
- **Support**: Extensive documentation and community support.

This setup allows you to deploy and manage your Express application on a reliable cloud platform.