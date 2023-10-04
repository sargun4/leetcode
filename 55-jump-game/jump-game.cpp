// // #include <bits/stdc++.h>
// // using namespace std;

// // //memoization- O()
// // class Solution {
// // public:
// //     int dp[10001];
// //     bool solve(vector<int> &nums,int n,int idx){
// //         if(idx==n-1) return true;
// //         // if(idx>=n) return true;
// //         if(dp[idx]!=-1) return dp[idx];
// //         for(int i=1;i<=nums[idx];i++){
// //             if(solve(nums,n,idx+i)) return dp[idx] = true;
// //         }
// //         return dp[idx] = false;
// //     }
// //     bool canJump(vector<int>& nums) {
// //         int n=nums.size();
// //         memset(dp,-1,sizeof(dp));
// //         return solve(nums,n,0);
// //     }
// // };

// // Tabulation
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n=nums.size();
//         vector<bool> dp(n,false);
//         // dp[i]- True means that we can reach idx i.
//         dp[0] = true;
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(dp[j] && j+nums[j]>=i){
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[n-1];
//     }
// };
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxreachableidx=0;
        for(int i=0;i<n;i++){
            if(i>maxreachableidx){
                return false;
            }
            maxreachableidx = max(maxreachableidx,i+nums[i]);
        }
        return true;
    }
};