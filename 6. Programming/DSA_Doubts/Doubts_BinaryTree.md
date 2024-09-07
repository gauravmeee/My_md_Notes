# Binary Tree 🌳



## Binary Tree Node Definition
```cpp
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};
```

## Acessing


Dot notation for -> direct instances 
`root.left.val` 

```cpp
    // Direct instance of TreeNode
    TreeNode root(10);

    // Accessing members using dot notation
    cout << "Root value: " << root.val << endl; 
```
Arrow notation for ->  pointers 
`root->left->val`
```cpp
    // Pointer to a TreeNode
    TreeNode* root = new TreeNode(10);

    // Accessing members using arrow notation
    cout << "Root value: " << root->val << endl;  // Output: 10

    // Clean up the allocated memory
    delete root;
```


## Important Functions
### Creating Nodes Pointer
```cpp
TreeNode* root = new TreeNode(10);
root->left = new TreeNode(5);
root->right = new TreeNode(15);
```

### Accessing Values
To access the values and pointers:
- Use `root->val` to access the value of the root node.
- Use `root->left` to access the left child node.
- Use `root->right` to access the right child node.


### Accessing and Modifying Node Values
To access and modify the node values:
- Directly use the `->` operator with the node pointer.

```cpp
// Modify the root value
root->val = 20;

// Modify the left child value
root->left->val = 8;

// Access and print the modified values
cout << "Modified Root value: " << root->val << endl;         // Output: 20
cout << "Modified Left child value: " << root->left->val << endl;  // Output: 8
```


## Functions.

### Insertion
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

### In-order Traversal
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

### Pre-order Traversal
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

### Post-order Traversal
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

### Level-order Traversal (BFS)
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

### Searching
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

### Deletion
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

### Finding the Height of the Tree
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

## Preorder and Inorder to BT.

note:- A binary tree cannot be uniquely constructed using only the preorder or inorder traversal. To uniquely determine a binary tree, you need two types of traversals. Typically, you use a combination of preorder and inorder traversals or a combination of inorder and postorder traversals.


### Preorder : F A E K C D H G B : Node Left Right
### Inorder : E A C K F H D B G : Left Node Right

Start:
1. In PreOrder: left most -> `F` is node.
2. In InOrder: 
- `left` of 'F' (that included in prorder left tree) -> 'E A C K'  -> left subtree
- `right` of 'F' (that included in prorder right tree) -> 'H D B G' -> right subtree

3. PreOrder: left most in the left Subtree -> `A` is node of left subtree
4. In InOrder: 
- `left` of 'A' -> `E` -> next left subtree
- `right` of 'A' -> 'C K' -> next right subtree

Continue... and repeat the steps. You will the the final BT :) 

# Doubts

## In contests, the Order given is : 

Input: root = [ 2 , 1 , 3 , null , null , null , 4 ]

```
2
```

```
  2
 / \
1   3
```
```
      2
    /  \
   1    3
 /   \
null null
```
```
        2
    /       \
   1         3
 /   \      /   \
null null  null  4
```

Output: [2,1,3,null,null,null,4]

## nullptr
```
TreeNode * root;
if(root) -> false : if root = nullptr
if(root) -> true :  if root is not nullptr
```
