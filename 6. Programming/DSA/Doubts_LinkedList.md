# Linked List 🖇️

Limitation of array:
- [1 7 5 2 9 4]
- fixed size
- Continuous block of memory
- insertion or deleting costly

Linked list
```
1 -> 7 -> 5 -> 2 -> 9 -> 4
```
## Structure
```cpp
class ListNode {
public:
    int val;
    ListNode* next;

    // Constructors
    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};
```
### Allocation
```cpp
// Stack Allocation : Object Created   
ListNode node1; // node1.val = 0
ListNode node2(5); // node2.val = 5
ListNode &node3(7, node2); //node3.val = 5 , node3.next->val = 7;
```
```cpp
// Heap Allocation : Pointers Created
ListNode* node1 = new ListNode(); //node1.val = 0;
ListNode* node2 = new ListNode(5); //node2.val = 5;
ListNode* node3 = new ListNode(7, node2); //node3.val = 7, node3.next -> val;

// cleanup
delete node1
delete node2
delete node3
```
Stack Allocation
- `ClassName objectName(parameter);`
- object are created on stack
- memory automatically deallocated when the scope is exited

Heap Allocation
- `ClassName * ObjectName = new ClassName(parameters);`
- Objects are created on Heap
Memory must be explicitly deallocated usinge `delete`

### Creating List 1 -> 2 -> 3
```cpp
ListNode *Head = new ListNode(1);
Head -> next = new ListNode(2);
Head -> next = new ListNode(3);
```
```cpp
// Stack Allocation
ListNode node3(3, nullptr);
ListNode node2(2, &node3); //Reference of object n3 should be passed
ListNode node1(1, &node2); 
// note:- node1 is a ListNode object on the stack, pointing to node2

```
```cpp
// Heap Allocation
ListNode* node3 = new ListNode(3, nullptr);
ListNode* node2 = new ListNode(2, node3);
ListNode* node1 = new ListNode(1, node2);    
// note:- node1 is a pointer to a ListNode object in the heap, pointing to node2
```
Pass by `ListNode* head` when you only need to access the pointer to traverse or modify the contents of nodes (next, val).
### Display
```cpp
void display(ListNode* Head) {
    while (Head != nullptr) {
        cout << Head->val << "->";
        Head = Head->next; 
    }
    cout << "NULL" << endl;
}
// Note:- without '&' -> copy of Head locally -> does not affect the original Head
```
### Insertion ( pass by reference nec)
Pass by `ListNode* &head` when you want to modify the original head pointer itself inside the function

**At Front :**`4` -> 1 -> 2 -> 3
```cpp
// head : point by reference
void insertAtHead(Listnode* &head, int val){
    ListNode* newNode = new ListNode(val);
    newNode -> next = head;
    head = newNode; // for this passing by reference necessary
}
```

**At Tail:** 1 -> 2 -> 3 -> `4`
```cpp
//call by reference
void insertAtTail(node * &head, int val){
    Listnode * newNode = new LinkedList(val);
    if(head == NULL){
        head = newNode; // for this we pass by reference
        return;
    }

    ListNode *tempNode = head;
    while(tempNode->next!=NULL){
        tempNode = tempNode -> next;
    }
    tempNode -> next = newNode 
}
```
```cpp
bool SearchNode(node * head, int key ){
    while(head! = NULL){
        if(head ->val == key){
            return true;
        }
        head = head -> next;
    }
    return false;
}
```

### Searching 
```cpp

```





















```cpp
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