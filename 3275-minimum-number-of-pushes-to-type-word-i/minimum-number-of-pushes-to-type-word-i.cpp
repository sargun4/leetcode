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
// O(n)
// class Solution {
// public:
//     int minimumPushes(string word) {
//         int res=0;
//         unordered_map<int,int> map;
//         //2,3,4,5,6,7,8,9
//         int assignkey=2;
//         for(char &ch:word){
//             if(assignkey>9){
//                 assignkey=2;
//             }
//             map[assignkey]++;
//             res+=map[assignkey];
//             assignkey++;
//         }
//         return res;
//     }
// };