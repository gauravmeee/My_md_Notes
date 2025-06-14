
# Sliding Window / 2 Pointer 

**Substring:** Continuous character elements (no skip)
- Method: Two loops (start and end pointers) or sliding window.
- Example: `"abc"` → `"ab", "bc"`

**Subarray:** Continuous integer elements (no skip)
- Method: Two loops (start and end pointers) or sliding window.
- Example: `[1,2,3]` → `[1,2], [2,3]`

---
# [L1. Introduction to Sliding Window and 2 Pointers | Templates | Patterns](https://youtu.be/9kdHxplyl5I?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

# **Pattern 1 :** Constant Window

>Use two pointers `l` and `r` with fixed window size `k`.  
>Window length is `k = r - l + 1`  
>To maintain constant window: `r = (k - 1) + l`

### **Ques.** Find the Maximum sum obtain by using `k` length subarray of `arr`.

```
Input:
arr = [-1, 2, 3, 4, 5, -1] 
k = 4
```


- `length(k) = r-l+1`
- `r` -> `(k-1)+l` = `3 + l` ⭐

##### **Start** `l=0` 

1. `l=0` -> `r=3+0 = 3`
```
 constant window
  l........r 
  ↓        ↓ 
  0  1  2  3  4   5
[-1  2  3  4  5  -1]

Sum = arr[0] + arr[1] + arr[2] + arr[3] = -1+2+3+4 = 8
Max Sum = 8
```

2. `l=1` -> `r=3+1=4`
```
	constant window
     l........r
     ↓        ↓
  0  1  2  3  4   5
[-1  2  3  4  5  -1] 

Sum = arr[1] + arr[2] + arr[3] + arr[4] = 2+3+4+5 = 14
Max Sum = 14  (8<14)
```

3. `l=3` -> `r=3+2=5`
```
       constant window
        l.........r
        ↓         ↓
  0  1  2  3  4   5
[-1  2  3  4  5  -1]
  

Sum = arr[2] + arr[3] + arr[4] + arr[5] = 3 + 4 + 5 -1 = 11
Max Sum = 14   (14>11)
```
	
4. `l=4` -> `r=3+3=6` ❌ `arr[6]` out of bond 

- So, Maximum Sum = `max(8,14,11)`
##### **End**


**C++ Code**
```cpp
int maxSumKSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, r = k - 1;

    // Base case: sum of first window
    int sum = 0;
    for(int i = 0; i <= r; i++) sum += arr[i];

    int maxSum = sum;

    // Slide the window
    while (r < n - 1) {
        sum -= arr[l]; // remove left element
        l++; r++;
        sum += arr[r]; // add new right element
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
```

# **Pattern 2 :** Longest Subarray/Substring where `(Condition)`  ⭐

⭐Important

> Use two pointers `l` and `r` with **variable window size**.  
> Window length is `r - l + 1`.  
> Expand window by increasing `r`, and shrink from left (increase `l`) when condition
> breaks.
### **Ques.** Find the `length` of Longest Subarray with `sum <= K`

```
arr = [2,5,1,7,10] 
k = 14
```

### 1. <ins>Brute Force</ins>

>Check all subarrays, and break when sum exceeds `k`

**C++ Code**
```cpp
int maxLen = 0;
for(int i = 0; i < n; i++) {
    int sum = 0;
    for(int j = i; j < n; j++) {
        sum += arr[j];
        if(sum <= k)
            maxLen = max(maxLen, j - i + 1);
        else
            break;
    }
}
```
- `TC:O(n^2)` 
- `SC:O(1)`

### 2. <ins>Better (Sliding Window)</ins>

> Two Pointer Technique with Shrinking from Left

- Expand → `r++`
- Shrink → `l++` when `sum > k`
- Window length = `r - l + 1`
- Maintain `maxLen`

**C++ Code**
```cpp
l = 0 , r = 0, sum = 0
while( r < n ){
    sum += arr[r]  // Add (expand)

    while(sum > k){
        sum -= arr[l]  // Subtract (shrink)
        l++ // move 'l' forward (shrink)
    }

    maxLen = max(maxLen, r - l + 1) // if you are asked to print the subarray, than store this l & r
    r++  // move 'r' forward (expand)
}
```
Time complexity:  `l` can go up to `n` by shrinking the window (`l++`) Worst Case. `r` can go up to `n` by expanding the window (`r++`) in Worst case. So total time: `O(n + n)`
- `TC:O(n+n)`
- `TC:O(1)`


**Note:**
- Window length = `r - l + 1`    
- Maintain max length using `maxLen = max(maxLen, r - l + 1)`


### 3. <ins>Optimal</ins>  ⭐

>Avoid shrinking more than once to save time (Why to shrink more than the current longest answer) ⭐


- Only shrink once using `if(sum > k)`
- Best for length only, not subarray

If you're asked to **find the actual longest subarray with sum ≤ k**, use the **previous (Better)** approach with `while(sum > k)`.

**Update:**  
- Use `if(sum > k)` instead of `while(sum > k)`  
- Shrink the window from left **only once** to **avoid reducing current valid window below max length**. Because it would no use to shrink, more than the possible answer.

**C++ Code**
```cpp
l = 0 , r = 0, sum = 0
while( r < n ){
    sum = sum + arr[r]
    if(sum > k){ // change
        sum = sum - arr[l]
        l = l+1
    }
    if(sum <= k){
        maxLen = max(maxLen, r-l+1)
        r = r+1
        
    }
}
```
- `TC:O(n)`
- `TC:O(1)`

**Note:** 
- Use this only when finding the **length** of longest subarray, or to print any longest subarray. 
- If asked for specific subarray like or based on some condition like - Longest Length of the subarray with   maximum `sum`  (with `sum <= k`  ), It would not work. Use  previous method (`while(sum > k)`).

# **Pattern 3 :** No. of Subarrays where (Condition)

- Solved using Pattern 2
- It is very difficult to count to calculate no. of subarray
- **Example** Find the No. of Subarrays with `sum = k`
- when there is some constant condition like `sum = k`, it is verry tough to understand when to **Expand** and when to **Shrink**. 

**Breaking down Problem**
```
No. of subarrays where sum <=k --> x
No. of subarrays where sum <= (k-1) --> y

x-y --> No. of subarray with (sum = k)
```

❓ why can't it solved directly using shrink and expand

# **Pattern 4 :** Shortest/Minimum Window (Condition)

- Same as **Pattern 2**
- Find a valid Window, Then shrink it till it valid

---
# [L2. Maximum Points You Can Obtain from Cards | 2 Pointers and Sliding Window Playlist](https://youtu.be/pBWCOCS636U)

### **Ques.** Find maximum score you can obtain by taking exactly `k` elements from `nums`. 
(Condition : You can pick card only from either left and right consecutively i.e. You can't go and pick element from middle.)

```
Input:
arr = [6, 2, 3, 4, 7, 2, 1, 7, 1]
k = 4
```


1. l` -> 4 element , `r` -> 0 element
```
 .........l
[6, 2, 3, 4, 7, 2, 1, 7, 1]

sum = (6+2+3+4) -> 15
```

2. `l` -> 3 element , `r` -> 1 element
```  
       ⭠                 ⭠
.......l                 r
[6, 2, 3, 4, 7, 2, 1, 7, 1]

sum = (6+2+3)+(1) -> 12
```

3. `l` -> 2 element , `r` -> 2 element
``` 
    ⭠                ⭠    
....l                 r...
[6, 2, 3, 4, 7, 2, 1, 7, 1]

sum = (6+2)+(7+1) -> 16
```

4. `l` -> 1 element , `r` -> 3 element
```
 ⭠                ⭠
 l                 r......
[6, 2, 3, 4, 7, 2, 1, 7, 1]

sum = (6)+(1+7+1) -> 15
```

5. `l` -> 0 element , `r` -> 4 element
```
⭠              ⭠
                r..........
[6, 2, 3, 4, 7, 2, 1, 7, 1]

sum = (2+1+7+1) -> 11
```

Maximum Points = 16

### 1. <ins>Brute Force </ins> (by me)

**C++ Code**
```cpp
func( nums[], k) {
       l=k , r= n //n : nums.size
       lsum =0 , rsum =0
       k+1; // need to iterate k+1 time
        while(k--){
            lsum=0; //reset
            for(i -> -1){
                lsum+=nums[i]
            }

            rsum =0; //reset
            for(int j=r; j<n; j++){
                rsum+=nums[j]
            }

            maxSum = max(maxSum, lsum+rsum);
            l-- , r--
        }
```
**Time Complexity:** While loop : O(k+1) + for loop1 : O(k) + for loop2 : O(k)
TC: (k+1)(k+k) => 2K^2 + 2K

- `TC:O(k^2)` 
- `SC:O(1)`

### 2. <ins>Optimal</ins>

**C++ Code**
```cpp
funct(nums, k) {
    lsum=0, rsum=0, maxSum =0

    //initialise first k window from left
    for(int i=0; i<k; i++){
        lsum = lsum + nums[i]
        maxSum = lsum
    }
    int r = n-1; //right Index

    //remove left last element and add right first element

    for( int i=k-1; i>=0 ; i--){ //left Index
        lsum = lsum - nums[i]
        rsum = rsum +  nums[r]
        r = r-1
        maxSum = max(maxSum, lsum+rsum)
    }
    return maxSum
}
```
**Time Complexity:** for loop 1 + for loop 2 = `O(k+k)`

`TC:O(2K)` `SC:O(1)`

---
# [L3. Longest Substring Without Repeating Characters](https://youtu.be/-zSxTJkcdAo)


**Brute force to generate all Substrings**
```cpp
for( i= 0 -> n-1){
    sub = " "
    for( j = i -> n-1 ){
        sub = sub + s[j]
    }
}
```
**Time Complexity:**
- Outer for loop (0->n) `*n...` times -> `TC:O(n)`
- inner for loo (i->n)  average `*n/2...` times -> `TC:O(n/2)`
`TC:O(n)` `SC:O(n)`

### **Ques.** Given a string `s`, find the length of the longest substring without repeating characters.

```
Input:
s = cadbzabcd
```

### 1. <ins>Brute Force</ins>

>Use Brute force to Generate All substring


`i=0`
```
j=0 -> c ✅
j=1 -> ca ✅
j=2 -> cadb ✅
j=3 -> cadbz ✅
j=4 -> cadbza ❌ `a` repeating
j = 5 -> cadbzab❌
j = 6 ❌
j = 7 ❌
```

**Note:** - if something repeating for `i` and `j`, than for that `i` it will also repeating for all `j`s greater than the current 'j'

We need to Use a memory to store if a Character is Already appeared or not.
- There are total `256` Characters
- We could use Hashing Technique `[0 to 255]` to keep tract which Ascii character is Previously seen.
- So, we could move forward outer loop (`i++`), whenever something repeating. Because it if something repeating for `i` & `j` then it will repeat for all `j` greater than current `i` for the given `i`

**C++ Code**
```cpp
for( i= 0; i<n; i++){
    bool hash[256]={0}; // hashing
    for( j = i; j<n;  j++ ){
	    if(hash[s[j]]==1) break; // break if something repeating for `i`
	    len = j-1+1; // length of substring
        maxlen = max(len, maxlen)
        hash[s[j]]=1; // mark the character
    }
} 
```
**Time Complexity:** only while loop i.e `*n` times... contributed to Time complexity
TC: `O(n^n)` 
SC: `O(256)` ~ `O(1)`


### 2. <ins>Better Approach</ins>

> Store elements index, and Move `l` directly to next  of the last repeating element.

**Start :** `r=0` and `r=0` 
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
^
l,r

len = r-l+1 = 0-0+1 = 1
maxlen = 1

│     │
│ c,0 │
└─────┘
Map <char, index>
```

**r++ :** `r=1` and `l=0`
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
^ ^
l r

len = r-l+1 = 1-0+1 = 2
maxlen = 2

│ a,1 │
│ c,0 │
└─────┘
Map <char, index>
```

**Similarly r++

 **When : `r=5`** ---> When `a` is repeating
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
^         ^
l         r

map[s[r]] = 1 -> `a` is already occuring at index 1

l <= map[a]=1 <= r 
```
**`l=map[a]+1` :**  `l=2` and `r=5` (Move `l` to next  of the repeating element.)
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
    ^     ^
    l     r


len = r-l+1 = 5-2+1 = 4
maxlen = 4

| z,4 |
| b,3 |
| d,2 |
│ a,5 │ updated map[a]=5
│ c,0 │
└─────┘
Map <char, index>
```


**r++ :** `l=2` and `r=6`
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
    ^       ^
    l       r

map[s[r]] = b -> `b` is already occuring at index 2

l <= map[b]=3 <= r
```
 **`l=map[a]+1` :**  `l=4` and `r=6`  (Move `l` to next  of the repeating element.))
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
        ^   ^
        l   r


len = r-l+1 = 6-4+1 = 3
maxlen = 4

| z,4 |
| b,6 | updated map[b]=6
| d,2 |
│ a,5 │ 
│ c,0 │
└─────┘
Map <char, index>
```

**r++ :** `l=4` and `r=7`
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
        ^     ^
        l     r

map[s[r]] = b -> `b` is already occuring at index 0

map[c]=0 < l  ( repeating but its already out of considered portion, so nothing to do )  
```
```
len = r-l+1 = 7-4+1 = 4
maxlen = 4

| z,4 |
| b,6 |
| d,2 |
│ a,5 │ 
│ c,7 │ update map[c]=7
└─────┘
Map <char, index>
```


**r++** : `r=8` and `l=4` -> Max length
```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
        ^       ^
        l       r


len = r-l+1 = 8-4+1 = 5
maxlen = 5

| z,4 |
| b,6 |
| d,2 |
│ a,5 │ 
│ c,0 │
└─────┘
Map <char, index>
```

**Pseudo Code**
```cpp
func(string s){
	hash[256] -> {-1} // using Array instead of Map 
	// fill(hash, hash + 256, -1); // In c++ Initialize all with -1 ⭐
	
	l =0, r = 0, maxlen=0, n = s.size()

	while(r<n){
		if(has[s[r]]!=-1){ // when s[r] is in the map
			if(has[s[r]]>=l){ // If s[r] is in considered portion
				l = hash[s[r]]+1;
			}
		}
		len = r-l+1
		maxlen = max(len, maxlen)
		hash[s[r]]=r
		r++
	}
	return maxlen	
}
```
**Time Complexity:** While loop `r++` for every `n` element, and `l` not contributing it
TC : `O(n)`
SC : `O(256)`

---

# [L4. Max Consecutive Ones III | 2 Pointers and Sliding Window Playlist](https://youtu.be/3E4JBHSLpYk)

### **Ques.** Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`_'s in the array if you can flip at most_ `k` `0`'s.

> Break Down Problem into -> Longest subarray with at most `k` zeros

```
Input
nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
k = 2
```
### 1. <ins>Brute Force</ins>

> Try **all subarrays** starting from each index and count zeros. If `zeros <= k`, track max length.

```
Input:
nums = [0,0,1,1,0,0,1,...], 
k=2
```

```
 l r.....r
 0 1 2 3 4
[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]

i=0, 
	j=0 → zeros=1 → len=1 → maxlen=1
	j=1 → zeros=2 → len=2 → maxlen=2 
	j=2 → zeros=2 → len=3 → maxlen=3
	j=3 → zeros=2 → len=4 → maxlen=4
	j=4 → zeros=3 → break  
```  

```
   l r.....r
 0 1 2 3 4 5 
[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
i=1, 
	j=1 → zeros=1 → len=1 → maxlen=1
	j=2 → zeros=1 → len=2 → maxlen=2 
	j=3 → zeros=1 → len=3 → maxlen=3
	j=4 → zeros=2 → len=4 → maxlen=4
	j=5 → zeros=3 → break  
```  

```
and so on...
```


**Pseudo Code:**
```cpp
func(list<int> nums, k){
	maxlen = 0
	for(i=0 -> n){
		zeros = 0
		for(j=i -> n){
			if(nums[j]==0) zeros++
			if(zeros<=k){ 
				len = j-i+1
				maxlen = max(maxlen, len)
			}
			else break;
		}
	}
	return maxlen
}
```
**Time Complexity :** Inner for loop -> O(n), Outer for loop -> O(n)
TC : `O(n^2)`
SC : `O(1)`


### 2. <ins>Better</ins> 

Why to reset `l`to 0->1->2...`  for every outer loop `r` !

>Use a window `[l..r]` that always contains **at most `k` zeros**  
>Expand `r`, and **shrink `l` only when zeros exceed k**

**Pseudo Code:**
```cpp
func(list<int> nums, k){
	maxlen = 0, l=0, r=0, zeros = 0
	while(r<nums.size()){
		if(nums[r]==0) zeros++;
		while(zeros>k){ // Shrink While Zeros > k
			if(nums[l]==0) zeros--;
			l++;
		}
	len = r-l+1;
	maxlen = max(len, maxlen);
	r++;
	}
	return maxlen;
}
```
**Time Complexity :** `l` can move from `0` to `n-1`, and `r` can move from `0` to `n-1`
TC : O(2n)
SC : O(1)



### 3. <ins>Optimal</ins>

Why to shrink subarray more than the current longest answer ! Shrinking more will always small and can never be the answer. so at this time, just shift the window `l++` & `r++` to right

>Avoid shrinking more than once to save time i.e. avoid `while()` loop to `l++` — just `if(zeros > k) to l++` 
>Saves redundant checks. **Only shrink once per violation**⭐


**Pseudo Code:**
```cpp
func(list<int> nums, k){
	maxlen = 0, l=0, r=0, zeros = 0
	while(r<nums.size()){
		if(nums[r]==0) zeros++
		if(zeros>k){ // While loop -> If Condition
			if(nums[l]==0) zeros--
			l++
		}
		if(zeros<=k) maxlen = max(maxlen, r-l+1)
	r++;
	}
	return maxlen;
}
```

**Time Complexity :** `r` can move from `0` to `n-1` i.e. `O(n)`
TC : `O(n)`
SC : `O(1)`

---

# [L5. Fruit Into Baskets | 2 Pointers and Sliding Window Playlist](https://youtu.be/e3bs0uA1NhQ)

### **Ques.** Given an array `fruits[]`, find the maximum number of fruits you can pick from a continuous subarray containing at most two distinct fruit types.

```
Input:
arr = [3 3 3 1 2 1 1 2 3 3 4]
```

Break Down the Problem ->  Max Length subarray with at most 2 types of numbers.
### <ins>1. Brute Force</ins>

`l=0`
```
l
3 3 3 1 2 1 1 2 3 3 4
r.....r

set = {3,1}, size=2
maxlen=4
```

`l=1`
```
  l
3 3 3 1 2 1 1 2 3 3 4
  r...r

set = {3,1}, size=2
maxlen=3
```

`l=2`
```
    l
3 3 3 1 2 1 1 2 3 3 4
    r.r

set = {3,1}, size=2
maxlen=2
```

`l=3`
```
      l
3 3 3 1 2 1 1 2 3 3 4
      r.......r

set = {1,2}, size=2
maxlen=5
```

and so on...
```
final answer maxlen = 5
```



**Pseudo Code:**
```cpp
int func(vector<int>& fruits) {
	int l =0, int r = 0, int maxlen = 0
	for(i= 0->n){
		set<int> st
		for(j= i->n){
			st.add(arr[i])
			if(st.size<=2){
				maxlen = max(maxlen, j-i+1)
			}
			else break
		}
	}
	return maxlen
}
};
```
**Time Complexity :** Inner for loop -> O(n), Outer for loop -> O(n)
**Space Complexity** : Adding in set  `O(logk)` -> `O(log3)`~`O(1)` because max 3 elements
TC : `O(nxn)`
SC : `O(1)`

### <ins>2. Better </ins>


Using Map to Track the no. of specific elements


**Start:**
```
r
l
3 3 3 1 2 1 1 2 3 3 4

