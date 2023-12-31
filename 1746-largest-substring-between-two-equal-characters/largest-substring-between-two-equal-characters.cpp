// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         int n=s.length();
//         int res=-1;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if(s[i]==s[j]){
//                     res=max(res,j-i-1);
//                 }
//             }
//         }
//         return res;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        int res=-1;
        unordered_map<char,int> m;
        for (int i = 0; i < n; i++){
            char ch=s[i];
            if(m.find(ch)==m.end()){
                m[ch]=i;
            }else{
                res=max(res,i-m[ch]-1);
            }
        }
        return res;
    }
};