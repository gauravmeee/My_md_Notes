
## npm (Node Package Manager)

`npm`  is a package manager for JavaScript, primarily used to manage dependencies for Node.js projects. It is the default package manager that comes with Node.js, which allows developers to share and reuse code.

*Note:* installing `Node` automatically install `npm`

Initialize (`Node`)
```sh
# intialize a new project
npm init -y # -y(optional) -> yes all prompts

```

Packages (`Dependencies : package.json`)
```sh
# install all dependencies from package.json
npm install

# Install package
npm i package_name # i -> install
#or
npm install package-name

# install a specific version
npm install package-name@version

# upgrade all dependencies
npm update

# update package
npm update package-name

# unistall
npm uninstall package-name

# List installed packages
npm list

# view outdated packages
npm outdated
```

Development Dependencies (`devDependencies:Package.json`)
```sh
npm install package-name --save-dev
```
*Note:* Dev dependencies are packages that are only needed during the development of a project, not in the production environment.

Run (`Script : Package.json`)
```sh
# Run Script "start": "node src/app.js" "dev": "nodemon src/app.js"
npm run script_name
# or
# Run `app.js` manually
node src/app.js
```

*Note:* `npm start` is a shorthand of `npm run start` to run the `start` script defined in `package.json`.
*Note:* It is not necessary to share the `node_modules`. All dependencies in this folder are already specified in you `package.json` and `package-lock.json`(or yarn.lock)

---
## yarn

`Yarn` is a package manager for JavaScript, similar to **npm**. It was developed by Facebook  to address some of the shortcomings of` npm` at the time. Yarn introduced several features to improve performance, reliability, and security when managing dependencies.

*Note:* Both npm (`package-lock.json`) and Yarn (`yarn.lock`) use a `lockfile` to ensure consistency across different environments.

Yarn
```sh
yarn init

yarn # npm install
 
yarn add package-name # add -> install

yarn add package-name@version

yarn add package-name --dev

yarn global add package-name # global -> -g

yarn upgrade # upgrade -> update

yarn upgrade package-name 

yarn remove package-name # remove -> uninstall

yarn list

yarn outdated

yarn run script-name
```

---
## Express

```sh
# Create an new project directory
mkdir my-express-app
cd my-express-app

# Initialize Node.js Project
npm init -y

# Install Express
npm install express

# run the server
node index.js

# install and start nodemon for autostart
npm install --save-dev nodemon
npm run dev

# Install MongoDB Client (ex mongoose)
npm install mongoose
```

---
## React
```sh
# Creat New react project
npx create-react-app my-react-app

# go to directory
cd my-react-app

# run the app
npm start
```

---
### React-Native
```sh
# Create a new react-native project
npx react-native init ProjectName

# run the app
npx react-native start 

# run in android
npx react-native run-android
```

---
### Vite

`Vite` is a modern frontend build tool that provides a faster and more efficient development experience for web applications
Vite works seamlessly with `React, Vue, and Svelte.`

```sh
# Initialise Vite (with react template)
npm init vite@latest my-project -- --template react

# go to directory
cd my-project

# Install required packages 
npm install
```

*Note :* You can install vite explicitly using
`npm install vite` even with `-g` or `--save-dev` options

---
### Dotenv

The `dotenv` package reads environment variables from a `.env` file located in the root of your project and loads them into `process.env`, making them available throughout your application.

Install `dotenv`
```sh
npm install dotenv
```

Create `.env` File
```.env
PORT=3000 MONGODB_URI=mongodb+srv://username:password@cluster.mongodb.net/mydatabase JWT_SECRET=your_jwt_secret_key
```
*Note:* If using local mongodb `MONGO_URI=mongodb://localhost:27017/your-database-name`

Load and Access the Environment variable
```javascript
import dotenv from 'dotenv';

dotenv.config();  // Load environment variables from .env file

// Now you can access environment variables
const mongoUri = process.env.MONGO_URI;
const jwtSecret = process.env.JWT_SECRET;
const port = process.env.PORT || 3000;
```

Add `.env` to `.gitignore` to protect sensitive information.
```.gitignore
.env
```
---
### Nodemon

`nodemon` is a tool that automatically restarts your Node.js application when it detects file changes. This is particularly useful during development

```sh
# install nodemon
npm install --save-dev nodemon

# start your application
nodemon index.js

# scripts{"dev":"nodemon index.js"}
npm run dev 
```
*Note :* install with `--save-dev` is recommended for project-specific use rather than `-g` option

---
### Docker

Docker is a platform that automates the deployment, scaling, and management of applications using containerization. Containers are lightweight, portable, and consistent across different environments. Docker enables you to package an application with its dependencies into a container, ensuring it runs the same way regardless of where it’s deployed.

---
## Work on 
Express, 
Flask, 
React, 
Vite,
dotenv, 
Docker

## Study
REDUX & REDUX
State and HOOK
React-DOM
Vite
Nodemon