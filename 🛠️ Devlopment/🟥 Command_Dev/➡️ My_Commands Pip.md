
## Python 

```sh
# Check python version (py ~ python, -v ~ --version)
python --version
# or
py -v

# Run python program
py app.py
#or
python app.py
```

```python
# Install package within a python script
import subprocess
subprocess.run(['pip', 'install', 'opencv-wrapper'])
```

---
### Pip Installs Packages (pip)

`pip` is the package installer for Python. It allows you to install and manage additional libraries and dependencies from `PyPI` or other sources that are not part of the standard Python library.
or
`pip` is a package management system used to install and manage software packages written in Python. It stands for "Pip Installs Packages." 

*Note:* 
- Installing `Python` will install `pip` automatically. 
- In `pip` 'i' doesn't stand for `install`

**Install Package**
```sh
# insttall package
pip install package_name

# Install multiple packages
pip install package_name1 package_name2 

# Install Specific Version
pip install package_name==version # pip install django==3.2.5

# Install from requirements.
pip install -r requirements.txt
```

**Upgrade Package**
```sh
# Upgrade NumPy:
pip install --upgrade package_name
```

**Uninstall Package**
```sh
# Uninstall Package
pip uninstall package_name
```

**List Packages**
```sh
# List All installed packages
pip list

# List Outdated Packages:
pip list --outdated

# show package information
pip show package_name
```

**Generate a Requirements File:**
```sh
pip freeze > requirements.txt
```

Note:
- **`pip`**: Used in the command line/terminal to install Python packages.
- **`!pip`**: Used in Jupyter Notebooks to run `pip` commands within a code cell.
- **`%pip`**: A newer magic command in Jupyter Notebooks that ensures package installation in the notebook's Python environment.
---
### Virtual env

Virtual environments are a fundamental tool in Python development, allowing you to manage dependencies and project environments more effectively. They ensure that your projects remain isolated and that your development setup remains clean and organized.

*Note:* The `venv` module is not a standalone command; it must be run as a module/script using the `-m` option.

```sh

#----- Create using `venv` (Built-in Module) -------

# Create a Virtual Environment
python -m venv myenv 

# Activate (Window)
myenv\Scripts\activate

# Now  install packages in Virtual env
pip install package_name 

#deactivate
deactivate


#or -------- Create using `virtualenv` (Third-Party Package) ------

# install virtual env
pip install virtualenv

# Create Virtual env
virtualenv myenv

# Activate, Intsall, Deactivate using same method
```

---

## Flask

```sh
# install Flask
pip install Flask

# Create app.py and Run the application
python app.py
```

*Note :* Jinja2 templating is Included with flask so no explicitly install required
