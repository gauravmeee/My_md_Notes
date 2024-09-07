
## python 

```sh
# Check python version (py ~ python, -v ~ --version)
python --version
# or
py -v

# Run python program
py app.js
#or
python app.js
```

```python
# Install package within a python script
import subprocess
subprocess.run(['pip', 'install', 'opencv-wrapper'])
```

### pip (Pip Installs Package)

`pip` is the package installer for Python. It allows you to install and manage additional libraries and dependencies from PyPI or other sources that are not part of the standard Python library.

*Note:* Installing `Python` will install `pip` automatically. 
In `pip` 'i' doesn't stand for `install`

```sh
# insttall package
pip install package_name

# Install Specific Version of Django
pip install django==3.2.5

# Install from requirements.
pip install -r requirements.txt

# Upgrade NumPy:
pip install --upgrade numpy

# Uninstall Package
pip uninstall package_name

# List Outdated Packages:
pip list --outdated

# view package information
pip show package_name
```

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
