class Solution {
public:
//The count of such subsequences is 2^(right - left) cuz each element between left and right can either be picked or not.
    int numSubseq(vector<int>& nums, int target) {
        int mod=1e9 + 7;
        int n=nums.size();
        //1.sort
        sort(nums.begin(), nums.end());//nlogn
        //2.precompute powers of 2 upto n (cuz for k elements, 2^k subsequences exist)
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int l = 0, r = n - 1, res = 0;
        //2ptr
        while(l<=r) {
            int sum=nums[l]+nums[r];
            if (sum<=target){
                //Total combinations=2^(right-left)            
                res=(res+power[r-l])%mod;
                l++;//move left fwd
            }else{
                //if sum > target, max element (nums[r]) is too large
                r--;//reduce max to make sum smaller
            }
        }
        return res;
    }
};