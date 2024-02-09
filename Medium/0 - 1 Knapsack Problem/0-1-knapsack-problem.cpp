//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public: 
    int ks(int W, int wt[], int val[], int n,vector<vector<int>>&dp) {
        // Base Case
        if (n == 0 || W == 0)
            return 0; 
        // Check if the value is already memoized
        if (dp[n][W] != -1)
            return dp[n][W]; 
        // If weight of the nth item is more than Knapsack capacity W, then
        // this item cannot be included in the optimal solution
        if (wt[n - 1] > W)
            return dp[n][W] = ks(W, wt, val, n - 1,dp); 
        // Return the maximum of two cases:
        // (1) nth item included
        // (2) not included
        else
            return dp[n][W] = max(val[n - 1] + ks(W - wt[n - 1], wt,val,n-1,dp),
                                   ks(W, wt, val, n - 1,dp));
    } 
    int knapSack(int W, int wt[], int val[], int n){
        vector<vector<int>> dp(n+1,vector<int>(W + 1, -1));
        return ks(W, wt, val, n,dp);
    }
};




//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends