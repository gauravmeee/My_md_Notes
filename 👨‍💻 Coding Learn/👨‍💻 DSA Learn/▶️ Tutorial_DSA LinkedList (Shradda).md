
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

Block of Linked List
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

#### Create Linked List \[1 2 3] using pointers
```cpp
int main(){
 node *head = new node(1);
 head->next = new node(2);
 head->next->next = new node(3);
 return 0;
}
```

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

┌────┬────┐
│       │        │
├────┼────┤
│       │        │
└────┴────┘