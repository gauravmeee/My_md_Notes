# Git Workflow Guide

## Prerequisites - Install (Git)

1. Go to the LevelUp Tech LMS frontend repository.
2. Click on the "Fork" button.
3. Create a fork - select the "master" branch (selected by default but check if not).
4. A copy of the repo will be created in your account under "Your repositories."
5. Go to the forked repository, click on the green "Code" button.
6. Copy the HTTP URL.
7. On your local machine (any folder you want to save that file), open a command prompt or terminal.
8. Type `git clone [http://your-repo-url.git](http://your-repo-url.git)` (link copied in step 6).
9. The LMS frontend folder will be copied. You can then open it in VS Code or your preferred IDE.
10. Open the terminal within your IDE or command prompt.
11. Switch to your branch from the master branch:
    ```bash
    git checkout -b "your_branch_name"
    ```
12. To check if the remote URL is correct:
    ```bash
    git remote -v
    ```
    (Ensure that it is connected to your GitHub LMS frontend repo).

## The above is a one-time process.

## For every change you make:

13. Do your work (e.g., adding functionalities). To see which files are changed:
    ```bash
    git status
    ```

14. To track all the untracked files (i.e., changed files):
    ```bash
    git add .
    ```

15. Push your changes to your repo:
    - For the first time:
      ```bash
      git push -u origin "your_branch_name"
      ```
    - For subsequent pushes:
      ```bash
      git push
      ```

16. Go to your GitHub account, select the LMS frontend repo. You will see a notification with a button (Compare & pull request). Click that, and you will see the files you have changed.

17. You will see something like this:
    ```
    leveluptechno/lmsfrontend <- (development_your_name) <-- your_github_account/lmsfrontend (your_branch_name)
    ```

18. Click the "Create pull request" button and you’re done! 👍
