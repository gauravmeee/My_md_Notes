
Stack - LIFO (Last in First Out) : 
Queue - FIFO (First in First Out)

**Stack Operations in C++**
```cpp
#include <stack>
stack<int> st;

st.push(1);      // insert element
st.top();        // get top element → 2
st.pop();        // remove top element
st.empty();      // check if empty
```

**Queue Operations in C++**
```cpp
#include <queue>
queue<int> q;

q.push(1);       // insert element
q.front();       // get front element → 1
q.pop();         // remove front element
q.empty();       // check if empty
```

---
# Implementation of Stack using Arrays

Example:
```
arr[5] = [  |  |  |  |  ]
```

```
top = -1
|___| 
	  <- top

push(6): arr[++top] = arr[0] = 6
|_6_| <- top

push(3): arr[++top] = arr[1] = 3
| 3 | <- top
|_6_|

push(7): arr[++top] = arr[2] = 7
| 7 | <- top
| 3 |
|_6_|
```

```
pop(): top--
| 3 | <- top
|_6_|

pop(): top--
|_6_| <- top

pop(): top--
|___| 
	  <- top
```

`top` :Index from which element will be popped
`top+1` : Index where next element will be pushed
`top+1` number of element stored in Stack

*Pseudocode:*
```cpp
arr[5] // array to be used as stack
top = -1 // index of the last elment

// push
push(x){
	arr[++top]=x
}

// pop
pop(){
	top--
}

// top
top(){
	return arr[top]
}

// size
size(){
	return top+1
}

// is empty
isempty(){
	return (top==-1)
}
```

more functions `Print stack`, 

---
# Implementation of Queue using Arrays

Here we are using circular array
- Circular array can easily be done using `rear%Array.size`. i.e **Modulo-n Concept**
- Let array Size `n=3`

```
rear < n
0 -> 0
1 -> 1
2 -> 2
3 -> 3%3 -> 0
4 -> 4%3 -> 1
5 -> 5%3 -> 2
6 -> 6%3 -> 0
....
```

Example:
```
arr[3] = [  |  |  |  |  ]
n = 3
```

- `f `: front
- `r` : rear
- `c` : count

```  
[   |   |   ] c=0
  f
  r

push(3): arr[r%3]=arr[0]=3, r++, c++
[ 3 |   |   ] c=1
  f   r

push(1): arr[r%3]=arr[1]=1, r++, c++ 
[ 3 | 1 |   ] c=2
  f       r

push(2): arr[r%3]=arr[1]=2, r++, c++
[ 3 | 1 | 2 ] c=n=3 (full)
  f           r=3
```

```
pop(): arr[f%3]=arr[0]=-1, f++, c--
[ -1 | 1 | 2 ] c=2
      f        r=3

pop(): arr[f%3]=arr[0]=-1, f++, c--
[ -1 | -1 | 2 ] c=1
            f   r=3
```

```
push(5): arr[r%3]=arr[0]=5, r++, c++
[ 5 | -1 | 2 ] c=2
	       f   r=4
```


`front`: Index from which element will be popped (In stack `top`)
`rear` : Index where next element will be pushed (In stack `top+1`)
`count` : number of element stored in queue (In stack `top+1`)

*Pseudocode:*
```cpp
arr[5] // array to be used as 
n = 5
front = 0 // Index of the logical first element 
rear = 0 // Index of the logical last elment + 1 
cnt = 0 // no. of elements present

Print(){
	for(i:front -> rear-1) print(a[rear%n])
}

# push
push(x){
	if(cnt==n) return -1
		a[rear%n] = x // rear%n : logical last index where element to be added
		rear++
		cnt++
}

# pop
pop(){
	if(cnt==0) return
	//optional (it only assign -1 at the removed index)
	a[front%n] = -1 // front%n : logical first index from where elment removed
	front++ // cirular array, shring from front element sides.
	cnt--
}

isEmpty(){
	return (cnt==0)
}

# front or top element
Front(){
	if(cnt==0) return -1
	return arr[front%n] // front%n : logical first index
}
```

