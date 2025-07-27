

# Types of Trees


```mathematica
                      Tree
                   /         \
              Binary      Multi-way 
             /      \              \
         BST        (Balanced,     (B-, B+, Trie, Segment,
      /      \     Full,Complete,   Fenwick Tree, Suffix, 
   AVL  Red-Black   Perfect, Skewed)   Splay Tree, K-D Tree)
                    Degenerate)
```


1. **Tree**
    - **Binary**
        - **BST** (Binary Search Tree)
            - **AVL** (Self-balancing Binary Search Tree) ⭐
            - **Red-Black** (Self-balancing Binary Search Tree) ⭐
        - **Balanced** (Binary trees where the height difference between subtrees is minimized)
        - **Full** (Each node has 0 or 2 children)
        - **Complete** (All levels are fully filled except possibly the last level, filled left to right)
        - **Perfect** (A Full Binary Tree where all leaf nodes are at the same level)
        - **Skewed**
            - **Left-Skewed** (All nodes have left children only)
            - **Right-Skewed** (All nodes have right children only)
        - **Degenerate** (Resembling a linked list where each parent node has only one child)
    - **Multi-way**
        - **B-Tree** (Balanced multi-way search tree, used for indexing in databases) ⭐
        - **B+ Tree** (Variant of B-Tree with all data in leaf nodes, used for efficient range queries) ⭐
        - **Trie** (Prefix Tree, used for efficient storage and retrieval of strings) ⭐
        - **Segment Tree** (Used for storing intervals or segments, supporting range queries)
        - **Fenwick Tree** (Binary Indexed Tree, used for efficient range sum queries and updates)
        - **Suffix Tree** (Stores all suffixes of a string, used for fast substring searching and pattern matching)
        - **Splay Tree** (Self-adjusting Binary Search Tree that moves frequently accessed elements to the root)
        - **K-D Tree** (Space-partitioning tree used for multidimensional search problems like nearest neighbor search)

# More Trees (That do not fit in above Categories)

- **Heap**
	- **Max-Heap** (Binary tree where the parent node is larger than its children)
	- **Min-Heap** (Binary tree where the parent node is smaller than its children)
	- **Used for implementing `priority queues`**
- **Graph-Related**
	- **Spanning Tree** (A tree that connects all vertices of a graph with the minimum number of edges)
- **Decision**
	- **Decision Tree** (A tree used for decision analysis or machine learning)
- **Space Partitioning**
	- **Cartesian Tree** (A tree where in-order traversal gives a sequence while maintaining the heap property)
	- **K-D Tree** (Used in multidimensional search problems)


---

# Important Trees

1. **Binary Tree**:
   - A ==tree== where each node has ==at most two children==, typically referred to as the left and right child.

2. **Heap**:
   - A ==binary tree== used to ==implement priority queues.== The heap property requires that each ==node’s value be greater than or equal to the values of its children (for a max heap)== or less than or equal to the values of its children (for a min heap).

3. **Binary Search Tree (BST)**:
   - A ==binary tree ==where for each node, the ==left child’s value is less than the node’s value==, and the ==right child’s value is greater==. This property allows efficient searching, insertion, and deletion operations.

3. **Balanced Binary Search Trees**:
   - **AVL Tree**: A ==self-balancing binary search tree== where the ==heights of two child subtrees of any node differ by== no more than one.
   - **Red-Black Tree**: A ==self-balancing binary search tree== with additional properties to ensure that the ==tree remains approximately balanced== during insertions and deletions.

4. **B-Tree**:
   - A ==self-balancing tree== data structure that ==maintains sorted data== and ==allows searches, sequential access, insertions, and deletions== in logarithmic time. It is commonly used in ==databases and file systems.==

5. **B+ Tree**:
   - A ==variation of the B-tree== where all ==values are stored at the leaf level==, and internal nodes only store keys. It is used extensively in ==database indexing.==

**More:**

7. **Segment Tree**:
   - A ==binary tree== used for answering range queries efficiently. It is often used for problems that involve querying sums or minimums over an interval of an array.

8. **Trie (Prefix Tree)**:
   - A tree-like data structure ==used to store associative data structures==, such as dictionaries. It is ohow ften used for string storage and retrieval.

9. **Fenwick Tree (Binary Indexed Tree)**:
   - A data structure that provides efficient methods for querying and updating prefix sums in an array.

---
# Binary Tree in C++

> Revise Linked List Notes, to Better Understand this Tree Notes

### Binary Tree Node Definition

```cpp
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};
```

### Create Binary Tree

**i. Create Binary Tree Dot Notation ( for direct instances )**

```cpp
// Direct instance of TreeNode
TreeNode root(10);

root.left -> new Node(5)

root.right -> new Node(15)
```
- Accessing value using `root.left.val` 

**ii. Create Binary Tree using `Arrow Notation` ( for pointers)**

```cpp
// Pointer to a TreeNode
TreeNode* root = new TreeNode(10); 
// 10

root->left = new TreeNode(5);  
//      10
//     /
//    5

root->right = new TreeNode(15);
//      10
//     /  \
//    5   15

// cleanup
delete root;
```
- Accessing value using `root->left->val`

```cpp
TreeNode* root = new TreeNode(10);
root->left = new TreeNode(5);
root->right = new TreeNode(15);
```

---
# Operations in Binary Tree

### 1. Traversal


>DFS (Depth-First Search) Traversal
- **Traversal order:** Preorder, Inorder, Postorder
- **Time complexity:** `O(|E| + |V|)`
- **Space complexity:** `O(|V|)`
- **Use cases:** Finding connected components, topological sorting, and finding strongly connected components.

