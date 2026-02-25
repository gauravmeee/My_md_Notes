---
description: From Striver's Tutorial ▶️
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

# Algorithm: Sliding Window ⏳

## Sliding Window / 2 Pointer

**Substring:** Continuous character elements (no skip)

* Method: Two loops (start and end pointers) or sliding window.
* Example: `"abc"` → `"ab", "bc"`

**Subarray:** Continuous integer elements (no skip)

* Method: Two loops (start and end pointers) or sliding window.
* Example: `[1,2,3]` → `[1,2], [2,3]`

***

## [L1. Introduction to Sliding Window and 2 Pointers | Templates | Patterns](https://youtu.be/9kdHxplyl5I?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

## **Pattern 1 :** Constant Window

> Use two pointers `l` and `r` with fixed window size `k`.\
> Window length is `k = r - l + 1`\
> To maintain constant window: `r = (k - 1) + l`

#### **Ques.** Find the Maximum sum obtain by using `k` length subarray of `arr`.

```
Input:
arr = [-1, 2, 3, 4, 5, -1] 
k = 4
```

* `length(k) = r-l+1`
* `r` -> `(k-1)+l` = `3 + l` ⭐

**Start `l=0`**

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

* So, Maximum Sum = `max(8,14,11)`

**End**

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

## **Pattern 2 :** Longest Subarray/Substring where `(Condition)` ⭐

⭐Important

> Use two pointers `l` and `r` with **variable window size**.\
> Window length is `r - l + 1`. ⭐ Expand window by increasing `r`, and shrink from left (increase `l`) when condition breaks.

#### **Ques.** Find the `length` of Longest Subarray with `sum <= K`

```
arr = [2,5,1,7,10] 
k = 14
```

#### 1. Brute Force

> Check all subarrays, and break when sum exceeds `k`

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

* `TC:O(n^2)`
* `SC:O(1)`

#### 2. Better (Sliding Window)

> Two Pointer Technique with Shrinking from Left

* Expand → `r++`
* Shrink → `l++` when `sum > k`
* Window length = `r - l + 1`
* Maintain `maxLen`

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

Time complexity: `l` can go up to `n` by shrinking the window (`l++`) Worst Case. `r` can go up to `n` by expanding the window (`r++`) in Worst case. So total time: `O(n + n)`

* `TC:O(n+n)`
* `TC:O(1)`

**Note:**

* Window length = `r - l + 1`
* Maintain max length using `maxLen = max(maxLen, r - l + 1)`

#### 3. Optimal ⭐

> Avoid shrinking more than once to save time (Why to shrink more than the current longest answer) ⭐

* Only shrink once using `if(sum > k)`
* Best for length only, not subarray

If you're asked to **find the actual longest subarray with sum ≤ k**, use the **previous (Better)** approach with `while(sum > k)`.

**Update:**

* Use `if(sum > k)` instead of `while(sum > k)`
* Shrink the window from left **only once** to **avoid reducing current valid window below max length**. Because it would no use to shrink, more than the possible answer.

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

* `TC:O(n)`
* `TC:O(1)`

**Note:**

* Use this only when finding the **length** of longest subarray, or to print any longest subarray.
* If asked for specific subarray like or based on some condition like - Longest Length of the subarray with maximum `sum` (with `sum <= k` ), It would not work. Use previous method (`while(sum > k)`).

## **Pattern 3 :** No. of Subarrays where (Condition)

* Solved using Pattern 2
* It is very difficult to count to calculate no. of subarray
* **Example** Find the No. of Subarrays with `sum = k`
* when there is some constant condition like `sum = k`, it is verry tough to understand when to **Expand** and when to **Shrink**.

**Breaking down Problem**

```
No. of subarrays where sum <=k --> x
No. of subarrays where sum <= (k-1) --> y

x-y --> No. of subarray with (sum = k)
```

❓ why can't it solved directly using shrink and expand

## **Pattern 4 :** Shortest/Minimum Window (Condition)

* Same as **Pattern 2**
* Find a valid Window, Then shrink it till it valid

***

## [L2. Maximum Points You Can Obtain from Cards | 2 Pointers and Sliding Window Playlist](https://youtu.be/pBWCOCS636U)

#### **Ques.** Find maximum score you can obtain by taking exactly `k` elements from `nums`.

