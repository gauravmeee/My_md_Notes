---
description: Made by Me 💚
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

# Amazon Interview Problems

#### 1. Distance between two nodes of Binary Tree

> **Topic:** Tree\
> **Sub-topics:** Binary Tree, LCA, DFS\
> **Category:** Trees + Recursion

**Idea**

* Distance between two nodes = distance(LCA → node1) + distance(LCA → node2)

**Steps**

1. Find Lowest Common Ancestor (LCA) of the two nodes
2. Find distance from LCA to each node
3. Add both distances

**Why this works**

* Path between two nodes always passes through their LCA

**C++ Solution**

```cpp
struct Node {
    int data;
    Node *left, *right;
};

Node* LCA(Node* root, int a, int b) {
    if (!root || root->data == a || root->data == b)
        return root;
    Node* l = LCA(root->left, a, b);
    Node* r = LCA(root->right, a, b);
    if (l && r) return root;
    return l ? l : r;
}

int findDist(Node* root, int key, int dist) {
    if (!root) return -1;
    if (root->data == key) return dist;
    int l = findDist(root->left, key, dist + 1);
    if (l != -1) return l;
    return findDist(root->right, key, dist + 1);
}

int distanceBetween(Node* root, int a, int b) {
    Node* lca = LCA(root, a, b);
    int d1 = findDist(lca, a, 0);
    int d2 = findDist(lca, b, 0);
    return d1 + d2;
}
```

* **Time Complexity**: `O(n)`
* **Space Complexity**: `O(h)` (recursion stack)

This is the optimal and interview-expected approach.

#### 2. Longest subsequence (123445273210334)

> **Topic:** Dynamic Programming\
> **Sub-topics:** LIS / LDS\
> **Category:** DP (Sequence DP)

**Observation**

* Digits sequence: `1 2 3 4 4 5 2 7 3 2 1 0 3 3 4`
  * LIS example: `1 2 3 4 5 7` → length **6**
  * LDS example: `7 3 2 1 0` → length **5**\
    Answer = **6**
* **DP Logic**
  * `inc[i]` = LIS ending at `i`
  * `dec[i]` = LDS ending at `i`\
    Take max of both.

**C++ Solution (O(n²))**

```cpp
int longestSubsequence(string s) {
    int n = s.size();
    vector<int> inc(n,1), dec(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(s[j] < s[i])
                inc[i] = max(inc[i], inc[j] + 1);
            if(s[j] > s[i])
                dec[i] = max(dec[i], dec[j] + 1);
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans, max(inc[i], dec[i]));

    return ans;
}
```

**Complexity**

* Time: `**O(n²)`\*\*
* Space: **`O(n)`**

Interview view: correct DP framing matters more than optimizing to O(n log n).

#### 3. Find number occurring once (others twice)

> **Topic:** Bit Manipulation\
> **Sub-topics:** XOR properties\
> **Category:** Bitwise Operations

**Key Idea**

* Use **XOR**
  * `x ^ x = 0`
  * `x ^ 0 = x`\
    All repeated numbers cancel out, unique remains.
* **Example** `2 2 3 3 4 4 5 6 6 7 7`\
  Result = `5`

**C++ Solution**

```cpp
int findUnique(vector<int>& a) {
    int x = 0;
    for(int v : a)
        x ^= v;
    return x;
}
```

**Why optimal**

* No extra space
* Single pass

**Complexity**

* Time: `O(n)`
* Space: `O(1)`

This is the **expected interview answer**.
