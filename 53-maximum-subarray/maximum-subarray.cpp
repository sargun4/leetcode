class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currmax = 0, maxTillNow = INT_MIN;
        for(int elmnt : nums)
            currmax = max(elmnt, currmax + elmnt),
            maxTillNow = max(maxTillNow, currmax);
        return maxTillNow;
    }
};