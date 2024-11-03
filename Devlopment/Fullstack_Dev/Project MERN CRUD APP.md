Make Project Directory 
```
My-CRUD-APP
```

Create Frontend (Client)
```sh
npx create-react-app client
```

Make Server Directory
```
My-CRUD-APP
	├── client
	└── Server
```

Open Server Directory
```sh
cd server
```

Setup Backend (Server)
```sh
npm init -y
 ```
or
```sh
npm init
```
```
.....package.json
 
package name : (server) crud-mern-app
version: (1.0.0)
discription:
entry point: (index.js)
test command:
git repository:
keywords:
author: Gaurav Meena

Is this OK? (yes) yes
```

# Backend

Install Packages
```sh
npm i express mongoose body-parser dottenv cors
```

install nodemon
```sh
npm i --save-dev nodemon
```

Create Directories for Controller, Routes, Model and index.js and .env file
```
My-CRUD-APP
	├── client
	└── server
		├── controller
		|      └── userController.js
		├── model
		|		└── userModel.js
		├── routes
		├── .env
		├── index.js
		└── package.json
```

package.json
```
// package.json
.
.
"main": "index.js",
"type": "module", // because we will use `import` method not `require`
"script":{
	"start": "nodemon index.js"
}
.
.
```

.env
```env
// .env

PORT = 8000
MONGOURL = "mongodb+srv://gaurav28official:169@gkmeena.d8ustvt.mongodb.net/crudApp?retryWrites=true&w=majority&appName=gkmeena"

// change 'crudApp' according to your database
```

Index.js
```js
// index.js
```

userModel.js
```js
// userModel.js
import mongoose from "mongoose";

const userSchema = new mongoose.Schema({
	fname:{
		type: String,
		required: true
	},
	lname:{
		type: String,
		required: true
	},
	email:{
		type: String,
		required: true
	},
	password:{
		type: String,
		required: true
	},
})

export default mongoose.model("User", userSchema);
```

userController.js
```js
// userController.js
import User from "../model/userModel.js";

export const create = async(req, res)=>{
	try{
		const userData = new User(req.body);

		if(!userData){
			return res.status(404).json({msg: "User data not found });
		}
		const saveData = await userData.save();
		res.status(200).json(saveData);
		
	}catch(error){
		res.status(500).json({error: error});
	}
}

```

userRoute.js
```js
// userRoute.js

```

# Frontend

Install Packages 
```sh

```