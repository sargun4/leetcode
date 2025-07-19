// //bfs
// class Solution {
// public:

//     int findMaxFish(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//         vector<vector<int>> vis(m,vector<int>(n,0));
//     }
// };
//dfs
class Solution {
public:
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
    int dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
        if(i<0||j<0||i>=m||j>=n||vis[i][j]) return 0;
        vis[i][j]=1;
        int ans=0;
        for(auto&d:dirns){
            int x=i+d[0];
            int y=j+d[1];
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