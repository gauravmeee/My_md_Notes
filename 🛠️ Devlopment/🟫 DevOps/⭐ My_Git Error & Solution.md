


### Git Push Error: Rejected - Non-Fast-Forward

**Error Message !**
```
! [rejected]        master -> master (non-fast-forward)
error: failed to push some refs to 'https://github.com/username/repo.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. If you want to integrate the remote changes,
hint: use 'git pull' before pushing again.
```

**What it means:**
- Your **local branch is behind the remote branch**, i.e., someone else (or you from another machine) has pushed commits to GitHub, and you don’t have them locally.
- Git refuses to push because it doesn’t want to overwrite others' work without your confirmation.

**Solution: Pull with Rebase (Safe Way)**
- Use this when you want to **pull remote changes and put your own changes on top**:
```bash
git pull --rebase origin master
```

**What it does:**
1. Temporarily removes your local commits.
2. Pulls the latest remote changes.
3. Re-applies your commits on top of the latest version.
4. Avoids unnecessary merge commits (clean history).

---

**If Conflicts Occur:**

- Git will stop and show:
```
CONFLICT (content): Merge conflict in file.js
```

- Then:
1. Manually fix the file.
2. Mark resolved:
    ```bash
    git add <file>
    ```
    
3. Continue rebase: 
    ```bash
    git rebase --continue
    ```
    
**After Rebase:**
- Now your branch is updated, so push it:
```bash
git push origin master
```
