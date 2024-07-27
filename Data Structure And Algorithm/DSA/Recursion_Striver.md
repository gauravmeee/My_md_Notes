# Recursion 🔁
~By Gaurav Meena

Recursion Idea - > Try Every possible way
Two ways to solve all kind of recursion 

Method 1. `Pick or not pick` -> L8 Combiantion Sum I\
Method 2. -> `loop (skip or pick)` -> L9 Combination Sum II (optimal), Sub Set II (Optimal)

# [Re 1. Introduction to Recursion | Recursion Tree | Stack Space | Strivers A2Z DSA Course](https://www.youtube.com/watch?v=yVdKa8dnKiE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=1&pp=iAQB)

# [Re 2. Problems on Recursion | Strivers A2Z DSA Course](https://youtu.be/un6PLygfXrA?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)

# [Re 3. Parameterised and Functional Recursion | Strivers A2Z DSA Course](https://youtu.be/69ZCDFy-OUo?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)

# [Re 4. Problems on Functional Recursion | Strivers A2Z DSA Course](https://youtu.be/twuC1F6gLI8?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)

# [Re 5. Multiple Recursion Calls | Problems | Strivers A2Z DSA Course](https://youtu.be/kvRjNm4rVBE?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)


# [L7. All Kind of Patterns in Recursion | Print All | Print one | Count](https://youtu.be/eQCS_v3bw0Q?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)

>## **Ques: Print All subsequence of Array whose sum in equal to `sum`

*Input:*
```
[1, 2, 1]  sum=2
```

*Output Print:* 
```
1 1
2 
```

> 1. Optimal:

*Pseudocode:*
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
````
*C++ Code:*
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

> ## **Ques: Modified** Print Any one Subsequence whose sum is equal to `sum` 

*Input:*
```
[1, 2, 1]  sum=2
```

*Output Print:* 
```
1 1
```

> 1. Brute force

note:- one approach may be using `flag`, this approach only stop `cout<<`, but does not the avoid future function calls;
& hence **time complexity will be same**, even of a single print. 

*Pseudocode:*
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

>2. Better Approach

use `bool` datatype as function return.

*C++ Code:*
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
**note:**  we can't be specify which sequence should be printed\
but if you wan to print '2' rather than '1 1' write `exclusion` function before `inclusion`
<hr>

>## **Ques Modified:** Count the subsequences with `sum = K`

*Input:*
```
[1, 2, 1]  sum=2
```

*return:*
```
2
```

- change the return type to `int`, remove the `ds`

if condition satisfies -> `return  1`
if condition not satisfies -> `return 0`

*C++ code:*
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

<ins>***Time Complexity:***</ins> `TC:O(2^n)` \
TC: two choice for each ( 1 to n )-> 2\*2\*2.... *n times

**TC:O(2^n)** for all above algorithm

It can be **optimised** somewhat by using another base condition at starting
```
if (s > sum) return 0;
```
**Note:** strictly done if array contains positives only

<ins>***Space Complexity:***</ins> `__` 

# [L8. Combination Sum | Recursion | Leetcode | C++ | Java](https://youtu.be/OyZFFqQtu98)

> ## **Ques:** Print all the combination whose sum is `k` ( Elements can be repeated)

*Input:*
```
[2, 3, 4, 7] target =7;
```

*return:*
```
[ [2 2 3] , [3 4] , [7] ]
```
*Pseudocode:*
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

*C++ Code:*
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

<ins>***Time Complexity:***</ins> `TC:O(2^t *k)` ~tricky

2 * 2 * 2 ... *n times : 2^n ❌ (not depend on size of arr[])

2 * 2 * 2 ... *t times : 2^t ✅ (depends on target)

t: target\
k: no. of push/pop to `ds `datastructure => average length of all combinations


<ins>***Space Complexity:***</ins> `SC:O(k*x)`

k = size of `ds` data structure\
x = total no. of combination possible


