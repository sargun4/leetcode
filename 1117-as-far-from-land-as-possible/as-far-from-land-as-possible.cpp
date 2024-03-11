#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        vector<vector<int>> vis=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.empty()|| q.size()==n*n){ //if no land cell or o water cell
            return -1; 
        }
        int dist=0;
        vector<pair<int,int>> dirns={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:dirns){
                    int nx=x+dx;
                    int ny=y+dy;
                    if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0){//in bounds and not yet vis
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            dist++;
        }
        return dist-1;
    }
};