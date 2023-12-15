#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> map;
        for(auto &path:paths){
            string src=path[0];
            map[src]=1;
        } 
        for(auto &path:paths){
            string dest=path[1];
            if(map[dest]!=1){
                return dest;
            }
        } 
        return "";
    }
};