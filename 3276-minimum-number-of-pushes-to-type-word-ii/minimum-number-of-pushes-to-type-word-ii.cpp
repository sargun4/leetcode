#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int minimumPushes(string word) {
        int res=0;
        vector<int> v(26,0);
        for(char &ch:word){
            v[ch-'a']++;
        }
        //sort in desc based on freq
        sort(begin(v),end(v),greater<int>());
        for(int i=0;i<26;i++){
            int freq=v[i];
            int press=i/8+1;
            res+=(freq*press);
        }
        return res;
    }
};