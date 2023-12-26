// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     bool isPathCrossing(string path) {
//         unordered_set <string> set;
//         int x=0,y=0;
//         string key=to_string(x)+"_"+to_string(y);
//         set.insert(key);
//         for(char &ch:path){
//             if(ch=='E'){
//                 x++;
//             }else if(ch=='W'){
//                 x--;
//             }else if(ch=='N'){
//                 y++;
//             }else if(ch=='S'){
//                 y--;
//             }
//             string key=to_string(x)+"_"+to_string(y);
//             if(set.find(key)!=set.end()){
//                 return true;
//             }
//         set.insert(key);
//         }
//         return false;
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        unordered_set<string> s;
        s.insert("0,0");
        for (auto c : path) {
            if (c == 'N')
                y++;
            else if (c == 'S')
                y--;
            else if (c == 'E')
                x++;
            else if (c=='W')
                x--;
            string coord=to_string(x)+","+to_string(y);
            if(s.find(coord)!=s.end()){
                return true;
            }
            s.insert(coord);
        }
        return false;
    }
};