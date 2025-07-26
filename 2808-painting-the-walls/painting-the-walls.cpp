class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int idx,int rem,vector<int>&cost,vector<int>&time){
        if(rem<=0){
            return 0;//no cost
        }
        if(idx>=n){
            return 1e9;//invalid case
        }
        if(dp[idx][rem]!=-1){
            return dp[idx][rem];
        }
        int paint_idx=cost[idx]+solve(idx+1,rem-1-time[idx],cost,time);
        int no_paint=solve(idx+1,rem,cost,time);
        return dp[idx][rem]=min(paint_idx,no_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=cost.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,cost,time);
    }
};