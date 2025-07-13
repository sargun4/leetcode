#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,pair<int,int>>> q;//{dist,{x,y}}
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9)); //2d dist arr
        int s_row=source.first;
        int s_col=source.second;
        dist[s_row][s_col]=0;
        q.push({0,{s_row,s_col}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                //in bounds, cell=1, newdist<prev dist stored in dist mat
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && grid[nrow][ncol]!=0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    if(nrow==destination.first && ncol==destination.second){
                        return dis+1;//ans
                    }
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        if(source.first==destination.first && source.second==destination.second){
            return 0;
        } 
        return -1;
    }
};

 


