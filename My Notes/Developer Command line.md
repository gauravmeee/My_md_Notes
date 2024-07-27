## Development NPM-PIP Guide

### g++ ( GNU C++ compiler )
note:- installing `MinGW` will automatically install `g++`

```sh
# check g++ version
g++ --version
```
```sh
# compile the source "demo.cpp" to the compiled executable "demo"
g++ demo.cpp -o demo 

# compile the source "demo.cpp" to the compiled executable "a.exe"
g++ demo.cpp

# Run the program
g++ demo.exe
```

### npm (Node Packages Manager)

note:- installing `Node` automatically install `npm`
**node**
```
i (install)
-y (yes)
-g (globally)
```
```sh
# Initialise NodeJS project
npm init -y
```
```sh
# Install required packages
npm i express mysql cors body-parser
```
```sh
#nodemon
npm install nodemon
```

```sh
# Run `app.js` manually
node src/app.js
```
```sh
# Run using `script`(custom command) in `package.json`

# "start": "node src/app.js"
npm start

# "dev": "nodemon src/app.js"
npm run dev
```

it is not necessary to share the `node_modules`.
all dependencies in this folder are already specified in you `package.json` and `package-lock.json`(or yarn.lock)

```sh
# install all dependencies
npm install
#or
yarn install
```

**React**

```sh
# Creat New react project
npx create-react-app ProjectName
```
```sh
# run the app
npm start
```
**React-Native**
```sh
# Create a new react-native project
npx react-native init ProjectName
```
```sh
# run the app
npx react-native start 
```
```sh
# run in android
npx react-native run-android
```
**Vite**

```sh
npm install vite
# npm install -g vite
# npm install --save-dev vite

# you can also installed vite as  -g or --save-dev :
```
## python 
```sh
# Check python version
python --version
# alternatives:- python -v | py --version | py -v 
```
```sh
# Run python program
py app.js
#or
python app.js
```
```py
import subprocess

# Install package within a python script
subprocess.run(['pip', 'install', 'opencv-wrapper'])
```

### pip (Pip Installs Package)

note: Installing `Python` will install `pip` automatically.
```sh
# Install from requirements.
pip install -r requirements.txt
```
```sh
# Install Flask:
pip install flask

#install requests
pip install requests
```
```sh
# Install Specific Version of Django:
pip install django==3.2.5
```
note: in `pip` 'i' doesn't stand for `install`
```sh
# Upgrade NumPy:
pip install --upgrade numpy
```
```sh
# Uninstall Matplotlib:
pip uninstall matplotlib
```
```sh
# List Outdated Packages:
pip list --outdated
```
### Virtual env

```sh
# Create a Virtual Environment
python -m venv myenv 

# Activate the Virtual Environment
myenv\Scripts\activate

# virtual environment active, use pip to install packages
pip install package_name 

#deactivate
deactivate
```
note: - `-m venv`: This tells Python to run the `venv` module as a script.
Using  without the `-m` option will not work. The venv module is not a standalone command; it must be run as a module using the -m option.

### Create file
```sh
# create an empty file and empty if already exist
nul > index.html
```


### Running scripts is disabled on this system (PowerShell error)

Use `Cmd` or Change the `execution policy`

Change Execution Policy:
open `Powershell` as administrator.
```sh
# Check Execution Policy
Get-ExecutionPolicy
```
```sh
# Set Execution policy to RemoteSigned
Set-ExecutionPolicy RemoteSigned

# Set Execution policy to Unrestricted
Set-ExecutionPolicy Unrestricted
```
```sh
# Revert the Execution policy if it was originally remoteSigned
Set-ExecutionPolicy RemoteSigned

# Revert the execution policy to unrestricted
Set-ExecutionPolicy Restricted
```


### Documentations
[Mongodb Documentation](https://www.mongodb.com/docs/manual/)
[Postman Documentation](https://learning.postman.com/docs/getting-started/overview/)
[npm packages Documentation](https://www.npmjs.com/package)
[Mongoose Documentation](https://mongoosejs.com/docs/)
[Validator Documentation](https://www.npmjs.com/package/validator) 
[HTTP Status Codes](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)
## Compare Nodejs vs Python
npm - pip
express - flask, django
package.json - requirements.txt


### Package Installers
chocolatey - npm installer
brew - mongodb installer