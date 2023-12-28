#include <bits/stdc++.h>
using namespace std;
int dp[101][27][101][101];
class Solution {
public:
    //O(n*26*n*k)
    int solve(string &s,int i,int prev_char,int freq,int k){
        if(k<0){
            return INT_MAX;
        }
        int n=s.length();
        if(i>=n){
            return 0;
        }
        if(dp[i][prev_char][freq][k]!=-1){
            return dp[i][prev_char][freq][k];
        }
        int del_i=solve(s,i+1,prev_char,freq,k-1);
        int keep_i=0;
        if(s[i]-'a'!=prev_char){
            keep_i=1+solve(s,i+1,s[i]-'a',1,k);
        }else{
            int one_more_addition=0; //for rle
            if(freq==1||freq==9||freq==99){
                one_more_addition=1;//if the current character is already present in the string then no need to add it again
            }
            keep_i=one_more_addition+solve(s,i+1,prev_char,freq+1,k);
        }
        return dp[i][prev_char][freq][k]=min(del_i,keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,26,0,k);
    }
};