map = {{3,1}} size=1
maxlen = 1
```

**r++ : `(map[fruits[r]]++)`** 
```
l r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,2}} size=1
maxlen = 2
```

**r++ : `(map[fruits[r]]++)`** 
```
l   r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,3}} size = 1
maxlen = 3
```

**r++ : `(map[fruits[r]]++)`** 
```
l     r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,3}, {1,1}} size = 2
maxlen = 4
```

**r++ : `(map[fruits[r]]++)`** 
```
l       r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,3}, {1,1}, {2,1}} size = 3
```
`size >2` ->, `l++ (map[fruits[l]]--)`
```
  l     r
3 3 3 1 2 1 1 2 3 3 4
map = {{3,2}, {1,1}, {2,1}} size = 3
```
`size >2` -> `l++ (map[fruits[l]]--)`
```
    l   r
3 3 3 1 2 1 1 2 3 3 4
map = {{3,1}, {1,1}, {2,1}} size = 3>2
```
`size >2` -> `l++ (map[fruits[l]]--)`
```
also map[fruits[3]]==0 -> remove 3

      l r
3 3 3 1 2 1 1 2 3 3 4
map = {1,1}, {2,1}} size = 2
maxlen = 4
```

**r++ : `(map[fruits[r]]++)`** 
```
      l   r
3 3 3 1 2 1 1 2 3 3 4
map = {1,2}, {2,1}} size = 2
maxlen = 4
```

**r++ : `(map[fruits[r]]++)`** 
```
      l     r
3 3 3 1 2 1 1 2 3 3 4
map = {1,3}, {2,1}} size = 2
maxlen = 4
```

**r++ : `(map[fruits[r]]++)`** 
```
      l       r
3 3 3 1 2 1 1 2 3 3 4
map = {1,3}, {2,2}} size = 2
maxlen = 5
```

and so on...
```
final answer maxlen = 5
```

**C++Code:**
```cpp
int func(vector<int>& fruits) {
	int l =0; int r = 0; int maxlen = 0;
	map<int,int> mp;
	while(r<fruits.size()){
		mp[fruits[r]]++;
		while(mp.size()>2){
			mp[fruits[l]]--;
			if(mp[fruits[l]]==0) mp.erase(fruits[l]); ⭐ // erase in C++
			l++;
		}
		maxlen = max(maxlen, r-l+1);
		r++;
	}
	return maxlen;
}
};
```
**Time Complexity:** Outer while Loop  r++ (1 -> n) `O(n)`, Inner While Loop l++ (1 -> n) `O(n)`, Adding/Deletion in Map with 3 elements -> `O(log3)` ~ `O(1)`
**Space Complexity:** Max no. of element in Map -> 3 `O(3)`
TC : `O(n+n)`
SC: `O(1)`

### <ins>3. Optimal </ins>

**r++ : `(map[fruits[r]]++)`** 
```
r
l
3 3 3 1 2 1 1 2 3 3 4

