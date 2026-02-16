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

# CPU Task Scheduler

My Approach After learning Heap : )

```cpp
int cpuTaskScheduler(int n, vector<vector<int>> arr) {
	// min heap to store the ending time of processes.
	// Logically, the number of heaps, will be equal to no. of processing required
	// the process with least ending time will remain on top, and new process ending time will be reassigned to it
    priority_queue<int, vector<int>, greater<int>> hp;
	// sort the array of process according to starting time
    sort(arr.begin(), arr.end());

	// Process the , task in ascending order their starting time
   for(int i=0; i<n; i++){
       if(hp.empty() or hp.top()>arr[i][0]){
			// If the heap is empty i.e (0 core), or 
			// least ending time of process > starting time of current process
			// all process are busy, create a new core/processor
           hp.push(arr[i][1]);

       }

       else{
	      // if the least ending time of process < starting time of current process
	      // pop out the ending time and assign new task ending time
           hp.pop();
           hp.push(arr[i][1]);
       }

   }
	// return the size of heap = minimum number of core required
   return hp.size();

}
```