```cpp
int arr[5];
int n =5;
int f=0;
int r=0;
int cnt=0;

void Push(int x){
	if(cnt<=n){
		arr[r]=x;
		r%=n;
	}
	else cout<<"Queue overflow";
}

void Pop(){
	if(cnt>0){
		arr[f]=-1;
		f%=n;
		
	}
	elese cout<<"Queue Underflow";
}

int front(){
	return arr[f];
}
```

> ☑️ 22-04-2025 Revised Upto here

---
# Implement Stack Using Queue

### Approach 1:  2 queue -> stack

Steps:
- push(x)
	1.  Add x -> q2
	2. q1 -> q2 (element by element from top)
	3. swap( q1 <-> q2)
- pop()
	 1. Remove the front element of q1
	 

```
|   |  |   |
|   |  |   |
|___|  |___|
  q1     q2
```

```

push(3)             Add 3->q2         swap q1<->q2
|   |  |   |       |   |  |   |      |   |  |   |
|   |  |   |   ->  |   |  |   |  ->  |   |  |   |
|___|  |___|       |___|  |_3_|      |_3_|  |___|
 q1     q2           q1     q2         q1    q2

push(4)             Add 4->q2         q1 -> q2        swap q1<->q2
|   |  |   |       |   |  |   |     |   |  |   |     |   |  |   |
|   |  |   |   ->  |   |  |   |  -> |   |  | 3 | ->  | 3 |  |   |
|_3_|  |___|       |_3_|  |_4_|     |___|  |_4_|     |_4_|  |___|
 q1     q2           q1     q2         q1    q2        q1     q2

push(2)             Add 2->q2         q1 -> q2        swap q1<->q2
|   |  |   |       |   |  |   |     |   |  | 3 |     | 3 |  |   |
| 4 |  |   |   ->  | 4 |  |   |  -> |   |  | 4 | ->  | 4 |  |   |
|_3_|  |___|       |_3_|  |_2_|     |___|  |_2_|     |_2_|  |___|
 q1     q2           q1     q2         q1    q2        q1     q2
 
```

```
Top : queue.front() -> 2 ( for queue it is first element, but for the stack it is actually last element)

pop()  -> remove last added element (queues front element)
| 3 |      |   |
| 4 |  ->  | 3 |
|_2_|      |_4_|


Top: queue.front() -> 3
```

*Pseudocode:*
```cpp
Push(x){
	q2.push(x)
	while(!q1.empty()){
		q2.push(q.front())
		q1.pop()
	}
	swap(q1,q2)
}

Pop(){
	q1.pop()
}

Top(){
	return q1.front()
}
```

<Ins>Time Complexity :</ins>  TC:`O(n)`
push(x) Swapping/pushing `n` element from `q2` to `q1` -> O(n)

<Ins>Space Complexity :</ins>   SC:`O(2n)`
2 Queue -> O(2n)
1 more variable using to Swap -> O(1)
### Approach 2: 1 queue -> stack (Optimised)

Steps:
- push(x)
	1.  Add x -> q1
	2. q1 : move `size-1` element from front one by one (i.e push the adding element to front)
- pop()
	 1. Remove the front : q.pop()

```
push(3)     add 3->q1    move front `size-1=0` element to back
|   |         |   |      |   |
|   |   ->    |   |   -> |   |
|___|         |_3_|      |___|

push(2)     add 2->q1    move front `size-1=1` element to back
|   |         |   |      |   |
|   |   ->    | 2 |   -> | 3 |
|_3_|         |_3_|      |_2_|

push(1)     add 1->q1    move front `size-1=2` element to back
|   |         | 1 |      | 3 |
| 3 |   ->    | 3 |   -> | 2 |
|_2_|         |_2_|      |_1_|
```

```
Top() : queue.front() -> 1 ( for queue it is first element, but for the stack it behaves as top/last element)

pop()  -> remove last added element (queues front element)
| 3 |      |   |
| 2 |  ->  | 3 |
|_1_|      |_2_|


Top(): queue.front() -> 2
```

*Pseudocode:*
```cpp
Push(x){
	q.push(x)
	for(i=0; i<q.size()-1; i++){
		q.push(q.top())
		q.pop()
	}
}

Pop(){
	q.pop()
}

Top(){
	q.front()
}
```

<Ins>Time Complexity :</ins>  TC:`O(n)`
push `size-1` or `n-1` front elment to back -> O(n)

<Ins>Space Complexity :</ins>   SC:`O(n)`
1 Queue -> O(n)

---
# Implement Queue using Stack

### Approach 1: 2 Stack -> queue

Steps:
- push(x)
	1.  s1 -> s2 (element by element from back)
	2. add x-> s1
	3. s2 -> s1 (element by element from back)
- pop()
	 1. Remove the top: s.pop()

```

push(4)             Add 4->s1  
|   |  |   |       |   |  |   |
|   |  |   |   ->  |   |  |   | 
|___|  |___|       |_4_|  |___|   
 s1     s2           s1     s2      

push(3)              s1 -> s2          Add 3->s1       s2 -> s1
|   |  |   |       |   |  |   |     |   |  |   |     |   |  |   |
|   |  |   |   ->  |   |  |   |  -> |   |  | 3 | ->  | 4 |  |   |
|_4_|  |___|       |___|  |_4_|     |___|  |_4_|     |_3_|  |___|
 s1     s2           s1     s2         s1    s2        s1     s2

push(2)              s1 -> s2        Add 2->s1         s2 -> s1
|   |  |   |       |   |  |   |     |   |  |   |     | 4 |  |   |
| 4 |  |   |   ->  |   |  | 3 |  -> |   |  | 3 | ->  | 3 |  |   |
|_3_|  |___|       |___|  |_4_|     |_2_|  |_4_|     |_2_|  |___|
 s1     s2           s1     s2         s1    s2        s1     s2

```

```
Front() : stack.top() -> 4 ( for stack it is last element, but for the queue it behaves as first/front element)

pop()  -> remove last added element (queues front element)
| 4 |      |   |
| 3 |  ->  | 3 |
|_2_|      |_2_|

Front(): stack.top() -> 3

```

<Ins>Time Complexity :</ins>  TC:`O(n)`
push(x) Swapping/pushing `n` element from `s2` to `s1` and then `s1` to `s2` -> O(2n)

<Ins>Space Complexity :</ins>   SC:`O(2n)`
2 Stack -> O(2n)
### Approach 2: 1 Stack -> queue (Optimized)

Steps:
- push(x)
	1. add x-> input
- pop()
	 1. if(output not empty){
			output.pop()
	     } 
		else(){
			input -> output (from back one by one)
			output.pop()
		 }
- top()
	1. if(output not empty){
			return output.front()
		 }
	  else(){
		  input -> output (from back one by one)
		  output.top()
	     }

```
push(2)            add 2-> input
|   |  |   |       |   |  |   |
|   |  |   |  ->   |   |  |   |
|___|  |___|       |_2_|  |___| 
input  output      input    output

push(5)            add 5-> input
|   |  |   |       |   |  |   |
|   |  |   |  ->   | 5 |  |   |
|_2_|  |___|       |_2_|  |___| 
input  output      input    output

push(3)            add 3-> input
|   |  |   |       | 3 |  |   |
| 5 |  |   |  ->   | 5 |  |   |
|_2_|  |___|       |_2_|  |___| 
input  output      input    output
```

```
Front() : output empty : input -> output
output.top() -> 2

| 3 |  |   |       |   |  | 2 |
| 5 |  |   |  ->   |   |  | 5 |
|_2_|  |___|       |___|  |_3_| 
input  output      input   output

Pop() : output not empty
output.pop() -> 2
|   |  | 2 |       |   |  |   |
|   |  | 5 |  ->   |   |  | 5 |
|___|  |_3_|       |___|  |_3_| 
input  output      input   output

push(6)            add 6-> input
|   |  |   |       |   |  |   |
|   |  | 5 |  ->   |   |  | 5 |
|___|  |_3_|       |_6_|  |_3_| 
input  output      input    output

Pop() : output not empty
output.pop() -> 5
|   |  |   |       |   |  |   |
|   |  | 5 |  ->   |   |  |   |
|_6_|  |_3_|       |_6_|  |_3_| 
input  output      input   output
```

