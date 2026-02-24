---
description: From Striver's Tutorial ▶️
icon: dot
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# Data Structure: Trie

## [L1. Implement TRIE | INSERT | SEARCH | STARTSWITH](https://youtu.be/dBGUmUQhjaM?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp)

Trie - Class/Struct , it has a `array of size 26` & `bool flag`

```
Trie Structure [char|flag]
```

```cpp
Trie{
    int a[26]; // a[0]->'a' , a[25]-> 'z'
    bool flag; // 1/0 -> true/false
}
```

if word completed at `char` `flag=1`

**Insert**

Inserting `'apple'`

```
1. [ |0]
2. [a|0] -> [ |0]
3. [a|0] -> [p|0] -> [ |0]
4. [a|0] -> [p|0] -> [p|0] -> [ |0]
5. [a|0] -> [p|0] -> [p|0] -> [l|0] -> [ |0]
6. [a|0] -> [p|0] -> [p|0] -> [l|0] -> [e|1] -> [ |0]
```

Similarly Adding, `apps, 'apxl', 'bac', 'bat'`

```
apple
1.          [a|0] -> [p|0] -> [p|0] -> [l|0] -> [e|0] -> `[ |1]` 
              ^                 ^       ^
apps          |                 |       |
2.            |                 |   -> [l,s|0] ->  [|1]    
              |                 |
apxl          |                 |
2.            |             -> [p,x|0] -> [l|0] -> [ |1]        
              |
bac           |
3.           [a,b|0] -> [a|0] -> [c|0] -> [ |1]
                                   ^
bat                                |
4.                                [c,t|0] -> [ |1]                
```

```
                           [a,b|0]
                           /       \
                       [p|0]       [a|0]
                        /             \
                    [p,x|0]           [c,t|0]
                     /     \            /    \
                  [l,s|0]   [l|0]     [|1]   [|1]
                   /    \      \       bac    bat
                [e|0]   [|1]   [|1]
                /       apps    apxl
	         [|1]
	         apple
```

**Search**

`'apple'` Exist??

```
// Starts with root [a,b|0] 

[a,b|0] : (a)pple : 'a' exists? -> Yes ✅
reference to variable -> [p|0]

[p|0] : a(p)ple : 'p' exists? -> yes ✅
reference to variable -> [p,x|0]

[p,x|0] : ap(p)le : 'p' exists? -> yes ✅
reference to variable -> [l,s|0]

[l,s|0] : app(l)e : 'l' exists? -> yes ✅
reference to variable -> [e|0]

[e|0] : appl(e) : 'e' exists? -> yes ✅
reference to variable -> [|1]

[|1] : apple ✅ : flag==1? -> yes ✅ -> apple exist ✅
```

`'appx'` exist?

```
// Starts with root [a,b|0] 

[a,b|0] : (a)ppx : 'a' exists? -> Yes ✅
reference to variable -> [p|0]

[p|0] : a(p)px : 'p' exists? -> yes ✅
reference to variable -> [p,x|0]

[p,x|0] : ap(p)x : 'p' exists? -> yes ✅
reference to variable -> [l,s|0]

[l,s|0] : app(x) : x 'x' exists? -> No ❌ -> appx not exist ❌
```

`'app'` exist?

```
// Starts with root [a,b|0] 

[a,b|0] : (a)pp : 'a' exists? -> Yes ✅
reference to variable -> [p|0]

[p|0] : a(p)p : 'p' exists? -> yes ✅
reference to variable -> [p,x|0]

[p,x|0] : ap(p) : 'p' exists? -> yes ✅
reference to variable -> [l,s|0]

[l,s|0] : app : flag==1? -> No ❌ -> app not exist ❌
```

_Note:_ Let in appx, to check if a char 'x' exist or not, we will see if x is not point to null,

* if `x` in `trie` is pointing to `null`-> x does not exist
* if `x` in `trie` is pointing to `reference variable` -> x exist

**Starts with**

`'app'` Prefix exist?

```
// Starts with root [a,b|0] 

[a,b|0] : (a)pp : 'a' exists? -> Yes ✅
reference to variable -> [p|0]

[p|0] : a(p)p : 'p' exists? -> yes ✅
reference to variable -> [p,x|0]

[p,x|0] : ap(p) : 'p' exists? -> yes ✅
reference to variable -> [l,s|0]

[l,s|0] : app : variabl==null? -> No ❌ -> app prefix exist ✅
```

`'apd'` prefix?

```
// Starts with root [a,b|0] 

[a,b|0] : (a)pd : 'a' exists? -> Yes ✅
reference to variable -> [p|0]

[p|0] : a(p)d : 'p' exists? -> yes ✅
reference to variable -> [p,x|0]

[p,x|0] : ap(d) :'d' exist? -> 'd' point to null -> not exist ❌ -> apd not exist as prefix
```

***

_**Implementation Code :**_

```cpp
#include <iostream>
using namespace std;

// Node structure for Trie
struct Node {
    // Array to store links to child nodes, each index represents a letter
    Node* links[26];
    
    // Flag indicating if the node marks the end of a word
    bool flag = false;

    // Check if the node contains a specific key (letter)
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific key (letter) into the Trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific key (letter) from the Trie
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Set the current node as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the current node marks the end of a word
    bool isEnd() {
        return flag;
    }
};

// Trie class
class Trie {
private:
    Node* root;

public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node();
    }

    // Inserts a word into the Trie Time Complexity O(len), where len is the length of the word
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // Create a new node for the letter if not present
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    // Returns if the word is in the trie
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found, the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node marks the end of a word
        return node->isEnd();
    }

    // Returns if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                // If a letter is not found, there is no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        // The prefix is found in the Trie
        return true;
    }
};
```

**Time Complexity** insert() TC:`O(n)` search() TC:`O(n)` startsWith() TC:`O(n)`

```cpp

int main() {
    Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    
    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    
    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;
    
    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;

    return 0;
}
             
```
