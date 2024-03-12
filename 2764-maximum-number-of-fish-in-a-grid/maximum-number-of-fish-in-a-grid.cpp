
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int m,n;
    int dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
        if(i<0||j<0||i>=m||j>=n||vis[i][j]) return 0;
        vis[i][j]=1;
        int ans=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x<m && x>=0 && y<n && y>=0 && !vis[x][y] && grid[x][y]){
                ans+=grid[x][y]+dfs(x,y,vis,grid);
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int maxfish=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    maxfish=max(maxfish,grid[i][j]+dfs(i,j,vis,grid));
                }
            }
        }
        return maxfish;
    }
};