#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }
        if (dp[i][j] > 0) return dp[i][j];
        int currmax = 1;

        // down neighbor
        if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
            currmax = max(currmax, 1 + dfs(matrix, i + 1, j, dp));
        }
        // up neighbor
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            currmax = max(currmax, 1 + dfs(matrix, i - 1, j, dp));
        }
        // right neighbor
        if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
            currmax = max(currmax, 1 + dfs(matrix, i, j + 1, dp));
        }
        // left neighbor
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            currmax = max(currmax, 1 + dfs(matrix, i, j - 1, dp));
        }
        dp[i][j] = currmax;
        return currmax;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxlen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxlen = max(maxlen, dfs(matrix, i, j, dp));
            }
        }
        return maxlen;
    }
};
