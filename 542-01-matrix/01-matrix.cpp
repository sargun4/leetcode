// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int m,n;
//     vector<vector<int>> dirn{{0,1},{0,-1},{1,0},{-1,0}}; 
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         m = mat.size(); 
//         n = mat[0].size(); 
//         vector<vector<int>> res(m, vector<int>(n, -1)); 
//         queue<pair<int,int>> q;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==0){
//                     res[i][j]=0;
//                     q.push({i,j});
//                 }
//             }
//         }
//         while(!q.empty()){
//             pair<int,int> p=q.front();;
//             q.pop();
//             int i=p.first;
//             int j=p.second;
//             for(auto &dir:dirn){
//                 int nx=i+dir[0];
//                 int ny=j+dir[1];
//                 //valid cell & not yet vis
//                 if(nx>=0 && nx<m && ny>=0 && ny<n && res[nx][ny]==-1){
//                     res[nx][ny]=res[i][j]+1;
//                     q.push({nx,ny});
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 
        // vis n dist matrix
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        vector<vector<int>> dist(n, vector<int>(m, 0)); 
        queue<pair<pair<int,int>, int>> q; //{{x,y}, steps}
        // traverse the matrix
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                //start BFS if cell contains 1
                if(mat[i][j]==0) {
                    q.push({{i,j},1}); 
                    vis[i][j]=1; 
                }
                else {
                    // mark unvisited 
                    vis[i][j]=0; 
                }
            }
        }
        int dx[] = {-1, 0, +1, 0}; 
        int dy[] = {0, +1, 0, -1}; 
        // traverse till queue becomes empty
        while(!q.empty()) {
            int x = q.front().first.first; 
            int y = q.front().first.second; 
            int steps = q.front().second; 
            q.pop(); 
            dist[x][y] = steps-1; 
            // for all 4 neighbours
            for(int i=0;i<4;i++) {
                int nx = x + dx[i]; 
                int ny = y + dy[i]; 
                //valid unvisited cell
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
                    vis[nx][ny] = 1; 
                    q.push({{nx, ny}, steps+1});  
                }
            }
        }
        // return distance matrix
        return dist; 
    }
};
