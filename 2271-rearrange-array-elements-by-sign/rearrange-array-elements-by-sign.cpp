class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a, b, c;

        // Separate positive and negative integers into two separate arrays
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }

        // Interleave positive and negative integers while preserving their order
        int count = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count % 2 == 0) {
                int n = a[c1++];
                c.push_back(n);
            } else {
                int n = b[c2++];
                c.push_back(n);
            }
            count++;
        }

        return c;
    }
};