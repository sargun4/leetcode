#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    vector<vector<int>> dirns={{1,0},{0,1},{-1,0},{0,-1}};
    bool isvalid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n){
            return true;
        }
        return false;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        m = matrix.size();
        if(!m) return 0;
        n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        queue<pair<int,int>> q;//{x,y}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto&d:dirns){
                    int x=i+d[0];
                    int y=j+d[1];
                    if(isvalid(x,y,m,n) && matrix[x][y]<matrix[i][j]) //incresing path(end)
                            indegree[i][j]++;//i,j depends on smaller neighbor
                }
                //if no smaller neighbors for this cell, it's a starting point
                if(!indegree[i][j]){ //incresing path(start)
                    q.push({i,j});
                }
            }
        }
        int maxlen=0;
        // Cells with indegree 0 are starting points of increasing paths.
        //bfs using topo sort-kahns
        while(!q.empty()){
            int len = q.size();
            while(len--){
                pair<int,int> curr = q.front();//curr matrix cell
                int i=curr.first;
                int j=curr.second;
                q.pop();
                for(auto &d: dirns){//4dirns
                    int x=i+d[0];
                    int y=j+d[1];
                    if(isvalid(x,y,m,n) && matrix[x][y]>matrix[i][j]){
                // If neighbor is strictly larger, it depends on the curr node
                        if (--indegree[x][y] == 0)
                            q.push({x,y});
                    }
                }
            }
            maxlen++;
        }
        return maxlen;
    }
};


//dfs
// class Solution {
// public:
//     int m, n;

//     int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp) {
//         if (i < 0 || j < 0 || i >= m || j >= n) {
//             return 0;
//         }
//         if (dp[i][j] > 0) return dp[i][j];
//         int currmax = 1;

//         // down neighbor
//         if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
//             currmax = max(currmax, 1 + dfs(matrix, i + 1, j, dp));
//         }
//         // up neighbor
//         if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
//             currmax = max(currmax, 1 + dfs(matrix, i - 1, j, dp));
//         }
//         // right neighbor
//         if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
//             currmax = max(currmax, 1 + dfs(matrix, i, j + 1, dp));
//         }
//         // left neighbor
//         if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
//             currmax = max(currmax, 1 + dfs(matrix, i, j - 1, dp));
//         }
//         dp[i][j] = currmax;
//         return currmax;
//     }

//     int longestIncreasingPath(vector<vector<int>> &matrix) {
//         m = matrix.size();
//         n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         int maxlen = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 maxlen = max(maxlen, dfs(matrix, i, j, dp));
//             }
//         }
//         return maxlen;
//     }
// };
