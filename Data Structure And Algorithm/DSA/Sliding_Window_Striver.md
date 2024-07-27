# 1. Sliding Window / 2 Pointer  🥃

# [L1. Introduction to Sliding Window and 2 Pointers | Templates | Patterns](https://youtu.be/9kdHxplyl5I?list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

## 1. Constant Window

int two pointer `length =  r-l+1` wher l and r , left and right pointer respectively 
>**Ques.** Find the Maximum sum obtain by using `k` length subarray of `arr`.

[-1, 2, 3, 4, 5, -1] k=4

```cpp
l=0, r=k-1 //start from first k element
sum = 7 //sum of first k element
while( r < n-1 ){
    sum = sum - arr[l]
    l++
    r++
    sum = sum + arr[r]
    maxSum = max(maxSum,sum)
}

```

## 2. Longest Subarray/Substring where `(Condition)` 
⭐Important

> **Ques.** Find the `length` of Longest Subarray with `sum <= K`

arr = [2,5,1,7,10] k = 14

>Brute Force
```cpp

for( i=0 -> n-1){
    sum = 0
    for( j=i -> n-1){
        sum = sum + arr[j]
        if( sum<=k ){
            maxLen = max(maxLen, j- i + 1) //length from i to j => j-i+1
        }
        
        else if (sum > k) break
    }
}
```
- `TC:O(n^2)` 
- `SC:O(1)`

>Better 

Implement using 2 Pointer/Sliding Window

1. Expand -> r
2. Shrink -> l

```cpp
l = 0 , r = 0, sum = 0
while( r < n ){
    sum = sum + arr[r]
    while(sum > k){
        sum = sum - arr[l]
        l = l+1
    }
    if(sum <= k){
        maxLen = max(maxLen, r-l+1) // if you are asked to print the subarray, than store this l & r
        r = r+1
        
    }
}
```
Time complexity: Overall `l` can go upto n by shrinking the lenght (l++), `r` can go upto `n` through by expanding the length (r++)
note: length = r-l+1
- `TC:O(n+n)`
- `TC:O(1)`

>Optimal

don't shrink the window beyond current maxLen 


this work only if to find length not to find the Subarray.

If you are asked to find longest subarray with max Sum <= k, than you should go with the previous approach.

**Update:** `while(sum > k)` to `if(sum > k)`:
Shrink the window from left side only once, because there is need to make the window size less than the current max Length


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


# [L2. Maximum Points You Can Obtain from Cards | 2 Pointers and Sliding Window Playlist](https://youtu.be/pBWCOCS636U)
>**Ques.** Find maximum score you can obtain by taking exactly `k` elements from `nums`

[1,2,3,4,5,6,1], k = 3

>Brute Force by me

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

```
Time Complexity: While loop : O(k+1) + for loop1 : O(k) + for loop2 : O(k)
TC: (k+1)(k+k) => 2K^2 + 2K

- `TC:O(k^2)` 
- `SC:O(1)`

>Optimal

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
Time Complexit: for loop 1 + for loop 2 = k+k

`TC:O(2K)` `SC:O(1)`


# [L3. Longest Substring Without Repeating Characters](https://youtu.be/-zSxTJkcdAo)

## Brute foce to generate all Substrings
s = "cadbzabcd"
```cpp
for( i= 0 -> n-1){
    sub = " "
    for( j = i -> n-1 ){
        sub = sub + s[j]
    }
}
```
note: outer for loop (0->n) *n... times -> TC:O(n)

inner for loo (i->n)  average *n/2... times -> TC:O(n/2)

`TC:O(n)` `SC:O(n)`

> Ques. Given a string `s`, find the length of the longest substring without repeating characters.

"cadbzab" 

> Brute Force

Create mp<int,int> and assign s[0] to s[255]

Ascii Value (A-Z): 65-90, (a-z): 97-122, (0-9): 48-57

int val = 'a'   note:- ascii value is assigned
Total characters = 256 (0 to 255) 

ex: - mp[s[0]] => mp['a'] => mp[65]

```cpp
        maxLen =0
        unordered_map <int,int> mp
        for(i=0 -> n-1 ){ //n length of string
            
            for(a= 0 -> 255) mp[a]=0

            for( j = i -> n-1){
                if(mp[s[j]]==1) break
                maxLen = max(maxLen, j-i+1)
                mp[s[j]]=1
            }
        }
        return maxLen
    }
```
`TC:O(n^2)` `TS:O(256)`

> better

note: there are two option to check if a key exist in map or not
1. ```cpp
    if (charMap.find(key) != charMap.end())
    // true: key exists in the map
    ```

2. ```cpp
    if(charMap[key] > 0)
    // true : key exist
    ```
    this one is used in algorithm

note: When you access a key that does not exist in the map, it will insert that key with a default-constructed value of the value type.

For an unordered_map<char, int>, the default-constructed value of int is 0.

but in algorithm there is a condition `if(myMap[key]>=l)` and `l` is initially '0' and non existing key in map is also '0'. so if will executed wrongly

so  we will take `int` as key of hashmap and f will initialise all the 256 character key to -1;

```cpp
        n=s.size()
        l=0 r=0 maxLen =0
        unordered_map <int,int> myMap
        for(i=0 -> 256 ){
            myMap[i]=-1
        }
        while(r<n){
            if(myMap[s[r]] >= l){
                l = myMap[s[r]]+1
            }
            maxlen = max(maxLen, r-l+1)
            myMap[s[r]]=r
            r++
        }
        return maxLen
```
TC: only while loop i.e *n times... contributed to Time complexity

`TC:O(n)` `SC:O(256)`