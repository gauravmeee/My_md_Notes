---
description: From Love Babbar's Tutorial ▶️
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

# Data Structure: Heap

## [# Lecture 74: Heaps in C++ || Heap Sort || Insertion/Deletion in Heap || Priority Queue STL](https://youtu.be/NKJnHewiGdc)

**What is Heap?** Heap is a complete Binary Tree that comes with a Heap order Property ⭐

**What is CBT(Complete Binary Tree)?**

* Every level is completely filled except the lowest one , which is filled from the left

**What is Heap order Property**

* **Max Heap** - A Max Heap is a complete binary tree where the value of each parent node is greater than or equal to its children, with the largest element always at the root.
* **Min Heap** - A Min Heap is a complete binary tree where the value of each parent node is less than or equal to its children, with the smallest element always at the root.

**How BST is different ?** A BST is a binary tree where each node has a value greater than all nodes in its left subtree and less than all nodes in its right subtree, enabling efficient searching, insertion, and deletion.

#### Max Heap Implementation (With Array)

_**Heap:**_

```cpp
class heap{
	public:
		int arr[100];
		int size;
		heap(){ // constructionr
			arr[0]=-1;
			size =0;
			}
		# Heapify Function here .....
};
```

We used **1 based indexing** to simplify parent child node find formula _Note:_ If a Node is at `(i)th` index in, than

* left child will be at `(2*i)th` index
* right child will be at `(2*i+1)th` index
* Parent of the node will be at `(i/2)th` index

***

**Max Heap Insertion**

Let Consider Current Heap

```
         60
	 /      \
	50        40
   /  \
  30  20     

[ x  60  50  40  30  20]
  0  1    2   3   4   5
```

Rule: Add a node at the last, if its parents is small, than swap it with parent, and do this swap again and again, till max heap property is satisfied

Insert 55

```
# Insert 55 at last -> 6th index
         60
	 /      \
	50        40
   /  \        \
  30  20       (55)

[ x  60  50  40  30  20  (55)] 
  0  1    2   3   4   5   6

added Node-> 6th node -> (55)
Parent-> 6th/2->3rd node -> (40)
40>55? ❌ -> swap

         60
	 /      \
	50       (55)
   /  \        \
  30  20        40

[ x  60  50 (55)  30  20  40]
  0  1    2   3   4   5   6

added Node -> 3rd node -> (55)
Parent -> 3rd/2 -> 1st node -> (60)
60>55? ✅ 
```

Insert 70

```
# Insert 70 at last -> 7th index
         60
	 /      \
	50       55
   /  \       / \
  30  20     40  (70)

[ x  60  50 (55)  30  20  40 (70)]
  0  1    2   3   4   5   6   7

added Node-> 7th node -> (70)
Parent-> 7th/2->3rd node -> (55)
55>70? ❌ -> swap

         60
	 /      \
	50      (70)
   /  \       / \
  30  20     40  55

[ x  60  50 (70)  30  20  40 55]
  0  1    2   3   4   5   6   7

added Node-> 3rd node -> (70)
Parent-> 3rd/2->1st node -> (60)
60>70? ❌ -> swap

        (70)
	 /      \
	50       60
   /  \       / \
  30  20     40  55

[ x (70) 50   60  30  20  40 55]
  0  1    2   3   4   5   6   7
```

_**Max Heap Insertion Code:**_

```cpp
# Insertion Function
void insert(int val){
	// add value to last
	size = size + 1;
	int index = size;
	arr[index] = val;
	// if it is greater than parent, swap it with parent.
	while(index>1){
		int parent = i/2;
		if(arr[parent]<arr[index]){
			swap(arr[parent], arr[index])
			index = parent;  
		}
		else{
			return;
		}
	}
	
}
```

**TC: `O(logn)`**

`n` number of nodes. each node with `2` children. `2^k=n` `k=height=logn` than maximum swaps will be the height of tree , i.e. `logn`

***

**Max Heap Delete ( Deleting the Root Node)**

