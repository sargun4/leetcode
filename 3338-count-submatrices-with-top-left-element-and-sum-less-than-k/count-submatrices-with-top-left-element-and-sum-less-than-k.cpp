#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;  
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>0) grid[i][j] += grid[i-1][j];
                if(j>0) grid[i][j] += grid[i][j-1];
                if(i>0 && j>0) grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k) res++;
                else break;
            }
        } 
        return res; 
    }
};
//tle
// class Solution {
// public:  
// void printMatrix(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 cout << mat[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
//     int countSubmatrices(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int ans = 0;
//         // Create a prefix sum grid
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0){
//                     dp[i][j]=grid[i][j];
//                 }else if(i==0){
//                     dp[i][j] += dp[i][j-1]+grid[i][j];
//                 }else if(j==0){
//                     dp[i][j] += dp[i-1][j]+grid[i][j];
//                 }else {
//                     dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];
//                 }
//                 if(dp[i][j]<=k) ans++;
//             }
//         }
//         printMatrix(dp);
//         return ans;
//     }
// };
