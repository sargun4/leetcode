// O(n) 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int topfreq = 0;
        for(int x: nums) {
            map[x]++;
            topfreq = max(topfreq, map[x]);
        }

        vector<int> ans;

        unordered_map<int, vector<int>> freqmap;
        for(auto it: map) {
            freqmap[it.second].push_back(it.first);
        }

        int ctr=0;
        while(ctr<k) {
            if(freqmap.find(topfreq) != freqmap.end()) {
                vector<int> v = freqmap[topfreq];
                int n = v.size();
                for(int i=0; i<n; i++) {
                    ans.push_back(v[i]);
                    ctr++;
                    if(ctr == k)
                        break;
                }
            }
            topfreq--;
        }

        return ans;
    }
};