(Condition : You can pick card only from either left and right consecutively i.e. You can't go and pick element from middle.)

```
Input:
arr = [6, 2, 3, 4, 7, 2, 1, 7, 1]
k = 4
```

1. l`-> 4 element ,`r\` -> 0 element

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

#### 1. Brute Force (by me)

**C++ Code**

```cpp
func( nums[], k) {
   l=k , r= n //n : nums.size
   lsum =0 , rsum =0, maxSum=0
   t=k+1; // need to iterate k+1 time
	while(t--){
		lsum=0; //reset
		for(int i = 0; i < l; i++){ // re calculate for each while loop
			lsum+=nums[i]
		}

		rsum =0; //reset
		for(int j=r; j<n; j++){ // re calculate for each while loop
			rsum+=nums[j]
		}

		maxSum = max(maxSum, lsum+rsum);
		l-- , r--
	}
}
```

**Time Complexity:** While loop : O(k+1) + for loop1 : O(k) + for loop2 : O(k) TC: (k+1)(k+k) => 2K^2 + 2K

* `TC:O(k^2)`
* `SC:O(1)`

#### 2. Optimal

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

    for( int l=k-1; l>=0 ; l--){ //left Index
        lsum = lsum - nums[l]
        rsum = rsum +  nums[r]
        r = r-1
        maxSum = max(maxSum, lsum+rsum)
    }
    return maxSum
}
```

**Time Complexity:** for loop 1 + for loop 2 = `O(k+k)`

`TC:O(2K)` `SC:O(1)`

***

## [L3. Longest Substring Without Repeating Characters](https://youtu.be/-zSxTJkcdAo)

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

* Outer for loop (0->n) `*n...` times -> `TC:O(n)`
* inner for loo (i->n) average `*n/2...` times -> `TC:O(n/2)` `TC:O(n)` `SC:O(n)`

#### **Ques.** Given a string `s`, find the length of the longest substring without repeating characters.

```
Input:
s = cadbzabcd
```

#### 1. Brute Force

> Use Brute force to Generate All substring

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

* There are total `256` Characters
* We could use Hashing Technique `[0 to 255]` to keep tract which Ascii character is Previously seen.
* So, we could move forward outer loop (`i++`), whenever something repeating. Because it if something repeating for `i` & `j` then it will repeat for all `j` greater than current `i` for the given `i`

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

**Time Complexity:** only while loop i.e `*n` times... contributed to Time complexity TC: `O(n^n)` SC: `O(256)` \~ `O(1)`

#### 2. Better Approach

> Store elements index, and Move `l` directly to next of the last repeating element.

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

\*\*Similarly r++

**When : `r=5`** ---> When `a` is repeating

```
0 1 2 3 4 5 6 7 8 
c a d b z a b c d
^         ^
l         r

map[s[r]] = 1 -> `a` is already occuring at index 1

l <= map[a]=1 <= r 
```

**`l=map[a]+1` :** `l=2` and `r=5` (Move `l` to next of the repeating element.)

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

**`l=map[a]+1` :** `l=4` and `r=6` (Move `l` to next of the repeating element.))

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

**Time Complexity:** While loop `r++` for every `n` element, and `l` not contributing it TC : `O(n)` SC : `O(256)`

***

## [L4. Max Consecutive Ones III | 2 Pointers and Sliding Window Playlist](https://youtu.be/3E4JBHSLpYk)

#### **Ques.** Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`_'s in the array if you can flip at most_ `k` `0`'s.

> Break Down Problem into -> Longest subarray with at most `k` zeros

```
Input
nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
k = 2
```

#### 1. Brute Force

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

**Time Complexity :** Inner for loop -> O(n), Outer for loop -> O(n) TC : `O(n^2)` SC : `O(1)`

#### 2. Better

