//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long int dp[101][101];
    long long int  rec(int i,int j,int m,int n){
        if(i>m || j>n){ //out of bounds
            return 0;
        }
        if(i==m && j==n){//reached 
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=(rec(i,j+1,m,n)+rec(i+1,j,m,n))%(1000000007);
    }
    
    long long int numberOfPaths(int m, int n){
        memset(dp,-1,sizeof(dp));
        return rec(1,1,m,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends