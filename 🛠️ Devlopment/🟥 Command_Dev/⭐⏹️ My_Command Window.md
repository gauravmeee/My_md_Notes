# Command Prompt


## what is `sh`, the most time command-line??

- In a Markdown file, `sh` refers to the "Bourne Shell", a command-line interpreter and programming language for Unix-like operating systems.

- note:- The `sh` command typically refers to the Unix shell and is not directly applicable to the Windows Command Prompt or PowerShell environments.

### Command Prompt vs Powershell

**Command Prompt (cmd.exe)** -> Command Prompt is the traditional command-line interpreter in Windows, tracing its roots back to MS-DOS.2
- **Functionality:** It's suitable for basic tasks like navigating the file system, running simple utilities, and executing batch scripts.5

**PowerShell** -> PowerShell is a more modern and powerful command-line shell and scripting language built on the .NET framework.6
- **Functionality:** It's designed for system administration, automation, and advanced tasks.9

### Unix- like shell 

common Unix-like shells that are available on Windows **1. Bash (Bourne Again Shell)** such as Git Bash:** 

### Directory Seperator

**Windows:** 
- Uses the **backslash** (`\`) as the directory separator.
 - `C:\Users\YourName\Documents\myfile.txt`

**Unix-like systems (Linux, macOS, etc.):**
- Use the **forward slash** (`/`) as the directory separator.
- `/home/yourname/documents/myfile.txt`
### Make new file

`touch` (Unix-like Shells)
- It is a standard Unix utility.
- It update the access and modification timestamps of a file. (If the file doesn't exist, `touch` creates an empty file)

`nul` (Window Command Prompt)
- It is a special device in Windows.
- It's essentially a "black hole" for output. Anything redirected to `nul` is discarded.
- you can use `touch` in Git Bash or windows subsystems for Linux(WSL)

`type` (Windows Command Prompt)
- It is used to display the contents of a file.
- It outputs the file's content to the console.

`echo` (Unix-like Shells and Windows Command Prompt)
- It is used to display text or variables.
- It outputs the provided arguments to the console.

`>` (Redirection Operator)
- It is a redirection operator. It redirects the output of a command to a file.


**Create a empty file or clear a file.**

```sh

> index.html

touch index.html

nul > index.html

```

**Display an output**

```sh

type app.js

echo app.js

```


**Create or overwrite empty file and display file**

```sh

type nul > app.js

echo > app.js

echo

```

  

Create or overwrite text in a file

```sh

# create or clear a file

echo > app.js

  

# create or overwrite a file with a 'single blank line'

echo. > app.js

  

# create or overwrite a file with 'Hellow World' text

echo Hellow world > html.txt

```

```sh

#

nul > app.js

  

# display content in file

type app.js

  

# type

type nul > app.js

```

```cmd

echo "bits/stdc++.h>" > myprogram.cpp

REM use "" if text contain reserved kewyword like '>'

```


### `Cntrl`+ `C` 
is used to terminate a running Process in Unix-like Operating System + `cmd` & `shell`
### Comment

`REM`
```cmd
REM This is a comment
```
`::`
```cmd
:: This is a comment
```
## echo ?
The echo command in Unix-like operating systems, including Linux and macOS, as well as in the Windows Command Prompt and PowerShell, is used to display a line of text or a string.

### Syntax
```sh
echo [option(s)] [string(s)]
```
### Display a simple message
```sh
echo "Hello, World!"
```
note:- like powershell `""` is not used in `cmd`

### Write output to a file (create file if not exist)

```sh
echo Hello, world! > myfile.txt
```

###  Display the value of a variable
```sh
name="Gaurav"
echo "Hello, $name!"
```

###  Print multiple lines
```sh
echo -e "Line 1\nLine 2\nLine 3"
```
### Common Options
- `-e`: Enable interpretation of backslash escapes (like `\n` for newline).
- `-n`: Do not output the trailing newline.
- `-E`: Disable interpretation of backslash escapes (default behavior).

### Using incorrect directory separators 
(e.g. `require('.\myFile.js')`, when it should be `.//myFile.js`. Remember, 
- Windows systems use backslashes while Unix-like systems use forward slashes



