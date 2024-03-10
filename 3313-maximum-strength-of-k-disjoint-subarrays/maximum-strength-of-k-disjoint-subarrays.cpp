#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define ll long long
    int n;
    vector<vector<vector<ll>>> dp;
    ll solve(int i,ll k,vector<int>& nums,bool startnew){
        if(k==0) return 0; //strength=0
        //case:not take:
        if(i>=n) return -1e18;
        if(dp[i][k][startnew]!=-1){
            return dp[i][k][startnew];
        }
        ll nottake= -1e18;
        ll take= -1e18;
        if (startnew==true){
            nottake=solve(i+1,k,nums,true);
        }
        //case take:
        //1.take nums[i] and close this subarr and create new one
        //2.or take nums[i],continue in the same subarr
        if(k%2!=0){
            take=solve(i+1,k-1,nums,true)+nums[i]*k;
            take=max(take,solve(i+1,k,nums,false)+nums[i]*k);
        }else{
            take=solve(i+1,k-1,nums,true)-nums[i]*k;
            take=max(take,solve(i+1,k,nums,false)-nums[i]*k);
        }
        return dp[i][k][startnew]=max(take,nottake);
    }
    long long maximumStrength(vector<int>& nums, int k) {
        n=nums.size();
        bool startnew=true;

        dp.resize(n+1,vector<vector<ll>>(k+1,vector<ll>(2,-1)));
        return solve(0,k,nums,startnew);
    }
};