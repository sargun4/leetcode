
#include <bits/stdc++.h>
using namespace std;
//bfs
class Solution {
    public:
     //find min time required to rot all oranges. 
    int orangesRotting(vector < vector < int >> & grid) {
        if(grid.empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
        int time=0,total=0,ctr=0;
        queue<pair<int,int>> rotten;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]!=0) total++; //total count of fresh & rotten oranges
                if(grid[i][j]==2) rotten.push({i,j}); //rotten oranges(2) pushed in queue
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!rotten.empty()){
            int k=rotten.size();
            ctr+=k;
            while(k--){
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){ //4 dirn
                    int neigh_row=x+dx[i];
                    int neigh_col=y+dy[i];
                    if(neigh_row<0|| neigh_row>=m || neigh_col<0 || neigh_col>=n || grid[neigh_row][neigh_col]!=1){//if out of bounds or not a fresh roange, skip
                        continue;
                    }   
                    grid[neigh_row][neigh_col]=2;//rot it
                    rotten.push({neigh_row,neigh_col});
                }
            }
            if(!rotten.empty()) time++;
        }
        return (total==ctr) ? time:-1;
    }
};

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> visited = grid;
//         //queue in which we will fill rotten oranges
//         queue<pair<int, int>> q;
//         int countFreshOrange = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (visited[i][j] == 2) {
//                     q.push({i, j});
//                 }
//                 if (visited[i][j] == 1) {
//                     countFreshOrange++;
//                 }
//             }
//         }
//         //q.empty() means there is no rotten orange in the grid and countFreshOrange = 0 means we will rotten the freshoranges in 0 mins
//         if (countFreshOrange == 0)
//             return 0;
//         if (q.empty())
//             return -1;
//         int time = -1;
//         //four dirns
//         vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
//         while (!q.empty()) {
//             int size = q.size();
//             while (size--) {
//                 auto [x, y] = q.front();
//                 q.pop();
//                 for (auto [dx, dy] : dirs) {
//                     int i = x + dx;
//                     int j = y + dy;
//                     if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
//                         visited[i][j] = 2;
//                         countFreshOrange--;
//                         q.push({i, j});
//                     }
//                 }
//             }
//             time++;
//         }
//         if (countFreshOrange == 0)
//             return time;
//         return -1;
//     }
// };

// class Solution {
//     public:
//       //find min time required to rot all oranges. 
//       int orangesRotting(vector < vector < int >> & grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         // store {{row, column}, time}
//         queue < pair < pair < int, int > , int >> q;
//         int vis[n][m];
//         int cntFresh = 0;
//         for (int i = 0; i < n; i++) {
//           for (int j = 0; j < m; j++) {
//             // if cell contains rotten orange
//             if (grid[i][j] == 2) {
//               q.push({{i, j}, 0}); 
//               // mark as visited (rotten) in visited array
//               vis[i][j] = 2;
//             }
//             // if not rotten
//             else {
//               vis[i][j] = 0;
//             }
//             // count fresh oranges
//             if (grid[i][j] == 1) cntFresh++;
//           }
//         }
//         int tm = 0;
//         // delta row and delta column
//         int drow[] = {-1, 0, +1, 0};
//         int dcol[] = {0, 1, 0, -1}; 
//         int cnt = 0;
//         // bfs traversal (until the queue becomes empty)
//         while (!q.empty()) {
//           int r = q.front().first.first;
//           int c = q.front().first.second;
//           int t = q.front().second;
//           tm = max(tm, t);
//           q.pop();
//           // exactly 4 neighbours 
//           for (int i = 0; i < 4; i++) {
//             // neighbouring row and column
//             int nrow = r + drow[i];
//             int ncol = c + dcol[i];
//             // check for valid cell and 
//             // then for unvisited fresh orange
//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//               vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
//               // push in queue with timer increased
//               q.push({{nrow, ncol}, t + 1}); 
//               // mark as rotten
//               vis[nrow][ncol] = 2;
//               cnt++;
//             }
//           }
//         }
//         // if all oranges are not rotten
//         if (cnt != cntFresh) return -1;
//         return tm;
//     }
// };