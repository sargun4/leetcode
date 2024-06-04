class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freq;
        string word;
        for (char c:paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (find(banned.begin(), banned.end(), word) == banned.end()) {
                    freq[word]++;
                }
                word.clear();
            }
        }
        if (!word.empty() && find(banned.begin(), banned.end(), word) == banned.end()) {
            freq[word]++;
        }
        string ans;
        int maxfreq = 0;
        for(auto& p:freq) {
            if (p.second > maxfreq) {
                maxfreq = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};
