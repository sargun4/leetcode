#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int s_map[26]={0};
        int t_map[26]={0};
        for(int i=0;i<n;i++){
            s_map[s[i]-'a']++;
            t_map[t[i]-'a']++;
        }
        int res=0;
        for(int i=0;i<26;i++){
            if(s_map[i] > t_map[i]){
                res+=abs(s_map[i]-t_map[i]);
            }
        }
        return res;
    }
};