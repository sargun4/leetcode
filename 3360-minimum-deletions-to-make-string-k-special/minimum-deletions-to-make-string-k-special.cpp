class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char ch : word) {
            freqMap[ch]++;
        }
        vector<int> freqs;
        for (auto& [ch, count] : freqMap) {
            freqs.push_back(count);
        }
        sort(freqs.begin(), freqs.end());
        int n = freqs.size();
        int minDels = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int base = freqs[i];
            int dels = 0;
            //delete all chars with freq < base
            for (int j = 0; j < i; ++j) {
                dels += freqs[j];  // Remove all lower freq
            }
            //delete excess chars where freq > base + k
            for (int j = i+1; j < n; ++j) {
                if (freqs[j] > base + k) {
                    dels += freqs[j] - (base + k);
                }
            }
            minDels = min(minDels, dels);
        }
        return minDels;
    }
};