#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid,int r,int c){
        if(r>=m||r<0||c>=n||c<0){//out of bounds
            return false;//not closed
        }
        if(grid[r][c]==1){//water cell
            return true; //closed
        }
        grid[r][c]=1; //mark as visited
        bool leftclosed=dfs(grid,r,c-1);
        bool rightclosed=dfs(grid,r,c+1);
        bool upclosed=dfs(grid,r-1,c);
        bool downclosed=dfs(grid,r+1,c);
        //closed frm all 4 sides
        return leftclosed && rightclosed && upclosed && downclosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ctr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)==true){
                        ctr++;
                    }
                }
            }
        }
        return ctr;
    }
};