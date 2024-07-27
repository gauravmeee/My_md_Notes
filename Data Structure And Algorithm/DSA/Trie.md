# Trie

# [L1. Implement TRIE | INSERT | SEARCH | STARTSWITH](https://youtu.be/dBGUmUQhjaM?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp)

Trie - Class/Struct , it has a `array of size 26` & `bool flag`

Trie Structure [char|flag]
Trie{
    int a[26];
    bool fLag;
}
note: flag:1-> true, flag:0 -> false

if word completed at `char` `flag=1`

Indexing
- 'a' -> index [0]
- 'z' -> index [25]

Inserting 'apple'
1. [ |0]
2. [a|0] -> [ |0]
3. [a|0] -> [p|0] -> [ |0]
4. [a|0] -> [p|0] -> [p|0] -> [ |0]
5. [a|0] -> [p|0] -> [p|0] -> [l|0] -> [ |0]
6. [a|0] -> [p|0] -> [p|0] -> [l|0] -> [e|1] -> [ |0]

Similarly Adding, apps, apxl, bac, bat
```cpp
apple
1. [a|0] -> [p|0] -> [p|0] -> [l|0] -> [e|0] -> `[ |1]` 

\\ apps (insert 's' in [l|0])\
2.                         -> [l,s|0] -> `[|1]`

apxl\
2.                -> [x|0] -> [l|0] -> [ |1]`

bac\
3.  
```         

search , not found https://youtu.be/dBGUmUQhjaM?t=1106

