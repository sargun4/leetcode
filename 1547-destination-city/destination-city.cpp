// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) {
//         unordered_map<string,int> map;
//         for(auto &path:paths){
//             string src=path[0];
//             map[src]=1;
//         } 
//         for(auto &path:paths){
//             string dest=path[1];
//             if(map[dest]!=1){
//                 return dest;
//             }
//         } 
//         return "";
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> set;
        for(auto &path:paths){
            string src=path[0];
            set.insert(src); //outgoin edge
        } 
        for(auto &path:paths){
            string dest=path[1];
            if(set.find(dest)==set.end()){
                return dest;
            }
        } 
        return "";
    }
};