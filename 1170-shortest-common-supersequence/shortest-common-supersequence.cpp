#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//dp[i][j]=scs of s1 of length i and s2 of length j
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(); int m=str2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]= i+j;
                }else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{//those chars not equal
                    dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        string ans=""; 
        int i=n;  int j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--; j--;
            }else if(dp[i-1][j]<dp[i][j-1]){//taking the min one
                ans+=str1[i-1];
                i--; //move up
            }else{
                ans+=str2[j-1];
                j--;//move down
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         int n=str1.length(); int m=str2.length();
//         int dp[n+1][m+1];
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 if(i==0||j==0){
//                     dp[i][j]= 0;
//                 }else if(str1[i-1]==str2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }else{
//                     dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//                 }
//             }
//         }
//         string ans="";
//         int i=n;  int j=m;
//         while(i>0 && j>0){
//             if(str1[i-1]==str2[j-1]){
//                 ans+=str1[i-1];
//                 i--; j--;
//             }else if(dp[i-1][j]>dp[i][j-1]){
//                 ans+=str1[i-1];
//                 i--;
//             }else{
//                 ans+=str2[j-1];
//                 j--;
//             }
//         }
//         while(i>0){
//             ans+=str1[i-1];
//             i--;
//         }
//         while(j>0){
//             ans+=str2[j-1];
//             j--;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };
// // https://www.geeksforgeeks.org/print-shortest-common-supersequence/