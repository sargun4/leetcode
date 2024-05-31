class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int elem : nums) {
            if (set.find(elem) != set.end()) {
                set.erase(elem);
            } else {
                set.insert(elem);
            }
        }
        
        vector<int> res(set.begin(), set.end());
        return res;
    }
};