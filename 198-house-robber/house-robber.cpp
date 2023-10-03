#include <bits/stdc++.h>
using namespace std;

// //memo
// class Solution {
// public:
//     int t[101];
//     int solve(vector<int>& nums,int i,int n){
//         if(i>=n){
//             return 0;
//         }
//         if(t[i]!=-1) return t[i];
//         int steal=nums[i]+solve(nums,i+2,n);
//         int skip=solve(nums,i+1,n);
//         return t[i]=max(steal,skip);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         memset(t,-1,sizeof(t));
//         return solve(nums,0,n);
//     }
// };

//tab
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t(n+1,0);  //t[i]=max stolen money till house i
        t[0]=0;//no house-no money
        t[1]=nums[0];//1 house only
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+t[i-2];
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        return t[n];
    }
};


// // //memoization-top down-O(n)
// // class Solution {
// // public:
// //     vector<int> dp;
// //     int f(int i,vector<int> &arr){
// //         if(i>=arr.size()) return 0;
// //         if(dp[i]!=-1) return dp[i];
// //         return dp[i]=max(arr[i]+f(i+2,arr),0+f(i+1,arr));
// //     }
// //     int rob(vector<int>& nums) {
// //         dp.resize(nums.size()+10,-1);
// //         return f(0,nums);
// //     }
// // };

// //tabulation-bottom up-O(n)
// class Solution {
// public:
//     vector<int> dp;
//     int f(int i,vector<int> &arr){
//         int n=arr.size();
//         if(n==1) return arr[n-1];
//         dp[n-1]=arr[n-1];
//         dp[n-2]=max(arr[n-1],arr[n-2]);
//         for(int i=n-3;i>=0;i--){
//             dp[i]=max(arr[i]+dp[i+2],0+dp[i+1]);
//         }
//         return dp[0];
//     }
//     int rob(vector<int>& nums) {
//         dp.resize(nums.size()+10,-1);
//         return f(0,nums);
//     }
// };




//java
// //tab
// class Solution {
//     public int rob(int[] num) {
//         int[][] dp = new int[num.length + 1][2];
//         for (int i = 1; i <= num.length; i++) {
//             dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
//             dp[i][1] = num[i - 1] + dp[i - 1][0];
//         }
//         return Math.max(dp[num.length][0], dp[num.length][1]);
//     }
// }
// // //memo
// // class Solution {
// //     public int rob(int[] num) {
// //         int rob = 0; //max monney can get if rob current house
// //         int notrob = 0; //max money can get if not rob current house
// //         for(int i=0; i<num.length; i++) {
// //             int currob = notrob + num[i]; //if rob current value, previous house must not be robbed
// //             notrob = Math.max(notrob, rob); //if not rob ith house, take the max value of robbed (i-1)th house and not rob (i-1)th house
// //             rob = currob;
// //         }
// //         return Math.max(rob, notrob);
// //     }
// // }
