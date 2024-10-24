
# [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/description/)

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

By GPT  (Same approach as mine : ) )
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
