class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(), del = 0;
        unordered_map<char, int> mp;
        // Count freq of each character
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        // calc no of chars to be removed
        for(auto ele : mp){
            int freq = ele.second;
            del += (freq%2) ? freq - 1 : freq - 2;
        }
        return n - del;
    }
};