# ▶️✔️ Recursion (Striver)

**Learn Recursion**

| \[\[#^R1]] | Introduction to Recursion              | Concept (Recursion) | ✅ |   |
| ---------- | -------------------------------------- | ------------------- | - | - |
| \[\[#^R2]] | Problems on Recursion                  | Problem (Recursion) | ✅ |   |
| \[\[#^R3]] | Parameterised and Functional Recursion | Concept (Recursion) | ✅ |   |
| \[\[#^R4]] | Problems on Functional Recursion       | Problem (Recursion) | ✅ |   |
| \[\[#^R5]] | Multiple Recursion Calls               | Concept (Recursion) | ✅ |   |
| \[\[#^R6]] | Recursion on Subsequences              | Concept (Recursion) | ✅ |   |

**2. Subsequences Pattern** ⭐

| \[\[#^R7]]  | All Kind of Patterns in Recursion           | Concept (Recursion)      | ✅ | A2Z🟠 |
| ----------- | ------------------------------------------- | ------------------------ | - | ----- |
| \[\[#^R8]]  | Combination Sum I                           | Algorithm (Backtracking) | ✅ | A2Z🟠 |
| \[\[#^R9]]  | Combination Sum II                          | Algorithm (Backtracking) | ✅ | A2Z🟠 |
| \[\[#^R10]] | Subset Sum I                                | Problem (Recursion)      | ✅ | A2Z🟠 |
| \[\[#^R11]] | Subset Sum II                               | Algorithm (Backtracking) | ✅ | A2Z🟠 |
| \[\[#^R12]] | Print all Permutations of a String/Array I  | Algorithm (Backtracking) | ✅ |       |
| \[\[#^R13]] | Print all Permutations of a String/Array II | Concept (Recursion)      | ✅ | 🟠SDE |

**Trying out all combos /Hard**

| \[\[#^R14]] | N-Queens Backtracking              | Algorithm (Backtracking) | ✅  | A2Z🔴SDE |
| ----------- | ---------------------------------- | ------------------------ | -- | -------- |
| \[\[#^R15]] | Sudoku Solver \| Backtracking      | Algorithm (Backtracking) | 🔃 | A2Z🔴SDE |
| \[\[#^R16]] | M-Coloring Problem \| Backtracking | Algorithm (Backtracking) | ✅  | A2Z🔴SDE |
| \[\[#^R17]] | Palindrome Partitioning            | Algorithm (Backtracking) | ❌  | A2Z🟠    |
| \[\[#^R18]] | K-th Permutation Sequence          | Algorithm (Recursion)    | ❌  |          |
| \[\[#^R19]] | Rat in A Maze                      | Algorithm (Backtracking) | ❌  | A2Z🔴SDE |

***

**Recursion vs Backtracking**

**Recursion:** -> Tool

* Just goes forward solving smaller subproblems.
* No need to undo anything when returning.

**Backtracking:** -> Technique

* Goes forward solving, but
* Before returning (going back to parent), it **undoes changes** made at the current step to explore different options (choices).

> **Backtracking = Recursion + Undo changes while returning** **Recursion** is a **tool** to **implement** Backtracking

***

**Problems Solved by Recursion**

**Can be Solved using Recursion ✅**

```mathematica
*Subsequence*: Pick elements (maintaining order + Can skip elements)
- Method: Recursion -> At every index -> Pick or Not Pick.
- Example: "abc" -> "ac"

*Subset*: Pick elements (no order important + Can skip elements)
- Method: Recursion -> At every index -> Pick or Not Pick. (Similar to Subsequence, but output considered as set)
- Example: [1,2,3] -> {}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}

*Combination*: Pick any elements (no order important)
- Method: Recursion + Backtracking -> At every index -> Pick or Not Pick.
- Example: [1,2,3] → (1,2), (1,3), (2,3)

*Permutation*: Pick and arrange elements (Order matters)
- Method: Recursion + Backtracking -> Swap elements at every index and explore.
- Example: [1,2] → (1,2), (2,1)
```

**Can't be Solved using Recursion** ❌

```mathematica
*Substring*: Continuous character elements (no skip)
- Method: Two loops (start and end pointers) or sliding window.
- Example: "abc" → "ab", "bc"

*Subarray*: Continuous integer elements (no skip)
- Method: Two loops (start and end pointers) or sliding window.
- Example: [1,2,3] → [1,2], [2,3]
```

***

**Recursion Approach Types**

**Combination Sum**

```sh
# Combination Sum I:
- Pick the same element unlimited times.
- At every index:
    a. Pick element → stay at same index.
    b. Not pick element → move to next index.
- Base Case: if (target == 0) -> store current path.

# Combination Sum II:
- Pick each element only once.
- Handle duplicate elements (skip duplicates).
- At every index:
    a. Pick element (move to next index).
    b. Not pick element (move to next index).
- Base Case: if (target == 0) -> store current path.
```

**Subset Sum**

```sh
# Subset Sum I:
- Find all subset sums.
- At every index:
    a. Pick element (add to sum).
    b. Not pick element.
- Base Case: if (index == n) -> store sum.

# Subset Sum II:
- Find all unique subsets (handle duplicates).
- Sort the array first.
- At every index:
    a. Pick element (move to next index).
    b. Not pick element (skip duplicates carefully).
- Base Case: store subsets.
```

**Print All Permutation**

```sh
# Print all Permutations of a String/Array I:
- No duplicate elements.
- Recursion + Swapping:
    a. Swap current index with every index.
    b. Recurse for next index.
    c. Backtrack (swap again to restore).

# Print all Permutations of a String/Array II:
- Array may have duplicate elements.
- Use a "visited" array to track picked elements.
- At each recursion:
    a. Pick unused element.
    b. Skip if element already picked at same level.
- Base Case: if (path.size() == array.size()) -> store path.
```

***

**Pick/Not-Pick vs Pick/Skip\`**

**Method 1: Pick or Not Pick**

```sh

- For every index:
    a. Pick the element.
    b. Not pick the element.
- Use when: No need to loop at each level.
- Example: Combination Sum I
```

**Method 2: For Loop (Pick or Skip)**

```sh
- At each recursion level:
    a. Run a loop from current index to end.
    b. Pick an element, move recursion ahead.
    c. Handle skipping of duplicates (for unique subsets).
- Use when: Need to explore multiple choices at one level.
- Example: 
    - Combination Sum II (Optimal)
    - Subset Sum II (Optimal)
```

***

[**Re 1. Introduction to Recursion | Recursion Tree | Stack Space | Strivers A2Z DSA Course**](https://www.youtube.com/watch?v=yVdKa8dnKiE\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=1\&pp=iAQB) **^R1**

Recursion

* Function Call itself
* Until a specific condition is met

Function Call Itself

```cpp
void f(){ 
	print(1)
	f() --------> void f(){
	}                 print(1)
}                     f() -----------> void f(){
                      }                     print(1)
main(){                                     f() -----------> .......
	f();                                    }
}

// Output: 1111111111111111.....∞
```

TC: `O(∞)` -> Recursion SC: `O(∞)` -> Stack Space

```scss
Stack

|...|
|...|
|f()|
|f()|
|f()|
|___|
```

Function Call itself + Condition

```cpp
void f(){
	if(ct==r) return --> (base condition)
	print(ct)
	ct++
	f()
}

main(){
 f()
}
```

TC: `O(n)` -> n\* time recursion SC: `O(n)` -> n stack space

```scss
Stack

|f()->     |   |    
|f()|      |f()->      |   |      
|f()|  =>  |f()|   =>  |f()->  =>  |   |   => 
|f()|      |f()|       |f()|       |f()|       |   |
|___|      |___|       |___|       |___|       |___|
```

Recursion Tree

```scss
f()
  ⬊
   f()
     ⬊
      f()
        ⬊
         f()
```

[**Re 2. Problems on Recursion | Strivers A2Z DSA Course**](https://youtu.be/un6PLygfXrA?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9) **^R2**

***

Problems on Recursion

```
Q1. Print Name N Times
Q2. Print Linearly from 1 to N
Q3. Print from N to 1
Q4. Print Linearly from 1 to N (by Backtracking)
Q5. Print from N to 1 (by Backtracking)
```

**Q1.** Print Name 5 Time

```cpp
void f(){
	if(i>n) return
		print("gaurav")
		f(i+1,n)
}

main(){
	int n;
	cin>>N;
	f(i,n)
}
```

```scss
    f(1,4)    -> "Gaurav"
	 |
     v
    f(2,4)    -> "Gaurav"
     |
     v
    f(3,4)    -> "Gaurav"
     |
     v
    f(4,4)    -> "Gaurav"
     |
     v
    f(5,4)    -> Returns (Base Case)
   
    Unwinds back up, printing "Gaurav" 4 X time

```

Siminlarly,

**Q2**. Print Linearly from 1 to N

```cpp
f(i,N){
	if(i>N) return
	print(i)
	f(i+1,N)
}

main(){
	input(N)
	f(1,N) // 1->N
}
```

**Q3**. Print from N to 1

```cpp
f(i,N){
	if(i<1) return
	print(i)
	f(i-1,N)
}

main(){
	input(N)
	f(N,N); // N->1
}
```

**Q4**. Print Linearly from 1 to N (by Backtracking)

```cpp
f(i<N){
	if(i<N) return;
	f(i-1,N)
	print(i)
	}

main(){
	input()
	f(N,N)
}
```

```scss
	f(3,3)
	 |    ⬉
     v    -> print(3)
    f(2,3)
     |     ⬉
     v   ->  print(2) 
    f(1,3) 
     |     ⬉
     v   ->  print(1)
    f(0,3) 

// Output : 1 2 3
```

**Q5**. Print from N to 1 (by Backtracking)

```cpp
f(i<N){
	if(i>N) return;
	f(i+1,N)
	print(i)
	}

main(){
	input()
	f(N,N)
}
```

**Recursion :** A recursive function solves a particular problem by calling a copy of itself and solving smaller subproblems of the original problems

**Backtracking :** Backtracking at every steps eliminates those choices that cannot give us the solution and process to those choices that have the potential of taking us to the solution

***

[**Re 3. Parameterised and Functional Recursion | Strivers A2Z DSA Course**](https://youtu.be/69ZCDFy-OUo?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9) **^R3**

**Parameterized Recursion :** In parameterized recursion, the function passes additional parameters to keep track of the state or accumulate results. The parameters change with each recursive call, influencing the behavior of the recursion.

Factorial using Parameterized Recursion

```cpp
int f(int n, int r = 1) {
    return (n == 1) ? r : f(n - 1, r * n);
}
```

**Functional Recursion :** In functional recursion, the function relies on returning values from recursive calls to calculate the final result. The recursion is driven by returning and combining results from each call rather than using parameters to track state.

Factorial using Functional Recursion

```cpp
int f(int n) {
    return n == 1 ? 1 : n * f(n-1);
}
```

***

**Q1. Print Sum of first N numbers**

**1. By Parameterized Recursion**

```cpp
f(i,sum){
	if(i<1){
		print(sum)
		return
		}
	
	f(i-1,sum+i)
}

main(){
	n = 3
	f(n,0)
}
```

TC: `O(n)` -> recursion SCL: `O(n)` -> stack space

```scss
   f(3,0) -> (i+1, sum+i)
	 |    ⬋
	 v
   f(2,3) -> (i+1,sum+i)
	 |   ⬋
	 v
   f(1,5) -> (i+1, sum+i)
	 |    ⬋
	 v  
   f(0,6) -> print(sum)
	 |
	 v
     X
```

**2. By Functional Recursion**

```cpp
f(n){
	if(n==0) return 0
	return n+f(n-1)
}

main(){
	n=3
	print(f(n))
}
```

TC: `O(n)` -> recursion SC: `O(n)` -> stack space

```scss
	f(3)                => 6
   ⬋   ⬊
  3  +  f(2)            => 3+3 = 6     
        ⬋   ⬊             ↑
       2  +  f(1)       => 2+1 = 3
             ⬋   ⬊        ↑
            1  +  f(0)  => 1+0 = 1
```

_Note :_ The **parameterised** recursion approach involves passing additional parameter to the recursive function to keep track of the current sum and the current number being considered. **Functional** recursion approach involves defining a recursion function without any additional parameters. The functional simplify calls itself with a modified argument until it reach the base case.

***

[**Re 4. Problems on Functional Recursion | Strivers A2Z DSA Course**](https://youtu.be/twuC1F6gLI8?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9) **^R4**

**Q1. Function to swap/reverse an array**

```
[1 2 3 4 2] -> [2 4 3 2 1]
```

Approach 1

```
[ 1  2  3  4  2 ]  swap(i & r) till i<r
  i ⤻ ⤻ ↜ ↜ r
```

```cpp
f(l,r){
	if(l>=r) return
	swap
}

main(){
	arr
	f(0,n-1)
}
```

TC: `O(n/2)` - recursion SC: `O(n/2)` -> stack space

Approach 2

```
       n/2
[ 1  2  3  4  2 ]  swap(i) till i<n/2
  i ⤻ ⤻   
```

```cpp
f(i){
	if(i>=n/2) return
	swap(a[i],a[n-i-1])
	f(i+1)
}

main(){
	arr
	f(0)
}
```

TC: `O(n/2)` -> recursion SC: `O(n/2)` -> stack space

***

**Q2. Check if a String is Palindrome**

```scss
"MADAM" -> "MADAM"  -> True
"MADAM" -> "MADSM"  -> False
```

```cpp
f(i){
	if(i>=n/2) return true;
	if(s[i]!=s[n-i-1]) return false;
	return f(i+1);
}

main(){
	print(f(0))
}
```

TC: `O(n/2)` -> recursion SC: `O(n/2)` -> stack space

***

[**Re 5. Multiple Recursion Calls | Problems | Strivers A2Z DSA Course**](https://youtu.be/kvRjNm4rVBE?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9) **^R5**

> Q1. Fibonacci of nth term

Fibonacci Series

```
0   1   2   3   4   5    6   7    8 ...........
0   1   1   2   3   5    8   13   21 ...........
```

```cpp
f(n){
	if(n<=) return n
	last = f(n-1)
	slast = f(n-2)
	return last + slast
}

main(){
	n // let 4
	print f(n)
}
```

TC:`O(2^n)` -> Recursion ⭐ SC:`O(n)` -> Stack Space

Recursion Tree.

```scss
                     f(4)=3
                 ⤤⬋         ⬊⤣ 
		     2= f(3)    +     f(2) =1
		      ⤤⬋    ⬊⤣     ⤤⬋   ⬊⤣  
		  1= f(2) + f(1)    f(1) + f(0)
		   ⤤⬋  ⬊⤣   =1       =1     =0
		 f(1) + f(0)
		  =1     =0
```

Calling and Return Order

```scss
                                  1↓⤣9
                                 f(4)
                           5⤤⬋2         7⬊⤣8 
		             f(3)         +     f(2)
		       3⤤⬋3         6⬊⤣4     6⤤⬋8   9⬊⤣7
		      f(2)       + f(1)      f(1) + f(0)
		  1⤤⬋4   5⬊⤣2  
		 f(1)  +  f(0)

c↓= Calling order
r⤣=return order
```

Time Complexity Explanation

```
f(n)    -> 2  Recursion calls  f(n-1) & f(n-2)
f(n-1)  -> 2  Recursion calls  f(n-2) & f(n-3)
.       -> 2  Recursion calls  ...
.       -> 2  Recursion calls  ...
f(2)    -> 2  Recursion calls  f(1) & f(0)
f(1)    -> 1

2*2*2* ... n times = 2^n Time complexity
```

**TC : `2^n` -> 2^4 = 16** **but there are only 9 calls for n->4** _Note:_ The reason being, you are calling two down level like from four , you are going to two So for every time you're like going twice down, there by its not exactly 2^n, but you can see its exponential in nature

***

[**L6. Recursion on Subsequences | Printing Subsequences**](https://youtu.be/AxNNVECce8c?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9) **^R6**

**Subsequence** : A contiguous or non-contiguous sequence, which follow the order

```
arr[3,1,2] 

subsequence :{},{3},{1},{2},{3 1},{1 2},{3 2},{3 1 2}

3  1  2
X  ✓  ✓  {1 2}
✓  ✓  X  {3 1}
✓  ✓  ✓  {3 1 2}
X  X  X  { }
```

***

**Q1. Find Subsequence of a Array/List**

_**Pseudo Code**_

```
f(ind, []){
	if(ind >=n){
		print([])
		return
		
	[].add(arr.[i])  ---> Take arr[i]
	f(ind+1, [])
	
	[].remove(arr.[i]) ---> Not Take arr[i]
	f(ind+1, [])
	}
}
```

Recursion Tree

```scss
                                     f(0,[])
                        ✅ ⬋                         ⬊ ❌
                  f(1,[3])                                  f(1,[])
                ✅ ⬋     ⬊ ❌                             ✅   ⬋     ⬊ ❌
       f(2,[31])            f(2,[3])              f(2,[1])           f(2,[])           ✅ ⬋     ⬊ ❌      ✅  ⬋      ⬊ ❌      ✅  ⬋     ⬊ ❌    ✅ ⬋     ⬊ ❌
f(3,[312]) f(3,[31])   f(3,[32]) f(3,[3])   f(3,[12]) f(3,[1])   f(3,[2])  f(3,[])

Take arr[i] - ✅ 
Not Take arr[i] - ❌
```

_**C++ Code**_

```cpp
# include <bits/stdc++.h>
using namespace std;

void printF(ind ind, vector<int> &ds, int arr[], int n){
	if(ind==n){
		for(auto it:ds) cout<<it<<" ";
		if(ds.size()==0) cout<<"{}";
		cout<<endl;
		return;
	}
	// pick the particular index into subsequence
	ds.push_back(arr[ind]);
	printF(ind+1,ds,arr,n);
	ds.pop_back();
	// not pick, this elment is not added to your subsequence
	printF(ind+1,ds,arr,n);
}
```

TC:`O(n*2^n)` for loop \* Recursion => n \* k => n\*2^n SC:`O(n)` Stack Space

Output Order

```
3 1 2
3 1
3 2
3
1 2
1
2
{}
```

How to Reverse The output (without backward for loop i.e. using recursion only?? Ans -> Write Exclusion call before Exclusion

```cpp
// not pick, this elment is not added to your subsequence
printF(ind+1,ds,arr,n);
// pick the particular index into subsequence
ds.push_back(arr[ind]);
printF(ind+1,ds,arr,n);
ds.pop_back();
```

_Note :_ More related term.

* **Substring:** Contiguous part of a string.
* **Subarray:** Contiguous part of an array.
* **Subsequence:** Contiguous or Non-contiguous sequence with order maintained.
* **Subset:** Any selection of elements from a set, order doesn’t matter.

***

[**L7. All Kind of Patterns in Recursion | Print All | Print one | Count**](https://youtu.be/eQCS_v3bw0Q?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9) **^R7**

**Ques: Print All subsequence of Array whose sum in equal to `sum`**

_Input:_

```
[1, 2, 1]  sum=2
```

_Output Print:_

```
1 1
2 
```

## Optimal:

_Pseudocode:_

```
    for(i, ds[], s){
        if(i==n){
            if(s==sum){ 
                print s, return
            }
            //pick ds[i]
            ds.add(arr[i])
            s+=arr[i];
            f(i+1, ds, s) 

            //not pick ds[i]
            ds.remove(arr[i])
            s-=arr[i]
            f(i+1, ds, s)
        }
        return
    }
```

_C++ Code:_

```cpp
void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    if(ind==n){
        if(s==sum){
            //print subarray
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    //pick 
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ind+1 , ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();
    
    //not pick
    printS(ind+1, ds, s, sum, arr, n);
}
```

***

> Modify Question : Print All -> Print Any

**Ques: Print Any one Subsequence whose sum is equal to `sum`**

_Input:_

```
[1, 2, 1]  sum=2
```

_Output Print:_

```
1 1
```

## 1. Brute force

note:- one approach may be using `flag`, this approach only stop `cout<<`, but does not the avoid future function calls; & hence **time complexity will be same**, even of a single print.

_Pseudocode:_

```
bool flag = false;
if(ind==n){
       if(s==sum and flag==false){
           flag = true
           //print subarray
           for(auto it: ds) cout<<it<<" "
           cout<<endl 
       }
       return;
   }
```

## 2. Better Approach

use `bool` datatype as function return.

_C++ Code:_

```cpp
bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){

    //condition satisfied
    if(ind==n){
        if(s==sum){
            //print subarray
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        //consdition not satisfied
        return false;
    }
    //pick 
    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printS(ind+1 , ds, s, sum, arr, n)== true)  return true; //if its future fucntion call return true, than this should also return true

    s -= arr[ind];
    ds.pop_back();
    
    //not pick
    if(printS(ind+1, ds, s, sum, arr, n)== true) return true; //if its future fucntion call return true, than this should also return true

    return false;
    };
```

**note:** we can't be specify which sequence should be printed\
but if you wan to print '2' rather than '1 1' write `exclusion` function before `inclusion`

***

> Modify Question : Print Any -> Count

**Ques: Count the subsequences with `sum = K`**

_Input:_

```
[1, 2, 1]  sum=2
```

_return:_

```
2
```

* change the return type to `int`, remove the `ds`

if condition satisfies -> `return 1` if condition not satisfies -> `return 0`

_C++ code:_

```cpp
int printS(int ind, int s, int sum, int arr[], int n){

    //condition satisfied
    if(ind==n){
        if(s==sum) return 1;
        else return 0;
    }
    s += arr[ind];
    int l = printS(ind+1 , s, sum, arr, n) // possible count if include this

    s -= arr[ind];
    int r = printS(ind+1, s, sum, arr, n) // possible count if not include this

    return l+r;
    };
```

_**Time Complexity:**_ `TC:O(2^n)`\
TC: two choice for each ( 1 to n )-> 2\*2\*2.... \*n times

**TC:O(2^n)** for all above algorithm

It can be **optimised** somewhat by using another base condition at starting

```
if (s > sum) return 0;
```

**Note:** strictly done if array contains positives only

_**Space Complexity:**_ `__`

***

[**L8. Combination Sum | Recursion | Leetcode | C++ | Java**](https://youtu.be/OyZFFqQtu98) **^R8**

**Ques: Print all the combination whose sum is `k` ( Elements can be repeated)**

_Input:_

```
[2, 3, 4, 7] target =7;
```

_return:_

```
[ [2 2 3] , [3 4] , [7] ]
```

_Pseudocode:_

```
if(ind == n){
    if(target == 0) [].add(ds) //store in 2 d array
    else return
}
//take
ds.add(arr[i])
if(a[ind]<=target){
    f(ind, target - arr[ind], ds)
}

//not take
ds.pop(arr[i])
f(int+1 , target, ds)
```

_C++ Code:_

```cpp
#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
        void findCombination(int ind , int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
            if(ind == arr.size()){
                if(target ==0){
                    ans.push_back(ds);
                }
                return ;
            }
            //pick up the element
            if(arr[ind <= target]){
                ds.push_back(arr[ind]);
                findCombination(ind, target - arr[ind], arr, ans, ds);
                ds.pop_back(); // should be inside if, if it is outside, it will may execute even it doesn't add something
            }

            // not pick the element
            findCombination(ind+1, target, arr, ans, ds);
    }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target){
            vector<vector<int>> ans;
            vector<int> ds;
            findCombination(0, target, candidates, ans, ds);
            return ans;
        }
};

```

_**Time Complexity:**_ `TC:O(2^t *k)` \~tricky

2 \* 2 \* 2 ... \*n times : 2^n ❌ (not depend on size of arr\[])

2 \* 2 \* 2 ... \*t times : 2^t ✅ (depends on target)

t: target\
k: no. of push/pop to `ds` datastructure => average length of all combinations

_**Space Complexity:**_ `SC:O(k*x)`

k = size of `ds` data structure\
x = total no. of combination possible

***

[**L9. Combination Sum II | Leetcode | Recursion | Java | C++**](https://youtu.be/G1fRTGRxXU8) **⭐ ^R9**

> **Modified Ques.** Elements Can be Repeated -> Each Element may only be used once

**Ques: Find all unique combinations in `candidates` where the candidate numbers sum to `target`**

> Note: - The solution set must not contain duplicate combinations. combination should be in sorted order

_input:_

```
[10, 1, 2, 7, 6, 1, 5]  target = 8
```

_output:_

```
[
[1, 1, 6].
[1, 2, 5],
[1, 7],
[2, 6]
]
```

## 1. Brute Force : ( with the help of L8. Combination )

1. modify: increase index even if element is picked so that it can't be used again. `f(ind+1, target - arr[ind], ds)`
2. To prevent duplicate combination stored , change `ans` data structure from `vector<vecto<int>>` to `set<vector<int>>`

Note: `arr[]` should be sorted. for sorted combination. sort it separately :)

_**Time complexity:**_ `TC:O(2^t*k*logn)`

* TC of storing combination in data structure increases form `k` to `klogn` because, set is taking `logn` extra time

_**Space Complexity:**_ `SC:O(k*x):`

## 2. Better

consider :

| `index:` | 0 | 1 | 2 | 3 | 4 |
| -------- | - | - | - | - | - |
| `arr[]:` | 1 | 1 | 1 | 2 | 2 |

**Approach:**

* the 0th, 1st and 2nd elements are same, and the 3rd and 4th element are same.
* so incase if `arr[0]` is not include element , Than why `arr[1]` or `arr[2]` will be included.
* similarly , we would not pick `arr[4]` if we not picked up `arr[3]`⭐
* if a element need to be pick, it will be passed in `findCombination(i+1, target-arr[i], arr, ans, ds)`;
* so, we will not pick a element if, same element is skipped in previous index i.e `if(i>ind && arr[i] == arr[i-1]) continue;`👇
* move for the next element in loop `for(int i=ind; i<arr.size(), i++)` and now after 1 loop, `i>ind` and hence, `i` no more remain first element of the combination,
* `ind` is passed in function(), So `ind` will be first element,

_Summarize:_

**Not include** -> for loop -> `i>ind`, and it will skip next element such that `arr[i]==arr[i-1]` **Include** -> if `i<=ind` or `arr[i]!=arr[i-1]` than, don't skip, & if `(arr[i]<=target)` push the `arr[i]` i.e. `ds.push_back(arr[i])`

```
find(ind, target, arr, ans, ds){
    if(target=0) ans.add(ds)
    return
```

```
    for(i: ind->n){
    if(i>ind and arr[i]=arr[i-1]) continue
    if(arr[i]>target) break
    ds.push(arr[i])
    f(i+1, target - arr[i], arr, ans, ds);
    ds.pop();
```

_Code C++:_

```cpp
#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
        void findCombination(int ind , int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
            //if(ind == arr.size()){  //update
			if(target ==0){
				ans.push_back(ds);
				return; //shifted inner
			}

            for(int i=ind; i<arr.size(), i++){
                if(i> ind && arr[i]==arr[i-1]); //"i>ind" exclude arr[i] in this condition  
                if(arr[i]>target) break;
                
                //picked
                ds.push_back(arr[i]);
                findCombination(i+1, target-arr[i], arr, ans, ds); //shifted inside loop
                ds.pop_back(); //remove last element for each backtrack
            }
        }
            

    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target){
            vector<vector<int>> ans;
            vector<int> ds;
            findCombination(0, target, candidates, ans, ds);
            return ans;
        }
};

```

_**Time Complexity:**_ `TC:O(2^n * k)`

* n: size of array
* k: averagel length of all combinations

_**Space Complexity:**_ `SC:O(k*x):`

[**L10. Subset Sum I | Recursion | C++ | Java**](https://www.youtube.com/watch?v=rYkfBRtMJr8\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=12\&pp=iAQB) **^R10**

> ### **Ques:** Print sum of all subsets of an array.
>
> Output should be in increasing order of `sum`.

_input:_

```
[3, 1, 2]
```

_return:_

```
[1, 2, 3, 3, 4, 5, 6]
```

> 1. Brute Force : use bit manipulation

**Power Set Algorithm**

* It uses `bit manipulation` to generate all subsets\`
* _**Time Compleaxity:**_ `2^*N`

> Better : use recursion

_C++ Code:_

```cpp
class Sollution{
    public:
    void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset){
        if(ind == N){
            sumSubset.push_back(sum);
            return;
        }

        //pick the element
        func(ind+1, sum + arr[ind], arr, N, sumSubset);

        //Don not pick the element
        func(ind + 1, sum, arr, N, sumSubset);

    }

    public:
    vector<int> sumbsetSums(vector<int> arr, int N){
        vector<int> sumSubset;
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};
```

How it is Different from **L9 Combination Sum I** ?:

* in combination sum 1, we need to print all the combination who `sum = k`:\
  `if(i=n)` -> `if(target ==0)` -> `print combinationo`
* in this we need to print all the sum of the subsets\
  `if(i = n)` -> `print sum`

_**Time Complexity:**_ `O(2^n + 2^n*log(2^n))`

Recursion = 2^n\
Sorting = 2^n\*log(2^n)

**note:** tc of sorting for **n** size -> **nlogn**

_**Space Complexity:**_ `O(2^n)`

2^n : size of data structure

[**L11. Subset Sum II | Leetcode | Recursion**](https://youtu.be/RIn3gOkbhQE?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9) **^R11**

> ### Ques: Return all possible subsets (the power set).
>
> The solution set must **not contain duplicate** subsets. Return the solution in **any oreder**

_Input:_

```
[1, 2, 2]
```

_Output:_

```
[[], [1], [1,2], [1,2,2], [2], [2,2]]
```

> 1. Brute Force : Pick & Not Pick

1. Recursion: Pick & Not Pick
2. Store in Set i.e `vector<vector<int>>`

**Time Complexity:** `O(2^n + (2^n)log(2^n))` 😓

Recursion -> 2^n storing into 'm' size set : mlogm

**Space Complexity:** `O(2^n)` ✅

Set size -> 2^n

> 2. Optimal :
>
> > Reduce storing time to set , Using L9. Combination Sum II (Optimal)

🤔 How this is Different From **L9. Combination Sum II** (Optimal) ??

* in combination sum II, we need to Store all the combination whoes `sum = k`:\
  `if(target ==0)` -> `print combination`
* in this we need to Store all the subsets `if(i = n)` -> `print all Subsets`

_C++ Code:_

```cpp
#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
        void findCombination(int ind ,  vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
                    ans.push_back(ds);

            for(int i=ind; i<nums.size(), i++){
                if(i> ind && nums[i]==nums[i-1]); //"i>ind" exclude nums[i] in this condition  
                //picked
                ds.push_back(nums[i]);
                findCombination(i+1,  nums, ans, ds); //shifted inside loop
                ds.pop_back(); //remove last element for each backtrack
            }
        }
            
    public:
        vector<vector<int>> combinationSum(vector<int>& nums){
            vector<vector<int>> ans;
            vector<int> ds; 
            sort(nums.begin(), nums.end()); //Sort array before use
            findCombination(0, nums, ans, ds);
            return ans;
        }
};
```

_**Time Complexity:**_ `TC:O(2^n*k )` 😀

Recursion -> O(2^n)\
let Average length of avery subset size k -> copying ->O(k)

_**Space Complexity:**_ `TC:O(2^n*k)` 😔

[**L12. Print all Permutations of a String/Array | Recursion | Approach - 1**](https://www.youtube.com/watch?v=YK78FU5Ffjw\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=14\&pp=iAQB) **^R12**

> ### **Ques:** Gine an array `nums` of distinct integers, return all the possible permutations.
>
> You can return the answer in any order

_Input:_

```
[1, 2, 3]  n =3
```

```
[[123], [132], [213], [231], [312], [321]]
```

no. of permutation => n! = 3! = 6

> 1. Brute Force
>
> > Using map array

Here we use int `freq[]` array i.e array used to map values to certain indices.

We will loop through indeces 0 to n-1, and if freq\[i] is `unmarked` than it is not picked

1. push this in datastructure and `marked` it
2. Recursion() with this updated freq

base case:

1. ds size equal to number of elment , add this in ans and return

on backtracking:

1. unmarked the freq\[i]
2. through/pop that element out

_Pseudcode:_

```cpp
f(ds,map){
    if(ds.size==n){
        ans.push(ds)
        return
    }

    for(i: 0 -> n-1){
        if(!map[i])
        ds.add[a[i]]
        map[i] =1
        f(ds,map)
        map[i]=0
        ds.pop[a[i]]
    }
}
```

_C++ Code:_

```cpp
class Solution {
    private:
        void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
            if(ds.size() == nums.size()){
                ans.push_back(ds);
                return;
            }

            for(int i = 0; i < nums.size(); i++) {
                if(!freq[i]){
                    ds.push_back(nums[i]);
                    freq[i] = 1;
                    recurPermute(ds, nums, ans, freq);
                    freq[i] = 0;
                    ds.pop_back();
                }
            }
        }

    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> ds;
            int freq[nums.size()] = {0}; // Index-wise frequency
            recurPermute(ds, nums, ans, freq);
            return ans;
        }
};
```

_**Time Complexity:**_ `TC:O(n!*n)` 😀 , Doubt??

the number of permutations -> O(n!)\
n recursive calls, one for each position in the list -> O(n)

_**Space Complexity:**_ `TC:O(n+n)` 😟

freq array -> O(n)\
ds DataStructure -> O(n)

ans DataStructure -> O(n!\*n) why this not include??

note:- there is also another type of space complexity apart of this `data structure` SC, and that is `call stack()` SC:\
Call Stack(): recursion depth (lenght of list) -> O(n)

[**L13. Print all Permutations of a String/Array | Recursion | Approach - 2**](https://www.youtube.com/watch?v=f2ic2Rsc9pU\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=15\&pp=iAQB) **^R13**

> Optimal Approach
>
> > Using Swap()

_Pseudocode:_

```
f(ind,arr){

    if(ind = n) 
    ans.push(arr)
    return

    for(i:ind -> n-1)
    swap(a[ind], a[i])
    f(ind+1,arr)
    reswap(a[ind], a[i])
}
```

_Dry run:_

```cpp
                                  (1,2,3)
                         /           |          \
                   /                 |                  \
          swap[0,0]             swap[0,1]                swap[0,2]        
           /                         |                          \
        (1 2 3)                   (2 1 3)                     (3 2 1)
        /    \                    /    \                      /     \
  swap[1,1] swap[1,2]       swap[1,1] swap[1,2]         swap[1,1] swap[1,2]   
      /        \                /        \                  /         \
(1 2 3)       (1 3 2)      (2 1 3)      (2 3 1)        (3 2 1)       (3 1 2) 
    |            |            |            |              |             |
swap[2,2]    swap[2,2]    swap[2,2]     swap[2,2]     swap[2,2]     swap[2,2] 
    |            |            |            |              |             |
 (1 2 3)      (1 3 2)      (2 1 3)       (2 3 1)       (3 2 1)       (3 1 2) 
```

_C++ Code:_

```cpp
class Solution {
    private:
        void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans){
            if(index == nums.size()){
                ans.push_back(nums);
                return;
            }

            for(int i= index; i<nums.size(); i++){
                swap(nums[index], nums[i]);
                recurPermute(index+1, nums, ans);
                swap(nums[index], nums[i]);
            }
        }
        

    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            recurPermute( 0, nums, ans);
            return ans;
        }
};
```

`TC:O(n!*n)` 😀

no of permutation (n factorial) -> O(n!) for loop (0->n) -> O(n)

_**Space Complexity:**_ `TC:O(n+n!)` 😀

Auxilliary Space of the Recursion Depth -> O(n) ans Data Structure -> O(n!)

[**L14. N-Queens | Leetcode Hard | Backtracking**](https://www.youtube.com/watch?v=i05Ju7AftcM\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=16\&pp=iAQB) **^R14**

> **Ques:** The n queens is the problem of placing n queens on an n X n chessboard such that no to queens attack each other. Given an integer n, return all distinct solutions to the n-queens puzzle

Rule:-

* in a Row -> no more than 1 Queen
* in a Col -> no more than 1 Queen
* No Queen Should Attack each other

hint :- none of the queen attack each other -> so every row will have a queen , every row will have a queen, none of the queen lies on same diagonal. ex:\\

```
 +---------------+
 |   | Q |   |   |
 |---|---|---|---|
 |   |   |   | Q |   
 |---|---|---|---|
 | Q |   |   |   |
 |---|---|---|---|
 |   |   | Q |   |
 +---------------+
```

_Input:_

```
n = 4
```

_Output:_

```
 [
    [ . . q . ]
    [ q . . . ]
    [ . . . q ]
    [ . q . . ] 
 ]

 [
    [ . q . . ]
    [ . . . q ]
    [ q . . . ]
    [ . . q . ] 
 ]
```

note:

board = string of vectors\
board\[i]\[j] = `ith char` of `jth string`

_Pseudocode:_

```
f(col){
   if(col==n) return ans;
   for(row:0->n-1){
       if(can fill?){
       board[row][col]=Q
       f(col+1)
       board[row][col]=empty
       }
   }
}
```

_C++ Code:_

```cpp
class Solution {
   public:
       //issafe() Definition here...

       void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
           if(col==n){
               ans.push_back(board);
               return;
           }
           for(int row =0; row<n; row++){
               if(isSafe(row, col, board, n)){
                   board[row][col] = 'q';
                   solve(col+1, board, ans, n);
                   board[row][col] = '.';
               }
           }
       }
   public:
       vector<vector<string>> solveQueens(int n){
           vector<vector<string>> ans;
           vector<string> board(n);
           string s(n, '.');
           for(int i=0; i<n; i++){
               board[i] = s;
           }

           solve(0, board, ans, n);
           return ans;
       } 
};
```

_isSafe():_

```cpp
bool isSafe(int row, int col, vector<string> board, int n){
        int duprow = row;
        int dupcol = col;
        
        //check left-upper diagonal
        while(row>= 0 && col>= 0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        //check left
        col = dupcol;
        row = duprow;
        while(col>= 0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        //check left-lower diagonal
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
        //we will not check right side columns, because we are filling from left to right, so how would right column had been aready filled!
    }
```

_**Time Complexity:**_ `TC:O(n(n+n+n))` -> (n\*n!)

for loop row: 0 to n-1 -> O(n)\
in isSafe() worst case, check n left & check n upper diagonal & check n lower diagonal not equal to 'Q' -> O(n)+O(n)+O(n)

_**Space Complexity:**_ `TC:O(n^2)`

size of 2D board -> n\*n

my thought. In General we don't include ans dataStructure because it size may be depends on solutions size of ans ? board \* no. of solutions. There is no formula to calculate no. of solution.

> Optimal Remove : the isSafe() O(n+n+n) Complexity

**For left check:**

Use a n size mapArray 0 -> n-1 for n rows. if a row have Queen marked hasMap\[row]=1

```cpp
//value 0 to 3 : size 4
[ 0  1  2  3]
```

**For Lower left Diagonal check:**

fill row + col = same diagonal -> Index of MapArray row 1 and col 2 and row 2 and col 1 will have same diagonal so that there value is 1+2 = 3

```
     0   1   2   3 
   +---------------+
 0 | 0 | 1 | 2 | 3 |
   |---|---|---|---|
 1 | 1 | 2 | 3 | 4 |   
   |---|---|---|---|
 2 | 2 | 3 | 4 | 5 |
   |---|---|---|---|
 3 | 3 | 4 | 5 | 6 |
   +---------------+
```

2n-1 = 2\*4-1 -> 7 size hashmap require\
value ( 0 to 6)

```cpp
// value 0 to 6 : size 2*4-1 = 7
[ 0  1  2  3  4  5  6 ]
```

**For Upper left Diagonal check:**

fill (n-1)+(col - row) = same diagonal -> Index of MapArray

for col 2 and row 1 : (4-1)+(2-1) =4, and col1 and row 0 : (4-1)+(1-0) = 4 will be on same diagonal

for

```
     0   1   2   3 
   +---------------+
 0 | 3 | 4 | 5 | 6 |
   |---|---|---|---|
 1 | 2 | 3 | 4 | 5 |   
   |---|---|---|---|
 2 | 1 | 2 | 3 | 4 |
   |---|---|---|---|
 3 | 0 | 1 | 2 | 3 |
   +---------------+
```

2n-1 = 2\*4-1 -> 7 size hashmap require\
value ( 0 to 6)

```cpp
// value 0 to 6 : size 2*4-1 = 7
[ 0  1  2  3  4  5  6 ]
```

```cpp
class Solution {
  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }

      for (int row = 0; row < n; row++) {

        // Check if there is no queen present ( that is marked as 0) if not present, than assign 'Q'
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';

          //Marked the left on row, upper and lower diagona as `Q` present
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;

          //Call for next col
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          
          //BackTrack -> unassign and unmark
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};
```

**Time Complexity:** `TC:O(n*n!)`

Exponential in nature since we are trying out all ways, to be precise it is O(N! \* N).

**Space Complexity:** `SC:O(n)`

[**L15. Sudoko Solver | Backtracking**](https://www.youtube.com/watch?v=FWAIf_EVUKE\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=17\&pp=iAQB) **^R15**

only one sudoko print (either time complexity would be too much), so we will, not backtrack and remove the filled element,

from cell \[0]\[0] , if it is not filled, then try (1->9) if can be filled,

[**L16. M-Coloring Problem | Backtracking** ](https://www.youtube.com/watch?v=wuVwUK25Rfc\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=18\&pp=iAQB)**^R16**

> ## Given an undirected graph and an integer `M`. Determine if the graphcan be colored with at most M colors such that no two adjacent vetices of the graph are colored with the same color. Here coloring of a graph means assignment of colors to all vertices. Print 1 if it is possible ot colour vertices and 0 otherwise.

```
0-----3
| \   |
|   \ |
2-----1
```

let three colors are 1, 2, 3

```
f(node){
    if(node == N) return T;

    for(color: 1 -> m){
        if(canColor(node,color)){
            color[node] = color;
            if(f(node+1)==true) return true
            color[Node] = 0;
        }
    }
    return false;
}
```

```
//f() -> coloring function 

M = 3

                    ✅
                  f(0)=1 
             /              \
            ❌             ✅
        f(1)=1            f(1)=2
                       /   |     \  
                    ❌   ❌      ✅     
                 f(2)=1  f(2)=2   f(2)=3
                                  /    |    \
                                 ❌    ❌     ✅
                               f(3)=1  f(3)=2  f(3)=3

```

```

m = 2

                 ✅
                f(0)=1 
             /          \
            ❌          ✅
        f(1)=1         f(1)=2
                       /     \      
                    ❌       ❌       
                 f(2)=1      f(2)=2  
```

_**Time Complexity:**_ `TC:O(n^m)`\
try m colors at every n nodes : O(m^n)\
but as we checking ifPossible, for each node, in reality, complexity is much lesser.

_**Space Complexity:**_ `TC:O(n)+O(n)` color array of size n : O(n) Auxilliary space (recursion 0->n): O(n)

```cpp
// Execute
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {
    0
  };
  if (solve(0, color, m, N, graph)) return true;
  return false;
}
```

```cpp
// Function
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}
```

```cpp
// isSafe Function
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
```

> ## 18/22 Videos Done ✅ | [Striver Recursion Playlist](https://youtube.com/playlist?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&si=gtCu_XYKbSkP6UFe)

Todo: Practice, Write the handwritten notes to Markdown.

[**L17. Palindrome Partitioning | Leetcode | Recursion | C++ | Java**](https://www.youtube.com/watch?v=WBgsABoClE0\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=19\&pp=iAQB) **^R17**

[**L18. K-th Permutation Sequence | Leetcode**](https://www.youtube.com/watch?v=wT7gcXLYoao\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=21\&pp=iAQB) **^R18**

[**L19. Rat in A Maze | Backtracking**](https://www.youtube.com/watch?v=bLGZhJlt4y0\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=20\&pp=iAQB) **^R19**

***

**More on Recursion**

[Merge Sort | Algorithm | Pseudocode | Dry Run | Code | Strivers A2Z DSA Course](https://www.youtube.com/watch?v=ogjf7ORKfd8\&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9\&index=8\&pp=iAQB)

[Quick Sort For Beginners | Strivers A2Z DSA Course](https://youtu.be/WIrA4YexLRQ)

[Count Inversions in an Array | Brute and Optimal](https://youtu.be/AseUmwVNaoY?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)
