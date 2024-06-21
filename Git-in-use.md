# Create New Repository
```bash
echo "# My-Notes" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M master
git remote add origin https://github.com/gauravmeee/My-Notes.git
git push -u origin master
```
# Push existing repository
```bash
git remote add origin https://github.com/gauravmeee/My-Notes.git
git branch -M master
git push -u origin master
```


# 1. To ignore node_modules (prevent from uploading on github)
1.  create a `.gitignore` file in project's root directory 
```bash
touch .gitignore
```
 manually specify this line in the file
   ```.gitignore
   node_modules/
   ```

**or**
Create and update the .gitignore file through command line

```bash
echo "node_modules/" >> .gitignore
```

<br/>

3.  Save and commit

  ```bash
  git add .gitignore
  git commit -m "Add .gitignore to exclude node_modules"
  ```
<br/>

4. Check `node_modules` not included in the list of files to be committed
   ```bash
    git status
   ```
   <br/>
5. Push your code to GitHub repo
   ```bash
     git push origin main
   ```
   
