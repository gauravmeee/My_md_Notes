Breadth-First Search (BFS) and Depth-First Search (DFS) are fundamental graph traversal algorithms used to explore nodes and edges in trees and graphs. Below are the C++ implementations for both BFS and DFS on trees and graphs.

### 1. **Breadth-First Search (BFS)**
BFS explores all the nodes at the present depth before moving on to nodes at the next depth level. It uses a queue to keep track of nodes to be explored.

#### **BFS in a Graph:**
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
```

```cpp
void BFS(int start, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

```
int main() {
    int vertices = 6;
    vector<vector<int>> adjList(vertices);
    
    // Example graph edges
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    vector<bool> visited(vertices, false);

    cout << "BFS Traversal: ";
    BFS(0, adjList, visited);

    return 0;
}
```

#### **BFS in a Tree:**
```
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

```cpp
void BFS(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

```
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "BFS Traversal: ";
    BFS(root);

    return 0;
}
```

### 2. **Depth-First Search (DFS)**
DFS explores as far as possible along a branch before backtracking. It can be implemented using either recursion or a stack.

#### **DFS in a Graph:**
```
#include <iostream>
#include <vector>
using namespace std;
```

```cpp
void DFS(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);
        }
    }
}
```

```
int main() {
    int vertices = 6;
    vector<vector<int>> adjList(vertices);
    
    // Example graph edges
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    DFS(0, adjList, visited);

    return 0;
}
```

#### **DFS in a Tree:**
```
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

```cpp
void DFS(TreeNode* root) {
    if (!root) return;

    cout << root->val << " ";
    DFS(root->left);
    DFS(root->right);
}
```

```
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "DFS Traversal: ";
    DFS(root);

    return 0;
}
```

### Summary:
- **BFS** is implemented using a queue and explores the nodes level by level.
- **DFS** is implemented using recursion (or a stack) and explores as deep as possible along a branch before backtracking.
- Both algorithms work similarly for trees and graphs, with minor differences based on the data structure used.

### Time Complexity of BFS and DFS

The time complexity of BFS and DFS can be expressed in two forms:
1. **In terms of the number of v==ertices (`V`) and edges (`E`)**==: This is commonly used for graphs.
2. **In terms of the number of ==nodes (`n`)**: ==This is commonly used for trees.

#### 1. BFS & DFS
- **Graph (in terms of `V` and `E`)**:  Each vertex is visited once (`O(V)`), Each edge is explored once (`O(E)`).
- **Tree (in terms of `n`)**: Each node is visited once.

| Algorithm | Graph (`V` + `E`) | Tree (`n`) |
|-----------|-------------------|------------|
| BFS       | `O(V + E)`        | `O(n)`     |
| DFS       | `O(V + E)`        | `O(n)`     |
