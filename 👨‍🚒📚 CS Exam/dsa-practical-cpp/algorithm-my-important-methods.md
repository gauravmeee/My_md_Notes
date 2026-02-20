---
description: Made by Me 💚
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

# Algorithm: My Important methods

### ✅ **String (C++)**

#### Longest Palindromic Substring

```cpp
string longestPalindrome(string s) {
    int start = 0, maxLen = 1, n = s.length();
    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if(r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
        l = i, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            if(r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
    }
    return s.substr(start, maxLen);
}
```

#### String Compression

```cpp
string compress(string s) {
    string res = "";
    int i = 0, n = s.length();
    while(i < n) {
        char ch = s[i];
        int count = 0;
        while(i < n && s[i] == ch) {
            count++; i++;
        }
        res += ch + to_string(count);
    }
    return res;
}
```

#### Character Frequency

```cpp
void freq(string s) {
    unordered_map<char, int> mp;
    for(char c : s) mp[c]++;
    for(auto it : mp)
        cout << it.first << ": " << it.second << "\n";
}
```

***

### ✅ **Array (C++)**

#### QuickSort

```cpp
void quicksort(int arr[], int low, int high) {
    if(low >= high) return;
    int pivot = arr[high], i = low;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[high]);
    quicksort(arr, low, i - 1);
    quicksort(arr, i + 1, high);
}
```

#### Kth Largest Element

```cpp
int kthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int num : arr) {
        pq.push(num);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}
```

#### Rotate NxN Matrix 90°

```cpp
void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    for(int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}
```

***

### ✅ **Pointers & Memory (C / C++)**

#### Swap Using Pointers

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

#### Dynamic Array Allocation

```c
void handleArray() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    free(arr);
}
```

***

### ✅ **String (C)**

#### Reverse String Without `strrev`

```c
void reverse(char* str) {
    int n = strlen(str);
    for(int i = 0; i < n/2; i++)
        swap(str[i], str[n-i-1]);
}
```

***

### ✅ **Math / Logic (C++)**

#### Fibonacci Without Recursion

```cpp
void fib(int N) {
    int a = 0, b = 1;
    for(int i = 0; i < N; i++) {
        cout << a << " ";
        int temp = a + b;
        a = b;
        b = temp;
    }
}
```
