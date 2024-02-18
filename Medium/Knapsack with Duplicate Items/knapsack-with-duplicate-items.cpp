//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

 
// Unbounded Knapsack 
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
 

#include <bits/stdc++.h>
using namespace std;
 
class Solution{
public:
    int solve(int i,int W,int val[],int wt[],vector<vector<int>> &dp){
        if(i==0){ 
            return val[0]*((int)(W/wt[0])); 
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        int skip=0+solve(i-1,W,val,wt,dp);
        int take=INT_MIN;
        if(wt[i]<=W){
            take=val[i]+solve(i,W-wt[i],val,wt,dp);
        }
        return dp[i][W]=max(take,skip);
    }
    int knapSack(int N, int W, int val[], int wt[]){
        vector<vector<int>> dp(N,vector<int> (W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
}; 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends