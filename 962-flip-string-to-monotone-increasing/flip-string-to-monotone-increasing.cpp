#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int solve(string &s,int curridx,int prevval, vector<vector<int>> &t){
        if(curridx>=n){
            return 0;
        }
        if(t[curridx][prevval]!=-1){
            return t[curridx][prevval];
        }
        int flip=INT_MAX;
        int noflip=INT_MAX;
        if(s[curridx]=='0'){
            if(prevval==1){
                flip=1+solve(s,curridx+1,1,t);
            }else{
                flip=1+solve(s,curridx+1,1,t);
                noflip=solve(s,curridx+1,0,t);
            }
        }else if(s[curridx]=='1'){
            if(prevval==1){
                noflip=solve(s,curridx+1,1,t);
            }else{
                flip=1+solve(s,curridx+1,0,t);
                noflip=solve(s,curridx+1,1,t);
            }
        }
        return t[curridx][prevval]=min(flip,noflip);
    }
    int minFlipsMonoIncr(string s) {
        n=s.length();
        vector<vector<int>> t(n+1,vector<int>(2,-1)); //t[n+1][2]
        return solve(s,0,0,t);
    }
};