//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


 #include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int f(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
        if(i>j) return 0;
        int maxi=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int idx=i;idx<=j;idx++){
            int cost=arr[i-1]*arr[idx]*arr[j+1]+f(i,idx-1,arr,dp)+f(idx+1,j,arr,dp);
            maxi=max(maxi,cost);
        } 
        return dp[i][j]=maxi;

    }
    int maxCoins(int N, vector<int> &arr) {
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return f(1,N,arr,dp);
    }
};
 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends