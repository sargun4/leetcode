class Solution {
public:
    int hIndex(vector<int>& cite) {
        int n = cite.size();
        sort(cite.begin(), cite.end());
        for (int i = 0; i < n; i++) {
            if (cite[i] >= (n - i)) return n - i;
        }
        return 0;
    }
};