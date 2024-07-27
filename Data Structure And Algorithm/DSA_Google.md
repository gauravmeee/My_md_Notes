# [DSA BY Google](https://techdevguide.withgoogle.com/paths/data-structures-and-algorithms/)

- Maps/Dictionaries
- Linked Lists
- Trees
- Stacks & Queues
- Heaps
- Graphs
- Runtime Analysis
- Searching & Sorting
- Recursion & DP

## 1.  Maps / Dictionaries

### > Quick Intro to HashMap?

- **Problem with Array and Linked List**:
  - **Array**: Fixed size, problematic for adding new students.
  - **Linked List**: Dynamic size but slow lookup time.
  - **Solution Needed**: Efficient storage with dynamic size and quick access.

- **HashMap Introduction**:
  - **Data Structure**: Combines array's random access and linked list's dynamism.
  - **Structure**: Consists of key-value pairs.
  - **Example**: 
    - Key: Student ID.
    - Value: Student's name.

- **Hash Function**:
  - **Purpose**: Determines where to store data.
  - **Functionality**: Converts a key into a hash code to find the storage location.
  - **Key Uniqueness**: Identical keys point to the same value, so keys must be unique.

- **Methods**:
  - **put**: Store data in the HashMap.
  - **get**: Retrieve data from the HashMap.

- **Considerations**:
  - **Key Selection**: Using non-unique keys (like student names) can cause conflicts.



### > How HashMap works?

#### Arrays
- **Pros**:
  - **Random Access**: Allows accessing any element in a single step using its index, enabling efficient algorithms like binary search.
- **Cons**:
  - **Fixed Size**: Size must be specified at the time of declaration, making it hard to grow the array if more memory is not available contiguously.

#### Linked Lists
- **Pros**:
  - **Dynamic Size**: Can grow as needed since elements are not stored contiguously.
- **Cons**:
  - **No Random Access**: Requires traversing the entire list to access a specific element, leading to O(n) lookup time.

### > Introduction to Hash Tables

#### Benefits
- **Speed**: Provide speedy insertion, deletion, and lookup.
- **Dynamic Growth**: Can grow over time, unlike arrays.

#### Structure
- **Array and Hash Function**: A hash table is an array coupled with a hash function.
- **Key and Hash Value**:
  - The hash function takes a key and outputs a hash value (integer).
  - This hash value determines the index in the hash table where the key-value pair is stored.

#### Hash Function Requirements
- **Consistency**: Should always output the same hash value for the same key.
- **Use of Key Information**: Should use all the information provided by the key to maximize possible hash values and minimize collisions.
- **Even Distribution**: Should spread hash values evenly across the hash table to reduce linked list lengths in case of collisions.
- **Efficiency**: Should use simple, quick operations to minimize runtime.

### Collision Resolution Methods

#### Linear Probing
- **Mechanism**: Assigns the next available slot in the table when a collision occurs.
- **Drawbacks**:
  - **Clustering**: Increases the chances of further collisions in the same area.
  - **Worst-Case Time**: Insertion, deletion, and lookup times can devolve to O(n) in the worst case.

#### Separate Chaining
- **Mechanism**: Uses an array of pointers to linked lists. When a collision occurs, the key is inserted at the head of the appropriate linked list.
- **Drawbacks**:
  - **Worst-Case Lookup Time**: O(n/k), where k is the size of the hash table. In real-world scenarios, O(n/k) can be a significant improvement over O(n).

### Conclusion
Hash tables offer an efficient way to manage data with fast insertion, deletion, and lookup times. The effectiveness of a hash table depends largely on the hash function's ability to minimize collisions and distribute hash values evenly.


## 2. Linked List

### > Intro to Linked Lists

#### Definition
- A linked list is a simple data structure that stores a list of values, where each value is connected (or linked) to the next value.

#### Structure
- **Node**: The basic unit of a linked list.
  - **Data Field**: Contains the value to be stored.
  - **Next Field**: Contains the address of the next node in the list.
- **Head**: The first node in the list, which doesn't have any nodes pointing to it.

#### Types of Linked Lists
1. **Singly-Linked List**: 
   - Nodes have a single next field pointing to the next node.
   - Traversal is only forward.
2. **Doubly-Linked List**:
   - Nodes have two fields: next (pointing to the next node) and previous (pointing to the previous node).
   - Allows traversal in both directions (forward and backward).
3. **Circular Linked List**:
   - The next field of the last node points back to the head node.
   - Forms a loop, allowing continuous traversal through the list.

#### Advantages and Disadvantages
- **Advantages**:
  - **Dynamic Size**: Can easily grow or shrink by adding or removing nodes.
  - **Easy Insertion/Deletion**: Adding or deleting nodes involves updating pointers, which is straightforward.
- **Disadvantages**:
  - **Memory Overhead**: Requires additional memory for storing pointers (next and possibly previous fields) along with the data.
  - **No Random Access**: Requires traversal from the head to access a specific node, making lookups less efficient compared to arrays.

