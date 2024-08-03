
# [React Tutorial in Hindi 🔥🔥](https://youtu.be/RGKi6LSPDLU)

 **What is React?**

React is a JavaScript library used to build single-page user interfaces. Although it's a library, it's often referred to as a framework due to its compatibility with other frameworks like AngularJS and VueJS.

**Single-Page Applications**

React is one of the most popular frameworks for building single-page applications (SPAs). In an SPA, the UI doesn't reload when navigating to another page or sending an HTTP request. Instead, the page updates dynamically, providing a seamless user experience.

**Library vs. Framework**

Frameworks provide a comprehensive set of functionality and often include pre-built components. Libraries, on the other hand, are more specialized and provide a specific set of functions or tools.

**JSX: JavaScript Syntax Extensions**

In React, we use JSX, which is an extension of JavaScript that allows you to write HTML-like code in your JavaScript files. JSX enables you to divide your website into reusable components, making it easier to manage and maintain. This is particularly useful when working with multiple team members on different parts of the project.

**Why Use React?**

You might wonder why use React when we already have HTML, CSS, and JavaScript. The answer is that building a complex application with HTML

If you were to build an application similar to a React app using only HTML and CSS, it would be time-consuming and challenging.

However, with React, the process becomes much easier. React provides many hooks that enable you to send data from one component to another in the form of props. Additionally, the React community has already created a wide range of packages that can be easily integrated into your project.

**Routing with React**

For client-side routing, you can use React Router DOM. This library helps to make routing smooth and seamless, allowing users to navigate between pages without seeing any loading screens.

**React Utilities and Hooks**

React offers a wide range of utilities and hooks that make it easy to build complex applications. With React, you have access to a vast ecosystem of tools and libraries that can help you streamline your development process.

##  Lets Get Started

To begin, you'll need to have Node.js and NPM (Node Package Manager) installed on your system. You can download and install Node.js from the official website, which will automatically include NPM.

Once installed, open a PowerShell or terminal and type the following commands to check if Node.js, NPM, and npx (a package runner) are properly installed:
```
node --version
npm --version
npx --version
```

> *Note:*  `npx` is a counterpart of `npm` that enables us to execute a package without downloading it. This is particularly useful when using the `create-react-app` utility or other packages, which can be executed using `npx` without the need for a permanent installation.

### Create React App

Open a folder where you want to create a React app, shift + right-click, and select "Open Windows PowerShell". Then, type:
```
npx create-react-app myapp 
```
This will create a new React app in a directory called `myapp`.

> *Note:* Project name can no longer contain capital letters. 'myApp' Invalid

### Files in Default React App

Open the project directory with VSCode (or your preferred code editor). You'll see the following files and directories:
```
myApp/
README.md
package.json
public/
favicon.ico
index.html
src/
...
```
The `package.json` file contains project details, such as dependencies and scripts. The `public` directory contains static assets, like the favicon and `index.html` file. The `src` directory contains the source code for your React app.

### Start Server

To start the app, run the following command:
```
npm start
```

This will start the development server, and your app will be available at:
`http://localhost:3000/`

You can also access the app from other devices on the same network by using the IP address and port: `http://192.168.0.103:3000/`

### index.html
let's talk about how React works its magic. When you open the app in a browser, you'll see that the source code only shows the `index.html` file, regardless of which page you navigate to. This is because React is a single-page application (SPA) framework.

The JavaScript files in the `src` directory target the `<div id="root">` element in `index.html` and inject dynamic content into it. As the user interacts with the app, the JavaScript files update the dynamic content accordingly.

> *Note:* If someone's computer doesn't have JavaScript or has it disabled, they will see the content inside `<noscript>...</noscript>`

### id="root"

From where does the content in `<div id="root">...</div>` come from?

- Close the `public/` directory; all development will be done in `src/`.
- `App.js` in the `src/` directory is the main app component we will use to develop the React application.

> *Note:* In a MERN stack application, `index.js` and `App.js` files are commonly written in JSX. While the code written is in JSX, the file extension can still be `.js`. It's common practice to use the `.js` extension for React components, even though they contain JSX syntax. Modern build tools like Babel can handle JSX syntax within `.js` files without any issues.

- `index.js` in `src/` is the entry point of React Application. 
```jsx
// index.js
...
ReactDOM.render(
	<React.StrictMode>
		<App />
	</React.StrictMode>,
	document.getElementById('root')
)
...
```
It takes two things: `App` (JSX) and the `root` selector.

In React, you can break your app into components according to your needs, like header, footer, etc. 
Let's go to the `App.js` component:
```jsx
// App.js
...
function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        
        <a className="App-link" href="https://reactjs.org" target="_blank" rel="noopener noreferrer" >

          Learn React
        </a>
      </header>
    </div>
  );
}
...
```
This includes HTML and JavaScript syntax, which is JSX, used in React components to insert dynamic JavaScript with HTML.

- `<div className="App">`: But what is `className`? We only know the `class` attribute.
    
    - `class` is a keyword in JavaScript, and so it would create a problem. That's why a new JSX keyword `className` is used.
    - Similarly, `for` in HTML is used as `htmlFor` in JSX.

- `<img src={logo}>`: Why is this written inside curly braces?
    
    - `logo` is a JavaScript variable, and to use it in HTML, we use `{}`.
    - Like you can print `<div>12 + 45</div>`: shows '12 + 45' on the webpage.
    - `<div>{12 + 45}</div>`: shows '57' on the webpage.

```jsx
// App.js
import logo from `./logo.svg`;
import './App.css'
```
Import is used to import modules, like CSS, to style our webpage.

If we use a wrong JavaScript variable or syntax inside `{}`, it will show an error on the webpage: 'Failed to compile'.

In React, we can create components in two ways:

- Class-based components
- Function-based components

We will go with function-based components, as it is good to start with.

Now, let's edit the `App.js` file.

This will give a compile error as it is invalid JSX ❌:
```jsx
function App(){
	return (
		</h3>My App</h3>
		<p> My app works</p>
	);
}
```

This will be valid
```jsx
function App(){
	return (
		<>
			</h3>My App</h3>
			<p> My app works</p>
		</>
	);
}
```
*Note:* The whole HTML that is returned in JSX should be wrapped in some single opening and closing tags. If no tags, then simply use `<>` and `</>`.