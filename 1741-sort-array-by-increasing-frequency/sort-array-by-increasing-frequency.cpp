class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int c:nums){
            freq[c]++;
        }
        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if (freq[n1] != freq[n2]) {// if freq of numbers are not equal then return in inc order based on freq.
                return freq[n1] < freq[n2];
            } else {// otherwise sort them in dec order based on number in nums
                return n2 < n1;
            }        
        });
        return nums;
    }
};