
### Shell programming basics

- **Shell** : command-line interpreter between user and OS  
- **Common shells:** `sh`, `bash` (default in Linux), `zsh` 
- **Script file extension:** `.sh`  
- **Run:** `bash file.sh` or `chmod +x file.sh && ./file.sh`  
- **`Shebang`**: `#!/bin/bash`

### Variables

User-defined variables: no space around `=`
```sh
x=10
name="SEBI"
echo $x
```

> `$` is used to **access (expand) the value of a variable** in shell, otherwise the variable name is treated as plain text.

Environment variables: 
```
PATH
HOME  
```
>`HOME` = environment variable that stores the **absolute path of the current user's home directory**  
> `PATH` = environment variable that stores a **colon-separated list of directories where the shell searches for executable commands`

**Export variable:**
```sh
export x
```

>`export` makes a variable **available to child processes (subshells)** so it can be accessed outside the current shell session.
### Input and output

**Read input:**
```sh
read x
```

> `read` takes input from user and stores it in a variable,


**Prompted input:**
```sh
read -p "Enter value: " x
```

> `-p` is an option of `read` used to **display a prompt message before taking input from the user**

**Output:**
```sh
echo "Value is $x"
```

>  `echo` prints the variable value
### Command substitution

**Store command output:**
```sh
d=$(date)
files=`ls`
```

> `$()` = **command substitution** (stores output of a command)  

### Arithmetic operations

**Use `expr` or `$(( ))`**
```sh
sum=$((a+b))
mul=`expr $a \* $b`
```

> `$(())` = **arithmetic expansion** (evaluates integer expressions)


### Conditional statements

##### **`if`** :
```sh
if [ $a -gt $b ]; then
  echo "a greater"
fi
```


> **Comparison operators:**   `-eq` equal, `-ne` not equal, `-gt` greater than, `-lt` less than, `-ge` greater or equal, `-le` less or equal (used for integer comparison in test `[ ]`)

> **String operators:** `=` string equal, `!=` string not equal, `-z` string length is zero (empty), `-n` string length is non-zero

##### **`if-else`**
```sh
if [ $a -eq 10 ]; then
  echo "Ten"
else
  echo "Not ten"
fi
```

> `if` starts condition check, `then` executes block when condition is true, `else` executes when false, `fi` ends the if statement

### Case statement

```sh
case $x in
  1) echo "One" ;;
  2) echo "Two" ;;
  *) echo "Other" ;;
esac
```

> `case` starts multi-way selection, `in` begins pattern list, `1)` is a matching pattern, `*)` is default case, `;;` ends a case block, `esac` ends the case statement


### Loops ⭐

##### **`for`**
```sh
for i in 1 2 3
do
  echo $i
done
```

> `do` starts the loop body, `done` ends the loop body in `for`, `while`, and `until` loops


##### **`while`**
```sh
while [ $x -lt 5 ]
do
  x=$((x+1))
done
```

##### **`until`**
```sh
until [ $x -gt 5 ]
do
  x=$((x+1))
done
```

### Functions

```sh
fun() {
  echo "Hello"
}
fun
```

Return status via `$?`

### Command line arguments

```sh
$0 script name
$1 $2 ... arguments
$# number of arguments
$@ all arguments
```

### File test operators

Example:
```sh
if [ -f file.txt ]; then echo "Exists"; fi
```

> `-f` file exists  , `-d` directory exists  , `-r -w -x` permissions  


### Redirection

```sh
ls > out.txt
```

> `>` overwrite  , `>>` append  , `<` input  , `2>` error
### Pipes ⭐

**Output of one command to another:**
```sh
ps -ef | grep root
```

> `ps` = shows running processes, `-ef` = full-format listing of all processes, 
> `grep` = searches text/pattern, `root` = pattern to match processes owned by root user
### Important Linux commands (exam-focused)

- `ls cd pwd mkdir rmdir rm cp mv`  
- `cat less more head tail`  
- `grep awk sed sort uniq wc cut`  
- `chmod chown ps top kill df du free`

### `awk` and `sed` basics

##### **`awk`:**
```sh
awk '{print $1}' file.txt
```

> `awk` = text processing tool, used to **extract/format columns**  
##### `sed` :
```sh
sed 's/old/new/' file.txt
```

> `sed` = stream editor, used to **find, replace, or modify text**
### Exit status

`0` success, non-zero failure
```sh
echo $?
```

### Crontab (basics)

**Schedule jobs:**
```sh
crontab -e
```

> `crontab` = schedules jobs to run automatically, `-e` = **edit the current user's cron jobs**

**Format:**
```
min hour day month week command
```
