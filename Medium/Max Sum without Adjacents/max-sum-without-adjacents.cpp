//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
// Max Sum without Adjacents

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	
	int solve(int*arr,int i,vector<int> &dp){
        if(i==0) return arr[i];
        if(i<0) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=solve(arr,i-2,dp)+arr[i];
        int skip=solve(arr,i-1,dp);
        return dp[i]=max(take,skip);
    }
	int findMaxSum(int*arr, int n) {
	    vector<int> dp(n,-1);
        return solve(arr,n-1,dp);
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends