# Package Manager

---
## Node Package Manager (npm)

`npm` (Node Package Manager) is used for managing packages in a Node.js project. It allows you to install, update, and uninstall packages, as well as manage your project's dependencies.

**Project Initialization:** Initialize a new Node.js project and create a `package.json` file
```sh
npm init

# initialize default setting without prompts
npm init -y 
```

**Package Installation:** Install all dependencies listed in `package.json`
```sh
npm install

# use `i` in place of `install` 
npm i
```

Install a specific package and add it to `dependencies` in `package.json`
```sh
npm install <package-name>

# Install multiple package
npm install <package-name1> <package-name2>

# add it to `devDependencies` in package.json.
npm install <package-name> --save-dev

#Install a specific version of a package.
npm install <package-name>@<version>

# Install a package globally
npm install <package-name> -g
```
**Package Removal:** Install a Specific package and remove it from `dependencies` in `package.json`

```sh
npm unistall <package-name>

# Uninstall a package from `devDependencies`
npm uninstall <package-name> --save-dev

# Uninstall a globally installed package
npm uninstall -g <package-name>
```

**Viewing Packages**: List all installed packages and their dependencies.
```sh
npm list

# list all globally installed packages
npm list -g

# list outdated package
npm outdated
```

**Updating Packages:** Update all packages to the latest version according to the `package.json` version range.
```sh
npm update

# Update a specific package to the latest version
npm update <package-name>
```

**Running Scripts:** Run a script defined in the `scripts` section of `package.json`
```sh
npm run <script-name>

# Run the test script defined in the `scripts section of package.json.
npm test
```

**Miscellaneous:**
```sh
# Run a security audit of your project's dependencies.
npm audit

# Automatically fix vulnerabilities found by npm audit.
npm audit fix
 
# Clear npm's cache.
npm cache clean --force

# Set an npm configuration key to a value.
npm config set <key> <value>

# Get the value of an npm configuration key.
npm config get <key>

# Display help information for npm commands.
npm help: 
```

`npx` is a tool (that come with npm v5.2.0 & above) to execute packages. It allows you to run Node.js commands without globally installing the package. It is useful for running CLI tools and one-off commands.

```sh
# create react project with npx
npx create-react-app my-app

# without npx
npm install -g create-react-app
create-react-app my-app
```

---
## Pip Installs Packages (pip)

`pip` is a package management system used to install and manage software packages written in Python. It stands for "Pip Installs Packages." 

**Install a Package:**
```sh
pip install package_name

# Install multiple packages
pip install package_1 package_2 

# Install Specific Version
pip install package_name==version
```

**Upgrade Package**
```sh
pip install -upgrade package_name
```

**Uninstall Package**
```sh
pip uninstall package_name
```

**List Installed Packages:**
```sh
pip list
```

Show Package Information:
```sh
pip show package_name
```

Check for Outdated Packages:
```sh
pip list --outdated
```

Install Packages from a Requirements File:
```sh
pip install -r requirements.txt
```
Generate a Requirements File:
```sh
pip freeze > requirements.txt
```
