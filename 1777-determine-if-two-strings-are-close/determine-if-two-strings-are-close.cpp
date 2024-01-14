// https://leetcode.com/problems/determine-if-two-strings-are-close/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> word1freq(26,0);
        vector<int> word2freq(26,0);
        vector<bool> isPresentword1(26,false);
        vector<bool> isPresentword2(26,false);
        for(char ch:word1){
            isPresentword1[ch-'a'] = true;
            word1freq[ch-'a']++;
        }
        for(char ch:word2){
            isPresentword2[ch-'a']=true;
            word2freq[ch-'a']++;
        }
        sort(begin(word1freq),end(word1freq));
        sort(begin(word2freq),end(word2freq));

        return word1freq==word2freq && isPresentword2==isPresentword1; 
    }
};
