//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
    if (n == 0) return 0; // No energy needed for the first step
    if (n == 1) return abs(height[1] - height[0]); // Only one jump possible

    int left = minimumEnergy(height, n - 1) + abs(height[n - 1] - height[n - 2]);
    int right = (n > 2) ? minimumEnergy(height, n - 2) + abs(height[n - 1] - height[n - 3]) : std::numeric_limits<int>::max();

    return std::min(left, right);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N-1) << "\n";
    }
    return 0;
}
// } Driver Code Ends