#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> freq;
        for(auto elmnt:nums){
            freq[elmnt]++;
            if(ans.size()<freq[elmnt]){
                ans.push_back({});
            }
            ans[freq[elmnt]-1].push_back(elmnt);
        }
        return ans;
    }
};