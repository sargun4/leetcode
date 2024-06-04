// //bfs
// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid){
//         int m= grid.size();
//         int n = grid[0].size();
//         int ctr = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1) {//land
//                     int dr[4] = {1, 0, -1, 0};
//                     int dc[4] = {0, 1, 0, -1};
//                     for (int i = 0; i < 4; i++) {
//                         int nr = i + dr[i];
//                         int nc = j + dc[i];
//                         // If the new position is out of bounds or represents water (value is 0)
//                         // then it contributes 1 to the perimeter ctr
//                         if (!(nr >= 0 && nr < m && nc= 0 && nc < n) || grid[nr][nc] == 0) {
//                             ctr++;
//                         }
//                     }
//                 }
//             }
//         }
//         return ctr
//     }
// };

//dfs
class Solution {
public:
    int ctr;
    int islandPerimeter(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        ctr = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){//land
                    dfs(grid,i,j);
                    break;
                }
            }
        }
        return ctr;
    }
    void dfs(vector<vector<int>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        // If a cell is out of bounds or is water (0), it contributes 1 to the perimeter (since water cells hv an exposed border).
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0){//if outside bounds or water
            ctr++;
            return;
        }
        // If a cell is land (1), we mark it as visited by changing its value to -1 to avoid recounting, then rec explore its 4 nghbring cells.
        if(grid[i][j]==-1 ) return;
        grid[i][j]=-1;
        //4dirns
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i,j-1);
    }
};