
# Selection Sort

```cpp
vector<int> sortArray(vector<int>& nums) {
	int n = nums.size();

	// traverse the list from 0->n, 1->n, 2->n, so on... 
   for(int i=0; i<n; i++){
	int min = nums[i];
	int mini = i;
	for(int j=i+1; j<n; j++){
		if(nums[j]<nums[mini]){
			mini = j;
			// `min` could be skip, if we use swap() function, 
			// `min` could b written outside the ending of loop min = nums[mini]
			min = nums[j];
		}
	}
	nums[mini] = nums[i];
	nums[i] = min;
	// Inbuilt function: swap(nums[i], nums[mini]);
   }
   return nums;
}
```