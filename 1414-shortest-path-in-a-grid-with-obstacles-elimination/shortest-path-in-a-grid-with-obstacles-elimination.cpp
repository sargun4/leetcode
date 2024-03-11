#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // q={i,j,e} e-eliminating power left for that cell
        queue<vector<int>>q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(k+1)));
        int steps=0;
        q.push({0,0,k}); //intitally k elminating power left at top left cell
        vector<vector<int>> dirns={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            while(size-- >0){
                vector<int> curr=q.front();
                q.pop();
                int x=curr[0];
                int y=curr[1];
                if(x==m-1 && y==n-1){//when we reach botomright cell
                    return steps;
                }
                for(vector<int> &d:dirns){
                    int i=x+d[0];
                    int j=y+d[1];
                    int obstacle=curr[2];
                    if(i>=0 && i<m && j>=0 && j<n){//if valid cell
                        if(grid[i][j]==0 && !vis[i][j][obstacle]){//if not an obstacle and not yet vis
                            q.push({i,j,obstacle});
                            vis[i][j][obstacle]=true;
                        }else if(grid[i][j]==1 && obstacle>0 && !vis[i][j][obstacle-1]){//if not an obstacle and not
                            q.push({i,j,obstacle-1});
                            vis[i][j][obstacle-1]=true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};