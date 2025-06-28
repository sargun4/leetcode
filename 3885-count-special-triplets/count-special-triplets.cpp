const int MOD = 1e9 + 7;
typedef long long ll;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;
        unordered_map<int, int> r, l;
        for (int val : nums) {
            r[val]++;
        }
        for (int j = 0; j < n; ++j) {
            int mid = nums[j];
            r[mid]--; 
            int left = l[2 * mid];
            int right = r[2 * mid];
            res = (res + 1LL * left * right) % MOD;
            l[mid]++;
        }
        return res;
    }
};