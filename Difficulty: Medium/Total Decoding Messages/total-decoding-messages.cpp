//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
	public:
	int mod = 1e9+7;
    int solve(string &str,int idx,vector<int>&dp){
        if(idx==0 || idx==1) return 1;
        if(dp[idx]!=-1) return dp[idx]; 
        int ctr=0;
        if(str[idx-1] >= '1') 
            ctr = ctr + solve(str,idx-1,dp)%mod;
        if(str[idx-2] =='1' || str[idx-2] == '2' && str[idx-1] <='6')
            ctr = (ctr + solve(str,idx-2,dp)%mod)%mod;
        return dp[idx] = ctr%mod;
    }
	int CountWays(string str){
	    int idx=str.length();
	    //  we need to return 0, if there are leading 0's.
	    if(str[0]=='0') return 0;
	    vector<int>dp(idx+1,-1);
	    return solve(str,idx,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends