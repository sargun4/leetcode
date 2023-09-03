//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
class Solution {
    void solve(int i,int j,vector<vector<int>> &mat,int n,vector<string>&ans,string move,vector<vector<int>> &vis){
        if(i==n-1 && j==n-1){ //last cell of matrix
            ans.push_back(move);
            return;
        }
        //down
        if(i+1<n && !vis[i+1][j] && mat[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,mat,n,ans,move+'D',vis);
            vis[i][j]=0;
        }
        //left
        if(j-1>=0 && !vis[i][j-1] && mat[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,mat,n,ans,move+'L',vis);
            vis[i][j]=0;
        }
        //right
        if(j+1<n && !vis[i][j+1] && mat[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,mat,n,ans,move+'R',vis);
            vis[i][j]=0;
        }
        //up
        if(i-1>=0 && !vis[i-1][j] && mat[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,mat,n,ans,move+'U',vis);
            vis[i][j]=0;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &mat,int n){
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(mat[0][0]==1) solve(0,0,mat,n,ans,"",vis);
        return ans;
    }
};

// Output:
// DDRDRR DRDDRR
// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).

    
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends