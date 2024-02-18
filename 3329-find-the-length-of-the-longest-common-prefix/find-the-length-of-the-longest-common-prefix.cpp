// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(); int n2=arr2.size();
        set<string> set;
        for(int i=0;i<n1;i++){
            string num=to_string(arr1[i]);
            string s="";
            for(char ch:num){
                s+=ch;
                set.insert(s);
            }
        }
        int maxlen=0;
        for(int i=0;i<n2;i++){
            string num=to_string(arr2[i]);
            string s="";
            for(char ch:num){
                s+=ch;
                if(set.count(s)){
                    maxlen= max(maxlen,(int)s.length());
                }
            }
        }
        return maxlen;
    }
};