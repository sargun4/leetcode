//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   long long int optimalKeys(int N){
         if(N<=6) return N;
         long long int dp[N+1];
         dp[0]=0;
         for(int i=1;i<=6;i++)
           dp[i]=i;
           
        for(int i=7;i<=N;i++)
           dp[i]=max({2*dp[i-3],3*dp[i-4],4*dp[i-5]});
           
       return dp[N];
    }
};
// #'''consider 4 cases:
// #0. A - takes 1key => 1
// #1. CA, CC, CV - takes 3 keys => 2*(selection)
// #2. CA, CC, CV, CV - takes 4 keys => 3*(selection)
// #3. CA, CC, CV, CV, CV - takes 5 keys => 4*(selection)

// #so if n = 10
// #(2 * screen[n - 3]) means go back and n-3 = 10-3 = 7 so screen 7 value is 9*2 = 18 so check if it max or not (case1)
// #(3 * screen[n - 4]) means go back and n-4 = 10-4 = 6 so screen 6 value is 6*3 = 18 so check if it max or not (case2)
// #(4 * screen[n - 5]) means go back and n-3 = 10-5 = 5 so screen 5 value is 5*4 = 20 so check if it max or not (case3)
// # so in all three max = max(18,18,20) = 20
// #so screen[10] value is 20

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends