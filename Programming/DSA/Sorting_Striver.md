
# Sorting Algorithms 1️⃣2️⃣3️⃣

# [Sorting - Part 1 | Selection Sort, Bubble Sort, Insertion Sort | Strivers A2Z DSA Course](https://youtu.be/HGk_ypEuS24)
## 1. Selection Sort
- Select Minimum & Swap with its desired position

>**Best, Average, Worst TC : `O(n^2)`**
>**SC** : `O(1)`

***Selection Sort Code :***
```cpp
void selectionSort(int arr[], int n){
	// In each Iteration, We set min to left side and exclude index from left
	for(int i=0; i<=n-1; i++){
	int mini =i;
		for(int j = i; j<=n-1; j++){
			if(arr[j]<arr[mini]){
				mini = j;
			}
		}
		//swap
		int temp = arr[mini];
		arr[mini] = arr[i];
		arr[i] = temp;
	}
}
```

- Select minimum between `i=0 & n-1` and Swap it with `ith` position. 
- Select minimum between `i=1 & n-1` and Swap it with `ith` position. 
- Select minimum between `i=2 & n-1` and Swap it with `ith` position. 
And so on till `i=n-2` ( note:- `n-1` will automatically sorted.)

Example:-
```
[13, 46, 24, 52, 20, 9]
```

1. `min=9`, swap it with `arr[0] = 13`
```
[9, 46, 24, 52, 20, 13]
```

2. next `min=13`, swap it with `arr[1] = 46`
```
[9, 13, 24, 52, 20, 46]
```

3. next `min=20`, swap it with `arr[2] = 24
```
[9, 13, 20, 52, 24, 46]
```

4. next `min=24`, swap it with `arr[3] = 52
```
[9, 13, 20, 24, 52, 46]
```

