#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10001];
    bool solve(vector<int> &nums,int n,int idx){
        if(idx==n-1) return true;
        // if(idx>=n) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            if(solve(nums,n,idx+i)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,0);
    }
};