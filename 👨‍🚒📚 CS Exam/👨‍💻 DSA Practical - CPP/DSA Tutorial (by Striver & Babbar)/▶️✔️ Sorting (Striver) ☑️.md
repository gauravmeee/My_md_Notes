---
description: From Striver's Tutorial ▶️
layout:
  width: wide
  title:
    visible: false
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

# ▶️✔️ Sorting (Striver) ☑️

## <mark style="color:blue;">**Algorithm: Sorting**</mark>

***

**Sorting - I**

| \[\[#^1]] | Selection Sort | Algorithm | ✅ | A2Z🟢 |
| --------- | -------------- | --------- | - | ----- |
| \[\[#^2]] | Bubble Sort    | Algorithm | ✅ | A2Z🟢 |
| \[\[#^3]] | Insertion Sort | Algorithm | ✅ | A2Z🟢 |

**Sorting - II**

| \[\[#^4]] | Merge Sort | Algorithm | ✅ | A2Z🟠 |
| --------- | ---------- | --------- | - | ----- |
| \[\[#^5]] | Quick Sort | Algorithm | ✅ | A2Z🟢 |

***

**Sorting Algorithms 1️⃣2️⃣3️⃣**

[**Sorting - Part 1 | Selection Sort, Bubble Sort, Insertion Sort | Strivers A2Z DSA Course**](https://youtu.be/HGk_ypEuS24)

**1. Selection Sort ^1**

* Select Minimum & Swap with its desired position

> **Best, Average, Worst TC : `O(n^2)`** **SC** : `O(1)`

_**Selection Sort Code :**_

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

* Select minimum between `i=0 & n-1` and Swap it with `0th` position.
* Select minimum between `i=1 & n-1` and Swap it with `1th` position.
* Select minimum between `i=2 & n-1` and Swap it with `2th` position.

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

3. next `min=20`, swap it with \`arr\[2] = 24

```
[9, 13, 20, 52, 24, 46]
```

4. next `min=24`, swap it with \`arr\[3] = 52

```
[9, 13, 20, 24, 52, 46]
```

3. next `min=46`, swap it with \`arr\[4] = 52

```
[9, 13, 20, 24, 46, 52]
```

Time Complexity :\
Best, worst, average `TC:O( n^2)`

Outer Loop : `0` to `n-2` -> `n-1*` times Inner Loop : `i` to `n-1` -> Inner loop x Outer Loop`*` times `i = 0` : `0` to `n-1` -> `n*` Times `i = 1` : `1` to `n-1` -> `n-1*` Times `i = 2` : `2` to `n-1` -> `n-2*` Times ...so on `i = n-2` : `n-2` to `n-1` -> `1*` Times

TC : 1 + 2 + 3 +. . . + n = n(n+1)/2 = (n^2)/2 + n/2

***

\## 2. Bubble Sort ^2 - Push the Maximum to the last, by adjacent swaps (adjacent swap is the key over here)

> **Average, Worst TC : `O(n^2)`** **Best TC : `O(n)`** SC: O(1)

_**Bubble Sort(Average, Worst) Code :**_

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

_**Bubble Sort (Best ) Code :**_

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

* Compare Adjacent from `i = 0` to `n-1`, swap if not sorted
* Compare Adjacent from `i = 0` to `n-2`, swap if not sorted
* Compare Adjacent from `i = 0` to `n-3`, swap if not sorted And so on till `i = 0 to 1`

Example :

```
[13, 46, 24 , 52, 20, 9 ]
```

```
// swap upto , n-2 & n-1
[ (13, 46), 24, ,52, 20, 9]  Index 0 & 1 sorted ✅
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

Time Complexity:\
Worst, Average `TC:O(n^2)`

Outer Loop `i= n-1` to `0` -> `n*` times Inner Loop `j=0` to `i-1` -> Inner Loop x Outer Loop`*` times i = n-1 : 0 to i-1=n-2 : 0&1 ,1&2, ... n-2\&n-1 -> n-1\* Times i = n-2 : 0 to i-1=n-3 : 0&1 ,1&2, ... n-3\&n-3 -> n-2\* Times i = n-3 : 0 to i-1 = n-4 : 0&1 ,1&2, ... n-4\&n-3 -> n-3\* Times ... so on i = 1 : 0 to i-1= 0 : 0&1. 1\* Times

TC: n-1 + n-2 + n-3 .... +1 = n\*(n+1)/2 = n^2/2 + n/2

> Optimization for Best Case

```
[ 1, 2, 3, 4, 5]
```

If every adjacent element is in correct order -> Array is sorted In one traversal, if you didn't find any wrong order -> Array is sorted -> Break the loop.

Time Complexity:\
Best `TC:O(n)`

Best, If every element is sorted Outer Loop `1*` Times Inner Loop `j=0 to i-1 = n-1` -> `n*` Times

> ☑️ 22-04-2025 Revised Upto here

***

**3. Insertion Sort ^3**

* Takes an element and place it in its correct position in new array
* Make array of size 1, include only `arr[0]`, then add new element in it in correct position in each iteration

> **Average, Worst TC : `O(n^2)`** \*\*Best TC : `O(n) SC :` O(1)\`

_**Insertion Sort (Average, Worst) Code :**_

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

_**Insertion Sort (Best) Code :**_

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
[(6, 8, 9, 12, 14, 15, 13)] -> right shift (element > 13) -> [6, 8, 9, 12, 13, 14 ,15]

[6, 8, 9, 12, 13, 14 ,15] ✅
```

Time Complexity : Average, worst `TC:O(n^2)`

Outer loop : 0 to n-1 -> n\* Times Inner Loop: Inner Loop x Outer Loop `*` Times i=0 : j=1->0 -> 1\* Times i=1 : j=2->0-> 2\* Times .. so on i = n-1 : -> n\* Times

TC = 1 + 2 + ...+ n = n(n+1)/2 = n^2/2 + n/2

> Optimization for Best case

if subarray is already sorted from size 1 till include all -> Array is sorted -> break

Time Complexity : Best `TC:O(n)`

Best, If every element is sorted Outer Loop `1*` Times Inner Loop `j-1` to `0` -> `n*` Times

[**Merge Sort | Algorithm | Pseudocode | Dry Run | Code | Strivers A2Z DSA Course**](https://youtu.be/ogjf7ORKfd8) **^4**

* Divide , Sort & Merge

> best, average, worst TC: `O(nlog(n))`\
> SC: `O(n)`

1. _**Merge Sort algorithm:**_

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

2. _**Merge algorithm**_

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

Time Complexity : Average, Worst, Best `TC: O(nlog(n))`

```
            [n]
    [n/2]         [n/2]
[n/4]   [n/4]  [n/4]  [n/4] 
```

1. if **recursion** call k...\*times times, then

n = 2^k => log2n = k => no. of times -> time complexity 2. **merge()** -> Traversing aray: TC: worst case O(n)

Space Complexity : `SC:O(n)` temporary array in merge of n size() -> SC: O(n) Recursion stack space -> SC:O(log(n))

_**C++ code :**_

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

[**Quick Sort For Beginners | Strivers A2Z DSA Course**](https://youtu.be/WIrA4YexLRQ) **^5**

* Divide and Conquer

1. pick any (first, last, right, random, etc.) element as `pivot` & place it in its correct place in the sorted array
2. Smaller element than `pivot` goes on its left , larger goes on the right

TC: Best, Average `O(n*log(n))` TC : Worst `O(n^2)` SC: Best, Average`O(logn)` SC: Worst `O(n)`

But how to put `pivot` in its correct position??

_**Quick Sort:**_

```cpp
qs(arr, low, high){
	//array should contain more than one element i.e. `low!=high`
	if(low<high){
		 // function to find out pivot
		 pIndex = partition(arr, low, high)
		 // sort left of partition
		 qs(arr, low, pIndex-1)
		 
		 // sort right of partition
		 qs(arr, pIndex+1, high)
	} 
}
```

_**Swap and Return Partition:**_

```cpp
int partition(arr, low, high){
	pivot = arr[low] // let choose `arr[low]` as pivot
	i = low;
	j = high;
    // stop when `i` & `j` cross each other
	while(i<j){
	
		// loop until find first element from left side greater than `pivot`
		// `i<=high` : `i` shouldn't cross right boundry
		while(arr[i]<=arr[pivot] && i<=high ){
			i++;
		}
		// loop until find first element from right side smaller than or equal to `pivot`
		//`j>=low` : `j` shouldn't cross left boundry
		while(arr[j]>arr[pivot] && j>=low){
			j--}
		}
		// if we find, `arr[i] > arr[pivot]` & `arr[j] <= arr[pivot]` from while loop & `if (i<j)` i dosn't cross each other, `swap`
		if(i<j) swap(arr[i]), arr[j]);
	}
	// Swap `arr[low] = pivot` with  `arr[j] = last element of left index`
	swap(arr[low], arr[j]);
}
```

Example:

```
[ 4 6 2 5 7 9 1 3 ]
```

In this Case, we will choose `arr[low]` as our `pivot` (it might not be optimal)

```
1. 
arr = [ 4 6 2 5 7 9 1 3 ] : let pivot = 4
qs(arr, low, high)
 
find i & j such that : arr[i]>pivot, arr[j]<= pivot and i<j

arr[i=6]=6 > 4 &  arr[j=7]=3 <= 4  
[ (4) 6 2 5 7 9 1 3 ]  : swap[i]&[j] -> swap(6,3) ✅ 

arr[i=3]= 5 > 4 & arr[j=6]=1 <= 4 
[ (4) 3 2 5 7 9 1 6 ] : swap[i]&[j] -> swap(5,1) ✅

arr[i=4]= 7 > 4 & arr[j=3]=1 <= 4 : but i>j 
[ (4) 3 2 1 7 9 5 6 ] : swap [i]&[j] ❌  swap [low]&[j] -> swap(4,1) ✅


>>> Partition: [[1 3 2] 4 [7 9 5 6]]
pIndex = 4
index<j : left partition < pIndex
index>j : right partition > pIndex
```

```
2.1
arr[1 3 2] : let pivot = 1
qs(arr, low, pIndex-1)

find i & j such that : arr[i]>pivot, arr[j]<= pivot and i<j

arr[i=1]= 3 > 1 & arr[j=0]=1 <= 1  : but i>j
[ (1) 3 2 ] : swap [i]&[j] ❌  swap [low]&[j] -> swap(1,1) ✅


>>> Partition: [1 [3 2]]
pIndex = 0
no left elements.
index>j : right partition > pIndex 
```

```
2.1.2
arr[3 2] : let pivot = 3
qs(arr, pIndex+1, high)

find i & j such that : arr[i]>pivot, arr[j]<= pivot and i<j

arr[i=2]=?  &  arr[j=1]=2 <= 3  : but i>j
[ 3 2 ]  : swap [i]&[j] ❌  swap [low]&[j] -> swap(3,1) ✅

>>> Partition: [[2] 3] // swapped in actual array
```

```
2.1.2.1
arr = [2]
low == high -> Single element -> Already sorted ✅
```

```
2.2
arr[7 9 5 6] : let pivot = 7
qs(arr, pIndex+1, high) 

find i & j such that : arr[i]>pivot, arr[j]<= pivot and i<j

arr[i=1]=9 > 7 &  arr[j=3]=6 <= 7
[(7) 9 5 6] : swap[i]&[j] -> swap(9,6) ✅

arr[i=3]= ? &  arr[j=2]=5 <= 7 : but i>j
[(7) 6 5 9] swap [i]&[j] ❌  swap [low]&[j] -> swap(7,5) ✅

>>> Partition: [[5 6] 7 [9]] // swapped in actual array
```

```
2.2.1
arr = [5 6] : let pivot = 5
arr[i=1]=6>5 & arr[j=0]=5 <= 5 : but i>j 
[(5) 6] swap [i]&[j] ❌  swap [low]&[j] -> swap(5,5) ✅

>>> partition : [5 [6]]
```

```
2.2.1.2
arr = [6]
low == high -> Single element -> Already sorted ✅
```

```
2.2.2
arr = [9]
low == high -> Single element -> Already sorted ✅
```

Time Complexity : Average, Worst, Best `TC: O(nlog(n))`

```
				[n]
        [n/2]         [n/2]
    [n/4]   [n/4]  [n/4]  [n/4] 
```

1. if **recursion call** k...\*times times, then

n = 2^k => log2n = k (height of tree) => no. of times -> time complexity

2. **partition()** function going to entire array : TC :O(n)

Space Complexity : `SC:O(logn)` Recursion stack space -> SC:O(log(n))

_**C++ Code:**_

```cpp
int partition(vector<int> &arr, int low, int hig){
    int pivot = arr[low]; // choosing `arr[low]` as pivot
    int i = low;
    int j = high;
    while( i < j){
        while(arr[i] <= pivot && i<= high-1){
            i++;
        }
        while(arr[i] > pivot && j>= low +1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex -1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr){
    qs(arr, 0, arr.size()-1);
    return arr;
}
```

***
