# Command Prompt

## what is `sh`, the most time command-line result By Chat gpt??

- In a Markdown file, `sh` refers to the "Bourne Shell", a command-line interpreter and programming language for Unix-like operating systems.
note:- The sh command typically refers to the Unix shell and is not directly applicable to the Windows Command Prompt or PowerShell environments.
## Make new file

create a empty file or clear a file.
```sh
> index.html
touch index.html
nul > index.html
```
Display an output
```sh
type app.js
echo app.js
```
Create or overwrite empty file and display file
```sh
type nul > app.js
echo > app.js
echo
```

Create or overwrite text in a file
```sh
```



```
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
## `Cntrl+ C` 
is used to terminate a running Process in Unix-like Operating System + `cmd` & `shell`
## Comment

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



