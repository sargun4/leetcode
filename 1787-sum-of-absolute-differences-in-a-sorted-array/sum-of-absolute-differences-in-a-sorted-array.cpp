class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
         int totsum=0;
         int n=nums.size();
        for(auto elmnt:nums) totsum+=elmnt;
        vector<int> ans;
        int lsum=0;
        for(int i=0;i<n;i++){
            int valleft=(nums[i]*i)-lsum;
            int valright=(totsum-lsum-nums[i]*(n-i));
            lsum+=nums[i];
            ans.push_back(valleft+valright);
        }
        return ans;

    }
};