#### Operations
- **Insertion**: Add a new node by updating the next pointer of the last node to point to the new node.
- **Deletion**: Remove a node by updating the next pointer of the previous node to point to the node after the one being removed.

#### Uses
- Linked lists are used in various computer science applications and can be an efficient way to store and manage a list of values depending on the specific requirements of the program.


## 3.  Tree

### > Intro to Trees

#### Definition
- A tree is a data structure used to represent hierarchical data.

#### Structure
- **Root**: The topmost node in the tree.
- **Node**: Each element in the tree.
  - **Parent**: A node that has children.
  - **Child**: A node that is a descendant of another node.
  - **Leaf Node**: A node that does not have any children.

#### Characteristics
- **Hierarchy**: Trees represent data with a hierarchical relationship, such as files and folders on a computer.
- **Parent-Child Relationship**: Each node can have multiple children but only one parent.
- **Binary Trees**: A special type of tree where each node can have no more than two children.

#### Traversal Methods
- **Breadth-First Traversal**: Visits nodes level by level, starting from the root and moving downwards.
- **Depth-First Traversal**: Explores all descendants of a node before moving to another node.

#### Applications
- Trees are used in various applications in computer science, including:
  - Representing hierarchical data structures like file systems.
  - Modeling game states, such as the different possible moves in a game like tic-tac-toe.
  
### > Binary Search Tree (BST)

### Understanding Trees and Binary Search Trees by Gayle Laakmann McDowell

#### Definition and Structure
- **Tree**: A hierarchical data structure with a root node and child nodes.
  - **Root Node**: The topmost node.
  - **Child Nodes**: Nodes connected directly to another node (parent node).
  - **Binary Tree**: A type of tree where each node has no more than two children (left and right).

#### Binary Search Tree (BST)
- **Binary Search Tree (BST)**: A binary tree with a specific ordering property where:
  - Left subtree nodes are less than the root node.
  - Right subtree nodes are greater than the root node.
  
#### Advantages of BST
- **Fast Searching**: The ordering property allows for efficient search operations by repeatedly dividing the tree in half.
  - Example: Searching for 17 involves comparing it with the root and deciding to move left or right based on the value.
- **Insertion**: Inserting a new value follows a similar process to searching. You compare the value and navigate through the tree until finding an appropriate null spot to insert.

#### Balanced Trees
- **Imbalance Problem**: Sequential insertions (e.g., inserting 1, 2, 3, 4 in order) can create an imbalanced tree that resembles a list, which degrades performance.
- **Balanced Tree Algorithms**: Ensure the tree remains balanced to maintain efficiency. Though complex, many programming languages have built-in support for balanced trees.

#### Traversal Methods
- **Inorder Traversal**: Visit the left subtree, then the root, then the right subtree. This method prints the values in order.
- **Preorder Traversal**: Visit the root first, then the left subtree, and finally the right subtree.
- **Postorder Traversal**: Visit the left subtree first, then the right subtree, and finally the root.


### > Trie
### Understanding Tries

#### Definition and Structure
- **Trie**: A type of tree data structure used to store strings. Each node represents a single character of a string.
  - Often pronounced as "tree" or "try".
  - **Nodes**: Represent individual characters.
  - **Edges**: Connections between nodes.
  - **Identifiers**: Mark the end of a valid word in the trie.

#### Example Use Case: Spellchecking Program

1. **Adding Words**:
   - **EAR**: The trie starts with nodes for 'E', 'A', and 'R'. The node for 'R' is marked as a valid word.
     ```plaintext
     E -> A -> R*
     ```
   - **EARL**: The first three nodes already exist, so only 'L' is added, and it is marked as a valid word.
     ```plaintext
     E -> A -> R* -> L*
     ```
   - **EARS**: The first three nodes exist, so only 'S' is added, and it is marked as a valid word.
     ```plaintext
     E -> A -> R* -> L*
                  -> S*
     ```

2. **Adding More Words**:
   - **EAT**: New nodes 'A' and 'T' are added, with 'T' marked as a valid word.
     ```plaintext
     E -> A -> R* -> L*
                  -> S*
            -> T*
     ```
   - **EATEN**: The first three nodes of 'EAT' are reused, and 'E' and 'N' are added, with 'N' marked as a valid word.
     ```plaintext
     E -> A -> R* -> L*
                  -> S*
            -> T* -> E -> N*
     ```

#### Operations

1. **Checking for a Word**:
   - To check if "EAT" is a word, traverse from the root node 'E' to 'A', and then to 'T'. Since 'T' is marked as a valid word, "EAT" is a valid word.

2. **Invalid Words**:
   - To check if "EATE" is a word, traverse from 'E' to 'A', to 'T', and then to 'E'. Since 'E' is not marked as a valid word, "EATE" is not a valid word.

