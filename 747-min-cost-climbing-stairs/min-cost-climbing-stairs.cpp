//1. Tabulation-Bottom Up 
// T-O(n), S-O(n)
#include <bits/stdc++.h>
using namespace std;
// vector<int> dp(1001,-1);
class Solution {
public:
    int solveTab(vector<int> &cost,int n){
        vector<int> dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return solveTab(cost,n);
    }
};


// 2.Memoization 
// T-O(n), S-O(n)
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int solve(vector<int> &cost,int n,vector<int> &dp){
//         if(n<=1) return cost[n];
//         if(dp[n]!=-1)
//             return dp[n];
//         dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
//         return dp[n];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int> dp(n+1,-1);
//         int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
//         return ans;
//     }
// };

// // #include <bits/stdc++.h>
// // using namespace std;
// // vector<int> dp(1001,-1);
// // class Solution {
// // public:
// //     int mincost(vector<int> &cost,int n){
// //         if(dp[n]!=-1) return dp[n];
// //         if(n<=1) return dp[n]=0;
// //         if(n==2) return dp[n]=min(cost[0],cost[1]);
// //         return dp[n]=min(mincost(cost,n-1)+cost[n-1],
// //                 mincost(cost,n-2)+cost[n-2]);
// //     }
// //     int minCostClimbingStairs(vector<int>& cost) {
// //         int n=cost.size();
// //         fill(dp.begin(),dp.end(),-1);
// //         return mincost(cost,n);
// //     }
// // };