*Pseudocode:*
```cpp
Push(x){
	input.push(x)
}

Pop(){
	if(output.empty()==false)
	output.pop()
	else(){
		while(input.empty()==false){
			output.push (input.top())
			input.pop()
		}
		output.pop()
	}
}
```

<Ins>Time Complexity :</ins>  TC:`O(1)`
Push -> O(1)
Pop -> O(1) Amortised ~ Average
Because in most of the cases TC->O(n) except some/very few with O(n).

<Ins>Space Complexity :</ins>   SC:`O(n)`
 1 Stack -> O(n)
# Valid Pranthesis

```
Valid

s = ( ) [ { } ( ) ]

( ) [ { } ( ) ]
^ ^
( ) [ { } ( ) ]
    ^         ^
( ) [ { } ( ) ]
      ^ ^
( ) [ { } ( ) ]
      ^ ^

Invalid
s = ] ( ) { } no  pair of this closing `]`
    ^

s = [ ) ( ] no valid pair of the `(` and `)`
      ^ ^

s = [ ( ] ) one `(` inside a `[]` pari |  one `]` inside a pair `( )`
      ^   ^
```

Approach to check if parentheses valid or not?  (using `stack` )

```
s = [ ( ) [ { ( ) } ] ]

[ ( ) [ { ( ) } ] ]  ->  |   |
^                        |_[_| push('[')

[ ( ) [ { ( ) } ] ]  ->  | ( |
  ^                      |_[_| push('(')

[ ( ) [ { ( ) } ] ]  ->  |   | `)` paired top(): `(`
    ^                    |_[_| pop('(')

[ ( ) [ { ( ) } ] ]  ->  | [ |
      ^                  |_[_| push('[')

[ ( ) [ { ( ) } ] ]  ->  | { |
        ^                | [ | 
                         |_[_| push('{')

[ ( ) [ { ( ) } ] ]  ->  | ( |
          ^              | { | 
                         | [ | 
                         |_[_| push('{')

[ ( ) [ { ( ) } ] ]  ->  | ( |
          ^              | { | 
                         | [ | 
                         |_[_| push('{')

[ ( ) [ { ( ) } ] ]  ->  | { |
            ^            | [ | `)` paired top(): `(`
                         |_[_| pop('(') 
                         
[ ( ) [ { ( ) } ] ]  ->  |   |
              ^          | [ | `}` paired top(): `{`
                         |_[_| pop('{')

[ ( ) [ { ( ) } ] ]  ->  |   |
                ^        |   | `]` paired top(): `[`
                         |_[_| pop('[')


[ ( ) [ { ( ) } ] ]  ->  |   |
                  ^      |   | `]` paired top(): `[`
                         |___| pop('[')

Empty  -> Balanced
```

```
s = [ ( ( ) ]

[ ( ( ) ]    -> |   |
^               |_[_| push('[')

[ ( ( ) ]    -> | ( |
  ^             |_[_| push('(')
  
[ ( ( ) ]    -> | ( |
    ^           | ( |
                |_[_| push('(')
                
[ ( ( ) ]    -> | ( | `)` paired top(): `(`
      ^         |_[_| pop('(')
      
[ ( ( ) ]    -> |   |
        ^       | ( |
                |_[_| 

Did't find opeining (top()==`[`) one for `]` -> not balanced X
```

```
s = ] ( )

} ( )  |   |
       |___|

Did't find opeining (top()==`{`) one for `}` -> not balanced X
```

*CPP Code: *
```cpp
stack <int> st;
for(i=0; i<n; i++){
	if(s[i]=='(' or s[i]=='[' or s[i]=='{') st.push(s[i]);
	else if(st.empty()) return false;
	
	char c = st.top(), st.pop();
	if(s[i]==')' && c=='(' or s[i]==']' && c=='[]' or s[i]=='}' && c=='{')
	else() return false;]
}

if(st.empty()) return true;
return false;
```

<Ins>Time Complexity :</ins>  TC:`O(n)`
<Ins>Space Complexity :</ins>   SC:`O(n)`