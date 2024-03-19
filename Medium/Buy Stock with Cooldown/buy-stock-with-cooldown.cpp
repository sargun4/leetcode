//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    long long f(int idx, int buy, vector<long long>& prices, vector<vector<long long>>& dp) {
        int n = prices.size(); 
        if (idx >= n) return 0; // Corrected syntax: if(idx >= n) instead of id(idx>=n)
        if (dp[idx][buy] != -1) return dp[idx][buy];
        if (buy == 1) {
            long long take = -prices[idx] + f(idx + 1, 0, prices, dp);
            long long skip = f(idx + 1, 1, prices, dp);
            return dp[idx][buy] = max(take, skip);
        } else { // sell
            long long take = prices[idx] + f(idx + 2, 1, prices, dp);
            long long skip = f(idx + 1, 0, prices, dp);
            return dp[idx][buy] = max(take, skip);
        }
    } 
    long long maximumProfit(vector<long long>& prices, int n) {
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, 1, prices, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends