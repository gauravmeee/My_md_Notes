
# [DP 5. Maximum Sum of Non-Adjacent Elements | House Robber | 1-D | DP on Subsequences](https://youtu.be/GrMBfJNk_NY?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY)

 -> pick the one with the maximum sum -> try  all subsequences -> recursion -> pick or not pick


```
if(i == n) maxx = max(maxx, sum)

f(i+2, arr, sum+arr[i+2])
f(i+3, arr, sum+arr[i+3])
```
### Recursion
TC O(2^n)
O(n)

### Memorization
O(n)
O(n) + O(n)

### Tabulation

### Best 

