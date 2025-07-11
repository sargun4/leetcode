#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int M=1e9+7;
    vector<vector<int>> adj =
    {
        {4,6}, //for 0
        {6,8}, //for 1
        {7,9}, //for 2
        {4,8}, //for 3
        {3,9,0}, //for 4
        {}, //for 5
        {1,7,0}, //for 6
        {2,6}, //for 7
        {1,3}, //for 8
        {2,4} //for 9
    };
    
    int knightDialer(int n) {
        int res=0;
        vector<vector<int>> dp(n,vector<int>(10));
        //base case
        for(int cell=0;cell<=9;cell++){
            dp[0][cell]=1;
        }
        //recursive case
        for(int i=1;i<=n-1;i++){
            for(int cell=0;cell<=9;cell++) {
                int ans=0;
                for (int &nextcell : adj[cell]){
                    ans=(ans+dp[i-1][nextcell])%M;
                }
                dp[i][cell] = ans;
            }
        }
        //return the number of ways to reach from 'n-1'th digit to all other digits
        for(int cell=0;cell<=9;cell++){
            res=(res+dp[n-1][cell])%M;
        }
        return res;
    }
};
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int M=1e9+7;
//     vector<vector<int>> adj =
//     {
//         {4,6}, //for 0
//         {6,8}, //for 1
//         {7,9}, //for 2
//         {4,8}, //for 3
//         {3,9,0}, //for 4
//         {}, //for 5
//         {1,7,0}, //for 6
//         {2,6}, //for 7
//         {1,3}, //for 8
//         {2,4} //for 9
//     };
//     int dp[5001][10];
//     int solve(int n,int cell){
//         if(n==0) return 1;
//         int ans=0;
//         if(dp[n][cell]!=-1){
//             return dp[n][cell];
//         }
//         for(int &nextcell:adj[cell]){
//             ans=(ans+solve(n-1,nextcell))%M;
//         }
//         return dp[n][cell]= ans;
//     }
//     int knightDialer(int n) {
//         int res=0;
//         memset(dp,-1,sizeof(dp));
//         for(int cell=0;cell<=9;cell++){
//             res=(res+solve(n-1,cell))%M;
//         }
//         return res;
//     }
// };
