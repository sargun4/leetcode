#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int n=nums.size();
        unordered_set<int> s;
        for(auto elmnt:nums) s.insert(elmnt);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }else{
                break;
            }
        }
        while(s.find(sum)!=s.end()){//if prefix sum is in nums
            sum++;//increase sum
        }
        return sum;
    }
};