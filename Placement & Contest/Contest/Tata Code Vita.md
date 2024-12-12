


**Problem A - Mock Vita 1 - 2025**

```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr, vector<vector<bool>>& visited, int xs, int ys, int xf, int yf, int x, int y){

    if(xs<0 or xs>=arr.size() or ys<0 or ys>=arr[0].size()) return 2147483647;
    if(arr[xs][ys]==1 or visited[xs][ys]) return 2147483647;
    
    if (xs == xf && ys == yf)
        return 0;
    
    visited[xs][ys]=true;
    
    //forward
    int f = solve(arr, visited, xs+x, ys+y, xf, yf, x, y);
    
    // right
    int r = solve(arr,visited, xs-y, ys+x, xf, yf, x, y);
    
    // backward
    int b = solve(arr, visited, xs-x, ys-y, xf, yf, x, y);
    
    // left
    int l = solve(arr, visited, xs+y, ys-x, xf, yf, x, y);
    
    // necessary so that, from other path, it could be accessed, because in backtracking value remain stored.
    visited[xs][ys]=false;
    
    // return min(b, min(l, min(r, f)));
    int result = min({f,r,l,b});
    
    return result == INT_MAX? INT_MAX : result + 1;
}


int main()
{

 // row x column
  int m, n;
  cin>>m>>n;
  
  // fill veector
  vector<vector<int>> arr(m, vector<int>(n, 0));
  for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
          cin>>arr[i][j];
      }
  }
  
  // initial position
  int xs, ys;
  cin>>xs>>ys;
  
  // destination position
  int xf, yf;
  cin>>xf>>yf;
  
  // move rule value
  int x, y;
  cin>>x>>y;
  
  vector<vector<bool>> visited(m, vector<bool>(n,false));
  
  cout<< solve(arr, visited,  xs, ys, xf, yf, x, y);
  
}

// int result = min({f, r, l, b});
// can we direct find min??
```

This error only in codevista compiler?? why??
due to the comparison of signed and unsigned integers. In C++, the `size()` method of a vector returns a value of type `size_t`, which is an unsigned integer type. When you compare this with a signed integer type (like `int`), the compiler generates a warning.

To resolve this, you can change the type of your `xs` and `ys` variables to `size_t`, which will match the type returned by `size()`. Here’s how to modify your code:
 `+`
 dp
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& arr, vector<vector<bool>>& visited, vector<vector<int>>& dp, 
          int xs, int ys, int xf, int yf, int x, int y) {

    // Check boundaries and obstacles
    if(xs < 0 || xs >= arr.size() || ys < 0 || ys >= arr[0].size()) 
        return INT_MAX;
    if(arr[xs][ys] == 1 || visited[xs][ys]) 
        return INT_MAX;
    
    // Check if we've reached the destination
    if (xs == xf && ys == yf)
        return 0;

    // Check if this state has already been computed
    if(dp[xs][ys] != -1) 
        return dp[xs][ys];

    // Mark the cell as visited
    visited[xs][ys] = true;

    // Explore all possible movements
    int f = solve(arr, visited, dp, xs + x, ys + y, xf, yf, x, y); // forward
    int r = solve(arr, visited, dp, xs - y, ys + x, xf, yf, x, y); // right
    int b = solve(arr, visited, dp, xs - x, ys - y, xf, yf, x, y); // backward
    int l = solve(arr, visited, dp, xs + y, ys - x, xf, yf, x, y); // left
    
    // Unmark the cell for backtracking
    visited[xs][ys] = false;

    // Get the minimum result
    int result = min({f, r, b, l});

    // Store the result in the dp array
    dp[xs][ys] = (result == INT_MAX) ? INT_MAX : result + 1;

    return dp[xs][ys];
}

int main() {
    // Read input dimensions
    int m, n;
    cin >> m >> n;
  
    // Initialize the grid
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
  
    // Initial position
    int xs, ys;
    cin >> xs >> ys;
  
    // Destination position
    int xf, yf;
    cin >> xf >> yf;
  
    // Move rule values
    int x, y;
    cin >> x >> y;
  
    // Visited array and dp table initialization
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dp(m, vector<int>(n, -1));
  
    // Call the solve function and print the result
    cout << solve(arr, visited, dp, xs, ys, xf, yf, x, y);
}

