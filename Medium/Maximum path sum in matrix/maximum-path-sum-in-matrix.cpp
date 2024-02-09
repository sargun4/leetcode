//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


 class Solution{
public:
    // // Space Optimization : TC: O(n*n) SC: O(2n) ~ O(n)
    // int maximumPath(int n, vector<vector<int>> matrix)
    // {
    //     vector<int> dp(n, 0);
    //     vector<int> temp(n, 0);
    //     dp = matrix[0];
    //     if(n == 1) temp = dp;
    //     for(int i=0; i<n-1; i++){
    //         for(int j=0; j<n; j++){
    //             if(j>0) temp[j-1] = max(temp[j-1], dp[j]+matrix[i+1][j-1]);
    //             temp[j] = max(temp[j], dp[j]+matrix[i+1][j]);
    //             if(j<n-1) temp[j+1] = max(temp[j+1], dp[j]+matrix[i+1][j+1]);
    //         }
    //         dp = temp;
    //     }
    //     return *max_element(temp.begin(), temp.end());
    // }
    
    // DP - TABULATION : TC: O(n*n) SC: O(n*n) for DP Matrix
    // int maximumPath(int n, vector<vector<int>> matrix)
    // {
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
    //     dp[0] = matrix[0];
    //     for(int i=0; i<n-1; i++){
    //         for(int j=0; j<n; j++){
    //             if(j>0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]+matrix[i+1][j-1]);
    //             dp[i+1][j] = max(dp[i+1][j], dp[i][j]+matrix[i+1][j]);
    //             if(j<n-1) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+matrix[i+1][j+1]);
    //         }
    //     }
    //     return *max_element(dp[n-1].begin(), dp[n-1].end());
    // }
    
    // DP - MEMOIZATION : TC: O(n*n) SC: O(n*n) for DP Matrix + O(n) for Recursive stack space
    int findMaxPath(vector<vector<int>> &matrix, int i, int j, int n, vector<vector<int>> &dp){
        if(i>=n || j<0 || j>=n){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = matrix[i][j] + findMaxPath(matrix, i+1, j-1, n, dp);
        int center = matrix[i][j] + findMaxPath(matrix, i+1, j, n, dp);
        int right = matrix[i][j] + findMaxPath(matrix, i+1, j+1, n, dp);
        return dp[i][j] = max(left, max(center, right));
    }

    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, findMaxPath(matrix, 0, i, n, dp));
        }
        return ans;
    }
    
    // BASIC RECURSION: TC: O(3^(n*n)) SC: O(n) for Recursive stack space
    // int findMaxPath(vector<vector<int>> &matrix, int i, int j, int n){
    //     if(i>=n || j<0 || j>=n){
    //         return 0;
    //     }
    
    //     int left = matrix[i][j] + findMaxPath(matrix, i+1, j-1, n);
    //     int center = matrix[i][j] + findMaxPath(matrix, i+1, j, n);
    //     int right = matrix[i][j] + findMaxPath(matrix, i+1, j+1, n);
    
    //     return max(left, max(center, right));
    // }

    // int maximumPath(int n, vector<vector<int>> matrix)
    // {
    //     int ans = 0;
    //     for(int i=0; i<n; i++){
    //         ans = max(ans, findMaxPath(matrix, 0, i, n));
    //     }
    //     return ans;
    // }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends