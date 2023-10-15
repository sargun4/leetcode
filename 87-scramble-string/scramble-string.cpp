#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,bool> map;
    bool solve(string s1,string s2){
        if(s1==s2) return true;
        if(s1.length()!=s2.length()){
            return false;
        }
        string key=s1+"_"+s2;
        if(map.find(key)!=map.end()){
            return map[key];
        }
        bool result=false;
        int n=s1.length();
        for(int i=1;i<n;i++){
            

            bool swapped=solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i));
            if(swapped==true) return true;

            bool notswapped=solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i));
            if(notswapped==true){
                result=true;
                break;
            } 
        }
        return map[key]=result;
    }
    bool isScramble(string s1, string s2) {
        map.clear();
        return solve(s1,s2);
    }
};