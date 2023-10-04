#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10001];
    int helper(int n){
        if(n==0) return 0;
        if(dp[n]!=-1){
            return dp[n];
        }
        int mincount=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int res=1+helper(n-i*i);
            mincount=min(mincount,res);
        }
        return dp[n]=mincount;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};