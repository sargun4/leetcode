#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    vector<vector<int>> dirn{{0,1},{0,-1},{1,0},{-1,0}}; 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(); 
        n = mat[0].size(); 
        vector<vector<int>> res(m, vector<int>(n, -1)); 
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=00;j<n;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();;
            q.pop();
            int i=p.first;
            int j=p.second;
            for(auto &dir:dirn){
                int nrow=i+dir[0];
                int ncol=j+dir[1];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && res[nrow][ncol]==-1){
                    res[nrow][ncol]=res[i][j]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size(); 
//         int m = mat[0].size(); 
//         // visited and distance matrix
//         vector<vector<int>> vis(n, vector<int>(m, 0)); 
//         vector<vector<int>> dist(n, vector<int>(m, 0)); 
//         // <coordinates, steps>
//         queue<pair<pair<int,int>, int>> q; 
//         // traverse the matrix
//         for(int i = 0;i<n;i++) {
//             for(int j = 0;j<m;j++) {
//                 // start BFS if cell contains 1
//                 if(mat[i][j] == 0) {
//                     q.push({{i,j}, 1}); 
//                     vis[i][j] = 1; 
//                 }
//                 else {
//                     // mark unvisited 
//                     vis[i][j] = 0; 
//                 }
//             }
//         }
//         int delrow[] = {-1, 0, +1, 0}; 
//         int delcol[] = {0, +1, 0, -1}; 
//         // traverse till queue becomes empty
//         while(!q.empty()) {
//             int row = q.front().first.first; 
//             int col = q.front().first.second; 
//             int steps = q.front().second; 
//             q.pop(); 
//             dist[row][col] = steps-1; 
//             // for all 4 neighbours
//             for(int i = 0;i<4;i++) {
//                 int nrow = row + delrow[i]; 
//                 int ncol = col + delcol[i]; 
//                 // check for valid unvisited cell
//                 if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
//                 && vis[nrow][ncol] == 0) {
//                     vis[nrow][ncol] = 1; 
//                     q.push({{nrow, ncol}, steps+1});  
//                 }
//             }
//         }
//         // return distance matrix
//         return dist; 
//     }
// };
