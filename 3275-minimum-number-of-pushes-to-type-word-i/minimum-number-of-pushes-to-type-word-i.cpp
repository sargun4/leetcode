#include <bits/stdc++.h>
using namespace std; 
//O(n)
class Solution {
public:
    int minimumPushes(string word) {
        int res=0;
        unordered_map<int,int> map;
        //2,3,4,5,6,7,8,9
        int assignkey=2;
        for(char &ch:word){
            if(assignkey>9){
                assignkey=2;
            }
            map[assignkey]++;
            res+=map[assignkey];
            assignkey++;
        }
        return res;
    }
};