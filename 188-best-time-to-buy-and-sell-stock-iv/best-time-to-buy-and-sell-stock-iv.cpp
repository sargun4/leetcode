// #include <bits/stdc++.h>
// using namespace std;
// //sppce opt
// class Solution {
// public:
//     // At most k transactions. 
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         // vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
//         vector<int> after(2*k+1,0);
//         vector<int> curr(2*k+1,0);
//         for(int idx=n-1;idx>=0;idx--){
//             for(int transNo=2*k-1;transNo>=0;transNo--){
//                 if(transNo%2==0){//buy
//                     int take=-prices[idx]+after[transNo+1];
//                     int skip=0+after[transNo];
//                     curr[transNo]=max(take,skip);
//                 }else{//sell
//                     int take=+prices[idx]+after[transNo+1];
//                     int skip=0+after[transNo];
//                     curr[transNo]=max(take,skip);
//                 }
//             }
//             after=curr;
//         }
//         return after[0];
//     }
// };
// //tab
// class Solution {
// public:
//     // At most k transactions. 
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
//         for(int idx=n-1;idx>=0;idx--){
//             for(int transNo=2*k-1;transNo>=0;transNo--){
//                 if(transNo%2==0){//buy
//                     int take=-prices[idx]+dp[idx+1][transNo+1];
//                     int skip=0+dp[idx+1][transNo];
//                     dp[idx][transNo]=max(take,skip);
//                 }else{//sell
//                     int take=+prices[idx]+dp[idx+1][transNo+1];
//                     int skip=0+dp[idx+1][transNo];
//                     dp[idx][transNo]=max(take,skip);
//                 }

//             }
//         }
//         return dp[0][0];
//     }
// };
class Solution {
public:
    //memo- At most k transactions, cap= no of transactions remaining
    int f(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size(); 
        //base case- //if we have reached the end of the prices arr or no transactions are allowed, return 0
        if (idx == n || cap == 0)
            return 0; 
        if (dp[idx][buy][cap] != -1) //if the val is alr calculated, return it
            return dp[idx][buy][cap]; 
        if (buy == 1){//buy
            int take = -prices[idx] + f(idx + 1, 0, cap, prices, dp); //buy the stock (subtract cost price of stock) and move to the next day(idx+1) and change state to sell(buy = 0)
            int skip = f(idx + 1, 1, cap, prices, dp); //skip buying the stock
            return dp[idx][buy][cap] = max(take, skip);
        } else { //sell
            int take = prices[idx] + f(idx + 1, 1, cap - 1, prices, dp); //sell the stock n move to the next day(idx+1) with 1 less transaction available => cap-1
            int skip = f(idx + 1, 0, cap, prices, dp); //skip selling the stock
            return dp[idx][buy][cap] = max(take, skip);
        }
    }  
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));// initialize dp array with -1
        return f(0, 1, k, prices, dp);//start at day 0 with intent to buy stock(buy=1) w at most k transactions available
    }
};