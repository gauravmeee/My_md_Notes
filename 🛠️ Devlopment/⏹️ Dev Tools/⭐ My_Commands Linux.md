
# 🐧 LINUX COMMANDS – COMPLETE NOTES

👉 **Linux commands work in:**

- Linux Terminal
- Unix systems
- Git Bash (Windows – Unix-like)  
    ❌ Not native to Windows CMD / PowerShell

##### **DIRECTORY & FILE MANAGEMENT**

| Command       | Explanation                             |
| ------------- | --------------------------------------- |
| `ls`          | ==List files and directories==          |
| `pwd`         | ==Show current working directory path== |
| `cd`          | ==Change directory==                    |
| `mkdir dir`   | ==Create directory==                    |
| `rmdir dir`   | ==Remove empty directory==              |
| `rm file`     | ==Delete file==                         |
| `cp src dest` | Copy file `src` to `dest`               |
| `mv old new`  | Move file or directory `old` to `new`   |

**`ls`** options
- `ls` : List files and directories in the current directory
- `ls -a` : Show **all files**, including hidden files (those starting with `.`)
- `ls -l` : Show detailed listing: permissions, owner, size, modification time
- `ls -la` : Combine `-l` and `-a`: detailed listing **including hidden files**
- `ls -h` : Human-readable file sizes in `-l` mode (e.g., KB, MB)
- `ls -t` : Sort files by **modification time**, newest first
- `ls -R` : List **directories recursively**
    
 **`cd`** options 
- `cd dir` : Change directory to `dir` ⭐
- `cd ..` : Move **up one directory** (parent directory) ⭐
- `cd ~` : Go to **home directory** ⭐
- `cd -` : Go to the **previous directory**

**`mkdir`** options
- `mkdir -p path/to/dir` : Create nested directories; creates parent directories if they don’t exist

**`rm`** options
- `rm -i file` : Prompt **before deleting**
- `rm -r dir` : ==Delete directory `dir` **recursively**==, including all files/subdirectories ⭐
- `rm -rf dir` : Force delete directory `dir` **without prompting**, even if not empty
    
**`cp`** options
- `cp -r src dest` : Copy **directory recursively**
    
**`mv`** options
- `mv file dir/` : Move file to another directory
- `mv oldname newname` : Rename a file or directory
    
**Notes / Tips**
- `-r` (recursive) is used for **directories**.
- `-f` (force) skips prompts.
- `-i` (interactive) asks before overwriting.
- ==Hidden files in Unix start with a **`.`** (dot).==


##### **FILE VIEWING & TEXT COMMANDS**

|Command|Explanation|
|---|---|
|`cat file`|Display file content|
|`more file`|View file page by page|
|`less file`|Advanced paging|
|`head file`|Show first 10 lines|
|`tail file`|Show last 10 lines|
|`nano file`|Simple text editor|
|`vi file`|Advanced text editor|


##### **SEARCH & FILTER COMMANDS**

|Command|Explanation|
|---|---|
|`grep "word" file`|Search text in file|
|`find`|Search files/directories|
|`sort file`|Sort file content|
|`uniq`|Remove duplicate lines|
|`wc file`|Count lines, words, characters|


##### **USER & LOGIN COMMANDS**

|Command|Explanation|
|---|---|
|`whoami`|Show current user|
|`who`|Logged-in users|
|`id`|User ID and group|
|`passwd`|Change password|
|`logout`|Exit session|


##### **PERMISSION & OWNERSHIP (VERY IMPORTANT)**

| Command   | Explanation             |
| --------- | ----------------------- |
| `chmod` ⭐ | Change file permissions |
| `chown`   | Change file owner       |
| `chgrp`   | Change group            |

**Permission Values :**

- `r = 4` (read)
- `w = 2` (write)
- `x = 1` (execute)
    

Example 1:
```
chmod 755 file
```
```
-> rwx r-x r-x

Owner (user): rwx
Group:        r-x
Others:       r-x
```

Example 2:
```
chmod 756 file
```
```
-> rwx r-x rw-

Owner (user): rwx
Group:        r-x
Others:       rw-
```

- `-` after `rw` is important — it represents a **missing permission**

##### **PROCESS MANAGEMENT**

| Command    | Explanation               |
| ---------- | ------------------------- |
| `ps`       | Process status            |
| `top`      | Running processes         |
| `kill pid` | Kill process ⭐            |
| `killall`  | Kill by name              |
| `bg`       | Run process in background |
| `fg`       | Bring to foreground       |

##### **SYSTEM INFORMATION COMMANDS**

|Command|Explanation|
|---|---|
|`date`|Show date & time|
|`cal`|Calendar|
|`uptime`|System running time|
|`uname`|System info|
|`df`|Disk usage|
|`du`|Directory size|
|`free`|RAM usage|

##### **NETWORK COMMANDS**

| Command    | Explanation             |
| ---------- | ----------------------- |
| `ping`     | Check connectivity ⭐    |
| `ifconfig` | Network configuration ⭐ |
| `netstat`  | Network statistics ⭐    |
| `ssh`      | Remote login ⭐          |
| `ftp`      | File transfer ⭐         |

##### **ARCHIVE & COMPRESSION**

|Command|Explanation|
|---|---|
|`tar`|Archive files|
|`gzip`|Compress file|
|`gunzip`|Decompress|
|`zip`|Create zip file|
|`unzip`|Extract zip|

##### **IMPORTANT EXAM POINTS**

- Linux is **open-source**
- Linux is **case-sensitive** ⭐
- Root user = **superuser**
- Shell = **Command interpreter**
- Common shells: **bash, sh**


> **Linux commands work in Linux/Unix environments and are case-sensitive.**
