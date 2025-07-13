//bfs-count number of land cells (1s) that are not connected to the boundary
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;//{x,y}
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //1st row, 1st col, last row, last col]            
                // If it's a land cell and on the boundary, it cannot be enclosed
                if(i==0||j==0||i==n-1||j==m-1){//boundary cells
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1; 
                }
            }
        }
        int ctr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
        // If it's a land cell and was never reached from boundary
                if(grid[i][j]==1 && vis[i][j]==0){
                    ctr++;
                }
            }
        }
        return ctr;//no of enclaved land cells
    }
};
// //dfs
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int m,n;
//     void dfs(vector<vector<int>>& grid,int i,int j){
//         if(i<0||i>=m||j<0||j>=n||grid[i][j]==0){
//             return;
//         }
//         grid[i][j]=0;
//         dfs(grid,i,j+1);
//         dfs(grid,i,j-1);
//         dfs(grid,i+1,j);
//         dfs(grid,i-1,j);
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//         //apply dfs on 1st n last col
//         for(int row=0;row<m;row++){
//             if(grid[row][0]==1){
//                 dfs(grid,row,0);
//             }
//             if(grid[row][n-1]==1){
//                 dfs(grid,row,n-1);
//             }
//         }
//         //apply dfs on 1st n last row
//         for(int col=0;col<m;col++){
//             if(grid[0][col]==1){
//                 dfs(grid,0,col);
//             }
//             if(grid[m-1][col]==1){
//                 dfs(grid,m-1,col);
//             }
//         }
//         int ctr=0;
//         //count 1s
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     ctr++;
//                 }
//             }
//         }
//         return ctr;
//     }
// };