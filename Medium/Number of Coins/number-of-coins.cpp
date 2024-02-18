//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article



#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
    int solve(int i,int sum,vector<int> &coins,vector<vector<int>> &dp){
        if(i==0){//only 1 elmnt,check the denomination
            if(sum%coins[i]==0){
                return sum/coins[i];
            }else{
                return 1e9;
            }
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int nottake=0+solve(i-1,sum,coins,dp);
        int take=INT_MAX;//since we nned min coins
        if(coins[i]<=sum){
            take=1+solve(i,sum-coins[i],coins,dp);
        }
        return dp[i][sum]=min(take,nottake);
    }
	int minCoins(vector<int> &coins, int M, int V) { 
        vector<vector<int>> dp(M,vector<int>(V+1,-1));
        int ans=solve(M-1,V,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
	} 
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends