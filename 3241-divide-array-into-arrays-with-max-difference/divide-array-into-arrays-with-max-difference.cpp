class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i+=3){//iterate it w step 3
            if(nums[i+2]-nums[i]>k){//if the diff bw the largest and the smallest elmnt is more than k
                return {};//not possible
            }
            res.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return res;
    }
};