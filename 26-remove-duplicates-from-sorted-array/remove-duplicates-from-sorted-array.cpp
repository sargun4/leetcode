#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;//j will get unique elmnt idx
        while(j<n){
            if(nums[i]!=nums[j]){//get uniq
                i++;
                nums[i]=nums[j];//write the unique elmnt to the idx
            }
            j++;
        }
        return i+1;
    }
};