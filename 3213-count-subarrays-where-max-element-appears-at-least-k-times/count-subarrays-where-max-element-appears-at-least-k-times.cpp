#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0,i=0,j=0,n=nums.size();
        unordered_map<int,int> map;
        long long ans=0;
        for(auto elmnt:nums){
            maxi=max(maxi,elmnt);
        }
        while(j<nums.size()){
            map[nums[j]]++;
            while(map[maxi]>=k){
                ans+=(n-j);
                --map[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};