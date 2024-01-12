
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int peak=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i] > nums[i - 1]){
                peak = i;
                break;
            }
        }
        // no peak, reverse the number
        if (peak == -1) {
            reverse(nums.begin(), nums.end());
        }
        else{
            // find right one that is smaller than nums[peak]
            for(int i=n-1;i>=peak;i--){
                if(nums[i] > nums[peak-1]){
                    swap(nums[i], nums[peak-1]);
                    break;
                }
            }
            // reverse the right part of nums[peak]
            reverse(nums.begin() + peak , nums.end());
        }
    }
};