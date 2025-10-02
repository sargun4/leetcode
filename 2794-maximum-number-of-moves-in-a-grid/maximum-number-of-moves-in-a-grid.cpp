class Solution {
public:
    vector<vector<int>>dirns={{-1,1},{0,1},{1,1}};
    //multi src bfs- start frm all 1st col cells to get max moves
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;//{{i,j},ctr}
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){//mark all cells in 1st col vis
            vis[i][0]=1;
            q.push({{i,0},0});//n enqueue the cells- starting pts for bfs
        }
        int maxmoves=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front(); q.pop();
                int x=curr.first.first;
                int y=curr.first.second;
                int ctr=curr.second;
                maxmoves=max(maxmoves,ctr);
                for(auto d:dirns){
                    int nx=x+d[0];
                    int ny=y+d[1];
                    //if next cell isnt vis yet n is strictly greater than the curr cell val- add it 
                    if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && grid[x][y]<grid[nx][ny]){
                        vis[nx][ny]=1;
                        q.push({{nx,ny},ctr+1});
                    }
                }
            }
        }
        return maxmoves;
    }
};