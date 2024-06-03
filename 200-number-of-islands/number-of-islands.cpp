// //dfs
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     bool isvalid(int i,int j,int n,int m,vector<vector<char>>& grid){
//         if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1'){
//             return true;
//         }
//         return false;
//     }
//     void countIslands(int i,int j,int n,int m,vector<vector<char>>& grid){
//         grid[i][j]='0';
//         if(isvalid(i+1,j,n,m,grid))
//             countIslands(i+1,j,n,m,grid);
//         if(isvalid(i-1,j,n,m,grid))
//             countIslands(i-1,j,n,m,grid);
//         if(isvalid(i,j+1,n,m,grid))
//             countIslands(i,j+1,n,m,grid);
//         if(isvalid(i,j-1,n,m,grid))
//             countIslands(i,j-1,n,m,grid);
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]=='1'){
//                     ans++;
//                     countIslands(i,j,n,m,grid);
//                 }
//             }
//         }
//         return ans;
//     }
// };
//bfs
//T: O(row * col)
//S: O(col)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int ctr = 0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j <n; ++j) {
                if(grid[i][j] == '1') {//land
                    ctr++;
                    queue<pair<int, int>> q;//<row, col>
                    grid[i][j] = '2';//mark as vis
                    q.push({i,j});
                    while(!q.empty()) {
                        pair<int, int> vis_cell = q.front();
                        q.pop();
                        for(auto d : dir) {
                            int nr = vis_cell.first + d.first;
                            int nc = vis_cell.second + d.second;
                            if(nr >= 0 && nr < m && nc >= 0 && nc <n && grid[nr][nc] == '1') {//if valid cell and land
                                grid[nr][nc] = '2';//mark as vis
                                q.push({nr,nc});
                            }
                        }
                    }
                }   
            }  
        }
        return ctr;
    }
private:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, col>
};

// class Solution {
// public:
//     //dfs + recursive
//     //T: O(row * col)
//     //S: O(row)
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.empty())
//             return 0;
//         int ctr = 0;
//         for(int m = 0; m < grid.size(); ++m) {
//             for(int n = 0; n < grid[0].size(); ++n) {
//                 if(grid[m][n] == '1') {
//                     ++ctr;
//                     dfs(grid, m, n);//use dfs to mark every grid = 2 which belongs to this island.
//                 }   
//             }  
//         }
//         return ctr;
//     }
// private:
//     //dfs to mark every grid in this island.
//     int dfs(vector<vector<char>>& grid, int m, int n) {
//         grid[m][n] = '2';
//         for(auto d : dir) {
//             int nr = m + d.first;
//             int nc = n + d.second;
//             if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1') {
//                 dfs(grid, nr, nc);
//             }   
//         }
//         return 0;
//     }
// private:
//     vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<m, col>
// };