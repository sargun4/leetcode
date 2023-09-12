#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for (char &ch : s) {
            freq[ch - 'a']++;
        }
        int res = 0;
        unordered_set<int> st;
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0 && st.find(freq[i]) != st.end()) {
                freq[i]--; // Decrement the frequency
                res++;
            }
            st.insert(freq[i]);
        }
        return res;
    }
};
