class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx1, int idx2, string word1, string word2) {
    // If 1st string is empty, the only option is to
    // insert all characters of 2nd string into 1st
        if(idx1 < 0)
            return idx2+1;
    // If 2nd string is empty, the only option is to
    // insert all characters of 1st string into 2nd
        if(idx2<0)
            return idx1+1;

        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
//if last chars r equal, no operation is needed for these positions-just solve for remaing part
        if(word1[idx1] == word2[idx2])
            return dp[idx1][idx2] = 0 + solve(idx1-1, idx2-1, word1, word2);     
//3cases       
    //insert word2[idx2] into word-this fixes the last char of word2, but idx1 stays the same,so move idx2 1 step left
        int insert = 1 + solve(idx1, idx2-1, word1, word2);
    //Delete word1[idx1]. This moves idx1 left, but idx2 stays the same.
        int del = 1 + solve(idx1-1, idx2, word1, word2);
    //Replace word1[idx1] with word2[idx2]-Move both indices left.
        int replace = 1 + solve(idx1-1, idx2-1, word1, word2);

        return dp[idx1][idx2] = min({insert, del, replace});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(n-1, m-1, word1, word2);
    }
};
// class Solution {
//  public:
//   int minDistance(string word1, string word2) {
//     int m = word1.length();//1st word length
//     int n = word2.length();//second word length
//     // dp[i][j] := min no of operations to convert word1[0..i) to word2[0..j)
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