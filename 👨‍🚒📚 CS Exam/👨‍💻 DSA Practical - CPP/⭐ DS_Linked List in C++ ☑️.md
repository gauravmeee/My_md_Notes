# ⭐ DS\_Linked List in C++ ☑️

***

## Introduction to Linked List

**Linked List** is a multiple block of memory linked to each other

**Array (& its Limitations )**

```
[1|7|5|2|9|4]
```

**Limitations of array:**

* fixed size
* Contiguous block of memory
* Insertion or deletion costly

**Linked List**

```
[1] -> [7] -> [5] -> [2] -> [9] -> [4] -> NULL
```

**Property of Linked List :**

* Size can be modified
* Non-contiguous memory
* Insertion and Deletion at any point is easier

**Block of Linked List :**

```cpp
Node [Data|Next] 
Data:Value of Current Block, 
Next: Address of Next Block
```

```
    ┌──-───↴   ┌───-──↴ 
[1|20k]    [2|30k]   [3|NULL]
 10k       20k 
 Head    
```

#### Linked List Operations

**1. Allocation (Node Creation)**

* i. **Static** (Fixed size array) - Rarely used
* ii. **Dynamic** (Heap allocation using `new`) - Common in C++

**2. Traversal**

* i. **Iterative** traversal (from head to NULL) - O(n)
* ii. **Recursive** traversal - O(n)

**3. Insertion**

* i. **Insert at Head** – O(1) ⭐
* ii. **Insert at Tail** – O(n) or O(1) with tail pointer ⭐
* iii. **Insert at Position (Index)** – O(n) ⭐
* iv. **Insert After a Given Node (Value or Address)** – O(n)
* v. **Insert Before a Given Node (Value)** – O(n)
* vi. **Insert in Sorted List** – O(n)
* vii. **Insert in Circular Linked List** – O(n) ❌
* viii. **Insert in Doubly Linked List** – O(1) if pointer given, O(n) if by value ❌

**4. Search**

* i. **Iterative Search** – O(n)
* ii. **Recursive Search** – O(n)

**5. Deletion**

* i. **Delete Head Node** – O(1) ⭐
* ii. **Delete Tail Node** – O(n)
* iii. **Delete at Position** – ⭐O(n)
* iv. **Delete by Value** – ⭐O(n)
* v. **Delete in Circular List** – O(n) ❌
* vi. **Delete in Doubly List** – O(1) if pointer known ❌

***

## Linked List in C++

#### Linked List Node Definition

**General Linked List**

```cpp
#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		node* next;

		Node(int val){
			data=val;
			next=NULL;
		}
};
```

* or in Advanced way

```cpp
class Node {
public:
    int data;
    Node* next;

    // Special Syntax Constructors
    Node() : data(0), next(nullptr) {}

    Node(int x) : data(x), next(nullptr) {}

    Node(int x, Node* nextNode) : data(x), next(nextNode) {}
};
```

#### Linked List Allocation ( using Pointer or Object )

**i. Create Linked List using Object (Stack Allocation)**

```cpp
// head is an object (stack)
Node head(1);  // head = 1
head.next = new Node(2); // head = 1 -> 2
head.next->next = new Node(3); // head = 1 -> 2 -> 3
return 0;
```

* or in Advanced way

```cpp
Node node3(3, nullptr); // 3
Node node2(2, &node3); // 2 -> 3
Node node1(1, &node2); // 1 -> 2 -> 3

```

* `head` is an **object** on **stack**
* `ClassName objectName(parameter);`
* `head.next` and following nodes are on **heap**
* object automatically destroyed when the scope is exited
* Final list: `[1] → [2] → [3] → NULL`

**ii. Create Linked List using Pointers (Heap Allocation)**

```cpp
// head is a pointer (heap)
Node *head = new Node(1);  // head = 1
head->next = new Node(2);  // head = 1->2
head->next->next = new Node(3); // head = 1->2->3

// cleanup
delete head ;
delete head -> next;
delete head -> next -> next;
```

* or in Advanced way

```cpp
Node* node3 = new Node(3, nullptr); // node3
Node* node2 = new Node(2, node3);  // node2 -> node3
Node* node1 = new Node(1, node2);  // node 1 -> node2 -> node3

// cleanup
delete node1
delete node2
delete node3
```

* Nodes are allocated on **heap**
* `ClassName * ObjectName = new ClassName(parameters);`
* `head` is a **pointer**
* Memory must be explicitly deallocated using `delete`
* Final list: `[1] → [2] → [3] → NULL`

