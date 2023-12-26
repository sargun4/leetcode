// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int MOD=1e9+7;
//     int dp[31][1001];
//     int solve(int n, int k, int target){
//         if(target<0){
//             return 0;
//         }
//         if(dp[n][target]!=-1){
//             return dp[n][target];
//         }
//         if (n == 0){
//             return target==0;
//         }
//         int ways=0;
//         for(int face=1;face<=k;face++){
//             ways=(ways+solve(n-1,k,target-face))%MOD;
//         }
//         return dp[n][target]= ways;
//     }
//     int numRollsToTarget(int n, int k, int target) {
//         memset(dp,-1,sizeof(dp));
//         return solve(n,k,target);
//     }
// };

// bottom up
// #dp[i][j]=no of ways to sum=j with i dices
class Solution {
public:
    int MOD=1e9+7;
    int dp[31][1001]; 
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                //i = no of dice, j = target
                int ways=0;
                for(int face=1;face<=k;face++){
                    if(j>=face){
                        ways=(ways+dp[i-1][j-face])%MOD;
                    }
                }
                dp[i][j]=ways;
            }
        }
        return dp[n][target];
    }
};