# Jupyter

1. **Jupyter Notebook :** a simple, easy-to-use interface for individual notebook documents.
2. **JupyterLab :** more powerful, flexible, and integrated environment for handling multiple documents and tools in your data science and development workflows.

---
# [Jupyter Lab Desktop Installation Tutorial](https://youtu.be/JYs2k9haGRM)

**Official Download Link**:- https://github.com/jupyterlab/jupyterlab-desktop

---
# [Jupyter Lab Browser Tutorial🔥🔥](https://youtu.be/6jgpCSYiV_o)

Use terminal to Install

**Install :**
```
pip install jupyterlab
```

**Run Jupyter lab :**
```
jupyter lab
```

This will open a webapp, but work and save data on your local computer

**Uninstall Jupyter Lab**
```sh
pip uninstall jupyterlab
```

**To clean leftover dependencies (optional but recommended):**
```sh
pip uninstall jupyter-core jupyter-client ipykernel ipython
```

---
# Jupyter Notebook Browser 

Use terminal to Install

**Install :**
```
!pip install notebook
```
- In **Jupyter Notebooks**, the `!` is used to run **shell commands** (system commands) directly from the notebook environment.

**Run Jupyter notebook :**
```
jupyter notebook
```
- Opens a **web app** in your browser.
- Works and saves data **on your local computer**.


**Open Jupyter in Specific Folder (Outside Default Root) :**
```
jupyter notebook --notebook-dir="D:/gkmee/Downloads/BTP Project"
```

**Open Path Inside Root Folder (via UI) :**
```
File -> Open from Path -> Enter Path.
```
- Only works for paths **inside** the root directory.
- Windows supports `/` or `\\` for paths.

**Uninstall Jupyter Notebook:**
```sh
pip uninstall notebook
```

**To clean leftover dependencies (optional but recommended):**
```sh
pip uninstall jupyter-core jupyter-client ipykernel ipython
```
- These are **core dependencies** of both Jupyter Notebook and JupyterLab.  
- Uninstalling them breaks Jupyter kernel execution and interactivity.  
- Only use when fully uninstalling Jupyter ecosystem.

---


