#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        int res=-1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    res=max(res,j-i-1);
                }
            }
        }
        return res;
    }
};