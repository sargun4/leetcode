class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            //traverse neighbors 8dirns and mark if land
            for(int drow=-1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){
                    int nrow=row+drow;
                    int ncol=col+dcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                     && grid[nrow][ncol]=='L' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }

        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ctr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='L'){
                    ctr++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return ctr;
    }
};