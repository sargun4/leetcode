class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int l = binsearch(nums, target, true);
        int r = binsearch(nums, target, false);
        res[0] = l;
        res[1] = r;
        return res;        
    }

    int binsearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int l = 0;
        int r = nums.size() - 1;
        int idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                idx = mid;
                if (isSearchingLeft) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return idx;
    }    
};