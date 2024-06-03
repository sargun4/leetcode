class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> common;
        vector<int> minfreq(26, INT_MAX);  
        for (const string& currstr : words) {
            vector<int> charfreq(26, 0);  
            for (char c : currstr) {
                charfreq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = std::min(minfreq[i], charfreq[i]);
            }
        }

        for (int i = 0; i < 26; ++i) {
            while (minfreq[i] > 0) {
                common.push_back(string(1, i + 'a')); // Convert char to string
                minfreq[i]--;
            }
        } 
        return common;
    }
};