Why to reset `l`to 0->1->2... `for every outer loop`r\` !

> Use a window `[l..r]` that always contains **at most `k` zeros**\
> Expand `r`, and **shrink `l` only when zeros exceed k**

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

**Time Complexity :** `l` can move from `0` to `n-1`, and `r` can move from `0` to `n-1` TC : O(2n) SC : O(1)

#### 3. Optimal

Why to shrink subarray more than the current longest answer ! Shrinking more will always small and can never be the answer. so at this time, just shift the window `l++` & `r++` to right

> Avoid shrinking more than once to save time i.e. avoid `while()` loop to `l++` — just `if(zeros > k) to l++` Saves redundant checks. **Only shrink once per violation**⭐

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

**Time Complexity :** `r` can move from `0` to `n-1` i.e. `O(n)` TC : `O(n)` SC : `O(1)`

***

## [L5. Fruit Into Baskets | 2 Pointers and Sliding Window Playlist](https://youtu.be/e3bs0uA1NhQ)

#### **Ques.** Given an array `fruits[]`, find the maximum number of fruits you can pick from a continuous subarray containing at most two distinct fruit types.

```
Input:
arr = [3 3 3 1 2 1 1 2 3 3 4]
```

Break Down the Problem -> Max Length subarray with at most 2 types of numbers.

#### 1. Brute Force

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

**Time Complexity :** Inner for loop -> O(n), Outer for loop -> O(n) **Space Complexity** : Adding in set `O(logk)` -> `O(log3)`\~`O(1)` because max 3 elements TC : `O(nxn)` SC : `O(1)`

#### 2. Better

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

**Time Complexity:** Outer while Loop r++ (1 -> n) `O(n)`, Inner While Loop l++ (1 -> n) `O(n)`, Adding/Deletion in Map with 3 elements -> `O(log3)` \~ `O(1)` **Space Complexity:** Max no. of element in Map -> 3 `O(3)` TC : `O(n+n)` SC: `O(1)`

#### 3. Optimal

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

`size>2` -> shift window **l++ `(map[fruits[l]]--)`**, **r++ `(map[fruits[r]]++)`**

```
  l     r       
3 3 3 1 2 1 1 2 3 3 4
map = {{3,2}, {1,1}, {2,1}} size = 3
```

`size>2` -> shift window **l++ `(map[fruits[l]]--)`**, \*\*r++ \`(map\[fruits\[r]]++)

```
    l     r
3 3 3 1 2 1 1 2 3 3 4
map = {{3,1}, {1,2}, {2,1}} size = 3
```

`size>2` -> shift window **l++ `(map[fruits[l]]--)`**, \*\*r++ \`(map\[fruits\[r]]++)

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

**Time Complexity:** While loop (1->n) `O(n)` TC : `O(n)` SC: `O(1)`

## [L6. Longest Substring With At Most K Distinct Characters | 2 Pointers and Sliding Window Playlist](https://youtu.be/teM9ZsVRQyc)

⭐ Same as above. just String and Variable `k` instead of Array and constant `2`.

#### **Ques.** Longind the length of the longest substring of string `s` that contains at most `k` distinct characters.

#### 1.Brute Force

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

**Time Complexity:** Outer-Inner for loop - `O(nx2)`, At worst case, `k` >=256 and so map can store `256` characters `O(log256)` (considering map take logarithm of time) TC : `O(n^2)` x `O(256)` SC : `O(256)`

#### 2.Better

**Pseudo Code:**

```cpp
func(s,k){
	maxlen = 0, l=0, r=0, mp<char,int>
	while(r<s.size()){
		mp[s[r]]++;
		while(mp.size()>k){
			mp[s[l]]--;
			if(mp[s[l]]==0) mp.erase(mp[s[l]])
			l++
		}
		maxlen=max(maxlen, r-l+1)
		r++
	}
	return maxlen
}
```

TC : `O(n+n)` + `O(log256)` SC : `O(256)`

#### 3.Optimal

**Pseudo Code:**

```cpp
func(s,k){
	maxlen = 0, l=0, r=0, mp<char,int>
	while(r<s.size()){
		mp[s[r]]++;
		if(mp.size()>k){ // while -> if
			mp[s[l]]--;
			if(mp[s[l]]==0) mp.erase(mp[s[l]])
			l++
		}
		if(mp.size()<=k) maxlen=max(maxlen, r-l+1)
		r++
	}
	return maxlen
}
```

TC : `O(n)` + `O(log256)` SC : `O(256)`

***

## [L7. Number of Substrings Containing All Three Characters | 2 Pointers and Sliding Window Playlist](https://youtu.be/xtqN4qlgr8s?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

#### **Ques.** Find the number of substrings of string `s` that contain at least one occurrence of each character `'a'`, `'b'`, and `'c'`.

```
s = bbacba
```

#### 1 Brute Force

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

TC: `O(N^2)` SC: `O(3)` \~ `O(1)`

**Note:** `hash[s[j] - 'a'] = 1` marks the presence of that character.

* `'a' - 'a' = 0` → `hash[0]`
* `'b' - 'a' = 1` → `hash[1]`
* `'c' - 'a' = 2` → `hash[2]`

#### 2 Better (only for non-worst case)

* Why to Wase time in Checking substrings superset, if it a smallest substring is valid one.
* if a substring `i->j` is contain all three characters, than the substrings `i->(j+1)`, `i->(j+2)` , .... upto `i->n`, will also contain all three characters
* so. if `i->j` is valid than there will be `n-j-1` more such substrings that would be valid.
* i.e. total = `1` + `n-j-1` = `n-j` substrings

`i=0`

```
j=3	____   -> bbac   +(1x3)          i.e. (6-3) = 1x(n-j)
j=2	___    -> bba ❌ 
j=1	__     -> bb ❌
j=0	_      -> b ❌  
	bbacba
	012345

no. of substring = 3
```

`i=1`

```
j=3	 ___   -> bac   + (1x3)           i.e. (6-3) = 1x(n-j)
j=2	 __    -> ba ❌
j=1	 _     -> b ❌
	bbacba
	012345
	
no. of substring = 3
```

`i=2`

```
j=4	  ___  -> acb  + (1x2)            i.e. (6-4) = 1x(n-j)
j=3	  __   -> ac ❌
j=2	  _    -> a ❌
	bbacba
	012345

no. of substring = 2
```

`i=3`

```
j=5	   ___ -> cba + (1x1)            i.e. (6-5) = 1x(n-j)
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

* Worst-case: O(n²) (if the condition is never satisfied early).
* Best/average-case: Much faster due to early breaks → **closer to O(n)**.

TC : `O(n^2)` SC : `O(1)`

#### 3 Optimal ⭐

> With every character, there is a substring that ends.

Keep Track of Last Seen Index of each type of character ⭐

Left Pointer -> Minimum Index from last seen characters Right Pointer (`i`) -> Maximum index from last seen characters

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

* `lastseen[x]` keeps the latest index where `'a'`, `'b'`, `'c'` appeared.
* Once all three characters have been seen at least once, the number of valid substrings ending at index `i` is: `1 + min(lastseen[0], lastseen[1], lastseen[2])` Because any starting index from `0` to `min(lastseen)` forms a valid substring.

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

TC: `O(n)` SC: `O(1)`

**Note:** We can skip the `if` condition contains, `cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});` because If any of `lastseen[x] == -1`, then `min(...) = -1` → `cnt += 1 + (-1) = 0` → No effect on `cnt` So even without the if condition, the line is safe and correct.

***

## [L8. Longest Repeating Character Replacement | 2 Pointers and Sliding Window Playlist](https://youtu.be/_eNhaDCr6P0?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

#### **Ques.** Find the length of the longest substring with all same letters after at most `k` character replacements in string `s`.

#### 1 Brute Force

> Try out all the substrings

```
s = AABABBA k=2
```

`i=0` , `j=i`

```
j = 0 -> A

len (j-l+1) = 1
- most frequesnt letter = A, Max frequency = 1
- no. of letters need to Replace = size-frequency = 0 < k

Max len = 1
j++
```

```
j=1 -> AA

len (j-l+1) = 2
most frequesnt letter = A, Max frequency = 2
no. of letters need to Replace = size-frequency = 0 ≤ k

Max len = 2
j++
```

```
j =2 -> AAB

len (j-l+1) = 3
most frequesnt letter = A, Max frequency = 2
no. of letters need to Replace = size-frequency = 1 ≤ k 

Max len = 3
j++
```

```
j=3 -> AABA

len (j-l+1) = 4
most frequesnt letter = A, Max frequency = 3
no. of letters need to Replace = size-frequency = 1 ≤ k 

Max len = 4
j++
```

```
j=4 -> AABAB

len (j-l+1) = 5
most frequesnt letter = A, Max frequency = 3
no. of letters need to Replace = size-frequency = 2 ≤ k 

Max len = 5
j++
```

```
j=5 -> AABABB

len (j-l+1) = 6
most frequesnt letter = A, Max frequency = 3
no. of letters need to Replace = size-frequency = 3 not ≤ k ❗

break !!
```

`i=1` , `j=i`

```
j = 1 -> A

len (j-l+1) = 1
most frequesnt letter = A, Max frequency = 1
no. of letters need to Replace = size-frequency = 0 ≤ k

Max len = 5
j++
```

