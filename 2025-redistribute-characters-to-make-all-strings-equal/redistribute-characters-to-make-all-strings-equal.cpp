#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        unordered_map<char,int> map;
        for(string &word:words){
            for(char &ch :word){
                map[ch]+=1;
            }
        }
        for(auto &it :map){
            int freq=it.second;
            //char ch=it.first;
            if(freq%n!=0){
                return false;
            }
        }
        return true;
    }
};