***

## Operations in Linked List

#### 1. Traversal (using Loop or Recursion)

**i. Traversal Using Loop** - O(n)

```cpp
void display(Node* head){
	Node* temp = head; // temp = head preserves the original list
	while(temp!=nullptr){
		cout<<temp->data<<"->";
		temp = temp->next; // 
	}
	cout<<"NULL"<<endl;
}
// 1->2->3
```

**ii. Traversal Using Recursion** - O(n)

```cpp
void display(Node* head){
	if(head==nullptr){
		cout<<"NULL"<<endl;
		return;
	}
	cout<<head->data<<"->";
	display(head->next);
}
// 1->2->3
```

#### 2. Insertion

**Note:**

* pass by reference is necessary
* Pass by `ListNode* &head` when you want to modify the original head pointer itself inside the function

**i. Insert at Head** -O(1) ⭐

```cpp
// head : point by reference
void insertAtHead(Node* &head, int val){
    Node* newNode = new tNode(val);
    newNode -> next = head;
    head = newNode; // for this passing by reference necessary
}
```

**ii. Insert at Tail** - O(n) ⭐

```cpp
//call by reference
void insertAtTail(Node * &head, int val){
    Node * newNode = new LinkedList(val);
    if(head == NULL){
        head = newNode; // for this we pass by reference
        return;
    }

    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp -> next;
    }
    temp -> next = newNode 
}
```

**iii. Insert at Position (0-based index)** – O(n) ⭐

```cpp
void insertAtPosition(Node* &head, int val, int pos){
    if(pos == 0){
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for(int i = 0; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL) return; // position out of bounds
    newNode->next = temp->next;
    temp->next = newNode;
}
```

**iv. Insert After a Given Node (Value)** – O(n)

```cpp
void insertAfterValue(Node* &head, int target, int val){
    Node* temp = head;
    while(temp != NULL && temp->data != target){
        temp = temp->next;
    }
    if(temp == NULL) return; // target not found
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
```

**v. Insert Before a Given Node (Value)** – O(n)

```cpp
void insertBeforeValue(Node* &head, int target, int val){
    if(head == NULL) return;
    if(head->data == target){
        insertAtHead(head, val);
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL && curr->data != target){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL) return; // target not found
    Node* newNode = new Node(val);
    newNode->next = curr;
    prev->next = newNode;
}
```

**vi. Insert in Sorted List** – O(n)

```cpp
void insertInSorted(Node* &head, int val){
    if(head == NULL || val < head->data){
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL && temp->next->data < val){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
```

#### 3. Search

**i. Iterative Search** - O(n)

```cpp
bool SearchNode(Node * head, int key ){
    while(head! = NULL){
        if(head ->val == key){
            return true;
        }
        head = head -> next;
    }
    return false;
}
```

**ii. Recursive Search** - O(n)

```cpp
bool SearchNode(Node* head, int key){
    if(head == NULL) return false;
    if(head->val == key) return true;
    return SearchNode(head->next, key);
}
```

#### 4. Delete

**i. Delete Head Node** - O(1) ⭐

```cpp
void deleteAtHead(ListNode* &head) {
    if (head == NULL) return;
    ListNode* temp = head;
    head = head->next;
    delete temp;
}
```

**ii. Delete Tail Node** - O(n)

```cpp
void deleteAtTail(Node* &head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}
```

**iii. Delete at Position (0-based index)** – O(n) ⭐

```cpp
void deleteAtPosition(Node* &head, int pos) {
    if (head == NULL) return;

    if (pos == 0) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
```

**iii. Delete by Value** - O(n) ⭐

```cpp
void deleteByValue(ListNode* &head, int val) {
    if (head == NULL) return;

    if (head->val == val) {
        deleteAtHead(head);
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL && temp->next->val != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) return; // not found

    ListNode* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
```

> ☑️ 22-04-2025 Revised Upto here

***

## Remove Nth Node From End

````cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
       vector<int> v;

       while(head!=nullptr){
        v.push_back(head->val);
        head=head->next;
       }

       ListNode* ans =nullptr;
       ListNode*temp =nullptr;

       for(int i=0;i<v.size(); i++){

            if(i==v.size()-n){ //nth node of linkedlist == ith element of vector
                continue;
            }

            else if(ans==nullptr){
                ans = new ListNode(v[i]);
                temp = ans;
            }
            else{
            temp->next = new ListNode(v[i]);
            temp=temp->next;
            }

       }
       return ans;
    }
    ```
    
````
