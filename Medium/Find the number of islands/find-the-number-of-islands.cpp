//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<char>>& grid ,int vis[][501] , int i , int j,int rows,int cols){
        if(i<0 or j<0 or i>=rows or j>=cols){
            return;
        }
        if (grid[i][j] == '0') return;
        if(!vis[i][j]){
            vis[i][j]=1;
            dfs(grid,vis,i+1,j,rows,cols);
            dfs(grid,vis,i-1,j,rows,cols);
            dfs(grid,vis,i,j+1,rows,cols);
            dfs(grid,vis,i,j-1,rows,cols); 
            dfs(grid,vis,i+1,j+1,rows,cols);//down right
            dfs(grid,vis,i-1,j-1,rows,cols);//up left
            dfs(grid,vis,i+1,j-1,rows,cols);//up right
            dfs(grid,vis,i-1,j+1,rows,cols);//down left
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int vis[501][501];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=0;
            }
        }
        int ctr=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    dfs(grid,vis,i,j,rows,cols);
                    ctr++;
                }
            }
        }
        return ctr;
    }
};
  
// class Solution {
//   public:
//     void dfs(vector<vector<char>>& grid , vector<vector<bool>>&vis , int i , int j){
//         int rows=grid.size();
//         int cols=grid[0].size();
//         vis[i][j]=true;
//         if(i-1 >= 0 && j+1 < cols && grid[i-1][j+1]=='1' && vis[i-1][j+1]==false){
//             dfs(grid , vis , i-1 , j+1);
//         }
//         if(i+1 < rows && j-1 >= 0 && grid[i+1][j-1]=='1' && vis[i+1][j-1]==false){
//             dfs(grid , vis , i+1 , j-1);
//         }
//         if(i+1 < rows && j+1 < cols && grid[i+1][j+1]=='1' && vis[i+1][j+1]==false){
//             dfs(grid , vis , i+1 , j+1);
//         }
//         if(i+1 < rows && j < cols && grid[i+1][j]=='1' && vis[i+1][j]==false){
//             dfs(grid , vis , i+1 , j);
//         }
//         if(j+1 < cols && grid[i][j+1]=='1' && vis[i][j+1]==false){
//             dfs(grid , vis , i , j+1);
//         }
//         if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1]=='1' && vis[i-1][j-1]==false){
//             dfs(grid , vis , i-1 , j-1);
//         }
//         if(i-1 >= 0  && grid[i-1][j]=='1' && vis[i-1][j]==false){
//             dfs(grid , vis , i-1 , j);
//         }
//         if(j-1 >= 0 && grid[i][j-1]=='1' && vis[i][j-1]==false){
//             dfs(grid , vis , i , j-1);
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         vector<vector<bool>> vis(rows,vector<bool>(cols,false));
//         int ans=0;
//         for(int i=0 ; i<rows ; i++){
//             for(int j=0 ; j< cols ; j++){
//                 if(vis[i][j]==false && grid[i][j]=='1'){
//                     dfs(grid , vis , i , j);
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };
 

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends