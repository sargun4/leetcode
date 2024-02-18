//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


#include <bits/stdc++.h>
using namespace std;

//memo
class Solution{
public:
    int solve(int i,int n,int price[],vector<vector<int>> &dp){
        if(i==0){
            return n*price[0];
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int skip=0+solve(i-1,n,price,dp);
        int take=INT_MIN;
        int rodlen=i+1;
        if(rodlen<=n){
            take=price[i]+solve(i,n-rodlen,price,dp);
        }
        return dp[i][n]= max(take,skip);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
};

// //Time Complexity: O(N^2)
// //Auxiliary Space: O(N) 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends