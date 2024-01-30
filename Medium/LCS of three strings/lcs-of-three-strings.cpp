//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std; 

//Time Complexity: O(n1*n2*n3).
//Auxiliary Space: O(n1*n2*n3)
class Solution {
public:
    int dp[21][21][21];
    
    int solve(string &a, string &b, string &c, int i, int j, int k) {
        if(i < 0 or j < 0 or k < 0) return 0;
        
        if(dp[i][j][k] != -1) 
            return dp[i][j][k];
        
        if(a[i] == b[j] and a[i] == c[k]) 
            dp[i][j][k] = 1 + solve(a, b, c, i - 1, j - 1, k - 1);
        
        else 
            dp[i][j][k] = max({solve(a, b, c, i-1, j, k), solve(a, b, c, i, j-1, k), solve(a, b, c, i, j, k-1)});
        
        return dp[i][j][k];
    }

    int LCSof3(string a, string b, string c, int n1, int n2, int n3) {
        memset(dp, -1, sizeof dp);
        return solve(a, b, c, n1 - 1, n2 - 1, n3 - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends