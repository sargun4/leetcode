//memoization
class Solution {
public:
    int m,n;
    int t[101][101];
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==1){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j]; 
        }
        if(i==m-1 && j==n-1) return 1;
        int right=solve(grid,i,j+1);
        int down=solve(grid,i+1,j);
        return t[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return solve(obstacleGrid,0,0);
    }
};