class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freqMap;
        for(auto &ch:s){
            freqMap[ch]++;
        }
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        vector<int> freqs;
        for(auto& pair : freqMap) {
            freqs.push_back(pair.second);
        }
        for (int freq : freqs) {
            if (freq % 2 == 0) {
                if (freq < minEven) {
                    minEven = freq;
                }
            } else {
                if (freq > maxOdd) {
                    maxOdd = freq;
                }
            }
        }
        if (maxOdd == INT_MIN || minEven == INT_MAX) {
            return 0; 
        }
        return maxOdd - minEven;
    }
};