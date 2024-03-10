#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=0) return ;
        grid[i][j]=1;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            dfs(nx,ny,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||j==n-1||i==m-1) && grid[i][j]==0){
                    dfs(i,j,grid);
                }
            }
        }
        int ctr=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    ctr++;
                }
            }
        }
        return ctr;
    }
};
// class Solution {
// public:
//     int m,n;
//     bool dfs(vector<vector<int>>& grid,int r,int c){
//         if(r>=m||r<0||c>=n||c<0){//out of bounds
//             return false;//not closed
//         }
//         if(grid[r][c]==1){//water cell
//             return true; //closed
//         }
//         grid[r][c]=1; //mark as visited
//         bool leftclosed=dfs(grid,r,c-1);
//         bool rightclosed=dfs(grid,r,c+1);
//         bool upclosed=dfs(grid,r-1,c);
//         bool downclosed=dfs(grid,r+1,c);
//         //closed frm all 4 sides
//         return leftclosed && rightclosed && upclosed && downclosed;
//     }
//     int closedIsland(vector<vector<int>>& grid) {
//         m=grid.size();
//         n=grid[0].size();
//         int ctr=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==0){
//                     if(dfs(grid,i,j)==true){
//                         ctr++;
//                     }
//                 }
//             }
//         }
//         return ctr;
//     }
// };