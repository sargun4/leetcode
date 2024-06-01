class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (auto elmnt : arr) freq[elmnt]++;

    unordered_set<int> set;
    for (auto [key,val] : freq)
        set.insert(val);
    return set.size()==freq.size();
    }
};