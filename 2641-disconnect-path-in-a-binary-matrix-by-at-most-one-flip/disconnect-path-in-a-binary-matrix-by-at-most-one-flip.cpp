class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        //reached bottom-right
        if(i==m-1 && j==n-1) return true;
        // mark as visited (flip to 0 temporarily)
        grid[i][j]=0;
        //try right and down
        if(i+1<m && grid[i+1][j]==1 && dfs(grid,i+1,j)) return true;
        if(j+1<n && grid[i][j+1]==1 && dfs(grid,i,j+1)) return true;
        return false;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        // 1st DFS: remove the first path from (0,0) to (m-1,n-1)
        dfs(grid, 0, 0);//dfs(grid,0,0) explores the original path frm top-left to bottom-right n removes it (flips 1s to 0s)
        // 2nd DFS: see if another path still exists
        return !dfs(grid, 0, 0);
    }
};
