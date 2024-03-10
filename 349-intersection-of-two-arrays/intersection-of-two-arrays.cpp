class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(),nums1.end());
        vector<int> res;
        for(int &num:nums2){
            if(set.find(num)!=set.end()){//if num found
                res.push_back(num);
                set.erase(num);
            }
        }
        return res;
    }
};