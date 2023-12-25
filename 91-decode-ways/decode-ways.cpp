#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<int> dp;
//     //memoization-TD
//     int str_to_int(string s){
//         if(s.size()==1) return s[0]-'0';
//         return (s[0]-'0')*10+(s[1]-'0');
//     }
//     int f(string s,int idx){
//         //base case;
//         if(s[idx]=='0') return 0;
//         if(idx>=s.size()) return 0;
//         if(idx==s.size()-1){
//             if(s[idx]=='0') return 0;
//             else return 1;
//         }
//         if(idx==s.size()-2){
//             bool canform2digits=str_to_int(s.substr(idx,2))<=26;
//             return f(s,idx+1)+(canform2digits);
//         }

//         if(dp[idx]!=-1) return dp[idx];
//         bool canform2digits=str_to_int(s.substr(idx,2))<=26;
//         return dp[idx]=f(s,idx+1)+((canform2digits) ? f(s,idx+2):0);
//     }
//     int numDecodings(string s){
//         dp.clear();dp.resize(105,-1);

//         return f(s,0);
//     }
// };

// //memo
// class Solution {
// public:
//     int dp[101];
//     int solve(int i,string &s,int &n){
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         if(i==n){ //one valid split done
//             return dp[i]=1;
//         } 
//         if(s[i]=='0'){
//             return dp[i]=0; //not possible to split
//         }
//         int res=solve(i+1,s,n);
//         if(i+1<n){
//             if(s[i]=='1'|| (s[i]=='2' && s[i+1]<='6')){
//                 res+=solve(i+2,s,n);
//             }
//         }
//         return dp[i]=res;
//     }
//     int numDecodings(string s){
//         int n=s.length();
//         memset(dp,-1,sizeof(dp));
//         return solve(0,s,n);
//     }
// }; 
// // #dp[i]=no. of decode ways for str s frm idx i to n


//tabulation
class Solution {
public:
    int dp[101];
    
    int numDecodings(string s){
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }else{
                dp[i]=(dp[i+1]); //single digit
                if(i+1<n){
                    if(s[i]=='1'||(s[i]=='2' && s[i+1]<='6')){
                        dp[i]+=dp[i+2];
                    }
                }
            }
        }
        return dp[0]; //s[0 to n] full string ka decode ways
    }
};  
