#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    bool issafe(int i,int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> dirn={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid,int i,int j,set<pair<int,int>>&vis){
        if(!issafe(i,j)||grid[i][j]==0||vis.find({i,j})!=vis.end()){
            return;
        }
        vis.insert({i,j});
        for(auto &dir:dirn){
            int nrow=i+dir[0];
            int ncol=j+dir[1];
            dfs(grid,nrow,ncol,vis);
        }
    }
    int bfs(vector<vector<int>>& grid,set<pair<int,int>> &vis){
        queue<pair<int,int>> q;
        for(auto &it:vis){
            q.push(it);
        }
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                for(auto &dir:dirn){
                    int nrow=x+dir[0];
                    int ncol=y+dir[1];
                    if(issafe(nrow,ncol) && vis.find({nrow,ncol})==vis.end()){
                        if(grid[nrow][ncol]==1){//found 2nd lvl
                            return lvl;
                        }
                        vis.insert({nrow,ncol});
                        q.push({nrow,ncol});
                    }
                }
            }
            lvl++;
        }
        return lvl;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        set<pair<int,int>> vis;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ //found 1st island
                    dfs(grid,i,j,vis); //mark all 1 cells of 1st island and store then in vis
                    return bfs(grid,vis);
                }
            }
        }
        return -1;
    }
};