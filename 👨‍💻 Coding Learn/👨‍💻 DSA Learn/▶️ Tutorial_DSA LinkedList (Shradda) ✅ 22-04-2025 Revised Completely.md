
##### Array
```
[1|7|5|2|9|4]
```
Limitations of array
- fixed size
- Contiguous block of memory
- Insertion or deletion costly

## Linked List
- It is a multiple block of memory linked to each other
```
[1] -> [7] -> [5] -> [2] -> [9] -> [4] -> NULL
```
Property of Linked List
- Size can be modified
- Non-contiguous memory
- Insertion and Deletion at any point is easier

Block of Linked List :
```
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

#### Linked List Using Class
```cpp
#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;

		node(int val){
			data=val;
			next=NULL;
		}
};
```

#### Create Linked List using Pointers
```cpp
int main(){
    node *head = new node(1);  // head is a pointer (heap)
    head->next = new node(2);
    head->next->next = new node(3);
    return 0;
}
// 1 -> 2 -> 3
```

```cpp
node *head = new node(1); // heap object
head->next = new node(x); // used when `next` is a pointer
head->next->next //  To access next nodes:
```


- Nodes are allocated on **heap**
- `head` is a **pointer**
- Manual deletion required: `delete head; delete head->next; delete head->next->next;`
- Final list: `[1] → [2] → [3] → NULL`


#### Create Linked List using Object

```cpp
int main(){
    node head(1);              // head is an object (stack)
    head.next = new node(2);
    head.next->next = new node(3);
    return 0;
}
// 1 -> 2 -> 3
```

```cpp
node head(1); // stack object
head.next = new node(x); // used when `next` is a pointer
head.next->next //  To access next nodes:
```

- `head` is an **object** on **stack**
- `head.next` and following nodes are on **heap**
- `head` is auto-destroyed; heap nodes must be deleted manually
- Final list: `[1] → [2] → [3] → NULL`


#### Traversal

**Traversal Using Loop**
```cpp
void display(node* head){
	node* temp = head;
	while(temp!=nullptr){
		cout<<temp->val<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
// 1->2->3
```

**Traversal Using Recursion**
```cpp
void display(node* head){
	if(head==nullptr){
		cout<<"NULL"<<endl;
		return;
	}
	cout<<head->val<<"->";
	display(head->next);
}
// 1->2->3
```


> ☑️ 22-04-2025 Revised Upto here