class Solution {
public:
    int n;
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    //dfs to label the island and compute its size
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis,int id){
        //if we go out of bounds or cell=0(water) or cell alr vis, 
        if(!isValid(i,j,n,n) || grid[i][j]==0 || vis[i][j]==true){
            return 0;
        }
        grid[i][j]=id;//same id assigned to all cells in that island
        vis[i][j]=true;
        int size=1;
        for(vector<int>&d:dirns){
            int nx=i+d[0];
            int ny=j+d[1];
            size+=dfs(grid,nx,ny,vis,id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid){
        n=grid.size();//row=col=n
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int maxarea=0;
        int id=2;//unique id of island-(since grid already has 0 and 1)
        unordered_map<int,int> map;//{id:size_island}
        // **Step 1: Label all islands and record their sizes**
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int size=dfs(grid,i,j,vis,id);
                    maxarea=max(maxarea,size);//track of largest existing island
                    map[id]=size;
                    id++;
                }
            }
        }
        // **Step 2: Try flipping each 0 and compute new island size**
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){//try converting all the 0 cells to unique id cells
                    unordered_set<int> unique_ids;
                    for(auto&d:dirns){
                        int nx=i+d[0];
                        int ny=j+d[1];
                        if(isValid(nx,ny,n,n)&& grid[nx][ny]!=0){
                            unique_ids.insert(grid[nx][ny]);
                        }
                    }
                    int overallsize=1;
                    for(auto &id:unique_ids){
                        overallsize+=map[id];
                    }
                    maxarea=max(maxarea,overallsize);
                }
            }
        }
        return maxarea;
    }
};