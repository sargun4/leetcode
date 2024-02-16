//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


#include <bits/stdc++.h>
using namespace std;
//tab
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        if (n == 0 || m == 0) return 0;
         if (n == 1 || m == 1) {
            // If the matrix has only one row or one column,
            // check if there is any 1 in the entire matrix
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (mat[i][j] == 1) return 1;
                }
            }
            // If no 1 is found, return 0 (no square can be formed)
            return 0;
        }
        int ans=0;
        vector<vector<int>> dp=mat;//copy
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){//bottom left cell
                    dp[i][j]=mat[i][j];
                    ans = max(ans, dp[i][j]);
                }else if(i==n-1){//last row
                    dp[i][j]=mat[i][j];
                    ans = max(ans, dp[i][j]);

                }else if(j==m-1){//last col
                    dp[i][j]=mat[i][j];
                    ans = max(ans, dp[i][j]);

                }else{
                    if(mat[i][j]==0){
                        dp[i][j]=0;
                    }else{
                        int right=dp[i][j+1];
                        int down=dp[i+1][j];
                        int rd=dp[i+1][j+1];
                        int mini=min(right,min(down,rd));
                        dp[i][j]=mini+1;
                        if(dp[i][j]>ans){
                            ans=dp[i][j];
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends