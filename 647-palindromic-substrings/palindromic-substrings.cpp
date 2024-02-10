#include <bits/stdc++.h>
using namespace std; 
// T-O(n^2)-memoi
class Solution {
public:
    int dp[1001][1001];
    bool check(string &s,int i,int j){
        if(i>j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=check(s,i+1,j-1);
        }
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        // dp[i][j]=-1 not yet found
        // dp[i][j]=0 false
        // dp[i][j]=1 true
        int ctr=0;
        for(int i=0; i < n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)){//if substr is palindrom
                    ctr++;
                }
            }
        }
        return ctr;
    }
};