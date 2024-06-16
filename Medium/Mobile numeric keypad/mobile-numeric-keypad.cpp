//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long help(int i,int j,int n,vector<vector<vector<long long>>> &dp){
        if(i>=4 || j>=3 || i<0 || j<0){//out of bounds
            return 0;
        }
        if(i==3 && (j==0||j==2)){ //* or #
            return 0;
        }
        if(n==1) return 1;
        if(dp[i][j][n]!=-1){
            return dp[i][j][n];
        }
        n--;
        long long up=help(i-1,j,n,dp);
        long long down=help(i+1,j,n,dp);
        long long right=help(i,j+1,n,dp);
        long long left=help(i,j-1,n,dp);
        return dp[i][j][n+1]=up+down+left+right +help(i,j,n,dp);
    }      
    long long getCount(int n) {
        long long ans=0;
        vector<vector<vector<long long>>> dp(4,vector<vector<long long>>(3,vector<long long>(n+1,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(i==3 && (j==0||j==2)){ //* or #
                    continue;
                }
                ans+=help(i,j,n,dp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends