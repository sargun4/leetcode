// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    // DFS to collect relative positions of each land cell in the island
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,vector<pair<int,int>>&vec,int row0,int col0){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
     // Store position relative to starting cell (row0, col0)
        vec.push_back({row-row0,col-col0});
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            // Check bounds, not visited, and land cell
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,vec,row0,col0);
            }
        } 
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); 
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;//set of island shapes
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    s.insert(vec);//add normalised shapes
                }
            }
        }
        return s.size();// count if distinct island shapes
    }
};   