```


eRROR
A.cpp In function int solve std vector std vector int std vector std vector bool std vector std vector int int int int int int int A.cpp 9 21 warning comparison of integer expressions of different signedness int and std vector std vector int size_type aka long unsigned int -Wsign-compare 9 | if xs 0 || xs = arr.size || ys 0 || ys = arr 0 .size | ^ A.cpp 9 51 warning comparison of integer expressions of different signedness int and std vector int size_type aka long unsigned int -Wsign-compare 9 | if xs 0 || xs = arr.size || ys 0 || ys = arr 0 .size | ^

```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& arr, vector<vector<bool>>& visited, vector<vector<int>>& dp, 
          size_t xs, size_t ys, size_t xf, size_t yf, int x, int y) {

    // Check boundaries and obstacles
    if(xs >= arr.size() || ys >= arr[0].size()) 
        return INT_MAX;
    if(arr[xs][ys] == 1 || visited[xs][ys]) 
        return INT_MAX;

    // Check if we've reached the destination
    if (xs == xf && ys == yf)
        return 0;

    // Check if this state has already been computed
    if(dp[xs][ys] != -1) 
        return dp[xs][ys];

    // Mark the cell as visited
    visited[xs][ys] = true;

    // Explore all possible movements
    int f = solve(arr, visited, dp, xs + x, ys + y, xf, yf, x, y); // forward
    int r = solve(arr, visited, dp, xs - y, ys + x, xf, yf, x, y); // right
    int b = solve(arr, visited, dp, xs - x, ys - y, xf, yf, x, y); // backward
    int l = solve(arr, visited, dp, xs + y, ys - x, xf, yf, x, y); // left
    
    // Unmark the cell for backtracking
    visited[xs][ys] = false;

    // Get the minimum result
    int result = min({f, r, b, l});

    // Store the result in the dp array
    dp[xs][ys] = (result == INT_MAX) ? INT_MAX : result + 1;

    return dp[xs][ys];
}

int main() {
    // Read input dimensions
    int m, n;
    cin >> m >> n;
  
    // Initialize the grid
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
  
    // Initial position
    size_t xs, ys;
    cin >> xs >> ys;
  
    // Destination position
    size_t xf, yf;
    cin >> xf >> yf;
  
    // Move rule values
    int x, y;
    cin >> x >> y;
  
    // Visited array and dp table initialization
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dp(m, vector<int>(n, -1));
  
    // Call the solve function and print the result
    cout << solve(arr, visited, dp, xs, ys, xf, yf, x, y);
}

```
---

B
```CPP
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;
    
    int S, R;
    cin >> S >> R;

    int m = X.length();
    int n = Y.length();
    
    // Reverse Y
    string Y_reversed = string(Y.rbegin(), Y.rend());

    // DP array to store minimum number of substrings
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0; // base case: 0 substrings needed to form the empty string

    // To track from where the last substring came
    vector<int> from(m + 1, -1); // -1 indicates no valid substring found
    
    // Iterate through all positions of X
    for (int i = 1; i <= m; i++) {
        // Check all substrings X[j:i]
        for (int j = 0; j < i; j++) {
            string substring = X.substr(j, i - j); // X[j:i]
            // Check if the substring exists in Y
            if (Y.find(substring) != string::npos) {
                if (dp[j] + 1 < dp[i]) {
                    dp[i] = dp[j] + 1;
                    from[i] = 0; // Indicate it came from Y
                }
            }
            // Check if the substring exists in reversed Y
            if (Y_reversed.find(substring) != string::npos) {
                if (dp[j] + 1 < dp[i]) {
                    dp[i] = dp[j] + 1;
                    from[i] = 1; // Indicate it came from reversed Y
                }
            }
        }
    }

    // If we cannot form X
    if (dp[m] == INT_MAX) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Count number of substrings from Y and reversed Y
    int countY = 0, countRevY = 0;
    for (int i = m; i > 0;) {
        if (from[i] == 0) {
            countY++;
            // Move to the start of the substring
            for (int j = i - 1; j >= 0; j--) {
                if (Y.find(X.substr(j, i - j)) != string::npos) {
                    i = j; // move i to the start of the substring
                    break;
                }
            }
        } else {
            countRevY++;
            for (int j = i - 1; j >= 0; j--) {
                if (Y_reversed.find(X.substr(j, i - j)) != string::npos) {
                    i = j; // move i to the start of the substring
                    break;
                }
            }
        }
    }

    // Calculate the String Factor
    int stringFactor = countY * S + countRevY * R;
    cout << stringFactor << endl;

    return 0;
}

```