1. Swap `root` node with the `last` node;
2. Remove last node (that will contain the previous root node value)
3. Check if all nodes are satisfying heap property, if not swap accordingly

Let consider the heap

```
         55
       /    \
     54     53
    /  \
   50   52
```

Delete

```
Swap last node (52) with root node (55)

        52
       /   \
     54     53
    /  \
   50   55

Delete Last node

        52
       /   \
     54     53
    / 
   50

52>54? ❌ -> swap

        54
       /   \
     52     53
    / 
   50

52>50? ✅
```

_**Max Heap Deletion Code:**_

```cpp
# Delete Function
void deleteFromHeap(){

	// check if there is element to delete?
	if(size==0){
	cout<<"nothing to delete" <<endl;
	return;
	}

	// remove root elment swapping it with last element.
	arr[1] = arr[size];
	arr[size]=-1;
	
	// take root node to its correct position by comparing to left and right child
	index = 1;
	while(index<size]){
		int lefIndex = 2*index;
		int rightIndex = 2*index+1;

		// if left is within size range and bigger than swap it with current node
		if(leftIndex<size && arr[index]< arr[leftIndex]){
			swap(arr[index], arr[leftIndex]);
			index = leftIndex;
		}
		
		// if right  is within size range and bigger than swap it with current node
		else if(rightIndex<size && arr[index]< arr[rightIndex]){
			swap(arr[index], arr[rightIndex]);
			index = rightIndex;
		}

		else return;
	}
}
```

**TC: `O(logn)`**

`n` number of nodes, than maximum swaps will be the height of tree , i.e. `logn`

***

### Heapify Algorithm

_Note:_ in a CBT(complete binary tree) the leaf nodes are from : `(n/2+1)th` to \`nth node

```
     54(1)
     /     \
   53(2)  55 (3)
   /    \ 
52 (4)  50 (5)

```

In heapify we will Check and Correct if any node is not a heap from Last node to root node

node 5 : heap ✅, Single node satisfy heap rule

```
50(5) 
```

node 4 : heap ✅, Single node satisfy heap rule

```
52(4)
```

node 3 : heap ✅, Single node satisfy heap rule

```
55(3)
```

node 2 : heap ✅, 52<53 and 50<53

```
       53(2)
     /      \
    52(4)  50(5)  
```

node 1 :node 2 : Not heap ❌, 53<54 but !55<54

```
     54(1)
    /     \
   53(2)  55(3)
   /    \ 
52 (4)  50 (5)
```

So Heapify it -> Swap (Parent, Incorrect Node)

```
     55(1)
    /     \
   53(2)  54(3)
   /    \ 
52 (4)  50 (5)
```

Heapify Done ✅

* The non-leaf nodes are positioned from the root up to the parent of the last node. The parent of the last node is at index `n/2` (using integer division).
* Thus, the leaf nodes are positioned from index `n/2 + 1` to `n`.
* In above example Leaf node are from `5/2+1` to `5` => `3` to `5`

Leaf Node, or Individual Nodes are always heap , so we need not to Heapify nodes leaf nodes and will only heapify nod es from backward from `n/2` to `1`

_**Max Heapify Code :**_

```cpp
void heapify(int arr[], int n, int i){
	int largest =i;
	int left = 2*i;
	int right = 2*i+1;

	if(left <= n && arr[largest]<arr[left]){
		largest = left; // largest -> left (if left is greater than curr(largest))
	}
	if(right <= n && arr[largest]<arr[right]){
		largest = right; // largest -> right (if right is greater than curr(greatest) or greatest(previously assigned left))
	}
	if(largest! = i){ //now largest is child node that is greater than node
		swap(arr[largest], arr[i]); // swap current node & Bigger child
		heapify(arr, n, largest); // heapify child node, if rearranged
		}
}

int main(){
	heap p;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();

	h.deletefromHeap();
	h.print();
	int arr[6] = {-1, 54, 53, 55, 52, 50};
	int n = 5;
	for( int i = n/2; i>0; i--){ // heapify from last node to root node
		heapify(arr, n, i); // 
	}
}

```

**heapify() TC: `O(logn)`**

**Building the Heap TC: `O(n)`**

#### Time Complexity of `heapify` Function:

Heapify: The `heapify` function compares the current node with its left and right children, and swaps it with the largest child if necessary, then recursively calls itself on the affected child. The worst case occurs when the recursion needs to go all the way down to the leaf nodes. The height of a binary is the time complexity of `heapify` i.e. `O(log n)`.

Heap Construction: In the `main` function, there's a loop where `heapify` is called for each node starting from the last non-leaf node up to the root node. This is part of the heap construction process. The loop starts at `i = n/2` and goes down to `1`. For each call to `heapify`, the maximum number of comparisons and swaps that might be needed is proportional to the height of the tree, which decreases as you move from the bottom of the heap to the top. The overall complexity of building a heap using this method is `O(n)`.

***

**Now Try Mean Heap, but with 0-based Indexing and Given Vector**

In zero based Indexing :-

* left child -> `2*i + 1`
* right child -> `2*i + 2`
* Parent -> `(i-1)/2`
* Leaf Node from `n/2` to `n-1`

_**Min Heapify Code :**_

```cpp
void heapify(int vector<int> &arr, int n, int i){
	int smallest =i;
	int left = 2*i + 1; // zero based indexing
	int right = 2*i+1; // zero based indexing

	if(left<n && arr[smallest]>arr[left]){
		smallest = left; // smallest -> left (if left is smaller than curr(smallest))
	}
	if(right<n && arr[smallest]>arr[right]){
		smallest = right; // smallest -> right (if right is smaller than curr(smallest) or smallest(previously assigned left))
	}
	if(smallest! = i){ //now smallest is child node that is smaller than node
		swap(arr[smallest], arr[i]); // swap current node & Bigger child
		heapify(arr, n, smallest); // heapify child node, if rearranged
		}
}

vector<int> buildMinHeap(vector<int> arr){
	int n = arr.size();
	for(int i = n/2-1; i>=0; i--){ // zero based indexing
		heapify(arr, n, i);
	}
	return arr;
}
```

_Note :_ We will not heapify leaf Nodes ( from `n/2` to `nth` node), because a single Individual node i.e. leaf node is heap in itself

**heapify() TC: `O(logn)`**

**buildMinHeap() TC: `O(n)`**

***

### Heap Sort

* **Max-Heap**: Used for sorting in **ascending order**.
* **Min-Heap**: Used for sorting in **descending order**.

**Algorithm**

`while(size>1):`

1. Swap `root` and `last` element -> `swap(arr[i], arr[n])` & Remove Last Node -> `size--`
2. take root node to correct position. -> Heapify Root Node-> `heapify(1)`

Let Max Heap:

```
		        70
		      /   \
		    60     55
		  /   \  
		45    50

size = 5
[ X  70  60  55  45  50]
  0   1   2   3   4   5
```

1.1 Swap first(70) & last(50) and Remove Last Node (70)

```
		       50
		      /   \
		    60     55
		  /   \  
		45     X

size--, size = 4
[ X  50  60  55  45 | 70]
  0   1   2   3   4 | 5
```

1.2 Heapify Root Node -> Already a heap

```
		       60
		      /   \
		    50     55
		  / 
		45  

[ X  60  50  55  45 | 70]
  0   1   2   3   4 | 5
```

2.1 Swap first(60) and last(45) and Remove Last Node (60)

```
		       45
		      /   \
		    50     55
		  / 
		X 

size--, size = 3
[ X  45  50  55 | 60 70]
  0   1   2   3 |  4  5
```

2.2 Heapify Root Node -> Swap 45 and 55(greater then current and left)

```
		       55
		      /   \
		    50     45

[ X  55  50  45 | 60 70]
  0   1   2   3 |  4  5
```

3.1 Swap first(55) and last(45) node, and remove last element (50)

```
		       45
		      /   \
		    50     X

