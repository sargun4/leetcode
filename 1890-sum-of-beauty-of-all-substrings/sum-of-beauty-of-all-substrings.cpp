class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0; 
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;
                int maxfreq = 0;
                int minfreq = INT_MAX;
                for (auto& f : freq) {
                    maxfreq = max(maxfreq, f.second);
                    minfreq = min(minfreq, f.second);
                }
                ans += (maxfreq - minfreq);
            }
        } 
        return ans;
    }
};