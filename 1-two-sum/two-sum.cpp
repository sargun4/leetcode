#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                return {mp[rem],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         unordered_map<int,int> mpp;
//         for(int i=0;i<nums.size();i++){
//             if(mpp.find(target-nums[i]) !=mpp.end()){
//                 ans.push_back(mpp[target-nums[i]]);
//                 ans.push_back(i);
//                 return ans;
//             }
//             mpp[nums[i]];
//         }      
//         return ans;
//     }
// };