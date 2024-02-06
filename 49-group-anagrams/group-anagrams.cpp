//without sorting
//O(n*(k+26))

class Solution {
public:
    string generate(string&word){
        int arr[26]={0};
        for(char &ch:word){
            arr[ch-'a']++;
        }
        string newword="";
        for(int i=0;i<26;i++){
            int freq=arr[i];
            if(freq>0){
                newword+=string(freq,i+'a');
            }
        }
        return newword;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string word=strs[i];
            string newword=generate(word);
            mp[newword].push_back(word);
        }
        for(auto &it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};
// //using sorting
// //O(n*klogk) where k is max size of string in input
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int n=strs.size();
//         vector<vector<string>> res;
//         unordered_map<string,vector<string>> mp;
//         for(int i=0;i<n;i++){
//             string temp=strs[i];
//             sort(begin(temp),end(temp));
//             mp[temp].push_back(strs[i]);
//         }
//         for(auto it:mp){
//             res.push_back(it.second);
//         }
//         return res;
//     }
// };