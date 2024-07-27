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