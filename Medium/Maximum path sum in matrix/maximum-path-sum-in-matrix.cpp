//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    int helper(int i, int j, int N, vector<vector<int>> &Matrix, vector<vector<int>> &dp){
        if(j < 0 || j >= N) return -1e9;
        if(i == 0) return Matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = Matrix[i][j] + helper(i-1, j, N, Matrix, dp);
        int ld = Matrix[i][j] + helper(i-1, j-1, N, Matrix, dp);
        int rd = Matrix[i][j] + helper(i-1, j+1, N, Matrix, dp);
        
        return dp[i][j] = max(up, max(ld, rd));
    }

    int maximumPath(int N, vector<vector<int>> Matrix){
        vector<vector<int>> dp(N, vector<int> (N, -1));
        
        int maxi = INT_MIN;
        
        for(int j=0;j<N;j++){
            int ans = helper(N-1, j, N, Matrix, dp);
            maxi = max(maxi, ans);
        }
        return maxi;
    }
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