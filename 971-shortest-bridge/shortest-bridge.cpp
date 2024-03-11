#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    bool issafe(int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> dirns={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,queue<pair<int,int>>&q,int i,int j){
        if(!issafe(i,j)||grid[i][j]==0||vis[i][j]==true){
            return;
        }
        vis[i][j]=true;
        q.push({i,j});
        for(auto &dir:dirns){
            int nrow=i+dir[0];
            int ncol=j+dir[1];
            dfs(grid,vis,q,nrow,ncol);
        }
    }
    int shortestBridge(vector<vector<int>>& grid){
        m=grid.size();
        n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        bool found=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ //found 1st island
                    dfs(grid,vis,q,i,j); //dfs on 1st island to put all cells in q to start bfs frm island1
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size-->0){
                auto curr=q.front();
                int i=curr.first;
                int j=curr.second;
                q.pop();
                for(auto &dir:dirns){
                    int nx=i+dir[0];
                    int ny=j+dir[1];
                    if(issafe(nx,ny) && !vis[nx][ny]){
                        if(grid[nx][ny]==1){//as soon as we reach any vis cell that is land=>from island2
                            return steps;
                        }
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
        
    }
};
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int m,n;
//     bool issafe(int i,int j){
//         return i>=0 && i<m && j>=0 && j<n;
//     }
//     vector<vector<int>> dirn={{0,1},{0,-1},{1,0},{-1,0}};
//     void dfs(vector<vector<int>>& grid,int i,int j,queue<pair<int,int>>&vis){
//         if(!issafe(i,j)||grid[i][j]==0||vis.find({i,j})!=vis.end()){
//             return;
//         }
//         vis.insert({i,j});
//         for(auto &dir:dirn){
//             int nrow=i+dir[0];
//             int ncol=j+dir[1];
//             dfs(grid,nrow,ncol,vis);
//         }
//     }
//     int bfs(vector<vector<int>>& grid,queue<pair<int,int>> &vis){
//         queue<pair<int,int>> q;
//         for(auto &it:vis){
//             q.push(it);
//         }
//         int lvl=0;
//         while(!q.empty()){
//             int n=q.size();
//             while(n--){
//                 pair<int,int> p=q.front();
//                 q.pop();
//                 int x=p.first;
//                 int y=p.second;
//                 for(auto &dir:dirn){
//                     int nrow=x+dir[0];
//                     int ncol=y+dir[1];
//                     if(issafe(nrow,ncol) && vis.find({nrow,ncol})==vis.end()){
//                         if(grid[nrow][ncol]==1){//found 2nd lvl
//                             return lvl;
//                         }
//                         vis.insert({nrow,ncol});
//                         q.push({nrow,ncol});
//                     }
//                 }
//             }
//             lvl++;
//         }
//         return lvl;
//     }
//     int shortestBridge(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//         queue<pair<int,int>> vis;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){ //found 1st island
//                     dfs(grid,i,j,vis); //mark all 1 cells of 1st island and store them in vis
//                     return bfs(grid,vis);
//                 }
//             }
//         }
//         return -1;
//     }
// };