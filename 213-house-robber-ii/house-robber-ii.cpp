// #include <bits/stdc++.h>
// using namespace std;
//O(n)
// //memo
// class Solution {
// public:
//     int t[101];
//     int solve(vector<int>& nums,int i,int n){
//         if(i>n){
//             return 0;
//         }
//         if(t[i]!=-1) return t[i];
//         int steal=nums[i]+solve(nums,i+2,n);//steals ith house & moves to i+2 since we cant rob adjacent house
//         int skip=solve(nums,i+1,n);//skips this house, and move to next hoeus
//         return t[i]=max(steal,skip);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
        
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0],nums[1]);
//         memset(t,-1,sizeof(t));
//         //case1=take first house(0th idx)
//         int take_0thidx_house=solve(nums,0,n-2);

//         memset(t,-1,sizeof(t));
//         //case2=take second house(1st idx)
//         int take_1stidx_house=solve(nums,1,n-1);

//         return max(take_0thidx_house,take_1stidx_house);
//     }
// };


#include <bits/stdc++.h>
using namespace std;
//O(n)
//tab
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> t(n+1,0);
        //t[i]=money stolen when we hv traversed/been to i houses
        
    
        //case1-take 1st house-hence skip last house
        t[0]=0;
        for(int i=1;i<=n-1;i++){
            int skip=t[i-1];
            int take=nums[i-1]+((i-2>=0) ?t[i-2]:0);
            t[i]=max(skip,take);
        }
        int res1=t[n-1];
        t.clear();


        //case1-skip 1st house-hence we can take last house
        t[0]=0,
        t[1]=0;//skip 1st house
        for(int i=2;i<=n;i++){
            int skip=t[i-1];
            int take=nums[i-1]+((i-2>=0) ?t[i-2]:0);
            t[i]=max(skip,take);
        }
        int res2=t[n];
        
        return max(res1,res2);
        
    }
};
