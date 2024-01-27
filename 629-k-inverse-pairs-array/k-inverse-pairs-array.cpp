#include <bits/stdc++.h>
using namespace std; 
// T-O(n*k*n-1)
//memo
class Solution {
public:
    int MOD=1e9+7;
    int dp[1001][1001];
    int solve(int n,int k){
        // Base case
        if(n == 0)return 0; //no elmnts
        if(k==0) return 1; //sorted arr-no inversions
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int res=0;
        //for an arr of n len, at max only (n-1) inversins possible
        for(int inv=0;inv<=min(k,n-1);inv++){
            res=(res%MOD+solve(n-1,k-inv)%MOD)%MOD;
        }
        return dp[n][k]=res;

    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof dp);//initializing dp array with -1
        return solve(n,k);
    }
};