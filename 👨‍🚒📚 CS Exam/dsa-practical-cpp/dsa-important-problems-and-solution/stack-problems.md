---
description: Made by Me 💚
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

# Stack Problems

## [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/description/)

By Me : )

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> num(nums1.size(),0);
	
	// map -> key=nums2[i] : value=next Greater element of nums2[i]
	unordered_map<int,int> mp;
	
	stack <int> st;

	// Traverse nums2 , and finde `Next Greater Element` using Stack
	for(int i=nums2.size()-1; i>=0; i--){

		// If st.top() smaller, pop and check for next top element until find some greater
		while(!st.empty() && st.top()<=nums2[i]){
			st.pop();
		}
		// If stack empty, no next greater elment, add `-1`
		if(st.empty()){
			st.push(nums2[i]);
			mp[nums2[i]]=-1;
		}

		// if, st.top() greater, than it is the next greater element, add 'st.top'
		else if (st.top()>nums2[i]){
			mp[nums2[i]]=st.top();
			st.push(nums2[i]);
		}
	}
	for(int i=0; i<nums1.size(); i++){
		num[i]=mp[nums1[i]];
	}
	return num;
}
```

By GPT (Same approach as mine : ) )

```python
def nextGreaterElement(nums1, nums2):
    stack = []
    next_greater = {}
    
    for num in nums2:
        # While there is an element in the stack and the current number is greater
        # than the element represented by the top of the stack
        while stack and num > stack[-1]:
            next_greater[stack.pop()] = num
        # Push the current number onto the stack
        stack.append(num)
    
    # For remaining elements in the stack, there's no next greater element
    while stack:
        next_greater[stack.pop()] = -1
    
    # Build the result for nums1
    result = [next_greater[num] for num in nums1]
    
    return result
```

TC: $O(n+m)$, SC:$O(n+m)$ n, m size of nums2 and nums1

***

## [Brackets](https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/)

```cpp
#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    if(S.size() == 0) return 1;
    if(S.size() % 2 == 1) return 0;

    stack<char> st;
    for(char c : S) {
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if(!st.empty() &&
               ((c == ')' && st.top() == '(') ||
                (c == ']' && st.top() == '[') ||
                (c == '}' && st.top() == '{'))) {
            st.pop();
        }
        else {
            return 0;
        }
    }
    return st.empty() ? 1 : 0;
}

```

***

**My Solution** ⭐

```cpp
int solution(vector<int> &A, vector<int> &B) {
    int n = A.size();
    stack<int> st;
    for(int i = n-1; i>=0; i--){
        if (B[i]==0 || st.empty() || B[st.top()]==1){
            st.push(i);
        } 
        else {
            while(B[st.top()]==0 && A[i]>A[st.top()]){
                st.pop(); 
            }
            if(B[st.top()]!=0) st.push(i);
        }
    }
    return st.size();
}
```

**TC:** `O(N)` Each fish is pushed & popped **at most once**.

**Issues:**

* You're processing from **right to left** (`i = n-1 to 0`), but the fish are defined **from upstream to downstream**, i.e., **left to right**.\
  This **violates the problem constraint**: fish `P < Q`, i.e., smaller index is upstream.
* It works on some test cases due to incidental symmetry but is **not reliable or standard**.

**Improvement:**

* Use a **stack to store downstream fish only** as we iterate **left to right**.
* When we encounter an **upstream fish**, we resolve fights against fish in the stack.

**Correct Approach:**

```cpp
int solution(vector<int> &A, vector<int> &B) {
    stack<int> downstream;
    int survivors = 0;
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        if (B[i] == 1) {
            downstream.push(A[i]);
        } else {
            while (!downstream.empty() && A[i] > downstream.top()) {
                downstream.pop();
            }
            if (downstream.empty()) survivors++;
        }
    }
    return survivors + downstream.size();
}
```

**TC:** `O(N)` — each fish enters and leaves the stack at most once.
