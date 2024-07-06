#include <vector>
#include <algorithm>

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9 + 7;
        vector<int> subarrsums;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum = (sum + nums[j]) % MOD;
                subarrsums.push_back(sum);
            }
        }
        sort(subarrsums.begin(), subarrsums.end());
        int ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + subarrsums[i]) % MOD;
        }
        
        return ans;
    }
};