size--, size = 2
[ X  45  50 | 55  60 70]
  0   1   2 |  3   4  5
```

3.2 Heapify -> swap 45 and 50

```
		       50
		      /
		    45 

[ X  50  45 | 55  60 70]
  0   1   2 |  3   4  5
```

3.3 Swap first(50) and last(45) node, and remove last element(50)

```
		       45
		      /
		    X 

size--, size == 1
[ X  45 | 50  55  60 70]
  0   1 |  2   3   4  5
```

size>1 ?? No -> Stop Array Sorted ✅

```
[45, 50, 55, 60, 70]
```

_**Heap Sort :**_

```cpp
heapSort(int arr[], int n){
	int size = n;

	while(size > 1){
	// setep1 : swap
	swap(arr[size], arr[1]);
	size--;
	
	// step2
	heapify(arr, size, 1);
	}
}
```

_Note :_ Do same process with min-Heap to sort in descending order

**TC:\*\* `O(nlogn)`**

\*\*Time Complexity Analysis:\*\*1. **Building the Heap**: Building a Max-Heap from an unsorted array takes `O(n)` time. 2. **Sorting Process**: The sorting process involves repeatedly extracting the maximum element and heapifying the reduced heap. - **While Loop**: The loop runs `n - 1` times, where `n` is the initial size of the array. - **Heapify Operation**: Each call to `heapify` takes `O(log k)`, where `k` is the current size of the heap. Initially, `k = n`, then `k = n-1`, and so on, down to `1`.

```
**Total Cost of Heapify**: `O(log⁡n)+O(log⁡(n−1))+O(log⁡(n−2))+…+O(log⁡1) = O(n*log n)
```

***

### STL Heap - `Priority Queue`

* \`#include
* Default -> MaxHeap

```cpp
// max-heap
priority_queue<int> pq;

pq.push(4); // push -> 4 [4]
pq.push(2); // push -> 2 [4, 2]
pq.push(5); // push -> 5 [5, 4, 2]
pq.push(3); // push -> 3 [5, 4, 2, 3]
pq.top(); // biggest element -> 5
pq.pop(); // remove top element -> [4, 2, 3]
pq.size(); // size of element -> 3
pq.empty(); // is empty?? -> 0 -> false
```

```cpp
# min-heap
priority_queue<int, vector<int>, greater<int> > minheap;

minheap.push(4); // push -> 4 [4]
minheap.push(2); // push -> 2 [2, 4]
minheap.push(5); // push -> 5 [2, 4, 5]
minheap.push(3); // push -> 3 [2, 4, 3, 5]
minheap.top(); // smallest element -> 2
minheap.pop(); // remove top element -> [3, 4, 5]
minheap.size(); // size of element -> 3
minheap.empty(); // is empty?? -> 0 -> false
```

***

## [Lecture 75: Heaps in C++ || Interview Questions || Part - 1](https://youtu.be/_9F2VgZcvdw)

### Q1 Find `kth` Smallest Element from a heap.

Example

```
{7, 10, 4, 3, 20, 15} 
3rd Smallest = 7
4th Smallest = 15
```

#### Approach 1

* Step 1: Sort Array in Increasing Order using any sort method.
* Step 2: Return `ans = arr[k-1]`
* minimum TC: `nlogn` if used optimized sort algorithm

#### Approach 2

* Step 1: Create a Max-Heap First K element `0 to kth` element
* Step 2: For rest elements `kth to (n-1)th`, if `element < heap.top()`, then `heap.pop()` and `heap.push(element)`.
* Now the heap of size `k` will only contains the smallest k number of elements from the array. because this will pop out element in heap greater than `kth` smallest element , and push the all the smallest element up to `k`.
* Step 3: Heapify. the biggest element i.e. on top() or root of heap will be the kth smallest element.
* TC: `O((n)⋅logk)`

dry run

```
arr = {7, 10, 4, 20, 15} k =4
```

```
Heap of first 4 elements

            20
           /  \
          10   4
          /
         7 