```
j = 2 -> AB

len (j-l+1) = 2
most frequesnt letter = A, Max frequency = 1
no. of letters need to Replace = size-frequency = 1 ≤ k

Max len = 5
j++
```

```
j = 3 -> ABA

len (j-l+1) = 3
most frequesnt letter = A, Max frequency = 2
no. of letters need to Replace = size-frequency = 1 ≤ k

Max len = 5
j++
```

```
j = 4 -> ABAB

len (j-l+1) = 4
most frequesnt letter = A, Max frequency = 2
no. of letters need to Replace = size-frequency = 2 ≤ k

Max len = 5
j++
```

```
j = 5 -> ABABB

len (j-l+1) = 5
most frequesnt letter = B, Max frequency = 3
no. of letters need to Replace = size-frequency = 2 ≤ k

Max len = 5
j++
```

```
j = 6 -> ABABBA

len (j-l+1) = 6
most frequesnt letter = A, Max frequency = 3
no. of letters need to Replace = size-frequency = 3 not ≤ k ❗

break!!
```

`i=2` , `j=i`

```
And so on.........
```

**ans**: `maxlen` = 5 ✅

**C++ Code**

```cpp
int func(string s) {
    int n = s.size();
    int maxlen = 0;  // maximum len i.e answer
    for (int i = 0; i < n; i++) {
        int hash[26] = {0}; // A, B, C.....Z
        int maxf = 0; // fequency of max 
        for (int j = i; j < n; j++) {
            hash[s[j] - 'A']++;
            maxf = max(maxf, hash[s[j]-'A']); // update maximum frequency
            int changes = (j-i+1) - maxf; // change required = len - max freq

			// if condition satisfy, update ans, else break
			if(changes<=k) maxlen = max(maxlen, j-i+1)
			else break;
        }
    }
    return maxlen;
}
```

TC: `O(N^2)` (For loops) SC: `O(26)` (hash map of 26 size)

#### 2.Better

> Use 2 pointers and a sliding window to shrink the window from the left when the current substring is not valid or doesn’t satisfy the condition.

```
s= AAABBCCD k=2
```

`i=0`, `j=i`

```

j=0 -> A  (A is most frequent) 
Required Change = Size - Maxf = 0  ≤ k  -> j++

Similarly...
j = 1 -> AA    (0≤k)  -> j++
j = 2 -> AAA   (0≤k)  -> j++
j = 3 -> AAAB  (1≤k)  -> j++
j = 4 -> AAABB (2≤k)  -> j++ 👈 (maximum length)
j = 5 -> AAABBC  (3 not ≤k ) ❌ -> i++
```

`i=1`

```
j = 5 -> AABBC  (3 not ≤k ) ❌ -> i++
```

`i=2`

```
j = 5 -> ABBC  (2 ≤ k )  -> j++  (Now B is most Frequent)
j = 6 -> ABBCC  (3 not ≤k ) ❌ -> i++
```

`i=2`

```
i = 3
j = 6 -> BBCC  (2 ≤ k )  -> j++
j = 7 -> BBCCD (3 not ≤k ) ❌ -> i++
```

`i=3`

```
i=3
j = 7 -> BCCD (2 ≤ k )  -> j++ (Now C is most Frequent)

(j->8) == n ✅ Done
```

**Ans:** `maxlen` = 5

**Note:**\
In **Brute Force**, we reset the frequency map (`hash[26]`) at the start of every outer loop because we start checking from a new index. So, we don’t need to maintain state across iterations.

But in the **Better Approach** (Sliding Window), there’s no fixed loop for `l++` or `r++` — movement depends on whether the current window satisfies the condition. So, we **can’t simply continue by resetting `hash[26]` to zero**. Instead, before shrinking the window (`l++`), we do `hash[s[l] - 'A']--`.\
If the removed character was contributing to `maxf`, we need to **traverse `hash[26]`** to recompute the new `maxf`.

**C++ Code**

```cpp
int func(string s, int k) {
    int l = 0, r = 0;
    int maxlen = 0, maxf = 0;
    int hash[26] = {0};

    while (r < s.size()) {
        hash[s[r] - 'A']++;
        maxf = max(maxf, hash[s[r] - 'A']);

        while ((r - l + 1) - maxf > k) {
            hash[s[l] - 'A']--, maxf = 0;
            l++;

            // Recalculate maxf only if necessary
            maxf = 0;
            for (int i = 0; i < 26; i++)
                maxf = max(maxf, hash[i]);
        }
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}
```

