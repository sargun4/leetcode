class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxdiff=0;
        for(int i=0;i<n;i++){
            maxdiff=max(maxdiff,abs(nums[i]-nums[(i+1)%n]));
        }
        return maxdiff;
    }
};