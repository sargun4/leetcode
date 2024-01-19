// https://leetcode.com/problems/minimum-falling-path-sum/?envType=daily-question&envId=2024-01-19
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(); int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
            dp[0][i]= matrix[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int minval=INT_MAX;
                if(i-1>=0) minval=min(minval,dp[i-1][j]);
                if(i-1>=0 && j-1>=0) minval=min(minval,dp[i-1][j-1]);
                if(i-1>=0 && j+1<m) minval=min(minval,dp[i-1][j+1]);
                dp[i][j] = matrix[i][j]+minval;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};