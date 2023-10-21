#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> set;
    int n;
    int dp[301];
    bool solve(int idx,string &s){
        if(idx>=n){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        if(set.find(s)!=set.end()){
            return true;
        }
        for(int l=1;l<=n;l++){
            string temp=s.substr(idx,l);
            if(set.find(temp)!=set.end() && solve(idx+l,s)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        for(string &word:wordDict){
            set.insert(word);
        }
        return solve(0,s);
    }
};