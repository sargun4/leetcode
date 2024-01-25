// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         int dp[m+1][n+1];
//         memset(dp, 0, sizeof(dp));
//         for(int i=1; i<=m; ++i) {
//             for(int j=1; j<=n; ++j) {
//                 if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
//                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[m][n];
//     }
// };
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int row=0;row<m+1;row++){
            dp[row][0]=0;
        }
        for(int col=0;col<n+1;col++){
            dp[0][col]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};