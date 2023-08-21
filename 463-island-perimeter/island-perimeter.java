class Solution {
    int ctr=0;
    public int islandPerimeter(int[][] grid) {
        ctr=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    break;
                }
            }
        }
        return ctr;
    }
    private void dfs(int[][] grid,int i,int j){
        if(i<0||i>=grid.length||j<0||j>=grid[i].length||grid[i][j]==0){
            ctr++;
            return;
        }
        if(grid[i][j]==-1)return;
        grid[i][j]=-1;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i,j-1);
    }
}