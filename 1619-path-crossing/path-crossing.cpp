#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set <string> set;
        int x=0,y=0;
        string key=to_string(x)+"_"+to_string(y);
        set.insert(key);
        for(char &ch:path){
            if(ch=='E'){
                x++;
            }else if(ch=='W'){
                x--;
            }else if(ch=='N'){
                y++;
            }else if(ch=='S'){
                y--;
            }
            string key=to_string(x)+"_"+to_string(y);
            if(set.find(key)!=set.end()){
                return true;
            }
        set.insert(key);
        }
        return false;
    }
};