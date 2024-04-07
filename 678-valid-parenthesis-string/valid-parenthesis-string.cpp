
#include <bits/stdc++.h>
using namespace std; 
// //1memo
// class Solution {
// public:
//     int dp[101][101];
//     bool solve(int idx,int open,string &s,int n){
//         if(idx==n) return open==0;
//         if(dp[idx][open]!=-1){
//             return dp[idx][open];
//         }
//         bool isvalid = false;
//         if(s[idx]=='*'){
//             isvalid |=solve(idx+1,open+1,s,n); //if * considered as open brkt
//             isvalid |=solve(idx+1,open,s,n); //if * considered as empty ""
//             if(open>0){
//                 isvalid |=solve(idx+1,open-1,s,n); //if * considered as closed brkt
//             }
//         }else if(s[idx]=='('){
//             isvalid |=solve(idx+1,open+1,s,n);
//         }else if(open>0){
//             isvalid |=solve(idx+1,open-1,s,n);
//         }
//         return dp[idx][open]=isvalid;
//     }
//     bool checkValidString(string s) {
//         int n=s.length();
//         memset(dp,-1,sizeof(dp));
//         return solve(0,0,s,n);
//     }
// };
//2-tab
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        
        dp[n][0]=true;

        for(int i=n-1;i>=0;i--){
            for(int open=0;open<=n;open++){
                bool isvalid=false;
                if(s[i]=='*'){
                    isvalid |=dp[i+1][open+1];// if * considered as open brkt
                    if(open>0){
                        isvalid |=dp[i+1][open-1]; //if * considered as closed brkt
                    }
                    isvalid |=dp[i+1][open];//if * considered as empty ""
                }else if(s[i]=='('){
                    isvalid |=dp[i+1][open+1];
                }else if(open>0){
                    isvalid |=dp[i+1][open-1];
                }
                dp[i][open] =isvalid;
            }
        }   
        return dp[0][0];
    }
};