# [L9. Combination Sum II | Leetcode | Recursion | Java | C++](https://youtu.be/G1fRTGRxXU8)

>## **Ques:** Find all unique combinations in `candidates` where the candidate numbers sum to `target`
>**modified.** Each no. may only be used once \
Note: - The solution set must not contain duplicate combinations.\
combination should be in sorted order

*input:*
```
[10, 1, 2, 7, 6, 1, 5]  target = 8
```

*output:*
```
[
[1, 1, 6].
[1, 2, 5],
[1, 7],
[2, 6]
]
```

> 1. Brute Force: ( with the help of L8. Combination )

1. modify: increase index even if element is picked so that it can't be used again.\
 `f(ind+1, target - arr[ind], ds)`
2. To prevent duplicate combination stored , change `ans` data structure from `vector<vecto<int>>` to `set<set<int>>`

note: arr[] should be sorted. for sorted combinaton. sort it seperately :)

<ins>***Time complexity:***</ins> `TC:O(2^t*k*logn)`

TC of storing combination in data structure increases form `k` to `klogn` because, set is taking `logn` extra time

<ins>***Space Complexity:***</ins> `SC:O(k*x):`

>2. Better
 
consider :
index:|0|1|2|3|4
-|-|-|-|-|-
arr[]:|1|1|1|2|2

approach: the 0th, 1st and second element are same,
and the 3rd and 4th element are same.

so incase if `arr[0]` is not include element , Than why `arr[1]` or `arr[2]` will be included.\

similarly , we would not pick `arr[4]` if we not picked up `arr[3]`

if a element need to be pick, it will be passed in `findCombination(i+1, target-arr[i], arr, ans, ds)`;

so, we will not pick a element if, same element  is skipped in previous index i.e `if(i>ind && arr[i] == arr[i-1]) continue;`👇\
move for the next element in loop `for(int i=ind; i<arr.size(), i++)` and now after 1 loop, `i>ind` and hence, `i` no more remain first element of the combination, 

`ind` is passed in function(), So `ind` will be first element,

*Summarize:*

**Not include** -> for loop -> `i>ind`, and it will skip next element such that `arr[i]==arr[i-1]`\
**Include** -> if `i<=ind` or `arr[i]!=arr[i-1]` than, don't skip, & if `(arr[i]<=target)` push the `arr[i]` i.e. `ds.push_back(arr[i])`

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

*Code C++:*
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

<ins>***Time Complexity:***</ins> `TC:O(2^n * k)`

n: size of array\
k: averagel length of all combinations


<ins>***Space Complexity:***</ins> `SC:O(k*x):`

# [L10. Subset Sum I | Recursion | C++ | Java](https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12&pp=iAQB)

>## **Ques:** Print sum of all subsets of an array. 
>Output should be in increasing order of `sum`.

*input:*
```
[3, 1, 2]
```
*return:*
```
[1, 2, 3, 3, 4, 5, 6]
```

>1. Brute Force : use bit manipulation

**Power Set Algorithm**
- It uses `bit manipulation` to generate all subsets`
- ***<ins>Time Compleaxity:***</ins> `2^*N`

> Better : use recursion

*C++ Code:*
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
- in combination sum 1, we need to print all the combination who `sum = k`:\
`if(i=n)` -> `if(target ==0)` -> `print combinationo`
                
- in this we need to print all the sum of the subsets \
`if(i = n)` -> `print sum`

<ins>***Time Complexity:***</ins> `O(2^n + 2^n*log(2^n))`

Recursion = 2^n\
Sorting = 2^n*log(2^n)

**note:** tc of sorting for **n** size -> **nlogn**

<ins>***Space Complexity:***</ins> `O(2^n)`

2^n : size of data structure

# [L11. Subset Sum II | Leetcode | Recursion](https://youtu.be/RIn3gOkbhQE?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)

>## Ques: Return all possible subsets (the power set).
>The solution set must **not contain duplicate** subsets. Return the solution in **any oreder**

*Input:*
```
[1, 2, 2]
```
*Output:*
```
[[], [1], [1,2], [1,2,2], [2], [2,2]]
```
>1. Brute Force : Pick & Not Pick

1. Recursion: Pick & Not Pick
2. Store in Set i.e `vector<vector<int>>`

<ins>**Time Complexity:**</ins> `O(2^n + (2^n)log(2^n))` 😓

Recursion -> 2^n
storing into 'm' size set : mlogm

<ins>**Space Complexity:**</ins> `O(2^n)` ✅

Set size -> 2^n

>2. Optimal :
>>Reduce storing time to set , Using L9. Combination Sum II (Optimal)

🤔 How this is Different From **L9. Combination Sum II** (Optimal) ??

- in combination sum II, we need to Store all the combination whoes `sum = k`:\
`if(target ==0)` -> `print combination`
                
- in this we need to Store all the subsets 
`if(i = n)` -> `print all Subsets`

*C++ Code:*
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

<ins>***Time Complexity:***</ins> `TC:O(2^n*k )` 😀

Recursion -> O(2^n)\
let Average length of avery subset size k -> copying ->O(k)

<ins>***Space Complexity:***</ins> `TC:O(2^n*k)` 😔

# [L12. Print all Permutations of a String/Array | Recursion | Approach - 1](https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14&pp=iAQB)

> ## **Ques:** Gine an array `nums` of distinct integers, return all the possible permutations. 
> You can return the answer in any order

*Input:*
``` 
[1, 2, 3]  n =3
```
```
[[123], [132], [213], [231], [312], [321]]
```
no. of permutation => n! = 3! =  6

>1.  Brute Force
>> Using map array

 Here we use int freq[] array i.e array used to map values to certain indices.

 We will loop through indeces 0 to n-1, and if freq[i] is `unmarked` than it is not picked
 1. push this in datastructure and `marked` it
 2. Recursion() with this updated freq

 base case:
 1. ds size equal to number of elment , add this in ans and return

 on backtracking:
 1. unmarked the freq[i]
 2. through/pop that element out


*Pseudcode:*
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

*C++ Code:*
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

<ins>***Time Complexity:***</ins> `TC:O(n!*n)`  😀 , Doubt??

 the number of permutations -> O(n!)\
n recursive calls, one for each position in the list -> O(n)

<ins>***Space Complexity:***</ins>  `TC:O(n+n)` 😟

freq array -> O(n)\
ds DataStructure -> O(n)

ans DataStructure -> O(n!*n) why this not include??

note:- there is also another type of space complexity apart of this `data structure` SC, and that is `call stack()` SC:\
Call Stack(): recursion depth (lenght of list) -> O(n)

# [L13. Print all Permutations of a String/Array | Recursion | Approach - 2](https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=15&pp=iAQB)

> Optimal Approach
>> Using Swap()

*Pseudocode:*
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

*Dry run:*
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

*C++ Code:*
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

no of permutation (n factorial) -> O(n!) 
for loop (0->n)  -> O(n)

<ins>***Space Complexity:***</ins> `TC:O(n+n!)` 😀

Auxilliary Space of the Recursion Depth ->  O(n)
ans Data Structure -> O(n!)

#  [L14. N-Queens | Leetcode Hard | Backtracking](https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=16&pp=iAQB)

> **Ques:** The n queens is the problem of placing n queens on an n X n chessboard such that no to queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle

Rule:-
- in a Row -> no more than 1 Queen
- in a Col -> no more than 1 Queen
- No Queen Should Attack each other

hint :- none of the queen attack each other -> so every row will have a queen , every row will have a queen, none of the queen lies on same diagonal.
ex:\
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

*Input:*
```
n = 4
```

*Output:*
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
 board[i][j] = `ith char` of `jth string`


*Pseudocode:*
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

 *C++ Code:*
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

*isSafe():*
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

<ins>***Time Complexity:***</ins> `TC:O(n(n+n+n))` -> (n*n!)

for loop row: 0 to n-1 -> O(n)\
in isSafe() worst case, check n left & check n upper diagonal & check n lower diagonal not equal to  'Q' -> O(n)+O(n)+O(n)

<ins>***Space Complexity:***</ins> `TC:O(n^2)`

size of 2D board -> n*n

my thought.
In General we don't include ans dataStructure because it size may be depends on solutions
size of ans ? board * no. of solutions. There is no formula to calculate no. of solution.

> Optimal
Remove : the isSafe() O(n+n+n) Complexity

**For left check:**

Use a n size mapArray 0 -> n-1 for n rows.
if a row have Queen marked hasMap[row]=1

```cpp
//value 0 to 3 : size 4
[ 0  1  2  3]
```

**For Lower left Diagonal check:**

fill row + col = same diagonal -> Index of MapArray 
row 1 and col 2 and row 2 and col 1 will have same diagonal so that there value is 1+2 = 3
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
 2n-1 = 2*4-1 -> 7 size hashmap require\
 value ( 0 to 6)
 ```cpp
 // value 0 to 6 : size 2*4-1 = 7
 [ 0  1  2  3  4  5  6 ]
 ```

 **For Upper left Diagonal check:**

fill (n-1)+(col - row) = same diagonal -> Index of MapArray 

for col 2 and row 1 : (4-1)+(2-1) =4, and  col1 and row 0 : (4-1)+(1-0) = 4 will be on same diagonal

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
 2n-1 = 2*4-1 -> 7 size hashmap require\
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
<ins>**Time Complexity:**</ins> `TC:O(n*n!)`

Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).

<ins>**Space Complexity:**</ins> `SC:O(n)`


# [L15. Sudoko Solver | Backtracking](https://www.youtube.com/watch?v=FWAIf_EVUKE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=17&pp=iAQB)

only one sudoko print (either time complexity would be too much), so we will, not backtrack and remove the filled element, 

from cell [0][0] , if it is not filled, then try (1->9) if can be filled, 

# [L16. M-Coloring Problem | Backtracking ](https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=18&pp=iAQB)

> # Given an undirected graph and an integer `M`. Determine if the graphcan be colored with at most M colors such that no two adjacent vetices of the graph are colored with the same color. Here coloring of a graph means assignment of colors to all vertices. Print 1 if it is possible ot colour vertices and 0 otherwise.

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

<ins>***Time Complexity:***</ins> `TC:O(n^m)`  
try m colors at every n nodes : O(m^n)\
but as we checking ifPossible, for each node, in reality, complexity is much lesser.

<ins>***Space Complexity:***</ins> `TC:O(n)+O(n)`
color array of size n : O(n)
Auxilliary space (recursion 0->n): O(n)

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

> # 18/22 Videos Done ✅ |  [Striver Recursion Playlist](https://youtube.com/playlist?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&si=gtCu_XYKbSkP6UFe)

Todo: Practice, Write the handwritten notes to Markdown.

# [L17. Palindrome Partitioning | Leetcode | Recursion | C++ | Java](https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=19&pp=iAQB)

# [L18. K-th Permutation Sequence | Leetcode](https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=21&pp=iAQB)

# [L19. Rat in A Maze | Backtracking](https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=20&pp=iAQB)


Related 
# [Merge Sort | Algorithm | Pseudocode | Dry Run | Code | Strivers A2Z DSA Course](https://www.youtube.com/watch?v=ogjf7ORKfd8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8&pp=iAQB)

# [Quick Sort For Beginners | Strivers A2Z DSA Course](https://youtu.be/WIrA4YexLRQ)

# [Count Inversions in an Array | Brute and Optimal](https://youtu.be/AseUmwVNaoY?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9)