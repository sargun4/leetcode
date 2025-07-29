class Solution {
public:
    int n;
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    //dfs to label the island and compute its size
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis,int id){
        //if not in bounds or cell=0(water) or cell alr vis
        if(!isValid(i,j,n,n)|| grid[i][j]==0||vis[i][j]==true){
            return 0;
        }
        grid[i][j]=id;//same id assigned to all cells in that islnd
        vis[i][j]=true;
        int size=1;
        for(auto&d:dirns){
            int nx=i+d[0];
            int ny=j+d[1];
            size+=dfs(grid,nx,ny,vis,id);
        }
        return size;//size of isalnd
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();//row=col=n
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int maxarea=0;
        int id=2;//unique id of island-since grid alr has 0 n 1
        unordered_map<int,int> map;//{id:island_size}
        //1. label all islands n record their sizes
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int size=dfs(grid,i,j,vis,id);
                    maxarea=max(maxarea,size);//track of largest exisiting island in grid
                    map[id]=size;
                    id++;//for each diff island, a diff unique id assgined
                }
            }
        }
        //2. try flipping each 0 n compute new island size
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){//try convertin all 0 cells to unique id
                    unordered_set<int> unique_ids;
                    for(auto&d:dirns){
                        int nx=i+d[0];
                        int ny=j+d[1];
                        if(isValid(nx,ny,n,n) && grid[nx][ny]!=0){
                            unique_ids.insert(grid[nx][ny]);
                        }
                    }
                    int overallsize=1;
                    for(auto&id:unique_ids){
                        overallsize+=map[id];
                    }
                    maxarea=max(maxarea,overallsize);
                }
            }
        }
        return maxarea;
    }
};