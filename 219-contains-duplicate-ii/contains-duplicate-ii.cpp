#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])!=map.end()   &&  abs(map[nums[i]]-i)<=k){
                return true;
            }else{
                map[nums[i]]=i;
            }
        }
        return false;
    }
};