---
description: Made By Me 💚
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

# Huffman Coding (Greedy Algo)

Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters.&#x20;

The variable-length codes assigned to input characters are [Prefix Codes](http://en.wikipedia.org/wiki/Prefix_code), means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream. \
Let us understand prefix codes with a counter example. Let there be four characters a, b, c and d, and their corresponding variable length codes be 00, 01, 0 and 1. This coding leads to ambiguity because code assigned to c is the prefix of codes assigned to a and b. If the compressed bit stream is 0001, the de-compressed output may be “cccd” or “ccb” or “acd” or “ab”.\
See [this](http://en.wikipedia.org/wiki/Huffman_coding#Applications) for applications of Huffman Coding. \
There are mainly two major parts in Huffman Coding

1. Build a Huffman Tree from input characters.
2. Traverse the Huffman Tree and assign codes to characters.

#### Algorithm:

The method which is used to construct optimal prefix code is called **Huffman coding**. This algorithm builds a tree in bottom up manner. We can denote this tree by **T** Let, |c| be number of leaves |c| -1 are number of operations required to merge the nodes. Q be the priority queue which can be used while constructing binary heap.

```cpp
Algorithm Huffman (c)
{
   n= |c| 
   Q = c 
   for i<-1 to n-1
   do
   {
      temp <- get node ()
      left (temp] Get_min (Q) right [temp] Get Min (Q)
      a = left [templ b = right [temp]
      F [temp]<- f[a] + [b]
      insert (Q, temp)
    }
	return Get_min (0)
}
```

_**Steps to build Huffman Tree**_\
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree.&#x20;

```
Character:    a   b   c   d   e   f
Frequency:    5   9   12  13  16  45
```

**Step 1.** Build a min heap that contains 6 nodes where each node represents root of a tree with single node.

**Step 2** Extract two minimum frequency nodes from min heap. Add a new internal node with frequency 5 + 9 = 14.

```
a  5 ---┐
        ├--- 14
b  9 ---┘ 
```

Now min heap contains 5 nodes where 4 nodes are roots of trees with single element each, and one heap node is root of tree with 3 elements

```
Character:       c   d    *   e   f
Frequency:       12  13  14   16  45
```

**Step 3:** Extract two minimum frequency nodes from heap. Add a new internal node with frequency 12 + 13 = 25

```
c  12 ---┐
         ├--- 25
d  13 ---┘ 
```

Now min heap contains 4 nodes where 2 nodes are roots of trees with single element each, and two heap nodes are root of tree with more than one nodes

```
Character:        *   e    *  f
Frequency:       14   16  25  45
```

**Step 4:** Extract two minimum frequency nodes. Add a new internal node with frequency 14 + 16 = 30

```
a  5 ---┐
        ├--- 14 ---┐
b  9 ---┘          |
                   ├--- 30
           e 16 ---┘
```

Now min heap contains 3 nodes.

```
Character:       *   *    f
Frequency:       25  30   45
```

**Step 5:** Extract two minimum frequency nodes. Add a new internal node with frequency 25 + 30 = 55

```
           c 12 ---┐
                   ├--- 25 ---┐
           d 13 ---┘          |
                              |
a  5 ---┐                     ├--- 55
        ├--- 14 ---┐          |
b  9 ---┘          |          |
                   ├--- 30 ---┘
           e 16 ---┘ 
```

Now min heap contains 2 nodes.

```
Character:       f    *
Frequency:       45   55
```

**Step 6:** Extract two minimum frequency nodes. Add a new internal node with frequency 45 + 55 = 100

```

                                 f 45 ---┐
           c 12 ---┐                     |
                   ├--- 25 ---┐          |
           d 13 ---┘          |          ├--- 100
                              |          |
a  5 ---┐                     ├--- 55 ---┘
        ├--- 14 ---┐          |
b  9 ---┘          |          |
                   ├--- 30 ---┘
           e 16 ---┘ 
```

Now min heap contains only one node.

```
Character:       *
Frequency:       100
```

Since the heap contains only one node, the algorithm stops here.

_**Steps to print codes from Huffman Tree:**_\
Traverse the tree formed starting from the root. Maintain an auxiliary array. While moving to the left (smaller) child , write 0 to the array. While moving to the right (greater) child, write 1 to the array. Print the array when a leaf node is encountered.

```

                                 f 45 ---┐
           c 12 ---┐ 0                   | 0
                   ├--- 25 ---┐          |
           d 13 ---┘ 1        | 0        ├--- 100
                              |          | 1
a  5 ---┐ 0                   ├--- 55 ---┘
        ├--- 14 ---┐ 0        |
b  9 ---┘ 1        |          | 1
                   ├--- 30 ---┘
           e 16 ---┘ 1
```

```
f = 0
c = 100
d = 101
a = 1100
b = 1101
e = 111
```

```
Character:    a     b    c     d   e    f
Frequency:    5     9    12    13  16   45
------------------------------------------
Code word:   1100  1101  100  101  111  0
```

```c++
// C++(STL) program for Huffman Coding with STL 
#include <bits/stdc++.h> 
using namespace std; 

// A Huffman tree node 
struct MinHeapNode { 

	// One of the input characters 
	char data; 

	// Frequency of the character 
	unsigned freq; 

	// Left and right child 
	MinHeapNode *left, *right; 

	MinHeapNode(char data, unsigned freq) 

	{ 

		left = right = NULL; 
		this->data = data; 
		this->freq = freq; 
	} 
}; 

// For comparison of 
// two heap nodes (needed in min heap) 
struct compare { 

	bool operator()(MinHeapNode* l, MinHeapNode* r) 

	{ 
		return (l->freq > r->freq); 
	} 
}; 

// Prints huffman codes from 
// the root of Huffman Tree. 
void printCodes(struct MinHeapNode* root, string str) 
{ 

	if (!root) 
		return; 

	if (root->data != '$') 
		cout << root->data << ": " << str << "\n"; 

	printCodes(root->left, str + "0"); 
	printCodes(root->right, str + "1"); 
} 

// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
void HuffmanCodes(char data[], int freq[], int size) 
{ 
	struct MinHeapNode *left, *right, *top; 

	// Create a min heap & inserts all characters of data[] 
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, 
				compare> 
		minHeap; 

	for (int i = 0; i < size; ++i) 
		minHeap.push(new MinHeapNode(data[i], freq[i])); 

	// Iterate while size of heap doesn't become 1 
	while (minHeap.size() != 1) { 

		// Extract the two minimum 
		// freq items from min heap 
		left = minHeap.top(); 
		minHeap.pop(); 

		right = minHeap.top(); 
		minHeap.pop(); 

		// Create a new internal node with 
		// frequency equal to the sum of the 
		// two nodes frequencies. Make the 
		// two extracted node as left and right children 
		// of this new node. Add this node 
		// to the min heap '$' is a special value 
		// for internal nodes, not used 
		top = new MinHeapNode('$', 
							left->freq + right->freq); 

		top->left = left; 
		top->right = right; 

		minHeap.push(top); 
	} 

	// Print Huffman codes using 
	// the Huffman tree built above 
	printCodes(minHeap.top(), ""); 
} 

// Driver Code 
int main() 
{ 

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
	int freq[] = { 5, 9, 12, 13, 16, 45 }; 

	int size = sizeof(arr) / sizeof(arr[0]); 

	HuffmanCodes(arr, freq, size); 

	return 0; 
} 

// This code is contributed by Aditya Goel

```

Output

```
f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111
```

**Time complexity:** O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2\*(n – 1) times. extractMin() takes O(logn) time as it calls minHeapify(). So, the overall complexity is O(nlogn).\
If the input array is sorted, there exists a linear time algorithm. We will soon be discussing this in our next post.

**Space complexity :- O(N)**

**Applications of Huffman Coding:**

1. They are used for transmitting fax and text.
2. They are used by conventional compression formats like PKZIP, GZIP, etc.
3. Multimedia codecs like JPEG, PNG, and MP3 use Huffman encoding(to be more precise the prefix codes).
