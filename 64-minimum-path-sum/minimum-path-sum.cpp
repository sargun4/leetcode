#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int solve(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>&t){
//         if(i==m-1 && j==n-1){
//             return grid[i][j];
//         }
//         if(t[i][j]!=-1){
//             return t[i][j];
//         }
//         if(i==m-1){ //last row- can only go right
//             return t[i][j]=grid[i][j]+solve(grid,i,j+1,m,n,t);
//         }else if(j==n-1){//last col- can only go down
//             return t[i][j]=grid[i][j]+solve(grid,i+1,j,m,n,t);
//         }else{
//             return t[i][j]=grid[i][j]+min(solve(grid,i,j+1,m,n,t),solve(grid,i+1,j,m,n,t));
//         }
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();

//         vector<vector<int>> t(m+1,vector<int>(n+1,-1));
//         return solve(grid,0,0,m,n,t);
//     }
// };

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> t(m,vector<int>(n));
        //t[i][j]=min path sum to  reach(i,j) frm (0,0)
        t[0][0]=grid[0][0];
        //fill 1st col
        for(int i=1;i<m;i++){
            t[i][0]=t[i-1][0]+grid[i][0];
        }
        //fill 1st row
        for(int j=1;j<n;j++){
            t[0][j]=t[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                t[i][j]=min(t[i-1][j],t[i][j-1])+grid[i][j];
            }
        }
        return t[m-1][n-1];
    }
};