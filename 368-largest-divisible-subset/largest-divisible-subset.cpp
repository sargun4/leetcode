// https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09

#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n,1);
        vector<int>prev_idx(n,-1);
        int lastchosenidx=0;
        int maxL=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev_idx[i]=j;
                    }
                    if(dp[i]>maxL){
                        maxL=dp[i];
                        lastchosenidx=i;
                    }
                }
            }
        }
        vector<int> res;
        while(lastchosenidx!=-1){
            res.push_back(nums[lastchosenidx]);
            lastchosenidx=prev_idx[lastchosenidx];
        }
        return res;
    }
};
//tle
// class Solution {
// public:
//     void solve(int idx,vector<int>&nums,vector<int>&res,vector<int>&temp,int prev){
//         if(idx>=nums.size()){
//             if(temp.size()>res.size()){
//                 res=temp;
//             }
//             return;
//         }
//         //take
//         if(prev!=-1||nums[idx]%prev==0){
//             temp.push_back(nums[idx]);//take
//             solve(idx+1,nums,res,temp,nums[idx]);
//             temp.pop_back(); //remove
//         }
//         solve(idx+1,nums,res,temp,prev);
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         //frst sort
//         sort(nums.begin(), nums.end());
//         vector<int> res;
//         vector<int> temp;
//         int prev=-1;
//         solve(0,nums,res,temp,prev);
//         return res;
//     }
// };