**i. In-order Traversal**
```cpp
void inOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
```

**ii. Pre-order Traversal**
```cpp
void preOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
```

**iii. Post-order Traversal**
```cpp
void postOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
```

>BFS (Breadth-First Search) Traversal
- **Traversal order:** Level by level, from left to right.
- **Time complexity:** `O(|E| + |V|)`
- **Space complexity:** `O(|V|)`
- Use cases: Finding shortest paths, minimum spanning trees, and network traversal.


**iv. Level-order Traversal (BFS)**
```cpp
void levelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}
```


### 2. Insertion
```cpp
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
```

### 3. Searching

```cpp
TreeNode* search(TreeNode* root, int value) {
    if (root == nullptr || root->val == value) {
        return root;
    }
    if (value < root->val) {
        return search(root->left, value);
    }
    return search(root->right, value);
}
```

### 4. Deletion

```cpp
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
```

### 5. Finding the Height of the Tree
```cpp
int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
```


---
# Construct Binary Tree from (Preorder + Inorder) traversals.


##### Given
- **Preorder** (Root → Left → Right): `F A E K C D H G B`    
- **Inorder** (Left → Root → Right): `E A C K F H D B G`
    
##### Key Idea:
1. **Preorder** gives the **root** of current subtree.
2. **Inorder** splits the tree into **left** and **right** subtrees around the root.
    
##### Step-by-Step Process:

**Step 1:**
- `Preorder[0] = F` → This is the **root**.
- In `Inorder`, elements **left** of `F` → `{E A C K}` (left subtree)  
    elements **right** of `F` → `{H D B G}` (right subtree)

**Step 2: Left Subtree of F**
- Next root in preorder → `A`
- In `{E A C K}`, `A` is root  
    Left of A → `{E}` → left subtree of A  
    Right of A → `{C K}` → right subtree of A
    
**Step 3: Left Subtree of A**
- Preorder next → `E`  
    In `{E}`, it's a leaf node
    
**Step 4: Right Subtree of A**
- Preorder next → `K`  
    In `{C K}`, `K` is root  
    Left of K → `{C}` → left child  
    Right of K → `[]` → NULL
    
**Step 5: Right Subtree of F**
- Next preorder → `D`  
    In `{H D B G}`, `D` is root  
    Left of D → `{H}`  
    Right of D → `{B G}`
    
**Step 6: Left Subtree of D**
- Preorder → `H` → leaf
    
**Step 7: Right Subtree of D**
- Preorder → `G`  
    In `{B G}`, `G` is root  
    Left → `{B}` → leaf  
    Right → `[]`
    

##### Final Binary Tree:

```
          F
        /   \
       A     D
      / \   / \
     E   K H   G
        /     /
       C     B
```

##### Time & Space

- Time: O(n)
- Space: O(n) (for recursion and `hashmap` for `inorder` indices)
    
##### More Order Combinations to Construct Tree

| Traversal Combinations                        | Can Construct Tree? | Notes                                                             |
| --------------------------------------------- | ------------------- | ----------------------------------------------------------------- |
| Inorder + Preorder                            | ✅ Yes               | Most commonly used. Preorder gives root, Inorder gives structure. |
| Inorder + Postorder                           | ✅ Yes               | Postorder gives root, Inorder gives structure.                    |
| Inorder + Level-order                         | ✅ Yes               | Possible but complex, needs extra mapping and indexing.           |
| Preorder + Postorder                          | ❌ Not always        | **Ambiguous** unless it's a **full binary tree**.                 |
| Preorder + Levelorder, Postorder + Levelorder | ❌ No                | Not enough information for unique construction.                   |



---
---

# Binary Search Tree (BST)

**Balanced->** **Insertion** : `O(logn)` **Find** : `O(logn)`✅
**Unbalanced->** **Insertion** : `O(n)` **Find** : `O(n)` ❌


### Implementing a Binary Search Tree

#### Node Class
```cpp
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
```

#### Insert Method
```cpp
void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
    } else if (value <= root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}
```

#### Contains Method
```cpp
bool contains(Node* root, int value) {
    if (root == nullptr) {
        return false;
    } else if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return contains(root->left, value);
    } else {
        return contains(root->right, value);
    }
}
```

#### Inorder Traversal Method
```cpp
void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << root->data << " ";
        printInOrder(root->right);
    }
}
```

### Example Usage
```cpp
int main() {
    Node* root = nullptr;
    
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 8);

    std::cout << "Tree contains 8: " << contains(root, 8) << std::endl; // Output: Tree contains 8: 1 (true)
    
    std::cout << "Inorder Traversal: ";
    printInOrder(root); // Output: 5 8 10 15
    
    return 0;
}
```

### Summary
Understanding the structure and operations of binary search trees is crucial for efficiently managing hierarchical data. The key operations—insert, contains, and various traversals—are fundamental for working with BSTs. Mastering these concepts and their implementation will significantly enhance your problem-solving skills in data structures and algorithms.

---

# [L39. Introduction to Binary Search Tree | BST](https://www.youtube.com/watch?v=p7-9UvDQZ3w&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=39&ab_channel=takeUforward)

# [L40. Search in a Binary Search Tree | BST | C++ | Java](https://www.youtube.com/watch?v=KcNt6v_56cc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=40&ab_channel=takeUforward)

# [L46. Check if a tree is a BST or BT | Validate a BST](https://www.youtube.com/watch?v=f-sj7I5oXEI&ab_channel=takeUforward)

