#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod=1e9+7;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool isvalid(int x,int y,vector<vector<int>>&grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size())
            return false;
        return true;
    }
    int dfs(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[x][y]!=-1)
            return dp[x][y];
        int ans=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isvalid(nx,ny,grid) and grid[x][y]>grid[nx][ny]){
                ans=(ans%mod+dfs(nx,ny,grid,dp)%mod);
            }
        }
        return dp[x][y]=ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //dp[i][j]=no of increasing paths starting at (i, j)
        vector<vector<int>> dp(m,vector<int>(n,-1));
        long long ctr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ctr=(ctr%mod+dfs(i,j,grid,dp)%mod)%mod;
            }
        }
        return (int) ctr%mod;
    }
};