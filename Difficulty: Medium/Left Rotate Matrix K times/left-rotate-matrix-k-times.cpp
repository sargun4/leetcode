//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void rotate(vector<int> &row, int k) {
        int n = row.size();
        k = k % n; // Normalize k to ensure it is within the bounds of the array size

        // Reverse the first k elements
        reverse(row.begin(), row.begin() + k);
        // Reverse the remaining n - k elements
        reverse(row.begin() + k, row.end());
        // Reverse the entire row
        reverse(row.begin(), row.end());
    }

    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            rotate(mat[i], k); // Rotate each row by k positions
        }
        return mat;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends