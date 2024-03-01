//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int mod = 1e9+7;
    int recur(int i,int j,vector <vector<int>> &dp,string &s){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int num = recur(i+1,j,dp,s)+recur(i,j-1,dp,s);
        if(s[i] == s[j]) num++;
        else num -= recur(i+1,j-1,dp,s);
        return dp[i][j] = num < 0 ? num+mod : num%mod;
    }
    long long int  countPS(string str){
        int n = str.size();
        vector <vector<int>> dp(n,vector<int>(n,-1));
        return recur(0,n-1,dp,str);
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends