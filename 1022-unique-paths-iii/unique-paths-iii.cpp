#include <bits/stdc++.h>
using namespace std;  
class Solution {
public:
    int m,n;
    int res;
    int nonObstacles; //no of non-obstacle cells

    void backtrack(vector<vector<int>>& grid,int ctr,int i,int j){
        //out of bounds or an obstacle,return 
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==-1){
            return;
        }        
        // if we reach the dest(2) and have visited all non-obstacle cells,
        // increment the result count 
        if(grid[i][j]==2){
            if(ctr==nonObstacles)
                res++;
            return;
        }
        //mark the cell as visited w -1 and move to next cell
        grid[i][j]= -1;
        //try all four directions
        backtrack(grid,ctr+1,i+1,j);//down
        backtrack(grid,ctr+1,i-1,j);//up
        backtrack(grid,ctr+1,i,j+1);//right
        backtrack(grid,ctr+1,i,j-1);//left
        //back track by marking the cell as empty again
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        res=0;
        nonObstacles=0;
        int start_x=0,start_y=0;
        // count non-obstacle cells and find the starting point
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    nonObstacles++;
                }
                if(grid[i][j]==1){
                    nonObstacles++;
                    start_x=i;
                    start_y=j;
                }
            }
        }
        int ctr=0;
        backtrack(grid,ctr,start_x,start_y);
        return res;
    }
};