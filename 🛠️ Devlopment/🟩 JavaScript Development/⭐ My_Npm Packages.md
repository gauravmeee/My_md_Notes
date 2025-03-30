
## Backend

Create and Navigate to new Directory and Setup
```sh
mkdir backend
cd mern-backend
npm init -y
```

Install Packages from `Package.json`
```
npm i
```

- express
- mongoose
- dotenv
- cors
- body-parser
- nodemon
- axios

## Frontend

Navigate to Project root and Create react App
```
cd..
npx create-react-app client
cd client
```

Install Packages from Package.json
```
npm i
```

- react
- react-router-dom
- axios
- react-hot-toast
- redux
- react-redux

---

# dotenv
**dotenv**: This package is used to load environment variables from a `.env` file into `process.env`. It's useful for managing configuration settings like database credentials, API keys, and other sensitive data that you don't want to hard-code into your application. 

   **Usage**:
   - Install with `npm install dotenv`.
   - Create a `.env` file in your project's root directory with your environment variables.
   - Load the variables at the start of your application with `require('dotenv').config()`.

   ```js
   require('dotenv').config();
   const dbPassword = process.env.DB_PASSWORD;
   ```

# mongoose

 **mongoose**: Mongoose is an Object Data Modeling (ODM) library for MongoDB and Node.js. It provides a schema-based solution to model your application data and includes built-in type casting, validation, and query building.

   **Usage**:
   - Install with `npm install mongoose`.
   - Connect to a MongoDB database and define schemas and models for your data.

   ```js
   const mongoose = require('mongoose');
   mongoose.connect(process.env.MONGO_URI, { useNewUrlParser: true, useUnifiedTopology: true });

   const UserSchema = new mongoose.Schema({
     name: String,
     email: String
   });

   const User = mongoose.model('User', UserSchema);
   ```

# cors

 **cors**: CORS (Cross-Origin Resource Sharing) is a middleware for Express that allows you to configure which domains are permitted to make requests to your server. This is important for security and to ensure that your API can be accessed from different origins as needed.

   **Usage**:
   - Install with `npm install cors`.
   - Use it as middleware in your Express app.

   ```js
   const express = require('express');
   const cors = require('cors');
   const app = express();

   app.use(cors()); // Allows all origins
   // or
   app.use(cors({ origin: 'http://example.com' })); // Restricts to specific origin

   app.get('/data', (req, res) => {
     res.json({ message: 'This is CORS-enabled for all origins!' });
   });
   ```

# body-parser

**body-parser**: This middleware is used to parse incoming request bodies in a middleware before your handlers, available under the `req.body` property. It's useful for parsing JSON, URL-encoded, and other types of request payloads.

   **Usage**:
   - Install with `npm install body-parser`.
   - Use it to parse different types of request bodies.

   ```js
   const express = require('express');
   const bodyParser = require('body-parser');
   const app = express();

   app.use(bodyParser.json()); // Parses JSON payloads
   app.use(bodyParser.urlencoded({ extended: true })); // Parses URL-encoded payloads

   app.post('/submit', (req, res) => {
     console.log(req.body);
     res.send('Data received');
   });
   ```

These packages are often used together in an Express application to handle environment configuration, database interactions, cross-origin requests, and request body parsing.


---
# Remove unused dependencies from your Node.js project

**Identify Unused Dependencies**
```sh
npx depcheck
#or
npx npm-check
```

**Remove Unused Dependencies from** `package.json`, `package-lock.json` & `node_modules`
```
npm uninstall <package_name1> <package_name2> ...
```

**Prune Extraneous Packages** : 
```sh
npm prune
```
- To remove any remaining extraneous packages those in `node_modules` but not listed in `package.json`

**Remove Development Dependencies (Optional)**
```sh
npm prune --production
```
