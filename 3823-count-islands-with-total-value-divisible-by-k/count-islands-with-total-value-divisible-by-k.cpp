class Solution {
public:
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<long long> sumIslands;//sum of each island
        //0-water cell
        vector<vector<int>> vis(m,vector<int>(n,0));//none is vis
        //go over all cells in grid
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //if a new unvis land cell found,start bfs
                if(grid[i][j]!=0 && !vis[i][j]){
                    //bfs for all cells that are not water and r yet to be vis
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;//marked as vis
                    long long sum=0;//stores curr island sum
                    while(!q.empty()){//bfs for curr island
                        auto curr=q.front(); q.pop();
                        int x=curr.first; 
                        int y=curr.second;
                        sum+=grid[x][y];//add cell val
                        for(auto&d:dirns){
                            int nx=x+d[0];
                            int ny=y+d[1];
                            if(isValid(nx,ny,m,n) && grid[nx][ny]>0 && !vis[nx][ny]){
                                q.push({nx,ny});
                                vis[nx][ny]=1;
                            }
                        }
                    }
                    sumIslands.push_back(sum);//1 more island 
                }
            }
        }
        // int numIslands=sumIslands.size();
        int ctr=0;
        for(long long sum:sumIslands){
            if(sum%k==0){
                ctr++;
            }
        }
        return ctr;
    }
};