```

```
Remainint elments = {15}

15<20 : pop 20 and push 15
```

```
            15
           /  \
          10   4
          /
         7 
```

```
Remaining elments? -> no

Heap.top() = 15 -> kth smallest element
ans = 15
```

\*\*C++ Code \*\*

```cpp
int kthSmallest(vector<int> &arr, int k) {
	int n= arr.size();
	priority_queue<int> pq;
	for(int i=0; i<k; i++){
		pq.push(arr[i]);
	}
	for(int i=k; i<n; i++){
		if(pq.top()>arr[j]){
			pq.pop();
			pq.push(arr[i]);
		}
	}
	
	return ans = pq.top();
}
```

**TC: `O(n*logk)`**

push + heapify first k elements: `O(k * log k)` worst case, swap all rest `n-k` element with heapify top one by one : `O((n-k) * log k)`

**SC : O(k)**

_Note :_ similarly you can find kth largest element using min heap

***

### Q2 Is Given Binary Tree Heap??

Heap - It is a Complete binary Tree (CBT) that satisfy heap property

Approach:

* Check if binary Tree is CBT
* Check if binary tree satisfying heap order (let Max heap)

We will create two function to , one for checking CBT property and other for heap property

1. **Main function**

```
solve(){
-> f( isCBT() && isMaxOrder) return true
-> else false;
}
```

2. **Check CBT??**

In `0` based indexing, if `node=i` then `left= 2i+1` and `right=2i+2`

Let there is a binary Tree:

```
                  (1)
                 /    \
               (2)     (3)
              /  \       \
             (4) (5)  6?  (7)
```

`Total no. of nodes(6) < Last Node(7th)` : not a CBT

Algorithm for CBT Check

```
isCBT( root, i, nodeCount){
-> if(root\==NULL) return True;
-> if( i > nodeCount) return false;
-> else {
     left = isCBT (root->left, 2i +1, nodeCount)
     right = isCBT(root->right, 2i+2, nodeCount)
     return (left && right)
  }
}
```

3. **Check Max order ??**

if you passed the CBT test, its mean that a node can be any out of these

```
                   ()
                 /    \
                ()     ()
              /  \     / 
             ()  ()  ()

1. Both child exist
2. Leaf Node exist
3. Only left exist (when left will be last elment -> right=NULL)
```

Algorithm for Max Order Check

```
isMaxOrder(){
-> if (leaf Node) return true
-> if (right == NULL){
		return (root->data > root->left->data)
	}
-> else{
       return (root->data > root->left->data) && 
       (root->data > root->right->data) &&
       isMaxOrder(root->left) && isMasOrder(root->right)
	}
}
```

**C++ Code**

```cpp
bool isHeap(struct Node* root){
	ind index = 0;
	int totalCount = countNode(root);
	if(isCBT(root, index, totalCount) && isMaxOrder(root)){
		return true;
	}
	else
		return false;
}
```

Count Nodes

```cpp
int countNodes(struct Node* root){
	if(root == NULL)
		return 0;

	int count = 1 + countNode(root->left) + countNodes(root->right);
	return count;
}
```

CBT

```cpp
bool isCBT(struct Node* root, int index, int cnt){
	if(root=NULL)
		return ture;
	if(index >= cnt)
		return false;
	else{
		bool left = isCBT(root->left, 2*index +1, cnt);
		bool right = isCBT(root->right, 2*index +1, cnt);
		return (left && right);
	}
}
```

Max Order

```cpp
bool isMaxOrder(struct Node* root){
	if(root->left == NULL && root->right ==NULL)
		return true;
	if(root->right == NULL ){
		return (root->data > root->left->data)
	}
	else{
		bool left = isMaxOrder(root->left);
		bool right = isMaxOrder(root->right);
		
		return if(left && right && 
		(root->data>root->left->data && root->data>root->right->data)) ;
	}
}
```

**TC : `O(3n)`**

each count, max order, and CBT traverse tree -> 3 times `O(n)`

**SC : `O(3logn)`**

each count, max order, and CBT stack space equal to height of tree -> 3 times `O(logn)`

### Q3. Merge two Binary Max-Heap

Steps: Max `Heap 1` -> `Vector a` Max `Heap 2` -> `Vector b` `Vector C` = `Vector a` + `Vector b` (push both's element into another) Heapify `Vector C`

**TC : `O(n+m)`**

Merge Vector a and b of size m and n -> `o(m+n)` Heapify Vector c of size m + n -> `O(m+n)`

**SC : `O(n_m)`**

### Q4. Minimum Costs of Ropes

_Problem Statement:_ There are given `N` ropes of different lengths, we need to connect these ropes into one rope. The costs to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum costs

_Approach:_ Minimum cost will be when, we start from combining smallest ropes.

* Store the `ropes[]` in heap;
* take out smallest `rope1` from the top of heap
* take out other smallest `rope2` from the top of heap
* Combine `rope1+rope2` and push into the heap.
* Repeat. do this till heap contain only single row

_**C++ Code:**_\*

```cpp
long long mincost(long long arr[], long long[]){
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for(int i=0; i<n; i++){
		pq.push(arr[i]);
	}

	long long cost = 0;
	while(pq.size()>1){
		long long a = pq.top();
		pq.pop();

		long long b = pq.top();
		pq.pop();

		long long sum = a+b;
		cost+=sum;
	}
	return cost;
}
```

### Q5. Convert BST to Minheap

_Problem Statement:_ Convert Complete Binary Search Tree into Minheap, with condition that all left child should be smaller than right child

```
Input: BST

              4
            /    \
           2      6
         /  \    /  \
        1    3   5   7

Output: MinHeap

              1
            /    \
           2      5
         /  \    /  \
        3    4   6   7
```

```
Given BST
BST : Left < Node < Right
BST Inorder : 1 2 3 4 5 6 7
```

```
Conclusion of MinHeap
MinHeap : Node < Left < Right
MinHeap Preorder : 1 2 3 4 5 6 7 8
```

_Note:_ Inorder of BST is sorted Preorder of MinHeap is sorted

So from the Inorder array left to right, We need to build the heap by, filling the elements in Preorder way, First Node, then Left, then Right.

Structure of Heap and BST is same, so we would use BST and modify its structure by assigning value in preorder form.

_Algorithm:_

```cpp
getInorder(root, vector){
	getInorder(root->left)
	Vector.Insert(root->data)
	getInorder(root->right)
}
```

```cpp
fillPreOrder(root, inorder, index){
	root->data = inorder[index++]
	fillPreOrder(root->left, inorder, index)
	fillPreOrder(root->right, inorder, index)
}
```

1

```
1 2 3 4 5 6 7
^ 
node

              (1)
            /    \
           2      6
         /  \    /  \
        1    3   5   7
```

2

```
1 2 3 4 5 6 7
  ^ 
node->left

              1
            /    \
          (2)      6
         /  \    /  \
        1    3   5   7
```

3

```
1 2 3 4 5 6 7
    ^ 
node->left->left

              1
            /    \
           2      6
         /  \    /  \
       (3)   3   5   7
```

```
node->left->left = null !
```

4

```
1 2 3 4 5 6 7
      ^ 
node->left->right

              1
            /    \
           2      6
         /  \    /  \
        3   (4)  5   7
```

```
node->left->right = null !
```

5

```
1 2 3 4 5 6 7
        ^ 
node->right

              1
            /    \
           2     (5)
         /  \    /  \
        3    4  5    7
```

6

```
1 2 3 4 5 6 7
          ^ 
node->right->left

              1
            /    \
           2      5
         /  \    /  \
        3    4 (6)    7
```

```
node->right->left = null !
```

7

```
1 2 3 4 5 6 7
            ^ 
node->right->right

              1
            /    \
           2      5
         /  \    /  \
        3    4  6   (7)
```

Inorder Traversed successfully -> Minheap done
