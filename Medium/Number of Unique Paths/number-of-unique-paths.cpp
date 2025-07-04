//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int NumberOfPath(int a, int b){
        int dp[a][b];
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[a-1][b-1];
    }
};
//tle
// class Solution{
//     public:
//     int solve(int i,int j,vector<vector<int>> &dp){
//         if(i<0||j<0){//out of bounds
//             return 0;
//         }
//         if(i==0 && j==0){//reached
//             return 1;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int up=solve(i-1,j,dp);
//         int left=solve(i,j-1,dp);
//         return up+left;
//     }
//     int NumberOfPath(int a, int b){
//         vector<vector<int>> dp(a,vector<int>(b,-1));
//         return solve(a-1,b-1,dp);
//     }
// };


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends