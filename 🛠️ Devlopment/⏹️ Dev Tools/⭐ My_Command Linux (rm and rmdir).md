> Edited in crl
### Remove Files and Directories (`rm`)

**`rm`** is used to ==remove both files and directories== (with the `-r` flag). It is a powerful command, and the `-rf` option can delete entire directories without any confirmation, so use it carefully.

**Syntax:**
```sh
rm [OPTION] <file/directory>
```

**Options:**
1. `-r`, `--recursive` : Remove directories and their contents
2. `-f`, `--force`  : Force remove without prompting (ignores non-existent files)
3. `-i`: Prompt before each removal
4. `-v`, `--verbose` : Show verbose output (which files are being removed)
5. `-d` : Remove empty directories
6. `--help` : Display help message for usage

```sh
# Remove a single file
rm file.txt         

# Remove a directory and all its contents (including subdirectories and files)
rm -r myfolder/    

# Forcefully remove without any confirmation prompts
rm -rf myfolder/   

# Prompt before each removal of a file
rm -i file.txt  

# Show verbose output while removing files
rm -rv folder/ 

# Remove multiple files at once
rm file1.txt file2.txt file3.txt 

# Remove only empty directories (fails if directory is not empty)
rm -d emptyfolder/  
```

**Notes:**
- `rm` is permanent and cannot recover deleted files unless using recovery tools.
- Use "`rm -rf`" with caution as it will delete everything inside the specified directory.
- Be mindful of using rm on system files and directories as it can cause irreparable damage.

### Remove Empty Directories(`rmdir`) 

**`rmdir`** is safer and specifically used for removing **empty** directories. It can also remove empty parent directories using the `-p` option.

**Syntax:**
```sh
rmdir [OPTION] <directory>
```

**Options:**
1. `-p` : Removes the specified directory and its empty parent directories (if they are empty)
2. `/s` : Removes directory and all of its subdirectories (Windows-only option)
3. `/q` : Quiet mode, removes without prompting for confirmation (Windows-only option)

```sh
# Remove an empty directory
rmdir myfolder/     # Removes myfolder if it is empty

# Remove empty directories, including parent directories, if they are empty
rmdir -p parent/child/  # Removes child directory, then parent if both are empty

# Remove directory and all its contents (Windows-only)
rmdir /s /q myfolder/   # Removes myfolder and all its subdirectories without any confirmation
```

**Notes:**
- `rmdir` only works on empty directories; it will fail if the directory contains files or other directories.
- For non-empty directories, you must use "rm -r" instead of `rmdir`.
- `rmdir` is considered safer as it doesn’t allow accidental deletion of non-empty directories.