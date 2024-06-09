class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int remk,vector<int>&nums){
        if(i==n) return 0;
        if(dp[i][remk]!=-1){
            return dp[i][remk];
        }
        int maxlen=1;
        for(int j=i-1;j>=0;j--){
            if(nums[i]==nums[j]){
                maxlen=max(maxlen,1+solve(j,remk,nums));
            }else if(nums[i]!=nums[j] && remk>0){
                maxlen=max(maxlen,1+solve(j,remk-1,nums));
            }
        }
        return dp[i][remk]=maxlen;
    }
    int maximumLength(vector<int>& nums, int k) {
        n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(min(n+1,26),-1));
        int maxlen=0;
        for(int i=0;i<n;i++){
            maxlen=max(maxlen,solve(i,k,nums));
        }
        return maxlen;
    }
};