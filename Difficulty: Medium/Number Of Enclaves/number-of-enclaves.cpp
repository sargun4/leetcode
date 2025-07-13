#include <bits/stdc++.h>
using namespace std;
 
//bfs-count number of land cells (1s) that are not connected to the boundary
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
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

 

