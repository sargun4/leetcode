//memo- O(n)
class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums,int i,int n){
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int steal=nums[i]+solve(nums,i+2,n);//steals ith house & moves to i+2 since we cant rob adjacent house
        int skip=solve(nums,i+1,n);//skips this house, and move to next hoeus
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        memset(dp,-1,sizeof(dp));
        //case1=take first house(0th idx)
        int take_0thidx_house=solve(nums,0,n-2);

        memset(dp,-1,sizeof(dp));
        //case2=take second house(1st idx)
        int take_1stidx_house=solve(nums,1,n-1);

        return max(take_0thidx_house,take_1stidx_house);
    }
};
 
// //O(n)
// //tab
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         vector<int> dp(n+1,0);
//         //dp[i]=money stolen when we hv traversed/been to i houses
//         //case1-take 1st house-hence skip last house
//         dp[0]=0;
//         for(int i=1;i<=n-1;i++){
//             int skip=dp[i-1];
//             int take=nums[i-1]+((i-2>=0) ?dp[i-2]:0);
//             dp[i]=max(skip,take);
//         }
//         int res1=dp[n-1];
//         dp.clear();
//         //case1-skip 1st house-hence we can take last house- since theyre placed in circular fashion
//         dp[0]=0,
//         dp[1]=0;//skip 1st house
//         for(int i=2;i<=n;i++){
//             int skip=dp[i-1];
//             int take=nums[i-1]+((i-2>=0) ?dp[i-2]:0);
//             dp[i]=max(skip,take);
//         }
//         int res2=dp[n];
//         return max(res1,res2);
        
//     }
// };
// class Solution {
// public:
//     int solve(vector<int>& nums,int l,int r){
//         int prev=0;
//         int prevprev=0;
//         for(int i=l;i<=r;i++){
//             int skip=prev;
//             int take=nums[i]+prevprev;
//             int temp=max(skip,take);
//             prevprev=prev;
//             prev=temp;
//         }
//         return prev;
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0],nums[1]);
//         int take1sthouse=solve(nums,0,n-2);
//         int skip1sthouse=solve(nums,1,n-1);
//         return max(take1sthouse,skip1sthouse);
//     }
// };
