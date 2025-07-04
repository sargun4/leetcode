class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> map(26, 0);
        for (char c : s) {
            map[c - 'a']++;
        }
        string result;

        for (char c : order) {
            result.append(map[c - 'a'], c);
            map[c - 'a'] = 0;
        }

        for (int i = 0; i < 26; ++i) {
            result.append(map[i], 'a' + i);
        } 
        return result;
    }
};