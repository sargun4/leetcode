class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 &&j<n) 
            return true;
        return false;
    }
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int ans=0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                int temp=0;//curr island area
                if(grid[i][j]==1){//start of an unvis island
                    q.push({i,j});
                    grid[i][j]=2;//mark as vis
                    while(!q.empty()){//bfs
                        int len=q.size();//no of nodes at curr lvl
                        for(int k=0;k<len;k++){
                            auto top = q.front();
                            q.pop();
                            temp++;//1more cell found in curr island
                            int x = top.first;
                            int y = top.second;
                            for(auto &dir:dirns){
                                int nr=x+dir[0];
                                int nc=y+dir[1];
                                //if neigh is valid unvis land cell,visit it
                                if(isvalid(nr,nc,m,n) && grid[nr][nc]==1){
                                    grid[nr][nc]=2;
                                    q.push({nr,nc});
                                }
                            }
                        }
                    }
                } 
                ans=max(ans,temp);  
            }
        }
        return ans;
    }
};