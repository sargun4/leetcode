//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int nthFibonacci(int n){
        vector<int> DP(n+1,0);
        DP[0]=0;
        DP[1]=1;
        for(int i=2;i<=n;i++)
        DP[i]=(DP[i-1]+DP[i-2])%mod;
        
        return DP[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends