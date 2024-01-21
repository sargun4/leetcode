#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    void solve(int i,vector<int> &nums,vector<int> &temp,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(temp);
        }else{
            //include ith elmnt
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();//remove the element to try other possibilities
            //exclude ith elmnt
            solve(i+1,nums,temp,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};
 