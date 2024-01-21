#include <bits/stdc++.h>
using namespace std;  
class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>> &perms){
        // Base case: if the last element is reached, add the permutation to perms
        int n=nums.size();
        if (i==n-1){
            perms.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(i+1,nums,perms);
            swap(nums[i],nums[j]);//backtracking-restore original order
        }
    }
    vector<vector<int>> permute(vector<int>& nums) { 
        vector<vector<int>> perms;
        solve(0,nums,perms);
        return perms;
    } 
};