3. next `min=46`, swap it with `arr[4] = 52
```
[9, 13, 20, 24, 46, 52]
```


<Ins>Time Complexity :</ins>  
Best, worst, average `TC:O( n^2)`

Outer Loop : `0` to `n-2` ->  `n-1*` times
Inner Loop : `i` to `n-1`  -> Inner loop x Outer Loop`*` times
`i = 0` : `0` to `n-1`  ->  `n*`  Times
`i = 1` : `1` to `n-1` ->  `n-1*`  Times
`i = 2` : `2` to `n-1`  -> `n-2*`  Times
...so on
`i = n-2` : `n-2` to `n-1`  ->  `1*`  Times

TC : 1 + 2 + 3 +. . . + n  = n(n+1)/2 = (n^2)/2 + n/2

<hr>
## 2. Bubble Sort
- Push the Maximum to the last, by adjacent swaps (adjacent swap is the key over here)

>**Average, Worst TC : `O(n^2)`**
>**Best TC : `O(n)`**
>SC: O(1)

***Bubble Sort(Average, Worst) Code :***
```cpp
void bubbleSort(int arr[], int n){
	// In each Iteration, We set max to Right side and exclude index from right
	for(int i=n-1; i>=0; i--){ 
		for(int j = 0; j<=i-1; j++){
			if(arr[j]> arr[j+1]){
				int temp = arr[j+1];
				arr[j+1]= arr[j];
				arr[j] = temp;
			}
		}
	}
}
```

***Bubble Sort (Best ) Code :***
```cpp
void bubbleSort(int arr[], int n){
	for(int i=n-1; i>=0; i--){
		bool didSwap = 0; // Check if any Pair swapped in one traversal
		for(int j = 0; j<=i-1; j++){
			if(arr[j]> arr[j+1]){
				int temp = arr[j+1];
				arr[j+1]= arr[j];
				arr[j] = temp;
				didSwap = 1; // If Swapped, Mark it true
			}
		}
		if(!didSwap) break; // If not swapped , Break the loop
	}
}
```


- Compare Adjacent from `i = 0 ` to  `n-1`, swap if not sorted
- Compare Adjacent from `i = 0 ` to  `n-2`, swap if not sorted
- Compare Adjacent from `i = 0 ` to  `n-3`, swap if not sorted
And so on till `i = 0 to 1`

Example : 
```
[13, 46, 24 , 52, 20, 9 ]
```

```
// swap upto , n-2 & n-1
[ (13, 24), 46, 20, 9, 52 ]  Index 0 & 1 sorted ✅
[ 13, (46, 24), 52, 20, 9 ] -> [13, (24, 46), 52, 20, 9 ]
[ 13, 24, (46, 52), 20, 9 ] Index 2 & 3 sorte ✅
[ 13, 24, 46, (52, 20), 9 ] -> [ 13, 24, 46, (20, 52), 9 ] 
[ 13, 24, 46, 20, (52, 9) ] -> [ 13, 24, 46, 20, 9, 52 ] 
maximum = 52 pushed to the n-1th position
```

```
// swap upto , n-3 & n-2
[ (13, 24), 46, 20, 9, 52 ] Index 0 & 1 sorted ✅
[ 13, (24, 46), 20, 9, 52 ] Index 1 & 2 sorted ✅
[ 13, 24, (46, 20), 9, 52 ] -> [ 13, 24, (20, 46), 9, 52 ]
[ 13, 24, 20, (46, 9), 52 ] -> [ 13, 24, 20, (9, 46), 52 ]
next maximum = 46 pushed to the n-2th position
```

```
// swap upto , n-4 & n-3
[ (13, 24), 20, 9, 46, 52 ] Index 0 & 1 sorted ✅
[ 13, (24, 20), 9, 46, 52 ] -> [ 13, (20, 24), 9, 46, 52 ]
[ 13, 20, (24, 9), 46, 52 ] -> [ 13, 20, (9, 24), 46, 52 ]
next maximum = 24 pushed to the n-3th position
```

```
// Swap upto, n-5 & n-4
[ (13, 20), 9, 24, 46, 52 ] Index 0 & 1 sorted ✅
[ 13, (20, 9), 24, 46, 52 ] -> [ 13, (9, 20), 24, 46, 52 ]
next maximum = 20 pushed to the n-4th position
```

```
// Swap upto n-6 & n-5  i.e 0th & 1st position
[ (13, 9), 20, 24, 46, 52 ] - > [ (9, 13), 20, 24, 46, 52 ]
next maximum = 13 pushed to the n-5th == 1st position

All Sorted ✅
```


<ins>Time Complexity: </ins>  
Worst, Average `TC:O(n^2)`

Outer Loop `i= n-1` to `0`  ->  `n*` times
Inner Loop  `j=0` to `i-1` -> Inner Loop x Outer Loop`*` times
i = n-1 : 0 to i-1=n-2 : 0&1 ,1&2, ... n-2&n-1 -> n-1* Times
i = n-2 : 0 to i-1=n-3 : 0&1 ,1&2, ... n-3&n-3 -> n-2* Times
i = n-3 : 0 to i-1 = n-4 : 0&1 ,1&2, ... n-4&n-3 -> n-3* Times
... so on
i = 1 : 0 to i-1= 0 : 0&1. 1* Times

TC: n-1 + n-2 + n-3 .... +1 = n*(n+1)/2 = n^2/2 + n/2

>Optimization for Best Case

```
[ 1, 2, 3, 4, 5]
```
If every adjacent element is in correct order -> Array is sorted
In one traversal,  if you didn't find any wrong order -> Array is sorted ->  Break the loop.

<ins> Time Complexity: </ins>  
Best `TC:O(n)`

Best, If every element is sorted
Outer Loop `1*` Times
Inner Loop  `j=0 to i-1 = n-1` -> `n*` Times

## 3. Insertion Sort
- Takes an element and place it in its correct position in new array
- Make array of size 1, include only `arr[0]`, then add new element  in it in correct position in each iteration

>**Average, Worst TC : `O(n^2)`**
>**Best TC : `O(n)
>SC : `O(1)`

***Insertion Sort (Average, Worst) Code :***
```cpp
void insertionSort(int arr[], int n){
	for(int i=0; i<=n-1; i++){
		int j=i;
		// if arr[j] < arr[j-1], push/Swap arr[j] to left until arr[j]>=arr[j-1]
		while(j>0 && arr[j-1]>arr[j]){ 
		// if array only contain first element,  don't compare it, start with `j>0`
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}
```

***Insertion Sort (Best) Code :***
```cpp
void insertionSort(int arr[], int n){
	for(int i=0; i<=n-1; i++){
		int j=i;
		bool didSwap = 0; // Check if any Pair swapped in one traversal
		while(j>0 && arr[j-1]>arr[j]){
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
			didSwap = 1; // If Swapped, Mark it true
		}
		if(!didSwap) break; // If not swapped , Break the loop
	}
}
```

Example:
```
[ 14, 9, 15, 12, 6, 8, 13]
```

Start by Taking `arr[0]` as and array, and include it right in every step.
```
[ (14), 9, 15, 12, 6, 8, 13] -> [14] sorted ✅
[(14, 9), 15, 12, 6, 8, 13] -> right shift (element > 9) -> [9, 14]
[(9, 14, 15), 12, 6, 8, 13] -> [9, 14, 15] sorted ✅
[(9, 14, 15, 12), 6, 8, 13] -> right shift (element > 12) -> [9, 12, 14, 15]
[(9, 12, 14, 15, 6), 8, 13] -> right shift (element > 6) -> [6, 9, 12, 14, 15]
[(6, 9, 12, 14, 15, 8), 13] -> right shift (element > 8) -> [6, 8, 9, 12, 14, 15]
[(6, 8, 9, 12, 14, 15, 13)] -> right shift (element >13) -> [6, 8, 9, 12, 13, 14 ,15]

[6, 8, 9, 12, 13, 14 ,15] ✅
```


<ins> Time Complexity : </ins>
Average, worst `TC:O(n^2)`

Outer loop : 0 to n-1 -> n* Times
Inner Loop: Inner Loop x Outer Loop `*` Times
i=0 : j=1->0 -> 1* Times
i=1 : j=2->0-> 2* Times
.. so on
i = n-1 : -> n* Times

TC = 1 + 2 + ...+ n = n(n+1)/2 = n^2/2 + n/2

> Optimization for Best case

if subarray is already sorted from size 1 till include all -> Array is sorted -> break

<ins>Time Complexity :</ins>
Best `TC:O(n)`

Best, If every element is sorted
Outer Loop `1*` Times
Inner Loop  `j-1` to `0` -> `n*` Times



# [Merge Sort | Algorithm | Pseudocode | Dry Run | Code | Strivers A2Z DSA Course](https://youtu.be/ogjf7ORKfd8)
## 4. Merge Sort (Recursion)
- Divide , Sort & Merge

> best, average, worst  TC: `O(nlog(n))`  
> SC: `O(n)`


1. ***Merge Sort algorithm:***
 ```cpp
  low = 0  //first element index
  high = n-1; //last element index
 mergesort(arr, low, high){
    if(low >= high) return;
    mid = (low + high)/2
    mergesort(arr, low, mid)  //(arr, low , mid-1) also valid
    mergesort(arr, mid+1, high)   //(arr, mid , high) also valid
    merge(arr, low, mid, high)      
 }
 ```
2. ***Merge algorithm***
 ```cpp
 merge(arr, low, mid, length){
        temp=[]
        left = low
        right = mid+1
    
    //check that left and right pointer not reach to end
    while(left<=mid && right<=high ){ 
        if(arr[left] <= arr[right]){
            temp.add(arr[left])
            left++
            }
        else{
            temp.add(arr[right])
            right++
        }
        
    }

    // if left array exhausted
    while(left<=mid){
        temp.add(arr[left])
        left++
    }
    //If right array exhausted
    while(right<=high){
        temp.add(arr[right])
        right++
    }

    //transfer from temporary array to main
    for( i=low -> high){
        arr[i] = temp[i-low] // logic: to correctly place element to right indexing

        //Important : understand it
    }
 }
 ```

Example: 
```
[3, 1, 2, 4, 1, 5, 2, 6, 4]
```

```

Merge sort -> divide and merge 
n = 9 , divide -> 5:4 or 4:5 

follow the same divide rule in each step , either `[n/2+1]:[n/2] `or `[n/2]:[n/2+1]` for reusable code

Divide:
 1. [3, 1, 2, 4, 1, 5, 2, 6, 4] => [3, 1, 2, 4, 1] + [5, 2, 6, 4]
 2. [3, 1, 2, 4, 1] => [3, 1, 2] + [4, 1]
 3. [5, 2, 6, 4] => [5, 2] + [6, 4]
 4. [3, 1, 2] => [3, 1] + [2]
 5. [4, 1] => [4] + [1]
 6. [5, 2] => [5] + [2]
 7. [6. 4] => [6] + [4]
 8. [3, 1] => [3] + [1]


Merge: 
sorted + sorted => sorted
1. [3] + [1] => [1, 3]
2. [6] + [4] => [4, 6]
3. [5] + [2] => [2, 5]
4. [4] + [1] => [1, 4]
5. [1, 3] + [2] => [1, 2, 3]. 
6. [2, 5] + [4, 6] => [2, 4, 5, 6]
7. [1, 2, 3] + [1, 4] => [1, 1, 2, 3, 4]
8. [1, 1, 2, 3, 4] + [2, 4, 5, 6] => [1, 1, 2, 3, 3, 4, 4, 5, 6]
```

<ins>Time Complexity :</ins>
Average, Worst, Best `TC: O(nlog(n))` 

                [n]
        [n/2]         [n/2]
    [n/4]   [n/4]  [n/4]  [n/4] 


if recursion call k...*times times, then 

n = 2^k
=> log2n = k 
=> no. of times -> time complexity
**merge() time complexity :** worst case O(n)

 
<ins>Space Complexity :</ins>
`SC:O(n)`
temporary array in merge of n size() -> SC: O(n)
Recursion stack space -> SC:O(log(n))

 ***C++ code :***
 ```cpp
 void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    //[low...mid]
    ///[mid+1...high]
    int left = low;
    int right = mid+1;
    while(left <= mid && right <=high){

        //left is smaller
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        //right is smaller
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    //if right exhausted
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    //if left exhausted
    while(right<=mid){
        temp.push_back(arr[right]);
        right++;
    }
    //transfer to the main array
    for(int i=low; i<=high ; i++){
        arr[i] = temp [ i- low]; //everything is by reference, so numbers will rearrange themselve in the array 
    }
}

void mergesort(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low+ high) /2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void callMergeSort(vector<int> & arr, int n){
    callMergeSort(arr, 0, n-1);
}
 ```

# [Quick Sort For Beginners | Strivers A2Z DSA Course](https://youtu.be/WIrA4YexLRQ)

1. pick any (first, last, right, random, etc.) element as `pivot` & place it in its correct place in the sorted array
2.  Smaller element than `pivot` goes on its left , larger goes on the right

TC: `O(n*log(n))`
SC: Average`O(logn)`
SC: Worst `O(n)`

But how to put `pivot`  in its correct position??

***Pseudocode:***
```
```

```
[ 4 6 2 5 7 9 1 3 ]
```
# More Knowledge

**Comparison Sorting**  
Quicksort usually has a running time of `n x log(n)` , but is there an algorithm that can sort even faster? In general, this is not possible. Most sorting algorithms are _comparison sorts_, i.e. they sort a list just by comparing the elements to one another. A comparison sort algorithm cannot beat  `n x log(n)` (worst-case) running time, since  `n x log(n) ` represents the minimum number of comparisons needed to know where to place each element. For more details, you can see [these notes](http://www.cs.cmu.edu/~avrim/451f11/lectures/lect0913.pdf) (PDF).

**Alternative Sorting**  
Another sorting method, the _counting sort_, does not require comparison. Instead, you create an integer array whose index range covers the entire range of values in your array to sort. Each time a value occurs in the original array, you increment the counter at that index. At the end, run through your counting array, printing the value of each non-zero valued index that number of times.