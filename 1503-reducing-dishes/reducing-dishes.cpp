// #include <bits/stdc++.h>
// using namespace std;
// //tle-recursion
// class Solution {
// public:
//     int n;
//     int solve(vector<int>& satisfaction,int i,int time){
//         if(i>=n) return 0;
//         int include=satisfaction[i]*time+solve(satisfaction,i+1,time+1);
//         int exclude=solve(satisfaction,i+1,time);
//         return max(include,exclude);
//     }
//     int maxSatisfaction(vector<int>& satisfaction) {
//         n=satisfaction.size();
//         sort(begin(satisfaction),end(satisfaction));
//         return solve(satisfaction,0,1);
//     }
// };

// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int n;
//     int dp[501][501];
//     int solve(vector<int>& satisfaction,int i,int time){
//         if(i>=n) return 0;
//         if(dp[i][time]!=-1) return dp[i][time];
//         int include=satisfaction[i]*time+solve(satisfaction,i+1,time+1);
//         int exclude=solve(satisfaction,i+1,time);
//         return dp[i][time]=max(include,exclude);
//     }
//     int maxSatisfaction(vector<int>& satisfaction) {
//         n=satisfaction.size();
//         sort(begin(satisfaction),end(satisfaction));
//         memset(dp,-1,sizeof(dp));
//         return solve(satisfaction,0,1);
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        
        vector<vector<long long>> dp(501,vector<long long>(501,INT_MIN));
        // dp[i][j]=max val till 0..i food and time is j currently
        // at time 0 we hv no val- cooking hasnt started yet
        for(int i=0;i<501;i++){
            dp[i][0]=0;
        }
        //cooking starts at time 1 and we start w 0th food = dp[0][1]
        dp[0][1]=satisfaction[0];
        for(int i=1;i<n;i++){
            for(int time=1;time<=n;time++){
                long long include=satisfaction[i]*time+dp[i-1][time-1];
                long long exclude=dp[i-1][time];         
                dp[i][time]=max(include,exclude); 
                
            }    
        }
        long long ans=0;
        for(int time=1;time<=n;time++){
            ans=max(ans,dp[n-1][time]);
        }
        return ans;
    }
};