map = {{3,1}} size=1
maxlen = 1
```

**r++ : `(map[fruits[r]]++)`** 
```
l r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,2}} size=1
maxlen = 2
```

**r++ : `(map[fruits[r]]++)`** 
```
l   r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,3}} size = 1
maxlen = 3
```

**r++ : `(map[fruits[r]]++)`** 
```
l     r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,3}, {1,1}} size = 2
maxlen = 4
```

**r++ : `(map[fruits[r]]++)`** 
```
l       r
3 3 3 1 2 1 1 2 3 3 4

map = {{3,3}, {1,1}, {2,1}} size = 3
maxlen = 4
```

`size>2` -> shift window  **l++ `(map[fruits[l]]--)`**, **r++ `(map[fruits[r]]++)`**
```
  l     r       
3 3 3 1 2 1 1 2 3 3 4
map = {{3,2}, {1,1}, {2,1}} size = 3
```
`size>2` -> shift window  **l++ `(map[fruits[l]]--)`**, **r++ `(map[fruits[r]]++)
```
    l     r
3 3 3 1 2 1 1 2 3 3 4
map = {{3,1}, {1,2}, {2,1}} size = 3
```
`size>2` -> shift window  **l++ `(map[fruits[l]]--)`**, **r++ `(map[fruits[r]]++)
```
map[fruits[3]]==0 -> remove 3
      l     r
3 3 3 1 2 1 1 2 3 3 4
map = {{1,1}, {2,1}} size = 2
```

**r++ : `(map[fruits[r]]++)`** 
```
      l       r
3 3 3 1 2 1 1 2 3 3 4
map = {{3,1}, {1,2}, {2,2}} size = 3>2
```

and so on...
```
final answer maxlen = 5
```

**C++Code:**
```cpp
int func(vector<int>& fruits) {
	int l =0; int r = 0; int maxlen = 0;
	map<int,int> mp;
	while(r<fruits.size()){
		mp[fruits[r]]++;
		if(mp.size()>2){ // while -> if
			mp[fruits[l]]--;
			if(mp[fruits[l]]==0) mp.erase(fruits[l]);
			l++;
		}
		if(mp.size()<=2) maxlen = max(maxlen, r-l+1);
		r++;
	}
	return maxlen;
}
};
```
**Time Complexity:** While loop (1->n) `O(n)`
TC : `O(n)`
SC: `O(1)`

# [L6. Longest Substring With At Most K Distinct Characters | 2 Pointers and Sliding Window Playlist](https://youtu.be/teM9ZsVRQyc)

⭐ Same as above. 
just String and Variable `k` instead of Array and constant `2`.
### **Ques.** Longest Substring With At Most K Distinct.

### 1.<ins>Brute Force</ins>

**Pseudo Code:**
```cpp
func(s,k){
	maxlen = 0, mp<char,int>
	for(i=0 -> n){
		mp.clear()
		for(j=i ->n){
			mp[s[j]]++
			if(mp.size()<=k){
				maxlen = max(maxlen, j-i+l)
			}
			else break
		}
	}
}
```
**Time Complexity:** Outer-Inner for loop - `O(nx2)`, At worst case, `k` >=256 and so map can store `256` characters `O(log256)`  (considering map take logarithm of time)
TC : `O(n^2)` x `O(256)`
SC : `O(256)`

### 2.<ins>Better</ins>

**Pseudo Code:**
```cpp
func(s,k){
	maxlen = 0, l=0, r=0, mp<char,int>
	while(r<s.size()){
		mp[s[r]]++;
		while(mp.size()>k){
			mp[s[l]]--;
			if(hash[s[l]]==0) mp.erase(mp[s[l]])
			l++
		}
		maxlen=max(maxlen, r-l+1)
		r++
	}
	return maxlen
}
```
TC : `O(n+n)` + `O(log256)`
SC : `O(256)`
### 3.<ins>Optimal</ins>

**Pseudo Code:**
```cpp
func(s,k){
	maxlen = 0, l=0, r=0, mp<char,int>
	while(r<s.size()){
		mp[s[r]]++;
		if(mp.size()>k){ // while -> if
			mp[s[l]]--;
			if(hash[s[l]]==0) mp.erase(mp[s[l]])
			l++
		}
		if(mp.size()<=k) maxlen=max(maxlen, r-l+1)
		r++
	}
	return maxlen
}
```
TC : `O(n)` + `O(log256)`
SC : `O(256)`

---
# [L7. Number of Substrings Containing All Three Characters | 2 Pointers and Sliding Window Playlist](https://youtu.be/xtqN4qlgr8s?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

```
s = bbacba
```
### 1 <ins>Brute Force</ins>

> Try out all the substrings 

`i=0`
```
______ -> bbacba +1
_____  -> bbacb  +1
____   -> bbac   +1
___    -> bba ❌
__     -> bb ❌
_      -> b ❌
bbacba
012345

