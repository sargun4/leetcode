//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int dp[n][m];
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0) dp[i][j]=mat[i][j];
                else{
                    if(mat[i][j]==1){
                        dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    }
                    else dp[i][j]=0;
                }
                mx=max(mx,dp[i][j]);
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends