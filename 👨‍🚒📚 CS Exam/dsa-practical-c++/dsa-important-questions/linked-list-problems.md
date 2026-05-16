---
title: Linked List Problems
---

## [Reverse a Linked List](https://leetcode.com/problems/reverse-linked-list/)

#### Brute Force: Reverse Links in Place Recursion

```cpp
ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp!=NULL){ // Store the value in Stack upto last node
            st.push(temp->val);
            temp=temp->next;
        }
        temp = head;
        while(!st.empty()){ // Pop out and Store the Value in Linked list in reverse
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
```

#### Optimal Approach-I Reverse Links in Place (Iterative)

```cpp
ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; 
        ListNode* temp = head;
        while(temp!=NULL){
            ListNode* front = temp->next; // set front
            temp ->next = prev; // point `current` node to `prev` node
            prev = temp; // `prev` node to `curr`
            temp = front; // move `current` node to `front`
        }
        return prev;
    }
 
```

Initial `prev=NULL`, `prev=temp=head`

```
NULL    [1|●]--->[2|●]--->[3|●]--->[4|●]--->NULL
prev     temp     
```

`front=temp->next`, `temp->next = prev` , `prev=temp`, `temp=front`

```
NULL<---[1|●]    [2|●]--->[3|●]--->[4|●]--->NULL
		prev     temp     front
```

`front=temp->next`, `temp->next = prev`, `prev=temp`, `temp=front`

```
NULL<---[1|●]<---[2|●]    [3|●]--->[4|●]--->NULL
		          prev     temp     front
```

`front=temp->next`, `temp->next = prev`, `prev=temp`, `temp=front`

```
NULL<---[1|●]<---[2|●]<---[3|●]<---[4|●]--->NULL
		                   prev     temp    front
```

`front=temp->next`, `temp->next = prev`, `prev=temp`, `temp=front`

```
NULL<---[1|●]<---[2|●]<---[3|●]<---[4|●]    NULL
		                            prev    temp    front
```

`temp==NULL` Stop
