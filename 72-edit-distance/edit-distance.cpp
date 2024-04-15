// class Solution {
//  public:
//   int minDistance(string word1, string word2) {
//     const int m = word1.length();//first word length
//     const int n = word2.length();//second word length
//     // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1));

//     for (int i = 1; i <= m; ++i)
//       dp[i][0] = i;

//     for (int j = 1; j <= n; ++j)
//       dp[0][j] = j;

//     for (int i = 1; i <= m; ++i)
//       for (int j = 1; j <= n; ++j)
//         if (word1[i - 1] == word2[j - 1])//same characters
//           dp[i][j] = dp[i - 1][j - 1];//no operation
//         else
//           dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
//                              //replace       //delete        //insert
//     return dp[m][n];
//   }
// };
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int idx1, int idx2, string word1, string word2) {
        if(idx1 < 0)
            return idx2+1;
        if(idx2 < 0)
            return idx1+1;

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if(word1[idx1] == word2[idx2])
            return dp[idx1][idx2] = 0 + solve(idx1-1, idx2-1, word1, word2);            

        int insert = 1 + solve(idx1, idx2-1, word1, word2);
        int del = 1 + solve(idx1-1, idx2, word1, word2);
        int replace = 1 + solve(idx1-1, idx2-1, word1, word2);

        return dp[idx1][idx2] = min({insert, del, replace});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(n-1, m-1, word1, word2);
    }
};