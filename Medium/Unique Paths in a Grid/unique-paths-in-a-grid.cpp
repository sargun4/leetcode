//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


#include <bits/stdc++.h>
using namespace std;
int mod=(1e9+7);
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp) {
        if(i>=0 && j>=0 && grid[i][j]==0) return 0;
        if(i==0 && j==0) return 1;//reached
        if(i<0||j<0)return 0;
        //if already computed then return the value else compute and store it in dp array
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,grid,dp);
        int left=solve(i,j-1,grid,dp);
        return dp[i][j]=(up+left)%mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid){
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends