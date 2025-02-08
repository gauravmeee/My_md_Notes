
### Euler Motors OA

**Bash Code Output :**

```bash
#!/bin/bash
echo $((5 + 3))
```
```
output
- 8
```

```sh
#!/bin/bash
for file in *.txt; do
    mv "$file" "${file%.txt}.bak"
done
```
```
output
- Renames all `.txt` files to `.bak`
```

- **Shebang (`#!/bin/bash`)** -> This tells the system that the script should be executed using the Bash shell.
- **Loop (`for file in *.txt; do`)** -> This loop iterates over all files in the current directory that end with `.txt`.
- **Renaming (`mv "$file" "${file%.txt}.bak"`)** -> The `mv` command is used to rename the file. `"${file%.txt}.bak"` is a parameter expansion in Bash that removes the `.txt` extension and appends `.bak` instead.
- **End of Loop (`done`)** -> The `done` keyword closes the loop.