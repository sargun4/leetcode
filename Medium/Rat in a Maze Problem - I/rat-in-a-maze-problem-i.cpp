//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).
class Solution{
    public:
    vector<string>v;
    void dfs(int i,int j,string s,vector<vector<int>> &m,int n,vector<vector<int>> &vis){
        if(i<0 or j<0 or i>=n or j>=n) return;//outofbounds
        if(m[i][j]==0 or vis[i][j]==1) return;
        if(i==n-1 and j==n-1){
            v.push_back(s);
            return;
        }
        vis[i][j]=1;
        dfs(i-1,j,s+'U',m,n,vis);
        dfs(i+1,j,s+'D',m,n,vis);
        dfs(i,j-1,s+'L',m,n,vis);
        dfs(i,j+1,s+'R',m,n,vis);
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        v.clear();
        int size=m.size();
        string s="";
        vector<vector<int>> vis(n,vector<int>(n,0));
         if (m[0][0] == 0 or m[n - 1][n - 1] == 0) return v;
        dfs(0,0,"",m,n,vis);
        sort(v.begin(),v.end());
        return v;
    }
};


// class Solution{
//     public:
//     vector<string> ans;
//     bool issafe(vector<vector<int>> &m, vector<vector<int>> &vis,int srcx,int srcy,int n){
//         if(srcx>=0 && srcy>=0 && srcx<n && srcy<n && m[srcx][srcy]==1 && !vis[srcx][srcy]){
//             return true;
//         }
//         return false;
//     }
//     void helper(vector<vector<int>> &m, vector<vector<int>> &vis,int n,int srcx,int srcy,string temp){
//         if(srcx==n-1 && srcy==n-1){
//             ans.push_back(temp);
//             return;
//         }
//         vis[srcx][srcy]=1;
//         if(issafe(m,vis,srcx,srcy,n)){
//             helper(m,vis,n,srcx+1,srcy,temp+'D');
//         }
//         if(issafe(m,vis,srcx,srcy,n)){
//             helper(m,vis,n,srcx,srcy-1,temp+'L');
//         }
//         if(issafe(m,vis,srcx,srcy,n)){
//             helper(m,vis,n,srcx,srcy+1,temp+'R');
//         }
//         if(issafe(m,vis,srcx,srcy,n)){
//             helper(m,vis,n,srcx-1,srcy,temp+'U');
//         }
//         vis[srcx][srcy]=0;//backtrack
//         // return;
//     }
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         if(m[0][0]==0) return ans;
//         vector<vector<int>> vis(n,vector<int>(n,0));
//         helper(m,vis,n,0,0,"");
//         return ans;
//     }
// };
// class Solution {
//     void solve(int i,int j,vector<vector<int>> &m,int n,vector<string>&ans,string move,vector<vector<int>> &vis){
//         if(i==n-1 && j==n-1){ //last cell of matrix
//             ans.push_back(move);
//             return;
//         }
//         //down
//         if(i+1<n && !vis[i+1][j] && m[i+1][j]==1){
//             vis[i][j]=1;
//             solve(i+1,j,m,n,ans,move+'D',vis);
//             vis[i][j]=0;
//         }
//         //left
//         if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
//             vis[i][j]=1;
//             solve(i,j-1,m,n,ans,move+'L',vis);
//             vis[i][j]=0;
//         }
//         //right
//         if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
//             vis[i][j]=1;
//             solve(i,j+1,m,n,ans,move+'R',vis);
//             vis[i][j]=0;
//         }
//         //up
//         if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
//             vis[i][j]=1;
//             solve(i-1,j,m,n,ans,move+'U',vis);
//             vis[i][j]=0;
//         }
//     }
//     public:
//     vector<string> findPath(vector<vector<int>> &m,int n){
//         vector<string> ans;
//         vector<vector<int>> vis(n,vector<int>(n,0));
//         if(m[0][0]==1) solve(0,0,m,n,ans,"",vis);
//         return ans;
//     }
// };
 



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