
### Shell programming basics (Detailed)

- **Shell**: Command-line interface between user and OS that interprets and executes commands.
    
- **Common shells:** `sh` (Bourne shell), `bash` (Bourne Again Shell, default in Linux), `zsh` (Z shell).
    
- **Script file extension:** `.sh`
    
- **Execution:**
    
    ```sh
    bash file.sh        # run using bash
    chmod +x file.sh    # make executable
    ./file.sh           # execute script directly
    ```
    
- **Shebang (`#!`)**: Specifies interpreter for the script, e.g., `#!/bin/bash`.
    

---

### Variables

- **User-defined variables:** No spaces around `=`
    
    ```sh
    x=10
    name="SEBI"
    echo $x
    ```
    
    `$` expands variable value.
    
- **Environment variables:**
    
    - `HOME`: Current user's home directory.
        
    - `PATH`: Colon-separated directories where shell searches commands.
        
- **Exporting variables:**
    
    ```sh
    export x
    ```
    
    Makes variable available to **child processes/subshells**.
    

---

### Input and Output

- **Read input:**
    
    ```sh
    read x
    ```
    
- **Prompted input:**
    
    ```sh
    read -p "Enter value: " x
    ```
    
- **Print output:**
    
    ```sh
    echo "Value is $x"
    ```
    

---

### Command substitution

- **Store command output:**
    
    ```sh
    d=$(date)      # modern syntax
    files=`ls`     # legacy syntax
    ```
    
- **Arithmetic operations:**
    
    ```sh
    sum=$((a+b))
    mul=`expr $a \* $b`
    ```
    

---

### Conditional statements

- **`if` syntax:**
    
    ```sh
    if [ $a -gt $b ]; then
        echo "a greater"
    fi
    ```
    
- **Comparison operators (integers):** `-eq, -ne, -gt, -lt, -ge, -le`
    
- **String operators:** `=, !=, -z (empty), -n (non-empty)`
    
- **`if-else` syntax:**
    
    ```sh
    if [ $a -eq 10 ]; then
        echo "Ten"
    else
        echo "Not ten"
    fi
    ```
    

---

### Case statement

```sh
case $x in
  1) echo "One" ;;
  2) echo "Two" ;;
  *) echo "Other" ;;
esac
```

- `case`: Starts multi-way selection.
    
- `in`: Begins pattern list.
    
- `1)`: Pattern match.
    
- `*)`: Default case.
    
- `;;`: Ends a block.
    
- `esac`: Ends case statement.
    

---

### Loops

- **For loop:**
    
    ```sh
    for i in 1 2 3; do
        echo $i
    done
    ```
    
- **While loop:**
    
    ```sh
    while [ $x -lt 5 ]; do
        x=$((x+1))
    done
    ```
    
- **Until loop:**
    
    ```sh
    until [ $x -gt 5 ]; do
        x=$((x+1))
    done
    ```
    

---

### Functions

```sh
fun() {
    echo "Hello"
}
fun
```

- Return status via `$?`.
    

---

### Command-line arguments

```sh
$0   # script name
$1 $2 ...  # arguments
$#   # number of arguments
$@   # all arguments
```

---

### File test operators

- `-f`: file exists
    
- `-d`: directory exists
    
- `-r`: readable, `-w`: writable, `-x`: executable
    

Example:

```sh
if [ -f file.txt ]; then echo "Exists"; fi
```

---

### Redirection

- `>` : overwrite output
    
- `>>`: append output
    
- `<` : input from file
    
- `2>`: redirect errors
    

```sh
ls > out.txt
```

---

### Pipes

- Send output of one command to another:
    

```sh
ps -ef | grep root
```

- `ps`: list processes, `-ef`: full format
    
- `grep`: search text/pattern, `root`: matches processes owned by root
    

---

### Important Linux commands (exam-focused)

- File operations: `ls cd pwd mkdir rmdir rm cp mv`
    
- View files: `cat less more head tail`
    
- Text processing: `grep awk sed sort uniq wc cut`
    
- Permissions: `chmod chown`
    
- Process management: `ps top kill`
    
- Disk & memory: `df du free`
    

---

### awk & sed

- **awk:** extract/format text columns
    
    ```sh
    awk '{print $1}' file.txt
    ```
    
- **sed:** find/replace/modify text
    
    ```sh
    sed 's/old/new/' file.txt
    ```
    

---

### Exit status

- `0` = success, non-zero = failure
    

```sh
echo $?
```

---

### Crontab

- **Schedule jobs:**
    

```sh
crontab -e
```

- `-e`: edit user's cron jobs
    
- **Format:**
    

```
min hour day month week command
```

---

### Extra Tips for SEBI Grade A (IT)

- Focus on **practical usage** of shell commands, loops, conditions, and file operations.
    
- Remember **command vs arithmetic substitution**: `$()` vs `$(( ))`.
    
- Know **pipes, redirection, cron jobs, awk & sed** basics.
    
- Expect questions on **environment variables, file tests, and exit status**.
    

---

If you want, I can create a **super-condensed one-page “last-minute revision sheet”** for shell scripting for SEBI IT Grade A. It will fit everything exam-relevant in **bare minimum lines**. Do you want me to do that?