no. of substring = 3
```

`i=1`
```
 _____ -> bacba +1
 ____  -> bacb  +1
 ___   -> bac   +1
 __    -> ba ❌
 _     -> b ❌
bbacba
012345

no. of substring = 3
```

`i=2`
```
  ____ -> acba +1
  ___  -> acb  +1
  __   -> ac ❌
  _    -> a ❌
bbacba
012345

no. of substring = 2
```

`i=3`
```
   ___ -> cba +1
   __  -> cb ❌
   _   -> c ❌
bbacba
012345

no. of substring = 1
```

`i=4`
```
    __  -> ba ❌
    _   -> b ❌
bbacba
012345

no. of substring = 0
```

`i=5`
```
     _   -> a ❌
bbacba
012345

no. of substring = 0
```

```
Total no. of Substring = 3 + 3 + 2 + 1 + 0 + 0 = 9
```



**C++ Code**
```cpp
int func(string s) {
    int n = s.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        int hash[3] = {0}; // track a, b, c
        for (int j = i; j < n; j++) {
            hash[s[j] - 'a'] = 1;
            if (hash[0] + hash[1] + hash[2] == 3)
                cnt++;
        }
    }
    return cnt;
}
```
TC: `O(N^2)`
SC: `O(3)` ~ `O(1)`


**Note:** `hash[s[j] - 'a'] = 1` marks the presence of that character.
- `'a' - 'a' = 0` → `hash[0]`
- `'b' - 'a' = 1` → `hash[1]`
- `'c' - 'a' = 2` → `hash[2]`
### 2 <ins>Better</ins> (only for non-worst case)

- Why to Wase time in Checking substrings superset, if it a smallest substring is valid one.
- if a substring  `i->j` is contain all three characters, than the substrings `i->(j+1)`, `i->(j+2)` , .... upto `i->n`, will also contain all three characters
- so. if `i->j` is valid than  there will be `n-j-1` more such substrings that would be valid.
- i.e. total = `1` +` n-j-1` = `n-j` substrings

`i=0`
```
j=3	____   -> bbac   +(1x3)          i.e. 1x(6-3) = 1x(n-j)
j=2	___    -> bba ❌ 
j=1	__     -> bb ❌
j=0	_      -> b ❌  
	bbacba
	012345

no. of substring = 3
```

`i=1`
```
j=3	 ___   -> bac   + (1x3)           i.e 1x(6-3) = 1x(n-j)
j=2	 __    -> ba ❌
j=1	 _     -> b ❌
	bbacba
	012345
	
	no. of substring = 3
```

`i=2`
```
j=4	  ___  -> acb  + (1x2)            i.e. 1x(6-4) = 1x(n-j)
j=3	  __   -> ac ❌
j=2	  _    -> a ❌
	bbacba
	012345

no. of substring = 2
```

`i=3`
```
j=5	   ___ -> cba + (1x1)            i.e. 1x(6-5) = 1(n-j)
j=4	   __  -> cb ❌
j=3	   _   -> c ❌
	bbacba
	012345

no. of substring = 1
```

`i=4`
```
    __  -> ba ❌
    _   -> b ❌
bbacba
012345

no. of substring = 0
```

`i=5`
```
     _   -> a ❌
bbacba
012345

no. of substring = 0
```

```
Total no. of Substring = 3 + 3 + 2 + 1 + 0 + 0 = 9
```

```cpp
int func(string s) {
    int n = s.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        int hash[3] = {0}; // track a, b, c
        for (int j = i; j < n; j++) {
            hash[s[j] - 'a'] = 1;
            if (hash[0] + hash[1] + hash[2] == 3){
	            cnt += n-j; // Consider current + all next substrings
	            break;
            }    
        }
    }
    return cnt;
}
```
**Time Complexity :** **practical optimization** reducing the number of inner loop iterations. 
- Worst-case: O(n²) (if the condition is never satisfied early).
- Best/average-case: Much faster due to early breaks → **closer to O(n)**.

TC : `O(n^2)`
SC : `O(1)`
### 3 <ins>Optimal</ins> ⭐ 


> With every character, there is a substring that ends.

Keep Track of Last Seen Index of each type of character ⭐

Left Pointer -> Minimum Index from last seen characters
Right Pointer (`i`) -> Maximum index from last seen characters

Minimal Window = `S[Left-Pinter : Right-Pointer]`

Start:
```
bbacba
012345