TC: `O(N+N) * 26` SC: `O(26)`

**Time Complexity:**

* The outer `while` loop runs `r = 0` to `n`, so **O(n)**.
* The inner `while` loop (which increments `l`) also moves `l` from `0` to `n` over time, so **O(n)** in total.
* Each time we shrink the window, we may recalculate `maxf` using a loop over 26 characters, i.e., **O(26)** ≈ **O(1)**.
* So overall time complexity = **O(n + n × 26) = O(26n) = O(n)** (since 26 is constant).

#### 3.Optimal ⭐

> We avoid shrinking repeatedly because our goal is to **maximize window length**, not minimize it.

> We **don’t recalculate `maxf`** after removing a character since reducing `maxf` makes the condition `(len - maxf) ≤ k` even harder to satisfy.

Example

```
s= AAABBCCD k=2
```

let `l=0` & `r=4`

```
AAABB___
len = 5
(len - maxf) <= k
(5 - 3)  <= 2 ✅ -> r++
```

So `l=0` & `r=5`

```
AAABBC__
(len - maxf) <= k
(6-3) not <= 2 ❌ Invalid
```

**Should we shrink?**

* No. If we shrink (`l++`), window length will reduce to `5`, which is not our goal.
* We are trying to find the **maximum length** valid window.
* So instead of shrinking repeatedly (like in brute or better),\
  → We just **slide** the window: do both `l++` and `r++`, and keep checking.

**We will not Reduce `maxf`**

* Let `l=0` & `r=5` -> `AAABBC__`
* `(6-3) not <= 2` ❌ Invalid

1. Now let’s say we **reduce** the frequency( because `A` was contributing to `maxf`)
   * `maxf--`; `maxf = 2`
   * `(6-2) not <= 2` ❌ Invalid
   * So reducing it make condition more Invalid
2. Now let’s say we try to **shrink** the window and Reduce the Frequency
   * `i++` -> `len--` -> `len=5`
   * `maxf--`, `maxf = 2`
   * `(5-2) not <= 3` ❌ Invalid
   * So reducing it make condition more Invalid

**Overall Idea** ⭐

* We don’t want to **shrink** using a `while` loop,\
  because our **goal is to grow the window** and find the **maximum possible length** with valid condition.
* We **can’t reduce `maxf`**,\
  because that may make the condition `(len - maxf) <= k` **even more invalid**.
* Instead, we **only increase `maxf`** whenever a more frequent char comes. `maxf = max(maxf, hash[s[r]-'A']);`
* Just **slide the window** (`l++`, `r++`) until the condition becomes valid again for a longer window.

**C++ Code**

```cpp
int func(string s, int k) {
    int l = 0, r = 0;
    int maxlen = 0, maxf = 0;
    int hash[26] = {0};

    while (r < s.size()) {
        hash[s[r] - 'A']++;
        maxf = max(maxf, hash[s[r] - 'A']);

        if ((r - l + 1) - maxf > k) {
            hash[s[l] - 'A']--;
            l++;
        }

        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}
```

TC: `O(N)` SC: `O(26)`

***

## [L9. Binary Subarrays With Sum | 2 Pointers and Sliding Window Playlist](https://youtu.be/XnMdNUkX6VM?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

```
nums = {1, 0, 0, 1, 1, 0} goal=2
```

#### 1.Brute Force

> Generate all possible subarrays and check if sum equals goal.

**C++ Code:**

```cpp
int countSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size(), cnt = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[j];
            if(sum == goal) cnt++;
        }
    }
    return cnt;
}
```

**TC**: `O(N^2)`\
**SC**: `O(1)`

#### 2.Better (Prefix Sum + HashMap) ⭐

> Maintain a prefix sum and count how many times `prefix_sum - goal` has occurred using hashmap.

#### Step-by-step:

We are given:\
`nums = {1, 0, 0, 1, 1, 0}`\
`goal = 2`

Initialize: `unordered_map<int, int> mp`

```
sum = 0
cnt = 0;
mp[0] = 1
```

**Index = 0**:

```
num = 1  
sum = sum + 1 = 1  
sum - goal = 1 - 2 = -1 → not in mp  
So, cnt = 0  
Update mp[1] = 1
```

**Index = 1**:

```
num = 0  
sum = 1 + 0 = 1  
sum - goal = -1 → not in mp  
So, cnt = 0  
Update mp[1] = 2
```

**Index = 2**:

```
num = 0  
sum = 1 + 0 = 1  
sum - goal = -1 → still not in mp  
So, cnt = 0  
Update mp[1] = 3
```

**Index = 3**:

```
num = 1  
sum = 1 + 1 = 2  
sum - goal = 2 - 2 = 0 → mp[0] = 1  
So, cnt += 1 → cnt = 1  
Update mp[2] = 1
```

**Index= 4**:

```
num = 1  
sum = 2 + 1 = 3  
sum - goal = 3 - 2 = 1 → mp[1] = 3  
So, cnt += 3 → cnt = 4  
Update mp[3] = 1
```

**Index = 5**:

```
num = 0  
sum = 3 + 0 = 3  
sum - goal = 3 - 2 = 1 → mp[1] = 3  
So, cnt += 3 → cnt = 7  
Update mp[3] = 2
```

**Final Answer: 7**

**Subarrays that sum to `2`:** `[1, 0, 0, 1]`, `[0, 0, 1, 1]`, `[0, 1, 1]`, `[1, 1]`, `[1, 0, 0, 1, 1]`, `[0, 0, 1, 1, 0]`, `[0, 1, 1, 0]`

Each time the prefix sum difference `sum - goal` has occurred, we add how many times it occurred to the answer.

**C++ Code:** ⭐

```cpp
int countSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> mp;
    int sum = 0, cnt = 0;
    mp[0] = 1; // base case for sum == goal

    for(int num : nums) {
        sum += num;
        if(mp.count(sum - goal)) cnt += mp[sum - goal];
        mp[sum]++;
    }
    return cnt;
}
```

**TC**: `O(N)`\
**SC**: `O(N)`

#### 3.Optimal (Sliding Window / Two Pointers) ⭐

> Use two calls to a function `atMost(nums, goal)` to calculate exact subarrays with sum = goal.

Given that the input array is binary (contains only 1s and 0s), it's possible to further optimise the solution from the O(N) time and O(N) space hashing approach. The aim is to achieve **O(N) time complexity and O(1) space complexity** by getting rid of external data structures like the hash map. This suggests using a two-pointer or sliding window algorithm.

**Initial Attempt and Challenge:**

* A standard two-pointer/sliding window approach typically involves finding the longest subarray or substring. When attempting to count subarrays with an _exact_ sum (`sum == goal`), a direct application of two pointers faces a dilemma. The challenge arises because **zeros do not affect the sum**. If the sum exceeds the goal and you need to shrink the window from the left, removing a zero from the left end does not decrease the sum, making it difficult to decide whether to move the left or right pointer to find _all_ valid subarrays.
* If `nums[i] = 0`, then moving `i++` doesn't reduce the sum.
* But if `nums[j]++`, the sum might increase, which can go beyond the goal.
* So, you face a **dilemma: whether to move `i++` or `j++`** to adjust the window.
* Zeros **do not change the sum**, so the window **gets stuck** and fails to explore all valid subarrays.

**The Key Insight: Solving for "Sum Lesser Than or Equal to Goal"**

* To overcome this challenge, the optimal approach involves a clever mathematical trick: The number of subarrays with sum **equal to** `goal` can be found by: **`countSubarraysWithSum(nums, goal) = atMostGoal(nums, goal) - atMostGoal(nums, goal - 1)`**.
* Here, `atMostGoal(nums, k)` is a function that computes the number of subarrays where the sum is **less than or equal to `k`**.

**Algorithm for `atMostGoal(nums, goal)`:**

This function uses a sliding window approach with two pointers, `L` (left) and `R` (right), along with a `current_sum` and a `count` for the valid subarrays.

We are given:\
`nums = {1, 0, 1, 1, 0}`\
`goal = 2`

**1. Let Find No. of Subarrays for `sum` <= 2**

* **Initial**:

```
L = 0
R = 0
sum = 0
count = 0
```

`L=0`

`R = 0`

```
1___
sum = 0 + 1 = 1. sum (1) <= goal (2)
count += (R - L + 1) = (0 - 0 + 1) = 1 → count = 1
R++
```

`R = 1`

```
10___

sum = 1 + 0 = 1. sum (1) <= goal (2)
count += (R - L + 1) = (1 - 0 + 1) = 2 → count = 3
R++
```

`R = 2`

```
101__

sum = 1 + 1 = 2. sum (2) <= goal (2)
count += (R - L + 1) = (2 - 0 + 1) = 3 → count = 6
R++
```

`R = 3`

```
1011_

sum = 2 + 1 = 3. sum (3) > goal (2)
 Shrink window:
   sum = 3 - nums[L = 0] = 2
   L++
```

`R=3` & `L=1`

```
_011_

sum (2) <= goal (2)
count += (R - L + 1) = (3 - 1 + 1) = 3 → count = 9
R++
```

`R = 4`

```
_0110

sum = 2 + 0 = 2. sum (2) <= goal (2)
count += (R - L + 1) = (4 - 1 + 1) = 4 → count = 13
R++ (out of bounds)
```

`R=5` -> (out of bounds) Stop! -> **No. of Subarrays with `sum`<=2 : `count = 13`**

**2. Let Find No. of Subarrays for `sum` <= 1**

* **Initial**:

```
L = 0
R = 0
sum = 0
count = 0
```

`L=0`

`R = 0`

```
1____
sum = 0 + 1 = 1. sum (1) <= goal (1)
count += (R - L + 1) = (0 - 0 + 1) = 1 → count = 1
R++
```

`R = 1`

```
10___

sum = 1 + 0 = 1. sum (1) <= goal (1)
count += (R - L + 1) = (1 - 0 + 1) = 2 → count = 3
R++
```

`R = 2`

```
101__

sum = 1 + 1 = 2. sum (2) > goal (1)
 Shrink window
 Sum = 2 - nums[L=0] = 1
 L++
```

`R = 2` & `L=1`

```
_01__

sum = 0 + 1 = 1. sum (1) <= goal (1)
count += (R - L + 1) = (2 - 1 + 1) = 2 → count = 5
R++
```

`R = 3`

```
_011_

sum = 1 + 1 = 2. sum (2) > goal (1)
 Shrink window
 Sum = 2 - nums[L=0] = 2
 L++
```

`R = 3` & `L=2`

```
__11_

sum = 1 + 1 = 2. sum (2) > goal (1)
 Shrink window
 Sum = 2 - nums[L=0] = 1
 L++
```

`R=3` & `L=3`

```
___1_

sum (1) <= goal (1)
count += (R - L + 1) = (3 - 1 + 1) = 3 → count = 6
R++
```

`R = 4`

```
___10

sum = 1 + 0 = 1. sum (1) <= goal (1)
count += (R - L + 1) = (4 - 1 + 1) = 4 → count = 8
R++ (out of bounds)
```

`R=5` -> (out of bounds) Stop! -> \*\*No. of Subarrays with `sum`<=1 : `count = 8`

**Final Answer** 13 - 8 = 5 (No. of subarrays with `sum` == 2)

**C++ Code:**

```cpp
int atMost(vector<int>& nums, int goal) {
    if(goal < 0) return 0; // sum can't be negative in binary array

    int l = 0, r = 0, sum = 0, cnt = 0;
    for(r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while(sum > goal) {
            sum -= nums[l++];
        }
        cnt += (r - l + 1);
    }
    return cnt;
}

int countSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}
```

**TC**: `O(4N)` \~ `O(N)`\
**SC**: `O(1)`

* **Time Complexity**: The `atMostGoal` function has a **time complexity of O(N)**. Both the left (`L`) and right (`R`) pointers traverse the array at most once. So `O(N +N)` for single call of `atMostGoal`
* Since the overall solution calls this function twice (`atMostGoal(goal)` and `atMostGoal(goal - 1)`), the total time complexity will be **O(2(N+N))**.

***

## [L10. Count number of Nice subarrays | 2 Pointers and Sliding Window Playlist](https://youtu.be/j_QOv9OT9Og?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

#### 1.Brute Force

#### 2.Better

#### 3.Optimal

***

## [L11. Subarray with k different integers | 2 Pointers and Sliding Window Playlist](https://youtu.be/7wYGbV_LsX4?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

#### 1.Brute Force

#### 2.Better

#### 3.Optimal

***

## [L12. Minimum Window Substring | 2 Pointers and Sliding Window Playlist](https://youtu.be/WJaij9ffOIY?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

#### 1.Brute Force

#### 2.Better

#### 3.Optimal
