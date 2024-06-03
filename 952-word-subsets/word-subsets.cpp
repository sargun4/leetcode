
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxfreq(26, 0); // max freq of each character in words2 
        //calc the maximum freq required for each character
        for(string& word : words2) {
            vector<int> charfreq = getCharFreq(word);
            for (int i = 0; i < 26; ++i) {
                maxfreq[i] = max(maxfreq[i], charfreq[i]);
            }
        }
        vector<string> res;
        //check each word in words1
        for(string& word : words1) {
            vector<int> charfreq = getCharFreq(word);
            if (isUniversal(charfreq, maxfreq)) {
                res.push_back(word);
            }
        }

        return res;
    }

private:
    vector<int> getCharFreq(string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        return freq;
    }
    bool isUniversal(vector<int>& wordfreq , vector<int>& maxfreq) {
        for (int i = 0; i < 26; ++i) {
            if (wordfreq[i] < maxfreq[i]) {
                return false;
            }
        }
        return true;
    }
};
