```sh
# Initialise a new git repository
git init

# Create a new README.md
echo "# Project Title" > README.md

# Add specific file to the Staging Area
git add README.md

# Add all changes to the staging area.
git add .

# After stagin, you need to commit them.
git commit -m "ADD README.md with project description"

# show the current status of your working directory and staging area.
git status
```

```sh

# Add remote repository to your local git configuration.
git remote add origin https://github.com/username/repository.git

# Update remote repository to your local git configuration.
git remote set-url origin https://github.com/username/repository.git

# verify or list the remote repositories and their urls
git remote -v


# Push Changes to the remote repository (master/main)
git push origin master

# note: using "git push -u origin master", "-u" flag sets the upstream for the branch so feature pushes can be done with just "git push"

# push subsequent changes
git push

# pull changes from the remote repository
git pull origin master

# Rename the remote from origin to something else
git remote rename origin "new-origin"

# Remove remote
git remote remove origin 

# Clone a repository
git clone https://github.com/username/repository.git

#clone a specific branch
git clone --branch branchname https://github.com/username/repository.git

# Create a new branch
git checkout -b my-new-branch

# switch existing branches
git checkout my-new-branch

# Merge another branch into current branch
git merge main

# view commit history
git log
```

More
```sh
# Remove file
git rm mynotes/javascript.md

# Stage file at once
git add -u
```

.gitignore
```sh
# Create a .gitignore
touch .gitignore # only for linux-based system
# or
echo. > .gitignore ✅
# or
copy nul .gitignore

# add node_modules/ in .gitignore
echo node_modules/ >> .gitignore ✅

# Edit a .gitignore
nano . gitignore

# Check ignored files
git status --ignored
```

Manual Add  .gitignore file 
```sh
# .gitignore
# Ignore all .log files
*.log

# Ignore node_modules directory
node_modules/

# Ignore specific file
config/settings.json

# Ignore all files in tmp directory
tmp/**/

```

---
### Undo Changes Using `reset` and `revert`

**Reset hard**
```sh
# Resets working directory, staging area, and HEAD to last commit (all local changes lost)
git reset --hard                 

# Moves HEAD 2 commits back, discards changes
git reset --hard HEAD~2         

# Resets everything to specific commit (destructive)
git reset --hard <commit-hash>  
```

**Reset soft**
```sh
# Moves HEAD to last commit (default), keeps changes in staging
git reset --soft                

# Moves HEAD 2 commits back, keeps changes in staging
git reset --soft HEAD~2         

# Moves HEAD to specific commit, keeps changes in staging
git reset --soft <commit-hash>  
```

**Reset mixed** (default)
```sh
# Unstages changes, keeps working directory as-is
git reset --mixed               

# Moves HEAD back 2 commits, unstages changes
git reset --mixed HEAD~2        

# Same as above but to specific commit
git reset --mixed <commit-hash> 
```

**Revert**
```sh
# Creates a new commit that undoes changes made by the target commit
git revert <commit-hash>        
```
- **Safe** way to undo commits (used in public/shared branches)
- Does not delete commit history


 **Clean** working directory
```sh
git clean -fd  - # Removes untracked files (-f) and directories (-d)
```

|Type|HEAD Moved|Staging Changed|Working Dir Changed|History Changed|Use Case|
|---|---|---|---|---|---|
|`--soft`|✅ Yes|❌ No|❌ No|✅ Yes|Undo commits, keep code staged|
|`--mixed`|✅ Yes|✅ Yes|❌ No|✅ Yes|Unstage commits, keep code|
|`--hard`|✅ Yes|✅ Yes|✅ Yes|✅ Yes (dangerous)|Remove commits + code|
|`revert`|✅ Yes|✅ Yes|✅ Yes|❌ No (safe)|Undo commit by creating a new one|

---
    
### Creating New Branch on Git and Push on New Branch in Github

   ```bash
   # Create a New Branch Locally
   git checkout -b new-branch-name
   
   # Push the New Branch to GitHub
   git push -u origin new-branch-name
   ```

_Note:_ This process is useful for managing different versions or features within the same project by using separate branches.


---

# Revert all changes up to the last commit. There are two main ways:

1. Discard all changes but keep the files (safer option)
2. Hard reset to the last commit (more aggressive option)

Let me show you both approaches:

First, let's see what changes are currently pending:
```bash
git status
```

##### **Method 1** -  Safer Option (Recommended)
```bash
git restore .                  # Restore tracked files
git clean -fd                  # Remove untracked files and directories
```

##### **Method 2** - Aggressive Option:
```bash
git reset --hard HEAD          # Hard reset to last commit
git clean -fd                  # Remove untracked files and directories
```

- `git restore .` is safer and more modern (This will discard changes but keep your files)
- `git reset --hard HEAD` is more aggressive and will completely reset everything

---
# Revert all changes to a specific commit. There are two main ways

Use `git log` to get the `<commit-hash>`.
```sh
git log
```

Shorten output in `<commit-hash> : <commit-message>`
```sh
git log --oneline
```

##### **Method 1 -** Hard reset (Dangerous, deletes changes):
```bash
git reset --hard <commit-hash>
git clean -fd                  # Remove untracked files and directories
```

##### **Method 2 -** Soft reset (Keeps changes staged):
```bash
git reset --soft <commit-hash>
git clean -fd                  # Remove untracked files and directories
```

##### **Method 3 -** Revert (Undo commit but keep history):
```bash
git revert <commit-hash>
git clean -fd                  # Remove untracked files and directories
```

---
## Fetch specific commit from GitHub:


Downloads all commits, branches, and tags from the remote (`origin`), **but doesn't change your working directory**.
```bash
git fetch origin
```

**Moves HEAD and working directory to that specific commit**, entering a **detached HEAD state** (not on any branch).  **Moves HEAD and working directory to that specific commit**, entering a **detached HEAD state** (not on any branch).  
```bash
git checkout <commit-hash>
```
- It is Useful for reviewing or extracting files from that state.

---

## Push on GitHub when `master` branch is **behind** the remote `master` branch. To fix this:

##### **Method 1** - Safe Way (Recommended):
```bash
git pull --rebase
git push
```

##### **Method 1** - Force Push (if sure your changes should overwrite remote):
```bash
git push --force
```

> Use force only if you're sure you don't need remote changes.


---