#include <bits/stdc++.h>
using namespace std;
// T-O(k*n)
class Solution {
public:
    int n;
    int dp[501];//only parametr i changes-therfore 1d dp arr taken
    int solve(int i,vector<int>&arr,int k){
        if(i>=n){
            return 0;
        }
        //dp[i]-maxsum got by partitioning arr of size i
        //if already solved before
        if(dp[i]!=-1)return dp[i];

        int res=0;
        int currmax=-1;
        for(int j=i;j<n && j-i+1<=k;j++){
            currmax = max(currmax,arr[j]);
            //curr subarr= arr[i to j];
            res=max((j-i+1)*currmax+solve(j+1,arr,k),res);
        }
        return dp[i]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof dp);
        return solve(0,arr,k);
    }
};