a = -1 --> last seen index of 'a'
b = -1 --> last seen index of 'b'
c = -1 --> last seen index of 'c'
```

`i=0`
```
_
bbacba
012345

a = -1 
b =  0  <-i
c = -1 
```

`i=1`
```
__
bbacba
012345

a = -1 
b = 1  <-i
c = -1 

0 substring
```

`i=2`
```
___
bbacba
012345

a = 2 <-i
b = 1 
c = -1 

0 substring
```

`i=3`
```
____
bbacba
012345

a = 2 
b = 1 
c = 3 <- i  

All a,b and c appeared

left most index is of `b` at 1 
right most index is of `c` at 3

minimal substring that contain all three characters is s[1:3] = bac (ending at c)

Total substring that contain all characters ending with `c` at 3
	s[1:3], s[0:3] -> 1+1 = 2 substring
```

`i=4`
```
_____
bbacba
012345

a = 2 
b = 4 <-i 
c = 3

All a,b and c appeared

left most index is of `a` at 2 
right most index is of `b` at 4

minimal substring that contain all three characters is s[2:4] = acb (ending at b)

Total substring that contain all characters and ending with `b` at 4
	s[2:4], s[1:4], s[0:4] -> 1+1+1 = 3 substring
```

`i=5`
```
_____
bbacba
012345

a = 5 <-i 
b = 4 
c = 3

All a,b and c appeared

left most index is of `c` at 3 
right most index is of `a` at 5

minimal substring that contain all three characters is s[3:5] = cba (ending at a)

Total substring that contain all characters and ending with `a` at 5
	s[3:5], s[2:5], s[1:5], s[0:5] -> 1+1+1+1 = 4 substring
```

```
Total Substring with all three characters = 4+3+2 = 9
```

- `lastseen[x]` keeps the latest index where `'a'`, `'b'`, `'c'` appeared.
- Once all three characters have been seen at least once, the number of valid substrings ending at index `i` is: `1 + min(lastseen[0], lastseen[1], lastseen[2])` Because any starting index from `0` to `min(lastseen)` forms a valid substring.
    
**C++ Code:** ⭐
```cpp
int func(string s) {
    int lastseen[3] = {-1, -1, -1}; // last index of 'a', 'b', 'c'
    int cnt = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        lastseen[s[i] - 'a'] = i; // update last seen index
        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
            cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
        }
    }
    return cnt;
}
```
TC: `O(n)`
SC: `O(1)`

**Note:** We can skip the `if` condition contains, `cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});` because
If any of `lastseen[x] == -1`, then `min(...) = -1`
→ `cnt += 1 + (-1) = 0`
→ No effect on `cnt`
So even without the if condition, the line is safe and correct.

---

# [L8. Longest Repeating Character Replacement | 2 Pointers and Sliding Window Playlist](https://youtu.be/_eNhaDCr6P0?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

### 1.<ins>Brute Force</ins>

### 2.<ins>Better</ins>

### 3.<ins>Optimal</ins>

---

# [L9. Binary Subarrays With Sum | 2 Pointers and Sliding Window Playlist](https://youtu.be/XnMdNUkX6VM?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

### 1.<ins>Brute Force</ins>

### 2.<ins>Better</ins>

### 3.<ins>Optimal</ins>

---
# [L10. Count number of Nice subarrays | 2 Pointers and Sliding Window Playlist](https://youtu.be/j_QOv9OT9Og?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

### 1.<ins>Brute Force</ins>

### 2.<ins>Better</ins>

### 3.<ins>Optimal</ins>

---
# [L11. Subarray with k different integers | 2 Pointers and Sliding Window Playlist](https://youtu.be/7wYGbV_LsX4?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

### 1.<ins>Brute Force</ins>

### 2.<ins>Better</ins>

### 3.<ins>Optimal</ins>

---
# [L12. Minimum Window Substring | 2 Pointers and Sliding Window Playlist](https://youtu.be/WJaij9ffOIY?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)


### 1.<ins>Brute Force</ins>

### 2.<ins>Better</ins>

### 3.<ins>Optimal</ins>
