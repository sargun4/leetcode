// // //dfs
// // #include <bits/stdc++.h>
// // using namespace std;
// // class Solution {
// // public:
// //     bool isvalid(int i,int j,int n,int m,vector<vector<char>>& grid){
// //         if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1'){
// //             return true;
// //         }
// //         return false;
// //     }
// //     void countIslands(int i,int j,int n,int m,vector<vector<char>>& grid){
// //         grid[i][j]='0';
// //         if(isvalid(i+1,j,n,m,grid))
// //             countIslands(i+1,j,n,m,grid);
// //         if(isvalid(i-1,j,n,m,grid))
// //             countIslands(i-1,j,n,m,grid);
// //         if(isvalid(i,j+1,n,m,grid))
// //             countIslands(i,j+1,n,m,grid);
// //         if(isvalid(i,j-1,n,m,grid))
// //             countIslands(i,j-1,n,m,grid);
// //     }
// //     int numIslands(vector<vector<char>>& grid) {
// //         int n=grid.size();
// //         int m=grid[0].size();
// //         int ans=0;
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<m;j++){
// //                 if(grid[i][j]=='1'){
// //                     ans++;
// //                     countIslands(i,j,n,m,grid);
// //                 }
// //             }
// //         }
// //         return ans;
// //     }
// // };
//bfs
//T: O(row * col)
//S: O(col)
class Solution {
public:
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, col>
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
};
// class Solution {
// public:
//     bool isValid(int i,int j,int m,int n){
//         return i>=0 && j>=0 && i<m && j<n;
//     }
//     vector<vector<int>> dirns={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//<row, col>
//     void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
//         int m=grid.size();
//         int n=grid[0].size();
//         vis[i][j]=1;//mark as vis
//         queue<pair<int,int>> q;
//         q.push({i,j});
//         while(!q.empty()){
//             auto [x,y]=q.front(); q.pop();
//             for(auto &d:dirns){
//                 int nx=x+d[0];
//                 int ny=y+d[1];
//                 if(isValid(nx,ny,m,n) && grid[i][j]=='1'){//in bounds n land
//                     q.push({nx,ny});
//                     vis[nx][ny]=1;//mark as vis
//                 }
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid){
//         if(grid.empty())
//             return 0;
//         int m=grid.size();
//         int n=grid[0].size();
//         int ctr=0;
//         vector<vector<int>> vis(m,vector<int>(n,0));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(!vis[i][j]){//not yet vis
//                     ctr++;//1 island more
//                     bfs(i,j,vis,grid);
//                 }
//             }
//         }
//         return ctr;
//     }
// };
