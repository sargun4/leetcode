//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

//tabualtion
class Solution{
    public: 
    int lcs(int n, int m, string s1, string s2){
        int dp[n+1][m+1];
        // memset(dp,-1,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){//if either n or m is 0 =>lcs is 0 
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
// class Solution{
//     public: 
//     int dp[1001][1001];
//     Solution(){memset(dp,-1,sizeof(dp));}
//     int lcs(int n, int m, string s1, string s2){
//         if(n==0||m==0) return dp[n][m]=0;
//         if(dp[n][m]!=-1){
//             return dp[n][m];
//         }
//         if(s1[n-1]==s2[m-1]){
//             return dp[n][m] = 1+lcs(n-1,m-1,s1,s2);
//         }else{
//             return dp[n][m] = max(lcs(n-1,m,s1,s2), lcs(n,m-1,s1,s2));
//         }
//     }
// };


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends